#include "game.h"

#include <iostream>
#include <GL/glew.h>

void fatalError(std::string error) {
    std::cout << error << std::endl;
    std::cout << "Enter any key to quit...";
    int temp;
    std::cin >> temp;

    SDL_Quit();
}

Game::Game() {
    this->screenWidth = 640;
    this->screenHeight = 480;
    this->window = nullptr;
    this->currState = gameState::PLAY;
}

Game::~Game() {

}

void Game::init() {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    this->window = SDL_CreateWindow("Game", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->screenWidth, this->screenHeight, SDL_WINDOW_OPENGL);
    
    if (this->window == nullptr)
        fatalError("SDL window could not be created");

    SDL_GLContext context = SDL_GL_CreateContext(this->window);

    if (context == nullptr)
        fatalError("SDL context could not be created");

    GLenum error = glewInit();

    if (error != GLEW_OK)
        fatalError("Failed to initialize GLEW");

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    glClearColor(0.0, 0.0, 1.0, 1.0);
}

void Game::run() {
    this->init();
    this->sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);
    this->loop();
}

void Game::processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            this->currState = gameState::EXIT;
            break;
        case SDL_MOUSEMOTION:
            std::cout << event.motion.x << " " << event.motion.y << std::endl;
            break;
        
        default:
            break;
        }
    }
    
}

void Game::loop() {
    while (this->currState != gameState::EXIT) {
        this->processInput();
        this->drawGame();
    }
    
}

void Game::drawGame() {
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->sprite.draw();

    SDL_GL_SwapWindow(this->window);
}
