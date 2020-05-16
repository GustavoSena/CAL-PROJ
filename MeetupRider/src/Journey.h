//
// Created by user on 05/05/2020.
//

#ifndef CAL_PROJ_JOURNEY_H
#define CAL_PROJ_JOURNEY_H

#include <vector>
#include "Time.h"
#include "Person.h"

class Journey {
public:
    Journey();

    const Time &getStartTime() const;

    void setStartTime(const Time &startTime);

    const vector<Time> &getArrivalTimes() const;

    void setArrivalTimes(const vector<Time> &arrivalTimes);

    const vector<Passenger*>  getPassenger() const;

    void setPassenger(const vector<Passenger*>  passenger);

    Driver *getDriver() const;

    void setDriver(Driver *driver);

    void setPath(const vector<int> &path);

    const vector<int> &getPath();

private:
    Time startTime;
    vector<int> path;
    vector<Time> arrivalTimes;
    vector<Passenger*> passenger;
    Driver *driver;

};


#endif //CAL_PROJ_JOURNEY_H
