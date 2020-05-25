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
    Time startTime;
    vector<int> path;
    vector<Passenger*> passenger;
    Driver *driver;

public:
    Journey() = default;

    const Time &getStartTime() const;

    void setStartTime(const Time &startTime);

    const vector<Passenger*>  getPassenger() const;

    void setPassenger(const vector<Passenger*>  passenger);

    Driver *getDriver() const;

    void setDriver(Driver *driver);

    string show();

    string showSimp();

    void setPath( vector<int> path);

    vector<int> getPath();

};


#endif //CAL_PROJ_JOURNEY_H
