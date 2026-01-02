#pragma once
#include "../common.h"

class TRIBE_Panel_Pop : public TPanel {
public:
    void* font;                              // 0xF4
    ulong color1;                            // 0xF8
    ulong color2;                            // 0xFC
    ulong color3;                            // 0x100
    int player_id;                           // 0x104
    TRIBE_World* world;                      // 0x108
    TRIBE_Player* player;                    // 0x10C
    int pop;                                 // 0x110
    int max_pop;                             // 0x114
    uchar mode;                              // 0x118
    float timer;                             // 0x11C
    void* image_clip_region;                 // 0x120
    TDrawArea* ImageBuffer;                  // 0x124
    tagRECT ImageRect;                       // 0x128
    tagRECT UsedImageRect;                   // 0x138
    tagRECT UsedScreenRect;                  // 0x148
    int ImageTextActive;                     // 0x158
    int LastIBWidth;                         // 0x15C
    int LastIBHeight;                        // 0x160

    TRIBE_Panel_Pop(TDrawArea* param_1, TPanel* param_2);
    virtual ~TRIBE_Panel_Pop();
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    virtual void startup();
    virtual int get_player_id();
    virtual void draw();
    virtual void get_true_render_rect(tagRECT* param_1);
    virtual long handle_idle();
    virtual int render_to_image_buffer();
};

static_assert(sizeof(TRIBE_Panel_Pop) == 0x164, "TRIBE_Panel_Pop Size Mismatch");
static_assert(offsetof(TRIBE_Panel_Pop, LastIBHeight) == 0x160, "TRIBE_Panel_Pop Offset Mismatch");

