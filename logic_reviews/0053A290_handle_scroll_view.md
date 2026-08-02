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

No formal blind review round has been integrated yet.

## Main-agent adjudication

Pending independent review.

## Integrated changes

None during logic review yet.

## Final decision

Pending. The function remains in `src/scratch` and must not move to
`src/verified_logic` while any substantive finding is unresolved.
