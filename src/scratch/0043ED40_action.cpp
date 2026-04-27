// THelpDialog::action
// VA: 0043ED40
// PDB: dlg_help.cpp:191-223
// No EH framing, plain __thiscall

#include "../../include/game_globals.h"
#include <stdio.h>

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
    int field_490;          // +0x490
    char pad_494[0x594 - 0x494];
    void* member_obj1;      // +0x594
    void* member_obj2;      // +0x598
    void* member_obj3;      // +0x59C
    void* member_obj4;      // +0x5A0

    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

long THelpDialog::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4)
{
    if (param_2 == 1) {
        if (param_1 == this->member_obj3) {
            panel_system.setCurrentPanel((char*)this + 0x494, 0);
            panel_system.destroyPanel("Help Dialog");
            return 1;
        }

        if (param_1 == this->member_obj4) {
            panel_system.setCurrentPanel((char*)this + 0x494, 0);
            panel_system.destroyPanel("Help Dialog");

            char* help_topic = this->get_string(this->field_490);
            _WinHelpA(*(int*)((char*)rge_base_game + 0x10),
                      "empires.hlp", 0x101, help_topic);
            return 1;
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
