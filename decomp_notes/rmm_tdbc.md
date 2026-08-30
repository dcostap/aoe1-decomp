# rmm_tdbc.cpp source module

`src/rmm_tdbc.cpp` owns all ten PDB functions in source order.
`include/rmm_tdbc.h` owns only the derived controller declaration.

The source composes the canonical DBCT, map, terrain, land, object, elevation,
cliff, and shallows owners. It has no TDBC wrapper or context header.

The debug path and log texts are source-private. The source declares
`debug_rand` locally. It uses the reviewed base-game global declaration.

## Status

`004876C0` reports `MATCH` and `0.0000%` in the direct source module.

The remaining owners stay in their prior honest states until direct validation:

- `004876F0`, `00487710`, `00487930`, `00487940`, `00488700`, `004887A0`,
  and `00488870` are scratch.
- `00487DD0` is accepted drift.
- `00487FA0` remains verified logic. Its ledger is
  `logic_reviews/00487FA0.md`.

The direct natural `00488870` body compiles. It differs by 78 bytes. The
current direct loop changes the old register and zero setup order.

Reopen an owner only with direct source evidence. Do not restore raw cursors,
absolute global macros, copied DBCT layouts, or wrapper context.
