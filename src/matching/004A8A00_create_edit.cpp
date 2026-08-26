// VA: 004A8A00 TRIBE_Screen_Sed::create_edit | scr_sed.cpp:580-588

#ifndef SCR_SED_TU_CONTEXT
class TPanel {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int value);
    char gap_18[0xF4 - 0x18];
    void set_z_order(unsigned char mode, short z_order);
};

class TEditPanel : public TPanel {
public:
    enum FormatType { FormatText = 0, FormatUnsignedInt = 3,
                      FormatMultiLine = 7 };
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x478 - 0xF4];
    int create_edit(TPanel* panel, TEditPanel** out_edit, char* text, short width,
                    int format, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
};

class TScreenPanel : public TEasy_Panel {
public:
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    int create_edit(TPanel* panel, TEditPanel** out_edit, char* text, short width,
                    TEditPanel::FormatType format, int a6, int a7);
};
#endif

int TRIBE_Screen_Sed::create_edit(TPanel* panel, TEditPanel** out_edit,
                                  char* text, short width,
                                  TEditPanel::FormatType format, int a6,
                                  int a7) {
    int result = ((TEasy_Panel*)this)->create_edit(panel, out_edit, text, width, format, 0, 0, 0, 0, 10, a6, a7);
    if (result == 0) return 0;
    ((TPanel*)(*out_edit))->set_z_order(1, 0);
    (*out_edit)->v5(0);
    return 1;
}
