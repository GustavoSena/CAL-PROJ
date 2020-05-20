//
// Created by user on 07/05/2020.
//

#ifndef MEETUPRIDER_UTILS_H
#define MEETUPRIDER_UTILS_H

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "graphviewer.h"
#include "NewGraph.h"


using namespace std;


void trim(string &str);

vector<string> decompose(string s, char sep);

bool compare_str(string str1, string str2);

vector<string> split(string str, char delimiter, size_t max_splits);


vector<int> getNodeValues(string text_line); //Atm only for grid graphs


vector<int> getEdgeValues(string text_line);


void mapViewer(string edge_file, string node_file);

void pathViewer(Graph graph, vector<int> path);

void AStarView(Graph b, int orig_id, int dest_id);

void DijkstraView(Graph b, int orig_id, int dest_id);

vector<int> subVector(vector<int> init, int pos);

#endif //MEETUPRIDER_UTILS_H


