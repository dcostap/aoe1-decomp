# `tvictory.cpp` source-cleanup report

## Delivery

- Module: `src/tvictory.cpp`
- Branch: `cleanup/staging-20260915-243`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `f8d77b08c8d4e319be1cddc8bc5cc0d0cfc15610`.
- Report correction commit: follows this source commit.
- Changed files:
  - `src/tvictory.cpp`
  - `decomp_notes/source_cleanup/wave04/tvictory.md`
- Registry: `config/functions/src/tvictory.cpp.json`
- Registry flags: `default`
- Header read but not edited: `include/tvictory.h`

The source keeps all six normal procedures in PDB source and address order.
The cleanup restores procedure-scoped PDB parameter names. It does not change
types, casts, statements, calls, literals, storage, or control flow.

## Evidence

I read the assigned cleanup, comments, resource, owner, and testing guides.
I inspected the source, its owner header, current declarations, and relevant
callers.

The original PDB is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`

Its SHA256 is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
The PDB source path is `C:\msdev\work\age1_x1\tvictory.cpp`.
The module record is `\\Release\\tvictory.obj`, module index `000E`.
The procedure-scoped reference is:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

Its SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The source map and line-change references are:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
  SHA256 `aead4dde6d2839dbd667e0c2d1a2f266ca19c8e559ae23757c969c4c443de8b8`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_line_changes.csv`
  SHA256 `0e4dc5c668ae96db2505488432a4ceeeb9eb49b3f74dc41fee2ce3ca87377561`.

The original executable is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`

Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup object is:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/tvictory.obj`

Its SHA256 is
`3e8853516f8882b6ff2ebfb80e7f13bac412d901e5192078c86a3d94ae998bfd`.

The original Ghidra references are:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tvictory.cpp.asm`
  SHA256 `4a2afa630b28d803dc28c4efabfe14ef0ab2c359cbf35e07924fb8210d054b14`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tvictory.cpp.decomp`
  SHA256 `8d545c7fe8a3967e6b2bb30ccaddd6c10015fc46d7e6a679e10360df857c42f9`.

I also inspected the complete module dump from the original PDB under the
worker build evidence directory. It records every procedure's register and
stack symbols.

I inspected these complete function packets:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052C8F0_TRIBE_Victory_Conditions.txt`
  SHA256 `cc567afeb28db6d22ad374535f7ff1066e368ce3dd927ee4e1bfae8fea615d95`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052C920_TRIBE_Victory_Conditions.txt`
  SHA256 `62619e53bc315112ec9c168154d53c74c449b79b822018c11d213b04fca79015`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052C940_TRIBE_Victory_Conditions.txt`
  SHA256 `5120f5131dec399e31bdef5998822c077108e369cbae75eca8a10862d1e6986d`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052C950_handle_condition.txt`
  SHA256 `e7f76c68494cccfbf724945f4a103f2d3892cac6bf7a49003e34bcbee030f5f2`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052C970_handle_tech.txt`
  SHA256 `a8d91f0e69997ab7e67f6a996915cbd276a563ccdfd7949ca04e9fa8086f2fdc`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052C9B0_add_tech.txt`
  SHA256 `4ae6ac720e7d8b8b8b17f52146294791c4cfd60f954eed7cabc89856e3bd7613`.

The relevant current declarations and callers are:

- `include/tvictory.h` declares the same six functions and types.
- `include/victory.h` defines `RGE_Victory_Entry` and the base methods.
- `include/tplayer.h` defines `TRIBE_Player::tech_tree` at `+0x220`.
- `include/tech.h` declares `TRIBE_Player_Tech::get_tech_state(short)`.
- `src/tplayer.cpp:3268-3276` constructs both derived objects.
- `src/tscenaro.cpp:701` calls `TRIBE_Victory_Conditions::add_tech`.

The original call references identify these uses:

- `0052C8F0` is called by `load_victory` at `005194D5`.
- `0052C920` is called by `new_victory` at `00519536`.
- `0052C950` owns the direct call to `0052C970` at `0052C962` and has a
  virtual-table reference at `00577344`.
- `0052C9B0` is called by `Save_victory_conditions_into_players` at
  `0052BF88`.
- `0052C940` has no direct call reference in its packet; destruction uses the
  class destruction path.

## Original-name recovery coverage

Every assigned function has a PDB procedure record. Every procedure has a
`this` register record in `ecx`. The table lists every PDB stack symbol and
its type. The PDB has no function-local stack or register symbols beyond
these entries.

| VA | Procedure | Size | PDB parameters | PDB locals | Source result |
| --- | --- | ---: | --- | --- | --- |
| `0052C8F0` | `TRIBE_Victory_Conditions::TRIBE_Victory_Conditions` | 42 | `in_player` (`RGE_Player*`, `+0x4`); `infile` (`int`, `+0x8`); `player_id_hash` (`long*`, `+0xc`); `version_control` (`unsigned char`, `+0x10`) | none | Restored all four parameters. |
| `0052C920` | `TRIBE_Victory_Conditions::TRIBE_Victory_Conditions` | 25 | `in_Player` (`RGE_Player*`, `+0x4`) | none | Restored the parameter. |
| `0052C940` | `TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions` | 11 | none | none | No rename was needed. |
| `0052C950` | `TRIBE_Victory_Conditions::handle_condition` | 26 | `node` (`RGE_Victory_Entry*`, `+0x4`) | none | Restored the parameter. |
| `0052C970` | `TRIBE_Victory_Conditions::handle_tech` | 49 | `node` (`RGE_Victory_Entry*`, `+0x4`) | none | Restored the parameter. |
| `0052C9B0` | `TRIBE_Victory_Conditions::add_tech` | 36 | `v_group` (`unsigned char`, `+0x4`); `tech_id` (`long`, `+0x8`) | none | Restored both parameters. |

The source changes these non-header identifiers:

- `0052C8F0`: `player` became `in_player`; `value` became `infile`;
  `data` became `player_id_hash`; `flag` became `version_control`.
- `0052C920`: `player` became `in_Player`.
- `0052C950`: `entry` became `node`.
- `0052C970`: `entry` became `node`.
- `0052C9B0`: `id` became `v_group`; `count` became `tech_id`.

These names are recovered original spellings. No new cleanup name was added.
The mixed spelling `in_Player` remains unchanged from the PDB.

## Locals and unresolved mappings

The PDB records only `this` for `0052C940`.

The local `TRIBE_Player* player` in `0052C970` has no PDB record. I retained
its existing descriptive name. The local `RGE_Victory_Entry* entry` in
`0052C9B0` also has no PDB record. I retained its existing descriptive name.
I did not force either optimized register value into a PDB declaration.

The source definitions now use the PDB names. The owner header still uses
its existing parameter labels. Parameter labels do not change the ABI.

## Calls, constants, resources, and comments

The original assembly gives these boundaries and direct targets:

| VA | Boundary size | Direct target evidence |
| --- | ---: | --- |
| `0052C8F0` | 42 | Calls base constructor `00531750`. |
| `0052C920` | 25 | Calls base constructor `00531AF0`. |
| `0052C940` | 11 | Tail-jumps to base destructor `00531B20`. |
| `0052C950` | 26 | Calls base handler `00531F90` or derived `0052C970`. |
| `0052C970` | 49 | Calls `TRIBE_Player_Tech::get_tech_state` at `0050C58C`. |
| `0052C9B0` | 36 | Calls base `add` at `00532930`. |

No numeric constant, enum, macro, resource ID, or literal changed. The
existing command values `'d'` and `0x64`, state values, and tech-state value
remain unchanged.

This module has no resource lookup. No resource DLL was checked because this
source has no resource path, override, fallback, or resource ID use. No
resource mapping request exists.

I added no source comment. The comment guide does not support a new comment
for these direct parameter-name recoveries.

## Code-generation, type, layout, and symbol review

The edits rename parameters and update their uses. They do not change types,
casts, declaration points, scope, storage duration, evaluation order, control
flow, calls, literals, function boundaries, relocations, virtual slots, class
layout, or ABI symbols. No helper, wrapper, layout change, assembly, or bug
repair was added.

The source file hash changed from
`c04ec5fa21fda1715a5024eca43e617a2f1929d800a4a7c9bc66675b2c05a652` to
`4b50d9712cc7a07a929ec23aaeab2bd3621f515c566b9935b608a6908e757f88`.
The baseline object remains unmodified. Generated code, program data,
relocations, and call targets remain unvalidated.

## Header and shared-file requests

Owner 27 owns `include/tvictory.h`. Please consider changing only these
parameter labels. Keep access, types, order, virtual slots, layout, and
symbols unchanged:

```cpp
TRIBE_Victory_Conditions(RGE_Player* in_player, int infile,
                         long* player_id_hash, unsigned char version_control);
TRIBE_Victory_Conditions(RGE_Player* in_Player);
```

The exact evidence is the `S_BPREL32` records for `0052C8F0` and `0052C920`
in `inventory/pdb/scoped_symbols.json`, with the types and stack offsets
listed in the coverage table above. No root-owned shared declaration or
resource mapping request exists.

## Validation status

I reviewed the complete source diff and ran `git diff --check`.
I ran the evidence-tool help command before PDB inspection.

Compilation, matching, audits, and tests were not run. No build, compiler,
game, runtime harness, or audit command was run.

**Compilation, matching, audits, and tests were not run.**
