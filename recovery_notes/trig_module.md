# trig.cpp source reunification

PDB source: `C:\msdev\work\age1_x1\trig.cpp`.

The module owns 11 normal functions. Their source order follows the PDB line
bands from 11 through 56. The compiler-facing source is `src/trig.cpp`. The
module declarations are in `include/trig.h`.

## Evidence

- The translation-unit packet lists 11 normal owners and 492 normal bytes.
- All 11 owners were in `src/matching` and had `MATCH` with zero positional
  differences before migration.
- The PDB source order is constructor `0052A730`, `RestrictAngle` `0052A830`,
  `RestrictAngle360` `0052A850`, then the eight table accessors through
  `0052A950`.
- The original assembly shows the constructor loops over 0x1000 and 0x168
  entries. It writes the four tables at the proven class offsets.
- The original assembly contains compiler-generated static initializer
  `0052A980` (`$E1`), which tail-jumps to the constructor for global `trig`.
  This is not a normal source owner.

## Migration changes

- Merged all 11 normal source-bank bodies into `src/trig.cpp` in PDB source
  order.
- Replaced the wrapper-only context with `include/trig.h`.
- Removed source-bank fallback declarations and context-selection macros.
- Defined the shared global `trig` in the module source. Its existing consumer
  declaration remains local to `src/fractal.cpp`. This preserves the
  compiler-generated static initializer without adding a declaration to the
  constructor's source context.
- Updated `src/fractal.cpp` to include the natural module header instead of the
  removed wrapper context header.

## Status

The source status remains matching for all 11 normal owners. The captain did
not run compiler or function validation, as required by the worker contract.
The lead must validate the complete source inside the authentic `trig` context.
