/*********************************
    chess v1.0 2022
    leonardomotta@ucl.br

**********************************/

#include <iostream>
#include <string>
#include "game/game_service.h"
#include "game/game_window.h"

const int delay_time_ms = 10;
const std::string texture_file_name = "textures";

void RunGame() {
    GameService chessGame;
    GameWindow window;
    window.loadAllTexturesFromFile(texture_file_name);
    window.renderBackground();
    window.renderPieces(&chessGame);
    chessGame.calculateCurrentGameStatus();
    while (window.running()) {
        window.handleEvents();
        window.updateWindow(&chessGame);
        window.delay(delay_time_ms);
    }
    std::cin.get();
}

int main(int argv, char** args) {
    RunGame();
    return 0;
}