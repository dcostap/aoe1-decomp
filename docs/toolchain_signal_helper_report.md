# Toolchain signal helper audit report

Date: 2026-04-22

## Scope explored

- `inventory/functions/0055/0055918F_FUN_0055918f.txt`
- `inventory/functions/0055/005592D3_FUN_005592d3.txt`
- `inventory/functions/0055/00559350_raise.txt`
- `inventory/functions/0055/005594D0_FUN_005594d0.txt`
- `inventory/functions/0055/00559100_crtMessageBoxA.txt`

## Goal

Decide whether the unnamed neighborhood around CRT signal handling is normal decomp work or
runtime/toolchain helper machinery.

## High-confidence conclusions

Two compact unnamed neighborhoods are high-confidence toolchain-supplied helper regions:

- `0055918F-00559347`
- `005594D0-00559516`

## Why this is high confidence

### 1) `FUN_0055918f` is hidden CRT `signal`

The listing excerpt directly labels `FUN_0055918f` as `_signal`.

The body:

- validates signal numbers and handlers,
- touches CRT signal globals at `00888430`..`00888440`,
- installs console-control handling with `SetConsoleCtrlHandler`,
- consults the exception action table,
- and returns previous handlers in standard CRT `signal` style.

This is classic runtime signal-management logic, not project-authored game code.

### 2) `FUN_005594d0` is a pure CRT exception-action-table lookup helper

High-confidence evidence:

- referenced by both hidden `_signal` and named `raise`,
- walks `__XcptActTab` / `__XcptActTabCount`,
- performs no game-specific work,
- and is clearly an internal CRT table helper.

Strict conclusion:

- toolchain-supplied,
- safest classified by exact VA region.

### 3) `FUN_005592d3` is local switch/cleanup glue inside the same signal island

High-confidence evidence:

- the listing shows `switchdataD_005592d4` owned by `FUN_0055918f`,
- linear disassembly at the start is obviously polluted by embedded table data,
- the reachable code path manipulates the same CRT signal globals used by `_signal`,
- and it sits between hidden `_signal` and named `raise` as local control glue.

This is not an independent project-authored function target.

### 4) The named neighbors reinforce the CRT classification

Nearby named functions are all runtime/toolchain-facing:

- `___crtMessageBoxA`
- `raise`
- `___addl`

That neighborhood context strongly supports a runtime island interpretation.

## Applied classification

### Region 1: `0055918F-00559347`

Contains:

- hidden `_signal`
- its local switchdata / cleanup glue
- no evidence of project-authored gameplay logic

### Region 2: `005594D0-00559516`

Contains:

- CRT exception action-table lookup helper used by `_signal` and `raise`

## Exact-name runtime additions

This pass also adds a few obviously safe CRT names to the manifest generator's exact-name set:

- `signal`
- `__atoldbl`
- `__fcloseall`
- `__fpreset`

These do not affect current hidden `FUN_...` inventory names directly, but they are safe
future-proof exact-name classifications if the inventory surface improves later.

## Bottom line

This neighborhood is CRT signal/runtime machinery, not normal manual C/C++ decomp work.

Strict classification:

- hidden `_signal` and its local unnamed glue -> `toolchain_supplied` by region
- `raise` stays `toolchain_supplied` by exact name
- the action-table lookup helper stays `toolchain_supplied` by region
