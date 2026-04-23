# Safe hidden-label review report

Date: 2026-04-22

## Goal

Review the entries surfaced by `build/toolchain_hidden_label_safe_candidates.tsv` and promote the
highest-confidence unhandled hits into the toolchain-supplied corpus.

## Reviewed unhandled hits

At review time, the safe hidden-label report still had five high-confidence unhandled entries:

- `00551474_FUN_00551474` -> `___sbh_heap_check`
- `00554659_FUN_00554659` -> `___crtGetStringTypeW`
- `00554F71_FUN_00554f71` -> `___crtLCMapStringW`
- `00556D0F_FUN_00556d0f` -> `___crtGetEnvironmentStringsW`
- `00559EBA_FUN_00559eba` -> `___crtCompareStringW`

All five were reviewed and promoted.

## Why these five were safe to promote

### 1) `00551474_FUN_00551474` -> `___sbh_heap_check`

High-confidence evidence:

- listing excerpt directly labels the body `___sbh_heap_check`
- the function walks `___small_block_heap`
- it validates allocator metadata and returns negative CRT-style error codes
- it sits inside the already-confirmed CRT small-block-heap neighborhood

Conclusion:

- toolchain-supplied by exact VA region

## 2) `00554659_FUN_00554659` -> `___crtGetStringTypeW`

High-confidence evidence:

- listing excerpt directly labels the body `___crtGetStringTypeW`
- the function calls `GetStringTypeW` and falls back to `GetStringTypeA`
- it performs conversion/setup glue around those APIs
- it uses standard CRT locale/codepage globals, not game state

Conclusion:

- toolchain-supplied by exact VA region

## 3) `00554F71_FUN_00554f71` -> `___crtLCMapStringW`

High-confidence evidence:

- listing excerpt directly labels the body `___crtLCMapStringW`
- the function calls `LCMapStringW` and falls back to `LCMapStringA`
- it allocates temporary buffers and does conversion glue around the locale APIs
- behavior is clearly CRT locale-wrapper machinery

Conclusion:

- toolchain-supplied by exact VA region

## 4) `00556D0F_FUN_00556d0f` -> `___crtGetEnvironmentStringsW`

High-confidence evidence:

- listing excerpt directly labels the body `___crtGetEnvironmentStringsW`
- the function probes `GetEnvironmentStringsW` and falls back to `GetEnvironmentStringsA`
- it converts between wide/ANSI environment blocks
- no sign of project-authored logic

Conclusion:

- toolchain-supplied by exact VA region

## 5) `00559EBA_FUN_00559eba` -> `___crtCompareStringW`

High-confidence evidence:

- listing excerpt directly labels the body `___crtCompareStringW`
- the function probes `CompareStringW` and falls back to `CompareStringA`
- it allocates/converts temporary buffers and returns CRT-style comparison results
- clearly a runtime locale-wrapper helper

Conclusion:

- toolchain-supplied by exact VA region

## Applied classifications

Added these exact toolchain-supplied regions:

- `00551474-0055164D` — hidden CRT small-block-heap validator `___sbh_heap_check`
- `00554659-005547E3` — hidden CRT string-type wrapper `___crtGetStringTypeW`
- `00554F71-00555186` — hidden CRT locale-map wrapper `___crtLCMapStringW`
- `00556D0F-00556F0B` — hidden CRT environment-string wrapper `___crtGetEnvironmentStringsW`
- `00559EBA-0055A0C1` — hidden CRT compare wrapper `___crtCompareStringW`

## Outcome

The initial safe hidden-label report was useful as intended:

- it surfaced a review queue,
- the review stayed strict,
- and the highest-confidence remaining hits were promoted deliberately by region.

## Bottom line

For the safely scriptable lane, the hidden-label report is now paying off exactly as intended:

- script finds the candidates,
- human review signs off the best ones,
- region manifests capture the classification safely when the inventory names are still `FUN_...`.
