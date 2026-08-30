# Recovery journal: 00447420 `uppercase`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/dstring.cpp`.
- PDB source: `C:\msdev\work\age1_x1\dstring.cpp`.
- Earlier recovery note: `recovery_notes/dstring.md`.

## Translation-unit context

- PDB module: `dstring.cpp`, source order 392-395, owner `DString::uppercase`.
- Natural owner: `src/dstring.cpp`, class declaration: `include/dstring.h`.
- Original body range: `00447420-00447451` (50 bytes, 22 instructions).
- The source body uses `int index`, a positive-length guard, and a `do` loop.
- The loop calls `length`, `_toupper`, and `length` in that order.

## Current mismatch

- Fresh natural check: 50/50 bytes, no frame, saved `esi` and `edi` match.
- Owner, boundary, call count, call order, relocations, and all control flow match.
- Current result: `MISMATCH`, 2 bytes, 4.0000%, with 48 equal bytes.
- First mismatch: `00447434`, the SIB byte in `movsx ecx,[eax+esi]`.
- Second mismatch: `00447444`, the SIB byte in `mov [edx+esi],al`.
- Rebuilt SIB forms are `[esi+eax]` and `[esi+edx]`.
- Both forms use scale one. They address the same bytes because addition is commutative.

## Recovered attempt history

- Baseline and final validation checks both produced the same 2-byte mismatch.
- A standalone old source with an explicit C-linkage `toupper` declaration matched all 50 bytes.
- The current natural translation unit uses canonical `<ctype.h>` declarations.
- This context produces the two SIB operand-order bytes in both `uppercase` and `lowercase`.
- Variant probes tested pointer expressions, references, temporary locals, casts, loop forms, and declarations.
- These probes produced the same 2-byte mismatch or changed the function shape.
- No natural body change improved the current source.

## Rejected approaches

- Pointer aliases and element references added register pressure or preserved the same basin.
- Arithmetic rewrites such as `index + 0` normalized to the same basin.
- Guard, increment, and loop-condition rewrites changed predicates or preserved the same SIB bytes.
- Function-local declarations did not reproduce the old standalone declaration context.
- No artificial compiler steering, raw address, wrapper, or inline assembly was retained.

## Open questions

- The original source declaration context is not present in the natural module.
- The remaining question is whether this narrow encoding drift is acceptable.

## Next useful approaches

- Review the narrow accepted-drift proposal below.
- If exact bytes remain required, test a reviewed source-context change outside this function assignment.

## Accepted-drift proposal

- Proposed scope: the two SIB bytes at offsets `+0x14` and `+0x24` only.
- Original uses `[eax+esi]` and `[edx+esi]`; rebuilt uses `[esi+eax]` and `[esi+edx]`.
- EAX and EDX hold `this->stringValue`; ESI holds the same loop index in both builds.
- Scale-one addition gives identical effective addresses for every index.
- The builds have identical size, frame, owner, boundaries, calls, targets, relocations, and control flow.
- The accesses have no side effects. Fault order remains unchanged.
- This is a proposal only. The coordinator decides status.

## Worker updates

- `wave21-dstring`: retained the natural source. Fresh check and grouped audit both show 2-byte SIB drift.
