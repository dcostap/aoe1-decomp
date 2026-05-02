// VA: 0043FC70 TMessageDialog::TMessageDialog (59B)
// PDB source: Dlg_msg.cpp lines 43-48
// tried manual-vtable class with explicit +0x490/+0x494/+0x498/+0x49C/+0x4A0 layout; call/base/prologue matches
// remaining drift: VC5 keeps hoisting the vtable store before dlg_type/text zeroing and reuses eax=0 for all button stores instead of xor ecx,ecx + late mov eax,esi

class TTextPanel;
class TButtonPanel;

class TDialogPanel {
public:
    TDialogPanel(char* param_1);
};

class TMessageDialog {
public:
    void* vtable_ptr;                // +0x000
    char gap_004[0x490 - 4];         // +0x004..+0x48F
    unsigned char dlg_type;          // +0x490
    char gap_491[3];                 // +0x491..+0x493
    TTextPanel* text;                // +0x494
    TButtonPanel* button0;           // +0x498
    TButtonPanel* button1;           // +0x49C
    TButtonPanel* button2;           // +0x4A0

    TMessageDialog(char* param_1);
};

TMessageDialog::TMessageDialog(char* param_1) {
    TTextPanel* t;
    TButtonPanel* b;

    ((TDialogPanel*)this)->TDialogPanel::TDialogPanel(param_1);
    t = 0;
    b = 0;
    this->dlg_type = 0;
    this->text = t;
    this->vtable_ptr = (void*)0x56FD60;
    this->button0 = b;
    this->button1 = b;
    this->button2 = b;
}
