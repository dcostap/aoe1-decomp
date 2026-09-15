# `src/tplayer.cpp` cleanup report

## Scope and delivery files

This correction changes only these two files:

- `src/tplayer.cpp`
- `decomp_notes/source_cleanup/wave04/tplayer.md`

Relative to the initial cleanup commit, the first correction moved opening braces only.
Every function definition in `src/tplayer.cpp` now uses one true brace style (1TBS).
The second correction restores the baseline variable ownership in `TRIBE_Player::save`.
This follow-up applies two root-approved direct resource substitutions.
It does not change types, scopes, call targets, buffers, argument order, fallback,
control flow, or data flow.

The common base is `c22ba4258c45b1178181e185d60a3b09a1add617`.
The full initial cleanup commit is `b55b6d4e480488bf47d0a8ceed53639dc70ca6ae` (`Clean up tplayer source names`).
The first correction commit is `93bec630cac14f33d4dcab822779006a3d114ec4` (`Normalize tplayer function braces`).
The save correction commit is `e35426b10aa87044da20b21f20c7e76395526fdc` (`Restore tplayer save handle ownership`).
The current correction follows that commit.

Source blob hashes:

- Common-base source: `bd436aa1bd57a02ca1c26ab69a5e3ce63aced680`.
- Initial cleaned source: `31f7862b3b78d76f7fa056bcee982c71d958d1ba`.
- Corrected source after the approved resource substitutions: `ba4edddfdcb7925b51576dbf574f1abd2e2150d1`.

The initial cleanup recovered evidence-supported names for AI, command, cost, scenario,
mouse, Gaia, and civilization setup code. It also recorded the proposed resource names
below. This correction keeps those names unchanged.

## PDB evidence

The procedure-scoped extraction is in `build/tplayer_evidence/pdb_records.txt`.
It contains 106 procedure records. I inspected every record and every handwritten
function definition in this source. The records include two compiler-generated scalar
deleting destructors without handwritten definitions.

The inspected groups include:

- Both `TRIBE_Player` constructors, the destructor, load and save functions, and scenario functions.
- Cost, availability, command, payment, reimbursement, technology, and population functions.
- Random-start, object-cost, research-cost, AI, logging, build, training, trader, gatherer, and diplomacy functions.
- AI information, notification, civilization selection, and build-list selection functions.
- All 16 civilization setup functions.
- Status, achievement, victory, attribute, selected-object, mouse, and Gaia functions.

The PDB extraction hash is `e83eecb60607fac8ad2196b27e97f085b7c9567a85907bdfea0a8a78248b5f45`.

## Root-approved resource substitutions

Root approved these two direct substitutions in
`decomp_notes/source_cleanup/wave04_root_review.md`, Owner 25:

| Proposed name | ID or range | Evidence and use |
|---|---:|---|
| `IDS_FILE_NONE` | `0x2775` | Loads the exact payload ` <None> ` into the unused `noneString` buffer. |
| `IDS_AI_FILE_RANDOM` | `0x277B` | Loads `Random` into `randomString` and compares it with build-list, city-plan, and ruleset inputs. |

The source uses these approved names at `src/tplayer.cpp:1612-1613`.
The unused `noneString` load remains in place.

The imported root header provenance is:

- `c7e587ce0993e28d5d6620e5b358dbb8286cfe88` added the AI file names.
- `bf943f3339643ee5beca7dd74e98b4cb729e48d3` corrected `0x2775` to `IDS_FILE_NONE`.
- The resulting root header blob is `3670c49563f971137b89644d4a0069796cf3d2af`.

The root-owned `include/resource_ids.h` was not changed in this worker tree.
The source now includes that owner-managed header and does not define its macros.

The prior `IDS_CIVILIZATION_NAME_BASE` and `IDS_BUILD_LIST_NAME_BASE` requests are withdrawn.
The `0x27F6` arithmetic and `0x26930` arithmetic remain numeric due to the proved limitations.
The civilization arithmetic does not provide one complete expansion mapping, and the
checked files do not prove the missing build-list payloads under an unchecked `STRING=` override.

## Complete resource evidence

The extraction used `tools/inspect_pe_strings.py` with resource type `RT_STRING`,
language `0x0409` (`1033`), and these selected IDs:

- `0x2775`, `0x277B`, and `0x27F6`.
- Every ID in `0x27F7..0x2806`.
- Every ID in `0x26930..0x269AC`.

The tool reads PE resource bytes. It does not load or execute a DLL. It reports
`missing` when no resource row exists. It reports `empty` when a row exists with
zero UTF-16 units.

Complete extraction outputs are preserved in `build/tplayer_evidence/`:

- `runtime_languagex_tplayer_ids_complete_v2.json` — current runtime expansion override.
- `runtime_language_tplayer_ids_complete_v2.json` — current runtime base fallback.
- `original_xpack_languagex_tplayer_ids_complete_v2.json` — pinned original expansion reference.
- `runtime_language_tplayer_ids.json` — initial cleanup extraction, preserved unchanged.

The complete output hashes are:

- `runtime_languagex_tplayer_ids_complete_v2.json`: `31b659cbbf14fcc1e689ea25c2da69a70703bb605d893156045490bb97676cb1`.
- `runtime_language_tplayer_ids_complete_v2.json`: `44df9dca631428444fb7fe917038be89d5f63a0ebc63516a16350bf4ed573abd`.
- `original_xpack_languagex_tplayer_ids_complete_v2.json`: `d00b3fcc99cafe043c991f25a6c7de75b5325599b8a7eab42d326efe67941444`.
- Initial extraction `runtime_language_tplayer_ids.json`: `a3543469d765ba433b3d06ef6eb5c0c462a8cd12055a1b206d6f0db7a151cd6d`.

### Singleton IDs

| ID | Runtime `languagex.dll` override | Runtime `language.dll` fallback | Pinned original XPack `languagex.dll` |
|---:|---|---|---|
| `0x2775` | missing | ` <None> ` | missing |
| `0x277B` | missing | `Random` | missing |

The runtime base supplies ` <None> ` for `0x2775` and `Random` for `0x277B`.
The current runtime expansion and pinned original expansion both report these IDs as missing.

### Civilization IDs

| ID | Runtime `languagex.dll` override | Runtime `language.dll` fallback | Pinned original XPack `languagex.dll` |
|---:|---|---|---|
| `0x27F6` | missing | empty | missing |
| `0x27F7` | missing | `Egyptian` | missing |
| `0x27F8` | missing | `Greek` | missing |
| `0x27F9` | missing | `Babylonian` | missing |
| `0x27FA` | missing | `Assyrian` | missing |
| `0x27FB` | missing | `Minoan` | missing |
| `0x27FC` | missing | `Hittite` | missing |
| `0x27FD` | missing | `Phoenician` | missing |
| `0x27FE` | missing | `Sumerian` | missing |
| `0x27FF` | missing | `Persian` | missing |
| `0x2800` | empty | `Shang` | empty |
| `0x2801` | empty | `Yamato` | empty |
| `0x2802` | empty | `Choson` | empty |
| `0x2803` | empty | empty | empty |
| `0x2804` | empty | `Unknown` | empty |
| `0x2805` | empty | `Tribe Name` | empty |
| `0x2806` | `Roman` | empty | `Roman` |

For the full build-list range `0x26930..0x269AC`, every ID is missing in all
three selected files. The complete JSON outputs contain each requested ID in
`missing_ids`, so the range result is not an extrapolation.

The inspected PE files and hashes are:

- Runtime base `runtime/language.dll`: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- Runtime expansion `runtime/languagex.dll`: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
- Pinned original `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

## Runtime override and fallback path

`RGE_Base_Game` sets `string_dll_name` to `language.dll` in
`src/basegame.cpp:160`. Base setup loads that name at `src/basegame.cpp:318-319`.
The checked runtime file is `runtime/language.dll`.

`TRIBE_Game::setup` sets the expansion name to `languagex.dll` at
`src/tribegam.cpp:388`. A `STRING=` command-line option replaces that name.
The setup loads the selected name at `src/tribegam.cpp:406`. The checked default
runtime override is `runtime/languagex.dll`.

`rge_base_game` points to the `TRIBE_Game` object created in `src/main.cpp:83`.
Its virtual `get_string` call reaches `TRIBE_Game::get_string` at
`src/tribegam.cpp:812`. That function calls `LoadStringA` on `StringTableX` first.
A zero result calls `RGE_Base_Game::get_string`, which reads `StringTable`.
A failed base lookup clears the destination buffer at `src/basegame.cpp:766-771`.

Therefore, the four direct `rge_base_game->get_string` calls in `tplayer.cpp`
use this path: selected expansion DLL first, then runtime `language.dll` fallback.
An empty expansion slot returns zero and therefore falls through to the base DLL.
For example, `0x2806` returns `Roman` from the expansion, while `0x2800..0x2802`,
`0x2804`, and `0x2805` fall back to the base text. The empty `0x2803` remains empty.
All build-list IDs remain empty after both lookups fail.

## Header requests

Please review these requests in the owning changes:

- `include/resource_ids.h`: the two approved definitions are owned by root.
  No civilization-name or build-list-name definition is requested.
- `include/tplayer.h`: add parameter names that match the cleaned definitions where useful.
  Keep all declaration types and signatures unchanged.
- `include/tplayer.h` and the first `TRIBE_Player` constructor: the PDB reports a
  stack name `reallyLoadAI`, but the source and header expose a three-argument constructor.
  Do not force that name into the signature without ABI review.

## Unresolved evidence

The PDB reports reused stack homes. I did not force uncertain names into declarations.

In `get_mouse_pointer_action_vars`, the PDB reports `RtClickTable` with an `int` type
at a reused stack home. The source keeps the proven table-pointer type.

The PDB reports overlapping cost-wrapper locals and does not expose every decompiler
temporary. The source keeps existing types, scopes, and declarations for those cases.

## Correction history and validation status

- Common base: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Initial cleanup: `b55b6d4e480488bf47d0a8ceed53639dc70ca6ae`.
- 1TBS correction: `93bec630cac14f33d4dcab822779006a3d114ec4`.
- Current correction: parent `93bec630cac14f33d4dcab822779006a3d114ec4`.
  In `TRIBE_Player::save`, `save_file` retains the file handle, and `outfile`
  is overwritten with the AI-present flag before `rge_write`.
  All file operations use `save_file`, including `playerAI->save(save_file)`.
- Follow-up resource correction: parent `e35426b10aa87044da20b21f20c7e76395526fdc`.
  It uses `IDS_FILE_NONE` and `IDS_AI_FILE_RANDOM` at the two direct call sites.
  It leaves the `0x27F6` and `0x26930` arithmetic numeric.

No build, compiler check, matching check, audit, test, or game run was performed.
