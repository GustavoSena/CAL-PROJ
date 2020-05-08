//
// Created by user on 08/05/2020.
//

#include "NewGraph.h"

Vertex::Vertex(int id, int x, int y)
{
    this->id = id;
    this->x = x;
    this->y = y;
}

int Vertex::getId() const {
    return id;
}

void Vertex::setId(int id) {
    Vertex::id = id;
}

int Vertex::getX() const {
    return x;
}

void Vertex::setX(int x) {
    Vertex::x = x;
}

int Vertex::getY() const {
    return y;
}

void Vertex::setY(int y) {
    Vertex::y = y;
}

const vector<Edge> & Vertex::getAdj() const {
    return adj;
}

void Vertex::setAdj(const vector<Edge> &adj) {
    Vertex::adj = adj;
}

void Vertex::addEdge(Vertex * dest){
    adj.push_back(Edge(this, dest));
}

double Vertex::distance(Vertex * v){
    double result = sqrt(pow(x-v->x, 2) + pow(y-v->y,2));
    return result;
}

Edge::Edge(Vertex *orig, Vertex *dest)
{
    this->orig = orig;
    this->dest = dest;
    this->weight = orig->distance(dest);
}

Vertex *Edge::getOrig() const {
    return orig;
}

void Edge::setOrig(Vertex *orig) {
    Edge::orig = orig;
}

Vertex *Edge::getDest() const {
    return dest;
}

void Edge::setDest(Vertex *dest) {
    Edge::dest = dest;
}

double Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(double weight) {
    Edge::weight = weight;
}

Graph::Graph()
{

}

const vector<Vertex*>  Graph::getVertexSet() const{
    return vertexSet;
}

void Graph::setVertexSet(const vector<Vertex*> vertexSet) {
    Graph::vertexSet = vertexSet;
}

Vertex* Graph::findVertex(int id){
    for (auto v : vertexSet)
    {
        if (v->id == id)
            return v;
    }
    return nullptr;
}

bool Graph::addVertex(int id, int x, int y) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id,x,y));
    return true;
}

bool Graph::addEdge(int id1, int id2) {
    auto src = findVertex(id1);
    auto dest = findVertex(id2);
    if (src == nullptr || dest == nullptr)
        return false;
    src->addEdge(dest);
    return true;
}

int Graph::getGraphSize() const {
    return vertexSet.size();
}