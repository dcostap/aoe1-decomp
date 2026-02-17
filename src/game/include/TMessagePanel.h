#pragma once
#include "TPanel.h"

class TMessagePanel : public TPanel {
public:
    TMessagePanel();
    TMessagePanel(void* param_1, long param_2, long param_3);

    // Virtuals (best-effort)
    virtual ~TMessagePanel(); // vt[0] (0x0)
    virtual void set_rect(tagRECT param_1); // vt[2] (0x8)
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // vt[3] (0xC)
    virtual void draw_setup(int param_1); // vt[10] (0x28)
    virtual void draw_finish(); // vt[11] (0x2C)
    virtual void draw(); // vt[12] (0x30)
    virtual void draw_rect(tagRECT* param_1); // vt[13] (0x34)

    virtual long handle_idle(); // vt[16] (0x40)
    virtual void handle_mouse_down(int param_1, int param_2, int param_3, int param_4, int param_5); // vt[17] (0x44)
    virtual void handle_mouse_move(int param_1, int param_2, int param_3, int param_4, int param_5); // vt[18] (0x48)
    virtual void handle_mouse_up(int param_1, int param_2, int param_3, int param_4, int param_5); // vt[19] (0x4C)
    virtual void handle_key_down(int param_1, int param_2, int param_3, int param_4, int param_5); // vt[20] (0x50)
    virtual void handle_key_up(int param_1, int param_2, int param_3, int param_4, int param_5); // vt[21] (0x54)
    virtual void handle_char(int param_1, int param_2, int param_3, int param_4, int param_5); // vt[22] (0x58)
    virtual void handle_scroll(int param_1, int param_2, int param_3, int param_4, int param_5); // vt[23] (0x5C)

    virtual int is_inside(int param_1, int param_2); // vt[24] (0x60)
    virtual void set_active(int param_1); // vt[25] (0x64)
    virtual void set_visible(int param_1); // vt[26] (0x68)
    virtual void set_redraw(RedrawMode param_1); // vt[27] (0x6C)
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3); // vt[28] (0x70)

    virtual void add_panel(TPanel* param_1); // vt[40] (0xA0)
    virtual void remove_panel(TPanel* param_1); // vt[41] (0xA4)
    virtual void remove_all_panels(); // vt[42] (0xA8)

    virtual void set_message(char* param_1); // vt[45] (0xB4)
    virtual void set_message(int param_1); // vt[46] (0xB8)
    virtual void clear_message(); // vt[47] (0xBC)
    virtual void set_time(unsigned long param_1); // vt[48] (0xC0)
    virtual void set_color(unsigned long param_1, unsigned long param_2); // vt[49] (0xC4)
    virtual void set_style(int param_1); // vt[50] (0xC8)
    virtual void set_alignment(int param_1, int param_2); // vt[51] (0xCC)
    virtual void set_wrap(int param_1); // vt[52] (0xD0)
    virtual void set_icon(int param_1); // vt[53] (0xD4)
    virtual void handle_move_outside(int param_1, int param_2, int param_3, int param_4, int param_5); // vt[54] (0xD8)
    virtual void handle_reactivate(); // vt[55] (0xDC)
    virtual void set_font(void* param_1, long param_2, long param_3); // vt[56] (0xE0)

    // Non-virtual helpers used by scr_game paths.
    void set_justification(int param_1, int param_2, int param_3);
    void remove_message();

    struct message_type* types;
    char text[512];
    int showing_message;
    unsigned long start_time;
    unsigned long duration;
    void* font;
    long font_height;
    long font_width;
    int index_color;
    unsigned long font_color1;
    unsigned long font_color2;
    int horz_just;
    int vert_just;
    int word_wrap;
    void* image_clip_region;
    TDrawArea* ImageBuffer;
    TShape* Icon;
    int IconIndex;
    int IconX;
    int IconY;
    int IconWidth;
    int IconHeight;
    int IconFrame1;
    int IconFrame2;
};
// static_assert(sizeof(TMessagePanel) == 0x380, "Size mismatch");
