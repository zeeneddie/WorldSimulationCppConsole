//
// Created by macie on 3/28/2018.
//

#pragma once

#include "Animal.h"

class Sheep : public Animal {
public:
    Sheep(World *world, Position *position);

    Organism *getNewInstance(Position *position) override;
};
