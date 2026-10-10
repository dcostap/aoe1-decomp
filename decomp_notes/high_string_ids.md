# String IDs above 0xFFFF

## Scope

The starting commit is `6af07fe2a`. This follow-up applies the 16-bit `LoadStringA` rule from
`decomp_notes/build_list_names.md` to the rest of the repository.

## Source changes

- `scr_game.cpp` market buttons now use `STRING_ID_HELP_GAME_TRADE_FOOD_FOR_GOLD` (`0x1A25C`),
  `..._WOOD_FOR_GOLD` (`0x1A25D`), and `..._STONE_FOR_GOLD` (`0x1A25E`).
  These IDs load `0xA25C` through `0xA25E` from the base `runtime/language.dll`: "Click to trade food for gold." and
  the matching wood and stone texts. The pinned expansion slots are empty, so the base text is used.
  The `0x265AF` beside them is the help page ID and stays numeric.
- The train and build buttons pass `master->string_id2 + 100000` as their help string.
  `100000` is now `STRING_ID_CREATION_HELP_OFFSET`.
  For example, creation string 6016 ("Build War Galley") plus 100000 is 106016, which loads 40480,
  "Click to build a War Galley."
  In the base DLL, 64 of the 67 creation strings from 6000 through 6999 have such a help string.
  The three without one are 6022 ("Build Build-Road"), 6118 ("Create Horse"), and 6133 ("Build Market (M)").

## Tool change

`tools/inspect_pe_strings.py --id` now looks up `id & 0xFFFF`, as `LoadStringA` does.
It lists each changed ID under `loaded_ids`. A test with `0x1A25C`, `0x103F`, and `0x7531` returned
`0xA25C` text, `0x103F` text, and `0x7531` as missing, as before.

## Corrected notes

Earlier notes reported these IDs as missing. Each note now has a dated correction:

- `0x1D4F7` (`STRING_ID_HELP_NOTICE`): `wave01/scr_main.md`, `wave01/owner-03.md`, and `wave01_root_review.md`.
- `0x1D4ED` through `0x1D4F0` (inventory help formats): `wave03/tpnl_inv.md`.
- `0x26930` through `0x269AC` (build lists): `wave04/tplayer.md` and `wave04_root_review.md`.

`game_command_help_ids.md` said that heal, convert, and repair take their text from the expansion DLL.
Those expansion slots are empty, so the base DLL supplies the text. The table now says so.

No other string ID above 0xFFFF appears in `src/` or `include/`.
Other "missing" findings in the notes concern IDs below 0x10000, and this rule does not affect them.

## Validation

- An audit of the 45 groups that depend on `src/scr_game.cpp` or `include/resource_ids.h` compiled all groups.
  All 1,171 exact claims passed (`build/cleanup-2026-10-10/high-ids`).
- All 45 non-debug object payloads equal the `c41e6039a` baseline.
- `git diff --check` and the line-ending check passed. clang-format 21.1.8 was applied to `src/scr_game.cpp`.

No linked executable build, image audit, automated tests, or runtime suites ran.
