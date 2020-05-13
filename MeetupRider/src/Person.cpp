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

const string & Person::getName() const {
    return name;
}

void Person::setName(const string &name) {
    Person::name = name;
}

const vector<Person*> & Person::getNetwork() const {
    return network;
}

void Person::setNetwork(const vector<Person*> &network) {
    this->network = network;
}

const string &Person::getAddress() const {
    return address;
}

void Person::setAddress(const string &address) {
    Person::address = address;
}

Vehicle *Driver::getVehicle() const {
    return vehicle;
}

void Driver::setVehicle(Vehicle *vehicle) {
    Driver::vehicle = vehicle;
}

Driver::Driver(int id, const string &name, const vector<Person*> &network, const string &address, Vehicle * vehicle) : Person(id, name, network, address) {

    this->vehicle = vehicle;

}
