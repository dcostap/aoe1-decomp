# Recovery journal: 004EA280 `setVictoryCondition`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `matching` in `config/source_modules/taistrmd.json`.
- Living source: `src/taistrmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taistrmd.cpp`.
- Module note: `recovery_notes/taistrmd_module.md`.

## Current mismatch

The current tracked `include/utmarray.h` has a temporary inline `resize` body.
The current-header check rebuilt 1036 bytes against 1231 original bytes and
reported `MISMATCH`, diff 1167. It emitted 0 of the target's 13 direct
`resize` calls. This mismatch is a temporary header-provider effect.

## Attempt

The update idle-rule append at `src/taistrmd.cpp:1092` now calls
`idleRules->add(worstRuleResult)` once. It has no following manual
`numberValue` increment. The public `add` operation publishes the value and
increments the count.

The ignored protected-header candidate compiles 33 of 33 module functions.
It keeps 30 of 31 registered owners exact. Its generated methods and public
call, fault-order, and relocation topology checks pass. See
`build/audits/integration/resize-protected-taistrmd/candidate_validation.txt`.

The final current-header grouped audit reports 30 registered-owner matches,
one temporary regression at 004EA280, and the existing update boundary issue.
See `build/audits/workers/wave21-resize-taistrmd-correct/taistrmd-final/report.txt`.

## Next useful approach

Pause until the protected out-of-line `ManagedArray::resize` provider lands.
Then rerun the focused target check and the grouped `taistrmd` audit.
