# Logic review: 005034B0 `checkStaleAttackGroups`

Current source: `src/taitacmd.cpp`. This ledger contains historical review evidence.

## Phase transition

The main agent suspended exact matching after repeated bounded attempts found
no natural source lead for the remaining local-home and register drift.

Candidate: `src/taitacmd.cpp`.

Current validation:

- original size: 194 bytes; rebuilt size: 184 bytes;
- all six calls align in exact order;
- saved registers and CFG signals align;
- the remaining drift is the original delayed `numberUnits` stack home and
  related time-chain register allocation.

The candidate uses named tactical-group, player, world, and time ownership.

## Semantic questions

1. Verify the attack-enabled guard and sentinel/null traversal.
2. Verify the type and in-use filters.
3. Verify both `numberUnits` calls and setter order.
4. Verify signed elapsed-time division, including negative elapsed values.

## Review rounds

### Round 1 — concurrent blind cohort, 2026-08-13

- `sa-3d1b13a3` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-23a45556` — `openai-codex-secondary/gpt-5.6-luna`, xhigh

Both reviewers found no definite behavioral difference.

They verified:

- the disabled attack path performs no traversal;
- traversal starts at `groups.next` and stops at the sentinel or null;
- type and in-use filters match the executable;
- the candidate calls `numberUnits`, `desiredNumberUnits`, then `numberUnits`
  again immediately before `setDesiredNumberUnits`;
- elapsed time uses 32-bit subtraction followed by signed, truncating division
  by 60000;
- the required cast before division preserves negative elapsed-time behavior.

The reviewers found no changed call order, writes, bounds, or null behavior.

## Final decision

No behavioral uncertainty remains in the reviewed paths. The residual drift is
VC5 local-home and register allocation. Promote to `verified_logic` status.
