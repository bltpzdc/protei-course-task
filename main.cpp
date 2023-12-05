#include "include/Config.h"
#include "include/CallHttpController.h"
#include "include/CDRWriterImpl.h"
#include "include/Operator.h"

#include <chrono>
#include <thread>

#define DEFAULT_PORT 8080

void updateConfig() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(Config::getInstance().getNextUpdateTime() * 1000));
        Config::update();
    }
}

bool init(const std::string &configFileName) {
    try {
        Config::setFilename(configFileName);
        Config &config = Config::getInstance();
    } catch (nlohmann::detail::parse_error e) {
        BOOST_LOG_TRIVIAL(fatal) << "Config initialization: syntax error while parsing config file";
        return 0;
    } catch (FileException &e) {
        BOOST_LOG_TRIVIAL(fatal) << e.getMessage();
        return 0;
    } catch (nlohmann::detail::type_error e) {
        BOOST_LOG_TRIVIAL(fatal) << "Config initialization: some values are missing in configuration file";
        return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        BOOST_LOG_TRIVIAL(fatal) << "No configuration file name in console arguments";
        return -1;
    }

    std::string configFileName = argv[1];
    uint32_t port = argc >= 3 ? atoi(argv[2]) : DEFAULT_PORT; 
    if (port == DEFAULT_PORT) BOOST_LOG_TRIVIAL(warning) << "Port have not written. Used default port " << DEFAULT_PORT;

    if (!init(configFileName)) 
        return -1;
    
    auto *queue = new CallQueue();
    auto *cdrWriter = new CDRWriterImpl(Config::getInstance().getCDRFile());
    auto *service = new CallServiceImpl(*queue, *cdrWriter);
    auto *controller = new CallHttpController(*service, port);
    std::thread timeoutHandler(std::bind(&CallServiceImpl::handleCleanExpired, service));
    std::thread operatorsHandler(std::bind(&CallServiceImpl::handleSchedulingReady, service));
    std::thread configUpdateHandler(updateConfig);
    controller->listenGet();
    configUpdateHandler.detach();
    timeoutHandler.detach();
    operatorsHandler.detach();
    return 0;
}
