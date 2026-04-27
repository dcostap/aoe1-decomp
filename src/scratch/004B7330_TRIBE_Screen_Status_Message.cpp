// VA: 004B7140 TRIBE_Screen_Status_Message (constructor)
// PDB source: scr_stms.cpp

#include <string.h>

extern void* rge_base_game;

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
    TPanel* currentPanel();
    TPanel* panel(const char* name);
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    void* draw_area;
    int multiplayerGame();
};

class TRIBE_Screen_Status_Message : public TScreenPanel {
public:
    TPanel* message;      // +0x478

    TRIBE_Screen_Status_Message(char* param_1, char* param_2, char* param_3, long param_4);
};

TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(
    char* param_1, char* param_2, char* param_3, long param_4)
    : TScreenPanel(param_1)
{
    char info_file[260];
    TEasy_Panel* cur;

    message = 0;
    cur = (TEasy_Panel*)panel_system.currentPanel();

    if (param_3 == 0 && param_4 == -1) {
        if (cur != 0 && cur != (TEasy_Panel*)panel_system.panel("Achievements Screen")) {
            strcpy(info_file, cur->get_info_file());
            param_4 = cur->get_info_id();
        } else {
            info_file[0] = 0;
            param_4 = -1;
        }
    } else {
        strcpy(info_file, param_3);
    }

    if (info_file[0] == 0) {
        if (((RGE_Base_Game*)rge_base_game)->multiplayerGame()) {
            strcpy(info_file, "scr3");
            param_4 = 0xC385;
        } else {
            strcpy(info_file, "scr2");
            param_4 = 0xC384;
        }
    }

    if (!setup(((RGE_Base_Game*)rge_base_game)->draw_area, info_file, param_4, 0)) {
        *(int*)((char*)this + 0xD8) = 1;
    } else {
        set_ideal_size(0x280, 0x1E0);
        create_text(this, &message, param_2, 0x28, 0x28, 0x230, 0x190, 4, 1, 1, 1);
    }
}
