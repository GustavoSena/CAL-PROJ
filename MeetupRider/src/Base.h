//
// Created by user on 08/05/2020.
//

#ifndef MEETUPRIDER_BASE_H
#define MEETUPRIDER_BASE_H

#include <vector>
#include <fstream>
#include "NewGraph.h"
#include "Person.h"
#include "Request.h"
#include "Journey.h"
#include "utils.h"

using namespace std;

class Base {
private:
    Graph graph;
    vector<Passenger *> passengers;
    vector<Driver *> drivers;
    vector<Request *> requests;
    vector<Journey *> journeys;
    int lastId; //the last id used for passengers and drivers
    int lastCarId; //the last id used for cars

public:

    Base(string fileName);

    Base();


    void loadPassengers(string fileName);

    void loadDrivers(string fileName);

    void loadRequests(string fileName);

    void loadJourneys(string fileName);

     Graph &getGraph() ;

    void setGraph(const Graph &graph);

    const vector<Passenger*> getPassengers() const;

    void setPassengers( vector<Passenger*>  passengers);

    const vector<Driver*>  getDrivers() const;

    void setDrivers( vector<Driver*>  drivers);

    const vector<Request*> getRequests() const;

    void setRequests(vector<Request*> requests);

    void addRequest(Request* request);

    const vector<Journey*> getJourneys() const;

    void setJourneys(vector<Journey*> journeys);

    void loadGraph(string node_text, string edge_text);

    void sign_up(string type); //Not tested yet

    int sign_in(string type); //Not tested yet, retorna id da pessoa

    Driver *findDriver(int id);

    Passenger *findPassenger(int id);

    vector<Passenger*> findPassengers(vector<int> ids);


};


#endif //MEETUPRIDER_BASE_H
