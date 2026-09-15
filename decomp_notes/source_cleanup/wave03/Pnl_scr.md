# Source-cleanup wave 03: `src/Pnl_scr.cpp`

## Handoff

- Module: `src/Pnl_scr.cpp`.
- Registry: `config/functions/src/Pnl_scr.cpp.json`.
- Build flags: `default`, from the registry.
- Branch: `cleanup/staging-20260915-159`.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final source commit: `31745ac4bd55634ab517f7fc60fc6c04ec31e390`.
- Changed files:
  - `src/Pnl_scr.cpp`
  - `decomp_notes/source_cleanup/wave03/Pnl_scr.md`
- Paired header: `include/Pnl_scr.h`. It was read only.

The source registry lists eight normal functions. It lists no generated
function body. The module also contains the compiler-generated deleting
destructor at `0047BA90`; no source body changed for that function.

## Evidence inspected

I read the repository contract and all assigned cleanup guides. I read the
paired header and the prior module note at `decomp_notes/pnl_scr.md`.

I inspected the registry-selected original packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/`:

- `0047BA70_TScreenPanel.txt`
- `0047BA90_vector_deleting_destructor.txt`
- `0047BAB0_TScreenPanel.txt`
- `0047BAD0_TScreenPanel.txt`
- `0047BAE0_setup.txt`
- `0047BB10_setup.txt`
- `0047BB40_draw.txt`
- `0047BB50_handle_paint.txt`
- `0047BB60_set_focus.txt`

I inspected the procedure-scoped PDB records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The original executable reference is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
The packets provide the original body ranges, line spans, call targets, and
assembly. The PDB provides parameter and local names for the functions below.
Every normal function has a `this` register named `this` in `ecx` with type
`TScreenPanel*`.

## Original-name recovery

The changes restore procedure-scoped PDB spellings. Types, order, scopes,
storage, calls, literals, and expressions stay unchanged.

| VA | Function and PDB span | Recovered names | Result |
| --- | --- | --- | --- |
| `0047BA70` | `TScreenPanel::TScreenPanel`, lines 44-45 | no source parameter or local | Reviewed; no rename needed. |
| `0047BAB0` | `TScreenPanel::TScreenPanel`, lines 52-53 | `name` | Already matched the PDB. |
| `0047BAD0` | `TScreenPanel::~TScreenPanel`, line 59 | no source parameter or local | Reviewed; no rename needed. |
| `0047BAE0` | `TScreenPanel::setup`, lines 66-71 | `render_area_in`, `info_file_name`, `resource_file_id`, `allow_shadow_area_in` | Recovered all four parameters. |
| `0047BB10` | `TScreenPanel::setup`, lines 77-82 | `render_area_in`, `palette_file`, `pal_res_id`, `color_in`, `allow_shadow_area_in` | Recovered all five parameters, including unused parameters. |
| `0047BB40` | `TScreenPanel::draw`, line 88 | no source parameter or local | Reviewed; no rename needed. |
| `0047BB50` | `TScreenPanel::handle_paint`, lines 96-100 | no source parameter or local | Reviewed; no rename needed. |
| `0047BB60` | `TScreenPanel::set_focus`, lines 106-145 | `have_focus_in`, `color`, `color_table`, `save_focus` | Recovered the named parameter and three named locals. |

The source already had `name`, `color`, `save_focus`, and `color_table` in
matching spelling. The source uses a local aggregate named `local` that holds
`save_focus` and `color_table`. The PDB records those members but do not record
the aggregate name. I kept that declaration to preserve its established stack
layout. I did not force a new aggregate name.

The PDB has no reliable source records for the existing `is_new` local, the
`system` local, or the file-scope `last_screen` name. I left them unchanged.
The PDB function-static list is empty. These names are not claimed as recovered
original source names. The generated deleting destructor has only its generated
`__flags` parameter and was not edited.

## Constants, resources, and comments

No constant changed. Existing values such as `0x100`, `-1`, `0.13f`, and the
screen-mode tests remain unchanged. No SDK or CRT symbol replacement was
needed.

This module has no resource lookup call and no investigated resource ID. The
`pal_res_id` parameter is a recovered unused parameter, not a numeric resource
lookup. No resource extraction ran. No shared resource mapping is requested.

No source comment was added. The existing local declaration of
`RGE_fade_palette` remains because its owner header does not publish it.

## Recovered and invented names

Recovered original PDB names:

- `name`
- `render_area_in`
- `info_file_name`
- `resource_file_id`
- `allow_shadow_area_in`
- `palette_file`
- `pal_res_id`
- `color_in`
- `have_focus_in`
- `color`
- `color_table`
- `save_focus`

No new parameter or local name was invented. Existing names without a direct
PDB record are `local`, `is_new`, `system`, and `last_screen`. They remain
unchanged because the PDB does not prove a replacement.

## Code-generation risks

The source change renames parameters and applies 1TBS function braces. It also
adjusts whitespace and wraps two signatures. These changes do not change types,
storage, declaration order, evaluation order, control flow, literals, calls,
virtual slots, public symbols, layouts, or ABI declarations.

The aggregate palette declaration remains unchanged. This avoids a speculative
stack-layout rewrite. The prior module note records seven normal owners and the
generated destructor as matching, with `0047BB60` still scratch and differing
by four bytes. That is prior evidence, not a fresh validation result.

Compiler output, relocations, data, direct-call targets, and debug line records
remain unvalidated after this cleanup.

## Shared-file requests and unresolved questions

No header change is requested. The paired owner retains `include/Pnl_scr.h`.
No shared resource declaration is requested. No duplicate local definition was
added.

The unresolved name mappings are the `local` aggregate, `is_new`, `system`, and
`last_screen`, as described above. Their source declarations remain unchanged.

## Validation status

Compilation, matching, audits, and tests were **not run**. I did not run a
compiler, build, matching check, audit, test, or game. I performed only source,
PDB, original-packet, and Git diff review.
