// 004920C0 TribeMPCreateDialog::TribeMPCreateDialog
// Attempt log:
// 1: natural constructor implementation from packet with /GX, local panel surfaces, real member calls: compile failed because parent parameter needs TEasy_Panel surface.
// 2: change ctor parameter to TEasy_Panel*: compiles, but broad mismatch; compiler uses ESI=this/EDI=parent, while original uses EBP=this/ESI=parent and EBX=&inputGamename.
// 3: introduce explicit self local and use it throughout to try EBP=this allocation: no register-allocation change.
// 4: add explicit parent local and use it, probing for ESI=parent / EBP=this allocation: no codegen change.
// 5: verified /GX is required for original EH registration/local_4 constructor state.
// 6: compared against the matching destructor and class layout; the five
//     derived fields are at +0x490/+0x494/+0x498/+0x49C/+0x4A0.
// 7: stack evidence showed that the registry copy uses the local buffer base;
//     strcpy(str, ...) restores the original inline strlen/rep-mov sequence.
// 8: a typed TEditPanel** output-slot alias recovers EBX=&inputGamename and
//     the exact post-setup body. This is a normal factory-output idiom.
// 9: the proven TPanel set_tab_order overload takes a short count.
// 10: child panel data surfaces need no speculative virtual destructors.
// 11: restored the same-TU TPanel virtual surface; it compiled identically,
//     so the first constructor hunk is not controlled by that lifetime ABI.
//
// Recovered constructor facts:
// - TPanel is 0xF4, TEasy_Panel is 0x478, and TDialogPanel is 0x490.
// - /GX is required for the original EH registration and shared failure exit.
// - setup evaluates popup id, popup file, and renderArea before setup.
// - The natural nested success chain creates title, input label, edit, OK,
//   and Cancel panels. It then stores Cancel hotkeys, sets tab order, and
//   selects inputGamename.
// - The current source matches all 14 calls, frame size, CFG, and the full
//   134-instruction body after the initial constructor block. The remaining
//   31 bytes are the EH/derived-vtable/field-initialization schedule.

#include <string.h>

class TDrawArea;
class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
    TDrawArea* renderArea();
    void set_tab_order(TPanel** list, short count);
    void set_curr_child(TPanel* child);
};
class TTextPanel : public TPanel { };
class TEditPanel : public TTextPanel { };
class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    virtual ~TEasy_Panel();
    long get_popup_info_id();
    char* get_popup_info_file();
    int create_text(TPanel* parent, TTextPanel** out, long string_id,
                    long x, long y, long w, long h, long font,
                    long a, long b, long c);
    int create_edit(TPanel* parent, TEditPanel** out, char* text,
                    short text_len, long format, long x, long font,
                    long w, long h, long max, long a, long b);
    int create_button(TPanel* parent, class TButtonPanel** out,
                      long string_id, long text2, long x, long y,
                      long w, long h, long font, long a, long b);
};
class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    virtual ~TDialogPanel();
    TDialogPanel(char* title);
    int setup(TDrawArea* drawArea, TPanel* parent, long w, long h,
              char* file, long id, int flag);
};
class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;
    long hotkey_shift;
};
class TRegistry { public: char* RegGetAscii(int, char*); };
extern TRegistry* Regs;

class TribeMPCreateDialog : public TDialogPanel {
public:
    TTextPanel* title;
    TTextPanel* input_title;
    TEditPanel* inputGamename;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    virtual ~TribeMPCreateDialog();
    TribeMPCreateDialog(TEasy_Panel* parent);
};

TribeMPCreateDialog::TribeMPCreateDialog(TEasy_Panel* parent)
    : TDialogPanel((char*)0x586208)
{
    TEditPanel** inputGamename = &this->inputGamename;
    this->title = 0;
    this->input_title = 0;
    *inputGamename = 0;
    this->okButton = 0;
    this->cancelButton = 0;

    if (this->setup(parent->renderArea(), parent, 500, 230,
                    parent->get_popup_info_file(),
                    parent->get_popup_info_id(), 1)) {
        if (this->create_text(this, &this->title, 0x25a6,
                              20, 20, 0x1cc, 0x1e, 1, 1, 1, 0)) {
            if (this->create_text(this, &this->input_title, 0x25aa,
                                  40, 0x55, 0x1a4, 20, 4, 0, 1, 0)) {
                char str[256];
                char* s = Regs->RegGetAscii(1, (char*)0x5861e4);
                if (s) {
                    strcpy(str, Regs->RegGetAscii(1, (char*)0x5861e4));
                } else {
                    str[0] = 0;
                }
                if (this->create_edit(this, inputGamename, str,
                                      40, 0, 40, 0x6e, 0x1a4, 0x17,
                                      0xb, 1, 0)) {
                    if (this->create_button(this, &this->okButton,
                                            0x0fa1, 0, 0x3c, 0xb4,
                                            0xb4, 0x1e, 0, 0, 0)) {
                        if (this->create_button(this, &this->cancelButton,
                                                0x0fa2, 0, 0x104, 0xb4,
                                                0xb4, 0x1e, 0, 0, 0)) {
                            TButtonPanel* cancel = this->cancelButton;
                            cancel->hotkey = 0x1b;
                            cancel->hotkey_shift = 0;
                            TPanel* tab_list[3];
                            tab_list[0] = this->inputGamename;
                            tab_list[1] = this->okButton;
                            tab_list[2] = this->cancelButton;
                            this->set_tab_order(tab_list, 3);
                            this->set_curr_child(this->inputGamename);
                        }
                    }
                }
            }
        }
    }
}
