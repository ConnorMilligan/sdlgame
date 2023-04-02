#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

extern bool m_bRunning;

void gameInit();

void gameRenderer();
void gameUpdate();
void gameHandleEvents();
void gameClean();

#endif // GAME_H