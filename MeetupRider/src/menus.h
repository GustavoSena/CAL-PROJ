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


//menu em que se escolhe se se é um passageiro ou um condutor
int main_menu(Base base);

//menu em que se escolhe se se faz sign up ou sign in
int next_menu(Base base, string type);

//menu em que o utilizador faz um pedido de boleia ou oferece boleia
void request_menu(Base *base,int id);

//menu de escolha de mapa
void chooseCity(Base *base);

//menu de escolha de algoritmo a ser utilizado
void chooseAlgorithm(Base * base,int id);

<<<<<<< HEAD
//menu que da a opçao de adicionar pedidos, ver o mapa, correr o algoritmo (processando os pedidios ja existentes) e ver as viagens já realizadas
void optionMenu(Base *base,int id);

//funcao de apoio ao input de tempos
Time *readTime(string timeType);

//menu de visualização das viagens ja realizadas
void viewJourneys(Base *base);

//menu onde se da a escolha de fazer o processamento de dados no momento ou usar os preprocessados
//menu que da a opção de adicionar pedidos, ver o mapa, correr o algoritmo (processando os pedidos já existentes) e ver as viagens já realizadas
void optionMenu(Base *base,int id);

//função de apoio ao input de tempos
Time *readTime(string timeType);

//menu de visualização das viagens já realizadas
void viewJourneys(Base *base);

//menu onde se dá a escolha de fazer o processamento de dados no momento ou usar os preprocessados
void floydwarshallMenu(Base*base,int id);

#endif //MEETUPRIDER_MENUS_H
