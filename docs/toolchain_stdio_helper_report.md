# Toolchain CRT stdio helper audit report

Date: 2026-04-22

## Scope explored

- `inventory/functions/0055/00553FD0_ioinit.txt`
- `inventory/functions/0055/00553EEB_FUN_00553eeb.txt`
- `inventory/functions/0055/00553FA9_FUN_00553fa9.txt`
- `inventory/functions/0055/005541C8_FUN_005541c8.txt`

## Goal

Audit the stdio runtime neighborhood and classify only the entries supported by strong
runtime evidence.

## High-confidence conclusions

Two unnamed helper neighborhoods are high-confidence CRT/runtime islands:

- `00553EEB-00553FC3`
- `005541C8-005541F7`

## Why this is high confidence

### 1) `FUN_00553eeb` is hidden `___initstdio`

The listing excerpt directly labels the body `___initstdio`.

High-confidence CRT evidence:

- adjacent to named `__ioinit`
- manipulates `__nstream` and `___piob`
- allocates stdio tables with `calloc`
- initializes stream metadata from CRT tables
- no PDB source information

This is standard runtime stdio initialization, not project-authored logic.

### 2) `FUN_00553fa9` is hidden `___endstdio`

The listing excerpt directly labels the body `___endstdio`.

High-confidence CRT evidence:

- calls `__flushall`
- conditionally jumps to `__fcloseall`
- reads `__exitflag`
- sits immediately after hidden `___initstdio` and immediately before named `__ioinit`

This is standard runtime stdio shutdown glue.

### 3) `FUN_005541c8` is hidden `__ioterm`

The listing excerpt directly labels the body `__ioterm`.

High-confidence CRT evidence:

- iterates over `___pioinfo`
- frees allocated stdio descriptor tables with `free`
- clears the pointer slots
- is directly adjacent to named `__ioinit`

This is stdio runtime teardown, not application code.

## Applied classification

### Region 1: `00553EEB-00553FC3`

Contains:

- hidden `___initstdio`
- hidden `___endstdio`
- compact stdio init/end helper glue surrounding `__ioinit`

### Region 2: `005541C8-005541F7`

Contains:

- hidden `__ioterm`

## Exact-name future-proofing

This pass also adds safe exact-name runtime names to the manifest generator:

- `___initstdio`
- `___endstdio`
- `__ioterm`

Those names do not affect the current hidden `FUN_...` inventory surface directly, but they
are safe future-proof exact-name classifications if the inventory labels improve later.

## Bottom line

These unnamed entries are CRT stdio initialization/termination helpers, not normal manual
C/C++ decomp targets.

Strict classification:

- `FUN_00553eeb`, `FUN_00553fa9`, and `FUN_005541c8` -> `toolchain_supplied` by exact VA region
- nearby named `__ioinit` remains `toolchain_supplied` by exact name
