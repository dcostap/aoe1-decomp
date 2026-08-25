// VA: 0047D120 TTextPanel::key_down_action
// PDB source: Pnl_txt.cpp lines 884-921
// Attempt log:
// - Replaced the structural stub with the period-plausible switch and panel
//   forwarding path supported by the original CFG and proven TPanel layout.
// - Earlier sessions: baseline source-order switch exact-sized but VC5 merged
//   all four break-case scroll calls; goto/duplicated-tail probes (probe-003
//   .. probe-010) all collapsed to the same full 4-way merge (diff 139).
// - NEW: return placement inside the if body vs after the if changes VC5's
//   tail-merge grouping. Uniform ret-after-if merges all four arrow cases
//   into one scroll call (diff 139). Uniform ret-inside-if merges 28/26/22
//   into one call and keeps 21 separate (3+1, diff 31).
// - EXACT: pair 1 (0x28/0x26) with `return 1;` INSIDE the if body and pair 2
//   (0x22/0x21) with `return 1;` AFTER the if produces the binary's 2+2
//   grouping (28/26 share one scroll call+check, 22/21 share another) and
//   exact bytes (diff 0). The mixed return placement is binary-proven: the
//   forward-path ret is a distinct block from the shared ret-1 tail.
// - Jump table lands at the original position once the grouping matches;
//   relocation identity of the table base is preserved (5/5 masked).

#ifndef PNL_TXT_TU_CONTEXT
struct tagRECT;
class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                  long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
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

    char gap_04[0x3C];
    TPanel* parent_panel; // +0x40
    char gap_44[0x30];
    int tab_stop;         // +0x74
    char gap_78[0x7C];
};

class TTextPanel : public TPanel {
public:
    void scroll(unsigned char scroll_type, short amount, int param_3);
    virtual long key_down_action(long param_1, short param_2, int param_3,
                                 int param_4, int param_5);
};
#endif

long TTextPanel::key_down_action(long param_1, short param_2, int param_3,
                                 int param_4, int param_5)
{
    switch (param_1) {
    case 0x28:
        this->scroll(2, 0, 1);
        if (this->parent_panel != 0 && this->tab_stop != 0) {
            this->parent_panel->key_down_action(param_1, param_2, param_3,
                                                 param_4, param_5);
            return 1;
        }
        return 1;
    case 0x26:
        this->scroll(3, 0, 1);
        if (this->parent_panel != 0 && this->tab_stop != 0) {
            this->parent_panel->key_down_action(param_1, param_2, param_3,
                                                 param_4, param_5);
            return 1;
        }
        return 1;
    case 0x22:
        this->scroll(4, 0, 1);
        if (this->parent_panel != 0 && this->tab_stop != 0) {
            this->parent_panel->key_down_action(param_1, param_2, param_3,
                                                 param_4, param_5);
        }
        return 1;
    case 0x21:
        this->scroll(5, 0, 1);
        if (this->parent_panel != 0 && this->tab_stop != 0) {
            this->parent_panel->key_down_action(param_1, param_2, param_3,
                                                 param_4, param_5);
        }
        return 1;
    case 0x24:
        this->scroll(6, 0, 1);
        return 1;
    case 0x23:
        this->scroll(7, 0, 1);
        return 1;
    default:
        return 0;
    }
}
