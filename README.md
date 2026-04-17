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

## Toolchain

VC5-era Microsoft toolchain, pinned through `config\toolchain.json`.

The build policy is to use one standard default compiler flag set for normal
work. Per-function flag overrides are exceptions and should be rare, justified,
and revisited after source-level fixes land.

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

Detailed workflow, agent rules, and project policy live in `AGENTS.md`.
