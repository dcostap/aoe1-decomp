#pragma once
#include "../common.h"

class TScrollTextPanel : public TTextPanel {
public:
    int scroll;                              // 0x188
    ulong last_time;                         // 0x18C
    int speed;                               // 0x190
    int done;                                // 0x194

    TScrollTextPanel(TPanel* param_1, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, int param_7, void* param_8, long param_9, long param_10, char* param_11);
    virtual ~TScrollTextPanel();
    virtual void set_text(char* param_1);
    virtual long handle_idle();
    virtual void draw();
    virtual void draw_scrolled_line(void* param_1, short param_2, short param_3, ulong param_4, ulong param_5);
};

static_assert(sizeof(TScrollTextPanel) == 0x198, "TScrollTextPanel Size Mismatch");
static_assert(offsetof(TScrollTextPanel, done) == 0x194, "TScrollTextPanel Offset Mismatch");

class TRIBE_Credits_Screen : public TScreenPanel {
public:
    TScrollTextPanel* text_panel;            // 0x478
    int text_set;                            // 0x47C
    int picture_set;                         // 0x480
    ulong last_picture_time;                 // 0x484
    ulong last_pause_time;                   // 0x488
    ScreenMode mode;                         // 0x48C
    tagPALETTEENTRY color_table[256];        // 0x490
    tagPALETTEENTRY color;                   // 0x890
    TShape* back_pics[7];                    // 0x894
    int first_draw;                          // 0x8B0
    int text_done;                           // 0x8B4

    TRIBE_Credits_Screen();
    virtual ~TRIBE_Credits_Screen();
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long handle_idle();
    virtual void draw();
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void close_screen();
};

static_assert(sizeof(TRIBE_Credits_Screen) == 0x8B8, "TRIBE_Credits_Screen Size Mismatch");
static_assert(offsetof(TRIBE_Credits_Screen, text_done) == 0x8B4, "TRIBE_Credits_Screen Offset Mismatch");

