// 00493C90 TribeEndScreen::action
// Source: scr_end.cpp lines 132-143. 197 bytes. __thiscall, ret 10h.
// EH-framed virtual function.
//
// Attempt log:
// Probe 1: function pointer ctor — wrong codegen
// Probe 2: new expression + local operator_new — STUB at +0 (local operator_new placed before action)
//   KEY INSIGHT: local operator_new function compiled into .text before action body. Use extern "C".
// Probe 3: extern operator_new + new expression — NO STUB, 192/197 bytes, EH present
// Probe 4: extern operator_new + explicit ctor call — 144/197 (no EH without new expression)
// Variant lab (30+30 variants): 
//   G0001 = best result: first 36 bytes EXACT match (EH prologue, reg saves, param reads).
//   32 edit-diff bytes (16.2%). Remaining mismatches are jump-offset shifts from EH handler split
//   (.text$x/.xdata$x in .obj vs inline in EXE) — linker-level, not source-fixable.
//   Winning source: externC + direct param reads + get_string inline in new args + /GX
// Current assignment:
// Probe 5: changed panel_system from a pointer to the inventory-proven global object; MATCH.
// Probe 6: modeled TribeAchievementsScreen as the TScreenPanel-derived 0x5F8 class with its
//   proven fields and virtual destructor; MATCH unchanged.
// Probe 7: default /O2 /Oy without /GX removed the EH prologue and produced 128 bytes; rolled back.
// Probe 8: typed the four TribeEndScreen fields from inventory; MATCH unchanged.
// Kept /GX because the original has the FS:[0] registration and constructor-cleanup state.

#include "..\..\include\game_globals.h"

extern "C" void* __cdecl operator_new(size_t size);

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
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x384];
    virtual ~TEasy_Panel();
    long action(TPanel* panel, long id, unsigned long param3, unsigned long param4);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};
extern TPanelSystem panel_system;

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TTextPanel;
class TScrollBarPanel;
class TButtonPanel;
class TPicturePanel;
class TShape;
class Time_Line_Panel;

class TribeAchievementsScreen : public TScreenPanel {
public:
    int end_game_flag;
    int current_mode;
    int size;
    TTextPanel* title;
    TTextPanel* summary_text;
    TTextPanel* instruction;
    TTextPanel* win_loss_text;
    TTextPanel* time;
    TTextPanel* title_bar[7];
    TTextPanel* achievement_choice[5];
    TTextPanel* statistics[8][7];
    TTextPanel* player_names[8];
    TScrollBarPanel* summary_text_bar;
    TScrollBarPanel* instruction_bar;
    TScrollBarPanel* win_loss_text_bar;
    TButtonPanel* okButton;
    TButtonPanel* backButton;
    TButtonPanel* backButton2;
    TButtonPanel* timelineButton;
    TButtonPanel* aftermathButton;
    TButtonPanel* restartButton;
    TButtonPanel* close_button;
    TShape* win_decal;
    Time_Line_Panel* time_line;

    virtual ~TribeAchievementsScreen();
    TribeAchievementsScreen(char* summary_text, int end_game_flag);
};

class TribeEndScreen : public TScreenPanel {
public:
    TPicturePanel* background;
    TTextPanel* title;
    TTextPanel* text;
    TButtonPanel* okButton;

    virtual ~TribeEndScreen();
    long action(TPanel* panel, long id, unsigned long param3, unsigned long param4);
};

long TribeEndScreen::action(TPanel* panel, long id, unsigned long param3, unsigned long param4)
{
    if (panel == 0 || id != 1)
        return ((TEasy_Panel*)this)->action(panel, id, param3, param4);

    new TribeAchievementsScreen(this->get_string(0x269E), 1);

    panel_system.setCurrentPanel("Achievements Screen", 0);
    panel_system.destroyPanel("End Screen");
    return 1;
}
