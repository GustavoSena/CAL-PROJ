//
// Created by user on 23/05/2020.
//

#ifndef MEETUPRIDER_GRAPHDRAWING_H
#define MEETUPRIDER_GRAPHDRAWING_H


#include "NewGraph.h"
#include "graphviewer.h"
#include "utils.h"



//desenha o grafo de acordo com os parametros
//  se for mapa de cidade ou não
//  se quer desenhar um caminho específico de maneira diferente ou não
void mapViewer(Graph *g, bool city_map, vector<int> path, bool show_path);



#endif //MEETUPRIDER_GRAPHDRAWING_H
