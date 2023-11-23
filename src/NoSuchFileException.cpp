//
// Created by sevastian on 23.11.23.
//

#include "../include/NoSuchFileException.h"

std::string NoSuchFileException::getMessage() {
    return FileException::getMessage() + filename;
}
