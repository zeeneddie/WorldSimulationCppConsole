#pragma once

//
// Created by macie on 3/26/2018.
//

class Organism;
class WorldBoard;
class Human;

#include <vector>
#include "Utils/Position.h"
#include "Organisms/Organism.h"
#include "Utils/Commentary.h"
#include "Utils/WorldBoard.h"


class World {
private:
    int roundNumber;
    std::vector<Organism *> organisms;
    Commentary *commentary;
    WorldBoard *board;
    Human* human;

    friend class FileWorker;

    void createNewBoardFromUserInput();

    void generateRandomWorld();

    int getIntegerFromUser() const;

    int getOrganismsVectorNumber(Position *position);

    Position *generateRandomPositionAnywhere() const;

    void cleanKilled();

    void nextRound();

    void sortOrganisms();

    void deleteOrganisms(size_t orgSize);


public:

    World();

    ~World();

    WorldBoard *getBoard() const;

    Commentary *getCommentary() const;

    Position *generateRandomPositionInRange(const Position *position) const;

    void putOrganism(Organism *organism);

    void deleteOrganism(Position *position);

    Organism *getOrganismOnPosition(Position *position);

    void moveOrganism(Organism *organism, Position *newPosition);

    bool performSimulation();
};
