//
// Created by sevastian on 24.11.23.
//

#ifndef CALLCENTER_CALLQUEUE_H
#define CALLCENTER_CALLQUEUE_H

#include <stdint.h>
#include <list>
#include "CallInfo.h"

class CallQueue {
    std::list<CallInfo> *queue;

public:
    CallQueue() {
        queue = new std::list<CallInfo>();
    }

    ~CallQueue() {
        delete queue;
    }
    
    bool tryPush(CallInfo &callInfo);
    uint32_t size() const;
    CallInfo& pop();
    std::list<CallInfo> &getQueue();
};

#endif //CALLCENTER_CALLQUEUE_H
