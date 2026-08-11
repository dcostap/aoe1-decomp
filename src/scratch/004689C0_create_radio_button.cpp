// 004689C0 TEasy_Panel::create_radio_button(...)
// Source: Panel_ez.cpp lines 1158-1209
// FLAGS: config/flags/004689C0_create_radio_button.rsp
// Attempt log:
// - Initial natural source from packet/decompiler.
// - Added /GX flag because original has VC5 EH registration around operator new + TButtonPanel ctor.
// - Corrected TEasy_Panel local layout so ideal_width/height are +0x14/+0x18 and draw_area +0x20; first attempt had a hidden-vptr gap and shifted those fields.
// - Tried moving `new TButtonPanel` before vs after coordinate scaling. Allocating after scaling gives closer arithmetic order, but EH prologue changes to FS load before EH pushes; allocating before scaling keeps EH order closer but arithmetic/register allocation worse.
// - Modeled the proven TButtonPanel allocation size as 0x2B8 and initialized sound before the scaling/new path; this improved the resynchronized body but still emitted a one-slot local and the wrong prologue family.
// - Tried explicit ideal-x initialization/compound arithmetic, x capture, a nontrivial destructor declaration, direct out-slot construction, and a common result/goto tail; these emitted the same or farther codegen basin.
// - Final clean candidate keeps the named field ownership and natural direct factory source. Remaining blocker is structural VC5 EH/local-home placement: original reserves 8 bytes, preloads x before callee-save pushes, and shares one success/failure epilogue; rebuilt reserves one slot, reloads x from its parameter home, and duplicates cleanup. No accepted_drift proposal; no inline asm.

class TPanel;
class TDrawArea;
class TShape;
class TDigital;

class RGE_Font { public: int font; int font_wid; int font_hgt; };
class RGE_Base_Game {
public:
    TDigital* get_sound(int id);
    RGE_Font* get_font(int id);
};
extern RGE_Base_Game* rge_base_game;

static char s_space[] = " ";
static char s_X[] = "X";

class TButtonPanel {
public:
    char gap_000[0xD8];
    int error;
    char gap_DC[0x2B8 - 0xDC];
    TButtonPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, int, TDigital*, int, long);
    void setDrawType(int t);
    void set_text_info(char*, int, int, int, int, int);
    void set_text(short, char*);
    void set_picture(short, TShape*, int);
    void set_sound_number(int);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_text_color(int, int, int);
    void set_highlight_text_color(int, int, int);
};

class TEasy_Panel {
public:
    char gap_000[0x10];
    int ideal_width;
    int ideal_height;
    char gap_01C[0x20 - 0x1C];
    TDrawArea* draw_area;
    char gap_024[0xD8 - 0x24];
    int error;
    char gap_0DC[0xF4 - 0xDC];
    int screen_width;
    int screen_height;
    char gap_0FC[0x31C - 0x0FC];
    int use_bevels;
    unsigned char bevel_color1, bevel_color2, bevel_color3, bevel_color4, bevel_color5, bevel_color6;
    char gap_326[0x328 - 0x326];
    int text_color1;
    int text_color2;
    int focus_color1;
    int focus_color2;
    int state_color1;
    int state_color2;
    char gap_340[0x448 - 0x340];
    TShape* button_pics;

    virtual int create_radio_button(TPanel* parent, TButtonPanel** out, long x, long y, long w, long h, long sound, long param8);
};

int TEasy_Panel::create_radio_button(TPanel* parent, TButtonPanel** out, long x, long y, long w, long h, long sound_id, long param8)
{
    TDigital* sound = 0;
    long sx = (x * this->ideal_width) / this->screen_width;

    y = (y * this->ideal_height) / this->screen_height;
    w = (w * this->ideal_width) / this->screen_width;
    h = (h * this->ideal_height) / this->screen_height;

    *out = new TButtonPanel;
    if (*out == 0 || (*out)->error != 0) {
        this->error = 1;
        return 0;
    }

    if (sound_id >= 0) {
        sound = rge_base_game->get_sound(sound_id);
    }

    if (!(*out)->setup(this->draw_area, parent, sx, y, w, h, 2, sound, 1, param8)) {
        this->error = 1;
        return 0;
    }
    (*out)->set_sound_number(sound_id);

    if (this->button_pics != 0) {
        (*out)->setDrawType(6);
        (*out)->set_picture(0, this->button_pics, 4);
        (*out)->set_picture(1, this->button_pics, 6);
    }
    else {
        RGE_Font* font;
        (*out)->setDrawType(3);
        font = rge_base_game->get_font(0);
        (*out)->set_text_info(s_space, font->font, font->font_wid, font->font_hgt, -1, -1);
        (*out)->set_text(1, s_X);
    }

    if (this->use_bevels != 0) {
        (*out)->set_bevel_info(4, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
    }
    (*out)->set_text_color(0, this->text_color1, this->text_color2);
    (*out)->set_highlight_text_color(0, this->focus_color1, this->focus_color2);
    (*out)->set_text_color(1, this->state_color1, this->state_color2);
    (*out)->set_highlight_text_color(1, this->focus_color1, this->focus_color2);
    return 1;
}
