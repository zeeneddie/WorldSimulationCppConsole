//
// Created by macie on 3/26/2018.
//

#include "Position.h"

Position::Position(int row, int column) : row(row), column(column) {
}

void Position::setPosition(int row, int column) {
    this->row = row;
    this->column = column;
}

int Position::getRow() const {
    return row;
}

int Position::getColumn() const {
    return column;
}