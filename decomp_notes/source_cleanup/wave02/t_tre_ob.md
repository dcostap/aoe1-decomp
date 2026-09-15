# `t_tre_ob.cpp` wave 02 cleanup report

## Delivery

- Module: `src/t_tre_ob.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `42fbc0dcc7b5c4b1965aec9800a62e13d3837ec4`
- Changed files: `src/t_tre_ob.cpp`; this report
- Header request: none. `include/t_tre_ob.h` remains owner 09's file.

The final source commit is the parent of the report-only commit that records
this report. The worker delivery response gives the full final worktree hash.

## PDB coverage and name recovery

The source registry at
`C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/t_tre_ob.cpp.json`
selects three normal procedures. All three have scoped PDB records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The corresponding packets are under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/`.

- `004CCA60` (`TRIBE_Tree_Object::TRIBE_Tree_Object`, lines 36-39,
  131 bytes): `tobj` (`TRIBE_Master_Tree_Object*`) at `+0x4`, `obj_owner`
  (`RGE_Player*`) at `+0x8`, `x`, `y`, and `z` (`float`) at `+0xc`, `+0x10`,
  and `+0x14`, and `do_setup` (`int`) at `+0x18`. The `ecx` register is
  `this` (`TRIBE_Tree_Object*`). The scoped record has no locals or statics.
- `004CCB20` (`TRIBE_Tree_Object::TRIBE_Tree_Object`, lines 44-47,
  101 bytes): `infile` (`int`) at `+0x4`, `gworld` (`RGE_Game_World*`) at
  `+0x8`, and `do_setup` (`int`) at `+0xc`. The `ecx` register is `this`
  (`TRIBE_Tree_Object*`). The scoped record has no locals or statics.
- `004CCB90` (`TRIBE_Tree_Object::set_object_state`, lines 51-62,
  13 bytes): `new_object_state` (`unsigned char`) at `+0x4`. The `ecx`
  register is `this` (`TRIBE_Tree_Object*`). The scoped record has no locals
  or statics.

All renamed identifiers are recovered original PDB names. No new descriptive
names were invented. No reused stack-slot mapping was uncertain.

The nearby `004CCAF0` scalar deleting destructor is compiler-generated and has
no source owner or source line. It was not edited.

## Behavior and evidence review

The source preserves the constructor calls, argument order, zero setup flags,
nonzero setup tests, direct setup targets, and the forwarding call in
`set_object_state`. The function packets record the original boundaries and
calls. The original executable used as behavior evidence is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup executable is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`,
SHA256 `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
The preserved module object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/t_tre_ob.obj`,
SHA256 `a4db0ec8713df726122e509f71cc15fc82f7507635b5e32e7b662095d2895bb5`.

No constants were added or replaced. This module has no resource lookup or
resource ID. No resource extraction was required. No comments were added;
the code has no non-obvious lifetime, unit, sentinel, or compatibility rule
that needs a source comment.

The identifier changes do not change types, storage, layout, ABI, calls, or
control flow. A rebuild could change debug names or line records. Compilation
was deferred, so generated-code impact was not measured.

## Requests and unresolved questions

There are no shared-header requests, resource requests, unresolved mappings,
or unresolved questions from this module.

Compilation, matching, audits, and tests were not run.
