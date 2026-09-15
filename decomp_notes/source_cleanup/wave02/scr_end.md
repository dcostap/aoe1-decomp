# `src/scr_end.cpp` cleanup report

## Delivery

- Module: `src/scr_end.cpp`
- Paired header: `include/scr_end.h` (owned by owner 11)
- Worker branch: `cleanup/staging-20260915-94`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `58c4d027aee629338711daea2d788dbc36965a34`
- Changed source: `src/scr_end.cpp`
- Changed report: `decomp_notes/source_cleanup/wave02/scr_end.md`

The final source commit changes only the assigned source. The report is a
separate documentation-only commit.

Correction history:

- `e252a26e474b9dac0f2c1acc4365f663336a3f01` recovered the PDB names and
  applied the initial 1TBS placement.
- `87b8556a3ec3d4084e2ec55a88d8f0e91b251702` compacted the short constructor
  and action signatures into one line. It made no semantic change.
- Root approved the shared resource mapping in
  `027da42cb19a66cd9d07a7c357ab223034f26cdd`. Integration imported the
  definition in `bdb8bc1afb50e9e28b76d09fe731855eafa66460` (`bdb8bc1af`). This
  worker then replaced the action call's literal with the approved macro.

## PDB inspection coverage

I inspected every source-owned function and the compiler-generated destructor
record in the procedure-scoped PDB inventory. The source inventory is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`,
SHA256 `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.

| VA | Function | PDB parameters, locals, and registers | Result |
| --- | --- | --- | --- |
| `004936D0` | `TribeEndScreen::TribeEndScreen` | Stack `titleText` `+0x4` (`char*`), `textText` `+0x8` (`char**`), `textLineCount` `+0xc` (`int`), and `backgroundName` `-0x18` (`char[10]`); register `this` in `ecx` | Recovered all four spellings. |
| `00493C00` | `TribeEndScreen::~TribeEndScreen` | No stack symbols; register `this` in `ecx` | No identifier mapping. Brace style only. |
| `00493C90` | `TribeEndScreen::action` | Stack `fromPanel` `+0x4` (`TPanel*`), `actionIn` `+0x8` (`long`), `a1` `+0xc` (`unsigned long`), and `a2` `+0x10` (`unsigned long`); register `this` in `ecx` | Recovered all four spellings. |
| `00493BE0` | Compiler-generated scalar deleting destructor | Stack `__flags` `+0x4` (`unsigned int`); register `this` in `ecx` | No source body. Not edited. |

The packet files used for the three normal bodies are:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0049/004936D0_TribeEndScreen.txt`, SHA256 `0096d52b0a1a278520b349f3843ed20585f078b503a8f227da60bca71b4255e1`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0049/00493C00_TribeEndScreen.txt`, SHA256 `bef79c6569250f85de68f1da104eea9c17fdee55a27ef1d6d2fc4f6f4717a9e6`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0049/00493C90_action.txt`, SHA256 `4c903069229c2769f137f5547db95422073c4d423e3adace95a0d7ad26fc2a0f`.

## Source changes and evidence

The constructor now uses the recovered PDB names:

- `title_text` -> `titleText`
- `text_list` -> `textText`
- `text_count` -> `textLineCount`
- `background_name` -> `backgroundName`

The action method now uses the recovered PDB names:

- `panel` -> `fromPanel`
- `id` -> `actionIn`
- `param3` -> `a1`
- `param4` -> `a2`

The names match their procedure records, stack offsets, types, and uses. No
uncertain reused-stack-slot mapping remains. I changed no type, scope,
declaration order, evaluation order, call, cast, literal value, member, or ABI
signature.

I moved the three function opening braces to 1TBS placement. No new comment was
needed. The code and existing names already explain the panel setup and cleanup
without a useful sparse comment.

## Resource and constant evidence

The action method uses `IDS_ACHIEVEMENTS_TITLE` at `src/scr_end.cpp:117`. The
approved macro expands to `0x269E`. The call passes the result to
`TribeAchievementsScreen` as its title. A second call in `src/dlg_menu.cpp:177`
uses the same ID when opening the same screen. These call sites establish the
purpose as the Achievements screen title.

The approved shared declaration is:

```c
#define IDS_ACHIEVEMENTS_TITLE 0x269E
```

This is a new descriptive cleanup name, not a recovered original macro name.
The definition is root-approved and imported from the integration header.
This worker's substitution changed only the preprocessor spelling. The value
remains `0x269E`.

The lookup path is:

1. `TribeEndScreen::action` calls `TPanel::get_string(int)`.
2. `TPanel::get_string` calls `rge_base_game->get_string` with its shared
   buffer.
3. The virtual `TRIBE_Game::get_string` checks `StringTableX` first.
4. On a miss, it calls `RGE_Base_Game::get_string`, which checks `StringTable`.
5. The PDB packet records the base match in `language.dll`.

I checked ID `0x269E` in each resource input:

| File | SHA256 | Language/result |
| --- | --- | --- |
| `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5` | `0x0409`: `Achievements` |
| `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39` | ID missing; no empty slot reported |
| `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll` | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2` | ID missing; no empty slot reported |

The runtime expansion file is therefore an override source that misses this
ID, and the runtime base file supplies the English fallback. The original
expansion reference also misses the ID. Missing blocks are distinct from empty
slots here; the extraction reported a missing ID, not an empty slot.

Shared-file provenance and request:

- Root approved `IDS_ACHIEVEMENTS_TITLE` with value `0x269E` in
  `027da42cb19a66cd9d07a7c357ab223034f26cdd`. Integration imported
  `include/resource_ids.h` at
  `bdb8bc1afb50e9e28b76d09fe731855eafa66460` (`bdb8bc1af`). The source substitution is in
  worker commit `58c4d027aee629338711daea2d788dbc36965a34`.
- Owner 11 owns `include/scr_end.h`. No header edit is required. The source
  parameter names can change without changing its unnamed declaration or ABI.

## Possible code-generation effects

The cleanup changed identifier spellings, function-brace placement, and the
resource ID token. These edits can change debug line records and object debug
metadata. The approved macro preserves the literal value and call arguments.
The edits do not intentionally change executable statements, data, relocations,
call targets, storage layout, types, or symbol identity. Compilation and
matching validation remain required.

The original executable evidence path is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The source cleanup used the packet OriginalAsm and PDB records; it did not
modify the original executable or the preserved baseline build.

## Validation limits

I ran resource extraction, Git diff review, and `git diff --check`. I ran the
resource tool's `--help` before extraction.

Compilation, matching, audits, and tests were not run. I also did not run a
build, linker, game, or runtime command.
