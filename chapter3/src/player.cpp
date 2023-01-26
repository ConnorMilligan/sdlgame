#include "player.h"

Player::Player(const LoaderParams *pParams) : SDLGameObject(pParams) {}

void Player::update() {
    this->m_x--;
    this->m_currentFrame = int(((SDL_GetTicks() / 100) %6));
}