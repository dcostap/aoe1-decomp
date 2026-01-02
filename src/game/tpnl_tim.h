#pragma once
#include "../common.h"

class TRIBE_Panel_Time : public TPanel {
public:
    void* font;                              // 0xF4
    ulong color1;                            // 0xF8
    ulong color2;                            // 0xFC
    int clock_type;                          // 0x100
    int old_clock_type;                      // 0x104
    int clock_format;                        // 0x108
    int old_clock_format;                    // 0x10C
    int player_id;                           // 0x110
    TRIBE_World* world;                      // 0x114
    TRIBE_Player* player;                    // 0x118
    ulong start_real_time;                   // 0x11C
    ulong game_time;                         // 0x120
    ulong last_game_time;                    // 0x124
    ulong display_time;                      // 0x128
    ulong last_display_time;                 // 0x12C
    void* image_clip_region;                 // 0x130
    TDrawArea* ImageBuffer;                  // 0x134
    tagRECT ImageRect;                       // 0x138
    tagRECT UsedImageRect;                   // 0x148
    tagRECT UsedScreenRect;                  // 0x158
    int ImageTextActive;                     // 0x168
    int LastIBWidth;                         // 0x16C
    int LastIBHeight;                        // 0x170

    TRIBE_Panel_Time(TDrawArea* param_1, TPanel* param_2);
    virtual ~TRIBE_Panel_Time();
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    virtual void startup();
    virtual void set_clock_type(int param_1, int param_2);
    virtual int get_clock_type();
    virtual int get_player_id();
    virtual void draw();
    virtual void get_true_render_rect(tagRECT* param_1);
    virtual long handle_idle();
    virtual int render_to_image_buffer();
};

static_assert(sizeof(TRIBE_Panel_Time) == 0x174, "TRIBE_Panel_Time Size Mismatch");
static_assert(offsetof(TRIBE_Panel_Time, LastIBHeight) == 0x170, "TRIBE_Panel_Time Offset Mismatch");

