#include "game.h"

#include <iostream>

Game::Game() {}

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
                SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
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
    if (!TheTextureManager::Instance()->load("../../res/animate-alpha.png", "animate", m_pRenderer))
        return false;

    return true;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer); // clear

    TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, this->m_pRenderer);
    TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, this->m_currentFrame, this->m_pRenderer);


    SDL_RenderPresent(m_pRenderer); // draw
}

void Game::update() {
    this->m_currentFrame = int(((SDL_GetTicks() / 100) %6));
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