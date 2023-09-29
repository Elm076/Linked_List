// pr1_ADRI_verano_contenedores_dina.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include "Dynamic_container.h"
#include "UTM.h"
#include "Airport.h"

/**
 * @author Adrián González Pérez
 */
int main() {

    Dynamic_container<Airport> airports;

    std::ifstream stream;
    std::stringstream  columns;
    std::string line;

    std::string id;
    std::string ident;
    std::string type;
    std::string name;
    std::string strLatitude;
    std::string strLongitude;
    std::string continent;
    std::string country_iso;

    std::cout << ".....Inicio del programa....." << std::endl;

    stream.open("..\\aeropuertos.csv"); //project folder
    if (stream.good()) {

        clock_t t_ini = clock();

        while (getline(stream, line)) {

            //¿Exists a new line on the file?
            if (!line.empty()) {

                columns.str(line);

                //Line format: id;ident;type;size;fecha;country_iso

                getline(columns, id, ';'); //we read the line till ';' and omit the caracter
                getline(columns, ident, ';');
                getline(columns, type, ';');
                getline(columns, name, ';');
                getline(columns, strLatitude, ';');
                getline(columns, strLongitude, ';');
                getline(columns, continent, ';');
                getline(columns, country_iso, ';');

                line = "";
                columns.clear();
                UTM location = UTM(strLatitude,strLongitude);
                airports.add(Airport(std::stoi(id), ident, type, name, location, continent, country_iso));

            }   
        }

        stream.close();

        std::cout << "Reading Time: " << ((clock() - t_ini) / (float)CLOCKS_PER_SEC) << " secs." << std::endl;
    }
    else {
        std::cout << "Fatal error opening the file" << std::endl;
    }

    std::cout << "The number of imgs stored in the container is: " << airports.used_tam() << " ." << std::endl;
    std::cout << "The first 50 airports stored are:" << std::endl << std::endl;
    for (unsigned int i = 0; i < 50; i++) {
        std::cout << "Airport number " << i << ":" << std::endl
                  << "Id: " << airports[i].getId() << std::endl
                  << "Ident: " << airports[i].getIdent() << std::endl
                  << "Type: " << airports[i].getType() << std::endl
                  << "Name: " << airports[i].getName() << std::endl
                  << "Latitude: " << airports[i].getLocation().getLatitude() << std::endl
                  << "Longitude: " << airports[i].getLocation().getLongitude() << std::endl
                  << "Continent: " << airports[i].getContinent() << std::endl
                  << "Country: " << airports[i].getCountryIso() << std::endl
                  << std::endl;
    }

    std::cout << std::endl << "The following data are the airports stored ordered by descendent ids:" << std::endl << std::endl;

    airports.reverse_order_container();
    for (unsigned int i = 0; i < 20; i++) {
        std::cout << "Airport number " << i << ":" << std::endl
                  << "Id: " << airports[i].getId() << std::endl
                  << "Ident: " << airports[i].getIdent() << std::endl
                  << "Type: " << airports[i].getType() << std::endl
                  << "Name: " << airports[i].getName() << std::endl
                  << "Latitude: " << airports[i].getLocation().getLatitude() << std::endl
                  << "Longitude: " << airports[i].getLocation().getLongitude() << std::endl
                  << "Continent: " << airports[i].getContinent() << std::endl
                  << "Country: " << airports[i].getCountryIso() << std::endl
                  << std::endl;
    }
    
    std::cout << std::endl << "The following data are the airports stored ordered by ascendent ids:" << std::endl << std::endl;

    airports.order_container();
    for (unsigned int i = 0; i < 20; i++) {
        std::cout << "Airport number " << i << ":" << std::endl
                << "Id: " << airports[i].getId() << std::endl
                << "Ident: " << airports[i].getIdent() << std::endl
                << "Type: " << airports[i].getType() << std::endl
                << "Name: " << airports[i].getName() << std::endl
                << "Latitude: " << airports[i].getLocation().getLatitude() << std::endl
                << "Longitude: " << airports[i].getLocation().getLongitude() << std::endl
                << "Continent: " << airports[i].getContinent() << std::endl
                << "Country: " << airports[i].getCountryIso() << std::endl
                << std::endl;
    }

    int ids_search[6] = {129027131,
                            263765825,
                            128371231, //this does not exists
                            130844403,
                            815967354,
                            981231423 }; //this does not exists
    std::cout << std::endl << "We are looking for some photos, we know their IDs." << std::endl
        << "We are looking for airports with ID:" << std::endl << std::endl;
        for (unsigned int i = 0; i < 6; i++) {
            std::cout << ids_search[i] << std::endl;
        }

    std::cout << std::endl << "The airports found by given ids are:" << std::endl << std::endl;

    for (unsigned int i = 0; i < airports.used_tam(); i++) {
        for (unsigned int j = 0; j < 6; j++) {
            if (airports[i].getId() == ids_search[j]) {
                std::cout << "Airport number " << i << ":" << std::endl
                          << "Id: " << airports[i].getId() << std::endl
                          << "Ident: " << airports[i].getIdent() << std::endl
                          << "Type: " << airports[i].getType() << std::endl
                          << "Name: " << airports[i].getName() << std::endl
                          << "Latitude: " << airports[i].getLocation().getLatitude() << std::endl
                          << "Longitude: " << airports[i].getLocation().getLongitude() << std::endl
                          << "Continent: " << airports[i].getContinent() << std::endl
                          << "Country: " << airports[i].getCountryIso() << std::endl
                          << std::endl;
            }
        }
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln