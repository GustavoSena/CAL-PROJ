//
// Created by user on 08/05/2020.
//

#ifndef MEETUPRIDER_BASE_H
#define MEETUPRIDER_BASE_H

#include <vector>
#include <iostream>
#include <fstream>
#include "NewGraph.h"
#include "Person.h"
#include "Request.h"
#include "Journey.h"
#include "utils.h"
#include "Time.h"
#include "FloydWarshall.h"


using namespace std;


class Base {
private:
    Graph graph;
    vector<Passenger *> passengers;
    vector<Driver *> drivers;
    vector<DriverRequest *> requests_drivers;
    vector<PassengerRequest *> requests_passengers;
    vector<Journey *> journeys;
    int lastId = 0; //the last id used for passengers and drivers
    int lastCarId = 0; //the last id used for cars
    int maxSpeed; //50 km/h
    string requestFile;
    string journeyFile;
    string driverFile;
    string passengerFile;
    string algorithm;
    string map;

public:

    //construtor da base que dá set aos ficheiros com informação
    Base(string fileName);

    Base();

    //função que vai buscar a informação dos passengers ao ficheiro e adiciona à base
    void loadPassengers(string fileName);

    //função que vai buscar a informação dos drivers ao ficheiro e adiciona à base
    void loadDrivers(string fileName);

    //função que vai buscar a informação dos requests ao ficheiro e adiciona à base
    void loadRequests(string fileName);

    //função que vai buscar a informação das journeys ao ficheiro e adiciona à base
    void loadJourneys(string fileName);

    //função que escreve no ficheiro a informação dos passengers
    void writePassengers();

    //função que escreve no ficheiro a informação dos drivers
    void writeDrivers();

    //função que escreve no ficheiro a informação dos requests
    void writeRequests();

    //função que escreve no ficheiro a informação das journeys
    void writeJourneys();

    //função que chama as funções de escrita de forma a atualizar tudo
    void updateFiles();

    void setPassengerFile(string fileName);

    void setJourneyFile(string fileName);

    void setRequestFile(string fileName);

    void setDriverFile(string fileName);

    void setAlgorithm(string alg);

    void setMap(string m);

    string getPassengerFile();

    string getDriverFile();

    string getRequestFile();

    string getJourneyFile();

    string getAlgorithm();

    string getMap();

    Graph &getGraph() ;

    void setGraph(const Graph &graph);

    const vector<Passenger*> getPassengers() const;

    void setPassengers( vector<Passenger*>  passengers);

    const vector<Driver*>  getDrivers() const;

    void setDrivers( vector<Driver*>  drivers);


    const vector<Journey*> getJourneys() const;

    void setJourneys(vector<Journey*> journeys);

    //função que a partir dos ficheiros dos nodes e das edges, cria o grafo com essas informações
    void loadGraph(string node_text, string edge_text);

    //função que permite a um utilizador inscrever-se na aplicação
    void sign_up(string type);

    //função que permite a um utilizador entrar na aplicação
    int sign_in(string type);

    //função que retorna o endereço para o driver que tem o id do parâmetro
    Driver *findDriver(int id);

    //função que retorna o endereço para o passenger que tem o id do parâmetro
    Passenger *findPassenger(int id);

    //função que retorna um vetor com endereços para os passangers correspondentes aos ids do parametro do vetor
    vector<Passenger*> findPassengers(vector<int> ids);

    //a partir do driver request, retornar o vetor de requests de passengers que à partida serão possíveis de atender
    //analisando a conetividade dos ids de cada passenger request com os ids de partida e chegada do driver request
    vector<PassengerRequest *> getPossibleRequests(DriverRequest * request);

    //retorna a distância entre dois vértices
    //usa o algoritmo definido na base
    double getDistance(int id1, int id2);

    PassengerRequest * getClosestToRequest(vector<PassengerRequest *> &requests, int dest_id);

    //retorna o passenger request que é melhor para o caso atual
    //o passenger request melhor é aquele que tem o melhor compromisso entre as distancias do request do driver e o numero de pessoas conhecidas no carro
    PassengerRequest * getClosestToRequest(vector<PassengerRequest *> &requests, DriverRequest * driver, vector<Passenger*> current_passengers);

    //retorna o id do vértice mais próximo do vetor de ids e apaga-o deste vetor
    //bool dest é verdadeiro se o comparing id é o destino: é importante para a ordem dos parametros para chamar getDistance()
    int getClosestId(vector<int> &ids, int comparing_id, bool dest);

    //ordena o vetor de ids de acordo com a proximidade ao comparing_id e retorna-o
    vector<int> orderingIds(vector<int> start, int comparing_id, bool dest);

    //retorna o vetor de ids com a ordem certa pela qual o driver terá que passar obrigatoriamente (startingIds e destinationIds)
    vector<int> recalculatePath(vector<Request*> requests);

    //retorna o vetor de endereços para os passageiros que vão com o condutor na sua viagem
    //o vector de ids terá a ordem dos ids dos vértices pela qual o driver terá que passar obrigatoriamente (startingIds e destinationIds)
    vector<Passenger*> fillVehicle(DriverRequest *driverRequest, vector<int> *ids);

    //verifica se há a conexão necessária entre os ids
    //Vetor ids já está com a ordem certa
    bool setup(vector<int> ids);

    //calcula o path completo que o driver tem que passar
    vector<int> calculatePath(vector<int>ids, double &distance);

    void run_algorithm();

    //remove o endereço do passanger do vetor de passenger requests da base
    //retorna true se o fez com sucesso
    bool removePassengerRequests(Passenger * p);

    //retorna true se o fez com sucesso
    bool removeRequests(vector<Passenger*> passengers, DriverRequest * request);

    bool createJourney(DriverRequest * request);

    void addDriverRequest(DriverRequest * request);

    void addPassengerRequest(PassengerRequest * request);

    void addPassenger(Passenger * passenger);

    void addDriver(Driver * driver);

    Time predictTime(double distance);

    bool conditionTime(Request *r, Time t);

    vector<int> getRequestPath(vector<int> ids, Request * request);

    bool checkTimeRestrictions(vector<Request*> requests, PassengerRequest * possible_request);

    int getNumberPeopleKnown(Driver *driver, vector<Passenger*> passengers, Passenger* possible_passenger);

    void updatePeopleKnown(Driver *driver, vector<Passenger*> passengers);

    void loadFloydWarshall();


    void setlastIDs();

};


#endif //MEETUPRIDER_BASE_H
