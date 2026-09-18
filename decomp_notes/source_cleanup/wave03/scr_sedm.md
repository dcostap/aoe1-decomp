# Source cleanup: `src/scr_sedm.cpp`

## Handoff

- Module: `src/scr_sedm.cpp`
- Branch: `cleanup/staging-20260915-185`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source-cleanup commit: `583dd22308e40f66a78eb00d1d4ba291d7d141ea`
- Changed files:
  - `src/scr_sedm.cpp`
  - `decomp_notes/source_cleanup/wave03/scr_sedm.md`
- `include/scr_sedm.h` was read but not changed.

The first source-cleanup commit contains only the assigned source file. The
earlier source-format correction and first report version are in
`67137c7ae8e5d06f3c1f7610150b132ebd350920`. Both commits touch assigned paths
only. A report-only correction follows. The handoff response records its full
hash.

## Follow-up correction record

The final combined review found three non-1TBS function openings in the
source. Commit `e749f5516dc100bf3d06f20475a453c2dacaae36` moved only the
constructor, destructor, and `handle_idle` opening braces onto their function
or initializer lines. It changed no token, statement, scope, or behavior.

This report update records that correction. No compiler, build, matching check,
audit, validation, test, or game was run.

## Follow-up correction record: approved resource macros

Root approved the payload-backed resource mappings in commit
`f5b7d6668f785b97811119493bea0e04403d1d10`. I read the approved header at
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-181/include/resource_ids.h`.
This root approval is separate from the worker's PE extraction evidence below.
The extraction records the resource payload and lookup status. The root commit
approves the shared macro names and ownership.

The source now uses these approved macros:

| ID | Approved macro | Source use |
| --- | --- | --- |
| `0x242D` | `STRING_ID_SCENARIO_EDITOR_TITLE` | `create_text` title argument |
| `0x242E` | `STRING_ID_SCENARIO_MENU_CREATE_SCENARIO` | `button[0]->set_text` caption |
| `0x242F` | `STRING_ID_BUTTON_EDIT_SCENARIO` | `button[1]->set_text` caption |
| `0x2430` | `STRING_ID_SCENARIO_EDITOR_CANCEL` | `button[3]->set_text` caption |
| `0x2431` | `STRING_ID_MENU_CAMPAIGN_EDITOR` | `button[2]->set_text` caption |

For `0x242E`, the source uses the approved existing
`STRING_ID_SCENARIO_MENU_CREATE_SCENARIO` name. It does not use the rejected duplicate
proposal `STRING_ID_BUTTON_CREATE_SCENARIO`.

Commit `583dd22308e40f66a78eb00d1d4ba291d7d141ea` changed only these five
resource expressions. It preserved argument types, casts, buffers, order,
lookup calls, and source structure. Each approved macro retains its original
integer value and adds no object storage.

## Scope and evidence

I read `AGENTS.md`, `docs/source_cleanup.md`,
`docs/source_comments.md`, `docs/resource_ids.md`,
`docs/source_cleanup_owners.md`, `docs/testing.md`, and
`decomp_notes/source_cleanup/wave03_assignments.md`.

I read `config/toolchain.json`, the assigned header, and the assigned registry.
The registry selects `config/flags/gx.rsp` for this module. I read the pinned
VC5 SDK files before changing a constant. `WINUSER.H` defines `VK_ESCAPE` as
`0x1B` at line 313. `FCNTL.H` was also read; this module uses no CRT open flags.

I inspected the original executable packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/`:

- `004B2EF0_TRIBE_Screen_Sed_Menu.txt`
- `004B3110_TRIBE_Screen_Sed_Menu.txt`
- `004B31A0_handle_idle.txt`
- `004B31D0_action.txt`

I inspected the complete scoped PDB at
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The local extract is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-185/build/scr_sedm-evidence/scoped-symbols.json`.
I also inspected the original disassembly and decompiler excerpts at
`C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/scr_sedm.cpp.asm`
and
`C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/scr_sedm.cpp.decomp`.
These files support ownership, boundaries, calls, and lookup arguments. They
are not treated as source templates.

The four normal registry entries and one generated procedure have this
coverage:

| VA | Procedure | PDB lines | bytes | PDB scoped records |
| --- | --- | ---: | ---: | --- |
| `004B2EF0` | `TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu` | 41-86 | 504 | `this` in ECX; no stack or static records |
| `004B30F0` | generated scalar deleting destructor | generated | 30 | `this` in ECX; `__flags`, unsigned int, at `+0x4` |
| `004B3110` | `TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu` | 91-97 | 129 | `this` in ECX; no stack or static records |
| `004B31A0` | `TRIBE_Screen_Sed_Menu::handle_idle` | 103-108 | 33 | `this` in ECX; no stack or static records |
| `004B31D0` | `TRIBE_Screen_Sed_Menu::action` | 114-154 | 502 | `this` in ECX; four stack parameters |

The PDB gives `TRIBE_Screen_Sed_Menu*` for `this` in every procedure. The
registry owns the four normal procedures. The scalar deleting destructor has
no handwritten source owner and was not edited.

The action parameter records are:

| Name | Type | Stack offset |
| --- | --- | ---: |
| `fromPanel` | `TPanel*` | `+0x4` |
| `actionIn` | `long` | `+0x8` |
| `a1` | `unsigned long` | `+0xC` |
| `a2` | `unsigned long` | `+0x10` |

The PDB has no local records for the four normal procedures. It has no record
for the existing `j`, `i`, or `cancel` declarations. I did not force a name
from an optimized register or stack slot.

## Original-name recovery

### `004B2EF0` — constructor

The PDB records only `this` in ECX. It records no stack local. The source keeps
`j`, `i`, and `cancel` unchanged. Their names are not claimed as recovered
original names.

### `004B3110` — destructor

The PDB records only `this` in ECX. It records no stack local. The existing
loop variable `i` remains unchanged and is not claimed as an original name.

### `004B31A0` — `handle_idle`

The PDB records only `this` in ECX. No rename was supported.

### `004B31D0` — `action`

The source now uses the exact PDB names `fromPanel`, `actionIn`, `a1`, and `a2`
for the four parameters. Their types, order, stack offsets, and uses remain
unchanged. The old `param_1` through `param_4` names were generated names.

No local declaration was added, removed, split, or merged. No reused PDB stack
slot created a supported local mapping.

## Source changes

- Added the existing root-owned `include/resource_ids.h` include.
- Replaced the proven close-button ID `0x3EA` with existing
  `STRING_ID_BUTTON_CLOSE`.
- Replaced the proven Escape virtual-key value `0x1B` with the pinned SDK macro
  `VK_ESCAPE`. The macro expands to the same integer value.
- Restored the four PDB parameter names in `action`.
- Joined the short `action` signature and opening brace onto one line.
- Kept 1TBS braces and source order.
- Added no source comment. The code has no non-obvious lifetime or bug fact
  that needs a new comment.

I preserved all casts, field types, declaration scopes, storage, evaluation
order, call targets, literals, lookup calls, and failure paths. I made no
helper, layout, ABI, assembly, or structural change. I repaired no behavior.

## Resource IDs

The source uses the `RT_STRING` lookup overloads of `create_text`,
`create_button`, and `TButtonPanel::set_text`. The lookup path is:

1. `TEasy_Panel` calls its `get_string` method for each numeric ID.
2. The virtual `TRIBE_Game::get_string` checks `StringTableX` first.
3. A failed expansion lookup falls back to `RGE_Base_Game::get_string` and
   `StringTable`.
4. The base lookup clears the destination when the ID is missing.

The source does not change this order or its `STRING=` override behavior.

I ran the read-only extractor after running its `--help`. The extraction files
are under this worker's build directory:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-185/build/scr_sedm-evidence/runtime-language.json`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-185/build/scr_sedm-evidence/runtime-languagex.json`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-185/build/scr_sedm-evidence/orig-languagex.json`

The checked base runtime DLL is
`C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`.
Its full SHA-256 is
`3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
The checked runtime expansion DLL is
`C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`.
Its full SHA-256 is
`4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
The pinned original XPack expansion DLL is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`.
Its full SHA-256 is
`a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

All extraction requests selected language `0x0409` (`1033`) and resource type
`RT_STRING`. The base runtime returned exact text for every ID. The runtime
expansion returned empty slots for `0x242D` through `0x242F` and missing slots
for the other IDs. The pinned original XPack expansion returned every ID as
missing. The runtime base therefore supplies the text after the normal
expansion fallback for this checked path.

| ID | Call-site purpose | Base runtime text, language `0x0409` | Runtime expansion status, language `0x0409` | Pinned XPack expansion status, language `0x0409` | Name status |
| --- | --- | --- | --- | --- | --- |
| `0x03EA` | Close-button caption passed to long `create_button` | `X` | Missing | Missing | Existing `STRING_ID_BUTTON_CLOSE` applied |
| `0x242D` | Scenario-editor menu title passed to `create_text` | `Scenario Builder` | Empty string | Missing | Approved `STRING_ID_SCENARIO_EDITOR_TITLE` applied |
| `0x242E` | Create-scenario button caption passed to `set_text` | `Create Scenario` | Empty string | Missing | Approved `STRING_ID_SCENARIO_MENU_CREATE_SCENARIO` applied |
| `0x242F` | Edit-scenario button caption passed to `set_text` | `Edit Scenario` | Empty string | Missing | Approved `STRING_ID_BUTTON_EDIT_SCENARIO` applied |
| `0x2430` | Cancel button caption passed to `set_text` | `Cancel` | Missing | Missing | Approved `STRING_ID_SCENARIO_EDITOR_CANCEL` applied |
| `0x2431` | Campaign-editor button caption passed to `set_text` | `Campaign Editor` | Missing | Missing | Approved `STRING_ID_MENU_CAMPAIGN_EDITOR` applied |

`STRING_ID_BUTTON_CLOSE` is an existing cleanup name in the root-owned
`include/resource_ids.h`. It is not an original macro name. The other five
names are cleanup names approved by root. No original macro spelling is
claimed. Root approved these declarations in
`f5b7d6668f785b97811119493bea0e04403d1d10`:

```cpp
#define STRING_ID_SCENARIO_EDITOR_TITLE          0x242D
#define STRING_ID_SCENARIO_MENU_CREATE_SCENARIO  0x242E
#define STRING_ID_BUTTON_EDIT_SCENARIO           0x242F
#define STRING_ID_SCENARIO_EDITOR_CANCEL         0x2430
#define STRING_ID_MENU_CAMPAIGN_EDITOR           0x2431
```

The numeric values and effective integer type match the current expressions.
The approved names describe the call-site roles. The `0x242E` name is shared
with the scenario-menu domain. No original macro spelling is claimed.

The other numeric values in the source are geometry, panel setup, positioning,
or action values. This report does not assign resource names to them.

## Header request

The assigned header owner should consider this declaration-only change in
`include/scr_sedm.h`:

```cpp
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
```

This request preserves the function name, types, order, virtual slot, and ABI.
It is not required for the source definition to compile. No header was edited.

Root approved the five resource macros. No further resource declaration request
remains for these IDs.

## Risk and unresolved items

- Parameter renames change debug names only. They do not change an ABI symbol,
  type, storage slot, or call target.
- `STRING_ID_BUTTON_CLOSE` is a macro for the same `0x03EA` integer and adds no
  object storage.
- `VK_ESCAPE` is the pinned SDK macro for `0x1B`. It preserves the hotkey
  value and field type.
- The added resource header include can affect preprocessing. Final compiler
  validation is required.
- Signature formatting can change debug line records. It does not move a
  statement or alter control flow.
- No uncertain local mapping remains hidden. The PDB has no local names for
  the existing constructor, destructor, and action locals.
- The approved five resource names are cleanup names, not recovered original
  macro names. Their text and lookup statuses remain those recorded above.
- `0xC386`, geometry values, positioning values, and action value `1` remain
  numeric because this task did not prove shared symbolic meanings for them.

## Review and validation

I reviewed the complete source diff and ran `git diff --check`.
I did not run a compiler, build, matching check, audit, test, or game.
Compilation, matching, audits, tests, and gameplay remain **NOT RUN**.
The result is reviewed but unvalidated.

## Commit records

- Base: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Initial source cleanup: `9649a6df2ff1ff8be90ae9acc5a546746b026cbb`
- Final source-format correction and first report version: `67137c7ae8e5d06f3c1f7610150b132ebd350920`
- 1TBS opening-brace correction: `e749f5516dc100bf3d06f20475a453c2dacaae36`
- Approved resource macro substitutions: `583dd22308e40f66a78eb00d1d4ba291d7d141ea`
- Report-only correction: committed after this source tree; its full hash is
  recorded in the handoff response.
