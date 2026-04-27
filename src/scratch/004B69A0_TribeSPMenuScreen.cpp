// VA: 004B69A0 TribeSPMenuScreen (constructor)
// PDB source: Scr_sing.cpp

extern void* rge_base_game;

class TPanel {
public:
    virtual void d00(); virtual void d04();
    virtual void d08(); virtual void d0C(); virtual void d10();
    virtual void addRef(int val);  // slot 5 (0x14)
    virtual void setMargins(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13);  // slot 6 (0x18)
    virtual void d1C(); virtual void d20(); virtual void d24();
    virtual void d28(); virtual void d2C(); virtual void d30();
    virtual void d34(); virtual void d38(); virtual void d3C();
    virtual void d40(); virtual void d44(); virtual void d48();
    virtual void d4C();
    void delete_panel(TPanel** panel_ptr);
    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** tab_list, int count);
    char pad_TPanel[0x40];
};

class TButtonPanel : public TPanel {
public:
    virtual void d50(); virtual void d54(); virtual void d58(); virtual void d5C();
    virtual void d60(); virtual void d64(); virtual void d68(); virtual void d6C();
    virtual void d70(); virtual void d74(); virtual void d78(); virtual void d7C();
    virtual void d80(); virtual void d84(); virtual void d88(); virtual void d8C();
    virtual void d90(); virtual void d94(); virtual void d98();
    virtual void d9C(); virtual void dA0(); virtual void dA4(); virtual void dA8();
    virtual void dAC(); virtual void dB0(); virtual void dB4(); virtual void dB8();
    virtual void dBC(); virtual void dC0(); virtual void dC4();
    void set_text(short a, short lang_id);
};

class TEasy_Panel : public TPanel {
public:
    long create_text(TPanel* panel, TPanel** text_field, unsigned short lang_id,
                     int x, int y, int width, int height,
                     int a8, int a9, int a10, int a11);
    long create_button(TPanel* panel, TPanel** btn_field, const char* name, int a4,
                       int a5, int a6, int a7, int a8, int a9, int a10, int a11);
    void set_ideal_size(int width, int height);
    char pad_TEasy[0x434];
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(const char* name);
    virtual ~TScreenPanel();
    long setup(void* draw_area, const char* name, int a3, int a4);
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    void* draw_area;  // +0x4C
    void setSinglePlayerGame(int val);
    void setScenarioName(const char* name);
};

class TribeSPMenuScreen : public TScreenPanel {
public:
    TPanel* title;            // +0x478
    TPanel* button[7];        // +0x47C to +0x497
    TButtonPanel* close_button; // +0x498

    TribeSPMenuScreen();
    virtual ~TribeSPMenuScreen();
    virtual long handle_idle();
    virtual long action(TPanel* panel, long a2, unsigned long a3, unsigned long a4);
};

TribeSPMenuScreen::TribeSPMenuScreen() : TScreenPanel("Single Player Menu") {
    ((RGE_Base_Game*)rge_base_game)->setSinglePlayerGame(1);
    ((RGE_Base_Game*)rge_base_game)->setScenarioName("");

    if (!setup(((RGE_Base_Game*)rge_base_game)->draw_area, "scr2", 0xC384, 1)) {
        *(int*)((char*)this + 0xD8) = 1;
        return;
    }

    for (int i = 0; i < 7; i++)
        button[i] = 0;
    close_button = 0;

    set_ideal_size(0x280, 0x1E0);

    if (create_text(this, &title, 0x2404, 0x14, 0x14, 600, 0x1E, 1, 1, 0, 0)) {
        for (int id = 0x76, i = 0; id < 0x1A2; id += 0x32, i++) {
            if (!create_button(this, &button[i], "", 0, 0xAA, id, 300, 0x28, 0, 0, 0))
                return;
        }

        if (create_button(this, (TPanel**)&close_button, (const char*)0x3EA, 0, 0, 0, 0, -1, -1, 0, 0)) {
            close_button->addRef(1);
            close_button->setMargins(9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, 0, 0, 0, 0);

            ((TButtonPanel*)button[0])->set_text(0, 0x240A);
            ((TButtonPanel*)button[1])->set_text(0, 0x2408);
            ((TButtonPanel*)button[2])->set_text(0, 0x240B);
            ((TButtonPanel*)button[3])->set_text(0, 0x2405);
            ((TButtonPanel*)button[4])->set_text(0, 0x2407);
            ((TButtonPanel*)button[5])->set_text(0, 0x2409);

            // Cancel button hotkey
            *(int*)((char*)button[5] + 0x298) = 0x1B;
            *(int*)((char*)button[5] + 0x29C) = 0;

            set_curr_child(button[0]);

            TPanel* tabList[6];
            for (int j = 0; j < 6; j++)
                tabList[j] = button[j];
            set_tab_order(tabList, 6);
        }
    }
}
