//
// Created by fotop on 24/10/2023.
//

#ifndef PR1_CD_VUELAFLIGHT_H
#define PR1_CD_VUELAFLIGHT_H

#include <iostream>
#include "Dynamic_container.h"
#include "Linked_list.h"
#include "Airport.h"
#include "Route.h"

class VuelaFlight {
private:
    Dynamic_container<Airport> airports;
    Linked_list<Route> routes;
public:
    VuelaFlight() { airports = Dynamic_container<Airport>();
                    routes = Linked_list<Route>();
    }
    VuelaFlight(std::string airports_file, std::string routes_file);
};


#endif //PR1_CD_VUELAFLIGHT_H
