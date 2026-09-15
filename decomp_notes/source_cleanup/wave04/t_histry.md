# `t_histry.cpp` source-cleanup report

## Scope and commits

- Module: `src/t_histry.cpp`.
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Source cleanup commit: `f5cf89b8070dd8bbd443f65ceb7d7527b08a6979`.
- Final report commit: to be copied from Git after the report update.
- Changed files: `src/t_histry.cpp` and this report only.
- Read-only header: `include/t_histry.h`.

The source keeps the existing natural owner and function order. The header keeps
its existing declaration parameter names because its owner is not this worker.

## Evidence paths and hashes

The original PDB is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`

Its SHA256 is `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
The generated scoped-symbol inventory is:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The PDB source path is `C:\msdev\work\age1_x1\t_histry.cpp`. Every scoped
record lists module object path `.\Release\t_histry.obj` and register `ecx`
with name `this`.

The original executable used as the behavior oracle is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The original listing evidence is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/t_histry.cpp.asm`

The preserved pre-cleanup object is:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/t_histry.obj`

Its SHA256 is
`fccfff038ba9c6f03a42a707c4bb495c7f56eefdfadfd13fbb5abd709d09fe66`.

The function registry is

`config/functions/src/t_histry.cpp.json`

It records 11 normal functions at the addresses listed below. The PDB source
map records the same 11 functions in source and address order.

## PDB name-recovery coverage

The following table covers every assigned function. The stack names and offsets
come from `inventory/pdb/scoped_symbols.json`. No function-static symbols exist.

| VA | PDB procedure and size | PDB stack names | Source result |
| --- | --- | --- | --- |
| `004CC730` | `TRIBE_History_Info::TRIBE_History_Info`, 41 bytes | `infile` at `+0x4`, `T_INT4(0074)` | Recovered `infile`. |
| `004CC760` | `TRIBE_History_Info::~TRIBE_History_Info`, 49 bytes | none | No parameter or local name recovered. |
| `004CC7A0` | `TRIBE_History_Info::save`, 148 bytes | `outfile` at `+0x4`, `T_INT4(0074)`; `count` at `+0x8`, `T_LONG(0012)` | Recovered `outfile` and `count`. |
| `004CC840` | `TRIBE_History_Info::load`, 159 bytes | `infile` at `+0x4`, `T_INT4(0074)`; `count` at `+0x8`, `T_LONG(0012)` | Recovered `infile` and `count`. |
| `004CC8E0` | `TRIBE_History_Info::add_history_entry`, 106 bytes | `history_type` at `+0x4`, `T_UCHAR(0020)`; `entry` at `+0x8`, `T_UCHAR(0020)` | Recovered both parameter names. |
| `004CC950` | `TRIBE_History_Info::get_history_entry_num`, 4 bytes | none | No parameter or local name beyond `this`. |
| `004CC960` | `TRIBE_History_Info::get_history_entry`, 36 bytes | `history_type` at `+0x4`, `T_UCHAR(0020)`; `time` at `+0x8`, `T_LONG(0012)` | Recovered both parameter names. |
| `004CC990` | `TRIBE_History_Info::add_history_event`, 65 bytes | `history_event` at `+0x4`, `T_UCHAR(0020)` | Recovered `history_event`. |
| `004CC9E0` | `TRIBE_History_Info::get_history_event_num`, 4 bytes | none | No parameter or local name beyond `this`. |
| `004CC9F0` | `TRIBE_History_Info::get_history_event`, 54 bytes | `number` at `+0x4`, `T_LONG(0012)`; `event` at `+0x8`, `0x1268` (`unsigned char&`); `time` at `+0xc`, `0x1009` (`long&`) | Recovered all three parameter names. |
| `004CCA30` | `TRIBE_History_Info::get_history_event`, 46 bytes | `time_slice` at `+0x4`, `T_LONG(0012)`; `event` at `+0x8`, `0x1268` (`unsigned char&`) | Recovered both parameter names. |

The PDB records `this` in `ecx` for all 11 procedures. It records no register
names other than `this`, and no function statics.

## Renamed parameters and locals

Recovered original parameter names replace the prior descriptive names:

- `004CC730`: `index` became `infile`.
- `004CC7A0`: `file` became `outfile`.
- `004CC840`: `file` became `infile`.
- `004CC8E0`: `flag` became `history_type`; `value` became `entry`.
- `004CC960`: `mode` became `history_type`; `index` became `time`.
- `004CC990`: `event` became `history_event`.
- `004CC9F0`: `index` became `number`.
- `004CCA30`: `time` became `time_slice`.

The PDB stack record named `count` at `+0x8` in both `save` and `load`.
The source local `step_count` now uses that recovered name in both functions.
The source keeps the existing `int` type. The PDB displays `T_LONG(0012)` for
this stack record. This type difference remains unresolved; this cleanup did
not change the declaration type.

The `004CC990` parameter recovery creates a local-name collision with the old
local `history_event`. That local now uses the new descriptive name `event_node`.
The PDB has no local record for it. The new name describes the allocated event
node and does not assert an original spelling.

These local names have no reliable PDB mapping and remain unchanged:

- `004CC760`: `events`.
- `004CC7A0`: `step`.
- `004CC840`: `prev_ptr` and `step`.
- `004CC8E0`: `old_capacity` and `new_entries`.
- `004CC9F0`: `node`.
- `004CCA30`: `node`.

The source has no `param_*`, `local_*`, or decompiler-register names. The names
listed above are either recovered PDB names or existing descriptive names.

## Constants, resources, and comments

No new constant or symbolic declaration was added. Existing values remain in
place: four-byte file fields use `4`, event records use `0x10` bytes, and entry
capacity grows by `0x3C`. No cast, width, signedness, declaration scope, or
storage duration changed.

This source has no resource-ID lookup. It has no resource DLL dependency. No
resource extraction was needed, and no `inspect_pe_strings.py` lookup was run.
There are no resource-ID mappings or header requests.

No source comment was added. The original listing at `004CC9F0` shows that the
indexed event method tests `number` but never decrements it. The source keeps
that behavior: only `number == 0` can return an event. The listing also shows
that `load` allocates zero-filled event nodes and preserves the terminating null
link. Neither behavior was changed.

## Original names versus cleanup names

Recovered original names are `infile`, `outfile`, `count`, `history_type`,
`entry`, `history_event`, `number`, `time`, `time_slice`, and `event`, as listed
by the PDB records above. `event_node` is the only new name introduced by this
cleanup. Existing names without PDB records are not claimed as original names.

## Code-generation, type, layout, and symbol effects

The edits rename parameters and locals. They do not change a mangled symbol,
calling convention, type, layout, control flow, evaluation order, call target,
literal, cast, or memory access. The signature wrapping change does not change
tokens. The local `event_node` keeps the prior pointer type and scope.

The unresolved PDB `T_LONG` versus source `int` record is a type-recovery question.
This commit preserves `int`; it does not claim a type correction or matching
result. Final compiler and binary checks remain required.

## Header requests and unresolved questions

No header change is requested. Definition parameter names can differ from the
read-only header parameter names without changing the interface. No shared
resource declaration is needed.

Open questions are the original spellings of PDB-unlisted locals and the reason
for the PDB `T_LONG` versus source `int` record for `count`. Reused stack slots
prevent a reliable declaration reconstruction for those locals. The indexed
event bug remains intentional compatibility behavior.

## Validation status

I reviewed the complete Git diff and ran `git diff --check`. I did not run a
compiler, build, matching check, audit, validation command, test, or game. I do
not claim byte equality, semantic approval, or validation.
