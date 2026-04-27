# FUN fragment audit
Generated from `project_full_status.csv` plus `inventory/functions/...` packets. This is a review aid, not an automatic manifest update.

Cleanup applied: the 14 normal scratch `FUN_...` fragment files identified below were moved out of compiler-facing `src/scratch` to `trash/rampant_scratch_quarantine_2026-04-27/fun_fragments/`. After regenerating the dashboard they appear as unclaimed normal entries, because this repo does not yet have a dedicated manifest bucket for PDB-backed C/C++ split-block/codelet artifacts.
## Counts
- Total `FUN_...` entries: 1625
- `toolchain_supplied`: 913
- `asm_region`: 573
- `normal`: 139

## Normal-corpus `FUN_...` summary
- Normal `FUN_...`: 139
- Normal scratches: 14
- Normal matching: 125

Top PDB files among normal `FUN_...`:
- 14: `taitacmd.cpp`
- 6: `stat_obj.cpp`
- 5: `view.cpp`
- 4: `scr_game.cpp`
- 4: `scr_sed.cpp`
- 4: `tplayer.cpp`
- 4: `tpnl_tml.cpp`
- 3: `aipbook.cpp`
- 3: `aiuaimod.cpp`
- 3: `scenario.cpp`
- 3: `scr_mps.cpp`
- 3: `scr_sed2.cpp`
- 3: `taiinfmd.cpp`
- 3: `taistrmd.cpp`
- 3: `taiuaimd.cpp`
- 2: `Act_atak.cpp`
- 2: `act_entr.cpp`
- 2: `act_list.cpp`
- 2: `act_move.cpp`
- 2: `diam_map.cpp`

Classifications among normal `FUN_...`:
- 124: `tiny_padding_or_epilogue`
- 9: `jumps_out_of_body+tiny_jump_codelet+switch_case_landing_pad_likely`
- 2: `small_unknown_fragment`
- 2: `possible_shared_tail_or_split_region`
- 1: `jumps_out_of_body`
- 1: `jumps_out_of_body+possible_shared_tail_or_split_region`

## Normal scratch `FUN_...` entries
| VA | Size | PDB file | Diff | First | Last | Classification | Recommended action |
|---|---:|---|---|---|---|---|---|
| `0047F00C` | 27 | `Res_file.cpp` | MISMATCH 25.9259 | `push 30h` | `ret` | small_unknown_fragment | review |
| `0047F076` | 172 | `Res_file.cpp` |  | `mov ecx,[86B254h]` | `ret` | possible_shared_tail_or_split_region | manual_packet_review_not_stub |
| `00502451` | 12 | `taitacmd.cpp` | MISMATCH 83.3333 | `mov esi,4Bh` | `jmp short 005024BDh` | jumps_out_of_body+tiny_jump_codelet+switch_case_landing_pad_likely | quarantine_scratch_or_region_review |
| `0050245D` | 7 | `taitacmd.cpp` | MISMATCH 71.4286 | `mov esi,5Dh` | `jmp short 005024BDh` | jumps_out_of_body+tiny_jump_codelet+switch_case_landing_pad_likely | quarantine_scratch_or_region_review |
| `00502464` | 12 | `taitacmd.cpp` | MISMATCH 83.3333 | `mov esi,27h` | `jmp short 005024BDh` | jumps_out_of_body+tiny_jump_codelet+switch_case_landing_pad_likely | quarantine_scratch_or_region_review |
| `00502470` | 12 | `taitacmd.cpp` | MISMATCH 83.3333 | `mov esi,49h` | `jmp short 005024BDh` | jumps_out_of_body+tiny_jump_codelet+switch_case_landing_pad_likely | quarantine_scratch_or_region_review |
| `0050247C` | 12 | `taitacmd.cpp` | MISMATCH 83.3333 | `mov esi,5` | `jmp short 005024BDh` | jumps_out_of_body+tiny_jump_codelet+switch_case_landing_pad_likely | quarantine_scratch_or_region_review |
| `00502488` | 7 | `taitacmd.cpp` | MISMATCH 71.4286 | `mov esi,12Bh` | `jmp short 005024B8h` | jumps_out_of_body+tiny_jump_codelet+switch_case_landing_pad_likely | quarantine_scratch_or_region_review |
| `0050248F` | 12 | `taitacmd.cpp` | MISMATCH 83.3333 | `mov esi,4` | `jmp short 005024BDh` | jumps_out_of_body+tiny_jump_codelet+switch_case_landing_pad_likely | quarantine_scratch_or_region_review |
| `0050249B` | 12 | `taitacmd.cpp` | MISMATCH 83.3333 | `mov esi,7Dh` | `jmp short 005024BDh` | jumps_out_of_body+tiny_jump_codelet+switch_case_landing_pad_likely | quarantine_scratch_or_region_review |
| `005024A7` | 12 | `taitacmd.cpp` | MISMATCH 83.3333 | `mov esi,29h` | `jmp short 005024BDh` | jumps_out_of_body+tiny_jump_codelet+switch_case_landing_pad_likely | quarantine_scratch_or_region_review |
| `005024B3` | 279 | `taitacmd.cpp` |  | `mov esi,28h` | `ret 4` | possible_shared_tail_or_split_region | manual_packet_review_not_stub |
| `00536912` | 32 | `view.cpp` |  | `mov edi,[esp+28h]` | `jmp short 00536992h` | jumps_out_of_body | review |
| `00536957` | 428 | `view.cpp` |  | `mov ax,[esi+10Ch]` | `jmp 005364E5h` | jumps_out_of_body+possible_shared_tail_or_split_region | manual_packet_review_not_stub |

## Taitacmd switch/codelet cluster
The `00502451`..`005024B3` scratches all share `taitacmd.cpp` line span `12609-12746`. The tiny entries are 7-12 byte blocks that load constants and jump into shared code at/near `005024BD`, which is characteristic of switch case landing pads or split codelets, not standalone source functions.

Recommended immediate action: quarantine/delete the current scratch files for the `00502451`..`005024B3` cluster from compiler-facing `src/scratch`, then review the enclosing `taitacmd.cpp` function/region as one unit. Do not promote these as ordinary one-function-one-`.cpp` decomp targets.

## Other normal scratch `FUN_...` observations

### `Res_file.cpp` cluster

`0047F00C` and `0047F076` share the broad `Res_file.cpp` line span `70-233`, the same line map as an enclosing resource-file routine. They look like split error/tail blocks inside that routine, not clean standalone source functions.

- `0047F00C` begins with `push 30h / push "RESOURCE ERROR" / push "Error: Reading resfile header." / call MessageBoxA`, then immediately executes the parent epilogue (`pop edi`, `pop esi`, `pop ebx`, `mov esp, ebp`, `pop ebp`, `ret`). The existing scratch body only calls `MessageBoxA`, so the current mismatch is expected; ordinary standalone C++ cannot naturally include the parent epilogue without treating this as a region/codelet.
- `0047F076` appends a resource node to a linked list, then falls through several string/error checks and parent epilogues. The current scratch captures only the linked-list append prefix and returns too early; it is a partial understanding note at best, not a ready per-function attempt.

Recommended action: quarantine from normal scratch unless someone is actively reconstructing the enclosing `Res_file.cpp` routine/region. Keep the linked-list observation if useful, but do not treat these as standalone solved targets.

### `view.cpp` cluster

`00536912` and `00536957` share `view.cpp` line span `2562-3006`, with 163 line records. Both are inside a large routine. `00536912` explicitly starts mid-function and jumps to `00536992`; its scratch note correctly says it is a tail-block fragment. `00536957` is a larger split region with internal returns and a final jump back to `005364E5`; the current scratch is only an empty stub.

Recommended action: keep/quarantine `00536912`'s note as region triage if desired; delete/quarantine `00536957`'s empty stub. Neither should be pursued as a normal one-function-one-`.cpp` target without an enclosing-region plan.

## Practical cleanup recommendation

For the current 14 normal scratch `FUN_...` entries:

- Quarantine/delete the ten `taitacmd.cpp` `005024xx` scratch files from compiler-facing `src/scratch`.
- Quarantine the two `Res_file.cpp` entries as split blocks; preserve any useful note externally or in a region report.
- Keep only `00536912`'s explanatory note if you want a breadcrumb; otherwise quarantine both `view.cpp` entries too.
- Do not touch the 125 normal `FUN_...` files already in `src/matching` during this cleanup pass; they are exact-claimed and mostly tiny padding/epilogue fragments.

## Output
- Full table: `build/fun_fragment_audit.tsv`
