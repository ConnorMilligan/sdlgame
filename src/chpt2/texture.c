#include "game.h"

typedef struct Texture {
    char *id;
    SDL_Texture *pTexture;
} Texture;

int compareTextures(void *a, void *b) {
    Texture *textureA = (Texture*) a;
    return strcmp(textureA->id, (char*) b);
}

bool textureLoad(char *filename, char *id, SDL_Renderer *m_pRenderer) {
    SDL_Surface *pTempSurface = SDL_LoadBMP(filename);
    if (pTempSurface == 0) {
        return false;
    }

    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    if (pTexture != 0) {
        Texture *pTex = malloc(sizeof(Texture));
        pTex->id = id;
        pTex->pTexture = pTexture;
        llistPush(&textures, pTex);
        return true;
    }

    return false;
}

bool textureDraw(char *id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, llistGetNode(&textures, compareTextures, id)->data, &srcRect, &destRect, 0, 0, flip);
    return true;
}

void textureDrawFrame(char *id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *m_pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(m_pRenderer, llistGetNode(&textures, compareTextures, id)->data, &srcRect, &destRect, 0, 0, flip);
}