# Function notes: 004B2EF0 `TRIBE_Screen_Sed_Menu`

Module notes: `decomp_notes/scr_sedm_module.md`.

## Recovered attempt history

<!-- recovered:5ead942efbb4a1fd16e5 -->
### `d050eea3c` `src/scr_sedm.cpp:1-2`

Mapping: `strong`. next mapped function definition is TRIBE_Screen_Sed_Menu at old line 21.

```text
// PDB source module: C:\\msdev\\work\\age1_x1\\scr_sedm.cpp.
// The definitions follow the original source-line and address order.
```
<!-- end-recovered:5ead942efbb4a1fd16e5 -->

<!-- recovered:44434b1b8295ca2cfdbc -->
### `target-session` `build/target_sessions/004B2EF0_TRIBE_Screen_Sed_Menu.json:1-19`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=412; shape=91.25: Natural typed UI/menu reconstruction before focused probes; verify behavior, ordered calls, boundary, and frame.
probe 2 liveness; result=MISMATCH; diff=405; shape=91.92546583850931: Scoped typed pointer to the real button member array for initialization; test whether original mov ecx,button-base and zero stores reflect a source alias.
probe 4 liveness; result=MISMATCH; diff=417; shape=90.625: Use a typed button-array pointer only for the first initialization store; test a narrow source alias without changing loop ownership.
probe 6 context; result=MISMATCH; diff=412; shape=91.25: Use period string literals for the three proven UI strings instead of invented extern string symbols; test relocation and rdata ownership without changing behavior.
probe 7 abi; result=MISMATCH; diff=412; shape=91.25: Restore the reviewed rich TPanel/TButtonPanel virtual surface and donor-proven addRef/setMargins slots; test canonical UI ABI and vtable ownership while retaining typed fields.
probe 8 liveness; result=MISMATCH; diff=415; shape=90.625: Put the proven title pointer zero in the member initializer list while retaining typed rich UI classes; test declaration/initialization timing against the constructor prologue.
probe 10 liveness; result=MISMATCH; diff=417; shape=90.625: Use an explicit typed address-of the first real button slot and dereference it once; test whether original ECX=button-base comes from pointer spelling. [same emitted code as probe 4]
probe 12 control-flow; result=MISMATCH; diff=404; shape=91.25: Move later button and close null stores into the successful setup path; test whether VC5 hoists these independent initializations into setup argument lowering as the oracle does.
probe 13 liveness; result=MISMATCH; diff=401; shape=98.10126582278481: Initialize button slots 1-3 with a natural bounded loop before setup after fixing VC5 loop-scope naming; test unrolling versus explicit stores.
probe 14 liveness; result=MATCH; diff=0; shape=100.0: Use one natural loop for all four typed button slots, with title and close null stores outside it; test VC5's unrolled array-address basin.
probe 15 layout; result=MISMATCH; diff=10; shape=94.30379746835443: Replace the proven inherited setup-error offset with a typed TPanel member at +0xD8; verify layout ownership without changing exact code.
probe 16 layout; result=MATCH; diff=0; shape=100.0: Correct the typed base tail padding to preserve TPanel size F4 while keeping setup_error at +D8; revalidate the exact candidate.
probe 17 abi; result=MATCH; diff=0; shape=100.0: Use the reviewed text and long-ID create_button overloads: the loop passes a literal string, while close passes language ID 0x3EA as an integer.
probe 18 abi; result=MATCH; diff=0; shape=100.0: Use declaration-only virtual stubs for the local panel ABI instead of invented inline bodies; test whether the natural unresolved method surface preserves exact code.
probe 20 abi; result=MATCH; diff=0; shape=100.0: Baseline audit: current 504-byte candidate is exact but uses dummy2/dummy3/dummy4 and a narrow TPanel virtual surface; record before canonical replacement. [same emitted code as probe 19]
probe 21 abi; result=MATCH; diff=0; shape=100.0: Canonical ABI replacement after removing duplicate SDK RECT declarations: full reviewed TPanel virtual order and fields; TButtonPanel uses canonical fields and inherited set_active/set_positioning in slots +0x14/+0x18.
probe 22 abi; result=MATCH; diff=0; shape=100.0: Canonical field spelling cleanup: use reviewed TDigital* and TShape* members in the full TButtonPanel layout; verify no codegen drift. [same emitted code as probe 21]
probe 23 layout; result=MATCH; diff=0; shape=100.0: Canonical TEasy_Panel tail cleanup: replace opaque F4-478 gap with repository type-dump fields while preserving the target hierarchy size. [same emitted code as probe 22]
probe 24 layout; result=MATCH; diff=0; shape=100.0: Canonical TPanel member naming cleanup: use reviewed error_code at +0xD8 instead of a local setup_error alias; validate exact bytes. [same emitted code as probe 23]
```
<!-- end-recovered:44434b1b8295ca2cfdbc -->

<!-- recovered:f932d13927f24e17d1f4 -->
### `d18d4cc8d844` `src/scratch/004B2EF0_TRIBE_Screen_Sed_Menu.cpp:1-48`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu constructor
// VA: 004B2EF0
// PDB: scr_sedm.cpp:41-86
// FLAGS: /GX (EH-framed constructor)
//
// Attempt log:
// - draft 1: C2027/C2227 (RGE_Base_Game forward-decl), C2664 (button array cast)
// - draft 2 (fixed Game stub, layout, setup decl): compiles, 72% diff
//   Key issues: register allocation (ebx vs eax zero), lea order, vtable addr,
//   interleaved push scheduling. This is a ~500-byte EH-framed function with
//   complex VC5 scheduling. Likely needs TU-context or nearby-function
//   inclusion for register basin alignment.
// - The first mismatch (offset 43) is lea order: original computes &button[0]
//   (ebp) before &title (edi). VC5 scheduler chose this order despite title
//   being declared earlier.
// - Remaining issues are mainly register choices (eax vs ebx for zero carrier,
//   edx vs eax for rge_base_game load) and vtable/string/call relocations.
// - Left in scratch: needs TU-context / header context work for register basin.
// - worker baseline after rebuilding: 504-byte body, 14/14 ordered calls, 414
//   differing bytes; external string symbols and the RGE_Base_Game spelling
//   changed relocation names but not emitted code.
// - swapping button[0] before title recovered the original LEA order and
//   reduced the diff to 411 bytes; a pointer-array alias changed the block
//   topology/size and was rejected.
// - restored the proven 0xF4 TPanel / 0x478 TEasy_Panel sizes and TButtonPanel
//   hotkey offsets (+0x298/+0x29C).  Caching button[3] in `cancel` then made
//   the late hotkey/tab-order block exact; current clean candidate is 504
//   bytes, 160 instructions, 14/14 calls, 65.19% exact-block coverage, and
//   412 differing bytes (81.746%).
// - stdlib header context was a codegen duplicate.  A title member-initializer
//   was slightly worse.  The metric-best pointer-alias variant was 12 bytes
//   short and structurally wrong, so it is not retained.
// - title-before-button[0] matched the natural same-TU field order hypothesis,
//   but reversed the two LEAs and worsened the diff to 415 bytes; restored.
// - shardA6 session: natural button-array aliases improved the diagnostic diff
//   to 398-406 bytes but shrank the body by 12 bytes; title-first layout was
//   415 bytes, and positive success nesting grew the body to 527 bytes. All
//   variants were rolled back; clean source remains 504 bytes and 412 diff.
// - orch claim: a natural zero local, typed null carrier, and complete local
//   virtual method bodies were codegen duplicates. A button-array alias only
//   shrank the body by 12 bytes and was rolled back.
// - aligned the factory/panel declarations with exact donors (TPanel parent,
//   two button strings, long IDs, int setup flag, short tab count). Bytes did
//   not change, but the living ABI now matches the period surface.
// - absolute global/string addresses changed relocation diagnostics but did
//   not improve positional output; restored external string/global symbols.
// - left in scratch: early constructor zero-carrier/store scheduling and
//   setup-argument interleaving remain unresolved after this focused pass.
```
<!-- end-recovered:f932d13927f24e17d1f4 -->
