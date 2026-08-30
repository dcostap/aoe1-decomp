# Function notes: 0045C790 `recycle_in_to_game`

Module notes: `decomp_notes/move_obj_module.md`.

## Recovered attempt history

<!-- recovered:2ee345ba74464ce81071 -->
### `d050eea3c` `src/move_obj.cpp:264-286`

Mapping: `ambiguous`. comment lies after mapped function recycle_in_to_game at old line 173.

```text
//   global angle constants: size/CFG improved, but VC5 kept the facet load
// [non-comment lines omitted during migration]
//   scaffolding. Remaining drift starts at the facet guard and FPU scheduling.
// - Main-agent audit restored canonical polymorphic master-object ownership;
//   validated output remains the same 152-byte structural mismatch.
// [non-comment lines omitted during migration]
//   surface probes were unchanged or worse; all rolled back.
// - Literal angle constants worsened FPU bytes. A diagnostic narrow volatile
//   facet-guard lab changed size to 293B but left the sprite register mismatch;
// [non-comment lines omitted during migration]
//   multiplication-order variants, a 24-case guard/facing/angle lab, and a
//   function-scope short facing local were tested. The direct-cmp forms reduced
//   size in isolation but worsened the FPU/tail drift; no form changed the
// [non-comment lines omitted during migration]
// - Paused after the 10-hypothesis budget: 295B vs 291B, five ordered calls
//   aligned, 152 positional diff bytes; remaining lead is original ECX sprite
```
<!-- end-recovered:2ee345ba74464ce81071 -->

<!-- recovered:1cc91c1d79020a600c17 -->
### `6a2aef2e2` `src/move_obj.cpp:111-117`

Mapping: `strong`. next mapped function definition is recycle_in_to_game at old line 137.

```text
// move_obj.cpp lines 152-158
//
//   deletes `userDefinedWaypoints` and clears it; compiler emits vptr restore, EH state transitions, member Path
//   destructors, and base RGE_Static_Object destructor in the original order.
// The former standalone fragment matched with its reduced class surface.
// The natural module currently emits the RGE_Animated_Object destructor target;
// the executable calls RGE_Static_Object directly. Keep this regression visible.
```
<!-- end-recovered:1cc91c1d79020a600c17 -->

<!-- recovered:9e22a7305f9639c349c0 -->
### `6a2aef2e2` `src/move_obj.cpp:223-246`

Mapping: `ambiguous`. comment lies after mapped function recycle_in_to_game at old line 137.

```text
//   six movement-state resets, and binary-proven random-angle normalization.
// - nested/combined sprite guards, int facet count, direct member rereads, and
//   before the compare and still chose EAX for the sprite pointer.
// - retained canonical sprite/type ownership; no raw-offset or volatility
// - This session: zero-local, post-guard pointer alias, short facings, direct
//   sprite rereads, scoped/const sprite lifetime, and full static-object
//   no volatility retained in living source.
//   with five ordered calls aligned; first unresolved block is sprite/facet
//   guard (original ECX direct short compare/reload vs rebuilt EAX/AX reuse).
//   pointer/reference and mixed-alias guard forms, complete RGE_Sprite layout,
//   rebuilt EAX sprite allocation. Restored the natural int-facing source.
//   versus rebuilt EAX/zero-ECX coloring plus the later FPU multiply schedule.
// - orch2-45C970-rand: inlined debug_rand directly in the facings product,
//   shape 92.94% -> 94.12%; calls and CFG stayed aligned. The first structural
//   separate debug_rand before facet reload reached 291B and 66-byte diff.
//   Direct member rereads broke the base-call argument schedule. Reordered
//   Keep the natural separate-call form; remaining gap is ECX/EDX pointer
//   coloring and the direct facet compare.
// - shardC2-45C970: moved the existing typed sprite assignment immediately
//   after base setup, before reset stores; emitted code stayed unchanged.
//   facings, function-scope facings, scalar sprite handles, volatile facet
// - The unresolved lead remains original ECX sprite -> EDX preservation and
//   EDI facings coloring versus rebuilt EDI sprite -> ECX facings, plus the
//   and a double denominator term without an outer float cast reproduce 291B.
```
<!-- end-recovered:9e22a7305f9639c349c0 -->

<!-- recovered:c6d96c9e37bf95108d71 -->
### `5ea464107b0b` `src/scratch/0045C790_recycle_in_to_game.cpp:1-42`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0045C790 RGE_Moving_Object::recycle_in_to_game (471B)
// move_obj.cpp lines 164-202
// FLAGS: config/flags/0045C790_recycle_in_to_game.rsp (/GX for the Path local)
// Attempt log:
// - Replaced the old allocation-only scaffold with the period moving-object
//   hierarchy, Path temporary/assignment, reset sequence, base recycle call,
//   and sprite-facet random-angle normalization shown by the packet.
// - Scoped the temporary Path: this reproduces its assignment/destructor
//   sequence before the movement-state reset (294 strict diff bytes).
// - Restored the typed start waypoint and its x/y/z zeroing; this recovered
//   the original 471-byte structural basin through the base recycle call.
// - The oracle compares facet_num in memory and sign-extends it again after
//   the guard.  A narrow volatile member preserves those binary-observed
//   accesses; nested positive guards retain the common set_angle tail.
// - Inlined debug_rand into the angle expression (best 99 strict diff bytes).
//   Remaining codegen drift is the x87 pair of redundant fxch instructions
//   and the quotient sign-adjust register; the Path call identity is recorded
//   by the target-specific original-symbol override.
// - Removed the explicit float cast from the double angle quotient. This
//   removed both fxch instructions and restored the exact 471-byte structure;
//   only three quotient sign-adjust register bytes differ.
// - A named quotient temp was much worse (123 bytes). A named debug_rand
//   result with the no-fxch expression reached 13 bytes but changed the
//   original multiply setup. Restored the direct period expression.
// - Tried the natural temporary assignment `this->pathValue = Path(10);` to
//   test the original Path lifetime. It lost the exact block topology (407
//   bytes); restored the scoped named Path source.
// - Tried a natural `short facings` declaration to mirror the sprite member;
//   VC5 emitted the same 3-byte quotient-register drift, so restored `int`.
// - Tried natural copy-initialization `Path path = Path(10)`; VC5 emitted
//   unchanged code, so restored direct named construction.
// - This claim tested a natural named random_angle, function-scope short
//   facings, register-qualified facings, reversed product operands, and an
//   explicit long product cast; all kept the same 3-byte ECX/EAX drift.
// - Function-scope or register-qualified random-result locals were worse
//   (134B and 13B); a six-case quotient variant lab had no invariant lead.
// - Function-scope sprite declaration also emitted unchanged code. Restored
//   the clean direct-expression source; only quotient sign-adjust coloring
//   remains unresolved.
// - orch-45C790-b tested local comparison, reversed integer product, scope and
//   const lifetime, explicit volatile reads, long quotient typing, and math
//   header context. All reproduced the same 3-byte EAX/ECX drift; restored.
```
<!-- end-recovered:c6d96c9e37bf95108d71 -->
