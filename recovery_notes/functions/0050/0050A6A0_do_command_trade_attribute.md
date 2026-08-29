# Recovery journal: 0050A6A0 `do_command_trade_attribute`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tcommand.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tcommand.cpp`.
- Earlier recovery note: `recovery_notes/tcommand_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:b4e9af4c0473bbe54761 -->
### `037950f4de84` `src/scratch/0050A6A0_do_command_trade_attribute.cpp:1-5`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// first pass was too generic; VC5 drifted immediately in the prolog because the signature/stub shape was off
// tried a byte counter and a pointer temp; VC5 saved ebx up front instead of using the original eax/bl basin
// tried int counter + unsigned char* walk; still missed at entry because VC5 kept choosing the wrong save/register basin
// current gap: prolog/register shape at the first counter load, not the loop body or call sequence
// next try: exact TRIBE_Command method signature with the packed 4-byte object-id walk kept as close to the asm as possible
```
<!-- end-recovered:b4e9af4c0473bbe54761 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
