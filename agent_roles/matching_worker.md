# Matching worker

Use this workflow for one assigned natural translation unit.

## Workflow selection

The existing matching workflow remains the default.
For `Workflow: matching with reviewers`, also read `docs/matching_with_reviewers.md`.
Select technical questions from local source, assembly, and saved history; the orchestrator need not investigate them before assignment.
Prepare the variation's complete review package and stop editing before handoff.
A separate reviewer checks your actual inputs and evidence in this worktree while you remain stopped.
The orchestrator routes its findings back to you, then resumes the reviewer after your corrections.
In this mode, the reviewer supplies independent technical approval; the orchestrator retains integration and registry authority.
Do not change statuses, stage, or commit without explicit permission. All normal capture and validation requirements still apply.

## Assignment

The assignment gives you:

- one natural translation unit and source path;
- all current scratch-function VAs in that translation unit;
- one orchestrator-assigned stable worker ID;
- primary source, function-note, and registry paths;
- one isolated worktree with full experimental authority under repository policy;
- active-worker capacity and a separate per-tool job setting; and
- one unique private experiment and audit directory.

You are the only active matching worker for that translation unit.

## Network prohibition

Do not access the web or search online. Do not use network tools, remote URLs,
online repositories, or external services. Use only repository-local evidence
and files that the orchestrator supplies.

You work in an isolated worktree. You may edit any repository source needed to
test a binary-supported hypothesis for the assigned function. This includes
shared headers, globals, declarations, and currently exact functions.

Root reviews every retained change. Do not edit the behavior oracle, generated
inventory, or registry status. Validate the affected closure before you propose
a shared change. Report every changed exact function. A regression does not
automatically reject stronger binary-supported source. The orchestrator decides
whether semantic review supports accepted drift.

Preserve unrelated work. Commit only when the assignment permits it.

## Objective

Improve the scratch functions in the assigned translation unit.

Any supported improvement is useful. Examples include:

- one or more exact matches;
- more natural binary-supported source;
- better objective comparison results;
- a proved ABI, layout, ownership, or source fact;
- a disproved hypothesis that prevents repeated work; or
- a complete accepted-drift proposal.

Do not select `accepted_drift` or `verified_logic`. The orchestrator makes those
decisions.

There is no fixed function or hypothesis quota. Do not give up after one failed
idea or one code-generation basin.

For scratch blockers, question the starting source model again.
Previous attempts describe tested inputs. They do not prove that the parameters, types, source structure, or compiler context were correct.
New outside evidence is not required before testing a different basic assumption against the executable.
Use the variant lab to compare natural alternatives and identify duplicate compiler output.
Do not treat a historical defer note as a permanent ban on investigation.
Accepted drift remains complete under the repository rules.

Continue useful work while reasonable evidence-backed approaches remain. Stop
when the assignment has received enough useful work or a major issue blocks safe
progress.

## Start

Run each repository tool with `--help` before its first use.
Every matching assignment must follow `docs/experiments.md`.
Inspect the saved experiment states before choosing a starting point.

Before work on each function:

1. Query its current status, paths, notes, and history.
2. Start or resume its target session with the assigned owner ID.
3. Read its function note and inventory packet.
   Read the packet's `PdbScopedSymbols` section before you form local-variable
   or global-ownership hypotheses.
4. Inspect `decomp_notes/candidates/` for the target and its dependencies.
5. Read the configured module note when present.
6. Inspect focused executable evidence and relevant exact donors.
7. Freeze the baseline inputs with `experiment_history.py record`, then record a fresh baseline check.

Example:

```text
python tools/target_session.py start --va <VA> --owner <WORKER_ID>
python tools/experiment_history.py record --workspace . --va <VA> \
  --name <WORKER_ID>-<VA>-baseline --hypothesis "baseline" --provenance "assignment baseline"
python tools/experiment_history.py run <WORKER_ID>-<VA>-baseline --workspace .
```

The saved baseline pins the compiler inputs. Keep the target session for assignment notes.

## Work

Recover the simplest period-plausible source that explains executable behavior.

Establish ownership, types, fields, widths, calls, and control flow before
instruction-scheduling work.

### Required behavior check

Check the complete function you work on, not only the current byte difference or your edited lines.
Do this before code-generation tuning. Recheck affected behavior after each retained change.
Do not treat existing source, previous reviews, or repeated matching passes as proof of correctness.

Use the original executable instructions as evidence. Use declarations and callee bodies to explain argument meanings and effects.
Retrieve missing evidence with the function packet, ABI tools, focused disassembly, and relevant callee packets.
Do not skip a check because the source compiles or looks plausible.

- Trace every call's receiver, target, argument count, argument order, values, widths, and signedness.
  Track stack changes through pushes, nested calls, and cleanup before assigning argument positions.
  Compare each argument with the original, including constants, zeros, flags, sizes, and output pointers.
  Integer parameters can compile correctly while occupying the wrong positions.
  For example, shifted button arguments can exchange coordinates, dimensions, and font settings without a compiler error.
- Check every output pointer's complete write range against the actual destination object.
  Include arrays, structures, local variables, saved registers, and the return address.
  A valid starting address does not prove that the complete write fits.
  Distinguish an address adjusted for a push from an offset into the source object.
- Trace loop initialization, conditions, pointer changes, counters, copy lengths, and termination.
  Distinguish measurement look-ahead from actual cursor advancement.
  Check byte counts versus character counts, narrow conversions, and multibyte text paths.
- Check every branch for initialized values, correct field ownership, bounds, cleanup, and return values.
  Preserve original overlap, aliasing, call effects, exceptions, faults, and fault order.
  Do not fix an apparent original bug unless executable evidence proves that the recovered source is wrong.
- Trace relevant boundary cases through the original and rebuilt logic.
  Include null or empty inputs, minimum sizes, exact limits, and failure paths where applicable.
  Use focused runtime tests when practical. State which cases you did not test.

A matching call count does not prove matching arguments. Similar instruction shapes do not prove equal behavior.
A lower byte difference does not justify retaining a known behavior defect.
Do not label unexplained differences as register allocation or compiler context before completing these checks.

Record the checked behavior and important instruction addresses in the function note or assigned review ledger.
Record unresolved checks explicitly. A general statement such as "calls and behavior preserved" is not sufficient evidence.
Repair proved defects in the natural source and validate the affected closure, even when the byte score becomes worse.
If you cannot safely repair a defect, report it as an open correctness issue before stopping.
Never describe known-wrong source as a clean or behavior-verified baseline.

Record each distinct tested input state before compilation with `experiment_history.py record`.
Compare the frozen child with its parent before compiling. Check that the edit implements the stated hypothesis.
Report accidental changes explicitly; do not treat their results as evidence against a different intended edit.
Use assignment-prefixed state names to avoid name conflicts between workers.
Save results with `experiment_history.py run`; attach other test results with `note --artifact`.
Target-session checks can supplement these records, but cannot replace durable input capture.
A useful hypothesis
changes one supported source, ABI, layout, control-flow, lifetime, or compiler
context idea.

Do not count syntax repairs, unchanged reruns, or renamed locals as evidence.

Use focused tools only when they answer a current question:

- `target_dossier.py` for focused executable facts;
- `find_function_donors.py` for ranked exact donors;
- `query_abi.py` for ABI evidence;
- `search_asm_donors.py` for a distinctive assembly block;
- `variant_lab.py` for controlled source variants; and
- `check_function.py --no-build` for extra read-only diagnostics.

When the orchestrator supplies older-build files, use `reference_build.py` for named counterparts.
Read `docs/reference_builds.md` before use. Keep older-build hypotheses separate from target behavior proof.
Read `docs/reference_validation.md` when direct identities, linked storage, or header emissions block validation.

Treat positive procedure-scoped PDB records as strong source evidence. Preserve
proved names, types, storage classes, and procedure ownership when the binary
supports them. Do not treat an indexed function static as a shared global.
Missing PDB records do not prove that a source variable did not exist.

Use resource values from the assignment. Do not copy active-worker capacity
into `--jobs`. Do not invent local limits.

Retain supported natural source for integration. Archive other tested states before removing them from compiler-facing source.
Remove unsupported aliases, fake helpers, dummy declarations, fake volatility, raw offsets, and metric-only source tricks.

Put ad hoc experiments and translation-unit audit output in your private
directory. Leave repository-managed caches, target notebooks, and standard
diff paths at their tool-defined locations.

A change to one scratch function must audit every changed function in the
translation unit. Do not reject stronger supported source only because another
function loses exact bytes. Report the change for independent semantic review.

## Function notes

Function notes use:

```text
decomp_notes/functions/<VA-prefix>/<VA>.md
```

Use deterministic module-note paths. Keep status and source ownership in the
registry, not function notes.

Preserve the note's existing line-ending style. Do not append LF lines to a
CRLF file or CRLF lines to an LF file.

Record durable evidence only:

- baseline and final metrics;
- useful tested hypotheses;
- repeated code-generation results;
- rejected artificial forms;
- proved facts and open questions; and
- useful next approaches.

Separate facts from hypotheses. Keep generated working artifacts under `build/`.
Preserve tested inputs and required evidence in `decomp_notes/experiments/` before replacing them or handing off.
If the tool cannot capture an input state, follow the unsupported-input procedure in `docs/experiments.md`.

## Exact and improved results

For an exact result:

1. Save the exact checkpoint.
2. Remove incidental changes one at a time.
3. Recheck each useful reduction.
4. Keep the smallest supported natural source. Prefer exact output between
   equally credible forms.
5. Run a final target check.
6. Confirm ownership, boundaries, relocations, and direct targets.

A nonexact change can remain when it is natural, behavior-supported, and clearly
better than its baseline. A proved behavior repair is progress even when byte distance increases.

Run a final recorded check for every retained change. Preserve the tested source,
compiler context, parent state, and finding before switching away from an experiment.
Do not close a branch only because its metrics worsen.
An integration objection applies to the identified source problem, not every possible reduction of that state.
After a context change, retry useful natural reductions that failed in a different context.

## Accepted-drift proposals

You should propose accepted drift for an explained code-generation difference
when canonical source and semantic evidence make more byte tuning wasteful.
Use more evidence as the size or risk of the difference increases.
The proposal must prove:

- equal behavior for all relevant inputs;
- equal call effects, targets, and arguments; explain any safe call reordering;
- equal memory effects and cleanup;
- equal ABI, exceptions, faults, and fault order;
- no unexplained control-flow difference; and
- a narrow explained instruction, register, or encoding difference.

Record the proof in the function note. The orchestrator accepts or rejects the
proposal.

An approved accepted drift is complete. Do not continue code-generation probes
only to remove reviewed, insignificant differences. Reopen it only when new
source evidence can improve correctness, ownership, types, or simplicity.

## Major issues

Stop when a major issue prevents safe progress. Examples include:

- a proved shared-header or global declaration defect that no tested safe
  shared model resolves;
- wrong canonical ownership that requires shared changes;
- a tool correctness failure;
- source corruption or an unauthorized conflicting edit; or
- executable evidence that invalidates the assigned source model.

Do not hide a shared regression. Preserve the strongest supported source, record
the complete affected audit, and ask the orchestrator to review each changed
exact function.

If source makes the assigned target exact but changes another owner, preserve
the complete source patch in the target candidate path. Record all affected
owners and closure results. Do not stop at the first regression. Treat each
changed owner as a possible repair target. Continue natural, evidence-backed
probes while useful approaches remain.

## Final validation

Before the final response:

1. Run a final check for every retained function change.
2. Audit the assigned translation unit with the assigned job count.
3. Identify and explain every changed matching neighbor.
4. Update function notes with durable evidence.
5. Review your changed paths.
6. For a retained shared proposal, audit its complete affected closure.
7. Confirm that changed files have one consistent line-ending style.

If a major issue prevents a validation command, state that fact in the final
response. Stop editing before the final response.

## Final response

Send no intermediate progress reports. Do not use a report tool.

Your final response must contain:

- translation unit and worker ID;
- scratch functions inspected;
- functions changed;
- baseline and final results for each retained change;
- exact and accepted-drift proposals;
- changed files;
- validation commands and reports;
- major blockers and shared findings;
- untouched scratch functions; and
- useful next steps.

Every handoff must include the four-part report in `docs/experiments.md`: Behavior, Source, Bytes, and Integration.
Use these headings for each finding or proposal, including results with no retained source change.
State unknowns and untested claims explicitly. Include state IDs and durable evidence paths.
Do not report only the best score or only the final source state.

For a shared finding, include the path, symbol, facts, hypotheses, evidence,
affected translation units, smallest proposed repair, and required validation.

After the final response, remain stopped unless the orchestrator continues your
session.
