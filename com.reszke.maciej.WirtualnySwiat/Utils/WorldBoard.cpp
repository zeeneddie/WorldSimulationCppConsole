//
// Created by macie on 3/27/2018.
//

#include "WorldBoard.h"
#include "Position.h"
#include "../Organisms/Organism.h"
#include <iostream>

using namespace std;


void WorldBoard::allocBoard() {
    this->board = new char *[rows];
    for (int i = 0; i < rows; i++) {
        this->board[i] = new char[columns];
    }
    resetWorld();
}


void WorldBoard::resetWorld() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            board[i][j] = this->freePlaceChar;
        }
    }
}


void WorldBoard::drawBoard() const {
    cout << " ";
    for (int i = 0; i < this->columns; i++) {
        cout << "_";
    }
    cout << endl;

    for (int i = 0; i < this->rows; i++) {
        cout << "|";
        for (int j = 0; j < this->columns; j++) {
            cout << board[i][j];
        }
        cout << "|" << endl;
    }

    cout << " ";
    for (int i = 0; i < this->columns; i++) {
        cout << "-";
    }
    cout << endl;
}


WorldBoard::WorldBoard(int rows, int columns) : rows(rows), columns(columns) {
    allocBoard();
}


void WorldBoard::deleteBoard() {
    for (int i = 0; i < rows; i++) {
        delete[] board[i];
        board[i] = nullptr;
    }
    delete[] board;
    board = nullptr;
}


WorldBoard::~WorldBoard() {
    deleteBoard();
}


int WorldBoard::getRows() const {
    return rows;
}


int WorldBoard::getColumns() const {
    return columns;
}


void WorldBoard::deleteFromBoard(Position *position) {
    board[position->getRow()][position->getColumn()] = freePlaceChar;
}


bool WorldBoard::isPositionFree(Position *position) const {
    return isPositionInRange(position) &&
           board[position->getRow()][position->getColumn()] == freePlaceChar;
}


bool WorldBoard::isPositionInRange(Position *position) const {
    return position->getRow() < rows &&
           position->getRow() > -1 &&
           position->getColumn() > -1 &&
           position->getColumn() < columns;
}

void WorldBoard::putOnBoard(Organism *organism) {
    board[organism->getPosition()->getRow()][organism->getPosition()->getColumn()] = organism->getSign();
}

bool WorldBoard::isAnyPositionAroundFree(const Position *position) const {
    Position* positionAround = new Position(position->getRow() + 1, position->getColumn());
    if(isPositionFree(positionAround)){
        delete positionAround;
        return true;
    }
    positionAround->setPosition(position->getRow()-1, position->getColumn());
    if (isPositionFree(positionAround)){
        delete positionAround;
        return true;
    }
    positionAround->setPosition(position->getRow(), position->getColumn() + 1);
    if(isPositionFree(positionAround)){
        delete positionAround;
        return true;
    }
    positionAround->setPosition(position->getRow(), position->getColumn()-1);
    if(isPositionFree(positionAround)){
        delete positionAround;
        return true;
    }
    delete positionAround;
    return false;
}

void WorldBoard::changePositionInBoard(Organism *organism, Position *newPostion) {
    board[organism->getPosition()->getRow()][organism->getPosition()->getColumn()] = freePlaceChar;
    board[newPostion->getRow()][newPostion->getColumn()] = organism->getSign();
}
