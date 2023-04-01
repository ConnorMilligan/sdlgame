#define SDL_MAIN_HANDLED
#include <SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char** argv) {
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        // If SDL_Init is successful, create a window
        g_pWindow = SDL_CreateWindow("Chapter 1: Setting up SDL", 
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
            640, 480, 
            SDL_WINDOW_SHOWN);
        
        // if the window creation is successful, create a renderer
        if(g_pWindow != 0)
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }
    else
        return 1; // SDL_Init failed

    // Set the draw color to black // This function expects RGBA values
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

    // Clear the window to black
    SDL_RenderClear(g_pRenderer);

    // Show the window
    SDL_RenderPresent(g_pRenderer);

    // Wait 5 seconds
    SDL_Delay(5000);

    // Clean up
    SDL_Quit();

    return 0;
}