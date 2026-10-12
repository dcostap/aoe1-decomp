# Obstruction table storage repair

## Confirmed defect

The original shift table at `00584EF4` lies in writable `.data`.
The prior linked build places its corresponding table at `005520E0` in read-only `.rdata`.
Both tables initially contain `0, 2, 4, 6`.

The original mask table at `00584EF0` also lies in writable `.data`.
The rebuilt mask table at `005520E4` lies in read-only `.rdata`.
Both masks initially contain `FC, F3, CF, 3F`.

## Static counterexample

Use `incrementObstruction` with `x = y = 0`.
For each image, set `this` to its shift-table address minus `0xCE624`.
Use separate mapped stack storage with valid return and argument words.
No stack overlap is required.

Both complete instruction sequences read zero from the map byte and shift table.
Both then compute a write of one to the shift table.
The original store succeeds under its image permissions.
The rebuilt store faults under its image permissions.

The proof asserts all 86 original instruction bytes and all 84 rebuilt instruction bytes.
It checks both table contents and the PE read/write flags.
It runs no game code or instruction emulator.

Proof event: `9975678aca9752d480fb82f9d478962a1c670bc8749384e56e767ceb70efd114`.
Artifacts: `build/prove_obstruction_storage_alias.py` and `build/obstruction-storage-alias-proof.json`.
The rebuilt input is `build/executable/claims-final/20260908T182352017500Z/empiresx.exe`.

## Source evidence and limits

`src/game_globals.cpp` defines both arrays as `const unsigned char`.
`src/pathsys.cpp` declares both arrays with the same qualifier.
The indexed PDB query and module-name search found no original declaration.
The storage difference alone does not prove the original C++ qualifier.

Writable arrays are a simple, period-plausible repair hypothesis.
Test the definitions and declarations together in an independent worktree.
Check symbol identity, all affected owners, initial bytes, and final linked permissions.
Do not add symbol aliases or change an entire section's permissions to hide the problem.

This proof covers one corresponding table-alias input.
It does not approve all pathfinding behavior or the separate array-header repair.

## Checked repair

State `obstruction-writable-tables` removes the qualifier from both declarations and definitions.
Its complete two-file snapshot includes `src/game_globals.cpp`, which the target compiler dependency list does not include.

- State hash: `cce4487dc96727a097e0933a378cb3f4ba75db473c6cd75ebe3bd3390b309c8c`.
- Target and module run: `3c6039fa579459bf228bd2f7044dd08989dab41ef4f63cc5860e1b74deb2584f`.
- Complete snapshot: `workflow/decomp_notes/candidates/0046/0046B5E0_complete_writable_tables.patch` and its hash manifest.

`0046B5E0` retains `MATCH`, `0.0000%`, and all 52 original bytes.
All 31 path-system owner descriptions agree with the baseline except two table symbol spellings in five owners.
The comparison includes scratch functions, relocations, and referenced data.
No function bytes change. No alias preserves the old qualified spelling.

The isolated build compiles 226 sources and links without errors or unresolved symbols.
The shift and mask tables now occupy writable `.data` at `00564C34` and `00564C38`.
Their initial bytes remain unchanged.
The linked increment sequence changes only its two table addresses.
It can now perform the previously rejected write.

Repair proof event: `3040f32ce120ad15ec67b38b5c85dd5f0a8b84e805604c7f699b8f542baadcbe`.
Artifacts: `build/verify_writable_table_repair.py` and `build/writable-table-repair-proof.json`.

Header validation reports 133 passing entries.
Linked references retain 6,873 passes and 5,276 unknowns, with no reported failures.
The initializer audit reports 124 equal entries, 107 review entries, 60 unmapped entries, and one invalid original section.
Those unresolved entries are not passes. The table-specific proof supplies the narrower storage evidence above.

## Integration decision

Approve only this bounded storage repair.
The full isolated suite passes 415 tests and 31 subtests.
The corrected tests also check original writable sections and freshly compiled table permissions.

Main passes the authoritative 52-byte obstruction check, all 16 matching path-module targets, and 24 focused tests.
Its 31 emitted owner descriptions agree with the checked isolated state.
Global code and CRT sections retain their bytes and named relocations.
Removing only the two moved four-byte tables makes all other global-object sections and adjusted symbols agree.

Final evidence event: `e4b37b17c63d8aa116c7b713d8c1661b567ddc7de1ac80051cc8945c11da3973`.
The four-file source and test snapshot is `workflow/decomp_notes/candidates/0046/0046B5E0_complete_writable_tables_with_tests.patch`.
Its hash manifest records the tested inputs.

This decision does not approve the separate array repair or unresolved original-behavior claims.
