#include "game.h"

void GameObject_Load(GameObject *obj, char *textureId, int width, int height, Point pos) {
    obj->textureId = textureId;
    obj->width = width;
    obj->height = height;
    obj->pos = pos;
    obj->currentFrame = 1;
    obj->currentRow = 1;
}

void GameObject_Draw(GameObject *obj, SDL_Renderer *renderer) {
    textureDrawFrame(obj->textureId, obj->pos.x, obj->pos.y, obj->width, obj->height,
        obj->currentRow, obj->currentFrame, renderer, SDL_FLIP_NONE);
}

void GameObject_Update(GameObject *obj) {
    obj->pos.x++;
}