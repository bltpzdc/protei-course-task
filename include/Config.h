//
// Created by sevastian on 08.11.23.
//

#ifndef CALLCENTER_CONFIG_H
#define CALLCENTER_CONFIG_H

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <boost/log/trivial.hpp>
#include <ctime>
#include "JsonReader.h"
#include "JsonReaderImpl.h"

using json = nlohmann::json;

class Config{
    static Config *instance; 
    static std::string filename;
    const JsonReader &jsonReader;
    uint32_t qLen;
    std::time_t randomExpirationTimeMin;
    std::time_t randomExpirationTimeMax;
    uint64_t operatorsCount;
    uint64_t nextUpdateTime;
    std::string cdrFile;


    explicit Config(const JsonReaderImpl *jsonReader): jsonReader(*jsonReader) {};
    void init();

public:
    Config(const Config&) = delete;
    void operator=(const Config&) = delete;

    static Config& getInstance();
    static void update();
    static void clear();
    static void setFilename(std::string filename);

    [[nodiscard]] uint32_t getQLen() const;
    [[nodiscard]] std::time_t getRandomExpirationTimeMin() const;
    [[nodiscard]] std::time_t getRandomExpirationTimeMax() const;
    [[nodiscard]] uint64_t getOperatorsCount() const;
    [[nodiscard]] uint64_t getNextUpdateTime() const;
    [[nodiscard]] std::string getCDRFile() const;
};

#endif //CALLCENTER_CONFIG_H
