//
// Created by sevastian on 24.11.23.
//

#ifndef CALLCENTER_CALLQUEUE_H
#define CALLCENTER_CALLQUEUE_H

#include <stdint.h>
#include <list>
#include "CallInfo.h"

class CallQueue {
    uint32_t maxSize;
    std::list<CallInfo> *queue;

public:
    explicit CallQueue(uint32_t maxSize): maxSize(maxSize) {
        queue = new std::list<CallInfo>();
    }

    bool tryPush(CallInfo &callInfo);
    uint32_t size() const;
    CallInfo& pop();
    std::list<CallInfo> &getQueue();
};

#endif //CALLCENTER_CALLQUEUE_H
