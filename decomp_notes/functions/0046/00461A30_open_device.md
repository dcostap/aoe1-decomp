# Function notes: 00461A30 `open_device`

## Recovered attempt history

<!-- recovered:1a9704c252cf7758e66c -->
### `target-session` `build/target_sessions/00461A30_open_device.json:1-38`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=487; shape=82.58064516129032: Natural typed WinMM/file-device reconstruction before local-stack probes.
probe 2 control-flow; result=MISMATCH; diff=542; shape=60.89385474860335: Natural infinite scan loop with fopen failure break; tests whether source topology matches the unconditional original back-edge.
probe 4 context; result=MISMATCH; diff=487; shape=82.58064516129032: Use repository-local extern string surfaces shared by the music TU instead of private static literals; tests relocation identity without raw addresses.
probe 5 layout; result=MISMATCH; diff=487; shape=82.58064516129032: Reorder natural local declarations by first-use flow to test VC5 stack-home placement against original four-byte local shift. [same emitted code as probe 4]
probe 6 control-flow; result=MISMATCH; diff=542; shape=60.89385474860335: Scope each FILE result to its natural scan loop and break on fopen failure; tests whether VC5 preserves one call site and the original unconditional back-edge.
probe 8 control-flow; result=MISMATCH; diff=485; shape=87.09677419354838: Use a positive MCI-open success arm with a shared post-switch failure return; tests the original distant failure tail without changing typed API flow.
probe 9 behavior; result=MISMATCH; diff=485; shape=87.09677419354838: Express the proven negative 10000 offset as a signed hexadecimal constant; tests the original add-immediate lowering without changing mixer ownership or result behavior.
probe 10 control-flow; result=MISMATCH; diff=467; shape=85.71428571428571: Use a natural do-loop with an explicit fopen success arm and break on failure, removing the duplicate bottom test.
probe 11 control-flow; result=MISMATCH; diff=467; shape=85.71428571428571: Use idiomatic FILE truth tests in the explicit do-loop success arms; tests whether VC5 emits the original EAX test and direct zero store. [same emitted code as probe 10]
probe 12 control-flow; result=MISMATCH; diff=547; shape=64.80446927374301: Use early failure break in the natural do-loop, then close and increment on success; tests branch polarity and EAX test lowering.
probe 14 control-flow; result=MISMATCH; diff=467; shape=85.71428571428571: Restore the winning natural do-loop success/failure arms and positive MCI-open success arm after exploratory rollback.
probe 15 layout; result=MISMATCH; diff=467; shape=85.71428571428571: Scope MCI records to the type-1 case, where only device-open flow uses them; tests natural lifetime and original four-byte local-home shift. [same emitted code as probe 14]
probe 16 layout; result=MISMATCH; diff=467; shape=85.71428571428571: Scope each scan FILE pointer to its music-type case; tests whether reduced lifetime restores direct EAX tests and original initialization homes. [same emitted code as probe 15]
probe 21 context; result=MISMATCH; diff=467; shape=85.71428571428571: Replace the local TMusic_System clone with canonical music_context.h.
probe 22 layout; result=MISMATCH; diff=467; shape=85.71428571428571: Restore the PDB/decompiler function-scope MCI record order before file_name. [same emitted code as probe 21]
probe 23 layout; result=MISMATCH; diff=468; shape=82.46753246753246: Test whether a 265-byte filename window explains the four-byte local displacement.
probe 24 layout; result=MISMATCH; diff=467; shape=88.31168831168831: Test the binary-used filename address as the real buffer base instead of a decompiler plus-four view.
probe 25 control-flow; result=MISMATCH; diff=547; shape=66.4804469273743: Use the binary negative fopen break followed by the common close and increment body.
probe 26 liveness; result=MISMATCH; diff=18; shape=93.37748344370861: Diagnose zero-register reuse with fixed-size track_count initialization through the period memset intrinsic.
probe 27 layout; result=MISMATCH; diff=18; shape=93.37748344370861: Spell the mixer offset as addition of the binary-supported negative volume bound. [same emitted code as probe 26]
probe 28 context; result=MISMATCH; diff=18; shape=93.37748344370861: Use a period-plausible named negative music-volume bound in both mixer conversions. [same emitted code as probe 27]
probe 29 liveness; result=MISMATCH; diff=18; shape=93.37748344370861: Apply the named negative bound to the computed volume with natural compound addition. [same emitted code as probe 28]
probe 30 layout; result=MISMATCH; diff=18; shape=93.37748344370861: Put the named negative bound on the left side of each final volume sum. [same emitted code as probe 29]
probe 31 abi; result=MISMATCH; diff=18; shape=93.37748344370861: Model the binary unsigned division and modulo negative offset with an unsigned volume intermediate. [same emitted code as probe 30]
probe 32 layout; result=MISMATCH; diff=18; shape=93.37748344370861: Test the negative bound as its exact unsigned 32-bit constant representation. [same emitted code as probe 31]
probe 33 liveness; result=MISMATCH; diff=8; shape=94.70198675496688: Apply the volume bound through the owning start_volume member before copying volume.
probe 34 layout; result=MISMATCH; diff=12; shape=92.05298013245033: Model the proved 261-byte stack window as a four-byte prefix plus the addressed filename field.
probe 35 layout; result=MATCH; diff=0; shape=100.0: Test one typed local window from the exact MCI slices and filename stack addresses.
probe 36 layout; result=MISMATCH; diff=5; shape=96.6887417218543: Walk back the local window's unused four-byte tail.
probe 37 layout; result=MATCH; diff=0; shape=100.0: Replace opaque tail padding with one complete 265-byte filename field in the proved stack window. [same emitted code as probe 35]
probe 38 layout; result=MATCH; diff=0; shape=100.0: Name the proved four-byte prefix and 261-byte filename as one typed subwindow. [same emitted code as probe 37]
probe 39 liveness; result=MISMATCH; diff=467; shape=94.8051948051948: Walk back fixed-size memset to direct track_count assignments under the exact local window.
probe 41 context; result=MATCH; diff=0; shape=100.0: Recover typed WinMM open logic in authentic music.cpp context
probe 43 liveness; result=MATCH; diff=0; shape=100.0: Walkback result: direct track_count assignments reproduce a 467-byte mismatch and zero-register lowering; retain fixed-size memset fills. [same emitted code as probe 41]
probe 44 liveness; result=MATCH; diff=0; shape=100.0: Walkback result: a scalar volume temporary changes both signed-bound ADD sites to SUB and causes a 10-byte mismatch; retain direct start_volume member update and publication. [same emitted code as probe 43]
probe 45 layout; result=MATCH; diff=0; shape=100.0: Walkback result: removing the four-byte filename offset changes four LEA displacements and causes a 4-byte mismatch; retain the typed interior text field. [same emitted code as probe 44]
probe 49 context; result=MATCH; diff=0; shape=100.0: Rebuild under the current shared translation-unit map; unrelated owner additions changed the manifest, so verify the exact target remains on authentic music_context. [same emitted code as probe 48]
probe 50 context; result=MATCH; diff=0; shape=100.0: Final rebuild under the stable current translation-unit map; exact target remains in authentic music_context. [same emitted code as probe 49]
```
<!-- end-recovered:1a9704c252cf7758e66c -->

<!-- recovered:7eab457d828319537ce8 -->
### `0491e8a91fc9` `src/scratch/00461A30_open_device.cpp:1-50`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00461A30 TMusic_System::open_device (551B)
// PDB source: music.cpp lines 71-216
// Attempt log:
// Baseline: canonical same-TU TMusic_System/mixer layout, typed MCI parameter
// records, period stdio/multimedia surfaces, and natural switch/scan reconstruction.
// Probe 2: late shared failure tail and do-loop scans improved CFG but loop peeling
// retained four static sprintf/fopen sites.
// Probes 3-5: FILE scope, explicit scan labels, and comma-condition loops were
// codegen duplicates; all retained the peeled call duplication.
// Probe 6: a do-loop with an explicit file-dependent bottom condition recovered the
// original 11-call static set and 0x138 frame; remaining drift is stack-local offsets,
// branch polarity, and return-tail placement.
// Probes 7-9: a dead stack gap and typed OpenDeviceWork gap model were nonproductive;
// the latter either grew the frame or changed local placement.
// Probe 10: removing the buffer +4 diagnostic moved only fopen behavior and did not
// improve the 489-byte best; restored this binary-supported +4 source shape.
// Final bounded result: natural typed source retained in scratch. Best current metrics
// are 489 differing bytes, exact 11-call set, 0x138 frame, and the full WinMM/stdio
// behavior/layout reconstructed. Next lead is a focused local-stack declaration/order
// pass to move status/set/open/file homes by four bytes and reproduce late failure tails.
// Main-agent audit replaced raw string addresses with named SDK/global surfaces
// and retained the natural typed WinMM/file-device flow.
// Fresh worker pass: for(;;), do/while(true), and scoped-label FILE scans all
// triggered VC5 loop peeling and four static sprintf/fopen sites; the natural
// bottom-test scan remains the only clean 11-call source shape.
// Fresh worker pass: placing sprintf in the do-condition via a comma/&& chain
// recovered a single-site scan and improved the diagnostic diff to 454 bytes,
// but changed the frame-size/CFG basin and used opaque scheduling source; it was
// rolled back. Declaration reordering and pointer-truth tests were duplicates.
// Current worker H1: defined named period format strings in this TU; unresolved extern
// placeholders were codegen-neutral and the named literals are retained for behavior.
// Current worker H2: corrected the standard MCI_STATUS_PARMS query field from dwTrack to
// dwItem. The change improved shape and confirms the record offset +8 query ownership.
// Current worker H3: an if-chain/common-return rewrite was structurally worse and was rolled back.
// Current worker H4: passed the full MCI_STATUS_PARMS record instead of reusing dwReturn as
// the status pointer. This aligns the original status base and improves the typed source.
// Current worker H5: a 260-byte scan buffer was codegen-neutral; the binary-supported 261-byte
// buffer remains. Full MCI_OPEN_PARMSA and MCI_SET_PARMS records also align their call pointers.
// Current worker H6: the original stack writes and PDB field labels prove the WinMM calls use
// &open_info.wDeviceID, &set_info.dwTimeFormat, and &status_info.dwReturn. The original status
// query writes dwTrack=3 and reads dwItem. The full-record/dwItem variant was codegen-neutral
// but not behavior-equivalent, so the named field pointers are restored.
// Current worker H7 audit: the MCI calls use the imported __imp__mciSendCommandA@16 surface,
// while the three original string targets are the WAV, MID, and "r" literals at 584CF4h,
// 584CE4h, and 57F320h. Named local literals preserve this source surface without raw addresses.
// Shard D2 H1: shared one FILE* local across both scans, with fopen-tested-before-fclose
// do-loop bodies and the original unconditional back-edge; VC5 emitted the prior code unchanged.
// Final current reconstruction: typed WinMM field calls, named format strings, natural
// bottom-test scans, and device/mixer ownership are retained. Remaining blocker is local-home
// placement and late failure-tail layout; no safe source lead remains in the audited call surface.
```
<!-- end-recovered:7eab457d828319537ce8 -->

## Earlier notes from `decomp_notes/functions/0046/00461A30_open_device.md`

This section is historical. Use the status query for current state.

## 00461A30 open_device

The original source is `music.cpp`, lines 71 through 216.

The function opens sequencer, MIDI-file, and wave-file music devices. It scans numbered files for types 2 and 3. It opens a mixer for types 1 and 2.

Tests found that a bottom-tested scan loop kept the required file-open calls. A typed MCI status record, MCI set record, MCI open record, and 261-byte file name were required. The status command uses the record tail at `dwReturn`. This follows the executable call layout.

The old source used aggregate locals and an artificial file-name prefix for byte tuning. The normal module now uses direct SDK records and a normal file-name buffer. This can change bytes.

### Current module result

The authentic `music.cpp` module check reports `MISMATCH`. The rebuilt body is
551 bytes, equal to the original body. It has 8 positional diff bytes across
8 spans (1.4519%), with the first mismatch at offset `+0x14F`. The frame,
saved registers, instruction count, calls, CFG, owner symbol, and boundary
match. All 13 relocated call sites also match.

The natural source remains the source body. This owner is scratch and is not
registered as an exact translation-unit owner.
