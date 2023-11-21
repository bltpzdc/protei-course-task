//
// Created by sevastian on 21.11.23.
//

#ifndef CALLCENTER_JSONREADERIMPL_H
#define CALLCENTER_JSONREADERIMPL_H

#include "./JsonReader.h"

class JsonReaderImpl : public JsonReader {
public:
    json readFile(const std::string &filename) override {
        std::fstream fs;
        fs.open(filename);
        json data = json::parse(fs);
        fs.close();
        return data;
    }

    json readRaw(const std::string &string) override {
        return json::parse(string);
    }
};

#endif //CALLCENTER_JSONREADERIMPL_H
