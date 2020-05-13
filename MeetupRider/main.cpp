
#include <iostream>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "src/Base.h"
#include "src/menus.h"


using namespace std;

int main() {

    string node_text = "..\\resources\\maps\\example\\nodes.txt";
    string edge_text = "..\\resources\\maps\\example\\edges.txt";
    Base b("..\\resources\\files\\Base.txt");
    b.loadGraph(node_text, edge_text);

    main_menu();

}