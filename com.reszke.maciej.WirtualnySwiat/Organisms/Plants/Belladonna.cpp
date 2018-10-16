//
// Created by macie on 3/27/2018.
//

#include "Belladonna.h"
#include "../Animals/Animal.h"

#define BELLADONNA_SIGN 'J'

Belladonna::Belladonna(World *world, Position *position) : Plant(world, position) {
    this->strength = 99;
    this->sign = BELLADONNA_SIGN;
    this->name = "WILCZE JAGODY";
}

Organism *Belladonna::getNewInstance(Position *position) {
    return new Belladonna(world, position);
}

void Belladonna::defenderCollision(Organism* organism) {
    Plant::defenderCollision(organism);
    commentary->addNewComment(organism->getName() + " zdechl przez zjedzenie Wilczych Jagod");
    world->deleteOrganism(organism->getPosition());
}
