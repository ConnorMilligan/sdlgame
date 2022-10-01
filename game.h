#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

enum class gameState {PLAY, EXIT};

class Game
{
private:
    SDL_Window *window;
    int screenWidth;
    int screenHeight;
    gameState currState;

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