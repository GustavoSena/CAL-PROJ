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

    Request(const Time &minStartTime,  const Time &minEndTime, const Time &maxEndTime,
            int destinationId, int startingId);

    const Time &getMinStartTime() const;

    void setMinStartTime(const Time &minStartTime);

    const Time &getMinEndTime() const;

    void setMinEndTime(const Time &minEndTime);

    const Time &getMaxEndTime() const;

    void setMaxEndTime(const Time &maxEndTime);

    const int &getDestinationId() const;

    void setDestinationId(const int &id);

    const int &getStartingId() const;

    void setStartingId(const int &id);

    void setTimesNull();

    void calculateMaxStartTime(Time time);



protected:
    Time minStartTime;
    Time minEndTime;
    Time maxEndTime;
    int destinationId;
    int startingId;


};

class PassengerRequest : public Request{
public:
    PassengerRequest(const Time &minStartTime, const Time &minEndTime, const Time &maxEndTime,
                     int destinationId, int startingId, Passenger *passenger);
    PassengerRequest(int destinationId, int startingId, Passenger * passenger);

    PassengerRequest() =default;
    Passenger *getPassenger() const;

    void setPassenger(Passenger *passenger);

private:
    Passenger * passenger;


};


class DriverRequest : public Request{
public:
    DriverRequest(const Time &minStartTime, const Time &minEndTime, const Time &maxEndTime, int destinationId,
                  int startingId, Driver *driver);


    DriverRequest(int destinationId, int startingId, Driver * driver);

    DriverRequest() = default;

    Driver *getDriver() const;

    void setDriver(Driver *driver);

    int getCapacity();

private:
    Driver * driver;
};

#endif //CAL_PROJ_REQUEST_H
