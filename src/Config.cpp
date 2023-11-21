//
// Created by sevastian on 08.11.23.
//

#include "../include/Config.h"

void Config::init() {
    std::fstream fs;
    fs.open("./../config.json");
    json data = json::parse(fs);
    qLen = data["pi"];
    fs.close();
}

Config& Config::getInstance(){
    static Config instance;
    if (!instance.isInitialized) {
        instance.init();
        instance.isInitialized = true;
        BOOST_LOG_TRIVIAL(info) << "Config has been initialized";
    }
    return instance;
}