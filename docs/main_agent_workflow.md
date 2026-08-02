# Main-agent project workflow

This document is for the user-designated main coordinating agent. `AGENTS.md`
contains the common rules injected into every Pi instance; this file defines the
additional top-level scheduling, integration, and semantic-review duties of the
main agent.

## Authority and responsibilities

The main agent maintains the project queue, assigns work, tracks active leases,
validates every returned edit, controls status moves, coordinates semantic
reviews, updates logic-review ledgers, and makes final promotion decisions.
Subagent output is always a proposal until the main agent reads the complete diff
and source, checks policy compliance and unrelated changes, reruns the relevant
validation, and confirms the reported result.

The main agent may run many matching workers concurrently on different targets.
Only one worker may edit a given function at a time.

Use `python tools/query_project_status.py --logic-review-in-progress --paths`
to inspect candidates currently in semantic review, and `--verified-logic` for
completed semantic reconstructions.

## Matching assignments

Assign one function to one matching worker. Require the worker to follow the
normal target-session contract in `AGENTS.md`, including a default budget of ten
meaningful hypotheses, a compact source attempt log, final validation, and a
pause or exact promotion result.

Ten hypotheses bound one worker assignment. They do not prove that the function
is exhausted. The main agent may assign fresh workers to the same function many
times. Before doing so, ensure the next worker reads the existing source attempt
log and target history and has a plausible way to add new evidence rather than
repeat an explored compiler basin.

Judge an exact-match stall from cumulative evidence, including:

- diversity and quality of attempted behavior, ABI, layout, structure, context,
  liveness, flags, and variant hypotheses;
- independent workers and whether they repeatedly converge on the same blocker;
- metric and structural progress across assignments;
- duplicate emitted-code basins and exhausted focused labs;
- remaining credible leads in the attempt log;
- whether calls, memory effects, block topology, and unresolved ABI facts are
  actually understood.

Do not infer a stall from raw attempt count alone. Keep assigning exact-matching
work while credible unexplored leads remain and the expected value is reasonable.

## Verify returned matching work

For every worker result:

1. inspect the complete diff and resulting source;
2. ensure only authorized files changed and preserve unrelated work;
3. reject forbidden asm, fake exactness, relocation mistakes, and policy drift;
4. rerun `check_function.py --va <VA>` and confirm the claimed outcome;
5. verify that the attempt log accurately records tried, kept, rolled-back, and
   remaining hypotheses;
6. accept, revise, or reject the result;
7. perform status moves and version-control integration only after verification.

Exact functions go to `src\matching`. Rare near-exact functions may go to
`src\accepted_drift` only under its existing narrow policy. Materially uncertain
functions remain in `src\scratch`.

## Enter logic matching

Only the main agent may decide to suspend exact matching and enter formal logic
review. This requires substantial cumulative matching work and a candidate whose
behavior appears reconstructable even though exact VC5 codegen remains stuck.

Create `logic_reviews\<slug>.md` from the format documented in
`logic_reviews\README.md`. Record the phase-transition rationale, current exact
and structural metrics, cumulative matching evidence, known assembly differences,
and every semantic uncertainty present at entry. Keep the source's matching
attempt log intact.

The candidate normally remains in `src\scratch` during review. Folder placement
changes only after final adjudication.

## Launch a blind review cohort

Launch several fresh reviewers concurrently. Give them the candidate source and
original evidence, but not the ledger, Git history, previous reports, or a claim
that any difference is harmless. Reviewers must be explicitly read-only and must
not claim the target.

Every review prompt must state that the goal is the original executable's actual
behavior, including bugs, odd signedness, incorrect-looking formulas, unintended
side effects, and error behavior—not the likely intention of the programmer.
Require concrete binary evidence for substantive findings.

Use complementary scopes such as control flow and bounds; calls, ABI, layout, and
memory effects; cleanup, ownership, and exceptional paths; and full adversarial
semantic review. Include at least one broad reviewer that is not primed with a
suspected issue.

A suitable neutral core prompt is:

> Perform an independent, read-only semantic verification of `<VA>`. Do not edit
> files, claim the target, inspect `logic_reviews`, inspect Git history, or seek
> previous review conclusions. Compare the reconstructed function directly with
> the original executable, which is the behavioral oracle. Reproduce its actual
> logic, including bugs and unintended edge cases. Report definite behavioral
> differences, plausible differences needing evidence, assumptions you verified,
> areas you could not establish, and your overall conclusion. Check reachable
> paths, predicates, loop bounds, calls and arguments, memory reads/writes and
> widths, object offsets, return values, error paths, ownership, and cleanup.

## Adjudicate and integrate a review round

Wait for the full concurrent cohort before editing. Append the complete reports
to the per-function ledger, deduplicate findings, and adjudicate each one against
the binary as confirmed, unresolved, or cleared. Reviewer count is not a vote;
one evidence-backed behavioral objection blocks promotion.

The main agent directly applies bounded, well-established review fixes to the
function and updates the ledger in the same integration pass. Rerun the checker
and inspect the complete diff. Do not delegate isolated review fixes merely to
have another agent edit them.

After the round is adjudicated and validated, version the ledger and any source
changes together. If the main agent stops with unresolved findings, version that
ledger state as the durable handoff rather than leaving the only record in an
agent transcript.

If a finding requires broad reconstruction rather than bounded integration,
record that result, stop the review phase, return the function to scratch matching
work, and assign one matching worker. Restart formal review later with fresh
reviewers.

After meaningful source changes, launch another fresh blind cohort. Do not give
new reviewers previous reports or adjudications. Repeated rediscovery is useful
evidence; the main agent uses the ledger to determine whether it is a real issue,
a failed fix, or a previously cleared function-specific false flag.

## Promote verified logic

Promotion requires extreme thoroughness rather than a fixed reviewer count.
Require repeated independent review rounds to converge, all reachable behavior
and important memory/call effects to be accounted for, and no substantive open
finding. Every supposedly irrelevant finding needs an evidence-backed resolution
in the ledger.

When satisfied, the main agent:

1. reads the complete source and ledger;
2. performs final policy and behavioral adjudication;
3. reruns final validation;
4. completes the ledger's final-decision section;
5. moves the source to `src\verified_logic`;
6. versions the source, ledger, and status change together.

`verified_logic` is non-exact and remains eligible for future exact-matching work.
Moving it back into matching work must preserve its ledger and attempt history.

## State flow

```text
project queue
    -> one matching worker per function
    -> main-agent validation
       -> exact: matching
       -> narrow reviewed codegen drift: accepted_drift
       -> uncertain or still promising: scratch / another worker
       -> cumulatively stalled but behavior-complete candidate: logic review
          -> concurrent read-only reviewers
          -> main-agent adjudication and bounded fixes
          -> broad defect: scratch / matching worker
          -> converged with no substantive open finding: verified_logic
```
