//
// Created by user on 13/05/2020.
//

#ifndef MEETUPRIDER_MENUS_H
#define MEETUPRIDER_MENUS_H

#include <string>
#include <iostream>
#include "Base.h"

using namespace std;


void main_menu(Base base);

void next_menu(Base base, string type);

void request_menu(Base base,int id);


Time *readTime(string timeType);
#endif //MEETUPRIDER_MENUS_H
