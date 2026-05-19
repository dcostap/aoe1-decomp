// VA: 004B2E60 TRIBE_Screen_Sed::create_radio_button
// PDB: scr_sed2.cpp lines 2313-2324 (143 bytes, 55 asm lines)
// MATCH: `python tools/check_function.py --va 004B2E60` -> 0.0000%.
// Key fix 2026-05-19: use natural member declarations for create_radio_button,
// set_z_order, the virtual at vtable +0x14, and TButtonPanel::set_bevel_info.
// Raw function-pointer calls changed call setup and register scheduling.

class TPanel {
public:
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14(int);

    void set_z_order(unsigned char, unsigned char);
};

class TButtonPanel : public TPanel {
public:
    void set_bevel_info(int, int, int, int, int, int, int);
};

class TRIBE_Screen_Sed {
public:
    char gap[0x31c];
    int useBevel;
    unsigned char c0;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    unsigned char c4;
    unsigned char c5;

    int create_radio_button(TPanel* parent, TButtonPanel** out);
    int TEasy_create_radio_button(TPanel*, TButtonPanel**, int, int, int, int, int, int);
};

int TRIBE_Screen_Sed::create_radio_button(TPanel* parent, TButtonPanel** out)
{
    if (!this->TEasy_create_radio_button(parent, out, 0, 0, 0, 0, 1, 0))
        return 0;

    (*out)->set_z_order(1, 0);
    (*out)->v14(0);

    if (this->useBevel) {
        (*out)->set_bevel_info(3, c0, c1, c2, c3, c4, c5);
    }

    return 1;
}
