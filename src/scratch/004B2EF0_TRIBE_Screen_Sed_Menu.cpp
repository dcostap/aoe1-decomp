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
// - worker baseline after rebuilding: 504-byte body, 14/14 ordered calls, 414
//   differing bytes; external string symbols and the RGE_Base_Game spelling
//   changed relocation names but not emitted code.
// - swapping button[0] before title recovered the original LEA order and
//   reduced the diff to 411 bytes; a pointer-array alias changed the block
//   topology/size and was rejected.
// - restored the proven 0xF4 TPanel / 0x478 TEasy_Panel sizes and TButtonPanel
//   hotkey offsets (+0x298/+0x29C).  Caching button[3] in `cancel` then made
//   the late hotkey/tab-order block exact; current clean candidate is 504
//   bytes, 160 instructions, 14/14 calls, 65.19% exact-block coverage, and
//   412 differing bytes (81.746%).
// - stdlib header context was a codegen duplicate.  A title member-initializer
//   was slightly worse.  The metric-best pointer-alias variant was 12 bytes
//   short and structurally wrong, so it is not retained.
// - title-before-button[0] matched the natural same-TU field order hypothesis,
//   but reversed the two LEAs and worsened the diff to 415 bytes; restored.
// - shardA6 session: natural button-array aliases improved the diagnostic diff
//   to 398-406 bytes but shrank the body by 12 bytes; title-first layout was
//   415 bytes, and positive success nesting grew the body to 527 bytes. All
//   variants were rolled back; clean source remains 504 bytes and 412 diff.
// - left in scratch: early constructor zero-carrier/store scheduling and
//   setup-argument interleaving remain unresolved after the 10-probe budget.

#include "..\..\include\game_globals.h"
#include <string.h>

class TDrawArea;
class TButtonPanel;
class TTextPanel;

// --- Panel hierarchy stubs ---

class TPanel {
public:
    char gap_00[0xF0];
    virtual ~TPanel() {}
    virtual long action(TPanel* p1, long p2, unsigned long p3, unsigned long p4) { return 0; }
    void delete_panel(TPanel** panel);
    void set_tab_order(TPanel** panels, long count);
    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
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

    char gap_F4[0x1A4];
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

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;
};

extern RGE_Base_Game* rge_base_game;

extern char s_Scenario_Editor_Menu[];
extern char s_scr4[];
extern char s_empty[];

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
    : TScreenPanel(s_Scenario_Editor_Menu)
{
    button[0] = 0;
    title = 0;
    button[1] = 0;
    button[2] = 0;
    button[3] = 0;
    close_button = 0;

    if (!setup(rge_base_game->draw_area, s_scr4, 0xC386, 1)) {
        *(long*)((char*)this + 0x0D8) = 1;
        return;
    }

    set_ideal_size(0x280, 0x1E0);

    if (!create_text(this, &title, 0x242D, 0x14, 0x14, 0x258, 0x1E, 1, 1, 0, 0))
        return;

    for (int i = 0; i < 4; i++) {
        if (!create_button(this, &button[i], s_empty, 0, 0xAA, 0xAA + i * 0x32, 0x12C, 0x28, 0, 0, 0))
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

    TButtonPanel* cancel = button[3];
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;

    set_tab_order((TPanel**)button, 4);
    set_curr_child(button[0]);
}
