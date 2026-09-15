# `misl_obj.cpp` cleanup report

## Scope and commits

- Module: `src/misl_obj.cpp`
- Header read: `include/misl_obj.h`
- Header owner: owner 09
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Source cleanup commit: `f441095319a3eaf0afb70bffe8efb9f307b7b988`
- Changed files: `src/misl_obj.cpp` and this report.
- No header, registry, or shared resource file changed.

The source registry is `config/functions/src/misl_obj.cpp.json`. It selects eleven
normal functions at `0045A740` through `0045AB20`. The PDB source path is
`C:\\msdev\\work\\age1_x1\\misl_obj.cpp`.

Evidence paths were the absolute main-root files under
`C:/Projects/my_decomps/aoe1_attempt3`. I used
`inventory/pdb/scoped_symbols.json`, all eleven selected packets under
`inventory/functions/0045/`, `orig/ghidra_decomp/misl_obj.cpp.decomp`,
and the existing missile-object notes. The scoped-symbol file SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The original executable evidence is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

## Function-by-function PDB coverage

All eleven assigned functions were inspected. This includes every PDB stack
record, local record, and register record. Each function has the implicit PDB
register `this` in `ecx`. No function static records exist.

- `0045A740` `RGE_Missile_Object` has `tobj`, `obj_owner`, `x`, `y`, `z`,
  and `do_setup`. It has no source locals. The source restores `tobj` and
  `obj_owner` from `master` and `player`.
- `0045A800` `RGE_Missile_Object` has `infile`, `gworld`, and `do_setup`.
  The source restores `infile` and `gworld` from `mode` and `world`.
- `0045A870` `setup` has `tobj`, `obj_owner`, `x`, `y`, and `z`. The source
  restores `tobj` and `obj_owner` from `master` and `player`.
- `0045A8A0` `setup` has `infile` and `gworld`. The source restores these
  names from `file` and `world`.
- `0045A900` `rehook` has no stack records. Its `this` record was already
  represented in the source. No name change was needed.
- `0045A910` `save` has `outfile`. The source restores `outfile` from `file`.
- `0045A940` `update` has no stack records. Its `this` record was already
  represented in the source. No name change was needed.
- `0045A950` `init_missile` has `launcher`, `target`, and `in_range`.
  The source restores these names from `target`, `source`, and `range`.
  The PDB types are `RGE_Combat_Object*`, `RGE_Static_Object*`, and `float`.
- `0045A9E0` `init_missile` has `launcher`, `x`, `y`, `z`, and `in_range`.
  The source restores `launcher` and `in_range` from `target` and `range`.
- `0045AA70` `missile_move` has the locals `new_z`, `new_y`, and `new_x`.
  The source already used these PDB spellings. Their unusual stack offsets
  remain unchanged.
- `0045AB20` `make_object_collision_list` has parameter `delta` and locals
  `dy`, `dx`, `map`, `check_list`, `x2`, `x1`, `ry`, `rx`, `ry2`, and `rx2`.
  The source restores `delta` from `extra`, `x1` from `max_x`, `x2` from
  `max_y`, and `check_list` from `list`. The PDB types establish the float,
  map, collision-list, and short categories. The original decompilation's
  four conversion calls support the upper-x and upper-y use of `x1` and `x2`.

Recovered original spellings are `tobj`, `obj_owner`, `infile`, `gworld`,
`outfile`, `launcher`, `target`, `in_range`, `delta`, `x1`, `x2`,
`check_list`, `new_x`, `new_y`, `new_z`, `dx`, `dy`, `rx`, `ry`, `rx2`,
`ry2`, and `map`. The source keeps the PDB mixed style.

The names `min_x`, `min_y`, `row`, `column`, `tile`, `node`, `object`,
`object_master`, and `dz` have no matching scoped PDB record. They remain
concise descriptive names. The PDB does not prove their original spellings.
The compiler reuses storage for `x2` and collision-list state. The source keeps
separate typed variables and does not force a storage alias.

## Constants, resources, comments, and formatting

- No constant changed. The source keeps missile type `0x3C`, save version
  `7.09f`, four-byte I/O widths, and the four `DAT_00570934` through
  `DAT_00570940` globals.
- The `0x3C` type value is also used by the missile master-object module.
  No shared name is proved for this value. The header owner was not asked to
  add one.
- No resource lookup occurs in this module. No resource ID was changed, and
  no resource extraction request is pending.
- No comment was added. The existing code has no comment that needs a change.
- The edit changes identifiers only. It does not change calls, casts, types,
  declaration points, scopes, evaluation order, control flow, or storage.
  Existing braces already follow 1TBS.

## Concerns and requests

Header owner 09 may add recovered parameter names to `include/misl_obj.h`
without changing types or ABI:

```cpp
RGE_Missile_Object(RGE_Master_Combat_Object* tobj, RGE_Player* obj_owner,
                   float x, float y, float z, int do_setup);
RGE_Missile_Object(int infile, RGE_Game_World* gworld, int do_setup);
virtual int setup(RGE_Master_Combat_Object* tobj, RGE_Player* obj_owner,
                  float x, float y, float z);
virtual int setup(int infile, RGE_Game_World* gworld);
virtual void save(int outfile);
void init_missile(RGE_Combat_Object* launcher, RGE_Static_Object* target,
                  float in_range);
void init_missile(RGE_Combat_Object* launcher, float x, float y, float z,
                  float in_range);
```

The source does not request a shared constant or resource declaration. The
unrecorded names listed above remain unresolved. The `x2` storage reuse also
needs no further source mapping without stronger evidence.

Compilation, matching, audits, and tests were not run. Games were not run.
