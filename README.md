# aoe1-decomp

Decompilation of Age of Empires 1. Specifically, a leaked release from
1998-07-17, where the Rise of Rome expansion was still in beta.
This release contained the PDB and other artifacts, which made this project
substantially easier.

## Core goal

The project remains **exact-match-first** under a pinned historical toolchain,
but it now tracks decompilation confidence separately from compiler parity.
There are three completed banks:

- `src\matching\` — exact generated assembly parity;
- `src\accepted_drift\` — rare, near-exact functions whose remaining localized
  drift has been manually reviewed as behavior-equivalent VC5 codegen;
- `src\verified_logic\` — functions for which exact matching was suspended only
  after substantial matching work, followed by repeated independent review of
  the reconstructed behavior against the original executable.

`verified_logic` is not an exact-match claim and is not a relaxed form of
`accepted_drift`. It is a separately reported semantic-reconstruction result.

### Source-recovery principle

The project is not trying to manufacture matching bytes from arbitrary C++.
Its primary source hypothesis should be the period-plausible C/C++ the original
developers most likely wrote. Exact assembly is the decisive test of that
hypothesis, not a reason to begin from decompiler artifacts or retain opaque
compiler-steering tricks.

Before low-level codegen tuning, reconstruct canonical ownership: real structs
and classes, named fields and arrays, API/COM surfaces, natural loops and control
flow, and likely same-TU declarations. Treat Ghidra cursor arithmetic, raw
offsets, fake volatility, comma-expression scheduling, manual vtable calls, and
register-forcing aliases as temporary experiments. They should not displace a
clean living source merely because they produce a modestly better diff.

This is period-plausible recovery, not modern prettification. Preserve original
bugs, odd evaluation order, overlap, aliasing, macros, C idioms, and narrow
widths whenever the executable proves them. An unusual spelling belongs in the
living source only when it is plausible original code, reaches exactness, or is
required for binary-observed behavior. Exact promotion still requires byte
equality; readability never relaxes the oracle.

The basic unit of work is a function:

1. identify a target function,
2. inspect its pregenerated raw packet,
3. reconstruct the simplest binary-supported, period-plausible source and its
   canonical type/layout ownership,
4. build it with the pinned toolchain,
5. compare rebuilt output against the original,
6. iterate until it matches or the current bounded matching assignment runs out
   of productive hypotheses;
7. after enough independent matching work, the project orchestrator may either
   approve a narrowly localized `accepted_drift` result or begin the separate
   logic-review workflow documented in `docs\main_agent_workflow.md`.

Exact parity is determined by the rebuilt machine code, not by source-body
plausibility alone. Diff tooling records byte-diff metrics for every checked
function; `0.0000%` diff is an exact match. A non-zero diff is only considered
accepted drift when the source file lives in `src\accepted_drift\`; there is no
separate manifest. Logic verification is represented by placement in
`src\verified_logic\` plus a versioned per-function review ledger under
`logic_reviews\`. In stubborn cases the effective source model can include
small translation-unit context such as neighboring declarations or a minimal
header include. Include context from the function's likely original donor file
is legitimate source context even when the tiny function body does not textually
use every header. Treat that context as something to iterate deliberately and
reduce carefully, not something to strip blindly.

Variant-generation labs or harnesses are a normal, encouraged tool for stubborn
unexpected VC5 codegen-family problems after a function has reached reasonable
behavioral/layout parity. They are not a substitute for first understanding the
behavior, call set, stack cleanup, touched type/global surface, and likely
original source structure. Variant output is experimental: review it as source
before replacing the clean living candidate.

`tools\check_function.py` reports size, frame, instruction/call/CFG structure,
strict bytes, and the output change since the previous run before recommending the
next workflow stage. It rejects entry-reachable code beyond the original boundary
without confusing adjacent jump-table/EH data for function bytes, and does not
mask relocations at structurally incompatible instruction sites. See
`docs\check_function_diagnostics.md` for the report and acceptance semantics.
For large functions it also provides context-aware `--call-map` and `--block-map`
alignment, concise giant-function output, and automatic restorable run history.
Use `--checkpoint <label>`, `--history`, and `--restore-checkpoint <label-or-id>`
to preserve and compare structural experiments without replacing a better baseline.
Checkpoint comparisons include call/block deltas; `--range` focuses one aligned
assembly band, and dry-run-first `--prune-history` controls retained experiments.
Target sessions designate one ordinary history checkpoint as `clean-source`: the
canonical plausible reconstruction. Metric-best experiments remain separate
history evidence. There is still exactly one compiler-facing `.cpp` per function.
History's codegen frontier and “assembly closer/farther” language describe emitted
bytes only; they do not rank source quality.

Parallel late-corpus work also has five advisory agent tools:

- `tools\target_session.py` provides shared-tree target leases, meaningful-probe
  bookkeeping, non-budget restore/final-validation checks, emitted-code duplicate
  detection, clean-source pin/restore commands, and a checker-stage-aware
  current-metrics briefing plus a bounded worker handoff;
- `tools\target_dossier.py` generates a target-local binary-evidence report for
  calls, candidate `this` offsets, globals, conservatively entry-normalized stack
  accesses/parameter homes, and generated-type size conflicts;
- `tools\query_abi.py` joins function/global/class reference metadata with
  declaration and usage evidence from living exact-match sources.
- `tools\find_function_donors.py` ranks exact donor functions using TU, owner
  class, constructor/destructor family, call/vslot, displacement, frame, and
  saved-register evidence.
- `tools\search_asm_donors.py` searches a selected assembly block against the
  exact-match bank and shows the matched assembly plus the C/C++ that emitted it.

See `docs\agentic_matching_workflow.md` for their workflow and evidence limits.
Compact target selection is available through
`tools\query_project_status.py --triage`; it avoids loading many full function
packets into an agent context merely to choose a target. The complete default
contract for a short request such as `match 0043C2B0` lives in `AGENTS.md` and is
injected into every repo-local agent session.

Project-wide orchestration, repeated worker assignment, exact-match stall
decisions, blind logic-review cohorts, ledger handling, and promotion authority
are documented in `docs\main_agent_workflow.md`. That document is intended for
the user-designated main coordinating agent; ordinary matching workers continue
to use the bounded contract in `AGENTS.md`.

The user supplies the exact subagent provider/model ID, thinking level, and an
approximate maximum concurrency or range. The main agent treats the upper bound
as a ceiling rather than an obligation to fill slots, assigns one explicit role
per participant, and reserves complete concurrent cohorts for blind logic review.

Focused `variant_lab.py` runs can enforce checker-equivalent effective size,
frame, and call-set gates. Compact previews avoid dumping whole generated files,
and `--session-owner <owner>` records one lab family as one meaningful probe.

## Toolchain

VC5-era Microsoft toolchain, pinned through `config\toolchain.json`.

The build policy is to use one standard default compiler flag set for normal
work. Per-function response files are exceptional, rare, and should only appear
after source-shape investigation has already been pushed as far as it reasonably
can. If a custom response file is used, treat it as part of the hypothesis under
test and revisit it after the source model improves.

- compiler: `C:\Program Files (x86)\DevStudio\VC\Bin\CL.EXE`
- linker: `C:\Program Files (x86)\DevStudio\VC\Bin\LINK.EXE`
- nmake: `C:\Program Files (x86)\DevStudio\VC\Bin\NMAKE.EXE`
- resource compiler: `C:\Program Files (x86)\DevStudio\SharedIDE\bin\RC.EXE`
- expected compiler version: `11.00.7022`
- expected linker version: `5.00.7022`
- include roots:
  - `C:\Program Files (x86)\DevStudio\VC\Include`
  - `C:\Program Files (x86)\DevStudio\VC\MFC\Include`
- lib roots:
  - `C:\Program Files (x86)\DevStudio\VC\Lib`
  - `C:\Program Files (x86)\DevStudio\VC\MFC\Lib`

Important detail: launch the VC5 tools under a **minimal environment**.
Inheriting the full modern host `PATH` can break VC5 backend startup.

- behavior comes from the original executable,
- type names, layouts, signatures, vtables, source-file hints, and enum values
  are taken from PDB/Ghidra.

Additional pinned upstream game files now live under:
- `orig\original_full_game_files_rise_of_romes_beta_17_7_1998`

Use that repo-local folder when the full original beta game file set is needed.

The repo separates functions into six workflow buckets:

- **normal** — ordinary manual C/C++ decomp/matching work,
- **padding_only** — reviewed non-behavioral padding or boundary labels whose
  exact byte shims stay tracked without counting as game source functions,
- **parent_owned_fragment** — real game-code bytes that are compiler-emitted blocks inside a larger parent function, not independently source-ownable functions,
- **toolchain_supplied** — supplied by imports / runtime / libraries and not manually decompiled,
- **asm_special** — named handwritten-assembly functions to be restored later through an asm workstream,
- **asm_region** — non-normal asm/codelet/data-dispatch regions that are part of handwritten-assembly neighborhoods and not ordinary `.cpp` targets.

The exclusion manifests for the non-normal / non-independent buckets live at:
- `config\padding_only_functions.txt`
- `config\parent_owned_fragments.txt`
- `config\toolchain_supplied_functions.txt`
- `config\toolchain_supplied_regions.txt`
- `config\asm_special_functions.txt`
- `config\asm_special_regions.txt`

Safe scripted toolchain extraction is generated by:
- `tools\generate_toolchain_supplied_manifest.py`

That tool also emits a review-oriented hidden-label candidate report at:
- `build\toolchain_hidden_label_safe_candidates.tsv`

and a smaller review queue of still-unhandled safe hidden-label candidates at:
- `build\toolchain_hidden_label_unhandled_candidates.tsv`

It also emits a review-only probable helper-island region report at:
- `build\toolchain_probable_helper_island_candidates.tsv`

Entries listed there stay tracked in the repo, but they are excluded from the normal
manual C/C++ decomp/matching corpus and should not appear as ordinary "left to do" work.

The first explored handwritten-draw asm neighborhood is documented in:
- `docs\asm_corpus_exploration_report.md`

The first explored CRT/helper-island toolchain neighborhood is documented in:
- `docs\toolchain_helper_island_report.md`

A focused FPU-control CRT helper-island audit is documented in:
- `docs\toolchain_fpu_control_helper_report.md`

A CRT conversion/io helper audit is documented in:
- `docs\toolchain_crt_conversion_io_report.md`

A CRT signal helper audit is documented in:
- `docs\toolchain_signal_helper_report.md`

A CRT heap helper audit is documented in:
- `docs\toolchain_heap_helper_report.md`

A VC5 EH/compiler-runtime helper audit is documented in:
- `docs\toolchain_eh_helper_report.md`

A CRT stdio helper audit is documented in:
- `docs\toolchain_stdio_helper_report.md`

A CRT ctype/case-conversion helper audit is documented in:
- `docs\toolchain_ctype_helper_report.md`

A review pass over safe hidden-label toolchain candidates is documented in:
- `docs\toolchain_hidden_label_review_report.md`

The review-only probable helper-island report is documented in:
- `docs\toolchain_probable_helper_island_report.md`

Parent-owned fragment handling is documented in:
- `docs\parent_owned_fragments.md`

Padding-only entry handling is documented in:
- `docs\padding_only_functions.md`

Detailed workflow, agent rules, and project policy live in `AGENTS.md`.
