//
// Created by user on 05/05/2020.
//

#include "Person.h"

int Person::getId() const {
    return id;
}

void Person::setId(int id) {
    Person::id = id;
}

string Person::getName()  {
    return name;
}

void Person::setName(const string &name) {
    Person::name = name;
}


const vector<int> & Person::getNetwork() const {

    return network;
}

void Person::setNetwork(const vector<int> &network) {
    this->network = network;
}

string &Person::getAddress() {
    return address;
}

void Person::setAddress(const string &address) {
    Person::address = address;
}

void Person::setFreqPlaces(const vector<int> &freqPlaces) {
    Person::freqPlacesId=freqPlaces;

}

const vector<int> &Person::getFreqPlaces() {
    return freqPlacesId;
}

void Person::addNetwork(int personId)
{
    if(!in(network, personId))
        network.push_back(personId);
}

void Person::addNetwork(vector<Person*> people)
{
    for(auto p : people)
    {
        if (p->getId() == id)
            continue;
        addNetwork(p->getId());
    }
}

Vehicle *Driver::getVehicle() const {
    return vehicle;
}

void Driver::setVehicle(Vehicle *vehicle) {
    Driver::vehicle = vehicle;
}

Driver::Driver(int id, const string &name, const vector<int> &network, const string &address, Vehicle *vehicle): Person(id, name, network, address) {

    this->vehicle = vehicle;

}

Driver::Driver(int id, const string &name, const vector<int> &network, const string &address,
               const vector<int> &freqPlacesId, Vehicle *vehicle): Person(id, name, network, address, freqPlacesId) {
    this->vehicle = vehicle;
}
