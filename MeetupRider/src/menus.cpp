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
        getline(cin,answer);
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




    string temp;
    cout<<"Time restriction? (y/n) (anything else to cancel)\n";
    getline(cin,temp);
    if (compare_str(temp, "n")){
        aux.setTimesNull();
    }
    else if (compare_str(temp, "y")){
        Time t=readTime("Minimum starting");
        if(t==NULL)
            return;
        aux.setMinStartTime(t);
        t=readTime("Minimum ending");
        if(t==NULL)
            return;
        aux.setMinEndTime(t);
        t=readTime("Maximum ending");
        if(t==NULL)
            return;
        aux.setMaxEndTime(t);

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
        try {
            point1 = stoi(temp);

        }catch(exception err){
            cout<<"Error with input please try again\n";
            continue;
        }
        cout<<"Ending point (id) (-1 to cancel)\n";
        getline(cin,temp);
        if(compare_str(temp,"-1"))
            return;
        try {
            point2 = stoi(temp);

        }catch(exception err){
            cout<<"Error with input please try again\n";
            continue;
        }
        if(!base.getGraph().areVertexConnected(point1,point2)){
            cout<<"Cannot connect locations! Please input new ones or cancel!\n";
            continue;
        }
        break;
    }
    aux.setStartingId(point1);
    aux.setDestinationId(point2);

    DriverRequest *aux1= static_cast<DriverRequest *>(new Request(aux));
    PassengerRequest *aux2=static_cast<PassengerRequest*>(new Request(aux));
    Passenger *p=base.findPassenger(id);
    if(p== nullptr) {
        Driver *d = base.findDriver(id);
        aux1->setDriver(d);
    }
    else{
        aux2->setPassenger(p);
    }
    if(typeid(aux)==typeid(PassengerRequest))
        base.addPassengerRequest(aux2);
    else
        base.addDriverRequest(aux1);

}


Time readTime(string timeType){
    do {
        string temp;
        Time t;
        cout << timeType << " time (hh:mm:ss) (0 to cancel)\n";
        getline(cin,temp);
        if(compare_str(temp,"0"))
            return NULL;
        vector<string> parts = decompose(temp,':');
        try{
            t.setHour(stoi(parts[0]));
            t.setMinute(stoi(parts[1]));
            t.setSecond(stoi(parts[2]));
        }catch(exception err){
            cout<<"Error with input! Please try again\n";
            continue;
        }
        return t;

    }while(true);

}


