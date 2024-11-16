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
        cout << "Lane " << i << ": " ;
        for (auto car : tollLane[i]) {
            car.print();
        }
    }
    cout << endl;
     
    // time value
    int n = 0;

    // loop until the time value equals 20 ie. runs the simulation for 20 time periods
    /*while (n != 20) {
        cout << "Time: " << n << " ";
        //creates a random number that determines whether the car objects will leave or join
        double randNum = (double)rand() / RAND_MAX;
        
        // randNum between 0.0 to 1.0 that determines if the car leaves the toll
        if (randNum <= LEAVE) {
            cout << "Operation: Car paid: ";
            tollLane.front().print();
            tollLane.pop_front();
        // if the randNum is apart of the 45%, create a new Car object that joins the deque
        } else {
            cout << "Operation: Joined lane: ";
            Car nCar;
            tollLane.push_back(nCar);
            nCar.print();
        }
        // output the current queue
        cout << "Queue:" << endl;
        for (auto cars : tollLane) {
            cars.print();
        }
        cout << endl;
        // increment the time value
        n++;
    }
    cout << "Empty" << endl;*/

    return 0;
}
