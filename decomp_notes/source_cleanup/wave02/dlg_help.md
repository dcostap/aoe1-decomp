# Source-cleanup report: `src/dlg_help.cpp`

## Delivery

- Module: `src/dlg_help.cpp`
- Header read-only: `include/dlg_help.h`
- Header owner: owner 10
- Shared resource header owner: root (`include/resource_ids.h`)
- Branch: `cleanup/staging-20260915-86`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Worker-local shared resource import: `08038221ea7047376f742814ca1185dbf31268e8`
- Root approval commit: `8c56055b7feee1526f296bd306036a4c34f38041`
- Earlier source commit: `7333ff58036a73e1d7fac31869df3bed37d9604b`
- Earlier report commit: `9e873050d6241e2e75bf9dde6f99f52943eb3d3c`
- Source correction commit: `1c75a1dd6757a05fc717fd9dfe44860656a02905`
- Final report commit: the commit that adds this report; copy its full hash from Git.
- Changed files:
  - `src/dlg_help.cpp`
  - `decomp_notes/source_cleanup/wave02/dlg_help.md`
- `include/dlg_help.h` was not changed.
- `include/resource_ids.h` was not changed.

The source cleanup changes names, formatting, and two resource macro uses. It
does not change types, storage, control flow, calls, or source order. The
`setup_help` local `x` keeps its baseline spelling because the recovered name
changed linked relocation order.

## Scope and evidence

I read the repository contract and these complete guides:

- `docs/source_cleanup.md`
- `docs/source_comments.md`
- `docs/resource_ids.md`
- `docs/source_cleanup_owners.md`
- `docs/testing.md`
- `decomp_notes/source_cleanup/wave02_assignments.md`

I read the assigned source, header, manifest, and existing module note. I used
these absolute main-root evidence paths:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/dlg_help.cpp.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043E840_THelpDialog.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043E8E0_THelpDialog.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043E950_THelpDialog.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043E9E0_setup_help.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043ED40_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043EE10_handle_mouse_down.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`

The registry selects six handwritten procedures in source and address order.
The PDB module is `.\\Release\\dlg_help.obj`, with source
`C:\\msdev\\work\\age1_x1\\dlg_help.cpp`.

The original PE SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved baseline directory was inspected but not changed.

## Original-name recovery coverage

Coverage is complete for all six registered procedures. I checked each PDB
parameter, local, function-static, and register record.

| VA | Procedure | PDB parameters | PDB locals and registers | Source result |
| --- | --- | --- | --- | --- |
| `0043E840` | `THelpDialog::THelpDialog` | `parentPanel`, `in_parent_panel`, `help_string_id`, `in_help_page_id`, `x`, `y` | No locals or statics; register `this` in `ecx` | Restored all six parameter names. Kept local `text`, which has no PDB record. |
| `0043E8E0` | `THelpDialog::THelpDialog` | `parentPanel`, `in_parent_panel`, `in_help_string`, `in_help_page_id`, `x`, `y` | No locals or statics; register `this` in `ecx` | Restored all six parameter names. |
| `0043E950` | `THelpDialog::~THelpDialog` | None | No locals or statics; register `this` in `ecx` | No rename was supported. |
| `0043E9E0` | `THelpDialog::setup_help` | `parentPanel`, `in_parent_panel`, `help_string`, `in_help_page_id`, `mouse_x`, `mouse_y` | `rge_text_font` at `-0xc`; `tabList` at `-0x8`; `dialog_x` at `+0xc`; `panel_height` at `+0x8`; register `this` in `ecx` | Restored all six parameters and `panel_height`. Kept baseline local `x` for linked relocation stability. Both geometry locals use reused positive stack homes. |
| `0043ED40` | `THelpDialog::action` | `fromPanel`, `actionIn`, `a1`, `a2` | No locals or statics; register `this` in `ecx` | Restored all four parameter names. Kept local `help_page_id` and `help_topic`; neither has a PDB record. |
| `0043EE10` | `THelpDialog::handle_mouse_down` | `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key` | No locals or statics; register `this` in `ecx` | Restored all five parameter names. `x` and `y` already matched. |

The PDB also lists compiler-generated scalar deleting destructor `0043E8C0`,
`THelpDialog::\`scalar deleting destructor'`. It has stack `__flags` and
register `this` in `ecx`. It has no handwritten source owner and was not edited.

### Name details

- Recovered original constructor names are `parentPanel`, `in_parent_panel`,
  `help_string_id`, `in_help_page_id`, `x`, and `y`.
- The second constructor also recovers `in_help_string`.
- Recovered `setup_help` names are `parentPanel`, `in_parent_panel`,
  `help_string`, `in_help_page_id`, `mouse_x`, `mouse_y`, `rge_text_font`,
  `tabList`, `dialog_x`, and `panel_height`.
- Recovered `action` names are `fromPanel`, `actionIn`, `a1`, and `a2`.
- Recovered `handle_mouse_down` names are `mouse_button_in`, `x`, `y`,
  `ctrl_key`, and `shift_key`.
- Existing names without PDB records remain unchanged. These include `text`,
  `line_height`, `y`, `button`, `tab_count`, `help_page_id`, and `help_topic`.
- The PDB records `dialog_x`, but the source uses the baseline spelling `x`.
  This is an intentional exception for the linked relocation repair below.
- The `setup_help` temporary named `help_topic` has no PDB record. The former
  local name `help_string` conflicted with the recovered `help_string` parameter.
  `help_topic` is a new descriptive cleanup name. It adds no declaration.
- No reused stack slot received a forced extra declaration. No parameter type,
  local type, scope, storage duration, or initialization point changed.
- No public function, class, member, global, ABI symbol, or layout changed.

### Reused stack-home evidence

The raw PDB BPREL offsets do not equal the entry-relative assembly stack slots.
Do not treat them as simple home equality.

The PDB names `panel_height` at raw offset `+0x8` and `dialog_x` at raw offset
`+0xc`. In the original instructions, the panel-height value is stored at
`0043EAD1` in `[esp+20h]`. The x value is stored at `0043EB50` and `0043EB58`
in `[esp+24h]`.

These assembly homes are reused after the prologue and later stack pushes. The
`panel_height` mapping remains supported because the value computed from
`line_height * rge_text_font->font_hgt + 0x37` is stored at `0043EAD1` and is
passed as the panel height. The `dialog_x` mapping remains supported because
the x candidates, clamp, and final `set_fixed_position` argument use the value
stored at `0043EB50` and `0043EB58`.

The source retains `panel_height` as a declaration mapping. It uses baseline
spelling `x` for the PDB `dialog_x` record because the recovered spelling
changed linked relocation order. This does not claim that either raw PDB offset
equals its entry-relative assembly home.

## Linked call-order repair

The baseline is commit
`6d46835cdc6e31ba879a2e6e31415327a7c7e341`. Its `setup_help` source uses the
expression `parent->width() + parent->xPosition()` and declares `long x`.
The cleanup kept the expression equivalent but renamed that local to
`dialog_x`.

The preserved baseline object at
`build/source-cleanup-20260915/preparation/baseline-build/dlg_help.obj` binds
relative relocation offset `246` to `width` and offset `255` to `xPosition`.
The fresh object at
`build/source-cleanup-20260915/final-validation/functions-r2/objects/dlg_help.obj`
binds offset `246` to `xPosition` and offset `255` to `width`. The linked audit
reports the same reciprocal failure at `0043E9E0`.

The source expression itself is unchanged. A prior reverse-sum probe also kept
the reciprocal failure. The evidence therefore points to the recovered
`dialog_x` spelling as the source-form drift. This repair restores only the
baseline spelling `x` at its existing declaration and uses. It keeps
`panel_height`, all calls, types, homes, control flow, and expression order.
No post-repair object or linked validation was run.

## Resource and constant evidence

The source now includes `../include/resource_ids.h` and uses the existing
`IDS_BUTTON_OK` macro for both OK-button caption calls. The macro is not claimed
as a recovered original symbol.

The worker-local shared resource import `08038221ea7047376f742814ca1185dbf31268e8`
contains `IDS_BUTTON_MORE_HELP` for `0x243D`. Root approved this mapping in
commit `8c56055b7feee1526f296bd306036a4c34f38041`. The source now uses this
macro for the optional More Help button. It is a new cleanup name, not an
original macro.

The existing macro maps `0x0FA1` to the OK caption. The source calls
`create_button` with this ID at original `0043ECCC` and the two branch paths
before it. The caption role is proved by that call and the resource lookup.

The resource extractor was run after `python tools/inspect_pe_strings.py --help`.
Its outputs are:

- `build/resource-strings/dlg-help-runtime-language.json`
- `build/resource-strings/dlg-help-runtime-languagex.json`
- `build/resource-strings/dlg-help-original-xpack-languagex.json`

All checked resources use `RT_STRING` and language `0x0409` (`1033`).

| File | SHA-256 | `0x0FA1` | `0x243D` |
| --- | --- | --- | --- |
| `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5` | `OK` | `More Help` |
| `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39` | Missing | Missing |
| `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll` | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2` | Missing | Missing |

`TPanel::get_string` calls the global `rge_base_game` string lookup. The
`TRIBE_Game` override checks `StringTableX` first and then the base table.
The checked runtime expansion therefore falls back to the base runtime DLL.
The checked original XPack expansion also lacks both entries.

The original setup call at `0043EC88` passes `0x243D` as the caption ID for the
optional single-player More Help button. The caption role is proved by the
call site, the branch, and the exact base resource text. The macro expands to
the same numeric value.

### Applied shared resource mapping

The worker-local import `08038221ea7047376f742814ca1185dbf31268e8` contains this
mapping. Root approved it in commit
`8c56055b7feee1526f296bd306036a4c34f38041`:

| Numeric ID | Proposed cleanup name | Resource type | Language | Exact text and files | Lookup path | Purpose |
| --- | --- | --- | --- | --- | --- | --- |
| `0x243D` (`9277`) | `IDS_BUTTON_MORE_HELP` | `RT_STRING` | `0x0409` (`1033`) | `runtime/language.dll`: `More Help`; `runtime/languagex.dll`: missing; original XPack `languagex.dll`: missing | `TPanel::get_string` -> virtual `TRIBE_Game::get_string`; expansion table first, base table fallback | Caption passed to `create_button` for the optional More Help button in `THelpDialog::setup_help` |

The name is a new cleanup name. It is not a recovered original macro. The source
now substitutes it for the original numeric expression.

The source retains `0x101` in `WinHelpA`. Pinned `WINUSER.H` identifies it as
`HELP_KEY` with value `0x0101L`. No replacement was made because this pass did
not need to change the existing API literal or its expression type.

## Comments and formatting

No new source comment was needed. The existing EH-framed constructor comment
remains. It records the module's existing context evidence.

Function opening braces now use 1TBS. The source keeps all statements, calls,
casts, literals, declarations, scopes, and evaluation order unchanged.

## Output and code-generation concerns

- Identifier changes can alter debug names and line records.
- The 1TBS formatting changes can alter line records.
- `IDS_BUTTON_OK` expands to the existing `0x0FA1` literal. It adds no storage.
- `IDS_BUTTON_MORE_HELP` expands to `0x243D`. It adds no storage.
- The new resource include changes preprocessing but adds no runtime state.
- The PDB positive offsets and assembly stack homes differ. The report records
  both forms. No forced stack layout or compiler steering was added.
- The existing module note records `setup_help` as nonexact in prior checks.
  This cleanup does not claim to repair that mismatch.
- No structural rewrite, helper, bug fix, layout change, or assembly was added.

## Header requests

The owner of `include/dlg_help.h` should review these parameter-name-only edits:

```cpp
THelpDialog(TEasy_Panel* parentPanel, char* in_parent_panel, long help_string_id,
            long in_help_page_id, long x, long y);
THelpDialog(TEasy_Panel* parentPanel, char* in_parent_panel, char* in_help_string,
            long in_help_page_id, long x, long y);
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
virtual long handle_mouse_down(unsigned char mouse_button_in, long x, long y,
                               int ctrl_key, int shift_key);
void setup_help(TEasy_Panel* parentPanel, char* in_parent_panel,
                char* help_string, long in_help_page_id, long mouse_x, long mouse_y);
```

These edits change no type, order, calling convention, symbol, or layout.

## Validation

Allowed checks performed:

- Read the complete assigned source and header.
- Read the registry and all six assigned function packets.
- Read every assigned procedure in `scoped_symbols.json`.
- Read the original resource evidence and extracted the requested IDs.
- Inspected the original PE path and preserved baseline directory.
- Ran `git diff --check`.
- Reviewed the complete source diff.

Compilation, matching, audits, and tests were not run. I did not run a compiler,
build, matcher, audit, automated test, menu suite, gameplay suite, or game.

## Commits

- Base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Worker-local shared resource import: `08038221ea7047376f742814ca1185dbf31268e8`
- Root approval: `8c56055b7feee1526f296bd306036a4c34f38041`
- Earlier source cleanup: `7333ff58036a73e1d7fac31869df3bed37d9604b`
- Earlier report: `9e873050d6241e2e75bf9dde6f99f52943eb3d3c`
- Source correction: `1c75a1dd6757a05fc717fd9dfe44860656a02905`
- Report correction: committed after this source correction. Copy its full hash from Git.
