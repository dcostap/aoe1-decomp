# Function notes: 0050B820 `get_cur_id`

Module notes: `decomp_notes/tdlg_lst_module.md`.

## Translation-unit context

- PDB module: `tdlg_lst.cpp`; owning class: `TRIBE_Dialog_List`.
- Natural source order is the six-method `src/tdlg_lst.cpp` module.
- Target range: `0050B820-0050B83A` (27 bytes), with a direct tail jump to
  `RGE_Dialog_List::get_cur_id` at `0047EB60`.
- The typed inherited member `list_type` is at `this+0x4AC`.

## Current mismatch

- Fresh baseline and retained source use no frame and no local calls.
- Original code is 27 bytes: `mov`, `sub 100`, two `dec` instructions, three
  short equality branches, the tail jump, `or ax,-1`, and `ret`.
- The best natural rebuild is 29 bytes. It matches the load, subtract, first two
  decrement branches, return value, and owner symbol, but emits an extra `test`
  and places the tail jump after the local return block.
- The remaining strict difference is 15 bytes (55.1724%); shape similarity is
  72.73%, with 70.00% exact-block coverage. The boundary has two extra bytes.

## Recovered attempt history

<!-- recovered:f4c804102e6c798336c1 -->
### `0c00f3d2dd72` `src/scratch/0050B820_get_cur_id.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TRIBE_Dialog_List::get_cur_id (27B)
// Attempt log:
// v6: compound expression approach
```
<!-- end-recovered:f4c804102e6c798336c1 -->

## Rejected approaches

- Direct typed comparisons and the inequality chain emit `cmp` instructions.
- A typed `switch` emits range-style comparisons and does not reproduce the
  subtract/decrement chain.
- Sequential statement-split decrements add branches and are much farther from
  the original.
- Short-circuit arithmetic and explicit if/else or label ordering remain in the
  same `dec; test; branch` code-generation basin.
- Raw field/padding stubs are not retained. They violate the natural typed
  panel access requirement.

## Open questions

- The original source form that makes VC5 place the tail jump before the shared
  `-1` return block remains unknown.
- The mismatch is localized to the third decrement branch and block layout.

## Next useful approaches

- If more work is approved, test only period-plausible arithmetic source forms
  that preserve typed `list_type` access and the known tail-call target.
- Do not reopen direct comparisons, switches, or raw-layout stubs without new
  compiler evidence.

## Worker updates

- `wave10-tdlg`: Tested typed comparisons, switch, arithmetic short-circuit,
  nested and split decrement forms. Retained the natural arithmetic decrement
  chain because it gives the closest code and correct behavior. Final
  validation checkpoint: `MISMATCH`, 15 bytes (51.7241%), 72.73% shape, 29
  rebuilt bytes versus 27 original bytes. No exact match.
