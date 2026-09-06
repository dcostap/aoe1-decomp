# Executable build

This build uses the pinned VC5 compiler and linker.
It compiles the complete current source tree, then attempts a normal link.
It does not copy original game code or force unresolved symbols into an EXE.

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
The build requests an EXE, public-symbol PDB, and linker map.
Existing matching compiler profiles do not supply full source-level debug information.

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
