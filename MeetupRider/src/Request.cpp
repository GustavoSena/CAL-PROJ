//
// Created by user on 05/05/2020.
//

#include "Request.h"



const Time &Request::getMinStartTime() const {
    return minStartTime;
}

void Request::setMinStartTime(const Time &minStartTime) {
    Request::minStartTime = minStartTime;
}


const Time &Request::getMinEndTime() const {
    return minEndTime;
}

void Request::setMinEndTime(const Time &minEndTime) {
    Request::minEndTime = minEndTime;
}

const Time &Request::getMaxEndTime() const {
    return maxEndTime;
}

void Request::setMaxEndTime(const Time &maxEndTime) {
    Request::maxEndTime = maxEndTime;
}

const int &Request::getDestinationId() const {
    return destinationId;
}

void Request::setDestinationId(const int &id) {
    Request::destinationId=id;
}

const int &Request::getStartingId() const {
    return startingId;
}

void Request::setStartingId(const int &id) {
    Request::startingId=id;
}




Request::Request(const Time &minStartTime, const Time &minEndTime, const Time &maxEndTime,
                 int destinationId, int startingId) : minStartTime(minStartTime),
                                                                      minEndTime(minEndTime), maxEndTime(maxEndTime),
                                                                      destinationId(destinationId),
                                                                      startingId(startingId) {}


void Request::setTimesNull() {
    minStartTime=Time("-1:-1");
    minEndTime=Time("-1:-1");
    maxEndTime=Time("-1:-1");

}


void Request::calculateMaxStartTime(Time time){

    //d
    //maxStartTime = maxEndTime - time;
}

PassengerRequest::PassengerRequest(const Time &minStartTime, const Time &minEndTime,
                                   const Time &maxEndTime, int destinationId, int startingId, Passenger *passenger)
        : Request(minStartTime,  minEndTime, maxEndTime, destinationId, startingId),
          passenger(passenger) {}


PassengerRequest::PassengerRequest(int destinationId, int startingId, Passenger * passenger)
{
    this->destinationId = destinationId;
    this->startingId = startingId;
    this->passenger = passenger;
}


Passenger *PassengerRequest::getPassenger() const {
    return passenger;
}

void PassengerRequest::setPassenger(Passenger *passenger) {
    PassengerRequest::passenger = passenger;
}

DriverRequest::DriverRequest(const Time &minStartTime, const Time &minEndTime, const Time &maxEndTime,
                             int destinationId, int startingId, Driver *driver) : Request(minStartTime, minEndTime,
                                                                                          maxEndTime, destinationId,
                                                                                          startingId), driver(driver) {}

Driver *DriverRequest::getDriver() const {
    return driver;
}

void DriverRequest::setDriver(Driver *driver) {
    DriverRequest::driver = driver;
}

int DriverRequest::getCapacity(){
    return driver->getVehicle()->getCapacity();
}

DriverRequest::DriverRequest(int destinationId, int startingId, Driver * driver)
{
    this->destinationId = destinationId;
    this->startingId = startingId;
    this->driver = driver;
}