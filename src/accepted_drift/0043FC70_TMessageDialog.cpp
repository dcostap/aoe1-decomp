// VA: 0043FC70 TMessageDialog::TMessageDialog (59B)
// PDB source: Dlg_msg.cpp lines 43-48
// ACCEPTED_DRIFT: VC5 reorders vtable write and collapses two zero-registers
// into one. 43/59 bytes match. Prologue, base ctor call, field offsets,
// vtable value, and epilogue all match. Remaining 16 bytes: VC5 places
// explicit vtable write at top of body (after xor eax) instead of between
// dlg_type/text and button groups; merges second zero register (xor ecx)
// into eax. Semantically identical — same fields zeroed, same vtable set.

class TPanel {
public:
    virtual ~TPanel();
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    char gap_04[0x3C];
    char gap_40[0xB4];

    TPanel();
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    char gap_F4[0x384];

    TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();
    char gap_478[0x18];

    TDialogPanel(char* param_1);
};

class TButtonPanel;
class TTextPanel;

class TMessageDialog : public TDialogPanel {
public:
    unsigned char dlg_type;            // +0x490
    unsigned char _pad_491[3];         // +0x491..+0x493
    TTextPanel* text;                  // +0x494
    TButtonPanel* button[3];           // +0x498

    TMessageDialog(char* param_1);
    virtual ~TMessageDialog();
    virtual long setup(TPanel* p1, char* p2, long p3, long p4, long p5,
        unsigned char p6, int p7, long p8, long p9);
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

TMessageDialog::TMessageDialog(char* param_1) : TDialogPanel(param_1) {
    this->dlg_type = 0;
    this->text = 0;
    *(void**)this = (void*)0x0056FD60;
    this->button[0] = 0;
    this->button[1] = 0;
    this->button[2] = 0;
}
