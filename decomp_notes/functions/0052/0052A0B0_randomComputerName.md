# Function notes: 0052A0B0 `randomComputerName`

Module notes: `decomp_notes/tribegam_module.md`.

## Recovered attempt history

<!-- recovered:e67882e4f8dca9468841 -->
### `d7b30a95b149` `src/scratch/0052A0B0_randomComputerName.cpp:1-16`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0052A0B0 TRIBE_Game::randomComputerName
// Source: tribegam.cpp lines 5397-5431, size 187 bytes
// Attempt log:
// first: wrong stack alloc (16 instead of 12), wrong struct offset (0xBF8 vs 0x1198)
// second: &param1 trick backfires — forces param1 on stack, ruins register alloc
// third: clean locals, 16 diff bytes — all esi/edi register swap (91.4% match)
// fourth: minimal locs/goto — not better
// Parked: pure VC5 register allocation drift (esi=param1↔edi=param1; edi=limit↔esi=limit)
//         16 diff bytes (8.6%), same size (187), 3 relocations masked
//         counter at [esp+20h] matches, computerNameUsed offset 1198h matches
//         All code structure, loop bounds, stack cleanup byte-identical except register names
// [non-comment lines omitted during migration]
// VirtualHelper for calling through vtable+0x20 (slot 8)
```
<!-- end-recovered:e67882e4f8dca9468841 -->
