# `m_mo_obj.cpp` cleanup report

## Delivery

- Source: `src/m_mo_obj.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Head commit for the source cleanup: `d629aef2d27fc767934b4ec04acdc05ba50cf962`
- Correction source head before this report commit: `caa4b29540d24510b1922e9e000926aeffe59066`
- Branch: `cleanup/staging-20260915-70`
- Worker slot: 70
- Changed files:
  - `src/m_mo_obj.cpp`
  - `workflow/decomp_notes/source_cleanup/wave02/m_mo_obj.md`

The source commit contains only the assigned source file. This report is the
second assigned commit. The final delivery hash is returned with this report.

## Root correction review

Root review requested address proof for the sprite temporary names. The prior
source commit was `d629aef2d27fc767934b4ec04acdc05ba50cf962`. The correction
source commit is `caa4b29540d24510b1922e9e000926aeffe59066`.

I inspected the original `00452040` packet at
`inventory/functions/0045/00452040_save.txt` and its original instruction
addresses. The prologue at `00452040` reserves eight bytes. After the saved
register pushes, the first local address is `[esp+0x8]` and the second is
`[esp+0xc]`.

- `0045204A` loads `move_sprite` from `[edi+0xBC]`.
- `00452054` reads `[eax+0x72]`, which is `move_sprite->id`.
- `00452058` stores that ID at `[esp+0x8]`. The null path at `0045205E`
  stores the `-1` sentinel at the same address.
- `00452080` loads `[esp+0x8]` into the first `rge_write` buffer. The first
  write calls `rge_write` at `00452088` with size `2`.
- `00452062` loads `run_sprite` from `[edi+0xC0]`.
- `0045206C` reads `[eax+0x72]`, which is `run_sprite->id`.
- `00452074` stores that ID at `[esp+0xc]`. The null path keeps the `-1`
  sentinel and stores it at the same address.
- `00452090` loads `[esp+0xc]` into the second `rge_write` buffer. The second
  write calls `rge_write` at `00452098` with size `2`.

This proves the field and serialized-write order. It does not prove both PDB
declaration names. The Ghidra packet labels `[esp+0x8]` as `temp_run_sprite`
at `00452058`, `0045205E`, and `00452080`, but labels the second address as
`local_4` at `00452074` and `00452090`. The scoped PDB record lists
`temp_run_sprite` and `temp_move_sprite`, but its home offsets do not resolve
that conflicting optimized alias.

I therefore reverted the sprite pair to the prior descriptive names
`move_sprite_id` and `run_sprite_id` in the two setup functions and `save`.
The earlier report claim that the reversed PDB names were proven is
superseded. The current source does not claim either unresolved PDB mapping.

The PDB table and earlier name list retain the prior names as historical
evidence. The current source uses supported PDB names except for this
unresolved sprite pair.
The earlier table sentence about mapping the pair by serialized order is also
historical and superseded.

The correction also compacts all three `setup` signatures, `copy_obj`, and
the three `modify` signatures onto one line where readable. It does not apply
an 80-column limit. Long signatures remain readable and keep their tokens.

I reviewed the complete base-to-head diff and ran `git diff --check`.

## Scope and source changes

The module has 14 normal functions. I recovered procedure-scoped names from
`inventory/pdb/scoped_symbols.json`. I also inspected all 14 packets under
`inventory/functions/0045/` for addresses `00451A20` through `00452040`.

The source uses supported recovered PDB names. It keeps types, declarations,
order, calls, casts, literals, evaluation order, and storage behavior. It also
uses 1TBS braces. No helper, layout, or control-flow rewrite was made.

## PDB inspection coverage

Every function has a matching scoped-symbol record. Each record has `this` in
`ecx`. All records have no function statics.

| VA | PDB source lines | Parameters inspected | Locals inspected |
| --- | --- | --- | --- |
| `00451A20` | 25-28 | `other_object: RGE_Master_Moving_Object*`, `do_setup: int` | none |
| `00451AA0` | 34-37 | `infile: int`, `sprites: RGE_Sprite**`, `sounds: RGE_Sound**`, `do_setup: int` | none |
| `00451B10` | 43-46 | `infile: _iobuf*`, `sprites: RGE_Sprite**`, `sounds: RGE_Sound**`, `in_id: short`, `do_setup: int` | none |
| `00451B90` | 51-67 | `other_object: RGE_Master_Moving_Object*` | none |
| `00451C10` | 72-94 | `infile: int`, `sprites: RGE_Sprite**`, `sounds: RGE_Sound**` | `temp_run_sprite` at `+0xc`; `temp_move_sprite` at `+0x10` |
| `00451D10` | 99-130 | `infile: _iobuf*`, `sprites: RGE_Sprite**`, `sounds: RGE_Sound**`, `in_id: short` | `temp_run_sprite` at `-0x2`; `temp_size_class` at `+0x14`; `temp_obj_trail_options` at `+0xc`; `temp_move_algorithem` at `+0x10`; `temp_move_sprite` at `+0x8` |
| `00451DE0` | 135 | none | none |
| `00451DF0` | 141-155 | `owner: RGE_Player*`, `x: float`, `y: float`, `z: float` | none |
| `00451EC0` | 160-162 | none | none |
| `00451F30` | 167-180 | `source: RGE_Master_Static_Object*` | none |
| `00451FB0` | 184-194 | `amount: float`, `flag: unsigned char` | none |
| `00451FE0` | 198-208 | `amount: float`, `flag: unsigned char` | none |
| `00452010` | 212-222 | `amount: float`, `flag: unsigned char` | none |
| `00452040` | 227-244 | `outfile: int` | `temp_run_sprite` at `-0x4`; `temp_move_sprite` at `-0x8` |

The `00451C10` and `00451D10` local records reuse stack slots that also hold
incoming parameters. Their optimized homes do not prove a source declaration
mapping for the sprite pair. The source keeps the prior descriptive names
`move_sprite_id` and `run_sprite_id`. Declaration order is unchanged.

## Name recovery

The following names are recovered originals from the PDB:

- `source` to `other_object` in the copy constructor and pointer setup.
- `id` to `infile` in the integer constructor.
- `file` to `infile` in the file constructor and both file setup paths.
- `index` to `in_id` in the file constructor and file setup path.
- `player` to `owner` in `make_new_obj`.
- `value` to `amount` and `attribute` to `flag` in all three modifier methods.
- `file` to `outfile` in `save`.
- `size_class_out` to `temp_size_class`.
- `obj_trail_options_out` to `temp_obj_trail_options`.
- `move_algorithem_out` to `temp_move_algorithem`.

The PDB sprite names remain unresolved. The source keeps the prior descriptive
names `move_sprite_id` and `run_sprite_id`.

The PDB does not record the `selected_move`, `selected_run`, or
`moving_source` locals. These are existing inferred snake_case names. I left
them unchanged because their original mappings are not proved.

The exact save instruction chain proves the sprite roles and serialized order,
not the PDB declaration mapping. The source keeps the prior descriptive names
`move_sprite_id` and `run_sprite_id`.

## Constants, resources, and comments

No new constants were added. The existing `0x1E` master type and `6` modifier
flag remain numeric. Searches of the shared declarations did not find symbols
whose type, value, and role prove either replacement. Existing read and write
sizes remain unchanged.

No comments were added. The functions have no non-obvious lifetime or resource
rule that needs a source comment. The existing misspelling `move_algorithem`
remains unchanged because it is an established member name.

This module has no resource lookup or resource ID. No resource request exists.
The language DLLs were not needed for this module.

## Header request for owner 08

Please update `include/m_mo_obj.h` declaration parameter names without changing
any type, order, ABI, or layout:

```cpp
virtual void copy_obj(RGE_Master_Static_Object* source);
virtual void modify(float amount, unsigned char flag);
virtual void modify_delta(float amount, unsigned char flag);
virtual void modify_percent(float amount, unsigned char flag);
virtual void save(int outfile);
virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);
RGE_Master_Moving_Object(RGE_Master_Moving_Object* other_object, int do_setup);
RGE_Master_Moving_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup);
RGE_Master_Moving_Object(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup);
int setup(RGE_Master_Moving_Object* other_object);
int setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
int setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id);
```

## Risk review

- All changes are identifier recovery and brace formatting.
- Parameter and local types are unchanged.
- No class layout, field, calling convention, public symbol, or vtable change was made.
- No explicit cast, narrowing conversion, file width, sentinel, or lookup order changed.
- The reused stack-slot locals remain separate declarations in the original order.
- Compilation and matching were deferred, so generated-code stability is not claimed here.

Compilation, matching, audits, and tests were not run.
