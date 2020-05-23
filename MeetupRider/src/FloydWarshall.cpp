//
// Created by user on 23/05/2020.
//

#include <fstream>
#include "FloydWarshall.h"
#include "utils.h"


using namespace std;
void writeMatrix(double **matrix, string text_file){

    ofstream newfile;
    newfile.open("..\\resources\\FloydWarshall\\newFloydWarshall.txt");

    int i=0;
    while(matrix[i]!= nullptr){
        int j=0;
        while(matrix[i][j+1]!=NULL){
            newfile<<matrix[i][j]<<" , ";
            j++;
        }
        newfile<<matrix[i][j]<<endl;
        i++;
    }

    const char* fileName = "..\\resources\\FloydWarshall\\FloydWarshall.txt";
    newfile.close();
    remove(fileName);
    rename("..\\resources\\FloydWarshall\\newFloydWarshall.txt", fileName);

}



double ** readMatrix(string text_file){

    ifstream a_file;
    a_file.open("..\\resources\\FloydWarshall\\FloydWarshall.txt");
    string temp;
    int counter=0;
    int counter2=0;
    vector<vector<double>> aux;
    double **matrix;
    while(getline(a_file,temp)){
        vector<string> parts=decompose(temp,',');
        vector<double>aux2;
        for (string temp2:parts){
            aux2.push_back(stod(temp2));
            matrix[counter][counter2]=stod(temp2);
            counter2++;
        }
        aux.push_back(aux2);
        counter++;
    }

    //apagar vetores se arrays funcionarem


    a_file.close();
    return matrix;
}