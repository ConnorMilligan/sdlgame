#include "enemy.h"

Enemy::Enemy(const LoaderParams *pParams) : SDLGameObject(pParams) {}

void Enemy::update() {
    this->m_x++;
    this->m_currentFrame = int(((SDL_GetTicks() / 100) %6));
}