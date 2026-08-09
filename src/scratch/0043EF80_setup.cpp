// VA: 0043EF80 TListDialog::setup (main)
// dlg_list.cpp lines 66-96

// attempt 1: main setup with child panel creation
// 416/420 bytes (99% size) — 4 bytes short
// attempt 2: restored the dlg_list/panel virtual surface, the nested renderArea
// evaluation, and the original list/button parameter ownership.
// attempt 3: added the proven TPanel data gap; title/list/scroll field addresses and the
// first 0xEA bytes aligned, leaving a localized button-call schedule drift.
// attempt 4: typed cancel output-pointer and receiver locals were codegen duplicates or
// worsened the suffix; rolled back to direct member ownership.
// attempt 5: restored the virtual long setup overload declaration; codegen duplicate.
// attempt 6: direct create_button result tests were tried in both orders.  The retained
// natural shape tests OK directly and assigns the cancel result; it reaches 420/420 bytes,
// 10/10 ordered calls, 97.14% shape, 88 differing bytes.  Remaining drift starts at the
// three button-argument stack displacements after scroll_cur_line and the downstream cancel tail.

class TDrawArea;

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class TPanel {
public:
    virtual ~TPanel();
    VPAD32(1)
    VPAD8(33)
    VPAD4(41)
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    VPAD8(46)
    VPAD2(54)
    char gap_04[0x3C];
    TDrawArea* renderArea();
    void set_curr_child(TPanel* child);
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
    virtual void set_text(char** param_1, short param_2);
    void scroll_cur_line(unsigned char param_1, short param_2, int param_3);
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    char gap_40[0x258];
    int field_298;
    int field_29C;
};

class TScrollBarPanel;

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    virtual void draw_background(int param_1);                 // +0xE0
    virtual void set_ideal_size(long param_1, long param_2);   // +0xE4
    virtual int create_button(TPanel* parent, TButtonPanel** out, long id, long zero,
        long param_5, long param_6, long param_7, long param_8,
        long param_9, long param_10, long param_11);            // +0xE8
    virtual int create_button_text(TPanel* parent, TButtonPanel** out, char* text,
        char* label, long param_5, long param_6, long param_7, long param_8,
        long param_9, long param_10, long param_11);            // +0xEC
    virtual int create_check_box(TPanel* parent, TButtonPanel** out,
        long param_3, long param_4, long param_5, long param_6,
        long param_7, long param_8);                            // +0xF0
    virtual int create_radio_button(TPanel* parent, TButtonPanel** out,
        long param_3, long param_4, long param_5, long param_6,
        long param_7, long param_8);                            // +0xF4
    virtual int create_text_number(TPanel* parent, TTextPanel** out, int param_3,
        long param_4, long param_5, long param_6, long param_7, long param_8,
        int param_9, int param_10, int param_11);               // +0xF8
    virtual int create_text_list(TPanel* parent, TTextPanel** out, char** param_3,
        long param_4, long param_5, long param_6, long param_7, long param_8,
        long param_9, int param_10, int param_11);              // +0xFC
    virtual int create_text(TPanel* parent, TTextPanel** out, char* text,
        long param_4, long param_5, long param_6, long param_7, long param_8,
        int param_9, int param_10, int param_11);               // +0x100
    virtual int create_input(TPanel* parent, TPanel** out, char* text, short param_4,
        long param_5, long param_6, long param_7, long param_8, long param_9, long param_10);
    virtual int create_edit(TPanel* parent, TPanel** out, char* text, short param_4,
        long param_5, long param_6, long param_7, long param_8, long param_9, long param_10,
        int param_11, int param_12);
    virtual int create_drop_down(TPanel* parent, TPanel** out,
        long param_3, long param_4, long param_5, long param_6,
        long param_7, long param_8, long param_9);
    virtual int create_list(TPanel* parent, TListPanel** out,
        long param_3, long param_4, long param_5, long param_6, long param_7); // +0x110
    virtual int create_scrollbar(TPanel* parent, TPanel** out, TTextPanel* text,
        long param_4, long param_5, long param_6, long param_7, long param_8);
    virtual int create_auto_scrollbar(TPanel** out, TTextPanel* text, long param_3); // +0x118
    virtual int create_vert_slider(TPanel* parent, TPanel** out,
        long param_3, long param_4, long param_5, long param_6,
        long param_7, long param_8, long param_9);
    virtual int create_horz_slider(TPanel* parent, TPanel** out,
        long param_3, long param_4, long param_5, long param_6,
        long param_7, long param_8, long param_9);
    virtual void position_panel(TPanel* parent, long param_2, long param_3,
        long param_4, long param_5);
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();
    virtual int setup(TDrawArea* area, TPanel* p1, long p2, long p3,
        unsigned char p4, int p5);
    virtual int setup(TDrawArea* area, TPanel* p1, long p2, long p3,
        char* p4, long p5, int p6);
};

class TListDialog : public TDialogPanel {
public:
    TPanel* parent;            // +0x40
    char gap_44[0x44C];        // up to +0x490
    TTextPanel* title;         // +0x490
    TListPanel* list;          // +0x494
    TScrollBarPanel* extra_scroll; // +0x498
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
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    virtual short get_list_id();
    virtual char* get_list_name();
};

long TListDialog::setup(TPanel* param_1, char* param_2, long param_3, long param_4,
    long param_5, long param_6, long param_7, long param_8, long param_9,
    char* param_10, long param_11, long param_12, long param_13, long param_14,
    char** param_15, short param_16, short param_17, long param_18, long param_19,
    long param_20, long param_21, long param_22) {
    
    int result = TDialogPanel::setup(param_1->renderArea(), param_1,
        param_4, param_5, param_2, param_3, 1);
    if (result == 0) return 0;
    
    if (param_10 != 0 && *param_10 != 0) {
        result = create_text((TPanel*)this, &title, param_10,
            param_6, param_7, param_8, param_9, 4, 1, 1, 1);
        if (result == 0) return 0;
    }
    
    result = create_list((TPanel*)this, &list,
        param_11, param_12, param_13, param_14, 0xB);
    if (result == 0) return 0;
    
    result = create_auto_scrollbar((TPanel**)&extra_scroll, list, 0x14);
    if (result == 0) return 0;
    
    if (param_15 != 0) {
        list->set_text(param_15, param_16);
    }
    
    list_id = (short)param_17;
    list->scroll_cur_line(1, param_17, 1);
    
    if (create_button((TPanel*)this, &ok_btn, 0xFA1, 0,
        param_18, param_19, param_20, param_21, 0, 0, 0) == 0)
        return 0;
    
    result = create_button((TPanel*)this, &cancel_btn, 0xFA2, 0,
        param_19, param_19, param_20, param_21, 0, 0, 0);
    if (result == 0) return 0;
    
    cancel_btn->field_298 = 0x1B;
    cancel_btn->field_29C = 0;
    
    TPanel::set_curr_child(list);
    return 1;
}
