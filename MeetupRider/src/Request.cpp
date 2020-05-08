//
// Created by user on 05/05/2020.
//

#include "Request.h"

Request::Request(const Time &minStartTime, const Time &maxStartTime, const Time &minEndTime, const Time &maxEndTime,
                 int personId) : minStartTime(minStartTime), maxStartTime(maxStartTime), minEndTime(minEndTime),
                                 maxEndTime(maxEndTime), personId(personId) {}

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

int Request::getPersonId() const {
    return personId;
}

void Request::setPersonId(int personId) {
    Request::personId = personId;
}
