//
// Created by sevastian on 24.11.23.
//

#include "../include/CallQueue.h"

bool CallQueue::tryPush(CallInfo &callInfo) {
    if (queue->size() >= Config::getInstance().getQLen()) return false;
    callInfo.status = CallStatus::READY;
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

std::list<CallInfo> &CallQueue::getQueue() {
    return *queue;
}
