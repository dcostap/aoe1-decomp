# Logic review: 00480610 `RGE_TimeSinceLastCall::GetHiLoInfo`

Current source: `src/rge_tslc.cpp`. This ledger contains historical review evidence.

## Phase transition

The main agent suspended ordinary exact matching after numerous independent passes, more than thirty meaningful source/type/control-flow/liveness hypotheses, a focused 48-case variant lab, and repeated convergence on stable VC5 parameter-home/register-allocation basins. An independent phase-readiness audit found no unresolved behavior, ABI, layout, call, or memory-effect fact, but required removal of codegen-only control-flow residue before ledger entry.

The reviewed candidate was `src/rge_tslc.cpp`. Before entry, the main agent removed a redundant positive-count guard already implied by the `1..100` range and normalized an empty positive branch to `if (idx <= 0) idx = 100`. The previously pinned 11-byte diagnostic used fake volatile/home-read scaffolding and is not the review candidate.

Current validated normalized checker state:

- original/rebuilt meaningful size: 132/126 bytes (128 extracted);
- frame: none/none;
- saved registers: `ebx, ebp, esi, edi` / `ebx, ebp, esi, edi`;
- calls: 1/1, ordered and target-aligned (`sprintf`);
- original/rebuilt instructions: 54/54;
- CFG: 7/6 conditional branches, 1/1 jump, 1/1 return;
- instruction-shape similarity: 87.04%; exact-block coverage: 33.33%;
- strict difference: 108 bytes in 3 spans, first mismatch `00480626`;
- edit/resync cost: 42 raw, 16.15% bounded, 104 equal bytes.

### Cumulative matching evidence

- Repeated passes tested exact class layout, signed/unsigned local surfaces, declaration and initialization order, direct parameter countdown, parameter-home aliases, register qualifiers, natural loop forms, compare algebra, invalid-path assignment forms, focused flags, and a 48-case home/tail lab.
- The closest 11-byte emitted candidate required fake volatile stack-home rereads and empty/redundant branch scaffolding. Those forms were rejected during source normalization despite their better metrics.
- Exact same-TU donors prove `RGE_TimeSinceLastCall` layout and the `__thiscall char*(int)` surface.
- The normalized candidate uses ordinary bounded control flow, unsigned accumulation/division, named fields, and one `sprintf` call; no opaque scheduling trick remains.

### Semantic questions at entry

Blind reviewers must establish directly from the executable:

1. Exact valid range, offset decrement/wrap rule, array element range, and loop iteration count.
2. Signedness/width of sum, minimum, maximum, quotient, and `sprintf` arguments, including overflow and division behavior.
3. Exact invalid-count fallback values and whether any array/member read occurs on invalid inputs.
4. Evaluation and memory-read order, especially for invalid object pointers and unusual `Offset` values.
5. Format string, argument order, destination buffer, return pointer, calling convention, and cleanup.
6. Whether normalization removed only redundant source conditions or changed any binary-observed edge behavior.

## Review rounds

### Round 1

- Numeric/control reviewer found no blocking difference. It verified the signed
  valid range 1..100, invalid-path fallback values, decrement/wrap behavior for
  malformed offsets, unsigned accumulation/division overflow, output argument
  order, return pointer, and all member-read/fault paths. It classified the
  removed positive-count guard as unreachable codegen residue.
- The reviewer noted that the rebuilt symbol surface names the CRT `_sprintf`
  import while the executable target at 0054BBC0 is the game's sprintf wrapper;
  checker relocation evidence must settle identity before final promotion even
  though `%d` output is expected equivalent.
- The concurrent adversarial reviewer remains pending.
- Adversarial reviewer confirmed the core values and ABI but found a substantive
  stack-home difference: the candidate wrote the final quotient back over the
  countdown home and initialized that home before reading `Offset`; the
  executable reads `Offset` first and leaves the valid-path home at zero.
  Verdict: needs attention.

## Main-agent adjudication

The stack-home finding is substantive for stack aliases and fault handlers. The
main agent integrated it by separating `average` from `remaining` and delaying
countdown initialization until after the valid-path `Offset` read. The emitted
candidate now preserves the executable's home value and read/write order. The
unreachable positive-count guard remains intentionally normalized away.

## Integrated changes

- Removed codegen-only redundant/empty branch scaffolding.
- Revalidated and repinned the normalized natural source; the expected metric regression from the 11-byte diagnostic to 108 strict bytes is explicitly nonsemantic pending blind verification.
- Separated average/result storage from the loop countdown and delayed countdown
  initialization until after `Offset`. Post-fix checker state is 120/132 bytes,
  97 strict differing bytes, first mismatch +0x17, 1/1 ordered call, and 79.63%
  exact-block coverage. A fresh post-fix blind review is required.

### Round 2 (post-fix)

- Stack/numeric reviewer found no blocking difference. It independently verified
  the corrected `Offset`-before-countdown initialization, zero countdown home
  versus register-held quotient, valid/invalid results, malformed-index behavior,
  unsigned overflow/division, format arguments, return and `ret 4` ABI.
- Adversarial reviewer independently found no behavioral divergence under
  ABI-valid execution. It verified the same layout, valid/invalid paths,
  countdown and unsigned arithmetic, malformed-offset reads/faults, exact
  `sprintf` target/arguments, return and cleanup. The omitted redundant
  `test/jle`, invalid-path register setup, and volatile residue were classified
  as codegen-only.

## Exact promotion

A later grouped recovery restored the natural inner positive-count branch and
valid-path-only output assignments. The candidate passed fresh grouped validation:
132 of 132 bytes, `MATCH`, `0.0000%`, correct owner, boundary, relocations,
and direct `sprintf` target.

The exact source now lives in `src/rge_tslc.cpp`.
The prior verified-logic decision is historical only.
