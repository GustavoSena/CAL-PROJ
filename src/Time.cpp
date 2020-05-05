//
// Created by user on 05/05/2020.
//

#include "Time.h"

Time::Time(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {}

int Time::getHour() const {
    return hour;
}

void Time::setHour(int hour) {
    Time::hour = hour;
}

int Time::getMinute() const {
    return minute;
}

void Time::setMinute(int minute) {
    Time::minute = minute;
}

int Time::getSecond() const {
    return second;
}

void Time::setSecond(int second) {
    Time::second = second;
}
