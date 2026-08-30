# Function notes: 00521120 `TRIBE_Game`

Module notes: `decomp_notes/tribegam_module.md`.

## Recovered attempt history

<!-- recovered:e1be6c20fa7475def876 -->
### `bf81de068f12` `src/scratch/00521120_TRIBE_Game.cpp:1-51`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00521120 TRIBE_Game::TRIBE_Game (599 B)
// PDB source: tribegam.cpp
// Packet-grounded: EH-framed, call RGE_Base_Game init, zero fields, set vtable
// [non-comment lines omitted during migration]
    // EH frame via FS:[0]

    // Call RGE_Base_Game constructor
// [non-comment lines omitted during migration]
    *(int*)((char*)self + 0x1250) = 0;

    // Set vtable to 0x5771A8
    *(int**)self = (int*)0x5771A8;

    // Set base class fields via RGE_Base_Game
    // ...

    // Zero out additional byte fields
    *(unsigned char*)((char*)self + 0xAE8) = 0;
    *(unsigned char*)((char*)self + 0xC58) = 0;
    *(unsigned char*)((char*)self + 0xD5C) = 0;
    *(unsigned char*)((char*)self + 0xE64) = 0;
    *(unsigned char*)((char*)self + 0xF68) = 0;
    *(int*)((char*)self + 0xE60) = 0;
    *(unsigned char*)((char*)self + 0x106C) = 0;

    // Zero globals
    *(int*)0x86BCD4 = 0;
    *(int*)0x62C560 = 0;
    *(int*)0x62C564 = 0;

    // Set mode to 0
    *(int*)((char*)self + 0x1B0) = 0;
    *(int*)((char*)self + 0x1B4) = 0;

    // Find panel system
    *(void**)((char*)self + 0x1A8) = panel_system_find;

    // More field init
    // ...
```
<!-- end-recovered:e1be6c20fa7475def876 -->
