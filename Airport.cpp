//
// Created by fotop on 27/09/2023.
//

#include "Airport.h"

Airport::Airport() {
    id = 0;
    ident = "";
    type = "";
    name = "";
    location = UTM();
    continent = "";
    country_iso = "";
}

Airport::Airport(int _id) {
    this->id = _id;
    ident = "";
    type = "";
    name = "";
    location = UTM();
    continent = "";
    country_iso = "";
}

Airport::Airport(int _id, std::string _ident, std::string _type, std::string _name, UTM _location,
                 std::string _continent, std::string _country_iso) {
    id = _id;
    ident = _ident;
    type = _type;
    name = _name;
    location = _location;
    continent = _continent;
    country_iso = _country_iso;
}

const int &Airport::getId() const {
    return id;
}

void Airport::setId(const int &id) {
    Airport::id = id;
}

const std::string &Airport::getIdent() const {
    return ident;
}

void Airport::setIdent(const std::string &ident) {
    Airport::ident = ident;
}

const std::string &Airport::getType() const {
    return type;
}

void Airport::setType(const std::string &type) {
    Airport::type = type;
}

const std::string &Airport::getName() const {
    return name;
}

void Airport::setName(const std::string &name) {
    Airport::name = name;
}

const UTM &Airport::getLocation() const {
    return location;
}

void Airport::setLocation(const UTM &location) {
    Airport::location = location;
}

const std::string &Airport::getContinent() const {
    return continent;
}

void Airport::setContinent(const std::string &continent) {
    Airport::continent = continent;
}

const std::string &Airport::getCountryIso() const {
    return country_iso;
}

void Airport::setCountryIso(const std::string &countryIso) {
    country_iso = countryIso;
}

bool Airport::operator<(const Airport &origin) {
    if (this->id < origin.id) {
        return true;
    }
    return false;

}

bool Airport::operator>(const Airport &origin) {
    if (this->id > origin.id) {
        return true;
    }
    return false;

}

bool Airport::operator==(const Airport &origin) {
    if (this->id == origin.id){
        return true;
    }
    return false;
}
