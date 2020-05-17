//
// Created by user on 05/05/2020.
//

#ifndef CAL_PROJ_REQUEST_H
#define CAL_PROJ_REQUEST_H


#include "Time.h"
#include "Person.h"

class Request {
public:

    Request()=default;

    Request(const Time &minStartTime, const Time &maxStartTime, const Time &minEndTime, const Time &maxEndTime,
            int destinationId, int startingId, Person *person);

    const Time &getMinStartTime() const;

    void setMinStartTime(const Time &minStartTime);

    const Time &getMaxStartTime() const;

    void setMaxStartTime(const Time &maxStartTime);

    const Time &getMinEndTime() const;

    void setMinEndTime(const Time &minEndTime);

    const Time &getMaxEndTime() const;

    void setMaxEndTime(const Time &maxEndTime);

    const int &getDestinationId() const;

    void setDestinationId(const int &id);

    const int &getStartingId() const;

    void setStartingId(const int &id);

    Person *getPerson() const;

    void setPerson(Person *person);


private:
    Time minStartTime;
    Time maxStartTime;
    Time minEndTime;
    Time maxEndTime;
    int destinationId;
    int startingId;
    Person *person;

};


#endif //CAL_PROJ_REQUEST_H
