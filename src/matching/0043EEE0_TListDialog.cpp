// VA: 0043EEE0 TListDialog::~TListDialog
// dlg_list.cpp lines 45-56

// attempt 1: EH-framed destructor with child release pattern under /GX.
// fixed: use delete child pointers, not explicit destructor calls; original uses scalar deleting destructors. MATCH.
// FLAGS: /GX required; default flags emit 144 bytes and no matching EH shape.

class TPanel {
public:
    virtual ~TPanel();
    // +0x00 vtable pointer
    char gap_04[0x48C];  // up to +0x490
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
};

class TListPanel : public TPanel {
public:
    virtual ~TListPanel();
    char gap_04[4];  // extra fields beyond TPanel
};

class TScrollBarPanel : public TPanel {
public:
    virtual ~TScrollBarPanel();
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
};

class TDialogPanel : public TPanel {
public:
    virtual ~TDialogPanel();
};

class TListDialog : public TDialogPanel {
public:
    TTextPanel* title;         // +0x490
    TListPanel* list;          // +0x494
    TScrollBarPanel* scroll_bar; // +0x498
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
};

TListDialog::~TListDialog() {
    // vtable set by compiler
    if (title != 0) {
        delete title;
    }
    if (list != 0) {
        delete list;
    }
    if (scroll_bar != 0) {
        delete scroll_bar;
    }
    if (ok_btn != 0) {
        delete ok_btn;
    }
    if (cancel_btn != 0) {
        delete cancel_btn;
    }
    // ~TDialogPanel() called automatically after body
}
