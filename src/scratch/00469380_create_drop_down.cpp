// 00469380 TEasy_Panel::create_drop_down
// Attempt log:
// 1: natural reconstruction from packet with EH/new ctor and TDropDownPanel member calls.
// 2: modeled scaled coordinate math exactly from asm: param*width/ideal_width and param*height/ideal_height, plus width*18/ideal_width.
// 3: modeled negative font id fallback to 10 and rge_base_game->get_font calls at both observed sites.
// 4: modeled calloc(1,4), calloc(0x14,1), copy of the single-space literal, and cleanup free loop.
// 5: modeled operator_new(0x144) + placement constructor; VC5 needed a local placement-new declaration to compile.
// 6: tried /GX response file because original has EH registration; no improvement, object .text still too short for extraction, removed flag.
// 7: modeled TDropDownPanel setup argument list in observed push order from decompiler/asm.
// 8: modeled optional set_buttons, set_bevel_info, val/list text color, highlight color, and val_panel virtual bevel call.
// 9: current source compiles but produced .text section only 736B vs configured/original 811B; check_function cannot diff rebuilt bytes.
// 10: left in scratch as blocker-like scratch give-up: source is structurally close but needs real EH/context/call surface to reach original size; not accepted_drift.
// 11: replaced the placement-new/byte-copy scaffolding with the natural new/
// strcpy surfaces and a virtual TPanel/TDropDownPanel ownership model; testing
// whether the real destructible type supplies the original EH state.
// 12: restored the binary-proven one-element do/while cleanup instead of
// hand-written if cleanup; the original retains a countdown and cursor.
// 13: route first calloc failure through the existing cleanup label; the
// original has one shared cleanup/SEH epilogue rather than an early return.
// 14: kept the ignored initial font lookup as two natural branch arms; this
// tests the original jl/push-font/jmp-call topology instead of a rewritten id.
// 15: inverted that equivalent guard so the nonnegative source arm remains
// inline and the negative fallback is the late branch target.
// 16: /GX plus the typed virtual/destructible surface recovered the original
// EH prologue, frame, call set, and body; the final stdlib-context check was
// neutral. Best current output is exact size with 21 strict bytes remaining:
// early leak exits target the result epilogue differently, and the final free
// cleanup schedules stack restoration before the failure/result load.
// 17: direct allocation-failure returns duplicated the EH epilogue and grew
// the function by 33 bytes; restored the shared leak exits.
// 18: a natural initialized result local also duplicated the epilogue and
// grew the frame; carrying the second calloc value had the same blocker.
// 19: negated and ternary failure predicates emitted the unchanged 21-byte
// tail; restored the clean == 0 spelling.
// 20: localized direct return after final free, suggested by the original
// delayed stack cleanup; emitted code was unchanged and the clean form remains authoritative.
// 21: split the cleanup success return from the early zero finish; /GX duplicated
// the EH epilogue and grew 33 bytes, so restored the shared finish.
// 22: a pointer result carrier emitted the same 844-byte basin; restored.
// 23: a comma return deferred the failure load past free but changed loop and
// argument scheduling and left sete after EH restore; restored.
// 24: an unsigned-byte result changed the frame to 0xC and emitted 837 bytes;
// restored.
// 25: a register-qualified result duplicated the 844-byte basin; restored.
// 26: reusing the list home as the result changed the null branch and emitted
// 826 bytes; restored. Clean source remains the best reconstruction.
// 27: decompiler-style result carrier with explicit zero on first calloc
// failure changed the early branch and emitted 815 bytes / 556-byte diff.
// 28: split carrier/list declarations produced the same codegen duplicate.
// 29: comma-wrapped final free moved cleanup-loop scheduling and emitted 813
// bytes / 70-byte diff; restored.
// 30: a late char* result carrier moved the failure load before stack cleanup,
// but spilled the setcc and emitted 819 bytes / 32-byte diff.
// 31: register-qualified late char* and late int carriers were duplicates.
// 32: split success return from the early finish duplicated EH cleanup and
// emitted 844 bytes / 607-byte diff; restored.
// 33: function-scope uninitialized int carrier duplicated the 32-byte basin.
// 34: function-scope char* carrier assigned directly from second calloc was
// a codegen duplicate of the clean 21-byte basin; restored.
// 35: direct return only on the second calloc failure grew the function by
// 17 bytes and duplicated the EH return path; restored the clean goto form.
// 36: restored canonical TEasy_Panel inheritance over the proven TPanel layout;
// VC5 emits the same 21-byte tail mismatch as the flattened equivalent.
// 37: restored the original second-calloc failure behavior with a natural
// return 0; the outer list allocation is intentionally leaked. VC5 grows the
// function by 17 bytes and duplicates the EH return path, but the behavior is
// correct and takes priority over the closer clean-source codegen.
// 38: changed the second-calloc failure to goto the shared result epilogue;
// this restores the oracle's 811-byte size, one return, and exact call set.
// 39-41: comma, logical-not, and ternary result spellings are codegen
// duplicates; each keeps the 21-byte final free/return scheduling mismatch.
// 42: an explicit cdecl int free declaration is a codegen duplicate and is
// not retained because the reviewed CRT surface returns void.
// 43: a function-scope failure result local adds the 17-byte EH return basin;
// a cleanup-scope result local and a pointer alias are codegen duplicates.
// 44: matching the oracle's single cleanup PDB line with #line has no effect;
// line state is not the cause of the final scheduling difference.
// 45: a focused return-shape variant lab tested nine result forms with VC5
// flags. Under /GX, all size/frame/call-set eligible forms stayed in the same
// 21-byte basin; no exact form was found.
// 46: moving the final outer-list free outside the cleanup scope is a codegen
// duplicate. The pinned natural goto-finish source remains authoritative.
// Current pass: exact Panel_ez sibling cleanup declaration order, explicit CRT
// free/strcpy declarations, pointer-size allocation spelling, and cdecl argument
// order all retained the 21-byte basin. A direct cleanup return grew 33 bytes.
// A named post-cleanup error local grew the diff by 4 bytes. A carried calloc
// result local changed the body or duplicated the clean basin. Empty guards and
// dead pointer clearing were codegen duplicates. The unresolved tail is the
// VC5 cleanup scheduler: the oracle loads error before final stack cleanup.
// FLAGS: config\flags\00469380_create_drop_down.rsp

#include <string.h>
#include <stdlib.h>

class TDrawArea;
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
typedef int PositionMode;
typedef int RedrawMode;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long, long, long,
                                  TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
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
    virtual void get_true_render_rect(tagRECT*);
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
    char gap_1c[4];
    TDrawArea* draw_area;
    char gap_24[0xb4];
    int error;
    char gap_dc[0x18];
};
class TShape;
class TListPanel { public: void set_text_color(unsigned long, unsigned long); void set_highlight_text_color(unsigned long, unsigned long); };
class RGE_Font { public: void* font; int font_wid; int font_hgt; };
class RGE_Base_Game { public: RGE_Font* get_font(int id); };
extern RGE_Base_Game* rge_base_game;

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
};
class TButtonPanel;
class TDropDownPanel : public TPanel {
public:
    virtual ~TDropDownPanel();
    TTextPanel* val_panel;
    TButtonPanel* btn_panel;
    TListPanel* list_panel;
    char gap_0100[0x144-0x100];
    TDropDownPanel();
    long setup(TDrawArea*, TPanel*, void*, int, int, int, char, int, int, int, int, int, int, int, int, int, int, char*, int, int, char**, int, int, char*, char*, char*, char*, int, int);
    void set_buttons(TShape*, int, int, int, int, int);
    void set_bevel_info(int,int,int,int,int,int,int);
    void set_val_text_color(unsigned long,unsigned long);
};

class TEasy_Panel : public TPanel {
public:
    int ideal_width; int ideal_height; char gap_fc[0x220]; int use_bevels;
    unsigned char bevel_color1, bevel_color2, bevel_color3, bevel_color4, bevel_color5, bevel_color6;
    char gap_326[2]; unsigned long text_color1; unsigned long text_color2; unsigned long focus_color1; unsigned long focus_color2;
    char gap_338[0x110]; TShape* button_pics;
    int create_drop_down(TPanel*, TDropDownPanel**, long,long,long,long,long,long,long);
};

int TEasy_Panel::create_drop_down(TPanel* parent, TDropDownPanel** out, long x, long y, long sx, long sy, long sw, long sh, long font_id)
{
    long ix = sx * this->width / this->ideal_width;
    long iy = sy * this->height / this->ideal_height;
    long iw = sw * this->width / this->ideal_width;
    long ih = sh * this->height / this->ideal_height;
    long bh = (this->width * 18) / this->ideal_width;
    long px = x * this->width / this->ideal_width;
    long py = y * this->height / this->ideal_height;
    if (font_id >= 0)
        rge_base_game->get_font(font_id);
    else
        rge_base_game->get_font(10);
    char** list = (char**)calloc(1,4);
    if (list == 0) { this->error = 1; goto finish; }
    list[0] = (char*)calloc(0x14,1);
    // The original returns through the shared result epilogue here and leaks
    // the outer list allocation.
    if (list[0] == 0) goto finish;
    strcpy(list[0], " ");
    if (this->error == 0) {
        TDropDownPanel* p = new TDropDownPanel;
        *out = p;
        if (p != 0 && p->error == 0) {
            RGE_Font* font = rge_base_game->get_font(font_id);
            if ((*out)->setup(this->draw_area,parent,font->font,font->font_wid,font->font_hgt,0,0,1,0xff,ix,iy,iw,ih,0,0,bh,ih,0,px,py,list,1,bh,0,0,0,0,bh,bh)) {
                if (this->button_pics) (*out)->set_buttons(this->button_pics,0xe,-1,8,10,0xc);
                if (this->use_bevels) (*out)->set_bevel_info(3,bevel_color1,bevel_color2,bevel_color3,bevel_color4,bevel_color5,bevel_color6);
                (*out)->set_val_text_color(text_color1,text_color2);
                TListPanel* lp = (*out)->list_panel;
                lp->set_text_color(text_color1,text_color2);
                lp->set_highlight_text_color(focus_color1,focus_color2);
                (*out)->val_panel->set_bevel_info(3,bevel_color1,bevel_color2,bevel_color3,bevel_color4,bevel_color5,bevel_color6);
                goto cleanup;
            }
        }
        this->error = 1;
    }
cleanup:
    {
        char** p = list;
        int count = 1;
        do {
            if (*p) { free(*p); *p = 0; }
            ++p;
            --count;
        } while (count != 0);
        free(list);
    }
finish:
    return this->error == 0;
}
