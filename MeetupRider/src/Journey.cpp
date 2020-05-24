//
// Created by user on 05/05/2020.
//

#include "Journey.h"



const Time &Journey::getStartTime() const {
    return startTime;
}

void Journey::setStartTime(const Time &startTime) {
    Journey::startTime = startTime;
}

const vector<Time> &Journey::getArrivalTimes() const {
    return arrivalTimes;
}

void Journey::setArrivalTimes(const vector<Time> &arrivalTimes) {
    Journey::arrivalTimes = arrivalTimes;
}

const vector<Passenger*> Journey::getPassenger() const{
    return passenger;
}

void Journey::setPassenger(vector<Passenger*> passenger) {
    this->passenger = passenger;
}

Driver *Journey::getDriver() const {
    return driver;
}

void Journey::setDriver(Driver *driver) {
    Journey::driver = driver;
}

void Journey::setPath(const vector<int> &path) {
    Journey::path=path;

}

const vector<int> &Journey::getPath() {
    return path;
}


string Journey::show(){
    stringstream ss;

    ss<<"Driver: "<<driver->getName()<<endl;
    ss<<"Passengers: \n";
    for(Passenger *p:passenger)
        ss<<"    "<<p->getName()<<endl;
    ss<<"Starting time: "<<startTime<<endl;
    ss<<"Arrival times: ";
    for(Time t: arrivalTimes) {
        ss << t;
        if(!(t==*arrivalTimes.end()))
            ss<<"->";
    }
    ss<<endl;

    ss<<"Path: ";
    for(int i:path){
        ss<<i;
        if(i!= *path.end())
            ss<<"->";
    }


    return ss.str();
}

string Journey::showSimp() {
    stringstream ss;
    ss<<"driver: "<<driver->getName()<<" -from: "<<path[0]<<" -to: "<<path[path.size()-1];
    return ss.str();
}
