// VA: 0043F220 TListDialog::action
// dlg_list.cpp lines 137-174

// attempt 1: natural action handler
// 224/248 bytes (90.3% size)
// 24 bytes short — likely vtable slot alignment / virtual dispatch differences
// Left in scratch.

class TPanel {
public:
    virtual ~TPanel();
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
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
                if (parent == 0) {
                    return 1;
                }
                parent->action(this, 2, 0, 0);
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
