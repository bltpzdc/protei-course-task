//
// Created by sevastian on 21.11.23.
//

#ifndef CALLCENTER_FILEEXCEPTION_H
#define CALLCENTER_FILEEXCEPTION_H

#include <string>

class FileException {
    std::string message;

public:
    explicit FileException(std::string  message): message(std::move(message)) {}
    virtual std::string getMessage() {
        return message;
    }
    virtual ~FileException() = default;
};

#endif //CALLCENTER_FILEEXCEPTION_H
