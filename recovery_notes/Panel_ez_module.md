# Panel_ez.cpp source migration

## Ownership

- PDB source: `C:\\msdev\\work\\age1_x1\\Panel_ez.cpp`
- Source: `src/Panel_ez.cpp`
- Header: `include/panel_ez.h`
- Flags: `config/flags/00467380_setup_shadow_area.rsp`
- Normal owners: 76
- Generated entry: `00466A70` scalar deleting destructor

The source keeps all 76 normal bodies in PDB source order. The order starts at
`00466A20 TEasy_Panel::TEasy_Panel` and ends at
`0046A670 TEasy_Panel::set_system_colors`.

The old source used two wrappers for one PDB module. The migration gives every
normal owner one compiler-facing source: `src/Panel_ez.cpp`. The old wrappers,
fragment files, fallback declarations, and context macros are removed.

The old registry had 68 registered exact owners. The direct registry keeps 65
owners after three merged-context regressions. The remaining matching owners
are present in the direct source but remain unregistered. The two accepted-drift
owners and six scratch owners remain nonexact.

## Context evidence

- PDB module: `C:\\msdev\\work\\age1_x1\\Panel_ez.cpp`
- Class owner: `TEasy_Panel`
- PDB source lines: 44 through 2013
- Address sequence: `00466A20` through `0046A670`, as listed in the generated
  Panel_ez module packet
- The generated scalar deleting destructor at `00466A70` has no PDB source
  line and remains outside normal-owner metadata.

The module header owns the reviewed panel, draw-area, shape, dialog, and API
surfaces. The source has no inline assembly, fake virtual slots, raw vtable
field, `.cpp` include, or fallback declaration.

## String evidence

The original `empiresx.exe` stores the two checkbox strings in `.data`:

- `00580460` starts with bytes `20 00`, which is the literal `" "`.
- `00583B74` starts with bytes `58 00`, which is the literal `"X"`.

The same bytes occur in both repository copies of the original executable.
The direct source now uses the module literals `s_space` and `s_X`.
No raw string-address cast remains.

## Validation

- Direct source definition count: 76.
- One fresh candidate TU validation checked generated owner `00466A70`.
  Result: `MATCH`, zero diff bytes, zero relocation mismatches, and zero
  boundary escapes.
- A focused `check_function --no-build` check was attempted after final source
  cleanup. The registered cached object was stale, so no final exact claim is
  made from that check.
- The grouped direct audit retained 65 registered matches. `00468CB0`,
  `00468E50`, and `00469380` differ by two, two, and one bytes. They are
  scratch and are removed from the direct exact registry.

## Open exactness state

The migration does not change the existing function bodies or status classes.
The known nonexact owners remain `00466A90`, `00467380`, `004675C0`, `00468000`,
and `004696B0` according to the module packet. Fresh focused owner checks need
one later cache rebuild under the direct source path.
