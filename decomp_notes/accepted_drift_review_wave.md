# Accepted-drift review wave

## Assignment

The user requested a new review of all accepted-drift functions and renewed exact-matching attempts.
The approved worker model is `openai-codex/gpt-6-luna`, with `xhigh` thinking.
The active limit is 40 matching workers. Each worker uses one compiler job.

The integration baseline is `23f6673f7e701837099507a9888d0197784c1db4`.
That registry contains 228 accepted-drift functions across 89 natural source modules.
The first wave selects the 40 modules with the most accepted-drift targets.
Each module has one worker in its own detached worktree.
The remaining modules stay queued until capacity becomes available.

## Reason for reopening

The old accepted-drift approval for `004D7CB0` concealed a wrong world-field read.
Commit `6e1c3f02c` repaired that defect. The function now matches exactly.
This does not prove that other accepted-drift approvals are wrong.
It does justify checking their original behavioral evidence again.

## Review requirements

Review behavior before byte tuning. Check the complete function against the original executable.
Previous source and approval notes are hypotheses, not substitutes for instruction evidence.
Check field offsets, widths, call arguments, writes, loops, cleanup, aliases, and fault order.
Preserve original bugs. Repair decompilation bugs even when byte similarity gets worse.

Workers may experiment with shared source only inside their isolated worktrees.
They must preserve baseline and tested inputs through `docs/experiments.md`.
They must audit changed modules and the full closure of shared changes.
Workers cannot change registry statuses or commit proposals.

Integration requires source review, fresh exact checks, and affected-owner validation.
Do not renew a behavior approval while material checks remain unresolved.
Keep exactness, behavior findings, and integration decisions separate.

## Session records

The initial assignment manifest is `build/accepted-drift-wave/assignments.json`.
The first launch request is `build/accepted-drift-wave/batch-01.json`.
These are scheduling records, not durable technical evidence.
Workers must record technical findings and preserved experiments in `decomp_notes/`.

The user also requested a commit of the pending formatting edit in `src/tribegam.cpp`.
That edit joins two lines without changing tokens. It is outside the workers' initial baseline.
