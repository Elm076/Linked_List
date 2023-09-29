//
// Created by fotop on 27/09/2023.
//

#ifndef PR1_CD_UTM_H
#define PR1_CD_UTM_H

#include "vector"
#include <string>

class UTM {
private:
    std::string latitude;
    std::string longitude;

public:
    UTM();
    UTM(std::string _latitude, std::string _longitude);
    void setLatitude(std::string _latitude);
    void setLongitude(std::string _longitude);
    void setLocation(std::string _latitude, std::string _longitude);
    std::string getLatitude() const;
    std::string getLongitude() const;
    std::vector<std::string> getLocation() const;



};


#endif //PR1_CD_UTM_H
