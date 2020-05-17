//
// Created by user on 05/05/2020.
//

#include "Request.h"

Request::Request(const Time &minStartTime, const Time &maxStartTime, const Time &minEndTime, const Time &maxEndTime,
                 Passenger *passenger, int destinationId, int staringId)
        : minStartTime(minStartTime), maxStartTime(maxStartTime), minEndTime(minEndTime),
          maxEndTime(maxEndTime), passenger(passenger), destinationId(destinationId), staringId(staringId) {}

const Time &Request::getMinStartTime() const {
    return minStartTime;
}

void Request::setMinStartTime(const Time &minStartTime) {
    Request::minStartTime = minStartTime;
}

const Time &Request::getMaxStartTime() const {
    return maxStartTime;
}

void Request::setMaxStartTime(const Time &maxStartTime) {
    Request::maxStartTime = maxStartTime;
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

Passenger *Request::getPassenger() {
    return passenger;
}

void Request::setPassenger(Passenger *passenger) {
    this->passenger=passenger;

}

const int &Request::getDestinationId() const {
    return destinationId;
}

void Request::setDestinationId(const int &id) {
    Request::destinationId=id;
}

const int &Request::getStartingId() const {
    return staringId;
}

void Request::setStartingId(const int &id) {
    Request::staringId=id;
}

void Request::setTimesNull() {
    minStartTime=Time("-1:-1");
    maxStartTime=Time("-1:-1");
    minEndTime=Time("-1:-1");
    maxEndTime=Time("-1:-1");

}


