# Recovery journal: 0051E790 `~Time_Line_Panel`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tpnl_tml.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tpnl_tml.cpp`.
- Earlier recovery note: `recovery_notes/tpnl_tml_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:4f2bea14a87d391d6a96 -->
### `df7d3ff083f2` `src/matching/0051E790_Time_Line_Panel.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0051E790 ~Time_Line_Panel (tpnl_tml.cpp:116-141)
// PDB source: tpnl_tml.cpp (Time_Line_Panel::~Time_Line_Panel)
//
// Attempt log:
// attempt 1: manual dtor+op delete; 192/206b, no EH frame.
// attempt 2: delete operator + virtual dtors for EH frame. EXACT MATCH.
// Key: virtual destructors in TPanel/TEasy_Panel/Time_Line_Panel force VC5
//   to emit EH frame (push -1; push handler; mov [fs:0],esp). Automatic base
//   dtor call (not explicit), proper linked-list walk using p->next before free.
//   Offsets: TPanel vtable at +0x00 (compiler-managed). 12 relocations masked.
// BINARY NOTE: this owner shares the complete tpnl_tml.cpp class declarations
// with the earlier constructor and the later create_timeline owner.
// context probe: the authentic ordered group remains an exact 206-byte owner.
```
<!-- end-recovered:4f2bea14a87d391d6a96 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
