#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "sprite.h"

enum class gameState {PLAY, EXIT};

class Game
{
private:
    SDL_Window *window;
    int screenWidth;
    int screenHeight;
    gameState currState;
    Sprite sprite;

    void init();
    void processInput();
    void loop();
    void drawGame();
public:
    Game();
    ~Game();

    void run();
    
};



#endif