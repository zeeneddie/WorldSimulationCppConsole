//
// Created by macie on 3/26/2018.
//

#include "Organism.h"
#include <iostream>

using namespace std;

Organism::Organism(Position *position, World *world) : position(position), world(world) {
    this->commentary = world->getCommentary();
}

Position *Organism::getPosition() {
    return position;
}

int Organism::getStrength() const {
    return strength;
}

int Organism::getInitiative() const {
    return initiative;
}

char Organism::getSign() const {
    return sign;
}

void Organism::setPosition(Position *position) {
    Organism::position = position;
}

const std::string &Organism::getName() const {
    return name;
}

void Organism::setStrength(int strength) {
    Organism::strength = strength;
}

Organism::~Organism() {
    delete position;
}
