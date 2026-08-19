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
// 11: current-session baseline rebuilt 568 B (not the stale prior 548 B report); calls and frame class match, but first mismatch is the pre-save x load.
// 12-16: direct/partial scaled-coordinate initializers and x-copy/in-place forms restore an early x read only with a one-slot EH frame; broad drift, rolled back.
// 17-18: moved sound declaration/zero initialization and tested a separate zero local; compiler basin remained broad or unchanged, rolled back.
// 19: joined failure/success through a typed result label; VC5 emitted the same split epilogues, rolled back.
// 20: branch-local null sound assignment plus direct sx initializer worsened the frame and structural diff, rolled back.
// 21: removed the artificial px alias and used x directly in sx; VC5 emitted the same code, kept the natural form.
// FLAGS: config/flags/00468530_create_button.rsp uses /GX because original has EH frame and default build is only 496 B/no EH.
// probe 37: an explicit ideal_x input and early button declaration were a codegen duplicate.
// probe 39: modeled the proven TPanel base and TButtonPanel inheritance; this moved the first mismatch to the post-setup font guard and cut positional diff to 256 bytes.
// probe 42: expressed font selection as two typed get_font branches; VC5 tail-merged the call and cut positional diff to 53 bytes.
// probe 43-44: common-result goto and nested positive guards were codegen duplicates; the remaining structural gap is the shared success/failure epilogue.
// Revisit pass: explicit fail/done labels, a result initializer, direct success/failure returns,
// the typed constructor result in the initial guard, direct output assignment from new, a declared
// TPanel constructor, and the period novtable annotation were all codegen duplicates. The clean
// typed source remains the 567-byte / 53-byte-diff basin: all 13 calls and the first 0x1CE bytes
// align, while VC5 still clones the success/failure /GX cleanup tail instead of the oracle's
// two-byte jump to one shared epilogue. Restore the natural source after each probe.
// Prior hold point: current best is 567 B with /GX, 53 positional diff bytes / 36 edit cost, 100% ordered calls, and 85.64% exact-block coverage. The remaining gap is the shared success/failure epilogue.
// ACCEPTED DRIFT: All factory work, field accesses, and 13 calls match. The
// rebuild clones equivalent success and failure EH epilogues. The failure
// store remains before cleanup. Each path restores the same SEH link,
// registers, stack, and return value. No call or external memory effect moves
// across the differing cleanup instructions.

typedef unsigned char uchar;

class TDrawArea;
class TDigital;
struct RGE_Font { void* font; int font_wid; int font_hgt; };

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x14 - 0x04];
    int width;
    int height;
    char gap_1C[4];
    TDrawArea* draw_area;
    char gap_24[0xD8 - 0x24];
    int failed;
    char gap_DC[0xF4 - 0xDC];
};

class RGE_Base_Game { public: TDigital* get_sound(int id); RGE_Font* get_font(int id); };
extern RGE_Base_Game* rge_base_game;

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x2B8 - 0xF4];
    TButtonPanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y, long w, long h, int draw_text, TDigital* sound, int notify_action, long user);
    void set_sound_number(long sound_id);
    void set_text_info(char* text, void* font, int font_wid, int font_hgt, int a, int b);
    void set_text(short mode, char* text);
    void set_bevel_info(int mode, int c1, int c2, int c3, int c4, int c5, int c6);
    void set_text_color(int index, int c1, int c2);
    void set_highlight_text_color(int index, int c1, int c2);
};

class TEasy_Panel : public TPanel {
public:
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

    virtual int create_button(TPanel* panel, TButtonPanel** out, char* text, char* label, long x, long y, long w, long h, long font_id, long sound_id, long user);
};

int TEasy_Panel::create_button(TPanel* panel, TButtonPanel** out, char* text, char* label, long x, long y, long w, long h, long font_id, long sound_id, long user)
{
    TDigital* sound;
    long sx;
    long sy;
    long sw;
    long sh;
    int i;

    sound = 0;
    sx = (x * this->width) / this->ideal_width;
    sy = (y * this->height) / this->ideal_height;
    sw = (w * this->width) / this->ideal_width;
    sh = (h * this->height) / this->ideal_height;

    TButtonPanel* button = new TButtonPanel;
    *out = button;
    if (*out != 0 && (*out)->failed == 0) {
        if (sound_id >= 0) {
            sound = rge_base_game->get_sound(sound_id);
        }

        if ((*out)->setup(this->draw_area, panel, sx, sy, sw, sh, 3, sound, 1, user) != 0) {
            (*out)->set_sound_number(sound_id);
            RGE_Font* font;
            if (font_id >= 0) {
                font = rge_base_game->get_font(font_id);
            } else {
                font = rge_base_game->get_font(10);
            }
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
            i = 1;
        } else {
            this->failed = 1;
            i = 0;
        }
    } else {
        this->failed = 1;
        i = 0;
    }
    return i;
}
