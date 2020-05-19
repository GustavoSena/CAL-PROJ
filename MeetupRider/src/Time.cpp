//
// Created by user on 05/05/2020.
//

#include <iomanip>
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

Time::Time(string time) {
    vector<string>parts = decompose(time,':');
    setHour(stoi(parts[0]));
    setMinute(stoi(parts[1]));
    setSecond(stoi(parts[2]));
}


Time::Time(double hour){
    
}


Time Time::operator+=(Time t1) {
    *this=*this+t1;
    return *this;
}

bool Time::operator<(Time t) {
    if(hour<t.getHour())
        return true;
    if(hour>t.getHour())
        return false;
    if(minute<t.getMinute())
        return true;
    if(minute>t.getMinute())
        return false;
    return second<t.getSecond();
}

bool Time::operator==(Time t) {
    return (hour==t.getHour())&&(minute==t.getMinute())&&(second==t.getSecond());
}

Time operator+(Time t1, Time t2) {
    int sec =t1.getSecond() + t2.getSecond();
    int min = t1.getMinute() + t2.getMinute();
    int hour=t1.getHour() + t2.getHour();
    if(sec>=60){
        sec-=60;
        min++;
    }
    if(min>=60){
        min-=60;
        hour++;
    }
    if(hour>=24)
        hour-=24;

    return Time(hour,min,sec);
}

ostream &operator<<(ostream &out, Time& t){
    out<<setfill('0')<<setw(2)<<t.getHour()<<":";
    out<<setfill('0')<<setw(2)<<t.getMinute()<<":";
    out<<setfill('0')<<setw(2)<<t.getSecond();
    setfill(' ');
    return out;
}


