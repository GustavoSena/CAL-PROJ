//
// Created by user on 23/05/2020.
//

#include "graphDrawing.h"
#include "utils.h"

void mapViewer(Graph *g, bool city_map, vector<int> path, bool show_path)
{
    int width = 750;
    int height = 750;
    int min_x = INT_MAX;
    int min_y = INT_MAX;
    int max_x = INT_MIN;
    int max_y = INT_MIN;

    GraphViewer *gv = new GraphViewer(width, height, false);
    gv->defineEdgeCurved(false);
    gv->createWindow(width, height);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");


    int id = 0;

    if(city_map)
    {

        for(auto v : g->getVertexSet())
        {
            if(v->getX() > max_x)
                max_x = v->getX();
            if(v->getY() > max_y)
                max_y = v->getY();
            if(v->getX() < min_x)
                min_x = v->getX();
            if(v->getY() < min_y)
                min_y = v->getY();
        }
        for(auto v: g->getVertexSet())
        {
            gv->setVertexSize(v->getId(), 2);

            double x_aux = ((v->getX()) - min_x)*1.0 / (max_x-min_x)*0.8;
            double y_aux = 1.0 - ((v->getY() - min_y)*1.0 / (max_y - min_y)*0.8);
            if(in(path, v->getId()) && show_path)
                gv->setVertexColor(v->getId(), "yellow");
            gv->addNode(v->getId(), (int) (x_aux * width), (int) (y_aux*height));

        }
        for(auto v : g->getVertexSet())
        {
            for(auto e : v->getAdj())
            {
                if(in(path, v->getId()) && in(path, e.getDest()->getId()) && show_path)
                    gv->setVertexColor(v->getId(), "yellow");
                gv->addEdge(id, v->getId(), e.getDest()->getId(), EdgeType::UNDIRECTED);
                id++;
            }
        }
    }
    else
    {
        for(auto v : g->getVertexSet())
        {
            gv->setVertexSize(v->getId(), 10);
            gv->setVertexLabel(v->getId(), to_string(v->getId()));
            if(in(path, v->getId()) && show_path)
                gv->setVertexColor(v->getId(), "yellow");
            gv->addNode(v->getId(), v->getX(), v->getY());
        }
        for(auto v : g->getVertexSet())
        {
            for(auto e : v->getAdj())
            {
                if(in(path, v->getId()) && in(path, e.getDest()->getId()) && show_path)
                    gv->setVertexColor(v->getId(), "yellow");
                gv->addEdge(id, v->getId(), e.getDest()->getId(), EdgeType::DIRECTED);
                id++;
            }
        }
    }



    gv->rearrange();
    string input;
    getline(cin, input);
    gv->closeWindow();

}

