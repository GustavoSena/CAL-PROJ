//
// Created by user on 23/05/2020.
//

#include <fstream>
#include "FloydWarshall.h"
#include "utils.h"

int row=0;
int col=0;
using namespace std;
void writeMatrix(double **matrix){

    ofstream newfile;
    newfile.open("..\\resources\\FloydWarshall\\FloydWarshall.txt");

    int i=0;
    while(i<row){
        int j=0;
        while(j+1<col){
            newfile<<matrix[i][j]<<" , ";
            cout<<matrix[i][j]<<" , ";

            j++;
        }
        newfile<<matrix[i][j]<<endl;
        cout<<matrix[i][j]<<endl;
        i++;
    }
    newfile.close();

}



double ** readMatrix(){

    ifstream a_file;
    a_file.open("..\\resources\\FloydWarshall\\FloydWarshall.txt");
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