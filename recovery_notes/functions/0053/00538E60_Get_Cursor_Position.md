# Recovery journal: 00538E60 `Get_Cursor_Position`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/view.cpp`.
- PDB source: `C:\msdev\work\age1_x1\view.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:01cc69fa631686707f2f -->
### `target-session` `build/target_sessions/00538E60_Get_Cursor_Position.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 layout; result=MATCH; diff=0; shape=100.0: Use inherited TPanel render_area and render_rect aliases in the authentic shared context; original accesses prove offsets +20 and +8C..+98.
```
<!-- end-recovered:01cc69fa631686707f2f -->

<!-- recovered:eee2eed089bfe917594f -->
### `caa20929b406` `src/matching/00538E60_Get_Cursor_Position.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00538E60 RGE_View::Get_Cursor_Position
// Source: view.cpp lines 4716-4741. 151 bytes. __thiscall, ret 0Ch.
```
<!-- end-recovered:eee2eed089bfe917594f -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
