// VA: 004B75A0 TribeSelectTribeScreen ctor (2085B)
// scr_trb.cpp lines 37-157
// Baseline: reconstructed the TScreenPanel child-panel creation sequence from
// the original call order and proven panel sizes. /GX is required by the EH
// cleanup frame around the constructor's new expressions.
// Probe 2: used the draw-area width for background selection; improved the
// first structural hunk.
// Probe 3: kept that width in a local; recovered the original load/compare.
// Probe 4: selected one background string and copied it once; improved size.
// Probe 5: used the original negative resolution test; duplicate codegen.
// Probe 6: used direct branch-local copies; improved the copy block.
// Probe 7: restored panel sizes 0x11C, 0x188, and 0x2B8.
// Probe 8: reused this->render_area for child setup; improved 642 bytes.
// Probe 9: carried background in a local through positioning; improved 70.
// Probe 10: reordered loop initialization; improved 5 bytes.
// Main-agent ABI audit restored the canonical rge_base_game global and the
// short set_tab_order count. Calls remain aligned; positional diff improved by one byte.
// Best unresolved source: all 34 calls and CFG match, frame is 0x54, but the
// constructor remains 81 bytes too large. The remaining drift starts at the
// button-loop setup and later local/register scheduling.

#include <string.h>

class TDrawArea {
public:
    char gap_00[0x18];
    int width;                         // +0x18
};
class TDigital;
class TPanel;
class TTextPanel;
class TButtonPanel;
class TPicturePanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup();
    virtual void set_rect();
    virtual void set_rect2();
    virtual void set_color();
    virtual void set_active(int active);
    virtual void set_positioning(long mode, long a2, long a3, long a4,
                                 long a5, long a6, long a7, long a8,
                                 long a9, TPanel* a10, TPanel* a11,
                                 TPanel* a12, TPanel* a13);

    char gap_04[0x8];
    long pnl_x;                       // +0x0C
    long pnl_y;                       // +0x10
    long pnl_wid;                     // +0x14
    long pnl_hgt;                     // +0x18
    char gap_1C[4];
    TDrawArea* render_area;            // +0x20
    char gap_24[0xB4];
    int setup_error;                 // +0xD8
    char gap_DC[0x18];               // sizeof(TPanel) == 0xF4

    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** panels, short count);
};

class TPicturePanel : public TPanel {
public:
    char gap_F4[0x28];             // sizeof(TPicturePanel) == 0x11C
    TPicturePanel();
    long setup(TDrawArea* draw, TPanel* parent, long x, long y,
               long width, long height, char* picture, long resource,
               int size_from_picture, int keep_loaded);
};

class RGE_Font {
public:
    void* font;
    int font_wid;
    int font_hgt;
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x94];             // sizeof(TTextPanel) == 0x188
    TTextPanel();
    long setup(TDrawArea* draw, TPanel* parent, long x, long y,
               long width, long height, void* font, long font_wid,
               long font_hgt, char* back_picture, int fill,
               unsigned char back_color, int outline,
               unsigned char outline_color, short fixed_len, char* text);
    void set_alignment(int vertical, int horizontal);
};

class TButtonPanel : public TPanel {
public:
    TButtonPanel();
    char gap_F4[0x1A4];
    long hotkey;                     // +0x298
    long hotkey_shift;               // +0x29C
    char gap_2A0[0x18];               // sizeof(TButtonPanel) == 0x2B8

    long setup(TDrawArea* draw, TPanel* parent, long x, long y,
               long width, long height, long draw_type, TDigital* sound,
               long notify_type, long button_id);
    void set_text_info(char* text, void* font, long font_wid,
                       long font_hgt, long x, long y);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];              // sizeof(TEasy_Panel) == 0x478
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(TDrawArea* draw, char* text, long id, int value);
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;
    RGE_Font* get_font(int index);
    TDigital* get_sound(int index);
};

extern RGE_Base_Game* rge_base_game;

extern int __stdcall DrawTextA(void*, const char*, int, void*, unsigned int);

enum { NotifyAction = 1 };

class TribeSelectTribeScreen : public TScreenPanel {
public:
    TPicturePanel* background;        // +0x478
    TTextPanel* title;                // +0x47C
    TTextPanel* tribeText;            // +0x480
    TButtonPanel* tribeButton[9];     // +0x484
    TButtonPanel* okButton;           // +0x4A8
    TButtonPanel* cancelButton;       // +0x4AC
    char** screenText;                // +0x4B0
    int numLines;                     // +0x4B4

    virtual ~TribeSelectTribeScreen();
    TribeSelectTribeScreen();
    char* tribeName(int index);
    void fillTribeText(int index);
};

TribeSelectTribeScreen::TribeSelectTribeScreen()
    : TScreenPanel("Select Tribe Screen")
{
    char backgroundName[10];
    TPanel* tabList[10];
    RGE_Font* font;
    TDigital* buttonSound;
    int secondWidth;
    int secondHeight;
    int i;
    int width;
    TPicturePanel* backgroundPanel;

    this->screenText = 0;

    if (this->setup(rge_base_game->draw_area, 0, 0, 1) == 0) {
        this->setup_error = 1;
        return;
    }

    width = this->render_area->width;
    if (width < 0x320) {
        strcpy(backgroundName, "bgA640");
    } else {
        if (width < 0x400) {
            strcpy(backgroundName, "bgA800");
        } else {
            strcpy(backgroundName, "bgA1024");
        }
    }

    this->background = new TPicturePanel;
    if (this->background == 0) {
        this->setup_error = 1;
        return;
    }
    if (this->background->setup(this->render_area, this, 0, 0,
                                0, 0, backgroundName, -1, 0, 1) == 0) {
        this->setup_error = 1;
        return;
    }

    backgroundPanel = this->background;
    secondHeight = this->pnl_hgt * 0x1E0 / 0x1E0;
    secondWidth = this->pnl_wid * 0x280 / 0x280;
    backgroundPanel->set_positioning(
        2, 0, 0, 0, 0, secondWidth, secondWidth,
        secondHeight, secondHeight, 0, 0, 0, 0);

    font = rge_base_game->get_font(1);
    this->title = new TTextPanel;
    if (this->title == 0) {
        this->setup_error = 1;
        return;
    }
    this->title->setup(
        this->render_area, this->background,
        this->pnl_wid * 0x14 / 0x280,
        this->pnl_hgt * 0x14 / 0x1E0,
        this->pnl_wid * 600 / 0x280,
        this->pnl_hgt * 0x1E / 0x1E0,
        font->font, font->font_wid, font->font_hgt,
        0, 0, 0, 0, 0, 0, "Civilization Selection");

    buttonSound = rge_base_game->get_sound(0);
    font = rge_base_game->get_font(0);
    secondWidth = 0;
    secondHeight = 0;
    i = 0;
    TButtonPanel** button = this->tribeButton;

    do {
        *button = new TButtonPanel;
        if (*button == 0) {
            this->setup_error = 1;
            return;
        }

        (*button)->setup(
            this->render_area, this->background,
            this->pnl_wid * 0x14 / 0x280 + secondWidth * this->pnl_wid / 0x280,
            this->pnl_hgt * 0x32 / 0x1E0 +
                secondHeight * this->pnl_hgt * 0x73 / 0x1E0,
            this->pnl_wid * 200 / 0x280,
            this->pnl_hgt * 0x6E / 0x1E0,
            (long)&DrawTextA, buttonSound, NotifyAction, 0);
        (*button)->set_text_info(this->tribeName(i), font->font,
                                 font->font_wid, font->font_hgt, -1, -1);

        if (i == 2 || i == 5) {
            secondHeight = -1;
            secondWidth += 200;
        }
        ++i;
        ++button;
        ++secondHeight;
    } while (i < 9);

    font = rge_base_game->get_font(0xB);
    this->tribeText = new TTextPanel;
    if (this->tribeText == 0) {
        this->setup_error = 1;
        return;
    }
    this->tribeText->setup(
        this->render_area, this->background,
        this->pnl_wid * 0x14 / 0x280,
        this->pnl_hgt * 400 / 0x1E0,
        this->pnl_wid * 0x1FE / 0x280,
        this->pnl_hgt * 0x3C / 0x1E0,
        font->font, font->font_wid, font->font_hgt,
        0, 0, 0, 0, 0, 0, "");
    this->tribeText->set_alignment(6, 0);

    this->okButton = new TButtonPanel;
    if (this->okButton == 0) {
        this->setup_error = 1;
        return;
    }
    this->okButton->setup(
        this->render_area, this->background,
        this->pnl_wid * 500 / 0x280,
        this->pnl_hgt * 400 / 0x1E0,
        this->pnl_wid * 0x78 / 0x280,
        this->pnl_hgt * 0x1E / 0x1E0,
        (long)&DrawTextA, buttonSound, NotifyAction, 0);
    this->okButton->set_text_info("Previous Screen", font->font,
                                  font->font_wid, font->font_hgt, -1, -1);

    this->cancelButton = new TButtonPanel;
    if (this->cancelButton == 0) {
        this->setup_error = 1;
        return;
    }
    this->cancelButton->setup(
        this->render_area, this->background,
        this->pnl_wid * 500 / 0x280,
        this->pnl_hgt * 0x1B8 / 0x1E0,
        this->pnl_wid * 0x78 / 0x280,
        this->pnl_hgt * 0x1E / 0x1E0,
        (long)&DrawTextA, buttonSound, NotifyAction, 0);
    this->cancelButton->set_text_info("Cancel", font->font,
                                      font->font_wid, font->font_hgt, -1, -1);

    this->set_curr_child(this->background);
    this->background->set_curr_child(this->tribeButton[0]);
    this->fillTribeText(0);

    tabList[0] = this->tribeButton[0];
    tabList[1] = this->tribeButton[1];
    tabList[2] = this->tribeButton[2];
    tabList[3] = this->tribeButton[3];
    tabList[4] = this->tribeButton[4];
    tabList[5] = this->tribeButton[5];
    tabList[6] = this->tribeButton[6];
    tabList[7] = this->tribeButton[7];
    tabList[8] = this->tribeButton[8];
    tabList[9] = this->okButton;
    this->set_tab_order(tabList, 10);
}
