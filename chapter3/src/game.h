#ifndef GAME_H
#define GAME_H

#include <vector>

#include "textureManager.h"
#include "player.h"
#include "enemy.h"

class Game {
    private:
        Game() {}
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
        SDL_Texture* m_pTexture;
        SDL_Rect m_sourceRectangle;
        SDL_Rect m_destinationRectangle;

        std::vector<GameObject*> m_gameObjects;
        GameObject *m_player;
        GameObject *m_enemy1;
        GameObject *m_enemy2;
        GameObject *m_enemy3;


        bool m_bRunning;

        int m_currentFrame;
        static Game* s_pInstance;

    public:
        static Game* Instance() {
            if (s_pInstance == 0) {
                s_pInstance = new Game();
                return s_pInstance;
            }
            return s_pInstance;
        }

        SDL_Renderer* getRenderer() const { return m_pRenderer; }
        bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
        void render();
        void update();
        void handleEvents();
        void clean();

        bool running();
};

typedef Game TheGame;

#endif
