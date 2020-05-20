//
// Created by user on 05/05/2020.
//

#ifndef CAL_PROJ_TIME_H
#define CAL_PROJ_TIME_H
#include <string>
#include "utils.h"


using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time() =default;
    Time(string time);
    Time(double hour);
    Time(int hour, int minute, int second);

    int getHour() const;

    void setHour(int hour);

    int getMinute() const;

    void setMinute(int minute);

    int getSecond() const;

    void setSecond(int second);

    friend Time operator+(Time t1, Time t2);

    friend Time operator-(Time t1, Time t2);

    Time operator+=(Time t1);

    Time operator-=(Time t1);

    bool operator<(Time t);

    bool operator<=(const Time t) const;

    bool operator==(Time t);

    friend ostream &operator<<(ostream &out,const Time& t);

};


#endif //CAL_PROJ_TIME_H
