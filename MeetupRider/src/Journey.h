//
// Created by user on 05/05/2020.
//

#ifndef CAL_PROJ_JOURNEY_H
#define CAL_PROJ_JOURNEY_H

#include <vector>
#include "Time.h"
#include "Person.h"

class Journey {

private:
    string city;
    Time startTime;
    vector<int> path;
    vector<Passenger*> passenger;
    Driver *driver;

public:
    Journey() = default;

     Time getStartTime();

    void setStartTime( Time startTime);

    vector<Passenger*>  getPassenger() ;

    void setPassenger( vector<Passenger*>  passenger);

    Driver *getDriver() ;

    void setDriver(Driver *driver);

    string show();

    string showSimp();

    void setPath( vector<int> path);

    vector<int> getPath();

    string getCity();

    void setCity(string city);

};


#endif //CAL_PROJ_JOURNEY_H
