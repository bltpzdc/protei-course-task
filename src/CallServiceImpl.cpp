//
// Created by sevastian on 24.11.23.
//

#include "../include/CallServiceImpl.h"

CallInfo &CallServiceImpl::addCall(std::string &number) const {
    auto *callInfo = new CallInfo(number);
    return *callInfo;
}

void CallServiceImpl::service() const {
    while (true) {
        //do nothing
    }
}
