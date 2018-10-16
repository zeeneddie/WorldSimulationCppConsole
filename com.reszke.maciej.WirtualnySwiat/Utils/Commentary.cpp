//
// Created by macie on 3/27/2018.
//

#include <iostream>
#include "Commentary.h"

Commentary::Commentary() {
    std::cout << "Witaj w nowym swiecie!" << std::endl;
    std::cout << "Autor: Maciej Reszke 172012" << std::endl;
}

void Commentary::addNewComment(std::string comment) {
    comments.push(comment);
}

void Commentary::readAllComments() {
    while (!comments.empty()) {
        std::cout << comments.front() << std::endl;
        comments.pop();
    }
}

void Commentary::readNextRound(int round) {
    std::cout << "Runda numer " << round << std::endl;
}
