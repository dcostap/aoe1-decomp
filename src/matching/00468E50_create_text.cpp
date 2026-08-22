// 00468E50 TEasy_Panel::create_text
// Source: Panel_ez.cpp lines 1281-1328
// attempt 1: natural source based on nearby 00468CB0 overload and packet; main body extremely close, but VC5 emits success early-return epilog and places failure block after configured end.
// attempt 2: added explicit result local with goto common return; worsened register allocation from first coordinate math (first mismatch 78).
// attempt 3: same common return using dead parameter center_h as result; same broad register-allocation regression.
// attempt 4: same common return using dead text_id/font_id as result; same broad regression.
// attempt 5: reordered source with ok/fail labels and no result local; no improvement over natural tail split.
// attempt 6: added register outp local to encourage EBX out pointer; no codegen change in best natural form.
// attempt 7: tried setting error_flag=0 on success to force common block; worsened broad diff.
// attempt 8: removed /GX; object lost required EH frame and was too small, reverted.
// attempt 9: tried /Ob0 with /GX; no codegen change.
// attempt 10: tried /Gy with /GX; no codegen change, reverted.
// attempt 11: late uninitialized int result with a common return widened the frame slot; 313 bytes, first mismatch 78, rolled back.
// attempt 12: reused ideal_y as the result; duplicate 313-byte codegen, rolled back.
// attempt 13: moved the result declaration before coordinate locals; duplicate 313-byte codegen, rolled back.
// attempt 14: success-only goto done with literal failure return; duplicate natural 53-byte codegen, rolled back.
// attempt 15: byte result formed one common epilogue but changed EBX/EBP coloring; 262 bytes, first mismatch 102, rolled back.
// attempt 16: output-pointer alias with byte result; duplicate attempt 15, rolled back.
// attempt 17: natural early failure guards produced duplicate 442-byte codegen; restored nested source because tail topology did not move.
// attempt 18: modeled the ABI-supported virtual TEasy_Panel surface with a vptr-preserving leading gap; emitted code was unchanged, rolled back.
// continuation probe: nested allocation/error guards were a codegen duplicate.
// continuation probe: reusing center_v for the common return widened early liveness to 448 bytes / 313 diff, rolled back.
// continuation probe: naming setup's return before its guard was a codegen duplicate.
// continuation probe: making create_text virtual shifted proven field accesses and worsened to 62 diff, rolled back.
// continuation probe: hoisting font selection before the allocation/error guard widened drift to 143 diff, rolled back.
// continuation probe: exact sibling nested factory guard shape was a codegen duplicate.
// continuation r5 probe: replaced the slot-zero dummy with the ABI-proven TTextPanel virtual destructor; duplicate.
// continuation r5 probe: modeled TTextPanel:TPanel inheritance and the proven base layout through +F4; duplicate.
// continuation r5 probe: used a natural panel owner local before publishing the output; duplicate.
// continuation r5 probe: corrected set_text's proven short id ABI; duplicate.
// continuation r5 probe: used explicit new TTextPanel() syntax; duplicate.
// current pass probe: unsigned-char result after coordinate locals recovered one syntactic return but moved the first mismatch to +0x66 and widened the difference to 262 bytes; restored.
// current pass probe: center_v and register-int result reuse formed the same 448-byte /313-diff basin, with first mismatch +0x4E; restored.
// r5 conclusion: same-TU factory donors and PDB bands support the remaining source order, but all natural lifetime/ABI variants preserve the +19-byte /GX cleanup-tail clone. No non-synthetic control-flow lead remains.
// Remaining evidence: 9 ordered calls, first 156 bytes, and all body blocks stay exact; only /GX success/failure cleanup-tail placement differs. Same-TU create_input, create_edit, create_scrollbar, and slider factories show the same duplicated-tail basin after typed control-flow/result probes.
// Left in scratch: best source has all functional code and first 156 bytes exact, but tail/failed-path placement is not exact; not accepted_drift because rebuilt failure target lies outside original configured function body.
// Fresh pass 2026-08-17:
// - PDB and TPanel records prove pnl_wid +14, pnl_hgt +18, render_area +20,
//   and error_code +D8. TTextPanel allocation is 0x188.
// - The canonical setup overload uses int, unsigned char, short, and long
//   widths in its trailing arguments. Constant zero arguments hide no ABI issue.
// - Full named panel fields, reduced named fields, and the sized text-panel
//   gap emit the same 53-byte mismatch. The canonical reduced declarations stay.
// - The Pnl_txt full TTextPanel surface moves set_text to +E8. This target's
//   call is provably +E0, so that unrelated surface is not imported here.
// - An empty TTextPanel destructor before this method produces a 423-byte
//   MATCH. It is not valid: VA 0047C0B0 owns the real destructor. Declaration-
//   only throw()/nothrow forms do not match.
// - Moving that empty definition after this method restores the 53-byte
//   mismatch. VC5 needs the destructor body visible before this method.
// - Reusing panel instead of reloading *out widens drift to 304 bytes. The
//   repeated output-pointer reloads are source-relevant.
// - Nested positive guards remain exact with the diagnostic destructor. The
//   combined guard stays as the simpler source form.
// - Final ownership-compliant validation: 442 rebuilt bytes, 53 positional
//   bytes, nine ordered calls, and a 156-byte exact prefix.
// ACCEPTED DRIFT: All factory work and nine calls match. The declaration-only
// build clones equivalent success and failure EH epilogues. The failure store
// to error_code stays before cleanup. Both paths restore the same SEH link,
// registers, stack, and return value. No call or external memory effect moves.
// The proven empty destructor makes this source exact in authentic TU context.
// Exact translation-unit finish: the grouped pnl_ez.cpp owner set supplies a
// real earlier body and the executable's +0xE0 text-list slot. The unchanged
// factory then matches all 423 bytes and nine calls. Target-only compilation
// emits the reviewed cloned-tail drift.

#ifndef PANEL_BUTTON_TEXT_CONTEXT_H
class TDrawArea;
struct tagRECT { long value[4]; };
struct PanelNode;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    void add_panel_node(PanelNode*);
    void remove_panel_node(PanelNode*);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    void set_redraw_only(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    void set_any_overlapping_redraw(int);
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

    char gap_004[8];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    char gap_024[0xB4];
    int error_code;
    char gap_0DC[0x18];
};
class TDrawArea {};
class RGE_Font { public: void* font; long font_wid; long font_hgt; };
class RGE_Base_Game { public: RGE_Font* get_font(int id); };
extern RGE_Base_Game* rge_base_game;

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_text_list(char** text, short id); // executable slot +0xE0
    char gap_F4[0x188 - 0xF4];
    TTextPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long, char*,
               int, unsigned char, int, unsigned char, short, long);
    void scroll(int a, int b, int c);
    void set_alignment(int v, int h);
    void set_text_color(unsigned long c1, unsigned long c2);
    void set_highlight_text_color(unsigned long c1, unsigned long c2);
};

class TEasy_Panel : public TPanel {
public:
    long ideal_width;      // +F4
    long ideal_height;     // +F8
    char gap_0FC[0x22C];
    unsigned long text_color1;  // +328
    unsigned long text_color2;  // +32C
    unsigned long focus_color1; // +330
    unsigned long focus_color2; // +334

    int create_text(TPanel* parent, TTextPanel** out, char** text, long text_id,
                    long x, long y, long w, long h, long font_id,
                    int center_h, int center_v);
};
#endif

int TEasy_Panel::create_text(TPanel* parent, TTextPanel** out, char** text, long text_id,
                             long x, long y, long w, long h, long font_id,
                             int center_h, int center_v)
{
    long ideal_x = (x * this->pnl_wid) / this->ideal_width;
    long ideal_y = (y * this->pnl_hgt) / this->ideal_height;
    long ideal_w = (w * this->pnl_wid) / this->ideal_width;
    long ideal_h = (h * this->pnl_hgt) / this->ideal_height;

    TTextPanel* panel = new TTextPanel;
    *out = panel;
    if (panel != 0 && panel->error_code == 0) {
        RGE_Font* font;
        if (font_id >= 0) {
            font = rge_base_game->get_font(font_id);
        } else {
            font = rge_base_game->get_font(10);
        }
        if ((*out)->setup(this->render_area, parent, ideal_x, ideal_y, ideal_w, ideal_h,
                          font->font, font->font_wid, font->font_hgt,
                          0, 0, 0, 0, 0, 0, 0) != 0) {
            (*out)->set_text_list(text, text_id);
            (*out)->scroll(6, 0, 1);
            if (center_h != 0 && center_v != 0) {
                (*out)->set_alignment(0, 0);
            } else if (center_h != 0) {
                (*out)->set_alignment(3, 0);
            } else if (center_v != 0) {
                (*out)->set_alignment(0, 1);
            } else {
                (*out)->set_alignment(3, 1);
            }
            (*out)->set_text_color(this->text_color1, this->text_color2);
            (*out)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            return 1;
        }
    }
    this->error_code = 1;
    return 0;
}
