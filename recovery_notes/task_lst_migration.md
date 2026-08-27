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

Before migration, the registered grouped evidence had nine positional matches.
The destructor differed at two bytes. `is_attack_task` had zero positional
byte differences but a non-MATCH result. Natural source consolidation can cause
temporary exactness regressions. Exact repair resumes after source migration.
