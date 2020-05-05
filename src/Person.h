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

protected:
    int id;
    string name;
    vector<Person*> network;


public:
    Person(int id, const string &name, const vector<Person> &network) : id(id), name(name), network(network) {}

    int getId() const;

    void setId(int id);
    const string &getName() const;
    void setName(const string &name);

    const vector<Person*> &getNetwork() const;

    void setNetwork(const vector<Person*> &network);
};



class Passenger : Person {
public:
    Passenger(int id, const string &name, const vector<Person> &network) : Person(id, name, network) {}

};

class Driver : Person {
private:
    Vehicle * vehicle;

public:
    Vehicle *getVehicle() const;

    void setVehicle(Vehicle *vehicle);


};


#endif //CAL_PROJ_PERSON_H
