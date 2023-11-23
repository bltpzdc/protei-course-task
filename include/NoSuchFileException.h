//
// Created by sevastian on 22.11.23.
//

#ifndef CALLCENTER_NOSUCHFILEEXCEPTION_H
#define CALLCENTER_NOSUCHFILEEXCEPTION_H

#include "./FileException.h"

class NoSuchFileException : public FileException {
    std::string filename;
public:
    NoSuchFileException(std::string message, std::string filename):
            FileException(std::move(message)), filename(std::move(filename)) {}

    std::string getMessage() override;
};

#endif //CALLCENTER_NOSUCHFILEEXCEPTION_H
