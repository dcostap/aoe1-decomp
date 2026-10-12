# Influence Map module recovery

## Scope

`src/infmap.cpp` owns all 21 normal `infmap.cpp` bodies in PDB order.
It replaces the fragment wrapper and every per-function owner.

The PDB source path is `C:\msdev\work\age1_x1\infmap.cpp`.
`0044E030` is a compiler-generated scalar deleting destructor.

## Canonical ownership

`include/infmap.h` owns `InfluenceMap` and `XYPoint`.
`include/rge_fio.h` owns `rge_read` and `rge_write`.

The source has no context include, local owner class, field overlay, or
absolute memory reference. `printToFile` uses source-local format strings.
Their contents come from the original read-only data records.

`XYPoint` is a structure. Its reference signatures use `ABUXYPoint@@`.
This identity is required for the four reference-argument symbols.

## Original behavior

`0044E680` and `0044E800` compare Y bounds with `xSizeValue`.
The executable proves this behavior. Keep this original bug.

`0044E9E0` keeps the case-zero fall-through into the case-seven suffix.
The switch layout comes from the original executable.

## Focused candidate gate

Command:

`python tools/validate_candidate_tu.py --proposal build/infmap_natural_proposal.json --output-dir build/candidate_tus/infmap_natural`

The candidate has 16 exact rows. Each has `MATCH`, `0.0000%`, matching
ownership, zero relocation mismatches, and zero boundary escapes:

- `0044DF80`, `0044E050`, `0044E080`, `0044E0B0`, `0044E0F0`, and `0044E1A0`;
- `0044E4C0`, `0044E4E0`, `0044E510`, `0044E560`, `0044E680`, and `0044E790`;
- `0044E800`, `0044E900`, `0044F030`, and `0044F040`.

Generated `0044E030` also matches exactly.

In this historical candidate snapshot, `0044E250` remained accepted drift and
`0044ED20` was scratch. Its fresh check
reports 541 differing bytes, 84.56% block-shape similarity, and a high-severity
control-flow difference. The natural body remains unchanged.

In the same snapshot, `0044E600` was scratch and its candidate row had two
boundary escapes. `0044E9E0` was scratch. `0044EC00` was verified logic.
The candidate records their current results.

## Accepted-drift re-review: 2026-09-28

- `0044E250` had a behavior defect: source passed `"wt"`, but original data at
  `0x57F4EC` is `"wa\0"`. Source now passes `"wa"`.
  The original call is at `0044E267`; see `0044E250.md` for instruction evidence.
- `0044E9E0` had no proved behavior defect.
  The current source keeps the case-zero fall-through and the original field order.
- `0044ED20` had no proved behavior defect.
  Original instructions `0044ED2A` through `0044ED30` load and test `min.x`
  before they load the count field. Baseline VC5 output does the same.
  The source-order probes widened the mismatch, so none remains.
- Final source has one change: the `printToFile` mode string.
  No registry, inventory, shared header, status, stage, commit, or integration file changed.

### Final checks

- `0044E250`: state `517cd454aba5caaef4caee473917c2c2480f7dcf274d1fcee94701d72182cc1c`;
  event `3812ca3a03a39d4b540985868de3a924f1d13805c55fb804999eacb5ec157338`.
  Check: `build/experiment_runs/b9d0c8e67e9a4e80a18241ff0d287733/check.txt`.
- `0044E9E0`: state `319b6501f4934e26c7dcfa4f40c02f64c1bb1e513ff7562cd4bbe976f16dfb49`;
  event `74de8f0304c2340a42668cf319b90e7664742cf30a7ceeadb39cfa3c3a2f8247`.
  Check: `build/experiment_runs/26c7f5881d324585b1e693ce7051d7a4/check.txt`.
- `0044ED20`: state `a10faa3c1e4096bb246c75151310f2a9653d264a35f458a27f0da3a0a10c3066`;
  event `0e90efd2200c070e14c58e1f4eb7cabc712c374a546cae00a3b1694fa238783c`.
  Check: `build/experiment_runs/16d7c79aa0f54f0ea346e7e1a4739404/check.txt`.
- Each target check ran with a one-job translation-unit closure.
  The final closure reports 18 matching rows, three observed accepted-drift rows,
  and no exact regressions.
  Its report is `build/experiment_runs/16d7c79aa0f54f0ea346e7e1a4739404/closure/report.txt`.
- Code checks do not prove linked static data or jump-table contents.
  No linked game image or runtime test was used.
  See each function note for open questions and original instruction addresses.
