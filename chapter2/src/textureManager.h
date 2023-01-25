#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>

class TextureManager {
    private:
        std::map<std::string, SDL_Texture*> m_textureMap;
    public:
        TextureManager();
        ~TextureManager();

        bool load(std::string filename, std::string id, SDL_Renderer *pRenderer);

        void draw(std::string id, int x, int y, int width, int height,
                SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

        void drawFrame(std::string id, int x, int y, int width, int height,
                int currentRow, int currentFrame, SDL_Renderer *pRenderer, 
                SDL_RendererFlip flip = SDL_FLIP_NONE);

        
};

#endif