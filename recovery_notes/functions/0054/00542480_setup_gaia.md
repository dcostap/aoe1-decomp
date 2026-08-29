# Recovery journal: 00542480 `setup_gaia`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/world.cpp`.
- PDB source: `C:\msdev\work\age1_x1\World.cpp`.
- Earlier recovery note: `recovery_notes/world_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:fd54922de680f39472b9 -->
### `e5b22f4df482` `src/scratch/00542480_setup_gaia.cpp:1-35`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00542480 RGE_Game_World::setup_gaia()
// PDB source: World.cpp lines 1156-1159 (104 bytes, 34 asm lines)
// FLAGS: config/flags/00542480_setup_gaia.rsp uses /GX for original EH new-expression frame.
// No inline asm/hacks.
//
// Behavior: allocate an RGE_Player (sizeof 0x220), construct it as GAIA with
// (this, *master_players, 0, "GAIA", 0, 1), then store it through *players.
//
// Attempt log:
// - Baseline explicit null normalization matches EH prologue/allocation/ctor args/call/null xor/common-store
//   family but VC5 inserts redundant `test eax,eax; jne +0` at the ctor/null join before loading players.
//   Best result: 104/104 bytes, positional diff 16.3462%, edit diff 7.6923%, 100 equal after resync.
// - Direct `*players = new ...` removes redundant join test but changes to success-path store/null-to-tail family
//   (diff 21.1538%).
// - Assignment-in-condition produced extra boolean/sete plumbing at the join, worse.
// - Hoisting `players` local adds EDI/save and shifts the EH frame; worse.
// - Local-only declarations versus shared include: no effect from baseline.
// - Manual `operator new` + explicit constructor loses VC5 EH new-expression lowering (80-byte text), wrong family.
// - /Ob0 with explicit null normalization: no effect. /O1 /GX: wrong 86-byte family. Removing /GX: wrong 64-byte
//   non-EH family. Restored /GX-only flag.
// - Hoisting `*master_players` into a local adds EDI/save and shifts call setup; worse.
// - Narrow ctor parameter declarations (`char` flags, `char*` name) do not affect the blocker.
// - 2026-05-10 pass on this VA only: retried 15+ variants: direct, if-null/if-not/goto common-store,
//   assignment-in-condition, zero-init, volatile pointer, bool temp, empty-if, if/else member stores, hoisted
//   players/master locals, char ctor flags/name, void* store, comma/no-op forms. No exact. Best remains the
//   current explicit null-normalization/common-store shape: edit diff 7.6923%, positional 16.3462%; mismatch
//   is a redundant join `test eax,eax; jne +0` that shifts the final FS restore and truncates add/ret out of
//   the 104-byte window, so not an accepted_drift suggestion under Boss's truncation ruling.
// - 2026-05-10 SpruceGlow Boss-assigned pass: revalidated current best and tried 16 variants:
//   direct/local assignment, if-null/if-not, goto common/null, players/master locals, member reference,
//   store-in-both-arms, volatile pointer, bool temp, zero-init, assignment-in-if, and explicit casts.
//   No exact. Direct/local sink store to success path. Common-tail variants keep the redundant join test.
//   Member-reference reduced positional diff to 14 but worsened edit diff and still changes tail layout, so not kept.
// Left in scratch: same null-path/common-store join blocker as sibling World init helpers. Allocation size, EH frame,
// ctor args/call, final store, stack cleanup, and behavior are understood.
```
<!-- end-recovered:fd54922de680f39472b9 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
