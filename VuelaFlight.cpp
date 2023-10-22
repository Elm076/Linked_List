//
// Created by fotop on 24/10/2023.
//

#include "VuelaFlight.h"
#include <fstream>
#include <sstream>

VuelaFlight::VuelaFlight(std::string airports_file, std::string routes_file) {

    std::ifstream airports_stream;
    std::stringstream columns_airports;
    std::string line;

    std::string id;
    std::string ident;
    std::string type;
    std::string name;
    std::string strLatitude;
    std::string strLongitude;
    std::string continent;
    std::string country_iso;

    std::cout << ".....Start of the program....." << std::endl;

    airports_stream.open(airports_file); //project folder
    if (airports_stream.good()) {

        clock_t t_ini = clock();

        while (getline(airports_stream, line)) {

            //¿Exists a new line on the file?
            if (!line.empty()) {

                columns_airports.str(line);

                //Line format: id;iata;type;size;fecha;country_iso

                getline(columns_airports, id, ';'); //we read the line till ';' and omit the caracter
                getline(columns_airports, ident, ';');
                getline(columns_airports, type, ';');
                getline(columns_airports, name, ';');
                getline(columns_airports, strLatitude, ';');
                getline(columns_airports, strLongitude, ';');
                getline(columns_airports, continent, ';');
                getline(columns_airports, country_iso, ';');

                line = "";
                columns_airports.clear();
                UTM location = UTM(strLatitude, strLongitude);
                airports.push(Airport(std::stoi(id), ident, type, name, location, continent, country_iso));
            }
        }

        airports_stream.close();

        std::cout << " Dynamic_container with airports initialized./n Reading Time: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " secs." << std::endl;
    } else {
        std::cout << "Fatal error opening the file" << std::endl;
    }

    airports.sort_container();



    std::string airline;
    std::string orig_airport;
    std::string dest_airport;

    std::ifstream routes_stream;
    std::stringstream columns_routes;
    routes_stream.open(routes_file); //project folder
    if (routes_stream.good()) {

        clock_t t_ini = clock();

        while (getline(routes_stream, line)) {

            //¿Exists a new line on the file?
            if (!line.empty()) {

                columns_routes.str(line);

                //Line format: id;iata;type;size;fecha;country_iso

                getline(columns_routes, airline, ';'); //we read the line till ';' and omit the caracter
                getline(columns_routes, orig_airport, ';');
                getline(columns_routes, dest_airport, ';');

                line = "";
                columns_routes.clear();

                routes.push_back(Route(airline,orig_airport,dest_airport));
            }
        }

        airports_stream.close();

        std::cout << " Dynamic_container with airports initialized./n Reading Time: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " secs." << std::endl;
    } else {
        std::cout << "Fatal error opening the file" << std::endl;
    }

}
