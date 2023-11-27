//
// Created by sevastian on 24.11.23.
//

#ifndef CALLCENTER_CALLSERVICEIMPL_H
#define CALLCENTER_CALLSERVICEIMPL_H

#include "CallService.h"
#include "CallQueue.h"
#include <list>

class CallServiceImpl : public CallService {
    CallQueue queue;
    static uint64_t idGen;

public:
    explicit CallServiceImpl(CallQueue &queue): queue(queue) {};

    bool handleCall(std::string &number) override;
    void handleCleanExpired() override;
    void service() override;
};

#endif //CALLCENTER_CALLSERVICEIMPL_H
