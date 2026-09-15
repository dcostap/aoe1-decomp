# Resource strings and ID names

Approved convention for the [source-cleanup pilot and wave](source_cleanup.md).

## Read the actual resource file

Use `tools/inspect_pe_strings.py` to read Win32 `RT_STRING` resources locally.
The tool reads PE bytes. It does not load or execute the DLL.
Run its `--help` before use.

```cmd
python tools/inspect_pe_strings.py --help
python tools/inspect_pe_strings.py --dll runtime/language.dll --id 0x103F 0x104A
python tools/inspect_pe_strings.py --dll runtime/language.dll --contains "Town Center"
python tools/inspect_pe_strings.py --dll runtime/language.dll --list --output build/resource-strings/language.json
```

IDs accept decimal or `0x` notation. `--language` selects a language ID when needed.
Output includes the file path, SHA256, numeric ID, language, block, slot, UTF-16 length, and exact decoded text.
JSON escaping preserves control characters and formatting tokens.
Text search does not change returned text.

An empty string-table slot does not prove whether the ID was intentionally empty or unused.
Missing blocks and empty slots are different findings. Do not invent a meaning for either.
The tool does not extract dialog captions, menus, or arbitrary binary resources.
Request further local extraction support when a different resource type is needed.

Always specify the file. Similar DLL names do not prove interchangeable contents.
In a lean worktree, use the absolute shared evidence path supplied in the assignment.
Determine which resource module the game loads at the call site.
Inspect override and fallback paths, not just a file that happens to contain the ID.
In `src/tribegam.cpp`, `TRIBE_Game::get_string` tries `StringTableX` before the base game's string lookup.
For that path, inspect both actual runtime DLLs and record which lookup supplies the text.
Prefer repo-local original evidence; inspect staged runtime files when they are the actual resource input.
Record their provenance and hashes. Do not describe a runtime file as the pinned original without evidence.

For example, the local investigation found:

- `runtime/language.dll`, SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- Language `0x0409`: ID `0x103F` contains `H`; ID `0x104A` contains `M`.
- The inspected pinned `orig/.../XPack/languagex.dll` does not contain ID `0x103F`.

Thus, looking in an arbitrary expansion DLL would miss this base-language hotkey.
The corresponding uses in `src/scr_game.cpp` provide the purpose; the single character alone does not.

## Naming convention

Preserve verified original symbols first.
Otherwise use uppercase `IDS_` names that describe purpose, not just text or numeric value.
These are new cleanup names unless original evidence establishes otherwise.

Recommended forms:

- `IDS_HOTKEY_VIEW_TOWN_CENTER`
- `IDS_HOTKEY_MOVE`
- `IDS_ERROR_<CONDITION>`
- `IDS_MENU_<ACTION>`
- `IDS_HELP_<SUBJECT>`
- `IDS_<SUBJECT>_NAME`
- `IDS_<SUBJECT>_FORMAT` for a verified formatted message

These patterns do not imply that the original macro names are known.
Do not name a hotkey resource `IDS_H` merely because its English payload is `H`.
Do not expand data-driven resource fields into thousands of speculative constants.

Use `IDS_` for the established base-language namespace.
Use a stable domain qualifier for a distinct resource namespace, such as `IDS_LANGX_` or `IDS_GAME_`.
Confirm the module and domain before selecting the qualifier.
An expansion override and its base fallback can represent one logical resource namespace.
Do not create separate names merely because both files contain that logical ID.
Do not merge IDs solely because their numbers or English strings match.
Different roles can require different names even when their text is equal.

Keep one definition for each named ID within its resource namespace.
The orchestrator assigns header ownership and schedules dependent TUs after that owner's changes.
Use an existing suitable resource header if one is found.
Otherwise, the proposed shared header is `include/resource_ids.h`, grouped by resource domain.
Do not let workers create competing headers or duplicate definitions.

## Declaration form

Prefer conventional resource macros that retain the original literal spelling and type:

```cpp
#define IDS_HOTKEY_VIEW_TOWN_CENTER 0x103F
#define IDS_HOTKEY_MOVE             0x104A
```

Then replace only the opaque ID expression:

```cpp
this->view_town_center_hotkey = *this->get_string(IDS_HOTKEY_VIEW_TOWN_CENTER);
```

This is a proposed cleanup naming example, not a recovered original header.
A macro expands to the same literal without introducing an object or a new enum type.
Final compiler-output validation remains required.
Do not replace resource macros with addressable constant objects or introduce unnecessary storage.

## Preserve the lookup contract

Keep numeric IDs, localization, placeholders, hotkey markers, buffer sizes, failure behavior, and call order unchanged.
Never replace a lookup with English text.
Never replace a fixed source ID with a hash or a runtime search by text.

For an expression such as `base_id + index`, inspect the complete range before naming the base.
Use a `_BASE` suffix when the range relationship is established.
Leave the arithmetic intact. Do not generate a replacement switch or table.

Record evidence for each new name in the module report or shared resource mapping.
Include the resource file hash, language, ID, text, call-site purpose, and whether the name is recovered or newly assigned.
Keep that evidence out of repetitive source comments. Clear names do not need comments that repeat their text.
