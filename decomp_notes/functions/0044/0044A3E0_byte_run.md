# Function notes: 0044A3E0 `byte_run`

Module notes: `decomp_notes/flics_module.md`.

## Recovered attempt history

<!-- recovered:585eb774b3bdb17473d2 -->
### `891c039ce4cb` `src/scratch/0044A3E0_byte_run.cpp:1-62`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// RGE_Flic_Player::byte_run
// VA: 0044A3E0 (217 bytes)
// Decodes byte-run compressed FLIC frames
// Attempt log:
// - Baseline CRT fill/copy candidate was structurally close but used the wrong
//   row ownership/lifetime and saved EBX as this (195 differing bytes).
// - Restored canonical fields, loaded chunk before the guard, reset the row
//   offset per row, shared the run local, and put the fill arm first.  This
//   recovered the original branch topology and a 0xC frame, but not the final
//   register basin (163 differing bytes, rebuilt body 208 vs 217 bytes).
// - Manual-loop, destination-local, alias, and declaration-scope variants were
//   tested and either regressed or produced duplicate codegen.  Best source is
//   retained here; remaining drift is the original ESI/EBX coloring and
//   line-offset spill/layout around the rep-string paths.
// Fresh exact pass (2026-08-09):
// - Same-TU full-class context, long/int width changes, signed-char opcode,
//   declaration-order, and register-qualified locals were neutral or worse.
// - Byte mutation in the negative arm is binary-supported by the observed
//   `neg al`; direct member access plus that form gives the best current 217-byte
//   reconstruction (160 differing bytes), but the ESI/EBX basin remains open.
// - Materializing the fill byte before the destination address worsened the
//   body to 222 bytes / 177 differing bytes; rolled back.
// - Signed-char opcode with in-place negation reproduced an older 208-byte /
//   163-byte-diff basin; rolled back as duplicate negative evidence.
// - Binary CFG confirms the stream header advances once per row after the
//   line-offset reset; moving `chunk++` into that outer loop improved the
//   reconstruction to 99 differing bytes and recovered the original ESI=this
//   basin, at the cost of four extra emitted bytes.
// - Signed negative-arm, one-byte union, branch-local count, short-count, and
//   cast-after-negation variants regressed or duplicated; retain the unsigned
//   opcode source with the per-row advance.  Remaining drift is the negative
//   arm's `and eax,0xff` versus original `movsx ebp,al` scheduling.
// - This claim: direct signed-byte casts, branch-local negative counts, and an
//   explicit unsigned-wrap/signed-cast expression all landed in the same
//   217-byte/107-diff basin with sign extension hoisted before `jl`; restore
//   the 221-byte/99-diff natural candidate, whose only structural drift is the
//   negative-arm widening and downstream four-byte displacement shift.
// - This claim: signed opcode/negative-cast forms hoisted sign extension
//   before the binary-proven `test al/jl`, and an unsigned high-bit range test
//   emitted `cmp al,80h`; both regressed.  Retain the 221-byte / 99-diff
//   natural unsigned-opcode candidate.  The remaining gap is isolated to
//   negative-arm `and eax,0xff` versus oracle `movsx ebp,al`.
// [non-comment lines omitted during migration]
// Main-agent audit confirmed canonical FLIC player/frame ownership and retained
// the natural packed-byte decoder.
```
<!-- end-recovered:585eb774b3bdb17473d2 -->
