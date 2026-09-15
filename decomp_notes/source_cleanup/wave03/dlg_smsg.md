# Source-cleanup handoff: `src/dlg_smsg.cpp`

## Handoff

- Module: `src/dlg_smsg.cpp`
- Worktree: `slot-189`
- Branch: `cleanup/staging-20260915-189`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source-cleanup commit: `8fc5420596ec5025b05f8b802b1a1e3035aad8f4`
- Changed files:
  - `src/dlg_smsg.cpp`
  - `decomp_notes/source_cleanup/wave03/dlg_smsg.md`
- Header owner: group owner for `include/dlg_smsg.h`
- Shared resource header owner: root for `include/resource_ids.h`

The final handoff commit adds this report after the source commit.
The source commit hash above is copied from Git.

Follow-up correction commit `8fc5420596ec5025b05f8b802b1a1e3035aad8f4`
moved both constructor opening braces onto their initializer-list lines.
The correction changes formatting only. It changes no token or behavior.

## Scope and method

This worker performed source cleanup only. It did not perform behavior recovery.

I read `AGENTS.md`, `docs/source_cleanup.md`, `docs/source_comments.md`,
`docs/resource_ids.md`, `docs/source_cleanup_owners.md`, `docs/testing.md`,
and `decomp_notes/source_cleanup/wave03_assignments.md`.

I read the pinned toolchain and flags from
`C:/Projects/my_decomps/aoe1_attempt3/config/toolchain.json` and
`C:/Projects/my_decomps/aoe1_attempt3/config/flags/default.rsp`.
I read the pinned CRT and SDK files `FCNTL.H`, `string.h`, `windows.h`,
and `WINUSER.H` under
`C:/Program Files (x86)/DevStudio/VC/Include`.

I read the registry entry, the complete assigned source, the assigned header,
the source notes, all assigned original-function packets, and every assigned
scoped PDB record. I reviewed the complete source diff before both commits.

The registry is `config/functions/src/dlg_smsg.cpp.json`. It selects the `gx`
profile and nine normal functions. The source PDB path is
`C:\\msdev\\work\\age1_x1\\dlg_smsg.cpp`.

## Complete PDB and packet coverage

All nine normal registry functions were inspected. The two compiler-generated
scalar deleting destructors were also inspected. They have no handwritten
source bodies in this module.

| VA | Function | Size | Registry status | PDB source lines | Scoped PDB coverage | Packet evidence |
| --- | --- | ---: | --- | --- | --- | --- |
| `004407A0` | `TribeSendMessageDialog::TribeSendMessageDialog` | 1623 | accepted_drift | 66-244 | `parentPanel`, `id`, `i`, `temp_str`, `world`, `humanity`, `this` | `C:/Projects/my_decomps/aoe1_attempt3/build/asm/orig_004407A0_TribeSendMessageDialog.txt`; SHA-256 `b456c1614c157fc5f636968d05ba31f0be5be6680056991bfcec400c8c6ecd34` |
| `00440E00` | compiler-generated scalar deleting destructor | 30 | compiler-generated | no source body | `__flags`, `this` | PDB record only; the handwritten destructor packet below owns the source body |
| `00440E20` | `TribeSendMessageDialog::~TribeSendMessageDialog` | 255 | matching | 249-267 | `this`; no source locals or parameters | `C:/Projects/my_decomps/aoe1_attempt3/build/asm/orig_00440E20_TribeSendMessageDialog.txt`; SHA-256 `79ba8704c1efe5c8162f3c5273edeec2e96cf84130f96d8900cf6875a04021db` |
| `00440F20` | `TribeSendMessageDialog::action` | 1264 | matching | 273-436 | `fromPanel`, `actionIn`, `a1`, `a2`, `save_msg`, `this` | `C:/Projects/my_decomps/aoe1_attempt3/build/asm/orig_00440F20_action.txt`; SHA-256 `0c78b27e100cbc58e589a9126ce2394d2011c6a08138b8fbb276e5c283f3f974` |
| `00441410` | `TribeSendMessageDialog::checkButtons` | 65 | matching | 441-464 | `this`; no source locals or parameters | `C:/Projects/my_decomps/aoe1_attempt3/build/asm/orig_00441410_checkButtons.txt`; SHA-256 `f918a317cdddf57c8f98e7411117c9b750d97655c843820b560dd554d9ec847c` |
| `00441460` | `TribeSendMessageDialog::draw` | 203 | matching | 470-499 | `i`, `this` | `C:/Projects/my_decomps/aoe1_attempt3/build/asm/orig_00441460_draw.txt`; SHA-256 `2c185e00aeb605b17c2c86ba1ecd23af3208ba7aaf52873a860b269330853449` |
| `00441530` | `TribeSendQuickMessageDialog::TribeSendQuickMessageDialog` | 246 | matching | 507-527 | `parentPanel`, `m`, `this` | `C:/Projects/my_decomps/aoe1_attempt3/build/asm/orig_00441530_TribeSendQuickMessageDialog.txt`; SHA-256 `a68bd2d710efcf1d65fbfa3d4e378a6adcdd61c40cde48eaf5c17b3ce5206af9` |
| `00441630` | compiler-generated scalar deleting destructor | 30 | compiler-generated | no source body | `__flags`, `this` | PDB record only; the handwritten destructor packet below owns the source body |
| `00441650` | `TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog` | 106 | matching | 532-535 | `this`; no source locals or parameters | `C:/Projects/my_decomps/aoe1_attempt3/build/asm/orig_00441650_TribeSendQuickMessageDialog.txt`; SHA-256 `2ee9459b61f12eb8fdcb9509512c4d0d091448e1a43a84f4bda069c3d3c973da` |
| `004416C0` | `TribeSendQuickMessageDialog::action` | 373 | matching | 542-590 | `fromPanel`, `actionIn`, `a1`, `a2`, `save_msg`, `this` | `C:/Projects/my_decomps/aoe1_attempt3/build/asm/orig_004416C0_action.txt`; SHA-256 `585203226eff74a6ceaf6c7bb457f1a05dff6ae903cd6f79996b0a88bbef1c08` |
| `00441840` | `TribeSendQuickMessageDialog::handle_mouse_down` | 90 | matching | 596-604 | `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key`, `this` | `C:/Projects/my_decomps/aoe1_attempt3/build/asm/orig_00441840_handle_mouse_down.txt`; SHA-256 `dc78e9fee6bf892a76f54b446607966fa70ceaebea4b388d59e74cf6e776a485` |

The scoped PDB source is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The source line map is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`.
The registry is
`C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/dlg_smsg.cpp.json`.
The original packets decode the executable
`C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`.

## Original-name recovery

### `004407A0` — `TribeSendMessageDialog` constructor

The scoped PDB records these source declarations:

- `parentPanel`, `TScreenPanel*`, stack offset `+0x4`.
- `id`, `int`, stack offset `-0x7C`.
- `i`, `int`, stack offset `-0x88`.
- `temp_str`, `char[100]`, stack offset `-0x70`.
- `world`, `RGE_Game_World*`, stack offset `-0x80`.
- `humanity`, `int`, stack offset `-0x84`.

The source now uses all six recovered spellings. It changes the old parameter
`parent` to `parentPanel` and the old loop name `n` to `i`.
It preserves the declarations, array bounds, types, storage, and loop order.

### `00440E20` — destructor

The scoped PDB has only `this`. No source rename was required.
The source keeps deletion order and casts unchanged.

### `00440F20` — `TribeSendMessageDialog::action`

The scoped PDB records these parameters:

- `fromPanel`, `TPanel*`, stack offset `+0x4`.
- `actionIn`, `long`, stack offset `+0x8`.
- `a1`, `unsigned long`, stack offset `+0xC`.
- `a2`, `unsigned long`, stack offset `+0x10`.

The source now uses these exact original spellings. This includes terse names
`a1` and `a2`. It keeps the original `save_msg` declaration and control flow.

### `00441410` — `checkButtons`

The scoped PDB has only `this`. No source rename was required.

### `00441460` — `draw`

The scoped PDB records `i`, `int`, at stack offset `-0x8`, plus `this`.
The source already used `i`. No source rename was required.

### `00441530` — `TribeSendQuickMessageDialog` constructor

The scoped PDB records these parameters:

- `parentPanel`, `TScreenPanel*`, stack offset `+0x4`.
- `m`, `TribeSendQuickMessageDialog::Mode`, stack offset `+0x8`.

The source now uses both exact original spellings. It changes `parent` to
`parentPanel` and `mode` to the original terse name `m`.

### `00441650` — destructor

The scoped PDB has only `this`. No source rename was required.

### `004416C0` — `TribeSendQuickMessageDialog::action`

The scoped PDB records `fromPanel`, `actionIn`, `a1`, and `a2` with the same
types and offsets as `00440F20`. The source now uses all four spellings.
It keeps `save_msg`, call order, and the existing local declarations.

### `00441840` — `handle_mouse_down`

The scoped PDB records these parameters:

- `mouse_button_in`, `unsigned char`, stack offset `+0x4`.
- `x`, `long`, stack offset `+0x8`.
- `y`, `long`, stack offset `+0xC`.
- `ctrl_key`, `int`, stack offset `+0x10`.
- `shift_key`, `int`, stack offset `+0x14`.

The source now uses all five exact original spellings.

### Unresolved declaration mappings

Optimized PDB records do not name every source declaration. The following
existing source names have no direct scoped PDB record:

- Constructor: `world_humanity`, `y`, `row`, `special`, `font`, `j`, `count`, and `h`.
- First action: `screen`, `player`, `i`, `player_id`, and `state`.
- Draw: `world`, `y`, and `id`.
- Quick constructor: `title_id`.
- Quick action: `line` and `screen`.

I did not force stack-slot mappings or change these declarations.
The two scalar deleting destructors have compiler parameter `__flags` only.
They remain outside the handwritten source owner.

## Resource IDs

The source now uses the existing shared macro `IDS_HELP_OK` for `0x7531`.
The macro is in `include/resource_ids.h`. It expands to the original literal.
It adds no storage. It is a new descriptive cleanup name, not a recovered
original macro name.

The other source IDs remain numeric. The source must keep these literals until
root reviews and adds shared declarations. Proposed names are cleanup names,
not recovered names.

The checked base runtime file is
`C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`.
Its full SHA-256 is
`3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
The checked expansion runtime file is
`C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`.
Its full SHA-256 is
`4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
The pinned original expansion file is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`.
Its full SHA-256 is
`a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
All returned resource records use language `0x0409` (`1033`).
The pinned original tree has no base `language.dll` file.

For explicit IDs, `TRIBE_Game::get_string` checks `StringTableX` first.
It falls back to the base `StringTable` lookup. Help IDs follow the same
lookup when `TPanel::get_string` reads the stored help ID.

For civilization text, the source passes selector `0x69` to
`TRIBE_Game::get_string2` with `master_player_id`. That function maps the
player value to a target string ID, then uses the same expansion-first path.
Selector `0x69` is not itself a resource ID.

The exact extraction outputs are under `build/resource-strings/`:

- `dlg_smsg-language.json`
- `dlg_smsg-language-266c.json`
- `dlg_smsg-languagex-all.json`
- `dlg_smsg-original-languagex-all.json`

| ID | Proposed name and source use | Lookup path | Base DLL: full SHA-256, language, result | Runtime expansion DLL: full SHA-256, language, result | Pinned original expansion DLL: full SHA-256, language, result |
| --- | --- | --- | --- | --- | --- |
| `0x2667` | `IDS_SEND_MESSAGE_TITLE`; main dialog title | `create_text` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Send Messages to` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x2668` | `IDS_SEND_MESSAGE_CHAT`; chat title and quick-chat title | `create_text` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Chat` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x2669` | `IDS_SEND_MESSAGE_ALLIES`; allies radio title | `create_text` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Allies` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x266A` | `IDS_SEND_MESSAGE_ENEMIES`; enemies radio title | `create_text` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Enemies` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x266B` | `IDS_SEND_MESSAGE_EVERYONE`; everyone radio title | `create_text` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Everyone` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x266C` | `IDS_BUTTON_RETURN_TO_GAME`; return button caption | `create_button` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Return to Game` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x266D` | `IDS_QUICK_MESSAGE_COMMENT`; quick-message title for `AsTaunt` | `create_text` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Comment` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x266E` | `IDS_SEND_MESSAGE_SELECT_PLAYER`; select-player radio title | `create_text` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Select Player` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x27F7` | `IDS_CIVILIZATION_EGYPTIAN`; master player ID 1 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Egyptian` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x27F8` | `IDS_CIVILIZATION_GREEK`; master player ID 2 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Greek` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x27F9` | `IDS_CIVILIZATION_BABYLONIAN`; master player ID 3 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Babylonian` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x27FA` | `IDS_CIVILIZATION_ASSYRIAN`; master player ID 4 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Assyrian` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x27FB` | `IDS_CIVILIZATION_MINOAN`; master player ID 5 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Minoan` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x27FC` | `IDS_CIVILIZATION_HITTITE`; master player ID 6 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Hittite` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x27FD` | `IDS_CIVILIZATION_PHOENICIAN`; master player ID 7 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Phoenician` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x27FE` | `IDS_CIVILIZATION_SUMERIAN`; master player ID 8 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Sumerian` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x27FF` | `IDS_CIVILIZATION_PERSIAN`; master player ID 9 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Persian` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x2800` | `IDS_CIVILIZATION_SHANG`; master player ID 10 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Shang` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x2801` | `IDS_CIVILIZATION_YAMATO`; master player ID 11 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Yamato` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x2802` | `IDS_CIVILIZATION_CHOSON`; master player ID 12 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Choson` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x2804` | `IDS_CIVILIZATION_UNKNOWN`; default mapping | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Unknown` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x2806` | `IDS_CIVILIZATION_ROMAN`; master player ID 13 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, empty slot | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, `Roman` | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, `Roman` |
| `0x2807` | `IDS_CIVILIZATION_CARTHAGINIAN`; master player ID 14 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, empty slot | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, `Carthaginian` | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, `Carthaginian` |
| `0x2808` | `IDS_CIVILIZATION_MACEDONIAN`; master player ID 16 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, empty slot | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, `Macedonian` | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, `Macedonian` |
| `0x2809` | `IDS_CIVILIZATION_PALMYRAN`; master player ID 15 | `get_string2(0x69, ...)` -> `TRIBE_Game::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, empty slot | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, `Palmyran` | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, `Palmyran` |
| `0x7531` | existing `IDS_HELP_OK`; OK button help | `set_help_info` -> later `TPanel::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, missing ID | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x767A` | `IDS_HELP_CHAT_INPUT`; chat input help | `set_help_info` -> later `TPanel::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Type a message. Press ENTER to send.` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x767B` | `IDS_HELP_CHAT_ALLIES`; allies radio help | `set_help_info` -> later `TPanel::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Click to send a message to all allies.` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x767C` | `IDS_HELP_CHAT_ENEMIES`; enemies radio help | `set_help_info` -> later `TPanel::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Click to send a message to all enemies.` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x767D` | `IDS_HELP_CHAT_ALL_PLAYERS`; everyone radio help | `set_help_info` -> later `TPanel::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Click to send a message to all players.` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x767E` | `IDS_HELP_CHAT_RECIPIENTS`; recipient radio help | `set_help_info` -> later `TPanel::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Select which players receive your messages.` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |
| `0x767F` | `IDS_HELP_CHAT_PLAYER`; player checkbox help | `set_help_info` -> later `TPanel::get_string` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, `0x0409`, `Click to send a message to this player.` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, `0x0409`, missing ID | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, `0x0409`, missing ID |

Empty slots and missing IDs are separate findings. The base DLL has empty
slots for `0x2806`-`0x2809`. Its `0x7531` entry is missing. The expansion DLL
supplies the four Rise of Rome names. The pinned original expansion supplies
the same four names. No source lookup was replaced with text.

## Comments, formatting, and risk

The source uses 1TBS braces for the assigned definitions. It joins short action
signatures. It preserves source order, casts, types, storage, call order,
control flow, literal values, and public symbol identity.

The source keeps the original empty fourth-radio-button branch. It now has a
short comment that states the observed behavior. The original action packet
supports that empty branch. No bug repair or structural rewrite was added.

Parameter and local-name changes do not change ABI types, order, layout, or
symbol identity. `IDS_HELP_OK` expands to the existing `0x7531` value.
The added include and formatting can change debug line records or compiler
output. Generated code, relocations, direct targets, and runtime behavior are
unvalidated.

No header change is needed for the source names. The assigned header uses
unnamed declarations. The group owner still owns `include/dlg_smsg.h`.

## Shared-file requests

### Request to root: `include/resource_ids.h`

Add these base-language macros. They are new cleanup names, not recovered
original symbols. Keep the listed values and leave the source literals numeric
until the declarations exist.

```cpp
#define IDS_SEND_MESSAGE_TITLE              0x2667
#define IDS_SEND_MESSAGE_CHAT               0x2668
#define IDS_SEND_MESSAGE_ALLIES             0x2669
#define IDS_SEND_MESSAGE_ENEMIES            0x266A
#define IDS_SEND_MESSAGE_EVERYONE           0x266B
#define IDS_BUTTON_RETURN_TO_GAME           0x266C
#define IDS_QUICK_MESSAGE_COMMENT           0x266D
#define IDS_SEND_MESSAGE_SELECT_PLAYER      0x266E
#define IDS_CIVILIZATION_EGYPTIAN           0x27F7
#define IDS_CIVILIZATION_GREEK              0x27F8
#define IDS_CIVILIZATION_BABYLONIAN         0x27F9
#define IDS_CIVILIZATION_ASSYRIAN           0x27FA
#define IDS_CIVILIZATION_MINOAN             0x27FB
#define IDS_CIVILIZATION_HITTITE            0x27FC
#define IDS_CIVILIZATION_PHOENICIAN         0x27FD
#define IDS_CIVILIZATION_SUMERIAN           0x27FE
#define IDS_CIVILIZATION_PERSIAN            0x27FF
#define IDS_CIVILIZATION_SHANG              0x2800
#define IDS_CIVILIZATION_YAMATO             0x2801
#define IDS_CIVILIZATION_CHOSON             0x2802
#define IDS_CIVILIZATION_UNKNOWN            0x2804
#define IDS_CIVILIZATION_ROMAN              0x2806
#define IDS_CIVILIZATION_CARTHAGINIAN       0x2807
#define IDS_CIVILIZATION_MACEDONIAN         0x2808
#define IDS_CIVILIZATION_PALMYRAN           0x2809
#define IDS_HELP_CHAT_INPUT                 0x767A
#define IDS_HELP_CHAT_ALLIES                0x767B
#define IDS_HELP_CHAT_ENEMIES               0x767C
#define IDS_HELP_CHAT_ALL_PLAYERS           0x767D
#define IDS_HELP_CHAT_RECIPIENTS            0x767E
#define IDS_HELP_CHAT_PLAYER               0x767F
```

Evidence for every request is in the resource table above. The source call
sites and `TRIBE_Game::get_string2` establish each role. The runtime and
pinned original resource hashes are recorded for every ID.

## Validation status

Compilation, matching, audits, tests, and games were **NOT RUN**. I did not
invoke a compiler, build, matching check, audit, test, or game command.
I ran only evidence extraction, resource extraction, `git diff --check`, and
full Git diff review. Compiler-output equality, relocation equality,
direct-target equality, and runtime behavior remain unvalidated.
