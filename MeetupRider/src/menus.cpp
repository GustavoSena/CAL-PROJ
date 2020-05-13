//
// Created by user on 13/05/2020.
//

#include "menus.h"

void main_menu()
{
    while(true)
    {
        bool retry = true;
        string answer;
        do{
            system("cls");
            cout << "Welcome to Meetup Rider!" << endl;
            cout << "Are you a [P]assenger or a [D]river?" << endl;
            cout << "[C]lose"<< endl;
            cin >> answer;
            if(answer == "P" || answer == "p")
            {
                retry = false;
                passenger_menu();
            }
            else if(answer == "D" || answer == "d")
            {
                retry = false;
                driver_menu();
            }
            else if(answer == "C" || answer == "c")
            {
                exit(0);
            }
            else
            {
                cout << "Invalid answer. Try again!\n";
            }

        }while(retry);
    }

}

void passenger_menu()
{
    bool retry = true;
    string answer;
    do{
        system("cls");
        cout << "Sign [I]n"<< endl;
        cout << "Sign [U]p" << endl;
        cout << "Go [B]ack" << endl;
        cout << "[C]lose" << endl;
        cin >> answer;
        if(answer == "I" || answer == "i")
        {
            retry = false;
            //ir para uma função que crie um novo passageiro
        }
        else if(answer == "U" || answer == "u")
        {
            retry = false;
            //ir para uma função que mostre os passageiros disponiveis para dar login
        }
        else if(answer == "B" || answer == "b")
        {
            return;
        }
        else if(answer == "C" || answer == "c")
        {
            exit(0);
        }
        else
        {
            cout << "Invalid answer. Try again!\n";
        }

    }while(retry);
}


void driver_menu()
{
    bool retry = true;
    string answer;
    do{
        system("cls");
        cout << "Sign [I]n"<< endl;
        cout << "Sign [U]p" << endl;
        cout << "Go [B]ack" << endl;
        cout << "[C]lose" << endl;
        cin >> answer;
        if(answer == "I" || answer == "i")
        {
            retry = false;
            //ir para uma função que crie um novo condutor
        }
        else if(answer == "U" || answer == "u")
        {
            retry = false;
            //ir para uma função que mostre os condutores disponiveis para dar login
        }
        else if(answer == "B" || answer == "b")
        {
            return;
        }
        else if(answer == "C" || answer == "c")
        {
            exit(0);
        }
        else
        {
            cout << "Invalid answer. Try again!\n";
        }

    }while(retry);
}