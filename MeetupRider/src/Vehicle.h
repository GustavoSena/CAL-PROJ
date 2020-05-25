//
// Created by user on 05/05/2020.
//

#ifndef CAL_PROJ_VEHICLE_H
#define CAL_PROJ_VEHICLE_H

#include "Person.h"
#include "NewGraph.h"

class Vehicle{

private:
    int id;
    int capacity;
    int driver_id;

public:
    Vehicle(int id, int capacity, int driverId);

    Vehicle() = default;

    int getId() const;

    void setId(int id);

    int getCapacity() const;

    void setCapacity(int capacity);

    int getDriverId() const;

    void setDriverId(int driverId);

    friend ostream &operator<<(ostream &out, const Vehicle &v);

};

#endif //CAL_PROJ_VEHICLE_H
