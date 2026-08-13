#include <string.h>

// 004936D0 TribeEndScreen::TribeEndScreen
// Source: scr_end.cpp lines 34-116
// Binary-backed ownership: TScreenPanel ends at +0x478. The four child
// panels occupy +0x478 through +0x487. The constructor arguments are the
// title string and the text list passed to the text panel.
// Attempt log:
// - Baseline: restored the typed TScreenPanel hierarchy, the proven child
//   allocation sizes, the resolution background copy, the three panel setup
//   calls, the text-list virtual call, and the final child chain.
// - Probe 2: changed the resolution gate to render_area->width, matching the
//   original [this+0x20]+0x18 access; the natural source then matched exactly.

class TDrawArea {
public:
    char gap_00[0x18];
    long width;                         // +0x18
};
class TDigital;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, int);
    virtual void set_rect();
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void vslot_1c();
    virtual void vslot_20();
    virtual void vslot_24();
    virtual void vslot_28();
    virtual void vslot_2c();
    virtual void vslot_30();
    virtual void vslot_34();
    virtual void vslot_38();
    virtual void vslot_3c();
    virtual void vslot_40();
    virtual void vslot_44();
    virtual void vslot_48();
    virtual void vslot_4c();
    virtual void vslot_50();
    virtual void vslot_54();
    virtual void vslot_58();
    virtual void vslot_5c();
    virtual void vslot_60();
    virtual void vslot_64();
    virtual void vslot_68();
    virtual void vslot_6c();
    virtual void vslot_70();
    virtual void vslot_74();
    virtual void vslot_78();
    virtual void vslot_7c();
    virtual void vslot_80();
    virtual void vslot_84();
    virtual void vslot_88();
    virtual void vslot_8c();
    virtual void vslot_90();
    virtual void vslot_94();
    virtual void vslot_98();
    virtual void vslot_9c();
    virtual void vslot_a0();
    virtual void vslot_a4();
    virtual void vslot_a8();
    virtual void vslot_ac();
    virtual void vslot_b0();
    virtual void vslot_b4();
    virtual void vslot_b8();
    virtual void vslot_bc();
    virtual void vslot_c0();
    virtual void vslot_c4();
    virtual void vslot_c8();
    virtual void vslot_cc();
    virtual void vslot_d0();
    virtual void vslot_d4();
    virtual void vslot_d8();
    virtual void vslot_dc();
    virtual void set_text(char**, short);

    char gap_04[0x10];
    long width;                         // +0x14
    long height;                        // +0x18
    char gap_1c[4];
    TDrawArea* render_area;             // +0x20
    char gap_24[0xB4];
    int setup_error;                    // +0xD8
    char gap_dc[0x18];                   // sizeof(TPanel) == 0xF4

    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    char gap_f4[0x384];                  // sizeof(TEasy_Panel) == 0x478
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(TDrawArea* draw_area, char* info_file, long info_id, int param);
};

class TPicturePanel : public TPanel {
public:
    char gap_f4[0x28];                    // sizeof(TPicturePanel) == 0x11C
    TPicturePanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y,
               long width, long height, char* picture, long resource,
               int size_from_picture, int keep_loaded);
};

class TTextPanel : public TPanel {
public:
    char gap_f4[0x94];                    // sizeof(TTextPanel) == 0x188
    TTextPanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y,
               long width, long height, void* font, long font_width,
               long font_height, char* back_picture, int fill,
               unsigned char back_color, int outline,
               unsigned char outline_color, short fixed_len, char* text);
    void set_alignment(int vertical, int horizontal);
    void scroll(unsigned char mode, short line, int update);
};

class TButtonPanel : public TPanel {
public:
    char gap_f4[0x1A4];                   // through +0x298
    long hotkey;                          // +0x298
    long hotkey_shift;                    // +0x29C
    char gap_2a0[0x18];                   // sizeof(TButtonPanel) == 0x2B8
    TButtonPanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y,
               long width, long height, long draw_type, TDigital* sound,
               long notify_type, long button_id);
    void set_text_info(char* text, void* font, long font_width,
                       long font_height, long text_x, long text_y);
};

class RGE_Font {
public:
    void* font;
    long font_wid;
    long font_hgt;
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;
    RGE_Font* get_font(int index);
    TDigital* get_sound(int index);
};

extern RGE_Base_Game* rge_base_game;

class TribeEndScreen : public TScreenPanel {
public:
    TPicturePanel* background;             // +0x478
    TTextPanel* title;                     // +0x47C
    TTextPanel* text;                      // +0x480
    TButtonPanel* okButton;                // +0x484

    virtual ~TribeEndScreen();
    TribeEndScreen(char* title_text, char** text_list, int text_count);
};

TribeEndScreen::TribeEndScreen(char* title_text, char** text_list,
                               int text_count)
    : TScreenPanel((char*)"End Screen")
{
    char background_name[10];

    if (this->setup(rge_base_game->draw_area, 0, 0, 1) == 0) {
        this->setup_error = 1;
        return;
    }

    if (this->render_area->width < 0x320) {
        strcpy(background_name, "bgA640");
    } else if (this->render_area->width < 0x400) {
        strcpy(background_name, "bgA800");
    } else {
        strcpy(background_name, "bgA1024");
    }

    this->background = new TPicturePanel;
    if (this->background == 0) {
        this->setup_error = 1;
        return;
    }
    if (this->background->setup(this->render_area, this, 0, 0, 0, 0,
                                background_name, -1, 0, 1) == 0) {
        this->setup_error = 1;
        return;
    }

    this->background->set_positioning(
        2, 0, 0, 0, 0,
        this->width * 0x280 / 0x280,
        this->width * 0x280 / 0x280,
        this->height * 0x1E0 / 0x1E0,
        this->height * 0x1E0 / 0x1E0,
        0, 0, 0, 0);

    RGE_Font* font = rge_base_game->get_font(1);
    this->title = new TTextPanel;
    if (this->title == 0) {
        this->setup_error = 1;
        return;
    }
    this->title->setup(
        this->render_area, this->background,
        this->width * 0x14 / 0x280,
        this->height * 0x14 / 0x1E0,
        this->width * 600 / 0x280,
        this->height * 0x1E / 0x1E0,
        font->font, font->font_wid, font->font_hgt,
        0, 0, 0, 0, 0, 0, title_text);

    this->text = new TTextPanel;
    if (this->text == 0) {
        this->setup_error = 1;
        return;
    }
    font = rge_base_game->get_font(0x0B);
    this->text->setup(
        this->render_area, this->background,
        this->width * 0x14 / 0x280,
        this->height * 0x46 / 0x1E0,
        this->width * 600 / 0x280,
        this->height * 0x154 / 0x1E0,
        font->font, font->font_wid, font->font_hgt,
        0, 0, 0, 0, 0, 0, 0);
    this->text->set_text(text_list, (short)text_count);
    this->text->set_alignment(0, 0);
    this->text->scroll(6, 0, 1);

    TDigital* sound = rge_base_game->get_sound(0);
    font = rge_base_game->get_font(0);
    this->okButton = new TButtonPanel;
    if (this->okButton == 0) {
        this->setup_error = 1;
        return;
    }
    this->okButton->setup(
        this->render_area, this->background,
        this->width * 0xAA / 0x280,
        this->height * 0x1AE / 0x1E0,
        this->width * 300 / 0x280,
        this->height * 0x28 / 0x1E0,
        3, sound, 1, 0);
    this->okButton->set_text_info((char*)"OK", font->font,
                                  font->font_wid, font->font_hgt, -1, -1);

    this->set_curr_child(this->background);
    this->background->set_curr_child(this->text);
}
