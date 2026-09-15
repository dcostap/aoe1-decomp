# Source cleanup: `music.cpp`

## Delivery

- Module: `src/music.cpp`
- Branch: `cleanup/staging-20260915-174`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `8cff18b8d9185d8c4769dcbbc11bdcf80e1e407f`
- Paired header: `include/music.h` (read only; not changed)
- Registry: `config/functions/src/music.cpp.json`
- PDB source: `C:\\msdev\\work\\age1_x1\\music.cpp`
- PDB evidence: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- Inventory evidence: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0046/`

Changed files:

- `src/music.cpp`
- `decomp_notes/source_cleanup/wave03/music.md`

The source restores procedure-scoped PDB names and applies 1TBS function
brace placement. It keeps types, scopes, storage, statements, calls, literals,
source order, and ABI symbols unchanged. It adds no executable statement or
source comment.

## PDB recovery coverage

The registry selects 24 `matching` functions. I inspected every selected
inventory packet and every scoped PDB stack and register record. Each function
has a `this` register record in `ecx` with type `TMusic_System*`.

| VA | Function | PDB parameters and locals | Source result |
| --- | --- | --- | --- |
| `00461910` | `TMusic_System::TMusic_System` | Parameters `music_type_in` (`unsigned char`), `instance_in` (`void*`), `window_in` (`void*`), `sound_system_in` (`TSound_Driver*`), `path_in` (`char*`). No local records. | Restored all five parameter names. |
| `00461A20` | `TMusic_System::~TMusic_System` | No stack records. | No name change. |
| `00461A30` | `open_device` | Locals `status_info` (`tagMCI_STATUS_PARMS`), `open_info` (`tagMCI_OPEN_PARMSA`), `set_info` (`tagMCI_SET_PARMS`), and `file_name` (`char[261]`). No parameters. | All four names already matched. |
| `00461C60` | `close_device` | No stack records. | No name change. |
| `00461D20` | `open_mixer` | Locals `num_dev` and `mixer_id` (`unsigned int`). No parameters. | Both names already matched. |
| `00461EC0` | `close_mixer` | No stack records. | No name change. |
| `00461F00` | `set_music_type` | Parameter `music_type_in` (`unsigned char`). | Renamed `type` to `music_type_in`. |
| `00461F40` | `set_fade_out` | Parameters `fade_out_in` (`int`) and `fade_time_in` (`unsigned long`). | Restored both names. |
| `00461F60` | `set_volume` | Parameters `volume_in` (`long`) and `permanent` (`int`). | Renamed `volume` to `volume_in` and `save` to `permanent`. |
| `00462010` | `play_track` | Parameters `track_in` (`int`), `loop_in` (`int`), and `set_pos_in` (`unsigned long`). | Restored all three names. |
| `00462090` | `play_file` | Parameters `file_name_in` (`char*`), `loop_in` (`int`), and `set_pos_in` (`unsigned long`). | Restored all three names. |
| `00462140` | `play_tracks` | Parameters `start_track_in`, `end_track_in`, `loop_in`, `make_cur_track_in` (`int`), and `set_pos_in` (`unsigned long`). | Restored all five names. |
| `00462200` | `play` | Parameters `start_track_in`, `end_track_in` (`int`), `file_name_in` (`char*`), `make_cur_track_in` (`int`), and `set_pos_in` (`unsigned long`). Locals `track_name` (`char[261]`), `open_info` (`tagMCI_OPEN_PARMSA`), `seek_info` (`tagMCI_SEEK_PARMS`), and `szErrorMsg` (`char[256]`). | Restored all five parameters and renamed `error_message` to `szErrorMsg`. |
| `004625C0` | `pause_play` | No stack records. | No name change. |
| `00462670` | `resume_play` | No stack records. | No name change. |
| `00462740` | `stop_track` | No stack records. | No name change. |
| `00462770` | `stop_playing` | No stack records. | No name change. |
| `00462820` | `fade_track` | No stack records. | No name change. |
| `00462860` | `start_fade` | No stack records. | No name change. |
| `004628A0` | `do_fade` | Local `time` (`float`). No parameters. | The source already used the PDB name `time`. |
| `004629B0` | `end_fade` | No stack records. | No name change. |
| `00462A10` | `handle_messages` | Parameters `wnd` (`void*`), `msg` (`unsigned int`), `wparam` (`unsigned int`), and `lparam` (`long`). | Restored all four names. |
| `00462B40` | `after_end_track` | No stack records. | No name change. |
| `00462C30` | `get_play_info` | Parameters `music_type_in` (`unsigned char*`), `track_from_in`, `track_to_in`, and `cur_track_in` (`int*`), `music_file_in` (`char*`), `loop_in` (`int*`), and `pos_in` (`unsigned long*`). Local `status_info` (`tagMCI_STATUS_PARMS`). | Restored all seven parameters. The local already matched. |

The scoped PDB records repeat `szErrorMsg` and `seek_info` at the same stack
homes in `play` because the optimized procedure has multiple scope records.
The source keeps one declaration for each existing array or structure. No
stack-slot type or declaration mapping was forced.

The selected packet names are:

- `00461910_TMusic_System.txt`, `00461A20_TMusic_System.txt`,
  `00461A30_open_device.txt`, and `00461C60_close_device.txt`.
- `00461D20_open_mixer.txt`, `00461EC0_close_mixer.txt`,
  `00461F00_set_music_type.txt`, `00461F40_set_fade_out.txt`, and
  `00461F60_set_volume.txt`.
- `00462010_play_track.txt`, `00462090_play_file.txt`,
  `00462140_play_tracks.txt`, and `00462200_play.txt`.
- `004625C0_pause_play.txt`, `00462670_resume_play.txt`,
  `00462740_stop_track.txt`, and `00462770_stop_playing.txt`.
- `00462820_fade_track.txt`, `00462860_start_fade.txt`,
  `004628A0_do_fade.txt`, and `004629B0_end_fade.txt`.
- `00462A10_handle_messages.txt`, `00462B40_after_end_track.txt`, and
  `00462C30_get_play_info.txt`.

## Recovered and unresolved names

The recovered original spellings are the PDB names listed in the table. This
includes mixed styles such as `music_type_in`, `set_pos_in`, `permanent`,
`szErrorMsg`, `wnd`, `msg`, `wparam`, and `lparam`. The source does not
normalize these names.

The source retains existing descriptive names without a scoped PDB record,
including `scan_file`, `mci`, `flags`, `result`, `count`, `file_handle`,
`was_playing`, `was_auto`, `delta`, and the local `type` in
`handle_messages`. These are not claimed as original names. The PDB has no
safe declaration mapping for them, so no new declarations or forced stack-slot
mappings were added.

The constructors and method declarations in `include/music.h` remain unchanged
because owner 20 controls that header. The source-only definitions keep the
same types and signatures.

## Constants, resources, and comments

No numeric constant, enum, resource ID, or symbolic constant changed. The
existing MCI command values, mixer values, file flags, format strings, and
sentinels remain intact. The local pinned VC5 headers inspected were:

- `C:/Program Files (x86)/DevStudio/VC/include/MMSYSTEM.H`
- `C:/Program Files (x86)/DevStudio/VC/include/STDIO.H`
- `C:/Program Files (x86)/DevStudio/VC/include/STRING.H`
- `C:/Program Files (x86)/DevStudio/VC/include/FCNTL.H`

This module has no resource-ID lookup. No resource extraction or resource
header request applies. The static file formats and the existing fallback text
`"Unknow Error"` remain unchanged.

No source comment was added. No existing comment was changed.

## Evidence and identity review

The selected inventory packets provide the original function boundaries, source
line records, assembly, and call targets. The scoped PDB JSON provides all
available procedure parameters, locals, and registers.

The original executable remains the behavior oracle:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
- SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The preserved pre-cleanup artifacts are:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/music.obj`
- SHA256: `69585dc12fcadd8575150dcf5c1b7802967c1067478146bb7ae5e15022a70657`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
- SHA256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`

All source changes are identifier renames or opening-brace placement. They do
not change types, declaration order, storage, member layout, evaluation order,
control flow, literals, calls, relocations, function boundaries, or ABI symbol
identity. Renamed identifiers do not change generated instructions. Brace
placement can change debug line records. Generated output remains unvalidated
until final wave checks.

## Header request

Owner 20 controls `include/music.h`; I did not edit it. The owner may apply
these name-only declaration updates without changing types or ABI:

```cpp
TMusic_System(unsigned char music_type_in, void* instance_in, void* window_in,
              TSound_Driver* sound_system_in, char* path_in);
int set_music_type(unsigned char music_type_in);
void set_fade_out(int fade_out_in, unsigned long fade_time_in);
void set_volume(long volume_in, int permanent);
int play_track(int track_in, int loop_in, unsigned long set_pos_in);
int play_file(char* file_name_in, int loop_in, unsigned long set_pos_in);
int play_tracks(int start_track_in, int end_track_in, int loop_in,
                int make_cur_track_in, unsigned long set_pos_in);
int play(int start_track_in, int end_track_in, char* file_name_in,
         int make_cur_track_in, unsigned long set_pos_in);
int get_play_info(unsigned char* music_type_in, int* track_from_in,
                  int* track_to_in, int* cur_track_in, char* music_file_in,
                  int* loop_in, unsigned long* pos_in);
```

No root-owned shared declaration or resource-ID request exists.

## Validation

I reviewed the complete source diff and ran `git diff --check`.

Compilation, matching, audits, and tests were not run. No build, compiler check,
game, or runtime harness was run.

**Compilation, matching, audits, and tests were not run.**
