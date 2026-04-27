// first pass: direct reconstruction from packet; keep typed panel surface local
extern "C" int strncmp(const char*, const char*, unsigned int);
extern "C" char* strncpy(char*, const char*, unsigned int);
long debug_timeGetTime(const char* file, int line);

class TPanel {
public:
    virtual void pv0();
    virtual void pv1();
    virtual void pv2();
    virtual void pv3();
    virtual void pv4();
    virtual void pv5(int);
    virtual void pv6();
    virtual void pv7();
    virtual void pv8(int);

    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0x9C];
    int field_E0;
    char gap_E4[0x10];
};

class TMessagePanel : public TPanel {
public:
    int message_type;
    char text[0x200];
    int field_2F8;
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
    void show_message(int message_type, char* text, unsigned char font_color, unsigned char back_color, void* font, long font_wid, long font_hgt);
};

void TMessagePanel::show_message(int message_type, char* text, unsigned char font_color, unsigned char back_color, void* font, long font_wid, long font_hgt) {
    if (this->field_2F8 && this->message_type == message_type && strncmp(text, this->text, 0x1ff) == 0) {
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
    this->field_E0++;
    this->field_2F8 = 1;
    this->start_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp", 0x9e);
    this->font_color = font_color;
    this->index_color = 1;
    this->back_color = back_color;

    if (this->ImageBuffer) {
        this->render_to_image_buffer();
    }

    this->pv5(1);
    this->pv8(1);
    if (this->parent_panel) {
        this->parent_panel->pv8(1);
    }
}
