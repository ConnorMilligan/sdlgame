#ifndef GAME_H
#define GAME_H

#include "textureManager.h"

class Game {
    private:
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
        SDL_Texture* m_pTexture;
        SDL_Rect m_sourceRectangle;
        SDL_Rect m_destinationRectangle;

        bool m_bRunning;

        int m_currentFrame;
    public:
        Game() {}
        ~Game() {}

        bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
        void render();
        void update();
        void handleEvents();
        void clean();

        bool running();
};

#endif
