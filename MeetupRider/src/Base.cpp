//
// Created by user on 08/05/2020.
//

#include "Base.h"


Base::Base(string text_line) { //função para dar load de tudo sendo text_line o nome do ficheiro

}

Base::Base(){

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