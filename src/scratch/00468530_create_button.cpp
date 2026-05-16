// VA: 00468530 TEasy_Panel::create_button
// Attempt log:
// 1: natural reconstruction from packet/decompiler with TButtonPanel new/ctor and EH context.
// 2: removed explicit operator new declaration due VC header/linkage conflict.
// 3: tested slug /GX flags: enables EH and exact 548 B size, but broad 78.1% diff; kept as required context because original has EH frame.
// 4: fixed TButtonPanel local stub size from accidental 0xDC to proven 0x2B8 new size; size unchanged under EH but allocation immediate now semantically correct.
// 5: rewrote post-construction uses through `*out` to try matching original EBX=out/reload [EBX] topology; edit diff improved substantially, positional still broad.
// 6: initialized sound local before scaling and reused it in negative-sound branch to try forcing original second EH local / `sub esp,8`; improved to 50.7% positional / 20.3% edit diff.
// 7: introduced px copy of x before scaling to try matching original pre-register-save load of param_5 into EAX; optimized away/no change.
// 8: tried volatile sx initialized from x; forced early load but worsened frame to one local and moved allocation later; rolled back.
// 9: tried /O2 /GX without /Oy; unchanged from best.
// 10: tried /Ob0 with /GX; unchanged.
// FLAGS: config/flags/00468530_create_button.rsp uses /GX because original has EH frame and default build is only 496 B/no EH.
// Left in scratch: current best is same-size 548 B with /GX, improved edit diff after sound local and *out topology, but still broad 50.7% positional diff from early scheduling/stack-slot differences and downstream register allocation. Not accepted_drift-safe.

typedef unsigned char uchar;

class TPanel;
class TDrawArea;
class TDigital;
struct RGE_Font { void* font; int font_wid; int font_hgt; };

class RGE_Base_Game { public: TDigital* get_sound(int id); RGE_Font* get_font(int id); };
extern RGE_Base_Game* rge_base_game;

class TButtonPanel {
public:
    char gap_00[0xD8];
    int failed;
    char gap_DC[0x2B8 - 0xDC];
    TButtonPanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y, long w, long h, int draw_text, TDigital* sound, int notify_action, long user);
    void set_sound_number(long sound_id);
    void set_text_info(char* text, void* font, int font_wid, int font_hgt, int a, int b);
    void set_text(short mode, char* text);
    void set_bevel_info(int mode, int c1, int c2, int c3, int c4, int c5, int c6);
    void set_text_color(int index, int c1, int c2);
    void set_highlight_text_color(int index, int c1, int c2);
};

class TEasy_Panel {
public:
    char gap_00[0x14];
    int width;
    int height;
    char gap_1C[4];
    TDrawArea* draw_area;
    char gap_24[0xD8 - 0x24];
    int failed;
    char gap_DC[0xF4 - 0xDC];
    int ideal_width;
    int ideal_height;
    char gap_FC[0x31C - 0xFC];
    int use_bevels;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    char gap_326[2];
    int text_color1;
    int text_color2;
    int focus_color1;
    int focus_color2;
    int state_color1;
    int state_color2;

    int create_button(TPanel* panel, TButtonPanel** out, char* text, char* label, long x, long y, long w, long h, long font_id, long sound_id, long user);
};

int TEasy_Panel::create_button(TPanel* panel, TButtonPanel** out, char* text, char* label, long x, long y, long w, long h, long font_id, long sound_id, long user)
{
    TDigital* sound;
    long sx;
    long sy;
    long sw;
    long sh;
    int i;
    long px;

    px = x;
    sound = 0;
    sx = (px * this->width) / this->ideal_width;
    sy = (y * this->height) / this->ideal_height;
    sw = (w * this->width) / this->ideal_width;
    sh = (h * this->height) / this->ideal_height;

    TButtonPanel* button = new TButtonPanel;
    *out = button;
    if (*out == 0 || (*out)->failed != 0) {
        this->failed = 1;
        return 0;
    }

    if (sound_id >= 0) {
        sound = rge_base_game->get_sound(sound_id);
    }

    if ((*out)->setup(this->draw_area, panel, sx, sy, sw, sh, 3, sound, 1, user) == 0) {
        this->failed = 1;
        return 0;
    }

    (*out)->set_sound_number(sound_id);
    if (font_id < 0) {
        font_id = 10;
    }
    RGE_Font* font = rge_base_game->get_font(font_id);
    (*out)->set_text_info(text, font->font, font->font_wid, font->font_hgt, -1, -1);
    if (label != 0) {
        (*out)->set_text(1, label);
    }
    if (this->use_bevels != 0) {
        (*out)->set_bevel_info(4, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
    }
    i = 0;
    do {
        (*out)->set_text_color(i, this->text_color1, this->text_color2);
        (*out)->set_highlight_text_color(i, this->focus_color1, this->focus_color2);
        ++i;
    } while (i < 9);
    (*out)->set_text_color(1, this->state_color1, this->state_color2);
    (*out)->set_highlight_text_color(1, this->focus_color1, this->focus_color2);
    return 1;
}
