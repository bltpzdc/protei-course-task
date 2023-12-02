//
// Created by sevastian on 08.11.23.
//

#include "../include/Config.h"

std::string Config::filename = "";
Config *Config::instance = nullptr;

void Config::init() {
    json data = jsonReader.readFile(Config::filename);
    qLen = data["queue_length"];
    randomExpirationTimeMin = data["expire_random_min"];
    randomExpirationTimeMax = data["expire_random_max"];
    operatorsCount = data["operators_count"];
    nextUpdateTime = data["next_update_time"];
}

void Config::update() {
    Config *newInstance = new Config(new JsonReaderImpl());
    try {
        newInstance->init();
    } catch (...) {
        BOOST_LOG_TRIVIAL(warning) << "Config: can not be updated. Check configuration file";
        delete newInstance;
        return;
    }
    Config *tmp = Config::instance;
    instance = newInstance;
    newInstance = tmp;
    delete newInstance;
    BOOST_LOG_TRIVIAL(info) << "Config: updated successfully";
}

Config& Config::getInstance(){
    if (!instance) {
        instance = new Config(new JsonReaderImpl());
        instance->init();
        BOOST_LOG_TRIVIAL(info) << "Config initialization: success";
    }
    return *instance;
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

uint64_t Config::getNextUpdateTime() const {
    return nextUpdateTime;
}

void Config::setFilename(std::string filename) {
    Config::filename = std::move(filename);
}