// VA: 00440070 TMessageDialog::action
// Dlg_msg.cpp lines 182-203

// attempt 1: natural action handler for 3 buttons
// 139/139 bytes exact size, 93 diff bytes
// Issue: parent offset wrong, vtable dispatch patterns differ
// Left in scratch.

class TPanel {
public:
    virtual ~TPanel();
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
    TPanel* button0;         // +0x498
    TPanel* button1;         // +0x49C
    TPanel* button2;         // +0x4A0

    virtual ~TMessageDialog();
    virtual long setup(TPanel* p1, char* p2, long p3, long p4, long p5,
        unsigned char p6, int p7, long p8, long p9);
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

long TMessageDialog::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4) {
    if (parent != 0 && param_2 == 1) {
        if (param_1 == button0) {
            parent->action(this, 0, 0, 0);
            return param_2;
        }
        if (param_1 == button1) {
            parent->action(this, 1, 0, 0);
            return 1;
        }
        if (param_1 == button2) {
            parent->action(this, 2, 0, 0);
            return 1;
        }
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
