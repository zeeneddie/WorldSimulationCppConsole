//
// Created by macie on 3/26/2018.
//


#include <ctime>
#include "Plant.h"
#include <iostream>

void Plant::action() {
    if (world->getBoard()->isAnyPositionAroundFree(this->getPosition()) &&
        rand() % 100 < this->spreadChances) {

        spread();

    }
}

void Plant::spread(){
    Position *newRandomPosition;
    do {
        newRandomPosition = world->generateRandomPositionInRange(this->position);
    } while (!world->getBoard()->isPositionFree(newRandomPosition));
    world->putOrganism(this->getNewInstance(newRandomPosition));
    commentary->addNewComment(this->spreadComment());
}

void Plant::defenderCollision(Organism *organism) {
    commentary->addNewComment(organism->getName() + " zjadl " + this->getName());
    auto *plantPosition = new Position(this->getPosition()->getRow(), this->getPosition()->getColumn());
    world->deleteOrganism(this->position);
    world->moveOrganism(organism, plantPosition);
}


Plant::Plant(World *world, Position *position) :Organism(position, world){
    this->strength = 0;
    this->initiative = 0;
}

std::string Plant::spreadComment() {
    return "Roslina " + this->getName() + " rozrasta sie";
}
