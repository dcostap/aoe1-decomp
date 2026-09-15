# Source cleanup: `src/scr_stms.cpp`

## Handoff

- Module: `src/scr_stms.cpp`
- Branch: `cleanup/staging-20260915-98`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `d249dd19f628068cd4e96e260b5c10e8a37d6e1a`
- Assigned header: `include/scr_stms.h` (read only; owner 11)
- Changed files:
  - `src/scr_stms.cpp`
  - `decomp_notes/source_cleanup/wave02/scr_stms.md`

The source commit changes only the assigned source file. The report is the
second assigned file. No header or shared file was changed.

## Scope and evidence

I read the complete repository contract, source-cleanup, source-comments,
resource-ID, owner, assignment, and testing guides. I read `include/scr_stms.h`,
`config/functions/src/scr_stms.cpp.json`, and the existing `decomp_notes/scr_stms.md`.

The source registry has five handwritten procedures, in this order:

- `004B7140` — `TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(char*, char*, char*, long)`
- `004B7330` — `TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(char*, long, char*, long)`
- `004B7500` — `TRIBE_Screen_Status_Message::~TRIBE_Screen_Status_Message`
- `004B7560` — `TRIBE_Screen_Status_Message::set_text(char*)`
- `004B7580` — `TRIBE_Screen_Status_Message::set_text(long)`

I inspected all five registry packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/`. I also
inspected the compiler-generated deleting-destructor packet at `004B7310`.
I inspected every procedure-scoped PDB parameter, local, and register record
for all six VAs in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB source path is `C:\msdev\work\age1_x1\scr_stms.cpp`.

Evidence fingerprints:

- Scoped PDB records:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`,
  SHA-256 `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
- Original executable:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
  SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Preserved baseline executable:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`,
  SHA-256 `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
- Preserved baseline object:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/scr_stms.obj`,
  SHA-256 `b6d15feaf3d52e811d972a6f30636bc05f9fe97e27409bf1be4ef67dee5423d0`.
- Pinned toolchain record:
  `config/toolchain.json`, which names VC5 `CL.EXE` version `11.00.7022`.

Packet fingerprints:

- `004B7140_TRIBE_Screen_Status_Message.txt`:
  `dd2bdae2d52138b2bce53325b170f27535929ebf1cf8aa39015e1f2752783e11`.
- `004B7330_TRIBE_Screen_Status_Message.txt`:
  `fe86a09fc4e67d2292910f1dc6f905f008463baff2ad5021ff1a68b47479af5d`.
- `004B7500_TRIBE_Screen_Status_Message.txt`:
  `6cfae14759382596db0e9d88ccfd2c816914a0f21572c56395a999e35dea7f1e`.
- `004B7560_set_text.txt`:
  `6063c49d0b19a14962371e78672ff4c6e42aba7fb81e0712a902bf3d68c228b4`.
- `004B7580_set_text.txt`:
  `3993d47fa1d59f4405b73ea4a87b62b3ee20fdde37e6e0ce01e227537f5945e5`.
- `004B7310_vector_deleting_destructor.txt`:
  `c85a112eaebba4e1a8121da218bada7fe73521c6c37994ff78a374fc8e5d089b`.

## PDB name recovery coverage

All six VAs have an inspected `this` register record of type
`TRIBE_Screen_Status_Message*` in `ecx`, including the compiler-generated
record at `004B7310`. The source registry records all five handwritten VAs as
`matching`; the deleting destructor has no handwritten source body.

### `004B7140` — character-message constructor

The PDB records these stack parameters:

- `name`, `char*`, `+0x4`
- `message_in`, `char*`, `+0x8`
- `info_file_in`, `char*`, `+0xc`
- `info_id_in`, `long`, `+0x10`

It also records local `info_file`, `char[260]`, at `-0x110`.
The source now uses all four exact PDB parameter names. `info_file` already
matched. The source keeps `info_id` and `current_panel`; neither has a
procedure-scoped PDB record. No stack-slot mapping was forced for either
name.

### `004B7330` — string-ID constructor

The PDB records these stack parameters:

- `name`, `char*`, `+0x4`
- `message_in`, `long`, `+0x8`
- `info_file_in`, `char*`, `+0xc`
- `info_id_in`, `long`, `+0x10`

It also records local `info_file`, `char[260]`, at `-0x110`.
The source now uses all four exact PDB parameter names. This restores
`message_in` even though the current source used the more specific
`text_id`. The source keeps the unrecorded `info_id` and `current_panel` locals.

### `004B7310` — compiler-generated deleting destructor

The packet labels this function as a vector deleting destructor. The scoped
PDB symbol calls it a scalar deleting destructor. The PDB record has
`__flags`, `unsigned int`, at `+0x4`, and `this` in `ecx`; it has no source
path or line records. The source has no body for this compiler-generated
function, so no source change applies.

### `004B7500` — destructor

The PDB has no stack symbols. It has only the inspected `this` register record.
The source has no rename for this procedure.

### `004B7560` — `set_text(char*)`

The PDB records `message_in`, `char*`, at `+0x4`, and `this` in `ecx`.
The source now uses `message_in` instead of `text`.

### `004B7580` — `set_text(long)`

The PDB records `message_in`, `long`, at `+0x4`, and `this` in `ecx`.
The source now uses `message_in` instead of `text_id`.

### Rename summary

Recovered original names came only from the procedure-scoped PDB records:
`name`, `message_in`, `info_file_in`, and `info_id_in` in both constructors,
and `message_in` in both `set_text` overloads. No invented cleanup name was
added. Existing `info_file`, `info_id`, and `current_panel` names remain where
the PDB does not prove a mapping. No function, class, member, global, type,
calling convention, storage layout, or source order changed.

## Constants, resources, and comments

No constant was replaced. The geometry, text-panel flags, and sentinel values
have no shared symbol with proven identical meaning in the reviewed headers.
The values `0xC384` and `0xC385` are screen-info IDs passed to `setup`, not
string IDs passed to a language lookup. The source has no `get_string` call and
requests no new resource-ID declaration. No resource extraction was needed.

No new source comment was needed. The existing control flow shows the current
panel metadata fallback and the `scr2`/`scr3` default selection without a
speculative comment. The source comments remain unchanged.

## Formatting and possible code-generation effects

The source uses 1TBS braces for all five handwritten definitions. The cleanup
renames parameters and changes brace placement only. It preserves all casts,
types, declarations, scopes, storage, statements, calls, direct targets,
evaluation order, literals, string data, and source order. It does not add a
helper, alter a layout, or change a public ABI symbol.

Identifier and brace changes can affect compiler debug names and line records.
No line-dependent macro appears in this source. Compiler output, relocations,
program data, and direct-call identity remain unvalidated.

## Header and shared-file requests

Owner 11 should consider updating declaration-only parameter names in
`include/scr_stms.h` to match the recovered PDB spelling:

```cpp
TRIBE_Screen_Status_Message(char* name, char* message_in, char* info_file_in, long info_id_in);
TRIBE_Screen_Status_Message(char* name, long message_in, char* info_file_in, long info_id_in);
void set_text(char* message_in);
void set_text(long message_in);
```

This request changes no type, order, ABI, layout, or symbol. I did not edit the
header. I request no edit to `include/resource_ids.h` and no other shared file.

## Validation and limits

I ran `python tools/inspect_pe_strings.py --help` before deciding that this
module has no string-resource lookup. I ran `git diff --check`, reviewed the
complete source diff, reviewed the complete assigned diff, and inspected all
listed evidence packets and PDB records.

Compilation, matching, audits, and tests were **not run**. I did not run a
compiler, build, matcher, audit, test suite, game, or runtime command. No claim
of byte equality or semantic approval is made from this review.

## Commits

- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `d249dd19f628068cd4e96e260b5c10e8a37d6e1a`
- Report commit: recorded by the final Git output after this report is added.
