//
// Created by sevastian on 28.11.23.
//

#ifndef CALLCENTER_CDRWRITERIMPL_H
#define CALLCENTER_CDRWRITERIMPL_H

#include <string>
#include <iostream>
#include <fstream>
#include "../include/FileException.h"
#include "CDRWriter.h"

class CDRWriterImpl : public CDRWriter {
    std::ofstream fileStream;
public:
    CDRWriterImpl(const std::string &filename){
        fileStream.open(filename, std::ios::out);
        std::cout << fileStream.fail();
    }

    void writeCDR(const CallInfo &callInfo) override;

    ~CDRWriterImpl() {
        if (fileStream.is_open()) {
            fileStream.close();
        }
    }
};

#endif //CALLCENTER_CDRWRITERIMPL_H
