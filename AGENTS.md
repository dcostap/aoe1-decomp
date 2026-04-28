Read the README.md file.

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
- `src\matching\...`: exact validated finished functions.

## Normal function workflow

1. If choosing a target, regenerate `project_full_status.csv` and usually pick
   from `unclaimed`; avoid non-normal buckets.
2. Read the function packet in `inventory\functions\...`.
3. Check relevant shared headers/source and generated type/class/global reference.
4. Implement or edit one per-function source in `src\scratch\...`.
5. Compile and compare with `tools\check_function.py`.
6. Fix missing shared facts only when stable/reusable; otherwise keep local stubs.
7. Iterate source shape, layout, declarations, and context until exact or clearly
   paused with notes.
8. Promote to `src\matching\...` only after local exact validation. This is a
   move, not a copy; a VA must have exactly one compiler-facing owner.
9. Use `src\accepted_drift\...` only for rare reviewed localized equivalent
   drift, preserving the full attempt log and adding an `ACCEPTED_DRIFT` note.

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

- Large functions are not automatically excluded. Avoid blind whole-function
  Cartesian sweeps on them, but use focused labs on localized gates, call sites,
  temps, or block-shape regions once those regions are understood.
- For nontrivial labs, write a template under `build\temp\...tpl.cpp` rather
  than embedding giant shell/Python strings.
- Reusable preset packs live in `config\variant_templates\*.vtpl`; each starts
  with a concise `// TEMPLATE ...` metadata comment.
- `python tools\variant_lab.py --help` is the concise reference.
- Variant labs may try thousands/tens of thousands of variants, but the axes
  should be deliberate and documented by the template/attempt log.
- Do not auto-promote from a lab result. Review the winning source, reduce any
  context, then validate normally with `check_function.py`.

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
  better VC5 basin than raw stores, fake helpers, or forced gotos.
- Use PDB line-change info to localize the mismatch region. If the first
  mismatch lives in one early source-line band, treat later line bands that
  already map cleanly as provisionally solved and stop churning them.
- Do not trust decompiler source order/factoring. If blocks or switch arms are
  behaviorally right but layout/tail-sharing is sticky, inspect original block
  placement and try source/order changes without changing block bodies.
- Semantically equivalent control-flow forms are not codegen-neutral. Probe direct
  return vs explicit branch, nested `if` vs early return, `if/else` arm order,
  switch/case order, and expression-style boolean vs 0/1 branches.
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

### Temporaries, liveness, and access shape

- Named temps are not neutral. Extra predicate temps, split loop locals, copied
  offsets, or saved object-graph pointers can change saved-register choice and
  liveness.
- Distinguish direct member access, early-declared/late-initialized locals, and
  immediate locals. VC5 often treats them differently.
- When original asm repeatedly reloads `scenario`, `player`, `object`, or
  `target`, avoid preserving that pointer early. Use direct member access or
  delay locals until the asm first preserves them.
- Conversely, if asm clearly carries one pointer through a phase, try one shared
  local carrying that object through destroy/recreate or old/new use.
- A temp can make VC5 prove away a reload/recheck the original kept. For redundant
  member tests or later virtual calls, try a fresh direct member access.
- For loops/scans, mirror state topology: one running iterator plus one saved
  boundary/start local often beats decompiler-style many-local forms.

### Expression and arithmetic shape

- Probe statement order, compare operand order, and expression term order.
- Stack spills inside math often indicate an anonymous temporary from one larger
  expression, not a durable named local; try inlining the math back into the
  parent expression.
- Interleaved integer/FPU code often points to one larger statement or nested
  expression tree.
- Compound spelling matters: `x += y`, `x = x + y`, direct assignment, and helper
  call/inlining can land in different basins.
- Preserve original compare algebra where visible, e.g. `index + 1` checks versus
  equivalent `index < length` checks.

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
  file.

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

## Scratch, accepted drift, and matching

Status meanings:

- `src\scratch\...`: active or paused unresolved function.
- `src\accepted_drift\...`: rare reviewed localized non-exact but
  behavior-equivalent VC5 drift.
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

## Attempt logs and comments

Scratch and accepted-drift files keep compact attempt-log comments near the top.
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

Do not create scratch/matching files for entries classified into non-normal
buckets. For duplicated generic helper labels inside known CRT/helper islands,
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
- when a non-obvious exact-match lesson is reusable, update these rules instead
  of leaving it as session-only memory.

Final mental model:

- `inventory\...` = generated reference
- `include\...` + `src\game_globals.cpp` = living shared source
- `src\scratch\...` = active/paused unresolved work
- `src\accepted_drift\...` = reviewed localized equivalent non-exact drift
- `src\matching\...` = exact validated finished bank
