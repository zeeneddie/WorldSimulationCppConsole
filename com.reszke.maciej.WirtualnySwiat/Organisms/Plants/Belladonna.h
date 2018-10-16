//
// Created by macie on 3/27/2018.
//


#include "Plant.h"

class Belladonna : public Plant {
protected:
    Organism *getNewInstance(Position *position) override;

    void defenderCollision(Organism *organism) override;

public:
    Belladonna(World *world, Position *position);
};

