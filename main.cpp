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

// probability that a car pays the toll and leaves
const double LEAVE = 0.55;

// main function
int main() {
    srand(time(0));

    // initial size of the deque when the simulation starts
    const int INIT_SIZE = 2;

    // creates a deque of Car objects
    deque<Car> tollLane;

    // pushes the Car objects into the created deque
    for (int i = 0; i < INIT_SIZE; i++) {
        tollLane.push_back(Car());
    }

    // intital queue before the while loop begins
    cout << "Initial Queue:" << endl;
    for (auto cars : tollLane) {
        cars.print();
    }
    cout << endl;
     
    // time value
    int n = 0;

    // while toll isn't empty
    while (!tollLane.empty()) {
        cout << "Time: " << n << " ";
        //creates a random number that determines whether the car objects will leave or join
        double randNum = (double)rand() / RAND_MAX;
        
        // randNum between 0.0 to 1.0 that determines if the car leaves the toll
        if (randNum <= LEAVE) {
            cout << "Operation: Car paid: ";
            tollLane.front().print();
            tollLane.pop_front();
        // if the randNum is apart of the 45%
        } else {
            cout << "Operation: Joined lane: ";
            Car nCar;
            tollLane.push_back(nCar);
            nCar.print();
        }
        cout << "Queue:" << endl;
        for (auto cars : tollLane) {
            cars.print();
        }
        cout << endl;
        n++;
    }
    cout << "Empty" << endl;

    return 0;
}
