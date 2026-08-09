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
// Best current reconstruction: 263/248 bytes, 8/8 ordered calls, 90.24% shape; remaining drift is the
// list-arm branch polarity/shared-success epilogue. Paused after the bounded 10-hypothesis assignment.

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class TPanel {
public:
    virtual ~TPanel();
    VPAD32(1) VPAD8(33) VPAD4(41)
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
            if (parent == 0) {
                return 1;
            }
            parent->action(this, 1, 0, 0);
            return 1;
        }
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
