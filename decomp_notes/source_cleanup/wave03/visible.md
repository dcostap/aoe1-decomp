# Source-cleanup handoff: `src/visible.cpp`

## Handoff

- Module: `src/visible.cpp`
- Header: `include/visible.h`
- Registry: `config/functions/src/visible.cpp.json`
- Branch: `cleanup/staging-20260915-140`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source cleanup commit: `f4911addc7df44b326e62657638bf69b2d165645`
- Final report commit: this report commit; Git output and the final handoff provide its full hash.
- Changed files:
  - `src/visible.cpp`
  - `decomp_notes/source_cleanup/wave03/visible.md`

The source owns 27 normal functions from the `visible.cpp` PDB module. The
registry selects all 27 addresses. The source order and function boundaries
remain unchanged.

## Scope and evidence

I read `AGENTS.md` and the complete source-cleanup, source-comments,
resource-ID, owner, testing, and wave-assignment guides. I read
`src/visible.cpp` and `include/visible.h`. The header belongs to the group
owner. I did not edit it.

I inspected the registry-selected original packets under the absolute path
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/` for these
27 VAs: `0053C1B0`, `0053C290`, `0053C3C0`, `0053C400`, `0053C490`,
`0053C4D0`, `0053C5D0`, `0053C670`, `0053C680`, `0053C6C0`, `0053C6F0`,
`0053C920`, `0053CAC0`, `0053CCF0`, `0053CE70`, `0053CE80`, `0053CEE0`,
`0053CF10`, `0053CFC0`, `0053CFF0`, `0053D040`, `0053D070`, `0053D0C0`,
`0053D0D0`, `0053D110`, `0053D150`, and `0053D200`. The packets provide
original boundaries, source line spans, call targets, and assembly evidence.

I inspected the procedure-scoped records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json` for
every registered VA. Class methods have the recorded `this` register in ECX.
The two free functions have no register records. The original source evidence
is `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/visible.cpp.decomp`.
The pinned executable is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The pinned language resource is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`,
SHA-256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
The preserved baseline resource input is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/original.res`,
SHA-256 `edd8f671b15254db0be049b421947cda59bbffdeb46a1d4c93176e42bfe9ee3a`.
No runtime DLL was needed for this identifier-only cleanup.

## Original-name recovery

The names below come from the procedure-scoped PDB records. They are recovered
original names. Names marked as cleanup names have no safe PDB mapping. I did
not force names across reused stack slots. I kept types, scopes, storage,
declaration order, evaluation order, calls, literals, and control flow.

| VA | Function | PDB names and source result |
| --- | --- | --- |
| `0053C1B0` | `RGE_Visible_Map::RGE_Visible_Map` | PDB parameters `in_map`, `in_player`; restored from `param_1`, `param_2`. The PDB has only `this` in ECX. The local `row` has no PDB record. |
| `0053C290` | `RGE_Visible_Map::RGE_Visible_Map` | PDB parameters `infile`, `theWorld`, and local `player_id`; restored `file` to `infile` and `world` to `theWorld`. `this` is in ECX. The local `row` has no PDB record. |
| `0053C3C0` | `RGE_Visible_Map::~RGE_Visible_Map` | No stack names. `this` is in ECX. No rename was needed. |
| `0053C400` | `RGE_Visible_Map::save` | PDB parameter `outfile`; restored `handle` to `outfile`. `this` is in ECX. |
| `0053C490` | `RGE_Visible_Map::get_visible` | PDB parameters `map_col` and `map_row`; restored `x` and `y`. `this` is a const pointer in ECX. |
| `0053C4D0` | `RGE_Visible_Map::set_all` | PDB parameter `vis_flag`; restored `value`. `this` is in ECX. |
| `0053C5D0` | `RGE_Visible_Map::explore_all` | No stack names. `this` is in ECX. The locals `y`, `x`, `row`, and `explored` have no PDB records. |
| `0053C670` | `RGE_Visible_Map::percentExplored` | No stack names. `this` is a const pointer in ECX. No rename was needed. |
| `0053C680` | `RGE_Visible_Map::recomputeExplored` | No stack names. `this` is in ECX. The locals `y`, `x`, and `row_ptr` have no PDB records. |
| `0053C6C0` | `RGE_Visible_Map::get_los_table` | PDB parameters `radius` and `Square`; restored `distance` to `radius` and `diagonal` to `Square`. `this` is in ECX. |
| `0053C6F0` | `RGE_Visible_Map::explore_terrain` | PDB parameters `tx`, `ty`, `radius`, `Square`, `UpdateMap`, and `id` already match. PDB locals `tile`, `csum`, `x2`, `y`, `Revealed`, `u`, `VisibleToCurPlayer`, `Tbl`, and `curVisPlayer` map to the source. PDB local `plNum` has no current declaration mapping; I did not add one. `this` is in ECX. The source cleanup names `Tbl`, `y`, and `u` replace `offsets`, `off_y`, and `explored` using the PDB records. `x1`, `visible`, and `value` remain inferred names. |
| `0053C920` | `RGE_Visible_Map::unexplore_terrain` | PDB parameters already match. PDB locals `tile`, `plNum`, `csum`, `u`, and `Tbl` map to the source. `this` is in ECX. The inferred cleanup names `off_y`, `visible`, and `value` replace `offY`, `vis`, and `v`. |
| `0053CAC0` | `RGE_Visible_Map::explore_terrain_sq` | PDB parameters `tx1`, `ty1`, `tx2`, `ty2`, `UpdateMap`, and `id`; restored the four former `x`/`y` parameter names. PDB locals `tile`, `csum`, `Revealed`, `isCurPlayer`, `curVisPlayer`, and `p` map to the source. PDB local `y` has no current declaration mapping because the source preserves the parameter `ty1` as the loop variable. `this` is in ECX. The source keeps the inferred local `u`. |
| `0053CCF0` | `RGE_Visible_Map::unexplore_terrain_sq` | PDB parameters `tx1`, `ty1`, `tx2`, `ty2`, `UpdateMap`, and `id`; restored the four former `x`/`y` parameter names. PDB locals `csum` and `tile` map to the source. PDB local `y` has no current declaration mapping because the source preserves the parameter `ty1` as the loop variable. `this` is in ECX. |
| `0053CE70` | `RGE_Visible_Map::checksum_visible_inputs` | No stack names. `this` is in ECX. The local `value` remains an inferred cleanup name. |
| `0053CE80` | `RGE_Unified_Visible_Map::RGE_Unified_Visible_Map` | PDB parameters `width` and `height`; restored `mapWidth` and `mapHeight` in the definition to the original parameter names. `this` is in ECX. |
| `0053CEE0` | `RGE_Unified_Visible_Map::RGE_Unified_Visible_Map` | PDB parameters `infile` and `world`; restored `map` to `infile`. `this` is in ECX. |
| `0053CF10` | `RGE_Unified_Visible_Map::load` | PDB parameter `infile` and local `oh`; restored `handle` to `infile` and `oldH` to `oh`. `this` is in ECX. The local `old_w` is an inferred cleanup name for `oldW`. |
| `0053CFC0` | `RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map` | No stack names. `this` is in ECX. No rename was needed. |
| `0053CFF0` | `RGE_Unified_Visible_Map::save` | PDB parameter `outfile`; restored `handle` to `outfile`. `this` is in ECX. |
| `0053D040` | `RGE_Unified_Visible_Map::reset` | No stack names. `this` is in ECX. No local rename was needed. |
| `0053D070` | `RGE_Unified_Visible_Map::Set_Map_Offsets` | No stack names. `this` is in ECX. The locals `y`, `row`, and `height` have no PDB records. |
| `0053D0C0` | `RGE_Unified_Visible_Map::suppress_updates` | PDB parameter `mode`; restored `val`. `this` is in ECX. |
| `0053D0D0` | `RGE_Visible_Map::checksumVisible` | No stack names. `this` is in ECX. The locals `value`, `y`, `x`, and `row` have no PDB records. |
| `0053D110` | `RGE_Visible_Map::checksumUnifiedVisible` | No stack names. `this` is in ECX. The locals `value`, `offsets`, `height`, `row`, and `width` have no PDB records. |
| `0053D150` | `log_map_call` | PDB parameters `wt`, `plyr`, `action`, `id`, `x1`, `y1`, `x2`, `y2`, and `sup`; restored all nine `param_1` through `param_9` names. The PDB has no register records. |
| `0053D200` | `dump_vismap_log` | No stack or register names. The inferred locals `done`, `f`, `idx`, and `action` remain unchanged. |

The PDB names `in_map`, `in_player`, `infile`, `theWorld`, `outfile`,
`map_col`, `map_row`, `vis_flag`, `radius`, `Square`, `mode`, `wt`, `plyr`,
`action`, `id`, `x1`, `y1`, `x2`, `y2`, and `sup` are recovered original
spellings. The names `total_tiles`, `off_y`, `visible`, `value`, and `old_w`
are new cleanup names. No public function, class, member, global, type, ABI
symbol, layout, calling convention, or parameter type changed.

## Constants, resources, and comments

No constants were added or replaced. No resource ID was changed. No resource
lookup call, text, buffer size, fallback path, or lookup order changed. No
resource mapping request is needed. No new source comment was needed. Existing
comments remain unchanged.

The source uses the same numeric values, casts, masks, sentinels, format text,
file path, and logging actions. The packet assembly and the original decompiler
source support this unchanged behavior surface.

## Header request

The group owner owns `include/visible.h`. Please consider updating only the
parameter names, without changing types, order, declarations, or ABI:

- `RGE_Visible_Map(RGE_Map* in_map, RGE_Player* in_player)`
- `RGE_Visible_Map(int infile, RGE_Game_World* theWorld)`
- `save(int outfile)` for both `save` declarations
- `get_visible(int map_col, int map_row) const`
- `set_all(unsigned char vis_flag)`
- `get_los_table(int radius, int Square)`
- The terrain methods' existing `x`/`y` names to `tx`/`ty` and `tx1`/`ty1`/`tx2`/`ty2`, while retaining `Square`, `UpdateMap`, and `id`
- `RGE_Unified_Visible_Map(int width, int height)`
- `RGE_Unified_Visible_Map(int infile, RGE_Game_World* world)`
- `load(int infile)`
- `suppress_updates(int mode)`

These names come from `inventory/pdb/scoped_symbols.json`. This worker did not
edit the header. No `include/resource_ids.h` request is proposed.

## Output risk and unresolved items

The source changes rename identifiers and join function signatures. They do
not change expressions, declarations, types, storage, control flow, calls,
literals, layouts, or symbol identity. Formatting can change debug line
records. Renamed locals can change debug names. Generated output remains
unverified.

The PDB does not provide safe mappings for the listed inferred locals. The
`plNum` record in `0053C6F0` and the `y` records in `0053CAC0` and `0053CCF0`
have no current declaration mapping. I did not add declarations or force stack
slot mappings. The header parameter names remain an owner decision.

## Commits

1. `f4911addc7df44b326e62657638bf69b2d165645` — Recover visible map source names.
2. This report commit — Document the visible map cleanup handoff. Git output and the final handoff provide its full hash.

## Validation status

Compilation, matching, audits, tests, and games were **NOT run**. Only evidence
inspection and complete Git diff review were performed. Generated code, program
data, relocations, and direct-target identity remain unvalidated.
