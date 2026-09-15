# Source-cleanup report: `src/scr_cam.cpp`

## Handoff

- Module: `src/scr_cam.cpp`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Final source-cleanup commit: `07d2bf45dbe4772db3b6922a9975a2814b39d7ce`
- Branch: `cleanup/staging-20260915-25`
- Changed files:
  - `src/scr_cam.cpp`
  - `decomp_notes/source_cleanup/wave01/scr_cam.md`
- `include/scr_cam.h` was read but not changed.

The report is committed after the source-cleanup commit. The handoff response
records the final report commit hash.

## Correction record

The previous report version cited resource JSON files under the old preserved
`pilot2-scr-load` worktree. That citation was wrong for this worker. I retain
the mistake here so the correction history is clear:

```text
C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/pilot2-scr-load/build/resource-strings/runtime-language.json
C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/pilot2-scr-load/build/resource-strings/runtime-languagex.json
C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/pilot2-scr-load/build/resource-strings/original-xpack-languagex.json
```

I did not edit that worktree or any of its artifacts. Before this correction,
I had written only the assigned source and report in the slot-25 worktree. The
old paths were read as evidence, not written by this worker. This correction
wrote temporary extractor output only under slot-25 `build/`.

After reading the extractor help, I ran the read-only PE extractor again. The
correct artifacts are under this slot-25 worktree:

```text
C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-25/build/resource-strings/runtime-language.json
C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-25/build/resource-strings/runtime-languagex.json
C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-25/build/resource-strings/original-xpack-languagex.json
```

The base file contains all 15 requested strings. Both expansion files return
empty `strings` arrays and list all 15 IDs as missing. The extractor records
exact PE resource text only. Source lookup and fallback evidence remains based
on the reviewed game source and call path.

The final source-format correction joined only these two calls onto one line:

```cpp
this->popupOKDialog(IDS_ERROR_CAMPAIGN_NAME_REQUIRED, 0, 0x1C2, 100);
this->popupOKDialog(IDS_ERROR_CAMPAIGN_REQUIRES_SCENARIO, 0, 0x1C2, 100);
```

No other source text changed in this correction. The source correction commit
is `07d2bf45dbe4772db3b6922a9975a2814b39d7ce`.

## Scope and evidence

This cleanup covers the 13 normal functions registered for `scr_cam.cpp`.
The procedure packets are under `inventory/functions/0048/` and
`inventory/functions/0049/`. The complete scoped PDB is
`inventory/pdb/scoped_symbols.json`.

The PDB source is `C:\msdev\work\age1_x1\scr_cam.cpp`. I inspected the
procedure-scoped stack and register records for every assigned function. Every
assigned normal function has `this` in ECX. The generated scalar deleting
destructor at `0048FA20` also has `this` in ECX and an `__flags` stack
parameter. It has no source owner in this module.

I inspected the original assembly and Ghidra excerpts in each procedure packet.
I used them as supporting evidence, not as a source template. I preserved
source order, declarations, scopes, storage, calls, control flow, literals,
buffers, and cleanup order.

## Name recovery coverage

### `0048F5D0` — constructor

PDB records:

- `this`, ECX, `TRIBE_Campaign_Editor_Screen*`.
- `tabList`, stack offset `-0x2C`, `TPanel*[32 bytes]`.

The source now uses the recovered original spelling `tabList`. The previous
`tab_list` spelling was a cleanup name. The local `cancel` has no PDB record
and remains an invented descriptive name.

### `0048FA40` — destructor

PDB records only `this` in ECX. The source had no recorded local to recover.
Only function-brace formatting changed.

### `0048FBC0` — `fill_campaign_drop`

PDB records:

- `this`, ECX.
- `file_info`, stack offset `-0x118`, `_finddata_t`.
- `file_name`, stack offset `-0x218`, `char[256]`.

Both local spellings already match the PDB. `handle` and `len` have no PDB
records. They remain concise invented snake_case names.

### `0048FD20` — `fill_scenario_list`

PDB records `this`, `file_info`, and `file_name` with the same types and
offsets as `fill_campaign_drop`. The source spellings already match. `handle`
and `len` have no PDB records and remain invented snake_case names.

### `0048FE80` — `fill_campaign_scenario_list`

PDB records:

- `this`, ECX.
- `scenario_names`, stack offset `-0x4`, `char**`.

The source spelling already matches. `count` and `i` have no PDB records and
remain invented snake_case names.

### `0048FF00` — `check_lists`

PDB records only `this` in ECX. The local names `count`, `i`, `text`, and
`index` have no procedure-scoped PDB records. They remain invented descriptive
snake_case names. No declaration or loop structure changed.

### `0048FF80` — `load_campaign`

PDB records:

- `this`, ECX.
- `file_info`, stack offset `-0x124`, `_finddata_t`.
- `text`, stack offset `-0x130`, `char*`.
- `text2`, stack offset `-0x12C`, `char*`.

The source spellings already match. `found` and `ok` have no PDB records and
remain invented snake_case names.

### `00490120` — `make_campaign`

PDB records:

- `this`, ECX.
- `campaign_filename`, stack offset `-0x234`, `char*`.
- `scenarios_text`, stack offset `-0x238`, `char**`.
- `scenarios_filenames`, stack offset `-0x23C`, `char**`.
- `text`, stack offset `-0x230`, `char*`.
- `test`, stack offset `-0x228`, `char[260]`.
- `file_info`, stack offset `-0x124`, `_finddata_t`.

The source now uses recovered `campaign_filename` for the edit-panel campaign
name. The previous `name` spelling was invented. The source now uses recovered
`scenarios_filenames` for the allocated scenario filenames. The previous
`campaign_filename` spelling described that array but did not match the PDB
name. `text`, `scenarios_text`, `test`, and `file_info` already matched the
PDB names.

The PDB records reuse nearby stack storage during different lifetimes. In
particular, the `campaign_filename` and `scenarios_filenames` records do not
justify changing declaration order, array types, or storage. The cleanup only
renames the existing declarations and their uses. `count`, `i`, and
`new_campaign` have no PDB records. They remain invented snake_case names.

### `00490380` — `add_scenario`

PDB records only `this` in ECX. The local names `text` and `line` have no
procedure-scoped PDB records. They remain invented snake_case names.

### `00490400` — `remove_scenario`

PDB records only `this` in ECX. The local names `text` and `line` have no
procedure-scoped PDB records. They remain invented snake_case names.

### `00490480` — `move_scenario_up`

PDB records only `this` in ECX. The local `text` has no procedure-scoped PDB
record. It remains an invented snake_case name.

### `00490520` — `move_scenario_down`

PDB records only `this` in ECX. The local names `last_line`, `line`, and
`text` have no procedure-scoped PDB records. They remain invented snake_case
names.

### `004905D0` — `action`

PDB records:

- `this`, ECX, `TRIBE_Campaign_Editor_Screen*`.
- `fromPanel`, stack offset `+0x4`, `TPanel*`.
- `actionIn`, stack offset `+0x8`, `long`.
- `a1`, stack offset `+0xC`, `unsigned long`.
- `a2`, stack offset `+0x10`, `unsigned long`.
- `str`, stack offset `-0x238`, `char[256]`.
- `text`, stack offset `-0x138`, `char[300]`.

The definition now uses the recovered original parameter spellings `fromPanel`,
`actionIn`, `a1`, and `a2`. The previous names `panel`, `code`, `p3`, and `p4`
were cleanup names. The `str` record appears twice at the same PDB storage
location. The source keeps one existing `str[256]` declaration and does not
split or resize that storage. No local declaration was added.

## Recovered and invented names

Recovered original spellings used in the source are `tabList`, `file_info`,
`file_name`, `scenario_names`, `text`, `text2`, `test`, `campaign_filename`,
`scenarios_filenames`, `scenarios_text`, `fromPanel`, `actionIn`, `a1`, `a2`,
and `str`, where the function-specific PDB records above establish the
mapping. `this` is the PDB register name in every function. `__flags` is the
PDB name for the generated scalar deleting destructor parameter.

Names with no matching procedure-scoped PDB record remain descriptive cleanup
names. These include `cancel`, `handle`, `len`, `count`, `i`, `found`, `ok`,
`new_campaign`, `line`, `line2`, `index`, and `last_line`. The `text` spelling
in `check_lists`, `add_scenario`, `remove_scenario`, `move_scenario_up`, and
`move_scenario_down` also has no local PDB record. I did not force mappings for
reused stack slots.

No public function, class, member, global, type, calling convention, or ABI
symbol was renamed.

## Resource IDs

The source now uses the existing cleanup macros `IDS_BUTTON_OK` and
`IDS_BUTTON_CANCEL` for numeric IDs `0x0FA1` and `0x0FA2`. These macros are
already defined in the root-owned `include/resource_ids.h`. They are new
cleanup names, not recovered original macro names.

The source now applies all 13 proved campaign-editor substitutions from the
root-approved shared resource commit. The source has no remaining numeric use
of these 13 IDs. The two existing button macros above were already applied in
the earlier source cleanup.

Shared resource commit tracking:

- Root-approved shared commit: `c9ba20d160541d928b5d9e55e1d02dce5a784e0c`
- Worker-local cherry-pick commit: `b2fabf8d2e4834afa166ba35f9148b286a33a50d`
- The cherry-pick changes only `include/resource_ids.h`.
- I did not edit `include/resource_ids.h`.
- The shared-header cherry-pick is separate from the module source and report
  commits. Owner integration should cherry-pick it as a shared dependency.

Resource provenance for every request:

- DLL: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
- SHA-256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- Resource type: `RT_STRING`
- Language: `0x0409` (1033)
- PE extraction artifacts: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-25/build/resource-strings/runtime-language.json`,
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-25/build/resource-strings/runtime-languagex.json`,
  and
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-25/build/resource-strings/original-xpack-languagex.json`
- Lookup path: these calls resolve to `TPanel::get_string`, which delegates to
  the virtual `rge_base_game->get_string`. `TRIBE_Game::get_string` checks
  `StringTableX` from `languagex.dll`, then falls back to
  `RGE_Base_Game::get_string` and `StringTable` from `language.dll`.
- The checked runtime file
  `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll` has SHA-256
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39` and
  returns these IDs as missing.
  The pinned original XPack file
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
  also returns them as missing; it has SHA-256
  `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
  The base `language.dll` therefore supplies the text on the checked path.

| Numeric ID | Call-site purpose | Exact base text | Applied cleanup macro |
| --- | --- | --- | --- |
| `0x2BC1` | Campaign editor screen title | `Campaign Editor` | `IDS_CAMPAIGN_EDITOR_TITLE` |
| `0x2BC2` | Campaign filename label | `Campaign Filename ` | `IDS_CAMPAIGN_FILENAME_LABEL` |
| `0x2BC4` | Save button caption | `Save` | `IDS_BUTTON_SAVE` |
| `0x2BC5` | Add-scenario button caption | `Add` | `IDS_BUTTON_ADD` |
| `0x2BC6` | Remove-scenario button caption | `Remove` | `IDS_BUTTON_REMOVE` |
| `0x2BC7` | Available-scenarios label | `Scenarios` | `IDS_SCENARIOS_TITLE` |
| `0x2BC8` | Campaign-scenarios label | `Campaign Scenarios` | `IDS_CAMPAIGN_SCENARIOS_TITLE` |
| `0x2BC9` | Save-changes confirmation format | `Do you want to save your changes to campaign\n %s` | `IDS_CONFIRM_SAVE_CAMPAIGN` |
| `0x2BCA` | Default filename edit text | `default campaign` | `IDS_DEFAULT_CAMPAIGN_NAME` |
| `0x2BCB` | Empty-campaign error | `At least one scenario is required in a campaign.` | `IDS_ERROR_CAMPAIGN_REQUIRES_SCENARIO` |
| `0x2BCC` | Empty-name error | `Cannot save. You must enter a campaign name.` | `IDS_ERROR_CAMPAIGN_NAME_REQUIRED` |
| `0x2BD5` | Move-scenario-up button caption | `Up` | `IDS_BUTTON_MOVE_SCENARIO_UP` |
| `0x2BD6` | Move-scenario-down button caption | `Down` | `IDS_BUTTON_MOVE_SCENARIO_DOWN` |

The exact text came from local PE extraction with
`tools/inspect_pe_strings.py`. The source uses the IDs as title, button,
format, edit-default, and error arguments. The applied macros preserve the
base resource namespace and literal values. The two `0x2BC9` call sites use
the same applied macro. No geometry or unrelated literal was replaced.

For the reused IDs, the same extraction found `0x0FA1` as `OK` and `0x0FA2`
as `Cancel`. The constructor passes them to the OK and Cancel button creation
calls. The existing macros preserve those numeric values.

## Comments and constants

The existing comment in `make_campaign` remains:

```cpp
// An invalid name returns without clearing need_to_save.
```

The packet control flow supports this fact. I added no new source comments.
The cleanup adds no new non-resource constants. It keeps dimensions, panel
codes, dialog codes, buffer sizes, and file extensions unchanged.

## Output-risk review

- Local identifier changes do not change types, scopes, storage, calls, or
  relocations.
- The 15 applied resource macros have the same integer literals as the
  replaced IDs. They add no storage. The shared header can still affect
  preprocessing, so final compiler validation is required.
- Function-brace and signature formatting can change debug line records. It
  does not move statements or change control flow.
- The `make_campaign` rename keeps the existing reused-stack-slot arrangement.
  It does not split arrays, change allocation, or alter constructor argument
  order.
- No inline assembly, structural rewrite, helper, layout change, or bug repair
  was made.

## Header request and resource status

Header owner 03 should update `include/scr_cam.h` only as follows:

Current declaration:

```cpp
virtual long action(TPanel* panel, long code, unsigned long p3,
                    unsigned long p4);
```

Proposed declaration:

```cpp
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
```

This restores the procedure-scoped PDB parameter names. It preserves parameter
types, order, calling convention, and ABI. The worker did not edit the header.

The root owner approved the 13 resource mappings in commit
`c9ba20d160541d928b5d9e55e1d02dce5a784e0c`. The source applies them. The
shared header remains separate from the module commits.

## Validation status

Compilation, matching, audits, tests, and games were **NOT run**. I did not
invoke a compiler or build command. I ran only evidence extraction and source
and Git diff review. Generated code, program data, relocations, and final
output equality remain unvalidated.
