# Natural `rmm_elev.cpp` module

## Current hackathon result: 2026-10-03

`004847C0` uses read-only pointer types. Commit: `075423602`. Output remains 224 bytes with 147 differences.
It remains scratch; no status improvement is claimed. The fresh ten-owner audit proves all five matching claims.
Two owners have new verified logic; three remain scratch. The target note records rejected probes and fault-order limits.
Older accepted-drift claims below do not describe the current registry.

## Ownership

The PDB assigns ten normal functions to
`C:\\msdev\\work\\age1_x1\\rmm_elev.cpp`. The source order is:

`004846C0`, `00484700`, `004847C0`, `004848A0`, `00484A40`, `00484B30`,
`00484B50`, `00484B90`, `00484C80`, and `00484D00`.

The integrated source is `src/rmm_elev.cpp`. It uses `include/rmm_elev.h` and
`include/map.h`. Map rows use `RGE_Tile*` and the packed `RGE_Tile::height`
field. Stack traversal uses typed `Map_Stack*` nodes and the canonical random-
map helper ABI. The source has no raw tile cursor, fake volatility, local
carrier, or context header.

## Direct natural-module validation

The candidate uses `config/flags/default.rsp`. The checked source module
contains all ten PDB owners in source order. The owning symbols match. No
relocation target mismatch occurred.

| VA | Result | Original | Rebuilt | Diff | Boundary | Classification |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| `004846C0` | MATCH | 59 | 59 | 0 | 0 | matching |
| `00484700` | MISMATCH | 191 | 187 | 158 | 0 | scratch |
| `004847C0` | MISMATCH | 224 | 224 | 147 | 0 | accepted drift |
| `004848A0` | MISMATCH | 408 | 401 | 340 | 0 | scratch |
| `00484A40` | MISMATCH | 240 | 240 | 7 | 0 | scratch |
| `00484B30` | MATCH | 28 | 28 | 0 | 0 | matching |
| `00484B50` | MISMATCH | 54 | 93 | 93 | 5 | scratch |
| `00484B90` | MISMATCH | 234 | 234 | 2 | 0 | accepted drift |
| `00484C80` | MISMATCH | 128 | 122 | 73 | 0 | scratch |
| `00484D00` | MISMATCH | 1273 | 1276 | 1223 | 1 | scratch |

The migration check found two exact functions and seven nonexact functions.
There are no generated entries.

Validation command:

```text
python tools/validate_candidate_tu.py --proposal build/rmm_elev_natural_candidate.json --output-dir build/candidate_tus/rmm_elev_natural_dc7820b95_policy
```

The result is two exact rows, eight non-exact rows, zero comparison errors,
zero relocation target mismatches, and `full_module_exact: false`. The command
returns failure because the observed rows are not exact. This is the expected
result for the partial natural candidate.

## Remaining blockers

Six non-exact rows remain scratch. `004847C0` and `00484B90` are accepted
drift. Their semantic reviews and direct grouped builds support that status.
The semantic review commit `15b53a5f9` was read as evidence only. No wrapper
or standalone status was transferred. `count_map_tiles` has five boundary escapes.
`base_elevation_generate` has one boundary escape and a large local frame
mismatch. These rows stay out of exact registration.

## Worker update: corpus-21-rmm-elev

The historical table above is not the current scratch baseline. The final
canonical checks for this work period report:

| VA | Result | Original | Rebuilt | Diff | Boundary | Calls |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| `00484700` | MISMATCH | 191 | 190 | 139 | 0 | 4/4 aligned |
| `00484D00` | MISMATCH | 1273 | 1270 | 790 | 0 | 23/23 aligned |

`00484D00` keeps frame `0x988` and 93.14% shape. Its `done` local now uses
the PDB-proven `uchar`; the emitted bytes are unchanged. The reviewed typed
`RGE_Tile::height` owner remains in both functions. No exact or accepted-drift
proposal is made.

The final translation-unit audit at
`build/agents/corpus-21-rmm-elev/audit-final/report.txt` keeps five exact
neighbors and three accepted-drift rows unchanged. It reports no relocation
or boundary regressions.

## Latest worker validation: corpus-73-rmm-elev-base

The final `rmm_elev` audit is `build/corpus73-rmm-elev-final/report.txt`.
It compiled all ten owners with `--jobs 1`. Five rows are exact, three rows
remain existing accepted drift, and two rows remain scratch. The target
`00484D00` is `MISMATCH`: 1273 original bytes, 1270 rebuilt bytes, 790
differences, matching `0x988` frame, and zero boundary or relocation-target
errors. All 23 direct calls align in order.

The target source keeps the canonical typed map and stack owners. It applies
the PDB-supported unsigned-char `done` local, the named float `in_zone` cost
home, and a scoped full-width base-elevation local. These source forms emit
the same natural 790-byte basin. No registry status change is proposed.

## Reopened drift review: drift-026-rmm_elev

The accepted-drift approvals for `004847C0`, `004848A0`, and `00484B90` were
reopened. This worker did not reaffirm them or change registry status.

Three final baseline closures used `--jobs 1`. Each compiled all ten module
functions, checked five exact targets, and found no exact regressions.

| VA | State | Event | Check report | Closure report |
| --- | --- | --- | --- | --- |
| `004847C0` | `9086bb74573f4eedaf1bc4f00a9c532ac98c449613b166d8cc9345a146fe3d70` | `14689942f3a9f1ddefbc1d2245d3d8d14c4d1d5792a44c8b94d70c3f9f1c7e14` | `build/experiment_runs/21d500a5597d4cb7b155a9dbc0a6d02b/check.txt` | `build/experiment_runs/21d500a5597d4cb7b155a9dbc0a6d02b/closure/report.txt` |
| `004848A0` | `a5c5b89370d717a8fc0422249eba3082f1d25e4b02a81f0cadc665c06831fc18` | `c836ba29561aad6361d99ce683416289923ec8df8f920edf1990d49af7120516` | `build/experiment_runs/11611f4beeaf4b3995bfceda82b94402/check.txt` | `build/experiment_runs/11611f4beeaf4b3995bfceda82b94402/closure/report.json` |
| `00484B90` | `dc62ee26627db9720d557a50d8d37cac7f0bf300dba02ea6f17b6ae47873e638` | `2ef9aaf5920b5c27cc3ff176f0307f64850daec97e29c553d95d2f10bfadf48f` | `build/experiment_runs/a6fb66c07cfa420890e8bb90a47d63e6/check.txt` | `build/experiment_runs/a6fb66c07cfa420890e8bb90a47d63e6/closure/report.json` |

The `004847C0` dead-parameter counter probe reduced its target diff by one
byte. Its closure made exact neighbor `00484B50` differ by two bytes. Moving
the assignment later did not remove that regression. An explicit area local
in `count_map_tiles` also did not restore those bytes. All probes were rolled
back. The final source matches the baseline source hash.

The per-function notes record original instruction evidence, source ownership,
byte results, and unknowns. No runtime tests or linked-image storage audit ran.
Nothing was staged, committed, or integrated.
