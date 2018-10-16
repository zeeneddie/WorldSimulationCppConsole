//
// Created by macie on 3/31/2018.
//

#include "Human.h"
#include "../Plants/Plant.h"
#include <iostream>

using namespace std;

#define HUMAN_SIGN 'C'
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Human::Human(World *world, Position *position) : Animal(world, position) {
    this->sign = HUMAN_SIGN;
    this->name = "CZLOWIEK";
    this->initiative = 4;
    this->strength = 5;
    this->specialSkillRoundCounter = 0;
    this->nextPosition = new Position(0, 0);
}


Organism *Human::getNewInstance(Position *position) {
    return new Human(world, position);
}


void Human::getDirectionFromUser() {
    int direction;
    while (true) {
        getchar();
        cout << "Podaj kierunek ruchu(WASD lub strzalki): " << endl;
        direction = getchar();
        switch (direction) {
            case KEY_UP:
            case 'w':
                nextPosition = new Position(this->getPosition()->getRow() - 1, this->getPosition()->getColumn());
                break;
            case KEY_DOWN:
            case 's':
                nextPosition = new Position(this->getPosition()->getRow() + 1, this->getPosition()->getColumn());
                break;
            case KEY_LEFT:
            case 'a':
                nextPosition = new Position(this->getPosition()->getRow(), this->getPosition()->getColumn() - 1);
                break;
            case KEY_RIGHT:
            case 'd':
                nextPosition = new Position(this->getPosition()->getRow(), this->getPosition()->getColumn() + 1);
                break;
            default:
                direction = 0;
                cout << "Zly wybor" << endl;
        }

        if (direction != 0) {
            if (generatePosition()) {
                return;
            } else {
                cout << "Blad: nie mozesz wyjsc po za mape" << endl;
            }
        }
    }
}


void Human::activateSpecialAbility() {
    if (!specialSkillRoundCounter) {
        cout << "Szybkosc antylopy aktywowana" << endl;
        specialSkillRoundCounter = 10;
    } else if (specialSkillRoundCounter > 7) {
        cout << "Umiejetnosc jest w pelni sprawna" << endl;
    } else if (specialSkillRoundCounter > 5) {
        cout << "Umiejetnosc ma 50% szans na zadzialanie" << endl;
    } else {
        cout << "Nie mozesz jeszcze uzyc umiejetnosci" << endl;
    }
}


Human::~Human() {
    delete nextPosition;
}


void Human::action() {
    if (specialSkillRoundCounter > 0) {
        specialSkillRoundCounter--;
    }
    if (world->getBoard()->isPositionFree(nextPosition)) {
        world->moveOrganism(this, nextPosition);
    } else {
        attackerCollision(world->getOrganismOnPosition(nextPosition));
    }
}

void Human::attackerCollision(Organism *organism){
    if (dynamic_cast< Plant * >( organism)) {
        organism->defenderCollision(this); 
    } else {
        dynamic_cast<Animal *>(organism)->defenderCollision(this);
    }
}

bool Human::generatePosition() {
    if (specialSkillRoundCounter > 7 || specialSkillRoundCounter > 5 && rand() % 2) {
        int rowDifference = (nextPosition->getRow() - this->getPosition()->getRow()) * 2;
        int columnDifference = (nextPosition->getColumn() - this->getPosition()->getColumn()) * 2;
        nextPosition->setPosition(this->position->getRow() + rowDifference,
                                  this->position->getColumn() + columnDifference);
    }
    return world->getBoard()->isPositionInRange(nextPosition);
}



