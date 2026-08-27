# taunt.cpp module recovery

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\taunt.cpp`.
- The PDB source order is 00509450, 00509480, 00509490, 00509530,
  00509610, 00509640, 00509670, and 005096A0.
- These eight owners cover 663 normal bytes at source lines 16-179.
- The owning class is `TTaunt`; all eight owners are normal handwritten
  functions.
- The executable anchors the sequence through the constructor's call to
  `RestartSoundSystem`, the destructor's tail jump to `StopSoundSystem`, and
  the calls from `PlayTauntStr` to `GetTauntNo` and `PlayTauntNo`.

## Migration

`src/taunt.cpp` is the compiler-facing owner for every PDB function in this
module. The source uses `include/taunt.h` for the complete `TTaunt` layout and
`include/sounddrv_context.h` for the reviewed `TDigital` declaration. It does
not copy the `TDigital` layout.

The former `src/taunt_tu.cpp` wrapper and eight source-bank fragments are
removed. The source preserves the reviewed matching bodies and the dedicated
`/GX` response file for `RestartSoundSystem`.

## Cross-shard request

`include/chat.h` still includes `include/taunt_context.h`. Replace that include
with `include/taunt.h` after this module is integrated, then remove the old
context header. This request affects the Chat module and needs its grouped
translation-unit validation. Do not add another `TTaunt` layout to Chat.
