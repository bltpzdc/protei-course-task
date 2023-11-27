//
// Created by sevastian on 23.11.23.
//

#ifndef CALLCENTER_PHONECONTROLLER_H
#define CALLCENTER_PHONECONTROLLER_H

#include "./HttpController.h"
#include "CallServiceImpl.h"

class CallHttpController : public HttpController {
    crow::SimpleApp app;
    CallService &service;

public:
    explicit CallHttpController(CallService &service): service(service) {};

    void listenGet() override;
    void listenPost() override;
    void listenPut() override;
    void listenDelete() override;
};

#endif //CALLCENTER_PHONECONTROLLER_H
