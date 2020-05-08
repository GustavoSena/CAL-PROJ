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

    void addEdge(Vertex * dest);
public:
    Vertex(int id, int x, int y);

    int getId() const;

    void setId(int id);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    const vector<Edge> &getAdj() const;

    void setAdj(const vector<Edge> &adj);

    double distance(Vertex * v);

    friend class Graph;
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

public:
    Graph();

    const vector<Vertex*> getVertexSet() const;

    void setVertexSet(const vector<Vertex*> vertexSet);

    Vertex * findVertex(int id);
    bool addVertex(int id, int x, int y);
    bool addEdge(int id1, int id2);
    int getGraphSize() const;




};

#endif //MEETUPRIDER_NEWGRAPH_H
