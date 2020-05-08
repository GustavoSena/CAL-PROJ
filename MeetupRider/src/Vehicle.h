//
// Created by user on 05/05/2020.
//

#ifndef CAL_PROJ_VEHICLE_H
#define CAL_PROJ_VEHICLE_H

#include "Person.h"

class Vehicle{
public:
    Vehicle(int id, int capacity, int driverId);

    int getId() const;

    void setId(int id);

    int getCapacity() const;

    void setCapacity(int capacity);

    int getDriverId() const;

    void setDriverId(int driverId);

private:

    int id;
    int capacity;
    int driver_id;

};

#endif //CAL_PROJ_VEHICLE_H
