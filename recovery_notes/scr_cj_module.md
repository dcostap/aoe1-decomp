# scr_cj.cpp source recovery

## Module

- PDB source: `C:\msdev\work\age1_x1\scr_cj.cpp`
- Source: `src/scr_cj.cpp`
- Header: `include/scr_cj.h`
- Owners: nine normal functions in PDB source-line order.
- Generated entries: `00491970` scalar deleting destructor and `00492310`
  vector deleting destructor. Both remain compiler-generated.
- Padding entry: `00491C42` is listed in
  `config/padding_only_functions.txt` and remains outside source ownership.

The address sequence is `00491650`, `00491990`, `00491A80`, `00491B20`,
`00491C70`, `00491E20`, `004920C0`, `00492330`, and `004923C0`.
PDB lines run from 62 through 513. The class owners are `TribeJoinScreen`
and `TribeMPCreateDialog`.

## Context evidence

The PDB source path, line bands, and address sequence identify `scr_cj.cpp`.
The join-screen constructor, destructor, handlers, list builder, and action
provide exact anchors for the first class. The dialog constructor, destructor,
and action provide exact anchors for the second class. The original wrapper
contained the five earlier owners in this order before the three later owners.

The generated packet is under
`build/tu_plans/scr_cj_cpp/packet.{json,txt}`. The requested Terra contract
path `build/source_reunification/terra_system/orchestrator_contract.md` was
absent from this worktree. This absence is a process blocker, not a binary
ownership hypothesis.

## Migration record

The old wrapper was `src/scr_cj_tu.cpp`. It included one source fragment for
each normal owner and selected declarations with `SCR_CJ_GROUPED_TU`. The new
`src/scr_cj.cpp` owns all nine bodies in PDB order. `include/scr_cj.h` owns the
module declarations and proven layouts. No source fragment, wrapper include,
fallback declaration, context-selection macro, fake virtual slot, raw vptr,
or inline assembly remains in the compiler-facing module.

The two generated deleting destructors are not hand-written. The padding-only
`00491C42` source stub was removed because the reviewed padding manifest owns
that entry and ordinary source must not contain inline assembly.

## Status and checks

The source-module manifest is `config/source_modules/scr_cj.json`. It records
six matching owners, two scratch owners, and one accepted-drift owner. The
translation-unit registry points its six exact owners to the direct module
source and records module name `scr_cj`.

The source uses `config/flags/00491E20_action.rsp`, which is
`/nologo /c /O2 /Oy /GX`. `/GX` is supported by the original EH registration.

Before migration, the wrapper had six registered exact owners:
`00491650`, `00491990`, `00491A80`, `00491B20`, `00491C70`, and `00492330`.
The three observed owners were `00491E20`, `004920C0`, and `004923C0`.
The generated entries were `00491970` and `00492310`.

The direct module checks returned `Result: MATCH` and `0.0000%` for all six
registered owners: `00491650`, `00491990`, `00491A80`, `00491B20`, `00491C70`,
and `00492330`. Each matched its original boundary, owner symbol, relocation
targets, and direct calls.

The candidate TU report is
`build/candidate_tus/scr_cj_natural/report.{json,txt}`. It also matched both
compiler-generated deleting destructors, `00491970` and `00492310`. Its three
observed normal owners stayed nonexact: `00491E20` differs by 14 bytes,
`004920C0` differs by 31 bytes, and `004923C0` differs by 38 bytes. All three
have zero relocation-target mismatches and zero boundary escapes.

The candidate validator requires source-bank paths for exact proposal owners.
The report therefore lists all nine normal owners as observed while the
registered configuration keeps only the six exact owners. The candidate used
the generated `build/tmp/scr_cj_candidate.cpp` include bridge only for that
validator limitation; the compiler-facing source has no `.cpp` include.

## Regressions and blockers

The direct migration preserved all six exact owners and both generated entries.
It did not change the three observed bodies. Their existing evidence blockers
remain as follows:

Open process blocker:

- `build/source_reunification/terra_system/orchestrator_contract.md` is absent.

Open evidence blockers from the prior owner records:

- `00491E20` retains a 14-byte EH handler identity and FS/ESI unwind-order
  difference. Its ordinary-path body, calls, frame, and CFG remain
  behavior-ready but not exact.
- `004920C0` retains a 31-byte constructor schedule difference. Its calls,
  frame, CFG, and post-initialization body match. It remains accepted drift.
- `004923C0` retains a 38-byte grouped EH-tail and shared-return difference.
  It remains scratch until that review.
