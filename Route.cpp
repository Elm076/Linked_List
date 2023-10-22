//
// Created by fotop on 22/10/2023.
//

#include "Route.h"

const std::string &Route::getAirline() const {
    return airline;
}

void Route::setAirline(const std::string &airline) {
    Route::airline = airline;
}

Airport *Route::getOrigin() const {
    return origin;
}

void Route::setOrigin(Airport *origin) {
    Route::origin = origin;
}

Airport *Route::getDestination() const {
    return destination;
}

void Route::setDestination(Airport *destination) {
    Route::destination = destination;
}

Route::Route(std::string& _airline, Airport* _origin, Airport* _destination) :
    airline(_airline),
    origin(_origin),
    destination(_destination)
    {}

    Route::~Route() = default;
