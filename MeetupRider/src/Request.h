//
// Created by user on 05/05/2020.
//

#ifndef CAL_PROJ_REQUEST_H
#define CAL_PROJ_REQUEST_H


#include "Time.h"

class Request {
public:
    Request(const Time &minStartTime, const Time &maxStartTime, const Time &minEndTime, const Time &maxEndTime,
            int personId);

    const Time &getMinStartTime() const;

    void setMinStartTime(const Time &minStartTime);

    const Time &getMaxStartTime() const;

    void setMaxStartTime(const Time &maxStartTime);

    const Time &getMinEndTime() const;

    void setMinEndTime(const Time &minEndTime);

    const Time &getMaxEndTime() const;

    void setMaxEndTime(const Time &maxEndTime);

    int getPersonId() const;

    void setPersonId(int personId);

private:
    Time minStartTime;
    Time maxStartTime;
    Time minEndTime;
    Time maxEndTime;
    //adicionar o destino
    int personId;


};


#endif //CAL_PROJ_REQUEST_H
