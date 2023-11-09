//
// Created by sevastian on 08.11.23.
//

#include "../include/config.h"

void Config::init() {
    std::ifstream in("config.json");
    json data = json::parse(in);
    qLen = data["pi"];
    in.close();
}

Config& Config::getInstance(){
    static Config instance;
    if (!instance.isInitialized) {
        instance.init();
    }
    return instance;
}