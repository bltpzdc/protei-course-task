//
// Created by sevastian on 23.11.23.
//

#include "../include/CallHttpController.h"
#include "../include/CallInfo.h"

void CallHttpController::listenGet() {
    CROW_ROUTE(app, "/")
            ([this](const crow::request &req) {
                std::string number;
                try {
                    number = std::string(req.url_params.get("phoneNumber"));
                } catch (std::exception e) {
                    return crow::response(400, "Phone number must be specified in query parameters");
                }
                if (number.empty())
                    return crow::response(400, "Phone number can not be an empty value");
                service.addCall(number);
                return crow::response(200, "Ok");
            });

    app.port(8080).multithreaded().run();
}

// Stubs for unused methods
// Can be refactored in next ver
void CallHttpController::listenPost() {}
void CallHttpController::listenPut() {}
void CallHttpController::listenDelete() {}