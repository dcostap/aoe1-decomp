Read the README.md file.

After reading the README, follow these working rules.

## Doc split

- `README.md` owns the general repo model: purpose, structure, workflow, and
  source-of-truth policy for humans and agents alike.
- `AGENTS.md` owns actionable agent-side rules: how to work, what to try, what to
  avoid, and how to respond to matching blockers.
- Do not duplicate README guidance here unless the repetition adds a concrete
  agent-only constraint or heuristic.

## Core model

- The project is **function-first** and **exact-match-first**.
- The original EXE is the behavioral oracle.
- PDB/Ghidra/type dumps are metadata/reference sources, not behavior oracles.
- Use the repo-local `orig\...` inputs instead of sibling-repo paths when a script needs the pinned EXE/PDB/Ghidra/type-dump side.
- Agents are expected to improvise, react to errors, and correct earlier bad assumptions as they learn more.
- The pinned working compiler is the repo's configured **VC5 host toolchain**.
- Do **not** switch compilers during normal matching work just because something
  does not match.

## Repository roles

- `inventory\...`
  - generated reference corpus
  - read-only in normal agent work
  - do not hand-edit these files just to fix one function
- `include\...`
  - shared working compiler surface
  - editable
  - this is where shared type/global understanding evolves
- `src\game_globals.cpp`
  - shared working global definitions
  - editable
- `src\scratch\...`
  - active per-function work area
  - this also holds understood-but-still-nonmatching functions
  - create or edit one file per target function here
- `src\matching\...`
  - finished bank
  - only promote a function here after local exact-match validation passes

## Current phase bias: local-first type work

The current phase is **match harvesting**, not broad type cleanup.

That means:

- default to **local stubs** inside the active function source,
- promote **globals** into shared headers/source when they are clearly real shared program state,
- promote **types/classes** into `include\game_types.h` only when reuse or cluster-unlocking value clearly justifies it,
- do **not** spend time trying to build a definitive class just because one function revealed one more field or method.

Practical rule:

- one function needing one partial class view -> keep it local,
- repeated use across multiple functions -> consider promoting it,
- broad class reconstruction -> save it for a later convergence phase.

## Normal workflow for one function

1. If choosing a new target, regenerate `project_full_status.csv` first and usually
   pick from the `unclaimed` bucket there instead of guessing from the raw dump.
2. Read the relevant packet in `inventory\functions\...`.
3. Check the shared working headers/source in `include\...` and `src\game_globals.cpp`.
4. Create or edit the function in `src\scratch\...`.
5. Compile and compare against the original.
6. If compilation or matching work exposes missing shared facts, update the shared working layer.
7. Keep iterating until the function matches.
8. If a function remains non-exact after meaningful investigation, keep it in `src\scratch\...` and make the file's top attempt log summarize the remaining gap clearly.
9. Remove scratch-only workflow notes when done.
10. Move the function to `src\matching\...` only after it is locally validated.

### Exact-match iteration heuristics

When a function is close but sticky, use these heuristics before escalating to
toolchain panic or stepping away from the function:

1. If the first mismatch moves deeper, treat that as a real lead and re-anchor on the
   new mismatch.
2. Assume semantically equivalent source may still produce very different VC5 codegen.
3. Explicitly probe named temps versus anonymous/inlined expression shapes.
4. Explicitly probe statement order, compare operand order, and expression term order.
5. Re-check local struct/class stubs when a late mismatch survives after control-flow
   issues are fixed.
6. Revert failed probes, but remember them as negative evidence in notes or docs.
7. Prefer a sequence of small controlled probes over large rewrites once the function
   is size-correct and behaviorally close.
8. Do **not** trust decompiler source ordering or factoring by default. If a
   function is behaviorally right but still has stubborn block-layout or
   tail-sharing drift, inspect the original object layout, block placement, and
   jump-table landing order, then try reordering the source **without changing
   the bodies** of the affected blocks/arms/cases. A real exact-match win now
   backs this: matching the original lexical order (`4, 6, 3, 1`) solved a
   sticky VC5 tail-sharing mismatch that multiple control-flow and
   expression-shape tricks did not.
9. Treat **translation-unit context** as a normal matching axis, not a weird
   last resort. For VC5, nearby declarations/definitions, header state, and even
   small CRT includes can change codegen for tiny helpers.
10. When a function is sticky, cycle **likely original-file include context**
   alongside code-shape probes. If the function came from a known donor `.cpp`,
   try the basic includes that file likely used even when the tiny function body
   does not textually need them. Re-test includes as the source shape changes,
   because the winning include/body combination can move together.
11. Probe context deliberately, not randomly, and prefer donor-file or
   cluster-local include baselines over repo-wide catch-all header sets. Then
   reduce any winning context back down to the smallest proven reproducer.

#### VC5-specific expression-shape hints

These are heuristics, not laws, but a real exact-match win now backs them:

1. Stack spills like `[esp+XX]` inside a math block often point to an **anonymous
   temporary from one larger expression**, not a durable named local. If a value is
   computed, spilled, other work happens, and it is immediately reloaded, try
   deleting explicit locals and inlining the math back into the parent expression.
2. Interleaved integer/FPU code often points to **one larger statement or tightly
   nested expression tree**, not several clean semicolon-separated steps. If the
   original asm mixes `fld` / `__ftol` / integer arithmetic before the final
   accumulation, test a more inlined source shape.
3. The final `add` / `lea` chain often reflects the source AST closely enough to
   probe **textual term order**. If the original adds `distance + y` before folding
   in `x`, test that exact `+` ordering in the source instead of assuming the
   compiler will normalize it.
4. If the math is behaviorally right but register allocation keeps thrashing, make
   “remove named temporaries and inline the expression” an early probe, not a last
   desperate guess.

#### VC5-specific tiny-helper / address-return hints

These are also heuristics, but a long stubborn `DString::operator[]` investigation
backed them hard enough to make them reusable:

1. If a tiny helper returns an address-like result and the original asm clearly
   carries an **integer offset/index** through the checks and into the final
   address formation, prefer source that selects or preserves that **offset**,
   not source that selects between two pointers/results. In practice this means
   “pick `0` or `index`, then index with it” often lands in a better VC5 basin
   than “pick `base` or `base + index` and return that”.
2. For that same class of tiny helpers, keep the **base/member access direct** as
   long as possible. A named `base` temp, even a `const` one, can kick VC5 into a
   different family with earlier base loads, extra pushes, and worse register
   choices.
3. Once a tiny helper is in a promising basin, be suspicious of named compare
   temps like `bound`, named `length` temps, copied-offset locals, and boolean
   success flags. In a real case they reliably ejected the function from the best
   basin even though the logic stayed the same.
4. Preserve the original compare **algebra**, not just the meaning. If the target
   wants an `index + 1` style compare, do not assume `index < length` or another
   simpler equivalent check is an improvement. VC5 may treat those as different
   basins with different register allocation and branch layout.
5. If dozens of source spellings collapse into only a few exact code signatures,
   stop treating it as ordinary decomp churn. That is a sign you are looking at a
   **codegen-family problem**, not a missing random spelling. At that point,
   switch from ad-hoc rewrites to classification, harnessing, and context/toolchain
   archaeology.
   
   Important policy: this kind of variant-generation lab / harness work is a
   **last-resort escalation**, not normal function iteration, and agents should
   use it only with **explicit user permission**.
6. For this pathology class, final-expression sugar is often low value once the
   correct basin is found. If `base[index]`, `*(base + index)`, `off[base]`,
   address-of wrappers, trivial casts, and `+0`/`-0` all collapse to the same
   bytes, treat that whole family as exhausted and move the investigation up a
   level.
7. If a tiny helper looks source-correct but only lands in the right codegen
   family inside a fuller donor-style translation-unit context, it is okay to
   reconstruct that local TU context **inside the same per-function file**.
   Practical rule: keep the target function's definition **lexically first** so
   the repo's current object extractor still sees the target bytes at the front
   of the concatenated `.text` output, then place the donor-like neighboring
   declarations/definitions after it.
8. If fuller TU context unlocks a match, do a reduction pass instead of assuming
   the whole donor context is truly required. A real `DString::operator[]` win
   later collapsed from a fuller donor-style TU down to a tiny local stub plus a
   CRT header include; the rest of the donor file was removable.

#### VC5-specific TU / header-context hints

These are broader than one helper class and should be treated as reusable
matching guidance:

1. Do **not** assume a semantically unused-looking include is codegen-neutral.
   On VC5, even a small standard header such as `<stdlib.h>` can change the
   front-end or optimizer enough to move a tiny function into a different codegen
   family.
2. Prefer the **likely include baseline of the original donor file** before you
   invent ad-hoc context. If several matched functions come from the same source
   file cluster, it is reasonable to reuse that cluster's basic include context.
3. When a tiny function is behaviorally right but trapped in a small set of
   stable signatures, probe minimal context changes on purpose: nearby class
   declarations, adjacent tiny methods, and one header/include change at a time.
   Re-test those include choices as the body shape changes; include/body coupling
   is real on VC5.
4. Do not cargo-cult random includes across the whole repo. Prefer donor-file or
   cluster-local include baselines over a universal catch-all header pile.
5. If a header or donor-style context change wins, keep the **smallest matching
   context** you can prove. Reduction is part of the solve, not optional cleanup.
6. Once a minimal context dependency is proven, preserve it even if it looks
   cosmetically unnecessary. Exact-match context is part of the source model.
7. When documenting a context win in a scratch or matching file, explain the
   preserved context in plain language so later agents do not delete it as
   “unused cleanup”.

## When it is okay to leave a function in `scratch`

Agents may stop active iteration and leave a function in `src\scratch\...` only when **all** of the following are true:

1. The mismatch is **localized and specifically understood**.
2. Source-shape and plausible flag/toolchain exploration have been meaningfully attempted; this is not just the first failed draft.
3. Calling convention, stack cleanup, call boundaries, and obvious externally visible behavior still look correct.
4. The remaining difference is judged **low-risk codegen drift**, such as merged epilogues, harmless register choice drift, or benign block-layout drift.
5. The remaining difference is **not** a changed predicate, changed call set, changed memory effect, changed copy size, or another behavior-sensitive divergence.
6. The file's top notes use the same compact attempt-log style used everywhere else, and the remaining gap is summarized there in plain language.

## Attempt-log comments in scratch files

There is **no separate sidecar notebook**.

Instead, the source file itself is the working notebook.

Scratch files, including paused near-matches, carry the same compact attempt log near the top of the file.
Use plain comments that record one probe at a time and its observed effect. Use as many short lines as needed to capture the probes you actually tried. 
Keep appending them as you work. It's supposed to be a ledger of what was tried:

```c
// tried inlining the temp; mismatch moved deeper to 00401A2C
// kept that change; reversed the add order; first mismatch is now the compare
// rolled back the temp change; tried a narrower local stub; no compile change
// tried the direct success return; VC5 still loaded the arg into edx
// tried a named base temp and a split fail-check form; no register change
// left this in scratch because the remaining mismatch is register-allocation drift at the first arg load
```

Good notes usually answer:

- what was tried,
- whether the change was kept or rolled back,
- what effect it had on the match or mismatch location,
- and whether the new clue is local or global.

Keep the note plain-language and focused on the observed effect.
The notes themselves should make clear whether the file is an active lead, a paused near-match, or basically ready for validation.

`FLAGS:` is optional and should appear only when a custom response file is actually
in use. Most functions should have no per-function flags at all.

The root dashboard may read these notes from `src\scratch\...` when
generating `project_full_status.csv`, so keep them short, specific, and
genuinely useful.

## Comments inside the function body

Agents may add useful inline comments inside the code body when those comments explain:

- how something works,
- why a weird shape is intentional,
- what binary-observed behavior is being preserved.

These are real source comments and may survive into the final file.

By contrast, the following are scratch-only comments and should be removed when the
function is completed:

- mismatch diary,
- decomp workflow chatter,
- blocker/status notes,
- “I tried X and it failed” notes,
- other temporary reconstruction commentary.

So the rule is:

- **code-explanatory comments may stay**
- **status/decomp-workflow comments are removed on completion**

## Header and type model

Headers are **shared**, not per-function.

This is critical.

Functions may begin life one-file-per-function, but types are global facts and should
not be duplicated per function.

Therefore:

- do **not** create one header per function,
- do **not** make headers travel alongside a function through `scratch` and `matching`,
- do **not** keep parallel scratch-vs-finished versions of the same shared type header.

Instead:

- function implementations are per-function,
- headers live centrally and are shared.

## How to use the generated reference layer

Use `inventory\types\...`, `inventory\classes\...`, and `inventory\globals\...` as lookup/reference material:

- to find names,
- to find candidate layouts,
- to find candidate class surfaces and slot names,
- to find candidate globals,
- to inspect raw generated context.

Do **not** treat generated reference files as sacred truth.

If the reference dump is wrong or incomplete:

- do **not** hand-edit the reference dump,
- do fix the working headers/source,
- and let real function work drive the correction.

## How to use `inventory\classes\...`

`inventory\classes\...` is the read-only best-effort class interface donor layer.

Use it to:

- replace local `vfXX` placeholders when slot/name evidence is strong,
- compare donor virtual names against packet-discovered slot usage,
- judge whether a class fragment is mature enough to promote.

Do **not**:

- treat it as compiler-facing truth,
- promote it into `include\game_types.h`,
- or let it override machine-code-observed slot behavior.

The intended flow is:

1. check `inventory\types\...` for hard layout facts,
2. check `inventory\classes\...` for best-effort method/slot names,
3. confirm against the packet/original asm,
4. keep the class surface local unless repeated reuse justifies promotion.

## How to use `include\game_types.h`

`include\game_types.h` is the living shared type header.

Agents should edit it conservatively.

Typical progression:

1. start with forward declarations,
2. add a minimal layout body when a function needs field access or `sizeof`,
3. optionally promote named methods from `inventory\classes\...` only when the slot evidence is strong,
4. expand the type later as more functions prove more fields or method surfaces.

When adding or correcting type bodies:

- prefer exact widths,
- prefer explicit padding arrays,
- prefer flat layout-first declarations,
- preserve offsets and sizes first,
- avoid pretty cleanup that risks changing layout,
- avoid bitfields unless packing is extremely well proven,
- avoid speculative inheritance unless it clearly helps and is strongly supported.

If only part of a type is currently known, it is fine to emit:

- the known fields,
- explicit `gap_...` / padding arrays,
- blunt placeholder names.

In the current matching phase, do **not** rush to move every partial class stub here.
Prefer local per-function stubs first, then promote only once the shared version is clearly paying for itself.

## How to use `include\game_globals.h` and `src\game_globals.cpp`

These are the living shared global declarations/definitions.

Agents should update them when a global fact becomes stable enough to be shared.

Good reasons to promote a global there:

- multiple functions need it,
- the type/location is stable enough,
- the project now has a clear shared understanding of it.

If a global is still uncertain, it is acceptable to keep a temporary local declaration in the scratch source until the fact is more stable.

## Shared vs local declarations

Put something in the shared working layer when:

- it is likely to be reused,
- it describes real project-wide type/global truth,
- it is stable enough to define the project-wide understanding of that type,
- keeping it local would just duplicate the same fact repeatedly,
- or leaving it local is now causing repeated duplicated work across a neighborhood of functions.

Keep something local to the scratch source when:

- it is speculative,
- it is temporary,
- it is only needed to unblock one function right now,
- it is too uncertain to promote confidently.
- it is a one-off partial class view exposed by a single function.

Temporary local declarations are allowed. They should be promoted later once stable.

## Prefer explicit source over hidden compiler magic

When the original binary looks like a compiler-emitted C++ helper pattern
such as:

- deleting destructors,
- vector deleting destructors,
- small virtual helper wrappers,
- other special-member-style glue,

prefer writing an **ordinary explicit function body** that reproduces the same
behavior and code shape.

Do **not** rely on the compiler to auto-generate hidden special-member helpers
unless there is a strong reason to do so.

Why:

- explicit source is easier to control,
- explicit source is easier to validate against the packet,
- explicit source avoids guessing exactly how VC5 will synthesize helper code,
- and explicit source keeps the matching bank understandable.

The target is the machine-code behavior and shape, not faithfulness to how much
of the original source was handwritten versus compiler-emitted.

## Inline asm policy

Inline asm is **forbidden** in this repo UNLESS the user explictly requests it.

That ban includes:

- `__asm`
- `_asm`
- `__declspec(naked)`
- hand-written asm wrappers
- any other source-level trick whose purpose is to smuggle raw asm into a matched file

### Narrow exception: padding-only pseudo-functions

A narrow exception is allowed for **padding-only pseudo-functions** whose entire
body is just non-behavioral filler such as:

- `nop`
- repeated `nop`
- `mov edi, edi`
- `mov eax, eax`
- simple combinations of those same padding bytes

Use this exception only when **all** of the following are true:

1. the body has no meaningful behavior,
2. the body has no memory effect,
3. the body has no real call/control-flow logic,
4. the entry appears to be padding/thunk filler rather than a real source function,
5. ordinary source cannot reasonably express the exact bytes.

This exception is **not** permission to use inline asm for real logic such as:

- getters/setters,
- wrappers,
- destructors with behavior,
- virtual dispatch helpers with real effects,
- or any other function where inline asm would bypass a still-unsolved source model.

If a function only seems to match with inline asm, treat that as proof that the
current source model is still wrong, incomplete, or not yet ready for promotion,
**unless** it is one of the padding-only pseudo-functions above.

When that happens for a real function:

- keep the function in `src\scratch\...`,
- continue source-shape / declaration / type / flag investigation if there is a
  real next lead,
- otherwise leave it in `src\scratch\...` with a clear top-note summary,
- but do **not** use inline asm to force it through.

Promotion rule:

- no real function may be promoted with inline asm still present,
- padding-only pseudo-functions may use the narrow exception above.

## Per-function flags policy

The project has a **standard default flag set**. Per-function response files are
allowed only as **last-resort exceptions** during active matching work, not as a
normal tuning tool.

Agents should assume this by default:

- if a function does not match, the first theory should be **source/type/layout
  is still wrong**, not “try a new flag”,
- prefer fixing declarations, struct layouts, calling context, control-flow
  shape, statement order, and expression shape before touching flags,
- treat custom flags as a sign that the current source model may still be
  incomplete unless there is strong evidence the flag itself is genuinely
  required,
- avoid using flag changes as procrastination or as a substitute for finding the
  real source-level fix,
- prefer the default project flags whenever they work,
- add custom per-function flags only when needed to make progress after
  meaningful source-shape investigation,
- keep those custom flags as small, rare, and explainable as possible,
- and re-test old custom flags periodically because many of them become
  unnecessary once the real source/type fix lands.

Promotion rule:

- do **not** keep a custom rsp file for a finished function unless the function
  has been re-tested without it and the default flags truly fail.

The long-term goal is not a chaotic forever-build with arbitrary flags per
function. The long-term goal is:

- one coherent project-wide baseline,
- plus a small and shrinking set of justified exceptions,
- eventually regrouped at sensible translation-unit boundaries when the project
  leaves the pure harvesting phase.

## Working scaffold rule

The generated scaffold was a **first pass**, not a permanent authority.

That means:

- agents are allowed to correct it,
- agents are expected to improve it,
- later generator improvements should not blindly overwrite hand-corrected working headers.

If regeneration happens in the future, treat it as candidate input for comparison, not as something that should automatically replace the living shared source.

## Error handling / improvisation

Agents should react to real problems pragmatically:

- missing declaration -> add the smallest safe declaration needed,
- bad generated type -> correct the working type definition,
- missing global -> add a local declaration first or promote it to shared globals if stable,
- compile failure -> narrow the issue and fix the smallest correct surface,
- mismatch -> prefer binary-observed behavior over prettier source.
- compiler-generated-looking helper -> prefer a plain explicit implementation that matches the helper pattern over depending on hidden compiler synthesis.
- ordinary function that seems to need inline asm -> investigate source shape, declaration context, and flags, or leave it in `src\scratch\...`; do not bypass the problem with asm.
- ordinary tiny mismatch -> remember that old compilers can generate meaningfully
  different code for semantically equivalent source shapes, so keep exploring
  alternative source-level formulations before giving up.
- progress deeper into the function is a useful signal; a later first mismatch often
  means the current source theory is partly correct even when the function is still
  non-exact.
- when a function finally matches after a non-obvious lesson, update the docs with the
  reusable rule instead of leaving it as session-only memory.

Do not get stuck because the initial scaffold is imperfect.
The scaffold is expected to improve through normal decomp work.

## Matching discipline

- A function in `src\matching\...` is a claim that it is done.
- A function in `src\scratch\...` is still in progress, even if it is close or temporarily paused.
- Do not promote speculative or still-mismatching code into `src\matching\...`.
- Do not promote any function there if it contains inline asm or another
  source-level hack added only to make the parity check pass, except for the
  documented padding-only pseudo-function exception above.
- Do not use hacks whose only purpose is to turn the check green while dodging
  the real source-level problem.
- Keep blocker notes and scratch workflow notes in `src\scratch\...` while a function is active.
- Remove scratch-only notes before or during promotion.

## Orchestrator promotion review

If you are orchestrating child agents or reviewing branch-local work before it
lands in the main tree:

- do **not** trust a child agent's “matched” claim blindly,
- read every incoming `.cpp` file yourself before moving it into
  `src\matching\...`,
- review any paired `config\flags\...rsp` file too,
- verify the file did not break repo rules,
- verify it does not use inline asm outside the documented padding-only pseudo-function exception,
- verify it is not relying on a green-check hack,
- and only then run the normal validation loop and promote it.

Promotion into `src\matching\...` is a review decision, not a blind move.

## Final mindset

- `inventory\...` = generated reference
- `include\...` + `src\game_globals.cpp` = living shared source
- `src\scratch\...` = active or paused non-exact work area
- `src\matching\...` = finished validated bank

Agents should be conservative about layout, flexible about workflow, and willing to correct earlier mistakes as soon as the function-level evidence says they should.
