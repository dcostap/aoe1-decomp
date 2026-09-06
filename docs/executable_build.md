# Executable build

This build uses the pinned VC5 compiler and linker.
It compiles the complete current source tree, then attempts a normal link.
It does not copy original game-function bodies or force unresolved symbols into an EXE.
The user approved two binary dependencies: the external compression library and the connected drawing assembly engine.
These dependencies are preserved code, not recovered source.

## Runtime setup

Use the complete local runtime under `runtime/`.
It contains the full release files with the beta `empiresx.exe` in place.
The folder is local and ignored by Git, except for `runtime/README.md`.
Do not assemble a runtime from selected base-game and expansion files.
Keep the repository original executable unchanged.

Prepare a new runtime directory after building:

```sh
python tools/prepare_runtime.py --help
python tools/prepare_runtime.py --exe build/executable/<run>/empiresx.exe --output build/runtime/installed_beta/rebuilt
```

The tool uses `runtime/` by default. Replace the build path for later builds.
Select a new output directory if one already exists.
The tool copies all installation files and verifies each copy with SHA256.
It then replaces only the runtime expansion EXE with the selected build.
`runtime_manifest.json` records the inputs, copied-file hashes, and selected EXE hash.

Double-click `build/runtime/installed_beta/rebuilt/Launch.cmd` to run the prepared build.
The launcher selects the runtime directory and supplies no game arguments by default.
It applies `DWM8And16BitMitigation` through a process-local environment setting.
This matches the working installation's path-specific Windows compatibility setting.
The launcher does not change registry settings or the installed game.
Directly launching the copied EXE can omit this compatibility setting.

The control copy is `build/runtime/installed_beta/original/Launch.cmd`.
Both prepared EXEs passed the constructor startup check with game error code zero.
The debugger stopped at that check. This does not prove menu or gameplay correctness.

## Commands

Run each tool with `--help` before use.

```text
python tools/build_executable.py --help
python tools/build_executable.py
```

Each run creates a new directory under `build/executable/`.
Previous logs and objects remain available.
The command returns zero only when every source compiles and the linker produces an EXE.
A successful link does not prove correct runtime behavior or exact image layout.

Inspect a failed link:

```text
python tools/audit_link_symbols.py --help
python tools/audit_link_symbols.py --report build/executable/<run>/report.json
```

The symbol audit writes `unresolved.csv` beside the build report.
Candidate symbols are investigation leads, not approved aliases.
Never connect different types or calling conventions only because their names look similar.

## Inputs

The function registry supplies existing source recipes.
`config/executable.json` adds integration recipes for `game_globals.cpp` and `tech.cpp`.
These recipes do not change function matching statuses.
The build rejects a source file without a recipe.

The original EXE supplies three resources: an icon, its group, and version data.
The build preserves resource payloads, identifiers, and languages.
It checks the original EXE hash before resource extraction.
`tools/pe_resources.py` writes ordinary Win32 `.res` input.
A test links these resources into a resource-only DLL and checks the complete resource round trip.
No original game instruction enters that DLL.

The original PE supplies the image base, Windows subsystem, stack reserve, and imported DLL list.
Object order is currently source-name order, not a proved original linker order.
The runnable configuration requests an EXE and linker map, without `/DEBUG`.
VC5 debug packing currently fails with `LNK1000`; embedded CodeView also fails with `LNK4027`.
The builder requests a PDB only when the configuration requests `/DEBUG`.
Existing matching compiler profiles do not supply full source-level debug information.

## Preserved compression dependency

`config/compression_binary.json` identifies the original `Inf32.obj` and `Deflate.obj` contributions.
`tools/compression_binary.py` extracts only their reviewed code and data ranges.
It builds a normal x86 COFF object with six exports and 565 absolute relocations.
VC5 LINK combines that object with the compiled game sources.
No original virtual address needs to remain fixed.

The extractor checks the original EXE hash, each payload hash, address operands, and the final object hash.
Its original-address round trip restores every preserved byte.
This is not a general route for embedding unrecovered game functions.
The build report records the binary dependency separately from compiled sources.

Run the independent runtime checks:

```text
python tools/probe_compression_binary.py --help
python tools/probe_compression_binary.py
python tools/probe_masm.py --help
python tools/probe_masm.py
```

Both probes keep outputs under new `build/probes/` directories.
The MASM probe uses the fixed tool in `config/assembly_toolchain.json`.
It does not replace the VC5 C/C++ compiler or linker.

## Drawing engine and recovered assembly

`config/drawing_binary.json` scopes the preserved drawing engine and its 4,223 absolute relocations.
The build uses one relocatable object for its code, dispatch tables, and mutable state.
`src/Asm_draw.asm` remains incomplete recovered source and does not enter the production link.
`src/Drawarea_asm.asm` remains an active source for three drawing memory methods.

Test the production drawing dependency with `python tools/probe_drawing_binary.py --help`, then run that tool without arguments.

`assembly_sources` in `config/executable.json` lists the standalone MASM sources.
`tools/build_assembly.py` verifies the assembler hash and uses the compiler admission gate.
The build reports assembly results separately from C/C++ compilation.
It requires every assembly input to produce an object successfully.

The drawing sources do not use the compression binary exception.
They restore instructions through assembly source and shared operation macros.

Run the address, instruction, data, and native checks:

```text
python tools/probe_asm_draw.py --help
python tools/probe_asm_draw.py
python tools/probe_asm_draw.py --manifest config/drawarea_asm.json
```

The probe resolves address fields to known original objects; it does not mask them.
Native tests use two separately linked image bases.
They do not establish game runtime correctness.

## DirectPlay library repair

The preserved VC98 `dplayx.lib` contains short import objects.
VC5 LINK 5.00.7022 cannot read that format and reports LNK1106.

`config/dplayx.def` records the three original ordinal imports.
The original EXE imports ordinals 1, 2, and 4.
The preserved library identifies their decorated names and argument sizes.
The build uses VC5 LIB to create compatible import objects.
It does not replace or modify the preserved library.

The pinned SDK calls its Video for Windows library `vfw32.lib`, not `msvfw32.lib`.
`uuid.lib` and the preserved period `dxguid.lib` supply GUID data.

## Virtual-table and data evidence

Use a function audit from the same source state as the build:

```text
python tools/audit_vtables.py --help
python tools/audit_vtables.py --build-report build/executable/<run>/report.json --function-audit build/audits/<audit>/report.json --output build/executable/<run>/vtables.json
```

The tool skips groups whose recorded input fingerprints differ.
It locates original tables through exact function relocations and reports unresolved slots and conflicting emitted definitions.
It does not prove original table bounds or class layouts.
The report also records unresolved absolute data references and their exact-reference coverage.
ASCII previews are evidence for review, not automatic initializers or complete type information.

## Completion requirements

A runnable reconstruction still requires:

1. Resolve every undefined symbol through its correct source or library owner.
2. Recover missing initialized data and shared declarations.
3. Resolve duplicate class surfaces and inherited-method declarations.
4. Restore the reviewed assembly functions and code regions.
5. Check startup, global initialization, imports, and resources.
6. Test menus, new games, rendering, sound, AI, saving, loading, and multiplayer.
7. Compare the linked image against the original.

Keep runtime files outside `orig/`.
Do not overwrite the original installation, saved games, or executable.
Do not describe a resource-only probe or failed-link output as a rebuilt game.

The integration evidence and remaining work are recorded in `decomp_notes/executable_build.md`.
