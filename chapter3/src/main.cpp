#include <iostream>

#include "game.h"

Game *g_game;

int main(int argc, char **argv) {
    std::cout << "Game init attempt" << std::endl;
    if (TheGame::Instance()->init("Chapter 3", 100, 100, 640, 480, 0)) {
        std::cout << "Game init successful" << std::endl;
        while (TheGame::Instance()->running()) {
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

        }
    }
    else {
        std::cout << "Game init failure - " << SDL_GetError() << std::endl;
        return -1;
    }

    std::cout << "Game closing" << std::endl;
    TheGame::Instance()->clean();

    return 0;
}