// ~TDialogPanel
// VA: 00473E40
// PDB: pnl_dlg.cpp:130-144
// EH-framed destructor, needs /GX

#include "..\..\include\game_globals.h"

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
    char gap_04[0x474];
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    virtual ~TDialogPanel();
};

TDialogPanel::~TDialogPanel()
{
    *(void**)this = (void*)0x005710B0;

    if (!panel_system.restorePreviousModalPanel())
        panel_system.setModalPanel(0);

    TPanel* parent = *(TPanel**)((char*)this + 0x40);
    if (parent) {
        // virtual call at parent->vtable[8], with integer param 2
        // This is parent->removeChild(2) or similar
        typedef void (__thiscall *RemoveFunc)(void*, int);
        ((RemoveFunc)(*(void***)parent)[8])(parent, 2);

        int old_child = *(int*)((char*)this + 0x47C);
        parent->set_curr_child((TPanel*)old_child);
    }

    ((TEasy_Panel*)this)->TEasy_Panel::~TEasy_Panel();
}
