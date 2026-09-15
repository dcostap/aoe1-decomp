# `m_dg_obj.cpp` source-cleanup report

## Delivery

- Source: `src/m_dg_obj.cpp`
- Report: `decomp_notes/source_cleanup/wave02/m_dg_obj.md`
- Branch: `cleanup/staging-20260915-68`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Head after the source commit: `f1a3e7fad9bb22b5d8c5ad46bfc635d67f2fbc57`
- Changed files in the source commit: `src/m_dg_obj.cpp`
- The follow-up report commit contains this report only.

The matching header `include/m_dg_obj.h` was read and was not edited.

## Evidence reviewed

I read the repository contract and the complete source-cleanup, source-comment,
resource-ID, owner, assignment, and testing guides. I read the module registry,
the assigned source, and the matching header.

I inspected every assigned procedure in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB source path is `C:\msdev\work\age1_x1\m_dg_obj.cpp`. I inspected these
complete function packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0045/`:

- `004510C0_RGE_Master_Doppleganger_Object.txt`
- `00451140_RGE_Master_Doppleganger_Object.txt`
- `004511B0_RGE_Master_Doppleganger_Object.txt`
- `00451230_setup.txt`
- `00451250_setup.txt`
- `00451280_setup.txt`
- `004512C0_RGE_Master_Doppleganger_Object.txt`
- `004512D0_make_new_obj.txt`
- `004513B0_make_new_master.txt`
- `00451420_copy_obj.txt`
- `00451430_save.txt`

The original executable used for assembly evidence is
`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup object is
`build/source-cleanup-20260915/preparation/baseline-build/m_dg_obj.obj`.
Its SHA-256 is
`97d5c5e292195859c1d3910aaa3037a925fbcc5381d06d988786112eca83a0ab`.

The registry selects the `gx` build profile. The pinned toolchain configuration
was read from `config/toolchain.json`. No compiler command was run.

## Per-function PDB inspection coverage

All eleven source-owned procedures have a `this` register record in ECX. None
has a PDB function-static record. None has a PDB source-local record. The
Ghidra listing shows EH slots such as `local_4`, `local_c`, and `local_10`.
Those slots are not procedure-scoped source locals in the PDB record.

| VA | Procedure | PDB stack parameters | PDB locals | Register record |
| --- | --- | --- | --- | --- |
| `004510C0` | constructor | `other_object` (`RGE_Master_Doppleganger_Object*`, `+0x4`); `do_setup` (`int`, `+0x8`) | none | `this` (`RGE_Master_Doppleganger_Object*`, ECX) |
| `00451140` | constructor | `infile` (`int`, `+0x4`); `sprites` (`RGE_Sprite**`, `+0x8`); `sounds` (`RGE_Sound**`, `+0xc`); `do_setup` (`int`, `+0x10`) | none | `this` (`RGE_Master_Doppleganger_Object*`, ECX) |
| `004511B0` | constructor | `infile` (`_iobuf*`, `+0x4`); `sprites` (`RGE_Sprite**`, `+0x8`); `sounds` (`RGE_Sound**`, `+0xc`); `in_id` (`short`, `+0x10`); `do_setup` (`int`, `+0x14`) | none | `this` (`RGE_Master_Doppleganger_Object*`, ECX) |
| `00451230` | `setup` | `other_object` (`RGE_Master_Doppleganger_Object*`, `+0x4`) | none | `this` (`RGE_Master_Doppleganger_Object*`, ECX) |
| `00451250` | `setup` | `infile` (`int`, `+0x4`); `sprites` (`RGE_Sprite**`, `+0x8`); `sounds` (`RGE_Sound**`, `+0xc`) | none | `this` (`RGE_Master_Doppleganger_Object*`, ECX) |
| `00451280` | `setup` | `infile` (`_iobuf*`, `+0x4`); `sprites` (`RGE_Sprite**`, `+0x8`); `sounds` (`RGE_Sound**`, `+0xc`); `in_id` (`short`, `+0x10`) | none | `this` (`RGE_Master_Doppleganger_Object*`, ECX) |
| `004512C0` | destructor | none | none | `this` (`RGE_Master_Doppleganger_Object*`, ECX) |
| `004512D0` | `make_new_obj` | `owner` (`RGE_Player*`, `+0x4`); `x` (`float`, `+0x8`); `y` (`float`, `+0xc`); `z` (`float`, `+0x10`); `obj_to_dopple` (`RGE_Static_Object*`, `+0x14`) | none | `this` (`RGE_Master_Doppleganger_Object*`, ECX) |
| `004513B0` | `make_new_master` | none | none | `this` (`RGE_Master_Doppleganger_Object*`, ECX) |
| `00451420` | `copy_obj` | `source` (`RGE_Master_Static_Object*`, `+0x4`) | none | `this` (`RGE_Master_Doppleganger_Object*`, ECX) |
| `00451430` | `save` | `outfile` (`int`, `+0x4`) | none | `this` (`RGE_Master_Doppleganger_Object*`, ECX) |

The scalar deleting destructor at `00451120` is compiler-generated and has no
source body in this module. It was not changed.

## Recovered names

The following definition names now match the procedure-scoped PDB records.
The call arguments and declaration order remain unchanged.

- `004510C0`: `param_1` became `other_object`; `param_2` became `do_setup`.
- `00451140`: `param_1` became `infile`; `param_2` became `sprites`;
  `param_3` became `sounds`; `param_4` became `do_setup`.
- `004511B0`: `param_1` became `infile`; `param_2` became `sprites`;
  `param_3` became `sounds`; `param_4` became `in_id`; `param_5` became
  `do_setup`.
- `00451230`: `param_1` became `other_object`.
- `00451250`: `param_1` became `infile`; `param_2` became `sprites`;
  `param_3` became `sounds`.
- `00451280`: `param_1` became `infile`; `param_2` became `sprites`;
  `param_3` became `sounds`; `param_4` became `in_id`.
- `004512D0`: `param_1` became `owner`; `param_2` became `x`;
  `param_3` became `y`; `param_4` became `z`; `param_5` became
  `obj_to_dopple`.
- `00451420`: `param_1` became `source`.
- `00451430`: `param_1` became `outfile`.

The destructor and `make_new_master` have no parameters to rename. These names
are recovered PDB names, not inferred cleanup names. The PDB's `infile` name for
the `int` overloads was preserved even though the type is an object ID there.

The local `recycled` in `004512D0` was already a descriptive source name. The
PDB has no source-local record for it, so I did not claim it as a recovered name
or change its declaration. No new inferred names were added. No reused stack
slot created an uncertain parameter mapping.

## Constants, comments, and resources

No constant replacement was made. The original assembly stores `0x19` into
`master_type` at `0045123D`, `00451269`, and `004512A3`. It stores `3` into
`fog_flag` at `00451241`, and stores `1` into `recyclable` at `004512A7`.
Those literals remain unchanged because no shared symbol with the same proved
meaning was found. The setup tests, allocation flag, and all constructor values
also remain unchanged.

No comment was added. The existing code does not need a comment for its direct
constructor, setup, recycling, copy, or save flow.

This module has no resource lookup or resource-ID use. No resource extraction,
resource mapping, or shared resource-ID request is needed.

## Code-generation, layout, and symbol risks

The source change only substitutes parameter identifiers and updates their uses.
It does not change types, casts, scopes, declaration order, storage, evaluation
order, control flow, literals, calls, class layout, or public signatures. It
does not change an ABI symbol or direct call target. The source keeps its
explicit `this->` expressions and existing C-style casts. No assembly, wrapper,
helper, or structural rewrite was added.

Parameter names can affect debug records, but they do not affect the function
ABI. Generated code, program data, relocations, and call-target identity remain
unvalidated until the final validation stage.

## Requests

No change is requested from the owner of `include/m_dg_obj.h`. The header keeps
unnamed declarations, and the cleaned definition names are valid without a
header change. No resource or shared declaration request is pending.

## Validation status

I reviewed the complete source diff and ran `git diff --check`.
Compilation, matching, audits, and tests were not run. Builds and game commands
were also not run, as required for this cleanup phase.
