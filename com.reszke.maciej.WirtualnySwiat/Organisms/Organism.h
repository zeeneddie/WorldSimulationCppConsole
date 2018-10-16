//
// Created by macie on 3/26/2018.
//

#pragma once

class World;

#include "../Utils/Position.h"
#include "../World.h"
#include "../Utils/Commentary.h"


class Organism {
protected:
    int strength, initiative;
    char sign;
    std::string name;
    Position *position;
    World *world;
    Commentary *commentary;

    virtual Organism *getNewInstance(Position *position)=0;

public:
    Organism(Position *position, World *world);

    virtual void defenderCollision(Organism *organism)=0;

    void setStrength(int strength);

    const std::string &getName() const;

    int getStrength() const;

    virtual ~Organism();

    int getInitiative() const;

    char getSign() const;

    Position *getPosition();

    virtual void action()= 0;

    void setPosition(Position *position);
};
