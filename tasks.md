# Pending recovery tasks

## Scope and current state

This file indexes the active recovery work and known deferred work.
It does not replace the function registry or claim to enumerate every scratch function.
Update each task when its decision, evidence, or integration state changes.

Baseline: main `044149b59`, including the completed corpus worker integrations.
The protected proposal is on `review/array-current-20260909`, last checked here at `d7d1df629`.
Its locked worktree is `build/array-caller-worktree`.
No isolated corpus worker is active. Protected-array tasks remain unassigned.

Last validated results:

- Main: the last complete audit compiled 225 modules and passed 4,884 matching targets.
- Recent focused audits found no regression in each changed translation unit.
- Protected proposal: 90 modules compile; 2,542 matching targets pass.
- Tests: 415 tests and 31 subtests pass.
- Registry: 4,889 matching, 291 accepted drift, 16 verified logic, and 230 scratch functions.
- Scratch source covers 305,625 bytes.

Read [the checkpoint](decomp_notes/array_integration_checkpoint.md) and [the handoff](decomp_notes/session_handoff_array_storage.md) for history.
The original executable is the behavior oracle. Main-source differences alone do not prove defects.
Accepted drift and matching are equally complete recovery results.

## Assignment and completion rules

- Keep unapproved source isolated from main.
- Pin each assignment to a commit, source owner, proposal, and evidence set.
- Inspect preserved candidates before another probe.
- Use Variant Lab for broad natural-source searches. Test hundreds of variants when the supported search space permits.
- Combine declaration order, scope, expression, branch, loop, cast, temporary, and argument-preparation choices.
- Rank variants by bytes, edit distance, control flow, calls, relocations, boundary, and closure effects.
- Review allocation failures, aliases, widths, reloads, calls, memory effects, floating-point operations, and relevant fault order.
- Keep ordinary caller-owned stack objects and supported overlap in scope.
- Exclude invented pointers into future callee-owned storage unless executable evidence demonstrates actual use.
- Do not execute original or rebuilt game executables.
- Preserve rejected probes and complete affected-owner results.
- Distinguish a limited repair from whole-function approval and shared-header approval.
- Run local checks first. Run the complete affected closure before integration.
- Do not repeat a completed semantic proof for unchanged approved inputs without new evidence.

A task ends with a committed decision: approve, reject with evidence, or state a precise remaining evidence gap.
Record the tested inputs, changed files, validation, and next action in its ledger or function notes.
A local match or passing compilation alone does not complete semantic review.

## A. Protected-array integration

### A1. Review `004F57C0 evaluateOpenTasks`

- [ ] Finish the protected proposal review.

**State:** Isolated proposal. Main's completed accepted-drift body is unchanged.
The inspected original getters resolve the local virtual-table reload concern.
The command player/coordinate read order remains open; no complete behavior defect is proved there.

**Next:** Prove the relevant lifetime, alias, and fault order, or find an executable-supported natural repair.
Then finish the growth, cleanup-loop, and group-tail review.
Do not repeat the rejected coordinate-float probe or resume main's byte matching.

**Evidence:** [Review](logic_reviews/004F57C0.md).
The retained direct-member probe is committed on the protected branch.

**Done when:** The complete proposal delta has a recorded decision and all affected owners pass review.

### A2. Review both priority queries

- [ ] `004F7590 numberSoldiersWithPriority`
- [ ] `004F7870 numberWarshipsWithPriority`

**State:** Natural public-array source is integrated in main. Both functions remain scratch.
The warship repair restores duplicate soldier counting and growth retry before an empty membership search.
These are limited source approvals, not complete emitted-code approvals.

**Next:** Compare the complete bodies with the executable under the proposed shared-header inputs.
Check repeated IDs, empty searches, failed growth, receiver reloads, count updates, aliases, and relevant faults.
Do not redo the two proved source repairs merely because the functions remain mismatches.

**Evidence:** [Soldier review](logic_reviews/004F7590.md), [shared priority review](logic_reviews/004F7870.md).

**Done when:** Each complete body has an explicit decision, with any remaining gap separated from the approved repair.

### A3. Review information changes

- [ ] `004DE600 checkDefend`
- [ ] Information-module `ManagedArray<int>` subscript, add, and protected resize descriptions.

**State:** These are the remaining information-module differences under the protected header.
The earlier resource-membership and attack-score repairs do not approve them.

**Next:** Review original operations and helper identities, including failed growth and read/write order.
Coordinate shared-helper decisions with A5. Do not independently edit the same shared header from several worktrees.

**Evidence:** [Array checkpoint](decomp_notes/array_integration_checkpoint.md), [array interface recovery](decomp_notes/array_interface_recovery.md).
Use the current changed-description report listed below.

**Done when:** Each description has an owner, evidence, and an explicit approval or remaining objection.

### A4. Review and integrate movement repair

- [ ] `0045DB90 doMove`

**State:** A separate preserved proposal repairs two proved defects. Integration remains pending.
Reset-only evidence does not approve the control-flow repair or the whole function.

**Next:** Review the complete movement proposal and its affected closure against the executable.
Separate approved reset operations from the remaining control-flow decision.

**Evidence:** [Function notes](decomp_notes/functions/0045/0045DB90.md).
Complete proposal: `decomp_notes/candidates/0045/0045DB90_complete_complete_protected_movement_tail.patch` and its JSON record.

**Done when:** The complete proposed delta has a recorded decision and validation supports integration or rejection.

### A5. Classify and review every remaining shared-header difference

- [ ] Mark each description as approved, unreviewed, or blocked, with its evidence and exact review scope.
- [ ] Assign the unreviewed descriptions to disjoint source-owner tasks.
- [ ] Finish helper ownership, symbol identity, reference-only changes, and remaining caller reviews.

**State:** The current comparison contains 41 changed descriptions across 3,586 emissions.
They are not 41 new defects or 41 unreviewed game functions.
The added `taskResearch` description is already covered by a complete review.
Limited neighboring approvals do not automatically approve their full shared-header deltas.

The following inventory accounts for all 41 descriptions. It is a review checklist, not a defect list.

| Module | Changed descriptions | Count |
| --- | --- | ---: |
| `aiuaimod` | `00413150 save`; `00414800 selectNewPlayPhase` | 2 |
| `move_obj` | `0045DB90 doMove` — A4 | 1 |
| `taiinfmd` | `004DE600 checkDefend`; subscript, add, protected resize — A3 | 4 |
| `taistrmd` | `004EA280 setVictoryCondition`; `004E9820 update`; public and protected resize | 4 |
| `taitacmd` | Subscript, add, public resize, protected resize | 4 |
| `taitacmd` | `004F0D70 addObject`; `00502310 checkForAttackResponseBuildInsertions`; `004F0190 doSomething`; `004F13F0 evaluateCivilianDistribution` | 4 |
| `taitacmd` | `004F57C0 evaluateOpenTasks` — A1 | 1 |
| `taitacmd` | `004FE950 fillBoatGroups`; `004FC500 fillSoldierGroups`; `004F7E80 idleCivilian`; `004F81A0 idleCivilian` | 4 |
| `taitacmd` | `004F62C0 notify`; both priority queries — A2 | 3 |
| `taitacmd` | `004EF4E0 save`; `004FDE00 setupBoatGroups`; `004FBC30 setupSoldierGroups` | 3 |
| `taitacmd` | `004F21F0 taskActiveSoldiers`; `004F1600 taskCivilians`; `00503070 taskElephantGatherers`; `004FA170 taskGatherer` | 4 |
| `taitacmd` | `004FB710 taskResearch` — completed review; do not reopen without new evidence | 1 |
| `taitacmd` | `004F4AA0 taskUngroupedSoldiers`; `004F8E20 updateGathererDistribution` | 2 |
| `taiuaimd` | `00508320`, `00504E10`, `005041C0 processNotify`; protected resize | 4 |

`setVictoryCondition`, `doSomething`, tactical `save`, and `setupBoatGroups` have reference-only description changes in this comparison.
Check their reference identities; do not label them changed instruction bodies.

**Evidence:** `build/protected-priority-reviewed-owner-changes.json`.
Its committed archive is identified in the evidence section below.
Also read [play and neighbor reviews](logic_reviews/004F4760.md) and [priority and neighbor reviews](logic_reviews/004F7870.md).

**Done when:** Every description has a decision. No unclassified item remains hidden behind the aggregate count.

### A6. Decide shared-header integration

- [ ] Complete A1–A5 or explicitly exclude unapproved repairs from a smaller validated proposal.
- [ ] Rebase or merge onto the selected main commit without changing approved behavior.
- [ ] Repeat the 90-module affected-header audit and complete emitted-description comparison.
- [ ] Review every new delta and validate identities, boundaries, calls, and references.
- [ ] Integrate only the approved source and registry decisions. Preserve the rejected remainder.

**State:** Blocked by incomplete owner review, not by matching-target failures.
The protected header must remain isolated until this gate passes.

## B. Integrated partial recoveries: separate whole-function work

These repairs are already on main. They are not waiting for source integration.
Their complete original-executable differences remain separate recovery tasks.

| Task | Function | Next action and evidence |
| --- | --- | --- |
| B1 | `0046B6E0 findTilePath` | Review remaining frame/control-flow and floor-evaluation differences. Keep the approved bounds and radius repair. [Review](logic_reviews/0046B6E0.md). |
| B2 | `004D9240 gameIDOfResourceObject` | Review the remaining body outside the approved bounded membership repair. [Review](logic_reviews/004D9240.md). |
| B3 | `004DC750 objectToAttack` | Review the remaining body outside the approved 85-operation score region. [Review](logic_reviews/004DC750.md). |

- [ ] B1 complete-body decision.
- [ ] B2 complete-body decision.
- [ ] B3 complete-body decision.

Their repaired emissions already agree under main and protected headers.
These whole-function tasks do not block A6 merely because the functions remain scratch.

## C. Deferred investigations

These tasks are pending, not assigned. Their earlier order was serial deferral until the shared-header decision.
They can run independently in isolated worktrees if source ownership and integration dependencies are explicit.

| Task | Function | Next action and evidence |
| --- | --- | --- |
| C1 | `00435110 duplicate_check_command_order` | Resolve Y conversion and relevant fault order. Apply the current stack-input scope to historical objections. [Review](logic_reviews/00435110.md), [notes](decomp_notes/command_order_repair.md). |
| C2 | `004180C0 processNotify` | Classify and review the 12 remaining differences after the public-interface repair. [Array interface notes](decomp_notes/array_interface_recovery.md). |
| C3 | `0050C730 tech_cost` | Finish natural scalar-storage and arithmetic review. |
| C4 | `0050CA9E check_tech_cost` | Finish natural scalar-storage and behavior review. |
| C5 | `0050CC25 start_research` | Finish source recovery and complete behavior review. |
| C6 | `0050CE68 check_for_new_tech` | Finish source recovery and complete behavior review. |

- [ ] C1 complete decision.
- [ ] C2 complete decision.
- [ ] C3 complete decision.
- [ ] C4 complete decision.
- [ ] C5 complete decision.
- [ ] C6 complete decision.

Tech evidence: [stack review](decomp_notes/tech_stack_review.md) and the four VA-specific notes under `decomp_notes/functions/0050/`.
Keep the integrated double literals. Do not repeat rejected stack permutations without new evidence.
Each task needs a complete decision, preserved inputs, and affected-owner validation before integration.

## D. Project-wide follow-up

- [x] Refresh the broader scratch backlog from the registry before assigning unrelated modules.
  The 231 scratch functions are not all listed individually here.
- [ ] Resolve the recorded accepted-drift evidence gap at `00405850`.
  First identify the missing evidence; do not assume byte matching is required.
- [ ] Continue linked-reference identity work.
  The earlier audit retained 5,276 unknowns. Refresh that count before planning or reporting progress.
- [ ] Continue gameplay and storage coverage review under the static-only execution constraint.
  Passing function checks does not prove complete game behavior.
- [x] Establish worker models, thinking levels, concurrency limits, and compiler-job limits before launching agents.
  Corpus workers use `openai-codex-secondary/gpt-5.6-luna`, `xhigh`, 15 slots, isolated worktrees, and `--jobs 1`.
- [x] Complete and integrate the final isolated corpus worker wave.
  The wave retained supported repairs in `rmm_elev`, `tpnl_tml`, and `map`.
  It preserved the remaining target evidence without unsupported registry promotions.

## Completed work: do not put back in the matching queue

- `005004C0 bestGroup`: completed accepted-drift review.
- `004F4760 playTaskSoldiers`: completed natural-buffer repair and exact result.
- `004FB710 taskResearch`: completed four-byte home-exchange review; accepted drift on main.
- Main's `004F57C0 evaluateOpenTasks`: completed result; A1 concerns the isolated replacement, not metric-only retuning.

Reopen these only with substantive source, type, ownership, simplification, or behavior evidence.
The partial repairs in section B also remain approved within their recorded scope.

## Where the evidence lives

Committed on main:

- `logic_reviews/`: decisions, proofs, and review limits.
- `decomp_notes/functions/`: target findings and historical probes.
- `decomp_notes/candidates/`: complete preserved source patches and metadata.
- `decomp_notes/experiments/`: immutable input states, events, and archived evidence objects.

The live protected source is committed on its separate branch, not integrated into main.
Do not remove preserved branches or worktrees as part of task assignment.
Some convenient reports are unpacked under ignored `build/` paths; those paths alone are not durable records.

Current source-review event:
`670652f57461e567b82e9bafb94c5c67fd0618b6605a586ce3a77bb20fa04aae`.

Current protected-audit event:
`84dddc575ce3c749cae4bb83a220f21674e33c4ee66efe11a9ff2d61924bb275`.

Their JSON files under `decomp_notes/experiments/events/` map artifact names to committed content objects.
Use those records if an unpacked report is missing. Read `docs/experiments.md` before using preservation tools.
Earlier information and path archive records are linked from the checkpoint and their review ledgers.

## Keep this list current

For each completed or blocked assignment, record:

1. Task ID and exact function or helper scope.
2. Tested main and proposal commits.
3. Decision and evidence path.
4. Changed owners and closure results.
5. Integration commit, or the precise remaining blocker.

Do not mark a whole-function task complete from a partial repair.
Do not count an already-approved description as a new integration objection.
