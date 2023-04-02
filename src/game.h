#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

extern bool m_bRunning;

bool gameInit(const char* title, int xpos, int ypos, int width, int height, int flags);

void gameRender();
void gameUpdate();
void gameHandleEvents();
void gameClean();

#endif // GAME_H