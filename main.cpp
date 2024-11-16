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
     
    // time value
    int n = 0;

    // loop until the time value equals 20 ie. runs the simulation for 20 time periods
    while (n != 20) {
        cout << "\nTime: " << n + 1 << endl;
        
        for (int i = 0; i < INIT_SIZE; i++) {
            if (!tollLane[i].empty()) {
                //creates a random number that determines whether the car objects will leave or join
                double randNum = (double)rand() / RAND_MAX;

                // 46% probability: Car leaves
                if (randNum <= LEAVE) {
                    cout << "Lane " << i + 1 << ": Paid: ";
                    tollLane[i].front().print();
                    tollLane[i].pop_front();
                // 39% probability: Car joins    
                } else if (randNum <= LEAVE + JOIN) {
                    cout << "Lane " << i + 1 << ": Joined: ";
                    Car newCar;
                    tollLane[i].push_back(newCar);
                    newCar.print();
                } else if (randNum <= LEAVE + JOIN + SHIFT) {
                    int randLane;
                    do {
                        randLane = rand() % INIT_SIZE + 1;
                    } while (randLane == i) {
                        Car switchCar = tollLane[i].back();
                        tollLane[i].pop_back();
                        tollLane[randLane].push_back(switchCar);

                        cout << "Lane " << i + 1 << ": Switched: ";
                        switchCar.print();
                    }
                }
            }
        }
        for (int i = 0; i < INIT_SIZE; i++) {
        cout << "Lane " << i + 1 << ":" << endl;
        for (auto car : tollLane[i]) {
            car.print();
        }
    }
        n++;
    }

    return 0;
}
