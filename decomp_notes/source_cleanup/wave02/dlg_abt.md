# Source cleanup: `src/dlg_abt.cpp`

## Handoff

- Module: `src/dlg_abt.cpp`
- Header read-only: `include/dlg_abt.h`
- Header owner: owner 10
- Branch: `cleanup/staging-20260915-83`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Source head commit: `d70f7ddbae5959ed116b0d2bd51ae96c412070a4`
- Changed files:
  - `src/dlg_abt.cpp`
  - `decomp_notes/source_cleanup/wave02/dlg_abt.md`

The source commit changes only the assigned source. This report is the only
other assigned path. No header or registry file changed.

## Evidence and packet selection

I read the repository contracts and all source-cleanup, comment, resource-ID,
owner, testing, and wave-assignment guides. I read the existing `dlg_abt`
recovery note and the assigned header.

The source registry is:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/dlg_abt.cpp.json`

It selects the four handwritten procedures and `gx` flags. I inspected the
selected packets under `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/`:

- `0043AD70_TribeAboutDialog.txt`
- `0043B300_TribeAboutDialog.txt`
- `0043B400_action.txt`
- `0043B550_draw.txt`

I also inspected the compiler-generated packet:

- `0043B2E0_scalar_deleting_destructor.txt`

The procedure-scoped PDB evidence is in:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The PDB source module is `C:\\msdev\\work\\age1_x1\\dlg_abt.cpp`. The
original executable evidence path is:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
- SHA-256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The preserved pre-cleanup build is:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`
- `dlg_abt.obj` SHA-256: `7680281902893420d2466acd8f12d4e05e2aa9938e437ac57bbdf35b990d6dbb`
- `empiresx.exe` SHA-256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`

## Original-name recovery coverage

The four registry procedures have complete source-function coverage. For each
procedure, I inspected all available PDB parameter, local, and register
symbols. The compiler-generated destructor is listed separately because it has
no source body.

| VA | Procedure | PDB parameters, locals, and registers | Source result |
| --- | --- | --- | --- |
| `0043AD70` | `TribeAboutDialog::TribeAboutDialog` | Stack `parentPanel` at `+0x4` (`TScreenPanel*`); `tabList` at `-0x122C` (`TPanel*[8 bytes]`); `temp_str` at `-0x120C` (`char[512]`); `rect` at `-0x1224` (`tagRECT`); `str` at `-0x100C` (`char[4096]`). Register `this` in `ecx` (`TribeAboutDialog*`). | Renamed `parent` to recovered `parentPanel` and `tabs` to recovered `tabList`. Existing `temp_str`, `rect`, and `str` already matched. |
| `0043B2E0` | compiler-generated scalar deleting destructor | Stack `__flags` at `+0x4` (`unsigned int`). Register `this` in `ecx` (`TribeAboutDialog*`). No PDB source span. | No source change. This procedure is compiler generated. |
| `0043B300` | `TribeAboutDialog::~TribeAboutDialog` | No stack symbols. Register `this` in `ecx` (`TribeAboutDialog*`). | No name change. |
| `0043B400` | `TribeAboutDialog::action` | Stack `fromPanel` at `+0x4` (`TPanel*`), `actionIn` at `+0x8` (`long`), `a1` at `+0xC` (`unsigned long`), and `a2` at `+0x10` (`unsigned long`). Register `this` in `ecx` (`TribeAboutDialog*`). | Renamed `panel` to recovered `fromPanel`, `command` to recovered `actionIn`, `param_3` to recovered `a1`, and `param_4` to recovered `a2`. |
| `0043B550` | `TribeAboutDialog::draw` | No stack symbols. Register `this` in `ecx` (`TribeAboutDialog*`). | No name change. |

The constructor PDB stack offsets match the existing declaration types and
storage. The action PDB offsets match the existing signature types and order.
No reused stack slot required an uncertain rename.

The existing source locals `modal`, `close_button`, `game_screen`, and `credits`
have no readable PDB stack records. I kept their declarations, scopes, types,
and initialization points. They remain existing descriptive names, not claimed
recovered originals. I did not remove the unused `credits` pointer or any
other alias or temporary.

The destructor deletes fields in the existing order. The constructor keeps its
field initialization, setup order, fallback branch, panel creation calls,
resource lookups, and tab setup. The action keeps its command guard and its
close, credits, and base-action paths.

## Cleanup changes

- Added the existing shared resource header include.
- Restored PDB parameter spelling `parentPanel`.
- Restored PDB local spelling `tabList`.
- Restored PDB action parameter spellings `fromPanel`, `actionIn`, `a1`, and
  `a2`.
- Applied 1TBS function brace placement.
- Joined the short action signature on one line.
- Replaced four numeric IDs with existing macros whose values and roles match:
  `IDS_PRODUCT_TITLE` (`0x2419`), `IDS_COPYRIGHT_PREFIX` (`0x241B`),
  `IDS_COPYRIGHT_SUFFIX` (`0x241C`), and `IDS_COPYRIGHT_SEPARATOR` (`0x2424`).

No new source comment was needed. No function, class, member, global, type,
layout, calling convention, public symbol, declaration order, or source order
changed.

## Resource evidence

The read-only extractor output is in this worker's ignored build directory:

- `build/resource-strings/dlg_abt-language.json`
- `build/resource-strings/dlg_abt-languagex.json`
- `build/resource-strings/dlg_abt-pinned-languagex.json`

The extractor was run after `python C:/Projects/my_decomps/aoe1_attempt3/tools/inspect_pe_strings.py --help`.
The pinned XPack query returned exit code 1 because it reports missing IDs.
The JSON output still records the missing IDs.

The resource files and hashes are:

- Base: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
  (`3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`)
- Current expansion: `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`
  (`4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`)
- Pinned XPack expansion: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
  (`a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`)

All records use resource type `RT_STRING` and language `0x0409` (`1033`).
`TRIBE_Game::get_string` loads the expansion table first and falls back to the
base `language.dll` table when the expansion lookup returns zero. The default
expansion name is `languagex.dll`; a `STRING=` command option can override it.
`TPanel::get_string` routes through `rge_base_game->get_string`, so these
lookups use that virtual expansion-first path.

The following table records the exact lookup results. `empty` means an existing
empty string-table slot. `missing` means no matching block or slot.

| ID | Name status and proposed name | Proven purpose | Base `language.dll` | Current `languagex.dll` | Pinned XPack `languagex.dll` |
| --- | --- | --- | --- | --- | --- |
| `0x2419` | Existing `IDS_PRODUCT_TITLE` | About-dialog product title. | `Microsoft© Age of Empires™` | `Microsoft® Age of Empires® Expansion:` | `Microsoft© Age of Empires, the Rise of Rome™` |
| `0x241A` | Request `IDS_PRODUCT_VERSION` | About-dialog version text. | `Version 1.0b` | `Version 1.0` | `Version 1.0` |
| `0x241B` | Existing `IDS_COPYRIGHT_PREFIX` | First copyright segment. | `© & ` | empty | empty |
| `0x241C` | Existing `IDS_COPYRIGHT_SUFFIX` | Final copyright segment. | `1997 Microsoft Corporation. All rights reserved.` | `1997-1998 Microsoft Corporation. All rights reserved.` | `1998 Microsoft Corporation. All rights reserved.` |
| `0x241D` | Request `IDS_COPYRIGHT_ENSEMBLE` | Developed by Ensemble Studios text. | `Developed by Ensemble Studios Corp. for Microsoft Corporation.` | empty | empty |
| `0x241E` | Request `IDS_PRODUCT_ID_LABEL` | Product ID label beside the registry value. | `Product ID:` | empty | empty |
| `0x241F` | Request `IDS_ABOUT_COPYRIGHT_WARNING` | About-dialog copyright warning text. | See exact records below. | See exact records below. | empty |
| `0x2420` | Request `IDS_ABOUT_CREDITS_BUTTON` | Credits button caption. | `Credits` | empty | missing |
| `0x2421` | Request `IDS_ABOUT_CLOSE_BUTTON` | Close button caption. | `Close` | empty | missing |
| `0x2423` | Request `IDS_GENIE_ENGINE_COPYRIGHT` | Genie engine copyright text. | `Genie engine technology © Copyright 1995, 1996, 1997 by Ensemble Studios Corp. All rights reserved.` | empty | missing |
| `0x2424` | Existing `IDS_COPYRIGHT_SEPARATOR` | Selects split or combined copyright layout. | empty | empty | missing |

The exact `0x241F` records are:

- Base: `WARNING: This computer program is protected by copyright law and international treaties.  Unauthorized reproduction or distribution of this program, or any portion of it, may result in severe civil and criminal penalties, and will be prosecuted to the maximum extent possible under the law.\n\nThe names of companies, products, people, characters, events and/or data mentioned in Age of Empires and its documentation are fictitious unless otherwise noted.`
- Current expansion: `WARNING: This computer program is protected by copyright law and international treaties.  Unauthorized reproduction or distribution of this program, or any portion of it, may result in severe civil and criminal penalties, and will be prosecuted to the maximum extent possible under the law.\n\nThe names of companies, products, people, characters, events and/or data mentioned in Age of Empires Expansion and its documentation are fictitious unless otherwise noted.`
- Pinned XPack expansion: empty slot.

The exact `0x2424` empty base and current-expansion slots cause the constructor
to use its split copyright path. The pinned expansion record is missing, so the
base fallback still produces an empty separator.

The existing `IDS_COPYRIGHT_WARNING` macro has value `0x2425`, not `0x241F`.
I did not use it for this dialog. The two IDs have separate source uses and
must not be merged by numeric proximity or similar purpose.

The numeric values `0xC4E0` and related setup values are picture or panel data,
not `RT_STRING` lookups. This report does not propose names for those values.

## Shared requests

The owner of `include/dlg_abt.h` should consider these declaration-only names:

```cpp
TribeAboutDialog(TScreenPanel* parentPanel);
virtual long action(TPanel* fromPanel, long actionIn,
                    unsigned long a1, unsigned long a2);
```

These names preserve the existing types, order, virtual slot, calling
convention, and ABI. This worker did not edit the header.

The root owner of `include/resource_ids.h` should review these new cleanup
macros. They are not recovered original macro names:

```cpp
#define IDS_PRODUCT_VERSION         0x241A
#define IDS_COPYRIGHT_ENSEMBLE      0x241D
#define IDS_PRODUCT_ID_LABEL        0x241E
#define IDS_ABOUT_COPYRIGHT_WARNING 0x241F
#define IDS_ABOUT_CREDITS_BUTTON    0x2420
#define IDS_ABOUT_CLOSE_BUTTON      0x2421
#define IDS_GENIE_ENGINE_COPYRIGHT  0x2423
```

Each request has one proven `RT_STRING` role and one resource namespace. The
source keeps these seven IDs numeric until the shared owner reviews them.

## Code-generation and validation limits

The existing macros expand to the same integer values. They add no storage and
no symbol. Identifier changes can alter debug names and PDB line records.
Brace and signature formatting can also alter line records. No executable
body structure, call target, relocation, literal value, expression order,
explicit cast, declaration scope, storage duration, or layout changed.

I ran `git diff --check`, Git diff review, PDB inspection, packet inspection,
resource extraction, and file-hash checks. I did not run a compiler or build.

Compilation, matching, audits, and tests were not run.
