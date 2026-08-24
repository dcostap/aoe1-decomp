// VA: 0049EE00 TRIBE_Screen_Main_Menu::action (715B)
// Scr_main.cpp lines 264-387
// EH-framed virtual action dispatcher
// Attempt log:
// - Baseline reconstruction follows the executable's panel-name filter,
//   five-button dispatch, CD checks, typed screen allocations, and inherited
//   TEasy_Panel fallback.
// - Mirrored the PDB/Ghidra lVar5 assignment at each success arm with long
//   result; VC5 widened the function to 854 bytes and produced nine returns.
//   Rolled back because this changed the proven one-return block shape.
// - Tested a direct return of the initialized success result after button 2;
//   VC5 emitted the same 715-byte code as the clean source. Rolled back as a
//   duplicate; the EAX-before-tail scheduling gap remains.
// - A single success-result assignment before the event chain plus a common
//   done label restored the original 715-byte size and one-return CFG; the
//   remaining basin keeps the success value in ESI and reloads it at the
//   common tail instead of moving EAX before each success jump.
// - Nested else-if, shared success-label, direct-confirm-return, and int
//   result variants were rolled back: they widened the body or duplicated
//   the EH epilogue. Remaining gap is localized VC5 tail/liveness scheduling,
//   with calls, offsets, frame, and behavior aligned.
// - Direct fallback return widened to 852 bytes and nine returns; restored.
// - Direct return or live-result return on one CD-popup arm was codegen
//   duplicate; narrowed result type was also duplicate.
// - Proven polymorphic declarations for allocated screen types kept the
//   715-byte output unchanged; restored the simpler size stubs.
// - Tested assigning the validated event value to the shared success result;
//   output changed by one byte farther from the original, so restored the
//   clean result assignment. The per-arm EAX move gap remains unresolved.
// - Current pass tested eleven distinct natural hypotheses. Direct returns,
//   per-arm result writes, direct fallback, and early result initialization
//   widened or changed the body. Typed button pointers, comparison reversal,
//   int result, and zero result initialization were unchanged or worse.
// - A structured lab covered 192 source/flag variants across result timing,
//   fallback form, button surface, event comparison, and VC5 flag axes.
//   It produced 12 code groups, 40 invariant-eligible variants, and no match.
//   The closest /GX group kept 715 bytes and one return but still missed the
//   original early branch spans and the per-arm EAX moves.
// - Fresh H12-H17 probes tested a register-qualified result, direct confirm
//   success, explicit success/fallback labels, event-valued returns, and
//   negative event guards. They reproduced the duplicated EH basin or grew
//   the body. Restored the pinned one-return source.
// - Remaining blocker: natural source preserves all calls, offsets, frame,
//   boundary, and CFG counts, but VC5 places the success value in ESI and
//   reloads it at the common tail. The original moves ESI to EAX on each
//   success edge and returns the fallback call value directly.
// FLAGS: /GX (EH)

#include <string.h>
#include <windows.h>
#include "../../include/scr_main_context.h"

#if 0
class TPanel {
public:
    char gap_04[0x18];
    char* panelNameValue;
    void* render_area;
    char gap_24[0x1C];
    void* parent_panel;
    char gap_44[0x28];
    int active;
    int visible;
    char gap_74[0x14];
    void* clip_rgn;
    RECT render_rect;
    char gap_9C[0x44];
    int display_changed_count;
    char gap_E4[0x10];

    virtual ~TPanel();
    char* panelName();
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    virtual ~TEasy_Panel();
    void popupOKDialog(long string_id, char* text, int value1, int value2);
    long action(TPanel* panel, long event, unsigned long p3, unsigned long p4);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x0C];
    void* prog_window;
    char gap_14[0x998];
    int save_check_for_cd;

    int check_for_cd(int players);
    void disable_input();
    void close();
};

extern RGE_Base_Game* rge_base_game;

class TribeSPMenuScreen {
public:
    char data[0x49C];
    TribeSPMenuScreen();
};

class TribeMPStartupScreen {
public:
    char data[0x6A0];
    TribeMPStartupScreen();
};

class TRIBE_Screen_Sed_Menu {
public:
    char data[0x490];
    TRIBE_Screen_Sed_Menu();
};

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    TPanel* title1;
    TPanel* title2;
    TPanel* button[7];
    TPanel* ms_title_text;
    TPanel* ms_copy_text1;
    TPanel* ms_copy_text2;
    TPanel* warning_text;
    TPanel* circle_p_pic;

    virtual ~TRIBE_Screen_Main_Menu();
    virtual long action(TPanel* panel, long event,
                        unsigned long p3, unsigned long p4);
};
#endif

long TRIBE_Screen_Main_Menu::action(TPanel* panel, long event,
                                    unsigned long p3, unsigned long p4) {
    long result;

    if (panel != 0) {
        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), "Confirm Dialog") == 0 &&
            event == 0) {
            panel_system.destroyPanel("Confirm Dialog");
            WinHelpA(rge_base_game->prog_window, "empires.hlp", 3, event);
            result = 1;
            goto done;
        }

        result = 1;
        if (event == 1) {
            if (panel == this->button[0]) {
                if (rge_base_game->save_check_for_cd == 0) {
                    if (rge_base_game->check_for_cd(0) == 0) {
                        this->popupOKDialog(0x7D8, 0, 0x1C2, 100);
                        goto done;
                    }
                    rge_base_game->save_check_for_cd = 1;
                }
                rge_base_game->disable_input();
                new TribeSPMenuScreen;
                panel_system.setCurrentPanel("Single Player Menu", 0);
                panel_system.destroyPanel("Main Menu");
                goto done;
            }

            if (panel == this->button[1]) {
                rge_base_game->disable_input();
                new TribeMPStartupScreen;
                panel_system.setCurrentPanel("MP Startup Screen", 0);
                panel_system.destroyPanel("Main Menu");
                goto done;
            }

            if (panel == this->button[2]) {
                this->popupOKDialog(0x1D4F7, "Confirm Dialog", 0x1C2, 100);
                goto done;
            }

            if (panel == this->button[3]) {
                if (rge_base_game->save_check_for_cd == 0) {
                    if (rge_base_game->check_for_cd(0) == 0) {
                        this->popupOKDialog(0x7DA, 0, 0x1C2, 100);
                        goto done;
                    }
                    rge_base_game->save_check_for_cd = 1;
                }
                rge_base_game->disable_input();
                new TRIBE_Screen_Sed_Menu;
                panel_system.setCurrentPanel("Scenario Editor Menu", 0);
                panel_system.destroyPanel("Main Menu");
                goto done;
            }

            if (panel == this->button[4]) {
                rge_base_game->close();
                goto done;
            }
        }
    }

    result = this->TEasy_Panel::action(panel, event, p3, p4);

done:
    return result;
}
