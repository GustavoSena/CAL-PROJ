//
// Created by user on 13/05/2020.
//

#include "menus.h"

int main_menu(Base base)
{

    string answer;
    do{
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
            cout<<"Successful sign up! You can now sign in:\n";
        }
        else if(compare_str(answer,"b"))
        {
            return-1;
        }
        else if(compare_str(answer,"c"))
        {
            base.updateFiles();
            exit(0);
        }
        else
        {
            cout << "Invalid answer. Try again!\n";
        }

    }while(true);
}



void request_menu(Base *base, int id){
    do {

        cout << "\n\n\nMake request? (y/n)\n";
        string input;
        getline(cin, input);

        if (compare_str(input, "n"))
            return;
        if (compare_str(input, "y"))
            break;
        cout<<"Invalid input!\n";
    }while(true);

    Request aux;
    
    string temp;
    while(true) {
        Time *t = readTime("Minimum starting");
        if (t == nullptr)
            return;
        aux.setMinStartTime(*t);
        t = readTime("Maximum ending");
        if (t == nullptr)
            return;
        aux.setMaxEndTime(*t);

        if(aux.getMinStartTime()<aux.getMaxEndTime())
            break;
        cout<<"Invalid times please try again\n";
    }



    int point1;
    int point2;
    while(true) {
        cout<< "View map? (y/n): ";
        getline(cin, temp);
        cout<<endl;
        if (compare_str(temp, "y")){
            mapViewer(&base->getGraph(),!compare_str(base->getMap(),"8x8"),vector<int>{},false);
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



        if (compare_str(temp, "5")) {
            base->updateFiles();
            exit(0);
        }
        if (compare_str(temp, "1")) {
            base->setRequestFile("portoRequests.txt");
            base->loadRequests("portoRequests.txt");
            base->loadGraph("..\\resources\\maps\\Porto\\nodes_x_y_porto.txt", "..\\resources\\maps\\Porto\\edges_porto.txt");
            base->setMap("Porto");
            return;
        }
        else if (compare_str(temp, "2")) {
            base->setRequestFile("fafeRequests.txt");
            base->loadRequests("fafeRequests.txt");
            base->loadGraph("..\\resources\\maps\\Fafe\\nodes_x_y_fafe.txt", "..\\resources\\maps\\Fafe\\edges_fafe.txt");
            base->setMap("Fafe");
            return;
        }else if (compare_str(temp, "3")) {
            base->setRequestFile("maiaRequests.txt");
            base->loadRequests("maiaRequests.txt");
            base->loadGraph("..\\resources\\maps\\Maia\\nodes_x_y_maia.txt", "..\\resources\\maps\\Maia\\edges_maia.txt");
            base->setMap("Maia");
            return;
        }else if (compare_str(temp, "4")) {
            base->setRequestFile("8x8Requests.txt");
            base->loadRequests("8x8Requests.txt");
            base->loadGraph("..\\resources\\maps\\8x8\\nodes.txt", "..\\resources\\maps\\8x8\\edges.txt");
            base->setMap("8x8");
            return;
        }
        else{
            cout<<"Invalid input! Plz try again\n";
        }
    }while(true);


}



void chooseAlgorithm(Base * base,int id){
    do {
        cout<<"Choose algorithm?\n";
        cout<<"1-Astar\n";
        cout<<"2-Dijkstra\n";
        if(compare_str(base->getMap(),"8x8"))
            cout<<"3-FloydWarshall\n";
        cout<<"4-Exit program\n";
        string temp;
        getline(cin, temp);

        if (compare_str(temp, "4")) {
            base->updateFiles();
            exit(0);
        }
        if ((compare_str(base->getMap(),"8x8")) && compare_str(temp, "3")) {


            base->setAlgorithm("floydwarshall");
            floydwarshallMenu(base,id);
            return;
        }
        else if (compare_str(temp, "1")) {
            base->setAlgorithm("astar");
            optionMenu(base,id);
            return;
        }else if (compare_str(temp, "2")) {
            base->setAlgorithm("dijkstra");
            optionMenu(base,id);
            return;
        }
        else{
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
        cout<<"4-See previous Journeys\n";
        cout<<"5-Exit program\n";
        string temp;
        getline(cin, temp);

        if (compare_str(temp, "5")) {
            base->updateFiles();
            exit(0);
        }
        if (compare_str(temp, "1")) {
            request_menu(base,id);
        }
        else if (compare_str(temp, "2")) {
            base->run_algorithm();
        }else if (compare_str(temp, "3")) {
            mapViewer(&base->getGraph(),!compare_str(base->getMap(),"8x8"),vector<int>{},false);
        }
        else if (compare_str(temp, "4")) {
            viewJourneys(base);
        }
        else{
            cout<<"Invalid input! Plz try again\n";
        }
    }while(true);
}





void viewJourneys(Base *base){

    vector<Journey*> j= base->getJourneys();

    for (int i=0; i<j.size();i++){
        cout<<i+1<<" -"<<j[i]->showSimp()<<endl;
    }
    cout<<"See detailed? (input id to see detailed and 0 to go back): ";

    string temp;
    getline(cin, temp);

    int x;

    try{
        trim(temp);
        x=stoi(temp);
        if(x==0)
            return;
        cout<<j[x-1]->show()<<endl;
        cout<<"See path in map? (y to confirm, anything else to cancel): ";
        getline(cin, temp);
        if(compare_str(temp,"y"))
            mapViewer(&base->getGraph(),!compare_str(base->getMap(),"8x8"),j[x-1]->getPath(),true);

        return;
    }catch(exception err){
        cout<<"Error with input: 1 to try again, anything else to cancel: ";
        getline(cin,temp);
        if(compare_str(temp,("1")))
            viewJourneys(base);


        return;

    }


}




void floydwarshallMenu(Base*base,int id){

    while(true) {
        cout << "1-Use pre-processed values\n";
        cout << "2-Run FloydWarshall\n";
        cout << "3-Exit program\n";

        cout << "Input: ";
        string temp;
        getline(cin, temp);

        if (compare_str(temp, "1")){
            base->getGraph().readFiles("..\\resources\\FloydWarshall\\GridGraphPathFW.txt", "..\\resources\\FloydWarshall\\GridGraphDistanceFW.txt");
            optionMenu(base, id);
        }
        else if(compare_str(temp, "2")){
            base->getGraph().floydWarshallShortestPath();
            base->getGraph().writeFiles("..\\resources\\FloydWarshall\\GridGraphPathFW.txt", "..\\resources\\FloydWarshall\\GridGraphDistanceFW.txt");
            optionMenu(base, id);
        }
        else if(compare_str(temp, "3")){
            base->updateFiles();
            exit(0);
        }
        else {
            cout << "Invalid input try again\n";
            continue;
        }

    }


}






Time* readTime(string timeType){
    do {
        string temp;
        Time t;
        cout << timeType << " time (hh:mm:ss) (-1 to cancel): ";
        getline(cin,temp);
        if(compare_str(temp,"-1"))
            return nullptr;
        vector<string> parts = decompose(temp,':');
        if(parts.size()!=3){
            cout<<"Error with input! Please try again\n";
            continue;
        }
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


