# Function notes: 00449990 `numberOfFilesWithFilenameOrAttribute`

## Recovered attempt history

<!-- recovered:c0f5ae2b5742804d2ef6 -->
### `a9a8fe10cd56` `src/scratch/00449990_numberOfFilesWithFilenameOrAttribute.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00449990 DriveInformation::numberOfFilesWithFilenameOrAttribute
// file_stf.cpp lines 167-180
//
// attempt 1-3: eager saves (ebx,ebp,esi,edi at prologue) vs lazy (only esi)
// attempt 4: defer count declaration, goto, block scope — all eager still
// Remaining 73%: VC5 register save heuristic — original uses lazy saves,
// rebuilt uses eager. Deep codegen basin; not controllable from C source.
// Retry 2026-05-19/20 assigned pass:
// - Revalidated baseline/default: exact size 144B, 72.9167% positional / 54.1667% edit; rebuilt eagerly saves EBX/EBP/ESI/EDI at entry, unlike original lazy saves (ESI first, EDI after first findnext, EBP/EBX only inside loop).
// - Moved `count = 1` before the first `_findnext` and returned `count` on no-next; worsened to 76.3889% and still eager saves; rolled back.
// - /Ob0 flag probe did not alter eager-save basin; removed.
// GIVEUP: no accepted_drift. Mismatch is broad prologue/save and control-flow layout drift, not localized.
// Left in scratch.
```
<!-- end-recovered:c0f5ae2b5742804d2ef6 -->
