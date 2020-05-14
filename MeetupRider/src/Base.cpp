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
                cout<<"load clients\n";
                loadClients(temp);
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


void Base::loadDrivers(string fileName){

}

void Base::loadClients(string fileName){

}

void Base::loadRequests(string fileName){

}

void Base::loadJourneys(string fileName){

}

Graph &Base::getGraph()  {
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

void Base::sign_up(string type) //type = passenger || type = driver
{
    string name, address;

    system("cls");
    cout << "Insert name\n";
    getline(cin, name);
    cout << "Insert address\n";
    getline(cin, address);
    //ver como fazer para adicionar as pessoas conhecidas - mostrar os utilizadores e perguntar quem conhece?
    vector<Person*> network;
    lastId++;
    if(type == "passenger")
    {
        Passenger p(lastId, name, network, address);
        passengers.push_back(&p);
    }
    else
    {
        int capacity;
        cout << "Insert vehicle capacity\n";
        cin >> capacity;
        lastCarId++;
        Vehicle v(lastCarId, capacity, lastId);
        Driver d(lastId, name, network, address, &v);
        drivers.push_back(&d);
    }


}

int Base::sign_in(string type)
{
    bool retry = true;
    int answer;
    do{

        system("cls");
        cout << "Choose your account:" << endl;
        int tmp_id = 1;
        if(type == "passenger")
        {
            for(auto p : passengers)
            {
                cout << tmp_id << ". " <<p->getName()<< endl;
                tmp_id++;
            }
            cin>>answer;
            if (answer >= 1 && answer <= passengers.size())
            {
                retry = false;
                return passengers[answer-1]->getId();
            } else{
                cout << "Invalid answer! Try again"<< endl;
        }


        } else{
            for(auto d: drivers)
            {
                cout << tmp_id << ". " <<d->getName()<< endl;
                tmp_id++;
            }
            cin>>answer;
            if(answer >= 1 && answer <= drivers.size())
            {
                retry = false;
                return drivers[answer-1]->getId();
            }
            else
            {
                cout << "Invalid answer! Try again"<< endl;
            }
        }

    }while(retry);


}