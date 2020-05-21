
#include <iostream>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "src/Base.h"
#include "src/menus.h"


using namespace std;


void testing_algorithms(Graph b,int orig_id, int dest_id)
{
    if(!b.areVertexConnected(orig_id,dest_id))
        cout << "Nodes not connected\n";
    else
    {
        b.AStar(orig_id, dest_id);
        vector<int> first_result = b.getPath(orig_id,dest_id);
        b.dijkstraShortestPath(orig_id);
        vector<int> second_result = b.getPath(orig_id,dest_id);
        cout << "A*"<< endl;
        for (int i = 0; i < first_result.size(); i++)
        {
            cout<< first_result[i] << " ";
        }
        cout << endl << "Dijkstra"<< endl;
        for (int i = 0; i < second_result.size(); i++)
        {
            cout<< second_result[i] << " ";
        }
        cout << endl << endl;
    }
}




int main() {

    string node_text = "..\\resources\\maps\\8x8\\nodes.txt";
    string edge_text = "..\\resources\\maps\\8x8\\edges.txt";
    Base b("..\\resources\\files\\Base.txt");
    b.loadGraph(node_text, edge_text);
    vector<int> network;
    Vehicle car(0, 4, 0);
    Driver d(0, "Joao", network, "rua", &car);
    Passenger p1(0, "Maria", network, "rua");
    Passenger p2(0, "Henrique", network, "rua");
    Passenger p3(0, "Manel", network, "rua");
    Passenger p4(0, "Julio", network, "rua");
    b.addDriver(&d);
    b.addPassenger(&p1);
    b.addPassenger(&p2);
    b.addPassenger(&p3);
    b.addPassenger(&p4);
    if(b.getGraph().areVertexConnected(4,25))
        cout << "true"<< endl;
    else
        cout << "false" << endl;
    Time t1(16, 0, 0);
    Time t2(18,0,0);
    DriverRequest request(t1, t2, t2,25,4, &d);
    PassengerRequest r1(t1,t2, t2, 25,5,&p1);
    PassengerRequest r2(t1, t2, t2,25, 6, &p2);
    PassengerRequest r3(t1, t2, t2,25, 7, &p3);
    PassengerRequest r4(t1, t2, t2, 16, 5, &p4);
    b.addDriverRequest(&request);
    b.addPassengerRequest(&r1);
    b.addPassengerRequest(&r2);
    b.addPassengerRequest(&r3);
    b.addPassengerRequest(&r4);
    if(b.createJourney(&request))
        cout<< "True"<< endl;
    else
        cout << "False"<<endl;


    //b.updateFiles();

    //mapViewer(edge_text, node_text);
}







