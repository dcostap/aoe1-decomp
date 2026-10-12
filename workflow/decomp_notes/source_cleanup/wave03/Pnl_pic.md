# Source cleanup report: `src/Pnl_pic.cpp`

## Delivery and scope

- Module: `src/Pnl_pic.cpp`.
- Owner: owner 18, worker slot 158.
- Branch: `cleanup/staging-20260915-158`.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final source commit: `6e1861891331fb28e2b2d3f56b25f60be0d7fab3`.
- Changed files:
  - `src/Pnl_pic.cpp`
  - `workflow/decomp_notes/source_cleanup/wave03/Pnl_pic.md`
- Header read only: `include/pnl_pic.h`.
- Registry: `config/functions/src/Pnl_pic.cpp.json`.
- Registry build flags: `gx`.
- Source SHA-256 before cleanup: `7f050773f632a3216bcc329238f55510fda3f62484f39de3cbc665d6e47e415e`.
- Source SHA-256 after cleanup: `46797dfcfff1cc0ec1eed3e0b49211f89b7d934a8525a52e2650b33ac60b963a`.

The source keeps seven registry procedures in source order. The cleanup
restores PDB names, replaces one proven enum value, and applies 1TBS braces.
It keeps types, scopes, storage, statements, calls, literals, and source order.

## Evidence checked

The registry-selected procedures are in
`C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/Pnl_pic.cpp.json`.
It marks all seven procedures as `matching`:

- `0047A1D0` `TPicturePanel::TPicturePanel`
- `0047A250` `TPicturePanel::~TPicturePanel`
- `0047A2A0` `TPicturePanel::setup`
- `0047A3A0` `TPicturePanel::set_picture`
- `0047A3E0` `TPicturePanel::load_pic`
- `0047A5B0` `TPicturePanel::free_pic`
- `0047A630` `TPicturePanel::draw`

I inspected the matching original packets:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A1D0_TPicturePanel.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A250_TPicturePanel.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A2A0_setup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A3A0_set_picture.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A3E0_load_pic.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A5B0_free_pic.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A630_draw.txt`

The procedure-scoped PDB records are in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Its SHA-256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
Every assigned procedure has a PDB `this` register in `ecx`, typed as
`TPicturePanel*`. The original PDB is
`C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`.
Its SHA-256 is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.

The original executable is
`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup executable is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`.
Its SHA-256 is
`492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
The preserved pre-cleanup object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/Pnl_pic.obj`.
Its SHA-256 is
`68de0775fd6ac3a90157b459551571fbda665bcfc4abcb771c09dab727e02247`.

## Original-name recovery coverage

The PDB records establish the following names:

| VA | Function | PDB records and source result |
| --- | --- | --- |
| `0047A1D0` | `TPicturePanel::TPicturePanel` | Only `this` is recorded. No source rename was possible. |
| `0047A250` | `TPicturePanel::~TPicturePanel` | Only `this` is recorded. No source rename was possible. |
| `0047A2A0` | `setup` | Recovered all parameters: `render_area_in`, `parent_panel_in`, `x_in`, `y_in`, `wid_in`, `hgt_in`, `pic_name_in`, `res_id_in`, `size_from_pic_in`, and `keep_loaded_in`. Recovered locals `shape_wid` and `shape_hgt`. |
| `0047A3A0` | `set_picture` | Recovered `pic_in` and `res_id_in`. |
| `0047A3E0` | `load_pic` | PDB local `file_name` already matched the source. |
| `0047A5B0` | `free_pic` | No stack names beyond `this`. No source rename was possible. |
| `0047A630` | `draw` | No stack names beyond `this`. No source rename was possible. |

For `0047A2A0`, the PDB types are three pointer arguments, five `long`
arguments, and two `int` arguments. The local records are `short`
`shape_wid` and `shape_hgt`. Their PDB homes overlap dead parameter homes
used for `res_id_in` and `size_from_pic_in`. The source keeps both separate
short declarations and does not combine or remap them.

The adjacent compiler-generated scalar deleting destructor at `0047A230`
has PDB parameter `__flags`. It has no source body in this module and was not
edited.

### Renamed parameters and locals

- `0047A2A0`: `p1` -> `render_area_in`; `p2` -> `parent_panel_in`;
  `p3` -> `x_in`; `p4` -> `y_in`; `p5` -> `wid_in`; `p6` -> `hgt_in`;
  `p7` -> `pic_name_in`; `p8` -> `res_id_in`; `p9` -> `size_from_pic_in`;
  `p10` -> `keep_loaded_in`.
- `0047A2A0`: `sw` -> `shape_wid`; `sh` -> `shape_hgt`.
- `0047A3A0`: `new_shape` -> `pic_in`; `new_res_id` -> `res_id_in`.

The names above are recovered originals from the procedure-scoped PDB. No
new descriptive name was added. Existing `old_shape` in `load_pic` and the
local aliases `p` and `s` in `free_pic` have no distinct scoped PDB records.
I retained them instead of forcing a mapping from optimized or reused slots.

## Constants, resources, and comments

`draw` now compares `this->pic_type` with `Picture` instead of numeric `0`.
`Picture` is the existing `TPicturePanel::PictureType` enumerator in
`C:/Projects/my_decomps/aoe1_attempt3/include/pnl_pic.h`, with value `0`.
The original packet types `pic_type` as `PictureType`; the constructor and
`load_pic` packets also use the `Picture` and `Shape` values. This change
preserves the value and effective enum comparison type.

No language resource ID or string lookup occurs in this module. The `res_id`
argument remains a numeric shape resource argument. No resource ID was
investigated, so no resource DLL extraction or mapping is needed. No source
comment was added or removed.

## Type, layout, code-generation, and symbol review

The edits change identifier spelling, opening-brace placement, and one enum
spelling only. They do not change types, declaration points, scopes, storage
duration, control flow, casts, explicit `this->` access, call targets,
relocations, function boundaries, virtual slots, public symbols, class layout,
or calling conventions.

The recovered local names preserve the existing short declarations and the
original stack-slot reuse. The `Picture` enumerator has the same value as the
replaced `0`. Identifier and brace changes can affect debug line records, and
this enum cleanup needs final generated-output checks. Those checks were
deferred.

## Header requests and unresolved questions

I did not edit the paired owner header
`C:/Projects/my_decomps/aoe1_attempt3/include/pnl_pic.h`. Owner 18 may add
these PDB-proven parameter names without changing types, order, access, or
symbols:

```cpp
long setup(TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in, long wid_in, long hgt_in, char* pic_name_in, long res_id_in, int size_from_pic_in, int keep_loaded_in);
void set_picture(TShape* pic_in, long res_id_in);
```

No request targets `include/resource_ids.h`, `include/game_globals.h`, or
another shared file. The unresolved source-name questions are the original
spellings of `old_shape`, `p`, and `s`; their scoped PDB records are absent.

Compilation, matching, audits, and tests were not run. No build, compiler,
game, or runtime command was run. Only evidence extraction, Git review, and
`git diff --check` were run. Generated code, program data, relocations, and
call targets remain unvalidated.
