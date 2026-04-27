// THelpDialog::~THelpDialog destructor
// VA: 0043E950
// PDB: dlg_help.cpp:76-88
// EH-framed destructor, needs /GX

#include "../../include/game_globals.h"
#include <stdio.h>

class TPanel {
public:
    char gap_00[0x3C];
    int curr_child; // +0x3C

    void set_curr_child(TPanel* child);
};

class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void setTitle(unsigned char);
    char gap_04[0x474];
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    virtual ~TDialogPanel();
};

// Minimal class with virtual destructor for member objects
class HelpDialogMember {
public:
    virtual ~HelpDialogMember() {}
};

class THelpDialog : public TDialogPanel {
public:
    int field_490;          // +0x490
    char pad_494[0x594 - 0x494];
    HelpDialogMember* member_obj1;      // +0x594
    HelpDialogMember* member_obj2;      // +0x598
    HelpDialogMember* member_obj3;      // +0x59C
    HelpDialogMember* member_obj4;      // +0x5A0

    virtual ~THelpDialog();
};

THelpDialog::~THelpDialog()
{
    // vtable set (compiler generates this in destructor body)
    // Order of member destruction observed in original:
    delete member_obj3;  // +0x59C
    delete member_obj4;  // +0x5A0
    delete member_obj2;  // +0x598
    delete member_obj1;  // +0x594
}
