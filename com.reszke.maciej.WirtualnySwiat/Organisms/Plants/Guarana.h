//
// Created by macie on 3/27/2018.
//

#pragma once

#include "Plant.h"

class Guarana: public Plant {
public:
    Guarana(World *world, Position *position);

protected:
    void defenderCollision(Organism* organism) override;

    Organism *getNewInstance(Position *position) override;

};


