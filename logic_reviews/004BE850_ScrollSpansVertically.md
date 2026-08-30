# Logic review: 004BE850 `TSpan_List_Manager::ScrollSpansVertically`

Current source: `src/spanlist.cpp`. This ledger contains historical review evidence.

## Phase transition

The main agent suspended ordinary exact matching after six claims and 28 meaningful probes.

The candidate is `src/spanlist.cpp`.

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

### Round 1 — concurrent blind cohort, 2026-08-12

- `sa-2d10e29e` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-6946de4a` — `deepseek/deepseek-v4-flash`, high

Luna found no source and executable difference for ordinary non-overflowing
inputs. It confirmed bounds, free calls, all array writes, copy direction, and
the executable's unsafe negative-movement behavior.

DeepSeek independently found no behavioral difference. It confirmed signed
bounds, all five arrays, call arguments, copy order, and clear ranges. It also
confirmed the executable's unsafe negative indices and wrapped `INT_MIN` path.

## Main-agent adjudication

The candidate matches the pinned VC5 executable, including its unsafe arithmetic
and out-of-bounds negative-scroll behavior. The source and executable touch the
same addresses in the same order. The four changed bytes only reverse two
loop-invariant bound reloads.

Promote to `verified_logic` status.
