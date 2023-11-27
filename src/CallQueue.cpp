//
// Created by sevastian on 24.11.23.
//

#include "../include/CallQueue.h"

bool CallQueue::tryPush(CallInfo &callInfo) {
    if (queue->size() >= maxSize) return false;
    queue->push_back(callInfo);
    return true;
}

uint32_t CallQueue::size() const {
    return queue->size();
}

CallInfo &CallQueue::pop() {
    CallInfo &callInfo = queue->front();
    queue->pop_front();
    return callInfo;
}

