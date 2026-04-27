// TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu destructor
// VA: 004B3110
// PDB: scr_sedm.cpp:91-97
// FLAGS: /GX (EH-framed)
//
// Attempt log:
// - explicit out-of-class dtor (virtual funcs, no in-class dtor decl): C2084
// - inline dtor + virtual funcs: no .text
// - dtor declared in class + out-of-class body, explicit ~TScreenPanel call: double call
// - current: implicit base destructor call (remove explicit ~TScreenPanel)

#include "..\..\include\game_globals.h"

// TPanel: 4-byte implicit vtable ptr + 0x54 bytes data = 0x58 total
class TPanel {
public:
    char gap_00[0x54];
    virtual ~TPanel() {}
    virtual long action(TPanel* p1, long p2, unsigned long p3, unsigned long p4) { return 0; }
    void delete_panel(TPanel** panel);
};

// TPanel=0x58, TEasy_Panel adds data to reach 0x478 total
class TEasy_Panel : public TPanel {
public:
    char gap_58[0x420];
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    ~TScreenPanel();
};

class TTextPanel : public TPanel {
public:
};

class TButtonPanel : public TPanel {
public:
};

class TRIBE_Screen_Sed_Menu : public TScreenPanel {
public:
    TTextPanel* title;           // +0x478
    TButtonPanel* button[4];     // +0x47C
    TButtonPanel* close_button;  // +0x48C

    virtual long handle_idle();
    virtual long action(TPanel* p1, long p2, unsigned long p3, unsigned long p4);

    ~TRIBE_Screen_Sed_Menu();
};

// NOTE: ~TScreenPanel() is NOT explicitly called body - VC5 generates the
// implicit base destructor call at the end automatically.
TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu()
{
    delete_panel((TPanel**)&title);
    for (int i = 0; i < 4; i++)
        delete_panel((TPanel**)&button[i]);
    delete_panel((TPanel**)&close_button);
}
