//
// Created by macie on 3/26/2018.
//

#pragma once


#include "Plant.h"

class Grass : public Plant {
protected:
    Organism *getNewInstance(Position *position) override;

public:
    Grass(World *world, Position *position);
};
