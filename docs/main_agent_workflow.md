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

Within the user-supplied concurrency ceiling, the main agent may run matching
workers concurrently on different targets. Only one worker may edit a given
function at a time.

Use `python tools/query_project_status.py --logic-review-in-progress --paths`
to inspect candidates currently in semantic review, and `--verified-logic` for
completed semantic reconstructions.

## User-supplied execution contract

Before launching subagents, obtain the user's execution contract:

- exact provider/model ID, not a nickname or inferred equivalent;
- explicit thinking level;
- an approximate maximum active-subagent count or an allowed range;
- any per-role model differences or temporary stop/replacement instructions.

Resolve an ambiguous model name with the local model-list command and confirm the
exact ID. Never inherit or guess a subagent model or thinking level. Unless the
user supplies separate role contracts, use the approved model/thinking pair for
matching workers, readiness auditors, and semantic reviewers alike.

Treat the user's maximum, or the upper end of a range, as a ceiling across active
and queued subagents. It is not a requirement to keep every slot occupied. A
lower end is a planning preference, not permission to launch low-value work. A
later user instruction such as "wrap up" or "start no more" overrides the earlier
contract immediately; do not replace completed or failed agents afterward.

## Concurrency and scheduling

Prefer a small live set whose results the main agent can review promptly. For a
four-agent ceiling, the normal allocation is at most two matching workers and at
most two read-only analysis/review workers. Adapt this split to the queue, but
never place two editors on one function.

Operational rules:

1. Count queued work against the ceiling; do not create a long hidden backlog.
2. Launch independent matching workers only on different targets.
3. Integrate and commit completed edits before reflexively filling the freed
   slot. The ceiling is not an occupancy target.
4. Replace a failed agent only when the user still permits launches and the
   replacement has a narrower, useful scope.
5. Do not poll running agents repeatedly. Use completion notifications; request
   status only when an orchestration decision actually depends on it.
6. Reserve two read-only slots for a complete blind-review cohort once a function
   enters logic review. Do not start one reviewer while the other cohort slot is
   occupied by unrelated work.
7. Matching results may be integrated individually as they finish. Blind-review
   reports may likewise be collected individually, but they create a logical
   barrier: do not adjudicate, edit the reviewed candidate, or act on any cohort
   finding until every member of that cohort has finished.
8. Do not turn a cohort's logical barrier into an immediate blocking wait for all
   reviewers. Use completion notifications or collect whichever result is ready,
   then continue independent orchestration work while the remaining reviewers
   run. Block only when adjudication is the next useful action and the cohort is
   still incomplete.

Broad initial queues are counterproductive in a shared worktree. Start with the
smallest useful batch, observe integration cost and compiler contention, and
expand only within the user contract.

## Participant briefings

Every subagent prompt must assign exactly one role and include the relevant
constraints below. Repository documents supplement the prompt; they do not make
an ambiguous assignment safe.

### Matching worker

- one explicit VA and one unique lease owner;
- read `README.md`, the complete `LESSONS.md`, `AGENTS.md`, the current attempt
  log, and target history;
- follow the ten-hypothesis target-session contract unless given another budget;
- run dossier, donor, and ABI evidence before broad archaeology;
- edit only the target source and narrowly justified flags/shared facts;
- do not commit, change unrelated functions, or normalize whole-file line endings;
- finish with attempt notes, unchanged validation, and pause or exact promotion.

### Phase-readiness auditor

- strictly read-only; no lease, edits, source-shape probes, or commits;
- may inspect attempt logs, session evidence, concise checker output, and Git
  history because this is matching-stall analysis, not blind semantic review;
- normally assess one or two named functions only;
- judge exact-match exhaustion separately from semantic completeness;
- identify concrete remaining leads and the exact prerequisite for ledger entry.

Do not assign an auditor a corpus-wide packet sweep. Use
`query_project_status.py` to shortlist, then inspect at most a few candidates.
If a broader scan is necessary, divide it into bounded source/TU groups.

### Blind semantic reviewer

- one named function, fresh context, and explicitly read-only;
- no lease, edits, commits, `logic_reviews`, Git history, prior reports, or prior
  claims that a difference is harmless;
- compare candidate source directly with executable evidence and treat comments
  as untrusted hypotheses;
- report definite differences, plausible concerns, verified assumptions,
  unestablished areas, and a conclusion with concrete binary evidence.

A readiness audit is never counted as a blind semantic review. A reviewer that
accidentally reads the ledger or prior conclusions is contaminated and cannot
count toward an independent cohort.

## Context and output discipline

- A matching worker receives one target, not a shopping list.
- A readiness auditor normally receives no more than two targets.
- A blind reviewer receives exactly one candidate.
- Prefer concise checker maps, focused ranges, and dossier sections over complete
  packet/history dumps.
- Remind participants to use `everything_search` for filename/path discovery and
  `rg` for contents; recursive `find` is inappropriate for ordinary indexed repo
  discovery and can stall on large `orig`/`build` trees.
- Ask for compact final reports containing outcome, probes or review scope,
  metrics/findings, changed files, validation, and next lead.
- If an audit approaches the model context limit, stop and return the bounded
  evidence already established rather than loading more candidates.

## Matching assignments

Assign one function to one matching worker. Require the worker to follow the
normal target-session contract in `AGENTS.md`, including a default budget of ten
meaningful hypotheses, a compact source attempt log, final validation, and a
pause or exact promotion result. Begin from or restore a clean period-plausible
reconstruction with canonical field/type ownership before localized codegen
tuning. Do not frame a decompiler-shaped retained scratch file as authoritative
source merely because it currently has the best diff.

The worker's first integrated `baseline` check pins that reconstruction in the
existing function history. There is still one living source file. Later experiments
may occupy metric-best history checkpoints without moving the clean pin. An
unresolved worker must restore or explicitly repin the defensible final source
before pausing; the session tool enforces this after final validation.

Ten hypotheses bound one worker assignment. They do not prove that the function
is exhausted. The main agent may assign fresh workers to the same function many
times. Before doing so, ensure the next worker reads the existing source attempt
log and target history and has a plausible way to add new evidence rather than
repeat an explored compiler basin. When prior workers mainly optimized one raw
pointer/decompiler form, prefer a clean-source reset using exact donors, PDB line
bands, canonical arrays/classes, and original API idioms over another register
allocation pass.

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
3. audit source plausibility: reject retained fake volatility, unused locals,
   comma-expression scheduling, raw vtable/offset plumbing, or decompiler cursors
   that have no original-source or behavior justification;
4. reject forbidden asm, fake exactness, relocation mistakes, and policy drift;
5. rerun `check_function.py --va <VA>` and confirm the claimed outcome;
6. verify that the attempt log accurately records tried, kept, rolled-back, and
   remaining hypotheses;
7. inspect the session's clean-source and codegen-best lines separately; if an
   opaque nonexact experiment only moved assembly closer, preserve its evidence
   in notes and restore the clean reconstruction before integration;
8. accept, revise, or reject the result;
9. perform status moves and version-control integration only after verification.

Also inspect `git status` before and after integration. Shared-tree workers must
not silently rewrite line endings, leave compiler artifacts, or modify common
headers without reusable evidence. Stage explicit reviewed paths rather than
using a blanket add, and keep another running worker's changes out of the commit.
If Git is temporarily locked by an active process, wait for that process; do not
delete a live lock file.

Exact functions go to `src\matching`. Rare near-exact functions may go to
`src\accepted_drift` only under its existing narrow policy. Materially uncertain
functions remain in `src\scratch`.

## Enter logic matching

Only the main agent may decide to suspend exact matching and enter formal logic
review. This requires substantial cumulative matching work and a candidate whose
behavior appears reconstructable even though exact VC5 codegen remains stuck.

Before launching the first blind cohort, perform a source-normalization pass.
Natural source is already the matching baseline; matching may temporarily test
compiler-steering spellings in checkpoints or labs, while logic review requires
all unjustified residue to be gone. Present the simplest ordinary C/C++ the
original developers plausibly wrote. Replace codegen-only comma expressions,
fake volatility, raw vtable/call
casts, manual-offset plumbing, redundant aliases, declaration-order tricks, and
decompiler scaffolding with canonical types, named fields, explicit statements,
natural control flow, and typed calls whenever the executable does not require
the odd form. Do not keep a lower diff at the cost of readability once exact
matching has been suspended.

An unnatural spelling may remain only when instruction evidence shows that it is
needed for real behavior such as access width, overlap, aliasing, lifetime,
evaluation/fault order, or an original bug. Document that reason. Rerun validation
after normalization and record metric regressions as nonsemantic drift. If
normalization exposes uncertain behavior, resolve it or return to matching work;
do not ask reviewers to reverse-engineer opaque codegen-lab residue.

Create `logic_reviews\<slug>.md` from the format documented in
`logic_reviews\README.md`. Record the phase-transition rationale, current exact
and structural metrics, cumulative matching evidence, known assembly differences,
and every semantic uncertainty present at entry. Keep the source's matching
attempt log intact.

The candidate normally remains in `src\scratch` during review. Folder placement
changes only after final adjudication.

## Launch a blind review cohort

Launch a complete cohort of at least two fresh reviewers concurrently. Give them
the candidate source and original evidence, but not the ledger, Git history,
previous reports, or a claim that any difference is harmless. Reviewers must be
explicitly read-only and must not claim the target.

Every review prompt must state that the goal is the original executable's actual
behavior, including bugs, odd signedness, incorrect-looking formulas, unintended
side effects, and error behavior—not the likely intention of the programmer.
Require concrete binary evidence for substantive findings.

Use complementary scopes such as control flow and bounds; calls, ABI, layout, and
memory effects; cleanup, ownership, and exceptional paths; and full adversarial
semantic review. Include at least one broad reviewer that is not primed with a
suspected issue.

Do not start a partial cohort merely to occupy a slot. If the user's concurrency
ceiling cannot provide at least two simultaneous read-only reviewers, finish or
defer other work first, or ask the user to revise the contract. Launch every
member of the cohort before collecting results. Record the cohort membership so
that an early report cannot accidentally trigger adjudication. Collect completed
reports as they arrive and continue unrelated useful work; cohort completeness
is required for action, not for the main agent to remain responsive.

In a harness with `wait_mode`, prefer nonblocking completion notifications or
`wait_mode="any"` when a result is currently needed. Keep the full cohort ID set
as the outstanding barrier and remove members only as their reports are safely
collected. Use a blocking `wait_mode="all"` only when no independent useful work
remains and progress genuinely depends on the complete cohort. Do not replace
this with repeated status polling.

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

Do not edit or adjudicate until the full concurrent cohort has completed. This is
a logical gate, not a requirement to issue a blocking wait-all operation as soon
as reviewers launch. Until the last report arrives, the main agent should keep
integrating independent matching results, validating unrelated targets, updating
the queue, or doing other non-conflicting work. Once complete, append all reports
to the per-function ledger, deduplicate findings, and adjudicate each one against
the binary as confirmed, unresolved, or cleared. Reviewer count is not a vote;
one evidence-backed behavioral objection blocks promotion.

The main agent directly applies bounded, well-established review fixes to the
function and updates the ledger in the same integration pass. Rerun the checker
and inspect the complete diff. Do not delegate isolated review fixes merely to
have another agent edit them.

Write review fixes as plausible ordinary developer source, not as new
compiler-scheduling puzzles. Prefer canonical declarations, explicit statements,
and typed calls even when they worsen byte metrics. Keep low-level or unusual
source only when the adjudicated executable behavior requires it, and record that
evidence in the ledger.

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
2. confirms the source is normalized, readable, plausible original-developer
   C/C++, with every remaining oddity justified by binary-observed behavior;
3. performs final policy and behavioral adjudication;
4. reruns final validation;
5. completes the ledger's final-decision section;
6. moves the source to `src\verified_logic`;
7. versions the source, ledger, and status change together.

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
