//
// Created by macie on 3/26/2018.
//

#pragma once

class Organism;

#include "../Organism.h"
#include <string>

class Plant : public Organism {
protected:
    int spreadChances = 2;  //2% to spread

    std::string spreadComment();

    void spread();
public:

    void action() override;

    Plant(World *world, Position *position);

    void defenderCollision(Organism *organism) override;
};


