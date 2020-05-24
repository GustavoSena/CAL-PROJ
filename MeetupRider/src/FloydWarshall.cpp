//
// Created by user on 23/05/2020.
//

#include <fstream>
#include "FloydWarshall.h"
#include "utils.h"

int row=0;
int col=0;
using namespace std;
void writeDistanceMatrix(double **matrix, string text_file, int size){

    ofstream newfile;
    newfile.open(text_file);
    col = size;
    row = size;
    int i=0;
    while(i<row){
        int j=0;
        while(j+1<col){
            newfile<<matrix[i][j]<<",";


            j++;
        }
        newfile<<matrix[i][j]<<endl;

        i++;
    }
    newfile.close();

}



double ** readDistanceMatrix(string text_file){

    ifstream a_file;
    a_file.open(text_file);
    string temp;
    int counter=0;
    int counter2=0;
    vector<vector<double>> aux;
    while(getline(a_file,temp)){
        counter2=0;
        vector<string> parts=decompose(temp,',');
        vector<double>aux2;
        for (string temp2:parts){

            aux2.push_back(stod(temp2));
            counter2++;
        }

        aux.push_back(aux2);
        counter++;

    }

    double **matrix = new double*[counter];
    for (int i=0;i<counter;i++){
        matrix[i]= new double[counter2];
        for (int j=0; j<counter2;j++) {
            matrix[i][j] = aux[i][j];
        }
    }
    col=counter2;
    row=counter;
    a_file.close();
    return matrix;
}

void writePathMatrix(int **matrix, string text_file, int size)
{
    ofstream newfile;
    newfile.open(text_file);

    col = size;
    row = size;
    int i=0;
    while(i<row){
        int j=0;
        while(j+1<col){
            newfile<<matrix[i][j]<<",";


            j++;
        }
        newfile<<matrix[i][j]<<endl;

        i++;
    }
    newfile.close();

}

int ** readPathMatrix(string text_file)
{
    ifstream a_file;
    a_file.open(text_file);
    string temp;
    int counter=0;
    int counter2=0;
    vector<vector<int>> aux;
    while(getline(a_file,temp)){
        counter2=0;
        vector<string> parts=decompose(temp,',');
        vector<int>aux2;
        for (string temp2:parts){

            aux2.push_back(stoi(temp2));
            counter2++;
        }

        aux.push_back(aux2);
        counter++;

    }

    int **matrix = new int*[counter];
    for (int i=0;i<counter;i++){
        matrix[i]= new int[counter2];
        for (int j=0; j<counter2;j++) {
            matrix[i][j] = aux[i][j];
        }
    }
    col=counter2;
    row=counter;
    a_file.close();
    return matrix;
}