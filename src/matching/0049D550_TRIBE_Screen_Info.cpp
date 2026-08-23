// VA: 0049D550 TRIBE_Screen_Info::TRIBE_Screen_Info
// scr_info.cpp lines 32-52

// Attempt log:
// 1-2: Existing natural constructor with /GX had exact size 142 but broad scheduling/register drift around timer/auto_close/vptr/setup.
// 3: Fixed RGE_Base_Game layout so draw_area is at +0x4C; call surface now matches original memory offset, but constructor scheduling still off.
// 4: Tried __declspec(novtable) plus manual vptr store at original source point; vptr placement improved locally but EH state store still stayed before setup rather than before vptr, and auto_close used EDX result family; rolled back.
// 5: Added explicit derived virtual destructor declaration; no EH-state scheduling change.
// 6: Tried `timer_val != 0` / if-else auto_close spelling; worsened to setne family, rolled back.
// 7: Tried volatile zero to force explicit zero local/registers; worsened with stack zero homes, rolled back.
// 8: Tried saved `p2` local and zero local for setup argument pressure; minor register/order changes only.
// 2026-05-19 later pass:
// 9: Re-tried novtable/manual vptr with current p2/zero source; vptr placed earlier but worsened to 76 positional bytes and still used ECX/EDX wrong for auto_close/setup scheduling.
// 10: Removed derived virtual declarations while using novtable/manual vptr; no improvement over try 9, rolled back.
// Retry 2026-05-19 assigned pass:
// 11: separate zero/zero2 locals no change.
// 12: timer_val != 0 spelling produced setne family and worsened to 78 positional bytes; rolled back.
// 13: volatile param2 local also forced setne/bad scheduling; rolled back.
// 14: explicit negative boolean added double neg and worsened; rolled back.
// 15: /Ob0 no codegen change; preserved original custom /GX flags only.
// 16: explicit param3 local and moving p2/p3 declarations around setup did not affect argument scheduling.
// 17: intentionally swapped setup args improved edit diff slightly but is semantically wrong; rolled back.
// 18: /O1 worsened to 103 positional bytes; rolled back.
// 19: novtable/manual vptr improved local vptr placement but worsened positional diff and still scheduled vptr before sbb/state; rolled back.
// 20: auto_close temp and signed zero locals no codegen change.
// GIVEUP: exact size but no match. Existing custom flags file remains /nologo /c /O2 /Oy /GX. Remaining mismatch is broad constructor body scheduling: original zeros EDX/ECX, stores timer, loads param2 into EDX, emits cmp/sbb/neg auto_close with local_4 state before vptr; rebuilt keeps vptr/state and setup arg scheduling in a different basin. No accepted_drift proposed.
// Retry assigned 2026-05-20:
// 21: baseline revalidation: 142B exact size, 50.0000% positional / 44.3662% edit, first mismatch +44.
// 22: separate signed `long z1` for auto_close compare (`z1 < (long)timer_val`) produced setg/test family and worsened to 54.9296%; rolled back.
// 23: literal-zero compare/stores (`0 < timer_val`, `last_time = 0`) no codegen change.
// 24: `#define rge_base_game (*(RGE_Base_Game**)0x62C574)` recovered literal global address but worsened register choice/order to 52.1127%; rolled back to extern.
// 25: `__declspec(novtable)` without manual vptr suppressed vptr store and worsened to 54.9296%; rolled back.
// 26: explicit if/else assignment for auto_close moved param loads early and worsened to 51.4085%; rolled back.
// 27: moving timer/auto_close/last_time into member initializer list worsened body scheduling to 51.4085%; rolled back.
// 28: /Ob0 under /GX no codegen change; restored flags.
// 29: /Gr under /GX no codegen change; restored flags.
// 30: named draw_area local before setup no codegen change; rolled back.
// GIVEUP: still broad constructor scheduling/register basin mismatch, not accepted_drift.
// Canonical TU pass: the reviewed TPanel/TEasy_Panel/TScreenPanel surface in
// include/scr_info_context.h restores the original declarations.  The grouped
// scr_info.cpp build is an exact 142-byte match with the PDB constructor owner.

#include "../../include/scr_info_context.h"

TRIBE_Screen_Info::TRIBE_Screen_Info(char* name, char* param2, long param3, unsigned long timer_val)
    : TScreenPanel(name) {
    unsigned long tv = timer_val; char* p2 = param2; long p3 = param3; int zero = 0; this->timer = tv; this->auto_close = (0 < tv); this->last_time = zero;
    if (TScreenPanel::setup(rge_base_game->draw_area, p2, p3, zero) == 0) *(int*)((char*)this+0xD8)=1;
}
