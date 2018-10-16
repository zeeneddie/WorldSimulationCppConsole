#include <iostream>
#include "World.h"

using namespace std;


int main() {
    system("clear");
    auto *world = new World();
    while (world->performSimulation()) {}
    delete world;
    return 0;
}