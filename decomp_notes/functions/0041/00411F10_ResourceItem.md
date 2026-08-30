# Function notes: 00411F10 `ResourceItem`

## Translation-unit context

The target is the second constructor in PDB module `airesitm.cpp`, after the
zero-count constructor. It owns `ResourceItem::ResourceItem(int)` at
`00411F10-00411F72` (98 bytes), with `__thiscall` and no frame. The original
body saves `ebx`, `esi`, and `edi`, performs no calls, and writes the vptr,
links, count, and three eight-element value lanes.

The natural module is `src/airesitm.cpp`. The constructor keeps the initializer
list for `next`, `prev`, and `numberValue`. A local pointer starts at
`sortedValue`; its three lanes are reached as `p[-8]`, `p[0]`, and `p[8]`.

## Current mismatch

No mismatch remains in the focused check. The rebuilt body is 98 bytes with 40
instructions, no frame, the same saved registers, and no calls. The owner symbol
is `??0ResourceItem@@QAE@H@Z`. Boundaries are closed, and the one vptr
relocation is safely masked. The result is `MATCH`, with 0 differing bytes and
0.0000% positional difference.

The grouped `airesitm` audit also reports `MATCH` for this target. Other module
rows remain unrelated repair work.

## Recovered attempt history

<!-- recovered:8196c7b548534643e4cf -->
### `a5fb96a1e6de` `src/scratch/00411F10_ResourceItem.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt log:
// first pass: natural constructor shape with vptr init, next/prev zero, count save, and the two fill phases
// second pass: switch to the decompiler-shaped do/while form because the first loop basin was slightly too small
// third pass: use sortedValue as the moving pointer base so the three writes land on the observed +/-0x20, 0, +0x20 addresses
// fourth pass: switching back to a top-tested loop changed the register basin too far and blew the diff up
// paused here: the remaining mismatch is still in the first-loop codegen basin / register order around the pointer walk
```
<!-- end-recovered:8196c7b548534643e4cf -->

<!-- recovered:wave21-airesitm -->
### `wave21-airesitm` `src/airesitm.cpp:12-44`

Mapping: `exact`.

The fresh natural baseline used direct indexed stores in two bounded loops. It
rebuilt 95 bytes and differed by 65 bytes (66.3265%), with a three-byte size
deficit and an early saved-register order difference.

The recovered form uses a moving `int*` based on `sortedValue`, a do/while
completion loop, and an early return when the requested count reaches eight.
This source emits the original 98 bytes exactly. A prior exact standalone
checkpoint independently records the same 98-byte result.
<!-- end-recovered:wave21-airesitm -->

## Rejected approaches

The direct indexed two-loop form is behaviorally clear but is rejected as the
current reconstruction. Fresh checking produced 95 bytes and 65 differing
bytes. A top-tested loop variant was also rejected in the prior recovery because
it moved the register and loop codegen basin farther from the original.

No artificial ABI, address, vtable, wrapper, or inline-assembly form was used.

## Open questions

The exact source spelling of the three lane accesses is not proven. The pointer
form is supported by the exact historical source checkpoint and by the original
`lea [this+2Ch]`, `add edx,4`, and `[-20h]/[0]/[+20h]` store sequence.

## Next useful approaches

The coordinator should review this pointer form for promotion from `scratch`.
If policy requires a more field-named form, retain this exact checkpoint while
testing only source forms that preserve the same natural array layout.

## Worker updates

`wave21-airesitm`: Recovered an exact natural-module constructor. Focused
`check_function.py --va 00411F10 --detail concise` reports `MATCH`, 98/98
bytes, 0.0000%, correct owner, closed boundaries, and safe relocation. The
grouped audit is at
`build/audits/workers/wave21-airesitm/airesitm/report.txt`. An earlier
target-session attempt hit a lock timeout; the later validation check recorded
the result successfully.

`wave21-airesitm`: Reviewed the exact pointer-form source and reran the
target-session validation check. It records `MATCH`, 98/98 bytes, 0.0000%,
owner `??0ResourceItem@@QAE@H@Z`, closed boundaries, one safely masked vptr
relocation, and no direct calls. The complete `airesitm` audit was rerun with
16 included normal functions and reports grouped `MATCH` for 00411F10. The
other audit queue rows are unrelated neighboring repairs.

## Earlier notes from `decomp_notes/functions/0041/00411F10_ResourceItem.md`

This section is historical. Use the status query for current state.

## 00411F10 `ResourceItem::ResourceItem(int)`

- PDB source: `airesitm.cpp`, lines 40 to 51.
- Original size: 98 bytes.

The constructor sets links to null. It stores zero in each active value lane.
It sets each inactive value lane to -1. It sets both sorted lanes to -1.

The former fragment used an initializer list to preserve grouped VC5 store order.
The source module keeps that natural initialization. Exactness needs a new module check.

### Current module result

The focused module check reports `MISMATCH`. The rebuilt body is 95 bytes. The
original body is 98 bytes. The check reports 65 positional diff bytes across
14 spans. The first mismatch is at offset 1.

The natural constructor remains the source body. This owner is scratch and is
not registered as an exact translation-unit owner.
