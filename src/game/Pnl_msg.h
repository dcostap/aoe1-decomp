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

class TMessagePanel : public TPanel       {
public:
    char _pad_0x4[0xF0];
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

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TMessagePanel() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 03] Offset 0x0C (Override)
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // Ghidra: set_rect

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 12] Offset 0x30 (Override)
    virtual void draw(); // Ghidra: draw

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 19] Offset 0x4C (Override)
    virtual long handle_idle(); // Ghidra: handle_idle

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 28] Offset 0x70 (Override)
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // Ghidra: handle_mouse_down

    // [Slot 29] Offset 0x74 (Override)
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4); // Ghidra: handle_mouse_move

    // [Slot 30] Offset 0x78 (Override)
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5); // Ghidra: handle_mouse_up

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 46] Offset 0xB8 (Override)
    virtual void get_true_render_rect(tagRECT* param_1); // Ghidra: get_true_render_rect

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 56] Offset 0xE0 (Override)
    virtual void set_font(void* param_1, long param_2, long param_3); // Ghidra: set_font

    // --- Non-Virtual Members ---
    void set_justification(JustType param_1, JustType param_2, int param_3);
    void show_message(MessageType param_1, char* param_2, uchar param_3, uchar param_4, void* param_5, long param_6, long param_7);
    void show_message2(MessageType param_1, char* param_2, ulong param_3, ulong param_4, void* param_5, long param_6, long param_7, TShape* param_8, int param_9, TShape* param_10, int param_11);
    void remove_message();
    int render_to_image_buffer();
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

