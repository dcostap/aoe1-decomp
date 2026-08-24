// THelpDialog::THelpDialog constructor
// VA: 0043E840
// PDB: dlg_help.cpp:57-61
// EH-framed constructor, needs /GX

#include "../../include/game_globals.h"
#include <stdio.h>

#ifdef DLG_HELP_SHARED_CONTEXT
#include "../../include/dlg_help_context.h"
#else
class TPanel {
public:
    char gap_00[0x3C];
    int curr_child; // +0x3C
    void set_curr_child(TPanel* child);
};

class TPanelSystem {
public:
    int restorePreviousModalPanel();
    void setModalPanel(TPanel* panel);
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
    char gap_04[0x474];
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    TDialogPanel(char* name);
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

    THelpDialog(TEasy_Panel* param_1, char* param_2,
        long param_3, long param_4, long param_5, long param_6);
    void setup_help(TEasy_Panel*, char*, char*, long, long, long);
};
#endif

// THelpDialog(param_1, param_2, param_3, param_4, param_5, param_6)
THelpDialog::THelpDialog(TEasy_Panel* param_1, char* param_2,
    long param_3, long param_4, long param_5, long param_6)
    : TDialogPanel("Help Dialog")
{
    char* str = this->get_string(param_3);
    this->setup_help(param_1, param_2, str, param_4, param_5, param_6);
}
