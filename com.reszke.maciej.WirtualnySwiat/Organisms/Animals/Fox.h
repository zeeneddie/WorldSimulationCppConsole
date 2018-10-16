//
// Created by macie on 3/28/2018.
//
#pragma once

#include "Animal.h"

class Fox : public Animal {
public:
    Fox(World *world, Position *position);

    void action() override;

private:
    Organism *getNewInstance(Position *position) override;

};


