# Recovery journal: 00462C30 `get_play_info`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/music.cpp`.
- PDB source: `C:\msdev\work\age1_x1\music.cpp`.
- Earlier recovery note: `recovery_notes/00462C30_get_play_info.md`.
- Logic-review ledger: `logic_reviews\00462C30_get_play_info.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:ff47b94c60fd34d7b38a -->
### `target-session` `build/target_sessions/00462C30_get_play_info.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 context; result=MATCH; diff=0; shape=100.0: Compile after authentic music.cpp constructor owner
```
<!-- end-recovered:ff47b94c60fd34d7b38a -->

<!-- recovered:848646f190ea0d9e6e0e -->
### `212bdb78fc39` `src/scratch/00462C30_get_play_info.cpp:1-56`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00462C30 TMusic_System::get_play_info (309B)
// PDB source: music.cpp lines 1127-1171
// Attempt log:
// Baseline: canonical non-polymorphic TMusic_System layout, natural output initialization,
// strcpy copy, and typed MCI status record/API surface reconstructed from the same-TU binary.
// Probe 2: early playing-track return plus one common result/status join improved structural
// parity but VC5 folded the two static MCI arms into one call (69 differing bytes).
// Probe 3: scoped result locals retained both calls but left duplicated status stores (82 bytes).
// Probes 4-6: binary-proven shared-tail/goto and early-return variants did not remove the
// duplicated tail or restore the original jump placement; best remained the common-result basin.
// Probes 7-9: nested if and direct per-case forms either folded a call or returned to the
// 165-byte baseline; probe 10's typed status alias was codegen-identical to probe 2.
// Final bounded result: restored the clean natural baseline. Remaining gap is the VC5
// switch/call tail topology: original has two static MCI call sites with one shared status
// store/final tail, while natural common-result source folds the calls and duplicated-arm
// source duplicates the store. Canonical fields, ABI, copy semantics, and runtime call
// behavior are established; leave unresolved for a future focused control-flow pass.
// Main-agent audit confirmed canonical non-polymorphic music/MCI ownership and
// retained the natural typed output/status flow.
// Fresh worker pass: deferring the status declaration and restoring the SDK
// mmsystem.h/MCI_STATUS_PARMS surface were codegen duplicates; the header cast
// is ABI-plausible but did not change VC5 output.
// Fresh worker pass: a 36-variant permutation of independent initial-output
// assignment order changed suffix bytes only; it never moved the first pointer
// home, so the register basin is not controlled by that store order.
// Fresh worker pass: early playing-track return remains the metric-best natural
// guard (69-byte diagnostic with one folded call); asymmetric goto/common-store,
// success-flag, and mixed inline/common-store forms either duplicated the tail,
// grew the frame body, or returned to the 165-byte baseline.
// Tail worker H1: applied resume_play's braced switch cases and case-local MCI
// results to the common status-store goto family, replacing the playing-track
// early return with done routing. Both MCI calls remained and the diff fell to
// 82 bytes; VC5 still placed the status pointer at [esp+14] and split case 1's
// success store from the common tail.
// Tail worker H2: scoped the status record to the active-track block. This was
// codegen-identical, so the H1 source remains the best structural reconstruction.
// Fresh pass: Cdaudio.cpp donors show the natural WinMM surface passes the full
// MCI_STATUS_PARMS record and reads dwReturn. This improved the current tail
// reconstruction by one byte; the reordered-field diagnostic was not retained.
// Fresh pass: an IAT function-pointer declaration was codegen-neutral.
// Fresh pass: direct zero-result jumps shortened the body to 322 bytes and left
// the closest current metric, but VC5 still duplicates the final tail and return.
// Current worker H1: corrected the standard MCI_STATUS_PARMS query field from dwTrack to dwItem.
// The original store is record offset +8, and this reduced the diff from 79 to 78 bytes.
// Current worker H2: matched the original error-first branch polarity; VC5 recovered both
// original call blocks and 98.92% exact-block coverage, but placed the shared store early.
// Current worker H3: restored a natural one-result typed switch; VC5 folded the identical
// MCI calls to one call (67-byte diagnostic), so it was not retained.
// Current worker H4: kept natural case-local result checks to preserve both typed MCI calls;
// this returned the 80-byte two-call basin with no raw offsets or compiler-only qualifiers.
// Current worker H5: reordered the typed switch arms to follow the original PDB call-line
// order; emitted code was unchanged. MCIERROR unsigned-long return type was also neutral.
// Final current reconstruction: standard WinMM record, dwItem query, full-record call, and
// dwReturn read are canonical. Remaining gap is VC5 shared-tail placement and one extra return.
// Previous bounded result: the typed WinMM surface and explicit success jump formed
// the prior best structural basin; the remaining gap was the shared MCI tail.
```
<!-- end-recovered:848646f190ea0d9e6e0e -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
