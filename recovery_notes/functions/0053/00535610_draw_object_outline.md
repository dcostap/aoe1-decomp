# Recovery journal: 00535610 `draw_object_outline`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/view.cpp`.
- PDB source: `C:\msdev\work\age1_x1\view.cpp`.
- Earlier recovery note: `recovery_notes/view_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:1526fd89e2b3068b63b6 -->
### `target-session` `build/target_sessions/00535610_draw_object_outline.json:1-26`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=239; shape=86.04651162790698: Validate current typed reconstruction before further probes; source log reports 665-byte size/frame and 12-call parity.
probe 2 control-flow; result=MISMATCH; diff=275; shape=82.32558139534883: Moved proven center arithmetic before sprite test, matching original PDB line order and target CFG; assess structural effect.
probe 4 liveness; result=MISMATCH; diff=239; shape=86.04651162790698: Swap x3 and scr_y declaration order to test proven get_tile output-home scheduling; preserve clean center guard. [same emitted code as probe 1]
probe 6 abi; result=MISMATCH; diff=239; shape=86.04651162790698: Use reviewed float-reference alignment ABI and natural reference call; test whether reference semantics recover the target conversion/output homes. [same emitted code as probe 4]
probe 9 behavior; result=MISMATCH; diff=239; shape=86.04651162790698: Restore binary get_tile failure path: return without clearing fog_next_shape.
probe 11 layout; result=MISMATCH; diff=238; shape=86.51162790697674: Make the proven world_time field unsigned; original uses SHR and unsigned compare in the fog-shape branch. Test whether natural unsigned field recovery fixes that late arithmetic topology.
probe 12 layout; result=MISMATCH; diff=237; shape=86.97674418604652: Keep world_time unsigned and make the derived fog-shape selector unsigned. The original uses an unsigned threshold branch (JAE), so this tests complete source width and signedness recovery.
probe 13 layout; result=MISMATCH; diff=247; shape=80.0: Test the binary-indicated reuse of the final alignment_box short output with frame_color. The decompiler lists no separate alignment-tail local and shows the final output pointer at the frame-color home; use a short local to preserve the proven wide write before the later byte color store.
probe 14 control-flow; result=MISMATCH; diff=233; shape=86.97674418604652: Use the exact draw_wall_outline donor's center algebra: output x3 is base x3 plus half(x4-y4) plus y4. This tests source expression topology rather than the commuted, non-donor formula.
probe 15 liveness; result=MISMATCH; diff=233; shape=86.97674418604652: Reorder the center and frame locals so x3 is declared before frame_color. The target center block stores x3 at the home that the current frame-color/x3/scr_y ordering assigns differently; test declaration-driven stack-home recovery. [same emitted code as probe 14]
probe 16 layout; result=MISMATCH; diff=249; shape=83.87096774193549: Use the named tile-output local x1 for get_tile_screen_coords and derive the final x3 center from that output. This tests the Ghidra-indicated x1 tile home while preserving the typed center geometry and scr_y output.
probe 17 control-flow; result=MISMATCH; diff=274; shape=86.97674418604652: Place both proven center updates before the sprite-null guard, matching the target PDB line order and original CFG. Keep the draw-wall donor algebra while testing the required structural block placement.
probe 18 abi; result=MISMATCH; diff=232; shape=87.44186046511628: Swap the two typed get_tile_screen_coords output references. The target builds the first output pointer at the first LEA home and the second at the second home, while the current natural call emits the reverse stack-home pattern; test whether the declaration/argument ownership is reversed.
probe 19 layout; result=MISMATCH; diff=520; shape=72.44444444444444: Follow the Ghidra-indicated tile output locals x1/x2, then use those typed short results as the center bases. This tests whether the target's output-home names are the live source variables rather than x3/scr_y.
probe 20 liveness; result=MISMATCH; diff=233; shape=86.97674418604652: Make frame_color branch-local inside the sprite path. The binary uses it only after the sprite guard, and a narrower lifetime may recover the target frame-color home without synthetic aliases. [same emitted code as probe 15]
probe 23 context; result=MISMATCH; diff=233; shape=86.97674418604652: Temporary shared view.cpp surface: exact 00535480 precedes draw_object_outline under default.rsp. Anchor MATCH; target remains 666/665, 233 diff, first +28. No tracked edit. [same emitted code as probe 22]
probe 25 baseline; result=MISMATCH; diff=188; shape=89.86175115207374: Fresh baseline in shared view.cpp TU after current continuation; 673/665 bytes, 188 strict differences, 12/12 ordered calls, 0x3C frame. The source preserves PDB-proven center-before-sprite order but has an extra named draw_flag and shifted local homes.
probe 26 liveness; result=MISMATCH; diff=274; shape=86.97674418604652: Remove the named draw_flag temporary while keeping PDB-proven center updates before the sprite guard and preserving the original direct master draw_flag read before game-mode tests. Test whether VC5 restores the original EDX draw-flag topology without changing call order or fault order.
probe 27 variant; result=MISMATCH; diff=274; shape=86.97674418604652: variant lab build\variant_lab\00535610_draw_object_outline\20260823_191706: 6 variants, 0 invariant-eligible, 0 exact
probe 28 variant; result=MISMATCH; diff=274; shape=86.97674418604652: variant lab build\variant_lab\00535610_draw_object_outline\20260823_191910: 2 variants, 0 invariant-eligible, 0 exact
probe 29 layout; result=MISMATCH; diff=193; shape=87.55760368663594: Restore donor-proven view.cpp local topology: get_tile_screen_coords writes x1/x2, alignment_box uses x4/y2/scr_x/y3/y4/y1/x2/alignment_tail, and centers update x1/x2 before the sprite guard. This follows Ghidra output ownership and the exact draw_wall_outline donor while retaining direct calls and named draw_flag.
probe 30 liveness; result=MISMATCH; diff=277; shape=81.86046511627907: Keep the Ghidra-indicated x1/x2 tile outputs and donor alignment-box topology, but remove the named draw_flag temporary. This tests the natural direct bit expression while preserving center-before-sprite ordering, object sprite guard, and direct virtual draw calls.
probe 31 layout; result=MISMATCH; diff=341; shape=75.57603686635944: Model the proven alignment-output/frame-color stack overlap as a local union: alignment_tail is the short output, frame_color is the later byte state. Keep the x1/x2 tile outputs and all ordered calls unchanged. This tests a typed overlap instead of a raw alias.
probe 33 abi; result=MISMATCH; diff=232; shape=80.93023255813954: Use the real RGE_Pick_Info scr_x/scr_y fields as get_tile_screen_coords outputs and center state, instead of duplicate locals. The packet and Ghidra listing prove these fields exist; test whether they recover the original output-home and fault-order topology.
probe 35 control-flow; result=MISMATCH; diff=188; shape=89.86175115207374: Expand both center compound assignments into explicit short assignments while preserving the target arithmetic order, center-before-sprite PDB order, and all call and global-state operations. Test whether VC5 selects the target screen-home cycle from assignment width and expression form. [same emitted code as probe 25]
probe 36 liveness; result=MISMATCH; diff=188; shape=89.86175115207374: Move the draw_flag declaration to function scope but keep its assignment at the PDB-proven line-2118 location after SDI_Draw_Line. Test declaration lifetime and register coloring without changing ordered calls or the partial draw state. [same emitted code as probe 35]
```
<!-- end-recovered:1526fd89e2b3068b63b6 -->

<!-- recovered:c734b6849fcce619e214 -->
### `056a20c24f68` `src/scratch/00535610_draw_object_outline.cpp:1-54`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00535610 RGE_View::draw_object_outline
// Source: view.cpp lines 2062-2207
// Attempt log:
// 1: broad natural reconstruction from packet: selected object, screen bounds, hit-test, bbox/project, draw outline and reset globals; after compile fixes object was too small (640 vs 665).
// 2: tried /Ob0 flag probe; no size change, flag removed.
// 3: tried /O1 /Oy flag probe; object shrank to 556 and failed configured size, flag removed.
// 4: reviewed original stack locals: eight short bbox/projection locals plus frame byte and coords; current source uses approximate uninitialized locals and wrong project signature.
// 5: reviewed original early screen bounds and hit-test call; current source matches behavior loosely but not exact argument/local shape.
// 6: original calls object vtable +24/+20/+34 and helper 00454690; current source fakes project/draw calls and misses exact helper surface.
// 7: original computes outline color from camera flags and selected result; modeled but scheduling/registers are likely wrong.
// 8: original special draw path depends on game mode/submode and view+174; modeled approximately.
// 9: final state remains too small (640 vs 665); no byte diff available.
// 10: left in scratch: needs real RGE_View/RGE_Static_Object draw/projection type surfaces and exact local short topology before matching.
// 11: canonical structural reset: restored the period RGE_Base_Game/RGE_Player/master-object ABI, RGE_View/TPanel ownership, virtual alignment/check_placement/draw slots, and typed pick/alignment_box calls. The old fake getMap/project/draw wrappers were removed.
// 12: direct absolute global surfaces restored the original fixed-address relocations and 0x3C frame; typed call order/target multiset became exact (12/12), with the remaining gap localized after the alignment call.
// 13: removing the named draw_flag temporary let VC5 retain the master vtable in EBX as in the oracle; widening the placement result to short recovered the oracle's xor-cx/mov-cl/test-cx sequence and reduced the strict gap to 225 bytes.
// 14: donor-shaped output reconstruction uses get_tile screen coordinates plus alignment_box x4/y2/scr_x/y3/y4/y1/x2/tail and the proven y4/tail midpoint formulas. Final source is size/frame exact with 12/12 calls and 54.42% exact-block coverage; remaining drift starts at the screen-coordinate output LEAs and late local-home/register scheduling. Duplicate final x3/scr_y spelling was rolled forward as the same canonical basin.
// 15: tried the natural view.cpp line-order lead by computing outline centers before the sprite gate; size matched, but the first hunk moved earlier and diff worsened from 239 to 275, so rolled back.
// 16: tested alignment output ownership and donor draw-wall center algebra; output-home swaps reached 238 bytes but lost exact islands or changed later scheduling, so rolled back.
// 17: tested a named center-offset temporary; size reached 665 but block shape worsened to 78.14%, so rolled back.
// 18: tested local declaration removal and a variant spelling; compile repair restored the clean typed source. Remaining blocker is VC5 local-home scheduling after alignment.
// 19: widened world_time to unsigned long; this recovered the original SHR and reduced the strict diff from 239 to 238 bytes.
// 20: widened the derived shape selector to unsigned; this recovered the original JAE and reduced the diff to 237 bytes.
// 21: reused frame_color as a short alignment output; frame fell to 0x38 and drift grew to 247 bytes, so rolled back.
// 22: used the exact draw_wall_outline x-center algebra (x3 + (x4-y4)/2 + y4); strict diff improved to 233 bytes.
// 23: reordered center/frame declarations; emitted code was unchanged and the source order was restored.
// 24: changed get_tile output ownership to x1/scr_y; frame stayed 0x3C but drift grew to 249 bytes, so rolled back.
// 25: moved center updates before the sprite guard; size matched but drift grew to 274 bytes and exact blocks fell, so rolled back.
// 26: swapped get_tile output pointers; drift reached 232 bytes, but both emitted output LEAs aliased one home unlike the target, so rolled back.
// 27: used Ghidra-indicated x1/x2 tile outputs; this added a call and grew the frame to 0x40, so rolled back.
// 28: made frame_color branch-local; emitted code was unchanged and the function-scope declaration was restored.
// 29: final validation remains 666/665 bytes, 0x3C/0x3C frame, 12/12 ordered calls, and 233 strict diff bytes. Pinned as current clean.
// Behavior correction: the executable returns directly when
// get_tile_screen_coords fails. It does not clear fog_next_shape on that path.
// Accepted-drift review also remains blocked by the later draw_flag/global
// pointer-read order, which changes invalid-owner fault context.
// Recovered view.cpp TU pass: the shared 0x360 RGE_View surface, /GX module
// flags, and exact 00535480 prefix keep 666/665 bytes and 233 differences.
// The 12 calls remain ordered. The output homes and fault-order blocker remain.
// Continuation sa-5abaa990-r3: PDB lines 2110-2113 prove both center updates
// precede the sprite test. Lines 2116-2119 prove the SDI store and draw-flag
// read precede the placement-color test. Canonical x1..y4 output names and an
// explicit draw-flag local restore that source order and the original early
// master draw-flag read. The grouped result improves to 188 strict differences
// with 12/12 ordered calls, but grows to 673/665 bytes. The remaining blocker
// is a three-way scr_x/scr_y/frame-color stack-home cycle and later argument
// scheduling. The result is not exact; preserve these binary-backed order fixes.
// Exact-finish audit: the shared view.cpp baseline is 673/665 bytes with 188
// strict differences, a 0x3C frame, and 12/12 ordered calls. Removing the
// named draw_flag worsens the result to 274 bytes. Ghidra/donor x1/x2 output
// ownership, pick-info screen fields, typed overlap, declaration-order, and
// swapped-output probes were worse or codegen duplicates. All probes are
// restored. The remaining first hunk is the screen-output LEA/home cycle at
// 005356D6; no exact claim is made.
```
<!-- end-recovered:c734b6849fcce619e214 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
