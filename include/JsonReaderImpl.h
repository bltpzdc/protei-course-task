//
// Created by sevastian on 21.11.23.
//

#ifndef CALLCENTER_JSONREADERIMPL_H
#define CALLCENTER_JSONREADERIMPL_H

#include "./JsonReader.h"
#include "./FileException.h"
#include "./NoSuchFileException.h"

class JsonReaderImpl : public JsonReader {
public:
    json readFile(const std::string &filename) const override;
    json readRaw(const std::string &string) const override;
};

#endif //CALLCENTER_JSONREADERIMPL_H
