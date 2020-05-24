//
// Created by user on 13/05/2020.
//

#ifndef MEETUPRIDER_MENUS_H
#define MEETUPRIDER_MENUS_H

#include <string>
#include <iostream>
#include "Base.h"

using namespace std;


int main_menu(Base base);

int next_menu(Base base, string type);

void request_menu(Base *base,int id);

void chooseCity(Base *base);

void chooseAlgorithm(Base * base,int id);
void optionMenu(Base *base,int id);
Time *readTime(string timeType);

void viewJourneys(Base *base);
#endif //MEETUPRIDER_MENUS_H
