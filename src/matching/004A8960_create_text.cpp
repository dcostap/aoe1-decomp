// VA: 004A8960 TRIBE_Screen_Sed::create_text(TPanel*, TTextPanel**, char*) | scr_sed.cpp:552-560

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

class TTextPanel : public TPanel {
public:
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x478 - 0xF4];
    int create_text(TPanel* panel, TTextPanel** text_panel, char* text,
                    int a4, int a5, int a6, int a7, int a8,
                    int a9, int a10, int a11);
};

class TScreenPanel : public TEasy_Panel {
public:
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    int create_text(TPanel* panel, TTextPanel** text_panel, char* text);
};
#endif

int TRIBE_Screen_Sed::create_text(TPanel* panel, TTextPanel** text_panel, char* text) {
    int ok = ((TEasy_Panel*)this)->create_text(panel, text_panel, text, 0, 0, 0, 0, 10, 0, 0, 0);
    if (!ok) return 0;
    ((TPanel*)(*text_panel))->set_z_order(1, 0);
    (*text_panel)->v5(0);
    return 1;
}
