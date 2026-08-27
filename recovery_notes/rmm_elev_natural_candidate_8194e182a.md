# Natural `rmm_elev.cpp` candidate status ledger

## Scope and result

This ledger records the held natural candidate at commit
`8194e182a98263aeeaa1c695c980f1fd4861d61e` (`Add natural rmm elevation source candidate`).
It is evidence only. It does not change source ownership, registration, or status
metadata.

- Candidate source: `src/rmm_elev.cpp`.
- Candidate proposal: `build/rmm_elev_candidate.json`.
- Candidate report: `build/candidate_tus/rmm_elev_natural/report.json`.
- Flags: `config/flags/default.rsp`.
- PDB owner module: `rmm_elev.cpp`.
- Calling convention: `__thiscall` for all ten rows.
- Candidate result: `success=false`, `proposal_valid=false`,
  `comparison_errors=0`, `full_module_exact=false`.
- Summary: six exact rows, two exact results; four observed rows, one exact
  result; ten compiled rows, three exact results.

`RELOCS` below means candidate relocation target mismatches. The candidate
report records zero target mismatches for every row. `BOUNDARY` is the count of
candidate boundary escapes.

## Completed ten-row review

| VA | PDB lines | Oracle body | Candidate bytes | Candidate result | Owner / relocs / boundary | Recommendation and reason |
| --- | ---: | --- | ---: | --- | --- | --- |
| `004846C0` `RGE_RMM_Elevation_Generator` | 21-25 | `004846C0-004846FA` (59) | 59 / 59; 0 bytes; 0.0000% | `MATCH` | match / 0 / 0 | **Exact.** Retain the exact owner. |
| `00484700` `generate` | 29-59 | `00484700-004847BE` (191) | 191 / 187; 158 bytes; 82.722513% | `MISMATCH` | match / 0 / 0 | **Exact owner retained.** The natural reunited source does not preserve the standalone exact bytes. |
| `004847C0` `check_start_elevation` | 64-95 | `004847C0-0048489F` (224) | 224 / 224; 147 bytes; 65.625000% | `MISMATCH` | match / 0 / 0 | **Accepted drift.** Keep the reviewed drift classification. |
| `004848A0` `check_elevation` | 100-153 | `004848A0-00484A37` (408) | 408 / 401; 340 bytes; 83.333333% | `MISMATCH` | match / 0 / 0 | **Accepted drift.** Keep the reviewed drift classification. |
| `00484A40` `generate_modifiers` | 159-193 | `00484A40-00484B2F` (240) | 240 / 240; 7 bytes; 2.916667% | `MISMATCH` | match / 0 / 0 | **Exact owner retained.** The natural reunited source does not preserve the standalone exact bytes. |
| `00484B30` `fig_chance` | 198-205 | `00484B30-00484B4B` (28) | 28 / 28; 0 bytes; 0.0000% | `MATCH` | match / 0 / 0 | **Exact.** Retain the exact owner. |
| `00484B50` `count_map_tiles` | 211-221 | `00484B50-00484B85` (54) | 54 / 93; 93 bytes; 100.000000% | `MISMATCH` | match / 0 / 5 | **Exact owner retained.** The natural Tile loop crosses five body-boundary offsets. Final integration waits for the canonical Tile header and row fanout. |
| `00484B90` `link_stack_randomly` | 225-260 | `00484B90-00484C79` (234) | 234 / 234; 0 bytes; 0.0000% | `MATCH` | match / 0 / 0 | **Exact promotion candidate.** See the promotion evidence below. Current accepted-drift metadata remains unchanged. |
| `00484C80` `remove_area_from_lists` | 264-285 | `00484C80-00484CFF` (128) | 128 / 122; 73 bytes; 57.031250% | `MISMATCH` | match / 0 / 0 | **Exact owner retained.** The natural reunited source does not preserve the standalone exact bytes. |
| `00484D00` `base_elevation_generate` | 290-403 | `00484D00-004851F8` (1273) | 1273 / 1276; 1223 bytes; 95.846395% | `MISMATCH` | match / 0 / 1 | **Scratch.** The mismatch is large and the candidate crosses one owner boundary. Keep this row out of promotion. |

The six exact recommendations refer to the reviewed standalone exact owners.
They do not claim that the held natural module is exact for all six rows.

## Direct target ledger

All targets below are direct calls. The addresses and symbol identities come
from the original function records and original assembly.

- `004846C0` constructor: `00480790`
  `RGE_Random_Map_Module::RGE_Random_Map_Module`.
- `00484700` `generate`: `00480E50` `clear_stack`, `00484A40`
  `generate_modifiers`, `00484D00` `base_elevation_generate`, and `004568C0`
  `RGE_Map::clean_elevation`.
- `004847C0` `check_start_elevation`: no direct calls.
- `004848A0` `check_elevation`: no direct calls.
- `00484A40` `generate_modifiers`: `0054B700` `__ftol`.
- `00484B30` `fig_chance`: no direct calls.
- `00484B50` `count_map_tiles`: no direct calls.
- `00484B90` `link_stack_randomly`: `004230A0` `debug_rand` twice, then
  `00480DE0` `RGE_Random_Map_Module::add_stack_node`.
- `00484C80` `remove_area_from_lists`: `00480E20`
  `RGE_Random_Map_Module::remove_stack_node`.
- `00484D00` `base_elevation_generate`, in direct call order: `00480CC0`
  `init_stack`; `00484B90` `link_stack_randomly`; `0054B700` `__ftol`;
  `00480DA0` `pop_stack`; `004847C0` `check_start_elevation`; `00484C80`
  `remove_area_from_lists`; `00480D10` `push_stack` four times;
  `00480DA0` `pop_stack`; `004230A0` `debug_rand`; `004848A0`
  `check_elevation`; `00484B30` `fig_chance`; four pairs of `004230A0`
  `debug_rand` and `00480D10` `push_stack`; and `00480CF0` `deinit_stack`.
  This is 23 direct call operations.

## `00484B90` promotion evidence

The held natural candidate emits an exact `00484B90` body:

- `MATCH`, 0 differing bytes, `0.0000%`.
- Original and rebuilt size: 234 bytes.
- PDB owner: `RGE_RMM_Elevation_Generator::link_stack_randomly` in
  `rmm_elev.cpp`, lines 225-260.
- Rebuilt owner symbol:
  `?link_stack_randomly@RGE_RMM_Elevation_Generator@@IAEXPAUMap_Stack@@@Z`.
- Owner status: `match`.
- Relocation target mismatches: 0.
- Boundary escapes: 0.
- Original and rebuilt instruction count: 85.
- Original and rebuilt frame: none.
- Saved registers: `ebx`, `ebp`, `esi`, `edi`.
- Three direct calls are aligned: two `debug_rand` calls and one
  `add_stack_node` call.
- CFG signals: four conditional branches, zero jumps, and one return on both
  sides.
- Focused comparison evidence records 5/5 safely masked relocations, zero
  relocated call sites, and zero target-count differences.

This is sufficient evidence for an exact-status promotion review of this row.
The review does not perform that promotion. The current accepted-drift source
and status metadata remain in place until the natural module is integrated.

## Proven ownership and integration gate

`RGE_RMM_Elevation_Generator` owns these members in the PDB source order. It
inherits the 0x30-byte `RGE_Random_Map_Module`; `info` starts at `+0x30`.
The proven base fields used here are `map_row_offset` at `+0x10`, `map_width` at
`+0x14`, `map_height` at `+0x18`, and `search_map_rows` at `+0x24`.
`RGE_Tile` is 0x18 bytes. Its terrain and height bits share byte `+0x05`;
terrain uses bits 0-4 and height uses bits 5-7.

The original `00484D00` frame is `sub esp, 0x988`. Its 0x948-byte `Map_Stack`
array starts at entry-relative `-0x948`, and element 99 ends at entry `ESP`.
The natural source still emits a 0x980-byte frame. This explains the scratch
recommendation and the boundary escape.

Final source integration waits for the canonical Tile header and row fanout,
and uses `height` for row traversal. This is an integration gate, not a source
or header change in this ledger.

## Evidence sources

- `orig/ghidra_decomp/rmm_elev.cpp.asm` and the original executable bytes.
- `inventory/pdb/function_source_map.csv`.
- The ten `inventory/functions/0048/00484*.txt` records.
- `build/rmm_elev_candidate.json`.
- `build/candidate_tus/rmm_elev_natural/report.json` and `report.txt`.
- `recovery_notes/00484D00_base_elevation_generate_audit.md`.
- `src/rmm_elev.cpp` at commit `8194e182a`.

No production source, public header, candidate registration, or status metadata
was changed for this note.
