//
// Created by macie on 4/1/2018.
//

#pragma once

#include "../World.h"

class FileWorker {
public:

    static void saveWorldToFile(World *world);

    static void readWorldFromFile(World *world);
private:
    static void pushNextOrganism(int row, int column, char sign, World *world, int strength);
};

