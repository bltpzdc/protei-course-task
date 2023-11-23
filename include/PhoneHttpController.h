//
// Created by sevastian on 23.11.23.
//

#ifndef CALLCENTER_PHONECONTROLLER_H
#define CALLCENTER_PHONECONTROLLER_H

#include "./HttpController.h"

class PhoneHttpController : public HttpController {
    //TODO service
    crow::SimpleApp app;

public:
    PhoneHttpController(/*TODO service DI*/) = default;

    void listenGet() override;
    void listenPost() override;
    void listenPut() override;
    void listenDelete() override;
};

#endif //CALLCENTER_PHONECONTROLLER_H
