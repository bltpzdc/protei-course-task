//
// Created by sevastian on 24.11.23.
//

#include "../include/CallServiceImpl.h"

bool CallServiceImpl::addCall(std::string &number) {
    CallInfo callInfo(number);
    return queue.tryPush(callInfo);
}

void CallServiceImpl::service() {
    while (true) {
        //do nothing
    }
}
