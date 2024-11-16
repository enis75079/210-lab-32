/*

lab32: toll booth
COMSC-210
Naveen Islam

 */

#include <iostream>
#include "Car.h"
#include <deque>
#include <ctime>
using namespace std;

// probability for whether the car will pay the toll and leave, join, or shift in the queue
const double LEAVE = 0.46;
const double JOIN = 0.39;
const double SHIFT = 0.15;


// main function
int main() {
    srand(time(0));

    // initial size of the deque when the simulation starts
    const int INIT_SIZE = 4;

    // creates a deque of Car objects
    deque<Car> tollLane[INIT_SIZE];

    // pushes the Car objects into the created deque
    for (int i = 0; i < INIT_SIZE; i++) {
        int numCar = rand() % 3 + 1;
        for (int j = 0; j < numCar; j++) {
           tollLane[i].push_back(Car()); 
        }
    }

    // intital queue before the while loop begins
    cout << "Initial Queue:" << endl;
    for (int i = 0; i < INIT_SIZE; i++) {
        cout << "Lane " << i + 1 << ":" << endl;
        for (auto car : tollLane[i]) {
            car.print();
        }
    }
    cout << endl;
    

    // loop until the time value equals 20 ie. runs the simulation for 20 time periods
    for (int i = 0; i < 20; i++) {
        cout << "\nTime: " << i + 1 << endl;
        
        for (int j = 0; j < INIT_SIZE; j++) {
            if (!tollLane[j].empty()) {
                //creates a random number that determines whether the car objects will leave or join
                double randNum = (double)rand() / RAND_MAX;

                // 46% probability: Car leaves
                if (randNum <= LEAVE) {
                    cout << "Lane " << i + 1 << ": Paid: ";
                    tollLane[j].front().print();
                    tollLane[j].pop_front();
                // 39% probability: Car joins    
                } else if (randNum <= LEAVE + JOIN) {
                    cout << "Lane " << j + 1 << ": Joined: ";
                    Car newCar;
                    tollLane[j].push_back(newCar);
                    newCar.print();       
                // 15% probability: Car switch                                                                                                                                                                                                                                                                                                                                           
                } else if (randNum <= LEAVE + JOIN + SHIFT) {
                    if (!tollLane[j].empty()) {                    
                        int randLane;
                        do {
                            randLane = rand() % INIT_SIZE;
                        } while (randLane == j);

                        Car switchCar = tollLane[j].back();
                        tollLane[j].pop_back();
                        tollLane[randLane].push_back(switchCar);                                              
                        cout << "Lane " << i + 1 << ": Switched: ";
                        switchCar.print();
                    }
                }
            }
        }

        // print lane queue after all operations finished
        for (int x = 0; x < INIT_SIZE; x++) {
            cout << "Lane " << x + 1 << " queue: " << endl;
            for (auto car : tollLane[x]) {
                car.print();
            }
        }
        cout << endl;
    }
}
