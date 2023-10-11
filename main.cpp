

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include "Dynamic_container.h"
#include "UTM.h"
#include "Airport.h"

/**
 * @author Adrián González Pérez agp00118@red.ujaen.es
 */

int main() {

    Dynamic_container<Airport> airports;

    std::ifstream stream;
    std::stringstream columns;
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

    stream.open("..\\aeropuertos_v2.csv"); //project folder
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
                UTM location = UTM(strLatitude, strLongitude);
                airports.push(Airport(std::stoi(id), ident, type, name, location, continent, country_iso));
            }
        }

        stream.close();

        std::cout << "Reading Time: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " secs." << std::endl;
    } else {
        std::cout << "Fatal error opening the file" << std::endl;
    }

    std::cout << "The number of imgs stored in the container is: " << airports.used_tam() << " ." << std::endl;






    clock_t time_stamp_1 = clock();
    airports.sort_container();
    std::cout << "Sort data structure Time: " << ((clock() - time_stamp_1) / (float) CLOCKS_PER_SEC) << " secs." << std::endl;

    std::cout << std::endl << "The following data are the airports stored ordered by ascendent ids:" << std::endl
              << std::endl;
    std::cout << "The first 30 airports stored are:" << std::endl << std::endl;
    for (unsigned int i = 0; i < 30; i++) {
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






    clock_t time_stamp_2 = clock();
    airports.reverse_sort_container();
    std::cout << "Reverse Sort data structure Time: " << ((clock() - time_stamp_2) / (float) CLOCKS_PER_SEC) << " secs." << std::endl;

    std::cout << std::endl << "The following data are the airports stored ordered by descendent ids:" << std::endl
              << std::endl;
    std::cout << "The first 30 airports stored are:" << std::endl << std::endl;

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






    const int SIZE_AIRPORT_TO_SEARCH = 5;
    Airport *airportToSearch = new Airport[SIZE_AIRPORT_TO_SEARCH];
    airportToSearch[0] = Airport(345166);
    airportToSearch[1] = Airport(6640);
    airportToSearch[2] = Airport(6676);
    airportToSearch[3] = Airport(345364);
    airportToSearch[4] = Airport(6778);


    std::cout << std::endl << "We are looking for some airports, we know their IDs." << std::endl
              << "We are looking for airports with ID:" << std::endl << std::endl;
    for (unsigned int i = 0; i < SIZE_AIRPORT_TO_SEARCH; i++) {
        std::cout << airportToSearch[i].getId() << std::endl;
    }

    std::cout << std::endl << "The airports found by given ids are:" << std::endl << std::endl;
    clock_t time_stamp_3 = clock();
    for(unsigned int i = 0; i < SIZE_AIRPORT_TO_SEARCH; i++){
        int found = airports.binary_search(airportToSearch[i]);
        if (found != -1){
            std::cout << "----- Found! ----- \n Airport with id: " << airportToSearch[i].getId()
                        << " located at position: " << found << " ."<< std::endl
                        << std::endl;
        }
    }
    std::cout << "Bynary Search inside data structure Time: " << ((clock() - time_stamp_3) / (float) CLOCKS_PER_SEC) << " secs." << std::endl
            << std::endl;






    std::cout << "Deleting the airports which are located at 'NA'" << std::endl << std::endl;

    Dynamic_container<Airport> deleted_data;
    clock_t time_stamp_4 = clock();
    for(unsigned int i = airports.used_tam(); i > 0; i --){
        if(airports[i].getContinent() == "NA"){
            //std::cout << "Deleted airport with id: " << airports.pop(i).getId() << " ." << std::endl;
            deleted_data.push(airports.pop(i));
        }

    }
    std::cout << "Deleting Time: " << ((clock() - time_stamp_4) / (float) CLOCKS_PER_SEC) << " secs." << std::endl;

    std::cout << "Number of airports now: " << airports.used_tam() << std::endl;
    std::cout << "Number of airports now in the deleted_data Dynamic Container: " << deleted_data.used_tam() << std::endl;

    for (unsigned int i = 0; i < 20; i++){
        std::cout << "Airport deleted number " << i << ":" << std::endl
                  << "Id: " << deleted_data[i].getId() << std::endl
                  << "Ident: " << deleted_data[i].getIdent() << std::endl
                  << "Type: " << deleted_data[i].getType() << std::endl
                  << "Name: " << deleted_data[i].getName() << std::endl
                  << "Latitude: " << deleted_data[i].getLocation().getLatitude() << std::endl
                  << "Longitude: " << deleted_data[i].getLocation().getLongitude() << std::endl
                  << "Continent: " << deleted_data[i].getContinent() << std::endl
                  << "Country: " << deleted_data[i].getCountryIso() << std::endl
                  << std::endl;
    }

    std::cout << "----- End of the program -----" << std::endl;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
