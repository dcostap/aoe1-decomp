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
  - Slot 1: `00403D90`, `src/act_gath.cpp`, `../aoe1-match-slot-1`, agent `sa-42e3ab20`.
  - Slot 2: `00412240`, `src/airesitm.cpp`, `../aoe1-match-slot-2`, agent `sa-12c5e51f`.
  - Slot 3: `00401170`, `src/act_atak.cpp`, `../aoe1-match-slot-3`, agent `sa-c49b51f9`.
  - Slot 4: `00406E00`, `src/act_tran.cpp`, `../aoe1-match-slot-4`, agent `sa-01c56171`.
  - Slot 5: `00405850`, `src/act_move.cpp`, `../aoe1-match-slot-5`, agent `sa-84d8b8a3`: no source change; evidence saved.
- Integrated: `00403CE0` exact match.
- Open: 230 unassigned entries; four assignments in progress. `00404590` and `00405850` stay accepted drift.

## Work log

Record each assignment here with its target VA, worker, worktree, result, validation, integration decision, and next step.

- `00403CE0`: Reordered two reads and the fallback x/y/z stores in `src/act_gath.cpp`. Main check: 174/174 bytes, 64/64 instructions, correct owner and five aligned calls. Main `act_gath` audit: no exact-neighbor regressions. Owner audit: zero mismatches. Promoted to `matching`; no runtime or linked-image check yet. Preserved worker experiment states, events, objects, and candidate patch.
- `00404590`: No supported source change. Four preserved experiment states. The best result remains two register-selection bytes in a virtual call; the original behavior and call target agree. Worker `act_list` audit: 24 exact claims passed; owner audit: zero mismatches. Keep `accepted_drift`. No runtime or linked-image check ran. Note: `decomp_notes/functions/0040/00404590.md`.
- `00405850`: No supported source change. Two bytes differ in one vptr register load. The `PathResult` probes failed compilation or produced the same output. Worker `act_move` audit: eight exact neighbors passed. Keep `accepted_drift`; no runtime or linked-image check ran. Note: `decomp_notes/functions/0040/00405850.md`.
