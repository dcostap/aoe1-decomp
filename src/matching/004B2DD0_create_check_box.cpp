// VA: 004B2DD0 TRIBE_Screen_Sed::create_check_box
// try 1: natural C++ methods instead of raw __fastcall wrappers.
class TPanel {
public:
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void set_active(int);
    void set_z_order(unsigned char, int);
};
class TButtonPanel : public TPanel {
public:
    void set_bevel_info(int, int, int, int, int, int, int);
};
class TEasy_Panel {
public:
    int create_check_box(TPanel*, TButtonPanel**, int, int, int, int, int, int);
};
class TRIBE_Screen_Sed : public TEasy_Panel {
public:
    char gap[0x31C];
    int use_bevel;
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    int create_check_box(TPanel* parent, TButtonPanel** out);
};
int TRIBE_Screen_Sed::create_check_box(TPanel* parent, TButtonPanel** out)
{
    int ok = TEasy_Panel::create_check_box(parent, out, 0, 0, 0, 0, 1, 0);
    if (!ok) return 0;
    (*out)->set_z_order(1, 0);
    (*out)->set_active(0);
    if (this->use_bevel) {
        (*out)->set_bevel_info(3, this->b0, this->b1, this->b2, this->b3, this->b4, this->b5);
    }
    return 1;
}
