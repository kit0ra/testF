#ifndef PROJET_PROGRAMMATION_S5_GAME_H
#define PROJET_PROGRAMMATION_S5_GAME_H

#include <string>
#include "../Mobile/Mobile.h"
#include "Board.h"

class Game {
    public:
        Game() = default;
        ~Game() = default;
        void loadLevel(std::string nameLevel);
        void launch();
    private:
        Board board;
        std::vector<Mobile> mobiles;
};


#endif //PROJET_PROGRAMMATION_S5_GAME_H
