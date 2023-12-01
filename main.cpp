#include "include/Config.h"
#include "include/CallHttpController.h"
#include "include/CDRWriterImpl.h"
#include "include/Operator.h"

#include <chrono>
#include <thread>

#define DEFAULT_PORT 8080

void print(const CallQueue *queue) {
    while (true) {
        std::cout << queue->size() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
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

    try {
        Config::setFilename(argv[1]);
        Config &config = Config::getInstance();
    } catch (nlohmann::detail::parse_error e) {
        BOOST_LOG_TRIVIAL(fatal) << "Config initialization: syntax error while parsing config file";
        return -1;
    } catch (FileException &e) {
        BOOST_LOG_TRIVIAL(fatal) << e.getMessage();
        return -1;
    } catch (nlohmann::detail::type_error e) {
        BOOST_LOG_TRIVIAL(fatal) << "Config initialization: some values are missing in configuration file";
        return -1;
    }
    auto *queue = new CallQueue(Config::getInstance().getQLen());
    auto *cdrWriter = new CDRWriterImpl("../cdr.txt");
    auto *service = new CallServiceImpl(*queue, *cdrWriter);
    auto *controller = new CallHttpController(*service, port);
    std::thread timeoutHandler(std::bind(&CallServiceImpl::handleCleanExpired, service));
    std::thread operatorsHandler(std::bind(&CallServiceImpl::handleSchedulingReady, service));
    std::thread t1(std::bind(print, queue));
    controller->listenGet();
    t1.detach();
    timeoutHandler.detach();
    operatorsHandler.detach();
    return 0;
}
