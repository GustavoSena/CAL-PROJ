//
// Created by user on 05/05/2020.
//

#include "Request.h"



 Time Request::getMinStartTime() {
    return minStartTime;
}

void Request::setMinStartTime(Time minStartTime) {
    Request::minStartTime = minStartTime;
}

 Time Request::getMaxEndTime()  {
    return maxEndTime;
}

void Request::setMaxEndTime( Time maxEndTime) {
    Request::maxEndTime = maxEndTime;
}

 int Request::getDestinationId()  {
    return destinationId;
}

void Request::setDestinationId( int id) {
    Request::destinationId=id;
}

 int Request::getStartingId()  {
    return startingId;
}

void Request::setStartingId( int id) {
    Request::startingId=id;
}




Request::Request( Time minStartTime,  Time maxEndTime,
                 int destinationId, int startingId) : minStartTime(minStartTime), maxEndTime(maxEndTime),
                                                                      destinationId(destinationId),
                                                                      startingId(startingId) {}


void Request::setTimesNull() {
    minStartTime=Time("-1:-1:-1");
    maxEndTime=Time("-1:-1:-1");

}


PassengerRequest::PassengerRequest( Time minStartTime,
                                    Time maxEndTime, int destinationId, int startingId, Passenger *passenger)
        : Request(minStartTime, maxEndTime, destinationId, startingId),
          passenger(passenger) {}


PassengerRequest::PassengerRequest(int destinationId, int startingId, Passenger * passenger)
{
    this->destinationId = destinationId;
    this->startingId = startingId;
    this->passenger = passenger;
}


Passenger *PassengerRequest::getPassenger()  {
    return passenger;
}

void PassengerRequest::setPassenger(Passenger *passenger) {
    PassengerRequest::passenger = passenger;
}

DriverRequest::DriverRequest( Time minStartTime,  Time maxEndTime,
                             int destinationId, int startingId, Driver *driver) : Request(minStartTime,
                                                                                          maxEndTime, destinationId,
                                                                                          startingId), driver(driver) {}

Driver *DriverRequest::getDriver()  {
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