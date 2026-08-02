Read the README.md file.
Read the entire LESSONS.md.

After reading the README, follow these agent-side working rules. README owns the
repo overview and source-of-truth model; this file owns actionable constraints,
heuristics, and blocker responses for agents.

## Non-negotiables

- The project is **function-first** and **exact-match-first**.
- The original EXE is the behavioral oracle. PDB/Ghidra/type dumps are reference
  metadata, not behavior oracles.
- Use repo-local `orig\...` inputs, especially
  `orig\original_full_game_files_rise_of_romes_beta_17_7_1998`, rather than
  sibling-repo paths.
- The pinned working compiler is the repo's configured **VC5 host toolchain**.
  Do **not** switch compilers during normal matching.
- Default flags are `config\flags\default.rsp` (`/nologo /c /O2 /Oy`).
- Exact promotion requires local validation with
  `python tools\check_function.py --va <VA>` and `Result: MATCH` / `0.0000%`.
- Positional byte equality is authoritative for exactness. Edit/resync diff is
  diagnostic only.
- The checker also enforces the original function boundary and known direct-call
  relocation identity. Entry-reachable rebuilt code past the original boundary
  or a call to the wrong external symbol is not an exact match even when old-style
  relocation masking would have hidden it.
- Inline asm is forbidden for real functions unless the user explicitly requests
  it. See the narrow padding-only exception below.
- High-confidence exclusions are listed in:
  - `config\parent_owned_fragments.txt`
  - `config\toolchain_supplied_functions.txt`
  - `config\toolchain_supplied_regions.txt`
  - `config\asm_special_functions.txt`
  - `config\asm_special_regions.txt`

## Corpus buckets and repo roles

Normal one-function C/C++ work applies only to the `normal` corpus bucket.
Excluded/non-independent buckets stay tracked but are not ordinary scratch/match
targets:

- `parent_owned_fragment`: real game-code blocks/switch arms/shared tails owned
  by a larger parent. Match them by matching the parent.
- `toolchain_supplied`: import thunks, CRT/runtime baggage, helper islands.
- `asm_special`: named handwritten assembly, for a future asm workstream.
- `asm_region`: handwritten-assembly/codelet/data-dispatch neighborhoods.

Repository roles:

- `inventory\...`: generated reference corpus; read-only in normal work.
- `include\...`: living shared compiler surface; edit conservatively.
- `src\game_globals.cpp`: shared global definitions; edit when facts stabilize.
- `src\scratch\...`: active or paused unresolved functions, one file per target.
- `src\accepted_drift\...`: reviewed localized behavior-equivalent non-exact
  functions; rare.
- `src\verified_logic\...`: behaviorally reconstructed functions promoted only
  after exact matching has genuinely stalled and repeated independent semantic
  reviews have converged with no substantive open finding.
- `src\matching\...`: exact validated finished functions.
- `logic_reviews\...`: versioned per-function ledgers for the logic-review phase;
  never use these ledgers as input to a blind first-pass review.
- `LESSONS.md`: shared pattern memory for generalized exact-match breakthroughs.

## Project status queries and target search

Use `python tools\query_project_status.py` for project-status questions and
function target searches. It computes status live from repo state; it does **not**
depend on stale `project_full_status.csv`. The CSV/HTML dashboard is mainly for
human browsing, not agent automation.

Use this tool instead of ad-hoc CSV parsing or manual `src\...` directory scans
when answering questions like "what is unclaimed?", "smallest remaining?",
"what is the status of this VA?", or "find functions matching these filters".
Common examples:

```bat
python tools\query_project_status.py --unclaimed --normal --smallest --no-blockers --limit 20
python tools\query_project_status.py --unclaimed --normal --no-blockers --unleased --smallest --triage --leases --limit 12
python tools\query_project_status.py --remaining --normal --smallest --limit 20
python tools\query_project_status.py --va 0047A3A0 --paths
python tools\query_project_status.py --source Pnl_pic.cpp --remaining
python tools\query_project_status.py --query set_picture --normal --paths
python tools\query_project_status.py --summary --normal
```

Useful filters include `--normal`, `--unclaimed`, `--scratch`, `--matching`,
`--accepted-drift`, `--verified-logic`, `--conflict`, `--remaining`,
`--logic-review`, `--logic-review-in-progress`, `--no-blockers`, `--blockers`,
`--source <file-or-path-substring>`, `--query <tokens>`, `--min-size`,
`--max-size`, `--smallest`, `--largest`, `--sort size|asm|va|name|source|bucket|diff|edit-diff|first-mismatch`,
`--paths`, `--notes`, `--unleased`, `--active-leases`, `--owner <agent>`,
`--leases`, `--triage`, `--json`, and `--csv`.

Use `--triage` before opening several large function packets. It parses compact
frame/EH/call/vslot/saved-register/PDB/decompiler evidence only for the rows left
after sorting and `--limit`. Inspect at most two or three promising complete
packets during target selection; do not dump eight or ten 50-KB packets into the
agent context merely to choose a target. Once a VA is assigned explicitly, skip
candidate shopping entirely.

If a human-readable dashboard is needed, run
`python tools\generate_status_dashboard.py` to rewrite `project_full_status.csv`
and `project_full_status.html`. Do not treat the generated CSV as the live source
of truth unless explicitly using `query_project_status.py --from-csv` for a
known stale/fast check.

## Default autonomous matching contract

When a user gives a short request such as `match 0043C2B0`, treat this section as
the complete default task contract; the user does not need to repeat it in the
prompt.

1. Read `README.md` and the complete `LESSONS.md` as required above. `AGENTS.md`
   is already injected into the agent system prompt; do not reread it through a
   file tool unless the user asks or the injected text is unavailable.
2. Preserve unrelated working-tree changes. Never clean/reset another agent's
   files.
3. Confirm the requested VA is a `normal` function and inspect its live status:
   `python tools/query_project_status.py --va <VA> --paths --notes --leases`.
   For an unassigned target search, use the compact `--triage` command above. If
   it is already exact in `src/matching`, validate/report rather than creating a
   second owner. If it is paused in `src/scratch`, read its attempt log and target
   session/history before proposing new experiments so prior negative evidence is
   not repeated.
4. Before editing, claim the target with a short unique owner name for this
   session and a default budget of **10 meaningful hypotheses**:
   `python tools/target_session.py start --va <VA> --owner <unique-owner> --budget 10`.
   Do not force-take an active lease. If the exact requested VA is leased by
   someone else, report the conflict unless the user explicitly authorizes a
   takeover.
5. Inspect the function packet, then run the dossier, donor ranking, and ABI
   evidence tools before broad declaration/layout archaeology:
   `target_dossier.py`, `find_function_donors.py`, and `query_abi.py`.
6. Create/edit only the living per-function source in `src/scratch` and use local
   type/global stubs until reuse and proof justify shared changes.
7. Record the first successful reconstruction check as `--kind baseline`, then
   record each interpreted source/type/layout/control-flow/context hypothesis via
   the integrated checker. Syntax/build repairs and unchanged reruns are not new
   hypotheses and are not probes:

   ```bat
   python tools/target_session.py check --va <VA> --owner <owner> ^
     --kind control-flow --note "specific hypothesis" -- --detail concise
   ```

   Do not pass `--no-build` before the target has a current built artifact. A
   compile/syntax repair is not a probe; rerun the same intended probe after the
   repair. `check_function.py` exits with status 1 for an ordinary completed
   mismatch, which some harnesses display as a command error; interpret the
   report, not that expected nonzero status. `target_session.py check` handles
   match and mismatch statuses correctly.

8. Treat the checker's `Workflow stage` as authoritative for what kind of work
   comes next. `STRUCTURAL RECONSTRUCTION` means fix size, ordered calls, CFG, and
   block topology before register coloring or broad variants. `EXACT CODEGEN`
   means focused source-shape work is appropriate. Do not override the checker
   stage merely because frame size or call counts happen to match.
9. Stop after 10 meaningful hypotheses by default, or earlier when exact, when a
   real ABI/layout blocker is identified, or when further variants would be
   blind. A source change that emits the same code as an earlier probe is useful
   negative evidence, but heed the session's `Codegen duplicate` notice and do
   not keep exploring the same compiler basin.
   This is a per-worker bound, not a declaration that the function is globally
   exhausted. Preserve enough evidence in the source attempt log for a later
   worker and the project orchestrator to avoid repeating the same hypotheses.
10. If exact, review source/flags, validate again, move (not copy) to
    `src/matching`, and validate after the move. If unresolved, leave the best
    state in `src/scratch` and write the compact attempt log **before** the final
    integrated validation. Record that unchanged final check with
    `--kind validation`, then pause with
    `target_session.py pause --va <VA> --owner <owner> --reason "..."` (`--note`
    is accepted as an alias). Validation must precede pause because checks require
    an active lease. The session tool rejects a pause when the current claim has
    recorded checks unless its latest check is a current `validation`; edits after
    validation make it stale and require another validation. Never use
    `accepted_drift` merely because the budget ended.
    An ordinary matching worker never promotes a target to `verified_logic` or
    starts semantic review on its own; that transition belongs to the designated
    project orchestrator after reviewing cumulative work from as many sequential
    matching assignments as it considers useful.
11. Report target, outcome, probe count, current/best metrics, changed files,
    validations, and the evidence-backed next lead. A bounded documented pause
    is a valid outcome; never force a fake match.

## Participant roles and shared-worktree conduct

The assigning prompt must give each subagent exactly one role. Do not silently
change roles during an assignment.

- **Matching worker:** edits one leased function under the bounded contract
  above. It may inspect prior attempts and history. It does not commit.
- **Phase-readiness auditor:** strictly read-only and unleased. It may inspect
  attempt logs, session/checker evidence, and Git history to judge cumulative
  matching exhaustion, but normally assesses at most two named functions.
- **Blind semantic reviewer:** strictly read-only and unleased. It must not read
  `logic_reviews`, Git history, prior reports, or harmlessness claims. It compares
  one candidate directly with the executable behavior oracle.
- **Main agent:** owns queueing, integration, ledger updates, status moves, and
  commits. Subagent output remains a proposal until main-agent validation.

All non-main participants preserve unrelated working-tree changes, avoid broad
shared-header edits, do not write compiler artifacts outside `build`, and do not
normalize an existing file's line endings. A worker must report any shared file
it touched. Read-only roles do not run source-shape experiments or checkers that
rewrite current build/history state unless the main agent explicitly authorizes
that narrow operation.

Concurrency, user-supplied model/thinking contracts, reviewer cohort sizing,
context limits, and integration order are defined in
`docs\main_agent_workflow.md` for the designated orchestrator.

Pi executes shell commands through Bash. In Bash command strings use forward
slashes such as `python tools/query_project_status.py`; unquoted Windows
backslashes can be consumed as escapes. Batch examples elsewhere in this file use
backslashes because they are written for `cmd.exe`.

## Parallel target sessions and evidence dossiers

When multiple agents share a working tree, claim a target before editing it:

```bat
python tools\target_session.py start --va 005204A0 --owner AgentName --budget 10
python tools\target_session.py list --active
python tools\query_project_status.py --remaining --normal --unleased --smallest --leases
```

The lease is advisory local state under ignored `build\target_sessions\`. Record
meaningful interpreted hypotheses with `target_session.py probe`, then pause or
release the lease when stopping. Compiler launches are not attempts by themselves;
one probe should correspond to one source/type/context hypothesis and its observed
effect. Keep durable conclusions in the scratch-file attempt log because session
state is not committed.

Probe kinds are `baseline`, `behavior`, `abi`, `layout`, `control-flow`,
`liveness`, `context`, `flags`, `variant`, `restore`, `validation`, and `other`. Use `baseline`
for the first compiled reconstruction, and `restore` for a deliberate rollback
rather than describing either as a new behavior hypothesis. Use `validation`
only for an unchanged final check after notes/documentation are complete.
Recorded `restore` and `validation` checks remain in history but do not consume
the meaningful-hypothesis budget.

Prefer the integrated checker wrapper so a completed check, checkpoint, input
hashes, emitted-code identity, duplicate-codegen detection, metric delta, and
probe note stay together:

```bat
python tools\target_session.py check --va 005204A0 --owner AgentName ^
  --kind liveness --note "direct member reload probe" -- --detail concise
```

For large, broad, or type-fragile targets, generate the binary-evidence dossier
before source-shape search:

```bat
python tools\target_dossier.py --va 005204A0
```

The dossier's calls and assembly accesses are evidence, but its `this` aliases,
generated names, and class-size comparison remain conservative hypotheses. Verify
them against original asm before changing a living layout. Entry-relative stack
coordinates are emitted only while stack adjustments and callee cleanup remain
provable; unknown rows are intentionally left unnormalized. See
`docs\agentic_matching_workflow.md`.

Before inventing a helper/global/class declaration, query exact-source donors and
generated reference provenance:

```bat
python tools\query_abi.py --symbol rge_read
python tools\query_abi.py --class TRIBE_Player
python tools\query_abi.py --global save_game_version
```

Exact matching source is strong codegen evidence, but a narrow local stub in one
exact function is not automatically canonical semantic ABI. The query tool never
auto-promotes declarations into shared headers.

For large/type-fragile functions, rank exact donors before inventing another TU or
class surface:

```bat
python tools\find_function_donors.py --va 004407A0 --limit 20
```

Donor scores are discovery heuristics, not proof of shared source or canonical
ABI. Same-TU and same-class exact donors deserve inspection; low-weight raw
displacement overlap does not prove common fields.

Call **count/target-multiset parity is not ordered call-site parity**. Before
saying the call set is aligned, inspect the session/checker call similarity and
`delete`/`insert`/`replace` site counts. A report such as `47/47` with `-2/+2`
site gaps is still structurally unresolved. Use
`check_function.py --call-map-unmatched` and the dossier/PDB evidence bands to
locate those gaps before tuning entry registers.

## Normal function workflow

1. If choosing a target, use `python tools\query_project_status.py` and usually
   pick from `--unclaimed --normal --no-blockers`; avoid non-normal buckets.
2. In a shared agent workspace, claim the VA with `tools\target_session.py` before
   editing. For a large/broad target, generate `tools\target_dossier.py --va <VA>`.
3. Read the function packet in `inventory\functions\...`.
4. Check relevant shared headers/source and generated type/class/global reference.
5. Implement or edit one per-function source in `src\scratch\...`.
6. Compile and compare with `tools\check_function.py`.
7. Fix missing shared facts only when stable/reusable; otherwise keep local stubs.
8. Iterate source shape, layout, declarations, and context until exact or clearly
   paused with notes.
9. Record meaningful agent probes in the target session and durable conclusions in
   the source attempt log. Pause/release the target session when stopping.
10. When a non-obvious reusable insight makes a function click, append the compact
   generalized lesson to `LESSONS.md`.
11. Promote to `src\matching\...` only after local exact validation. This is a
   move, not a copy; a VA must have exactly one compiler-facing owner.
12. Use `src\accepted_drift\...` only for rare reviewed localized equivalent
   drift, preserving the full attempt log and adding an `ACCEPTED_DRIFT` note.
13. Only the designated project orchestrator may enter the separate logic-review
   workflow or promote to `src\verified_logic\...`; ordinary matching workers
   stop with a validated, documented scratch state.

When assigned a whole PDB translation unit, do not call it exhausted just because
one function is large/EH-framed/sticky. Give every tractable function a real pass;
clear small helpers/wrappers first; leave only meaningful holdouts in scratch with
compact notes.

## Variant lab workflow

`tools\variant_lab.py` is now a normal and encouraged part of matching work for
**stubborn, unexpected VC5 codegen mismatches** once the function has reached a
reasonable parity point.

Use it when:

- behavior, call set, stack cleanup, and touched layout are understood;
- the remaining mismatch is localized or clearly a stable codegen-family problem;
- many semantically equivalent source spellings collapse into a few signatures;
- edit/resync diff suggests shifted alignment around a small hunk;
- you need to probe natural source axes systematically.

Do not use it to hide basic unknowns. Poor candidates: unclear behavior, wrong
call set, wrong stack cleanup, broad control-flow mismatch, obviously wrong
struct/class size, or missing real shared global/type facts. Fix those first.

Practical rules:

- Avoid blind whole-function Cartesian sweeps. Prefer focused labs on localized
  gates, call sites, temps, or block-shape regions once those regions are understood.
- For nontrivial labs, write a template under `build\temp\...tpl.cpp` rather
  than embedding giant shell/Python strings.
- Reusable preset packs live in `config\variant_templates\*.vtpl`; each starts
  with a concise `// TEMPLATE ...` metadata comment.
- `python tools\variant_lab.py --help` is the concise reference.
- Variant labs may try thousands/tens of thousands of variants, but the axes
  should be deliberate and documented by the template/attempt log.
- One deliberate variant-lab run is one meaningful `variant` hypothesis family,
  regardless of how many generated cases it compiles. During a leased agent
  session pass `--session-owner <owner>` so the lab records that probe
  automatically; do not run unrecorded labs around the budget.
- `--preview-variants N` prints compact labels/sizes/hashes. Add `--preview-full`
  only when complete generated sources are truly needed; use `--show-variant`
  for one specific full expansion.
- Do not auto-promote from a lab result. Review the winning source, reduce any
  context, then validate normally with `check_function.py`.
- For localized late-stage labs, use `--focus-range` and hard gates such as
  `--require-size --require-frame --require-call-set`. Gated variants are still
  whole-function compiles; ineligible groups remain visible but rank after groups
  that preserve the requested invariants. COFF relocation symbol identity is part
  of call-set grouping/gating.

## Type/global policy: local first, exact layout always

Current phase bias is match harvesting, not broad class cleanup.

- Start with local stubs for one-function/speculative facts.
- Promote types/classes to `include\game_types.h` only when reuse or cluster
  unlocking value justifies it.
- Promote globals to `include\game_globals.h` / `src\game_globals.cpp` when the
  location/type is stable and likely reused.
- Do not create per-function headers or parallel scratch-vs-matching headers.

Local-first does **not** mean approximate-layout-first. If the packet, original
asm, PDB/type dump, or Ghidra proves an offset, size, vptr, base boundary, field
width, or `sizeof`, model that fact immediately in the local or shared surface
before chasing code-shape variants. Use explicit `gap_XX` / `pad_XX` arrays
liberally. Preserve base-vs-derived ownership in constructors/destructors when it
affects vptr stores, EH state, base ctor/dtor lowering, offsets, or `sizeof`.

Use generated reference material as lookup, not truth:

- `inventory\types\...`: names/layout candidates.
- `inventory\classes\...`: best-effort class/method/slot donor info.
- `inventory\globals\...`: global candidates.

If generated reference is wrong or incomplete, fix the living working headers or
local source, not the generated inventory.

## Matching heuristics: general VC5 axes

Prefer small controlled probes once behavior is close. If the first mismatch moves
deeper, treat that as a lead. Revert failed probes but record useful negative
evidence in the file's attempt log.

### Natural source and control flow

- Prefer the simplest natural source family a real programmer likely wrote before
  decompiler-shaped plumbing. Ordinary control flow, member calls, constructors,
  destructors, `delete`, library calls, and aggregate assignments often land in a
  better VC5 basin than raw stores, fake helpers, forced gotos, or temporary-heavy
  decompiler scaffolding. Treat natural source shape as the default hypothesis:
  make lower-level or decompiler-shaped source earn its keep by moving the diff
  deeper or matching a binary-observed effect. When chasing variants, periodically
  stop and review the source as source: ask whether a human would likely have
  written it that way, or whether you are preserving decompiler artifacts.
- Use PDB line-change info to localize the mismatch region. If the first
  mismatch lives in one early source-line band, treat later line bands that
  already map cleanly as provisionally solved and stop churning them.
- Do not trust decompiler source order/factoring. If blocks or switch arms are
  behaviorally right but layout/tail-sharing is sticky, inspect original block
  placement and try source/order changes without changing block bodies.
- Semantically equivalent control-flow forms are not codegen-neutral. Probe direct
  return vs explicit branch, nested `if` vs early return, `if/else` arm order,
  switch/case order, and expression-style boolean vs 0/1 branches. For guarded
  success paths, also probe positive combined predicates (`state < 3 && state > -1`)
  versus early negative returns; VC5 can change frame size and tail layout based on
  whether the source names a result local or returns directly from each arm.
- In VC5, `switch` and `if/else if/else` produce fundamentally different block layout
  for the same dispatch logic. A two-case dispatch with default that uses `je`
  (jump-to-handler: else inline, cases at end) in the original will likely be a
  `switch` statement. `if/else if/else`, independent `if+return`, and `goto` all
  produce `jne`-skip layout (cases inline, else at end) even though they are
  semantically equivalent. If you see `je` dispatch branches targeting code after
  the function's main epilogue, try a `switch` before reaching for complex
  control-flow hacks.
- Do not over-force shared tails with `goto` just because asm has shared-looking
  epilogues. Natural nested `if`/`switch` can still produce the same tails; forced
  top-declared-local/goto plumbing can perturb branch distances, liveness, and
  block layout.
- If deleting or reordering a late block fixes an early prologue/frame/register
  mismatch, treat that as a whole-function pressure-threshold clue, not proof that
  the late block order or behavior is wrong. Look for artificial long-lived temps,
  saved object pointers, assignment-in-condition results, or helper/declaration
  surface mistakes that increase liveness across the function.

### Temporaries, liveness, and access shape

- Named temps are not neutral. Extra predicate temps, split loop locals, copied
  offsets, or saved object-graph pointers can change saved-register choice and
  liveness.
- Treat writes to incoming parameter stack slots as a source-shape clue, not just
  decompiler noise. VC5 may reuse dead parameters as scratch locals, especially
  narrow byte parameters used for row/column/modulo-style temporaries. If original
  asm stores into `[esp+param]` and later reloads it, try assigning back to the
  source parameter (`param_1 = rows; ... param_1 = remainder;`) before introducing
  separate clean locals. Fresh locals can be behaviorally identical but still
  perturb saved-register allocation and divisor/remainder registers.
- Distinguish direct member access, early-declared/late-initialized locals, and
  immediate locals. VC5 often treats them differently.
- When original asm repeatedly reloads `scenario`, `player`, `object`, or
  `target`, avoid preserving that pointer early. Use direct member access or
  delay locals until the asm first preserves them.
- Conversely, if asm clearly carries one pointer through a phase, try one shared
  local carrying that object through destroy/recreate or old/new use.
- A temp can make VC5 prove away a reload/recheck the original kept. For redundant
  member tests or later virtual calls, try a fresh direct member access.
- Decompiler-introduced predicate/result locals are especially suspect in `||` / `&&`
  chains. If a call result is used only for truth testing (`!= 0`, pointer/nonzero)
  and the original asm does not preserve that pointer/value for later use, try the
  natural direct-predicate spelling (`if (call(a) || call(b) || ...)`) instead of
  assignment-in-condition or reusable result-local forms. This can remove artificial
  liveness that changes saved-register choice, hidden `this` homes, and frame size
  in large VC5 functions. Do not apply blindly when the result value is consumed
  later.
- For loops/scans, mirror state topology: one running iterator plus one saved
  boundary/start local often beats decompiler-style many-local forms. When two
  sequential loops in one function reuse the same source iterator in the original,
  prefer one shared local declared outside both loops over separate `for (short i ...)`
  declarations; the latter can add a stack slot and shift every frame offset.
  Conversely, block-scoping an inner loop local around multiple adjacent loops can
  keep an outer loop index in the original slot while moving the reused inner
  iterator/name-length temp pair into the expected VC5 debug-frame slots.

### Expression and arithmetic shape

- Probe statement order, compare operand order, and expression term order. Even
  commutative arithmetic is not neutral: `dst = a + b` versus `dst = b + a` can
  change which operand VC5 keeps live, whether it introduces/saves a register such
  as `esi`, and whether a tiny helper lands at the exact size. If original asm
  saves an otherwise surprising register around an expression, try swapping the
  source operand order before reaching for lower-level rewrites. For
  bounds checks, algebraically identical source such as `member < param`,
  `param > member`, `param <= member`, and `member >= param` is not neutral: VC5
  may reload operands in a different order and choose different compare registers.
  If original asm loads/tests the parameter first and then reloads `this`/member,
  try spelling the second check with the parameter on the left (for example
  `param_1 > this->count`) rather than the member on the left (`this->count < param_1`).
- Stack spills inside math often indicate an anonymous temporary from one larger
  expression, not a durable named local; try inlining the math back into the
  parent expression.
- Interleaved integer/FPU code often points to one larger statement or nested
  expression tree.
- Compound spelling matters: `x += y`, `x = x + y`, direct assignment, and helper
  call/inlining can land in different basins.
- Preserve original compare algebra where visible, e.g. `index + 1` checks versus
  equivalent `index < length` checks. For FPU comparisons, also probe logically
  inverted source (`!(a < b)`, `a <= b`, `b > a`) because VC5's `fcomp`/`fnstsw`
  branch polarity and block placement can flip even when the C condition is
  semantically identical.

### Widths, parameters, and return values

- Treat parameter width/signedness and return width as codegen axes for tiny
  helpers. `char`, `unsigned char`, `short`, and `int` spellings can change load,
  mask, test, and shift sequences.
- Declared parameter width and later stack-slot access width can differ. A narrow
  parameter may still need a later wider stack-slot reload/sign-extension such as
  `*(short*)&param` to match `movsx ..., word [esp+...]`.
- If original tests `al`/`dl` but rebuilt tests `eax`/`edx`, probe narrower callee
  return surfaces.

### Object, virtual call, and lifetime surface

- Prefer real typed member calls over fake C helper wrappers. Fake helpers can
  preserve behavior while changing argument order, stack shape, and scheduling.
- For IAT-resolved calls, prefer `extern` function pointers over
  `__declspec(dllimport)` when the original uses indirect `call dword [addr]`.
- In constructors/destructors, object surface is codegen context: base size,
  visible virtual destructors, real `delete`, vptr ownership, and member-call
  declarations can decide EH/vptr lowering.
- If a destructor's vtable restore is ordered wrong, try natural class/destructor
  declarations instead of a manual vtable store.
- In small `new` helpers, verify `sizeof(T)` early; wrong local stub size often
  appears as the wrong `operator new` size.
- Prefer explicit source for compiler-looking helpers (deleting destructors,
  vector deleting destructors, tiny virtual wrappers) unless hidden synthesis is
  strongly indicated. Explicit source is easier to validate and control.

### TU/header/flag context

- Treat translation-unit context as a normal matching axis. Nearby declarations,
  visible special members, and even small CRT headers such as `<stdlib.h>` can
  change VC5 codegen.
- Prefer likely donor-file or cluster-local include context over repo-wide header
  piles. If context wins, reduce to the smallest proven reproducer and document
  why it remains.
- `/GX` is a legitimate donor-file/cluster hypothesis when original asm shows EH
  registration, unwind-state slots, constructor/destructor cleanup tracking, or
  nearby functions only match with `/GX`. Do not spray it randomly.
- Custom per-function flags are last-resort exceptions, not a substitute for
  source/type/layout fixes. Re-test without them before keeping a finished flag
  file. However, some no-PDB/debug-basin leftovers in this corpus genuinely match
  only with `/Od`; when original asm has an EBP frame, `push ecx`/small local slots,
  no frame-pointer omission, and very direct source-line-style codegen, test a
  narrow `/Od` response file and document why it remains.

### Data/helper surface

- Prefer natural typed surfaces before raw-buffer tricks: real structs, API
  structs, aggregate assignment, direct fields, `memset`, `strcpy`, etc.
- Lower-level-looking source is not necessarily closer. Manual byte stores and
  pointer casts often produce worse VC5 basins than high-level typed/helper forms.
- For fixed parameter blocks and small copies/stores, test whole-struct or helper
  forms early, then keep the smallest exact-friendly surface.

## Diff diagnostics

`check_function.py` and dashboard output include positional and edit/resync
metrics. Exactness still requires positional equality / `Result: MATCH`.

Use edit/resync diagnostics for triage:

- tiny edit diff plus large positional diff usually means a shifted alignment;
  focus near the first insert/delete/replace hunk;
- positional diff remains the promotion authority;
- edit diff is a guide to localize experiments, not a claim of equivalence.

## Scratch, accepted drift, verified logic, and matching

Status meanings:

- `src\scratch\...`: active or paused unresolved function.
- `src\accepted_drift\...`: rare reviewed localized non-exact but
  behavior-equivalent VC5 drift.
- `src\verified_logic\...`: independently reviewed semantic reconstruction after
  exact matching was deliberately suspended; broader codegen drift may remain.
- `src\matching\...`: exact validated match only.

It is okay to leave a function in scratch when the remaining mismatch is
localized and specifically understood, meaningful source/layout/context/flag work
has been tried, call boundaries and memory effects look correct, and the top notes
plainly summarize the gap. Do not use scratch notes as a sidecar; the file is the
notebook.

Accepted drift requires all of the above plus a manually reviewed non-zero diff
that is low-risk and behavior-equivalent, such as benign register choice, merged
epilogues, harmless block-layout drift, or equivalent address encoding. Do not use
accepted drift for changed predicates, calls, stack cleanup, memory effects, copy
sizes, virtual dispatch, or broad unexplained drift. Folder placement is the only
status marker; no separate manifest.

Verified logic is a different and more demanding semantic-review workflow, not a
place to move functions merely because matching is difficult. The full process is
owned by the designated main agent and documented in
`docs\main_agent_workflow.md`. Promotion requires a per-function ledger under
`logic_reviews\`, repeated fresh read-only review cohorts, evidence-backed
adjudication of every substantive finding, direct main-agent integration of
bounded fixes, and no open behavioral uncertainty. The original executable is
the oracle, including its bugs, odd edge cases, unintended side effects, and
incorrect-looking formulas.

When assigned as an independent logic reviewer:

- do not edit any file, claim a target, run source-shape experiments, or make a
  status move;
- do not inspect `logic_reviews\`, Git history, prior reviewer reports, or claims
  that a difference is harmless;
- compare the candidate directly with original binary evidence and report
  definite differences, plausible concerns, verified assumptions, and areas that
  could not be established;
- treat comments, decompiler output, PDB metadata, and intended game behavior as
  hypotheses; only the original executable is the behavior oracle.

## Attempt logs and comments

Scratch and accepted-drift files keep compact attempt-log comments near the top.
Verified-logic files retain the complete matching attempt log too; it is the
durable evidence used to decide that exact matching had genuinely stalled. The
separate logic-review ledger records semantic reviews and adjudications rather
than replacing or deleting the matching attempt log.

Append factual one-probe notes:

```c
// tried inlining the temp; mismatch moved deeper to 00401A2C
// reversed add order; first mismatch is now the compare
// rolled back named base temp; no register change
// left in scratch: remaining drift is first-arg register allocation
```

Good notes say what was tried, kept/rolled back, observed effect, and whether the
clue is local/global. `FLAGS:` is optional and only for an actual custom response
file. Code-explanatory comments inside function bodies may stay when they explain
binary-observed behavior or intentional weird source shape.

## Shared lessons

`LESSONS.md` is the project's shared pattern memory. It exists to simulate the
human learning loop: as agents match more functions, they should notice what made
VC5 emit the expected assembly and preserve those reusable eureka moments for the
next agent.

When a function finally matches because of a non-obvious insight, especially a
stubborn match after many iterations, append a compact generalized note to
`LESSONS.md`. Record lessons about source shape, control flow, temporaries,
liveness, declaration/type/layout facts, include or flag context, helper surfaces,
or variant-lab findings that are likely to help future matching work.

Do not use `LESSONS.md` as a per-function attempt log or victory diary. Keep the
local blow-by-blow in the scratch/accepted-drift/verified-logic source file. In `LESSONS.md`,
abstract the lesson away from the specific function: explain the reusable pattern,
when to try it, why it changes VC5 codegen, and any caveats. Mention function
names or VAs only as optional evidence.

If a lesson later proves broadly important and stable, promote or summarize it in
`AGENTS.md`; otherwise leave it in `LESSONS.md` as field knowledge.

## Inline asm policy

Inline asm is forbidden for real functions unless the user explicitly requests it:
`__asm`, `_asm`, `__declspec(naked)`, handwritten wrappers, or any raw-asm source
hack to force a match.

Narrow exception: padding-only pseudo-functions may use inline asm-like filler
only when the entire body is non-behavioral padding (`nop`, repeated `nop`,
`mov edi, edi`, `mov eax, eax`, simple combinations), has no memory effect, no
real control flow/calls, and ordinary source cannot reasonably express the exact
bytes. No real function may be promoted with inline asm.

If a real function seems to need inline asm, the source model is still wrong or
incomplete. Investigate source shape, declaration context, types, or flags; if no
lead remains, leave it in scratch with clear notes.

## Non-normal manifest work

Do not create scratch, accepted-drift, verified-logic, or matching files for
entries classified into non-normal buckets. For duplicated generic helper labels
inside known CRT/helper islands,
prefer region manifests over brittle name lists. Use
`tools\generate_toolchain_supplied_manifest.py` for safe exact-name toolchain
extraction and hidden-label reports.

Review queues, not auto-approval lists:

- `build\toolchain_hidden_label_safe_candidates.tsv`
- `build\toolchain_hidden_label_unhandled_candidates.tsv`
- `build\toolchain_probable_helper_island_candidates.tsv`

If a classification is wrong, fix it deliberately; do not casually remove entries
from exclusion manifests.

## Orchestrator promotion review

If reviewing child-agent or branch-local work before it lands in the main tree,
do not trust a reported match blindly. Read each incoming `.cpp` and paired
`config\flags\...rsp`, verify repo rules and no forbidden inline asm/hacks, then
run local `check_function.py --va <VA>` before promotion. Promotion is a review
decision, not a blind move.

## Error handling mindset

React pragmatically:

- missing declaration: add the smallest safe local/shared declaration;
- bad generated type: correct the working type surface;
- missing global: add local first or promote when stable;
- compile failure: narrow and fix the smallest correct surface;
- generated scaffold mismatch: treat scaffold as a first-pass candidate, not
  authority; improve the living working source rather than preserving bad output;
- mismatch: trust binary-observed behavior over prettier source;
- ordinary mismatch: assume source/type/layout/context is still wrong before
  reaching for flags or hacks;
- when a non-obvious exact-match lesson is reusable, append it to `LESSONS.md`
  instead of leaving it as session-only memory; promote it into these rules only
  after it proves broadly important and stable.

Final mental model:

- `inventory\...` = generated reference
- `include\...` + `src\game_globals.cpp` = living shared source
- `src\scratch\...` = active/paused unresolved work
- `src\accepted_drift\...` = reviewed localized equivalent non-exact drift
- `src\verified_logic\...` = independently verified reconstructed behavior,
  still non-exact
- `src\matching\...` = exact validated finished bank
- `logic_reviews\...` = full per-function semantic-review history
- `LESSONS.md` = shared generalized memory of matching breakthroughs
