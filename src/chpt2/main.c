#define SDL_MAIN_HANDLED

#include <SDL.h>

#include "game.h"

int main(int argc, char** argv) {
    gameInit("Chapter 2 Setting up SDL", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        640, 480, SDL_WINDOW_SHOWN);

    while (m_bRunning) {
        gameHandleEvents();
        gameUpdate();
        gameRender();
    }

    gameClean();

    return 0;
}