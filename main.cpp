

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include "Dynamic_container.h"
#include "UTM.h"
#include "Airport.h"
#include "Linked_list.h"
#include "Iterator.h"

/**
 * @author Adrián González Pérez agp00118@red.ujaen.es
 */

int main() {

    Linked_list<int> intList;

    for(int i = 101; i < 201; i++){
        intList.push_back(i);
    }

    Iterator<int> iterator = intList.iterator();
    for(int i = 98; i > 0; i--){
        intList.push_front(i);
    }

    //here i'll try to push data using an iterator of another list and see what happens

    Linked_list<int> intList2;
    for(int i = 10000; i < 10010; i++){
        intList2.push_back(i);
    }

    Iterator<int> iterator2 = intList2.iterator();
    std::cout << "-----ELEMENTS OF THE LIST 2-----" << std::endl << std::endl;
    while (!iterator2.end()){
        std::cout << "Node with data: " << iterator2.data() << std::endl;
        iterator2.next();
    }
    iterator = intList.iterator();

    iterator2 = intList2.iterator();
    //Iterator<int> iterator2 = intList2.iterator();
    try {
        while (!iterator.end()){
            if (iterator.data() == 101){
                int data_to_insert = 100;
                intList.push_in_forward(iterator2, data_to_insert);
                break;
            }
            iterator.next();
        }
    }
    catch (std::out_of_range& err){
        std::cout << err.what() << std::endl;
    }


    while (!iterator.end()){
        if (iterator.data() == 101){
            int data_to_insert = 100;
            intList.push_in_forward(iterator, data_to_insert);
            break;
        }
        iterator.next();
    }



    Linked_list<int> intList3 = Linked_list<int>(intList2);
    Iterator<int> iterator3 = intList3.iterator();
    std::cout << "-----ELEMENTS OF THE LIST 3-----" << std::endl << std::endl;
    while (!iterator3.end()){
        std::cout << "Node with data: " << iterator3.data() << std::endl;
        iterator3.next();
    }

    Linked_list<int> intList4;

    for(int i = 200000; i < 200200; i++){
        intList4.push_back(i);
    }
    Iterator<int> iterator4 = intList4.iterator();
    std::cout << "-----ELEMENTS OF THE LIST 4-----" << std::endl << std::endl;
    while (!iterator4.end()){
        std::cout << "Node with data: " << iterator4.data() << std::endl;
        iterator4.next();
    }

    intList4 = intList3;
    iterator4 = intList4.iterator();
    std::cout << "-----ELEMENTS OF THE LIST 4-----" << std::endl << std::endl;
    while (!iterator4.end()){
        std::cout << "Node with data: " << iterator4.data() << std::endl;
        iterator4.next();
    }


    
    iterator = intList.iterator();
    while (!iterator.end()){
        if(iterator.data() == 98){
            int data_to_insert = 99;
            intList.push_in_behind(iterator,data_to_insert);
            break;
        }
        iterator.next();
    }

    for (int i = 0; i < 10; i++){
        intList.pop_front();
        intList.pop_back();
    }


    iterator = intList.iterator();
    while (!iterator.end()){
        if (iterator.data()%10 == 0){
            intList.pop(iterator);
        }
        else{
            iterator.next();
        }
    }

    iterator = intList.iterator();
    std::cout << "-----ELEMENTS OF THE LIST 1-----" << std::endl << std::endl;
    while (!iterator.end()){
        std::cout << "Node with data: " << iterator.data() << std::endl;
        iterator.next();
    }

    Linked_list<int> intList5 = intList.concatenate(intList4);
    Iterator<int> iterator5 = intList5.iterator();
    std::cout << "-----ELEMENTS OF THE LIST 5-----" << std::endl << std::endl;
    while (!iterator5.end()){
        std::cout << "Node with data: " << iterator5.data() << std::endl;
        iterator5.next();
    }

    std::cout << "----- End of the program -----" << std::endl;



/*
    Dynamic_container<Airport> airports;

    std::ifstream stream;
    std::stringstream columns;
    std::string line;

    std::string id;
    std::string iata;
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

                //Line format: id;iata;type;size;fecha;country_iso

                getline(columns, id, ';'); //we read the line till ';' and omit the caracter
                getline(columns, iata, ';');
                getline(columns, type, ';');
                getline(columns, name, ';');
                getline(columns, strLatitude, ';');
                getline(columns, strLongitude, ';');
                getline(columns, continent, ';');
                getline(columns, country_iso, ';');

                line = "";
                columns.clear();
                UTM location = UTM(strLatitude, strLongitude);
                airports.push(Airport(std::stoi(id), iata, type, name, location, continent, country_iso));
            }
        }

        stream.close();

        std::cout << "Reading Time: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " secs." << std::endl;
    } else {
        std::cout << "Fatal error opening the file" << std::endl;
    }

    std::cout << "The number of airports stored in the container is: " << airports.used_tam() << " ." << std::endl;

*/

}
/*





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
                  << "Ident: " << deleted_data[i].getIata() << std::endl
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
*/
 // Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln