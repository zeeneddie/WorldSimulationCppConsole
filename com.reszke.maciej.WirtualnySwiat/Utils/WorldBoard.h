//
// Created by macie on 3/27/2018.
//

#pragma once

#include "Position.h"
#include "../Organisms/Organism.h"
#include "FileWorker.h"

class WorldBoard {
private:
    char **board;
    int rows, columns;
    const char freePlaceChar = ' ';

    friend class FileWorker;
    void allocBoard();

    void resetWorld();

    void deleteBoard();

public:
    WorldBoard(int rows, int columns);

    int getRows() const;

    int getColumns() const;

    ~WorldBoard();

    void drawBoard() const;

    void deleteFromBoard(Position *position);

    void putOnBoard(Organism *organism);

    bool isAnyPositionAroundFree(const Position *position) const;

    bool isPositionInRange(Position *position) const;

    bool isPositionFree(Position *position) const;

    void changePositionInBoard(Organism *organism, Position *newPostion);
};
