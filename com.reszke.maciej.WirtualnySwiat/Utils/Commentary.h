//
// Created by macie on 3/27/2018.
//

#pragma once

#include <queue>
#include <string>

class Commentary {
private:
    std::queue<std::string> comments;

public:
    Commentary();
    void addNewComment(std::string comment);
    void readAllComments();
    void readNextRound(int round);
};


