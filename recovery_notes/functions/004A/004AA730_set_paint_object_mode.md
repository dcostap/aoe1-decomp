# Recovery journal: 004AA730 `set_paint_object_mode`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_sed.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_sed.cpp`.
- Earlier recovery note: `recovery_notes/scr_sed.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:1c7a664e4260936054f9 -->
### `9acc26143f36` `src/scratch/004AA730_set_paint_object_mode.cpp:1-38`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004AA730 TRIBE_Screen_Sed::set_paint_object_mode (107 B)
// PDB: scr_sed.cpp lines 1541-1560
// Attempt log:
// try 1: inherited scratch baseline was exact size but broad 98.13% diff; call surface used a fake indirect slot and global reload.
// try 2: changed RGE_Base_Game to a real virtual surface; tail calls now match exactly and diff dropped to 11 bytes / 10.28%.
// try 3: direct indexed expression self->world->players[self->player_num] kept same remaining mismatch.
// try 4: int player-number local kept same remaining mismatch.
// try 5: explicit players local kept same remaining mismatch.
// try 6: volatile player_num forced source load order but destroyed register allocation; rolled back.
// try 7: volatile self forced stack home/prologue and worsened badly; rolled back.
// try 8: final remaining mismatch is localized to lookup-chain register/load order only: original loads player_num into EDI before world into EDX, rebuilt loads world into EDI then player_num into EDX.
// try 9: typed world->players as RGE_Player** instead of void**; no codegen change.
// try 10: collapsed lookup to one direct indexed expression; no codegen change.
// try 11: made player_num field volatile; no improvement for the lookup hunk and with some shapes perturbed the whole register allocation, rolled back.
// try 12: raw offset read *(short*)((char*)self+0x4B8) for player_num; optimizer still reordered world load before index load.
// try 13: explicit world local and reversed pointer addition *(pn + players); no improvement; explicit world local with volatile field worsened prologue/register allocation.
// try 14: short pn local and direct players[pn] access; same 11-byte localized lookup-order mismatch.
// try 15: raw char* pointer arithmetic for world/player lookup; optimizer still hoisted world load before player_num.
// try 16: volatile short pointer for player_num forced source read order but changed prologue/register allocation and worsened to 26 bytes; rolled back.
// try 17: register int pn with explicit world local; no change, still world in EDI before player_num in EDX.
// try 18: volatile world load after pn forced source order but destroyed prologue/register allocation; rolled back.
// try 19: raw intptr chain with separate pn/world/players/player/masters locals; optimizer kept same reordered lookup hunk.
// try 20: mutating self to world after pn; no change.
// try 21: one raw direct expression with pn first; no change.
// try 22: C++ reference to self->world after pn; no change.
// try 23: function-scope local declaration order pn/w/obj; no change.
// try 24: players and player locals after pn; no change.
// try 25: /O1 tested as a flag probe but object was too small/wrong family; /O2 without /Oy, /Ob1, /Gs, and /Gr all kept same 11-byte hunk.
// try 26: direct this expression without self alias; no change.
// try 27: using game->master_obj_id directly instead of mo_id local destroyed early register/branch shape; rolled back.
// try 28: bool enabled changed the whole prologue/result basin; rolled back.
// try 29: nested ifs with short pn local; no change in lookup hunk.
// try 30: comma pn/world assignment and split pointer arithmetic variants; no change.
// try 31: register pn plus raw +0x40 players load; no change, same 11-byte hunk.
// try 32: pointer-to-players, C++ reference world, raw all-char chain, precomputed slot, short-copy pn, declaration-split assignments, and reversed w/pn declarations; all kept same 11-byte hunk.
// try 33: const int pn kept same 11-byte hunk.
// try 34: unsigned short pn destroyed prologue/register allocation and worsened to broad mismatch; rolled back.
// GIVEUP: behavior/calls/size match, but not exact; not proposing accepted_drift because remaining drift is a localized address-generation/register-topology hunk in the object lookup (world pointer vs player index register/load order), not a tiny harmless encoding swap.
```
<!-- end-recovered:1c7a664e4260936054f9 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
