//
// Created by sevastian on 21.11.23.
//

#ifndef CALLCENTER_JSONREADERIMPL_H
#define CALLCENTER_JSONREADERIMPL_H

#include "./JsonReader.h"
#include "FileException.h"

class JsonReaderImpl : public JsonReader {
public:
    json readFile(const std::string &filename) const override {
        std::fstream fs;
        fs.open(filename);
        if (!fs.is_open())
            throw NoSuchFileException("JsonReaderImpl: can not find file ", filename);
        json data = json::parse(fs);
        fs.close();
        BOOST_LOG_TRIVIAL(info) << "JsonReaderImpl: successfully read " + filename;
        return data;
    }

    json readRaw(const std::string &string) const override {
        return json::parse(string);
    }
};

#endif //CALLCENTER_JSONREADERIMPL_H
