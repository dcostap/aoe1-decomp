# Function notes: 00426350 `KillAnyMissingPlayers`

Module notes: `decomp_notes/com_hand_module.md`.

## Recovered attempt history

<!-- recovered:865cce919300d6df20e6 -->
### `6a2aef2e2` `include/com_hand.h:15-19`

Mapping: `strong`. removed comment names one current scratch VA.

```text
// Canonical Com_hand.cpp context for six grouped owners.
// Evidence: exact 00425A40, 00426350, and 00426530, plus behavior-reviewed
// unsigned char, void*, int, unsigned char):
// ?CommOut@TCommunications_Handler@@IAEJKEPAXHE@Z.
// The field offsets follow the executable and the exact constructor source.
```
<!-- end-recovered:865cce919300d6df20e6 -->

<!-- recovered:89814276893cf09207a0 -->
### `f760ff4ab641` `src/scratch/00426350_KillAnyMissingPlayers.cpp:1-31`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00426350 TCommunications_Handler::KillAnyMissingPlayers()
// Source: Com_hand.cpp lines 383-431
// Size: 247 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PARKED — VC5 TU-context drift
// Complex function with virtual dispatch + multiple extern calls + globals
//
// Attempt log:
// Probe 1: extern C functions, __stdcall virtual call — 81.4% positional diff
// Probe 2: __thiscall member, extern C helpers — 82.6% positional diff
// Probe 3: member functions for helpers — goto issues
// Probe 4: declared vars at top — 82.6% positional diff
//
// Key findings:
// - +0x12D8: MaxGamePlayers (unsigned short)
// - +0x1568: player_dcoID[] (int array, 1-based indexing)
// - +0x10C8: current_turn (used as TDebuggingLog* for log calls)
// - +0x13C0 = +0x1568 - 0x1A8: flag (if 0, calls DropDeadPlayer)
// - Virtual calls at vtable[0x54] through global at [62C5ECh]
// - DebugLog: ecx=current_turn, stack=(g_pDebugObj[62C4FCh], fmt[580D40h], playerIdx, 0x0C)
// - operator_new at 0054B6F0h, operator_delete at 0054B660h
// - IsPlayerHuman (0042CCD0h): __thiscall ecx=this, stack=playerIdx
// - CommOut (0042B270h): __thiscall ecx=this, stack=(0, 0x4B, &kp, 0x0C, 0)
// - DropDeadPlayer (00428B10h): __thiscall ecx=this, stack=(playerIdx, dcoID)
//
// Remaining drift (VC5 TU-context):
// - Stack layout differs (more/less locals declared)
// - Register allocation (ebx/edi/esi/ebp choices)
// - Virtual dispatch calling convention (__thiscall vs __cdecl)
// - All external calls are placeholders (relocations)
```
<!-- end-recovered:89814276893cf09207a0 -->
