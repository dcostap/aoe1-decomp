// VA: 004A87F0 TRIBE_Screen_Sed::create_button(TPanel*, TButtonPanel**, long, int) | scr_sed.cpp:498-512

class TPanel {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int value);
    char gap_18[0xF4 - 0x18];
    int get_string(int string_id, char* buffer, int length);
};

class TButtonPanel;

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x478 - 0xF4];
    int create_button(TPanel* panel, TButtonPanel** button, char* text,
                      long a, long b, long c);
};

class TScreenPanel : public TEasy_Panel {
public:
};

class TButtonPanel : public TPanel {
public:
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    int create_button(TPanel* panel, TButtonPanel** button, long string_id, int param_4);
};

int TRIBE_Screen_Sed::create_button(TPanel* panel, TButtonPanel** button, long string_id, int param_4) {
    char buffer[0x78];
    ((TPanel*)this)->get_string(string_id, buffer, 0x78);
    return ((TEasy_Panel*)this)->create_button(panel, button, buffer, 0, 0, 0);
}
