# Logic review: 00469910 `TEasy_Panel::create_scrollbar`

## Phase transition

Exact matching is suspended. The candidate has six ordered calls and all
allocation, constructor, setup, and output-pointer paths aligned. The remaining
47-byte difference is the VC5 `/GX` shared EH cleanup-tail layout.

## Blind review cohort — 2026-08-13

Three independent reviews found no behavior difference.

- `sa-56c6b5c0` verified arithmetic order, allocation size, constructor path,
  output writes, field guard, setup arguments, post-construction failure state,
  and successful updates.
- `sa-b26625da` verified allocation and constructor failure behavior, output
  values, setup path, all post-construction failure behavior, and EH metadata.
- `sa-82067f93` verified division and fault order, allocation, constructor,
  output timing, setup, text/button/bevel updates, returns, and cleanup state.

All found that the candidate clones the zero-return cleanup epilogue. The
original jumps into one shared cleanup block. Both forms restore the same state
and return the same value on each valid execution path.

## Main-agent adjudication

The candidate is a readable typed reconstruction. It has no retained inline
assembly, volatile state, raw vtable store, or synthetic stack-layout source.

Promote it to `src/verified_logic`. This is not an exact match. The residual
output difference is the compiler's EH tail lowering.
