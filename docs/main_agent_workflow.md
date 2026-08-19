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

Assign one VA, one lease owner, and a compact evidence card. Include known prior
work, open questions, and useful observations. The worker chooses its methods.
The worker follows `docs\agentic_matching_workflow.md` and works on only that
target. Authorize any shared-file change separately.

Every assignment must request honest, sustained matching work. Include these
requirements in the worker prompt:

- Do not stop after a few failed probes.
- Try at least ten meaningful, evidence-led hypotheses before an unresolved
  pause.
- Test distinct source, type, layout, control-flow, lifetime, or compiler-context
  ideas. Do not inflate the count with cosmetic edits or repeated checks.
- Use exact donors, nearby functions, assembly evidence, and a structured
  variant lab when they apply.
- Ten attempts are a minimum, not a stop target. Continue while useful leads
  remain.
- Stop before ten only for an exact match, a real external constraint, or a
  direct user instruction.
- Report each attempt, its result, and the evidence learned from it.
- Treat the first exact result as the start of the exact-finish retrospective.
- Compare it with the last clean nonexact source. Walk back independent changes,
  test interacting groups, and remove incidental context or source machinery.
- Retain the smallest natural source that remains exact. Record which changes
  were required, incidental, or inseparable.
- Report reusable lesson candidates. Do not edit `LESSONS.md` unless the
  assignment authorizes that shared-file change.

Do not weaken this requirement with prompt text such as "otherwise pin and
pause" without the effort conditions above.

### Phase-readiness auditor

Use this read-only role to assess cumulative exact-matching coverage. Assign at
most two named functions. The auditor may read bounded matching history, but does
not declare a function impossible or decide semantic promotion.

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
- Read the source comment log before reassigning scratch work. It is the
  authoritative durable history.
- Treat generated session history as optional local detail. Cleanup can remove it.
- Give workers prior evidence and open questions. Let them choose their methods.
- Do not repeatedly poll participants.
- Keep each assignment bounded. Avoid complete packet and history dumps.

Wait for the next completion across all active participant groups. Use
`subagent_wait` with `wait_mode: "any"` and the active agent IDs. Route each
result by role. Review worker results while matching workers, auditors, and blind
reviewers continue. Wait again only after useful integration work finishes.

A blind-review cohort has a logical adjudication barrier, not a global wait
barrier. Collect its reports as they finish, but adjudicate that candidate only
after every cohort member returns. Continue to process unrelated completions.
Use `wait_mode: "all"` only when the selected agents are the only remaining work
and no unrelated result can require integration. A cancelled wait leaves agents
running; do not launch replacements.

When no blind cohort is due, keep the normal live set small. A blind cohort uses
four read-only slots. Reserve all four slots before launch.

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

A worker pause ends one assignment. It does not declare global exhaustion. Rotate
workers when a fresh independent approach can help. Use cumulative evidence for
scheduling, not as proof that exact matching is impossible. Consider:

- behavior, ABI, layout, structure, context, liveness, flags, and variant coverage;
- convergence across independent workers;
- metric and structural progress;
- repeated emitted-code basins;
- ordered calls, memory effects, cleanup, and block topology;
- unresolved source, type, or ownership facts.

Workers can try new source forms, tools, compiler context, structured sweeps, and
speculative investigative methods. Repeating an old experiment is valid when new
context or a controlled comparison gives it a different purpose.

## Assess cumulative matching evidence

Use informed judgment to decide when more exact work has low value. Do not use
one metric or a fixed threshold.

Review all available evidence:

- the durable attempt log in the source header;
- the number and quality of distinct hypotheses;
- results from independent matching assignments;
- current byte parity and exact-block coverage;
- ordered calls, CFG, frame, ABI, cleanup, and memory effects;
- generated claim, probe, checkpoint, and last-gain history, when available;
- existing review ledgers and relevant Git history;
- known behavior questions and useful approaches that remain untested.

Treat source comments as the durable record. Generated work history can support
the decision, but cleanup can remove it.

Count evidence-led hypotheses, not cosmetic edits or repeated checks. A high
probe count alone does not show exhaustion.

Interpret byte parity with structural evidence. Large block movement can cause
a poor positional score while logic remains close. A high score can also hide a
wrong call, predicate, or memory effect.

Ask these questions:

1. Did recent assignments improve behavior or important structure?
2. Does a strong unused matching approach remain?
3. Are remaining differences semantic, structural, or compiler-driven?
4. Is the complete reachable behavior ready for direct review?
5. Can new executable evidence change the current conclusion?

Continue exact work when useful evidence-led approaches remain. Enter semantic
review when progress has leveled off and the behavior is reviewable.

Use `accepted_drift` only for a small, localized, proved equivalent difference.
Broad drift belongs in semantic review, even when aggregate parity is high.

Record the decision, reviewed evidence, remaining differences, and reopening
condition in the source or assigned ledger.

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

Before each project commit, refresh `project_status_metrics.csv`. Stage it with
the source changes. This compact file gives each commit durable diff metrics.

For an exact return, require the worker's exact-finish retrospective. Inspect the
first exact checkpoint, the last clean nonexact checkpoint, and all reported
walkback tests. Do not treat `MATCH` as the end of source recovery. If the worker
did not reduce the exact transition, continue the same assignment or perform the
bounded walkback before promotion.

Confirm that the retained source is the smallest supported natural form, not
only the smallest byte-producing form. Recheck each unusual declaration, flag,
scope, alias, control form, allocation choice, and ambient-context change. Record
required, incidental, and inseparable changes in the source notes. Promote only
after the reduced source still reports `MATCH` and `0.0000%`.

Require an `ORIGINAL BUG:` note for each proved shipped defect. The note must
name the binary evidence, observable effect, and reason not to correct it. Do
not label uncertain or merely unusual source as a bug.

Before exact promotion, review comments as part of source recovery. Keep a few
useful comments at key blocks. Prefer comments that explain intent, ownership,
required ordering, or strange shipped behavior. Use `BINARY NOTE:`,
`ORIGINAL BUG:`, and `LIKELY INTENT:` to separate evidence from interpretation.
Remove stale probe explanations and comments that only repeat the code. Do not
state a suspected copy mistake or developer motive as fact.

Reject a shallow unresolved return. If the worker reports fewer than ten honest
hypotheses, continue that same assignment. Do not count syntax repairs, unchanged
reruns, cosmetic edits, or unsupported register guesses as honest hypotheses.
Also reject a ten-item list that leaves useful evidence-led approaches untested.

Do not trust folder placement or a reported match. Exact promotion requires a
fresh local `MATCH` after the move.

Use `accepted_drift` only for a localized, proved behavior-equivalent codegen
difference. Never use it for changed calls, predicates, cleanup, memory effects,
ABI, or broad unexplained drift.

Common-sense judgment can select an accepted-drift candidate. It cannot replace
the required proof of equivalence.

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
repeated independent matching assignments, a deliberate main-agent decision to
suspend exact work, and confirmation that the candidate's behavior is reviewable.

Use the cumulative-evidence assessment above. The workflow sets no fixed claim,
probe, byte-parity, or assignment threshold. Explain why more exact work has low
expected value for this function.

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

Launch exactly four fresh reviewers concurrently. Do not launch a partial
cohort. Use complementary scopes and include one broad adversarial review.

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
4. add bounded source comments for key intent and established unusual behavior;
5. run final validation;
6. complete the ledger decision;
7. move the source to `src\verified_logic`;
8. version the source, ledger, and status change together.

`verified_logic` remains nonexact. Preserve its ledger and attempt log if later
exact work resumes.

## State flow

```text
queue -> matching worker -> main-agent validation
  exact                      -> matching
  narrow reviewed drift      -> accepted_drift
  uncertain or promising     -> scratch / later worker
  exact work deliberately suspended and behavior-ready
                             -> blind cohorts -> adjudication
     broad defect            -> scratch / matching
     no substantive finding  -> verified_logic
```
