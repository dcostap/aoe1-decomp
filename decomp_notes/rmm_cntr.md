# rmm_cntr.cpp source module

`src/rmm_cntr.cpp` owns all six PDB functions in source order.
`include/rmm_cntr.h` owns only the controller declaration.

The header uses canonical random-map, land, terrain, and object owners. It does
not copy DBCT, TDBC, map, or world declarations.

The debug path and `debug_rand` declaration are source-private.

## Status

`004821A0`, `00482260`, and `004828A0` report `MATCH` and `0.0000%` from the
direct module. They are the registered exact owners.

`00482270`, `004826E0`, and `004828B0` remain scratch. Their direct bodies use
typed records and arrays. They do not retain raw cursor or interior-field
pointer scaffolding.

## Fresh exact-policy audit

The PDB assigns `004821A0` to `rmm_cntr.cpp`, lines 42-49. Its original body
is `004821A0-00482254` (181 bytes). The direct compiler-facing owner is
`src/rmm_cntr.cpp`, in the source-module address order recorded above.

The standalone check rebuilt the constructor as
`??0RGE_RMM_Controller@@QAE@PAVRGE_Map@@PAVRGE_Game_World@@EJ@Z`. The original
owner name is `RGE_RMM_Controller`, and the owner check passes. The rebuild
has 181 meaningful bytes, no boundary escape, and no trailing non-padding
body. The 10 relocations are all compatible, with no actionable target
mismatch.

The constructor has five direct calls in the original and rebuilt code:
`__alloca_probe`/`__chkstk`, `RGE_Random_Map_Module`, `add_land_module`,
`add_terrain_module`, and `add_object_module`. The stack-probe name pair is
the VC5 `chkstk.obj` alias at the same helper body. The other direct symbols
match their decorated owners. There are no tail jumps.

The grouped candidate check for the module passes all three registered owners:
`004821A0`, `00482260`, and `004828A0`. The controller header contains only
the controller declaration and forward declarations. The source includes
the canonical record and generator owners. It uses no wrapper, raw address,
manual vtable, or compiler-only alias.

## 2026-09-09 corpus-19-rmm-cntr worker audit

The worker rechecked all three scratch owners in `src/rmm_cntr.cpp`. Final
results are `00482270` `MISMATCH` with 714 differing bytes, `004826E0`
`MISMATCH` with 262 differing bytes, and `004828B0` `MISMATCH` with 369
differing bytes. All owners, boundaries, relocations, frames, and direct call
sets pass their applicable checks.

The worker tested one fresh natural source form for each target. Initializing
the land collision cursor at declaration worsened `00482270` to 970 bytes.
Declaring the terrain loop index before the area local was a 262-byte codegen
duplicate. Reversing stone radius assignments worsened `004828B0` to 370 bytes;
reversing predator assignments was a 369-byte duplicate. All source changes
were restored.

The complete one-job audit is under
`build/agents/corpus-19-rmm-cntr/final-tu-audit/report.txt`. Registered exact
owners `004821A0`, `00482260`, and `004828A0` remain exact. No exact or
accepted-drift proposal is supported. The remaining blockers are compiler
register coloring, switch-tail lowering, stack-home scheduling, and the valid
VC5 helper-name alias.

## 2026-09-10 sa-7ab71ac7 allocation review

The worker rechecked `00482270` and `004826E0` in the natural `src/rmm_cntr.cpp`
owner. Both targets preserve typed generator allocation, parent-list
ownership, constructor identity, copied parameters, null guards, EH cleanup,
and original boundaries. The land target has eight ordered calls and remains
`MISMATCH` with 714 differing bytes and 1090 rebuilt bytes. The terrain target
has two ordered calls and remains `MISMATCH` with 262 differing bytes and 412
rebuilt bytes.

An explicit typed allocation-result local with an explicit null return was
tested for each target. Each target emitted the same result as its baseline.
The full TU closure exposed a two-byte mismatch in exact `004828A0`; restoring
the natural `new` form restored that function to `MATCH`. The rejected states
and final clean states are recorded in the target notes and experiment store.
The final one-job audit is under
`build/agents/sa-7ab71ac7-final-tu-audit/report.txt`. The completed `004828B0`
review remains unchanged. No exact or accepted-drift proposal is supported.

## 2026-09-10 sa-a2367e49 terrain-module review

The worker rechecked `004826E0` with owner `sa-a2367e49`. The clean source
remains unchanged. Its final result is `MISMATCH`, 262 differing bytes, 412
rebuilt bytes versus 414 original bytes, no frame, four saved registers, and
two ordered direct calls. The owner, boundary, relocation, ABI, and call
target checks pass. The first structural divergence is the switch table;
VC5 also tail-merges the second terrain-size arithmetic and hoists radius 12
into the hot-spot loop register.

Two natural Variant Lab families compiled with the pinned `gx` recipe and
two workers. The hot-loop family tested five forms. The switch family tested
four forms. No variant met the original size, frame, and call-set gates. The
size-before-fields form produced a 440-byte body and an extra tail. The
typed pointer, cached-count, do-while, record-reference, and direct-condition
forms did not improve the clean result. The reports are under
`build/variant_lab/004826E0_add_terrain_module/20260910_205100/` and
`20260910_205306/`.

The final one-job module audit is under
`build/agents/sa-a2367e49/final-tu-audit/report.txt`. Exact owners
`004821A0`, `00482260`, and `004828A0` remain exact. Scratch owners
`00482270`, `004826E0`, and `004828B0` remain mismatches at 714, 262, and
369 differing bytes. The `00482270` land cursor and allocation evidence was
not changed. No exact or accepted-drift proposal is supported.

## 2026-09-10 sa-113cf173 object-module reassessment

The worker rechecked `004828B0` without changing the natural source. Static
evidence still supports six object records, the land-point copy, and the
generator allocation. The source keeps the canonical record owners, values,
strides, null path, call order, and fault order. Runtime tests were not run.

The corrected two-worker Variant Lab family tested 72 natural combinations of
local widths, alias declaration placement, equivalent loop forms, and direct
or aliased allocation arguments. It produced two groups at 691 and 694 bytes.
No exact or invariant-eligible variant was found. A first template run omitted
one deer initializer by mistake; its output is preserved as rejected input.

The clean target remains `MISMATCH`, with 369 differing bytes and 691 rebuilt
bytes versus 695 original bytes. The final one-job audit is under
`build/agents/sa-113cf173-final-tu-audit-clean/report.txt`. Exact owners
`004821A0`, `00482260`, and `004828A0` remain exact. Scratch owners
`00482270`, `004826E0`, and `004828B0` remain at 714, 262, and 369
differences. No source change, exact match, or accepted-drift proposal is
retained. The saved-`this`, stack-home, and compiler-helper differences remain
open.

## 2026-09-10 sa-c9a6ba24 object-module reassessment

The worker rechecked `004828B0` with no living source change. Static evidence
still supports six object records, the land-point copy, and one allocation.
The source preserves field values, 0x34-byte and 0x10-byte copy strides, the
null guard, call order, and fault order. Runtime tests were not run.

The worker ran a 72-variant pointer-alias family and a three-variant
literal/named/field-derived constant family. The pointer family produced
691- and 694-byte groups. The constant family produced one 691-byte group.
No variant was exact or invariant-eligible. The clean target remains
`MISMATCH` with 369 differences and 691 rebuilt bytes versus 695 original
bytes. No exact or accepted-drift proposal is supported.

The one-job audit is `build/agents/sa-c9a6ba24-final-tu-audit/report.txt`.
Exact owners `004821A0`, `00482260`, and `004828A0` remain exact. Scratch
owners remain `00482270` at 714 differences, `004826E0` at 262 differences,
and `004828B0` at 369 differences. The saved-`this`, stack-home, register
schedule, and helper-name differences remain open.

## 2026-09-10 sa-7a356fb1 object-module pointer-offset reassessment

The worker rechecked `004828B0` with no living source change. Static evidence
still supports six object records, the land-point copy, and one allocation. The
source preserves field values, copy strides, null behavior, call order, and
fault order. Runtime tests were not run because game execution is forbidden.

The period decompiler uses the terrain subobject as the generator copy anchor.
The target passes the same address as canonical `&info`. The terrain-subobject
cast is not safe ownership for the complete `RGE_Object_Info` object.

The pointer-offset Variant Lab family tested that cast and a named aggregate
pointer. It compiled 120 variants with two workers. It produced 96 variants at
691 bytes and 24 at 694 bytes. No variant passed size, frame, and call-set
gates. The terrain-anchor group stayed at 691 bytes but lost one exact loop
block. Neither source form was retained.

The clean target remains `MISMATCH` with 369 differences and 691 rebuilt bytes
versus 695 original bytes. The owner, boundary, frame, and three-call checks
remain valid. The first mismatch is `+0x1F`, where VC5 saves `this` before the
callee-save pushes. The final audit is
`build/agents/sa-7a356fb1-final-tu-audit/report.txt`.

Exact owners `004821A0`, `00482260`, and `004828A0` remain exact. Scratch owners
remain `00482270` at 714 differences, `004826E0` at 262 differences, and
`004828B0` at 369 differences. The random-map module evidence remains
unchanged. The saved-`this`, stack-home, register schedule, and helper-name
differences need toolchain or wider-context evidence.
