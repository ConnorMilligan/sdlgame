#include "SDLgameObject.h"
#include "textureManager.h"
#include "game.h"

SDLGameObject::SDLGameObject(const LoaderParams *pParams) : GameObject(pParams) {
    this->m_x = pParams->getX();
    this->m_y = pParams->getY();
    this->m_width = pParams->getWidth();
    this->m_height = pParams->getHeight();
    this->m_textureId = pParams->getTextureId();

    this->m_currentRow = 1;
    this->m_currentFrame = 1;
}

void SDLGameObject::draw() {
    TextureManager::Instance()->drawFrame(m_textureId, m_x, m_y,
        m_width, m_height, m_currentRow, m_currentFrame,
        TheGame::Instance()->getRenderer());
}

void SDLGameObject::update() {}
void SDLGameObject::clean() {}