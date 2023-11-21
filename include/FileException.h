//
// Created by sevastian on 21.11.23.
//

#ifndef CALLCENTER_FILEEXCEPTION_H
#define CALLCENTER_FILEEXCEPTION_H

#include <string>
#include <utility>

class FileException {
    std::string message;

public:
    explicit FileException(std::string  message): message(std::move(message)) {}
    virtual std::string getMessage() {
        return message;
    }
    virtual ~FileException() = default;
};

class NoSuchFileException : public FileException {
    std::string filename;
public:
    explicit NoSuchFileException(std::string message, std::string filename):
                FileException(std::move(message)), filename(std::move(filename)) {}
    std::string getMessage() override {
        return FileException::getMessage() + filename;
    }
};

#endif //CALLCENTER_FILEEXCEPTION_H
