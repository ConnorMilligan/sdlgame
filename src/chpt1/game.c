#include "game.h"

#include <stdio.h>
#include <SDL.h>

SDL_Window *m_pWindow = NULL;
SDL_Renderer *m_pRenderer = NULL;

bool m_bRunning = false;

bool gameInit(const char* title, int xpos, int ypos, int width, int height, int flags) {
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        printf("SDL_Init success\n");

        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, 
            width, height, flags);

        // if window creation successful create our renderer
        if (m_pWindow != 0) {
            printf("Window creation success\n");
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            // if renderer creation successful set draw color to white
            if (m_pRenderer != 0) {
                printf("Renderer creation success\n");
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            } else {
                printf("Renderer init fail\n");
                return false;
            }
        }
        else {
            printf("Window init fail\n");
            return false;
        }
    }
    else {
        printf("SDL_Init fail\n");
        return false;
    }

    printf("Init success\n");
    m_bRunning = true;

    return true;
}

void gameRender() {
    // clear renderer to the draw color
    SDL_RenderClear(m_pRenderer);
    // draw to the screen
    SDL_RenderPresent(m_pRenderer);
}

void gameUpdate() {}

void gameHandleEvents() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
                break;
        }
    }
}

void gameClean() {
    printf("Cleaning game\n");
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}