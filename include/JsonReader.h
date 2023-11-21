//
// Created by sevastian on 21.11.23.
//

#ifndef CALLCENTER_JSONREADER_H
#define CALLCENTER_JSONREADER_H

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <boost/log/trivial.hpp>

using json = nlohmann::json;

class JsonReader {
public:
    virtual json readFile(const std::string &filename) = 0;
    virtual json readRaw(const std::string &string) = 0;
    virtual ~JsonReader() = default;
};

#endif //CALLCENTER_JSONREADER_H
