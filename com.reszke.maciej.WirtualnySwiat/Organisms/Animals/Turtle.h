//
// Createpostawa obronnadd by macie on 3/28/2018.
//

#pragma once

#include "Animal.h"

class Turtle : public Animal {
public:
    Turtle(World *world, Position *position);

    void action() override;

protected:

    Organism *getNewInstance(Position *position) override;

    void defenderCollision(Organism *organism) override;

};


