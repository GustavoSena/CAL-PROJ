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




protected:
    Time minStartTime;
    Time maxEndTime;
    int destinationId;
    int startingId;


};

class PassengerRequest : public Request{
public:
    PassengerRequest( Time minStartTime,  Time maxEndTime,
                     int destinationId, int startingId, Passenger *passenger);
    PassengerRequest(int destinationId, int startingId, Passenger * passenger);

    PassengerRequest() =default;
    Passenger *getPassenger();

    void setPassenger(Passenger *passenger);

private:
    Passenger * passenger;


};


class DriverRequest : public Request{
public:
    DriverRequest( Time minStartTime,  Time maxEndTime, int destinationId,
                  int startingId, Driver *driver);


    DriverRequest(int destinationId, int startingId, Driver * driver);

    DriverRequest() = default;

    Driver *getDriver();

    void setDriver(Driver *driver);

    int getCapacity();

private:
    Driver * driver;
};

#endif //CAL_PROJ_REQUEST_H
