//
// Created by macie on 3/31/2018.
//

#pragma once

class Organism;

class Animal;

#include "../Organism.h"
#include "Animal.h"

class Human : public Animal {
private:
    int specialSkillRoundCounter;
    Position *nextPosition;

    Organism *getNewInstance(Position *position) override;

    bool generatePosition();

    friend class FileWorker;

    void attackerCollision (Organism *organism) override;

public:
    Human(World *world, Position *position);

    ~Human();

    void getDirectionFromUser();

    void activateSpecialAbility();

    void action() override;

};


