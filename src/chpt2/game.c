#include "game.h"

#include <stdio.h>
#include <SDL_image.h>

SDL_Window *m_pWindow = NULL;
SDL_Renderer *m_pRenderer = NULL;

LinkedList textures;
bool m_bRunning = false;

int m_currentFrame;

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

                llistInit(&textures);
                SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

                // Create a texture from a surface
                textureLoad("../res/animate-alpha.png", "animate", m_pRenderer);
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

    // Render texture
    textureDraw("animate", 0, 0, 128, 82, m_pRenderer, SDL_FLIP_NONE);
    textureDrawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer, SDL_FLIP_NONE);

    // draw to the screen
    SDL_RenderPresent(m_pRenderer);
}

void gameUpdate() {
    m_currentFrame = (int) ((SDL_GetTicks() / 100) % 6);
}

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

    llistDestroy(&textures);

    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}