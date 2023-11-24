//
// Created by sevastian on 24.11.23.
//

#ifndef CALLCENTER_ABSTRACTCALLSERVICE_H
#define CALLCENTER_ABSTRACTCALLSERVICE_H

#include "CallInfo.h"

class CallService {
public:
    virtual CallInfo& addCall(std::string &number) const = 0;
    virtual void service() const = 0;
    virtual ~CallService() = default;
};

#endif //CALLCENTER_ABSTRACTCALLSERVICE_H
