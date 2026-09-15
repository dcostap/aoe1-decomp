# Source-cleanup handoff: `src/scr_vc.cpp`

## Handoff

- Module: `src/scr_vc.cpp`
- Worktree: `slot-188`
- Branch: `cleanup/staging-20260915-188`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source-cleanup commit: `3ec6d5735700829768fbcc49e5fd384a5019703d`
- Changed files:
  - `src/scr_vc.cpp`
  - `decomp_notes/source_cleanup/wave03/scr_vc.md`
- Header owner: group owner for `include/scr_vc.h`
- Shared resource header owner: root for `include/resource_ids.h`

The final handoff commit is the commit that adds this report after the source commit.
The source commit hash above is copied from Git.

## Scope and method

This worker performed source cleanup only. It did not perform behavior recovery.

I read `AGENTS.md`, `docs/source_cleanup.md`, `docs/source_comments.md`,
`docs/resource_ids.md`, `docs/source_cleanup_owners.md`, `docs/testing.md`,
and `decomp_notes/source_cleanup/wave03_assignments.md`.

I read the pinned VC5 CRT and SDK headers before source changes. The relevant
CRT declarations are in `C:/Program Files (x86)/DevStudio/VC/Include/string.h`.
The pinned Windows definitions are in `C:/Program Files (x86)/DevStudio/VC/Include/windows.h`
and `WINUSER.H`.

I read the registry entry, the complete assigned source, the assigned header,
the durable source note, all assigned original-function packets, and every
assigned scoped PDB record. I reviewed the complete source diff before commit.

The registry is `config/functions/src/scr_vc.cpp.json`. It selects the `gx`
profile and six normal functions. The source PDB path is
`C:\\msdev\\work\\age1_x1\\scr_vc.cpp`.

The original packet evidence is under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/`.
The preserved selected object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/scr_vc.obj`.
No compiler command used this object during this task.

## Complete PDB and packet coverage

All six normal registry functions were inspected. The compiler-generated
vector-deleting destructor was also inspected. Packet hashes are included to
identify the evidence that I read.

| VA | Function | Size | PDB lines | Scoped PDB coverage | Packet |
| --- | --- | ---: | --- | --- | --- |
| `004B8100` | `TRIBE_Mission_Screen::TRIBE_Mission_Screen` | 1707 | 45-194 | `text_in`, `from_game`, `background_bmp`, `starting_description`, `info_file`, `adjusted_name`, and `this` | `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004B8100_TRIBE_Mission_Screen.txt`, SHA-256 `ff50e4141b5d2295fbae06ec4563fe18bbb111c02dcde767b716ae08b47eff98` |
| `004B87B0` | compiler-generated scalar deleting destructor | 30 | no source body | `__flags` and `this` | `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004B87B0_vector_deleting_destructor.txt`, SHA-256 `151f7721ec21c436336232b306e419f3a2b61fbedabe84197e4514b3c58ffcf4` |
| `004B87D0` | `TRIBE_Mission_Screen::~TRIBE_Mission_Screen` | 211 | 200-219 | `this`; no source locals or parameters | `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004B87D0_TRIBE_Mission_Screen.txt`, SHA-256 `72c1cac2eff31761b2a630c2a023b874d390fde6f76b91e9dee29e2896f74e02` |
| `004B88B0` | `TRIBE_Mission_Screen::handle_idle` | 33 | 225-230 | `this`; no source locals or parameters | `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004B88B0_handle_idle.txt`, SHA-256 `67f0ca2290bc09581e6bf15976724cfe14f34bf75cbb499ceb455af78f22afb9` |
| `004B88E0` | `TRIBE_Mission_Screen::draw` | 191 | 236-260 | `this`; no source locals or parameters | `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004B88E0_draw.txt`, SHA-256 `5f1f8ff79c7a3b4141eaf5bb322c18496b16e7fd9614f541973ca7059a87da19` |
| `004B89A0` | `TRIBE_Mission_Screen::action` | 318 | 266-293 | `fromPanel`, `actionIn`, `a1`, `a2`, and `this` | `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004B89A0_action.txt`, SHA-256 `dae8cf1bcf1a62499837e65539feb2816d3262507a11830e0b3fbb7445466e81` |
| `004B8AE0` | `TRIBE_Mission_Screen::key_down_action` | 77 | 299-307 | `key`, `count`, `alt_key`, `ctrl_key`, `shift_key`, and `this` | `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004B8AE0_key_down_action.txt`, SHA-256 `63ddf3b4ecc7fae1875ccdb24152b2ddfd2fc8d867c35a328b0df6fb3e8a87cb` |

The normal packet body ranges are `004B8100-004B87AA`,
`004B87D0-004B88A2`, `004B88B0-004B88D0`, `004B88E0-004B899E`,
`004B89A0-004B8ADD`, and `004B8AE0-004B8B2C`.
The vector-deleting destructor has no handwritten source body.

## Original-name recovery

### `004B8100` — constructor

The scoped PDB records these parameters and locals:

- `text_in`, `char*`, stack offset `+0x4`.
- `from_game`, `unsigned char`, stack offset `+0x8`.
- `background_bmp`, `TPicture*`, stack offset `+0xC`.
- `starting_description`, `unsigned char`, stack offset `-0x21D`.
- `info_file`, `char[260]`, stack offset `-0x110`.
- `adjusted_name`, `char[260]`, stack offset `-0x214`.

The source now uses all six recovered spellings. The old source used
`info_file`, `game_flag`, and `vc_back_bmp` for the three parameters. It used
`setup_file` for the local `info_file`. The source now keeps `game_flag` and
`vc_back_bmp` as the class member names and uses the recovered parameter names.
The local array remains `char info_file[260]`.

The packet source lines show the local setup string copied before the `setup`
call. The packet also shows the fallback resource lookup at line 88 and the
three button IDs at lines 108-110. The source keeps the original array sizes,
copy calls, call order, and the four-byte name truncation.

### `004B87D0` — destructor

The scoped PDB has only `this`. No local or parameter rename was required.
The destructor keeps the original stop-stream condition and deletion order.

### `004B88B0` — `handle_idle`

The scoped PDB has only `this`. No local or parameter rename was required.

### `004B88E0` — `draw`

The scoped PDB has only `this`. No local or parameter rename was required.
The source keeps the three panel-width draw positions and the lock/unlock order.

### `004B89A0` — `action`

The scoped PDB records these parameters:

- `fromPanel`, `TPanel*`, stack offset `+0x4`.
- `actionIn`, `long`, stack offset `+0x8`.
- `a1`, `unsigned long`, stack offset `+0xC`.
- `a2`, `unsigned long`, stack offset `+0x10`.

The source now uses these exact original spellings. This includes the terse
original names `a1` and `a2`. It preserves the source call and parameter order.

### `004B8AE0` — `key_down_action`

The scoped PDB records these parameters:

- `key`, `long`, stack offset `+0x4`.
- `count`, `short`, stack offset `+0x8`.
- `alt_key`, `int`, stack offset `+0xC`.
- `ctrl_key`, `int`, stack offset `+0x10`.
- `shift_key`, `int`, stack offset `+0x14`.

The source now uses all five original spellings. The source keeps the original
comparison with `0x56` and the original use of the fourth parameter.

### Unresolved declaration mappings

The constructor packet contains compiler EH slots (`local_4` and `local_c`) and
a decompiler-only temporary (`local_21c`). These are not source declarations.
The decompiler also labels a byte temporary `local_21d`; the scoped PDB maps the
source declaration to `starting_description`, which the source uses.

The source has no scoped PDB record for `text_button_1` or the loop index `i`.
These existing concise names remain unchanged. They are not claimed as
recovered original names. I did not split or merge any declarations to imitate
reused stack slots.

The vector-deleting destructor has a compiler parameter `__flags`, but it has
no handwritten source declaration. It remains outside `src/scr_vc.cpp`.

## Resource IDs

The source now uses the existing shared macro `IDS_BUTTON_OK` for `0x0FA1`.
The macro is in `include/resource_ids.h`. It preserves the original literal
value and does not add storage. The source includes that existing header.

The remaining four IDs stay numeric. They need new shared macros from the root
owner before this source can replace them. The requested names are descriptive
cleanup names. They are not claimed as original developer symbols.

| ID | Source use and proposed name | Runtime base result | Runtime expansion result | Pinned original expansion result |
| --- | --- | --- | --- | --- |
| `0x0FA1` | `ok_button` caption; existing `IDS_BUTTON_OK` | `runtime/language.dll`, SHA-256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, language `0x0409` (`1033`), exact text `OK` | `runtime/languagex.dll`, SHA-256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, language `0x0409`, missing ID; no empty slot | `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA-256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, language `0x0409`, missing ID; no empty slot |
| `0x2655` | Fallback title when `Get_scenario_name()` returns null or empty; request `IDS_MISSION_TITLE_INSTRUCTIONS` | `runtime/language.dll`, SHA-256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, language `0x0409`, exact text `Instructions` | `runtime/languagex.dll`, SHA-256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, language `0x0409`, missing ID; no empty slot | `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA-256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, language `0x0409`, missing ID; no empty slot |
| `0x2A31` | `text_buttons[0]` caption; it selects scenario message index `4`; request `IDS_MISSION_HISTORY` | `runtime/language.dll`, SHA-256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, language `0x0409`, exact text `History` | `runtime/languagex.dll`, SHA-256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, language `0x0409`, missing ID; no empty slot | `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA-256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, language `0x0409`, missing ID; no empty slot |
| `0x2A32` | `text_buttons[1]` caption; it selects scenario message index `0`; request `IDS_MISSION_INSTRUCTIONS` | `runtime/language.dll`, SHA-256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, language `0x0409`, exact text `Instructions` | `runtime/languagex.dll`, SHA-256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, language `0x0409`, missing ID; no empty slot | `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA-256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, language `0x0409`, missing ID; no empty slot |
| `0x2A37` | `text_buttons[2]` caption; it selects scenario message index `1`; request `IDS_MISSION_HINTS` | `runtime/language.dll`, SHA-256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, language `0x0409`, exact text `Hints` | `runtime/languagex.dll`, SHA-256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, language `0x0409`, missing ID; no empty slot | `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA-256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, language `0x0409`, missing ID; no empty slot |

The extraction outputs are under `build/resource-strings/`:

- `runtime-language.json`
- `runtime-languagex.json`
- `scr_vc-language.json`
- `scr_vc-runtime-languagex.json`
- `scr_vc-languagex.json`

The tool inspected PE bytes. It did not load or execute a DLL. The checked
runtime base path is `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`.
The checked runtime override path is
`C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`.
The pinned original expansion path is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`.

The source packet proves that `0x2655` is passed to `TPanel::get_string` only
for the missing or empty scenario-name fallback. It proves that the three
button IDs are passed to `create_button`. The `action` packet and source prove
the message index roles listed above. The runtime `TRIBE_Game::get_string`
path checks `StringTableX` first and calls the base lookup when that load fails.
The checked expansion DLLs have missing entries, so the base runtime table
supplies the five captions in this path. The names above describe proven roles,
not original macro names.

## Comments and formatting

No new source comment was needed. The existing comment before the scenario-name
truncation remains. The original packet shows the copy and the NUL write at
`004B821F-004B825B`, so the source keeps that compatibility behavior.

The source uses 1TBS braces for all six handwritten definitions. It joins the
short action and key-handler signatures. It preserves source order, control
flow, declarations, types, storage, casts, call order, literal semantics, and
explicit behavior.

## Risk and unresolved work

- Parameter-name changes do not change ABI types, order, or symbol identity.
- The local `setup_file` to `info_file` rename does not change its `char[260]`
  storage or its setup call.
- `IDS_BUTTON_OK` expands to the existing `0x0FA1` value. No new storage or
  layout was added.
- Formatting and the added include can change debug line records or compiler
  details. Generated code, relocations, and direct-call targets are unvalidated.
- The four requested resource macros are not in this source. Their numeric
  literals remain unchanged until root reviews and adds shared declarations.
- The assigned header still has its old parameter spellings because the group
  owner owns that file.
- The compiler-generated vector-deleting destructor remains unowned by a
  handwritten source body and needs complete-module validation.

No structural rewrites, helper functions, layout changes, ABI changes, bug
repairs, assembly, or macro-context fragments were added.

## Shared-file requests

### Request to group owner: `include/scr_vc.h`

Update declaration parameter names to match the scoped PDB. Keep all types,
order, calling conventions, and declarations unchanged.

- Constructor: `info_file` -> `text_in`; `game_flag` -> `from_game`;
  `vc_back_bmp` -> `background_bmp`.
- `action`: `sender` -> `fromPanel`; `actionType` -> `actionIn`;
  `param3` -> `a1`; `param4` -> `a2`.
- `key_down_action`: `param_1` -> `key`; `param_2` -> `count`;
  `param_3` -> `alt_key`; `param_4` -> `ctrl_key`; `param_5` -> `shift_key`.

Evidence: the scoped records at
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
for `004B8100`, `004B89A0`, and `004B8AE0`. The packet line spans are
45-194, 266-293, and 299-307.

### Request to root: `include/resource_ids.h`

Add these shared macros with the listed values. Keep them in the base-language
resource namespace. They are new descriptive cleanup names, not recovered
original symbols.

```cpp
#define IDS_MISSION_TITLE_INSTRUCTIONS 0x2655
#define IDS_MISSION_HISTORY            0x2A31
#define IDS_MISSION_INSTRUCTIONS       0x2A32
#define IDS_MISSION_HINTS              0x2A37
```

Evidence: the constructor packet uses `0x2655` in the fallback call and
`0x2A31`, `0x2A32`, and `0x2A37` in the three `create_button` calls. The action
packet maps those buttons to message indexes `4`, `0`, and `1`. Runtime resource
extraction is recorded above. Leave the source literals unchanged until the
shared declarations exist.

## Validation status

Compilation, matching, audits, tests, and games were **NOT RUN**. I did not
invoke a compiler, build, matching check, audit, test, or game command. I ran
only evidence extraction, resource extraction, `git diff --check`, and full
Git diff review. Compiler-output equality, relocation equality, direct-target
equality, and runtime behavior remain unvalidated.
