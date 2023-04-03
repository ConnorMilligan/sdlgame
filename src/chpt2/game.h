#ifndef GAME_H
#define GAME_H

#include "list.h"

#include <stdbool.h>
#include <SDL.h>

extern LinkedList textures;

extern bool m_bRunning;

bool gameInit(const char* title, int xpos, int ypos, int width, int height, int flags);

void gameRender();
void gameUpdate();
void gameHandleEvents();
void gameClean();

// Textures
bool textureLoad(char *filename, char *id, SDL_Renderer *m_pRenderer);

bool textureDraw(char *id, int x, int y, int width, int height,
    SDL_Renderer *pRenderer, SDL_RendererFlip flip);

void textureDrawFrame(char *id, int x, int y, int width, int height,
    int currentRow, int currentFrame, SDL_Renderer *m_pRenderer,
    SDL_RendererFlip flip);

#endif // GAME_H