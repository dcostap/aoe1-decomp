# `tact_rep.cpp` cleanup report

## Module and commits

- Module: `src/tact_rep.cpp`
- Registry: `config/functions/src/tact_rep.cpp.json`
- PDB source: `C:\\msdev\\work\\age1_x1\\tact_rep.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final module commit: `3ae68b20c4796eb17c7ed00d1b6e08ec9cc83386`
- The report correction is a follow-up commit on the final module commit.
- Changed files:
  - `src/tact_rep.cpp`
  - `decomp_notes/source_cleanup/wave02/tact_rep.md`
- `include/tact_rep.h` was read but not changed. No other header was changed.

The registry selects 12 source owners from `004D1680` through `004D2020`.
The registry marks 11 owners `matching` and `004D1BB0` `accepted_drift`.
Those claims were not rechecked in this wave.

## Correction history

- Initial source cleanup: `57b1f2e3fc4b104f46ab826744974e5d4aae5929`.
- Initial cleanup report: `8d02b5c3f7a1a807bd3591322ccdac200fe1d9e3`.
- Root formatting correction: `3ae68b20c4796eb17c7ed00d1b6e08ec9cc83386`.
- The correction joins the short `move_to` and `work` signatures onto one line.
- It changes no expression, type, cast, scope, or statement.

## Original-name recovery

I inspected procedure-scoped parameters, locals, and registers for all 12 source
owners in `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB records `this` in `ecx` for every owner.
The following recovered names now match the PDB records:

| VA | Owner | Recovered parameters | Recovered locals |
| --- | --- | --- | --- |
| `004D1680` | first constructor | `infile`, `obj_in`, `do_setup` | none recorded |
| `004D1720` | target constructor | `obj_in`, `task_in`, `target_obj_in` | none recorded |
| `004D17B0` | coordinate constructor | `obj_in`, `task_in`, `x`, `y`, `z` | none recorded |
| `004D1800` | `setup` | `infile`, `obj_in` | none recorded |
| `004D1850` | `save` | `outfile` | none recorded |
| `004D1880` | `first_in_stack` | `first_time` | none recorded |
| `004D18B0` | `set_state` | `new_state` | none recorded |
| `004D1BB0` | `update` | none | none recorded |
| `004D1F50` | `stop` | none | none recorded |
| `004D1F60` | `move_to` | `obj_in`, `x`, `y`, `z` | none recorded |
| `004D1FA0` | `work` | `obj_in`, `x`, `y`, `z` | none recorded |
| `004D2020` | `meet_target` | none | `start`, `rVal`, `dest` |

The changed names replace generated or non-original names as follows:

- `param_1`, `param_2`, and `param_3` in the first constructor became
  `infile`, `obj_in`, and `do_setup`.
- The second constructor's `obj`, `task_arg`, and `target` became `obj_in`,
  `task_in`, and `target_obj_in`.
- The third constructor's `obj` and `task` became `obj_in` and `task_in`.
- `setup` now uses `infile` and `obj_in`.
- `save` now uses `outfile` instead of `handle`.
- `first_in_stack` now uses `first_time` instead of `value`.
- `set_state` now uses `new_state` instead of `param_1`.
- `move_to` now uses the recorded `obj_in` name.
- `work` now uses the recorded `obj_in`, `x`, `y`, and `z` names.

The PDB has no local records for `setup::result`, `set_state::action`,
`update::check_target`, `update::target`, `update::result`, `update::state`,
or the optimized locals in `meet_target`. I left those existing mappings in
place. I did not force names across reused or optimized storage.
The `meet_target` declarations keep the existing source order, even though the
PDB lists the three named stack symbols in a different order.

The nearby `004D16F0` scalar deleting destructor and `004D1710` destructor are
compiler-generated records. They have no source definition in this module and
were not changed.

## Source cleanup and evidence

- Applied 1TBS brace placement to the function definitions.
- Kept statement order, declaration scope, types, casts, calls, literals, and
  evaluation order unchanged.
- Added no new comments. The existing constructor comment remains.
- Added no constants, enums, resource IDs, or macros.
- The source has no resource lookup. No resource extraction was needed.
- No structural rewrite, helper, layout change, ABI change, or symbol rename was
  made.

Supporting source-function inventory paths and SHA256 values are:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D1680_TRIBE_Action_Repair.txt`
  `f11feaf0a33e21806f835f763718a80dd664e914522a4873d526e7d2655bfd08`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D1720_TRIBE_Action_Repair.txt`
  `f230020f8ae56f3e3360a8a5973dfc613d7b2be120f002bb009f03cb60fd9a37`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D17B0_TRIBE_Action_Repair.txt`
  `d9d9ee2f7119c8c283a3fd701550579ec76251656aa8fd54be23eb2aa0b1f34f`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D1800_setup.txt`
  `d78a7771789d77bd4a38c107925dd89bfc53dff188a6eb745192f15389ba78ec`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D1850_save.txt`
  `742ef52f56dbd0040b14c5936b334d1306bb3c56d1efb698d7da81125302a07c`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D1880_first_in_stack.txt`
  `29857b5c13186aeb8684586ecf12adfedd8d90fb003602ee7f7471f1a7f35ec2`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D18B0_set_state.txt`
  `63ed2750625dee52a387222be24fdf3775957b46c8384d05e7c423f8d80aff35`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D1BB0_update.txt`
  `44209191376a0df70d802dfa73c9e4177da458117d213420281dc38475ec0628`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D1F60_move_to.txt`
  `992d199f7aeb0a4902a1624b1632d34899076ee7b67d8fba6ebe152288b24968`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D1FA0_work.txt`
  `435d8b6fc1d27c9578a407980221ee9b7653f8e5c134d663310d38f961059960`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D2020_meet_target.txt`
  `464231cb39207dd6db628f5c12dfca24f42b6b2b343ed380f63293bcacf0853c`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`

The retained wave evidence references are:

- Original PE: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Runtime base language: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
  SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- Runtime expansion language: `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`
  SHA256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
- Preserved baseline object: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/tact_rep.obj`
  SHA256 `c5ea738cf32c749dc58a1dacbd46195a8b4d3114dcfa386f6d9a12d868267c66`.

## Shared requests and risks

- Header request to owner 05 for `include/tact_rep.h`: none.
- Shared `include/resource_ids.h` request: none.
- Shared `include/game_globals.h` request: none.
- No resource IDs were requested, so there is no per-ID text, missing-slot,
  language, lookup-path, or proposed-name mapping.
- Name and formatting changes can alter debug names and line records. No claim
  about generated-code equality is made before final validation.
- No type, object layout, call target, ABI symbol, relocation, or direct-call
  identity change was made in source.

## Validation limits

I reviewed the complete Git diff and ran `git diff --check`.
Compilation, matching, audits, and tests were not run.
No build, compiler check, game, or runtime command was run.
