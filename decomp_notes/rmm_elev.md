# Natural `rmm_elev.cpp` module

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
| `004847C0` | MISMATCH | 224 | 224 | 147 | 0 | scratch |
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

Seven non-exact rows remain scratch. `00484B90` is accepted drift because the
landed semantic review and this direct grouped build support that status. The
semantic review commit `15b53a5f9` was read as evidence only. No wrapper or
standalone status was transferred. `count_map_tiles` has five boundary escapes.
`base_elevation_generate` has one boundary escape and a large local frame
mismatch. These rows stay out of exact registration.
