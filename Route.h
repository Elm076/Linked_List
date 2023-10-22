//
// Created by fotop on 22/10/2023.
//

#ifndef PR1_CD_ROUTE_H
#define PR1_CD_ROUTE_H

#include <iostream>
#include "Airport.h"

class Route {
private:

    std::string airline;
    Airport* origin;
    Airport* destination;

public:

    Route() {   airline = "";
                origin = nullptr;
                destination = nullptr; }

    Route(std::string& _airline, Airport* _origin, Airport* _destination);

    const std::string &getAirline() const;

    void setAirline(const std::string &airline);

    Airport *getOrigin() const;

    void setOrigin(Airport *origin);

    Airport *getDestination() const;

    void setDestination(Airport *destination);

    ~Route();

};


#endif //PR1_CD_ROUTE_H
