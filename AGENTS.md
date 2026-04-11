Read the README.md file.

After reading the README, follow these working rules.

## Core model

- The project is **function-first** and **exact-match-first**.
- The original EXE is the behavioral oracle.
- PDB/Ghidra/type dumps are metadata/reference sources, not behavior oracles.
- Agents are expected to improvise, react to errors, and correct earlier bad assumptions as they learn more.

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
- `src\matching\...`
  - finished bank
  - only promote a function here after local exact-match validation passes

## Normal workflow for one function

1. Read the relevant packet in `inventory\functions\...`.
2. Check the shared working headers/source in `include\...` and `src\game_globals.cpp`.
3. Create or edit the function in `src\scratch\...`.
4. Compile and compare against the original.
5. If compilation or matching work exposes missing shared facts, update the shared working layer.
6. Keep iterating until the function matches.
7. Remove scratch-only workflow notes when done.
8. Move the function to `src\matching\...` only after it is locally validated.

## How to use the generated reference layer

Use `inventory\types\...` and `inventory\globals\...` as lookup/reference material:

- to find names,
- to find candidate layouts,
- to find candidate globals,
- to inspect raw generated context.

Do **not** treat generated reference files as sacred truth.

If the reference dump is wrong or incomplete:

- do **not** hand-edit the reference dump,
- do fix the working headers/source,
- and let real function work drive the correction.

## How to use `include\game_types.h`

`include\game_types.h` is the living shared type header.

Agents should edit it as progress is made.

Typical progression:

1. start with forward declarations,
2. add a minimal layout body when a function needs field access or `sizeof`,
3. expand the type later as more functions prove more fields.

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

Temporary local declarations are allowed. They should be promoted later once stable.

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

Do not get stuck because the initial scaffold is imperfect.
The scaffold is expected to improve through normal decomp work.

## Matching discipline

- A function in `src\matching\...` is a claim that it is done.
- Do not promote speculative or still-mismatching code there.
- Keep blocker notes and scratch workflow notes in `src\scratch\...` while a function is active.
- Remove scratch-only notes before or during promotion.

## Final mindset

- `inventory\...` = generated reference
- `include\...` + `src\game_globals.cpp` = living shared source
- `src\scratch\...` = active work area
- `src\matching\...` = finished validated bank

Agents should be conservative about layout, flexible about workflow, and willing to correct earlier mistakes as soon as the function-level evidence says they should.
