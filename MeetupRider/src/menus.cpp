//
// Created by user on 13/05/2020.
//

#include "menus.h"

void main_menu(Base base)
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
                next_menu(base, "passenger");
            }
            else if(answer == "D" || answer == "d")
            {
                retry = false;
                next_menu(base, "driver");
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

void next_menu(Base base, string type)
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
            base.sign_in(type);

        }
        else if(answer == "U" || answer == "u")
        {
            retry = false;
            base.sign_up(type);
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


