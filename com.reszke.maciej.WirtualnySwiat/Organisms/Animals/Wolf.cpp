//
// Created by macie on 3/27/2018.
//

#include "Wolf.h"

#define WOLF_SIGN 'W'

Wolf::Wolf(World *world, Position *position) : Animal(world, position) {
    this->name = "WILK";
    this->sign = WOLF_SIGN;
    this->initiative = 5;
    this->strength = 9;
}

Organism *Wolf::getNewInstance(Position *position) {
    return new Wolf(this->world, position);
}

