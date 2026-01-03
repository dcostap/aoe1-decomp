#pragma once
#include "../common.h"

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

    TMessagePanel(void* param_1, long param_2, long param_3);
    virtual ~TMessagePanel();
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    virtual void set_justification(JustType param_1, JustType param_2, int param_3);
    virtual void show_message(MessageType param_1, char* param_2, uchar param_3, uchar param_4, void* param_5, long param_6, long param_7);
    virtual void show_message2(MessageType param_1, char* param_2, ulong param_3, ulong param_4, void* param_5, long param_6, long param_7, TShape* param_8, int param_9, TShape* param_10, int param_11);
    virtual void remove_message();
    virtual void draw();
    virtual void get_true_render_rect(tagRECT* param_1);
    virtual long handle_idle();
    virtual int render_to_image_buffer();
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4);
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual void set_font(void* param_1, long param_2, long param_3);
};

static_assert(sizeof(TMessagePanel) == 0x380, "TMessagePanel Size Mismatch");
static_assert(offsetof(TMessagePanel, IconFrame2) == 0x37C, "TMessagePanel Offset Mismatch");

long TMessagePanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall handle_mouse_down(TMessagePanel * this, uchar param_
//              long              EAX:4          <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1
//              long              Stack[0x8]:4   param_2
//              long              Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?handle_mouse_down@TMessagePanel@@UAEJEJJHH@Z                XREF[1]:     005716d8(*)
//                               TMessagePanel::handle_mouse_down
//                              pnl_msg.h:41 (5)
//         0047a160     XOR        EAX,EAX
//         0047a162     RET        0x14
//         0047a165     ??         90h
//         0047a166     NOP
//         0047a167     NOP
//         0047a168     NOP
//         0047a169     NOP
//         0047a16a     NOP
//         0047a16b     NOP
//         0047a16c     NOP
//         0047a16d     NOP
//         0047a16e     NOP
//         0047a16f     NOP
    return 0;
}

long TMessagePanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall handle_mouse_move(TMessagePanel * this, long param_1
//              long              EAX:4          <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?handle_mouse_move@TMessagePanel@@UAEJJJHH@Z                 XREF[1]:     005716dc(*)
//                               TMessagePanel::handle_mouse_move
//                              pnl_msg.h:43 (5)
//         0047a170     XOR        EAX,EAX
//         0047a172     RET        0x10
//         0047a175     ??         90h
//         0047a176     NOP
//         0047a177     NOP
//         0047a178     NOP
//         0047a179     NOP
//         0047a17a     NOP
//         0047a17b     NOP
//         0047a17c     NOP
//         0047a17d     NOP
//         0047a17e     NOP
//         0047a17f     NOP
    return 0;
}

long TMessagePanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall handle_mouse_up(TMessagePanel * this, uchar param_1,
//              long              EAX:4          <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1
//              long              Stack[0x8]:4   param_2
//              long              Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?handle_mouse_up@TMessagePanel@@UAEJEJJHH@Z                  XREF[1]:     005716e0(*)
//                               TMessagePanel::handle_mouse_up
//                              pnl_msg.h:45 (5)
//         0047a180     XOR        EAX,EAX
//         0047a182     RET        0x14
//         0047a185     ??         90h
//         0047a186     NOP
//         0047a187     NOP
//         0047a188     NOP
//         0047a189     NOP
//         0047a18a     NOP
//         0047a18b     NOP
//         0047a18c     NOP
//         0047a18d     NOP
//         0047a18e     NOP
//         0047a18f     NOP
    return 0;
}

