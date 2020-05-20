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
    vector<DriverRequest *> requests_drivers;
    vector<PassengerRequest *> requests_passengers;
    vector<Journey *> journeys;
    int lastId; //the last id used for passengers and drivers
    int lastCarId; //the last id used for cars
    int maxSpeed; //50 km/h

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


    const vector<Journey*> getJourneys() const;

    void setJourneys(vector<Journey*> journeys);

    void loadGraph(string node_text, string edge_text);

    void sign_up(string type); //Not tested yet

    int sign_in(string type); //Not tested yet, retorna id da pessoa

    Driver *findDriver(int id);

    Passenger *findPassenger(int id);

    vector<Passenger*> findPassengers(vector<int> ids);

    vector<PassengerRequest *> getPossibleRequests(int idDestino);

    double getDistance(int id1, int id2);

    PassengerRequest * getClosestToRequest(vector<PassengerRequest *> &requests, int dest_id);

    vector<Passenger*> fillVehicle(DriverRequest *driverRequest, vector<int> *ids);

    bool setup(vector<int> ids);

    vector<int> calculatePath(vector<int>ids, double &distance);

    bool removePassengerRequests(Passenger * p);

    bool removeRequests(vector<Passenger*> passengers, DriverRequest * request);

    bool createJourney(DriverRequest * request);

    void addDriverRequest(DriverRequest * request);

    void addPassengerRequest(PassengerRequest * request);

    void addPassenger(Passenger * passenger);

    void addDriver(Driver * driver);

    Time predictTime(double distance);

    bool conditionTime(Request *r, Time t);

    bool checkTimeRestrictions(vector<int> possible_path, vector<Request*> requests, PassengerRequest * possible_request);




};


#endif //MEETUPRIDER_BASE_H
