// VA: 0043C0C0 ~TribeConfigDialog (485B)
// PDB: dlg_conf.cpp:326-371
//
// Baseline reconstruction: this is the period dialog-owned panel cleanup,
// using the real TPanel::delete_panel surface and the TPanel -> TEasy_Panel ->
// TDialogPanel layout.  The arrays and scalar panel members follow the
// generated class layout at +0x494 through +0x548.
//
// Attempt log:
// - baseline: replaced the previous vtable/field-only stub with the typed
//   inherited dialog surface and the 19 binary-proven delete_panel calls in
//   their original grouped loop order.
// - layout: mirrored the same-TU TPanel base fields; the first edit retained
//   the old derived gap and shifted the members to +0x584 (36-byte drift).
//   Correcting TEasy_Panel's gap to 0x384 restored the proven +0x490 base end
//   and the exact 485-byte output.

#ifndef DLG_CONF_TU_CONTEXT
class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();

    char gap_04[0x1C];
    TDrawArea* render_area;                 // +0x20
    char gap_24[0xD0];                      // TPanel size = 0xF4

    void delete_panel(TPanel** panel);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    virtual ~TDialogPanel();
};

class TTextPanel : public TPanel {
};

class TButtonPanel : public TPanel {
};

class TVerticalSliderPanel : public TPanel {
};

class TribeConfigDialog : public TDialogPanel {
public:
    int modeValue;                         // +0x490
    TTextPanel* title;                      // +0x494
    TTextPanel* speedTitle[4];              // +0x498
    TButtonPanel* speedButton[3];           // +0x4A8
    TTextPanel* musicTitle[3];              // +0x4B4
    TVerticalSliderPanel* musicSlider;      // +0x4C0
    TTextPanel* soundTitle[3];              // +0x4C4
    TVerticalSliderPanel* soundSlider;      // +0x4D0
    TTextPanel* scrollSpeedTitle[3];        // +0x4D4
    TVerticalSliderPanel* scrollSpeedSlider;// +0x4E0
    TTextPanel* sizeTitle[4];               // +0x4E4
    TButtonPanel* sizeButton[3];            // +0x4F4
    TTextPanel* mouseTitle[3];              // +0x500
    TButtonPanel* mouseButton[2];           // +0x50C
    TTextPanel* rolloverTitle[3];           // +0x514
    TButtonPanel* rolloverButton[2];        // +0x520
    TTextPanel* pathFindingTitle[4];        // +0x528
    TButtonPanel* pathFindingButton[3];     // +0x538
    TButtonPanel* okButton;                 // +0x544
    TButtonPanel* cancelButton;             // +0x548

    virtual ~TribeConfigDialog();
};
#endif

TribeConfigDialog::~TribeConfigDialog()
{
    this->delete_panel((TPanel**)&this->title);

    TTextPanel** text_panels;
    TButtonPanel** button_panels;
    int count;

    text_panels = this->speedTitle;
    count = 4;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    button_panels = this->speedButton;
    count = 3;
    do {
        this->delete_panel((TPanel**)button_panels);
        ++button_panels;
        --count;
    } while (count != 0);

    text_panels = this->musicTitle;
    count = 3;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    this->delete_panel((TPanel**)&this->musicSlider);

    text_panels = this->soundTitle;
    count = 3;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    this->delete_panel((TPanel**)&this->soundSlider);

    text_panels = this->scrollSpeedTitle;
    count = 3;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    this->delete_panel((TPanel**)&this->scrollSpeedSlider);

    text_panels = this->sizeTitle;
    count = 4;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    button_panels = this->sizeButton;
    count = 3;
    do {
        this->delete_panel((TPanel**)button_panels);
        ++button_panels;
        --count;
    } while (count != 0);

    text_panels = this->mouseTitle;
    count = 3;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    button_panels = this->mouseButton;
    count = 2;
    do {
        this->delete_panel((TPanel**)button_panels);
        ++button_panels;
        --count;
    } while (count != 0);

    text_panels = this->rolloverTitle;
    count = 3;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    button_panels = this->rolloverButton;
    count = 2;
    do {
        this->delete_panel((TPanel**)button_panels);
        ++button_panels;
        --count;
    } while (count != 0);

    text_panels = this->pathFindingTitle;
    count = 4;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    button_panels = this->pathFindingButton;
    count = 3;
    do {
        this->delete_panel((TPanel**)button_panels);
        ++button_panels;
        --count;
    } while (count != 0);

    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
}
