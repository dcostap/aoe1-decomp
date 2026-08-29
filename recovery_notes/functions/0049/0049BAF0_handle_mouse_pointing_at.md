# Recovery journal: 0049BAF0 `handle_mouse_pointing_at`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_game.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_game.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:bdd45011e87c422dd5d2 -->
### `target-session` `build/target_sessions/0049BAF0_handle_mouse_pointing_at.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 context; result=MISMATCH; diff=328; shape=78.0952380952381: Restore the period Windows API declaration needed by the natural foreground-window guard.
```
<!-- end-recovered:bdd45011e87c422dd5d2 -->

<!-- recovered:1f6d1d44806aceec1922 -->
### `7f9d273d677d` `src/matching/0049BAF0_handle_mouse_pointing_at.cpp:1-15`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0049BAF0 handle_mouse_pointing_at (358B)
// scr_game.cpp:4717-4840
// Natural same-TU reconstruction of the foreground/focus/modal gate, mouse
// position tracking, map pick, and button tooltip scan.
// Attempt log (sa-66340ab1-handle_mouse_pointing_at):
// - baseline typed source had exact frame/call/CFG but a -6-byte base-layout
//   shift and a broad loop mismatch.
// - restored the canonical 0xF4 TPanel/0x478 TScreenPanel sizes; this aligned
//   all screen fields and isolated the button scan.
// - reloaded *slot for the enabled/get_id/virtual-action checks, preserving the
//   binary's slot-address liveness and inline help-text ownership.
// - changed the ordinary do/while to a natural while(i < 17) header; VC5 then
//   emitted the original jl backedge/jmp-over-found-arm and all 358 bytes match.
// - Main-agent audit restored canonical base-game destructor ownership and
//   retained the typed panel/button scan; exact bytes were revalidated.
```
<!-- end-recovered:1f6d1d44806aceec1922 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
