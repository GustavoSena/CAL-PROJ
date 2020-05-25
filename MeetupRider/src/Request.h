//
// Created by user on 05/05/2020.
//

#ifndef CAL_PROJ_REQUEST_H
#define CAL_PROJ_REQUEST_H


#include "Time.h"
#include "Person.h"

class Request {

protected:
    Time minStartTime;
    Time maxEndTime;
    int destinationId;
    int startingId;

public:
    Request()=default;

    Request( Time minStartTime,  Time maxEndTime,
             int destinationId, int startingId);

    Time getMinStartTime();

    void setMinStartTime( Time minStartTime);

    Time getMaxEndTime();

    void setMaxEndTime( Time maxEndTime);

    int getDestinationId();

    void setDestinationId( int id);

    int getStartingId() ;

    void setStartingId( int id);

    void setTimesNull();

};

class PassengerRequest : public Request{

private:
    Passenger * passenger;
public:
    PassengerRequest( Time minStartTime,  Time maxEndTime,
                      int destinationId, int startingId, Passenger *passenger);
    PassengerRequest(int destinationId, int startingId, Passenger * passenger);

    PassengerRequest() =default;
    Passenger *getPassenger();

    void setPassenger(Passenger *passenger);

};


class DriverRequest : public Request{

private:
    Driver * driver;

public:
    DriverRequest( Time minStartTime,  Time maxEndTime, int destinationId,
                   int startingId, Driver *driver);


    DriverRequest(int destinationId, int startingId, Driver * driver);

    DriverRequest() = default;

    Driver *getDriver();

    void setDriver(Driver *driver);

    int getCapacity();

};

#endif //CAL_PROJ_REQUEST_H
