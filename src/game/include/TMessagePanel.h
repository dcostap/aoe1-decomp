#pragma once

#include "TPanel.h"

class TMessagePanel : public TPanel {
public:
    enum MessageType : int {
        InfoMessage = 0,
        BadMessage = 1,
        DebugMessage = 2,
        ChatMessage = 3,
        ColoredChatMessage = 4,
        RightInfoMessage = 5,
    };

    enum JustType : int {
        TopJust = 0,
        BottomJust = 1,
        LeftJust = 2,
        RightJust = 3,
        CenterJust = 4,
    };

    TMessagePanel();
    TMessagePanel(void* param_1, long param_2, long param_3);
    virtual ~TMessagePanel();

    virtual void set_rect(tagRECT param_1) override;
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4) override;
    virtual void draw() override;
    virtual void get_true_render_rect(tagRECT* param_1) override;
    virtual long handle_idle() override;
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) override;
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4) override;
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) override;
    virtual void set_font(void* param_1, long param_2, long param_3);

    void set_message(char* param_1);
    void set_message(int param_1);
    void clear_message();
    void set_time(unsigned long param_1);
    void set_color(unsigned long param_1, unsigned long param_2);
    void set_style(int param_1);
    void set_alignment(int param_1, int param_2);
    void set_wrap(int param_1);
    void set_icon(int param_1);
    void set_justification(int param_1, int param_2, int param_3);
    void show_message(int param_1, char* param_2, unsigned char param_3, unsigned char param_4, void* param_5, long param_6, long param_7);
    void show_message2(int param_1, char* param_2, unsigned long param_3, unsigned long param_4, void* param_5, long param_6, long param_7, TShape* param_8, int param_9, TShape* param_10, int param_11);
    void remove_message();

protected:
    int render_to_image_buffer();

public:
    MessageType message_type;
    char text[512];
    int showing_message;
    unsigned long start_time;
    long show_message_interval;
    void* font;
    long font_wid;
    long font_hgt;
    unsigned char font_color;
    unsigned char back_color;
    unsigned char _pad_0[2];
    int index_color;
    unsigned long font_color1;
    unsigned long font_color2;
    JustType horz_just;
    JustType vert_just;
    int word_wrap;
    void* image_clip_region;
    TDrawArea* ImageBuffer;
    tagRECT ImageRect;
    tagRECT UsedImageRect;
    tagRECT UsedScreenRect;
    int LastIBWidth;
    int LastIBHeight;
    int ImageTextActive;
    TShape* Icon1;
    TShape* Icon2;
    int IconFrame1;
    int IconFrame2;
};

static_assert(sizeof(TMessagePanel) == 0x380, "Size mismatch");
