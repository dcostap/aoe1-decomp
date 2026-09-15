# `src/colorlog.cpp` source-cleanup report

## Delivery and scope

- Module: `src/colorlog.cpp`.
- Owner: owner 22, worker slot 193.
- Branch: `cleanup/staging-20260915-193`.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final source commit: `ccee99a6bc723ba0fbf3a88f3a96113b54bc6858`.
- Changed files:
  - `src/colorlog.cpp`
  - `decomp_notes/source_cleanup/wave03/colorlog.md`
- Header read only: `include/colorlog.h`.
- Registry: `config/functions/src/colorlog.cpp.json`.
- Registry build flags: `default`, from `config/flags/default.rsp`.
- Source SHA-256 before cleanup:
  `9ed359f182627c8f9e2932cb8908249d6be237d1647be731dbf8f80beb837bb9`.
- Source SHA-256 after cleanup:
  `245c041a3384880df6d6a93c8c9aa45fe828768161299fbef97f7a9ffe491641`.

The module has one handwritten function. The cleanup restores three original
PDB parameter names and replaces one proven DirectDraw flag expression. It does
not change declarations, types, calls, statement order, or storage.

## Evidence identity

- Original executable:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
  SHA-256:
  `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Preserved baseline report:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`.
  SHA-256:
  `fddd62868626e21ec7282183fa1cf84ad5b0b14fc719c8830a266d6ed0f155b3`.
  Its `src/colorlog.cpp` input record has the pre-cleanup source hash listed
  above and selects the registry route with `default` flags.
- Procedure-scoped PDB inventory:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
  SHA-256:
  `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
- Selected original function packet:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00424810_color_log.txt`.
  SHA-256:
  `f540e75bb1a092e06f79bd86813d1c70eab5e6ef9814988a775b8c46a232bed5`.
- PDB type dumps reviewed:
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/RGE_Base_Game.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/TDrawSystem.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/TDrawArea.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/DDBLTFX.txt`
- Pinned SDK header reviewed:
  `C:/Program Files (x86)/DevStudio/VC/Include/DDRAW.H`.

The packet identifies `color_log` at `00424810`, with source lines 13 to 68,
body range `00424810-004249C9`, size 442 bytes, and `__cdecl` calling
convention. It shows one `ClientToScreen` call and four virtual `Blt` calls.
The assembly and line records remain the behavior evidence. The prior durable
module note records the same source owner and member-offset checks.

## Original-name review coverage

I reviewed every configured function in the source registry. The registry has
one entry, `00424810`, with symbol `?color_log@@YAXEEH@Z` and status
`matching`. The selected packet and the scoped PDB record both identify the
same function.

The scoped PDB record has these stack symbols:

- `c1` at `+0x4`, type `unsigned char`.
- `c2` at `+0x8`, type `unsigned char`.
- `pos` at `+0xC`, type `int`.
- `point` at `-0x6C`, type `tagPOINT`.
- `back_dest` at `-0x7C`, type `tagRECT`.
- `ddbltfx` at `-0x64`, type `_DDBLTFX`.
- `scr_dest` at `-0x8C`, type `tagRECT`.

The PDB has no register symbols and no function statics for this procedure.
The source now uses the recovered original names `c1`, `c2`, and `pos` for the
three former `param_*` parameters. The existing local declarations already
use the recovered PDB spellings for `point`, `back_dest`, `ddbltfx`, and
`scr_dest`.

The locals `game`, `sys`, and `offset` have no PDB declaration records. Their
names remain concise descriptive cleanup names. I did not map them from
reused registers or stack slots. No source declaration mapping remains that
requires a header edit. The public header keeps its existing parameter names;
this source-only definition rename does not change its type or ABI.

## Constants, resources, comments, and formatting

The four former `0x1000400` Blt flag arguments now use
`DDBLT_WAIT | DDBLT_COLORFILL`. The pinned header proves:

- `DDBLT_COLORFILL` is `0x00000400l` at `DDRAW.H:2025`.
- `DDBLT_WAIT` is `0x01000000l` at `DDRAW.H:2112`.
- `IDirectDrawSurface::Blt` accepts a `DWORD` flags argument at `DDRAW.H:555`.

Their OR value is exactly `0x01000400`, the value shown in the original
packet. The expression remains an inline constant expression. The source keeps
`ddbltfx.dwSize = 100`; the reviewed `_DDBLTFX` type dump records size `0x64`
(100 bytes), but replacing this literal with `sizeof` is outside this cleanup
and could alter generated output. The source also keeps the numeric screen
mode, rectangle sizes, and position scale because no shared declaration proves
those meanings.

No resource ID occurs in this module. No resource DLL was queried. Therefore,
no resource hash, language, text, lookup path, or shared resource mapping
applies. No source comment was added. Existing comments and source order stay
unchanged. Function braces already use 1TBS style.

## Code-generation effects and unresolved items

Parameter renames do not change the decorated symbol, calling convention,
types, stack layout, or generated operations. The SDK macros expand to the
same flag bits as the replaced literal. The macro operands have `long` suffixes,
while the old literal had `int` type; the `Blt` declaration converts the result
to `DWORD`. This source type detail and any debug-record effect remain
unvalidated because compilation is deferred.

The cleanup keeps all guards, casts, declaration order, evaluation order,
virtual call targets, four Blt operations, one `ClientToScreen` operation,
rectangle updates, and color assignments unchanged. It adds no helper, layout,
assembly, macro context, or public symbol. The registry's existing `matching`
status is not revalidated by this work.

The PDB does not prove original names for `game`, `sys`, or `offset`. No
uncertain mapping was forced. There are no unresolved shared declarations and
no shared-file requests.

## Validation status

I ran evidence inspection, SHA-256 checks, and a complete Git diff review.
I did not run compilation, matching, audits, or tests. I did not run any
compiler, build, matching check, audit, test, or game command. Final generated
code remains unvalidated until the final validation stage.
