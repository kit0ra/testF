#ifndef PROJET_PROGRAMMATION_S5_LEVEL_H
#define PROJET_PROGRAMMATION_S5_LEVEL_H


#include <string>
#include "Board.h"

class Level {
    public:
        explicit Level(std::string nameLevel);
        Board generateBoard();
    private:
        string path;
};


#endif //PROJET_PROGRAMMATION_S5_LEVEL_H
