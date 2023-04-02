#define SDL_MAIN_HANDLED

#include <SDL.h>

#include "window.h"

bool g_bRunning = false;

int main(int argc, char** argv) {
    if (init("Chapter 1 Setting up SDL", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        640, 480, SDL_WINDOW_SHOWN)) {

        g_bRunning = true;
    } 
    else {
        return 1; // sdl could not initialize
    }

    while (g_bRunning) {
        render();
    }

    // clean up SDL
    SDL_Quit();

    return 0;
}