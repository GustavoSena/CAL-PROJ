
#include <iostream>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "src/Base.h"


using namespace std;

int main() {

    string node_text = "..\\resources\\maps\\8x8\\nodes.txt";
    string edge_text = "..\\resources\\maps\\8x8\\edges.txt";
    Base b("..\\resources\\files\\Base.txt");
    b.loadGraph(node_text, edge_text);

    cout << "Size of graph: " << b.getGraph().getGraphSize();

}