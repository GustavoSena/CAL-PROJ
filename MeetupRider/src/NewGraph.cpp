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

//Floyd Warshall Algorithm
int Graph::findVertexIdx(const int id) const{

    for (int i = 0; i < vertexSet.size(); i++)
    {
        if(vertexSet[i]->id == id)
            return i;
    }
    return -1;
}

template <class T>
void deleteMatrix(T **m, int n)
{
    if(m != nullptr)
    {
        for (int i = 0; i < n; i++)
        {
            if(m[i]!= nullptr)
            {
                delete [] m[i];
            }

        }
        delete [] m;
    }
}

//Falta testar
void Graph::floydWarshallShortestPath(){
    int n = vertexSet.size();
    deleteMatrix(W, n);
    deleteMatrix(P, n);
    W = new double *[n];
    P = new int *[n];
    for (int i = 0; i < n; i++)
    {
        W[i] = new double[n];
        P[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            W[i][j] = i == j? 0 : INF;
            P[i][j] = -1;

        }
        for(auto e : vertexSet[i]->adj)
        {
            int j = findVertexIdx(e.dest->id);
            W[i][j] = e.weight;
            P[i][j] = i;
        }
    }

    for (int k = 0; k < n ; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(W[i][k] == INF || W[k][j] == INF) continue;
                int val = W[i][k] + W[k][j];
                if (val < W[i][j]){
                    W[i][j] = val;
                    P[i][j] = P[k][j];
                }

            }
        }
    }

}

vector<int> Graph::getFloydWarshallPath(const int orig, const int dest) const {
    vector<int> result;
    int i = findVertexIdx(orig);
    int j = findVertexIdx(dest);
    if(i == -1 || j == -1 || W[i][j] == INF) //missing or disconected
        return result;
    for(; j!=-1; j = P[i][j])
    {
        result.push_back(vertexSet[j]->id);
    }
    reverse(result.begin(), result.end());
    return result;

}

//Connectivity - https://www.geeksforgeeks.org/find-if-there-is-a-path-between-two-vertices-in-a-given-graph/
//Falta testar
bool Graph::areVertexConnected(int id1, int id2)
{
    if(id1 == id2)
        return true;
    for(auto v : vertexSet)
    {
        v->visited = false;
    }
    auto orig = findVertex(id1);
    auto dest = findVertex(id2);
    queue<Vertex *> q;
    q.push(orig);

    while(!q.empty())
    {
        auto tmp = q.front();
        q.pop();

        for (auto e : tmp->adj)
        {
            if(e.dest == dest)
                return true;
            if(!e.dest->visited)
            {
                e.dest->visited = true;
                q.push(e.dest);
            }
        }
    }

    return false;

}

