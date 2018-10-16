//
// Created by macie on 3/27/2018.
//

#include "SowThistle.h"

#define SOWTHISTLE_SIGN 'M'

SowThistle::SowThistle(World *world, Position *position) : Plant(world, position) {
    this->sign = SOWTHISTLE_SIGN;
    this->name = "MLECZ";
}

Organism *SowThistle::getNewInstance(Position *position) {
    return new SowThistle(world, position);
}

void SowThistle::action() {
    if (world->getBoard()->isAnyPositionAroundFree(this->getPosition())) {
        for (int i = 0; i < 3; i++) {
            if (rand() % 100 < this->spreadChances) {
                Plant::spread();
                return;
            }
        }
    }
}

