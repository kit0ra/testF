#include "Headers/Creation/Game.h"

using namespace std;

int main() {
    Game game;
    game.loadLevel("../levels/level1.lvl");
    game.launch();
    return 5;
}
