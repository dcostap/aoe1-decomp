# Recovery journal: 00457F80 `load_terrain_types`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/map.cpp`.
- PDB source: `C:\msdev\work\age1_x1\map.cpp`.
- Earlier recovery note: `recovery_notes/map_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:33f347045dfa329b2bf1 -->
### `target-session` `build/target_sessions/00457F80_load_terrain_types.json:1-63`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 other; result=MISMATCH; diff=342; shape=68.33333333333333: Hypothesis 1: the 14th post-float token is terrain_to_draw; the earlier short is an unused field. Remove the erroneous third float local and store is_animated from its own token.
probe 3 layout; result=MISMATCH; diff=342; shape=67.08333333333333: Hypothesis 2: the post-float %hd destination is a short, not a float. Keep the existing source flow and test only the local width.
probe 5 liveness; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 3: map.cpp declares parser locals at function scope, like the adjacent border loader, rather than inside the resource iteration block.
probe 7 layout; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 4: the adjacent map.cpp border loader uses name+4 and pict_name+4 as fscanf destinations; test the same proven four-byte input overlay here.
probe 9 behavior; result=MISMATCH; diff=342; shape=68.33333333333333: Hypothesis 5: the binary stores the own is_animated token and the post-float short token as terrain_to_draw; sound_id only controls border records. [same emitted code as probe 1]
probe 11 liveness; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 6: declaration order controls the two same-width scan outputs. Declare terrain_id before sound_id so the dead filename home coalesces with terrain_id, not the border count. [same emitted code as probe 5]
probe 13 liveness; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 7: terrain_id is a function-scope local declared before fopen, allowing the dead filename parameter home to coalesce with the first scan field while retaining block-local parser state. [same emitted code as probe 11]
probe 15 liveness; result=MISMATCH; diff=331; shape=76.44628099173553: Hypothesis 8: sound_id dies after the border loop and is not reused for terrain_to_draw. Replace the late reuse with a constant to test the target local-home lifetime.
probe 17 behavior; result=MISMATCH; diff=338; shape=75.93360995850622: Hypothesis 9: recover canonical terrain field names and ownership: token 10 is is_animated, token 11 is animation_frames, tokens 15/16 are rows/cols, and token 14 is terrain_to_draw.
probe 19 behavior; result=MISMATCH; diff=342; shape=67.08333333333333: Hypothesis 10: use the binary-proven narrow field widths without a float cast: token 14 is a short terrain_to_draw, token 10 is is_animated, token 11 is animation_frames, and tokens 15/16 are rows/cols.
probe 22 liveness; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 11: the border index is block-local to the sound-border loop, allowing VC5 to reuse the dead filename home used by terrain_id; sound_id then retains a separate local home. [same emitted code as probe 21]
probe 24 liveness; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 12: border_num is a late, ignored parse output. Declare it after the contiguous short field block instead of before sound/colour locals, matching the target's separate -0x3E home. [same emitted code as probe 22]
probe 26 liveness; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 13: mirror the adjacent map.cpp loader's function-scope parser declaration order, with sound/color shorts first, then cursors, floats, FILE, resource, strings, and counters. [same emitted code as probe 24]
probe 28 behavior; result=MISMATCH; diff=342; shape=67.08333333333333: Hypothesis 14: use the repository-local canonical map reconstruction's field order: low_color_unused at token 5, med_color as sound index, is_animated/animation_frames at tokens 10/11, interval/pause floats, terrain_to_draw at token 14, rows/cols at 15/16, border_num last.
probe 31 layout; result=MISMATCH; diff=406; shape=77.82426778242677: Hypothesis 15: the border-loop counter is a short, matching the target's  lowering instead of an int count with sign extension.
probe 33 liveness; result=MISMATCH; diff=555; shape=69.70954356846472: Hypothesis 16: initialize the border-count local before fscanf. VC5 may retain a distinct short home instead of coalescing sound_id with the dead filename parameter.
probe 36 layout; result=MISMATCH; diff=324; shape=77.91666666666667: Hypothesis 17: the extra post-float short aliases an existing terrain_to_draw home, removing the third float local and testing whether this explains the four-byte frame excess.
probe 37 behavior; result=MISMATCH; diff=342; shape=67.08333333333333: Hypothesis 18: retain the frame-correct two-float alias shape, but recover the canonical field ownership and order: border_count is the final token, low_color_unused is token 5, and rows/cols occupy tokens 15/16. [same emitted code as probe 19]
probe 39 layout; result=MISMATCH; diff=342; shape=67.08333333333333: Hypothesis 19: replace the erroneous third float with a distinct short terrain_to_draw2 for token 14, preserving natural value ownership while removing the four-byte frame excess. [same emitted code as probe 37]
probe 41 context; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 20: the zero timing sentinel is the reviewed DAT_005706ac global, matching the target absolute fcomp relocation rather than a float literal.
probe 45 behavior; result=MISMATCH; diff=540; shape=74.58333333333333: Hypothesis 21a: recover the PDB-proven malformed parser source while retaining a float local for VC5: overwrite filename as the terrain id, pass name/pict_name plus four, and write the fifth short into interval plus two.
probe 47 liveness; result=MISMATCH; diff=478; shape=74.58333333333333: Hypothesis 22: make the first giant fscanf destination explicitly reuse the filename parameter home, matching the target argument and post-call stack address.
probe 49 liveness; result=MISMATCH; diff=524; shape=77.91666666666667: Hypothesis 23: remove the separate terrain-id local and use the overwritten filename parameter for the index, while changing no other parser destinations.
probe 51 liveness; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 24: move terrain_id to function scope before fopen, matching the prior natural donor basin that lets VC5 reuse the dead filename home. [same emitted code as probe 44]
probe 54 layout; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 25: apply the binary-proven four-byte input overlay consistently: scan, convert_us, and both copies use name plus four and pict_name plus four, allowing the saved-this home to overlap name[0..3].
probe 56 layout; result=MISMATCH; diff=527; shape=74.58333333333333: Hypothesis 26: model the target fifth %hd destination as the proven upper two bytes of interval, not an independent border-count local.
probe 58 behavior; result=MISMATCH; diff=527; shape=85.0: Hypothesis 27: recover the full decompiler-supported scratch-home source: filename receives both terrain and border %hd outputs, name and pict_name use plus four consistently, and the fifth short overlays interval plus two.
probe 59 behavior; result=MISMATCH; diff=526; shape=86.25: Hypothesis 28: preserve the binary-proven interval overlap at the final terrain_to_draw store; load its low short, not the independent sound-count local.
probe 60 layout; result=MISMATCH; diff=526; shape=86.25: Hypothesis 29: retain the PDB-listed unused border_num local while keeping filename as the proven terrain/border scratch home; its short slot may recover the target four-byte local block offset.
probe 61 liveness; result=MISMATCH; diff=526; shape=86.25: Hypothesis 30: give the tile-loop counter function scope and assign 19 in the target block, testing whether its natural lifetime recovers the target local block offset and register topology. [same emitted code as probe 60]
probe 62 liveness; result=MISMATCH; diff=526; shape=86.25: Hypothesis 31: permute parser float declaration order to infile, local_30, interval, testing whether target stack-home coloring follows declaration order once the binary scratch overlays are restored. [same emitted code as probe 61]
probe 63 liveness; result=MISMATCH; diff=526; shape=86.25: Hypothesis 32: declare the FILE local before the clear loop and assign it at fopen, testing whether its live range recovers the target +34 home without changing the overlay behavior. [same emitted code as probe 62]
probe 64 liveness; result=MISMATCH; diff=526; shape=86.25: Hypothesis 33: give resource_id function scope and assign it after the terrain-count guard, matching the target local list and testing the +4 block shift. [same emitted code as probe 63]
probe 65 abi; result=MISMATCH; diff=526; shape=86.25: Hypothesis 34: model the malformed %f local as a four-byte union with float and FILE-pointer views, preserving direct x87 loads while testing the PDB pointer-type evidence.
probe 66 layout; result=MISMATCH; diff=526; shape=86.25: Hypothesis 35: declare the two input buffers as sixteen-byte stack objects, testing whether name-plus-four and pict-name-plus-four then recover the target saved-this overlap and destination displacements. [same emitted code as probe 65]
probe 67 layout; result=MISMATCH; diff=502; shape=86.25: Hypothesis 36: bind a short terrain-id reference to the filename parameter home, so the proven scratch destination remains a natural 16-bit local at both parser and border scans.
probe 68 layout; result=MISMATCH; diff=495; shape=87.44769874476988: Hypothesis 37: use a short border-loop counter so VC5 can compare SI directly with the short sound-count home, matching the target border-loop topology.
probe 69 control-flow; result=MISMATCH; diff=495; shape=88.28451882845188: Hypothesis 38: use the target positive sound-index arm first, with the negative arm assigning zero, matching the original branch polarity and common store layout.
probe 70 layout; result=MISMATCH; diff=495; shape=88.28451882845188: Hypothesis 39: remove the shadowed filename-reference alias; the active inner short terrain_id already owns the target 16-bit parser loads, so the unused alias should not shape the frame.
probe 73 behavior; result=MISMATCH; diff=524; shape=87.44769874476988: Hypothesis 1: restore the PDB/decompiler parser ownership: overwrite filename for the terrain and border %hd outputs, use name and pict_name plus four, write the post-float short into interval plus two, and use a short border counter.
probe 75 context; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 2: restore the donor-supported map.cpp CRT context with stdio, string, and stdlib headers, using the period strcpy declaration instead of a local prototype.
probe 77 liveness; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 3: move the complete parser and loop local set to function scope in the PDB declaration order, so VC5 can recover the contiguous narrow homes and saved-this overlay. [same emitted code as probe 72]
probe 79 abi; result=MISMATCH; diff=406; shape=77.82426778242677: Hypothesis 4: use the PDB/decompiler short border-loop counter, matching the original SI increment and word compare instead of an int counter. [same emitted code as probe 31]
probe 81 liveness; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 5: declare the FILE stream at function scope and assign it after the clear loop, matching the PDB infile/local_38 lifetime instead of a block initializer. [same emitted code as probe 77]
probe 83 control-flow; result=MISMATCH; diff=332; shape=77.91666666666667: Hypothesis 6: put the nonnegative sound lookup in the fall-through arm, matching the target JL-to-zero layout and preserving the negative fault guard.
probe 84 behavior; result=MISMATCH; diff=333; shape=77.08333333333333: Hypothesis 7: preserve the binary-proven post-float short as the terrain_to_draw source, rather than substituting sound_id.
probe 85 layout; result=MISMATCH; diff=669; shape=68.33333333333333: Hypothesis 8: model the proven contiguous parser scratch window as a typed Terrain_Load_Scratch aggregate, including the three-byte alignment gap between the two 13-byte buffers and the stream/timing fields.
probe 87 layout; result=MISMATCH; diff=324; shape=77.91666666666667: Hypothesis 9: restore the closest prior natural basin, which reuses terrain_to_draw for the parser's post-float short and removes the separate interval home, while retaining the typed loop. [same emitted code as probe 36]
probe 88 liveness; result=MISMATCH; diff=324; shape=77.91666666666667: Hypothesis 10: give sound_id function scope before fopen, matching its target low address-taken home and its use in both the border loop and final record store. [same emitted code as probe 87]
probe 89 abi; result=MISMATCH; diff=520; shape=81.66666666666667: Hypothesis 11: reuse the dead filename parameter as the first terrain-id fscanf destination, without changing the closest frame-0x5C local basin.
probe 90 layout; result=MISMATCH; diff=605; shape=78.75: Hypothesis 12: remove the dead border_num home by reusing the existing narrow terrain_to_draw local for the extra serialized short.
probe 91 variant; result=MISMATCH; diff=605; shape=78.75: variant lab build\variant_lab\00457F80_load_terrain_types\20260823_192104: 16 variants, 0 invariant-eligible, 0 exact
probe 92 context; result=MISMATCH; diff=324; shape=77.91666666666667: Hypothesis 13: restore the authentic polymorphic RGE_Map surface and its proven 0x8C terrain base, instead of a nonvirtual gap-only owner.
probe 95 context; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 1c: restore authentic map.cpp <windows.h> context and use its period strcpy declaration instead of a conflicting local prototype.
probe 96 abi; result=MISMATCH; diff=538; shape=76.66666666666667: Hypothesis 2: use the proven entry filename parameter home as the first terrain-id and later border-id fscanf destination, preserving the binary's reused 16-bit stack home and malformed-input fault order.
probe 97 context; result=MISMATCH; diff=331; shape=77.08333333333333: Hypothesis 3: restore the authentic polymorphic RGE_Map prefix and proven 0x8C terrain base from exact map.cpp donors, without changing shared headers.
probe 98 abi; result=MISMATCH; diff=524; shape=77.91666666666667: Hypothesis 6: move the proven filename-home terrain-id reference to function scope, allowing one natural alias across the giant scan and terrain publication while preserving target parameter overwrite.
probe 99 abi; result=MISMATCH; diff=538; shape=76.66666666666667: Hypothesis 7: preserve the proven filename parameter home as both vararg scan destinations using the original-looking &filename spelling, with narrow lvalue reads for range and border indexing.
probe 100 layout; result=MISMATCH; diff=479; shape=77.5: Hypothesis 9: reuse the proven filename parameter home for the border-loop narrow destination only, removing one independent short home while retaining the separate terrain-id parser field.
probe 101 control-flow; result=MISMATCH; diff=332; shape=77.91666666666667: Hypothesis 13: put the nonnegative sound lookup in the source fall-through arm, matching the target JL-to-zero topology under the required Windows map.cpp context.
probe 102 layout; result=MISMATCH; diff=527; shape=74.58333333333333: Hypothesis 15: model the proven overlapping narrow/dword parser scratch as a four-byte union with word and float views, avoiding an invented independent border_num object while retaining scan order.
probe 103 layout; result=MISMATCH; diff=324; shape=77.91666666666667: Hypothesis 16: reproduce the closest prior parser basin with the narrow/dword post-float overlap on terrain_to_draw, the proven declaration order, and no unused interval local; this tests a supported malformed-input source model under <windows.h>.
probe 104 layout; result=MISMATCH; diff=533; shape=81.66666666666667: Hypothesis 18: in the closest 0x5C overlap basin, remove the independent border short and reuse the proven filename home for both scan IDs, testing whether the remaining four-byte parser shift is a dead border home.
```
<!-- end-recovered:33f347045dfa329b2bf1 -->

<!-- recovered:de99f27e58cd0aba9769 -->
### `489810cbdcd9` `src/scratch/00457F80_load_terrain_types.cpp:1-55`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00457F80 RGE_Map::load_terrain_types
// Attempt log:
// baseline: typed terrain record reconstruction used an approximate record.
// probe 2: canonical RGE_Tile_Set fields, reverse loaded-byte clear, convert_us,
// direct float conversion, unconditional fclose, and tile shape totals.
// probe 3: reordered locals toward the binary stack map; diff improved.
// probe 4: restored count-minus-one loop and full giant fscanf argument surface.
// probe 5: one FILE local and the second parsed float as infile; diff 333 bytes.
// probes 6-10: tested format-width, parameter-home, cursor, and interval-home
// variants. They did not improve the best source and are not retained.
// New pass: one natural forward tile cursor reduced positional drift by 2 bytes,
// while typed stdio context and cursor declaration scope emitted no new bytes.
// The positive sound-index guard follows the target branch shape but did not
// improve positional drift. The remaining gap is the input-field overlay and
// local home/register placement. Calls, cleanup, record stride, and widths match.
// Fresh shard probe: moved shape_index initialization before the giant fscanf to
// match the oracle's pre-call EBX clear; this worsened the diff by 2 bytes and
// was restored. The input-field overlay remains the next structural blocker.
// Luna pass: the oracle overlays both scan ids on the dead filename home, but a
// direct source overlay worsened the structural diff. A short border counter
// improved local compare shape but worsened positional bytes. Function-scope
// declaration and merged-counter probes were also nonproductive. The natural
// negative-first sound guard is retained; it reaches the best 331-byte diff.
// Paused: frame remains 0x60 versus 0x5C, with the scan-id home and tile-pointer
// topology still differing. Calls, cleanup, record stride, and widths match.
// Revisit pass: twenty fresh probes tested scan-field ownership, declaration
// scope/order, input-buffer overlays, counter widths, field remapping, and the
// reviewed timing global. They did not beat the pinned 331-byte clean source.
// One exploratory alias of the post-float short removed the third float home,
// reached frame 0x5C and diff 324, but it merged two distinct input fields and
// is not a valid source reconstruction. It was discarded. The clean source is
// restored. The remaining blocker is the natural local-home overlay.
// Accepted-drift blocker: the giant fscanf rejects only EOF. Partial
// conversions therefore leave later stack fields uninitialized, but the
// function still consumes them as indexes, border writes, colors, sizes, and
// division inputs. Different local homes can change these effects and faults.
// The unbounded name and pict_name conversions also have different overflow
// fault addresses. Keep this parser in scratch.
// Exact-finish audit: fresh malformed-input alias, header, declaration-scope,
// width, branch, and aggregate probes did not produce an exact result. The
// closest natural basin remains 324 bytes with frame 0x5C, but it reuses the
// post-float short as terrain_to_draw and is not a valid source recovery.
// A 16-variant source-axis lab found no size/frame/call-set invariant lead.
// The pinned natural source is restored; the open blocker is still local-home
// placement around the giant fscanf and its partial-conversion fault order.
// Managed pass: the required <windows.h> context and polymorphic RGE_Map owner
// preserve the map.cpp basin but do not change the 331-byte result. Fresh
// probes tested parameter-home views, narrow destination reuse, branch order,
// and typed interval overlap. The best result was 324 bytes with frame 0x5C.
// It used an unsupported post-float alias and was discarded. The final source
// keeps distinct narrow fields, separate float locals, ordered calls, and
// unconditional fclose. Final validation remains MISMATCH: 331 bytes, frame
// 0x60 versus 0x5C, with all eight ordered calls aligned.
// BINARY NOTE (map TU wave02): The authentic grouped wrapper keeps the same
// 331-byte parser basin and one boundary escape.  No source-only repair is supported.
```
<!-- end-recovered:de99f27e58cd0aba9769 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
