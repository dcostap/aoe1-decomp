# Recovery journal: 004D68A0 `compare`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `accepted_drift`.
- Living source: `src/taiconmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taiconmd.cpp`.
- Earlier recovery note: `recovery_notes/taiconmd_module.md`.

## Translation-unit context

The PDB module is `taiconmd.cpp`. The owning class is
`TribeConstructionAIModule`. The natural owner is `src/taiconmd.cpp`.
The target follows `setBuilt` at `004D6800` and precedes the padding after the
41-byte body. The protected owner symbol is
`?compare@TribeConstructionAIModule@@IAEPAVConstructionItem@@PAV2@0@Z`.
The six registered exact neighbors remain the module anchors.

## Current mismatch

The final focused check is `MISMATCH`, 12 bytes, or 29.2683%. The original and
rebuilt bodies are both 41 bytes with no frame. Both save `ebx`, `esi`, and
`edi`. Both have two aligned direct `buildAttempts` calls, one conditional,
one return, zero relocation mismatches, and zero boundary escapes. The rebuilt
owner is correct.

The retained source stores the first result in a local. It evaluates `left`
before `right`, which preserves the observed null-fault order. VC5 uses a
different register allocation and saves `edi` before the first load. The
diagnostic class is `PARTIAL_REGISTER_RECOLOR`.

## Recovered attempt history

### Final natural source

```cpp
int leftAttempts = left->buildAttempts();
if (leftAttempts > right->buildAttempts()) {
    return right;
}
return left;
```

This source remains the clean natural reconstruction. It uses the canonical
const `ConstructionItem::buildAttempts` declaration and target.

### Tested hypotheses

- A direct unqualified comparison reduced the byte diff to 5, but VC5 called
  `right` first. It does not preserve the proven null-fault order.
- Conditional-return, pointer-alias, const-reference, register-qualified,
  split-assignment, and reversed-condition forms did not improve the natural
  left-first result. They emitted the same 5- or 12-byte basins.
- Explicit `ConstructionItem::buildAttempts` qualification reduced the diff to
  2 bytes, but it still evaluated `right` first. It is not retained as a
  metric-only source tweak.
- The old standalone exact donor used a non-const `buildAttempts` declaration
  and emitted the QAE symbol. The canonical shared declaration emits QBE, which
  is the original `0040AA20` symbol. The old donor does not prove the shared
  ABI or the natural TU codegen.


<!-- recovered:9dd503b5d80ce7b1a726 -->
### `d050eea3c` `src/taiconmd.cpp:258-258`

Mapping: `strong`. comment lies after mapped function compare at old line 252.

```text
    // BINARY NOTE: Read left first. A null left faults before a null right.
```
<!-- end-recovered:9dd503b5d80ce7b1a726 -->

<!-- recovered:c37d10476ee685a9d130 -->
### `target-session` `build/target_sessions/004D68A0_compare.json:1-2`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Baseline before access repair; target bytes are exact, but grouped symbol audit reports public QAEP instead of PDB protected IAEP.
probe 2 abi; result=MATCH; diff=0; shape=100.0: Protected compare declaration follows PDB decorated owner IAEP; bytes should remain unchanged while owner symbol is corrected. [same emitted code as probe 1]
```
<!-- end-recovered:c37d10476ee685a9d130 -->

## Rejected approaches

The direct comparison and explicit-qualified comparison are rejected for the
final source because both evaluate `right` before `left`. The conditional,
alias, reference, register-qualified, and split-local variants either repeat
those basins or add source machinery without recovering the target bytes.

## Open questions

The remaining question is whether a period source form can force the original
left-first VC5 schedule while retaining the canonical const member ABI. The
tested natural forms did not find one. A future worker needs new source or
toolchain evidence, not more cosmetic register hints.

## Next useful approaches

Review the 12-byte register recolor as a possible accepted-drift proposal.
Any proposal must cite the left-first fault order, the two QBE calls, argument
order, cleanup, boundary, and owner evidence. Do not promote this scratch
target from byte metrics alone.

## Worker updates

### wave20-taiconmd

- Result: improved natural reconstruction retained; exactness unresolved.
- Focused final check: `MISMATCH`, 12 bytes, 29.2683%, 94.44% shape,
  100.00% aligned calls, owner match, zero relocation mismatches, and zero
  boundary escapes.
- Grouped audit:
  `python tools/audit_translation_unit_observed.py --group taiconmd --jobs 1`
  with worker output under
  `build/audits/workers/wave20-taiconmd/taiconmd`. It found six registered
  exact-owner matches, one grouped match not registered, and two grouped
  mismatches (`placeStructure` and this target).
- The worker made no status or registration change.

### Coordinator accepted-drift review

The coordinator approved accepted drift after the wave closed. Both bodies are
41 bytes. They have the same owner, frame, saved registers, left-first fault
order, two const `buildAttempts` calls, comparison, return values, boundary,
and relocations. The difference is register allocation around the two calls.
The left-first local-result source remains because direct forms reverse the
proved call and fault order.
