# `scr_mp.cpp` source-module recovery

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\scr_mp.cpp`.
- The normal source-order bands are 68-220, 225-241, 247-252, 258-365,
  370-410, and 415-424.
- The address sequence is `0049F370`, `0049F890`, `0049F9A0`, `0049F9D0`,
  `0049FED0`, and `004A00A0`.
- All six bodies belong to `TribeMPStartupScreen`.
- `0049F870` is the compiler-generated vector-deleting destructor.

## Natural provider composition

`src/scr_mp.cpp` is the compiler-facing owner for all six normal bodies. It
uses `include/scr_mp.h`, `include/scr_cj.h`, and the canonical panel, registry,
communications, and BaseGame headers.
It does not use a context header, copied class declaration, wrapper, or source
fragment.

The constructor uses the canonical `RGE_Base_Game`, panel, registry, and
communications providers. Its natural candidate has 154 differing bytes.
This remains `scratch`. No reviewed semantic ledger proves localized
equivalence, so the byte difference is not an accepted-drift claim.

The source uses direct child deletion and typed registry buffers. The action
body at lines 258-365 consumes the complete `TribeJoinScreen` owner from
`include/scr_cj.h`.

## Validation

The grouped candidate is `build/candidate_tus/final_natural_scr_mp4/report.txt`.
It reports `MATCH`, `0.0000%`, correct owner symbols, zero relocation-target
mismatches, and zero boundary escapes for four exact bodies.

The compiler-generated `0049F870` destructor also reports `MATCH` and
`0.0000%`. The scratch constructor reports 154 differing bytes. The scratch
destructor reports 223 differing bytes. Neither is part of the exact
registration.

The translation-unit registry lists four exact bodies. The source-module
manifest records all six normal owners and their current statuses.
