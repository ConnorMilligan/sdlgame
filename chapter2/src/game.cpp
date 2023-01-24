#include "game.h"

#include <iostream>

Game::Game() {
    this->m_bRunning = false;
}

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL init success" << std::endl;

        // init window
        this->m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (m_pWindow != 0) {
            std::cout << "Window creation success" << std::endl;

            this->m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if(m_pRenderer != 0) {
                std::cout << "Renderer creation success" << std::endl;
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            } else {
                std::cout << "Renderer init failed" << std::endl;
                return false;
            }
        } else {
            std::cout << "Window init failed" << std::endl;
            return false;
        }
    } else {
        std::cout << "SDL init failed" << std::endl;
        return false;
    }

    std::cout << "Init successful" << std::endl;
    this->m_bRunning = true;

    // load texture
    SDL_Surface *pTempSurface = SDL_LoadBMP("../../res/rider.bmp");
    this->m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    // set to rectangle
    SDL_QueryTexture(this->m_pTexture, NULL, NULL, &this->m_sourceRectangle.w, &this->m_sourceRectangle.h);

    this->m_destRectangle.x = this->m_sourceRectangle.x = 0;
    this->m_destRectangle.y = this->m_sourceRectangle.y = 0;

    this->m_destRectangle.w = this->m_sourceRectangle.w;
    this->m_destRectangle.h = this->m_sourceRectangle.h;

    return true;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer); // clear
    SDL_RenderCopy(this->m_pRenderer, this->m_pTexture, &this->m_sourceRectangle, &this->m_destRectangle);
    SDL_RenderPresent(m_pRenderer); // draw
}

void Game::update() {

}

void Game::handleEvents() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                this->m_bRunning = false;
                break;
            
            default:
                break;
        }
    }
}

void Game::clean() {
    std::cout << "Cleaning game" << std::endl;
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

bool Game::running() {
    return this->m_bRunning;
}