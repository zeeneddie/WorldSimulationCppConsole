//
// Created by macie on 3/27/2018.
//

#include "Animal.h"
#include "../Plants/Plant.h"
#include <typeinfo>

Animal::Animal(World *world, Position *position):Organism(position, world) {

}


void Animal::action() {
    Position *newPosition = world->generateRandomPositionInRange(this->position);
    if (world->getBoard()->isPositionFree(newPosition)) {
        world->moveOrganism(this, newPosition);
    } else {
        attackerCollision(world->getOrganismOnPosition(newPosition));
    }
}


void Animal::attackerCollision(Organism *organism){
    if (dynamic_cast< Plant * >( organism)) {
        organism->defenderCollision(this);
    } else if (typeid(*this) == typeid(*organism)) {
        if (world->getBoard()->isAnyPositionAroundFree(this->position)) {
            Position *newPosition;
            do {
                newPosition = world->generateRandomPositionInRange(this->position);
            } while (!world->getBoard()->isPositionFree(newPosition));
            world->putOrganism(this->getNewInstance(newPosition));
            commentary->addNewComment("Zwierze " + this->name + " rozmnozylo sie");
        }
    } else {
        dynamic_cast<Animal *>(organism)->defenderCollision(this);
    }
}


void Animal::defenderCollision(Organism *organism){
    if (this->strength > organism->getStrength()) {
        commentary->addNewComment(this->getName() + " zabil " + organism->getName());
        world->deleteOrganism(organism->getPosition());
    } else {
        commentary->addNewComment(organism->getName() + " zabil " + this->getName());
        auto *newPosition = new Position(position->getRow(), position->getColumn());
        world->deleteOrganism(this->position);
        world->moveOrganism(organism, newPosition);
    }
}
