# Logic review: 00469AD0 `TEasy_Panel::create_vert_slider`

## Phase transition

Exact matching is suspended. The candidate has five ordered calls and aligned
allocation, constructor, setup, and output-pointer behavior. The remaining
46-byte difference is the VC5 `/GX` EH cleanup-tail layout.

## Blind review cohort — 2026-08-13

Three independent reviews found no behavior difference after ABI correction.

- `sa-d10eeb52` verified allocation, constructor failure cleanup, output timing,
  setup failure state, optional calls, and returns. It found the first setup
  parameter was incorrectly typed as `void*`.
- `sa-4c97966d` verified allocation size, null allocation, constructor cleanup,
  EH state, output assignment, all failure paths, setup arguments, and success
  calls.
- `sa-87eb71e4` verified allocation, constructor cleanup, output assignment,
  setup checks, argument widths, call and fault order, and returns.

The ABI issue is resolved. The source now declares `setup(TDrawArea*, ...)`.
Validation retained the five aligned call sites and the same 46-byte tail drift.

## Main-agent adjudication

The candidate is a readable typed reconstruction. It has no retained inline
assembly, volatile state, raw vtable store, or synthetic stack-layout source.

The original shares the zero-return EH cleanup tail. VC5 emits a cloned tail.
Both forms use the same EH cleanup, state, output values, and return values on
all reviewed paths.

Promote it to `src/verified_logic`. This is not an exact match.
