//
// Created by sevastian on 08.11.23.
//

#ifndef CALLCENTER_CONFIG_H
#define CALLCENTER_CONFIG_H

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <boost/log/trivial.hpp>

using json = nlohmann::json;

class Config{
    bool isInitialized = false;
    unsigned int qLen;

    Config() = default;
    void init();

public:
    Config(const Config&) = delete;
    void operator=(const Config&) = delete;

    static Config& getInstance();
    [[nodiscard]] unsigned int getQLen() const {
        return qLen;
    }
};

#endif //CALLCENTER_CONFIG_H
