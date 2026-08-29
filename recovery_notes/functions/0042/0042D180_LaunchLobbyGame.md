# Recovery journal: 0042D180 `LaunchLobbyGame`

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


<!-- recovered:3b740a910451adf4bdd5 -->
### `8558dca82389` `src/scratch/0042D180_LaunchLobbyGame.cpp:1-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0042D180 TCommunications_Handler::LaunchLobbyGame (Com_hand.cpp:5332-5436, 329B)
// Left in scratch: 320/329 bytes match (~2.7% remaining).
// Issues:
// - Frame size 0x54 instead of 0x58 (need 4 more bytes local allocation)
// - COM __stdcall Release: need `mov ecx,[eax]; push eax; call [ecx+8]` but getting
//   `mov edx,[ecx]; call [edx+8]` (missing push, different register)
// - `r` result variable causes extra `mov [esp+NN],eax` stores vs original `mov edi,eax`
// - Global access: getting `mov ecx,[addr]` (6B) vs `mov eax,[addr]` (5B)
// - Session info offset different due to frame layout
// Best path: variant_lab on frame size + COM call pattern + result variable removal
// FLAGS: /nologo /c /O2 /Oy
```
<!-- end-recovered:3b740a910451adf4bdd5 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
