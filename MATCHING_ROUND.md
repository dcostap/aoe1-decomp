# Accepted-drift matching round

## Plan

- Work through the functions with `accepted_drift` status in `config/functions/`.
- Use at most five workers. Give each worker one target and a reusable worktree.
- Workers may change shared source and headers. They must check affected functions and repair regressions where possible.
- Try different evidence-backed approaches before stopping. Do not stop after a fixed number of attempts.
- Integrate worthwhile changes on main after reviewing source and fresh validation.
- Keep accepted-drift status unless exactness is proved and integrated.

## Progress

- Starting main commit: `e5e8f15dd`.
- Starting registry: 237 `accepted_drift` entries across 93 registry files.
- Assigned:
  - Slot 1: `00403D90`, `src/act_gath.cpp`, `../aoe1-match-slot-1`, agent `sa-42e3ab20`: integrated; slot ready.
  - Slot 2: `00410050`, `src/aipbook.cpp`, `../aoe1-match-slot-2`, agent `sa-75f0ed1d`.
  - Slot 3: `004012B0`, `src/act_atak.cpp`, `../aoe1-match-slot-3`, agent `sa-ccd95373`.
  - Slot 4: `0040E520`, `src/aimodule.cpp`, `../aoe1-match-slot-4`, agent `sa-f05f503a`.
  - Slot 5: `0040B1A0`, `src/aiconmod.cpp`, `../aoe1-match-slot-5`, agent `sa-d40aeaaf`.
- Integrated: `00403CE0`, `00403D90`, `00406E00` exact matches.
- Open: 226 unassigned entries; four assignments in progress. `00401170`, `00404590`, `00405850`, and `00412240` stay accepted drift.

## Work log

Record each assignment here with its target VA, worker, worktree, result, validation, integration decision, and next step.

- `00403CE0`: Reordered two reads and the fallback x/y/z stores in `src/act_gath.cpp`. Main check: 174/174 bytes, 64/64 instructions, correct owner and five aligned calls. Main `act_gath` audit: no exact-neighbor regressions. Owner audit: zero mismatches. Promoted to `matching`; no runtime or linked-image check yet. Preserved worker experiment states, events, objects, and candidate patch.
- `00404590`: No supported source change. Four preserved experiment states. The best result remains two register-selection bytes in a virtual call; the original behavior and call target agree. Worker `act_list` audit: 24 exact claims passed; owner audit: zero mismatches. Keep `accepted_drift`. No runtime or linked-image check ran. Note: `decomp_notes/functions/0040/00404590.md`.
- `00405850`: No supported source change. Two bytes differ in one vptr register load. The `PathResult` probes failed compilation or produced the same output. Worker `act_move` audit: eight exact neighbors passed. Keep `accepted_drift`; no runtime or linked-image check ran. Note: `decomp_notes/functions/0040/00405850.md`.
- `00406E00`: Separate state-2 branches reproduce three virtual call sites. Main check: 70/70 bytes, 25/25 instructions, matching owner and boundary. Main `act_tran` audit: nine existing exact claims pass; owner audit: zero mismatches. Promoted to `matching`. No runtime or linked-image check ran. Note: `decomp_notes/functions/0040/00406E00.md`.
- `00401170`: No source change. Best result remains 45 differing bytes of 311 after source probes, 64 variants, and 12 ambient samples. Worker `act_atak` audit: nine exact claims passed; owner audit: zero mismatches. Keep `accepted_drift`; linked checks and runtime remain open. Note: `decomp_notes/functions/0040/00401170.md`.
- `00412240`: No source change. One SIB byte differs, with the same effective address. Seven source alternatives produced no exact match. Worker `airesitm` audit: 15 exact claims pass. Keep `accepted_drift`; no runtime edge tests ran. Note: `decomp_notes/functions/0041/00412240.md`.
- `00403D90`: Direct target-ID comparison and x/y/z write order match the original. Main check: 257/257 bytes, 91/91 instructions, correct owner and eight calls. The `act_gath` audit has no exact-neighbor regressions; owner audit: zero mismatches. Promoted to `matching`. Runtime and linked-image checks remain open. Note: `decomp_notes/functions/0040/00403D90.md`.
