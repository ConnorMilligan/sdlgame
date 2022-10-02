#include "sprite.h"

Sprite::Sprite() {
    this->vboID = 0;
}

Sprite::~Sprite() {
    if (this->vboID != 0) {
        glDeleteBuffers(1, &this->vboID);
    }
    
}

void Sprite::init(float x, float y, float width, float height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    if (this->vboID == 0) {
        glGenBuffers(1, &vboID);
    }
    
    float vertexData[12];

    vertexData[0] = this->x + this->width;
    vertexData[1] = this->y + this->width;

    vertexData[2] = x;
    vertexData[3] = y + height;

    vertexData[4] = x;
    vertexData[5] = y;

    vertexData[6] = x;
    vertexData[7] = y;

    vertexData[8] = x + width;
    vertexData[9] = y;

    vertexData[10] = x + width;
    vertexData[11] = y + height;

    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw() {
    glBindBuffer(GL_ARRAY_BUFFER, this->vboID);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}