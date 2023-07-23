#define SDL_MAIN_HANDLED

#include <SDL.h>

#include "game.h"

const int FPS = 100;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char** argv) {
    Uint32 frameStart, frameTime;

    gameInit("Chapter 2 Setting up SDL", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        640, 480, SDL_WINDOW_SHOWN);

    while (m_bRunning) {
        frameStart = SDL_GetTicks();

        gameHandleEvents();
        gameUpdate();
        gameRender();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < DELAY_TIME) {
            SDL_Delay((int) (DELAY_TIME - frameTime));
        }
    }

    gameClean();

    return 0;
}