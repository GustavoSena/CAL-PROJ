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
            int id =base.sign_in(type);
            request_menu(base, id);

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


void request_menu(Base base, int id){
    system("cls");
    do {

        cout << "\n\n\nMake request? (y/n)\n";
        string input;
        getline(cin, input);

        if (compare_str(input, "n"))
            return;
        if (compare_str(input, "y"))
            break;
        system("cls");
        cout<<"Invalid input!\n";
    }while(true);

    Request aux;
    aux.setPassenger(base.findPassenger(id));
    string temp;
    cout<<"Time restriction? (y/n) (anything else to cancel)\n";
    getline(cin,temp);
    if (compare_str(temp, "n")){
        aux.setTimesNull();
    }
    else if (compare_str(temp, "y")){
        cout<< "Minimum starting time (hh::mm) (0 to cancel)\n";
        getline(cin,temp);
        if(compare_str(temp, "0"))
            return;
        aux.setMinStartTime(Time(temp));
        cout<< "Maximum starting time (hh::mm) (0 to cancel)\n";
        getline(cin,temp);
        if(compare_str(temp, "0"))
            return;
        aux.setMaxStartTime(Time(temp));
        cout<< "Minimum ending time (hh::mm) (0 to cancel)\n";
        getline(cin,temp);
        if(compare_str(temp, "0"))
            return;
        aux.setMinEndTime(Time(temp));
        cout<< "Maximum ending time (hh::mm) (0 to cancel)\n";
        getline(cin,temp);
        if(compare_str(temp, "0"))
            return;
        aux.setMaxEndTime(Time(temp));

    }
    else
        return;

    int point1;
    int point2;
    while(true) {

        cout << "Starting point (id) (-1 to cancel)\n";
        getline(cin, temp);
        if(compare_str(temp,"-1"))
            return;
        point1=stoi(temp);
        cout<<"Ending point (id) (-1 to cancel)\n";
        getline(cin,temp);
        if(compare_str(temp,"-1"))
            return;
        point2=stoi(temp);
        if(!base.getGraph().areVertexConnected(point1,point2)){
            cout<<"Cannot connect locations! Please input new ones or cancel!\n";
            continue;
        }
        break;
    }
    aux.setStartingId(point1);
    aux.setDestinationId(point2);

    base.addRequest(new Request(aux));


}




