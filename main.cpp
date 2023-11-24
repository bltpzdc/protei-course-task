#include "include/Config.h"
#include "include/CallHttpController.h"

int main()
{
    try {
        Config &config = Config::getInstance();
    } catch (nlohmann::detail::parse_error e) {
        BOOST_LOG_TRIVIAL(error) << "Config initialization: syntax error while parsing config file";
        return -1;
    } catch (FileException &e) {
        BOOST_LOG_TRIVIAL(error) << e.getMessage();
        return -1;
    }
    auto *service = new CallServiceImpl();
    auto *controller = new CallHttpController(*service);
    controller->listenGet();
    return 0;
}
