# Recovery journal: 004C7F50 `TRIBE_Building_Object`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/t_b_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\t_b_obj.cpp`.
- Earlier recovery note: `recovery_notes/t_b_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:96c0512f8bae6b931478 -->
### `7f3355354a67` `src/scratch/004C7F50_TRIBE_Building_Object.cpp:1-28`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C7F50, TRIBE_Building_Object::TRIBE_Building_Object
// PDB source: t_b_obj.cpp:57-76
//
// Canonical reconstruction: this is the seven-argument load/new constructor.
// The base and production-queue ownership are named rather than represented by
// decompiler cursor arithmetic.  The executable stores the derived vftable in
// the constructor body, but this source deliberately leaves vptr lowering to
// VC5; an explicit store or __declspec(novtable) is not an acceptable source
// model.
//
// Attempt log:
// - Typed the complete Static/Moving/Action/Combat base chain, master task
//   fields, player vptr/creator ownership, tile-table pointer array, and the
//   production-queue members. This reaches the original 311-byte size, frame,
//   saved registers, calls, CFG, and all post-constructor bytes.
// - Adding the proven player vptr is a codegen duplicate; it is retained for
//   canonical layout.
// - Restored the donor-proven virtual int setup, virtual set_task, and
//   TRIBE_Combat_Object destructor declarations; each was codegen-identical.
// - The only remaining drift is VC5's implicit derived-vptr store: rebuilt
//   writes offset zero before the queue initializers, while the executable
//   writes it after them. Explicit vptr assignment and __declspec(novtable)
//   diagnostics reached the bytes but are rejected as living source. Keep the
//   natural polymorphic constructor in scratch.
//
// FLAGS: /nologo /c /O2 /Oy /GX
// Main-agent audit restored canonical master/player destructor ownership and
// retained natural compiler-managed vptr lowering.
```
<!-- end-recovered:96c0512f8bae6b931478 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
