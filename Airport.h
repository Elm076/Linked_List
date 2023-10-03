//
// Created by fotop on 27/09/2023.
//

#ifndef PR1_CD_AIRPORT_H
#define PR1_CD_AIRPORT_H

#include <string>
#include <iostream>
#include "UTM.h"

class Airport {
private:
    int id;
    std::string ident;
    std::string type;
    std::string name;
    UTM location;
    std::string continent;
    std::string country_iso;
public:
    Airport();
    explicit Airport(int _id);
    Airport(int _id, std::string _ident, std::string _type, std::string _name, UTM _location, std::string _continent, std::string _country_iso);

    const int &getId() const;
    void setId(const int &id);

    const std::string &getIdent() const;
    void setIdent(const std::string &ident);

    const std::string &getType() const;
    void setType(const std::string &type);

    const std::string &getName() const;
    void setName(const std::string &name);

    const UTM &getLocation() const;
    void setLocation(const UTM &location);

    const std::string &getContinent() const;
    void setContinent(const std::string &continent);

    const std::string &getCountryIso() const;
    void setCountryIso(const std::string &countryIso);

    bool operator<(const Airport& origin);
    bool operator>(const Airport& origin);
    bool operator==(const Airport& origin);

};


#endif //PR1_CD_AIRPORT_H
