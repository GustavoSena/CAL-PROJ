//
// Created by user on 05/05/2020.
//

#ifndef CAL_PROJ_PERSON_H
#define CAL_PROJ_PERSON_H

#include <vector>
#include <string>
#include "Vehicle.h"

using namespace std;

class Person{

public:
    Person(int id, string &name, vector<Person*> &network,string &address) : id(id), name(name), network(network), address(address){}

    int getId() const;

    void setId(int id);

    void setName(const string &name);

    vector<Person*> &getNetwork();

    void setNetwork(const vector<Person*> &network);

    string &getAddress();

    void setAddress(const string &address);

    string getName();



protected:
    int id;
    string name;
    vector<Person*> network;
    string address;
    //adicionar destinos frequentes



};



class Passenger : public Person {
public:
    Passenger(int id, string &name, vector<Person*> &network, string &address) : Person(id, name, network, address) {}



};

class Vehicle;


class Driver : public Person {
private:
    Vehicle * vehicle;

public:
    Driver(int id, const string &name, const vector<Person*> & network, const string & address, Vehicle *vehicle);

    Vehicle *getVehicle() const;

    void setVehicle(Vehicle *vehicle);


};


#endif //CAL_PROJ_PERSON_H
