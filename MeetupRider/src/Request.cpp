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

Person *Request::getPerson() const {
    return person;
}

void Request::setPerson(Person *person) {
    Request::person = person;
}

Request::Request(const Time &minStartTime, const Time &maxStartTime, const Time &minEndTime, const Time &maxEndTime,
                 int destinationId, int startingId, Person *person) : minStartTime(minStartTime),
                                                                      maxStartTime(maxStartTime),
                                                                      minEndTime(minEndTime), maxEndTime(maxEndTime),
                                                                      destinationId(destinationId),
                                                                      startingId(startingId), person(person) {}


