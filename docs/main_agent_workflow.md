# Main-agent workflow

Read this file only when coordinating project work. `AGENTS.md` owns universal
rules. `docs\agentic_matching_workflow.md` owns worker procedure. This file owns
scheduling, integration, and semantic review.

## Authority

The user-designated main agent owns:

- queue and lease coordination;
- participant assignment;
- returned-work review;
- status moves and commits;
- reviewed shared ABI evidence;
- semantic-review ledgers and promotion decisions.

Subagent output is a proposal. The main agent must inspect and validate it before
integration.

Honor the user's exact model, thinking, concurrency, and launch limits. Do not
infer a missing execution contract.

## Participant roles

Assign each participant exactly one role.

### Matching worker

Assign one VA, one lease owner, a compact evidence card, and one useful lead.
The worker follows `docs\agentic_matching_workflow.md` and works on only that
target. Authorize any shared-file change separately.

### Phase-readiness auditor

Use this read-only role to decide whether exact matching still has credible
leads. Assign at most two named functions. The auditor may read bounded matching
history, but does not decide semantic promotion.

### Blind semantic reviewer

Assign exactly one candidate in fresh, read-only context. The reviewer must not:

- edit files or claim a lease;
- read `logic_reviews`;
- read Git history or prior reports;
- read the candidate's matching attempt-log header;
- receive a claim that a difference is harmless.

Treat source comments as hypotheses, not executable evidence.

## Scheduling

- Never assign two editors to one function.
- Count queued work against the user's concurrency ceiling.
- Keep the live set small enough for prompt review.
- Integrate completed edits before filling every free slot.
- Review live work history before reassigning paused work.
- Give a later worker a new evidence-backed lead.
- Do not repeatedly poll participants.
- Keep each assignment bounded. Avoid complete packet and history dumps.

A practical four-slot split is at most two workers and two read-only analysts.
Reserve two read-only slots when a blind-review cohort is due.

## Obstacle notes

`BLOCKER` is a manual obstacle note in a living source header. It is not a lease,
status bank, corpus class, or automatic scheduling ban.

A worker can add it during an unresolved finish. The main agent reviews it during
integration. Use it for a specific obstacle that makes immediate reassignment
low-value. Record the evidence or condition that can change the assessment.

Status filters can include or exclude these notes. Nothing enforces them. Remove
or update a stale note when new evidence resolves it. Corpus manifests own
permanent non-normal classification.

Status tooling also reports a verified-logic source without its required ledger
as blocked. That is a repository-integrity check, not a source-header decision.

## Matching queue

Keep exact matching active while credible leads remain. Judge a stall from
cumulative evidence, not probe count alone. Consider:

- behavior, ABI, layout, structure, context, liveness, flags, and variant coverage;
- convergence across independent workers;
- metric and structural progress;
- repeated emitted-code basins;
- ordered calls, memory effects, cleanup, and block topology;
- unresolved source, type, or ownership facts.

Do not start another broad source-shape pass without new evidence.

## Review returned matching work

For every return:

1. inspect the complete diff and final source;
2. confirm that only assigned files changed;
3. preserve unrelated shared-worktree edits;
4. inspect source plausibility and canonical ownership;
5. inspect clean-source and metric-best checkpoints separately;
6. rerun the authoritative function checker;
7. accept, revise, or reject the proposal;
8. perform any status move;
9. stage only reviewed paths.

Do not trust folder placement or a reported match. Exact promotion requires a
fresh local `MATCH` after the move.

Use `accepted_drift` only for a localized, proved behavior-equivalent codegen
difference. Never use it for changed calls, predicates, cleanup, memory effects,
ABI, or broad unexplained drift.

## Shared ABI evidence

The main agent owns `config\shared_abi_evidence.json`. Add an entry only after
verifying:

- canonical declaration and type;
- symbol or storage identity;
- shared header and definition;
- measured effect on at least one target;
- evidence strong enough for reuse.

Update the shared declaration and evidence entry in one reviewed change. Matching
workers may consume this evidence but must not edit the registry.

## Enter semantic review

Only the main agent may suspend exact matching. Enter semantic review only after
substantial matching work leaves no reasonable exact lead and the candidate's
behavior is reviewable.

Before review:

1. remove codegen-only residue;
2. restore canonical types, fields, calls, and natural control flow;
3. retain an unusual form only when executable behavior requires it;
4. validate the normalized source;
5. create `logic_reviews\<slug>.md`;
6. keep the source in `src\scratch`;
7. preserve its complete matching attempt log.

The ledger must record:

- transition reason and current checker metrics;
- cumulative matching evidence and unresolved questions;
- every reviewer report and assigned scope;
- main-agent adjudication of each finding;
- integrated fixes and validation;
- later review rounds;
- final decision and remaining nonsemantic differences.

Use the live status tool's logic-review view to find active reviews.

## Blind review cohorts

Launch at least two fresh reviewers concurrently. Do not launch a partial cohort.
Use complementary scopes and include one broad adversarial review.

Ask each reviewer to compare the candidate directly with the executable. Require
findings about paths, predicates, bounds, calls, arguments, and memory effects.
Also require findings about offsets, returns, errors, ownership, cleanup,
exceptions, and fault order.

The complete cohort is an action barrier. Collect reports as they finish, but do
not adjudicate or edit the candidate until every cohort member completes. Continue
unrelated work while waiting. Reviewer count is not a vote; one proved behavior
difference blocks promotion.

## Adjudication

After the full cohort completes:

1. append every report to the ledger;
2. deduplicate findings;
3. classify each finding as confirmed, unresolved, or cleared;
4. record direct binary evidence for the decision;
5. apply only bounded, well-established fixes;
6. rerun the checker;
7. version source and ledger changes together.

Use plausible ordinary source for fixes. If a finding needs broad reconstruction,
return the function to matching work. After meaningful fixes, launch a fresh
blind cohort without prior conclusions.

Clear a difference only after bounded review proves that no shipped code can
observe it. It must change no call, cleanup, handler, state, result, memory,
exception, or fault result. Record that proof. This rule can clear dead compiler
bookkeeping, but never real ABI, cleanup, lifetime, or fault-order differences.

## Promote verified logic

Promote only after repeated fresh cohorts converge and no substantive uncertainty
remains.

Before promotion:

1. read the complete source and ledger;
2. confirm every reachable behavior and important effect;
3. confirm all unusual source has binary justification;
4. run final validation;
5. complete the ledger decision;
6. move the source to `src\verified_logic`;
7. version the source, ledger, and status change together.

`verified_logic` remains nonexact. Preserve its ledger and attempt log if later
exact work resumes.

## State flow

```text
queue -> matching worker -> main-agent validation
  exact                      -> matching
  narrow reviewed drift      -> accepted_drift
  uncertain or promising     -> scratch / later worker
  stalled and behavior-ready -> blind cohorts -> adjudication
     broad defect            -> scratch / matching
     no substantive finding  -> verified_logic
```
