//
// Created by macie on 4/1/2018.
//

#include <fstream>
#include <iostream>
#include "FileWorker.h"
#include "../Organisms/Animals/Sheep.h"
#include "../Organisms/Animals/Antelope.h"
#include "../Organisms/Animals/Fox.h"
#include "../Organisms/Animals/Human.h"
#include "../Organisms/Animals/Turtle.h"
#include "../Organisms/Animals/Wolf.h"
#include "../Organisms/Plants/Belladonna.h"
#include "../Organisms/Plants/Grass.h"
#include "../Organisms/Plants/Guarana.h"
#include "../Organisms/Plants/SosnowskysHogweed.h"
#include "../Organisms/Plants/SowThistle.h"


using namespace std;

void FileWorker::saveWorldToFile(World *world) {
    cout << "Podaj nazwe pliku bez rozszerzenia: ";
    string fileName;
    cin >> fileName;
    ofstream saveFile(fileName + ".bin", ios::binary);
    if (saveFile.is_open()) {
        saveFile << world->board->rows << endl;
        saveFile << world->board->columns << endl;
        saveFile << world->roundNumber << endl;
        if (world->human != nullptr) {
            saveFile << world->human->specialSkillRoundCounter << endl;
        } else {
            saveFile << "-" << endl;
        }

        for (Organism *org: world->organisms) {
            saveFile << org->getPosition()->getRow() << endl;
            saveFile << org->getPosition()->getColumn() << endl;
            saveFile << org->getSign() << endl;
            saveFile << org->getStrength() << endl;
        }
        saveFile.close();
        cout << "Swiat zapisany do pliku " + fileName + ".bin poprawnie" << endl;
    } else {
        cout << "Problem z otworzeniem pliku" << endl;
    }
}


void FileWorker::readWorldFromFile(World *world) {
    cout << "Podaj nazwe pliku bez rozszerzenia: ";
    string fileName;
    cin >> fileName;
    ifstream readFile(fileName + ".bin", ios::binary);
    if (readFile.is_open()) {
        world->organisms.clear();
        world->board->deleteBoard();
        world->deleteOrganisms(world->organisms.size());
        world->human = nullptr;

        string specialSkillRoundCounter;
        readFile >> world->board->rows;
        readFile >> world->board->columns;
        readFile >> world->roundNumber;
        readFile >> specialSkillRoundCounter;

        world->board->allocBoard();

        int positionRow = 1;
        int positionColumn = 1;
        int strength = 0;
        char sign = '0';
        while (readFile >> positionRow) {
            readFile >> positionColumn;
            readFile >> sign;
            readFile >> strength;
            pushNextOrganism(positionRow, positionColumn, sign, world, strength);
        }
        if (world->human != nullptr) {
            world->human->specialSkillRoundCounter = stoi(specialSkillRoundCounter);
        }
        readFile.close();
        cout << "Swiat zostal pomyslnie wczytany" << endl;
        world->board->drawBoard();
    } else {
        cout << "Problem z otworzeniem pliku" << endl;
    }
}


void FileWorker::pushNextOrganism(int row, int column, char sign, World *world, int strength) {
    switch (sign) {
        case 'A':
            world->putOrganism(new Antelope(world, new Position(row, column)));
            break;
        case 'L':
            world->putOrganism(new Fox(world, new Position(row, column)));
            break;
        case 'C': {
            auto *human = new Human(world, new Position(row, column));
            world->putOrganism(human);
            world->human = human;
            break;
        }
        case 'O':
            world->putOrganism(new Sheep(world, new Position(row, column)));
            break;
        case 'Z':
            world->putOrganism(new Turtle(world, new Position(row, column)));
            break;
        case 'W':
            world->putOrganism(new Wolf(world, new Position(row, column)));
            break;
        case 'J':
            world->putOrganism(new Belladonna(world, new Position(row, column)));
            break;
        case 'T':
            world->putOrganism(new Grass(world, new Position(row, column)));
            break;
        case 'G':
            world->putOrganism(new Guarana(world, new Position(row, column)));
            break;
        case 'B':
            world->putOrganism(new SosnowskysHogweed(world, new Position(row, column)));
            break;
        case 'M':
            world->putOrganism(new SowThistle(world, new Position(row, column)));
            break;
        default:;
    }
    world->organisms.at(world->organisms.size() - 1)->setStrength(strength);
}
