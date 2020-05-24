//
// Created by user on 23/05/2020.
//

#ifndef MEETUPRIDER_FLOYDWARSHALL_H
#define MEETUPRIDER_FLOYDWARSHALL_H

#include "NewGraph.h"
#include <iostream>
void writeDistanceMatrix(double **matrix, string text_file, int size);

double ** readDistanceMatrix(string text_file);

void writePathMatrix(int **matrix, string text_file, int size);

int ** readPathMatrix(string text_file);


#endif //MEETUPRIDER_FLOYDWARSHALL_H
