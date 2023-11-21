//
// Created by sevastian on 08.11.23.
//

#include "../include/Config.h"

void Config::init() {
    json data = jsonReader.readFile("./../config.json");
    qLen = data["pi"];
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