# Logic review: 004F21F0 `taskActiveSoldiers`

## Phase transition

The main agent suspended exact matching after repeated assignments stopped
producing useful structural progress.

Candidate: `src/scratch/004F21F0_taskActiveSoldiers.cpp`.

Cumulative evidence includes:

- eight recorded claims and more than one hundred meaningful probes;
- multiple sustained worker passes over behavior, ABI, layout, control flow,
  liveness, source context, and compiler flags;
- PDB line, symbol, local, and source-label evidence;
- direct executable, CFG, ordered-call, frame, and stack-map comparisons;
- exact same-translation-unit donor and neighboring-function experiments;
- controlled translation-unit tests with zero through twelve preceding bodies;
- repeated convergence on the same broad emitted-code basins;
- no recent change to the unresolved relic and defender setter-tail ownership.

The last exact-oriented source had these checker results:

- original/rebuilt meaningful size: 9580/9588 bytes;
- frame: `0xD0/0xD0`;
- saved registers: exact;
- calls: 440/437;
- ordered-call alignment: 93.86 percent;
- conditional branches: 233/235;
- jumps: 69/66;
- instruction-shape similarity: 80.57 percent;
- exact-block coverage: 36.11 percent;
- strict positional difference: 8820 bytes.

The remaining exact obstacle was broad compiler tail ownership. VC5 merged one
relic and defender completion suffix. Local source forms either kept that merge
or damaged proved behavior, frame, or nearby structure.

## Normalization before review

The main agent removed these codegen-only forms:

- the `TASK_GROUP` scheduling macro;
- three shared integer stack homes used as unrelated floats and pointers;
- the `task_group` compiler tail;
- the `exception_after_task` coordinate tail;
- one unused reset macro.

The source now uses direct task and location calls on each path. It keeps the
PDB-proved `ContinueLoop` label. It also keeps the binary-supported common
attack-state clear tail.

Normalized validation reports:

- original/rebuilt meaningful size: 9580/9583 bytes;
- frame: `0xD0/0xC8`;
- saved registers: exact;
- calls: 440/441;
- conditional branches: 233/235;
- jumps: 69/67;
- instruction-shape similarity: 81.02 percent;
- exact-block coverage: 32.59 percent;
- strict positional difference: 8747 bytes.

Normalization changed compiler tail sharing and local lifetimes. It did not
intentionally change any reachable source path, call, argument, or state write.
The review must verify that claim against the executable.

## Semantic questions at entry

Reviewers must establish these facts directly from the executable:

1. Verify sentinel traversal, null handling, group advancement, and time limits.
2. Verify every inactive group-type branch and its state writes.
3. Verify defend and relic path calls, arguments, failure exits, and wait state.
4. Verify victory-condition target selection and allocation-failure behavior.
5. Verify attack target selection, limiter predicates, and attack-state updates.
6. Verify transport actions `0x0D`, `0x0F`, and `0x10`, including unit removal.
7. Verify action 7 path recovery, timeout behavior, and exception-path calls.
8. Verify action 2 replacement, subtype, enemy, retreat, and play-status paths.
9. Verify actions 3, 4, `0x0C`, and `0x13`, including loss calculations.
10. Verify every direct and virtual call ABI, argument, and receiver.
11. Verify field offsets, integer widths, signedness, and division behavior.
12. Verify memory access, allocation, cleanup, exception, and first-fault order.
13. Verify that normalized direct calls match each reachable shared-tail path.
14. Identify unreachable source, missing executable paths, and extra source paths.

## Review rounds

### Round 1 — initial two-reviewer cohort, 2026-08-18

This cohort completed before the project changed the required cohort size from
two reviewers to four. All later cohorts use four fresh reviewers.

- `sa-7766f98f` — broad adversarial behavior review;
- `sa-4beb79fa` — ABI, control-flow, and fault-order review.

Both reviewers used `openai-codex-secondary/gpt-5.6-luna` with `xhigh`
thinking.

The broad reviewer reported nine confirmed difference groups:

1. Attack-disabled and attack-limiter rejection paths did not exit.
2. One successful action `0x0D` entry path did not clear active state.
3. The action `0x0F` and `0x10` reset omitted one group-state store.
4. Action `0x10` added a null guard for the action-list owner.
5. Action `0x10` added a changing-result `unitAI()` null guard.
6. Avoidance setup used the wrong predicate and getter order.
7. One action 3 path skipped the common dispatch and loss path.
8. Normal action 7 and action 2 paths skipped loss handling.
9. Several action paths omitted the common active-state clear.

The reviewer found no confirmed difference in the initial sentinel scan, group
skip filters, defend and relic path calls, resize bounds, most transport loops,
replacement targeting, or the final time-limit check.

The ABI reviewer reported four difference groups:

1. Tactical-group getters used noncanonical local declarations.
2. Several other helper declarations might have wrong qualifiers or references.
3. History logging used a free local declaration instead of AIModule ownership.
4. The debug timer used `const char*` instead of the original `char*`.

It also reported the avoidance predicate-order risk. It found no confirmed
virtual-slot, field-width, allocation, cleanup, or normalized task-argument
difference.

## Main-agent round-1 adjudication

Direct executable review confirmed all nine broad control-flow groups. The
source now:

- exits after attack disable and limiter rejection;
- clears active state on the reported action paths;
- restores the missing `numberObjectsToDestroyValue` reset;
- removes both extra null guards and preserves original fault behavior;
- evaluates avoidance predicates in executable order;
- routes normal action 7, action 2, and action 3 paths through loss handling.

Exact getter donors confirmed the TacticalAIGroup `const` qualifiers and
Waypoint reference returns. The source now uses those declarations.

Exact donors cleared part of the ABI report. `UnitAIModule`,
`TribeStrategyAIModule`, and `BuildAIModule` getters are non-const in the
original. Target-point helpers return pointers. Generated donor signatures also
support pointer parameters for `bestGroup` and `findStagingPoint`. Those local
declarations remain unchanged.

Executable call setup and exact donors confirmed AIModule history-log ownership
and the timer's mutable character pointer. The source now uses both canonical
forms.

The integrated source validates and compiles. A fresh four-reviewer cohort must
review the corrected candidate.

### Cohort policy update

The user increased every blind cohort from two reviewers to four. The main-agent
workflow now requires exactly four fresh concurrent reviewers. Round 2 will use
that policy.

### Round 2 — four-reviewer blind cohort, 2026-08-18

- `sa-4d9fc8d2` — broad adversarial review;
- `sa-bf76ab8d` — action-dispatch and shared-tail review;
- `sa-a828ade5` — transport and first-fault review;
- `sa-bf812298` — ABI, targeting, and arithmetic review.

All reviewers used `openai-codex-secondary/gpt-5.6-luna` with `xhigh`
thinking.

The broad reviewer confirmed two differences:

1. One action `0x0D` missing-commander path also cleared assist fields.
2. The loss expression called original HP before current HP.

It cleared traversal, main targeting, most transport paths, cleanup, and time
advancement. It also raised one signed-overflow question in array guards.

The dispatch reviewer confirmed two differences:

1. Action 2 with an active play entered loss handling instead of the clear tail.
2. Action 4 with a missing target entered loss handling instead of resetting.

It also claimed that several pointer and clear tests used a nonzero inherited
`EBP` value. Direct entry disassembly clears `EBP` at `004F2254` before every
group path. The main agent rejected those claims.

The transport reviewer confirmed one difference. Action `0x0D` treated a null
transporter as available capacity. The original clears both assist fields and
active state. It cleared the remaining boarding, staging, transporter,
defender, attacker, stopper, allocation, and changing-getter paths. It raised a
load-order question for `master_obj` and `objects`.

The ABI reviewer confirmed these differences:

1. `objectToAttack` uses an `int&` output parameter.
2. Influence helpers take signed integer owner arguments.
3. One action 2 replacement-failure path continued into loss handling.
4. The action 7 timeout shift needed unsigned-before-shift behavior.

It claimed that `numberUnits` is non-const. The exact getter donor uses the
const symbol, so the main agent rejected that claim.

## Main-agent round-2 adjudication

Executable review confirmed the reported action `0x0D`, action 2, action 4,
loss-order, shift, and helper-ABI differences. The source now:

- exits immediately on the missing action-`0x0D` commander;
- clears assist fields for a missing action-`0x0D` transporter;
- sends active-play action 2 paths to the clear tail;
- sends all failed action 2 replacement paths to the clear tail;
- resets action 4 after a missing target;
- calls current HP before both original-HP calls;
- calls current unit count before both original-unit-count calls;
- shifts the timeout setting as unsigned 32-bit data;
- uses the PDB-supported reference and signed helper declarations.

Compiled output uses `dec` and `jns` for every reviewed array guard. This
matches the executable's `INT_MIN` wrap behavior. Compiled output also loads
`master_obj` before `objects` in both reviewed transport comparisons. Those two
open questions are cleared.

The corrected candidate compiles. A fresh four-reviewer cohort must review all
integrated round-2 changes.

### Round 3 — four-reviewer blind cohort, 2026-08-18

- `sa-81d2e3b8` — broad adversarial review;
- `sa-d3af07dc` — inactive and targeting review;
- `sa-a3f5b96d` — active-dispatch review;
- `sa-901123a2` — ABI and machine-effects review.

All reviewers used `openai-codex-secondary/gpt-5.6-luna` with `xhigh`
thinking.

The cohort confirmed these behavior differences:

1. The direct defense path used `weaponRange()` instead of `sn[0x17]`.
2. A null selected target fell into post-setup and issued an extra task.
3. Active exception paths called `weaponRange()` twice instead of once.
4. Action 7 exception paths also called `weaponRange()` twice.
5. Action `0x0D` used the wrong null-transporter path after round 2.
6. Action `0x13` tested elapsed time before calling `allUnitsIdle`.
7. Target-point code called the second getter before copying the first value.
8. Object lookup methods belonged to `MainDecisionAIModule`.

One reviewer claimed that action 3 skipped action-7 behavior. The original only
passes through pure action comparisons before reaching the loss guard. Since
the action remains 3, no action-7 body runs. The main agent rejected that
finding.

One reviewer claimed that action-2 play recovery uses `playNumberValue == -1`.
Original range `004F436B-004F43D0` enters recovery only when the value is not
`-1`. The main agent rejected that finding.

The ABI reviewer also challenged `numberUnits`, strategy getters, target-point
returns, and allocator aliases. Exact getter donors support the retained const
and pointer forms. Exact repository sources and the build resolver support the
allocator aliases. Those findings are cleared.

## Main-agent round-3 adjudication

The source now:

- passes `sn[0x17]` to the direct defense path call;
- exits after null target selection;
- evaluates each active-path weapon range once and reuses it;
- restores the original action-`0x0D` null-transporter unit scan;
- calls `allUnitsIdle` before the action-`0x13` elapsed-time branch;
- copies all four dwords from target point 1 before calling target point 2;
- owns both object overloads on `MainDecisionAIModule`.

The corrected candidate compiles. A fresh four-reviewer cohort must review all
integrated round-3 changes.

### Round 4 — four-reviewer blind cohort, 2026-08-18

- `sa-3ea12b41` — complete adversarial review;
- `sa-c727aa5f` — inactive-path review;
- `sa-076ed19a` — active-path review;
- `sa-5bc6b135` — ABI and exceptional-path review.

All reviewers used `openai-codex-secondary/gpt-5.6-luna` with `xhigh`
thinking.

The cohort confirmed these differences:

1. Action `0x10` omitted `stopUnit` for a type-100 unit with no target object.
2. The special target path omitted `attackAttempts++`.
3. One action-`0x0F` stop path repeated containment checks after `stopUnit`.
4. Virtual slot `+0x194` takes six arguments, not two.
5. `removeUnboardedUnits` returns `int`, although this caller ignores it.

One reviewer claimed that the defense direct path needs `sn[0x17]`. Original
range `004F259C-004F2664` calls `weaponRange()` for defense. The `sn[0x17]`
range at `004F2402` belongs to relic handling. The main agent restored the
correct defense call.

One reviewer claimed that action 4 with a null target enters loss handling.
Original range `004F4417-004F448E` resets action and in-use state. The retained
reset is correct.

One reviewer claimed that action-2 play recovery uses the opposite predicate.
The candidate's outer `playNumberValue == -1` block already guards all action-2
maintenance. Original `004F436B-004F43D0` confirms the retained recovery test.

## Main-agent round-4 adjudication

The source now:

- stops an outside type-100 unit when its target object is absent;
- increments the special memory target before commander lookup;
- advances the unit loop immediately after the reported stop call;
- passes `target`, range, `0`, `1`, `-1`, and `-1` to slot `+0x194`;
- declares `removeUnboardedUnits` with its original return type;
- restores `weaponRange()` for the direct defense path.

The corrected candidate must compile and pass another fresh four-reviewer
cohort before promotion.

### Round 5 — four-reviewer blind cohort, 2026-08-18

- `sa-ec6d4859` — broad review;
- `sa-a05def2b` — pathing and targeting review;
- `sa-db55cf70` — transport and dispatcher review;
- `sa-cda7ecdf` — ABI and fault-order review.

All reviewers used `openai-codex-secondary/gpt-5.6-luna` with `xhigh`
thinking.

Three reviewers found no broad behavior or ABI difference in their assigned
areas. The pathing reviewer confirmed one missing
`numberObjectsToDestroyValue = 0` write after action-2 replacement failure.

The dispatcher reviewer again claimed that action 3 can enter action-7 work.
Exact `isGathered` source shows that helper can remove invalid units but does not
change the group action. The original redispatch therefore performs only pure
action getters before its action-3 loss guard. The direct candidate route has
the same state and result. The main agent cleared this finding.

## Main-agent round-5 adjudication

Original range `004F4299-004F42A9` confirms the missing reset store. The source
now writes zero between `setTarget(-1)` and `setTargetType(-1)`.

The candidate needs one fresh four-reviewer convergence cohort after this fix.

### Round 6 — four-reviewer blind cohort, 2026-08-18

- `sa-96dd49b5` — broad convergence review;
- `sa-9b2492cf` — inactive convergence review;
- `sa-caf38bfe` — active convergence review;
- `sa-023bbef2` — ABI convergence review.

All reviewers used `openai-codex-secondary/gpt-5.6-luna` with `xhigh`
thinking.

The cohort confirmed these differences:

1. One action-`0x0D` capacity check loaded `master_obj` before `objects`.
2. Defend additional-path failure omitted the idle timestamp reset.
3. The special `sn[0xA2]` path had an extra `attackAttempts` increment.

The active reviewer claimed that history logging passed only the format pointer.
Compiled output at the two calls pushes the format pointer and `EDI`, then
cleans eight bytes. The main agent cleared that finding.

The ABI reviewer claimed that every no-loss path needs an active-state clear.
Original `004F44A3`, `004F44B3`, and `004F4522` jump directly to `004F4552`
without the store at `004F4548`. The retained behavior is correct.

## Main-agent round-6 adjudication

The source now:

- reads the action-`0x0D` object list before the master object;
- distinguishes defend additional-path failure from path-point failure;
- resets consecutive idle time only on the additional-path failure;
- removes the extra special-path attack-attempt write.

Compiled output confirms the required object-list-before-master load order. A
fresh four-reviewer cohort must review these fixes.

### Round 7 — four-reviewer final convergence cohort, 2026-08-18

- `sa-d084309a` — broad final review;
- `sa-3619b96e` — inactive final review;
- `sa-62a1b7e4` — active final review;
- `sa-fb3a76f0` — ABI final review.

All reviewers used `openai-codex-secondary/gpt-5.6-luna` with `xhigh`
thinking.

The broad and inactive reviewers found no confirmed difference. They audited
all reachable paths, calls, arguments, writes, cleanup, returns, and fault
order.

The active reviewer claimed that the initial skip paths bypass state and time
handling. Original skip target `004F45B2` only advances the group pointer and
returns to the loop test. It does not update the resume ID, test active state,
or check time. The candidate skip has the same behavior.

The ABI reviewer claimed that the action-2 play gate covers only the HP loop.
The source's outer `playNumberValue == -1` block spans the complete maintenance
body through the subtype paths. The following recovery block handles non-`-1`
values, as original `004F3D85-004F3D8C` requires.

The ABI reviewer also claimed that direct defense adds a gather call. Original
defense range `004F2769-004F2804` sets target location, gather location, and
in-use state. The retained call is correct.

## Main-agent round-7 adjudication

No confirmed behavior difference remains. The final cohort converged after
direct executable review cleared its three reported questions.

## Final decision

Promote to `src/verified_logic`.

Final normalized checker state before the move:

- original/rebuilt meaningful size: 9580/9771 bytes;
- frame: `0xD0/0xF0`;
- saved registers: exact;
- calls: 440/439;
- conditional branches: 233/234;
- jumps: 69/70;
- instruction-shape similarity: 79.70 percent;
- exact-block coverage: 33.91 percent;
- strict positional difference: 8684 bytes.

The remaining differences are nonexact compiler structure. Normalization gives
direct source call sites instead of several merged VC5 tails. Named value
copies and sequenced fault-order reads also extend local lifetimes and the
frame. Seven review rounds found and corrected substantive source differences.
The final four-reviewer cohort found no surviving reachable behavior gap.

Reopen exact matching only when new original source, new canonical ABI evidence,
or a concrete executable counterexample gives a new lead.
