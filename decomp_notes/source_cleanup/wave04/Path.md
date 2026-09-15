# `src/Path.cpp` cleanup report

## Delivery

- Module: `src/Path.cpp`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Initial source commit: `67af8d2f4413adea5af92136602734a987d61fc8`
- Initial report commit: `410ccb2b4cf99559d65c6dc4bbbce7ca8fb7740c`
- Correction source commit: `dd36d9b93d668bb6a833937e71147b3d62998787`
- Changed files:
  - `src/Path.cpp`
  - `decomp_notes/source_cleanup/wave04/Path.md`

The initial source commit restores PDB parameter names. It also renames one
inferred stream pointer to avoid a collision with the recovered `out` parameter.
The correction source commit applies 1TBS across the module.

## Correction history

- `dd36d9b93d668bb6a833937e71147b3d62998787` moves every function-definition
  opening brace onto its signature line.
- The same commit joins two short allocation calls.
- No executable token, declaration type, control-flow scope, or source order
  changed in the correction.

## Scope and original-name recovery

The module owns all 30 normal procedures from `0046A740` through `0046AFE0`.
The PDB source is `C:\\msdev\\work\\age1_x1\\Path.cpp`.
The source map covers source lines 36 through 367.

The procedure-scoped records are in the following table. `stack` lists each
PDB stack symbol, its type, and its home. `register` lists each PDB register
symbol. Every procedure has zero PDB function statics.

| VA | Procedure | PDB stack symbols | PDB register symbols |
| --- | --- | --- | --- |
| `0046A740` | `Path::Path` | `v: int` at `+0x4` | `this: Path*` in `ecx` |
| `0046A7F0` | `Path::~Path` | none | `this: Path*` in `ecx` |
| `0046A810` | `operator<<` | `out: ostream&` at `+0x4`; `p: const Path&` at `+0x8` | none |
| `0046A8E0` | `Path::operator+` | `__$ReturnUdt` at `+0x4`; `p: const Path&` at `+0x8`; `newPath: Path` at `-0x40` | `this: const Path*` in `ecx` |
| `0046A9E0` | `Path::operator=` | `p: const Path&` at `+0x4` | `this: Path*` in `ecx` |
| `0046AAE0` | `Path::operator==` | `p: const Path&` at `+0x4` | `this: const Path*` in `ecx` |
| `0046AB60` | `Path::insertAtCurrent` | `w: const Waypoint&` at `+0x4` | `this: Path*` in `ecx` |
| `0046AC10` | `Path::insertAtEnd` | `w: Waypoint` at `+0x4` | `this: Path*` in `ecx` |
| `0046ACE0` | `Path::contains` | `w: const Waypoint&` at `+0x8` | `this: const Path*` in `ecx` |
| `0046ADA0` | `Path::killPath` | none | `this: Path*` in `ecx` |
| `0046ADB0` | `Path::maxNumberOfWaypoints` | none | `this: const Path*` in `ecx` |
| `0046ADC0` | `Path::numberOfWaypoints` | none | `this: const Path*` in `ecx` |
| `0046ADD0` | `Path::timeStamp` | none | `this: const Path*` in `ecx` |
| `0046ADE0` | `Path::setTimeStamp` | `v: unsigned long` at `+0x4` | `this: Path*` in `ecx` |
| `0046ADF0` | `Path::length` | none | `this: const Path*` in `ecx` |
| `0046AE50` | `Path::start` | none | `this: const Path*` in `ecx` |
| `0046AE60` | `Path::goal` | none | `this: const Path*` in `ecx` |
| `0046AE70` | `Path::waypoint` | `w: int` at `+0x4` | `this: const Path*` in `ecx` |
| `0046AEA0` | `Path::currentWaypoint` | none | `this: const Path*` in `ecx` |
| `0046AEC0` | `Path::currentWaypointNumber` | none | `this: const Path*` in `ecx` |
| `0046AED0` | `Path::setCurrentWaypointNumber` | `v: int` at `+0x4` | `this: Path*` in `ecx` |
| `0046AEE0` | `Path::nextWaypoint` | none | `this: const Path*` in `ecx` |
| `0046AF10` | `Path::previousWaypoint` | none | `this: const Path*` in `ecx` |
| `0046AF40` | `Path::firstWaypoint` | none | `this: const Path*` in `ecx` |
| `0046AF60` | `Path::lastWaypoint` | none | `this: const Path*` in `ecx` |
| `0046AF80` | `Path::initToStart` | none | `this: Path*` in `ecx` |
| `0046AF90` | `Path::initToEnd` | none | `this: Path*` in `ecx` |
| `0046AFA0` | `Path::moveToNextWaypoint` | none | `this: Path*` in `ecx` |
| `0046AFC0` | `Path::moveToLastWaypoint` | none | `this: Path*` in `ecx` |
| `0046AFE0` | `Path::distanceToNextWaypoint` | none | `this: const Path*` in `ecx` |

Recovered definition names are:

- `Path::Path`: `max_size` to `v`.
- `operator<<`: `os` to `out`, and `path` to `p`.
- `Path::operator+`, `operator=`, and `operator==`: `other` to `p`.
- `Path::insertAtCurrent`, `insertAtEnd`, and `contains`: `wp` to `w`.
- `Path::setTimeStamp` and `setCurrentWaypointNumber`: `value` to `v`.
- `Path::waypoint`: `index` to `w`.

The PDB local `newPath` was already present and remains unchanged.
The PDB `__$ReturnUdt` entry is compiler return storage, not a source name.

The PDB omits source locals for the remaining procedures. I did not force
those homes into declarations. Existing cleanup names remain for `i`, `j`,
`value`, `path`, `other_path`, `new_path`, `dst`, `index`, `next_index`,
`total`, `waypoint`, `remaining`, `result`, and `current`.
The inferred stream pointer `out` is now `stream`.
These are cleanup names, not recovered original names.

## Evidence and behavior

The procedure records came from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0046/`

The original executable oracle is:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/aoe1_ghidra_assembly_listing.txt`

The preserved cleanup baseline is:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/Path.obj`

The current source keeps the original call targets, expression order, casts,
field access, allocation sizes, sentinels, and failure paths.
No type, storage, layout, or ABI declaration changed in this source commit.

`Path::length` keeps the confirmed shipped expression defect. The first
z-axis product subtracts the previous waypoint's `x` value.
The existing source comment records this fact.
The instruction evidence is in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0046/0046ADF0_length.txt`.

`Path` remains 0x34 bytes. `Waypoint` remains 0x10 bytes.
The layouts are supported by:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/Path.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/Waypoint.txt`
- `include/path.h`
- `include/waypoint.h`

## Constants, resources, and comments

No numeric constant changed. No new constant was added.
The existing `16` allocation stride matches the proved 0x10-byte `Waypoint`.
The existing `1000` limit is the original `0x3E8` comparison.
The existing `-1` checks are waypoint sentinels from the original branches.

`Path.cpp` has no resource lookup and no resource ID.
No DLL resource was inspected. No resource mapping is requested.
No new comment was added. The existing `Path::length` comment remains sparse
and records the executable-proven expression defect.

## Shared-file requests and open questions

`include/path.h` belongs to owner 24. I did not edit it.
Please align its declaration parameter names with the PDB records:

- `Path(int v)`.
- `operator<<(ostream& out, const Path& p)`.
- `Path::operator+(const Path& p)`, `operator=(const Path& p)`, and
  `operator==(const Path& p)`.
- `insertAtCurrent(const Waypoint& w)`, `insertAtEnd(Waypoint w)`, and
  `contains(const Waypoint& w)`.
- `setTimeStamp(unsigned long v)`, `waypoint(int w)`, and
  `setCurrentWaypointNumber(int v)`.

This request changes names only. It does not change any type or signature.
No shared resource declaration request exists.

The remaining local mappings are unresolved because the optimized PDB has no
local records for them. The source leaves those declarations unchanged.
The header request remains pending with owner 24.

## Review and validation status

I reviewed the complete Git diff. `git diff --check` reported no whitespace
errors.

Compilation, matching, audits, and tests were not run.
Builds, validation commands, and games were not run.
