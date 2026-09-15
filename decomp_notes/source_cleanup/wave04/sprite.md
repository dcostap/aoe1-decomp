# Source-cleanup report: `src/sprite.cpp`

## Delivery

- Module: `src/sprite.cpp`
- Header read-only: `include/sprite.h`
- Header owner: owner 23
- Branch: `cleanup/staging-20260915-206`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Source cleanup commit: `e08c04ec673f459c01a049107868db2aecf4a4d5`
- Source name correction commit: `080c03fc194a7587c3550de7593aaf5228b78b22`
- Report commit: the commit that adds this report; Git records its full hash.
- Changed files:
  - `src/sprite.cpp`
  - `decomp_notes/source_cleanup/wave04/sprite.md`
- `include/sprite.h` was not changed.
- No other file was changed.

The source changes recover PDB names and replace a few generated local names.
They do not change types, storage, control flow, calls, literals, or source order.

## Scope and evidence

I read the repository contract and these complete guides:

- `docs/source_cleanup.md`
- `docs/source_comments.md`
- `docs/resource_ids.md`
- `docs/source_cleanup_owners.md`
- `docs/testing.md`
- `decomp_notes/source_cleanup/wave04_assignments.md`

I read the assigned source, read-only header, function registry, and root
sprite note. I checked every registered sprite procedure in the PDB and its
function inventory packet. The PDB module is `.\\Release\\sprite.obj`, and its
source is `C:\\msdev\\work\\age1_x1\\sprite.cpp`.

Additional main-root evidence paths were:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-206/src/sprite.cpp`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-206/include/sprite.h`
- `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/sprite.md`
- `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/source_cleanup/wave04_assignments.md`

The original executable is the behavior oracle:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

The preserved pre-cleanup build was read at:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`

I did not change that directory.

## Original-name recovery coverage

Coverage is complete for all 22 registered procedures. I checked each PDB
parameter, local, function-static, and register record. Every procedure has a
`this` record in `ecx`. No procedure has a PDB function-static record.

| VA | Procedure | PDB parameters | PDB locals | Source result |
| --- | --- | --- | --- | --- |
| `004BF720` | `RGE_Sprite::RGE_Sprite` | `in_id` | None | Restored `in_id`. |
| `004BF790` | `RGE_Sprite::RGE_Sprite` | `infile`, `sounds`, `c_tables` | `index1`, `info`, `lock1` | Restored all mapped names. Renamed the three-facet loop and sound ID locals. |
| `004BFA20` | `RGE_Sprite::RGE_Sprite` | `infile`, `in_id`, `sounds` | `temp_main_sound`, `temp_animated`, `index1`, `temp_draw_level`, `temp_loop_once`, `last_facet`, `temp_transparent_picking_flag`, `sound_facet`, `temp_mirror_flag`, `temp_color_flag`, `temp_randomize_on_start`, `count`, `temp_micro_sound_num`, `temp_directional`, `sound_frame`, `sound_id` | Restored `in_id`. Existing matching names were kept. Reused PDB homes were not forced into declarations. Renamed two generated locals to `sound_index` and `sound_frame_value`. |
| `004BFCE0` | `RGE_Sprite::~RGE_Sprite` | None | None | No rename was supported. |
| `004BFD40` | `RGE_Sprite::rehook` | `sprites` | None | Existing name matched the PDB. |
| `004BFDA0` | `RGE_Sprite::save` | `outfile` | `index1`, `info`, `lock1` | Restored the parameter and the two mapped loop locals. |
| `004BFFE0` | `RGE_Sprite::load_facets` | `sprites` | None | Restored `sprites`. |
| `004BFFF0` | `RGE_Sprite::play_sound` | `frame1`, `frame2`, `facet` | None | Restored all three parameters. |
| `004C00E0` | `RGE_Sprite::get_facetindex` | `facet`, `frame`, `facetindex` | None | Restored the output parameter `facetindex`. |
| `004C01A0` | `RGE_Sprite::do_draw` | `facet`, `frame`, `x`, `y`, `player_color`, `draw_area`, `min_draw_level` | `facetindex`, `fname`, `s` (listed twice) | Restored `player_color`, `min_draw_level`, and `s`. |
| `004C04F0` | `RGE_Sprite::draw` | `facet`, `frame`, `x`, `y`, `sx`, `sy`, `player_color`, `draw_area`, `min_draw_level` | `index` | Restored all mapped parameters. `index` already matched. |
| `004C0620` | `RGE_Sprite::normal_draw` | `facet`, `frame`, `x`, `y`, `player_color`, `draw_area` | `index` | Restored the parameters. Kept `index`; renamed the normalized facet alias to `local_facet`. |
| `004C0720` | `RGE_Sprite::shadow_draw` | `facet`, `frame`, `x`, `y`, `player_color`, `draw_area`, `flag` | `index` | Restored the parameters. The PDB `index` home is reused by the `facet` parameter in the current source form, so no extra declaration was added. |
| `004C0840` | `RGE_Sprite::get_size` | `xmin`, `ymin`, `xmax`, `ymax`, `facet` | `fname` | Restored the four output names. `facet` and `fname` already matched. |
| `004C0960` | `RGE_Sprite::get_frame` | `min_x`, `min_y`, `max_x`, `max_y`, `facet`, `frame` | `index`, `fname` | Restored the PDB order names `facet`, `frame`. Existing `fname` matched. The PDB `index` home is reused and has no separate source declaration. |
| `004C0B70` | `RGE_Sprite::get_frame_min_max` | `min_x`, `min_y`, `max_x`, `max_y`, `facet`, `frame`, `pic_x`, `pic_y` | `calc_min_y`, `facetindex`, `calc_min_x`, `calc_max_x`, `calc_max_y` | Restored `pic_x`, `pic_y`, and `facetindex`. Renamed `local_4` to `calc_max_y_value`; the PDB `calc_min_x` and `calc_max_x` records are reused parameter homes. |
| `004C0C50` | `RGE_Sprite::get_lowest_draw_level` | None | None | No rename was supported. |
| `004C0C90` | `RGE_Sprite::hit_test` | `x`, `y`, `facet`, `frame` | `index` | Restored `frame` and `index`. |
| `004C0D80` | `RGE_Sprite::shape_hit_test` | `x`, `y`, `facet`, `frame` | `ymax`, `xmax`, `shape_num`, `ymin`, `xmin`, `fname` | Restored `shape_num`. Existing parameter and bound names matched. |
| `004C0F90` | `RGE_Sprite::make_active_sprite` | None | None | No rename was supported. |
| `004C1030` | `RGE_Sprite::check_for_shadows` | None | None | No rename was supported. |
| `004C1080` | `RGE_Sprite::update` | `curr_time` | None | Restored `curr_time`. |

### Name details

Recovered original names came from the procedure-scoped PDB records. These
include `in_id`, `infile`, `sounds`, `c_tables`, `index1`, `info`, `lock1`,
`outfile`, `frame1`, `frame2`, `facetindex`, `player_color`,
`min_draw_level`, `sx`, `sy`, `flag`, `xmin`, `ymin`, `xmax`, `ymax`, `pic_x`,
`pic_y`, `frame`, `shape_num`, `s`, and `curr_time`.

The existing `temp_*`, `sound_*`, `last_facet`, `fname`, and `index` names
also match PDB records where the table lists them. I did not normalize the
mixed PDB spelling.

The following names are new descriptive cleanup names. They are not claims
about original developer names:

- `sound_index` replaces `local_4` in the text-file constructor.
- `sound_frame_value` replaces `local_e` in the text-file constructor.
- `local_facet` separates the normalized facet alias from the recovered facet
  parameter in `normal_draw` and `shadow_draw`.
- `calc_max_y_value` replaces `local_4` in `get_frame_min_max`.

No new declaration was added. Each name change keeps its original declaration,
scope, type, initialization point, and storage duration.

### Unresolved and reused declarations

I did not force a name into a declaration when the PDB home was reused or when
the current source has no distinct declaration.

- The text-file constructor records `temp_main_sound` and `temp_mirror_flag`,
  but the current source has no distinct declarations that can be mapped to
  them. It also records `count` and `temp_micro_sound_num` at a reused positive
  home. The source keeps `in_id` and `sound_count` in their current types and
  scopes.
- `get_frame` records `index` at a reused positive home. The current source
  has no separate `index` declaration.
- `get_frame_min_max` records `calc_min_x` and `calc_max_x` at reused parameter
  homes. The source keeps the existing parameter aliases and the distinct
  `calc_max_y_value` local.
- `shadow_draw` records local `index`, but the current source uses the recovered
  `facet` parameter as the loop counter after the normalized facet alias is
  saved. No extra local was added.
- PDB records do not exist for several existing descriptive locals, including
  `sound_count`, `sound_slot`, `frame_index`, `x_value`, `entry_offset`, and
  the allocation and loop aliases. They remain unchanged unless the cleanup
  name above was supported by direct use and a safe declaration mapping.

No public function, class, member, global, ABI symbol, layout, calling
convention, or source owner changed.

## Resource, constant, and comment evidence

The module has no string lookup, resource macro, language ID, or resource-ID
constant use. The `resource_id` member is serialized and passed to `TShape`; it
is not a resource namespace lookup in this source. No resource extraction was
needed. No resource request is open.

No new constant or enum was added. No unexplained numeric value was replaced.

The existing constructor comment about the final `fscanf` count remains. Its
identifier changed from `sprite_id` to the recovered `in_id` name. The comment
records a proven parameter-home alias and the need to preserve the partial-scan
value. No other source comment was added.

## Header request

`include/sprite.h` was read only, as requested. Its parameter names still use
older names and placeholders. The header owner may align declaration names with
the recovered definitions. This is a parameter-name-only request. It changes
no type, order, calling convention, symbol, or layout.

Requested declaration names:

```cpp
RGE_Sprite(short in_id);
RGE_Sprite(int infile, RGE_Sound** sounds, RGE_Color_Table** c_tables);
RGE_Sprite(FILE* infile, short in_id, RGE_Sound** sounds);
void save(int outfile);
void load_facets(RGE_Sprite** sprites);
void play_sound(short frame1, short frame2, short facet);
unsigned char get_facetindex(long facet, long frame, long& facetindex);
void do_draw(long facet, long frame, long x, long y,
             RGE_Color_Table* player_color, TDrawArea* draw_area,
             unsigned char min_draw_level);
unsigned char draw(long facet, long frame, long x, long y, long sx, long sy,
                   RGE_Color_Table* player_color, TDrawArea* draw_area,
                   unsigned char min_draw_level);
unsigned char normal_draw(long facet, long frame, long x, long y,
                          RGE_Color_Table* player_color, TDrawArea* draw_area);
unsigned char shadow_draw(long facet, long frame, long x, long y,
                          RGE_Color_Table* player_color, TDrawArea* draw_area,
                          unsigned char flag);
int get_size(long& xmin, long& ymin, long& xmax, long& ymax, long facet);
int get_frame(short& min_x, short& min_y, short& max_x, short& max_y,
              long facet, long frame);
int get_frame_min_max(short& min_x, short& min_y, short& max_x, short& max_y,
                      long facet, long frame, short pic_x, short pic_y);
unsigned char hit_test(short x, short y, long facet, long frame);
unsigned char shape_hit_test(short x, short y, long facet, long frame);
void update(unsigned long curr_time);
```

The `rehook` declaration already uses `sprites`.

## Module status and code-generation limits

The registry covers all 22 owners. Its reviewed statuses are:

- Accepted drift: `004BF790`, `004BFA20`, `004C00E0`, `004C0B70`, and
  `004C0D80`.
- Matching or reviewed matching: the remaining registered owners except
  `004C1080`.
- `004C1080 update` is `new_verified_logic` in the registry.

The existing root sprite note also records earlier context concerns for
`shadow_draw` and `hit_test`, plus accepted drift and the `update` review. This
cleanup does not claim to repair those issues.

The source diff changes identifiers and one signature line break. It preserves
all declarations, types, scopes, casts, literals, calls, branches, loops,
source order, and explicit `this->` use. It adds no wrapper, helper, assembly,
header, binary dependency, or compiler steering.

Identifier changes can change debug names and line records. The source does
not claim generated-code equality until final validation.

## Evidence hashes

These hashes were taken from the absolute main-root evidence paths. The registry
hash is included because it defines the 22-owner scope. The original PE hash is
included as the behavior-oracle reference.

| Evidence path | SHA-256 |
| --- | --- |
| `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/sprite.cpp.json` | `73df4deee64273390cb554465b0d03a60e03a12083f3eafffa40edf5f20c387b` |
| `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json` | `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335` |
| `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe` | `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90` |

The 22 function packet paths below are relative to
`C:/Projects/my_decomps/aoe1_attempt3/` and have these hashes:

| VA | Packet path | SHA-256 |
| --- | --- | --- |
| `004BF720` | `inventory/functions/004B/004BF720_RGE_Sprite.txt` | `008669d80eca3257dae1acda08998d9e827b3273c2e1e03f164ed08d7ddc0536` |
| `004BF790` | `inventory/functions/004B/004BF790_RGE_Sprite.txt` | `3cb7e26d0f815de010bf20391fde2c94f991c97fa0bc992ece33442aacf7d649` |
| `004BFA20` | `inventory/functions/004B/004BFA20_RGE_Sprite.txt` | `0bc04ea3ffd2a8c323857a31df37ad4b384be8c83cdc2c171f35011f7c68e8c7` |
| `004BFCE0` | `inventory/functions/004B/004BFCE0_RGE_Sprite.txt` | `d506a1b71d2ba9c950ace4a9a539624c003fc32bab7c314865f7e64ca9aaefce` |
| `004BFD40` | `inventory/functions/004B/004BFD40_rehook.txt` | `0564773e440c5009ec92d29e9e001b480e6262b4874fbe3e38a92d05b6e476c2` |
| `004BFDA0` | `inventory/functions/004B/004BFDA0_save.txt` | `df4797ab72b68ca48842175c988a9cc73306a0cfe83cdf7ac1dce66fa1635af0` |
| `004BFFE0` | `inventory/functions/004B/004BFFE0_load_facets.txt` | `9a3782af09cca51be52604c14d6e5e7d1970ebf4abd1e0238ee980c2a763a863` |
| `004BFFF0` | `inventory/functions/004B/004BFFF0_play_sound.txt` | `bc1031139f5a4421e62438a98046c8d9782c2bc7552995cf41b0113ca1095a9e` |
| `004C00E0` | `inventory/functions/004C/004C00E0_get_facetindex.txt` | `16fd94753aba68be1ff16ecc66b83aa47ebfb2af843a77c208ee52ec90914947` |
| `004C01A0` | `inventory/functions/004C/004C01A0_do_draw.txt` | `ac913a611424997728964cd4d8e3923988fd59022d7f499ba79df9668476fb1e` |
| `004C04F0` | `inventory/functions/004C/004C04F0_draw.txt` | `f496822f899cccbe1f6ee0a9aa422d545b821e5a779d348cb73c16df146f61b1` |
| `004C0620` | `inventory/functions/004C/004C0620_normal_draw.txt` | `452acd740d116821ed8767a11adecfed4f062d2cccc44d5638e2069f568e9251` |
| `004C0720` | `inventory/functions/004C/004C0720_shadow_draw.txt` | `d6e91b6998c2fa8f6493a7d1a7b3e93af7a2e5cef171c277dd3a1d8498e38c31` |
| `004C0840` | `inventory/functions/004C/004C0840_get_size.txt` | `4f8f6f90b242c94e9558c88d63423c8c49b35a84462efdb0b1b9904232b84b69` |
| `004C0960` | `inventory/functions/004C/004C0960_get_frame.txt` | `77d01cd4b5749d82922534bbecdb3539ba60f7826e37d8114ba197a4d1767031` |
| `004C0B70` | `inventory/functions/004C/004C0B70_get_frame_min_max.txt` | `5c0cc1eb081a1398579884eff0dcacdea56eedb305462b4d2ad9297ff7f5bdc1` |
| `004C0C50` | `inventory/functions/004C/004C0C50_get_lowest_draw_level.txt` | `4460646b0c966277191f3bb5f614b687e2a464926edf36ce6f1504ef2130ee31` |
| `004C0C90` | `inventory/functions/004C/004C0C90_hit_test.txt` | `80503d33e55ab9079f97be81b4ec7563e3ead04028bb3f3ba4b9f6d46ad4b744` |
| `004C0D80` | `inventory/functions/004C/004C0D80_shape_hit_test.txt` | `a6e9ea4dab73d6d42d1cc57a1ceced2fc606a4355de8f2787bbc0a655cf5042a` |
| `004C0F90` | `inventory/functions/004C/004C0F90_make_active_sprite.txt` | `2b22c81cc8261eece35f0866737ec7c12d5c34a9347e8b6355e972069e8efdfe` |
| `004C1030` | `inventory/functions/004C/004C1030_check_for_shadows.txt` | `c734a5f129508c774e709f59221dfe73c37745c427f0b2eb092069041f4748d5` |
| `004C1080` | `inventory/functions/004C/004C1080_update.txt` | `0c6b19726c27b8151f1d93edb9cf16759b8313465e96788eca162e28ee248a2a` |

## Validation

Allowed preparation and review checks performed:

- Read the complete assigned source and header.
- Read the registry and all 22 function packets.
- Read every assigned procedure in `scoped_symbols.json`.
- Inspected the original executable path and preserved baseline directory.
- Reviewed the complete `src/sprite.cpp` diff.
- Ran `git diff --check`.

Compilation, matching, audits, and tests were not run. I did not run a
compiler, build, matcher, audit, automated test, menu suite, gameplay suite,
or game. The cleanup remains unvalidated until final comparison.

## Commits

- Base: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Source cleanup: `e08c04ec673f459c01a049107868db2aecf4a4d5`
- Source name correction: `080c03fc194a7587c3550de7593aaf5228b78b22`
- Report: the commit that adds this report; copy its full hash from Git.
