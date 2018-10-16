//
// Created by macie on 3/28/2018.
//

#include "Antelope.h"

#define ANTELOPE_SIGN 'A'

Antelope::Antelope(World *world, Position *position) : Animal(world, position) {
    this->name = "ANTYLOPA";
    this->sign = ANTELOPE_SIGN;
    this->initiative = 4;
    this->strength = 4;
}


Organism *Antelope::getNewInstance(Position *position) {
    return new Antelope(world, position);
}

void Antelope::action() {
    Position *newPosition;
    do {
        newPosition = world->generateRandomPositionInRange(this->getPosition());
        int rowDifference = (newPosition->getRow() - this->getPosition()->getRow()) * 2;
        int columnDifference = (newPosition->getColumn() - this->getPosition()->getColumn()) * 2;
        newPosition->setPosition(this->position->getRow() + rowDifference,
                                 this->position->getColumn() + columnDifference);
    } while (!world->getBoard()->isPositionInRange(newPosition));

    if (world->getBoard()->isPositionFree(newPosition)) {
        world->moveOrganism(this, newPosition);
    } else {
        attackerCollision(world->getOrganismOnPosition(newPosition));
    }
}

void Antelope::defenderCollision(Organism *organism) {
    if (rand() % 2 && world->getBoard()->isAnyPositionAroundFree(this->position)) {
        commentary->addNewComment("Antylopa czmychnela z pola walki!");
        auto *antelopePosition = new Position(this->getPosition()->getRow(), this->getPosition()->getColumn());
        Position *newAntelopePosition;
        do {
            newAntelopePosition = world->generateRandomPositionInRange(this->position);
        } while (!world->getBoard()->isPositionFree(newAntelopePosition));

        world->moveOrganism(this, newAntelopePosition);
        world->moveOrganism(organism, antelopePosition);
    } else {
        Animal::defenderCollision(organism);
    }
}
