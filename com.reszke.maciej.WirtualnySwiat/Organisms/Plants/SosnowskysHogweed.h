//
// Created by macie on 3/27/2018.
//

#pragma once

#include "Plant.h"

class SosnowskysHogweed : public Plant {
protected:
    void defenderCollision(Organism *organism) override;

    Organism *getNewInstance(Position *position) override;

    void killIfExistOnPos(World *world, Position *positionToCheck);

public:

    SosnowskysHogweed(World *world, Position *position);

    void action() override;
};

