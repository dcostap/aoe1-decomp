// TRIBE_Screen_Sed::create_button — real pass
// VA: 004A8840
// Attempt log:
// 1: replaced the old raw __fastcall wrappers with the period-plausible typed
//    TEasy_Panel/TButtonPanel call surface; baseline was same size/calls but
//    the bevel block used +464 instead of the binary-proven +31C fields.
// 2: modeled the TPanel base size explicitly and placed the inherited bevel
//    fields at +31C; exact match under the repository default flags.
//
// The helper is the text-label overload in the scr_sed.cpp button family.  Keep
// the TEasy_Panel/TPanel surface typed so the direct base call, TPanel z-order
// call, and TButtonPanel virtual slot are expressed as ordinary C++ calls.

#ifndef SCR_SED_TU_CONTEXT
class TPanel {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int value);

    char gap_04[0x18 - 0x04];
    char gap_18[0xF4 - 0x18];

    void set_z_order(unsigned char mode, short z_order);
};

class TButtonPanel : public TPanel {
public:
    void set_text(short mode, char* text);
    void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x31C - 0xF4];

    int use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;

    int create_button(TPanel* parent, TButtonPanel** out, char* text1, char* text2,
                      long p5, long p6, long p7, long p8, long p9, long p10, long p11);
};

class TScreenPanel : public TEasy_Panel {
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    int create_button(TPanel* parent, TButtonPanel** out,
                      char* text1, char* text2, char* text3, char* text4);
};
#endif

int TRIBE_Screen_Sed::create_button(TPanel* parent, TButtonPanel** out,
                                    char* text1, char* text2,
                                    char* text3, char* text4)
{
    if (this->TEasy_Panel::create_button(parent, out, text1, text2,
                                         0, 0, 0, 0, 10, 1, 0) == 0)
        return 0;

    if (text3 != 0)
        (*out)->set_text(2, text3);
    if (text4 != 0)
        (*out)->set_text(3, text4);

    (*out)->set_z_order(1, 0);
    (*out)->v5(0);

    if (this->use_bevels != 0) {
        (*out)->set_bevel_info(3,
                               this->bevel_color1,
                               this->bevel_color2,
                               this->bevel_color3,
                               this->bevel_color4,
                               this->bevel_color5,
                               this->bevel_color6);
    }

    return 1;
}
