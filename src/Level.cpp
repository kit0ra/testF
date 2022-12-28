#include "../../Headers/Creation/Level.h"
#include "../../Headers/Mobile/Player.h"
#include "../../Headers/Obstacle/Wall.h"
#include "../../Headers/Mobile/Lion.h"
#include "../../Headers/Mobile/Tiger.h"
#include "../../Headers/Creation/Board.h"
#include <fstream>
#include <utility>
#include <iostream>

Level::Level(std::string nameLevel) {
    path = std::move(nameLevel);
}

Board Level::generateBoard() {
    ifstream file(path);
    vector<string> data;

    string text;
    while (getline (file, text)) {
        data.push_back(text);
    }

    file.close();

    Board board;
    // Lecture des fichiers de levels
    for (const auto & i : data) {
        string j = i.substr(2, i.size());
        string left = j.substr(0, j.find('.'));
        string right = j.substr(j.find('.') + 1, j.size());
        switch (i[0]) {
            case 'I': {
                board = {stoi(left), stoi(right)};
                break;
            }
            case 'P': {
                Player player;
                player.setPosition(stoi(left), stoi(right));
                board.place(player);
                board.addMobile(player);
                break;
            }
            case 'L': {
                Lion lion;
                lion.setPosition(stoi(left), stoi(right));
                board.place(lion);
                board.addMobile(lion);
                break;
            }
            case 'T': {
                Tiger tiger;
                tiger.setPosition(stoi(left), stoi(right));
                board.place(tiger);
                board.addMobile(tiger);
                break;
            }
        }
    }

    // Création des murs autour de la map
    for (int i = 0; i < board.getWidth(); i++) {
        for (int j = 0; j < board.getLength(); j++) {
            if (i == 0 || j == 0 || i == board.getWidth() - 1 || j == board.getLength() - 1) {
                Wall wall;
                wall.setPosition(i, j);
                board.place(wall);
                board.walls.push_back(wall);
            }
        }
    }

    return board;
}
