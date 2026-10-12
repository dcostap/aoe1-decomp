# `aimdmod.cpp` cleanup report

## Scope and commits

- Module: `src/aimdmod.cpp`.
- PDB source: `C:\\msdev\\work\\age1_x1\\aimdmod.cpp`.
- Header owner: `include/aimdmod.h`. This worker did not edit it.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Source head commit: `305a85c363894606688f421eee0c9ebf810f4b20`.
- Final report commit: the child commit that adds this report is returned with delivery.
- Changed files: `src/aimdmod.cpp` and this report.
- Module flags remain `config/flags/gx.rsp` (`/nologo /c /O2 /Oy /GX`).

The source commit restores procedure-scoped PDB names. It also applies 1TBS
function brace placement. It does not change source order, types, calls,
casts, literals, or declaration scope.

## Evidence

- Original PDB: `orig/age1_x1.pdb`, SHA256
  `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
- Scoped PDB index: `inventory/pdb/scoped_symbols.json`, SHA256
  `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
- Original executable reference:
  `orig/empiresx.exe`,
  SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- PDB packets: `inventory/functions/0040/0040CDF0_MainDecisionAIModule.txt`
  through `0040DC30_mostDamaged.txt`.
- Existing module evidence: `workflow/decomp_notes/aimdmod.md`.

The scoped PDB records put every procedure in `.\\Release\\aimdmod.obj`.
Each record has an `ecx` register symbol named `this`. No function-static
records exist for these procedures.

## PDB coverage and name evidence

The table lists every normal function in PDB source order. Stack names include
parameters and locals. A repeated stack offset is a reused storage slot.

| VA | PDB lines | PDB stack names | PDB registers |
| --- | --- | --- | --- |
| `0040CDF0` | 34-35 | `pW`, `playerID`, `plyr` | `ecx:this` |
| `0040CE90` | 43-52 | `playerID`, `plyr`, `infile`; `i`; `numberUnits`; `tempInt` | `ecx:this` |
| `0040D020` | 57-58 | none | `ecx:this` |
| `0040D090` | 63 | `v` | `ecx:this` |
| `0040D0A0` | 69-77 | `outfile`, `tempInt` | `ecx:this` |
| `0040D180` | 82-87 | `obj` | `ecx:this` |
| `0040D250` | 92-94 | `id` | `ecx:this` |
| `0040D2C0` | 99-101 | none | `ecx:this` |
| `0040D2D0` | 106-116 | `aid`, `count` | `ecx:this` |
| `0040D3B0` | 121-131 | `gid`, `count` | `ecx:this` |
| `0040D480` | 137-148 | `action`, `target`, `count` | `ecx:this` |
| `0040D580` | 153-163 | `tt`, `count` | `ecx:this` |
| `0040D660` | 169-180 | `action`, `tt`, `count` | `ecx:this` |
| `0040D760` | 185-187 | `id` | `ecx:this` |
| `0040D780` | 194-213 | `gameID`, `typeID`, `groupID`, `currentAction`, `canPerformActionID`, `targetID`, `targetType`, `secondaryTargetType`, `objectState`, `maxAttributeAmount`; `i` | `ecx:this` |
| `0040D9D0` | 219-235 | `gameID`, `typeID`, `groupID`, `action1`, `action2`, `objectState` | `ecx:this` |
| `0040DB20` | 240-243 | `a` | `ecx:this` |
| `0040DB40` | 248-250 | `id`, `t` | `ecx:this` |
| `0040DB50` | 255-265 | `count` | `ecx:this` |
| `0040DC30` | 270-295 | `oGroup`, `oType`, `damagePercentage`, `mDB` | `ecx:this` |

The source changes map the records as follows:

- `0040CDF0`: `owner` to `pW`, `player_number` to `playerID`, and
  `player_value` to `plyr`.
- `0040CE90`: `player_number` to `playerID`, `player_value` to `plyr`,
  `file` to `infile`, `count` to `numberUnits`, and `object_id` to
  `tempInt`. The loop local keeps `i`.
- `0040D090`: the unnamed parameter is now `v`.
- `0040D0A0`: `file` to `outfile`; both existing temporary declarations now
  use the PDB spelling `tempInt`.
- `0040D180`: `object` to `obj`.
- `0040D250`: `object_id` to `id`.
- `0040D2D0`: `action` to `aid`.
- `0040D3B0`: `group_id` to `gid`.
- `0040D580`: `target_type` to `tt`.
- `0040D660`: `target_type` to `tt`.
- `0040D760`: `object_id` to `id`.
- `0040D780`: parameters now use the recovered spellings `gameID`, `typeID`,
  `groupID`, `currentAction`, `canPerformActionID`, `targetID`, `targetType`,
  `secondaryTargetType`, `objectState`, and `maxAttributeAmount`.
- `0040D9D0`: parameters `p1` through `p6` now use `gameID`, `typeID`,
  `groupID`, `action1`, `action2`, and `objectState`.
- `0040DB20`: `action` to `a`.
- `0040DB40`: the unnamed parameters are now `id` and `t`.
- `0040DC30`: `class_id` to `oGroup`, `type_id` to `oType`,
  `result` to `mDB`, and `damage_percentage` to `damagePercentage`.

All changed names are recovered original spellings from the scoped PDB.
This patch adds no invented names. Existing names without a scoped PDB record
remain descriptive and are not claimed as original names. These include loop
indices `i` in the query methods, local `object`, `unit_ai`, `ai`, `maxhp`,
`hp`, and `damage`.

## Unresolved mappings and risks

- In `0040CE90`, PDB storage reuses `+0x8` for parameter `plyr` and local
  `i`. It also reuses `+0xC` for parameter `infile` and local `tempInt`.
  The source keeps separate declarations and scopes.
- In `0040D0A0`, the PDB emits one `tempInt` stack record while the source
  keeps the two existing scoped declarations. The source does not merge them.
- In `0040DC30`, the generated Ghidra listing labels one return slot
  `local_8`, while the scoped PDB names the corresponding storage `mDB`.
  The source follows the scoped PDB name and keeps the existing declarations.
- The PDB does not record several optimized register locals. Their names were
  not changed without evidence.
- Parameter names in `include/aimdmod.h` remain unchanged because that header
  belongs to the owner of the module group.

No type, layout, ABI signature, call target, control-flow condition, literal,
cast, evaluation order, or resource lookup changed. Brace placement can change
debug line records. Name changes can change debug symbol records. No compiler
comparison was made in this phase.

## Constants, resources, comments, and shared requests

- No constant or enum was added or replaced.
- No resource ID or lookup occurs in this module. No resource extraction or
  resource request is needed.
- No source comment was added. Existing behavior stays visible in the source.
- No shared declaration or header change is requested.

## Validation

I reviewed the complete source diff. `git diff --check` passed before the
source commit. Compilation, matching, audits, and tests were not run.
