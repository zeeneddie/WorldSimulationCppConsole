//
// Created by macie on 3/27/2018.
//

#include "Guarana.h"

#define GUARANA_SIGN 'G'

Guarana::Guarana(World *world, Position *position) : Plant(world, position) {
    this->sign = GUARANA_SIGN;
    this->name = "GUARANA";
}

void Guarana::defenderCollision(Organism *organism){
    Plant::defenderCollision(organism);
    commentary->addNewComment(organism->getName() + " zyskalo +3 sily przez zjedzenie Guarany");
    organism->setStrength(organism->getStrength() + 3);
}

Organism *Guarana::getNewInstance(Position *position) {
    return new Guarana(world, position);
}
