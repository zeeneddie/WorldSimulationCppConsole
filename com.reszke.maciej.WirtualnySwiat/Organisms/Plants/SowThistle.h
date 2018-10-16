//
// Created by macie on 3/27/2018.
//

#pragma once

#include "../../World.h"
#include "Plant.h"

class SowThistle : public Plant {
protected:
    Organism *getNewInstance(Position *position) override;

public:
    SowThistle(World *world, Position *position);

    void action() override;
};

