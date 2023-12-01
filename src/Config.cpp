//
// Created by sevastian on 08.11.23.
//

#include "../include/Config.h"

std::string Config::filename = "aboba";

void Config::init() {
    std::cout << Config::filename;
    json data = jsonReader.readFile(Config::filename);
    qLen = data["queue_length"];
    randomExpirationTimeMin = data["expire_random_min"];
    randomExpirationTimeMax = data["expire_random_max"];
    operatorsCount = data["operators_count"];
}

Config& Config::getInstance(){
    static Config instance(new JsonReaderImpl());
    if (!instance.isInitialized) {
        instance.init();
        instance.isInitialized = true;
        BOOST_LOG_TRIVIAL(info) << "Config initialization: success";
    }
    return instance;
}

uint32_t Config::getQLen() const {
    return qLen;
}


std::time_t Config::getRandomExpirationTimeMin() const {
    return randomExpirationTimeMin;
}

std::time_t Config::getRandomExpirationTimeMax() const {
    return randomExpirationTimeMax;
}

uint64_t Config::getOperatorsCount() const {
    return operatorsCount;
}

void Config::setFilename(std::string filename) {
    Config::filename = std::move(filename);
}
