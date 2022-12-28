#include <iostream>
#include "../../Headers/Creation/Board.h"

using namespace std;

Board::Board(int width, int length) : d_width{width}, d_length{length} {
    // Initialize
    for (int i = 0; i < d_width; i++){
        std::vector<Empty> tab;
        d_board.push_back(tab);
    }

    // Fill with Empty Object
    for (int i = 0; i < d_width; i++){
        for (int j = 0; j < d_length; j++){
            Empty empty = {};
            d_board[i].push_back(empty);
            d_board[i][j].setPosition(i, j);
        }
    }
}

void Board::display() {
    cout << endl;
    for (int i = 0; i < d_width; i++) {
        for (int j = 0; j < d_length; j++) {
            cout << d_board[i][j].getSymbol();
            cout << "  ";
        }
        cout << endl;
    }
}

Board::Board() {
    d_width = 0;
    d_length = 0;
}

int Board::getWidth() const {
    return d_width;
}

void Board::setWidth(int dWidth) {
    d_width = dWidth;
}

int Board::getLength() const {
    return d_length;
}

void Board::setLength(int dLength) {
    d_length = dLength;
}

void Board::addMobile(const Mobile& mobile) {
    mobiles.push_back(mobile);
}

vector<std::vector<Empty>> Board::getBoard() const {
    return d_board;
}

void Board::place(Empty object) {
    d_board[object.getPosition()[0]][object.getPosition()[1]] = object;
}

void Board::place(Empty object, Empty empty) {
    d_board[object.getPosition()[0]][object.getPosition()[1]] = object;
    d_board[empty.getPosition()[0]][empty.getPosition()[1]] = empty;
}

Mobile Board::getPlayer() {
    return mobiles[0];
}

void Board::displayTuto() {
    string s;
    s += " _________________ \n";
    s += "|  7     8     9  |\n";
    s += "|     ↖  ↑  ↗     |\n";
    s += "|  4  ←  O  →  6  |\n";
    s += "|     ↙  ↓  ↘     |\n";
    s += "|  1     2     3  |\n";
    s += "|_________________|\n";
    cout << s;
}

//Player* Creation::getPlayer() {
//    return d_player;
//}
