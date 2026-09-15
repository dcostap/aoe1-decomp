# Source cleanup report: `act_misl.cpp`

## Delivery

- Module: `src/act_misl.cpp`
- Base commit from `git rev-parse`: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Final source commit from `git rev-parse`: `e535b4922722406b64cf3c162db65c97c27971e9`
- Changed files: `src/act_misl.cpp`; this report.
- Header request only: `include/act_misl.h` remains unchanged.
- Registry: `config/functions/src/act_misl.cpp.json`, build flags `gx`.
- Branch: `cleanup/staging-20260915-10`
- Source SHA-256 after cleanup: `0fd7108ba40028312d4e1484451fd0ad850e5b0ad5ade4b0457fece261613219`.

The source commit contains the code cleanup.
The report commit follows the source commit.
The report covers all seven assigned registry functions.

## Evidence

The name recovery uses `inventory/pdb/scoped_symbols.json`.
The PDB source is `C:\msdev\work\age1_x1\ACT_misl.cpp`.
The records include stack and register symbols for every assigned function.
Each assigned function has a `this` register record in `ecx`.

I inspected the complete packets for these functions:

- `inventory/functions/0040/00404BB0_RGE_Action_Missile.txt`
- `inventory/functions/0040/00404C90_RGE_Action_Missile.txt`
- `inventory/functions/0040/00404D10_first_in_stack.txt`
- `inventory/functions/0040/00404D50_intercept.txt`
- `inventory/functions/0040/00404DB0_set_state.txt`
- `inventory/functions/0040/004050F0_update.txt`
- `inventory/functions/0040/004054B0_save.txt`

The packets confirm the source order and function boundaries.
The original PDB hash is `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
The original behavior oracle is
`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA-256 is `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

## Original-name recovery

The table lists every assigned source function.
All names marked recovered come from the PDB records.
The PDB records name `this` as `RGE_Action_Missile*` in `ecx` for every row.

| VA | Function | Recovered names and coverage |
| --- | --- | --- |
| `00404BB0` | file constructor | Parameters `infile`, `obj_in`. |
| `00404C90` | target constructor | Parameters `obj_in`, `launcher`, `target`, `x`, `y`, `z`. |
| `00404D10` | `first_in_stack` | Parameter `first_time`. |
| `00404D50` | `intercept` | Parameters `tx`, `ty`, `tz`. |
| `00404DB0` | `set_state` | Parameter `new_state`; locals `tx`, `ty`, `tz`, `dx`, `dy`, `dz`, `d`, `target_vx`, and `target_vy`. |
| `004050F0` | `update` | Locals `hit_ground`, `vz`, `vy`, `vx`, `bounds`, `t`, and `s`. |
| `004054B0` | `save` | Parameter `outfile`. |

The source changes restore these PDB spellings:

- `file` became `infile` in both the file read calls and the constructor.
- `object` became `obj_in` in the file constructor.
- The target constructor now uses `obj_in`, `launcher`, and `target`.
- `target2` was the baseline name for the PDB `target` parameter.
- `value` became `first_time` in `first_in_stack`.
- `x`, `y`, and `z` became the PDB output names `tx`, `ty`, and `tz` in `intercept`.
- The set-state parameter `value` became `new_state`.
- The set-state coordinate locals became `tx`, `ty`, and `tz`.
- The set-state distance magnitude became `d`.
- The target vector locals became `target_vx` and `target_vy`.
- The update locals `velocity_x`, `velocity_y`, and `velocity_z` became `vx`, `vy`, and `vz`.
- The update locals `time` and `distance` became `t` and `s`.
- `handle` became `outfile` in `save` and its write calls.

## Locals and unresolved mappings

The set-state PDB also lists `virtual_speed`, `apparant_target_speed`, `vy`, `vx`, and `speed`.
All five records use the same stack home at `-0x20`.
The current source has one `target_speed` declaration across those value lifetimes.
I did not split that declaration or force one PDB name across all uses.
The mapping remains unresolved because the PDB records show reused storage.

The set-state PDB has no records for `adjustment`, `time`, or `acceleration`.
The source keeps these concise descriptive names.
The update PDB has no records for `change`, `new_velocity`, `average_velocity`, `node`, or `source`.
The source keeps these names because the records do not prove another name.
These are descriptive names, not recovered original names.
No invented name was added.

The PDB has no named local for the `S_LDATA32` dispatch data near `004040D8`.
That data is not a source declaration.
The compiler-generated destructors at `00404C60` and `00404C80` have no source bodies here.
Their PDB records were inspected but they were not edited.

## Constants, resources, and comments

No numeric constant changed.
No new constant or enum was added.
The state values, missile types, object IDs, sentinels, and existing `DAT_0056e380` through `DAT_0056e394` references remain unchanged.

This module has no resource lookup.
No resource ID mapping or resource header request is needed.

No source comment was added.
The existing code and this report provide the needed evidence.

## Code generation, type, layout, and symbol review

The source edits rename identifiers and move function opening braces to 1TBS form.
They do not change types, storage, declaration scope, member order, evaluation order, control flow, calls, relocations, boundaries, or ABI symbols.
The overlapping PDB stack records remain documented above.
No inline assembly, wrapper, alias, or layout change was added.

The five earlier matching owners remain source owners in this module.
The two reviewed logic owners remain unchanged in control flow and expression form.
No registry, status, flag, header, or generated file changed.

## Header request

The owner of `include/act_misl.h` may add these PDB-proven parameter names without changing types or signatures:

```cpp
RGE_Action_Missile(int infile, RGE_Action_Object* obj_in);
RGE_Action_Missile(RGE_Action_Object* obj_in, RGE_Static_Object* launcher,
                   RGE_Static_Object* target, float x, float y, float z);
virtual void first_in_stack(unsigned char first_time);
virtual unsigned char update();
virtual void save(int outfile);
virtual void set_state(unsigned char new_state);
void intercept(float& tx, float& ty, float& tz);
```

No root-owned header request exists.
No resource declaration request exists.

## Validation

Compilation, matching, audits, and tests were not run.
No build, compiler check, game, or runtime harness was run.
Only evidence inspection, Git review, and `git diff --check` were run.
