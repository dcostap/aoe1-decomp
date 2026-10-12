# Executable build

This build uses the pinned VC5 compiler and linker.
It compiles the complete current source tree, then attempts a normal link.
It does not copy original game-function bodies or force unresolved symbols into an EXE.
It takes no code, data, or resources from `orig/empiresx.exe`. The build records
that file's hash when it is present, but does not need it.

## Runtime setup

For the shared-asset build, windowed launch, and menu capture commands, see [runtime harness](runtime_harness.md).
Use `game.cmd build`, then `game.cmd rebuilt` or `game.cmd original`.
The older complete-copy commands below remain available as a control.

Use the complete local runtime under `runtime/`.
It contains a complete retail install. Its own `empiresx.exe` can be the retail
or the beta one: the runtime copy always replaces it with the selected EXE.
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

The launcher forwards command-line arguments. The known runtime configuration
uses `NOSTARTUP GAMECD`:

```sh
build/runtime/installed_beta/rebuilt/Launch.cmd NOSTARTUP GAMECD
```

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

The executable has three resources: an icon, its group, and version data.
`src/empiresx.rc` declares them, and VC5 `RC.EXE` compiles it.
The icon is a game asset, so the repository does not contain it.
The build extracts it from the retail `EMPIRES.EXE` in `runtime/`, which has the same icon bytes as the beta.
`config/executable.json` pins the hash of the extracted `.ico` file.
A test links the compiled script into a resource-only DLL.
It checks that payloads, identifiers, and languages equal the original EXE's resources.
No original game instruction enters that DLL.

The original PE supplies the image base, Windows subsystem, stack reserve, and imported DLL list.
Object order is currently source-name order, not a proved original linker order.
The runnable configuration requests an EXE and linker map, without `/DEBUG`.
VC5 debug packing currently fails with `LNK1000`; embedded CodeView also fails with `LNK4027`.
The builder requests a PDB only when the configuration requests `/DEBUG`.
Existing matching compiler profiles do not supply full source-level debug information.

## Compression library

The game links the `compress.lib` compressor and decoder from source:

- `src/Deflate.c` is the compressor (`Deflate.obj`), compiled with the default VC5 profile.
- `src/Inf32.asm` is the hand-written decoder (`Inf32.obj`), assembled with the pinned MASM.

The library predates the game. The 1997 PTRIBE build in the leaked builds has
instruction-identical Deflate code, and its map file supplies the function names.
That code came from an older compiler than VC5, so `Deflate.c` cannot match
byte for byte. It is proved by behavior instead.
`Inf32.asm` assembles to the original bytes and relocation targets.

`tools/probe_compression_library.py` checks both:

- It compares the assembled `Inf32` code and data with the original executable.
- It links the original Deflate object next to `src/Deflate.c` and runs
  `tests/fixtures/compression_library/deflate_diff.c`. Every case must produce the same
  output bytes, write-callback calls, return codes, and final state buffer.
  The full run covers more than 10,000 synthetic cases plus the decompressed `empires.dat`.
- It compresses and decodes test data with the source-built objects at two link
  bases, and checks the results with zlib and the game's `empires.dat`.

The original object comes from `config/compression_binary.json` through
`tools/compression_binary.py`. It is the test oracle only; the build never links it.

Run the checks:

```text
python tools/probe_compression_library.py --help
python tools/probe_compression_library.py
python tools/probe_masm.py --help
python tools/probe_masm.py
```

Both probes keep outputs under new `build/probes/` directories.
The MASM probe uses the fixed tool in `config/assembly_toolchain.json`.
It does not replace the VC5 C/C++ compiler or linker.

## Drawing engine and recovered assembly

`src/Asm_draw.asm` is the hand-written drawing engine: its code, dispatch tables,
and mutable state. It assembles to the original `THIS_COD` and `THIS_DAT` bytes,
and every one of its 4,223 address fields points at the original target.
Labels of the form `L56xxxx` keep original addresses of branch targets that
have no recovered name yet.
`src/Drawarea_asm.asm` is the source for three drawing memory methods.

`config/drawing_binary.json` describes the original object. It is the test oracle
only; the build never links it.

`tools/probe_drawing_engine.py` assembles `src/Asm_draw.asm`, compares both sections
and all relocation targets with the original executable, and runs the setup,
HLine, and sprite fixtures against the assembled object at two image bases.

`assembly_sources` in `config/executable.json` lists the standalone MASM sources.
`tools/build_assembly.py` verifies the assembler hash and uses the compiler admission gate.
The build reports assembly results separately from C/C++ compilation.
It requires every assembly input to produce an object successfully.

The drawing sources restore instructions through assembly source and shared operation macros.

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

The integration evidence and remaining work are recorded in `workflow/decomp_notes/executable_build.md`.
