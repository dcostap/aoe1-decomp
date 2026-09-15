# Source cleanup: `src/scr_info.cpp`

## Handoff

- Module: `src/scr_info.cpp`
- Header read-only: `include/scr_info.h`
- Branch: `cleanup/staging-20260915-95`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source cleanup commit: `1c0c10bd6edd401f7c70b1a47173fa854bf5c8fc`
- Changed files:
  - `src/scr_info.cpp`
  - `decomp_notes/source_cleanup/wave02/scr_info.md`

The source commit changes only the assigned source file. The report commit
follows the source commit. Its full hash is returned in the worker handoff.
The final module source commit above is the exact post-cleanup source hash.

## Scope and evidence

I read the repository contract and all six assigned guides. I read the
assigned source, header, registry, existing module note, and all assigned
function packets. I inspected every assigned VA in
`inventory/pdb/scoped_symbols.json`, including stack, local, static, and
register records.

The source registry is:

- `config/functions/src/scr_info.cpp.json`
- PDB source: `C:\msdev\work\age1_x1\scr_info.cpp`
- Flags: `config/flags/gx.rsp`
- Registry status before cleanup: seven normal functions marked `matching`

The checked PDB inventory hash is:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- SHA-256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`

The original behavior packets and hashes are:

| VA | Packet | SHA-256 |
| --- | --- | --- |
| `0049D550` | `inventory/functions/0049/0049D550_TRIBE_Screen_Info.txt` | `f52497cbc426510a95ee08f76a53db8120bfd375afab22b459f69fd8a6c1137d` |
| `0049D5E0` | `inventory/functions/0049/0049D5E0_scalar_deleting_destructor.txt` | `cd1a77bafc40a0d816d2103a269c8346fed8eda35ec03a14a9e8800aab380283` |
| `0049D600` | `inventory/functions/0049/0049D600_TRIBE_Screen_Info.txt` | `ef369f27ec74af6b66511c8c7815c8d925256c3ed9cbcad7acdf6193b1d1077e` |
| `0049D610` | `inventory/functions/0049/0049D610_handle_idle.txt` | `c38c93020d64e852bbbbdcf58e1c60bc60b7d51b05e7f2206f0b93f9cd3777a0` |
| `0049D690` | `inventory/functions/0049/0049D690_key_down_action.txt` | `a8aa3ee9a78adf93bafa8be5a2d595941da20b40343cc1492d16d1afbd1fb044` |
| `0049D6B0` | `inventory/functions/0049/0049D6B0_mouse_left_down_action.txt` | `ca92a9c823e585a08364bed559fb4eca9b81a1c3dc9b7ab7681050eb4f2be517` |
| `0049D6C0` | `inventory/functions/0049/0049D6C0_action.txt` | `fd13c7f9ff1b7029d77d59852c0469858a1a364181ab2ac3978ebf3e8d1b16ab` |
| `0049D6E0` | `inventory/functions/0049/0049D6E0_close_screen.txt` | `4c694e9b676bf01aea999cb66608a2d719b67a606a82bc40bc1e9e5b39032534` |

The original executable used for the packet corpus is:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
- SHA-256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

## Original-name recovery coverage

All seven normal procedures have a scoped PDB register record for `this`.
Each record has register `ECX` and type `TRIBE_Screen_Info*`. The scoped PDB
records no function static for any assigned procedure.

| VA | Procedure | Scoped stack records and result |
| --- | --- | --- |
| `0049D550` | `TRIBE_Screen_Info::TRIBE_Screen_Info` | `scr_name_in` (`char*`, `+0x4`), `info_file_in` (`char*`, `+0x8`), `info_id_in` (`long`, `+0xc`), and `timer_in` (`unsigned long`, `+0x10`). Restored all four names and uses. |
| `0049D600` | `TRIBE_Screen_Info::~TRIBE_Screen_Info` | No stack records. The source has no rename. |
| `0049D610` | `TRIBE_Screen_Info::handle_idle` | No stack records. The source has no rename. |
| `0049D690` | `TRIBE_Screen_Info::key_down_action` | `key` (`long`, `+0x4`), `count` (`short`, `+0x8`), `alt_key` (`int`, `+0xc`), `ctrl_key` (`int`, `+0x10`), and `shift_key` (`int`, `+0x14`). Restored all five names. |
| `0049D6B0` | `TRIBE_Screen_Info::mouse_left_down_action` | `x` (`long`, `+0x4`), `y` (`long`, `+0x8`), `ctrl_key` (`int`, `+0xc`), and `shift_key` (`int`, `+0x10`). Restored all four names. |
| `0049D6C0` | `TRIBE_Screen_Info::action` | `fromPanel` (`TPanel*`, `+0x4`), `actionIn` (`long`, `+0x8`), `a1` (`unsigned long`, `+0xc`), and `a2` (`unsigned long`, `+0x10`). Restored all four names and forwarding uses. |
| `0049D6E0` | `TRIBE_Screen_Info::close_screen` | No stack records. The source has no rename. |

The PDB records no source locals for the seven normal procedures. Ghidra
shows optimized exception and temporary storage in `close_screen`, but those
records do not prove source declarations or names. I did not force mappings
for them. No reused PDB stack slot created an uncertain source rename.

The compiler-generated scalar deleting destructor at `0049D5E0` was also
inspected. Its PDB record has `__flags` (`unsigned int`, `+0x4`) and register
`this` (`TRIBE_Screen_Info*`, `ECX`). Its packet has no PDB source span. It
has no handwritten source body and was not edited.

The source does not change public function names, class names, members, types,
calling conventions, storage, or declaration order. The unassigned header
still has its old declaration names.

## Constants, resources, and comments

No new constant or resource name was added. This module performs no string
lookup and has no `RT_STRING` resource call. The numeric values passed to
`TScreenPanel::setup` remain unchanged:

- `0xC392` for `Logo2Screen`
- `0xC394` for `UnitInfo1`
- `0xC395` for `UnitInfo2`
- `0xC396` for `UnitInfo3`
- `0xC393` for `TechInfo`
- `0xC38F` for `QuotesInfo`

These values are setup IDs, not proven language string IDs. I kept them
numeric because no reviewed shared symbol proves a matching meaning and type.
The key comparisons `0x12`, `0x11`, and `0x10` also remain numeric. The
source keeps the `2000` timer value and all existing literals.

There is no shared resource-ID request. Therefore, there are no requested IDs
to report with a resource path, language, text, fallback, or hash. The runtime
resource files were not used for this module. Their checked hashes are listed
only as provenance:

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`:
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`:
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`:
  `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`

No source comments were added. The fixed debug source path and explicit time
line values remain unchanged. Existing control flow and compatibility behavior
remain unchanged.

## Header request

Owner 11 owns `include/scr_info.h`. Please review these declaration-only name
changes:

```cpp
TRIBE_Screen_Info(char* scr_name_in, char* info_file_in, long info_id_in,
                  unsigned long timer_in);
virtual long key_down_action(long key, short count, int alt_key, int ctrl_key,
                             int shift_key);
virtual long mouse_left_down_action(long x, long y, int ctrl_key, int shift_key);
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1,
                    unsigned long a2);
```

The request changes no type, order, ABI, virtual slot, or layout. This worker
did not edit the header.

## Code-generation effects and validation

The cleanup restores names that the PDB records. It moves function opening
braces to 1TBS form. It joins the short action definition signature. These
changes can alter debug names and line records. They do not add data, calls,
casts, temporaries, helpers, or control flow. Compiler output, relocations,
and direct-call identity remain unvalidated.

I ran these allowed checks:

- Read-only evidence inspection for all seven normal procedures and the
  generated destructor.
- Read-only inspection of the source, header, registry, and durable note.
- `git diff --check` before the source commit.
- Complete source diff review.

Compilation, matching, audits, and tests were **not run**. I did not run a
compiler, build command, matching tool, audit, test suite, or game command.

## Commit records

- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source cleanup commit: `1c0c10bd6edd401f7c70b1a47173fa854bf5c8fc`
- Final report commit: the commit that adds this report; its full hash is
  returned in the worker handoff.
