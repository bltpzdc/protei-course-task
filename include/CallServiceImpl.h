//
// Created by sevastian on 24.11.23.
//

#ifndef CALLCENTER_CALLSERVICEIMPL_H
#define CALLCENTER_CALLSERVICEIMPL_H

#include "CallService.h"

class CallServiceImpl : public CallService {
public:
    CallInfo& addCall(std::string &number) const override;
    void service() const override;
};

#endif //CALLCENTER_CALLSERVICEIMPL_H
