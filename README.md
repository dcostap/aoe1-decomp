# aoe1-decomp

Decompilation of Age of Empires 1. Specifically, a leaked release from
1998-07-17, where the Rise of Rome expansion was still in beta.
This release contained the PDB and other artifacts, which made this project
substantially easier.

## Core goal

The project goal is **exact generated assembly parity** under a pinned
historical toolchain. A separate audited escape-hatch bucket,
`src\accepted_drift\`, exists for rare functions whose remaining non-zero diff
is manually reviewed as localized behavior-equivalent VC5 codegen drift. These
are not exact matches and are reported separately from `src\matching\`.

The basic unit of work is a function:

1. identify a target function,
2. inspect its pregenerated raw packet,
3. implement it,
4. build it with the pinned toolchain,
5. compare rebuilt output against the original,
6. iterate until it matches, or in rare reviewed cases move it to
   `src\accepted_drift\` with the full attempt log preserved and a clear
   `ACCEPTED_DRIFT` comment explaining the localized equivalent drift.

Exact parity is determined by the rebuilt machine code, not by source-body
plausibility alone. Diff tooling records byte-diff metrics for every checked
function; `0.0000%` diff is an exact match. A non-zero diff is only considered
accepted drift when the source file lives in `src\accepted_drift\`; there is no
separate manifest. In stubborn cases the effective source model can include
small translation-unit context such as neighboring declarations or a minimal
header include. Include context from the function's likely original donor file
is legitimate source context even when the tiny function body does not textually
use every header. Treat that context as something to iterate deliberately and
reduce carefully, not something to strip blindly.

Variant-generation labs or harnesses are a normal, encouraged tool for stubborn
unexpected VC5 codegen-family problems after a function has reached reasonable
behavioral/layout parity. They are not a substitute for first understanding the
behavior, call set, stack cleanup, and touched type/global surface.

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

Parallel late-corpus work also has four advisory agent tools:

- `tools\target_session.py` provides shared-tree target leases, meaningful-probe
  bookkeeping, emitted-code duplicate detection, and a checker-stage-aware
  current-metrics briefing;
- `tools\target_dossier.py` generates a target-local binary-evidence report for
  calls, candidate `this` offsets, globals, conservatively entry-normalized stack
  accesses/parameter homes, and generated-type size conflicts;
- `tools\query_abi.py` joins function/global/class reference metadata with
  declaration and usage evidence from living exact-match sources.
- `tools\find_function_donors.py` ranks exact donor functions using TU, owner
  class, constructor/destructor family, call/vslot, displacement, frame, and
  saved-register evidence.

See `docs\agentic_matching_workflow.md` for their workflow and evidence limits.
Compact target selection is available through
`tools\query_project_status.py --triage`; it avoids loading many full function
packets into an agent context merely to choose a target. The complete default
contract for a short request such as `match 0043C2B0` lives in `AGENTS.md` and is
injected into every repo-local agent session.

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

The repo separates functions into five workflow buckets:

- **normal** — ordinary manual C/C++ decomp/matching work,
- **parent_owned_fragment** — real game-code bytes that are compiler-emitted blocks inside a larger parent function, not independently source-ownable functions,
- **toolchain_supplied** — supplied by imports / runtime / libraries and not manually decompiled,
- **asm_special** — named handwritten-assembly functions to be restored later through an asm workstream,
- **asm_region** — non-normal asm/codelet/data-dispatch regions that are part of handwritten-assembly neighborhoods and not ordinary `.cpp` targets.

The exclusion manifests for the non-normal / non-independent buckets live at:
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

Detailed workflow, agent rules, and project policy live in `AGENTS.md`.
