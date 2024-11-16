/*

lab32: toll booth
COMSC-210
Naveen Islam

 */

#include <iostream>
#include "Car.h"
#include <deque>
using namespace std;

const double LEAVE = 0.55;
const double JOIN = 0.45;

int main() {
    const int INIT_SIZE = 2;
    deque<Car> tollLane;

    for (int i = 0; i < INIT_SIZE; i++) {
        tollLane.push_back(Car());
    }

    for (auto cars : tollLane) {
        cars.print();
    }

    return 0;
}
