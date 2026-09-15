# Wave 02 cleanup report: `scr_cred.cpp`

## Delivery

- Module: `src/scr_cred.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `5842248aa71cd3ccdf2f800902f44ad476f51210`
- Changed files:
  - `src/scr_cred.cpp`
  - `decomp_notes/source_cleanup/wave02/scr_cred.md`
- Base source SHA256: `ef7120cdf9b3dfcb3b5d872bd5d57834ca1c4e9ef336b95055e1f8cf08c74126`
- Final source SHA256 before commit: `604c8e1c5c039b4e27324ccc51234b59c35d71a43d5e3fd820836546984ae609`

The source keeps the sixteen normal registry owners in address order. No header changed.

## Correction review

This correction compacts the short `action` signature and delegated call.
It also compacts the `draw_scrolled_line` call and signature while preserving
aligned continuation lines where wrapping remains.

The direct packet trace below was added to prove the `x2` and `x` mappings.
No structural change was made.

## PDB coverage

I inspected every normal function entry in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The scoped-symbol file SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
I also inspected each matching function packet selected by
`config/functions/src/scr_cred.cpp.json`.
The registry SHA256 is
`ad909e22ed1ed94d052f3d00ab589da1a8018172de6408d58ecacae539294b51`.

| VA | Function | Scoped parameters and locals | Registers |
| --- | --- | --- | --- |
| `004926E0` | `TRIBE_Credits_Screen::TRIBE_Credits_Screen` | `size` (`long`), `temp_file_name` (`char[13]`) | `this` in `ecx` |
| `00492970` | `TRIBE_Credits_Screen::~TRIBE_Credits_Screen` | none | `this` in `ecx` |
| `00492A40` | `handle_mouse_down` | `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key` | `this` in `ecx` |
| `00492A50` | `handle_idle` | none | `this` in `ecx` |
| `00492CC0` | `draw` | none | `this` in `ecx` |
| `00492D50` | `key_down_action` | `key`, `count`, `alt_key`, `ctrl_key`, `shift_key` | `this` in `ecx` |
| `00492D70` | `action` | `from_panel`, `action_in`, `action_val1`, `action_val2` | `this` in `ecx` |
| `00492DB0` | `close_screen` | none | `this` in `ecx` |
| `00492E70` | `TScrollTextPanel::TScrollTextPanel` | `parent_in`, `render_area_in`, `x`, `y`, `wid`, `hgt`, `speed_in`, `font_in`, `font_wid_in`, `font_hgt_in`, `text_in` | `this` in `ecx` |
| `00492F70` | `TScrollTextPanel::~TScrollTextPanel` | none | `this` in `ecx` |
| `00492F80` | `TScrollTextPanel::set_text` | `text_in` | `this` in `ecx` |
| `00492FB0` | `TScrollTextPanel::handle_idle` | none | `this` in `ecx` |
| `00493070` | `TScrollTextPanel::draw` | `old_font` | `this` in `ecx` |
| `00493160` | `TScrollTextPanel::draw_scrolled_line` | parameters `dc`, `draw_row`, `text_line`, `color1`, `color2`; locals `text_len`, `temp_text2`, `x2`, `x`, `text2_len`, `line_rect` | `this` in `ecx` |
| `00493420` | `RGE_fade_palette_start` | `surface_in`, `color_in`, `fade_time_in`, `direction_in`, `new_palette`, `ignore_color1_in`, `ignore_color2_in` | none |
| `00493540` | `RGE_fade_palette_step` | `done`, `delta_time` | none |

The scalar deleting destructors at `00492950` and `00492F50` are compiler-generated.
They are not source owners in the registry and were not changed.

## Recovered names

I restored these names from the scoped PDB records:

- `00492A40`: `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key`.
- `00492D50`: `count`, `alt_key`, `ctrl_key`, `shift_key`.
- `00492D70`: `from_panel`, `action_in`, `action_val1`, `action_val2`.
- `00492E70`: `parent_in`, `render_area_in`, `wid`, `hgt`, `speed_in`, `font_in`, `font_wid_in`, `font_hgt_in`, `text_in`.
- `00492F80`: `text_in`.
- `00493160`: `dc`, `draw_row`, `text_line`, `text2_len`, `x2`, and `x`.
- `00493420`: `surface_in`, `color_in`, `fade_time_in`, `direction_in`, `new_palette`, `ignore_color1_in`, and `ignore_color2_in`.
- `00493540`: `delta_time`.

The `x2` and `x` mappings follow the PDB names and the two text-column uses.
The same names occur in the PDB packet for `TTextPanel::draw_line` at
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047D760_draw_line.txt`.
That packet SHA256 is
`dd0d247991e094f93d6f1944b991654341de7c2d5d8faa9b9565cacfb369bb61`.

I renamed `lVar1` to the invented cleanup name `action_result`.
The local stores the delegated action return value and returns it unchanged.
The PDB has no stable name for this local.

### Direct packet trace for `draw_scrolled_line` coordinates

The direct original packet is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0049/00493160_draw_scrolled_line.txt`.
Its SHA256 is
`7e2bf6e7fe9c59b1234d30a141fd06a3e77807f7dc4ef9a8021ca4f90f545b7e`.

Let `S` be the entry `ESP`. The prologue leaves `ESP` at `S-34h` after the
four register pushes. `00493166` reads `[esp+3Ch]`, which is the `text_line`
argument at `S+0Ch`. The `calc_line_pos` call at `004931E0` pushes five
arguments. Its `ret 14h` restores `ESP` to `S-34h` before `004931E5`.

- `004931EB` reads `[esp+24h]` (`S-10h`), the `line_rect.left` result.
- `004931F1` writes that value to `[esp+40h]` (`S+0Ch`). `004931FC` adds
  five for the non-centred alignment case. `004931FF` stores the adjusted
  first-column coordinate in the same cell.
- `00493209` reads `[esp+40h]`. `00493203` reads `second_column_pos`, and
  `00493214` adds it to the first-column value. `00493216` stores the result
  in `[esp+3Ch]` (`S+08h`), a reused stack cell for the second-column value.

The first-column TextOutA calls read the `[esp+40h]` cell directly. In the
shadow path, `00493293` reads it, `0049329C` subtracts one, and `0049329E`
pushes that x coordinate before `004932A0` calls TextOutA. The normal path
reads it at `004932B7`, pushes it at `004932BE`, and calls TextOutA through
`00493314`. The style-zero path reads it at `0049330C`, pushes it at
`00493313`, and calls TextOutA at `00493314`.

The second-column TextOutA calls read the `[esp+3Ch]` cell. The shadow path
reads it at `0049336D`, subtracts one at `00493376`, pushes it at `00493378`,
and calls TextOutA at `0049337A`. The normal path reads it at `0049338C`,
pushes it at `00493393`, and calls TextOutA at `00493395`. The other text
styles read the same cell at `004933B6`, `004933D5`, and `004933FF` before
their TextOutA calls at `004933C3`, `004933DE`, and `00493408`.

This direct instruction trace proves `text_x` maps to the first-column PDB
name `x2`, and `second_text_x` maps to the second-column PDB name `x`.
The PDB reports reused homes at `+0Ch` and `+10h`; the packet uses dynamic
`[esp+40h]` and `[esp+3Ch]` cells after the call. The mapping does not rely
only on those reused homes or on another function.

The constructor PDB records `size` as `long`. The source retains its existing
`int` type because this wave forbids type changes. Both types are 32-bit here.
This type difference remains an open review item.

Other source locals have no stable scoped PDB name. I left them unchanged.
This includes `zero`, `one`, `font`, `file_buf`, `fd`, `i`, `id`, `shape_slot`,
`music`, `current_mode`, `draw_system`, `no_text`, `now`, `elapsed`, `amount`,
`cur`, `ticks`, `v`, `text`, and `text_y`.
The PDB has no function statics for this module.

## Constants, resources, and comments

No numeric constant changed. Existing `_O_BINARY`, `SEEK_END`, and `SEEK_SET`
spellings remain. No new source comment was needed.

The source passes `0xC38B` to `TScreenPanel::setup` and passes the range
`0xC3EB` through `0xC3F1` to `TShape` constructors named `credit1` through
`credit7`. These are panel and shape resource arguments, not string lookups.
I kept them numeric because this evidence does not prove RT_STRING names.

I ran `python tools/inspect_pe_strings.py --help` before resource inspection.
The tool found no RT_STRING entries for these IDs. Missing blocks and empty slots
are different findings. The checked output files are under this worktree's
ignored `build/` directory.

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
  - SHA256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
  - IDs `50059`, `50155` through `50161`: missing.
- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`
  - SHA256: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
  - IDs `50059`, `50155` through `50161`: missing.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
  - SHA256: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`
  - IDs `50059`, `50155` through `50161`: missing.

No shared resource-ID request is needed.

## Shared-file requests

Owner 11 owns `include/scr_cred.h`. Please add the recovered parameter names
without changing types, order, layout, or ABI:

```cpp
virtual long handle_mouse_down(unsigned char mouse_button_in, long x, long y,
                               int ctrl_key, int shift_key);
virtual long key_down_action(long key, short count, int alt_key, int ctrl_key,
                             int shift_key);
virtual long action(TPanel* from_panel, long action_in,
                    unsigned long action_val1, unsigned long action_val2);
TScrollTextPanel(TPanel* parent_in, TDrawArea* render_area_in, long x, long y,
                 long wid, long hgt, int speed_in, void* font_in,
                 long font_wid_in, long font_hgt_in, char* text_in);
virtual void set_text(char* text_in);
void draw_scrolled_line(void* dc, short draw_row, short text_line,
                        unsigned long color1, unsigned long color2);
```

Evidence for this request is the scoped PDB file and packets at
`00492A40`, `00492D50`, `00492D70`, `00492E70`, `00492F80`, and `00493160`.
The current header SHA256 is
`42ca07ae9ec7e45d3f6f6891b0f2bb65234adb3217d824ae182b4cc23912102b`.

## Code-generation effects and validation

The edits rename parameters and locals, apply 1TBS brace placement, and compact
short handler signatures and calls. The action and draw-scrolled-line wrappers
retain the same argument order and continuation alignment.
They do not change types, declarations, scopes, calls, literals, evaluation
order, layout, calling conventions, or ABI symbols.
Parameter and local names can change debug metadata. Brace placement can change
PDB line records. No compiler check was allowed in this wave.

The original executable evidence file is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
I read `config/toolchain.json` for the pinned VC5 paths.
I did not run a compiler, build, matching tool, audit, test, or game command.
Compilation, matching, audits, and tests were not run.
