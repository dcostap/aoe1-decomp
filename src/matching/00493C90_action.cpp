#include "../../include/game_globals.h"
#include "../../include/scr_end_context.h"

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
// proven fields and virtual destructor; MATCH unchanged.
// Probe 7: default /O2 /Oy without /GX removed the EH prologue and produced 128 bytes; rolled back.
// Probe 8: typed the four TribeEndScreen fields from inventory; MATCH unchanged.
// Probe 9: moved TEasy_Panel::action and the remaining panel declarations into the shared
// context; the qualified base call preserves the original direct target; MATCH.
// Kept /GX because the original has the FS:[0] registration and constructor-cleanup state.

extern "C" void* __cdecl operator_new(size_t size);

long TribeEndScreen::action(TPanel* panel, long id, unsigned long param3,
                            unsigned long param4)
{
    if (panel == 0 || id != 1)
        return TEasy_Panel::action(panel, id, param3, param4);

    new TribeAchievementsScreen(this->get_string(0x269E), 1);

    panel_system.setCurrentPanel("Achievements Screen", 0);
    panel_system.destroyPanel("End Screen");
    return 1;
}
