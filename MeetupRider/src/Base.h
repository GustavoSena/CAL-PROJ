//
// Created by user on 08/05/2020.
//

#ifndef MEETUPRIDER_BASE_H
#define MEETUPRIDER_BASE_H

#include <vector>
#include <iostream>
#include <fstream>
#include "NewGraph.h"
#include "Person.h"
#include "Request.h"
#include "Journey.h"
#include "utils.h"
#include "Time.h"
#include "FloydWarshall.h"


using namespace std;


class Base {
private:
    Graph graph;
    vector<Passenger *> passengers;
    vector<Driver *> drivers;
    vector<DriverRequest *> requests_drivers;
    vector<PassengerRequest *> requests_passengers;
    vector<Journey *> journeys;
    int lastId = 0; //the last id used for passengers and drivers
    int lastCarId = 0; //the last id used for cars
    int maxSpeed; //50 km/h
    string requestFile;
    string journeyFile;
    string driverFile;
    string passengerFile;
    string algorithm;
    string map;

public:

    Base(string fileName);

    Base();


    void loadPassengers(string fileName);

    void loadDrivers(string fileName);

    void loadRequests(string fileName);

    void loadJourneys(string fileName);

    void writePassengers();

    void writeDrivers();

    void writeRequests();

    void writeJourneys();

    void updateFiles();

    void setPassengerFile(string fileName);

    void setJourneyFile(string fileName);

    void setRequestFile(string fileName);

    void setDriverFile(string fileName);

    void setAlgorithm(string alg);

    void setMap(string m);

    string getPassengerFile();

    string getDriverFile();

    string getRequestFile();

    string getJourneyFile();

    string getAlgorithm();

    string getMap();

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

    vector<PassengerRequest *> getPossibleRequests(DriverRequest * request);

    double getDistance(int id1, int id2);

    PassengerRequest * getClosestToRequest(vector<PassengerRequest *> &requests, int dest_id);

    PassengerRequest * getClosestToRequest(vector<PassengerRequest *> &requests, DriverRequest * driver, vector<Passenger*> current_passengers);

    int getClosestId(vector<int> &ids, int comparing_id, bool dest);

    vector<int> orderingIds(vector<int> start, int comparing_id, bool dest);

    vector<int> recalculatePath(vector<Request*> requests);

    vector<Passenger*> fillVehicle(DriverRequest *driverRequest, vector<int> *ids);

    bool setup(vector<int> ids);

    vector<int> calculatePath(vector<int>ids, double &distance);


    void run_algorithm();

    bool removePassengerRequests(Passenger * p);

    bool removeRequests(vector<Passenger*> passengers, DriverRequest * request);

    bool createJourney(DriverRequest * request);

    void addDriverRequest(DriverRequest * request);

    void addPassengerRequest(PassengerRequest * request);

    void addPassenger(Passenger * passenger);

    void addDriver(Driver * driver);

    Time predictTime(double distance);

    bool conditionTime(Request *r, Time t);

    vector<int> getRequestPath(vector<int> ids, Request * request);

    bool checkTimeRestrictions(vector<Request*> requests, PassengerRequest * possible_request);

    int getNumberPeopleKnown(Driver *driver, vector<Passenger*> passengers, Passenger* possible_passenger);

    void updatePeopleKnown(Driver *driver, vector<Passenger*> passengers);


    void loadFloydWarshall();




};


#endif //MEETUPRIDER_BASE_H
