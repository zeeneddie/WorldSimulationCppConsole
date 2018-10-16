//
// Created by macie on 3/28/2018.
//

#include "Fox.h"
#include <iostream>

#define FOX_SIGN 'L'

Fox::Fox(World *world, Position *position) : Animal(world, position) {
    this->name = "LIS";
    this->sign = FOX_SIGN;
    this->initiative = 7;
    this->strength = 3;
}


Organism *Fox::getNewInstance(Position *position) {
    return new Fox(world, position);
}


void Fox::action() {
    Position *newPosition = world->generateRandomPositionInRange(this->position);
    if (world->getBoard()->isPositionFree(newPosition)) {
        world->moveOrganism(this, newPosition);
    } else if (world->getOrganismOnPosition(newPosition)->getStrength() <= getStrength()) {
        attackerCollision(world->getOrganismOnPosition(newPosition));
    }
}
