#ifndef PROJET_PROGRAMMATION_S5_BOARD_H
#define PROJET_PROGRAMMATION_S5_BOARD_H

#include <vector>
#include "../Empty.h"
#include "../Mobile/Mobile.h"
#include "../Mobile/Player.h"
#include "../Obstacle/Wall.h"

class Board {
    public:
        Board();
        Board(int width, int length);
        void display();
        void displayTuto();
        void addMobile(const Mobile& mobile);

        int getWidth() const;
        void setWidth(int dWidth);
        int getLength() const;
        void setLength(int dLength);
        void place(Empty object);
        void place(Empty object, Empty empty);
        vector<std::vector<Empty>> getBoard() const;
        Mobile getPlayer();

        std::vector<Mobile> mobiles;
        std::vector<Wall> walls;
    private:
        int d_width;
        int d_length;
        std::vector<std::vector<Empty>> d_board;
};

#endif //PROJET_PROGRAMMATION_S5_BOARD_H
