//
// Created by sevastian on 23.11.23.
//

#ifndef CALLCENTER_HTTPCONTROLLER_H
#define CALLCENTER_HTTPCONTROLLER_H

#include <string>
#include "./crow_all.h"

class HttpController {
public:
    virtual ~HttpController() = default;

    virtual void listenGet() = 0;
    virtual void listenPost() = 0;
    virtual void listenPut() = 0;
    virtual void listenDelete() = 0;
};


#endif //CALLCENTER_HTTPCONTROLLER_H
