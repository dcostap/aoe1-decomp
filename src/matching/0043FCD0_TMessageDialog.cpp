// VA: 0043FCD0 TMessageDialog::~TMessageDialog
// Dlg_msg.cpp lines 54-64

// attempt 1: EH-framed destructor with text + 3-button release
// /GX for EH

class TPanel {
public:
    virtual ~TPanel();
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    char gap_04[0x3C];
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
    char gap_44[0x450];
    TPanel* text;            // +0x494
    TPanel* button[3];       // +0x498, +0x49C, +0x4A0

    virtual ~TMessageDialog();
    virtual long setup(TPanel* p1, char* p2, long p3, long p4, long p5,
        unsigned char p6, int p7, long p8, long p9);
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

TMessageDialog::~TMessageDialog() {
    if (text != 0) {
        delete text;
    }
    for (int i = 0; i < 3; i++) {
        if (button[i] != 0) {
            delete button[i];
        }
    }
}
