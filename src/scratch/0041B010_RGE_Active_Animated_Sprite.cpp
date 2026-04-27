// VA: 0041B010 RGE_Active_Animated_Sprite (constructor)
// PDB source: asprite.cpp

#include <math.h>

class RGE_Sprite {
public:
    char gap_00[0x5E];
    short frame_count;      // +0x5E
    char gap_60[0x04];
    float const1;           // +0x64
    float animate_speed;    // +0x68
    float anim_elapsed;     // +0x6C
    char flags;             // +0x70
};

class RGE_Active_Sprite {
public:
    virtual void d00();
    RGE_Active_Sprite(RGE_Sprite* sprite);
    char gap_04[0x04];
    RGE_Sprite* sprite;     // +0x04
    char byte_08;           // +0x08
};

extern "C" long __cdecl __ftol();

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
public:
    short frame;                // +0x14
    float animate_interval;     // +0x18
    float animate_last;         // +0x1C
    short last_frame;           // +0x20
    char frame_changed;         // +0x22
    char frame_looped;          // +0x23
    char animate_flag;          // +0x24

    RGE_Active_Animated_Sprite(RGE_Sprite* spr);
    virtual void update(float param_1, float param_2);
};

extern int debug_rand(char* file, int line);
extern "C" void* __cdecl operator_new(unsigned long sz);
extern "C" void __cdecl operator_delete(void* p);

RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(RGE_Sprite* spr)
    : RGE_Active_Sprite(spr)
{
    byte_08 = 2;
    last_frame = 0;
    animate_interval = sprite->animate_speed;

    float min_interval = 0.001f;
    if (animate_interval < min_interval) {
        animate_interval = min_interval;
    }

    if (!(sprite->flags & 4)) {
        frame = 0;
    } else {
        int rnd = debug_rand("C:\\msdev\\work\\age1_x1\\asprite.cpp", 0xB7);
        float tmp = (float)rnd * sprite->animate_speed + sprite->anim_elapsed;
        int ft = __ftol();
        frame = (short)ft;

        if (frame >= sprite->frame_count) {
            frame = sprite->frame_count - 1;
            animate_interval = (float)((double)tmp - (double)(int)frame * (double)sprite->animate_speed);
        }

        last_frame = frame;
    }

    animate_last = 0.0f;
    frame_changed = 0;
    frame_looped = 0;
    animate_flag = 1;
}
