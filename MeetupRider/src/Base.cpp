//
// Created by user on 08/05/2020.
//

#include "Base.h"


Base::Base(){

    this->algorithm = "astar";

}

Base::Base(string fileName) {

    maxSpeed = 50;
    ifstream a_file;
    a_file.open(fileName);
    int counter =0;
    string temp;
    while(getline(a_file, temp)) {
        switch(counter){
            case 0:
                setPassengerFile(temp);
                loadPassengers(temp);
                break;
            case 1:
                setDriverFile(temp);
                loadDrivers(temp);
                break;
            case 2:
                setJourneyFile(temp);
                loadJourneys(temp);
                break;
            case 3:
                setRequestFile(temp);
                loadRequests(temp);
                break;
            default:
                break;
        }
        counter++;
    }
    this->algorithm = "astar";
    setlastIDs();
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
                for (string i : parts)
                    aux.push_back(stoi(i));
                p.setNetwork(aux);
                aux={};
                break;
            case 3:
                p.setAddress(temp);
                break;
            case 4:
                passengers.push_back(new Passenger(p));
                p= Passenger();
                counter=-1;
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
                for (string i : parts)
                    aux.push_back(stoi(i));
                d.setNetwork(aux);
                aux={};
                break;
            case 3:
                d.setAddress(temp);
                break;
            case 4:
                parts = decompose(temp,',');
                v = Vehicle(stoi(parts[0]),stoi(parts[1]),d.getId());
                d.setVehicle(new Vehicle(v));
                break;
            case 5:
                drivers.push_back(new Driver(d));
                d= Driver();
                counter=-1;
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
    int counter =0;
    string temp;
    vector<int> aux = {};
    vector<string> parts;
    vector<Time> times;
    Passenger *p;
    PassengerRequest pr;
    DriverRequest dr;
    bool pass=false;
    while(getline(a_file, temp)) {
        switch(counter) {
            case 0:
                p = findPassenger(stoi(temp));
                if (p == nullptr){
                    pass = false;
                    dr.setDriver(findDriver(stoi(temp)));
                }
                else{
                    pass=true;
                    pr.setPassenger(p);
                }
                break;
            case 1:
                if(pass)
                    pr.setStartingId(stoi(temp));
                else
                    dr.setStartingId(stoi(temp));
                break;
            case 2:
                if(pass)
                    pr.setDestinationId(stoi(temp));
                else
                    dr.setDestinationId(stoi(temp));
                break;
            case 3:
                if (pass)
                    pr.setMinStartTime(Time(temp));
                else
                    dr.setMinStartTime(Time(temp));
                break;
            case 4:
                if(pass)
                    pr.setMaxEndTime(Time(temp));
                else
                    pr.setMaxEndTime(Time(temp));
                break;
            case 5:
                if(pass)
                    requests_passengers.push_back(new PassengerRequest(pr));
                else
                    requests_drivers.push_back(new DriverRequest(dr));
                counter=-1;
                break;
            default:
                break;
        }
        counter++;
    }
    a_file.close();
}


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
                for (string i : parts)
                    aux.push_back(stoi(i));
                j.setPassenger(findPassengers(aux));
                aux={};
                break;
            case 2:
                parts = decompose(temp,',');
                for (string i : parts)
                    aux.push_back(stoi(i));
                j.setPath(aux);
                aux={};
                break;
            case 3:
                j.setStartTime(Time(temp));
                break;
            /*case 4:
                parts = decompose(temp,',');
                for (string i : parts)
                    times.push_back(Time(temp));
                j.setArrivalTimes(times);
                break;*/
            case 4:
                journeys.push_back(new Journey(j));
                j= Journey();
                counter=-1;
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

    for(int i = 0; i < n_edges; i++)
    {
        getline(e_data, text_line);
        vector<int> edge_values = getEdgeValues(text_line);
        this->graph.addEdge(edge_values[0], edge_values[1]);
    }

}

void Base::sign_up(string type) //type = passenger || type = driver
{
    string name, address;

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
        do {
            int cap=0;
            try {
                string capacity;
                cout << "Insert vehicle capacity\n";
                getline(cin, capacity);
                cap=stoi(capacity);
            }catch(exception err){
                cout<<"Invalid capacity! Try again.\n";
                continue;
            }
            Vehicle v(lastCarId, cap, lastId);
            Driver d(lastId, name, network, address, new Vehicle(v));
            drivers.push_back(&d);
            break;
        }while(true);
    }


}

int Base::sign_in(string type)
{
    string answer;
    do{
        cout << "Choose your account:" << endl;
        int tmp_id = 1;
        if(type == "passenger")
        {
            for(auto p : passengers)
                cout << tmp_id++ << ". " <<p->getName()<< endl;

            cout<< "type 0 to cancel"<<endl;
            getline(cin,answer);
            if(compare_str(answer,"0"))
                return -1;
            try{
                int id=stoi(answer);
                if (id >= 1 && id <= passengers.size())
                    return passengers[id-1]->getId();

            }catch(exception err){
            }
            cout << "Invalid answer! Try again" << endl;

        } else{
            for(auto d: drivers)
                cout << tmp_id++ << ". " <<d->getName()<< endl;
            cout<< "type 0 to cancel"<<endl;
            getline(cin,answer);
            if(compare_str(answer,"0"))
                return -1;
            try{
                int id=stoi(answer);
                if( id>= 1 && id <= drivers.size())
                    return drivers[id-1]->getId();

            }catch(exception err){
            }
            cout << "Invalid answer! Try again" << endl;
        }

    }while(true);

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


vector<PassengerRequest *> Base::getPossibleRequests(DriverRequest * request){
    vector<PassengerRequest *> result;

    for(auto r : requests_passengers) {
        if(graph.areVertexConnected(r->getStartingId(), request->getDestinationId()) && graph.areVertexConnected(r->getDestinationId(), request->getDestinationId())
        && graph.areVertexConnected(request->getStartingId(), r->getStartingId())){

            result.push_back(r);
        }
    }
    return result;
}



double Base::getDistance(int id1, int id2)
{
    if(algorithm != "floydwarshall")
    {
        if(algorithm == "astar")
            graph.AStar(id1, id2);
        else if(algorithm == "dijkstra")
            graph.dijkstraShortestPath(id1);
        auto v = graph.findVertex(id2);
        return v->getDist();
    }
    else
    {
        int i1 = graph.findVertexIdx(id1);
        int i2 = graph.findVertexIdx(id2);
        return graph.getW()[i1][i2];
    }

}

PassengerRequest * Base::getClosestToRequest(vector<PassengerRequest *> &requests, int dest_id){
    double temp = INF;
    PassengerRequest * result = NULL;
    int pos = requests.size();
    for(int i = 0; i < requests.size(); i++)
    {
        if(temp>getDistance(dest_id, requests[i]->getStartingId()))
        {
            temp = getDistance(dest_id, requests[i]->getStartingId());
            result = requests[i];
            pos = i;
        }
    }
    requests.erase(requests.begin() + pos);
    return result;
}


PassengerRequest * Base::getClosestToRequest(vector<PassengerRequest *> &requests, DriverRequest * driver, vector<Passenger*> current_passengers){

    double temp = INF;
    PassengerRequest * result = NULL;
    int pos = requests.size();
    int temp_people = 0;
    Driver * d = driver->getDriver();
    for(int i = 0; i < requests.size(); i++)
    {
        double orig_dist = getDistance(driver->getStartingId(), requests[i]->getStartingId());
        double dest_dist = getDistance(requests[i]->getDestinationId(), driver->getDestinationId());
        double median = (orig_dist+dest_dist)/2;
        int people_known = getNumberPeopleKnown(d, current_passengers, requests[i]->getPassenger());
        if((people_known==temp_people && median < temp) || (people_known>temp_people && (temp < (median+300))) || (temp_people>people_known && temp>=(median+300)))
        {
            temp = median;
            result = requests[i];
            pos = i;
            temp_people = people_known;
        }
    }
    requests.erase(requests.begin() + pos);
    return result;
}

int Base::getClosestId(vector<int> &ids, int comparing_id, bool dest)//Dest true if comparing id is the dest
{
    double cmp = INF;
    int id;
    int pos;
    double tmp;
    for(int i = 0; i < ids.size(); i++)
    {
        if(dest)
            tmp = getDistance(ids[i], comparing_id);
        else
            tmp = getDistance(comparing_id, ids[i]);
        if(cmp>tmp)
        {
            cmp = tmp;
            id = ids[i];
            pos = i;
        }
    }
    ids.erase(ids.begin() + pos);
    return id;

}
vector<int> Base::orderingIds(vector<int> start, int comparing_id, bool dest) //Dest true if comparing id is the dest
{
    vector<int> result;
    int tmp = comparing_id;
    while(start.size() > 0)
    {
        tmp = getClosestId(start, tmp, dest);
        result.push_back(tmp);
    }

    if(dest)
    {
        reverse(result.begin(), result.end());
    }
    return result;
}

vector<int> Base::recalculatePath(vector<Request*> requests)
{
    vector<int> result;
    vector<int> starting_ids;
    vector<int> destination_ids;
    result.push_back(requests[0]->getStartingId());
    for(int i = 1; i < requests.size(); i++)
    {
        starting_ids.push_back(requests[i]->getStartingId());
        destination_ids.push_back(requests[i]->getDestinationId());
    }
    starting_ids = orderingIds(starting_ids,requests[0]->getStartingId(), false);
    destination_ids = orderingIds(destination_ids, requests[0]->getDestinationId(), true);
    for(int i = 0; i < starting_ids.size(); i++)
    {
        result.push_back(starting_ids[i]);
    }
    for(int i = 0; i < destination_ids.size(); i++)
    {
        result.push_back(destination_ids[i]);
    }
    result.push_back(requests[0]->getDestinationId());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;

}

vector<Passenger *> Base::fillVehicle(DriverRequest *driverRequest, vector<int> *ids){
    vector<Passenger*> result;
    vector<Request *> aux;
    aux.push_back(driverRequest);
    vector<PassengerRequest *> possibleRequests = getPossibleRequests(driverRequest);
    int counter = 1;
    PassengerRequest * tmp;
    while(counter < driverRequest->getCapacity() && possibleRequests.size() >0)
    {
        tmp = getClosestToRequest(possibleRequests, driverRequest, result);

        if(checkTimeRestrictions(aux, tmp))
        {
            result.push_back(tmp->getPassenger());
            counter++;
            aux.push_back(tmp);
        }
    
    }

    *ids = recalculatePath(aux);
    return result;

}


bool Base::setup(vector<int> ids)//ids dos vértices pela qual temos que passar
{
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

vector<int> Base::calculatePath(vector<int>ids, double &distance) //os ids já estariam ordenados pela ordem que o condutor iria passar
{

    distance = 0;
    vector<int>result;
    vector<int> tmp;
    for(int i = 0; i < ids.size()-1; i++)
    {
        if(algorithm != "floydwarshall")
        {
            if(algorithm == "astar")
            {
                graph.AStar(ids[i], ids[i+1]);

            }
            else if(algorithm == "dijkstra")
            {
                graph.dijkstraShortestPath(ids[i]);

            }

            auto v = graph.findVertex(ids[i+1]);
            distance += v->getDist();
            tmp = graph.getPath(ids[i], ids[i+1]);
        }
        else{
            int id1 = graph.findVertexIdx(ids[i]);
            int id2 = graph.findVertexIdx(ids[i+1]);
            distance += graph.getW()[id1][id2];
            tmp = graph.getFloydWarshallPath(ids[i], ids[i+1]);

        }


        int j;
        if(i==0)
            j = 0;
        else j = 1;
        for(j; j < tmp.size(); j++)
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
    Journey* j = new Journey();
    vector<int>places;
    vector<int>path;
    double distance;
    vector<Passenger*> passengers = fillVehicle(request, &places);
    if(!setup(places)) return false;
    path = calculatePath(places, distance);
    j->setDriver(request->getDriver());
    j->setPassenger(passengers);
    j->setStartTime(request->getMinStartTime());
    j->setPath(path);
    if(!removeRequests(passengers, request)) return false;
    updatePeopleKnown(request->getDriver(), passengers);
    journeys.push_back(j);
    return true;


}

void Base::addDriverRequest(DriverRequest * request)
{
    requests_drivers.push_back(request);
}

void Base::addPassengerRequest(PassengerRequest * request)
{
    requests_passengers.push_back(request);
}

void Base::addPassenger(Passenger * passenger)
{
    lastId++;
    passenger->setId(lastId);
    passengers.push_back(passenger);
}

void Base::addDriver(Driver * driver)
{
    lastId++;
    driver->setId(lastId);
    lastCarId++;
    driver->getVehicle()->setDriverId(lastId);
    driver->getVehicle()->setId(lastCarId);
    drivers.push_back(driver);
}

Time Base::predictTime(double distance)
{

    double time = (distance*0.001)/maxSpeed;
    return Time(time);

}

bool Base::conditionTime(Request *r, Time t)
{
    return r->getMinStartTime() <= r->getMaxEndTime() - t;
}

vector<int> Base::getRequestPath(vector<int> ids, Request * request)
{
    vector<int> result;
    int pos_inicial = -1;
    for(int i = 0; i < ids.size(); i++)
    {
        if(ids[i] == request->getStartingId() || pos_inicial>0)
        {
            result.push_back(ids[i]);
            if(pos_inicial == -1)
                pos_inicial = i;
            if(ids[i] == request->getDestinationId())
                break;
        }
    }
    return result;
}

bool Base::checkTimeRestrictions(vector<Request*> requests, PassengerRequest * possible_request)
{

    requests.push_back(possible_request);
    vector<int> possible_path = recalculatePath(requests);
    requests.push_back(possible_request);
    double distance = 0;
    for(int i = 0; i < requests.size(); i++)
    {
        calculatePath(getRequestPath(possible_path, requests[i]), distance);
        if(!conditionTime(requests[i], predictTime(distance)))
            return false;

    }
    return true;

}


int Base::getNumberPeopleKnown(Driver *driver, vector<Passenger*> passengers, Passenger* possible_passenger )
{
    int result = 0;
    if(in(driver->getNetwork(), possible_passenger->getId()))
        result++;
    for(int i = 0; i < passengers.size(); i++)
    {
        if(in(passengers[i]->getNetwork(), possible_passenger->getId()))
            result++;
    }
    return result;
}

void Base::updatePeopleKnown(Driver *driver, vector<Passenger*> passengers)
{
    vector<Person*> people;
    people.push_back(driver);
    for(auto p : passengers)
    {
        people.push_back(p);
    }
    for(auto p : people)
    {
        p->addNetwork(people);
    }
}

void Base::writePassengers() {
    ofstream newfile;
    newfile.open("..\\resources\\files\\"+passengerFile);
    for (auto p : passengers) {
        newfile << p->getId() << endl;
        newfile << p->getName() << endl;
        for (int i : p->getNetwork()) {
            newfile << i;
            if(i!=*(p->getNetwork().end()-1))
                newfile<<", ";
        }

        newfile << endl <<p->getAddress() << endl;
        newfile << "::::::::::";
        if(p!=*(passengers.end()-1))
           newfile << endl;
    }
    //const char* fileName = ("..\\resources\\files\\"+passengerFile).c_str();
    newfile.close();
    //remove(fileName);
    //int i=rename("..\\resources\\files\\newPassengerFile.txt", fileName);
}

void Base::writeDrivers() {
    ofstream newfile;
    newfile.open("..\\resources\\files\\"+driverFile);
    for (auto d : drivers) {
        newfile <<d->getId() << endl;
        newfile << d->getName() << endl;
        for (int i : d->getNetwork()) {
            newfile << i;
            if(i!=*(d->getNetwork().end()-1))
                newfile<<", ";
        }
        newfile << endl <<d->getAddress() << endl;
        newfile << *d->getVehicle()<<endl;
        newfile  << "::::::::::";
        if(d!=*(drivers.end()-1))
            newfile << endl;
    }
    //const char* fileName = ("..\\resources\\files\\"+driverFile).c_str();
    newfile.close();
    //remove(fileName);
    //int i=rename("..\\resources\\files\\newDriverFile.txt", fileName);
}

void Base::writeRequests() {
    ofstream newfile;
    newfile.open("..\\resources\\files\\"+requestFile);
    for (auto r : requests_passengers) {
        newfile<<r->getPassenger()->getId()<<endl;
        newfile<<r->getStartingId()<<endl;
        newfile<<r->getDestinationId()<<endl;
        newfile<<r->getMinStartTime()<<endl;
        newfile<<r->getMaxEndTime()<<endl;
        newfile<< "::::::::::"<<endl;
    }
    for (auto r : requests_drivers) {
        newfile<<r->getDriver()->getId()<<endl;
        newfile<<r->getStartingId()<<endl;
        newfile<<r->getDestinationId()<<endl;
        newfile<<r->getMinStartTime()<<endl;
        newfile<<r->getMaxEndTime()<<endl;
        newfile<< "::::::::::";
        if(r!=*requests_drivers.end())
            newfile<<endl;
    }
    //const char* fileName = ("..\\resources\\files\\"+requestFile).c_str();
    newfile.close();
    //remove(fileName);
    //int i=rename("..\\resources\\files\\newRequestFile.txt", fileName);
}

void Base::writeJourneys() {
    ofstream newfile;
    newfile.open("..\\resources\\files\\"+journeyFile);
    for (auto j : journeys) {
        newfile<<j->getDriver()->getId()<<endl;
        for (Passenger *p : j->getPassenger()) {
            newfile << p->getId();
            if(p!=*(j->getPassenger().end()-1))
                newfile<<", ";
        }
        newfile<<endl;
        for (int i: j->getPath()) {
            newfile << i;
            if(i!=*(j->getPath().end()-1))
                newfile<<", ";
        }
        newfile<<endl<<j->getStartTime()<<endl;
        /*for (Time t: j->getArrivalTimes()) {
            newfile << t;
            if(!(t==*j->getArrivalTimes().end()))
                newfile<<", ";
        }*/
        newfile<< "::::::::::";
        if(j!=*(journeys.end()-1))
            newfile<<endl;
    }

    //const char* fileName = ("..\\resources\\files\\"+journeyFile).c_str();
    newfile.close();
    //remove(fileName);
    //int i=rename("..\\resources\\files\\newJourneyFile.txt", fileName);
}

void Base::setPassengerFile(string fileName) {
    passengerFile=fileName;
}

void Base::setJourneyFile(string fileName) {
    journeyFile=fileName;
}

void Base::setRequestFile(string fileName) {
    requestFile=fileName;
}

void Base::setDriverFile(string fileName) {
    driverFile=fileName;
}

string Base::getPassengerFile() {
    return passengerFile;
}

string Base::getDriverFile() {
    return driverFile;
}

string Base::getRequestFile(){
    return requestFile;
}

string Base::getJourneyFile(){
    return journeyFile;
}

void Base::updateFiles() {
    writeDrivers();
    writeJourneys();
    writePassengers();
    writeRequests();
}

string Base::getAlgorithm() {
    return algorithm;
}

void Base::setAlgorithm(string alg) {
    algorithm=alg;

}

void Base::run_algorithm() {
    int count = 0;
    vector<DriverRequest*> vd = requests_drivers;
    for (DriverRequest *d : vd){
        if (createJourney(d))
            cout<<++count<<" -journey successful"<<endl;
        else
            cout<<++count<<" -journey unsuccessful"<<endl;

    }






}


void Base::loadFloydWarshall() {
    graph.floydWarshallShortestPath();
}

string Base::getMap() {
    return map;
}

void Base::setMap(string m) {
    map=m;
}

void Base::setlastIDs() {
    int id=0;
    int carId=0;
    for (Passenger * p: passengers)
        if(p->getId()>id)
            id=p->getId();
    for (Driver * d: drivers) {
        if (d->getId() > id)
            id = d->getId();
        if(d->getVehicle()->getId()>carId)
            carId=d->getVehicle()->getId();
    }

    lastId=id;
    lastCarId=carId;

}


