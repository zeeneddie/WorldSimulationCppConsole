//
// Created by macie on 3/28/2018.
//

#pragma once

#include "Animal.h"

class Antelope : public Animal {
    void defenderCollision(Organism *organism) override;

    Organism *getNewInstance(Position *position) override;
public:
    Antelope(World *world, Position *position);

    void action() override;

};


