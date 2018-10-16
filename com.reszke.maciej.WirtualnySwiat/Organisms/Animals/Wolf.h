//
// Created by macie on 3/27/2018.
//
#pragma once

#include "Animal.h"

class Wolf : public Animal {

public:
    Wolf(World *world, Position *position);

protected:
    Organism *getNewInstance(Position *position) override;
};


