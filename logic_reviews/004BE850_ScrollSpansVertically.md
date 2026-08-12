# Logic review: 004BE850 `TSpan_List_Manager::ScrollSpansVertically`

## Phase transition

The main agent suspended ordinary exact matching after six claims and 28 meaningful probes.

The candidate is `src/scratch/004BE850_ScrollSpansVertically.cpp`.

Current validation:

- original and rebuilt size: 394 bytes;
- both calls align in exact order;
- frame, instruction count, and control flow align;
- strict difference: four bytes in the final bound reload order.

The final focused lead reused the existing `line` local. It emitted identical code.
The retained source uses typed span-list ownership and natural loops.

### Semantic questions at entry

1. Verify region and full-list bounds for positive and negative movement.
2. Verify absolute-value behavior for `INT_MIN`.
3. Verify every freed span and all five cleared array fields.
4. Verify copy direction, source and destination indices, and overlap behavior.
5. Verify the final clear range, malformed bounds, fault order, and memory effects.

## Review rounds

### Round 1 — partial blind cohort, 2026-08-12

- `sa-2d10e29e` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- DeepSeek review remains pending.

Luna found no source and executable difference for ordinary non-overflowing
inputs. It confirmed bounds, free calls, all array writes, copy direction, and
the executable's unsafe negative-movement behavior.

The review also confirmed that the executable wraps `INT_MIN` through its
absolute-value instruction sequence. The source uses `abs(int)`, which has
undefined behavior for `INT_MIN`. Keep this question open until the second
review and main-agent adjudication.
