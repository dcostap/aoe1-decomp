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
  - create or edit one file per target function here
- `src\almost_matched\...`
  - intentionally parked non-exact bank
  - use only for functions that remain non-matching under strict admission rules
  - these files are **not** done and must not be treated as equivalent to `matching`
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

1. Read the relevant packet in `inventory\functions\...`.
2. Check the shared working headers/source in `include\...` and `src\game_globals.cpp`.
3. Create or edit the function in `src\scratch\...`.
4. Compile and compare against the original.
5. If compilation or matching work exposes missing shared facts, update the shared working layer.
6. Keep iterating until the function matches.
7. If a function is understood but intentionally parked as non-exact, move it to `src\almost_matched\...` only when the strict admission rules below are satisfied and the required structured header notes are present.
8. Remove scratch-only workflow notes when done.
9. Move the function to `src\matching\...` only after it is locally validated.

### Exact-match iteration heuristics

When a function is close but sticky, use these heuristics before escalating to
toolchain panic or inline asm:

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

## `almost_matched` admission rules

Agents may move a function from `src\scratch\...` to `src\almost_matched\...` only when **all** of the following are true:

1. The mismatch is **localized and specifically understood**.
2. Source-shape and plausible flag/toolchain exploration have been meaningfully attempted; this is not just the first failed draft.
3. Calling convention, stack cleanup, call boundaries, and obvious externally visible behavior still look correct.
4. The remaining difference is judged **low-risk codegen drift**, such as merged epilogues, harmless register choice drift, or benign block-layout drift.
5. The remaining difference is **not** a changed predicate, changed call set, changed memory effect, changed copy size, or another behavior-sensitive divergence.
6. The file carries a structured header that explains why it was parked.

Required structured header for `src\almost_matched\...`:

```c
// STATUS: almost_matched
// CLASS: <short mismatch class>
// RISK: <low|medium|high>
// WHY: <why this is understood and parked>
// NEXT: <what would justify revisiting it>
```

Optional additional notes may still use:

```c
// FLAGS: ...
// BLOCKER: ...
// NOTE: ...
```

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
- bulk-copy it into `include\game_types.h`,
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
- or keeping it local would just duplicate the same fact repeatedly.

Keep something local to the scratch source when:

- it is speculative,
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

Inline asm is a **last resort**, not a normal matching tool.

For ordinary functions, agents should first fight through:

- declaration context,
- return type/shape,
- source expression shape,
- materially different but semantically equivalent source spellings,
- especially forms that materialize results differently,
- C vs C++ frontend differences,
- and reasonable flag differences,

before accepting inline asm.

Inline asm is most acceptable when the original function plausibly looks like:

- hand-written low-level helper code,
- compiler/runtime support glue,
- or another function whose original source likely was already very close to raw asm.

For small ordinary gameplay/utility functions, inline asm should be treated as a
warning sign that the current source model is still wrong.

For ordinary functions:

- do **not** mark the function finished while it still depends on inline asm,
- keep it in `src\scratch\...`,
- and leave comments in the scratch file explaining why it is still draft,
  what was tried, and which source-shape alternatives still remain to test.

## Per-function flags policy

Custom per-function response files are acceptable during the current
match-harvesting phase, but they are **exceptions**, not the final project
shape.

Agents should:

- prefer the default project flags when they work,
- add custom per-function flags only when needed to make progress,
- keep those custom flags as small and explainable as possible,
- and treat them as candidates for later convergence.

The long-term goal is not a chaotic forever-build with arbitrary flags per
function. The long-term goal is:

- a mostly coherent project-wide baseline,
- plus a shrinking set of justified exceptions,
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
- ordinary function that only matches with inline asm -> investigate source shape, declaration context, and flags before accepting the asm workaround.
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
- A function in `src\almost_matched\...` is a claim that it is intentionally parked, understood, and still non-exact.
- Do not promote speculative or still-mismatching code there.
- Do not promote an ordinary function there if it still relies on inline asm as
  a temporary matching crutch.
- Keep blocker notes and scratch workflow notes in `src\scratch\...` while a function is active.
- Remove scratch-only notes before or during promotion.

## Final mindset

- `inventory\...` = generated reference
- `include\...` + `src\game_globals.cpp` = living shared source
- `src\scratch\...` = active work area
- `src\almost_matched\...` = understood non-exact parking area
- `src\matching\...` = finished validated bank

Agents should be conservative about layout, flexible about workflow, and willing to correct earlier mistakes as soon as the function-level evidence says they should.
