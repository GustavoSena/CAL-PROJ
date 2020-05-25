//
// Created by gmend on 25/05/2020.
//






#include <chrono>
#include "resultGenerator.h"



void testAlgoritmsPerformance(Base base){
    srand(time(NULL));
    ofstream graphFile;
    graphFile.open("..\\resources\\graphPerfomance.csv");
    graphFile << "size; time" << endl;
    vector<int> network;
    Vehicle car(0, 4, 0);
    Driver d(0, "Vrum Vrum", network, "rua", &car);
    Passenger p1(0, "Rita", network, "rua");
    Passenger p2(0, "Hora", network, "rua");
    Passenger p3(0, "Melia", network, "rua");
    Passenger p4(0, "Nadia", network, "rua");
    base.addDriver(&d);
    base.addPassenger(&p1);
    base.addPassenger(&p2);
    base.addPassenger(&p3);
    base.addPassenger(&p4);

    Time t3(16, 0, 0);
    Time t4(18,0,0);
    PassengerRequest r3(t3,  t4,25, 7, &p3);
    for(int i=0; i<5;i++)
        base.addPassengerRequest(&r3);
    for (int size = 1; size <= 100; size += 1){
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 1000*size; k++){
            Time t1(16, 0, 0);
            Time t2(18,0,0);
            DriverRequest request(t1, t2,25,4, &d);
            PassengerRequest r1(t1, t2,25,5,&p1);
            PassengerRequest r2(t1,  t2,25, 6, &p2);
            PassengerRequest r4(t1,  t2, 16, 5, &p4);
            base.addDriverRequest(new DriverRequest(request));
            base.addPassengerRequest(new PassengerRequest(r1));
            base.addPassengerRequest(new PassengerRequest(r2));
            base.addPassengerRequest(new PassengerRequest(r4));
            base.createJourney(new DriverRequest(request));
            base.setJourneys({});
        }
        auto finish = std::chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(finish - start).count();
        graphFile << size*1000 << ";" << elapsed << endl;
        cout << size*1000 << ";" << elapsed << endl;

    }
    graphFile.close();
}

