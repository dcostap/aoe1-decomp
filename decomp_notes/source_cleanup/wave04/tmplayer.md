# Source cleanup: `tmplayer.cpp`

## Delivery

- Module: `src/tmplayer.cpp`
- Branch: `cleanup/staging-20260915-220`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `a540c0409504a58501d7fe0a97b87e7b5e68c52f`
- Assigned header: `include/tmplayer.h` (read only; not changed)
- Registry: `config/functions/src/tmplayer.cpp.json` (read only; not changed)
- PDB source: `C:\\msdev\\work\\age1_x1\\tmplayer.cpp`
- PDB evidence: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- Function evidence: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/`
- Original PDB: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/age1_x1.pdb`
- Original executable evidence: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

## Changed files

- `src/tmplayer.cpp`
- `decomp_notes/source_cleanup/wave04/tmplayer.md`

The source now uses the original scoped PDB parameter names. It also uses 1TBS
braces and keeps short calls on one line. It keeps types, scopes, storage,
statements, calls, constants, and source order.

## PDB recovery coverage

The registry selects five source-owned functions. I inspected each procedure's
scoped PDB stack and register records. The PDB records use `this` in `ecx` for
each member function.

| VA | Function | Scoped PDB records and result |
| --- | --- | --- |
| `005117C0` | `TRIBE_Master_Player::TRIBE_Master_Player(FILE*)` | Stack parameter `infile` at `+0x4` (`_iobuf*`). Register `this` in `ecx`. No other PDB local or register record. |
| `00511800` | `TRIBE_Master_Player::TRIBE_Master_Player(int)` | Stack parameter `infile` at `+0x4` (`int`). Register `this` in `ecx`. No other PDB local or register record. |
| `00511820` | `TRIBE_Master_Player::~TRIBE_Master_Player()` | No stack record. Register `this` in `ecx`. No local record. |
| `00511830` | `TRIBE_Master_Player::load_master_object` | Stack parameters `infile` (`int`), `obj_type` (`unsigned char`), `sprites` (`RGE_Sprite**`), `sounds` (`RGE_Sound**`), and `index` (`short`) at `+0x4` through `+0x14`. Register `this` in `ecx`. No other PDB local or register record. |
| `00511990` | `TRIBE_Master_Player::load_object` | Stack parameters `infile` (`_iobuf*`), `obj_type` (`unsigned char`), `sprites` (`RGE_Sprite**`), `sounds` (`RGE_Sound**`), and `index` (`short`) at `+0x4` through `+0x14`. Register `this` in `ecx`. No other PDB local or register record. |

The PDB also contains `005117E0`, the scalar deleting destructor. It has a
stack `__flags` (`unsigned int`) and register `this`, but it is compiler
created and has no handwritten source body in this module.

The Ghidra packets list exception bookkeeping homes such as `local_4` and
`local_c` for the two loading functions. The scoped PDB has no source-local
records for those homes. The source keeps its existing `object` declaration
and does not force a mapping for compiler bookkeeping.

## Recovered and unresolved names

Recovered original parameter names:

- `infile` replaces `file` in the file constructor.
- `infile` replaces `player` in the integer constructor.
- `infile` replaces `id` in `load_master_object`.
- `obj_type` replaces `object_type` in both loading functions.
- `sprites`, `sounds`, and `index` already matched the PDB records.

The PDB proves these mappings by procedure VA, stack offset, and type. No local
name was recovered. `object` remains an existing source name without a scoped
PDB record. No invented name was added.

The assigned header has unnamed parameter declarations. It needs no name-only
header change. No shared declaration request is pending.

## Constants, resources, and comments evidence

- The object tags `'F'`, `'P'`, and `'Z'` remain unchanged. No existing symbol
  proves a better shared name for these local dispatch tags.
- The constructor and allocation value `1` remain unchanged. No constant change
  was supported.
- This module has no resource lookup or resource ID expression.
- No resource extraction was needed. No resource mapping request exists.
- No source comment was added.

## Code-generation and behavior-sensitive points

- The source changes are parameter renames, brace placement, and whitespace.
- No cast, expression, evaluation order, control flow, literal, call target,
  relocation, function boundary, layout, virtual slot, or ABI symbol changed.
- The PDB line records can change after the formatting pass. Compilation and
  matching were deferred, so this report makes no byte-equality claim.
- The compiler-created scalar deleting destructor was not edited.

## Validation and limits

I reviewed the complete diff and ran `git diff --check`.

Compilation, matching, audits, and tests were not run, as required for this
cleanup wave. No build, compiler, game, or runtime validation was run.
