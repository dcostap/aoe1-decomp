# Recovery journal: 00429A90 `SendIResignMsg`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_hand.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Com_hand.cpp`.
- Earlier recovery note: `recovery_notes/com_hand_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:4e236c372f2ffdbc06ff -->
### `912332e8f578` `src/scratch/00429A90_SendIResignMsg.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00429A90 TCommunications_Handler::SendIResignMsg (Com_hand.cpp:2890-2924, 313B)
// Sends RSGN followed by 3 DONE messages with latency stats.
// Early return if Multiplayer flag at +0x10E4 is zero.
//
// Fields:
//   +0x10C8 = current_turn (int)
//   +0x10E4 = Multiplayer (int)
//   +0x14D4 = Speed (RGE_Communications_Speed*)
//   +0x1590 = CommandTurnIncrement (unsigned char)
//
// CommOut is __thiscall with 5 stack params (ret 14h cleans all).
// Log is __cdecl with 3 params (add esp, 0Ch after call).
// FLAGS: /nologo /c /O2 /Oy
```
<!-- end-recovered:4e236c372f2ffdbc06ff -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
