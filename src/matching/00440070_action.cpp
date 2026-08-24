// VA: 00440070 TMessageDialog::action
// Dlg_msg.cpp lines 182-203

// Attempt log:
// 1: Existing natural action handler was exact size but differed because parent->action emitted vtable slot +4 instead of original +0xB4.
// 2: Added TPanel vtable padding so action lands at vt[45] / +0xB4; natural source then matched exactly.
// MATCH: python tools/check_function.py --va 00440070 => Result: MATCH / 0.0000%.

#ifndef DLG_MSG_CANONICAL_TU
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
    char gap_04[0x3C];  // up to +0x40 for parent
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();
};

class TMessageDialog : public TDialogPanel {
public:
    TPanel* parent;          // +0x40
    char gap_44[0x450];      // +0x44 to +0x493
    TPanel* text;            // +0x494
    TPanel* button[3];        // +0x498, +0x49C, +0x4A0

    virtual ~TMessageDialog();
    long setup(TPanel* p1, char* p2, long p3, long p4, long p5,
        unsigned char p6, int p7, long p8, long p9);
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};
#endif

long TMessageDialog::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4) {
    if (parent != 0 && param_2 == 1) {
        if (param_1 == button[0]) {
            parent->action(this, 0, 0, 0);
            return param_2;
        }
        if (param_1 == button[1]) {
            parent->action(this, 1, 0, 0);
            return 1;
        }
        if (param_1 == button[2]) {
            parent->action(this, 2, 0, 0);
            return 1;
        }
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
