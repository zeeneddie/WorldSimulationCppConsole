//
// Created by macie on 3/26/2018.
//

#include "Grass.h"

#define GRASS_SIGN 'T'

Grass::Grass(World *world, Position *position) : Plant(world, position) {
    this->sign = GRASS_SIGN;
    this->name = "TRAWA";
}

Organism *Grass::getNewInstance(Position *position) {
    return new Grass(this->world, position);
}

