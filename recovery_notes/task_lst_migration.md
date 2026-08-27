# task_lst.cpp source-module migration

The original PDB names `C:\\msdev\\work\\age1_x1\\task_lst.cpp` as the source
module. Its eleven normal owners remain in this source order:

- `00508E00` constructor
- `00508E20` destructor
- `00508E30` `copy`
- `00508EC0` integer-handle `load`
- `00508F60` `FILE*` `load`
- `00509010` `save`
- `00509050` `delete_list`
- `005090B0` `create_task`
- `00509120` `get_target_task`
- `005092D0` `is_attack_task`
- `005092F0` `check_task`

The module now uses `src/task_lst.cpp` and `include/task_lst.h`. The former
wrapper, per-function matching files, and temporary context header were
removed. The bodies were moved without byte-tuning changes.

The source includes canonical `rge_fio.h` for C++ `rge_read` and `rge_write`.
It has no local C-linkage I/O declaration.
It includes action-object, static-object, master-static, player, map, and world
owners only in the source file for accessed fields and methods.

The current focused checks report 11/11 exact owners. Every owner reports
`Result: MATCH` and `0.0000%` positional difference. Exact repair is complete
after source migration.
## Owner-only header validation

The first grouped `task_lst` candidate after header cleanup did not produce an
object. The compiler rejected the moved local `rge_read` declaration because
`include/task.h` declares the same helper with a `void` return type. The local
declaration now matches the canonical header in commit `ccff7f590`. The
syntax-repair rerun matched all eleven owners with zero positional bytes,
zero relocation target mismatches, and zero boundary escapes. Its grouped
report is `build/candidate_tus/task_lst_owner_cleanup/report.json`.
