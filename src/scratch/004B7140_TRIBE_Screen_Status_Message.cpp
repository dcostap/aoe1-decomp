// VA: 004B7140 TRIBE_Screen_Status_Message (constructor, variant 1)
// PDB source: scr_stms.cpp
//
// Attempt log:
// - first pass with string.h strcpy generated correct repne scasb/rep movsd inlines
// - /GX needed for EH frame (FS:[0] handling, sub esp, 108h for info_file[260])
// - v1 had 6 bytes diff: all [esp+14h] -> [esp+18h] shifts from extra local var
// - Fixed info_file[4] -> info_file[0]
// - Changed if/else nesting structure removed wrong branch distances -> 81 bytes diff
// - Best version was 6 bytes diff with [esp+14h/18h] shift from extra 4-byte stack local
// - Remaining diff is stack layout: buffer at [esp+18h] instead of [esp+14h] due to cur pointer
//
// Left in scratch: logic is correct, stack layout diverges by 4 bytes from one extra local.
// The extra local (cur = currentPanel() result) can't be eliminated from C source
// while preserving correct register allocation to match the original.

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
