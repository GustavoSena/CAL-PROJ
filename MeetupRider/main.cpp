
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
    /*testing_algorithms(b.getGraph(), 1 , 7);
    testing_algorithms(b.getGraph(), 4 , 50);
    testing_algorithms(b.getGraph(), 45 , 67);
    testing_algorithms(b.getGraph(), 30 , 50);
    testing_algorithms(b.getGraph(), 10 , 34);
    testing_algorithms(b.getGraph(), 23 , 70);

    testing_algorithms(b.getGraph(), 5, 20);*/
    //AStarView(b.getGraph(),14,17);
    //DijkstraView(b.getGraph(),10,23);

    testing_algorithms(b.getGraph(), 5, 20);

    AStarView(b.getGraph(),10,34);
    //DijkstraView(b.getGraph(),10,34);







}