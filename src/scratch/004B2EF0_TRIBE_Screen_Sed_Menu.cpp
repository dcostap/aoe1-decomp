// TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu constructor
// VA: 004B2EF0
// PDB: scr_sedm.cpp:41-86
// FLAGS: /GX (EH-framed constructor)
//
// Attempt log:
// - draft 1: C2027/C2227 (RGE_Base_Game forward-decl), C2664 (button array cast)
// - draft 2 (fixed Game stub, layout, setup decl): compiles, 72% diff
//   Key issues: register allocation (ebx vs eax zero), lea order, vtable addr,
//   interleaved push scheduling. This is a ~500-byte EH-framed function with
//   complex VC5 scheduling. Likely needs TU-context or nearby-function 
//   inclusion for register basin alignment.
// - The first mismatch (offset 43) is lea order: original computes &button[0]
//   (ebp) before &title (edi). VC5 scheduler chose this order despite title
//   being declared earlier.
// - Remaining issues are mainly register choices (eax vs ebx for zero carrier,
//   edx vs eax for rge_base_game load) and vtable/string/call relocations.
// - Left in scratch: needs TU-context / header context work for register basin.

#include "..\..\include\game_globals.h"
#include <string.h>

class TDrawArea;
class TButtonPanel;
class TTextPanel;

// --- Panel hierarchy stubs ---

class TPanel {
public:
    char gap_00[0x54];
    virtual ~TPanel() {}
    virtual long action(TPanel* p1, long p2, unsigned long p3, unsigned long p4) { return 0; }
    void delete_panel(TPanel** panel);
    void set_tab_order(TPanel** panels, long count);
    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    char gap_58[0x420];
    void set_ideal_size(long w, long h);
    int create_text(TEasy_Panel* parent, TTextPanel** out, int langId, long x, long y, long w, long h,
                    long a8, long a9, long a10, long a11);
    int create_button(TEasy_Panel* parent, TButtonPanel** out, char* name, long flag,
                      long x, long y, long w, long h,
                      long a9, long a10, long a11);
};

class TTextPanel : public TPanel {
public:
};

class TButtonPanel : public TPanel {
public:
    virtual void dummy2() {}
    virtual void dummy3() {}
    virtual void dummy4() {}
    virtual void set_text_size(long size) {}
    virtual void set_button_rect(long a1, long a2, long a3, long a4, long a5,
                                 long a6, long a7, long a8, long a9, long a10,
                                 long a11, long a12, long a13) {}

    long hotkey;
    long hotkey_shift;
    void set_text(short param1, unsigned short langId);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    long setup(TDrawArea*, char*, long, long);
    ~TScreenPanel();
};

class RGE_Base_Game_Local {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;
};

static const char s_Scenario_Editor_Menu[] = "Scenario Editor Menu";
static const char s_scr4[] = "scr4";
static const char s_empty[] = "";

class TRIBE_Screen_Sed_Menu : public TScreenPanel {
public:
    TTextPanel* title;
    TButtonPanel* button[4];
    TButtonPanel* close_button;

    virtual long handle_idle();
    virtual long action(TPanel* p1, long p2, unsigned long p3, unsigned long p4);

    TRIBE_Screen_Sed_Menu();
};

TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu()
    : TScreenPanel((char*)s_Scenario_Editor_Menu)
{
    title = 0;
    button[0] = 0;
    button[1] = 0;
    button[2] = 0;
    button[3] = 0;
    close_button = 0;

    if (!setup(((RGE_Base_Game_Local*)rge_base_game)->draw_area, (char*)s_scr4, 0xC386, 1)) {
        *(long*)((char*)this + 0x0D8) = 1;
        return;
    }

    set_ideal_size(0x280, 0x1E0);

    if (!create_text(this, &title, 0x242D, 0x14, 0x14, 0x258, 0x1E, 1, 1, 0, 0))
        return;

    for (int i = 0; i < 4; i++) {
        if (!create_button(this, &button[i], (char*)s_empty, 0, 0xAA, 0xAA + i * 0x32, 0x12C, 0x28, 0, 0, 0))
            return;
    }

    if (!create_button(this, &close_button, (char*)0x3EA, 0, 0, 0, 0, 0, -1, -1, 0))
        return;

    close_button->set_text_size(1);
    close_button->set_button_rect(9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, 0, 0, 0, 0);

    button[0]->set_text(0, 0x242E);
    button[1]->set_text(0, 0x242F);
    button[2]->set_text(0, 0x2431);
    button[3]->set_text(0, 0x2430);

    button[3]->hotkey = 0x1B;
    button[3]->hotkey_shift = 0;

    set_tab_order((TPanel**)button, 4);
    set_curr_child(button[0]);
}
