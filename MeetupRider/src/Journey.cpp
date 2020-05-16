//
// Created by user on 05/05/2020.
//

#include "Journey.h"



const Time &Journey::getStartTime() const {
    return startTime;
}

void Journey::setStartTime(const Time &startTime) {
    Journey::startTime = startTime;
}

const vector<Time> &Journey::getArrivalTimes() const {
    return arrivalTimes;
}

void Journey::setArrivalTimes(const vector<Time> &arrivalTimes) {
    Journey::arrivalTimes = arrivalTimes;
}

const vector<Passenger*> Journey::getPassenger() const{
    return passenger;
}

void Journey::setPassenger(vector<Passenger*> passenger) {
    this->passenger = passenger;
}

Driver *Journey::getDriver() const {
    return driver;
}

void Journey::setDriver(Driver *driver) {
    Journey::driver = driver;
}

void Journey::setPath(const vector<int> &path) {
    Journey::path=path;

}

const vector<int> &Journey::getPath() {
    return path;
}
