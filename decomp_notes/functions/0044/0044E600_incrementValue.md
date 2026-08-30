# Function notes: 0044E600 `incrementValue`

Module notes: `decomp_notes/infmap_module.md`.

## Recovered attempt history

<!-- recovered:7ea26ff562cdae873a47 -->
### `9acc26143f36` `src/scratch/0044E600_incrementValue.cpp:1-39`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0044E600 InfluenceMap::incrementValue
// PDB: infmap.cpp lines 240-257 (123 bytes, 45 asm lines)
// Default flags. No inline asm/hacks.
// Retry 2026-05-18/19 (18 honest tries):
// - Revalidated baseline: exact-sized 123 but broad register/order mismatch (71.5447% positional / 60.9756% edit).
// - Tried naming rowData/limit/row/cell/cur locals to force original ESI=rowData and CL=limit; worsened to extra EDI save and 86.1789% positional.
// - Tried precomputing cell vs using row[rx]; original wants both LEA cell in ESI and load from [edx+eax], but VC5 either keeps pointer in EAX or spills cur.
// - Tried `--limit` / `limit-1` saturation spellings; no improvement.
// - Tried preserving coordinate roles by swapping temp names and expression order; VC5 still uses EDX for rx/EAX for ry in baseline, opposite original.
// - Tried /Ob0 briefly; no change, flag removed.
// - 2026-05-19 tried mutating x/y parameter slots; got original initial EAX=x/EDX=xRef but introduced extra EDI save and worse body.
// - 2026-05-19 tried x-mutated/y-local, explicit assignment locals, register locals, and swapped parameter names; either same baseline register swap or extra callee-save pressure.
// - 2026-05-19 tried direct row[rx] stores instead of cell local and nested positive bounds checks; both worsened with extra EDI/EBX saves.
// - 2026-05-19 tried real virtual class surface from type dump; no codegen change from flat vtable field.
// - 2026-05-19 later pass tried parameter mutation (x-=ref/y-=ref) with named rows/row/limit/cell: got original EAX=x start but added EDI save and worsened to 86%+ positional.
// - Tried x-mutated with y local and value+cur order: still added EDI save and worsened to 87.8% positional.
// - Tried value parameter as int and split rx/ry copy-then-sub assignments: no change from baseline register-swap basin.
// - 2026-05-19 Boss retry: revalidated baseline (71.5447% / first mismatch +1); tried direct
//   parameter mutation and xref/yref/named row+limit variants. Direct mutation stayed in baseline
//   register-swap basin; xref/named variants got desired initial EAX/EDX but added EDI save and
//   worsened to 86.1789%. Rolled back to baseline as best scratch state.
// - 2026-05-20 Boss retry: revalidated baseline (123 bytes, 71.5447% positional / 60.9756% edit).
// - Tried direct parameter mutation with direct rowData[y][x] accesses; worse (109 positional bytes, first mismatch +5).
// - Tried parameter mutation with row/cell/cur/limit locals to force ESI cell and CL limit; worse (108 positional bytes).
// - Tried nested positive bounds checks and in-body cur<limit structure; much worse edit/position due to different branch/layout basin.
// - Tried int value local and sum/value+cur ordering; worse and changed early parameter/register allocation.
// - Tried xref/yref locals plus rows/row/cell/limit locals; got a different family but still worse (106 positional bytes).
// - Tried rx/ry declaration/assignment expression forms and positive `&&` guard; no improvement over the known bad families.
// - Tried `register` on x, y, and both parameters; no codegen change from baseline.
// - Tried volatile value parameter; worsened to 98 positional bytes.
// - Tried signature width variants for value (`int`, `unsigned int`, `char`, `signed char`); no change from baseline.
// - Tried flag probes `/Og`, `/Oi`, `/Ox`, `/Gf` on top of default `/O2 /Oy`; no change, flags removed.
// GIVEUP: remaining blocker is combined register allocation (original EAX=rx, EDX=ry, ESI=cell, CL=limit) plus exact unsigned-byte widening/order around sum and saturation. No accepted_drift proposal because drift changes stack spills/register topology/control displacements broadly.
// 2026-05-21 Boss retry: tried declaration-order swap (`ry` before `rx`), direct parameter mutation,
//   combined initializer expressions, split assignment locals, `register` locals, explicit `rows/row/cell`
//   forms, `register` cell, cell/reference form, signed `int sum`, and positive `cur < limit` body.
//   Best new family gets exact first 22 bytes with `rows` local and signed sum, improving edit diff to
//   ~26%, but still uses `add edx,eax`/stack-spilled cur instead of original `lea esi,[edx+eax]` + AL
//   and shifts all return tails. No MATCH; not accepted_drift-worthy because the diff is still broad.
```
<!-- end-recovered:7ea26ff562cdae873a47 -->
