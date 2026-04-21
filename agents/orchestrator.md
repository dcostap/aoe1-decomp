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
8. Inline asm is forbidden. If a function only seems matchable with asm, keep it in `scratch` with a clear attempt-log summary.
9. `src\matching\...` is exact-only. `src\scratch\...` holds all non-exact work, whether active or temporarily paused.
10. Keep blocked work documented in the source with the attempt-log comments expected by `AGENTS.md`.
11. If a tiny helper or other sticky function keeps collapsing into a small number of stable codegen families, stop assigning endless random spelling probes. Treat it as a codegen-family case, summarize the discovered families, and escalate to focused harness/context/toolchain work.
12. When assigning or reviewing sticky functions, treat likely original-file include context as a normal part of the source model. Ask agents to cycle plausible donor-file includes alongside body-shape probes instead of assuming “unused” headers are irrelevant.
13. Do **not** strip “unused” includes or small donor-style context from an incoming exact-match file without revalidating it. For VC5, translation-unit context can be part of the winning source model.
14. If a context change unlocks a match, ask for or perform a reduction pass so the tree keeps the smallest proven reproducer instead of cargo-cult full donor context.
15. Prefer reusing active agents over spawning new ones, and when explicitly told to hold, do **not** queue new agents or new tasks; let the existing live work finish first.
