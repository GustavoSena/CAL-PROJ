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
    vector<int> network;
    string address;
    vector<int> freqPlacesId;


public:
    Person(int id, const string &name, const vector<int> &network, const string &address) : id(id), name(name), network(network), address(address){}
    Person(int id, const string &name, const vector<int> &network, const string &address,const vector<int> &freqPlacesId) : id(id), name(name), network(network), address(address),freqPlacesId(freqPlacesId){}
    Person() = default;


    int getId() const;

    void setId(int id);

    void setName(const string &name);

    const vector<int> &getNetwork() const;

    void setNetwork(const vector<int> &network);

    string &getAddress();

    void setAddress(const string &address);

    string getName();

    void setFreqPlaces(const vector<int> &freqPlaces);

    const vector<int> &getFreqPlaces();

};



class Passenger : public Person {
public:

    Passenger(int id, const string &name, const vector<int> &network, const string &address) : Person(id, name, network, address) {}
    Passenger(int id, const string &name, const vector<int> &network, const string &address,const vector<int> &freqPlacesId) : Person(id, name, network, address,freqPlacesId) {}
    Passenger() = default;


};

class Vehicle;


class Driver : public Person {
private:
    Vehicle * vehicle;

public:

    Driver(int id, const string &name, const vector<int> &network, const string &address, Vehicle *vehicle);
    Driver(int id, const string &name, const vector<int> &network, const string &address, const vector<int> &freqPlacesId, Vehicle *vehicle);
    Driver() = default;

    Vehicle *getVehicle() const;

    void setVehicle(Vehicle *vehicle);


};


#endif //CAL_PROJ_PERSON_H
