// 004754C0 TDropDownButtonPanel::handle_mouse_move
// Attempt log:
// - baseline: the previous file was only an empty Stub_004754C0 definition.
// - reconstructed the period dropdown-button forwarding path from the original
//   virtual slots and the TPanel/TButtonPanel field ownership evidence.
// - second list-panel forwarding is also a mouse-down dispatch; separate
//   width/xPosition temporaries reproduce the original call order and frame.
// - probes of direct versus local child pointers, arithmetic spellings,
//   named argument copies, and named child types were codegen duplicates.
// - inline width/xPosition, receiver-local, arithmetic-parenthesization, and
//   inherited TPanel-base-call probes were also duplicates or structurally worse.
// - canonical TListPanel->TTextPanel ownership and the int/long width ABI
//   variants do not affect the remaining final-call scheduling hunk.
// - focused final-dispatch variant lab (direct/base cast/named x/split x/local
//   receiver) collapsed to one 253-byte group; no variant changed the hunk.
// - fresh TU lane confirmed the period TPanel/TTextPanel/TListPanel ownership
//   and virtual mouse ABI from the class/type dumps and Pnl_drop donors.
// - width - 1 + x, x + width - 1, top-level locals, complete TListPanel size,
//   TPanel receiver casts, Windows header context, register locals, and a
//   scoped result local all emitted the same bytes as the clean candidate.
// - direct xPosition()+width() evaluation was structurally worse (263 bytes);
//   reversing the width/x local declaration order selected the original LEA SIB
//   encoding but left the same 15-byte shifted push/LEA schedule, so it was
//   restored. Named coordinate/receiver/argument forms were duplicates.
// - focused 16-variant declaration/expression lab and 10-variant
//   third-argument-cast lab preserved size/frame/call-set but collapsed to two
//   nonexact 253-byte groups; neither delayed the final third-argument push.
//   Clean source remains best.
// - reverse local-order plus receiver/parameter lifetime labs isolated a
//   diagnostic lead: reverse declarations select the oracle LEA SIB bytes,
//   but VC5 still pushes the third argument before the receiver load/arithmetic;
//   receiver aliases instead color the drop pointer into ESI and worsen the
//   prefix.
// - TTextPanel/TListPanel field surfaces, alternate final expressions,
//   parameter ABI widths, and narrow address aliases all collapsed
//   back to the same 253-byte group; no source-plausible form delayed that
//   push. Restore the natural typed candidate after each lab.
// - best natural reconstruction: 253 bytes, all 9 calls/CFG/frame aligned;
//   remaining 15 bytes are only final-call scheduling/SIB operand order.
// - fresh pass: exact Pnl_drop and panel ABI donors confirm the same typed
//   TPanel/TListPanel ownership and vslot calls; the first mismatch stays at
//   +00C8 (LEA versus the rebuilt third-argument push). No new source-plausible lead
//   remains without repeating prior receiver, local-order, or ABI probes.
// - reassessed exact Panel.cpp width/xPosition donors: int/non-const method
//   declarations and int result locals were codegen duplicates; restored the
//   period PDB long/const ABI.
// - restored the six PDB-proven TListPanel data fields after TTextPanel; this
//   layout correction is codegen-neutral and keeps the local model canonical.
// - fresh worker probes of a post-arithmetic list-panel receiver local, a named
//   right-edge temporary, and an inline arithmetic helper were codegen
//   duplicates; restored the pinned natural source after each test.
// - fresh worker lab tested 12 natural edge-expression spellings across 64
//   neutral file-scope declaration contexts (768 variants); every variant
//   stayed in the same 253-byte group with the +00C8 scheduling mismatch.
// - fresh worker probes of top-level parameter const qualifiers, inherited
//   TListPanel mouse virtuals, a post-arithmetic reference receiver, and
//   original-style one-line call formatting were all codegen duplicates.
// - reverse width/x local declarations select the oracle LEA SIB but retain
//   the same 15-byte shifted third-argument push; combining that form with a named
//   right-edge temporary is also a duplicate. Restored the simpler pinned
//   natural source.
// - Object audit confirms the PDB parameter ABI, 253-byte FPO body, four saved
//   registers, no locals or SEH, panel layouts, and direct call relocations.
//   Repeated builds are stable. No metadata explains the oracle LEA-before-push
//   schedule, so compiler-steering aliases remain unsupported.
// - source-gate audit: the panel hierarchy, field ownership, event slot names,
//   and event signatures now follow the reviewed ui_core and panel type dumps.
//   The PDB names the last two parameters ctrl_key and shift_key. Keep that
//   order in every forwarding call.
// - fresh scheduling pass: twenty natural probes covered result-local reuse,
//   edge temporaries and expression trees, declaration and initializer forms,
//   function-scope local lifetimes, parameter const/register qualifiers, and
//   compound edge updates. All retained the stable 253-byte group and the same
//   15-byte +00C8 dispatch schedule mismatch. The reversed function-scope local
//   order selects the oracle LEA SIB encoding but does not move the ctrl push.
// Fresh final pass: a post-coordinate receiver plus named edge and a split
// compound edge calculation both reproduced the same 15-byte output.
// ACCEPTED DRIFT: The 15 changed bytes move one nonfaulting LEA around a stack
// argument save and child-pointer load. The same right edge and call arguments
// result. The final base forward only recolors two temporary registers. Values,
// flags, observable memory effects, nine calls, branches, cleanup, and fault
// order are equivalent.

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
struct PanelNode;
class TShape;
class TDigital;
class TScrollBarPanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
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

    TPanel* previousPanelValue; // +0x04
    TPanel* previousModalPanelValue; // +0x08
    long pnl_x; // +0x0C
    long pnl_y; // +0x10
    long pnl_wid; // +0x14
    long pnl_hgt; // +0x18
    char* panelNameValue; // +0x1C
    TDrawArea* render_area; // +0x20
    tagRECT clip_rect; // +0x24
    int position_mode; // +0x34
    int need_redraw; // +0x38
    TPanel* curr_child; // +0x3C
    TPanel* parent_panel; // +0x40
    TPanel* left_panel; // +0x44
    TPanel* top_panel; // +0x48
    TPanel* right_panel; // +0x4C
    TPanel* bottom_panel; // +0x50
    PanelNode* node; // +0x54
    PanelNode* first_child_node; // +0x58
    PanelNode* last_child_node; // +0x5C
    TPanel* tab_prev_panel; // +0x60
    TPanel* tab_next_panel; // +0x64
    int mouse_captured; // +0x68
    int active; // +0x6C
    int visible; // +0x70
    int tab_stop; // +0x74
    int have_focus; // +0x78
    int overlapping_children; // +0x7C
    int handle_mouse_input; // +0x80
    int just_drawn; // +0x84
    void* clip_rgn; // +0x88
    tagRECT render_rect; // +0x8C
    long left_border; // +0x9C
    long top_border; // +0xA0
    long right_border; // +0xA4
    long bottom_border; // +0xA8
    long min_wid; // +0xAC
    long max_wid; // +0xB0
    long min_hgt; // +0xB4
    long max_hgt; // +0xB8
    long mouse_hold_interval; // +0xBC
    long mouse_move_tolerance; // +0xC0
    long mouse_down_x; // +0xC4
    long mouse_down_y; // +0xC8
    int mouse_down_ctrl; // +0xCC
    int mouse_down_shift; // +0xD0
    unsigned long mouse_down_time; // +0xD4
    int error_code; // +0xD8
    int z_order; // +0xDC
    int display_changed_count; // +0xE0
    long help_string_id; // +0xE4
    long help_page_id; // +0xE8
    unsigned char mouse_action; // +0xEC
    unsigned char mouse_down_button; // +0xED
    unsigned char panel_type; // +0xEE
    unsigned char color; // +0xEF
    unsigned char fill_in_background; // +0xF0
    unsigned char clip_to_parent; // +0xF1
    unsigned char draw_rect2_flag; // +0xF2
    unsigned char need_restore; // +0xF3

    long width() const;
    long xPosition() const;
};

class TButtonPanel : public TPanel {
public:
    long id[9]; // +0xF4
    long id2[9]; // +0x118
    int buttonTypeValue; // +0x13C
    int drawTypeValue; // +0x140
    int notifyTypeValue; // +0x144
    TDigital* sound; // +0x148
    TShape* pic[9]; // +0x14C
    short pic_index[9]; // +0x170
    unsigned char _pad_0[2]; // +0x182
    int auto_pic_pos; // +0x184
    long pic_x; // +0x188
    long pic_y; // +0x18C
    int all_hot; // +0x190
    int draw_reverse; // +0x194
    char* text1[9]; // +0x198
    char* text2[9]; // +0x1BC
    long text_x; // +0x1E0
    long text_y; // +0x1E4
    void* font; // +0x1E8
    long font_wid; // +0x1EC
    long font_hgt; // +0x1F0
    short num_states; // +0x1F4
    short cur_state; // +0x1F6
    int is_down; // +0x1F8
    TButtonPanel** radio_buttons; // +0x1FC
    short num_radio_buttons; // +0x200
    unsigned char _pad_1[2]; // +0x202
    unsigned long button_down_time; // +0x204
    unsigned long text_color1[9]; // +0x208
    unsigned long text_color2[9]; // +0x22C
    unsigned long highlight_text_color1[9]; // +0x250
    unsigned long highlight_text_color2[9]; // +0x274
    long hotkey; // +0x298
    int hotkey_shift; // +0x29C
    int bevel_type; // +0x2A0
    unsigned char bevel_color1; // +0x2A4
    unsigned char bevel_color2; // +0x2A5
    unsigned char bevel_color3; // +0x2A6
    unsigned char bevel_color4; // +0x2A7
    unsigned char bevel_color5; // +0x2A8
    unsigned char bevel_color6; // +0x2A9
    unsigned char _pad_2[2]; // +0x2AA
    long key_down; // +0x2AC
    int disabled; // +0x2B0
    int sound_number; // +0x2B4
};

class TTextPanel : public TPanel {
public:
    class TextNode;

    TextNode* list; // +0xF4
    short num_lines; // +0xF8
    short draw_lines; // +0xFA
    short top_line; // +0xFC
    short bot_line; // +0xFE
    short cur_line; // +0x100
    short cur_col; // +0x102
    void* font; // +0x104
    long font_wid; // +0x108
    long font_hgt; // +0x10C
    int vert_align; // +0x110
    int horz_align; // +0x114
    int word_wrap; // +0x118
    int text_style; // +0x11C
    unsigned long text_color1; // +0x120
    unsigned long text_color2; // +0x124
    unsigned long highlightTextColor1; // +0x128
    unsigned long highlightTextColor2; // +0x12C
    TScrollBarPanel* scbar_panel; // +0x130
    int auto_scbar; // +0x134
    short fixed_len; // +0x138
    unsigned char _pad_0[2]; // +0x13A
    long text_wid; // +0x13C
    long text_hgt; // +0x140
    TShape* back_pic; // +0x144
    short back_pic_wid; // +0x148
    short back_pic_hgt; // +0x14A
    int fill_back; // +0x14C
    unsigned char back_color; // +0x150
    unsigned char _pad_1[3]; // +0x151
    int outline; // +0x154
    unsigned char outline_color; // +0x158
    unsigned char _pad_2[3]; // +0x159
    int sorted; // +0x15C
    long second_column_pos; // +0x160
    long full_width; // +0x164
    long scbar_width; // +0x168
    int scbar_active; // +0x16C
    int bevel_type; // +0x170
    unsigned char bevel_color1; // +0x174
    unsigned char bevel_color2; // +0x175
    unsigned char bevel_color3; // +0x176
    unsigned char bevel_color4; // +0x177
    unsigned char bevel_color5; // +0x178
    unsigned char bevel_color6; // +0x179
    unsigned char _pad_3[2]; // +0x17A
    void* clip_rgn2; // +0x17C
    int border_size; // +0x180
    int spacer_size; // +0x184
};

class TListPanel : public TTextPanel {
public:
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual int is_inside(long, long);

    int auto_track;
    unsigned long mouse_scroll_last_time;
    unsigned long mouse_scroll_interval;
    int mouse_scroll_up;
    int mouse_scroll_down;
    int drawHighlightBar;
};

class TScrollBarPanel : public TPanel {
public:
    TPanel* list_panel; // +0xF4
    long list_len; // +0xF8
    long one_step; // +0xFC
    long page_step; // +0x100
    long list_num; // +0x104
    TShape* button_pics; // +0x108
    int back_frame; // +0x10C
    int up_frame; // +0x110
    int down_frame; // +0x114
    int tab_frame; // +0x118
    long arrowSize; // +0x11C
    long tabSize; // +0x120
    long tab_y; // +0x124
    long tab_min_y; // +0x128
    long tab_max_y; // +0x12C
    long tab_mouse_y; // +0x130
    long tab_x; // +0x134
    long tab_min_x; // +0x138
    long tab_max_x; // +0x13C
    long tab_mouse_x; // +0x140
    unsigned char item_down; // +0x144
    unsigned char _pad_0[3]; // +0x145
    int item_is_down; // +0x148
    long item_x; // +0x14C
    long item_y; // +0x150
    unsigned char item_mode; // +0x154
    unsigned char _pad_1[3]; // +0x155
    unsigned long item_last_time; // +0x158
    unsigned long item_hold_interval; // +0x15C
    unsigned long item_down_interval; // +0x160
    tagRECT up_rect; // +0x164
    tagRECT down_rect; // +0x174
    tagRECT tab_rect; // +0x184
    tagRECT top_rect; // +0x194
    tagRECT bottom_rect; // +0x1A4
    int orientation; // +0x1B4
    int bevel_type; // +0x1B8
    unsigned char bevel_color1; // +0x1BC
    unsigned char bevel_color2; // +0x1BD
    unsigned char bevel_color3; // +0x1BE
    unsigned char bevel_color4; // +0x1BF
    unsigned char bevel_color5; // +0x1C0
    unsigned char bevel_color6; // +0x1C1
    unsigned char _pad_end[2]; // +0x1C2

    virtual int is_inside(long, long);
};

class TDropDownPanel : public TPanel {
public:
    TTextPanel* val_panel;       // +0xF4
    TButtonPanel* btn_panel;     // +0xF8
    TListPanel* list_panel;       // TDropDownPanel +0xFC
    TScrollBarPanel* scbar_panel; // TDropDownPanel +0x100
    int mode; // +0x104
    short val_num; // +0x108
    unsigned char val_num_padding[2]; // +0x10A
    long val_wid; // +0x10C
    long val_hgt; // +0x110
    long btn_wid; // +0x114
    long btn_hgt; // +0x118
    long list_wid; // +0x11C
    long list_hgt; // +0x120
    long scbar_wid; // +0x124
    long scbar_arrow_hgt; // +0x128
    long scbar_tab_hgt; // +0x12C
    unsigned char list_is_above; // +0x130
    unsigned char list_is_above_padding[3]; // +0x131
    long font_hgt; // +0x134
    int outline_color; // +0x138
    int draw_style; // +0x13C
    int draw_val_rect; // +0x140
};

class TDropDownButtonPanel : public TButtonPanel {
public:
    TDropDownPanel* drop_down_panel; // TDropDownButtonPanel +0x2B8

    virtual long handle_mouse_move(long, long, int, int);
};

long TDropDownButtonPanel::handle_mouse_move(long x, long y, int ctrl_key, int shift_key)
{
    if (this->mouse_captured != 0) {
        if (this->drop_down_panel->list_panel->is_inside(x, y) != 0) {
            this->handle_mouse_up(1, x, y, ctrl_key, shift_key);
            return this->drop_down_panel->list_panel->handle_mouse_down(1, x, y, ctrl_key, shift_key);
        }

        if (this->drop_down_panel->scbar_panel->is_inside(x, y) != 0) {
            this->handle_mouse_up(1, x, y, ctrl_key, shift_key);
            long list_width = this->drop_down_panel->list_panel->width();
            long list_x = this->drop_down_panel->list_panel->xPosition();
            return this->drop_down_panel->list_panel->handle_mouse_down(
                1, list_width + list_x - 1, y, ctrl_key, shift_key);
        }
    }

    return TPanel::handle_mouse_move(x, y, ctrl_key, shift_key);
}
