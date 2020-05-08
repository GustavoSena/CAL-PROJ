
#include <iostream>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "src/graphviewer.h"
#include "src/utils.h"




int main() {

    string porto_nodes = "maps/Porto/nodes_x_y_porto.txt";
    string porto_edges = "maps/Porto/edges_porto.txt";
    mapViewer(porto_edges, porto_nodes);


}