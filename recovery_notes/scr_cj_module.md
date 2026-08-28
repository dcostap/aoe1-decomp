# scr_cj.cpp source recovery

## Module

- PDB source: `C:\msdev\work\age1_x1\scr_cj.cpp`
- Source: `src/scr_cj.cpp`
- Header: `include/scr_cj.h`
- Owners: nine normal functions in PDB source-line order.
- Generated entries: `00491970` scalar deleting destructor and `00492310`
  vector deleting destructor. Both remain compiler-generated.
- Padding entry: `00491C42` is listed in
  `config/padding_only_functions.txt` and remains outside source ownership.

The address sequence is `00491650`, `00491990`, `00491A80`, `00491B20`,
`00491C70`, `00491E20`, `004920C0`, `00492330`, and `004923C0`.
PDB lines run from 62 through 513. The class owners are `TribeJoinScreen`
and `TribeMPCreateDialog`.

## Context evidence

The PDB source path, line bands, and address sequence identify `scr_cj.cpp`.
The join-screen constructor, destructor, handlers, list builder, and action
provide exact anchors for the first class. The dialog constructor, destructor,
and action provide exact anchors for the second class. The original wrapper
contained the five earlier owners in this order before the three later owners.

The generated packet is under
`build/tu_plans/scr_cj_cpp/packet.{json,txt}`. The requested Terra contract
path `build/source_reunification/terra_system/orchestrator_contract.md` was
absent from this worktree. This absence is a process blocker, not a binary
ownership hypothesis.

## Migration record

The old wrapper was `src/scr_cj_tu.cpp`. It included one source fragment for
each normal owner and selected declarations with `SCR_CJ_GROUPED_TU`. The new
`src/scr_cj.cpp` owns all nine bodies in PDB order. `include/scr_cj.h` owns the
module declarations and proven layouts. No source fragment, wrapper include,
fallback declaration, context-selection macro, fake virtual slot, raw vptr,
or inline assembly remains in the compiler-facing module.

The two generated deleting destructors are not hand-written. The padding-only
`00491C42` source stub was removed because the reviewed padding manifest owns
that entry and ordinary source must not contain inline assembly.

## Status and checks

The source-module manifest is `config/source_modules/scr_cj.json`. It records
four matching owners and five scratch owners. The translation-unit registry
points its four exact owners to the direct module source and records module
name `scr_cj`.

The source uses `config/flags/00491E20_action.rsp`, which is
`/nologo /c /O2 /Oy /GX`. `/GX` is supported by the original EH registration.

## String address recovery

The original `.data` bytes at `0x00586174` are `73 63 72 33 00`, which is
`"scr3"`. The bytes at `0x0058617C` are
`4A 6F 69 6E 20 53 63 72 65 65 6E 00`, which is `"Join Screen"`.
`objdump -s -j .data` on
`orig/_original_empiresx_from_beta_that_was_decompiled.exe` shows both
addresses. The original listing also names these operands `s_scr3` at
`004916E8` and `s_Join_Screen` at `0049166E`.

The constructor now uses the natural literals. The raw address casts are gone.
The focused constructor check still returns `Result: MATCH` and `0.0000%`.
Its original boundary, owner symbol, direct calls, and relocation targets all
match. The diagnostic reports six emitted bytes changed in two spans, but no
strict byte difference.

Before migration, the wrapper had six registered exact owners:
`00491650`, `00491990`, `00491A80`, `00491B20`, `00491C70`, and `00492330`.
The three observed owners were `00491E20`, `004920C0`, and `004923C0`.
The generated entries were `00491970` and `00492310`.

The natural source uses direct `delete` expressions for child panels. The two
destructor owners are now scratch because this source form changes their
emitted bytes.

The candidate TU report is
`build/candidate_tus/final_rebase_scr_cj/report.{json,txt}`. It matches four
normal owners and both compiler-generated deleting destructors, `00491970` and
`00492310`. The five scratch owners report 167, 12, 31, 102, and 38 differing
bytes.

## Regressions and blockers

The direct migration preserves the four exact owners and both generated
entries. The five scratch owners remain outside exact registration.

Open process blocker:

- `build/source_reunification/terra_system/orchestrator_contract.md` is absent.

Open evidence blockers from the prior owner records remain for the three
action and constructor bodies. The two destructor regressions come from the
natural child-panel deletes.

## Current provider composition

The former copied hierarchy is removed from `include/scr_cj.h`. The header now
consumes canonical Panel, screen, dialog, control, BaseGame, registry, drawing,
and logging owners. `src/scr_cj.cpp` keeps all nine normal bodies in PDB order.

`com_sess.h` now consumes the canonical communication-handler declaration.
The source uses typed communication enums, typed GUID values, natural dialog
strings, and direct child deletion. The complete provider chain supplies the
canonical `scr_mps.h` declaration.

The two source bodies that construct `TribeMPSetupScreen` remain present. Do
not copy or partially redeclare `TribeMPSetupScreen` here.
