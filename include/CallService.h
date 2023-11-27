//
// Created by sevastian on 24.11.23.
//

#ifndef CALLCENTER_ABSTRACTCALLSERVICE_H
#define CALLCENTER_ABSTRACTCALLSERVICE_H

#include "CallInfo.h"

class CallService {
public:
    virtual bool handleCall(std::string &number) = 0;
    virtual void handleCleanExpired() = 0;
    virtual void service() = 0;
    virtual ~CallService() = default;
};

#endif //CALLCENTER_ABSTRACTCALLSERVICE_H
