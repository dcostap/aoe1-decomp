# Logic review: 0053A290 `RGE_View::handle_scroll_view`

Current source: `src/view.cpp`. This ledger contains historical review evidence.

## Phase transition

The main agent suspended ordinary exact matching on 2026-08-02 after two
independent bounded assignments and twenty focused hypotheses converged on the
same VC5 scheduling basin. Focused case-7 labs repeatedly produced either the
validated 41-byte residual or a worse tail-merged form; no exact variant was
found and the remaining source-shape lead has low expected value.

Current validated checker state:

- source remains `src/view.cpp`;
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

### Formal round 2 — fresh post-fix concurrent blind cohort

Two new reviewers independently assessed the corrected source concurrently.
They were blind to this ledger, Git history, the first cohort, and the integrated
finding, and remained strictly read-only and unleased.

#### Reviewer 3 — broad post-fix behavior

> **Verdict: PASS — no definite function-level behavioral difference found.**
>
> - Entry early return, player-view snapshot, dispatch for 2/6/7/8/default,
>   strict movement bounds, cursor thresholds, and field widths/offsets match.
> - Case 7 now has the original redraw ordering: both `mouse_last` fields precede
>   redraw; warp stores y then x, non-warp stores x then y.
> - Case 8 conversion/update behavior, default edge gating, action-specific
>   3/4/9 handling, final view-change redraw/return, all calls and arguments,
>   action-4 object reload/fallback, null/error behavior, and ownership effects
>   match.
>
> **Conditional concern:** the local `RGE_View::set_redraw` stub has an empty
> body, whereas the runtime implementation forwards to `TPanel::set_redraw` and
> has mode-2 behavior. The reviewed function nevertheless performs the correct
> virtual call through slot `+0x20`; this matters only if the local stub replaces
> the runtime implementation rather than serving as a compilation surface.
>
> External callee internals, concurrent mutation, and pathological portable-C++
> overflow/conversion behavior were not independently established. No
> instruction-evidenced discrepancy exists under the pinned runtime model.

#### Reviewer 4 — adversarial post-fix behavior

> **Definite findings:** None.
>
> **Verified behavior**
>
> - Entry, switch/default semantics, case-2 bound/redraw, case-6
>   inside/pick/view update, case-7/8 strict deltas and cursor paths, default edge
>   handling, action-4 object reload/sprite fallback, and final redraw/returns
>   match addresses `0053A290–0053A998`.
> - Correct virtual slots and arguments are used for `is_inside +0xBC`, redraw
>   `+0x20`, teleport `+0x34`, and `do_paint +0xF4`.
> - Both case-7 paths store both mouse fields before redraw, with the original
>   per-path field order.
>
> x87 C3-only equality, signed overflow/`abs(INT_MIN)`, pathological `__ftol`,
> and external callback internals are pinned-artifact or unestablished caveats,
> not concrete candidate/oracle differences.
>
> **Verdict:** Behaviorally faithful; no semantic discrepancy identified.

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

### Formal round 2 adjudication

- **Cleared — corrected case-7 ordering.** Both post-fix reviewers independently
  verified the corrected x/y-store ordering on warp and non-warp paths. Focused
  rebuilt disassembly confirms the non-warp path performs both stores before it
  reaches VC5's shared redraw/return tail, so static tail merging does not
  reintroduce the round-1 behavior defect.
- **Cleared — local empty virtual bodies.** Placeholder bodies supply vtable
  layout to this isolated translation unit; `handle_scroll_view` itself emits
  runtime indirect calls through the object's vtable. Checker and disassembly
  confirm redraw uses slot `+0x20`, so no local direct call to the empty stub is
  part of this function's behavior.
- **Cleared — numeric-language caveats.** The emitted candidate uses the same
  32-bit integer, x87 status, `__ftol`, and narrow-word operations as the
  original on the reviewed paths. Modern portable-language edge semantics are
  not substituted for the pinned artifact.
- **Cleared — remaining paths and effects.** Dispatch, predicates, external and
  virtual calls, arguments, widths, object reloads, null behavior, state writes,
  redraw decisions, and returns received independent post-fix confirmation.

No substantive finding remains open after formal round 2.

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

Approved for `verified_logic` status on 2026-08-02 after two complete fresh blind
cohorts (four independent reviews), main-agent instruction-level adjudication,
and a bounded correction followed by fresh post-fix review.

The first cohort identified one real discrepancy: case 7 called virtual redraw
between the x and y mouse-state stores. The original exposes both new values at
that call boundary. The source now stores both fields first, and focused rebuilt
disassembly confirms VC5's shared redraw/return tail preserves that corrected
runtime ordering. The second cohort independently found no remaining behavioral
difference. All switch/default values, predicates and bounds, x87/integer/short
conversions, call targets and arguments, field widths and offsets, object
reloads, cursor APIs, warp behavior, redraw decisions, null/error paths, and
returns are accounted for. No substantive finding remains open.

Final nonsemantic metrics are original/rebuilt size 1801/1801, frame
`0x24`/`0x24`, saved registers aligned, instructions 588/586, conditional
branches 59/59, jumps 9/9, strict difference 96 bytes in 15 spans, and bounded
edit cost 3.03%. Static call sites are 36/35 and returns 10/9 because VC5 merges
one corrected case-7 redraw/return with a later identical tail; path-level
disassembly verifies the call still executes after both required stores.
Promotion asserts reconstructed executable behavior, not exact code parity.
