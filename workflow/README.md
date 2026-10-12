# How this was made

The decompilation was done mostly by AI coding agents, run through the
[Pi](https://github.com/badlogic/pi-mono) coding agent, between April and October 2026
(about 9,000 commits). This folder holds what they worked from: the rules, the role
prompts, the guides, and every note and review they left behind.

Nothing here is needed to build the game.

## The pipeline

1. **Reference data.** The beta's PDB and a Ghidra export of the original
   executable produce a local function inventory (`inventory/`, not in the repo).
   `config/functions/` is the registry: each source file, its compiler flags, and
   the status and symbol of each function.

2. **Matching.** A root orchestrator assigns translation units to orchestrators,
   and each orchestrator runs matching workers in their own git worktrees. A worker
   writes natural source for its functions until `tools/check_function.py` reports
   a byte match against the original. Every attempt is recorded as a durable
   experiment, so failed ideas are kept, not lost.
   - [agent_roles/root_orchestrator.md](agent_roles/root_orchestrator.md),
     [orchestrator.md](agent_roles/orchestrator.md),
     [matching_worker.md](agent_roles/matching_worker.md)
   - [docs/experiments.md](docs/experiments.md)

3. **Review.** The later rounds replaced self-review with a separate reviewer agent
   that checks the stopped worker's evidence before anything is merged.
   - [docs/matching_with_reviewers.md](docs/matching_with_reviewers.md),
     [agent_roles/matching_reviewer.md](agent_roles/matching_reviewer.md)

4. **Accepted drift.** Some functions have natural source whose bytes still differ
   slightly from the original. A complete semantic review that proves equal
   behavior accepts them as `accepted_drift`. [MATCHING_ROUND.md](MATCHING_ROUND.md) is the
   plan from one of these rounds.

5. **Behavior recovery.** For the hardest functions, workers aim for correct
   behavior instead of exact bytes. Two fresh reviewers must both return `PERFECT`
   for identical source before a function becomes `accepted_logic`.
   - [agent_roles/behavior_recovery_orchestrator.md](agent_roles/behavior_recovery_orchestrator.md),
     [behavior_recovery_worker.md](agent_roles/behavior_recovery_worker.md)
   - [tools/behavior_recovery.py](tools/behavior_recovery.py) prepares the workspaces and routes reviews.

6. **Exact lottery.** An opt-in experiment: many blind workers write one function
   independently, and the run stops when any variant matches exactly.
   - [docs/exact_lottery.md](docs/exact_lottery.md)

7. **Source cleanup.** Waves of agents renamed constants, joined wrapped lines, and
   wrote comments, without changing the generated machine code or data.
   - [docs/source_cleanup.md](docs/source_cleanup.md),
     [docs/source_comments.md](docs/source_comments.md),
     [docs/resource_ids.md](docs/resource_ids.md)

8. **Whole-game checks.** The full executable is built, linked, and audited. The
   game then runs side by side with the original under scripted and recorded human
   input. The harness compares clocks, game state, complete RNG streams, and raw
   frames.
   - [docs/executable_build.md](docs/executable_build.md),
     [docs/runtime_harness.md](docs/runtime_harness.md),
     [docs/behavior_replay.md](docs/behavior_replay.md),
     [docs/testing.md](docs/testing.md)

## What's in here

| Path | What it is |
| --- | --- |
| [`../AGENTS.md`](../AGENTS.md) | The rules every agent gets (kept at the root, where agents look for it) |
| [`agent_roles/`](agent_roles) | Role prompts for orchestrators, workers, and reviewers |
| [`docs/`](docs) | Workflow guides and tool references |
| [`vc5_lessons.md`](vc5_lessons.md) | What we learned about coaxing VC5 into matching code. The most useful file here if you do your own decomp. |
| [`decomp_notes/`](decomp_notes) | Per-function and per-module notes, ID tables, and audits |
| [`decomp_notes/candidates/`](decomp_notes/candidates) | Saved candidate patches from matching attempts |
| [`logic_reviews/`](logic_reviews) | Semantic review ledgers from the earlier workflow |
| [`recovery_notes/`](recovery_notes) | Repository-wide audits |
| [`tools/`](tools) | Scripts used only by the agent workflows |
| [`pi/`](pi) | A Pi extension that shows live function counts while agents work. Copy it to `.pi/` to use it. |

The core tools that build and compare functions are in the root [`tools/`](../tools).

These files are kept as they were written. Older ones use earlier status names:
`new_verified_logic` is now `accepted_logic`, and `scratch` is now `nonmatching`.
