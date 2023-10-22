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
public:
    Route(const std::string& _airline, Airport* _origin, Airport* _destination);

private:
    Airport* destination;

public:

    const std::string &getAirline() const;

    void setAirline(const std::string &airline);

    Airport *getOrigin() const;

    void setOrigin(Airport *origin);

    Airport *getDestination() const;

    void setDestination(Airport *destination);

};


#endif //PR1_CD_ROUTE_H
