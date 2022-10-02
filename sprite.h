#ifndef SPRITE_H
#define SPRITE_H

#include <GL/glew.h>

class Sprite
{
private:
    int x;
    int y;
    int width;
    int height;

    GLuint vboID;
public:
    Sprite();
    ~Sprite();

    void init(float x, float y, float width, float height);

    void draw();
    
};



#endif