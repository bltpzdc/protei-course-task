#include "include/Config.h"
#include "include/CallHttpController.h"

#include <chrono>
#include <thread>

void print(const CallQueue *queue) {
    std::cout << queue << std::endl;
    while (true) {
        std::cout << queue->size() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
}

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
    auto *queue = new CallQueue(Config::getInstance().getQLen());
    auto *service = new CallServiceImpl(*queue);
    auto *controller = new CallHttpController(*service);
    std::thread t1(std::bind(print, queue));
    std::cout << queue << std::endl;
    controller->listenGet();
    t1.detach();
    return 0;
}
