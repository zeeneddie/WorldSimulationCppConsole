//
// Created by macie on 3/26/2018.
//

#pragma once

class Position {
    int row, column;
public:
    Position(int row, int column);

    int getRow() const;

    int getColumn() const;

    void setPosition(int row, int column);
};

