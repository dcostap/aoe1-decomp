# Recovery journal: 004BCD30 `load`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Sounddrv.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Sounddrv.cpp`.
- Earlier recovery note: `recovery_notes/sounddrv_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:d3195937c6933817496b -->
### `d050eea3c` `src/Sounddrv.cpp:577-577`

Mapping: `ambiguous`. comment lies after mapped function load at old line 410.

```text
                /* ORIGINAL BUG: The shipped path frees resource_data twice. */
```
<!-- end-recovered:d3195937c6933817496b -->

<!-- recovered:bff70eca3a10407952f4 -->
### `target-session` `build/target_sessions/004BCD30_load.json:1-30`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=882; shape=89.20570264765784: Baseline current natural TDigital load: correct 0x15C frame, 42 calls, 3-byte short; call identity and read compare differ.
probe 2 control-flow; result=MISMATCH; diff=882; shape=89.61303462321793: Hypothesis 1: spell resource invalid gate as param <= -1 to reproduce original cmp ebx,-1/jle instead of cmp ebx,0/jl.
probe 3 control-flow; result=MISMATCH; diff=1170; shape=86.35437881873727: Hypothesis 2: express both read gates as positive unsigned success branches with explicit success labels; original uses cmp eax,edi/ja, unlike baseline test/ja.
probe 5 liveness; result=MISMATCH; diff=882; shape=89.61303462321793: Hypothesis 3: name owner chain target before recursive load; original keeps owner in ECX across null test and call, testing whether an explicit local preserves that lifetime and relocation. [same emitted code as probe 2]
probe 7 behavior; result=MISMATCH; diff=878; shape=90.42769857433808: Hypothesis 4: use size2, not mem2, as the resource Lock secondary-segment guard; original binary tests a stack local whose semantic identity is ambiguous in decompiler output.
probe 8 behavior; result=MISMATCH; diff=880; shape=90.020366598778: Hypothesis 5: use explicit read == 0 failure gates; Ghidra's recovered source treats nonzero read as success and original cmp/ja may reflect nonzero comparison.
probe 10 abi; result=MISMATCH; diff=880; shape=90.020366598778: Hypothesis 6: declare read's return as signed int, matching the decompiler's int local; test whether VC5 emits original compare form without changing call ABI.
probe 12 liveness; result=MISMATCH; diff=876; shape=90.42769857433808: Hypothesis 7: capture each read result in the existing result local before the gate; Ghidra recovers an iVar4 and this may retain the original cmp against live zero.
probe 13 abi; result=MISMATCH; diff=874; shape=90.83503054989816: Hypothesis 8: keep named read result but make it unsigned; original cmp eax,edi/ja proves unsigned relational lowering, while H7's signed result gave jg.
probe 14 liveness; result=MISMATCH; diff=872; shape=90.63136456211812: Hypothesis 9: use a branch-local pointer-to-sound_buffer slot for the resource Create/Lock cleanup; original resource path proves a carried member address in EBX.
probe 15 liveness; result=MISMATCH; diff=872; shape=90.63136456211812: Hypothesis 10: retain the freshly allocated resource WAVEFORMATEX in a named local before member assignment; Ghidra recovers ptVar6 and original zeroing uses ECX rather than the baseline EDI. [same emitted code as probe 14]
probe 17 control-flow; result=MISMATCH; diff=879; shape=91.85336048879837: Hypothesis 11: use direct positive CreateSoundBuffer failure guard in resource path; original Create call is test/je while named result emitted cmp/jne.
probe 19 liveness; result=MISMATCH; diff=872; shape=90.42769857433808: Hypothesis 12: promote sound_buffer pointer slot to a function-wide local and use it in both Create/Lock paths; original carries a member-slot owner across resource calls.
probe 21 liveness; result=MISMATCH; diff=874; shape=90.83503054989816: Hypothesis 13: carry the newly allocated WAVEFORMATEX through the full resource descriptor as a typed local; Ghidra recovers ptVar6 and this can change EDX/ESI liveness. [same emitted code as probe 13]
probe 23 liveness; result=MISMATCH; diff=845; shape=90.42769857433808: Hypothesis 14: initialize the sound_buffer slot alias at function scope; original carries a proven member-slot pointer, testing whether early ownership changes resource register colors.
probe 24 liveness; result=MISMATCH; diff=845; shape=90.42769857433808: Hypothesis 15b: name zero only for resource descriptor reserved field; compare whether this selects original ESI zero without changing API pointer typing. [same emitted code as probe 23]
probe 26 liveness; result=MISMATCH; diff=845; shape=90.42769857433808: Hypothesis 16: name the resource sound driver receiver before loading direct_sound; original resource descriptor carries the driver in ECX across stores, unlike the direct EAX reload. [same emitted code as probe 24]
probe 28 liveness; result=MISMATCH; diff=845; shape=90.42769857433808: Hypothesis 17: delay sound_buffer slot alias assignment until after the sound-system guard; original member-slot address appears only in successful load paths. [same emitted code as probe 26]
probe 30 control-flow; result=MISMATCH; diff=845; shape=90.42769857433808: Hypothesis 18: route resource wave_info allocation failure directly to common fail_return after freeing data; test whether original tail-sharing at +BD160 comes from one common log source. [same emitted code as probe 28]
probe 32 abi; result=MISMATCH; diff=1143; shape=90.42769857433808: Hypothesis 19: discard recursive load's return and return explicit zero; tests whether original self-call's internal relocation came from a void-style statement rather than propagated int return.
probe 36 control-flow; result=MISMATCH; diff=845; shape=90.42769857433808: Hypothesis 1: remove the branch-local color_log/return after wave_info allocation failure; original Ghidra flow falls through to the common failure label, and the original BD160 push/jump skips the common c-argument push. [same emitted code as probe 35]
probe 38 liveness; result=MISMATCH; diff=872; shape=90.42769857433808: Hypothesis 2: keep one pointer-to-sound_buffer local but assign it immediately before each descriptor setup, after wave_info field stores; original materializes the member address at +01EC/+048 and carries it in EBX while ESI remains zero. [same emitted code as probe 19]
probe 40 liveness; result=MISMATCH; diff=845; shape=90.42769857433808: Hypothesis 3: restore the PDB local declaration order with resDataSize before file_with_path; PDB lists buffer_desc, wave_hdr, then resDataSize and file_with_path, and declaration order can alter the resource stack layout/code shape. [same emitted code as probe 36]
probe 42 abi; result=MISMATCH; diff=986; shape=81.26272912423626: Hypothesis 4: use the period DirectSound SDK surface from the exact Sounddrv.cpp donor (dsound.h and real IDirectSound/IDirectSoundBuffer methods) instead of narrow handwritten vtable structs; this tests whether the original SDK declarations select the missing call and register basin.
probe 44 control-flow; result=MISMATCH; diff=838; shape=90.63136456211812: Hypothesis 5: use the proven load_type value as the branch-local color_log third argument; the branch tests load_type == 1, and original ESI=1 is pushed before the tail jump at BD160 while the common call supplies only the remaining arguments.
probe 45 liveness; result=MISMATCH; diff=845; shape=90.42769857433808: Hypothesis 6: bind the proven literal-one value to a named local and use it only in the branch-local failure log; this tests whether VC5 carries the existing ESI=1 through the tail join instead of emitting the common literal push. [same emitted code as probe 40]
probe 47 liveness; result=MISMATCH; diff=845; shape=90.42769857433808: Hypothesis 7: keep one named one-value live through both resource-data ownership tests and the branch-local failure log; original ESI=1 serves both the load_type comparisons and the pushed c argument. [same emitted code as probe 45]
probe 49 liveness; result=MISMATCH; diff=845; shape=90.42769857433808: Hypothesis 8: move the function-scope sound_buffer slot alias next to buffer_desc, before wave_hdr and result locals; Ghidra's original variable order places ppIVar1 before direct_sound/result, so declaration order may recover EBX ownership without changing behavior. [same emitted code as probe 47]
probe 51 liveness; result=MISMATCH; diff=845; shape=90.42769857433808: Hypothesis 9: keep the carried slot alias for buffer reload and cleanup, but pass the direct member address to CreateSoundBuffer; original argument pushes interleave later with header stores, which may require direct address syntax even when cleanup carries a slot pointer. [same emitted code as probe 49]
probe 53 context; result=MISMATCH; diff=845; shape=90.42769857433808: Hypothesis 10b: add period windows.h and use its canonical WAVEFORMATEX while retaining the narrow DirectSound ABI; this isolates SDK type/header context from the full dsound.h surface. [same emitted code as probe 51]
```
<!-- end-recovered:bff70eca3a10407952f4 -->

<!-- recovered:01fc16715753721d3c0b -->
### `c0df8ea95b4f` `src/scratch/004BCD30_load.cpp:1-35`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TDigital::load
// Period-plausible WAV file/resource loading with the VC5 DirectSound ABI.
// Attempt log:
// - Rebuilt the file and resource paths from the original call order and stack homes.
// - Kept the five-field DSBUFFERDESC and named DirectSound vtable slots.
// - Separate cleanup branches recover all 42 original calls and the 0x15C frame.
// - An unsigned result local around both read calls reproduces cmp/ja lowering.
// - The explicit <= -1 resource gate reproduces the original cmp/jle boundary.
// - The resource Lock path tests size2. This matches its proven stack-local test.
// - A function-scope sound_buffer slot alias reduces the strict diff from 874 to 845.
// - Rejected direct positive read guards, signed read/result types, direct Create
//   guards, branch-local aliases, delayed aliases, and explicit recursive return 0.
// - Final validation: 1475-byte output, 42 calls, 0x15C frame, 845-byte strict diff.
// - Remaining drift is resource descriptor register coloring and cleanup-tail
//   layout, plus the recursive-call relocation identity.
// Claim sa-0f3d8299 probes (2026-08-22):
// - Removing the branch-local failure log did not change codegen.
// - Assigning the slot alias at each Create site worsened the diff to 872 bytes.
// - PDB local declaration order, windows.h context, and alias declaration order
//   were neutral. The full dsound.h surface worsened frame and shape.
// - Passing load_type as the branch-local log value improved strict diff to 838,
//   but added five bytes and worsened resynchronization; the natural clean source
//   remains the 1475-byte, 845-byte-diff form.
// TU captain notes (phase4):
// - Context gate proved Sounddrv.cpp, lines 507-826, TDigital ownership, and
//   the ordered 36-owner address sequence. The wrapper uses the same sequence.
// - Removed grouped-only alternate bodies from the 13 observed exact candidates.
//   Their canonical declarations remain guarded for standalone source checks.
// - Direct sound_buffer member calls reduced the grouped load diff from 986 to
//   430. A local failure label reduced the standalone diff to 385.
// - The resource buffer-slot alias reduced the final grouped diff to 383.
// - Final grouped candidate: 22 exact owners MATCH; 13 observed owners MATCH;
//   load is 1488 bytes, 383 bytes different, with one boundary escape.
// - UNRESOLVED: resource-path field scheduling, zero-register coloring, and the
//   self-recursion call identity still differ from the original.
```
<!-- end-recovered:01fc16715753721d3c0b -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
