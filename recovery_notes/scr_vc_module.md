# scr_vc.cpp source-module recovery

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\scr_vc.cpp`.
- PDB source-order bands are 45-194, 200-219, 225-230, 236-260,
  266-293, and 299-307.
- The normal address sequence is `004B8100`, `004B87D0`, `004B88B0`,
  `004B88E0`, `004B89A0`, and `004B8AE0`.
- The compiler-generated vector-deleting destructor at `004B87B0` has no
  source body. Validate it from the complete module build.
- `TRIBE_Mission_Screen` owns all six normal bodies in this source file.

## Ownership

- `include/scr_vc.h` owns only `TRIBE_Mission_Screen`.
- Panel, screen, text, button, scrollbar, picture, game, world, scenario,
  and sound declarations come from their canonical owner headers.
- The constructor uses the canonical `use_bevels`, bevel-color, and
  `error_code` members. The executable calls the text-panel bevel virtual at
  the observed seven-argument slot.

## Recovery state

- The complete natural module is present in `src/scr_vc.cpp`.
- All six normal functions start as scratch until grouped validation proves
  exact ownership, boundaries, relocations, and direct targets.
- The shipped constructor truncates the copied scenario name by four bytes.
  Keep this behavior until binary evidence disproves it.
