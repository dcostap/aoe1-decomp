# `tact_tek.cpp` source-cleanup report

## Delivery

- Module: `src/tact_tek.cpp`
- Branch: `cleanup/staging-20260915-133`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `f9c32ca108a355223b365202cc2846249df79e24`
- Report correction commit: follows this source commit.
- Changed files:
  - `src/tact_tek.cpp`
  - `workflow/decomp_notes/source_cleanup/wave03/tact_tek.md`
- Registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/tact_tek.cpp.json`
- Registry flags: `gx`
- Header read but not edited: `include/tact_tek.h`

The source keeps all nine normal procedures in the PDB source order. The
cleanup restores procedure-scoped PDB names and removes stale empty comments.
It does not change statements, calls, types, casts, literals, or storage.

## Evidence

I read the complete source-cleanup guides and the assigned source and header.
I inspected every registry procedure in the scoped PDB record file:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The scoped PDB file SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The original PDB is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`

Its SHA256 is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
The PDB source path is `C:\msdev\work\age1_x1\tact_tek.cpp`.
Every assigned procedure has a `this` register record in `ecx`.

I inspected these complete function packets selected by the source registry:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D21B0_TRIBE_Action_Make_Tech.txt`
  SHA256 `dfca9c7bfb04378dbfc298f1579907ed388e90374e53e833b7836c267eead5c0`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D2250_TRIBE_Action_Make_Tech.txt`
  SHA256 `95701a94cfeebdf812dae5545a0f2b97128fc7f5a2c71094a51d385a102da39a`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D2290_TRIBE_Action_Make_Tech.txt`
  SHA256 `2c12a3bf23c28a85def2fc9e24c5730f898486aac08b0cf8b505c31fdabcc5b0`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D2370_save.txt`
  SHA256 `cf11a739640e13fff6fa1b9e44f17dd0d4b2d235ae574d4f55038b7b2ddfce28`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D23B0_first_in_stack.txt`
  SHA256 `6775140097bbba060a0919ea4663a6878e0afd46879820e0606a48f028f1d1f9`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D2440_set_state.txt`
  SHA256 `b3c8f7e6bc013ca28f0655fbe11e5a63bcf6c70c1323d15347cbaf976676412c`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D2450_update.txt`
  SHA256 `083053194bd214da942ddd83bbb6176409e98be03578011d7658456865ac3c89`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D2550_stop.txt`
  SHA256 `68bf7bc3616129ddc4bf9a27460058e019daece9a1b8c320cfa849c44195ff9e`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D25E0_get_info.txt`
  SHA256 `706cdb0b5edfd19464aabe97ee7f527e25dbfe8b764741f5421728b836022f79`

The original executable remains the behavior oracle:

`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`

Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup object is:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/tact_tek.obj`

Its SHA256 is
`0611755466d3ce6501c2e924059a1ce4dc1f8b70b6ef3776589ca56edee0d49d`.
The preserved pre-cleanup executable is:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`

Its SHA256 is
`492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.

The packet excerpts and original assembly support the recorded boundaries,
source lines, calls, and direct target identities. The original Ghidra unit is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tact_tek.cpp.decomp`

## Original-name recovery coverage

The table lists every PDB stack symbol, its type, and its source result.
The PDB register symbol is `this` in `ecx` for every procedure.

| VA | Procedure | PDB parameters | PDB locals | Source result |
| --- | --- | --- | --- | --- |
| `004D21B0` | file constructor | `infile` (`int`, `+0x4`); `obj_in` (`RGE_Action_Object*`, `+0x8`) | none | Restored both parameters. |
| `004D2250` | value constructor | `obj_in` (`RGE_Action_Object*`, `+0x4`); `id` (`short`, `+0x8`); `uID` (`int`, `+0xc`) | none | Restored all three parameters. |
| `004D2290` | destructor | none | none | No source name was available. |
| `004D2370` | `save` | `outfile` (`int`, `+0x4`) | none | Renamed `file` to `outfile`. |
| `004D23B0` | `first_in_stack` | `first_time` (`unsigned char`, `+0x4`) | `attNeeded` (`short`, `+0x8`) | Restored `first_time`; retained the existing alias for `attNeeded`. |
| `004D2440` | `set_state` | `new_state` (`unsigned char`, `+0x4`) | none | The source already used `new_state`. |
| `004D2450` | `update` | none | `work` (`float`, `-0x4`) | The source already used `work`. |
| `004D2550` | `stop` | none | none | No source name was available. |
| `004D25E0` | `get_info` | `id` (`short&`, `+0x4`); `progress` (`short&`, `+0x8`); `name` (`char*`, `+0xc`); `name_size` (`short`, `+0x10`) | none | Restored all four parameter names. |

The source changes these non-header identifiers:

- `004D21B0`: `file` became `infile`; `object` became `obj_in`.
- `004D2250`: `object` became `obj_in`; `tech_id_value` became `id`;
  `unique_id_value` became `uID`.
- `004D2370`: `file` became `outfile`.
- `004D23B0`: `value` became `first_time`.
- `004D25E0`: `tech_id_out` became `id`; `progress_out` became `progress`;
  `name_out` became `name`; `max_length` became `name_size`.

The names `uID`, `attNeeded`, and `first_time` preserve their original
mixed-style spellings. No public function, class, member, or ABI symbol changed.

## Locals and unresolved mappings

The PDB records `attNeeded` for `004D23B0`, but its storage overlaps the
incoming `first_time` home in the optimized original assembly. The packet shows
`004D23C8` passing the incoming stack slot to `start_research`. The failure path
reads that same slot at `004D2405` before `cancelResearch`.

The source keeps `reinterpret_cast<short*>(&first_time)` and
`(int)*(short*)&first_time`. I did not add a separate `short attNeeded`
declaration. That would force a declaration and storage mapping that the
optimized packet does not support. The `attNeeded` source declaration mapping
remains unresolved.

The PDB has no source-local records for `result`, `player_tech`, or
`action_object` in the current source. These remain existing descriptive names.
They are not claimed as recovered originals. No new cleanup name was invented.
No reused stack slot was split or merged.

The nearby vector-deleting destructor at `004D2230` is compiler generated. Its
PDB `__flags` parameter was inspected, but it has no handwritten source owner.
It was not edited.

## Constants, resources, and comments

No numeric constant, enum, resource ID, or macro changed. This module has no
resource lookup. No resource extraction was needed. No resource-ID request
exists for `include/resource_ids.h`.

I removed the empty `//` separator and the stale constructor note. I added no
new source comment. The remaining source has no comment that claims validation.

## Code-generation, type, layout, and symbol review

The edits rename identifiers, join short signatures, adjust indentation, and
remove two comments. They do not change types, casts, declaration points,
scope, storage duration, evaluation order, control flow, calls, literals,
function boundaries, relocations, virtual slots, class layout, or ABI symbols.
No helper, wrapper, layout change, assembly, or bug repair was added.

The registry statuses remain unchanged: `004D21B0`, `004D2370`, `004D23B0`,
`004D2440`, `004D2450`, and `004D2550` are `matching`; `004D2250` and
`004D25E0` are `accepted_drift`; and `004D2290` is `matching`.
These claims were not rechecked during this cleanup.

The removed and moved source comments can change debug line records. Generated
code, program data, relocations, and call targets remain unvalidated.

## Header and shared-file requests

I read `include/tact_tek.h` and did not edit it. Owner 15 controls that header.
The header owner may add these PDB-proven parameter names without changing
access, types, order, virtual slots, layout, or symbols:

```cpp
TRIBE_Action_Make_Tech(int infile, RGE_Action_Object* obj_in);
TRIBE_Action_Make_Tech(RGE_Action_Object* obj_in, short id, int uID);
virtual void save(int outfile);
virtual void first_in_stack(unsigned char first_time);
virtual void set_state(unsigned char new_state);
void get_info(short& id, short& progress, char* name, short name_size);
```

`update()` and `stop()` have no parameters to name. `attNeeded` should not be
added to the header. No root-owned shared declaration request exists.

## Validation status

I reviewed the complete source and report diff. I ran `git diff --check`.
I ran the required evidence-tool help commands before inspection.

Compilation, matching, audits, and tests were not run. No build, compiler,
game, runtime harness, or audit command was run.

**Compilation, matching, audits, and tests were not run.**
