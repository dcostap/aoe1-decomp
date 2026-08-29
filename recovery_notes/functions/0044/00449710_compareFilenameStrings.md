# Recovery journal: 00449710 `compareFilenameStrings`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/file_stf.cpp`.
- PDB source: `C:\msdev\work\age1_x1\file_stf.cpp`.
- Earlier recovery note: `recovery_notes/file_stf_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:ac699e7d598df4c93640 -->
### `7adef504ea1e` `src/scratch/00449710_compareFilenameStrings.cpp:1-20`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00449710 compareFilenameStrings
// file_stf.cpp lines 20-22
// 59 bytes
// BLOCKER: VC5 optimizes 2-byte-at-a-time loop into 1-byte-at-a-time.
// The original processes 2 bytes per iteration (add eax,2; add esi,2)
// with eax/esi as pointers and cl as saved second byte. Our VC5
// generates inc ecx; inc edx (byte-at-a-time) regardless of source shape.
//
// Attempt log:
// - while(1) with explicit 2-byte loop: VC5 optimizes to byte-at-a-time
// - do-while with a[-1] check: same optimization
// - separate inc a; inc b twice instead of a+=2: same
// - int locals for byte values: same
// - goto-style break with unified diff return: same
// - unsigned char* with explicit single-byte loads: same
// - while(*a==*b) with inner if breaks: same
// - literal Ghidra decomp with bVar2 boolean tracking: same
// FLAGS: none
// NOTE: Might be VC5 CRT strcmp-style pattern, or a different VC5 version.
// The 2-byte optimization is not reproducible with our build setup.
```
<!-- end-recovered:ac699e7d598df4c93640 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
