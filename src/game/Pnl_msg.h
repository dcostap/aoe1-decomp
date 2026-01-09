#pragma once
#include "common.h"

enum JustType : unsigned int {
    TopJust = 0,
    BottomJust = 1,
    LeftJust = 2,
    RightJust = 3,
    CenterJust = 4,
};

enum MessageType : unsigned int {
    InfoMessage = 0,
    BadMessage = 1,
    DebugMessage = 2,
    ChatMessage = 3,
    ColoredChatMessage = 4,
    RightInfoMessage = 5,
};

class TMessagePanel : public TPanel {
public:
    MessageType message_type;                // 0xF4
    char text[512];                          // 0xF8
    int showing_message;                     // 0x2F8
    ulong start_time;                        // 0x2FC
    long show_message_interval;              // 0x300
    void* font;                              // 0x304
    long font_wid;                           // 0x308
    long font_hgt;                           // 0x30C
    uchar font_color;                        // 0x310
    uchar back_color;                        // 0x311
    int index_color;                         // 0x314
    ulong font_color1;                       // 0x318
    ulong font_color2;                       // 0x31C
    JustType horz_just;                      // 0x320
    JustType vert_just;                      // 0x324
    int word_wrap;                           // 0x328
    void* image_clip_region;                 // 0x32C
    TDrawArea* ImageBuffer;                  // 0x330
    tagRECT ImageRect;                       // 0x334
    tagRECT UsedImageRect;                   // 0x344
    tagRECT UsedScreenRect;                  // 0x354
    int LastIBWidth;                         // 0x364
    int LastIBHeight;                        // 0x368
    int ImageTextActive;                     // 0x36C
    TShape* Icon1;                           // 0x370
    TShape* Icon2;                           // 0x374
    int IconFrame1;                          // 0x378
    int IconFrame2;                          // 0x37C

    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // vt0[3]+0xC=0x4790E0
    virtual void draw();                                    // vt0[12]+0x30=0x479590
    virtual long handle_idle();                             // vt0[19]+0x4C=0x479A80
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[28]+0x70=0x47A160
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4); // vt0[29]+0x74=0x47A170
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[30]+0x78=0x47A180
    virtual void get_true_render_rect(tagRECT* param_1);    // vt0[46]+0xB8=0x479A10
    virtual void set_font(void* param_1, long param_2, long param_3); // vt0[56]+0xE0=0x47A190
    TMessagePanel(void* param_1, long param_2, long param_3);
    ~TMessagePanel();
    void set_justification(JustType param_1, JustType param_2, int param_3);
    void show_message(MessageType param_1, char* param_2, uchar param_3, uchar param_4, void* param_5, long param_6, long param_7);
    void show_message2(MessageType param_1, char* param_2, ulong param_3, ulong param_4, void* param_5, long param_6, long param_7, TShape* param_8, int param_9, TShape* param_10, int param_11);
    void remove_message();
    int render_to_image_buffer();
};

static_assert(sizeof(TMessagePanel) == 0x380, "TMessagePanel Size Mismatch");

