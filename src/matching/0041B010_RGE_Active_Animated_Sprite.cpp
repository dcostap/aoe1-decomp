// VA: 0041B010 RGE_Active_Animated_Sprite (constructor)
// PDB source: asprite.cpp
// Attempt log:
// - baseline: existing reconstruction had the wrong base layout and no EH frame (250 diff bytes).
// - layout: restored RGE_Active_Sprite ownership, virtual destructor, and DAT_0056ee78/80 globals (227 diff bytes).
// - control-flow: positive flag guard restored the random-path inline / zero-frame cold arm (231 diff bytes).
// - liveness: natural rnd/tot_time locals matched the integer parameter-home reuse, but the frame stayed 4 bytes short.
// - behavior: a separate frame_time value preserved the FPU product across __ftol and produced an exact 259-byte match.
// - TU context: duration and pause_between_loops are the shared +0x68/+0x6C
//   RGE_Sprite fields; the old narrow aliases selected the wrong shared fields.
// - exact finish: count, tot_time, rnd, frame_time declaration order is required
//   with those canonical fields; each independent walkback lost grouped exactness.
// FLAGS: /GX is required for the original constructor EH frame.

#ifndef ASPRITE_FULL_TU
class RGE_Sprite {
public:
    char gap_00[0x5E];
    short frame_count;      // +0x5E
    char gap_60[0x04];
    float const1;            // +0x64
    float duration;         // +0x68
    float pause_between_loops; // +0x6C
    char flags;             // +0x70
};

class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
    RGE_Active_Sprite(RGE_Sprite* sprite);
    RGE_Sprite* sprite;     // +0x04
    unsigned char type;     // +0x08
    char gap_09[0x03];
    long offset_x;          // +0x0C
    long offset_y;          // +0x10
};

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

extern double DAT_0056ee78;
extern float DAT_0056ee80;
extern int debug_rand(char* file, int line);
#endif

RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(RGE_Sprite* spr)
    : RGE_Active_Sprite(spr)
{
    int count;
    float tot_time;
    int rnd;
    float frame_time;

    type = 2;
    last_frame = 0;
    animate_interval = sprite->duration;

    if (animate_interval < DAT_0056ee78) {
        animate_interval = 0.001f;
    }

    if (sprite->flags & 4) {
        count = (int)sprite->frame_count;
        tot_time = (float)count * sprite->duration + sprite->pause_between_loops;
        rnd = debug_rand("C:\\msdev\\work\\age1_x1\\asprite.cpp", 0xB7);
        frame_time = (float)rnd * tot_time * DAT_0056ee80;
        frame = (short)(frame_time / sprite->duration);

        if (frame >= sprite->frame_count) {
            frame = sprite->frame_count - 1;
            animate_interval = frame_time - (float)(int)frame * sprite->duration;
        }

        last_frame = frame;
    } else {
        frame = 0;
    }

    animate_last = 0.0f;
    frame_changed = 0;
    frame_looped = 0;
    animate_flag = 1;
}
