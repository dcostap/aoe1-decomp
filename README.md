# aoe1-decomp

Decompilation of Age of Empires 1. Specifically, a leaked release from
1998-07-17, where the Rise of Rome expansion was still in beta.
This release contained the PDB and other artifacts, which made this project
substantially easier.

## Core goal

The project goal is **exact generated assembly parity** under a pinned
historical toolchain.

The basic unit of work is a function:

1. identify a target function,
2. inspect its pregenerated raw packet,
3. implement it,
4. build it with the pinned toolchain,
5. compare rebuilt output against the original,
6. iterate until it matches.

Exact parity is determined by the rebuilt machine code, not by source-body
plausibility alone. In stubborn cases the effective source model can include
small translation-unit context such as neighboring declarations or a minimal
header include. Include context from the function's likely original donor file
is legitimate source context even when the tiny function body does not textually
use every header. Treat that context as something to iterate deliberately and
reduce carefully, not something to strip blindly.

Large variant-generation labs or harnesses are exceptional tools for stubborn
codegen-family problems, not part of the normal per-function loop.

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

The repo separates functions into four workflow buckets:

- **normal** — ordinary manual C/C++ decomp/matching work,
- **toolchain_supplied** — supplied by imports / runtime / libraries and not manually decompiled,
- **asm_special** — named handwritten-assembly functions to be restored later through an asm workstream,
- **asm_region** — non-normal asm/codelet/data-dispatch regions that are part of handwritten-assembly neighborhoods and not ordinary `.cpp` targets.

The exclusion manifests for the non-normal buckets live at:
- `config\toolchain_supplied_functions.txt`
- `config\toolchain_supplied_regions.txt`
- `config\asm_special_functions.txt`
- `config\asm_special_regions.txt`

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

A CRT stdio helper audit is documented in:
- `docs\toolchain_stdio_helper_report.md`

Detailed workflow, agent rules, and project policy live in `AGENTS.md`.
