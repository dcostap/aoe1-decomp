# Exact lottery

## Purpose

Exact lottery is an opt-in follow-up experiment for one reviewed function.
It asks several independent workers for natural source reconstructions.
It stops when one variant compiles to the original function bytes.

This workflow does not replace behavior recovery.
Do not run it automatically for every mismatch.

## Eligibility

Use exact lottery only when all these conditions apply:

- normal behavior recovery has a final technical approval;
- the integrated function has `new_verified_logic` status;
- the authoritative function check reports a mismatch;
- a blank immutable reconstruction wave exists; and
- the user explicitly authorizes the experiment and its resources.

Prefer small functions with several plausible natural source forms.
Large functions have higher cost and lower first-hit value.

## Launch contract

Obtain these settings before launch:

- target VA and name;
- exact orchestrator model and thinking level;
- exact worker model and thinking level;
- requested variant count;
- maximum active agents; and
- compiler jobs per worker and checker.

The successful pilot used one Luna `xhigh` orchestrator and ten Luna `xhigh`
workers. This is evidence, not an automatic default.

Read these role files:

- `agent_roles/exact_lottery_orchestrator.md`
- `agent_roles/exact_lottery_worker.md`

## Workspace setup

Use the blank wave from the function's original behavior-recovery run.
Create fresh repositories outside the main repository tree.

Use a unique run directory:

```text
C:/Projects/my_decomps/exact-lottery/<VA>/<run-id>/variant-01
C:/Projects/my_decomps/exact-lottery/<VA>/<run-id>/variant-02
...
```

Run the tool help first. Then create each workspace:

```text
python tools/behavior_recovery.py workspace --help
python tools/behavior_recovery.py workspace \
  --wave logic_matching/<VA>/<blank-wave> \
  --destination C:/Projects/my_decomps/exact-lottery/<VA>/<run-id>/variant-NN
```

Never reuse or overwrite a workspace.
Confirm that each workspace has the expected blank target and pinned baseline.

## Independent reconstruction

Launch one fresh worker in each workspace.
Workers use the same model and thinking level unless the user requests another
experiment design.

Each worker receives the same evidence and core task.
Workers cannot see:

- another variant;
- the current approved implementation;
- old implementations or attempts;
- checker results; or
- byte-difference feedback.

Workers recover natural source from static evidence.
Behavior must match all behavior encoded by the original assembly.
This includes bugs, unusual behavior, faults, overflow, aliasing, and effect
order.

Each worker builds, commits its source, leaves a clean repository, and stops.
Workers do not decide exactness.

## Mechanical selection

The orchestrator runs the authoritative function checker after each completed
variant.

The first valid `MATCH 0.0000%` wins.
The orchestrator then stops all remaining workers immediately.
It preserves every workspace and reports only the exact hit.

Do not continue the lottery to count more matches.
The experiment seeks one viable exact source, not a distribution.

If all valid variants mismatch, retain the approved `new_verified_logic`
implementation. Do not select the closest byte score.

## Review and promotion

An exact byte result still needs a source-policy check.
The root performs this check directly. Do not launch a separate reviewer for an
exact-lottery hit unless the user requests one.

The lottery orchestrator never integrates a hit.
The root performs these separate steps:

1. Preserve the exact workspace and commit identity.
2. Import the candidate into a unique durable attempt archive.
3. Reproduce the exact result from the current integration base.
4. Check behavior, source policy, ownership, ABI, boundaries, and calls.
5. Integrate only the unchanged exact candidate.
6. Run the authoritative function check again.
7. Run the affected translation-unit closure audit.
8. Set `matching` only while exactness and the root check remain valid.

If the root changes compiler-facing source, recheck exactness before promotion.
Route a nonexact revision through normal behavior recovery.

## Pilot result

The first experiment targeted `0046AAE0 Path::operator==` with ten requested
Luna `xhigh` variants.

Variant 06 produced an authoritative exact match before all workers finished.
This result established the first-hit stop rule.
