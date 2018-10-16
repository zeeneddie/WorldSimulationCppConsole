//
// Created by macie on 3/27/2018.
//

#include "SosnowskysHogweed.h"
#include "../Animals/Animal.h"

#define SOSNOWSKYSHOGWEED_SIGN 'B'

SosnowskysHogweed::SosnowskysHogweed(World *world, Position *position) : Plant(world, position) {
    this->sign = SOSNOWSKYSHOGWEED_SIGN;
    this->strength = 10;
    this->name = "BARSZCZ SOSNOWSKIEGO";
}


Organism *SosnowskysHogweed::getNewInstance(Position *position) {
    return new SosnowskysHogweed(world, position);
}


void SosnowskysHogweed::action() {
    int row = position->getRow();
    int column = position->getColumn();

    auto *positionToCheck = new Position(row + 1, column);
    killIfExistOnPos(world, positionToCheck);
    positionToCheck->setPosition(row - 1, column);
    killIfExistOnPos(world, positionToCheck);
    positionToCheck->setPosition(row, column - 1);
    killIfExistOnPos(world, positionToCheck);
    positionToCheck->setPosition(row, column + 1);
    killIfExistOnPos(world, positionToCheck);

    Plant::action();

}

void SosnowskysHogweed::defenderCollision(Organism *organism) {
    Plant::defenderCollision(organism);
    commentary->addNewComment(organism->getName() + " zdechl przez zjedzenie Barszczu Sosnowskiego");
    world->deleteOrganism(organism->getPosition());
}

void SosnowskysHogweed::killIfExistOnPos(World *world, Position *positionToCheck) {
    if (world->getBoard()->isPositionInRange(positionToCheck) &&
        !world->getBoard()->isPositionFree(positionToCheck) &&
        (dynamic_cast< Animal * >( world->getOrganismOnPosition(positionToCheck)))) {
        commentary->addNewComment(world->getOrganismOnPosition(positionToCheck)->getName() +
                                  " znajdowal sie za blisko Barszczu Sosnowskiego i zginal");
        world->deleteOrganism(world->getOrganismOnPosition(positionToCheck)->getPosition());
    }
}