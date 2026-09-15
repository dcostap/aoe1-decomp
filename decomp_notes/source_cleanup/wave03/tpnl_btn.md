# Source-cleanup report: `src/tpnl_btn.cpp`

## Delivery

- Module: `src/tpnl_btn.cpp`
- Slot and branch: 167, `cleanup/staging-20260915-167`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `5032101aed8d8d3eb6a9fcc31315ba832e8858f8`
- Changed files in the source commit:
  - `src/tpnl_btn.cpp`
- Changed files in the report commit:
  - `decomp_notes/source_cleanup/wave03/tpnl_btn.md`
- The source and report commits contain no other files.
- Header owner: owner 19 owns `include/tpnl_btn.h`. This worker did not edit it.

## Correction 1

Correction base: `3b72d82d2e2e5bb6a62fcb7fd63bdda58d04f6a1`.
This correction applies 1TBS to every definition in `src/tpnl_btn.cpp`.
It joins each short signature with its opening brace. The wrapped constructor
keeps its parameter list and puts its opening brace after the closing `)`.

The registry packet is `config/functions/src/tpnl_btn.cpp.json`. It selects seven
normal procedures in source order. The selected registry statuses are six
`matching` procedures and `accepted_drift` for `TRIBE_Panel_Button::draw`.
The source changes names and one verified SDK constant. They preserve types,
scopes, storage, calls, casts, literal values, control flow, and layouts.

## PDB coverage and name recovery

The scoped PDB evidence is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Its SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The source PDB is `C:\msdev\work\age1_x1\tpnl_btn.cpp`.
The original PDB SHA256 is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.

I inspected the stack and register records for all seven assigned normal
procedures. Every procedure has `this` in ECX. The function packets are under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/`.
No assigned procedure has a PDB function-static record. Their scoped names and
coverage are:

| VA | Function | PDB span | PDB parameters | PDB locals | Register records |
| --- | --- | --- | --- | --- | --- |
| `00519DA0` | `TRIBE_Panel_Button::TRIBE_Panel_Button` | `50-68` | `render_area_in` (`TDrawArea*`), `parent_panel_in` (`TPanel*`), `sound_in` (`TDigital*`), `font_in` (`void*`), `font_wid_in` (`long`), `font_hgt_in` (`long`), `border_pic_in` (`TShape*`) | none | `this` (`TRIBE_Panel_Button*`) in ECX |
| `00519EA0` | `TRIBE_Panel_Button::set_text_msg` | `74-82` | `text_msg_in` (`char*`) | none | `this` (`TRIBE_Panel_Button*`) in ECX |
| `00519EE0` | `TRIBE_Panel_Button::is_inside` | `88-100` | `x` (`long`), `y` (`long`) | none | `this` (`TRIBE_Panel_Button*`) in ECX |
| `00519F40` | `TRIBE_Panel_Button::draw` | `109-317` | none | `old_font` (`void*`, `-0x1C`), `calc_y` (`long`, `-0x20`), `y` (`long`, `-0x2C`), `frame` (`short`, `-0x20`), `x` (`long`, `-0x24`), `text` (`char*`, `-0x28`), `text_size` (`tagSIZE`, `-0x14`), `msg` (`char[10]`, `-0x0C`) | `this` (`TRIBE_Panel_Button*`) in ECX |
| `0051A570` | `TRIBE_Panel_Button::set_display_garrison` | `320-323` | `value` (`int`) | none | `this` (`TRIBE_Panel_Button*`) in ECX |
| `0051A590` | `TRIBE_Panel_Button::set_garrison_number` | `326-329` | `value` (`int`) | none | `this` (`TRIBE_Panel_Button*`) in ECX |
| `0051A5B0` | `TRIBE_Panel_Button::get_garrison_number` | `332-334` | none | none | `this` (`TRIBE_Panel_Button*`) in ECX |

The constructor packet is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/00519DA0_TRIBE_Panel_Button.txt`.
The other selected packets are
`00519EA0_set_text_msg.txt`, `00519EE0_is_inside.txt`,
`00519F40_draw.txt`, `0051A570_set_display_garrison.txt`,
`0051A590_set_garrison_number.txt`, and
`0051A5B0_get_garrison_number.txt` in the same directory. I inspected each
packet's original assembly and decompiler excerpt as supporting evidence.

The source now restores these recovered PDB spellings:

- Constructor parameters: `draw_area` to `render_area_in`, `parent` to
  `parent_panel_in`, `sound` to `sound_in`, `font` to `font_in`,
  `font_width` to `font_wid_in`, `font_height` to `font_hgt_in`, and `border`
  to `border_pic_in`.
- `set_text_msg` parameter: `text` to `text_msg_in`.
- `draw` local: `message` to `msg`, with the same `char[10]` storage and scope.
- `is_inside` parameters `x` and `y`, and the `value` parameters in
  `set_display_garrison` and `set_garrison_number`, already matched.
- All other PDB-named `draw` locals already matched and remain unchanged.

The PDB records place `calc_y` and `frame` in the same stack offset
(`-0x20`) at different lifetimes. The source keeps them as separate
variables. No mapping was forced from a reused slot.

The PDB has no scoped names for the current source locals `screen`, `map_view`,
`border_drawn`, `dc`, `center_x`, `text_length`, or `second_length`. I left
them unchanged. These are descriptive source names, not recovered original
names. The field spelling `garrsion_number` comes from the read-only header and
remains unchanged.

The module also has two generated destructor procedures in the PDB inventory.
They have no source line records and no source body in this module:

| VA | Procedure | PDB records |
| --- | --- | --- |
| `00519E70` | scalar deleting destructor | `this` in ECX; `__flags` (`unsigned int`) at `+0x4` |
| `00519E90` | `TRIBE_Panel_Button::~TRIBE_Panel_Button` | `this` in ECX; no stack symbols |

I inspected their packets and left them unchanged because they are compiler
output without a natural source body here.

## Constants, resources, comments, and requests

The two `SetBkMode` calls changed their second argument from literal `1` to
`TRANSPARENT`. The pinned SDK defines `TRANSPARENT` as `1` in
`C:/Program Files (x86)/DevStudio/VC/Include/WINGDI.H` at line 1302, and the
same header declares `SetBkMode(HDC, int)` at line 2716. The header SHA256 is
`23f25eec95cf776f75add1c694f0cb920e8e54dd9bf26320755e864ac76f0554`.
The replacement keeps the original value and effective `int` argument type.
Other numeric values remain unchanged because this module has no stronger
symbol mapping for them.

No resource lookup or resource ID occurs in this module. No resource ID was
investigated, so no DLL extraction or resource mapping request is needed.
No comments were added. No existing comment needs correction.

Header request to owner 19: add the recovered parameter names to
`include/tpnl_btn.h`. Keep the existing types and declaration order:

```cpp
TRIBE_Panel_Button(TDrawArea* render_area_in, TPanel* parent_panel_in,
                   TDigital* sound_in, void* font_in, long font_wid_in,
                   long font_hgt_in, TShape* border_pic_in);
void set_text_msg(char* text_msg_in);
virtual int is_inside(long x, long y);
void set_display_garrison(int value);
void set_garrison_number(int value);
```

The constructor and `set_text_msg` names are recovered from the PDB. The
other parameterized method names already match their PDB records. This worker
did not edit the header. The request does not change any ABI type or layout.

## Code-generation and unresolved items

The source commits change parameter and local identifiers only, except for the
`TRANSPARENT` macro replacement. The correction also changes brace placement
and signature wrapping. The macro expands to the same literal `1`.
No ABI, type, layout, symbol, call target, cast, control-flow, evaluation
order, storage, buffer, or literal value changed. The constructor call was
wrapped for readability without moving a statement. Generated output was not
rechecked in this wave.

The existing durable note
`decomp_notes/functions/0051/00519F40.md` records a prior exact-codegen
investigation for `TRIBE_Panel_Button::draw`, including the retained branch
coordinate form. This worker did not repeat those historical compiler checks.

Evidence hashes:

- Preserved baseline report:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`
  SHA256 `fddd62868626e21ec7282183fa1cf84ad5b0b14fc719c8830a266d6ed0f155b3`.
- Baseline report object for this module:
  `C:/Projects/my_decomps/aoe1_attempt3/build/executable/ai-rng-filename-repair/20260915T083203564911Z/tpnl_btn.obj`
  SHA256 `c8f7e36a531cbe37d002c63289c922d4f4424a0ac09a14e6c8dc12682023d266`.
- Preserved baseline executable hash from that report:
  `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
- Original executable:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

## Validation status

Evidence extraction, SDK/header inspection, hash checks, and complete Git diff
review ran. Compilation, builds, matching, audits, tests, and game commands
were not run. No compiler, build, matching, audit, test, or game command was
run for this assignment.
