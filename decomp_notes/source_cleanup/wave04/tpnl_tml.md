# `src/tpnl_tml.cpp` source-cleanup report

## Delivery

- Module: `src/tpnl_tml.cpp`
- Report: `decomp_notes/source_cleanup/wave04/tpnl_tml.md`
- Branch: `cleanup/staging-20260915-250`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Source cleanup commit: `320ebf88394be8a8f5c032c6f1b72e7d9cfd4032`.
- Resource correction commit: `a37f59faf13f56e3ecf610b084f6b4f8dac0aec9`.
- Reviewer correction commit: returned separately. This report cannot contain
  its own commit hash without self-reference.
- Changed files:
  - `src/tpnl_tml.cpp`
  - `decomp_notes/source_cleanup/wave04/tpnl_tml.md`
- `include/tpnl_tml.h` was not changed.
- `include/resource_ids.h` was not changed.
- No other tracked file was changed.

The source owns 25 handwritten `Time_Line_Panel` procedures in PDB order.
The compiler-generated scalar-deleting destructor at `0051E770` remains outside
this source owner and was not edited.

The cleanup restores supported PDB parameter names. It records three approved
language-ID mappings. It also applies 1TBS brace placement and readable
wrapping. It does not change statements, types, scopes, storage, calls,
control flow, or source order.

## Correction history

- Initial source cleanup commit:
  `320ebf88394be8a8f5c032c6f1b72e7d9cfd4032`.
- Resource mapping correction commit:
  `a37f59faf13f56e3ecf610b084f6b4f8dac0aec9`.
- Reviewer correction base: integrated head
  `180836230c0c7275581e3489e391546c0c320552`.
- The current reviewer correction commit is returned separately. This report
  cannot contain its own commit hash without self-reference.

## Evidence and hashes

The behavior oracle is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The PDB source path is `C:\msdev\work\age1_x1\tpnl_tml.cpp`. The PDB object
module is `.\\Release\\tpnl_tml.obj`.

The scoped PDB evidence is:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

Its SHA-256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.

The source registry is:

`config/functions/src/tpnl_tml.cpp.json`

The original assembly and decompiler evidence are:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/aoe1_ghidra_assembly_listing.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tpnl_tml.cpp.decomp`

The base source SHA-256 is
`d18e69dfde64eb38fed1929b93ab12ac360e3be8ce38c61f6a02278cb1e1d1f4`.
The pre-correction source SHA-256 is
`84775fd96cde18ebf00b37914f7bcbf7bc299340e0bb3c56fe6d52e9616d5b2d`.
The previous corrected source SHA-256 is
`9b1b1987325be11f6f1cfe522dc8b4afa85ca1329b4964a9634fd9c712da776e`.
The reviewer-corrected source SHA-256 is
`145fdf495d4ac78ff1135aa28981801547a1db574fda08a26904f593c42a37c6`.

## Original-name recovery

I inspected the scoped PDB records for all 25 handwritten procedures. Every
member receiver is recorded in `ecx`. The recovered parameter names are:

| VA | Procedure | Recovered parameters |
| --- | --- | --- |
| `0051E860` | `create_timeline` | `parent`, `time_line`, `x`, `y`, `width`, `height`, `axis_font_num`, `body_font_num`, `ideal_width`, `ideal_height` |
| `0051E9E0` | `setup` | `render_area_in`, `parent_panel_in`, `x_in`, `y_in`, `wid_in`, `hgt_in`, `axis_font_in`, `axis_font_wid_in`, `axis_font_hgt_in`, `body_font_in`, `body_font_wid_in`, `body_font_hgt_in`, `back_pic_in`, `special_event_pic_in`, `fill_back_in`, `back_color_in`, `outline_in`, `outline_color_in` |
| `0051EAB0` | `set_bevel_info` | `bevel_type_in`, `c1`, `c2`, `c3`, `c4`, `c5`, `c6` |
| `0051EB00` | `set_background(char*)` | `file_name` |
| `0051EC10` | `set_background(char*, long)` | `file_name`, `resource_id` |
| `0051EDD0` | `set_special_events(char*)` | `file_name` |
| `0051EEE0` | `set_special_events(char*, long)` | `file_name`, `resource_id` |
| `0051F0A0` | `set_axis_font` | `font_in`, `font_wid_in`, `font_hgt_in` |
| `0051F0D0` | `set_body_font` | `font_in`, `font_wid_in`, `font_hgt_in` |
| `0051F100` | `set_back_color` | `use_back_color_flag_in`, `back_color_in` |
| `0051F4E0` | `add_pop_total_special_event` | `sample_time_slice`, `sample_pop_total`, `sample_x_line_pos`, `time_flag` |
| `0051F560` | `record_special_event` | `player_id`, `history`, `player_color`, `time_slice`, `x_line_pos`, `y_line_pos`, `intermediate_y_line_segment` |
| `0051F600` | `calculate_icon_location` | `event_ptr`, `icon_number`, `history_type` |
| `00520AE0` | `draw_icon` | `event_ptr`, `icon_number`, `history_type` |

The other 11 procedures have no source parameters. Their declarations and
bodies remain in their original order.

### Supported mappings retained

The parameter mappings in the table above are supported by direct PDB records.
They remain in the source. The source retains existing local names when the
PDB type, scope, or use does not prove a distinct declaration.

Several PDB records reuse stack homes or show type aliases. I did not add a
new declaration or force a reused home into a different scope. The source
retains the baseline names, types, initialization points, and storage duration.

### Forced mappings restored to baseline

The reviewer found these earlier local mappings unsupported. The correction
restores each baseline descriptive identifier and all of its uses:

| Procedure | Earlier forced mapping | Restored baseline name |
| --- | --- | --- |
| `calculate_icon_location` | `result` -> `temp_start_txt_x1` | `result` |
| `calculate_icon_location` | `start_y` -> `temp_start_x` | `start_y` |
| `calculate_icon_location` | `start_text_x` -> `temp_start_y` | `start_text_x` |
| `draw_timeline` | `time_slice_counter` -> `time_slice_cntr` | `time_slice_counter` |
| `draw_timeline` | `pop_sample_counter` -> `pop_sample_cntr` | `pop_sample_counter` |
| `draw_timeline` | `dropped_slice_counter` -> `error_correction_drop_time_slice_rate` | `dropped_slice_counter` |
| `draw_timeline` | `pop_total` -> `temp_pop_num` | `pop_total` |
| `draw_timeline` | `special_event` -> `error_correction_time_slice_thickness` | `special_event` |
| `draw_timeline` | `time_slice` -> `next_pop_total` | `time_slice` |
| `draw_timeline` | `next_pop_total` -> `float_remainder` | `next_pop_total` |
| `draw_timeline` | `next_time_slice` -> `y_line_segment_length` | `next_time_slice` |
| `draw_timeline` | `time_slice_thickness` -> `num_intermediate_slices` | `time_slice_thickness` |
| `draw_timeline` | `interpolation_counter` -> `special_event_flag` | `interpolation_counter` |
| `draw_timeline` | `y_line_total` -> `cntr2` | `y_line_total` |
| `draw_timeline` | `segment_remainder` -> `cntr_droped_slice_rate` | `segment_remainder` |
| `draw_timeline` | `population` -> `temp_color` | `population` |

The earlier mapping list also included PDB local names that had no reliable
declaration mapping. None of those names remains forced in these functions.

No public function, class, member, global, ABI symbol, layout, or calling
convention changed.

## Resource evidence

The three lookups in `draw_icon` call `TPanel::get_string`. That method calls
the virtual game string method. `TRIBE_Game::get_string` tries `StringTableX`
first, then the base-game fallback. The base records are present and nonempty.
The extracted base file is:

`C:/Projects/my_decomps/aoe1_attempt3/build/runtime/original-20260914T230838850570Z/language.dll`

Its SHA-256 is
`3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
The extraction record is `build/resource-strings/tpnl_tml-language.json`.
Its SHA-256 is
`0b2df69dc8135c8ffc1459fadf47bfa6ac9d800b3f1aeeb7de7b2f8426f03c69`.

All three records use language `0x0409`:

| ID | Text | Cleanup name | Call-site purpose |
| --- | --- | --- | --- |
| `0x106A` | `Tool Age` | `STRING_ID_HELP_AGE_TOOL` | Age-event label in `draw_icon` case `0`. |
| `0x106B` | `Bronze Age` | `STRING_ID_HELP_AGE_BRONZE` | Age-event label in `draw_icon` case `1`. |
| `0x106C` | `Iron Age` | `STRING_ID_HELP_AGE_IRON` | Age-event label in `draw_icon` case `2`. |

Root approved the existing names for these exact three IDs in
`include/resource_ids.h` at commit
`bf943f3339643ee5beca7dd74e98b4cb729e48d3`. The approval covers no other
resource substitution. The current source uses those three macros and keeps
each numeric value, lookup call, buffer size, lookup order, localization, and
failure path.

For comparison, the inspected expansion file is:

`C:/Projects/my_decomps/aoe1_attempt3/build/runtime/original-20260914T230838850570Z/languagex.dll`

Its SHA-256 is
`4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
The extraction record is `build/resource-strings/tpnl_tml-languagex.json`.
It marks `0x106A`, `0x106B`, and `0x106C` as MISSING. These are missing
entries, not empty slots. The missing expansion entries require the base-game
fallback for these IDs. The extraction does not prove a macro's original name.

The extraction records are exact `RT_STRING` results. They do not prove the
runtime loader path by themselves. The `draw_icon` call site and the game
method chain establish the lookup path here.

### Root approval

The approval evidence is in these exact files:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/reviewer-owner28/language-age-ids.json`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/reviewer-owner28/languagex-age-ids.json`

It covers the following base-language `RT_STRING` lookups:

- Lookup path: `Time_Line_Panel::draw_icon` calls `TPanel::get_string`, which
  calls the virtual game method. `TRIBE_Game::get_string` tries `StringTableX`
  first, then the base-game fallback.
- DLL: `language.dll`, SHA-256
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- Language: `0x0409`.
- `0x106A`: present and nonempty, `Tool Age`; existing name `STRING_ID_HELP_AGE_TOOL`.
- `0x106B`: present and nonempty, `Bronze Age`; existing name `STRING_ID_HELP_AGE_BRONZE`.
- `0x106C`: present and nonempty, `Iron Age`; existing name `STRING_ID_HELP_AGE_IRON`.
- `languagex.dll`: MISSING for all three IDs, not empty slots.

The source adds no new resource name. This worker did not edit the shared
header or change any other resource ID.

## Header request

`include/tpnl_tml.h` was read only. Its declarations use unnamed parameters.
The header owner may align declaration names with these definitions:

```cpp
long create_timeline(TPanel* parent, Time_Line_Panel** time_line,
                     long x, long y, long width, long height,
                     long axis_font_num, long body_font_num,
                     long ideal_width, long ideal_height);
long setup(TDrawArea* render_area_in, TPanel* parent_panel_in,
           long x_in, long y_in, long wid_in, long hgt_in,
           void* axis_font_in, long axis_font_wid_in, long axis_font_hgt_in,
           void* body_font_in, long body_font_wid_in, long body_font_hgt_in,
           char* back_pic_in, char* special_event_pic_in, int fill_back_in,
           unsigned char back_color_in, int outline_in,
           unsigned char outline_color_in);
void set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4,
                    int c5, int c6);
int set_background(char* file_name);
int set_background(char* file_name, long resource_id);
int set_special_events(char* file_name);
int set_special_events(char* file_name, long resource_id);
void set_axis_font(void* font_in, long font_wid_in, long font_hgt_in);
void set_body_font(void* font_in, long font_wid_in, long font_hgt_in);
void set_back_color(int use_back_color_flag_in, unsigned char back_color_in);
void add_pop_total_special_event(long sample_time_slice, long sample_pop_total,
                                 long sample_x_line_pos, int time_flag);
void record_special_event(unsigned char player_id,
                          TRIBE_History_Info* history,
                          unsigned char player_color, long time_slice,
                          long x_line_pos, long y_line_pos,
                          long intermediate_y_line_segment);
int calculate_icon_location(Special_Events* event_ptr, short icon_number,
                            unsigned char history_type);
void draw_icon(Special_Events* event_ptr, short icon_number,
               unsigned char history_type);
```

This is a parameter-name-only request. It changes no type, order, calling
convention, symbol, or layout.

## Code-generation and validation status

The source diff changes supported identifiers, approved resource macro
spellings, whitespace, wrapping, and brace placement. It does not change
executable expressions, field offsets, calls, control flow, or source order.

Compilation, builds, compiler checks, audits, validation, matching checks, and
tests were not run. No executable comparison or runtime harness was run. The
correction was limited to the assigned source and report. The result remains
unvalidated until the final project validation stage.
