//
// Created by user on 08/05/2020.
//

#ifndef MEETUPRIDER_NEWGRAPH_H
#define MEETUPRIDER_NEWGRAPH_H

#include <vector>
#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include <cmath>

#include "MutablePriorityQueue.h"
#include "FloydWarshall.h"

using namespace std;

class Edge;
class Vertex;
class Graph;

#define INF std::numeric_limits<double>::max()

//Node
class Vertex{
private:
    int id;
    int x;
    int y;
    vector<Edge> adj;
    bool visited; //For connectivity
    //Dijkstra
    double dist = 0;
    Vertex *path = NULL;
    int queueIndex = 0;
    bool processing = false;

    double comparing_var = 0;

    void addEdge(Vertex * dest);
public:
    Vertex(int id, int x, int y);

    int getId() const;

    void setId(int id);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    double getDist();

    const vector<Edge> &getAdj() const;

    void setAdj(const vector<Edge> &adj);

    double distance(Vertex * v);

    bool operator<(Vertex & vertex); // required by MutablePriorityQueue

    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;
};




//Edge
class Edge{
private:
    Vertex *orig;
    Vertex *dest;
    double weight; //Distância entre os vértices;
public:
    Edge(Vertex *orig, Vertex *dest);

    Vertex *getOrig() const;

    void setOrig(Vertex *orig);

    Vertex *getDest() const;

    void setDest(Vertex *dest);

    double getWeight() const;

    void setWeight(double weight);

    friend class Graph;
    friend class Vertex;

};

//Graph
class Graph{
private:
    vector<Vertex *> vertexSet;
    //Floyd Warshall Algorithm
    double ** W = nullptr; //Distance
    int ** P = nullptr; //Path


public:
    Graph();

    const vector<Vertex*> getVertexSet() const;

    void setVertexSet(const vector<Vertex*> vertexSet);

    Vertex * findVertex(int id);
    bool addVertex(int id, int x, int y);
    bool addEdge(int id1, int id2);
    int getGraphSize() const;

    //Floyd Warshall Algorithm
    int findVertexIdx(const int id) const;
    void floydWarshallShortestPath();
    vector<int> getFloydWarshallPath(const int orig, const int dest) const;
    double ** getW();
    int ** getP();


    bool areVertexConnected(int id1, int id2);

    //Dijkstra
    Vertex * initSSource(int orig_id);
    bool relax(Vertex *v, Vertex *w, double weight);
    void dijkstraShortestPath(int orig_id);
    vector<int> getPath(int orig_id, int dest_id);

    //A*
    double heuristic(Vertex * orig, Vertex * dest);
    bool relaxA(Vertex *v, Vertex *w, Vertex *dest, double weight);
    void AStar(int orig_id, int dest_id);

    void writeFiles(string path_file, string distance_file);

    void readFiles(string path_file, string distance_file);
};

#endif //MEETUPRIDER_NEWGRAPH_H
