#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

#include <string>
#include <SDL2/SDL.h>

class LoaderParams {
    private:
        int m_x;
        int m_y;

        int m_height;
        int m_width;

        std::string m_textureId;
    public:
        LoaderParams(int x, int y, int width, int height, std::string textureId) 
            : m_x(x), m_y(y), m_width(width), m_height(height), m_textureId(textureId) {}
        
        int getX() const { return this->m_x; }
        int getY() const { return this->m_y; }
        int getWidth() const { return this->m_width; }
        int getHeight() const { return this->m_height; }
        std::string getTextureId() const { return this->m_textureId; }




};

#endif
