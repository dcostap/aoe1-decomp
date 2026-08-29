# Recovery journal: 004D23B0 `first_in_stack`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tact_tek.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tact_tek.cpp`.
- Earlier recovery note: `recovery_notes/tact_tek_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:da188a3037ec4ca8d348 -->
### `d050eea3c` `src/tact_tek.cpp:81-81`

Mapping: `strong`. next mapped function definition is first_in_stack at old line 86.

```text
// VA 004D2370; PDB tact_tek.cpp:68-73; matching.
```
<!-- end-recovered:da188a3037ec4ca8d348 -->

<!-- recovered:6c0b4930e69e29123e4a -->
### `d050eea3c` `src/tact_tek.cpp:88-88`

Mapping: `strong`. comment lies after mapped function first_in_stack at old line 86.

```text
// VA 004D23B0; PDB tact_tek.cpp:76-98; matching.
```
<!-- end-recovered:6c0b4930e69e29123e4a -->

<!-- recovered:17171072868466f586bf -->
### `a5fb96a1e6de` `src/scratch/004D23B0_first_in_stack.cpp:1-4`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TRIBE_Action_Make_Tech::first_in_stack
// VA: 004D23B0
// PDB: tact_tek.cpp:76-98
// No EH framing
```
<!-- end-recovered:17171072868466f586bf -->

<!-- recovered:39b2c744efbdc710931e -->
### `a5fb96a1e6de` `src/scratch/004D23B0_first_in_stack.cpp:100-100`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // Vtable calls for non-match path
```
<!-- end-recovered:39b2c744efbdc710931e -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
