//
// Created by user on 05/05/2020.
//

#include "Journey.h"



Time Journey::getStartTime()  {
    return startTime;
}

void Journey::setStartTime( Time startTime) {
    Journey::startTime = startTime;
}

vector<Passenger*> Journey::getPassenger() {
    return passenger;
}

void Journey::setPassenger(vector<Passenger*> passenger) {
    this->passenger = passenger;
}

Driver *Journey::getDriver()  {
    return driver;
}

void Journey::setDriver(Driver *driver) {
    Journey::driver = driver;
}

void Journey::setPath( vector<int> path) {
    Journey::path=path;

}
vector<int> Journey::getPath() {
    return path;
}


string Journey::show(){
    stringstream ss;

    ss<<"Driver: "<<driver->getName()<<endl;
    ss<<"Passengers: \n";
    for(Passenger *p:passenger)
        ss<<"    "<<p->getName()<<endl;
    ss<<"Starting time: "<<startTime<<endl;
    ss<<"Path: ";
    for(int i:path){
        ss<<i;
        if(i!= *(path.end()-1))
            ss<<"->";
    }


    return ss.str();
}

string Journey::showSimp() {
    stringstream ss;
    ss<<"driver: "<<driver->getName()<<" -from: "<<path[0]<<" -to: "<<path[path.size()-1];
    return ss.str();
}

string Journey::getCity() {
    return city;
}

void Journey::setCity(string city) {
    this->city=city;
}
