// tried a direct wrapper with a local result; mismatch stayed at the prolog, so I switched to a no-local if/return shape
// tried the no-local if/return shape and the slot-0x14 callback; mismatch still stayed at the function entry load/save order
// leaving in scratch: body behavior is right, but VC5 keeps loading/saving args in a different prolog basin

class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(int value);
    virtual void set_z_order(unsigned char mode, short z_order);
};

class TTextPanel : public TPanel {
};

class TEasy_Panel {
public:
    int create_text(TPanel* param_1, TTextPanel** param_2, long param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10, int param_11, int param_12);
};

class TRIBE_Screen_Sed : public TEasy_Panel {
public:
    int create_text(TPanel* panel, TTextPanel** text_panel, long value);
};

int TRIBE_Screen_Sed::create_text(TPanel* panel, TTextPanel** text_panel, long value) {
    if (((TEasy_Panel*)this)->create_text(panel, text_panel, value, 0, 0, 0, 0, 10, 0, 0, 0, 0) == 0) {
        return 0;
    }
    (*text_panel)->set_z_order(1, 0);
    (*text_panel)->vf14(0);
    return 1;
}
