//
// Created by macie on 3/28/2018.
//

#include "Sheep.h"

#define SHEEP_SIGN 'O'

Sheep::Sheep(World *world, Position *position) : Animal(world, position) {
    this->name = "OWCA";
    this->sign = SHEEP_SIGN;
    this->initiative = 4;
    this->strength = 4;
}

Organism *Sheep::getNewInstance(Position *position) {
    return new Sheep(this->world, position);
}


