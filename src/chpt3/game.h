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

// GameObject
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    char *textureId;
    int currentFrame;
    int currentRow;
    Point pos;
    int width;
    int height;
} GameObject;

void GameObject_Load(GameObject *obj, char *textureId, int width, int height, Point pos);
void GameObject_Draw(GameObject *obj, SDL_Renderer *renderer);
void GameObject_Update(GameObject *obj);


// Input handler
void inputUpdate();

#endif // GAME_H