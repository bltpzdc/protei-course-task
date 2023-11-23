//
// Created by sevastian on 23.11.23.
//

#include "../include/JsonReaderImpl.h"

json JsonReaderImpl::readFile(const std::string &filename) const {
    std::fstream fs;
    fs.open(filename, std::fstream::in);
    if (!fs.is_open())
        throw NoSuchFileException("JsonReaderImpl: can not find or read file ", filename);
    json data = json::parse(fs);
    fs.close();
    BOOST_LOG_TRIVIAL(info) << "JsonReaderImpl: successfully read " + filename;
    return data;
}

json JsonReaderImpl::readRaw(const std::string &string) const {
    return json::parse(string);
}
