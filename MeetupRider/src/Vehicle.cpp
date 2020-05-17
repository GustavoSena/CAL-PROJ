//
// Created by user on 05/05/2020.
//

#include "Vehicle.h"


Vehicle::Vehicle(int id, int capacity, int driverId) : id(id), capacity(capacity), driver_id(driverId) {}

int Vehicle::getId() const {
    return id;
}

void Vehicle::setId(int id) {
    Vehicle::id = id;
}

int Vehicle::getCapacity() const {
    return capacity;
}

void Vehicle::setCapacity(int capacity) {
    Vehicle::capacity = capacity;
}

int Vehicle::getDriverId() const {
    return driver_id;
}

void Vehicle::setDriverId(int driverId) {
    driver_id = driverId;
}

