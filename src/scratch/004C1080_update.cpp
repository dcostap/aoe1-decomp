// VA: 004C1080 RGE_Sprite::update (123B)
// PDB source: sprite.cpp lines 955-975
// Updates sprite animation time tracking, deletes shape if timed out
#include "..\..\include\game_globals.h"

struct TShape {
    ~TShape();
};
struct RGE_Sprite;

void operator_delete(void* ptr);

struct RGE_Sprite {
    char field_00[0x14];
    unsigned char loaded;        // +0x14
    char field_15[0x07];
    TShape* shape;               // +0x1C
    unsigned long last_time;     // +0x20
    int delta_time;              // +0x24
    
    void update(unsigned long param_1);
};

void RGE_Sprite::update(unsigned long param_1) {
    if (!loaded) return;
    if (!shape) return;
    
    if ((double)delta_time == 0.0) {
        last_time = param_1;
        delta_time = 1;
        return;
    }
    
    {
        unsigned long old_time = last_time;
        int new_dt;
        last_time = param_1;
        new_dt = (param_1 - old_time) + delta_time;
        delta_time = new_dt;
        
        if (new_dt > 179999) {
            if (shape) {
                shape->~TShape();
                operator_delete(shape);
            }
            shape = 0;
        }
    }
}
