# Source cleanup report: `com_err.cpp`

## Delivery

- Module: `src/com_err.cpp`
- Branch: `cleanup/staging-20260915-102`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `a7d93f5c181cd5be30a60dd5c81756d8faf9d394`
- Changed files:
  - `src/com_err.cpp`
  - `decomp_notes/source_cleanup/wave02/com_err.md`
- Source SHA-256 after cleanup: `c81e7fd37a67d2e4554f3fcf7f7d7df48eb8e2decfd442667fbb85f03979500d`
- The source commit changes parameter names only.

The worktree was clean at the assigned base. The source registry is
`config/functions/src/com_err.cpp.json`. It assigns the default build flags and
four matching functions to this module. The report owns only the assigned
source and report paths. `include/com_err.h` was read but not edited.

## Evidence inspected

I ran the evidence-tool help commands before use. This included
`query_abi.py --help`, `source_listing.py --help`, `target_dossier.py --help`,
`function_diagnostics.py --help`, and `inspect_pe_strings.py --help`.

I queried every registry function with `query_abi.py --json --va`. The tool
loaded the procedure-scoped records from the absolute path
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
That file has SHA-256
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.

I inspected the complete packets selected by the source registry:

- `inventory/functions/0042/00424E40_RGE_Comm_Error.txt`
  (`f557a56a26932c5d7353f45ae4e8fe5d6a6b064903b75b1147b4ebff33ed75ac`)
- `inventory/functions/0042/00424E60_NotifyWindowParam.txt`
  (`651239d20c0bcf081fd39eccb85d708bfe59e43dcf2c0b1f623799742c89a298`)
- `inventory/functions/0042/00424EA0_RGE_Comm_Error.txt`
  (`2366e6fe9e3fcdbef6b715768044976f150596c541e4fc7b93fffa59aa326123`)
- `inventory/functions/0042/00424EB0_ShowReturn.txt`
  (`cfea47648ae9faf3c012cac81b061c4f212cfc77597ec95e9f5898671fdef356`)

The packet hashes above are SHA-256 values from the absolute main-root
inventory. The original executable behavior-oracle path is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The source registry file has SHA-256
`256cc0612ec27690b430d2e5d40fae9b65d8017d843dc972d41ef90f720662da`.

## Original-name recovery

All four assigned registry functions were inspected. Every procedure has a
PDB `this` register record in `ecx` with type `RGE_Comm_Error*`. No procedure
has a named local or function-static record. The PDB source path is
`C:\msdev\work\age1_x1\com_err.cpp`.

| VA | Function | Procedure-scoped PDB records | Source result |
| --- | --- | --- | --- |
| `00424E40` | `RGE_Comm_Error::RGE_Comm_Error` | Stack `Host` at `+0x4`; register `this` in `ecx`. | `param` became recovered `Host`; the assignment now uses `Host`. |
| `00424E60` | `RGE_Comm_Error::NotifyWindowParam` | Stack `msg` at `+0x4` and `lparam` at `+0x8`; register `this` in `ecx`. | `msg` already matched. `param` became recovered `lparam` in both calls. |
| `00424EA0` | `RGE_Comm_Error::~RGE_Comm_Error` | No stack record; register `this` in `ecx`. | No source rename. |
| `00424EB0` | `RGE_Comm_Error::ShowReturn` | Stack `hr` at `+0x4` and `Text` at `+0x8`; register `this` in `ecx`. | `code` became recovered `hr`. `context` became recovered `Text` in every use. |

The PDB records and packet line maps establish all source parameter mappings.
The source has no unresolved parameter or local mapping for these records.
The class members `HostHWND` and `LastReportedError` remain unchanged. The
procedure-scoped records do not provide member-field names for this module.
No invented name was added. All changed names are recovered PDB spellings,
including the mixed-case `Host` and `Text` names.

The constructor packet covers `00424E40-00424E51`. The notify packet covers
`00424E60-00424E94`. The destructor packet covers `00424EA0-00424EA0`. The
`ShowReturn` packet covers `00424EB0-00425737`. The source keeps these
function boundaries and source order unchanged.

## Constants, resources, and comments

No numeric constant changed. Existing `COMMMESSAGES` symbols remain in use.
The `0x400` message value remains unchanged. The pinned VC5 SDK header
`C:/Program Files (x86)/DevStudio/VC/Include/WINUSER.H` defines `WM_USER` as
`0x0400` at line 1498, but this cleanup does not replace the existing literal.
The explicit `(long)` casts and the HRESULT and DirectPlay values in
`ShowReturn` remain unchanged. No new symbol was introduced without a proved
source declaration and type.

This module has no resource lookup. No language DLL was used, and no resource
ID mapping or resource header request is needed. The runtime resource paths
were not used because this source does not access a resource namespace.

No source comment was added. The existing comment before `ShowReturn` remains.
The `ShowReturn` packet shows the threshold tree, empty non-match arms, and
shared default fallthrough. The comment records that observed layout without
changing the handler.

## Header and shared-file requests

Owner 12 owns `include/com_err.h`. The declaration parameter names remain
unchanged in that header. Owner 12 may apply this declaration-only request:

```cpp
RGE_Comm_Error(void* Host);
void NotifyWindowParam(COMMMESSAGES msg, long lparam);
void ShowReturn(long hr, char* Text);
```

This request changes no type, calling convention, symbol, layout, or virtual
slot. There is no root-owned header request. There is no shared resource-ID
request. The unrelated `NotifyWindowParam` declaration in
`include/com_hand.h` was not changed or requested from this module.

## Code-generation and scope review

The source edit renames four parameters and updates their uses. It does not
change a type, declaration scope, storage duration, initialization point,
expression, evaluation order, control flow, call target, literal, relocation,
function boundary, or ABI symbol. It adds no helper, wrapper, layout, or
assembly. The source retains the explicit `this->` uses and the existing
1TBS layout.

The source diff and complete assigned-file scope were reviewed. `git diff
--check` passed.

Compilation, matching, audits, and tests were not run. No build, compiler
check, executable validation, game, or runtime harness was run.
