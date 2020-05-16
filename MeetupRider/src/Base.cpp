//
// Created by user on 08/05/2020.
//

#include "Base.h"

Base::Base(){

}

Base::Base(string fileName) {

    ifstream a_file;
    a_file.open(fileName);
    int counter =0;
    string temp;
    while(getline(a_file, temp)) {
        switch(counter){
            case 0:
                loadPassengers(temp);
                break;
            case 1:
                loadDrivers(temp);
                break;
            case 2:
                loadJourneys(temp);
                break;
            case 3:
                loadRequests(temp);
                break;
            default:
                break;

        }
        counter++;
    }
    a_file.close();
}



void Base::loadPassengers(string fileName){
    ifstream a_file;
    a_file.open("..\\resources\\files\\" + fileName);
    int counter =0;
    string temp;
    Passenger p = Passenger();
    vector<int> aux = {};
    while(getline(a_file, temp)) {
        switch(counter){
            case 0:
                p.setId(stoi(temp));
                break;
            case 1:
                p.setName(temp);
                break;
            case 2:
                vector<string> parts = decompose(temp,',');
                for (string i : parts){
                    aux.push_back(stoi(i));
                }
                p.setNetwork(aux);
                aux={};
                break;
            case 3:
                p.setAddress(temp);
                break;
            case 4:
                passengers.push_back(new Passenger(p));
                p= Passenger();
                break;
            default:
                break;

        }
        counter++;
    }
    a_file.close();


}

void Base::loadDrivers(string fileName){
    ifstream a_file;
    a_file.open("..\\resources\\files\\" + fileName);
    int counter =0;
    string temp;
    Driver d = Driver();
    Vehicle v = Vehicle();
    vector<int> aux = {};
    while(getline(a_file, temp)) {
        switch(counter){
            case 0:
                d.setId(stoi(temp));
                break;
            case 1:
                d.setName(temp);
                break;
            case 2:
                vector<string> parts = decompose(temp,',');
                for (string i : parts){
                    aux.push_back(stoi(i));
                }
                d.setNetwork(aux);
                aux={};
                break;
            case 3:
                d.setAddress(temp);
                break;
            case 4:
                vector<string> parts = decompose(temp,',');
                v = Vehicle(stoi(parts[0]),stoi(parts[1]),d.getId());
                d.setVehicle(new Vehicle(v));
                break;
            case 5:
                drivers.push_back(new Driver(d));
                d= Driver();
                break;
            default:
                break;

        }
        counter++;
    }
    a_file.close();
}

void Base::loadRequests(string fileName){
    ifstream a_file;
    a_file.open("..\\resources\\files\\" + fileName);
}

void Base::loadJourneys(string fileName){
    ifstream a_file;
    a_file.open("..\\resources\\files\\" + fileName);
}

const Graph &Base::getGraph() const {
    return graph;
}

void Base::setGraph(const Graph &graph) {
    Base::graph = graph;
}

const vector<Passenger*> Base::getPassengers() const{
    return passengers;
}

void Base::setPassengers(vector<Passenger*> passengers) {
    Base::passengers = passengers;
}

const vector<Driver*> Base::getDrivers() const{
    return drivers;
}

void Base::setDrivers(vector<Driver*> drivers) {
    Base::drivers = drivers;
}

const vector<Request*> Base::getRequests() const{
    return requests;
}

void Base::setRequests(vector<Request*> requests) {
    Base::requests = requests;
}

const vector<Journey*> Base::getJourneys() const{
    return journeys;
}

void Base::setJourneys(const vector<Journey*> journeys) {
    Base::journeys = journeys;
}

void Base::loadGraph(string node_text, string edge_text) {

    Graph graph;
    this->graph = graph;

    ifstream n_data(node_text);
    ifstream e_data(edge_text);

    string text_line;
    getline(n_data, text_line);
    int n_nodes = stoi(text_line);

    for(int i = 0; i < n_nodes; i++)
    {
        getline(n_data, text_line);
        vector<int> node_values = getNodeValues(text_line);
        this->graph.addVertex(node_values[0], node_values[1], node_values[2]);
    }

    getline(e_data, text_line);
    int n_edges = stoi(text_line);

    for(int i = 0; i < n_nodes; i++)
    {
        getline(e_data, text_line);
        vector<int> edge_values = getEdgeValues(text_line);
        this->graph.addEdge(edge_values[0], edge_values[1]);
    }
}