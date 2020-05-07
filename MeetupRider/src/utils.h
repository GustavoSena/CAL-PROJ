//
// Created by user on 07/05/2020.
//

#ifndef CAL_PROJ_UTILS_H
#define CAL_PROJ_UTILS_H

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "graphviewer.h"


using namespace std;


void trim(string &str)
{
    const string WHITE_SPACE = " \t\n\v\f\r";
    str.erase(0, str.find_first_not_of(WHITE_SPACE));
    str.erase(str.find_last_not_of(WHITE_SPACE) + 1, string::npos);
}


vector<string> split(string str, char delimiter, size_t max_splits)
{
    str += '\n';
    string temp;
    vector<string> result;
    stringstream line_stream(str);


    for (size_t i = 0; i < max_splits; i++)
    {
        getline(line_stream, temp, delimiter);
        trim(temp);
        result.push_back(temp);
    }

    getline(line_stream, temp, '\n');
    trim(temp);
    result.push_back(temp);

    return result;
}

void mapViewer(string edge_file, string node_file)
{

    ifstream n_data(node_file);
    ifstream e_data(edge_file);

    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    vector<string> tmp;
    string text_line;
    getline(n_data,text_line);
    int n_nodes = stoi(text_line);
    for (int i = 0; i < n_nodes; i++){

        getline(n_data, text_line);
        tmp = split(text_line, ';', 3);
        gv->addNode(stoi(tmp[0]), stoi(tmp[1]), stoi(tmp[2]));

    }


    string text;
    getline(e_data, text);
    int n_edges = stoi(text);
    for(int i = 0; i < n_edges; i++)
    {
        getline(e_data, text);
        tmp = split(text, ';', 3);
        gv->addEdge(stoi(tmp[0]), stoi(tmp[1]), stoi(tmp[2]), EdgeType::DIRECTED );
    }
}




#endif //CAL_PROJ_UTILS_H


