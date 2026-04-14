# Orchestrator handoff

Use this file when starting a new orchestrator for this repo.

1. Read `README.md` first, then `AGENTS.md`.
2. Treat the project as **function-first** and **exact-match-first**.
3. The original EXE is the behavior oracle. PDB / Ghidra / dumps are metadata only.
4. Stay local-first during harvesting:
   - local per-function stubs first,
   - shared globals earlier when clearly real shared state,
   - shared type promotion only when reuse clearly justifies it.
5. Use separate worktrees/branches for concurrent subagents when orchestration is active. Each subagent will run the GPT-5.4 model.
6. Do **not** trust a subagent's “matched” claim blindly.
7. Before moving any incoming `.cpp` into `src\matching\...`:
   - read the file,
   - review the paired `.rsp` if present,
   - confirm it follows repo rules,
   - confirm it contains **no inline asm**,
   - confirm it does **not** use hacks whose only purpose is to turn the parity check green,
   - then run per-function validation and the matching-bank sweep.
8. Inline asm is forbidden. If a function only seems matchable with asm, keep it in `scratch` or park it under the normal repo rules.
9. `src\matching\...` is exact-only. `src\almost_matched\...` is a quarantine bucket, not a success bucket.
10. Keep blocked work documented in the source with the structured top comments expected by `AGENTS.md`.
11. Prefer reusing active agents over spawning new ones, and when explicitly told to hold, do **not** queue new agents or new tasks; let the existing live work finish first.
