// VA: 004696B0 TEasy_Panel::create_list
// Source: Panel_ez.cpp lines 1540-1610
// Attempt log:
// 1: initial reconstruction from packet/decompiler with /GX candidate EH for TListPanel construction cleanup.
// 2: switched placement-new to real `new TListPanel`; EH prologue appears but only one local slot and this in esi.
// 3: added explicit temp local and self register; worsened scheduling and did not produce sub esp,8/ebx=this, rolled back.
// 4: changed calloc call argument order to source `calloc(4,1)`; negligible edit improvement but original pushes 4 then 1, keep.
// 5: changed second calloc source to `calloc(1,0x14)`; no improvement, rolled back.
// 6: replaced manual empty-string copy with strcpy; positional worse and removes original rep movs, rolled back.
// 7: declared explicit operator new surface and used `new TListPanel`; EH appears but function remains 32 bytes short.
// 8: first allocation `calloc(4,1)` kept because it slightly improves edit diff and still allocates 4 bytes.
// 9: remaining first mismatch is EH handler address relocation area/prologue: rebuilt has EH but uses one local (`push ecx`) and this in esi; original has `sub esp,8`, this in ebx, and stores intermediate scaled values in stack slots.
// 10: left in scratch: behavior/calls mostly understood, but local/register allocation and cleanup/return layout remain broad; not accepted_drift-safe.
// 11: restored the period TPanel base layout and derived TEasy_Panel/TTextPanel
// surfaces.  The prior flat stubs placed error and ideal-size fields four bytes
// early and made the list allocation 0xDC instead of the proven 0x1A0.
// 12: corrected coordinate ownership to TPanel width/height (+14/+18) scaled
// by TEasy_Panel ideal dimensions (+F4/+F8).  The old names used the ideal
// fields as numerators and fabricated screen dimensions.  Also let font_id
// remain the direct parameter for both observed get_font calls.
// 13: keep the output slot in a named local alias across allocation and setup;
// the oracle loads the out parameter before new and carries it in EDI.
// 14: diagnostic only: make ideal_y volatile to test whether the oracle's
// distinct second coordinate stack slot is a real lifetime rather than a
// compiler-reused parameter home.
// 15: diagnostic only: extend that test to ideal_x so both coordinate results
// require durable local storage.
// 16: rolled back both volatile coordinate locals and the no-op output alias;
// neither reached the oracle frame or register topology.
// 17: retained /GX after testing the explicit EH frame.  Without it, VC5
// removes the EH registration and emits a 558-byte non-period function.
// 18: split the first-hunk coordinate declarations from their initializers;
// no emitted-code movement, so restored the initializer form.
// 19: replaced the manual bevel vtable expression with the proven TTextPanel
// slot-59 virtual surface.  This removes the explicit this push and aligns
// the vslot +0xEC call; the full TPanel slot surface is local to this TU.
// 20: restored the oracle's inline empty-string copy with VC5 intrinsic strcpy
// and the proven literal at 0x580460.  The rep scas/movsd/movsb block now
// matches structurally; the declaration was moved before the pragma to avoid
// the intrinsic warning.
// 21: a synthetic scaled-coordinate aggregate improved stack homes, but it
// is not a plausible source surface. Keep ordinary scalar coordinates.
// The scalar form loses the exact frame and worsens the byte metrics. It is
// still retained because its local ownership is source-plausible.

typedef unsigned long ulong;
typedef unsigned int uint;

extern "C" char* __cdecl strcpy(char* dst, const char* src);
#pragma intrinsic(strcpy)
extern "C" void* __cdecl calloc(uint count, uint size);
extern "C" void __cdecl free(void* p);
extern "C" void* __cdecl operator_new(uint size);

class RGE_Font { public: int font; int font_wid; int font_hgt; };
class RGE_Base_Game { public: RGE_Font* get_font(int id); };
extern RGE_Base_Game* rge_base_game;

class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long,
                                  TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(void*);
    virtual void draw_offset(long, long, void*);
    virtual void draw_rect2(void*);
    virtual void draw_offset2(long, long, void*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(void*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    char gap_04[0x10];
    int width;
    int height;
    char gap_1C[4];
    TDrawArea* draw_area;
    char gap_24[0xB4];
    int error;
    char gap_DC[0x18];
};
class TDrawArea {};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    char gap_F4[0x188 - 0xF4];
    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h, int font, int font_wid, int font_hgt, char* text, int a, unsigned char b, int c, int d, int e, char** lines, int f);
    void set_text_color(ulong a, ulong b);
    void set_highlight_text_color(ulong a, ulong b);
};

class TListPanel : public TTextPanel {
public:
    char gap_188[0x1A0 - 0x188];
    TListPanel();
    void scroll_cur_line(unsigned char a, int b, unsigned char c);
};

class TEasy_Panel : public TPanel {
public:
    int ideal_width;
    int ideal_height;
    char gap_FC[0x31C - 0xFC];
    int use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char gap_326[2];
    ulong text_color1;
    ulong text_color2;
    ulong focus_color1;
    ulong focus_color2;

    virtual int create_list(TPanel* parent, TListPanel** out, long x, long y, long w, long h, long font_id);
};

int TEasy_Panel::create_list(TPanel* parent, TListPanel** out, long x, long y, long w, long h, long font_id)
{
    long ideal_x = (x * this->width) / this->ideal_width;
    long ideal_y = (y * this->height) / this->ideal_height;
    char** list_items;

    w = (w * this->width) / this->ideal_width;
    h = (h * this->height) / this->ideal_height;

    if (font_id >= 0) {
        rge_base_game->get_font(font_id);
    } else {
        rge_base_game->get_font(10);
    }

    list_items = (char**)calloc(4, 1);
    if (list_items == 0) {
        this->error = 1;
        return 0;
    }
    list_items[0] = (char*)calloc(0x14, 1);
    if (list_items[0] == 0) {
        goto cleanup_fail;
    }
    strcpy(list_items[0], "");

    if (this->error == 0) {
        TListPanel* list = new TListPanel;
        *out = list;
        if (list != 0 && list->error == 0) {
            RGE_Font* font = rge_base_game->get_font(font_id);
            if ((*out)->setup(this->draw_area, parent, ideal_x, ideal_y, w, h, font->font, font->font_wid, font->font_hgt, 0, 0, 0, 1, 0xFF, 0, list_items, 1) != 0) {
                (*out)->scroll_cur_line(1, 0, 1);
                goto cleanup_success;
            }
        }
        this->error = 1;
    }

cleanup_success:
    {
        int n = 1;
        char** p = list_items;
        do {
            if (*p != 0) {
                free(*p);
                *p = 0;
            }
            ++p;
            --n;
        } while (n != 0);
    }
    free(list_items);
    if (this->use_bevels != 0) {
        TListPanel* list = *out;
        list->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
    }
    (*out)->set_text_color(this->text_color1, this->text_color2);
    (*out)->set_highlight_text_color(this->focus_color1, this->focus_color2);
    return 1;

cleanup_fail:
    return 0;
}
