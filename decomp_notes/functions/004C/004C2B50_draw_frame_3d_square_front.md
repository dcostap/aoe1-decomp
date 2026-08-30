# Function notes: 004C2B50 `draw_frame_3d_square_front`

Module notes: `decomp_notes/stat_obj_module.md`.

## Recovered attempt history

<!-- recovered:f3c93a760547c8048bde -->
### `d050eea3c` `src/stat_obj.cpp:1074-1074`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// 004C2B50 RGE_Static_Object::draw_frame_3d_square_front
```
<!-- end-recovered:f3c93a760547c8048bde -->

<!-- recovered:5c8e6d9f213f9b559c0d -->
### `target-session` `build/target_sessions/004C2B50_draw_frame_3d_square_front.json:1-26`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=56; shape=97.83549783549783: Revalidated current clean source before evidence-driven health-bar probe; prior best is 670B/56-byte mismatch with calls, frame, and CFG aligned.
probe 2 behavior; result=MISMATCH; diff=72; shape=82.68398268398268: Used Ghidra decompiler evidence: health projection and both health rectangles consume x2/y2, not x1/y1. This tests the canonical local ownership without opaque aliases.
probe 5 variant; result=MISMATCH; diff=56; shape=97.83549783549783: Tested equivalent bar-left spelling x1 + (-12) against the current (-12) + x1 form, targeting the original add-immediate lowering in the first health rectangle. [same emitted code as probe 4]
probe 6 variant; result=MISMATCH; diff=88; shape=96.1038961038961: Tested the decompiler-supported direct health rectangles and direct fill ratio expression, removing bar-base and fill-right aliases while keeping typed coordinates.
probe 8 variant; result=MISMATCH; diff=56; shape=97.83549783549783: Kept the binary-close first rectangle aliases but removed only fill_right, forcing the ratio computation to remain a named value while the second right edge uses the decompiler's direct -12 plus x form. [same emitted code as probe 5]
probe 9 variant; result=MISMATCH; diff=56; shape=97.83549783549783: Tested a single compound bar-left update (initialize x1, then add -12) to seek the oracle's six-byte add-immediate lowering without changing the second rectangle. [same emitted code as probe 8]
probe 10 behavior; result=MISMATCH; diff=56; shape=97.83549783549783: Tested the Ghidra-supported x2/y2-first output-local ownership across both outline edges and the health projection, with endpoint uses swapped to preserve geometry behavior. [same emitted code as probe 9]
probe 11 variant; result=MISMATCH; diff=88; shape=96.1038961038961: Tested the decompiler's x2/y2 health expressions in the full swapped-output-local source, while preserving ratio computation after the outline FillRect. [same emitted code as probe 6]
probe 15 liveness; result=MISMATCH; diff=142; shape=66.95278969957081: Exact same-TU draw_frame donor uses mutable x/y health-bar bounds with pre-increment and compound updates. Applied the natural x1 -= 12, y1 -= 1 form so both FillRect calls reuse the mutated bounds.
probe 17 variant; result=MISMATCH; diff=142; shape=66.95278969957081: variant lab build\variant_lab\004C2B50_draw_frame_3d_square_front\20260817_130344: 12 variants, 0 invariant-eligible, 0 exact
probe 18 abi; result=MISMATCH; diff=56; shape=97.83549783549783: Same-TU exact draw_frame donor declares FillRect color as unsigned char. Tested that reviewed period ABI surface against the target's long color declaration.
probe 20 liveness; result=MISMATCH; diff=56; shape=97.83549783549783: Same-TU donor evidence also supports mutable int health bounds. Tested int copies with compound -1/-12 updates, avoiding short-output lifetime changes from the prior probe. [same emitted code as probe 14]
probe 22 abi; result=MISMATCH; diff=99; shape=96.98275862068965: The master hp field is a proven short. Tested a short denominator local instead of the current widened int local while retaining the exact signed compare and divide behavior.
probe 24 abi; result=MISMATCH; diff=56; shape=97.83549783549783: FillRect takes long coordinates in the target declaration. Tested long health-bar base locals instead of int, matching the member ABI width without changing behavior. [same emitted code as probe 20]
probe 26 liveness; result=MISMATCH; diff=122; shape=80.08474576271186: Exact draw_frame donor uses independent mutable rectangle bounds and compound updates in call arguments. Tested separate int left/top/right/bottom locals with right-to-left compound updates.
probe 28 context; result=MISMATCH; diff=56; shape=97.83549783549783: The exact same-TU draw_frame donor includes stdlib.h. Tested that period header context as a supported translation-unit codegen hypothesis.
probe 30 context; result=MISMATCH; diff=56; shape=97.83549783549783: Combined the exact draw_frame donor's stdlib.h context and unsigned-char FillRect color ABI. The pair tests whether the donor context only works together.
probe 32 abi; result=MISMATCH; diff=56; shape=97.83549783549783: Retested the full exact-donor RGE_Base_Game virtual surface after adding the required forward declaration. The surface keeps get_panel at slot 0x2C.
probe 35 liveness; result=MISMATCH; diff=56; shape=97.83549783549783: Fresh bound-lifetime probe: initialize the two integer bar bases from outputs, then apply natural compound offsets. [same emitted code as probe 34]
probe 37 liveness; result=MISMATCH; diff=56; shape=97.83549783549783: Fresh second-fill probe: name all four integer rectangle bounds after the guarded ratio calculation. [same emitted code as probe 35]
probe 41 behavior; result=MISMATCH; diff=479; shape=84.84848484848484: Hypothesis: use the PDB/Ghidra direct health expressions and direct master hp read; retain additive -12 spelling to test original ADD lowering and right-to-left argument order.
probe 43 liveness; result=MISMATCH; diff=56; shape=97.83549783549783: Hypothesis: materialize bar_left from x1 then compound-add -12 to force the original ADD lowering while preserving the validated alias source. [same emitted code as probe 40]
probe 45 behavior; result=MISMATCH; diff=88; shape=96.1038961038961: Hypothesis: replace only the two health calls with direct Ghidra coordinate expressions while retaining the validated named denominator and fill-height lifetimes. [same emitted code as probe 11]
probe 47 liveness; result=MISMATCH; diff=56; shape=97.83549783549783: Hypothesis: remove fill-height and fill-right temporaries, keeping only the direct ratio expression for the second FillRect; this tests the PDB-local inventory and original arithmetic schedule. [same emitted code as probe 43]
probe 48 liveness; result=MISMATCH; diff=139; shape=76.92307692307692: Hypothesis: mutate the short x1 output in place with += -12, then reuse that shifted base in both health calls; retain the existing bottom alias to isolate the original ADD lowering.
probe 50 variant; result=MISMATCH; diff=56; shape=97.83549783549783: Hypothesis: use the natural x1 + -12 operand order instead of (-12) + x1 to test VC5 ADD/SUB selection without changing health lifetimes. [same emitted code as probe 47]
```
<!-- end-recovered:5c8e6d9f213f9b559c0d -->

<!-- recovered:4447c5804c297d42a268 -->
### `e1de88963e6b` `src/scratch/004C2B50_draw_frame_3d_square_front.cpp:1-42`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// Attempt log for 004C2B50 RGE_Static_Object::draw_frame_3d_square_front
// Prior attempts matched the 668-byte size but used an approximate geometry
// surface. The owner, master, and health-bar fields were not canonical.
// Fresh reconstruction: use the period class fields and the neighboring
// square-frame source shape before testing code-generation variants.
// Probe summary: short draw parameters plus direct coordinate mutation now
// reach the best 671B / 83-byte mismatch. Remaining mismatch is the health
// rectangle argument schedule and final padding; calls, frame, and CFG align.
// Probe 15: assign the canonical x outline radius before y, matching the
// neighboring square-frame geometry source order; test the original B0/AC
// load order without changing the typed ownership model.
// Result: geometry prologue now matches through the panel guard; 671B / 100
// bytes, up from 104. The remaining structural hunk is the front-face
// coordinate-offset expression and its 16-bit VC5 scheduling.
// Probe 17: short draw parameters improved the central offset block to 83B;
// direct x/y use preserved it. Unsigned offsets, aliases, cached offsets, and
// alternate health-bar spellings did not improve the clean source.
// The panel clip region is a named field. The prior raw offset expression was
// only a diagnostic form.
// Probe r1: executable y-2..y-1 and x-12..x+12 health rectangles were tested;
// direct forms emitted 674B and did not improve the structural basin.
// Probe r1: int bar-left/bar-bottom bases, declared bottom before left, reduced
// the mismatch to 56B / 670B. The bases are retained as the best clean source.
// Probe r1: x2/y2 output aliases and reused bar bases regressed the CFG or
// stack layout. A six-case health-bar variant lab found no eligible winner.
// Probe r1 final: compound base updates regressed to 64B; restored the 56B
// integer-base form. Calls, frame, and CFG align; final drift is health-bar
// register/opcode scheduling and two bytes of tail size.
// Revisit r2: revalidated the clean source at 670B with 56 differing bytes.
// The Ghidra x2/y2 health-local form regressed to 72B; direct health rectangle
// forms regressed to 88B. Output-local swaps and equivalent arithmetic forms
// duplicated the 56B basin. Restored the pinned typed source for final pause.
// Revisit r3: completed 10 more evidence-led hypotheses before this pause.
// Same-TU mutable short bounds caused a 0x20 frame and 142 differing bytes.
// Unsigned-char FillRect, mutable int bases, long bases, stdlib.h, and the
// combined donor context all duplicated the 670B / 56-byte basin.
// A short denominator caused 674B / 99 bytes. Separate mutable rectangle
// arguments kept 668B but caused 122 bytes and broad block drift.
// The full RGE_Base_Game virtual surface also duplicated the 56-byte basin.
// A 12-case lab found nine variants in the 670B basin and three at 674B.
// No variant passed the size, frame, and call-set gates. The typed source is
// restored and remains the best clean reconstruction.
```
<!-- end-recovered:4447c5804c297d42a268 -->
