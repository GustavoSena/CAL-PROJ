//
// Created by user on 23/05/2020.
//

#ifndef MEETUPRIDER_FLOYDWARSHALL_H
#define MEETUPRIDER_FLOYDWARSHALL_H

#include "NewGraph.h"
#include <iostream>

//escreve a matriz das distâncias no ficheiro
void writeDistanceMatrix(double **matrix, string text_file, int size);

//lê a matriz das distâncias do ficheiro
double ** readDistanceMatrix(string text_file);

//escreve a matriz do caminho no ficheiro
void writePathMatrix(int **matrix, string text_file, int size);

// le a matriz do caminho do ficheiro
int ** readPathMatrix(string text_file);


#endif //MEETUPRIDER_FLOYDWARSHALL_H
