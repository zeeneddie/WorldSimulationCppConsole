//
// Created by macie on 3/28/2018.
//

#include <ctime>
#include "Turtle.h"

#define TURTLE_SIGN 'Z'

Turtle::Turtle(World *world, Position *position) : Animal(world, position) {
    this->name = "ZOLW";
    this->sign = TURTLE_SIGN;
    this->initiative = 1;
    this->strength = 2;
}

void Turtle::action() {
    if (rand() % 100 < 25) {
        Animal::action();
    }
}

Organism *Turtle::getNewInstance(Position *position) {
    return new Turtle(world, position);
}

void Turtle::defenderCollision(Organism *organism){
    if (organism->getStrength() >= 5) {
        Animal::defenderCollision(organism);
    }
}
