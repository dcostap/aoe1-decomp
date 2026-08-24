// THelpDialog::action
// VA: 0043ED40
// PDB: dlg_help.cpp:191-223
// No EH framing, plain __thiscall
//
// Attempt log:
// - baseline natural action shape was 8 bytes short because the compiler
//   delayed help_page_id and selected only ESI.
// - materializing help_page_id before the command guard and prog_window before
//   get_string reproduced the original EBX/ESI/EDI basin and matched exactly.
// - normalized the proven parent_panel/button/global ownership without codegen
//   movement; retained as the exact source.

#include "../../include/game_globals.h"
#include <stdio.h>

#ifdef DLG_HELP_SHARED_CONTEXT
#include "../../include/dlg_help_context.h"
#else
// IAT extern for WinHelpA
typedef int (__stdcall *GDI_WinHelpA)(int, char*, unsigned int, char*);
extern GDI_WinHelpA _WinHelpA;

class TPanel {
public:
    char gap_00[0x3C];
    int curr_child; // +0x3C

    void set_curr_child(TPanel* child);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};

TPanelSystem panel_system;

class RGE_Base_Game {
public:
    char gap_00[0x10];
    int prog_window; // +0x10
};

#undef rge_base_game
#define rge_base_game (*(RGE_Base_Game**)0x0062C574)

class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void setTitle(unsigned char);
    char* get_string(int id);
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    char gap_04[0x474];
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    virtual ~TDialogPanel();
};

class THelpDialog : public TDialogPanel {
public:
    int help_page_id;       // +0x490
    char parent_panel[0x100]; // +0x494
    TPanel* title;           // +0x594
    TPanel* list;            // +0x598
    TPanel* ok_button;       // +0x59C
    TPanel* encyclopedia_button; // +0x5A0

    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};
#endif

long THelpDialog::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4)
{
    int help_page_id = this->help_page_id;

    if (param_2 == 1) {
        if (param_1 == this->ok_button) {
            panel_system.setCurrentPanel(this->parent_panel, 0);
            panel_system.destroyPanel("Help Dialog");
            return 1;
        }

        if (param_1 == this->encyclopedia_button) {
            panel_system.setCurrentPanel(this->parent_panel, 0);
            panel_system.destroyPanel("Help Dialog");

            int prog_window = rge_base_game->prog_window;
            char* help_topic = this->get_string(help_page_id);
            _WinHelpA(prog_window,
                      "empires.hlp", 0x101, help_topic);
            return 1;
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
