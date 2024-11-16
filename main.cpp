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

const double LEAVE = 0.55;
const double JOIN = 0.45;

int main() {
    srand(time(0));

    const int INIT_SIZE = 2;
    deque<Car> tollLane;

    for (int i = 0; i < INIT_SIZE; i++) {
        tollLane.push_back(Car());
    }

    cout << "Initial Queue:" << endl;
    for (auto cars : tollLane) {
        cars.print();
    }
    cout << endl;

    int n = 0;
    while (tollLane.empty() != true) {
        cout << "Time: " << n << endl;
        double randNum = (double)rand() / RAND_MAX;
        
        if (randNum <= LEAVE) {
            cout << "Operation: Car paid: ";
            tollLane.front().print();
            tollLane.pop_front();
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

        n++;
    }

    cout << "Empty" << endl;

    return 0;
}
