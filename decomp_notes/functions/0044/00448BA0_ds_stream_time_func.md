# Function notes: 00448BA0 `ds_stream_time_func`

Module notes: `decomp_notes/dsutil_module.md`.

## Recovered attempt history

<!-- recovered:de2d02747e82d97ded41 -->
### `target-session` `build/target_sessions/00448BA0_ds_stream_time_func.json:1-39`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1248; shape=64.09638554216868: Baseline current scratch source before new edits; establish authoritative metrics and call set.
probe 2 abi; result=MISMATCH; diff=1248; shape=64.09638554216868: Hypothesis 1: give all legacy globals C linkage in the C++ target, matching the exact Dsutil.c donor symbol surface; test whether decorated global relocations caused the prologue drift.
probe 3 control-flow; result=MISMATCH; diff=1247; shape=64.09638554216868: Hypothesis 2: restore the original two early returns before the lock store; Ghidra and CFG show busy/paused exit at 004490CB without clearing DAT_0062e658, unlike post-lock failures at 004490C5.
probe 4 control-flow; result=MISMATCH; diff=1252; shape=60.431654676258994: Hypothesis 3: mirror the original outer branch order from Ghidra: normal buffer fill under (!b0 || !b4), then the b4 silence decrement tail; also restore nested zero-length/a8 and wrapped return topology.
probe 6 liveness; result=MISMATCH; diff=1239; shape=65.37530266343826: Hypothesis 4: introduce natural function-scope zero/one locals and use them in the entry guard and lock assignment, testing the original EBP-zero/EBX-one prologue colors without raw assembly steering.
probe 7 context; result=MISMATCH; diff=1239; shape=65.94202898550725: Hypothesis 5 compiled: define CINTERFACE before Windows headers so VC5 selects the C vtable surface in C++ mode, matching the exact C donor; use canonical DirectSound macros and records.
probe 8 abi; result=MISMATCH; diff=1239; shape=65.94202898550725: Hypothesis 6: give canonical Dsutil globals C linkage in the C++ TU, matching the C donor external symbol identity while preserving the SDK type surface.
probe 9 liveness; result=MISMATCH; diff=1239; shape=65.94202898550725: Hypothesis 7: retain a natural Lock HRESULT local, as exact Dsutil donors use a result local for API status; test whether this gives the target EBP-zero/EBX-one allocation and output-home topology. [same emitted code as probe 8]
probe 10 liveness; result=MISMATCH; diff=1239; shape=65.70048309178743: Hypothesis 8: carry the natural zero/one locals through all zero arguments, zero fills, predicates, and flag stores; this tests whether the original EBX=1 and EBP=0 were long-lived source values rather than literals.
probe 11 liveness; result=MISMATCH; diff=1239; shape=65.70048309178743: Hypothesis 9: move the zero/one declarations after the PDB-proven API output locals, testing declaration order as a register-color control while keeping the same natural value use. [same emitted code as probe 10]
probe 12 flags; result=MISMATCH; diff=1252; shape=67.98029556650246: Hypothesis 10: force the target .cpp through the C compiler with /TC, matching the proven Dsutil.c donor and canonical CINTERFACE ABI context; this is a compiler-mode test, not a source simplification.
probe 13 behavior; result=MISMATCH; diff=1250; shape=66.42685851318944: Hypothesis 11: use the actual Lock output-pointer guards for retry loops, not the second segment lengths; Ghidra and original assembly load/test lpWrite1 at 48E87 and lpWrite2 at 48FF1.
probe 14 liveness; result=MISMATCH; diff=1246; shape=66.90647482014388: Hypothesis 12: reorder locals to the PDB/decompiler declaration sequence (dwLen1, dwLen2, lpWrite1, uChkErr, lpWrite2, dwPlay, dwWrite, local_4), testing whether source declaration order recovers the original Lock homes and ESI length color.
probe 15 liveness; result=MISMATCH; diff=1246; shape=66.90647482014388: Hypothesis 13: mark the long-lived zero/one values register locals, a period-plausible register allocation hint, to test whether VC5 selects EBP zero and EBX one instead of ESI one. [same emitted code as probe 14]
probe 16 behavior; result=MISMATCH; diff=1248; shape=63.68038740920097: Hypothesis 14: use the Lock segment lengths as the original branch predicates, with pointer checks only inside silence fills; the original assembly tests [esp+0C] and [esp+10] before the normal and second-segment paths.
probe 17 flags; result=MISMATCH; diff=1268; shape=41.13300492610838: Hypothesis 15: test size-oriented /O1 with the canonical C Dsutil context and /TC; prior /O1 evidence used a custom C++ surface, so this checks the distinct period-context combination.
probe 18 flags; result=MISMATCH; diff=1246; shape=66.90647482014388: Hypothesis 15b: restore proven default /O2 after the O1 experiment; recompile the canonical C source before interpreting further assembly. [same emitted code as probe 15]
probe 19 abi; result=MISMATCH; diff=1255; shape=68.22660098522168: Hypothesis 16: restore the exact WaveStartDataRead ABI from the Dsutil donor: pass addresses of DAT_00888464/68/7C, while WaveReadFile takes the handle value; original assembly pushes all three StartDataRead addresses.
probe 20 liveness; result=MISMATCH; diff=1255; shape=68.22660098522168: Hypothesis 17: remove the API result temporary and use direct Lock predicates, matching the original direct test-eax call sites and reducing artificial local liveness. [same emitted code as probe 19]
probe 21 liveness; result=MISMATCH; diff=1255; shape=68.47290640394088: Hypothesis 18: remove compiler-steering zero/one locals and retain direct literals in the canonical C source; this tests the smallest natural form after ABI and behavior corrections.
probe 24 control-flow; result=MISMATCH; diff=1255; shape=68.47290640394088: Hypothesis 19: combine the busy and paused entry guards into one short-circuit condition; the original loads busy before the prologue, then compares both values against one EBP zero after push/xor, unlike separate return statements. [same emitted code as probe 23]
probe 25 control-flow; result=MISMATCH; diff=1061; shape=77.26161369193154: Hypothesis 20: restore the original separate post-lock early returns for DAT_008884a8 and a null sound buffer, each clearing DAT_0062e658 before return, instead of one combined goto-done guard.
probe 26 abi; result=MISMATCH; diff=1061; shape=77.26161369193154: Hypothesis 21: use the period Dsutil output types unsigned char* for Lock buffers and explicit (void**) casts, matching the exact ds_stream_file donor and Ghidra uchar* locals; test local-home and pointer-address lowering. [same emitted code as probe 25]
probe 27 behavior; result=MISMATCH; diff=1061; shape=77.26161369193154: Hypothesis 22: retain the binary-observed redundant lpWrite2 and DAT_008884a8 tests in the second-segment silence fallback, rather than letting the compiler reuse the outer if state. [same emitted code as probe 26]
probe 28 control-flow; result=MISMATCH; diff=1067; shape=59.75903614457831: Hypothesis 23: split second-segment reading and second-segment silence into two independent if statements; original assembly rejoins after the read arm, then repeats both lpWrite2 and DAT_008884a8 tests at 00449045.
probe 29 context; result=MISMATCH; diff=1061; shape=77.26161369193154: Hypothesis 24: match the exact Dsutil donor header order by defining CINTERFACE after windows.h and mmsystem.h but before dsound.h, testing SDK front-end context as the source of local-home and register-basin drift. [same emitted code as probe 27]
probe 30 liveness; result=MISMATCH; diff=1105; shape=77.33990147783251: Hypothesis 25: use the PDB-named dwPlay local for the playback delta instead of a nested diff temporary; original source evidence names dwPlay and the original arithmetic carries the delta in EDX across the update.
probe 31 control-flow; result=MISMATCH; diff=1083; shape=80.58968058968058: Hypothesis 26: model the first segment as an outer lpWrite1 guard with two independent a8 branches; original bytes retest both pointer and a8 at 00448EE3 after the normal read path.
probe 32 control-flow; result=MISMATCH; diff=1086; shape=75.97087378640776: Hypothesis 27: apply the same independent second-segment read and silence guards as the first segment, matching the original join at 00448F18 and repeated checks at 00449045.
probe 33 liveness; result=MISMATCH; diff=1050; shape=80.54187192118226: Hypothesis 28: mirror the original retry induction by mutating dwLen1 and lpWrite1 before WaveReadFile; Ghidra and original assembly show a stored remaining count and an advanced pointer, unlike one compound call expression.
probe 34 liveness; result=MISMATCH; diff=1059; shape=74.69586374695864: Hypothesis 29: mirror the second-segment retry induction by mutating dwLen2 and lpWrite2 before WaveReadFile, matching the original subtract/store and pointer-add topology at 00448FFE-0044900C.
probe 35 control-flow; result=MISMATCH; diff=1059; shape=77.64127764127764: Hypothesis 30: test independent second-segment silence with the improved first-segment retry induction; this isolates whether the p2 rejoin shape is required once the p1 source matches its stored remaining count.
probe 36 layout; result=MISMATCH; diff=1050; shape=80.54187192118226: Hypothesis 31: model the unused GetCurrentPosition output as the Ghidra-proven four-byte local_4 array, not a DWORD scalar, to test stack-home and address-taking behavior without changing storage size. [same emitted code as probe 33]
probe 37 control-flow; result=MISMATCH; diff=1050; shape=80.54187192118226: Hypothesis 32: place the wrap_play label after an explicit under-total goto done; original falls through from the final increment and jumps directly from the silent-buffer arm to the subtraction tail, without a normal-path jump. [same emitted code as probe 36]
probe 39 liveness; result=MISMATCH; diff=1093; shape=77.14987714987716: Hypothesis 33: preserve lpWrite1 for the later Unlock while using a block-local retryWrite1 cursor; original evidence shows a separate advanced ESI cursor and a distinct saved output pointer.
probe 40 layout; result=MISMATCH; diff=1095; shape=59.70515970515971: Hypothesis 34 retry: use a typed five-word DsStreamLockData local because original output homes form one contiguous Lock-output window in source declaration order (dwLen1, dwLen2, lpWrite1, uChkErr, lpWrite2), followed by dwWrite and local_4.
probe 41 liveness; result=MISMATCH; diff=1093; shape=73.46437346437347: Hypothesis 35: use the exact Dsutil retry statement order (retryWrite1 += uChkErr; dwLen1 -= uChkErr) while preserving the original output pointer for Unlock; the exact donor emits this natural cursor form.
probe 42 liveness; result=MISMATCH; diff=1075; shape=81.46341463414635: Hypothesis 36: advance retryWrite1 and shrink dwLen1 before WaveStartDataRead; original assembly performs the subtract/add before the helper call, and the exact Dsutil donor uses this source order.
probe 43 liveness; result=MISMATCH; diff=1071; shape=83.49753694581281: Hypothesis 37: mirror the proved first retry form for the second segment with a block-local retryWrite2 cursor and mutable dwLen2 before WaveStartDataRead; original assembly preserves lpWrite2 while advancing ESI.
```
<!-- end-recovered:de2d02747e82d97ded41 -->

<!-- recovered:b4357284db300d7c0c88 -->
### `b7fd2baf398f` `src/scratch/00448BA0_ds_stream_time_func.cpp:1-65`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00448BA0 ds_stream_time_func
// Attempt log:
// try 1: direct C reconstruction from packet/Ghidra with helper clear_audio: default /O2 too small (.text 1312 vs 1332), so not comparable.
// try 2: macro-expanded CLEAR_AUDIO to recover repeated memset tests: exact-size comparable (1332/1332) but broad mismatch, 95.2703% positional / 120.1201% edit, first mismatch prologue due local initialization/control-flow topology.
// try 3: /GX no change from try 2, rolled back.
// try 4: /O1 too small (.text 1277), rolled back.
// try 5: /Od exact-size comparable but worse debug-basin mismatch (92.9429% positional / 146.8468% edit), rolled back.
// try 6-9: removed prologue zero initializers, mirrored PDB local names/order,
// and tested the local_4 GetCurrentPosition home plus shared zero/one values;
// these preserved the exact 18-call set but left the broad CFG/register basin.
// final normalized source keeps ordinary uninitialized API output locals and
// natural literal predicates rather than compiler-steering aliases.
// FLAGS: config/flags/00448BA0_ds_stream_time_func.rsp = /Oi- /TC (C ABI, direct memset calls)
// probe 10: restored the PDB-proven unused GetCurrentPosition output home
// local_4 and the Dsutil local declaration order; emitted code was unchanged.
// probe 11: restored exact Dsutil global identities and the imported
// PostMessageA surface from donor and ABI evidence; size became 1339 bytes,
// with all 18 calls still aligned.
// probe 12: sent busy and paused guards to the shared cleanup label shown by
// the original CFG; diff improved by one byte, but the first hunk stayed open.
// probe 13: switching the TU to a C extension did not change emitted code.
// probe 14: split partial-read silence from full-buffer silence so the base
// write pointer is tested before adding uChkErr; this saved EBX and improved
// the diff to 1264 bytes.
// probe 15: kept end-of-stream silence's wave/length checks inside a separate
// fill form; this reached exact 1332-byte size and diff 1248.
// probe 16: mutating retry pointers and uChkErr to model stack-home reuse grew
// the body to 1345 bytes; rolled back. A p1-only version also regressed shape.
// probe 17: separating the p2 end-silence branch and a register zero/one form
// both regressed or duplicated the 1248-byte result; rolled back.
// Current source uses named legacy globals, typed DirectSound calls, the
// unused output home, and direct imported PostMessageA. Remaining drift starts
// at prologue save/zero scheduling and continues through Lock output homes,
// silence branches, and shared tails. Not accepted_drift.
// Probes 18-21: canonical VC5 C mode (/TC), SDK DirectSound/MMIO types, the
// address-taking WaveStartDataRead ABI, pointer retry guards, and literal
// zero/one forms. Calls stayed 18; no exact block moved past 15.02%.
// Final unresolved checkpoint: 1312 rebuilt bytes, 1255 positional bytes,
// 68.47% shape, 18 aligned calls, frame 0x1C, first mismatch +8.
// New claim probes:
// - Separate post-lock returns for a8 and a null buffer improved the result
//   to 1282 bytes, 1061 positional bytes, 77.26% shape, and 34.24% blocks.
// - An outer lpWrite1 guard with independent a8 branches improved shape to
//   80.59%; it was retained with the first-segment retry form below.
// - Separate retry cursors preserve lpWrite1 and lpWrite2 for Unlock while
//   the length locals shrink. Advancing both cursors before WaveStartDataRead
//   gave 1280 bytes, 1071 positional bytes, 83.50% shape, and 35.47% blocks.
//   Directly mutating lpWrite1 gave 1050 bytes but changed the Unlock pointer,
//   so it was rejected. A typed output aggregate was also rejected. Header
//   order, pointer casts, local_4 type, dwPlay, and wrap-label edits were
//   unchanged or worse. Calls stayed 18 and frame stayed 0x1C.
// Context gate: PDB module Dsutil.c, lines 1726-1983, one ordinary C owner;
// the address sequence carries 18 ordered calls and the shared cleanup tails.
// Exact anchors are the callback declaration in 004486F0_ds_stream_file.c and
// the 00447EF0/00447F40 helper targets used at lines 1890-1960.
// Probe 22: the length-first split for both Lock outputs follows the PDB CFG;
// it reduced the standalone diff from 1071 to 984 bytes and kept 18 calls.
// The final source keeps this natural control flow. Register-color drift
// remains: expected EBX/EBP versus rebuilt EBX/ESI/EDI saved-register colors.
// Final standalone validation: 1292 rebuilt bytes versus 1332 original,
// 984 differing bytes, 18 aligned calls, frame 0x1C, result MISMATCH.
// Fresh complete-TU validation is recorded in
// build/candidate_tus/dsutil_prefix/report.json: four scratch promotion
// candidates matched, but remain observed because source-bank moves are not
// captain edits. DSReloadSoundBuffer remains a manual-vtable policy hold.
```
<!-- end-recovered:b4357284db300d7c0c88 -->
