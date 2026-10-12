# `tm_tre_o.cpp` cleanup report

## Delivery

- Module: `src/tm_tre_o.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `2a8e3fafe` (the full hash is recorded below)
- Final source commit full hash: `2a8e3fafee1050bd115c6fbd7a12264d208e401d`
- Changed files:
  - `src/tm_tre_o.cpp`
  - `workflow/decomp_notes/source_cleanup/wave02/tm_tre_o.md`
- No header changed. `include/tm_tre_o.h` remains owner 09's file.

The source commit contains only the assigned source. This report is a later
report-only commit. The final branch hash is reported with the delivery.

## PDB coverage

The source registry selects five normal functions. The scoped PDB record covers
all five functions. Each record has no function statics and no PDB local
declarations. Each record has the listed `this` register in `ecx`.

| VA | Function | PDB parameters | PDB source lines |
| --- | --- | --- | --- |
| `0050F180` | `TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object` | `other_object` (`TRIBE_Master_Tree_Object*`), `do_setup` (`int`) | 21-27 |
| `0050F220` | `TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object` | `infile` (`int`), `sprites` (`RGE_Sprite**`), `sounds` (`RGE_Sound**`), `do_setup` (`int`) | 32-38 |
| `0050F2A0` | `TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object` | `infile` (`_iobuf*`), `sprites` (`RGE_Sprite**`), `sounds` (`RGE_Sound**`), `in_id` (`short`), `do_setup` (`int`) | 43-49 |
| `0050F320` | `TRIBE_Master_Tree_Object::make_new_obj` | `owner` (`RGE_Player*`), `x` (`float`), `y` (`float`), `z` (`float`) | 53-55 |
| `0050F3A0` | `TRIBE_Master_Tree_Object::make_new_master` | none | 59-61 |

The two compiler-generated destructor entries were also inspected:

- `0050F1F0` has `__flags` (`unsigned int`) at stack offset `+0x4`.
- `0050F210` has no stack parameter.
- Both entries have `this` in `ecx` and no PDB locals.
- Neither entry has a handwritten source owner in the registry.

The decompiler's `local_*` names describe exception-handler stack slots. They
are not PDB source declarations. The cleanup leaves those slots unchanged.

## Name recovery

The cleanup restores these exact PDB spellings in the source definition:

- `source` to `other_object` at `0050F180`.
- `id` to `infile` at `0050F220`.
- `file` to `infile` at `0050F2A0`.
- `id` to `in_id` at `0050F2A0`.
- `player` to `owner` at `0050F320`.

The source already used the PDB spellings `do_setup`, `sprites`, `sounds`,
`x`, `y`, and `z`. No new descriptive names were invented. No reused stack
slot mapping remains uncertain for these parameters.

## Source changes

The cleanup also applies 1TBS braces to all five definitions. It preserves
types, casts, declarations, scopes, statements, evaluation order, calls,
literals, and virtual symbols.

The source registry remains unchanged. It records `gx` flags and matching
status for all five normal functions.

## Constants, resources, and comments

The three assignments to `master_type = 0x5A` remain numeric. The original
packets write byte `0x5A` at `this + 0x4` at `0050F1C8`, `0050F276`, and
`0050F300`. `include/m_s_obj.h` declares `master_type` as `unsigned char`.
No established symbolic name exists for this tree master type.

The `0` setup flags, `1` constructor flags, and allocation sizes remain
unchanged. No resource lookup exists in this module. No resource ID request
is needed. No comment was added because the code has no proven lifetime,
unit, sentinel, or compatibility fact that needs a nearby explanation.

## Evidence

The source registry and scoped PDB records were selected through these paths:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-81/config/functions/src/tm_tre_o.cpp.json`
  - SHA256 `046aaf0709b3ea233fde863492941aa40d81ccd0424cc416908383a02c40c518`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  - SHA256 `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`

The five selected inventory packets have these hashes:

- `inventory/functions/0050/0050F180_TRIBE_Master_Tree_Object.txt`: `b42649c77fc4f3ca504fa14e0f95d5b08146cccfa74b6ccd111c517be962de7e`
- `inventory/functions/0050/0050F220_TRIBE_Master_Tree_Object.txt`: `afb315915d9c719b26ee3213d0e1c2297a5be2ad4cd2269a14e5b73036029476`
- `inventory/functions/0050/0050F2A0_TRIBE_Master_Tree_Object.txt`: `c799dbeb7b08edefecde2979df1cf994153ff98a8670025906bfec943b68c18f`
- `inventory/functions/0050/0050F320_make_new_obj.txt`: `5d07bf734f518ab5b35781754f14359679ae1cc13bf64bbaa146ada1e7762d68`
- `inventory/functions/0050/0050F3A0_make_new_master.txt`: `8c6e8487a3d91d3db0707fe0579bf73f8a001f305505bf551379b7a91a114c41`

The original executable evidence is:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`
  - SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The preserved pre-cleanup outputs are:

- `build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  - SHA256 `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`
- `build/source-cleanup-20260915/preparation/baseline-build/tm_tre_o.obj`
  - SHA256 `0b9a62f164fa1fa21aca8d0ecfcbd59a7dc387e54fdf8319c41d9b69061ca258`

## Code-generation effects

Parameter names and brace placement can change debug names or line records.
They do not change the compiler-facing types or the ABI. No optimized code
comparison was run. The `gx` flags are `/nologo /c /O2 /Oy /GX`.

## Shared requests and open questions

Owner 09 should update `include/tm_tre_o.h` parameter names to match the PDB:

```cpp
TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* other_object, int do_setup);
TRIBE_Master_Tree_Object(int infile, RGE_Sprite** sprites,
                         RGE_Sound** sounds, int do_setup);
TRIBE_Master_Tree_Object(FILE* infile, RGE_Sprite** sprites,
                         RGE_Sound** sounds, short in_id, int do_setup);
virtual RGE_Static_Object* make_new_obj(RGE_Player* owner,
                                        float x, float y, float z);
```

This request changes names only. It does not change types, layout, values, or
symbols. No other shared request or unresolved question remains.

## Validation status

I inspected the source registry, all assigned PDB scopes, all selected packets,
the original executable reference, and the preserved baseline hashes. I also
reviewed the complete Git diff.

Compilation, matching, audits, and tests were not run. Builds, games, and
runtime resource extraction were not run.
