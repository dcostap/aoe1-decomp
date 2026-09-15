# Owner 14 cleanup ledger

## Scope

Owner 14 covers Tribe AI and game information.

The reviewed source modules are:

- `src/taiinfmd.cpp`
- `src/taimdmd.cpp`
- `src/tairesmd.cpp`
- `src/taistrmd.cpp`
- `src/taitacmd.cpp`
- `src/taiuaimd.cpp`
- `src/taunt.cpp`
- `src/gameinfo.cpp`

The owner updated only the eight assigned headers. Root-owned headers stayed unchanged.

The common base is `76037279ee11dde077bb7d55aeb46b518b2bb27c`.

## Worker deliveries

| Module | Reviewed worker head | Result |
| --- | --- | --- |
| `taiinfmd` | `421668fb67ef8abd3c52dde0d63db944d80d15e0` | Approved after declaration, binding, and matching repairs. |
| `taimdmd` | `3c2d4a7914ba1a6c24d7424442a63cdaca5f3bb0` | Approved after storage and VC5 scope repairs. |
| `tairesmd` | `f9a3b91cd91120610cb363989a00c7502ee86967` | Approved. |
| `taistrmd` | `afe72c51515b825f5f2508f76d8f433285619e2d` | Approved after formatting correction. |
| `taitacmd` | `0210fcdf9217069b4585f52599ff1f5578d84baa` | Approved after report, formatting, and PDB-name corrections. |
| `taiuaimd` | `1afecc2a951296a7948d68298026db70c4d03dde` | Approved after alias correction. |
| `taunt` | `5f30c8f67c43fd8e004020e59799d55e7993bc04` | Approved. |
| `gameinfo` | `95e763c54fc9b18dbe4407c8db9077e8a746d762` | Approved. |

The module reports give the source commit identities from each worker branch.
Cherry-pick commit identities differ on this integration branch.

## Review and correction history

The owner reviewed each complete worker diff and report against the common base.

- `taiinfmd`: The first delivery changed declaration shape and reused storage.
  The first correction restored several aliases, declarations, and initialization points.
  A full-source review then found a real `setupWalls` logic regression.
  Renamed center parameters had replaced loop locals, so loops changed later center values.
  The second correction restored `centerX`, `centerY`, and separate `x` and `y` locals.
  The PDB parameter names `x` and `y` conflict with those required loop locals.
  It also restored the baseline storage forms in `save`, the destructor, `update`,
  `unexploredPlayerLocation`, and `dropsitesWithinRequiredDistance`.
  `requiredZone` is an unsafe reused-home record, not a source declaration.
  The final source correction restored the baseline local declaration order in
  `dropsitesWithinRequiredDistance`.
  A later object review found that an added `numMemoriesToLoad` local changed
  the `loadLearnInfo` frame from `0x34` to `0x38` bytes.
  The repair restores baseline `numToLoad` storage reuse.
  `numMemoriesToLoad` is a reused-home PDB record, not a distinct declaration.
  Report corrections now state these limits and rejected forms accurately.
  The retained formatting uses 1TBS and four-space indentation.
- `taimdmd`: The correction restored the separate `diplomacy_start_time` local.
- `tairesmd`: The source preserved all declarations and required no correction.
- `taistrmd`: The correction moved function opening braces to 1TBS positions.
- `taitacmd`: The first report lacked required coverage. Later corrections expanded
  the report, applied 1TBS, and recovered omitted direct PDB parameter names.
- `taiuaimd`: The correction restored `NotifyEvent* event = nEvent;` and its uses.
- `taunt`: The source preserved behavior and required no correction.
- `gameinfo`: The source preserved behavior and required no correction.

A root fresh-main compilation later found two incorrect cleanup bindings.

- `taiinfmd`: `lookupZone` used the removed `gatherer` name. The repair binds
  the call to the existing `gathererObj` declaration.
- `taimdmd`: A final `i` loop declaration collided with an earlier initializer
  under VC5 scope rules. The repair restores `neutralPlayer` and `target`.

The external report is
`C:/Projects/my_decomps/aoe1_attempt3/build/executable/user/20260915T215425319815Z/20260915T215425568371Z/report.json`.

The later functions-r2 report compiled all 225 selected functions. It found a
matching regression in `loadLearnInfo` at `004E1260`. The row is in
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/final-validation/functions-r2/report.csv`.
Preserved baseline and fresh objects proved that the extra local caused the drift.

No prohibited compiler, build, matching, audit, test, or game command occurred.

## Evidence

The review used the following main-root evidence:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/`
- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/`
- `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/`

Each module report lists its procedure packets and module-specific evidence.
The original executable remains the behavior oracle.

## Findings

All eight modules now use direct procedure-scoped PDB names where the mapping is reliable.
Descriptive substitute names use snake_case when no original name is proved.
The cleanup preserves declarations, types, scopes, storage, calls, casts, literals,
statement order, explicit `this->` use, and known original bugs.

The owner updated these assigned declarations with proved parameter names:

- `include/taiinfmd.h`
- `include/taimdmd.h`
- `include/tairesmd.h`
- `include/taistrmd.h`
- `include/taitacmd.h`
- `include/taiuaimd.h`
- `include/taunt.h`
- `include/gameinfo.h`

The header edits change parameter names only. They do not change types, order, ABI,
class layout, virtual slots, or function ownership.

`taimdmd` keeps numeric values that collide with unrelated DirectDraw error constants.
The available evidence does not prove a shared resource or SDK mapping.

Some PDB records reuse registers or stack slots. The source keeps separate existing
variables when one recovered name cannot map to each lifetime safely.

## Shared requests

There are no shared-header, resource-ID, or global-declaration requests.
No change is requested for `include/resource_ids.h` or `include/game_globals.h`.

## Validation status

The owner and workers performed evidence extraction and Git diff review only.
Root ran the fresh-main compilation that found the two errors recorded above.
Root also ran functions-r2, which found the `loadLearnInfo` matching regression.
The workers did not run compilation, matching, audits, tests, or game execution.

The later repairs have not received another validation run.
Generated-code equality remains unknown.
