# Recovery journal: 0042F830 `SendZoneMessage`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_loby.cpp`.
- PDB source: `C:\msdev\work\age1_x1\com_loby.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:28a582e7a769ea1c5851 -->
### `a5fb96a1e6de` `src/scratch/0042F830_SendZoneMessage.cpp:1-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0042F830 SendZoneMessage
// 245 bytes, __thiscall, RGE_Lobby method
// probe 3: 245/245 bytes, 66.9% diff
// tried: correct member layout (glpDPL+4, glpDPL2+8, glpDP+C, glpdplConnection+10, lobby_game+14, Err+18)
// tried: COM call via vtable slot 7 (SendMessage), raw function pointer cast
// tried: memmove for data copy block
// BLOCKER: Deep VC5 codegen basin at offset 0. Original pushes ecx at entry (no frame pointer),
//   VC5 generates push ebp/mov ebp,ecx. Original saves this at [esp] (below return addr),
//   VC5 uses ebp for frame. This cascades through entire function. Core logic correct:
//   lobby_game guard, TDebuggingLog_Log, operator new/delete, GUID copy to buf,
//   memmove for data, COM call slot 7, operator delete, ShowReturn.
```
<!-- end-recovered:28a582e7a769ea1c5851 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
