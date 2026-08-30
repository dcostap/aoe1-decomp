# Function notes: 0042A330 `StoreForResend`

Module notes: `decomp_notes/com_hand_module.md`.

## Recovered attempt history

<!-- recovered:2d30d4e213c426289832 -->
### `target-session` `build/target_sessions/0042A330_StoreForResend.json:1-25`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=359; shape=76.41025641025641: Natural typed resend entry, storage, map copy, diagnostics baseline before focused probes.
probe 2 liveness; result=MISMATCH; diff=359; shape=76.41025641025641: Typed slot counter signed as Ghidra int iVar7; tests whether VC5 restores original EBP slot and EBX self coloring. [same emitted code as probe 1]
probe 3 variant; result=MISMATCH; diff=486; shape=79.67032967032966: Natural memcpy payload copy replaces scalar manual loops; tests period string.h lowering against oracle REP movsd/movsb.
probe 5 behavior; result=MISMATCH; diff=359; shape=76.41025641025641: Restored exact binary log formats from local original strings: occupied QUEUE, stored resend, and full-buffer diagnostics.
probe 6 context; result=MISMATCH; diff=359; shape=76.41025641025641: Header-context probe: add period memory.h alongside existing string.h; tests VC5 intrinsic and register basin without source ownership changes. [same emitted code as probe 5]
probe 7 liveness; result=MISMATCH; diff=486; shape=79.67032967032966: Payload memcpy with a typed saved entry alias tests whether natural pointer liveness preserves original frame homes while recovering REP copy.
probe 9 layout; result=MISMATCH; diff=423; shape=76.5625: Scoped typed entry alias after the occupancy test mirrors the original reload-before-free and occupied paths while retaining RESENDER ownership.
probe 11 layout; result=MISMATCH; diff=490; shape=56.38297872340426: Natural typed RESENDER pointer walk replaces raw byte cursor and physical offset reconstruction; tests canonical communications ownership.
probe 14 liveness; result=MISMATCH; diff=359; shape=76.41025641025641: Swap natural payload local declaration order (destination pointer before byte count) to test original ESI entry/EDI destination coloring and spill homes. [same emitted code as probe 13]
probe 16 abi; result=MISMATCH; diff=359; shape=76.41025641025641: Canonical local RESENDER names and TCommunications_Handler fields replace arbitrary aliases; layout remains proven 0x38 and packet map ownership stays typed. [same emitted code as probe 14]
probe 18 abi; result=MISMATCH; diff=359; shape=76.41025641025641: Canonical Multiplayer owner name and occupied serial local preserve reviewed communications vocabulary; no codegen change expected. [same emitted code as probe 17]
probe 21 other; result=MISMATCH; diff=498; shape=64.97175141242938: Main review removed compiler-steering ownership forms and retained natural typed source.
probe 23 control-flow; result=MISMATCH; diff=486; shape=79.67032967032966: Restore binary-supported byte-offset loop and explicit slot-derived free-entry recomputation; tests whether original tail placement and loop CFG return without changing ownership or copy/log behavior. [same emitted code as probe 7]
probe 24 variant; result=MISMATCH; diff=359; shape=76.41025641025641: Replace payload memcpy with the decompiler-supported shared-count dword/byte loops; tests whether original local_4 lifetime and REP lowering arise from source loop shape. [same emitted code as probe 19]
probe 25 layout; result=MISMATCH; diff=328; shape=74.21052631578948: Use repeated typed Resend[slot] ownership in the free-entry path, matching the decompiler's original member-indexed source; tests entry-pointer liveness and allocation/map register topology without dead scaffolding.
probe 26 layout; result=MISMATCH; diff=496; shape=72.58064516129032: Diagnostic only: express the proven 0x38 slot offset and entry fields through a table byte cursor; tests whether original base-plus-offset addressing controls the free-path frame and store topology.
probe 27 liveness; result=MISMATCH; diff=359; shape=76.41025641025641: Type the slot counter as signed int, matching PDB/Ghidra iVar7 and original signed register role; tests whether VC5 recolors slot to EBP without changing loop behavior. [same emitted code as probe 24]
probe 28 variant; result=MISMATCH; diff=497; shape=70.8108108108108: Split payload into typed dword-count and byte-tail memcpy operations, equivalent to the proven two-loop copy; tests whether intrinsic REP lowering preserves local size lifetime and original payload topology.
probe 29 abi; result=MISMATCH; diff=359; shape=76.41025641025641: Use the decompiler-proven direct cdecl operator new surface instead of a new[] expression; tests allocation declaration and source call lowering while preserving the same null-check behavior. [same emitted code as probe 27]
probe 30 liveness; result=MISMATCH; diff=360; shape=76.41025641025641: Swap declaration order of the signed slot and byte offset locals, testing PDB-declared loop-state order for original EBX-self/EBP-slot coloring.
probe 31 liveness; result=MISMATCH; diff=488; shape=78.80434782608695: Keep payload size in a named local across intrinsic memcpy and restore it to the entry; tests whether natural post-copy size use induces the original local_4 spill and REP block.
probe 32 layout; result=MISMATCH; diff=358; shape=76.92307692307692: Use one typed Resend base plus indexed slot access across the free-entry path; tests a natural owner alias between byte-offset scan and array-indexed storage.
probe 33 liveness; result=MISMATCH; diff=358; shape=76.92307692307692: Introduce a natural handler alias for all member reads, testing whether explicit owner lifetime changes VC5 self and slot register colors toward the original EBX/EBP topology. [same emitted code as probe 32]
probe 34 liveness; result=MISMATCH; diff=486; shape=79.12087912087912: Replace payload loops with an entry-length reference used by intrinsic memcpy and restored afterward; tests whether a natural alias preserves the original local size home and REP lowering.
probe 35 layout; result=MISMATCH; diff=464; shape=69.61325966850829: Use the scanned typed entry for free-path stores instead of a second indexed owner; tests whether eliminating the redundant base alias restores compact liveness while retaining the proven offset loop.
```
<!-- end-recovered:2d30d4e213c426289832 -->

<!-- recovered:bd063b83021a68e07d6e -->
### `912332e8f578` `src/scratch/0042A330_StoreForResend.cpp:1-42`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0042A330 TCommunications_Handler::StoreForResend
// Attempt log:
// try 1: natural reconstruction from packet/Ghidra; exact size but broad mismatch from struct offsets/log surface/copy loops.
// try 2: switched Log to free DebugLog(TDebuggingLog*,...) to match cdecl push-this surface; removed C++ member-call artifacts.
// try 3: extern memcpy made text too small (464 vs 523), so not viable.
// try 4: <string.h> memcpy still emitted helper-call sized body, too small.
// try 5: restored manual copy loops; exact size returned.
// try 6: corrected resend entry layout: assert/id at +0, used at +4, data at +8, size at +0xC, recipient words at +0x10.
// try 7: changed occupied-entry logging to use +4/+8/+0C/+10 layout; improved edit diff slightly but still broad.
// try 8: /GX tried because of allocation paths; no EH in original and text stayed too small/wrong, removed flag.
// try 9: natural memcpy-like loops compile as scalar loop family, not original rep movsd/rep movsb sequence.
// try 10: slot/off loop modeled as slot*0x38 and off+=0x38; compiler keeps different slot register/liveness than original (edi vs ebp/esi).
// fresh session: flattened active/delivery guards to explicit early returns; emitted code was unchanged, so restored the nested source.
// fresh session: direct typed resendTable[slot] ownership grew the body to 650B/frame 0x10; restored the smaller entry-alias basin.
// session: corrected the entry's +0 timestamp and canonical TDebuggingLog ABI, and
// rebuilt occupied diagnostics with the oracle's 13-vararg push order/8 recipient
// dwords. Parameter-mutating copy loops retain the exact 0x8 frame and near-size
// output; payload-only memcpy was a diagnostic -32B basin and was rolled back.
// session: expressed the recipient-map copy as typed memcpy into ResendEntry::vals;
// this natural field-owned form restores the oracle REP block and improves diff
// 493->359, but leaves a -26B payload-loop size gap and structural CFG drift.
// follow-up: retested typed memcpy lowering for the payload after the recipient-map
// copy reached the REP family; rebuilt size fell 497->467 and the frame disappeared,
// so restored the clean typed-map source.
// follow-up: hoisted scan-state declarations before the delivery gates while keeping
// initialization after the gates; emitted code was unchanged, so restored the clean source.
// follow-up: typed 501-entry array induction, a typed free-slot entry reference, and
// a register-qualified self alias were each codegen duplicates; restored the clean source.
// revisit: restored the binary-local diagnostic strings for occupied entries, stored
// payloads, and the full-buffer tail; canonical RESENDER field names are codegen-neutral.
// policy normalization: the final unresolved source uses a typed RESENDER pointer
// walk instead of a raw byte cursor. This is natural ownership, but it widens the
// codegen gap and relocates the full-buffer log call.
// bounded pass: 11 probes found no better natural basin. The final source is 497B
// versus 523B with 7/7 ordered calls and frame 0x8; REP payload lowering and
// EBX-self/EBP-slot coloring remain unresolved.
// Main review replaced the explicit allocation call and handwritten copy loop
// with ordinary new[] and memcpy ownership.
// Fresh diagnostics used a byte-offset table scan, explicit operator new,
// and handwritten payload-copy loops. Main review rejected these forms as
// compiler-facing plumbing. Keep typed RESENDER iteration, new[], and memcpy.
// left in scratch: behavior and layout modeled, but logging argument order/register allocation and copy-loop lowering remain broad; not accepted-drift-safe.
```
<!-- end-recovered:bd063b83021a68e07d6e -->
