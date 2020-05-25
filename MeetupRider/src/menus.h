//
// Created by user on 13/05/2020.
//

#ifndef MEETUPRIDER_MENUS_H
#define MEETUPRIDER_MENUS_H

#include <string>
#include <iostream>
#include "Base.h"
#include "graphDrawing.h"

using namespace std;


int main_menu(Base base);

int next_menu(Base base, string type);

void request_menu(Base *base,int id);


void chooseCity(Base *base);

//menu de escolha de algoritmo a ser utilizado
void chooseAlgorithm(Base * base,int id);

//menu que da a opçao de adicionar pedidos, ver o mapa, correr o algoritmo (processando os pedidios ja existentes) e ver as viagens já realizadas
void optionMenu(Base *base,int id);

//funcao de apoio ao input de tempos
Time *readTime(string timeType);

//menu de visualização das viagens ja realizadas
void viewJourneys(Base *base);

//menu onde se da a escolha de fazer o processamento de dados no momento ou usar os preprocessados
void floydwarshallMenu(Base*base,int id);

#endif //MEETUPRIDER_MENUS_H
