//
// Created by user on 13/05/2020.
//

#include "menus.h"

int main_menu(Base base)
{

    string answer;
    do{
        system("cls");
        cout << "Welcome to Meetup Rider!" << endl;
        cout << "   -           __\n"
                " --          ~( @\\   \\\n"
                "---   _________]_[__/_>________\n"
                "     /  ____ \\ <>     |  ____  \\\n"
                "    =\\_/ __ \\_\\_______|_/ __ \\__D\n"
                "________(__)_____________(__)____" << endl;
        cout << "Are you a [P]assenger or a [D]river?" << endl;
        cout << "[C]lose"<< endl;
        getline(cin,answer);
        if(compare_str(answer,"p"))
        {
            int id =next_menu(base, "passenger");
            if(id>-1)
                return id;

        }
        else if(compare_str(answer,"d"))
        {

            int id=next_menu(base, "driver");
            if(id>-1)
                return id;
        }
        else if(compare_str(answer,"c"))
        {
            exit(0);
        }
        else
        {
            cout << "Invalid answer. Try again!\n";
        }

    }while(true);


}

int next_menu(Base base, string type)
{
    string answer;
    do{

        cout << "Sign [I]n"<< endl;
        cout << "Sign [U]p" << endl;
        cout << "Go [B]ack" << endl;
        cout << "[C]lose" << endl;
        getline(cin,answer);
        if(compare_str(answer,"i"))
        {
            return base.sign_in(type);
        }
        else if(compare_str(answer,"u"))
        {
            base.sign_up(type);
            system("cls");
            cout<<"Successful sign up! You can now sign in:\n";
        }
        else if(compare_str(answer,"b"))
        {
            return-1;
        }
        else if(compare_str(answer,"c"))
        {
            exit(0);
        }
        else
        {
            system("cls");
            cout << "Invalid answer. Try again!\n";
        }

    }while(true);
}



void request_menu(Base *base, int id){
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
    cout<<"Time restriction? (y/n) (anything else to cancel): ";
    getline(cin,temp);
    cout<<endl;
    if (compare_str(temp, "n")){
        aux.setTimesNull();
    }
    else if (compare_str(temp, "y")){
        Time *t=readTime("Minimum starting");
        if(t==NULL)
            return;
        aux.setMinStartTime(*t);
        t=readTime("Minimum ending");
        if(t==NULL)
            return;
        aux.setMinEndTime(*t);
        t=readTime("Maximum ending");
        if(t==NULL)
            return;
        aux.setMaxEndTime(*t);

    }
    else
        return;

    int point1;
    int point2;
    while(true) {
        cout<< "View map? (y/n): ";
        getline(cin, temp);
        cout<<endl;
        if (compare_str(temp, "y")){
            cout<<"Falta fazer call da map function\n";
            system("cls");
        }
        else if(compare_str(temp, "n")){
            //nothing
        }
        else{
            cout<<"Invalid input please try again\n";
            continue;
        }
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
        if(!base->getGraph().areVertexConnected(point1,point2)){
            cout<<"Cannot connect locations! Please input new ones or cancel!\n";
            continue;
        }
        break;
    }
    aux.setStartingId(point1);
    aux.setDestinationId(point2);

    DriverRequest *aux1= static_cast<DriverRequest *>(new Request(aux));
    PassengerRequest *aux2=static_cast<PassengerRequest*>(new Request(aux));
    Passenger *p=base->findPassenger(id);
    if(p== nullptr) {
        Driver *d = base->findDriver(id);
        aux1->setDriver(d);
    }
    else{
        aux2->setPassenger(p);
    }
    if(typeid(aux)==typeid(PassengerRequest))
        base->addPassengerRequest(aux2);
    else
        base->addDriverRequest(aux1);

}

void chooseCity(Base *base){
    do {
        cout<<"Which city are you in?\n";
        cout<<"1-Porto\n";
        cout<<"2-Fafe\n";
        cout<<"3-Maia\n";
        cout<<"4-8x8 grid\n";
        cout<<"5-Exit program\n";
        string temp;
        getline(cin, temp);



        if (compare_str(temp, "5"))
            exit(0);

        if (compare_str(temp, "1")) {
            base->loadGraph("..\\resources\\maps\\Porto\\nodes.txt", "..\\resources\\maps\\Porto\\edges.txt");
            return;
        }
        else if (compare_str(temp, "2")) {
            base->loadGraph("..\\resources\\maps\\Fafe\\nodes.txt", "..\\resources\\maps\\Fafe\\edges.txt");
            return;
        }else if (compare_str(temp, "3")) {
            base->loadGraph("..\\resources\\maps\\Maia\\nodes.txt", "..\\resources\\maps\\Maia\\edges.txt");
            return;
        }else if (compare_str(temp, "4")) {
            base->loadGraph("..\\resources\\maps\\8x8)\\nodes.txt", "..\\resources\\maps\\8x8\\edges.txt");
            return;
        }
        else{
            system("cls");
            cout<<"Invalid input! Plz try again\n";
        }
    }while(true);


}



void chooseAlgorithm(Base * base,int id){
    do {
        cout<<"Choose algorithm?\n";
        cout<<"1-FloydWarshall\n";
        cout<<"2-Astar\n";
        cout<<"3-Dijkstra\n";
        cout<<"4-Exit program\n";
        string temp;
        getline(cin, temp);

        if (compare_str(temp, "4"))
            exit(0);

        if (compare_str(temp, "1")) {
            base->setAlgorithm("floydwarshall");
            return;
        }
        else if (compare_str(temp, "2")) {
            base->setAlgorithm("astar");
            optionMenu(base,id);
            return;
        }else if (compare_str(temp, "3")) {
            base->setAlgorithm("dijkstra");
            return;
        }
        else{
            system("cls");
            cout<<"Invalid input! Plz try again\n";
        }
    }while(true);

}


void optionMenu(Base *base,int id){
    do {
        cout<<"What do you want to do?\n";
        cout<<"1-Add Request\n";
        cout<<"2-Run algorithm\n";
        cout<<"3-See Map\n";
        cout<<"4-See previour Journeys\n";
        cout<<"5-Exit program\n";
        string temp;
        getline(cin, temp);

        if (compare_str(temp, "5"))
            exit(0);

        if (compare_str(temp, "1")) {
            request_menu(base,id);
            return;
        }
        else if (compare_str(temp, "2")) {
            base->run_algorithm();
            return;
        }else if (compare_str(temp, "3")) {
            cout<<"Falta fazer call da map function\n";
            system("cls");
        }
        else if (compare_str(temp, "4")) {
            cout<<"Falta fazer a funcao para apresentar as journeys\n";
            system("cls");
        }
        else{
            system("cls");
            cout<<"Invalid input! Plz try again\n";
        }
    }while(true);
}







Time* readTime(string timeType){
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
        return new Time(t);

    }while(true);

}


