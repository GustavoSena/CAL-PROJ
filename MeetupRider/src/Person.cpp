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

vector<Person*> & Person::getNetwork() {
    return network;
}

void Person::setNetwork(const vector<Person*> &network) {
    this->network = network;
}

string &Person::getAddress() {
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

Driver::Driver(int id, string &name, vector<Person*> &network,  string &address, Vehicle * vehicle) : Person(id, name, network, address) {

    this->vehicle = vehicle;

}
