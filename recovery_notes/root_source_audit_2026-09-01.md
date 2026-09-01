# Root source audit: 2026-09-01

This audit covers merged source changes after `0e8f2b409`.

## Accepted exact changes

- `805a06ddb`: `004C1840 setup`. Root reproduced the 1,184-byte match.
- `035af02a8`: `00512250 save`. Root reproduced the 351-byte match.
- `55c9d98ec`: `00515BB0 notifyAI`. Root reproduced the 531-byte match. Exact `save` stayed unchanged.

## Retained mismatch changes

- `3d73c8bf2`: Keep the `done.ExecuteOnTurn` assignment in its only send path. The value has no use outside that path.
- `92277c3b2`: Keep the clipped-right assignment order. Both forms assign the same two local values without added effects.
- `c5e56240a`: Keep PDB-supported signed `int count`. The unsigned-short cast limits the value to 0 through 65,535.
- `9125db1a4`: Keep PDB-supported `long x` and `long y`. Win32 `long` and `int` have the same 32-bit width.
- `b5c868254`: Keep PDB-supported local lifetimes and case-1 coordinate values. Each value is assigned before use.
- `b2a66f3a9`: Keep PDB names and integer-equivalent clamps. `value < 9` and `value <= 8` are equal for signed integers.

## Corrected mismatch changes

- `ecd48abfb`: The executable proves two indexed array checks. Root replaced the manual second guard and raw `value[]` access with a second natural `operator[]` access.
- `9a3f57869`: Keep threshold-first terrain evaluation. The executable reads the terrain table before exception comparisons. Root removed the byte cursor and manual tile stride. Typed tile indexing now owns the access.
- `93969f516`: Root rejected `Scan_State`. It was a synthetic aggregate used to alter stack homes. Independent `long` locals now own `count` and `row_index`.

## Validation

Root rebuilt the three corrected targets and ran one-job translation-unit audits.

- `aiuaimod`: 104 matching results. The shared direct `resize` binding remains unresolved.
- `pathsys`: 16 matching results. All 11 target calls align.
- `rmm_terr`: 8 matching results. The target has no calls.

The repository test suite passed before these source corrections: 286 tests and 24 subtests. Focused checks will run with the correction commit.

## Integration rule

Do not merge a source-changing worker commit from its report alone. Root must inspect the complete function and diff first. Root must confirm behavior, ownership, types, fault order, and the affected closure.
