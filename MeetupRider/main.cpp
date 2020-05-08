
#include <iostream>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "src/Base.h"


using namespace std;

int main() {

    string node_text = "C:\\Users\\user\\Desktop\\CAL-PROJ\\MeetupRider\\maps\\8x8\\nodes.txt";
    string edge_text = "C:\\Users\\user\\Desktop\\CAL-PROJ\\MeetupRider\\maps\\8x8\\edges.txt";
    Base b;
    b.loadGraph(node_text, edge_text);

    cout << "Size of graph: " << b.getGraph().getGraphSize();

}