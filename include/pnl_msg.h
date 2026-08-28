#ifndef AOE1_PNL_MSG_H
#define AOE1_PNL_MSG_H

#include "panel.h"

// TPanel, TDrawArea, and TDrawSystem belong to their canonical modules.
// TShape is used only through pointers in this module's public surface.
class TShape;

class TMessagePanel : public TPanel {
public:
    enum MessageType {
        InfoMessage = 0,
        BadMessage = 1,
        DebugMessage = 2,
        ChatMessage = 3,
        ColoredChatMessage = 4,
        RightInfoMessage = 5
    };
    enum JustType {
        TopJust = 0,
        BottomJust = 1,
        LeftJust = 2,
        RightJust = 3,
        CenterJust = 4
    };

    MessageType message_type;
    char text[0x200];
    int showing_message;
    int start_time;
    int show_message_interval;
    void* font;
    long font_wid;
    long font_hgt;
    unsigned char font_color;
    unsigned char back_color;
    unsigned char gap_312[2];
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

    TMessagePanel(void*, long, long);
    virtual ~TMessagePanel();
    virtual void set_rect(long, long, long, long);
    virtual void draw();
    virtual void get_true_render_rect(tagRECT&);
    virtual long handle_idle();
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    void set_justification(JustType, JustType, int);
    void show_message(MessageType, char*, unsigned char, unsigned char,
                      void*, long, long);
    void show_message2(MessageType, char*, unsigned long, unsigned long,
                       void*, long, long, TShape*, int, TShape*, int);
    void remove_message();
protected:
    int render_to_image_buffer();
public:
    virtual void set_font(void*, long, long);
};

typedef char pnl_msg_message_panel_size_check[
    (sizeof(TMessagePanel) == 0x380) ? 1 : -1];

#endif
