//
// Created by user on 13/05/2020.
//

#include "menus.h"

int main_menu(Base *base)
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
            if(next_menu(base, "passenger"))
                continue;
            return 0;
        }
        else if(compare_str(answer,"d"))
        {

            if(next_menu(base, "driver"))
                continue;
            return 0;
        }
        else if(compare_str(answer,"c"))
        {
            return 0;
        }
        else
        {
            cout << "Invalid answer. Try again!\n";
        }

    }while(true);


}

int next_menu(Base *base, string type)
{
    string answer;
    do{

        cout << "Sign [I]n"<< endl;
        cout << "Sign [U]p" << endl;
        cout << "\n\nGo [B]ack" << endl;
        cout << "[C]lose" << endl;
        getline(cin,answer);
        if(compare_str(answer,"i"))
        {
            if(base->sign_in(type))
                continue;
            return 0;
        }
        else if(compare_str(answer,"u"))
        {
            base->sign_up(type);
            cout<<"\nSuccessful sign up! You can now sign in:\n";
        }
        else if(compare_str(answer,"b"))
        {
            return-1;
        }
        else if(compare_str(answer,"c"))
        {
            return 0;
        }
        else
        {
            cout << "\nInvalid answer. Try again!\n";
        }

    }while(true);
}



int request_menu(Base *base, int id, string type){
    do {

        cout << "\n\n\nMake request? (y/n): ";
        string input;
        getline(cin, input);

        if (compare_str(input, "n"))
             return 1;
        if (compare_str(input, "y"))
            break;
        cout<<"\nInvalid input!\n";
    }while(true);

    Request aux;
    
    string temp;
    while(true) {
        Time *t = readTime("Minimum starting");
        if (t == nullptr)
            return 1;
        aux.setMinStartTime(*t);
        t = readTime("Maximum ending");
        if (t == nullptr)
            return 1;
        aux.setMaxEndTime(*t);

        if(aux.getMinStartTime()<aux.getMaxEndTime())
            break;
        cout<<"\nInvalid times please try again\n";
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
            cout<<"\nInvalid input please try again\n";
            continue;
        }
        cout << "\nStarting point (id) (-1 to cancel): ";
        getline(cin, temp);
        if(compare_str(temp,"-1"))
            return 1;
        try {
            point1 = stoi(temp);

        }catch(exception err){
            cout<<"\nError with input please try again\n";
            continue;
        }
        cout<<"\nEnding point (id) (-1 to cancel): ";
        getline(cin,temp);
        if(compare_str(temp,"-1"))
            return 1;
        try {
            point2 = stoi(temp);

        }catch(exception err){
            cout<<"\nError with input please try again\n";
            continue;
        }
        if(!base->getGraph().areVertexConnected(point1,point2)){
            cout<<"\nCannot connect locations! Please input new ones or cancel!\n";
            continue;
        }
        break;
    }
    aux.setStartingId(point1);
    aux.setDestinationId(point2);
    if(compare_str(type, "Driver"))
        base->addDriverRequest(new DriverRequest(aux,base->findDriver(id)));
     else
        base->addPassengerRequest(new PassengerRequest(aux,base->findPassenger(id)));
    cout <<"\n\n\nRequest successfully made!\n";
    return 1;
}

int chooseCity(Base *base, int id,string type){
    do {
        cout<<"Which city are you in?\n";
        cout<<"1-Porto\n";
        cout<<"2-Fafe\n";
        cout<<"3-Maia\n";
        cout<<"4-8x8 grid\n";
        cout<<"5-\n\nGo Back\n";
        cout<<"6-Exit Program\n";
        cout<<"Input: ";
        string temp;
        getline(cin, temp);


        if (compare_str(temp, "6"))
            return 0;

        else if (compare_str(temp, "5"))
            return 1;

        else if (compare_str(temp, "1")) {
            base->setRequestFile("portoRequests.txt");
            base->loadRequests("portoRequests.txt");
            base->loadGraph("..\\resources\\maps\\Porto\\nodes_x_y_porto.txt", "..\\resources\\maps\\Porto\\edges_porto.txt");
            base->setMap("Porto");
            if(chooseAlgorithm(base,id,type))
                continue;
            return 0;
        }
        else if (compare_str(temp, "2")) {
            base->setRequestFile("fafeRequests.txt");
            base->loadRequests("fafeRequests.txt");
            base->loadGraph("..\\resources\\maps\\Fafe\\nodes_x_y_fafe.txt", "..\\resources\\maps\\Fafe\\edges_fafe.txt");
            base->setMap("Fafe");
            if(chooseAlgorithm(base,id,type))
                continue;
            return 0;
        }else if (compare_str(temp, "3")) {
            base->setRequestFile("maiaRequests.txt");
            base->loadRequests("maiaRequests.txt");
            base->loadGraph("..\\resources\\maps\\Maia\\nodes_x_y_maia.txt", "..\\resources\\maps\\Maia\\edges_maia.txt");
            base->setMap("Maia");
            if(chooseAlgorithm(base,id,type))
                continue;
            return 0;
        }else if (compare_str(temp, "4")) {
            base->setRequestFile("8x8Requests.txt");
            base->loadRequests("8x8Requests.txt");
            base->loadGraph("..\\resources\\maps\\8x8\\nodes.txt", "..\\resources\\maps\\8x8\\edges.txt");
            base->setMap("8x8");
            if(chooseAlgorithm(base,id,type))
                continue;
            return 0;
        }
        else
            cout<<"Invalid input! Plz try again\n";

    }while(true);




}



int chooseAlgorithm(Base * base,int id, string type){
    do {
        cout<<"\nChoose algorithm?\n";
        cout<<"1-Astar\n";
        cout<<"2-Dijkstra\n";
        if(compare_str(base->getMap(),"8x8"))
            cout<<"3-FloydWarshall\n";
        cout<<"\n\n4-Go Back\n";
        cout<<"5-Exit Program\n";
        cout<<"Input: ";
        string temp;
        getline(cin, temp);


        if (compare_str(temp, "5"))
            return 0;

        else if (compare_str(temp, "4"))
            return 1;

        else if ((compare_str(base->getMap(),"8x8")) && compare_str(temp, "3")) {
            base->setAlgorithm("floydwarshall");
            if(floydwarshallMenu(base,id, type))
                continue;
            return 0;
        }
        else if (compare_str(temp, "1")) {
            base->setAlgorithm("astar");
            if(optionMenu(base,id, type))
                continue;
            return 0;
        }else if (compare_str(temp, "2")) {
            base->setAlgorithm("dijkstra");
            if(optionMenu(base,id, type))
                continue;
            return 0;
        }
        else
            cout<<"Invalid input! Plz try again\n";

    }while(true);

}


int optionMenu(Base *base,int id, string type){
    do {
        cout<<"\nWhat do you want to do?\n";
        cout<<"1-Add Request\n";
        cout<<"2-Run algorithm\n";
        cout<<"3-See Map\n";
        cout<<"4-See previous Journeys\n";
        cout<<"\n\n5-Go Back\n";
        cout<<"6-Exit Program\n";
        cout<<"Input: ";
        string temp;
        getline(cin, temp);
        if (compare_str(temp, "6"))
            return 0;

        else if (compare_str(temp, "5"))
            return 1;

        else if (compare_str(temp, "1"))
            if(request_menu(base,id, type))
                continue;

        else if (compare_str(temp, "2"))
            base->run_algorithm();

        else if (compare_str(temp, "3"))
            mapViewer(&base->getGraph(),!compare_str(base->getMap(),"8x8"),vector<int>{},false);

        else if (compare_str(temp, "4"))
            viewJourneys(base);

        else
            cout<<"\nInvalid input! Plz try again\n";

    }while(true);
}





void viewJourneys(Base *base){

    vector<Journey*> j= base->getJourneys();
    cout<<endl;
    for (int i=0; i<j.size();i++){
        if(compare_str(j[i]->getCity(),base->getMap()))
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
        cout<<"\nSee path in map? (y to confirm, anything else to cancel): ";
        getline(cin, temp);
        if(compare_str(temp,"y"))
            mapViewer(&base->getGraph(),!compare_str(base->getMap(),"8x8"),j[x-1]->getPath(),true);

        return;
    }catch(exception err){
        cout<<"\nError with input: 1 to try again, anything else to cancel: ";
        getline(cin,temp);
        if(compare_str(temp,("1")))
            viewJourneys(base);

        return;

    }


}




int floydwarshallMenu(Base*base,int id, string type){

    while(true) {
        cout << "\n1-Use pre-processed values\n";
        cout << "2-Run FloydWarshall\n";
        cout << "\n\n3-Go Back\n";
        cout << "4-Exit program\n";

        cout << "Input: ";
        string temp;
        getline(cin, temp);

        if (compare_str(temp, "1")){
            base->getGraph().readFiles("..\\resources\\FloydWarshall\\GridGraphPathFW.txt", "..\\resources\\FloydWarshall\\GridGraphDistanceFW.txt");
            if(optionMenu(base, id, type))
                continue;
            return 0;
        }
        else if(compare_str(temp, "2")){
            base->getGraph().floydWarshallShortestPath();
            base->getGraph().writeFiles("..\\resources\\FloydWarshall\\GridGraphPathFW.txt", "..\\resources\\FloydWarshall\\GridGraphDistanceFW.txt");
            if(optionMenu(base, id, type))
                continue;
            return 0;
        }
        else if(compare_str(temp, "3"))
            return 1;

        else if(compare_str(temp, "4" ))
            return 0;

        else
            cout << "\nInvalid input try again\n";

    }


}






Time* readTime(string timeType){
    do {
        string temp;
        Time t;
        cout <<endl<< timeType << " time (hh:mm:ss) (-1 to cancel): ";
        getline(cin,temp);
        if(compare_str(temp,"-1"))
            return nullptr;
        vector<string> parts = decompose(temp,':');
        if(parts.size()!=3){
            cout<<"\nError with input! Please try again\n";
            continue;
        }
        try{
            t.setHour(stoi(parts[0]));
            t.setMinute(stoi(parts[1]));
            t.setSecond(stoi(parts[2]));
        }catch(exception err){
            cout<<"\nError with input! Please try again\n";
            continue;
        }
        return new Time(t);

    }while(true);

}


