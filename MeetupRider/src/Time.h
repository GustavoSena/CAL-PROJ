//
// Created by user on 05/05/2020.
//

#ifndef CAL_PROJ_TIME_H
#define CAL_PROJ_TIME_H
#include <string>
#include "utils.h"


using namespace std;

class Time {
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

private:
    int hour;
    int minute;
    int second;

};


#endif //CAL_PROJ_TIME_H
