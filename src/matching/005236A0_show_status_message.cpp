class TPanel {
public:
    virtual void d00(); virtual void d04();
    virtual void d08(); virtual void d0C(); virtual void d10();
    virtual void addRef(int val);
    virtual void setMargins(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13);
    virtual void d1C(); virtual void d20(); virtual void d24();
    virtual void d28(); virtual void d2C(); virtual void d30();
    virtual void d34(); virtual void d38(); virtual void d3C();
    virtual void d40(); virtual void d44(); virtual void d48();
    virtual void d4C();
    char pad_TPanel[0x40];
};

class TEasy_Panel : public TPanel {
public:
    void set_ideal_size(int width, int height);
    long create_text(TPanel* panel, TPanel** text_field, const char* text,
                     int x, int y, int width, int height,
                     int a8, int a9, int a10, int a11);
    char* get_info_file();
    long get_info_id();
    char pad_TEasy[0x434];
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(const char* name);
    virtual ~TScreenPanel();
    long setup(void* draw_area, char* info, long param, int zero);
};

class TPanelSystem {
public:
    TPanel* panel(const char* name);
    int setCurrentPanel(const char* name, int mode);
};

extern TPanelSystem panel_system;

class TRIBE_Screen_Status_Message : public TScreenPanel {
public:
    TPanel* message;      // +0x478

    TRIBE_Screen_Status_Message(const char* name, char* a, char* b, long c);
    void set_text(int value);
};

// RGE_Base_Game has draw_window as a member
class RGE_Base_Game {
public:
    char gap_00[4];
    void draw_window();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void show_status_message(char* param_1, char* param_2, long param_3);
};

void TRIBE_Game::show_status_message(char* param_1, char* param_2, long param_3) {
    TRIBE_Screen_Status_Message* panel;

    panel = (TRIBE_Screen_Status_Message*)panel_system.panel("Status Screen");
    if (panel != 0) {
        panel->set_text((int)param_1);
        this->draw_window();
    } else {
        panel = new TRIBE_Screen_Status_Message("Status Screen", param_1, param_2, param_3);
    }
    panel_system.setCurrentPanel("Status Screen", 0);
}
