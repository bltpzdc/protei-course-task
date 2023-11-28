//
// Created by sevastian on 24.11.23.
//

#ifndef CALLCENTER_CALLSERVICEIMPL_H
#define CALLCENTER_CALLSERVICEIMPL_H

#include "CallService.h"
#include "CallQueue.h"
#include "CDRWriterImpl.h"
#include <list>

class CallServiceImpl : public CallService {
    CallQueue &queue;
    static uint64_t idGen;
    CDRWriter &cdrWriter;

public:
    explicit CallServiceImpl(CallQueue &queue, CDRWriter &cdrWriter): queue(queue), cdrWriter(cdrWriter) {};

    bool handleCall(std::string &number) override;
    void handleCleanExpired() override;
    void service() override;
};

#endif //CALLCENTER_CALLSERVICEIMPL_H
