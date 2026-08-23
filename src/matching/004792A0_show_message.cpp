// first pass: direct reconstruction from packet; keep typed panel surface local
extern "C" int strncmp(const char*, const char*, unsigned int);
extern "C" char* strncpy(char*, const char*, unsigned int);
long debug_timeGetTime(const char* file, int line);

#ifndef AOE1_PNL_MSG_CONTEXT_H
class TPanel {
public:
    virtual void pv0();
    virtual void pv1();
    virtual void pv2();
    virtual void pv3();
    virtual void pv4();
    virtual void set_active(int);
    virtual void pv6();
    virtual void pv7();
    virtual void set_redraw(int);

    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0x9C];
    int display_changed_count;
    char gap_E4[0x10];
};

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
    int message_type;
    char text[0x200];
    int showing_message;
    int start_time;
    int show_message_interval;
    void* font;
    long font_wid;
    long font_hgt;
    unsigned char font_color;
    unsigned char back_color;
    char gap_312[2];
    int index_color;
    char gap_318[0x18];
    void* ImageBuffer;

    void render_to_image_buffer();
    void show_message(MessageType message_type, char* text, unsigned char font_color, unsigned char back_color, void* font, long font_wid, long font_hgt);
};
#endif

void TMessagePanel::show_message(TMessagePanel::MessageType message_type, char* text, unsigned char font_color, unsigned char back_color, void* font, long font_wid, long font_hgt) {
    if (this->showing_message && this->message_type == message_type && strncmp(text, this->text, 0x1ff) == 0) {
        if (font == 0) {
            return;
        }
        if (font == this->font) {
            return;
        }
    }

    if (font != 0) {
        this->font = font;
        this->font_wid = font_wid;
        this->font_hgt = font_hgt;
    }

    this->message_type = message_type;
    for (int i = 0; i < 0x200; ++i) {
        this->text[i] = 0;
    }
    strncpy(this->text, text, 0x1ff);
    this->display_changed_count++;
    this->showing_message = 1;
    this->start_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp", 0x9e);
    this->font_color = font_color;
    this->index_color = 1;
    this->back_color = back_color;

    if (this->ImageBuffer) {
        this->render_to_image_buffer();
    }

    this->set_active(1);
    this->set_redraw(1);
    if (this->parent_panel) {
        this->parent_panel->set_redraw(1);
    }
}
