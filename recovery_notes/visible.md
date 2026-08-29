# `visible.cpp` source-module migration

## Ownership

- PDB source: `C:\\msdev\\work\\age1_x1\\visible.cpp`.
- Source: `src/visible.cpp`.
- Header: `include/visible.h`.
- Flags: `config/flags/default.rsp`.

The source owns 27 normal PDB functions. Their order follows the PDB. The
source has one compiler-facing owner for each function.

The old wrapper, source-bank fragments, fallback declarations, and context
header are removed. The source uses no wrapper include or recovery macro.

The module metadata status names the reviewed source bank. It is not a byte
match claim. Exact claims live in `config/translation_units.json`.

## Current exact claims

The final grouped reconciliation has 20 registered exact owners. It promotes
`0053C1B0`, `0053C290`, and `0053C680` from the earlier migration results.

An earlier candidate full-TU check compiled all 27 owners. It found 17 `MATCH`
rows and 10 `MISMATCH` rows. Every row had a PDB-qualified owner symbol. Its
historical results were:

| VA | Bank | Historical result | Historical mismatch |
| --- | --- | --- | --- |
| `0053C1B0` | matching | MISMATCH | 2 bytes; merged-context register order |
| `0053C290` | matching | MISMATCH | 171 bytes; 296 rebuilt bytes, one boundary escape |
| `0053C5D0` | accepted_drift | MISMATCH | 89 bytes; 149 rebuilt bytes, inner-loop lowering |
| `0053C680` | accepted_drift | MISMATCH | 26 bytes; one extra SIB displacement and branch shifts |
| `0053C6F0` | scratch | MISMATCH | 555 bytes; 571 rebuilt bytes, broad codegen drift |
| `0053C920` | scratch | MISMATCH | 385 bytes; 376 rebuilt bytes, broad frame and loop drift |
| `0053CAC0` | scratch | MISMATCH | 554 bytes; 582 rebuilt bytes, broad codegen drift |
| `0053CCF0` | scratch | MISMATCH | 361 bytes; 356 rebuilt bytes, broad frame and loop drift |
| `0053D0D0` | accepted_drift | MISMATCH | 1 register-order byte |
| `0053D200` | accepted_drift | MISMATCH | 11 bytes in one final epilogue span |

The full-TU result is a migration check. It does not promote or demote a
source bank by itself. It records the exactness regressions caused by the
natural module context.

## Accepted drift review

`0053C5D0` keeps the original action log, row and column bounds, explored count,
visible-map writes, explored-mask writes, tile-list call, and collapse flag.
The remaining difference is inner-loop address and register scheduling. The
source uses the reviewed row-pointer form. It is not an exact claim.

`0053D0D0` keeps the same row and column loops and checksum result. One memory
operand uses the opposite SIB register order. The address and read are equal.

`0053D200` keeps the same file path, action text, log fields, loop bounds,
wraparound, and close call. The final 11-byte mismatch is one epilogue span.
The jump-table and data references have the same relocated targets.

These three owners remain accepted drift. The notes do not call them `MATCH`.
Their status is narrow, behavior-equivalent drift. New evidence must reopen the
status if it shows a changed call, bound, write, return, error, or fault order.

## Scratch review

`0053C6F0` explores a clipped LOS radius. It updates the explored count, tile
lists, tile flags, visible bytes, and unified explored and visible masks. Its
current merged-TU build is 571 bytes against the 546-byte original. The main
unresolved differences are the suppression branch, checksum home, and late
loop schedule. No changed call target or field ownership is known.

`0053C920` reverses visibility for a clipped LOS radius. It updates tile flags
and clears the player visible mask when the byte reaches zero. Its current
merged-TU build is 376 bytes against the 401-byte original. The unresolved
points are the original local frame, saved `this`, and parameter-home reuse.

`0053CAC0` explores a clipped rectangle. It updates the explored count, tile
lists, tile flags, visible bytes, and unified masks. Its current merged-TU build
is 582 bytes against the 550-byte original. The unresolved points are local-slot
and hash scheduling, bounds-return layout, and the late tile tail.

`0053CCF0` reverses visibility for a clipped rectangle. It updates tile flags
and clears the player visible mask when the byte reaches zero. Its current
merged-TU build is 356 bytes against the 381-byte original. The unresolved
points are the original local frame, saved `this`, and parameter-home layout.

These four owners stay scratch. Their source is behavior-focused and typed. No
exact or accepted-drift claim exists for them.

## Final matching reconciliation

`0053C1B0`, `0053C290`, and `0053C680` retain fresh `MATCH` results in the
final grouped context. Each has exact registration and valid ownership.

## Header cleanup candidate

The grouped candidate maps both overloaded `save` symbols explicitly:

- `0053C400`: `?save@RGE_Visible_Map@@QAEXH@Z`
- `0053CFF0`: `?save@RGE_Unified_Visible_Map@@QAEXH@Z`

The second grouped run compiled the cleaned source and compared all 14
registered owners. All 14 owners returned `MATCH`, with zero relocation target
mismatches and zero boundary escapes.

The earlier observed rows remain useful migration evidence. The final grouped
audit supersedes those results for `0053C1B0`, `0053C290`, and `0053C680`.
`0053C5D0`, `0053D0D0`, and `0053D200` retain their reviewed drift.
`0053CCF0` differs by 361 bytes. The overloaded
scratch rows `0053C6F0`, `0053C920`, and `0053CAC0` have comparison errors
because the candidate proposal has no unique symbol mapping for those methods.
They are not treated as matches.

Validation report: `build/candidate_tus/visible_header_cleanup/run02/report.txt`.
Report SHA-256: `21ab51c8bfb35720de12d693ce96104fc9a92360f5ebd525bb4043bc2ed9cce1`.

## Wave20 full-audit reconciliation

The fresh full audit reports 171 differing bytes and one boundary escape for
`0053C290 RGE_Visible_Map`. That constructor is scratch and is no longer
registered as exact.
