# aoe1_attempt3

Agent-first, exact-match decompilation workflow for Age of Empires / Rise of Rome.

This document describes **how the project is supposed to work**.

It is intentionally focused on:

- workflow,
- repository roles,
- source-of-truth rules,
- type/header policy,
- validation policy.

It is **not** meant to be a running changelog of current progress.

## Core goal

The project goal is **exact generated assembly parity** under a pinned historical toolchain.

The basic unit of work is a function:

1. identify a target function,
2. inspect its pregenerated raw packet,
3. implement it,
4. build it with the pinned toolchain,
5. compare rebuilt output against the original,
6. iterate until it matches.

The project is **not** organized around “make the game build first.”

It is organized around **exact-match function work**.

## Truth hierarchy

Use truth in this order:

1. the pinned original EXE bytes,
2. exact-match diff results,
3. deterministic Ghidra/PDB-derived type and listing facts,
4. any rough reference code only as a last-resort hint.

Important rule:

- **machine code is the behavioral oracle**
- **PDB/Ghidra are metadata and context oracles**

That means:

- behavior comes from the original executable,
- type names, layouts, signatures, vtables, source-file hints, and enum values can be taken aggressively from PDB/Ghidra when deterministic,
- but PDB/Ghidra do not get to override machine-code-observed behavior.

## Agent-first repo model

The repo is meant to work well for agents without requiring a prep step before every function.

The intended model is:

1. the repo contains a committed master inventory of functions,
2. the repo contains committed pregenerated per-function raw packets,
3. agents read those packets directly,
4. agents work in per-function scratch sources,
5. matched functions are promoted into a finished bank,
6. periodic sweeps revalidate the finished bank.

So the repo should carry the raw context needed to start work.

## Intended repository roles

```text
inventory\
  all_functions.csv
  functions\
    <per-function raw packets>
  globals\
    <generated global reference dumps>
  types\
    <generated type/layout reference dumps>

include\
  <shared working headers used by the compiler>

src\
  scratch\
    <one active source file per function>
  matching\
    <finished exact-match source files>
  game_globals.cpp

tools\
  <build, check, status, validation, generation scripts>

build\
  <volatile generated artifacts; ignored in git>

project_full_status.csv
  <regenerated root dashboard>
```

### `inventory\`

This is the committed raw corpus.

It answers:

- what functions exist in total,
- what the raw per-function context is,
- what generated global reference data is available,
- what generated type/layout reference data is available.

### `include\`

This is the shared working header surface used by the compiler.

It is editable, but under strict rules.

### `src\scratch\`

This is the active working area.

Functions that are:

- unfinished,
- blocked,
- mismatching,
- currently being iterated on,

should live here.

### `src\matching\`

This is the finished exact-match bank.

If a source file is here, the claim is:

- “this function is supposed to be finished.”

### `build\`

This is for volatile generated artifacts only:

- diff reports,
- rebuilt objects,
- extracted asm,
- manifests,
- validator summaries,
- temporary files.

`build\` is ignored in git.

### `project_full_status.csv`

This is the regenerated root dashboard.

It is a computed view of project state, not an authoritative notebook.

## Function inventory and raw packets

## Upstream inputs vs committed generated outputs

When this document says things like:

- “the PDB should provide this,”
- “the EXE should provide this,”
- “we leverage Ghidra here,”

it means those raw upstream inputs should be read by generator/export scripts and converted into committed repo artifacts.

So the intended split is:

### Upstream raw inputs

- pinned original EXE,
- pinned PDB,
- pinned Ghidra exports/listings.

### Generated committed outputs

- `inventory\all_functions.csv`,
- `inventory\functions\...`,
- `inventory\globals\...`,
- `inventory\types\...`.

Agents should normally consume the generated committed outputs.

However, the pinned original EXE still remains the live oracle for exact-match validation during per-function checks and finished-bank sweeps.

## `inventory\all_functions.csv`

This is the committed universe of known functions.

It should answer:

- what functions exist at all,
- where they live by VA/name/size,
- what is left,
- which are the largest remaining by asm size or line count,
- what the project’s total function space looks like.

This file is the answer to:

- “what exists in total?”

It is not the place for day-to-day scratch notes.

## `inventory\functions\...`

This is the committed bank of per-function raw packets.

The design goal is that an agent should not need a prep helper before starting work.

For a target function, the repo should already contain a raw packet with stable, deterministic context such as:

- VA / name / size,
- original extracted asm from the EXE,
- function ranges,
- relevant Ghidra listing excerpt,
- Ghidra auto-decompiler pseudocode excerpt,
- calling convention,
- stack parameter names if available,
- source-file / line hints if available,
- nearby literals / globals / call-target context,
- later, deterministic PDB/type enrichment when useful.

These packets are meant to be blunt, committed, and agent-usable.

## Globals

Globals are shared project facts, not per-function state.

They should be handled the same way as types:

- generated reference dumps in the committed corpus,
- shared working declarations in central headers/sources,
- temporary local declarations only when something is still too tentative.

### Generated global reference dumps

This should live in:

```text
inventory\globals\
  all_globals.csv
  dumps\
  data\
```

This layer should capture the generator's best read-only starting facts such as:

- address,
- name,
- section,
- size,
- mutability,
- known type,
- relevant initial bytes.

Use the PDB strongly here for:

- names,
- types,
- symbol identity.

Use the original image strongly here for:

- actual bytes,
- initial values,
- zero-init vs nonzero-init behavior,
- raw string/table data.

This layer is reference material, not the sacred compiler surface.

If the generator gets something wrong, later agent work is allowed to correct the working headers/source instead of pretending the dump was perfect.

### Shared working global declarations

Shared global declarations should live centrally, for example:

- `include\game_globals.h`
- `src\game_globals.cpp`

Scratch functions should normally use those shared declarations.

Temporary local `extern` declarations inside scratch files are acceptable only while something is still too tentative to promote into shared headers.

## Source file model

## One implementation file per function, at least initially

The initial working unit is **one source file per function**.

That means the normal path is:

- create a function source in `src\scratch\`,
- iterate until it matches,
- promote it into `src\matching\`.

This is a workflow choice, not a permanent promise that the final project will always remain one-file-per-function.

Later, stable functions may be grouped into larger translation units if that becomes useful. This is TO BE DEFINED LATER.

FOR NOW, the **working unit** is one function per source file.

## Scratch vs matching

### `src\scratch\`

Use this for:

- in-progress work,
- blocked work,
- known-nonmatching work,
- temporary experiments.

### `src\matching\`

Use this for:

- functions that passed local exact-match validation and are being claimed as finished.

Folder location is the claim.

No extra “finished” flag is required.

## Structured top comments in scratch files

There is **no separate JSON scratch-state sidecar**.

Instead, the scratch source file itself is the working notebook.

Active scratch files should be allowed to carry a compact structured header block such as:

```c
// STATUS: blocked
// FLAGS: config\flags\o2.rsp
// BLOCKER: needs TU context for sibling helper at 004013A0
// NOTE: stack cleanup matches, but register allocation still diverges after debug_srand
```

This is where agents put:

- blocker notes,
- decompilation-specific status,
- current flags in use,
- high-value “what’s wrong right now” notes.

These notes do **not** need to be queryable beyond simple scraping if desired.

The source file itself is the detailed status record for active work.

## Comments inside the function body

Agents are allowed to add useful inline comments inside the code body when those comments explain:

- how something works,
- why a weird shape is intentional,
- what binary-observed behavior is being preserved.

These are real source comments and may survive into the final file.

By contrast, the following are scratch-only comments and should be removed when the function is completed:

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

Functions may begin life one-file-per-function, but types are global facts and should not be duplicated per function.

### Therefore:

- do **not** create one header per function,
- do **not** make headers travel alongside a function through `scratch` and `matching`,
- do **not** keep parallel scratch-vs-finished versions of the same shared type header.

Instead:

- function implementations are per-function,
- headers live centrally and are shared.

## Two header/type layers

### Layer 1: generated type reference dumps

This lives under the committed corpus, for example:

```text
inventory\types\
  all_types_reference.h
  dumps\
  vtables\
```

This layer is:

- generated from PDB + Ghidra/layout facts,
- committed to git,
- treated as read-only reference material,
- regenerated in bulk when exporters improve.

Use this layer aggressively for:

- class/struct names,
- member names,
- offsets,
- sizes,
- vtable slot order,
- signatures,
- calling conventions,
- enum names and values,
- inheritance clues.

### Layer 2: shared working headers

These live under:

- `include\game_types.h`
- `include\game_globals.h`

These are the headers used by the compiler.

They should usually be bootstrapped once from the generated reference dumps and then edited by agents as the project learns where the generator was wrong or incomplete.

## Scaffold generation policy

The practical workflow is:

1. generate the initial shared type/global scaffold once,
2. start using it for real function work,
3. fix it in place when function work proves a generated assumption wrong.

So:

- generated reference dumps under `inventory\...` stay read-only,
- generated working headers under `include\...` and `src\...` become normal editable project source.

Important rule:

- do **not** keep bulk-regenerating the same working headers in place after agents have started correcting them.

If a later exporter improvement is worth comparing, generate a fresh candidate somewhere else and diff it against the working headers instead of overwriting project edits.

## Working header rules

### Safe edits

These are safe to add as needed:

- missing non-virtual method declarations,
- constructors / destructors,
- forward declarations,
- includes,
- static helper declarations,
- corrections to bad generated names or declarations once function work proves them wrong,
- other linkage-only declarations needed to compile.

### Unsafe edits unless strongly proven

These are not to be changed casually:

- member order,
- member count,
- member offsets,
- vtable order,
- inheritance structure,
- anything else that changes in-memory layout.

The core rule is:

- **if it changes bytes in memory, be extremely conservative**
- **if it is only code linkage or a clearly proven correction, editing it is usually fine**

## Shared headers vs local temporary declarations

Shared working headers should contain reasonably stable facts.

If something is too tentative, keep it local in the scratch source at first.

Examples of things that may stay local temporarily:

- forward declarations,
- temporary `extern` declarations,
- minimal blunt helper declarations,
- temporary scaffolding needed to get one function compiling.

Promote that information into shared headers only once it is stable enough to represent project-wide truth.

### Rule of thumb

Put it in shared headers if:

- multiple functions need it,
- it describes real type/layout/linkage truth,
- or it is stable enough to define the project-wide understanding of that type.

Keep it local in the scratch file if:

- it is speculative,
- it is temporary,
- it is only there to get one function compiling for now.

## Structs and classes

Treat structs/classes primarily as **layout carriers first**, not as pretty design artifacts.

That means:

- use PDB/Ghidra layout information strongly,
- preserve offsets/sizes/vtables carefully,
- do not force a prettier object model than the binary justifies.

If a type is only needed for:

- field access,
- `this`-adjusted calls,
- virtual slot dispatch,
- `sizeof` / offset correctness,

then the working header only needs to preserve those facts.

It does not need to be aesthetically complete.

## Inheritance

Be conservative.

Only model inheritance in working headers when evidence is strong enough that it helps more than it hurts.

Bad inheritance guesses are dangerous because they can break:

- layout,
- `this` adjustment,
- destructor behavior,
- virtual dispatch.

## Vtables and virtuals

Slot order is sacred.

Do not:

- reorder virtuals,
- delete unknown virtuals,
- prettify the vtable shape.

If placeholders are required to preserve virtual ordering, keep them.

## Enums

Use PDB/Ghidra enums aggressively for:

- names,
- values,
- switch labels,
- symbolic meaning.

Be more careful about using enums as **actual stored member field types** in layout-sensitive structs/classes.

When storage width matters, it is often safer to keep:

- a fixed-width integer field,
- plus enum constants / comments,

than to risk a bad enum storage assumption in old C++ compilation.

So:

- **enum meaning: yes**
- **enum-typed storage fields: only when safe**

## Bitfields

Be very conservative.

Unless packing is nailed down and worth the risk, prefer:

- raw integer fields,
- masks,
- shifts,
- named constants,

over C++ bitfields.

## PDB usage policy

Use the PDB strongly for **type metadata** and weakly for **behavioral interpretation**.

### Strong PDB use

Use it for:

- names,
- signatures,
- member layouts,
- vtables,
- enum names/values,
- inheritance clues.

### Weak PDB use

Do **not** let it override machine-code-observed behavior in:

- control flow,
- branch semantics,
- copy sizes,
- subtle signedness behavior,
- weird calling behavior visible in assembly.

So the rule is:

- **machine code decides behavior**
- **PDB decides type metadata when deterministic**

## Ghidra usage policy

The committed Ghidra data is an important hint source for agents.

The useful part is especially the raw assembly-side listing context:

- demangled names,
- calling conventions,
- stack parameter names,
- source-file / line hints,
- XREFs,
- labels,
- annotated per-instruction comments.

That context belongs in the pregenerated per-function raw packets.

The function comparison pipeline itself still compares against the real EXE bytes.

Ghidra auto-decompiler pseudocode may also be included in packets as a helpful lower-trust add-on, but it is not the behavioral oracle.

## Root status report

The project-wide dashboard is:

- `project_full_status.csv`

This file lives at repo root because it is a frequently regenerated current-state report, not part of the stable inventory corpus.

It should be regenerated by a script that looks at:

- `inventory\all_functions.csv`,
- files present in `src\scratch\`,
- files present in `src\matching\`,
- optionally the structured top comments in scratch files.

It should answer questions like:

- how much is left,
- what functions are left,
- which functions are in scratch,
- which are in matching,
- which are the largest remaining,
- which scratch files currently declare blockers,
- which functions use custom flags.

This CSV is a **computed dashboard**, not a hand-maintained source of truth.

Important simplification:

- `project_full_status.csv` does **not** track finished-bank validation pass/fail results.

## Validation model

Validation happens at two levels.

## 1. Local function validation

An agent working on one function runs the exact-match loop for that function and uses the result before promotion.

The promotion rule is:

- a function should only move from `src\scratch\` to `src\matching\` after local exact-match validation passes.

## 2. Finished-bank sweep validation

Because `src\matching\` is only a claim, the repo should also support a periodic sweep such as:

```powershell
python tools\validate_functions.py --matching-only
```

This sweep should:

- scan `src\matching\`,
- rerun exact-match validation for each supposedly finished function,
- print a simple summary,
- detect regressions.

Important simplifications:

- folder location is the only claim flag needed,
- the validator is read-only with respect to source placement,
- it does **not** auto-move files back to `scratch`,
- its results do **not** feed into `project_full_status.csv`.

The validator answers one question:

- is the finished bank still actually okay right now?

## Build and volatile artifacts

`build\` is for volatile artifacts only:

- extracted original asm,
- rebuilt asm,
- diff reports,
- build manifests,
- rebuilt objects,
- validator output,
- temporary files.

This is where parity evidence lives, but it is not authoritative source code.

## Overall workflow summary

The intended workflow is:

1. consult `inventory\all_functions.csv`,
2. open the committed per-function raw packet,
3. create or edit one source file in `src\scratch\`,
4. use shared working headers from `include\`,
5. keep tentative declarations local when necessary,
6. run the exact-match loop,
7. remove scratch-only status/decomp notes when complete,
8. promote the source file into `src\matching\`,
9. periodically sweep `src\matching\` for regressions.

## Design summary

The project is built around these decisions:

- exact-match function work is the core unit,
- the repo should contain a committed pregenerated raw corpus for agents,
- the full function universe should live in a committed inventory,
- active work lives in `src\scratch\`,
- finished work lives in `src\matching\`,
- scratch files themselves carry temporary status/blocker notes,
- useful inline code comments may survive into final source,
- shared headers live centrally and are not per-function,
- generated type/global reference dumps are separate from editable working headers,
- the shared working scaffold is generated once and then corrected in place as function work proves mistakes,
- PDB is used strongly for type metadata,
- machine code remains the behavioral oracle,
- `project_full_status.csv` is a regenerated dashboard,
- `build\` is volatile and ignored,
- finished-bank validation is separate from the status dashboard.
