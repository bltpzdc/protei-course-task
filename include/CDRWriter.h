//
// Created by sevastian on 27.11.23.
//

#ifndef CALLCENTER_CDRWRITER_H
#define CALLCENTER_CDRWRITER_H

#include "CallInfo.h"

class CDRWriter {
public:
    virtual void writeCDR(const CallInfo &callInfo) = 0;
    virtual ~CDRWriter() = default;
};

#endif //CALLCENTER_CDRWRITER_H
