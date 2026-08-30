# Function notes: 004C2400 `capture_frame_3d_square`

Module notes: `decomp_notes/stat_obj_module.md`.

## Recovered attempt history

<!-- recovered:c3528226bf9348655ea9 -->
### `d050eea3c` `src/stat_obj.cpp:811-811`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// 004C2400 RGE_Static_Object::capture_frame_3d_square
```
<!-- end-recovered:c3528226bf9348655ea9 -->

<!-- recovered:db4eb6ef0861c410a3bc -->
### `target-session` `build/target_sessions/004C2400_capture_frame_3d_square.json:1-29`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1107; shape=71.14967462039046: Baseline current typed reconstruction: establish exact size, frame, calls, and positional mismatch before source hypotheses.
probe 2 context; result=MISMATCH; diff=1107; shape=70.93275488069415: H1: replace absolute-dereference macros with reviewed extern globals; test relocation and scheduling basin.
probe 4 liveness; result=MISMATCH; diff=1309; shape=72.23427331887201: H2: remove cached master pointer and use direct this->master_obj member reads; test original master register lifetime and frame.
probe 6 abi; result=MISMATCH; diff=1107; shape=71.14967462039046: H3: add the proven master-object virtual surface while preserving all observed offsets; test type-context codegen. [same emitted code as probe 1]
probe 8 abi; result=MISMATCH; diff=1169; shape=72.19827586206897: H4: mutate the short screen parameters and use short get_point screen arguments, mirroring the exact square-back donor's whole-word parameter homes.
probe 10 liveness; result=MISMATCH; diff=1315; shape=72.0173535791757: H5: end the cached master alias before health work; direct reloads match original health-path master load while preserving early EAX use.
probe 12 context; result=MISMATCH; diff=1107; shape=71.14967462039046: H7: restore the exact stat_obj donor's period <stdlib.h> translation-unit context; test header-driven VC5 basin changes. [same emitted code as probe 6]
probe 14 layout; result=MISMATCH; diff=1336; shape=60.52060737527115: H8: replace pointer/float output aliases with eight explicit short corner locals; test the natural get_point/AddGDINode typed model.
probe 16 liveness; result=MISMATCH; diff=1057; shape=63.77440347071583: H9: mutate screen parameters without changing the int get_point ABI; isolate parameter-home lifetime from formal-width effects.
probe 18 liveness; result=MISMATCH; diff=1107; shape=71.14967462039046: H10: register-qualify the long-lived master pointer to test the observed early EAX carry; exploratory only unless natural source survives. [same emitted code as probe 12]
probe 20 layout; result=MISMATCH; diff=1126; shape=71.05831533477321: H11: make the first corner output a real short local instead of a TShape pointer alias; keep the later shape receiver separate through pTVar2.
probe 22 abi; result=MISMATCH; diff=1107; shape=71.14967462039046: H12: narrow local_34 to its observed short output width; test stack-home width and extension timing. [same emitted code as probe 18]
probe 24 abi; result=MISMATCH; diff=1158; shape=70.66381156316916: H13: narrow the screen-y temporary to short; original AddGDINode receives a sign-extended screen-y register.
probe 26 abi; result=MISMATCH; diff=1280; shape=72.23427331887201: H14: narrow the y-line temporary itself to short, matching the original sign-extended ESI-to-EBX AddGDINode setup.
probe 28 abi; result=MISMATCH; diff=1280; shape=72.23427331887201: H15: apply an explicit short cast at every y-line call argument without narrowing the shared local; test extension scheduling at all four node paths. [same emitted code as probe 26]
probe 30 abi; result=MISMATCH; diff=1280; shape=72.23427331887201: H16: force one signed short-to-int materialization for the y-line value before all node calls; test the original EBX sign-extension point. [same emitted code as probe 28]
probe 32 liveness; result=MISMATCH; diff=1107; shape=71.14967462039046: H17: introduce one explicit yline alias that spans the node paths; test a proved call-crossing screen-y lifetime. [same emitted code as probe 22]
probe 34 liveness; result=MISMATCH; diff=1109; shape=60.52060737527115: H18: reuse one float local for radius_y and converted health, as original assembly reuses the same stack home at +0x28 across those phases.
probe 36 liveness; result=MISMATCH; diff=1107; shape=71.14967462039046: H19: scope the int health local inside the selected-health guard; test lifetime coalescing with the dead radius-y float home. [same emitted code as probe 32]
probe 38 abi; result=MISMATCH; diff=1113; shape=69.19739696312364: H20: test the decompiler's short y2 candidate against the byte-store evidence; verify width before any liveness tuning.
probe 40 layout; result=MISMATCH; diff=1107; shape=72.0173535791757: H21: model the decompiler's distinct short x3 output and keep ry1 as a float radius temporary; test selective alias separation.
probe 42 layout; result=MISMATCH; diff=1107; shape=72.0173535791757: H22: use the decompiler's distinct short y1 for the third projected output, leaving the float ry1 radius live. [same emitted code as probe 40]
probe 44 layout; result=MISMATCH; diff=1109; shape=72.25806451612904: H23: separate both decompiler short outputs x3 and y1 from the float/pointer aliases; test combined local-home pressure.
probe 47 abi; result=MISMATCH; diff=1107; shape=71.14967462039046: H24: replace explicit vptr fields with real period virtual destructors on RGE_Static_Object and RGE_Master_Static_Object, preserving all observed offsets; test natural polymorphic ownership rather than manual vptr storage. [same emitted code as probe 46]
probe 48 abi; result=MISMATCH; diff=1107; shape=71.14967462039046: H25: use the donor-proven polymorphic RGE_Player surface with a +0x3C world field, replacing the flat gap while preserving the observed owner/world offsets. [same emitted code as probe 47]
probe 49 behavior; result=MISMATCH; diff=1291; shape=71.8004338394794: H26: follow the original health projection's proven z operand: the radius-z home is overwritten by negated x radius before the 1091 get_point call, so test neg_x3 instead of retaining radius_z.
probe 51 context; result=MISMATCH; diff=1109; shape=71.14967462039046: H27: use the reviewed extern rge_base_game symbol instead of an absolute-storage macro, as exact same-TU donor evidence requires the extern compiler surface.
probe 52 abi; result=MISMATCH; diff=1107; shape=71.14967462039046: H28: restore polymorphic period surfaces for Map, Game_World, and Base_Game while keeping get_point/get_shape nonvirtual direct calls and every observed field offset fixed. [same emitted code as probe 48]
probe 53 layout; result=MISMATCH; diff=1113; shape=66.45161290322581: H29: evaluate the negative radius before screen-offset sums, matching the original FPU-first geometry setup at 004C24C7 before parameter-home additions.
```
<!-- end-recovered:db4eb6ef0861c410a3bc -->

<!-- recovered:b3cd1c098ac2620e82ae -->
### `912332e8f578` `src/scratch/004C2400_capture_frame_3d_square.cpp:1-54`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004C2400 RGE_Static_Object::capture_frame_3d_square
// PDB: stat_obj.cpp:1010-1193
// Attempt log:
// - The prior notebook modeled only four corners and one draw call; it missed
//   the 14-node capture/selection/ID-marker paths and used fake helper types.
// - Current reconstruction follows the packet's typed ownership, exact map
//   get_point/AddGDINode/AddDrawNode surfaces, health-bar path, and ID digits.
// - Added the fifth health-bar projection and restored the original ordered
//   call sequence; int ID digits and parameter-home aliases align all 14 calls.
// - Inverted the digit branch only to reproduce VC5's original block order;
//   this is source-control evidence, not a behavior change.
// - Kept the cached base-game/master aliases after direct-member and outline
//   cache probes regressed the emitted basin.
// - Tried a typed geometry reorder: initialize map before master, read
//   outline_type directly, and reload master fields in the health path. The
//   frame fell to 0x44 and positional diff grew to 1275; restored the clean
//   source. The first hunk still points to local-home lifetime and geometry
//   temporary layout, not a call or CFG gap.
// - Loaded owner/world/map before the master alias. This improved the local
//   register basin to 1158 bytes without changing the call set.
// - Widened only the shared y screen-coordinate temporary to int. The best
//   result was 1344 bytes, 0x48 frame, and 1107 positional diff bytes.
//   Widening both coordinates, narrowing the yline, and reloading master
//   fields regressed; those forms were rolled back.
// - Paused: current code is 1344 vs 1382 bytes, frame 0x48 vs 0x54, 100%
//   ordered-call alignment, 71.15% shape, and 1107 positional diff bytes.
//   Remaining structural lead is original local-home/register allocation and
//   map/yline lifetime; no call-target or CFG-count gap remains.
// - Fresh worker pass: 23 meaningful probes. Extern globals, a virtual master
//   surface, <stdlib.h>, register qualification, and scoped yline aliases did
//   not change the clean 1344-byte basin. Direct master reads regressed to
//   1309 bytes. Parameter mutation reduced the strict diff to 1057 bytes but
//   broke the early register basin and was rolled back.
// - Explicit corner locals widened the drift. Narrow yline and call casts
//   moved the frame to 0x4C and worsened the diff. Reusing a float radius
//   local for health added a second __ftol call. These forms are rejected.
// - Decompiler-supported short output locals x3/y1 changed only the stack
//   frame to 0x4C. Using both changed it to 0x50 and gave 1109 diff bytes.
// - Replaced manual vptr fields with real polymorphic period surfaces for the
//   static object, master object, player, map, world, and base-game types.
//   All observed offsets and emitted bytes stayed unchanged; the source now
//   follows the exact same-TU ownership model without handwritten vptrs.
// - Tested the health projection with neg_x3 as its z input because the
//   original overwrites the radius-z home before that call. VC5 removed the
//   dead radius load and moved to a 0x44 frame with 1291 differing bytes;
//   restored the natural radius_z expression, whose home naturally reuses
//   the negated radius value in emitted code.
// - Tested the reviewed extern rge_base_game declaration. It changed the
//   relocation schedule and worsened the result by two bytes, so the target's
//   absolute global form remains the current local source evidence.
// - Evaluated radius negation before screen offsets to follow the FPU-first
//   original block. It worsened shape and strict drift; restored source order.
//   The clean source remains the best natural checkpoint: 1344 bytes, 0x48
//   frame, 14 ordered calls, 71.15% shape, 1107 positional diff bytes.
```
<!-- end-recovered:b3cd1c098ac2620e82ae -->
