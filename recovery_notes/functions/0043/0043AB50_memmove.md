# Recovery journal: 0043AB50 `memmove`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Dib.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Dib.cpp`.
- Earlier recovery note: `recovery_notes/Dib_module.md`.

## Translation-unit context

The owner is the free function `memmove` in `Dib.cpp`, at PDB lines 1770-1776.
It follows `xlatRle4` and precedes `DibMapToPalette`. The original body is 42
bytes, has no frame, saves `esi`, and has no calls or relocations. Its only
incoming call is from `DibMapToPalette`, which ignores the return value.

## Current mismatch

The final natural grouped-TU check is `MISMATCH`: 39 differing bytes
(`84.7826%`), 46 rebuilt bytes versus 42 original bytes, 24 versus 19
instructions, and shape `62.50%`. The frame is absent in both bodies. The
rebuilt body saves `ebp`, `esi`, and `edi`; the original saves only `esi`.
Calls and relocations are zero, the owner symbol matches, and the rebuilt
boundary escapes by four bytes. The first mismatch is at `+0001`. The first
structural hunk is the grouped-TU prologue and return preservation.

## Recovered attempt history


<!-- recovered:3b5973f3840b00048124 -->
### `b25c5800db4c` `src/scratch/0043AB50_memmove.cpp:1-12`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0043AB50 memmove (42B)
// PDB source: Dib.cpp lines 1770-1776
// BINARY NOTE: Dib.cpp has already included the CRT memmove declaration when
// this owner is grouped. The canonical return and const source surface avoids
// a C-linkage conflict; the helper's return value is unused by its caller.
// TU captain, 2026-08-26, owner sa-c6a4d383-r1:
// - The original source form with a separate count local and no parameter
//   reload reduced the mismatch from 39 bytes to two LEA SIB bytes.
// - Pointer arithmetic, endpoint indexing, declaration order, and byte-pointer
//   parameter probes were codegen duplicates.
// - Returning the decremented working pointer changed the public return value.
//   It was rejected despite its smaller two-byte mismatch.
```
<!-- end-recovered:3b5973f3840b00048124 -->

## Rejected approaches

The natural reverse byte-copy body with `return dst_arg` is retained. It keeps
the original endpoint formation, zero-count guard, backward copy order, and
fault order. A `return dst` variant produced the original 42-byte shape and
only two differing LEA SIB bytes, but it returns `dst_arg - 1` after copying.
That changes the public `memmove` return contract and remains rejected.

Reversing the commutative pointer-add operands produced the same two-byte
variant. Endpoint indexing was also tested, but the target-session check
timed out while waiting for `build/target_sessions/sessions.lock`; no result
was recorded for that probe. Do not force or delete that lock.

## Open questions

The original function has an unknown source return type. Its caller ignores
the return value, while the natural grouped source must use the CRT-compatible
`void*` declaration. The remaining difference is a grouped-TU code-generation
effect from preserving `dst_arg`, not a missing copy operation.

## Next useful approaches

If further work is assigned, first test a period-plausible declaration context
that proves the original return type without changing the custom reverse-copy
semantics. Avoid CRT replacement. Rebuild after any source-context change.

## Worker updates

### 2026-08-29 `wave10-dib`

Started the target session and rebuilt the stale grouped-TU evidence. The
baseline was 39 differing bytes with a 46-byte body. Returning the decremented
working pointer reduced the result to two differing bytes, both LEA SIB
register-map bytes, but changed the public return value. Reversed pointer-add
operands were a code-generation duplicate. The final source restores the
canonical return and natural pointer arithmetic. Final validation reports the
same 39-byte mismatch. One endpoint-indexing check hit target-session lock
contention and was not retried.
