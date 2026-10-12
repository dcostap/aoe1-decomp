# `tm_co_ob.cpp` source-cleanup report

## Scope and commits

- Module: `src/tm_co_ob.cpp`.
- Branch: `cleanup/staging-20260915-80`.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Final source commit: `b4b519fc44306fa380166c8b2903632415c7ce5a`.
- Changed files: `src/tm_co_ob.cpp` and this report.
- Header read only: `include/tm_co_ob.h`. Owner 09 owns that header.
- Registry: `config/functions/src/tm_co_ob.cpp.json`, flags `gx`.
- Registry status: all 15 functions are `matching`.

I read the assigned cleanup, comments, resource-ID, owner, and testing guides.
I used the registry to select all 15 packets under `inventory/functions/0050/`.
I inspected the shared PDB record for every assigned VA.

The original executable path is:
`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`.
Its SHA-256 is `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved baseline object is:
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/tm_co_ob.obj`.
Its SHA-256 is `95713945cc25f4c815406b487cfa7c12b2d044451fc00d4de323f65510eb6593`.
The preserved baseline executable SHA-256 is
`492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.

## PDB coverage

The PDB source path is `C:\msdev\work\age1_x1\tm_co_ob.cpp`.
Every assigned procedure has a `this` register record in `ecx`.
The type is `TRIBE_Master_Combat_Object*` in every record.
Every assigned procedure has an empty PDB `function_statics` list.

| VA | Procedure | PDB stack names and types |
| --- | --- | --- |
| `0050E970` | first constructor | `other_object` (`TRIBE_Master_Combat_Object*`), `do_setup` (`int`) |
| `0050E9F0` | integer constructor | `infile` (`int`), `sprites` (`RGE_Sprite**`), `sounds` (`RGE_Sound**`), `do_setup` (`int`) |
| `0050EA60` | file constructor | `infile` (`_iobuf*`), `sprites` (`RGE_Sprite**`), `sounds` (`RGE_Sound**`), `in_id` (`short`), `do_setup` (`int`) |
| `0050EAE0` | copy setup | `other_object` (`TRIBE_Master_Combat_Object*`) |
| `0050EB60` | integer setup | `infile` (`int`), `sprites` (`RGE_Sprite**`), `sounds` (`RGE_Sound**`) |
| `0050EC90` | file setup | `infile` (`_iobuf*`), `sprites` (`RGE_Sprite**`), `sounds` (`RGE_Sound**`), `in_id` (`short`); locals `temp_flag` (`short`) and `temp_button_location` (`short`) |
| `0050EDA0` | destructor | no stack names |
| `0050EDB0` | `create_task_list` | no stack names |
| `0050EE00` | `copy_obj` | `source` (`RGE_Master_Static_Object*`) |
| `0050EE80` | `modify` | `amount` (`float`), `flag` (`unsigned char`) |
| `0050EF70` | `modify_delta` | `amount` (`float`), `flag` (`unsigned char`) |
| `0050EFC0` | `modify_percent` | `amount` (`float`), `flag` (`unsigned char`) |
| `0050F010` | `save` | `outfile` (`int`) |
| `0050F090` | `make_new_obj` | `owner` (`RGE_Player*`), `x` (`float`), `y` (`float`), `z` (`float`) |
| `0050F110` | `make_new_master` | no stack names |

The PDB packets also show no function-static names or extra register names.
The inventory packets provide the original body ranges and direct call targets.

## Recovered original names

These names came from the procedure-scoped PDB records.
The source preserves the exact PDB spelling.

- `0050E970`: `source` became `other_object`.
- `0050E9F0`: `id` became `infile`.
- `0050EA60`: `file` became `infile`; `id` became `in_id`.
- `0050EAE0`: `source` became `other_object`.
- `0050EB60`: `fd` became `infile`.
- `0050EC90`: `file` became `infile`; `id` became `in_id`.
- `0050EE80`: `value` became `amount`; `attribute` became `flag`.
- `0050EF70`: `value` became `amount`; `attribute` became `flag`.
- `0050EFC0`: `value` became `amount`; `attribute` became `flag`.
- `0050F010`: `fd` became `outfile`.
- `0050F090`: `player` became `owner`.

Existing names already matched the PDB and remain unchanged.
These include `do_setup`, `sprites`, `sounds`, `source` in `copy_obj`, and `x`, `y`, `z`.

## Locals and unresolved mappings

The source keeps existing descriptive names without PDB support.
These names include `armor_count`, `left`, `cost`, `remaining`, `entry`,
`tribe_source`, `type`, `types`, `current_value`, `values`, and loop variable `i`.
They are not claimed as original names.
No invented local name was added.

`0050EC90` needs a conservative note.
The PDB records `temp_flag` at `+0x14` and `temp_button_location` at `+0x10`.
The same record lists `in_id` at `+0x10`.
The original packet shows the first `fscanf` destination using the `in_id` stack home.
It shows the final `fscanf` destination using the `sounds` stack home.
The source keeps those existing aliases and does not add local declarations.
This avoids forcing an uncertain reused-stack-slot mapping.
The existing comment documents the final `sounds` store and its width.

The Ghidra packets show exception-chain slots and register temporaries.
Those artifacts are not source locals.
The source keeps the existing declarations, scopes, types, and storage duration.

## Constants, resources, and comments

No constant changed.
The source retains `master_type = 0x46`, loop count `3`, and I/O widths `6`, `2`,
and `1` from the original packets.
It retains attribute values `'d'`, `'e'`, `0x64`, `4`, `0x0B`, and `0x13`.
The packets prove these values and their existing operations.
No existing enum or symbolic declaration proved a better replacement.

No resource lookup occurs in this source module.
No resource ID name or resource request is needed.
No resource extractor ran.
For provenance, the inspected runtime hashes are:

- `runtime/language.dll`: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- `runtime/languagex.dll`: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
- Pinned XPack `languagex.dll`: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

No new comment was added.
The existing comment before the final `fscanf` remains.
The `0050EC90` packet proves its unusual `sounds` stack destination.
It also proves the preserved byte-width cast to `button_location`.

## Header request

Owner 09 may apply these declaration-only PDB names in `include/tm_co_ob.h`:

```cpp
TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* other_object, int do_setup);
TRIBE_Master_Combat_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup);
TRIBE_Master_Combat_Object(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup);

int setup(TRIBE_Master_Combat_Object* other_object);
int setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
int setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id);

virtual void modify(float amount, unsigned char flag);
virtual void modify_delta(float amount, unsigned char flag);
virtual void modify_percent(float amount, unsigned char flag);
virtual void save(int outfile);
virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);
```

The request changes names only.
It does not change types, order, ABI, layout, or symbol identity.
No shared resource declaration request is open.

## Code-generation effects and validation

The source changes identifier spellings only.
It preserves types, casts, declarations, scopes, storage, statement order,
evaluation order, calls, literals, and direct targets.
It adds no helper, wrapper, layout change, or assembly.
Parameter names can change debug metadata, but not the public symbols.
The source uses the existing 1TBS brace style.

I ran `git diff --check` and reviewed the complete source diff.
I did not run a compiler, build, matcher, audit, test, or game command.
Compilation, matching, audits, and tests were not run.
