# Recovery journal: 004261E0 `~TCommunications_Handler`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_hand.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Com_hand.cpp`.
- Earlier recovery note: `recovery_notes/com_hand_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:a2add3923836089f173c -->
### `d050eea3c` `include/com_hand.h:17-19`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// 004261E0, 00426650, and 00426FC0. The constructor anchor uses Com_hand.cpp
// lines 268-332 with /GX.
// The original FPO/PDB symbol proves protected CommOut(unsigned long,
```
<!-- end-recovered:a2add3923836089f173c -->

<!-- recovered:3c88ce4752b04afe42f2 -->
### `target-session` `build/target_sessions/004261E0_TCommunications_Handler.json:1-32`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=299; shape=96.85039370078741: Baseline current natural destructor source; verify call set, frame, boundary, and first mismatch.
probe 2 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_224740: 5 variants, 4 invariant-eligible, 0 exact
probe 3 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_224954: 20 variants, 8 invariant-eligible, 0 exact
probe 4 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225136: 80 variants, 32 invariant-eligible, 0 exact
probe 5 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225245: 64 variants, 64 invariant-eligible, 0 exact
probe 6 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225308: 1 variants, 1 invariant-eligible, 0 exact
probe 7 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225350: 1 variants, 1 invariant-eligible, 0 exact
probe 8 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225414: 1 variants, 1 invariant-eligible, 0 exact
probe 9 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225442: 1 variants, 0 invariant-eligible, 0 exact
probe 10 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225501: 1 variants, 1 invariant-eligible, 0 exact
probe 11 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225522: 1 variants, 1 invariant-eligible, 0 exact
probe 12 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225541: 1 variants, 0 invariant-eligible, 0 exact
probe 13 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225554: 1 variants, 1 invariant-eligible, 0 exact
probe 14 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225609: 1 variants, 1 invariant-eligible, 0 exact
probe 15 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225646: 1 variants, 1 invariant-eligible, 0 exact
probe 16 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225659: 1 variants, 1 invariant-eligible, 0 exact
probe 17 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225715: 1 variants, 1 invariant-eligible, 0 exact
probe 18 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225725: 1 variants, 1 invariant-eligible, 0 exact
probe 19 variant; result=MISMATCH; diff=299; shape=96.85039370078741: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260816_225815: 4 variants, 4 invariant-eligible, 0 exact
probe 20 liveness; result=MISMATCH; diff=38; shape=100.0: Natural direct typed member indexing restores the original loop block; remaining mismatch is the callee-saved ESI/EDI allocation family.
probe 22 behavior; result=MISMATCH; diff=357; shape=84.1726618705036: Test natural typed delete[] for RESENDER and HOLDER arrays, preserving ownership and compiler EH array cleanup.
probe 24 abi; result=MISMATCH; diff=338; shape=85.71428571428571: Test the reviewed virtual destructor surface used by exact TCommunications_Handler donors; preserve typed ownership and natural destructor ABI.
probe 26 layout; result=MISMATCH; diff=38; shape=100.0: Restore canonical NAME ownership at FriendlyName/FormalName from constructor evidence; keep typed array and child ownership. [same emitted code as probe 21]
probe 27 layout; result=MISMATCH; diff=38; shape=100.0: Use the canonical six-field HOLDER record from constructor evidence instead of an opaque byte array; verify no codegen drift. [same emitted code as probe 26]
probe 28 abi; result=MISMATCH; diff=38; shape=100.0: Canonicalize the VC5 vector EH helper size parameter to int, matching local exact EH donors; verify cleanup ABI remains unchanged. [same emitted code as probe 27]
probe 30 other; result=MISMATCH; diff=357; shape=84.1726618705036: Source-policy audit replaced manual VC5 vector-helper and allocation-cookie plumbing with natural delete and delete[] ownership; helper form was compiler scaffolding.
probe 33 variant; result=MISMATCH; diff=357; shape=84.1726618705036: variant lab build\variant_lab\004261E0_TCommunications_Handler\20260822_130212: 12 variants, 5 invariant-eligible, 0 exact
probe 34 flags; result=MISMATCH; diff=357; shape=84.1726618705036: Flag family: natural delete[] under /GX restores 364-byte/21-call helper basin but retains 38-byte ESI/EDI recolor; default remains 392-byte inline-destructor basin. Variant lab 20260822_130212. [same emitted code as probe 33]
probe 35 liveness; result=MISMATCH; diff=357; shape=84.1726618705036: Loop family: explicit byte-offset/index and split counter forms under /GX preserve 364-byte helper basin but lose one block or widen edit diff; direct typed indexing remains best. Variant lab 20260822_130612. [same emitted code as probe 34]
probe 36 context; result=MISMATCH; diff=357; shape=84.1726618705036: Context family: stdlib/string header choices do not change default or /GX basins. Natural output remains 392 default and 364/38 under /GX. Variant lab 20260822_130705. [same emitted code as probe 35]
probe 37 liveness; result=MISMATCH; diff=357; shape=84.1726618705036: Type family: signed/unsigned/short/ulong loop counters do not recover original register assignment; /GX unsigned remains 364/38. Variant lab 20260822_130738. [same emitted code as probe 36]
probe 38 abi; result=MISMATCH; diff=357; shape=84.1726618705036: ABI family: _CPPUNWIND macros and destructor throw/nothrow specifications do not select vector helper without /GX; all default variants remain 392-byte inline-destructor output. Labs 20260822_130758 and 20260822_130818. [same emitted code as probe 37]
```
<!-- end-recovered:3c88ce4752b04afe42f2 -->

<!-- recovered:55933deb597ba4c7882b -->
### `8cc11d033c9d` `src/scratch/004261E0_TCommunications_Handler.cpp:1-42`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004261E0 TCommunications_Handler::~TCommunications_Handler()
// PDB source: Com_hand.cpp lines 335-380
// Attempt log:
//   baseline: natural scalar cleanup, resend log scan, vector cleanup, and child deletes;
//     exact size/frame/call count but the helper symbol and loop register/address shape drifted.
//   ABI: corrected the cleanup helper to __cdecl-name `eh_vector_destructor_iterator`;
//     all 21 ordered calls and relocation identities then aligned.
//   liveness: removed the local this alias; this improved the broad drift from 300 to 42
//     differing bytes while retaining the original no-frame shape.
//   declaration-scope and typed Resend/DestMap variants were tested; late child-pointer
//     declarations were codegen-identical, while natural pointer/DestMap forms regressed
//     to a 370-byte basin. Restored the best direct-this source.
// Left in scratch: the remaining 42 bytes are a localized VC5 callee-save/address family:
//   rebuilt keeps this in ESI and loop offset/child temporaries in EDI, while original keeps
//   this in EDI and offset/delete pointers in ESI, including its explicit entry LEA. The
//   narrow volatile Resend reread is retained because the oracle visibly reloads +0x1520 at
//   every loop iteration around the logging call. No inline asm; default /O2 /Oy.
// Follow-up session: complete RESENDER/DestMap and per-slot typed forms moved to a 370-byte
// SIB-address basin or a 300-byte register basin; declaration-only full RESENDER and full
// TCommunications_Handler layouts emitted the same clean 42-byte result. A 12-variant natural
// loop lab found no exact form; its closest edit basin was the known 370-byte local-resend
// variant. Restored the clean direct-this source; remaining gap is still the ESI/EDI coloring
// and entry LEA family, with all 21 ordered calls, size, and frame exact.
// Follow-up probes: loading active through a local resend pointer and forming the log entry
// from the direct member gave a 364-byte, full-shape 38-byte diff. Volatile local, typed-record,
// declaration-order, and register-keyword variants did not improve it. Keep the 38-byte source
// reconstruction; the remaining drift is the this/offset callee-save assignment.
// Main-agent audit rejected the byte-offset cursor and raw string address. The
// canonical 0x38-byte RESENDER record and typed array walk rebuild to 364 bytes
// with all 21 calls aligned; the wider 298-byte diff is accepted in scratch.
// Follow-up: typed slot indexing with an unsigned bound preserves the observed
// per-iteration Resend reload and improves shape to 96.85% with 96% exact blocks;
// declaration order is a codegen duplicate. Keep this natural record form.
// Follow-up probe: in-loop RESENDER base plus entry declarations preserved the
// same 364-byte, 96.85%-shape output; restored the current typed source.
// Follow-up probe: direct typed member indexing forms the original loop block and
// reduces the strict gap to 38 bytes. The remaining gap is only ESI/EDI coloring.
// Pointer-scope, destructor-surface, vector-pointer, ambient-context, header, alias,
// field-type, loop-type, and declaration-order probes did not change that basin.
// Ownership review: FriendlyName/FormalName are NAME* and HOLDER is the canonical
// six-field 0x18-byte record. Main review keeps source-level delete expressions;
// compiler cleanup helpers and allocation cookies are not original source forms.
```
<!-- end-recovered:55933deb597ba4c7882b -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
