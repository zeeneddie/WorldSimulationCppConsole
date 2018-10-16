//
// Created by macie on 3/26/2018.
//


#include "World.h"
#include "Organisms/Plants/Grass.h"
#include "Organisms/Animals/Turtle.h"
#include "Organisms/Animals/Wolf.h"
#include "Organisms/Animals/Sheep.h"
#include "Organisms/Animals/Human.h"
#include "Organisms/Animals/Fox.h"
#include "Organisms/Animals/Antelope.h"
#include "Organisms/Plants/Guarana.h"
#include "Organisms/Plants/Belladonna.h"
#include "Organisms/Plants/SosnowskysHogweed.h"
#include "Organisms/Plants/SowThistle.h"
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;


World::World() {
    srand((unsigned) time(nullptr));
    roundNumber = 0;
    commentary = new Commentary();
    createNewBoardFromUserInput();
    generateRandomWorld();
    sortOrganisms();
    system("clear");
    cout << "Poczatek rozgrywki"<<endl;
    board->drawBoard();

}


World::~World() {
    deleteOrganisms(organisms.size());
    delete commentary;
    delete board;
    cout << "KONIEC GRY";
}

void World::deleteOrganisms(size_t orgSize) {
    for (int i = 0; i < orgSize; i++) {
        delete organisms.at(0);
        organisms.erase(organisms.begin());
    }
}


Position *World::generateRandomPositionInRange(const Position *position) const {
    auto *newPosition = new Position(position->getRow() + 1, position->getColumn());
    int random;
    while (true) {
        random = rand() % 100;
        if (random < 25) {
        } else if (random < 50) {
            newPosition->setPosition(position->getRow() - 1, position->getColumn());
        } else if (random < 75) {
            newPosition->setPosition(position->getRow(), position->getColumn() + 1);
        } else {
            newPosition->setPosition(position->getRow(), position->getColumn() - 1);
        }
        if (board->isPositionInRange(newPosition)) {
            return newPosition;
        }
    }
}


void World::putOrganism(Organism *organism) {
    board->putOnBoard(organism);
    organisms.push_back(organism);
}


void World::deleteOrganism(Position *position) {
    this->board->deleteFromBoard(position);
    position->setPosition(-1, -1);
}


Commentary *World::getCommentary() const {
    return commentary;
}


void World::moveOrganism(Organism *organism, Position *newPosition) {
    board->changePositionInBoard(organism, newPosition);
    delete organism->getPosition();
    organism->setPosition(newPosition);
}


WorldBoard *World::getBoard() const {
    return board;
}


Organism *World::getOrganismOnPosition(Position *position) {
    return organisms.at(static_cast<unsigned int>(getOrganismsVectorNumber(position)));
}


bool World::performSimulation() {
    char userInput;
    cout << "Wcisnij 'q' aby wyjsc, 'n' aby przeprowadzic kolejna runde,\n"
            "'s' aby aktywowac specjalna umiejetnosc, 'z' zeby zapisac, 'w' zeby wczytac" << endl;
    cin >> userInput;
    switch (userInput) {
        case 'q':
            return false;
        case 's':
            if (human != nullptr) human->activateSpecialAbility();
            else cout << "Twoj czlowiek nie zyje" << endl;
            break;
        case 'n':
            nextRound();
            break;
        case 'z':
            FileWorker::saveWorldToFile(this);
            break;
        case 'w':
            FileWorker::readWorldFromFile(this);
            sortOrganisms();
            break;
        default:;
    }
    return true;

}

/******** FOR CLASS USAGE ONLY *******/
/******** FOR CLASS USAGE ONLY *******/
/******** FOR CLASS USAGE ONLY *******/
/******** FOR CLASS USAGE ONLY *******/


void World::createNewBoardFromUserInput() {
    int rows, columns;
    do {
        cout << "Podaj rozmiar planszy AxB. Minimalne pole to 11. \nDlugosc: ";
        rows = getIntegerFromUser();
        cout << "Szerokosc: ";
        columns = getIntegerFromUser();
    } while (rows * columns < 11);
    board = new WorldBoard(rows, columns);
}

int World::getIntegerFromUser() const {
    int integer;
    cin >> integer;
    while (cin.fail()) {
        cout << "Wprowadzona wartosc jest niepoprawna. Sprobuj ponownie: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> integer;
    }
    return integer;
}


Position *World::generateRandomPositionAnywhere() const {
    auto *position = new Position(0, 0);
    int row, column;
    do {
        row = (11 * rand()) % board->getRows();
        column = (31 * rand()) % board->getColumns();
        position->setPosition(row, column);
    } while (!board->isPositionFree(position));

    return position;
}


int World::getOrganismsVectorNumber(Position *position) {
    for (auto i = 0; i < organisms.size(); i++) {
        if (organisms[i]->getPosition()->getColumn() == position->getColumn() &&
            organisms[i]->getPosition()->getRow() == position->getRow()) {
            return i;
        }
    }
}


void World::generateRandomWorld() {
    int loopMaxCounter = this->getBoard()->getColumns() * this->getBoard()->getRows() / 10 / 5;  //board fill ~ 20%
    loopMaxCounter = loopMaxCounter < 1 ? 1 : loopMaxCounter;
    this->human = new Human(this, generateRandomPositionAnywhere());
    putOrganism(this->human);
    for (int i = 0; i < loopMaxCounter; i++) {
        putOrganism(new Antelope(this, generateRandomPositionAnywhere()));
        putOrganism(new Fox(this, generateRandomPositionAnywhere()));
        putOrganism(new Sheep(this, generateRandomPositionAnywhere()));
        putOrganism(new Turtle(this, generateRandomPositionAnywhere()));
        putOrganism(new Wolf(this, generateRandomPositionAnywhere()));
        putOrganism(new Grass(this, generateRandomPositionAnywhere()));
        putOrganism(new Guarana(this, generateRandomPositionAnywhere()));
        putOrganism(new Belladonna(this, generateRandomPositionAnywhere()));
        putOrganism(new SosnowskysHogweed(this, generateRandomPositionAnywhere()));
        putOrganism(new SowThistle(this, generateRandomPositionAnywhere()));
    }
}


void World::cleanKilled() {
    size_t orgSize = organisms.size();
    Organism *org;
    for (int i = 0; i < orgSize;) {
        org = organisms.at(i);
        if (org->getPosition()->getColumn() == -1) {
            organisms.erase(organisms.begin() + i);
            if (dynamic_cast<Human *>(org)) {
                human = nullptr;
            }
            delete org;
            orgSize--;
        } else {
            i++;
        }
    }
}


void World::sortOrganisms() {
    stable_sort(organisms.begin(), organisms.end(), [](const Organism *l, const Organism *r) {
        return l->getInitiative() > r->getInitiative();
    });
}


void World::nextRound() {
    if (human != nullptr) {
        this->human->getDirectionFromUser();
    }
    system("clear");

    commentary->readNextRound(++roundNumber);
    const int organizmSize = organisms.size();

    for (int i = 0; i < organizmSize; i++) {
        if (organisms.at(i)->getPosition()->getColumn() != -1) {
            organisms.at(i)->action();
        }
    }
    sortOrganisms();
    cleanKilled();
    this->board->drawBoard();
    commentary->readAllComments();

}

