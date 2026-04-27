// VA: 0043EF80 TListDialog::setup (main)
// dlg_list.cpp lines 66-96

// attempt 1: main setup with child panel creation
// 416/420 bytes (99% size) — 4 bytes short
// ret 58h
// Left in scratch.

class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();
    TDrawArea* renderArea(TPanel* param);
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
    virtual void set_something(long a, long b);
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    int field_298;
    int field_29C;
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();
    virtual int setup(TDrawArea* area, TPanel* p1, long p2, long p3, char* p4, long p5, int p6);
};

class TListDialog : public TDialogPanel {
public:
    TPanel* parent;
    char gap_44[0x44C];
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
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    
    // Child creation virtuals
    virtual int create_title(TPanel** out, char* text, long a, long b, long c, long d, long e, int f, int g, int h, int i);
    virtual int create_list(TListPanel** out, long a, long b, long c, long d, long e, int f);
    virtual int create_scroll(TPanel** out, TListPanel* list, int size);
    virtual TButtonPanel* create_button(TButtonPanel** out, int id, int zero, long a, long b, long c, long d, int e, int f, int g);
};

long TListDialog::setup(TPanel* param_1, char* param_2, long param_3, long param_4,
    long param_5, long param_6, long param_7, long param_8, long param_9,
    char* param_10, long param_11, long param_12, long param_13, long param_14,
    char** param_15, short param_16, short param_17, long param_18, long param_19,
    long param_20, long param_21, long param_22) {
    
    TDrawArea* draw_area = TPanel::renderArea(param_1);
    int result = TDialogPanel::setup(draw_area, param_1, param_4, param_5, param_2, param_3, 1);
    if (result == 0) return 0;
    
    if (param_10 != 0 && *param_10 != 0) {
        result = create_title(&title, param_10, param_6, param_7, param_8, param_9, 0, 4, 1, 1, 1);
        if (result == 0) return 0;
    }
    
    result = create_list(&list, (long)param_11, param_12, param_13, param_14, 0, 0xB);
    if (result == 0) return 0;
    
    result = create_scroll(&extra_scroll, list, 0x14);
    if (result == 0) return 0;
    
    if (param_5 != 0) {
        list->set_something(param_5, param_6);
    }
    
    list_id = (short)param_7;
    TPanel::set_curr_child(list);
    
    TButtonPanel* ok = create_button(&ok_btn, 0xFA1, 0, param_18, param_19, param_20, param_21, 0, 0, 0);
    if (ok == 0) return 0;
    
    TButtonPanel* cancel = create_button(&cancel_btn, 0xFA2, 0, param_19, param_20, param_21, param_22, 0, 0, 0);
    if (cancel == 0) return 0;
    
    cancel_btn->field_298 = 0x1B;
    cancel_btn->field_29C = 0;
    
    TPanel::set_curr_child(list);
    return 1;
}
