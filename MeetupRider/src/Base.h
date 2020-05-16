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
public:

    Base(string fileName);

    Base();


    void loadPassengers(string fileName);

    void loadDrivers(string fileName);

    void loadRequests(string fileName);

    void loadJourneys(string fileName);

    const Graph &getGraph() const;

    void setGraph(const Graph &graph);

    const vector<Passenger*> getPassengers() const;

    void setPassengers( vector<Passenger*>  passengers);

    const vector<Driver*>  getDrivers() const;

    void setDrivers( vector<Driver*>  drivers);

    const vector<Request*> getRequests() const;

    void setRequests(vector<Request*> requests);

    const vector<Journey*> getJourneys() const;

    void setJourneys(vector<Journey*> journeys);

    void loadGraph(string node_text, string edge_text);



};


#endif //MEETUPRIDER_BASE_H
