#pragma once
#include "common.h"

enum ScreenMode : unsigned int {
    ModeNone = 1,
    ModeFadeOut = 2,
    ModeFadeOutDone = 3,
    ModePause = 4,
    ModeFadeIn = 5,
};

enum ActionType : unsigned int {
    ActionDone = 1,
};

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

    virtual void draw();                                    // vt0[12]+0x30=0x492CC0
    virtual long handle_idle();                             // vt0[19]+0x4C=0x492A50
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[28]+0x70=0x492A40
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // vt0[43]+0xAC=0x492D50
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x492D70
    TRIBE_Credits_Screen();
    ~TRIBE_Credits_Screen();
    void close_screen();
};

static_assert(sizeof(TRIBE_Credits_Screen) == 0x8B8, "TRIBE_Credits_Screen Size Mismatch");

class TScrollTextPanel : public TTextPanel {
public:
    int scroll;                              // 0x188
    ulong last_time;                         // 0x18C
    int speed;                               // 0x190
    int done;                                // 0x194

    virtual void draw();                                    // vt0[12]+0x30=0x493070
    virtual long handle_idle();                             // vt0[19]+0x4C=0x492FB0
    virtual void set_text(char* param_1);                   // vt0[58]+0xE8=0x492F80
    TScrollTextPanel(TPanel* param_1, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, int param_7, void* param_8, long param_9, long param_10, char* param_11);
    ~TScrollTextPanel();
    void draw_scrolled_line(void* param_1, short param_2, short param_3, ulong param_4, ulong param_5);
};

static_assert(sizeof(TScrollTextPanel) == 0x198, "TScrollTextPanel Size Mismatch");

