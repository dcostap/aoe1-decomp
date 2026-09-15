# Source cleanup report: `Sounddrv.cpp`

## Delivery

- Module: `src/Sounddrv.cpp`
- Base commit from `git rev-parse`: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit from `git rev-parse`: pending; the report update follows it.
- Branch: `cleanup/staging-20260915-176`
- Changed files: `src/Sounddrv.cpp`; this report.
- Registry: `config/functions/src/Sounddrv.cpp.json`; build flags `default`.
- Header owner: owner 20 owns `include/sounddrv.h`. This worker did not edit it.

The cleanup covers all 36 procedures in the registry. It restores names from
procedure-scoped PDB records and replaces proved DirectSound and WinMM values
with pinned SDK symbols. It does not change function symbols, types, storage,
control flow, declaration order, call targets, or resource lookup behavior.

The source uses the PDB module object `.\\Release\\Sounddrv.obj` and source
`C:\\msdev\\work\\age1_x1\\Sounddrv.cpp`. The original executable remains the
behavior oracle. Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90` at:

`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

## Evidence

Name and register evidence comes from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/Sounddrv.cpp.json`

I inspected every assigned function packet under:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/`

The inspected packets were:

- `004BC590_TSound_Driver.txt`, `004BC5A0_TSound_Driver.txt`,
  `004BC5C0_TSound_Driver.txt`, `004BC5D0_init_vars.txt`,
  `004BC610_init.txt`, `004BC7C0_exit.txt`, `004BC810_set_path.txt`,
  `004BC850_driver_active.txt`, `004BC860_get_volume.txt`,
  `004BC870_set_volume.txt`, `004BC8D0_stream_file.txt`,
  `004BC930_set_stream_volume.txt`, `004BC950_pause_stream.txt`,
  `004BC960_resume_stream.txt`, `004BC970_stop_stream.txt`,
  `004BC980_handle_messages.txt`, `004BC9B0_add_to_play_list.txt`,
  `004BC9F0_play_list.txt`, `004BCA20_reset_play_list.txt`,
  `004BCA30_open_mixer.txt`, `004BCBF0_close_mixer.txt`.
- `004BCC40_TDigital.txt`, `004BCC80_TDigital.txt`,
  `004BCCB0_TDigital.txt`, `004BCCC0_init_vars.txt`,
  `004BCCF0_exit.txt`, `004BCD30_load.txt`, `004BD300_unload.txt`,
  `004BD370_play.txt`, `004BD490_stop.txt`, `004BD4C0_set_loop.txt`,
  `004BD4E0_set_volume.txt`, `004BD510_set_pitch.txt`,
  `004BD540_set_pan.txt`, `004BD570_is_playing.txt`,
  `004BD5C0_add_to_play_list.txt`.

Each packet records the original boundary, source span, assembly, and owner.
Every scoped PDB record has `this` in `ecx`. The function table below records
all stack symbols, including parameters and locals.

## Original-name recovery

A blank stack entry means the PDB has no stack symbol for that procedure. The
register record is `this` in `ecx` for every row. PDB names retain their source
spelling, including `dsBD`, `resDataSize`, and `wparam`.

| VA | Function | PDB stack records | Source result |
| --- | --- | --- | --- |
| `004BC590` | `TSound_Driver::TSound_Driver` | none | No parameter or local rename. |
| `004BC5A0` | `TSound_Driver::TSound_Driver` | `wnd` `+0x4` `void*`; `path_in` `+0x8` `char*` | Renamed `window` to recovered `wnd`; renamed `path` to recovered `path_in`. |
| `004BC5C0` | `TSound_Driver::~TSound_Driver` | none | No parameter or local rename. |
| `004BC5D0` | `TSound_Driver::init_vars` | none | No parameter or local rename. |
| `004BC610` | `TSound_Driver::init` | `wnd` `+0x4` `void*`; `path_in` `+0x8` `char*`; `dscaps` `-0x60` `_DSCAPS`; `dsBD` `-0x74` `_DSBUFFERDESC`; `fmt` `-0x88` `tWAVEFORMATEX` | Renamed parameters `window` and `path` to recovered `wnd` and `path_in`. Renamed local `dsbd` to recovered `dsBD`. Other names already matched. |
| `004BC7C0` | `TSound_Driver::exit` | none | No parameter or local rename. |
| `004BC810` | `TSound_Driver::set_path` | `path_in` `+0x4` `char*` | Renamed `path` to recovered `path_in`. |
| `004BC850` | `TSound_Driver::driver_active` | none | No parameter or local rename. |
| `004BC860` | `TSound_Driver::get_volume` | none | No parameter or local rename. |
| `004BC870` | `TSound_Driver::set_volume` | `in_vol` `+0x4` `long`; `permanent` `+0x8` `int` | Renamed `volume` and `update_driver` to recovered `in_vol` and `permanent`. |
| `004BC8D0` | `TSound_Driver::stream_file` | `file_name` `+0x4` `char*`; `loop` `+0x8` `int`; `volume` `+0xc` `long`; `file_name2` `-0x104` `char[260]` | Renamed `file`, `mode`, and `resource_id` to recovered `file_name`, `loop`, and `volume`. `file_name2` already matched. |
| `004BC930` | `TSound_Driver::set_stream_volume` | `volume` `+0x4` `long` | The source parameter already matched recovered `volume`. |
| `004BC950` | `TSound_Driver::pause_stream` | none | No parameter or local rename. |
| `004BC960` | `TSound_Driver::resume_stream` | none | No parameter or local rename. |
| `004BC970` | `TSound_Driver::stop_stream` | none | No parameter or local rename. |
| `004BC980` | `TSound_Driver::handle_messages` | `wnd` `+0x4` `void*`; `msg` `+0x8` `unsigned int`; `wparam` `+0xc` `unsigned int`; `lparam` `+0x10` `long` | Renamed `a`, `b`, `c`, and `d` to recovered `wnd`, `msg`, `wparam`, and `lparam`. |
| `004BC9B0` | `TSound_Driver::add_to_play_list` | `sound` `+0x4` `TDigital*` | Renamed `digital` to recovered `sound`. |
| `004BC9F0` | `TSound_Driver::play_list` | none | No parameter or local rename. |
| `004BCA20` | `TSound_Driver::reset_play_list` | none | No parameter or local rename. |
| `004BCA30` | `TSound_Driver::open_mixer` | `num_dev` `-0x4` `unsigned int`; `mixer_id` `-0x8` `unsigned int` | Existing local names already matched recovered names. |
| `004BCBF0` | `TSound_Driver::close_mixer` | none | No parameter or local rename. |
| `004BCC40` | `TDigital::TDigital` | `in_sound_system` `+0x4` `TSound_Driver*`; `file_name` `+0x8` `char*`; `res_id` `+0xc` `long` | Renamed `driver`, `file`, and `resource_id` to recovered `in_sound_system`, `file_name`, and `res_id`. |
| `004BCC80` | `TDigital::TDigital` | `first` `+0x4` `TDigital*` | Renamed `owner` to recovered `first`. |
| `004BCCB0` | `TDigital::~TDigital` | none | No parameter or local rename. |
| `004BCCC0` | `TDigital::init_vars` | none | No parameter or local rename. |
| `004BCCF0` | `TDigital::exit` | none | No parameter or local rename. |
| `004BCD30` | `TDigital::load` | `file_name` `+0x4` `char*`; `res_id` `+0x8` `long`; `buffer_desc` `-0x148` `_DSBUFFERDESC`; `wave_hdr` `-0x134` `_tag_wavheader`; `load_type` `-0x14c` `int`; `mem2` `-0x154` `void*`; `mem1` `-0x150` `void*`; `size2` `-0x158` `unsigned long`; `size1` `-0x15c` `unsigned long`; `file_with_path` `-0x104` `char[260]`; `resDataSize` `-0x108` `int` | Renamed `name` and `param` to recovered `file_name` and `res_id`. The existing local names already matched. Renamed local type `WAVHEADER` to recovered `_tag_wavheader`. |
| `004BD300` | `TDigital::unload` | none | No parameter or local rename. |
| `004BD370` | `TDigital::play` | `status` `-0x4` `unsigned long` | The existing local name already matched recovered `status`. |
| `004BD490` | `TDigital::stop` | none | No parameter or local rename. |
| `004BD4C0` | `TDigital::set_loop` | `loop_count` `+0x4` `short` | Renamed `value` to recovered `loop_count`. |
| `004BD4E0` | `TDigital::set_volume` | `in_vol` `+0x4` `long` | Renamed `value` to recovered `in_vol`. |
| `004BD510` | `TDigital::set_pitch` | `in_pitch` `+0x4` `unsigned long` | Renamed `value` to recovered `in_pitch`. |
| `004BD540` | `TDigital::set_pan` | `in_pan` `+0x4` `long` | Renamed `value` to recovered `in_pan`. |
| `004BD570` | `TDigital::is_playing` | `status` `-0x4` `unsigned long` | The existing local name already matched recovered `status`. |
| `004BD5C0` | `TDigital::add_to_play_list` | none | No parameter or local rename. |

## Locals and unresolved mappings

The PDB records no names for the remaining existing locals. I left them
unchanged. They remain inferred names, not recovered original names:

- `004BC610 init`: `has_secondary`.
- `004BC870 set_volume`: `delta` and `scaled`.
- `004BC9F0 play_list`: `i` and `sound`.
- `004BCD30 load`: `result`, `direct_sound`, `resource_data`, and `fd`.
- `004BD300 unload`: `p`.
- `004BD370 play`: `target`, `original`, `driver`, `loop_flag`, `hr`, and both scoped `result` declarations.
- `004BD490 stop`: `p`.
- `004BD4E0 set_volume`, `004BD510 set_pitch`, and `004BD540 set_pan`: `p`.
- `004BD570 is_playing`: `target`.
- `004BD5C0 add_to_play_list`: `sound_system`.

The PDB has no symbol record for these locals. Optimized stack reuse does not
prove another mapping. I did not force a rename, type, scope, or declaration
change. The external declaration parameters also lack assigned procedure
records and remain unchanged.

The PDB type record `0x19D5` proves `_tag_wavheader`, with size 44 and the 13
fields already present in the source. The source now uses that recovered tag.
The pinned type dump records the same name and fields at
`C:/Projects/my_decomps/aoe1_attempt3/build/direct-tas/original-pdb-types.txt`.

## Constants, resources, comments, and formatting

The pinned VC5 headers were read before these changes:

- `C:/Program Files (x86)/DevStudio/VC/include/DSOUND.H`
- `C:/Program Files (x86)/DevStudio/VC/include/MMSYSTEM.H`
- `C:/Program Files (x86)/DevStudio/VC/include/WINUSER.H`
- `C:/Program Files (x86)/DevStudio/VC/include/FCNTL.H`

The following replacements preserve the original values and their API roles:

- DirectSound `8` became `DSCAPS_PRIMARY16BIT`.
- Cooperative levels `2` and `1` became `DSSCL_PRIORITY` and `DSSCL_NORMAL`.
- Primary-buffer flag `1` became `DSBCAPS_PRIMARYBUFFER`.
- PCM format value `1` became `WAVE_FORMAT_PCM` in both checks and setup.
- Primary-buffer play flag `1` became `DSBPLAY_LOOPING`.
- Secondary-buffer flags `0xE2` became `DSBCAPS_STATIC | DSBCAPS_CTRLDEFAULT`.
- Buffer-lost result `0x88780096` became `DSERR_BUFFERLOST`.
- Status values `1` and `4` became `DSBSTATUS_PLAYING` and `DSBSTATUS_LOOPING`.
- Mixer component `0x1008` became `MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT`.
- Mixer line-info flag `3` became `MIXER_GETLINEINFOF_COMPONENTTYPE`.
- Mixer control type `0x50030001` became `MIXERCONTROL_CONTROLTYPE_VOLUME`.
- Mixer line-controls flag `2` became `MIXER_GETLINECONTROLSF_ONEBYTYPE`.
- Mixer details flags `0` became `MIXER_GETCONTROLDETAILSF_VALUE` and
  `MIXER_SETCONTROLDETAILSF_VALUE` at their respective calls.
- The resource type `0x77617620` became
  `MAKEFOURCC('w', 'a', 'v', ' ')`. The same value identifies `wav` in
  `src/game_globals.cpp`'s `res_extension_table`.

No fixed resource ID or RT_STRING lookup occurs in this module. `res_id` is a
caller-supplied ID passed to `RESFILE_load`. No DLL resource text, language,
empty slot, missing block, or fallback applies. No resource-ID header request
is open.

The existing comment about the shipped double-free path remains unchanged.
The original `004BCD30_load.txt` packet shows the two `free(resource_data)`
calls in that path. No new source comment was added.

The source keeps original numeric sizes, sentinels, buffer lengths, casts,
lookup order, and fallback path. It keeps the exact status comparisons. It does
not turn `status == 1 || status == 4` into a bit-mask test.

## Code-generation risks and review

The recovered names do not affect ABI symbols, function boundaries, storage,
call targets, or parameter types. The `_tag_wavheader` rename changes only the
local type spelling. It keeps the PDB-proven 44-byte layout and all fields.

The SDK symbols expand to the values used by the original assembly. The mixer
macros use `long` constants, and the destination fields and API parameters are
32-bit values. `MAKEFOURCC` returns the same 32-bit `wav ` value required by
`RESFILE_load`; the call has no overload.

No declaration scope, evaluation order, expression, cast, loop, branch, or
lifetime changed. The existing bug and fallback behavior remain. Debug line
records can move because source names and wrapping changed. Final output checks
remain required.

I reviewed the complete source diff against the exact base. The diff contains
only recovered names, proved SDK symbols, the proved local type tag, and line
wrapping for those names. No helper, wrapper, layout change, assembly, or
structural rewrite was added.

## Header and shared-file requests

Owner 20 should update parameter names in `include/sounddrv.h` to match these
PDB records. Types and declaration order remain unchanged:

```cpp
TSound_Driver(void* wnd, char* path_in);
int init(void* wnd, char* path_in);
void set_path(char* path_in);
void set_volume(long in_vol, int permanent);
int stream_file(char* file_name, int loop, long volume);
unsigned int handle_messages(void* wnd, unsigned int msg, unsigned int wparam, long lparam);
int add_to_play_list(TDigital* sound);
TDigital(TSound_Driver* in_sound_system, char* file_name, long res_id);
TDigital(TDigital* first);
int load(char* file_name, long res_id);
void set_loop(short loop_count);
void set_volume(long in_vol);
void set_pitch(unsigned long in_pitch);
void set_pan(long in_pan);
```

No new shared resource mapping is requested. The `_tag_wavheader` type already
has a root-owned forward declaration in `include/game_types.h`; no header edit
was needed here.

## Validation

Compilation, matching, audits, and tests were not run. No build, compiler check,
game, or runtime harness was run. Only PDB and function-packet inspection,
pinned-header inspection, source review, resource-type review, Git diff review,
and `git diff --check` were run.
