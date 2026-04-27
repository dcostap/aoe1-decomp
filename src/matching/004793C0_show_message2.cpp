// first pass: mirrors show_message with the extra icon/frame/color state
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
    int showing_message;
    int start_time;
    int show_message_interval;
    void* font;
    long font_wid;
    long font_hgt;
    char gap_310[4];
    int index_color;
    unsigned long font_color1;
    unsigned long font_color2;
    char gap_320[0x10];
    void* ImageBuffer;
    char gap_334[0x3C];
    void* Icon1;
    void* Icon2;
    int IconFrame1;
    int IconFrame2;

    void render_to_image_buffer();
    void show_message2(int message_type, char* text, unsigned long font_color1, unsigned long font_color2, void* font, long font_wid, long font_hgt, void* Icon1, int IconFrame1, void* Icon2, int IconFrame2);
};

void TMessagePanel::show_message2(int message_type, char* text, unsigned long font_color1, unsigned long font_color2, void* font, long font_wid, long font_hgt, void* Icon1, int IconFrame1, void* Icon2, int IconFrame2) {
    if (this->showing_message && this->message_type == message_type && strncmp(text, this->text, 0x1ff) == 0) {
        if (font == 0 || font == this->font) {
            if (this->Icon1 == Icon1 && this->Icon2 == Icon2 && this->IconFrame1 == IconFrame1 && this->IconFrame2 == IconFrame2) {
                return;
            }
        }
    }

    if (font != 0) {
        this->font = font;
        this->font_wid = font_wid;
        this->font_hgt = font_hgt;
    }

    this->message_type = message_type;
    this->Icon1 = Icon1;
    this->IconFrame1 = IconFrame1;
    this->IconFrame2 = IconFrame2;
    this->Icon2 = Icon2;

    for (int i = 0; i < 0x200; ++i) {
        this->text[i] = 0;
    }
    strncpy(this->text, text, 0x1ff);
    this->field_E0++;
    this->showing_message = 1;
    this->start_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp", 0xd3);
    this->font_color1 = font_color1;
    this->index_color = 0;
    this->font_color2 = font_color2;

    if (this->ImageBuffer) {
        this->render_to_image_buffer();
    }

    this->pv5(1);
    this->pv8(1);
    if (this->parent_panel) {
        this->parent_panel->pv8(1);
    }
}
