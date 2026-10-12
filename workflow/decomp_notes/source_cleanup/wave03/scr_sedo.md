# Source-cleanup report: `scr_sedo.cpp`

## Delivery

- Module: `src/scr_sedo.cpp`
- Header: `include/scr_sedo.h`
- PDB source: `C:\\msdev\\work\\age1_x1\\scr_sedo.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `cc350e5cbab2079d151ef0c88b5c0299e765445f`
- Report path: `workflow/decomp_notes/source_cleanup/wave03/scr_sedo.md`
- Changed worker files: `src/scr_sedo.cpp` and this report.

The header correction commit `b249684deea3ff2fb648ad376804ba5ea770b763`
restored `include/scr_sedo.h` to the common-base content. The header is not a
delivered worker file. The declaration-name change remains a group-owner
request below.

The source module remains the sole owner of the four normal PDB procedures in
source order. The registry and source-module configuration were not changed.
The compiler-generated scalar deleting destructor remains without a source
body.

The cleanup restores procedure-scoped PDB names. It reuses approved resource
macros and pinned SDK key constants. It changes no type, layout, call, control
flow, storage, source order, or ABI symbol.

## Function coverage

| VA | Function | PDB records checked | Cleanup result |
| --- | --- | --- | --- |
| `004B33D0` | `TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open` | `tabList`, `info_file`, `from_panel`, register `this` | Existing `tabList` and `info_file` names remain. The overlapping `from_panel` record is not forced onto a source declaration. |
| `004B3680` | scalar deleting destructor | `__flags`, register `this` | Compiler generated. No source owner. |
| `004B36A0` | `TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open` | register `this` | No name change was needed. |
| `004B3740` | `TRIBE_Screen_Sed_Open::fillList` | `fileInfo`, `file_name`, register `this` | Existing names already match the PDB. |
| `004B38A0` | `TRIBE_Screen_Sed_Open::action` | `fromPanel`, `actionIn`, `a1`, `a2`, `str` twice, `text`, `of`, `fileName`, register `this` | Restored the four parameters, both `str` buffer names, and `fileName`. Existing `text` and `of` names remain. |

Evidence sources:

- `inventory/pdb/scoped_symbols.json`, entries `004B33D0`, `004B3680`,
  `004B36A0`, `004B3740`, and `004B38A0`.
- `inventory/functions/004B/004B33D0_TRIBE_Screen_Sed_Open.txt`.
- `inventory/functions/004B/004B38A0_action.txt`.
- `workflow/decomp_notes/scr_sedo.md` and
  `workflow/decomp_notes/functions/004B/004B38A0.md`.
- `config/functions/src/scr_sedo.cpp.json`.

## Name recovery

### Recovered original names

The action definition now uses the PDB parameter names exactly:

```cpp
long TRIBE_Screen_Sed_Open::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
```

The four names come from the stack records at `+0x4`, `+0x8`, `+0xc`, and
`+0x10`. The assigned header keeps its common-base unnamed declaration.
The group owner should apply the declaration-name request below.

The action path buffer now uses `fileName`. The PDB records `fileName` at
`-0x33c` and shows its six path-buffer uses. The source keeps the existing
`char fileName[260]` declaration. The PDB type record reports `char[257]`.
This cleanup restores the name only. It does not change the buffer size.

The two independent branch-local character buffers now use the PDB name
`str`. The PDB lists two `str` records with type `char[256]`. The source keeps
both declarations separate and keeps their existing `char[256]` type. One
buffer builds paths for deletion. The other receives the delete-confirmation
format string.

The constructor already used the PDB names `tabList` and `info_file`. The
`fillList` procedure already used `fileInfo` and `file_name`. The action
procedure already used the PDB names `text` and `of`.

### Retained descriptive names

The PDB has no reliable records for these current source names:

- Constructor: `draw_area`, `cancel`, and `delete_button`.
- `fillList`: `handle` and `len`.
- Action: `line`, `prog_info`, `curr_line`, `scenario_dir`,
  `scenario_dir_scx`, and `target`.

These names describe the current source uses. They are not claimed as original
PDB names. No new declaration or scope was added to support a name.

### Unresolved declaration mappings

The constructor PDB lists `from_panel` as a `TEasy_Panel*` at `-0x128`. The
same procedure lists `tabList` at `-0x124` and `info_file` at `-0x110`. The
assembly and prior natural source use the current panel through `tabList[0]`.
The overlapping PDB record does not prove a separate current declaration, so
this cleanup does not add or rename one.

The action PDB places `str` and `_OFSTRUCT of` at the same stack offset.
Their source scopes and types differ. The source keeps two `str` declarations
and one typed `of` declaration. It does not merge or overlay them.

The action PDB omits the current `line`, `prog_info`, and `curr_line` locals.
Their source names remain descriptive. No reused slot receives a forced name.

## Resource identifiers

### Root approval

Root approved the payload-backed shared declarations in commit
`f5b7d6668f785b97811119493bea0e04403d1d10`. The approved header was read at:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-181/include/resource_ids.h`

The approved declarations are:

```cpp
#define STRING_ID_SCENARIO_OPEN_TITLE 0x24CD
#define STRING_ID_ERROR_CANNOT_LOAD_SCENARIO 0x24CF
```

This approval is shared-header evidence. It is separate from the worker's
resource extraction evidence below. The worker did not edit the shared header.

### Worker evidence

The source now includes the existing `include/resource_ids.h` and reuses these
approved names:

| Macro | Value | Use | Text from staged base resource |
| --- | --- | --- | --- |
| `STRING_ID_BUTTON_OK` | `0x0FA1` | OK button caption | `OK` |
| `STRING_ID_BUTTON_CANCEL` | `0x0FA2` | Cancel button caption | `Cancel` |
| `STRING_ID_BUTTON_DELETE` | `0x24C9` | Delete button caption | `Delete` |
| `STRING_ID_CONFIRM_DELETE_FILE` | `0x24CA` | Delete confirmation format string | `Are you sure you want to delete the file \n'%s'?` |

The source now uses the root-approved names for these two IDs:

```cpp
#define STRING_ID_SCENARIO_OPEN_TITLE 0x24CD
#define STRING_ID_ERROR_CANNOT_LOAD_SCENARIO 0x24CF
```

These are new cleanup names. No original macro name is claimed. Their uses are:

- `0x24CD`: title passed to `create_text` in the scenario-open constructor.
- `0x24CF`: failure message passed to `popupOKDialog` when neither scenario
  extension can be opened.

The resource lookup path is established by the current source owners:

- `TPanel::get_string` in `src/panel.cpp` calls the virtual
  `rge_base_game->get_string` method.
- `TRIBE_Game::get_string` in `src/tribegam.cpp` checks `StringTableX` first
  and then calls the base-game lookup.
- The staged `languagex.dll` has no entries for these IDs, so the staged base
  `language.dll` supplies the text for this run-time path.

The inspected staged base resource was:

- File: `C:/Projects/my_decomps/aoe1_attempt3/build/runtime/original-20260914T230838850570Z/language.dll`
- SHA256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- Resource type: `RT_STRING`
- Language: `0x0409` (`1033`)

The staged expansion resource was:

- File: `C:/Projects/my_decomps/aoe1_attempt3/build/runtime/original-20260914T230838850570Z/languagex.dll`
- SHA256: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- Result: IDs `0x0FA1`, `0x0FA2`, `0x24C9`, `0x24CA`, `0x24CD`, and `0x24CF`
  were missing.

The checked pinned XPack expansion resource was:

- File: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
- SHA256: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`
- Result: the checked IDs were missing.

The actual base-resource extraction returned these exact entries from the
staged file:

- `0x0FA1`: `OK`.
- `0x0FA2`: `Cancel`.
- `0x24C9`: `Delete`.
- `0x24CA`: `Are you sure you want to delete the file \n'%s'?`.
- `0x24CD`: `Select Scenario`.
- `0x24CF`: `Cannot load that scenario.`.

The `%s` token and newline in `0x24CA` remain part of the original format
contract. The source keeps the same lookup, buffer, formatting call, and
lookup order.

Extraction records are in the ignored worker files:

- `build/resource-strings/scr_sedo-language.json`
- `build/resource-strings/scr_sedo-languagex.json`
- `build/resource-strings/scr_sedo-pinned-languagex.json`

## SDK constants

The constructor now uses `VK_ESCAPE` for the Cancel hotkey and `VK_DELETE`
for the Delete hotkey. The pinned VC5 header proves these values:

- `C:/Program Files (x86)/DevStudio/VC/Include/WINUSER.H:313` defines
  `VK_ESCAPE` as `0x1B`.
- `C:/Program Files (x86)/DevStudio/VC/Include/WINUSER.H:329` defines
  `VK_DELETE` as `0x2E`.

The macros preserve the former integer values and effective argument types.
No panel action value or popup parameter was renamed without a verified shared
symbol.

## Comments and formatting

No new source comment was added. The existing comments explain panel-slot
ownership, child-creation order, and the preserved action-path order. They
remain sparse and factual.

The source uses 1TBS for the constructor, `fillList`, and `action` definitions.
The action signature stays on one line because its parameter list is short.
The `else` branches use the same-line brace form. No statement or declaration
was moved.

## Output-risk review

- Parameter and local name changes can change debug names and line records.
- The header parameter names do not change its ABI or class layout.
- Resource macros expand to the same integer literals as the former IDs.
- `VK_ESCAPE` and `VK_DELETE` expand to the same integer values as the former
  hotkey literals.
- The added resource-header include adds no object or runtime storage.
- The retained `fileName[260]`, `str[256]`, `text[556]`, and `OFSTRUCT of`
  declarations keep their existing types, sizes, scopes, and storage.
- No call target, relocation source, control-flow edge, data value, or symbol
  identity was changed by source intent.
- Formatting can change debug line records. This source has no `__LINE__` use.

The existing function registry still claims matching status for the four
normal procedures. This cleanup did not validate that claim.

## Shared-file requests and open questions

Root approval covers the `0x24CD` and `0x24CF` declarations. Do not add local
duplicate definitions.

Request the group owner of `include/scr_sedo.h` to apply this declaration-only
change:

```cpp
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
```

The declaration request is supported by the `004B38A0` PDB stack records. It
does not change types, calling convention, symbol identity, or class layout.

The constructor `from_panel` PDB record and the action `str`/`of` shared stack
offset remain documented uncertainties. This cleanup does not change their
source declarations or storage model.

## Validation

Allowed review work completed:

- Reviewed the complete assigned source, header, registry, PDB records,
  function packets, durable notes, and cleanup guides.
- Ran `python tools/inspect_pe_strings.py --help` before extraction.
- Extracted all six relevant IDs from the staged base and expansion resources.
- Read the pinned `WINUSER.H` definitions for `VK_ESCAPE` and `VK_DELETE`.
- Ran `git diff --check` on the final source and header changes before the
  source commit.
- Inspected the complete source and header diff.

Not run, as required by the cleanup wave:

- Compilation or build.
- Function matching.
- Audits.
- Automated tests.
- Menu or gameplay tests.
- Game execution.

The source cleanup remains unvalidated until the final wave validation stage.
