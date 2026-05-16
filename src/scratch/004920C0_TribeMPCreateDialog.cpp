// 004920C0 TribeMPCreateDialog::TribeMPCreateDialog
// Attempt log:
// 1: natural constructor implementation from packet with /GX, local panel surfaces, real member calls: compile failed because parent parameter needs TEasy_Panel surface.
// 2: change ctor parameter to TEasy_Panel*: compiles, but broad mismatch; compiler uses ESI=this/EDI=parent, while original uses EBP=this/ESI=parent and EBX=&inputGamename.
// 3: introduce explicit self local and use it throughout to try EBP=this allocation: no register-allocation change.
// 4: add explicit parent local and use it, probing for ESI=parent / EBP=this allocation: no codegen change.
// 5: verified /GX is required for original EH registration/local_4 constructor state.
// 6: compared against destructor/matching class layout: field offsets +0x490/+0x494/+0x498/+0x49C/+0x4A0 are intended; rebuilt still allocates EBX to +0x494 because source/register basin differs.
// 7: registry string copy shape is semantically natural but not yet exact; original calls RegGetAscii twice then uses strlen/rep movs into stack buffer.
// 8: final tab-order setup behavior is represented, but local array placement/scheduling may differ after earlier register drift.
// 9: current primary blocker is constructor register allocation immediately after base ctor: original EBP=this/ESI=parent/EDI=&title/EBX=&inputGamename, rebuilt ESI=this/EDI=parent/EBP=&title/EBX=&input_title.
// 10: left in scratch: broad mismatch from function start after EH/base ctor, not accepted_drift-safe.

class TDrawArea;
class TPanel {
public:
    virtual ~TPanel();
    int renderArea();
    void set_tab_order(TPanel** list, long count);
    void set_curr_child(TPanel* child);
};
class TEasy_Panel : public TPanel {
public:
    long get_popup_info_id();
    char* get_popup_info_file();
    int create_text(TPanel* parent, TPanel** out, long string_id, long x, long y, long w, long h, long font, long a, long b, long c);
    int create_edit(TPanel* parent, TPanel** out, char* text, long text_len, long format, long x, long font, long w, long h, long max, long a, long b);
    int create_button(TPanel* parent, TPanel** out, long string_id, long x, long y, long w, long h, long font, long a, long b, long c);
};
class TDialogPanel : public TEasy_Panel {
public:
    char pad[0x490-4];
    TDialogPanel(char* title);
    int setup(int drawArea, TPanel* parent, long w, long h, char* file, long id, long flag);
};
class TButtonPanel : public TPanel { public: char gap[0x298-4]; long hotkey; long hotkey_shift; };
class TRegistry { public: char* RegGetAscii(int, char*); };
extern TRegistry* Regs;

class TribeMPCreateDialog : public TDialogPanel {
public:
    TPanel* title;
    TPanel* input_title;
    TPanel* inputGamename;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TribeMPCreateDialog(TEasy_Panel* parent);
};

TribeMPCreateDialog::TribeMPCreateDialog(TEasy_Panel* parent) : TDialogPanel((char*)0x586208)
{
    TribeMPCreateDialog* self = this;
    TEasy_Panel* p = parent;
    self->title = 0;
    self->input_title = 0;
    self->inputGamename = 0;
    self->okButton = 0;
    self->cancelButton = 0;

    if (self->setup(p->renderArea(), p, 500, 230, p->get_popup_info_file(), p->get_popup_info_id(), 1)) {
        if (self->create_text(self, &self->title, 0x25a6, 20, 20, 0x1cc, 0x1e, 1, 1, 1, 0)) {
            if (self->create_text(self, &self->input_title, 0x25aa, 40, 0x55, 0x1a4, 20, 4, 0, 1, 0)) {
                char str[256];
                char* s = Regs->RegGetAscii(1, (char*)0x5861e4);
                if (s) {
                    char* s2 = Regs->RegGetAscii(1, (char*)0x5861e4);
                    char* d = str;
                    while ((*d++ = *s2++) != 0) {}
                } else {
                    str[0] = 0;
                }
                if (self->create_edit(self, &self->inputGamename, str, 40, 0, 40, 0x6e, 0x1a4, 0x17, 0xb, 1, 0)) {
                    if (self->create_button(self, (TPanel**)&self->okButton, 0x0fa1, 0, 0x3c, 0xb4, 0xb4, 0x1e, 0, 0, 0)) {
                        if (self->create_button(self, (TPanel**)&self->cancelButton, 0x0fa2, 0, 0x104, 0xb4, 0xb4, 0x1e, 0, 0, 0)) {
                            self->cancelButton->hotkey = 0x1b;
                            self->cancelButton->hotkey_shift = 0;
                            TPanel* tab_list[3];
                            tab_list[0] = self->inputGamename;
                            tab_list[1] = self->okButton;
                            tab_list[2] = self->cancelButton;
                            self->set_tab_order(tab_list, 3);
                            self->set_curr_child(self->inputGamename);
                        }
                    }
                }
            }
        }
    }
}
