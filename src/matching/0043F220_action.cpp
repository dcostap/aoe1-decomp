// VA: 0043F220 TListDialog::action
// dlg_list.cpp lines 137-174

// Attempt log:
// 1: natural handler was 224/248 bytes; parent calls used an indirect slot and fields were at the wrong offsets.
// 2: added the proven TPanel vtable padding through action at +0xB4; all eight call sites aligned.
// 3: added the proven TListDialog gap from parent +0x40 to title +0x490; VC5 cross-jumped the duplicate OK/list work.
// 4: used the binary-supported early parent-null return in the list arm; duplicate calls returned, but a separate 15-byte epilogue remained.
// 5: an explicit TTextPanel cast in the OK arm was codegen-identical to 3.
// 6: a branch-local TTextPanel alias added EDI pressure and lost calls; rolled back.
// 7: a local shared-success label was optimized back to 3; rolled back.
// 8: a list-arm result local was codegen-identical to 4.
// 9: /O2 /Oy /Og- produced a 369-byte unoptimized basin; diagnostic response file removed.
// 10: completing the known TListDialog virtual declaration surface was codegen-identical to 4.
// 11: changed cancel handling to call parent only when non-null and share the success return; 257/248 bytes.
// 12: applied the same non-null parent call/shared return shape to the list arm; exact 248/248 bytes.
// Best current reconstruction: exact 248/248 bytes, 8/8 ordered calls, natural named field ownership and
// the proven +0xB4 parent action slot.

class TPanel {
public:
    virtual ~TPanel();
    virtual void setup();
    virtual void set_rect_1(); virtual void set_rect_2();
    virtual void set_color(); virtual void set_active();
    virtual void set_positioning(); virtual void set_fixed_position();
    virtual void set_redraw(); virtual void set_overlapped_redraw();
    virtual void draw_setup(); virtual void draw_finish(); virtual void draw();
    virtual void draw_rect(); virtual void draw_offset();
    virtual void draw_rect2(); virtual void draw_offset2(); virtual void paint();
    virtual void wnd_proc(); virtual void handle_idle(); virtual void handle_size();
    virtual void handle_paint(); virtual void handle_key_down();
    virtual void handle_char(); virtual void handle_command();
    virtual void handle_user_command(); virtual void handle_timer_command();
    virtual void handle_scroll(); virtual void handle_mouse_down();
    virtual void handle_mouse_move(); virtual void handle_mouse_up();
    virtual void handle_mouse_dbl_click(); virtual void mouse_move_action();
    virtual void mouse_left_down_action(); virtual void mouse_left_hold_action();
    virtual void mouse_left_move_action(); virtual void mouse_left_up_action();
    virtual void mouse_left_dbl_click_action(); virtual void mouse_right_down_action();
    virtual void mouse_right_hold_action(); virtual void mouse_right_move_action();
    virtual void mouse_right_up_action(); virtual void mouse_right_dbl_click_action();
    virtual void key_down_action(); virtual void char_action();
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    char gap_04[0x3C];
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    int currentLineNumber();
    char* currentLine();
};

class TListPanel : public TTextPanel {
public:
    virtual ~TListPanel();
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();
};

class TListDialog : public TDialogPanel {
public:
    TPanel* parent;            // +0x40
    char gap_44[0x44C];         // up to +0x490
    TPanel* title;             // +0x490
    TListPanel* list;          // +0x494
    TPanel* extra_scroll;      // +0x498
    TButtonPanel* ok_btn;      // +0x49C
    TButtonPanel* cancel_btn;  // +0x4A0
    short list_id;             // +0x4A4
    char* list_name;           // +0x4A8

    virtual ~TListDialog();
    virtual long setup(TPanel* param_1, char* param_2, long param_3, long param_4,
        long param_5, long param_6, long param_7, long param_8, long param_9,
        char* param_10, long param_11, long param_12, long param_13, long param_14,
        char** param_15, short param_16, short param_17, long param_18, long param_19,
        long param_20, long param_21, long param_22);
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    virtual short get_list_id();
    virtual char* get_list_name();
};

long TListDialog::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4) {
    if (param_1 != 0) {
        if (param_1 == ok_btn) {
            if (param_2 == 1) {
                list_id = (short)list->currentLineNumber();
                list_name = list->currentLine();
                if (parent != 0) {
                    parent->action(this, 1, 0, 0);
                }
                return 1;
            }
        }
        else if (param_1 == cancel_btn) {
            if (param_2 == 1) {
                if (parent != 0) {
                    parent->action(this, 2, 0, 0);
                }
                return 1;
            }
        }
        else if (param_1 == list && param_2 == 3) {
            list_id = (short)list->currentLineNumber();
            list_name = list->currentLine();
            if (parent != 0) {
                parent->action(this, 1, 0, 0);
            }
            return 1;
        }
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
