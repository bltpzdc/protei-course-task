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
                    BOOST_LOG_TRIVIAL(info) << "Controller: request was rejected because of empty number";
                    return crow::response(400, "Phone number must be specified in query parameters");
                }
                if (number.empty()) {
                    BOOST_LOG_TRIVIAL(info) << "Controller: request was rejected because of empty number";
                    return crow::response(400, "Phone number can not be an empty value");
                }
                BOOST_LOG_TRIVIAL(info) << "Controller: got request with number " << number;
                if (!service.handleCall(number)) {
                    return crow::response(503, "Queue is full");
                }
                return crow::response(200, "Ok");
            });

    app.port(8080).multithreaded().run();
}

// Stubs for unused methods
// Can be refactored in next ver
void CallHttpController::listenPost() {}
void CallHttpController::listenPut() {}
void CallHttpController::listenDelete() {}