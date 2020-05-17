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
//                loadRequests(temp);
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
    vector<string> parts;
    while(getline(a_file, temp)) {
        switch(counter){
            case 0:
                p.setId(stoi(temp));
                break;
            case 1:
                p.setName(temp);
                break;
            case 2:
                parts = decompose(temp,',');
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
                parts = decompose(temp,',');
                for (string i : parts){
                    aux.push_back(stoi(i));
                }
                p.setFreqPlaces(aux);
                aux={};

                break;
            case 5:
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
    vector<string> parts;
    while(getline(a_file, temp)) {
        switch(counter){
            case 0:
                d.setId(stoi(temp));
                break;
            case 1:
                d.setName(temp);
                break;
            case 2:
                parts = decompose(temp,',');
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
                parts = decompose(temp,',');
                for (string i : parts){
                    aux.push_back(stoi(i));
                }
                d.setFreqPlaces(aux);
                aux={};
                break;
            case 5:
                parts = decompose(temp,',');
                v = Vehicle(stoi(parts[0]),stoi(parts[1]),d.getId());
                d.setVehicle(new Vehicle(v));
                break;
            case 6:
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

/*
void Base::loadRequests(string fileName){
    ifstream a_file;
    a_file.open("..\\resources\\files\\" + fileName);
    int counter =0;
    string temp;
    Request r;
    vector<int> aux = {};
    vector<string> parts;
    vector<Time> times;
    while(getline(a_file, temp)) {
        switch(counter){
            case 0:
                r.setPassenger(findPassenger(stoi(temp)));
                break;
            case 1:
                r.setStartingId(stoi(temp));
                break;
            case 2:
                r.setDestinationId(stoi(temp));
                break;
            case 3:
                r.setMinStartTime(Time(temp));
                break;
            case 4:
                r.setMaxStartTime(Time(temp));
                break;
            case 5:
                r.setMinEndTime(Time(temp));
                break;
            case 6:
                r.setMinEndTime(Time(temp));
                break;
            case 7:
                requests.push_back(new Request(r));
                r=Request();
                break;
            default:
                break;

        }
        counter++;
    }
    a_file.close();
}
*/

void Base::loadJourneys(string fileName){
    ifstream a_file;
    a_file.open("..\\resources\\files\\" + fileName);
    int counter =0;
    string temp;
    Journey j = Journey();
    vector<int> aux = {};
    vector<string> parts;
    vector<Time> times;
    while(getline(a_file, temp)) {
        switch(counter){
            case 0:
                j.setDriver(findDriver(stoi(temp)));
                break;
            case 1:
                parts = decompose(temp,',');
                for (string i : parts){
                    aux.push_back(stoi(i));
                }
                j.setPassenger(findPassengers(aux));
                aux={};
                break;
            case 2:
                parts = decompose(temp,',');
                for (string i : parts){
                    aux.push_back(stoi(i));
                }
                j.setPath(aux);
                aux={};
                break;
            case 3:
                j.setStartTime(Time(temp));
                break;
            case 4:
                parts = decompose(temp,',');
                for (string i : parts){
                    times.push_back(Time(temp));
                }
                j.setArrivalTimes(times);
                break;
            case 5:
                journeys.push_back(new Journey(j));
                j= Journey();
                break;
            default:
                break;

        }
        counter++;
    }
    a_file.close();
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
    vector<int> network;
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

    return -1;
}

Driver *Base::findDriver(int id) {
    for (Driver *i:drivers){
        if(i->getId()==id){
            return i;
        }

    }
    return nullptr;
}

Passenger *Base::findPassenger(int id) {
    for (Passenger *i:passengers){
        if(i->getId()==id){
            return i;
        }

    }
    return nullptr;
}

vector<Passenger *> Base::findPassengers(vector<int> ids) {
    vector<Passenger *> aux;
    for (int i: ids){
        Passenger *p = findPassenger(i);
        if(p!=nullptr){
            aux.push_back(p);
        }
    }

    return aux;
}


vector<PassengerRequest *> Base::getPossibleRequests(int idDestino){
    vector<PassengerRequest *> result;
    for(auto r: requests_passengers){
        if(r->getDestinationId() == idDestino && graph.areVertexConnected(r->getStartingId(), idDestino)){
            result.push_back(r);
        }
    }
    return result;
}

PassengerRequest * Base::getClosestToRequest(vector<PassengerRequest *> requests, int dest_id, int person_id){
    double temp = INF;
    PassengerRequest * result = NULL;
    for(auto request: requests){
        if(request->getPassenger()->getId() != person_id){
            auto v = graph.findVertex(request->getStartingId());
            auto v2 = graph.findVertex(dest_id);
            if(temp < v->distance(v2)){
                temp = v->distance(v2);
                result = request;
            }
        }
    }
    return result;
}

vector<Passenger *> Base::fillVehicle(DriverRequest *driverRequest, vector<int> *ids){
    vector<Passenger*> result;
    ids->push_back(driverRequest->getStartingId());
    vector<PassengerRequest *> possibleRequests = getPossibleRequests(driverRequest->getDestinationId());
    int counter = 1;
    PassengerRequest * tmp = getClosestToRequest(possibleRequests, driverRequest->getStartingId(), driverRequest->getDriver()->getId());
    while(counter < driverRequest->getCapacity() && tmp != NULL)
    {
        result.push_back(tmp->getPassenger());
        ids->push_back(tmp->getStartingId());
        counter++;
        tmp =  getClosestToRequest(possibleRequests, tmp->getStartingId(), tmp->getPassenger()->getId());
    }

    ids->push_back(driverRequest->getDestinationId());
    return result;

}


bool Base::setup(vector<int> ids)//ids dos vértices pela qual temos que passar
{
    graph.floydWarshallShortestPath();
    for(int i = 0; i < ids.size()-1; i++)
    {
        for(int j = i+1; j < ids.size(); j++)
        {
            if(!graph.areVertexConnected(ids[i], ids[j]))
                return false;
        }
    }
    return true;
}

vector<int> Base::calculatePath(vector<int>ids) //os ids já estariam ordenados pela ordem que o condutor iria passar
{

    vector<int>result;
    vector<int> tmp;
    for(int i = 0; i < ids.size()-1; i++)
    {
        graph.AStar(ids[i], ids[i+1]);
        tmp = graph.getPath(ids[i], ids[i+1]);
        for(int j = 0; j < tmp.size(); j++)
        {
            result.push_back(tmp[j]);
        }
    }
    return result;

}

bool Base::removePassengerRequests(Passenger * p)
{
    for(int i = 0; i < requests_passengers.size(); i++)
    {
        if(requests_passengers[i]->getPassenger()->getId() == p->getId())
        {
            requests_passengers.erase(requests_passengers.begin()+i);
            return true;
        }
    }
    return false;
}


bool Base::removeRequests(vector<Passenger*> passengers, DriverRequest * request)
{
    for(auto p : passengers)
    {
        if(!removePassengerRequests(p))
            return false;
    }
    for(int i = 0; i < requests_drivers.size(); i++)
    {
        if(requests_drivers[i]->getDriver()->getId() == request->getDriver()->getId())
        {
            requests_drivers.erase(requests_drivers.begin()+i);
            return true;
        }
    }
    return false;
}


bool Base::createJourney(DriverRequest * request)
{
    Journey j;
    vector<int>places;
    vector<int>path;
    vector<Passenger*> passengers = fillVehicle(request, &places);
    if(!setup(places)) return false;
    path = calculatePath(places);
    j.setDriver(request->getDriver());
    j.setPassenger(passengers);
    j.setStartTime(request->getMinStartTime());
    j.setPath(path);
    if(!removeRequests(passengers, request)) return false;
    journeys.push_back(&j);
    return true;
}