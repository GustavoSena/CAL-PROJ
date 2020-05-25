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

//tira os espaços brancos da string
void trim(string &str);

//divide a string em várias strings com a char sep e retorna o vetor com essas strings
vector<string> decompose(string s, char sep);

//compara as strings
bool compare_str(string str1, string str2);

//separa uma string em várias strings com a char delimiter e retorna o vetor de strings sem espaços
vector<string> split(string str, char delimiter, size_t max_splits);

//vai buscar os valores para um vértice a partir duma linha
vector<int> getNodeValues(string text_line);

//vai buscar os valores para uma aresta a partir duma linha
vector<int> getEdgeValues(string text_line);




vector<int> subVector(vector<int> init, int pos);

bool in(vector<int> vec, int n);
#endif //MEETUPRIDER_UTILS_H


