//
// Created by sevastian on 23.11.23.
//

#include "../include/PhoneHttpController.h"

void PhoneHttpController::listenGet() {
    CROW_ROUTE(app, "/")
            ([](const crow::request &req) {
                std::string number;
                try {
                    number = std::string(req.url_params.get("phoneNumber"));
                } catch (std::exception e) {
                    return crow::response(400, "Phone number must be specified in query parameters");
                }
                if (number.empty())
                    return crow::response(400, "Phone number can not be an empty value");
                return crow::response(200, "Ok");
            });

    app.port(8080).multithreaded().run();
}

// Stubs for unused methods
// Can be refactored in next ver
void PhoneHttpController::listenPost() {}

void PhoneHttpController::listenPut() {}

void PhoneHttpController::listenDelete() {}