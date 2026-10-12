# Source cleanup: `src/scr_sing.cpp`

## Handoff

- Module: `src/scr_sing.cpp`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Final source-cleanup commit: `de015f711aa467725ddecf5bdf4a3c87dc1be1d9`
- Branch: `cleanup/staging-20260915-23`
- Changed paths:
  - `src/scr_sing.cpp`
  - `workflow/decomp_notes/source_cleanup/wave01/scr_sing.md`

The report commit follows the source-cleanup commit. The handoff response records its full hash.

The approved shared resource commit is `c9ba20d160541d928b5d9e55e1d02dce5a784e0c`.
This worker cherry-picked it locally as `90059e0b3cccac0e76bc94adfffd52ba42882554`.
That worker-local header commit is not a module commit for owner integration.
Exclude `90059e0b3cccac0e76bc94adfffd52ba42882554` when integrating this module.

## Scope and evidence

This worker read the repository contract and all listed source-cleanup guides.
It read the module header, registry, procedure packets, scoped PDB records, and resource evidence.
It used the original executable packets under `inventory/functions/004B/`.

The registry records four normal functions in `Scr_sing.cpp` order. Their prior claims are `matching`.
The edited source was not rechecked by a compiler or matcher.

| VA | PDB lines | bytes | owner |
| --- | ---: | ---: | --- |
| `004B69A0` | 55-106 | 573 | `TribeSPMenuScreen::TribeSPMenuScreen()` |
| `004B6C00` | 111-117 | 129 | `TribeSPMenuScreen::~TribeSPMenuScreen()` |
| `004B6C90` | 123-128 | 33 | `TribeSPMenuScreen::handle_idle()` |
| `004B6CC0` | 134-318 | 1138 | `TribeSPMenuScreen::action` |

The PDB also records generated vector-deleting destructor `004B6BE0`.
That function has no handwritten source owner and was not edited.

## Original-name recovery

### `004B69A0` — `TribeSPMenuScreen::TribeSPMenuScreen()`

The register record names `this` as `TribeSPMenuScreen*` in `ECX`.
The stack record names `tabList` as `TPanel*[24 bytes]` at `-0x24`.
The source already used `tabList`, so it stayed unchanged.

The loop names `i` and `id`, and local `cancel`, have no matching scoped PDB records.
They remain unchanged. I do not claim them as recovered original names.

### `004B6C00` — `TribeSPMenuScreen::~TribeSPMenuScreen()`

The register record names `this` as `TribeSPMenuScreen*` in `ECX`.
The packet has no other PDB name records.
The existing `panel` and `i` locals remain unchanged.

### `004B6C90` — `TribeSPMenuScreen::handle_idle()`

The register record names `this` as `TribeSPMenuScreen*` in `ECX`.
The packet has no local or parameter records.
No name change was needed.

### `004B6CC0` — `TribeSPMenuScreen::action`

The register record names `this` as `TribeSPMenuScreen*` in `ECX`.
The PDB records these parameters:

- `fromPanel`, `TPanel*`, at `+0x4`.
- `actionIn`, `long`, at `+0x8`.
- `a1`, `unsigned long`, at `+0xc`.
- `a2`, `unsigned long`, at `+0x10`.

The source now uses those exact mixed-style spellings.
The PDB records locals `players`, `char**`, at `+0x8` and `curr_player`, `long`, at `+0xc`.
Their types and use match the prior `list` and `count` declarations.
The source now uses the recovered names `players` and `curr_player`.

The PDB reuses the `actionIn` and `a1` stack offsets for these locals.
I changed names only. I did not split buffers or reshape declarations.

The locals `info`, `result`, and loop `i` have no matching scoped PDB records.
They remain unchanged. I do not claim them as recovered original names.

## Source changes and risk

- Restored PDB parameter names `fromPanel`, `actionIn`, `a1`, and `a2`.
- Restored PDB local names `players` and `curr_player`.
- Applied 1TBS braces to all four definitions.
- Joined the short action signature and its opening brace.
- Preserved source order, control flow, calls, types, storage, literals, and lookup order.
- Preserved the existing local-receiver comment and `cancel` declaration.
- Applied eight reviewed shared resource macros without changing their values.
- Added no structural rewrite, helper, cast removal, bug repair, or modern language feature.
- Added no new source comment or local constant.

The parameter and local renames do not change types, layout, calling convention, or symbols.
Formatting can change debug line records. Compiler-output and relocation risk remains unvalidated.

## Header request

The assigned header was read but not edited.
Request `include/scr_sing.h` owner 03 to change only the declaration names:

```cpp
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
```

The declaration keeps the existing function name, types, order, virtual slot, and ABI.
This request is not required for the source definition to compile.

The worker did not edit `include/resource_ids.h`.
The approved shared commit added the requested macros there.
The local cherry-pick `90059e0b3cccac0e76bc94adfffd52ba42882554` must stay outside module integration.

## Resource mapping requests

The source uses resource IDs through `TPanel::get_string`.
The `0x76` value is a button Y coordinate in the text-overload call.
It is not a resource ID and has no mapping request.

For every row below, the base evidence file is:
`C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`.
Its SHA-256 is `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
The resource type is `RT_STRING`, and each returned entry uses language `0x0409` (`1033`).

The expansion evidence file is:
`C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`.
Its SHA-256 is `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
It has `RT_STRING` resources, but every requested ID below is missing.
The missing entries have no returned language record.

The pinned original expansion file is:
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`.
Its SHA-256 is `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
It also has `RT_STRING` resources, but every requested ID below is missing.

| ID | Proposed macro | Purpose evidence | Base text |
| --- | --- | --- | --- |
| `0x3EA` | `STRING_ID_BUTTON_CLOSE` | Long `create_button` call creates the close button. | `X` |
| `0x2404` | `STRING_ID_MENU_SINGLE_PLAYER_TITLE` | `create_text` sets the screen title. | `Single Player Menu` |
| `0x2405` | `STRING_ID_MENU_SCENARIO` | `button[3]->set_text` labels the scenario route. | `Scenario` |
| `0x2407` | `STRING_ID_MENU_SAVED_GAME` | `button[4]->set_text` labels the saved-game route. | `Saved Game` |
| `0x2408` | `STRING_ID_MENU_CAMPAIGN` | `button[1]->set_text` labels the campaign route. | `Campaign` |
| `0x2409` | `STRING_ID_MENU_SINGLE_PLAYER_CANCEL` | `button[5]->set_text` labels the return route. | `Cancel` |
| `0x240A` | `STRING_ID_MENU_RANDOM_MAP` | `button[0]->set_text` labels the random-map route. | `Random Map` |
| `0x240B` | `STRING_ID_MENU_DEATH_MATCH` | `button[2]->set_text` labels the death-match route. | `Death Match` |

These are new descriptive cleanup names. No original macro name is claimed.
The proposed macros retain the existing numeric values and introduce no storage.
The shared commit `c9ba20d160541d928b5d9e55e1d02dce5a784e0c` added them to `include/resource_ids.h`.
The source commit `de015f711aa467725ddecf5bdf4a3c87dc1be1d9` replaced these eight uses.
The worker did not edit the shared header.

The lookup path starts at `TPanel::get_string`, which calls `rge_base_game->get_string`.
The base game loads `language.dll` into `StringTable`.
The tribe game checks `StringTableX` first, then falls back to the base lookup.
The expansion setup loads `languagex.dll`, or a `STRING=` override, into `StringTableX`.
Therefore, these missing expansion entries fall back to the base `language.dll` entries.

## Unresolved items

- `include/scr_sing.h` still uses `panel`, `code`, `p3`, and `p4`.
  The header owner must review the proposed PDB-backed declaration names.
- PDB stack storage overlaps action parameters and recovered locals.
  The source keeps one declaration for each semantic local and does not imitate PDB storage.
- The `0x76` coordinate remains numeric because it is not a resource ID.
- The `cancel` local remains because prior source evidence ties it to the two hotkey stores.

## Commit records

- `aff63bc7131506e321e22eae2579e6f38e2394d1`: source names and formatting.
- `9ff38c23120dcaab2e0a6fe07dd164a133d8664a`: initial cleanup report.
- `90059e0b3cccac0e76bc94adfffd52ba42882554`: worker-local cherry-pick of shared header commit.
- `de015f711aa467725ddecf5bdf4a3c87dc1be1d9`: source resource substitutions.

The report update commit follows. The handoff response records its full hash.

## Validation status

I ran `git diff --check` and inspected the complete source diff.
Compilation, matching, audits, tests, and games were **NOT run**.
No compiler or build command was invoked.
The final report commit hash is supplied in the handoff response.
