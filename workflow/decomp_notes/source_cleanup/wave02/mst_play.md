# Source cleanup: `mst_play.cpp`

## Delivery

- Module: `src/mst_play.cpp`
- Branch: `cleanup/staging-20260915-77`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `404c5ae46a6d9cdeccaabde8fdccc474bba9071e`
- Assigned header: `include/mst_play.h` (read only; not changed)
- Registry: `config/functions/src/mst_play.cpp.json`
- PDB source: `C:\\msdev\\work\\age1_x1\\mst_play.cpp`
- PDB evidence: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- Inventory evidence: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0046/`

## Changed files

- `src/mst_play.cpp`
- `workflow/decomp_notes/source_cleanup/wave02/mst_play.md`

The source commit restores supported procedure names and applies 1TBS brace
placement. It keeps types, scopes, storage, statements, calls, constants, and
source order. It adds no executable statement or comment.

## PDB recovery coverage

The registry selects eight normal functions. I inspected every selected
function packet and every scoped PDB stack and register record. Each function
has a `this` record in `ecx` with type `RGE_Master_Player*`.

| VA | Function | PDB records and result |
| --- | --- | --- |
| `00460FD0` | `RGE_Master_Player::RGE_Master_Player(FILE*)` | PDB parameters: `infile` (`_iobuf*`). PDB locals: `temp_count` (`short`), `temp_culture` (`short`), `temp_amount` (`float`), and `temp_index` (`short`). The source now maps these names to the existing declarations by type and use. |
| `004610C0` | `RGE_Master_Player::RGE_Master_Player(int)` | PDB parameter `infile` (`int`) replaces `fd`. No other stack local record. |
| `00461150` | `RGE_Master_Player::~RGE_Master_Player()` | No stack records. The source keeps the existing `num`, `i`, and `obj` locals. |
| `004611D0` | `RGE_Master_Player::finish_init` | PDB parameters: `infile` (`int`), `sprites` (`RGE_Sprite**`), and `sounds` (`RGE_Sound**`). PDB local `obj_type` (`unsigned char`) shares an optimized stack home with a parameter record and conflicts with the source `int temp` type. The source keeps `temp` and its scope and type. |
| `00461270` | `RGE_Master_Player::load_master_object` | PDB parameters: `infile` (`int`), `obj_type` (`unsigned char`), `sprites`, `sounds`, and `index` (`short`). The source restores `infile` from `id` and `obj_type` from `type`; the pointer and index names already matched. |
| `00461530` | `RGE_Master_Player::create_master_object_space` | PDB parameter `count` (`short`) already matched. No other stack local record. |
| `00461560` | `RGE_Master_Player::load_object` | PDB parameters: `infile` (`_iobuf*`), `obj_type` (`unsigned char`), `sprites`, `sounds`, and `index` (`short`). The source restores `infile` from `file` and `obj_type` from `type`; the other names already matched. |
| `00461840` | `RGE_Master_Player::save` | PDB parameter `outfile` (`int`) replaces `fd`. The source keeps local `i`; no other stack local record. |

The nearby `004610A0` scalar deleting destructor is compiler-generated and has
no handwritten source owner. The `004614D9` inventory entry is padding-only.
Neither entry was edited.

## Recovered and unresolved names

The following names are recovered original spellings from the scoped PDB:
`infile`, `outfile`, `temp_count`, `temp_culture`, `temp_amount`,
`temp_index`, and `obj_type` where the source mapping is type-safe.

The `finish_init` PDB `obj_type` record is not applied. Its stack offset is
reused, and its PDB type is `unsigned char` while the existing source local is
`int temp`. The source keeps that declaration unchanged. This is an unresolved
storage and type mapping, not a recovered rename.

Existing names without a safe scoped PDB mapping remain unchanged. These
include `num`, `i`, `obj`, and `temp`. They are not claimed as original names.
Loop locals have no scoped PDB records in this module.

## Constants, resources, and comments

- No numeric constant, enum, or symbolic constant changed.
- This module has no resource lookup or resource ID expression.
- No resource extraction was needed. No resource header request exists.
- No source comment was added. Existing comments remain unchanged.

## Header request

Owner 09 controls `include/mst_play.h`; I did not edit it. The header declares
these parameter names with older names. The owner may apply these name-only
updates without changing types or ABI:

```cpp
RGE_Master_Player(FILE* infile);
RGE_Master_Player(int infile);
virtual void finish_init(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
virtual void load_master_object(int infile, unsigned char obj_type,
                                RGE_Sprite** sprites, RGE_Sound** sounds,
                                short index);
virtual void load_object(FILE* infile, unsigned char obj_type,
                         RGE_Sprite** sprites, RGE_Sound** sounds, short index);
virtual void save(int outfile);
```

Evidence is the procedure-scoped PDB records listed above and the eight
registry packets. `count` already matches the header declaration.

## Code-generation and behavior-sensitive points

- All changed source tokens are identifier renames or brace placement.
- The first constructor swaps names among existing `short` and `float`
  declarations. It does not change declaration order, types, or storage.
- The unresolved `finish_init` local keeps its original `int` type, scope, and
  declaration point because the PDB record has a reused stack home and a type
  conflict.
- No cast, expression, evaluation order, control flow, literal, virtual slot,
  call target, relocation, function boundary, layout, or ABI symbol changed.
- 1TBS changes move opening braces only. PDB line records can change after
  formatting; no byte-equality claim is made here.
- The durable checkpoint `workflow/decomp_notes/mst_play.md` records the prior exact
  composition result for all eight owners. No executable check was run for
  this cleanup.

## Validation and limits

I reviewed the complete source diff and ran `git diff --check`.

Compilation, matching, audits, and tests were not run, as required for this
cleanup wave. No build, compiler, game, or runtime validation was run.
