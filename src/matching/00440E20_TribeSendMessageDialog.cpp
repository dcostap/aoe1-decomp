// VA: 00440E20 ~TribeSendMessageDialog
// Canonical ownership: TDialogPanel base ends at +0x490; the destructor owns
// the panel pointers at +0x490..+0x524 and the non-virtual TShape at +0x528.
//
// Attempt log:
// The previous file used raw fastcall function pointers and a free wrapper,
// which discarded the C++ destructor/EH and base-destructor context.  Rebuilt
// from the period-plausible virtual class surface and member delete_panel calls.
// Probe 1 baseline: typed member cleanup and overlapping panel cursors were
// structurally close but retained an extra callee-save register for p + 8.
// Probe 2: TTextPanel**/TButtonPanel** cursor casts did not change codegen.
// Probe 3: pointer-only child declarations likewise did not change codegen.
// Probe 4: natural indexed loops over the three adjacent panel arrays and the
// two radio arrays produced an exact match; retain this source shape.
// FLAGS: config/flags/00440E20_TribeSendMessageDialog.rsp (/GX preserves the
// observed EH registration around the owning destructor cleanup).
// Main-agent audit restored the child panel inheritance surfaces; emitted
// code remains exact.

extern void __cdecl operator_delete(void*);

class TPanel {
public:
    void delete_panel(TPanel** panel);
    virtual ~TPanel();
};

class TEasy_Panel : public TPanel {
public:
    char gap_04[0x474];
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    virtual ~TDialogPanel();
};

class TTextPanel : public TPanel {};
class TButtonPanel : public TPanel {};
class TEditPanel : public TPanel {};

class TShape {
public:
    ~TShape();
};

class TribeSendMessageDialog : public TDialogPanel {
public:
    TTextPanel* title;                    // +0x490
    TTextPanel* playerName[8];            // +0x494
    TTextPanel* playerCivilization[8];    // +0x4B4
    TButtonPanel* checkButton[8];          // +0x4D4
    TTextPanel* radioTitle[4];             // +0x4F4
    TButtonPanel* radioButton[4];          // +0x504
    TShape* radioButtonShapes;             // +0x514
    TEditPanel* chatInput;                 // +0x518
    TTextPanel* chatTitle;                 // +0x51C
    TButtonPanel* okButton;                // +0x520
    TButtonPanel* help_button;             // +0x524
    TShape* backgroundPics;                // +0x528
    int commPlayers[8];                    // +0x52C

    virtual ~TribeSendMessageDialog();
};

TribeSendMessageDialog::~TribeSendMessageDialog()
{
    this->delete_panel((TPanel**)&this->title);

    int i;
    for (i = 0; i < 8; ++i) {
        this->delete_panel((TPanel**)&this->playerName[i]);
        this->delete_panel((TPanel**)&this->playerCivilization[i]);
        this->delete_panel((TPanel**)&this->checkButton[i]);
    }

    for (i = 0; i < 4; ++i) {
        this->delete_panel((TPanel**)&this->radioTitle[i]);
        this->delete_panel((TPanel**)&this->radioButton[i]);
    }

    this->delete_panel((TPanel**)&this->chatInput);
    this->delete_panel((TPanel**)&this->chatTitle);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->help_button);

    TShape* shape = this->backgroundPics;
    if (shape != 0) {
        shape->~TShape();
        operator_delete(shape);
    }
}
