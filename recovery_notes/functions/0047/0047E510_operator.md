# Recovery journal: 0047E510 `operator=`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/point.cpp`.
- PDB source: `C:\msdev\work\age1_x1\point.cpp`.

## Translation-unit context

- Module: `point.cpp`; natural source: `src/point.cpp`.
- Owning class: `XYZ`; PDB lines: 60-65.
- Address sequence: `0047E510-0047E528`.
- The source uses the canonical `XYZ` fields at offsets `0x0`, `0x4`, and
  `0x8`, then returns `*this`.

## Current mismatch

- No mismatch. Fresh baseline and final validation both match all 25 bytes.
- Original and rebuilt frame: none. Calls: 0. Relocations: 0.
- Original and rebuilt instruction counts: 9. Boundary: `0047E510-0047E528`.
- Owner symbol matches: `??4XYZ@@QAEAAV0@ABV0@@Z`.

## Recovered attempt history

- The existing natural memberwise assignment was retained without edits.
- Baseline check: `MATCH`, 0 bytes, 0.0000%, 25/25 bytes.
- Final validation check: `MATCH`, 0 bytes, 0.0000%, 25/25 bytes.
- Point translation-unit audit: 8 functions compiled; target grouped `MATCH`,
  0 bytes. Four registered neighbors also remained exact.

## Rejected approaches

- None tested. No source change was needed.

## Open questions

- The target is still marked `scratch` and is not registered as an owner in the
  module manifest. Main-agent review is needed before promotion.

## Next useful approaches

- Review promotion and ownership registration. Keep the natural memberwise
  assignment and canonical `XYZ` types.

## Worker updates

- `wave10-point`: Existing source is exact and behavior-supported. No source
  edit was made. Final target check and worker audit both passed for this VA.
