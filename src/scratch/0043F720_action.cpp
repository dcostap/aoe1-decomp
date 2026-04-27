// 0043F720 TribeMenuDialog::action
// Source: dlg_menu.cpp lines 159-326
//
// Attempt log:
// Probe 1: full decomp with EH prolog, /GX needed. 1349 bytes, 12-way switch

#include "..\..\include\game_globals.h"
#include <stdlib.h>

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};
extern TPanelSystem* panel_system;

class TDrawArea;

class TPanel {
public:
    char _gap_04[0x1C];
    void* render_area;
    char _gap_24[0x1C];
    void* parent_panel;
    char _gap_44[0x28];
    int active;
    int visible;
    char _gap_74[0x14];
    void* clip_rgn;
    RECT render_rect;
    char _gap_9C[0x44];
    int display_changed_count;
    char _gap_E4[0x10];

    virtual ~TPanel();
    char* get_string(int id);
    virtual long action(TPanel* panel, long id, unsigned long param3, unsigned long param4);
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x39C];
    virtual ~TEasy_Panel();
    void popupYesNoDialog(long lang_id, long title_id, long param3, long param4);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TDialogPanel : public TEasy_Panel {
public:
    TDialogPanel(char* name);
    virtual ~TDialogPanel();
};

class TribeMenuDialog : public TDialogPanel {
public:
    char* button[11];

    TribeMenuDialog(TScreenPanel* parent);
    virtual ~TribeMenuDialog();
    virtual long action(TPanel* panel, long id, unsigned long param3, unsigned long param4);
};

class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;

extern int confirmed_close;

class RGE_Base_Game {
public:
    char _gap_00[0x10];
    int field_10;
    char _gap_14[0x3E0];
    int field_3F4;
    char _gap_3F8[0xA00];
    int save_paused;

    int multiplayerGame();
    int singlePlayerGame();
    void set_paused(int param1, int param2);
};

extern void* operator_new(unsigned int size);

void* operator_new(size_t size) {
    return malloc(size);
}

extern "C" __declspec(dllimport) void __stdcall WinHelpA(void* hwnd, const char* helpFile, unsigned long command, unsigned long data);

long TribeMenuDialog::action(TPanel* panel, long id, unsigned long param3, unsigned long param4)
{
    if (panel == 0 || id != 1)
        goto default_handler;

    if (param3 == 1) {
        void* obj = operator_new(0x6A4);
        if (obj) {
            ((void (__thiscall *)(void*, int, char*, int))0x004A71F0)(obj, 0, 0, 0);
        }
        panel_system->setCurrentPanel("Save Game Screen", 0);
        panel_system->destroyPanel("Menu Dialog");
        return 1;
    }

    if (param3 == 2) {
        void* obj = operator_new(0x6A4);
        if (obj) {
            ((void (__thiscall *)(void*, int, char*, int))0x004A71F0)(obj, 1, 0, 0);
        }
        panel_system->setCurrentPanel("Save Game Screen", 0);
        return 1;
    }

    if (param3 == 3) {
        TScreenPanel* ep = *(TScreenPanel**)((char*)this + 0x40);
        panel_system->destroyPanel("Menu Dialog");
        panel_system->setCurrentPanel("Game Screen", 0);
        ep->popupYesNoDialog(0xC1C, 0x5843A4, 0x1C2, 100);
        return 1;
    }

    if (param3 == 8) {
        if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        panel_system->destroyPanel("Menu Dialog");
        panel_system->setCurrentPanel("Game Screen", 0);
        WinHelpA(*(void**)((char*)rge_base_game + 0x10), "empires.hlp", 3, 0);
        return 1;
    }

    if (param3 == 4) {
        confirmed_close = 1;
        TScreenPanel* ep = *(TScreenPanel**)((char*)this + 0x40);
        panel_system->destroyPanel("Menu Dialog");
        panel_system->setCurrentPanel("Game Screen", 0);
        ep->popupYesNoDialog(0xC1D, 0x584394, 0x1C2, 100);
        return 1;
    }

    if (param3 == 5) {
        TScreenPanel* ep = *(TScreenPanel**)((char*)this + 0x40);
        panel_system->destroyPanel("Menu Dialog");
        panel_system->setCurrentPanel("Game Screen", 0);
        void* obj = operator_new(0x564);
        if (obj) {
            ((void (__thiscall *)(void*, TScreenPanel*, int))0x0043B560)(obj, ep, 0);
        }
        return 1;
    }

    if (param3 == 7) {
        void* obj = operator_new(0x5F8);
        if (obj) {
            char* s = this->get_string(0x269E);
            ((void (__thiscall *)(void*, char*, int))0x0048D530)(obj, s, 0);
        }
        panel_system->setCurrentPanel("Achievements Screen", 0);
        panel_system->destroyPanel("Menu Dialog");
        return 1;
    }

    if (param3 == 10) {
        TScreenPanel* ep = *(TScreenPanel**)((char*)this + 0x40);
        panel_system->destroyPanel("Menu Dialog");
        panel_system->setCurrentPanel("Game Screen", 0);
        void* obj = operator_new(0x4C4);
        if (obj) {
            ((void (__thiscall *)(void*, TScreenPanel*))0x0043AD70)(obj, ep);
        }
        return 1;
    }

    if (param3 == 11) {
        TScreenPanel* ep = *(TScreenPanel**)((char*)this + 0x40);
        panel_system->destroyPanel("Menu Dialog");
        panel_system->setCurrentPanel("Game Screen", 0);
        ep->popupYesNoDialog(0xC1E, 0x584370, 0x1C2, 100);
        return 1;
    }

    if (param3 == 9) {
        void* obj = operator_new(0x49C);
        if (obj) {
            void* world = *(void**)((char*)rge_base_game + 0x3F4);
            void* scenario = *(void**)((char*)world + 0x5C);
            int pic = *(int*)((char*)scenario + 0x198C);
            ((void (__thiscall *)(void*, char*, int, int))0x004B8100)(obj, 0, 1, pic);
        }
        panel_system->setCurrentPanel("Mission Dialog", 0);
        panel_system->destroyPanel("Menu Dialog");
        return 1;
    }

    if (param3 == 6) {
        if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        panel_system->setCurrentPanel("Game Screen", 0);
        panel_system->destroyPanel("Menu Dialog");
        return 1;
    }

    if (param3 == 12) {
        TScreenPanel* ep = *(TScreenPanel**)((char*)this + 0x40);
        panel_system->destroyPanel("Menu Dialog");
        panel_system->setCurrentPanel("Game Screen", 0);
        ep->popupYesNoDialog(0xC1F, 0x584350, 0x1C2, 100);
        return 1;
    }

    return 1;

default_handler:
    return ((TPanel*)this)->action(panel, id, param3, param4);
}
