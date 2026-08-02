# Logic review: 0053A290 `RGE_View::handle_scroll_view`

## Phase transition

The main agent suspended ordinary exact matching on 2026-08-02 after two
independent bounded assignments and twenty focused hypotheses converged on the
same VC5 scheduling basin. Focused case-7 labs repeatedly produced either the
validated 41-byte residual or a worse tail-merged form; no exact variant was
found and the remaining source-shape lead has low expected value.

Current validated checker state:

- source remains `src/scratch/0053A290_handle_scroll_view.cpp`;
- original/rebuilt size: 1801/1801 bytes;
- frame: `0x24`/`0x24`;
- saved registers: `ebx, ebp, esi, edi` / `ebx, ebp, esi, edi`;
- calls: 36/36 ordered and target-aligned;
- CFG signals: 59/59 conditional branches, 9/9 jumps, 10/10 returns;
- instructions: 588/588;
- instruction shape: 99.15%; exact-block coverage: 89.63%;
- strict difference: 41 bytes in 11 spans, first mismatch `0053A485`;
- edit/resync cost: 61 raw, 1.69% bounded.

The residual is localized to case 7. Register coloring cascades through the warp
path, and the rebuilt in-bounds path writes `mouse_last_x`, calls virtual
`set_redraw(1)`, then writes `mouse_last_y`, whereas the original instruction
order appears to perform both stores before the virtual call. That ordering is
potentially observable through virtual dispatch or reentrancy and is therefore
an explicit semantic-review question, not presumed harmless drift.

### Cumulative matching evidence

- Dispatch, size, frame, instruction count, CFG signal counts, all calls, vtable
  slots, constants, major paths, and the long function tail are aligned.
- The first assignment reconstructed the natural switch/default edge-scroll
  structure and reduced broad drift to a localized 41-byte case-7 region.
- The second assignment tested ten targeted liveness, context, control-flow,
  layout, pointer-local, result-local, comma-expression, base-dispatch, and
  focused variant-lab hypotheses. The best emitted code did not improve.
- Stores-first spellings repeatedly trigger a worse VC5 tail merge; the retained
  between-stores spelling preserves the closest overall machine-code topology.

### Semantic questions at entry

Blind reviewers must establish these directly from the executable:

1. Whether case 7 must write both `mouse_last_x` and `mouse_last_y` before
   `set_redraw(1)`, and whether the virtual call can observe or reenter this state.
2. Exact field-write order in the case-7 warp and in-bounds branches, including
   the order of x/y restoration and redraw.
3. Exact arguments and memory effects of `ClientToScreen`, `SetCursorPos`,
   `bound_point`, `pick`, `set_view_loc`, `teleport`, `set_selection_area`, and
   `do_paint` on every reachable dispatch arm.
4. Signed bounds and edge behavior for mouse deltas, clip-rectangle comparisons,
   `abs`, short truncation, float multiplication, and integer conversion.
5. Behavior for every `scroll_action` value, including values outside the named
   cases and the byte-width semantics of the member.
6. Nullability and access order for `player`, `selected_obj`, sprite pointers,
   sprite-list pointers, render-area handles, picked objects, and tiles.
7. Exact return values and redraw decisions on unchanged-view, failed-pick,
   warp, teleport, paint, and default edge-scroll paths.

## Review rounds

### Formal round 1 — complete concurrent blind cohort

Two fresh reviewers ran concurrently, blind to this ledger, Git history, prior
reports, and harmlessness claims. Both were strictly read-only and unleased.

#### Reviewer 1 — broad adversarial behavior

> **Conclusion:** The candidate matches the original executable's ordinary
> control flow, predicates, offsets, calls, argument order, conversions, and side
> effects across cases 2, 6, 7, 8, and default dispatch. One definite
> reentrancy-visible difference remains.
>
> **Definite difference**
>
> For `scroll_action == 7`, when both drag distances are `<= 8`, the source does
> `mouse_last_x = param_1; set_redraw(1); mouse_last_y = param_2;`. Original
> instructions `0053A484–0053A493` write both fields before the virtual redraw
> call. A redraw override or reentrant callback can therefore observe old
> `mouse_last_y` in the candidate but the new value in the original.
>
> **Verified assumptions**
>
> - Only 2, 6, 7, and 8 have dedicated switch paths; all other byte values use
>   the edge-scroll path.
> - Case 7/8 nonzero deltas are strictly `-99..99`; edge deltas are strictly
>   `-199..199`; cursor warp uses distance `> 8`.
> - The 16-bit `map_x`/`map_y` writes and order match.
> - `pick`, `is_inside`, `bound_point`, `set_view_loc`, `set_selection_area`,
>   `teleport`, `do_paint`, and virtual redraw targets and arguments match.
> - Case 4 reloads `selected_obj` after teleport and follows the original
>   sprite-list/sprite/fallback level chain.
> - Case 9 passes pre-update coordinates to `do_paint`; null/failure paths and
>   final view-change return/redraw logic match.
>
> Extreme signed subtraction/`abs(LONG_MIN)` depends on pinned VC5 wraparound.
> The ordering difference is definitely present at a virtual call boundary even
> though observability requires inspection or reentry.
>
> **Recommendation:** Not fully equivalent until the case-7 stores both precede
> redraw.

#### Reviewer 2 — dispatch, calls, state ordering, and numeric edges

> **Definite finding:** Case 7's non-warp path has the wrong observable write
> order. Original `0053A484–0053A493` writes `mouse_last_x` and
> `mouse_last_y`, then calls virtual `set_redraw(1)`. The candidate calls between
> the stores. A reentrant/overridden redraw sees different state and any
> callback mutation of `mouse_last_y` is overwritten afterward. The case-7 warp
> path is correct: y store, x store, then redraw.
>
> **Verified matches**
>
> - Switch/default semantics and virtual slots `is_inside +0xBC`, redraw
>   `+0x20`, `do_paint +0xF4`, and teleport `+0x34` match.
> - Direct helpers and both stdcall Windows APIs have matching arguments and
>   cleanup.
> - Signed thresholds, strict clipping ranges, `abs(...) > 8`, 16-bit map
>   updates, float conversions, nullability/unguarded dereferences, sprite
>   fallback, and return/redraw decisions match apart from case-7 timing.
>
> x87 C3-only equality and extreme signed overflow are pinned-artifact caveats,
> not separately evidenced mismatches.
>
> **Verdict:** Reject strict behavioral equivalence until the non-warp source is
> `mouse_last_x = param_1; mouse_last_y = param_2; set_redraw(1);`.

## Main-agent adjudication

### Formal round 1 adjudication

- **Confirmed — case-7 non-warp write/call order.** Original B018 loads the
  redraw vtable and argument, writes `mouse_last_x`, writes `mouse_last_y`, then
  performs the virtual call. The candidate's retained matching-oriented source
  calls redraw between those writes. Virtual dispatch is an observable boundary:
  an override can inspect both fields or mutate `mouse_last_y`, so this is a real
  behavioral difference and blocks promotion.
- **Cleared provisionally — all other reviewed paths.** Both independent reports
  agree with instruction evidence on dispatch, predicates, calls and arguments,
  widths, null behavior, FPU/integer conversions, warp path, object/sprite
  handling, redraw decisions, and return values. These areas require fresh
  confirmation after the source fix but have no current open finding.
- **Cleared — portable-overflow caveats for the pinned artifact.** Promotion is
  judged on the actual VC5-emitted candidate. Final adjudication will verify its
  32-bit arithmetic and x87 predicates directly rather than substitute modern
  portable-language semantics.

The confirmed issue is bounded and its exact correction is proved by original
instruction order, so the main agent will integrate it directly before another
fresh blind cohort.

## Integrated changes

- Changed the case-7 non-warp source to store `mouse_last_x` and
  `mouse_last_y` before calling `set_redraw(1)`, matching the original's
  observable state at the virtual call boundary. Validation and resulting
  metrics are recorded after the edit.
- Post-fix validation: size remains 1801/1801, frame `0x24`/`0x24`, saved
  registers aligned, instructions 588/586, strict difference 96 bytes, bounded
  edit cost 3.03%, and CFG signals 59/59 conditionals and 9/9 jumps. Static call
  sites are 36/35 because VC5 tail-merges the corrected case-7 redraw/return with
  the later identical redraw/return tail; focused disassembly confirms the
  case-7 path performs both field stores and then reaches the shared virtual
  `set_redraw(1)` call. This is a code-layout regression from the 41-byte
  matching-oriented source but a required semantic correction.

## Final decision

Pending. The function remains in `src/scratch` and must not move to
`src/verified_logic` while any substantive finding is unresolved.
