

#include <iostream>
#include <string>
#include <ctime>
#include "Dynamic_container.h"
#include "Airport.h"
#include "Linked_list.h"
#include "Iterator.h"
#include "VuelaFlight.h"

/**
 * @author Adrián González Pérez agp00118@red.ujaen.es
 */

int main() {

    std::cout << ".....Start of the program 1....." << std::endl;

    Linked_list<int> intList;

    for (int i = 101; i < 201; i++) {
        intList.push_back(i);
    }

    Iterator<int> iterator = intList.iterator();
    for (int i = 98; i > 0; i--) {
        intList.push_front(i);
    }

    //here i'll try to push data using an iterator of another list and see what happens

    Linked_list<int> intList2;
    for (int i = 10000; i < 10010; i++) {
        intList2.push_back(i);
    }

    Iterator<int> iterator2 = intList2.iterator();
    std::cout << "-----ELEMENTS OF THE LIST 2-----" << std::endl << std::endl;
    while (!iterator2.end()) {
        std::cout << "Node with data: " << iterator2.data() << std::endl;
        iterator2.next();
    }
    iterator = intList.iterator();

    iterator2 = intList2.iterator();
    //Iterator<int> iterator2 = intList2.iterator();
    try {
        while (!iterator.end()) {
            if (iterator.data() == 101) {
                int data_to_insert = 100;
                intList.push_in_forward(iterator2, data_to_insert);
                break;
            }
            iterator.next();
        }
    }
    catch (std::out_of_range &err) {
        std::cout << err.what() << std::endl;
    }


    while (!iterator.end()) {
        if (iterator.data() == 101) {
            int data_to_insert = 100;
            intList.push_in_forward(iterator, data_to_insert);
            break;
        }
        iterator.next();
    }


    Linked_list<int> intList3 = Linked_list<int>(intList2);
    Iterator<int> iterator3 = intList3.iterator();
    std::cout << "-----ELEMENTS OF THE LIST 3-----" << std::endl << std::endl;
    while (!iterator3.end()) {
        std::cout << "Node with data: " << iterator3.data() << std::endl;
        iterator3.next();
    }

    Linked_list<int> intList4;

    for (int i = 200000; i < 200200; i++) {
        intList4.push_back(i);
    }
    Iterator<int> iterator4 = intList4.iterator();
    std::cout << "-----ELEMENTS OF THE LIST 4-----" << std::endl << std::endl;
    while (!iterator4.end()) {
        std::cout << "Node with data: " << iterator4.data() << std::endl;
        iterator4.next();
    }

    intList4 = intList3;
    iterator4 = intList4.iterator();
    std::cout << "-----ELEMENTS OF THE LIST 4-----" << std::endl << std::endl;
    while (!iterator4.end()) {
        std::cout << "Node with data: " << iterator4.data() << std::endl;
        iterator4.next();
    }


    iterator = intList.iterator();
    while (!iterator.end()) {
        if (iterator.data() == 98) {
            int data_to_insert = 99;
            intList.push_in_behind(iterator, data_to_insert);
            break;
        }
        iterator.next();
    }

    for (int i = 0; i < 10; i++) {
        intList.pop_front();
        intList.pop_back();
    }


    iterator = intList.iterator();
    while (!iterator.end()) {
        if (iterator.data() % 10 == 0) {
            intList.pop(iterator);
        } else {
            iterator.next();
        }
    }

    iterator = intList.iterator();
    std::cout << "-----ELEMENTS OF THE LIST 1-----" << std::endl << std::endl;
    while (!iterator.end()) {
        std::cout << "Node with data: " << iterator.data() << std::endl;
        iterator.next();
    }

    Linked_list<int> intList5 = intList.concatenate(intList4);
    Iterator<int> iterator5 = intList5.iterator();
    std::cout << "-----ELEMENTS OF THE LIST 5-----" << std::endl << std::endl;
    while (!iterator5.end()) {
        std::cout << "Node with data: " << iterator5.data() << std::endl;
        iterator5.next();
    }

    std::cout << ".....Start of the program 2....." << std::endl;

    VuelaFlight data_base("..\\aeropuertos_v2.csv", "..\\\\rutas_v1.csv");


    try {
        std::cout << "The route specified is provided by the airline "
                  << data_base.origDestRoutesSearch("BCN", "IST").getAirline() << std::endl;
    } catch (std::invalid_argument err) {
        std::cout << err.what() << std::endl;
    }

    try {
        Dynamic_container<Route> routes_GRX = data_base.origRoutesSearch("GRX");
        for (unsigned int i = 0; i < routes_GRX.used_tam(); i++) {
            if (routes_GRX[i].getDestination()->getCountryIso() == "GB") {
                std::cout << "Found route with origin in GRX and destination in Great Britain with destiny airport "
                          << routes_GRX[i].getDestination()->getIata() << std::endl;
            }
        }
    } catch (std::invalid_argument err) {
        std::cout << err.what() << std::endl;
    }

    try {
        std::cout << "Number of routes stored: " << data_base.getRoutes().list_size() << std::endl;
        data_base.addNewRoute("GRX", "CDG", "IBE");
        data_base.addNewRoute("CDG", "GRX", "IBE");
        std::cout << "Number of routes stored: " << data_base.getRoutes().list_size() << std::endl;
    } catch (std::invalid_argument err) {
        std::cout << err.what() << std::endl;
    }

/*
 * Tried to make the optional exercise work. I couldn't make it so I commented it
 *
        Dynamic_container<Route> routes_ESP_PRT;
        clock_t t_ini = clock();
        Dynamic_container<Airport> airports_ESP(data_base.countryAirportSearch("ES"));

        for (unsigned int i = 0; i < airports_ESP.used_tam(); i++) {
            try {
                Dynamic_container<Route> routes_for_actual_airport(
                        data_base.origRoutesSearch(airports_ESP[i].getIata()));

                for (unsigned int j = 0; j < routes_for_actual_airport.used_tam(); j++) {
                    if (routes_for_actual_airport[i].getDestination()->getCountryIso() == "PRT") {
                        routes_ESP_PRT.push(routes_for_actual_airport[i]);
                    }
                }
            }
            catch (std::out_of_range err){
                err.what();
            }
        }
        std::cout << " All airports ESP to PRT found ." << std::endl << " Searching Time: "
                  << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " secs." << std::endl;
        for (unsigned int i = 0; i < routes_ESP_PRT.used_tam(); i++) {
            std::cout << "Found route with origin in ESP and destination in PRT with destiny airport "
                      << routes_ESP_PRT[i].getDestination()->getIata() << std::endl;
        }

*/

    std::cout << "----- End of the program -----" << std::endl;
}