// TribeSendQuickMessageDialog::TribeSendQuickMessageDialog
// VA: 00441530
//
// Baseline reconstruction: the dialog owns the edit and title panels at
// +0x490/+0x494 and stores its Mode at +0x498.  The source follows the
// same typed panel construction idiom as the neighboring dlg_smsg.cpp
// functions; the /GX response file is required by the original EH frame.
//
// Attempt log:
// - Replaced the initial raw-call scaffold with the named TDialogPanel/
//   TScreenPanel surface and typed +0x490/+0x494/+0x498 members.
// - Moved modeValue into the constructor initializer list: VC5 then emitted
//   the original mode store before the derived-vtable store and recovered the
//   exact first block (best result: 105 differing bytes, 247-byte output).
// - Direct/additive/ternary title-ID spellings, a named title-ID local, exact
//   trailing argument widths, and a title out-pointer local all emitted the
//   same best basin. The remaining localized drift is the title-ID temporary:
//   the original keeps it in EAX (`and eax,5; add eax,2668h`), while this
//   natural source keeps it in ECX (`and ecx,5; add ecx,2668h`), adding one
//   byte to the function. A focused byte-select lab found no compileable
//   candidate under its tested spellings.
// - An explicit natural if/else assignment to an uninitialized title_id
//   reproduced the original EAX title-ID schedule and exact 246-byte body.
//   Both Mode cases assign title_id before the call; this is a plausible
//   period source form, not a register-forcing alias.

class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();

    TDrawArea* renderArea();
    void set_curr_child(TPanel* child);
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
};

class TEditPanel : public TTextPanel {
public:
    virtual ~TEditPanel();
};

class TEasy_Panel : public TPanel {
public:
    char gap_04[0x474];

    virtual ~TEasy_Panel();

    int get_popup_info_id();
    char* get_popup_info_file();
    virtual int create_text(TPanel* parent, TTextPanel** out, int text,
                    long x, long y, long width, long height, long font,
                    int align, int center, int wrap);
    virtual int create_edit(TPanel* parent, TEditPanel** out, char* text,
                    short width, long format, long x, long y, long width2,
                    long height, long font, int align, int center);
};

class TScreenPanel : public TEasy_Panel {
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];

    TDialogPanel(char* name);
    virtual ~TDialogPanel();

    virtual int setup(TDrawArea* draw_area, TPanel* parent, long width, long height,
              char* info_file, long info_id, int modal);
};

class TribeSendQuickMessageDialog : public TDialogPanel {
public:
    enum Mode {
        AsChat = 0,
        AsTaunt = 1
    };

    TEditPanel* chatInput; // +0x490
    TTextPanel* chatTitle; // +0x494
    Mode modeValue;        // +0x498

    TribeSendQuickMessageDialog(TScreenPanel* parent, Mode mode);
    virtual ~TribeSendQuickMessageDialog();
    virtual long action(TPanel* sender, long code, unsigned long a,
                        unsigned long b);
    virtual long handle_mouse_down(unsigned char button, long x, long y,
                                   int flags, int area);
};

TribeSendQuickMessageDialog::TribeSendQuickMessageDialog(TScreenPanel* parent,
                                                         Mode mode)
    : TDialogPanel("Send Quick Message Dialog"), modeValue(mode)
{
    if (!this->setup(parent->renderArea(), parent, 0x21C, 0x23,
                     parent->get_popup_info_file(),
                     parent->get_popup_info_id(), 1)) {
        return;
    }

    int title_id;
    if (this->modeValue == AsChat)
        title_id = 0x2668;
    else
        title_id = 0x266D;
    if (!this->create_text(this, &this->chatTitle, title_id,
                           5, 5, 0x78, 0x19, 4, 1, 1, 0)) {
        return;
    }

    if (!this->create_edit(this, &this->chatInput, "", 0x41, 0,
                           0x82, 5, 0x195, 0x19, 0x0B, 1, 0)) {
        return;
    }

    this->set_curr_child(this->chatInput);
}
