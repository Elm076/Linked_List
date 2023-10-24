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
    VuelaFlight() = default;

    VuelaFlight(std::string airports_file, std::string routes_file);

    const Dynamic_container<Airport> &getAirports() const;

    const Linked_list<Route> &getRoutes() const;

    Route& origDestRoutesSearch(const std::string& airportIataOrig, const std::string& airportIataDest);

    Dynamic_container<Route> origRoutesSearch(std::string airportIataOrig);

    Dynamic_container<Airport> countryAirportSearch(std::string country);

    void addNewRoute(std::string origAirportIata, std::string destAirportIata, std::string airline);
};



#endif //PR1_CD_VUELAFLIGHT_H
