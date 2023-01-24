#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game {
    private:
        bool m_bRunning;
   
        SDL_Window *m_pWindow;
        SDL_Renderer *m_pRenderer;

        SDL_Texture *m_pTexture;
        SDL_Rect m_sourceRectangle;
        SDL_Rect m_destRectangle;
    public:
        Game();
        ~Game();

        bool init(const char *title, int xpos, int ypos, int width, int height, int flags);

        void render();
        void update();
        void handleEvents();
        void clean();

        bool running();
};

#endif