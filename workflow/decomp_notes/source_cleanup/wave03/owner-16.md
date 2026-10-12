# Owner 16 maps and visibility cleanup ledger

## Scope

- Group branch: `cleanup/staging-20260915-136`
- Shared base: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Reviewed code and header head: `ad18e3fc4b5bb3d89465c018d4229b0425ba5e40`
- Final map report correction commit: `65082007ade49949c7d26cfb94cec046540ecfd6`
- Modules: `map`, `tmap`, `infmap`, `visible`, `vis_unit`, `zone_map`, `fractal`, and `rmm_dbct`
- Owned headers: the eight matching headers under `include/`

All integrated work is reviewed but unvalidated.

Compilation, builds, matching checks, audits, tests, and games did not run.

## Worker deliveries

Each worker started from `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
I read each complete base-to-head diff and each module report.

| Module | Worker | Worker head | Review result |
| --- | --- | --- | --- |
| `src/map.cpp` | `sa-959dcdc9` | `1aade9e2fb858e2db94a5e6952a28f811bf21a04` | Approved after owner and independent reviewer corrections. |
| `src/tmap.cpp` | `sa-029166df` | `e6d057666df925b3bf6111c6c428139e52247abf` | Approved after one correction round. |
| `src/infmap.cpp` | `sa-6888a065` | `7e825092e5af5da525e1c1a1bef4c0b64babf81a` | Approved after one report correction. |
| `src/visible.cpp` | `sa-f17ac0bc` | `38d82bb82af1198139607c4c68bc89cbcaf080a1` | Approved without correction. |
| `src/vis_unit.cpp` | `sa-40984409` | `b2477491d4b94920f72bf33292d74f5276b75735` | Approved without correction. |
| `src/zone_map.cpp` | `sa-82b7c3b8` | `d65f16a573656c683c7b96bfe5660aa79f4b6eb3` | Approved after one correction round. |
| `src/fractal.cpp` | `sa-03d32bb3` | `7fb36ddd012f24adef49924c3a2ddbdc9944d0cc` | Approved after one report correction. |
| `src/rmm_dbct.cpp` | `sa-51438837` | `1ca7a0f99b66483b8af95403e9fc40492c1ed858` | Approved without correction. |

## Review findings

Each report covers every registry-selected normal function.
The reports also identify compiler-generated entries without source bodies.

Workers inspected procedure-scoped PDB parameters, locals, and register records.
They preserved original mixed spelling and terse names.

Uncertain reused stack slots remain unresolved.
No worker changed types to match conflicting PDB slot types.

The source edits preserve casts, scopes, storage, calls, literals, and statement order.
No worker added a helper, wrapper, layout, assembly block, or behavior repair.

No assigned module uses a resource lookup.
No resource extraction or shared resource-ID request was needed.

### Correction history

The first `map` result did not apply 1TBS.
It also used abbreviated hashes and gave an optional header note.

The same worker applied 1TBS and supplied full hashes and declarations.
A later round restored repository pointer style and readable wrapping.
The final round joined one short terrain call.

Independent review then found five map blockers.
The same worker restored the `scenario_load` alias and the omitted border local.
It also restored one format-string token and two PDB-backed names.
The corrected report withdraws its earlier inaccurate completeness claims.
Final review found one stale `place_terrain_object` name in the header request.
The same worker changed that report-only name to `obj_owner`.

The `map` reminder-only run made no project change.
It restated the cleanup command restrictions.

The first `zone_map` result retained next-line function braces.
The same worker applied 1TBS and joined readable signatures and calls.

The first `tmap` report incorrectly said no header request existed.
The correction added the complete request and improved call wrapping.

The first `infmap` report also said no header request existed.
The correction added the complete declaration-only request.

The first `fractal` report cited a duplicate executable path.
The correction cites the required repo-local original executable.

The owner also aligned `Get_Closest_Resource` header names.
The source names already matched the PDB, but the worker request omitted this declaration.

## Integrated commits

### `map`

- `cf9daa12cf1780246a011c8386a53a32671e62b3`
- `13edd334454db8f06e335b48234f4ae15f9d3344`
- `aa83fa156b34a7cf0f92d7b1f117c3a6a2e80db4`
- `7ee3cac1bc9f5fd416d1cc7a9c4ad72c42cfda4f`
- `da18280cdec50ceb768debafddd8f3ac08fe4c30`
- `a24b098f7ef060d570f4df5a5c157404c7ed8e18`
- `ff2f1ae05fe99af9ba36cfa17620db1351fd65af`
- `bbd77d048094b622ed2d72d34c8712bb28c82ceb`
- `2285e72eedc825142232bdaaacf3cd4343275975`
- `4e85a504daa058adc3f3115b8d76fbf67701e1f9`
- `60e86cdce663bb06acde10004d870dc9d570ead1`
- `158092d9ddd691a9c4395fdc888d40bce463ee48`
- `65082007ade49949c7d26cfb94cec046540ecfd6`

### `tmap`

- `bcf43dd477a75cec351650ad6af8a166de515a6c`
- `b9bf82c159a730be9bbd9fe7c827d5df7a2b2d5a`
- `29a8348f1d1973bfedcdfcf1d8d45335e470f085`
- `9b4288be4dcb8a90d74a1f5fef206efb198cdee3`
- `184d40f45ac905ebd118183ab6f7fd88a92a08ec`
- `99ae760f510e6e3e8f1b9d4359ef2d66fc5fad59`

### `infmap`

- `40661ea60bf3d8f169b8754ce979259933fe39d2`
- `c350d448d2aa399bf0e5e768145c7ea940973fc5`
- `105a0127a1a64614386e5606d8bd074c7fdec5a5`

### `visible`

- `1b044a9a1ae3d42aa818ec15866ee555132e6670`
- `8dfcc11743e05e7bb377aa4976cdc0a80f462cb0`

### `vis_unit`

- `c314234309ef11d9d7facbea3915da0e8817dbf9`
- `bc25b8c42651a48ba0c018186c9b6e2a9d8fc6e6`

### `zone_map`

- `6882a4619813486a9b05b26f5b57c7ee17d0be10`
- `db8d0bd5c198d36961115132e49b5f95cfb83b54`
- `df6cf46ebc306a9a0be3294f6f277a8b04f3c826`
- `7ed1c0b09bf07039037ace5285f483c9b1b69e99`
- `baeee67a0eaf7661478fbb9dc9674d036a1e1d6c`

### `fractal`

- `8d1bb4ac3230702c7960e527e562e30329a8f8ed`
- `bb4f7afaed5a54c30247bb0c931fe310743ea023`
- `3f3a7e566690894bc3f465a3a77d281357dc0e83`

### `rmm_dbct`

- `25e2d00e653c82470e3b6e6d38d34b6a6509666d`
- `9758d333b2ef135532e83dfa203fd74c1b16961a`

## Owner header commit

Commit `21f342d1d8be6bc22153f8a515c010c47d7ce9b4` updates:

- `include/map.h`
- `include/tmap.h`
- `include/infmap.h`
- `include/visible.h`
- `include/vis_unit.h`
- `include/zone_map.h`
- `include/fractal.h`
- `include/rmm_dbct.h`

The commit adds recovered parameter names and adjusts declaration wrapping.
It changes no type, order, overload, virtual slot, layout, or ABI symbol.

Commit `ad18e3fc4b5bb3d89465c018d4229b0425ba5e40` changes the
`place_terrain_object` parameter from `player` to PDB name `obj_owner`.
This declaration-only correction changes no type, order, or ABI symbol.

## Shared requests and open items

No request targets `include/resource_ids.h`, `include/game_globals.h`, or another root-owned header.
No cross-group request remains.

The module reports record unresolved optimized local mappings.
These items do not block this reviewed cleanup.

## Validation status

Only evidence inspection, Git status checks, and complete diff review ran.

Compilation, matching checks, audits, tests, builds, and games did not run.
Generated code, program data, relocations, and call targets remain unvalidated.
Final comparison remains deferred to the root stage.
