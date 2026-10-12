# Exact lottery

## Purpose

Exact lottery is an opt-in follow-up experiment for one reviewed function.
It asks several independent workers for natural source reconstructions.
It stops when one variant compiles to the original function bytes.

If the blind variants do not match, the orchestrator runs a bounded refinement
phase on the best candidates. This workflow does not replace behavior recovery.
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
- compiler jobs per worker and checker;
- maximum refinement seeds; and
- maximum refinement build-and-check iterations.

The successful pilot used one Luna `xhigh` orchestrator and ten Luna `xhigh`
workers. This is evidence, not an automatic default.

Read these role files:

- `workflow/agent_roles/exact_lottery_orchestrator.md`
- `workflow/agent_roles/exact_lottery_worker.md`

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
python workflow/tools/behavior_recovery.py workspace --help
python workflow/tools/behavior_recovery.py workspace \
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
variant. A sparse blind wave can omit the checker by design. Keep that variant
immutable. Clone its committed state into a separate sibling check workspace.
Copy the complete root-supplied `tools/` directory into only the check
workspace, then run the checker there. Do not expose checker files or output to
the blind worker.

The first valid `MATCH 0.0000%` wins.
The orchestrator then stops all remaining workers immediately.
It preserves every workspace and reports only the exact hit.

Do not continue the lottery to count more matches.
The experiment seeks one viable exact source, not a distribution.

## Post-lottery refinement

If all valid blind variants mismatch, do not stop immediately. The orchestrator
must make a bounded matching effort on the most promising variants.

The orchestrator can now inspect all variant source and checker reports. It can
use byte differences to find code-generation hypotheses. A byte score cannot
override behavior, source, ownership, or ABI evidence.

Select up to the supplied refinement-seed limit. Prefer candidates that meet
all these conditions:

- the source is natural and period-plausible;
- the behavior model is complete;
- calls, widths, side effects, faults, and fault order have strong support; and
- the remaining byte differences are small or localized enough to investigate.

Do not edit an original variant workspace. Clone each selected commit into a
new sibling directory named `refinement-NN`. Record the seed variant and commit.

The orchestrator can edit source in each refinement workspace. It can use the
authoritative checker output after each build. Test supported source-shape,
type, lifetime, expression, and control-flow hypotheses. Do not use inline
assembly, byte copies, fake volatility, wrappers, manual vtables, or unsupported
compiler steering.

Stop refinement when one condition applies:

- a valid exact match exists;
- the supplied iteration limit is reached;
- no evidence-backed hypothesis remains; or
- a concrete blocker prevents more work.

An exact refinement hit follows the normal first-hit stop rule.

The orchestrator can also report an `accepted_drift` proposal. Closeness alone
does not support this proposal. The candidate must have canonical natural source
and a written semantic proof for all behavior. The proof must cover ABI, calls,
cleanup, widths, aliasing, side effects, exceptions, faults, and fault order. It
must also explain why each remaining code difference does not change behavior.

Keep an accepted-drift proposal in a clean committed refinement workspace. Save
its proof and validation commands in that workspace. The root must send the
proposal to an independent technical reviewer before integration or promotion.

If refinement finds no exact hit or accepted-drift proposal, retain the approved
`new_verified_logic` implementation. Do not integrate the closest score.

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
