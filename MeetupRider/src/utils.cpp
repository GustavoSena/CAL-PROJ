//
// Created by user on 08/05/2020.
//
#include "utils.h"

void trim(string &str)
{
    const string WHITE_SPACE = " \t\n\v\f\r";
    str.erase(0, str.find_first_not_of(WHITE_SPACE));
    str.erase(str.find_last_not_of(WHITE_SPACE) + 1, string::npos);
}

vector<string> decompose(string s, char sep) {
    vector<string> elements;
    string usage = "";
    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] == sep) {
            trim(usage);
            //replaceAccent(usage);
            elements.push_back(usage);
            usage = "";
        }
        else {
            usage += s[i];

            if (i == s.length() - 1) {
                trim(usage);
                elements.push_back(usage);
            }

        }
    }
    return elements;
}
vector<string> split(string str, char delimiter, size_t max_splits)
{
    str += '\n';
    string temp;
    vector<string> result;
    stringstream line_stream(str);


    for (size_t i = 0; i < max_splits; i++)
    {
        getline(line_stream, temp, delimiter);
        trim(temp);
        result.push_back(temp);
    }

    getline(line_stream, temp, '\n');
    trim(temp);
    result.push_back(temp);

    return result;
}

vector<int> getNodeValues(string text_line) //Atm only for grid graphs
{
    vector<string> tmp = split(text_line, ',', 3);
    vector<int> result;
    int size1 = tmp[0].size() - 1;
    result.push_back(stoi(tmp[0].substr(1, size1)));
    result.push_back(stoi(tmp[1]));
    int size2 = tmp[2].size() - 1;
    result.push_back(stoi(tmp[2].substr(0,size2 )));
    return result;

}

vector<int> getEdgeValues(string text_line)
{
    vector<string> tmp = split(text_line, ',', 2);
    vector<int> result;
    result.push_back(stoi(tmp[0].substr(1, string::npos)));
    int size = tmp[1].size()-1;
    result.push_back(stoi(tmp[1].substr(0, size)));
    return result;
}

void mapViewer(string edge_file, string node_file)
{

    ifstream n_data(node_file);
    ifstream e_data(edge_file);




    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");


    string text_line;
    getline(n_data,text_line);
    int n_nodes = stoi(text_line);
    for (int i = 0; i < n_nodes; i++){

        getline(n_data, text_line);
        vector<int> nvalues = getNodeValues(text_line);
        gv->addNode(nvalues[0], nvalues[1], nvalues[2]);

    }


    string text;
    getline(e_data, text);
    int n_edges = stoi(text);
    int id = 1;
    for(int i = 0; i < n_edges; i++)
    {
        getline(e_data, text);
        vector<int> evalues = getEdgeValues(text);
        gv->addEdge(id, evalues[0], evalues[1], EdgeType::DIRECTED);
        id++;
    }

    getchar();
    gv->closeWindow();

}

void pathViewer(Graph graph, vector<int> path)
{
    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    for(int i = 0; i < path.size(); i++)
    {
        auto v = graph.findVertex(path[i]);
        gv->addNode(path[i], v->getX(), v->getY());
    }

    int id = 1;

    for(int i = 0; i < path.size()-1; i++)
    {
        gv->addEdge(id, path[i], path[i+1], EdgeType::DIRECTED);
        id++;
    }

    getchar();
    gv->closeWindow();

}


void AStarView(Graph b, int orig_id, int dest_id)
{
    if(!b.areVertexConnected(orig_id,dest_id))
        cout << "Nodes not connected\n";
    else
    {
        b.AStar(orig_id, dest_id);
        vector<int> result = b.getPath(orig_id,dest_id);
        pathViewer(b, result);
    }
}

void DijkstraView(Graph b, int orig_id, int dest_id)
{
    if(!b.areVertexConnected(orig_id,dest_id))
        cout << "Nodes not connected\n";
    else
    {
        b.dijkstraShortestPath(orig_id);
        vector<int> result = b.getPath(orig_id,dest_id);
        pathViewer(b, result);
    }
}