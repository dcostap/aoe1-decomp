// quick-win attempt log:
// no existing work file for 004A8A00; this wrapper only forwards into TEasy_Panel::create_edit
// and then adjusts the created edit panel. Tried direct wrapper shapes, member-call vs
// qualified-call spellings, the exact success branch, and the final vf14 call on the new
// edit panel, but the remaining issue stayed in the prolog/call-surface basin and the
// last build was still too large.

class TEditPanel;

class TPanel {
public:
    virtual ~TPanel();
    char pad_00[0x40];
    TPanel* parent_panel;
    char pad_44[0x98];
    int z_order;

    void set_z_order(unsigned char mode, short z_order);
};

class TEasy_Panel : public TPanel {
public:
    int create_edit(TPanel* panel, TEditPanel** out_edit, char* text, short width,
                    int format, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
};

class TEditPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(int value);
};

class TRIBE_Screen_Sed {
public:
    int create_edit(TPanel* panel, TEditPanel** out_edit, char* text, short width,
                    int format, int a6, int a7);
};

int TRIBE_Screen_Sed::create_edit(TPanel* panel, TEditPanel** out_edit, char* text, short width,
                                int format, int a6, int a7) {
    int result = ((TEasy_Panel*)this)->create_edit(panel, out_edit, text, width, format, 0, 0, 0, 0, 10, a6, a7);
    if (result == 0) {
        return 0;
    }
    (*out_edit)->vf14(0);
    return 1;
}
