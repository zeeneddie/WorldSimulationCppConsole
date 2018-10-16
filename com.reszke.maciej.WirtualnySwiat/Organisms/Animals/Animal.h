//
// Created by macie on 3/27/2018.
//

#pragma once

#include "../Organism.h"

class Animal : public Organism {
protected:
    virtual void attackerCollision(Organism *organism);

public:

    void defenderCollision(Organism *organism) override;

    Animal(World *world, Position *position);

    void action() override;
};


