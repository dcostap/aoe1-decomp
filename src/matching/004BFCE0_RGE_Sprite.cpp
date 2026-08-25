// attempt 1: natural destructor with the loaded/shape gate, then sound/draw frees and the final zero
// result: exact match after preserving the redundant inner shape check and the original field clear order
// moved to src\matching\004BFCE0_RGE_Sprite.cpp after local validation

#include "..\..\include\sprite_context.h"

extern void operator_delete(void* block);
extern "C" void __cdecl free(void* block);

RGE_Sprite::~RGE_Sprite() {
    TShape* shape = this->shape;
    if (shape != 0 && this->loaded != 0) {
        if (this->shape != 0) {
            shape->~TShape();
            operator_delete(shape);
        }
        this->loaded = 0;
    }

    this->shape = 0;

    if (this->sound_list != 0) {
        free(this->sound_list);
        this->sound_list = 0;
    }

    if (this->draw_list != 0) {
        free(this->draw_list);
        this->draw_list = 0;
    }

    this->color_tables = 0;
}
