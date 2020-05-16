//
// Created by user on 05/05/2020.
//

#ifndef CAL_PROJ_REQUEST_H
#define CAL_PROJ_REQUEST_H


#include "Time.h"
#include "Person.h"

class Request {
public:
    Request(const Time &minStartTime, const Time &maxStartTime, const Time &minEndTime, const Time &maxEndTime,
            Passenger *passenger, int destinationId, int staringId);

    Request()=default;

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

    Passenger *getPassenger();

    void setPassenger(Passenger * passenger);




private:
    Time minStartTime;
    Time maxStartTime;
    Time minEndTime;
    Time maxEndTime;
    int destinationId;
    int staringId;
    Passenger *passenger;


};


#endif //CAL_PROJ_REQUEST_H
