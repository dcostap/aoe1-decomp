# fractal.cpp module recovery

- PDB source: `C:\msdev\work\age1_x1\fractal.cpp`.
- Source: `src/fractal.cpp`.
- Header: `include/fractal.h`.
- Flags: `config/flags/default.rsp`.

## Source order and ownership

The module has 41 normal owners. It has 6,416 source bytes in the executable.
The source lists every owner in PDB line and address order.

The class has one real `PrimaryPt` and 500 real `PtToPt` entries. Its final
size is 0x1058. The four masks start at 0xFA8. The probability array and the
placement array are at 0x1024 and 0x1028.

The source no longer uses an owner wrapper, source-bank includes, recovery
macros, fallback class declarations, unions for alternate field names, or raw
point-array views.

## Function state

Thirty-one owners are `matching`. The final grouped reconciliation promoted
`0044B2B0` after it returned `MATCH`, `0.0000%`.

Seven owners remain `accepted_drift`: `0044AB90`, `0044B470`,
`0044B760`, `0044BB60`, `0044BCD0`, `0044BF90`, and `0044C510`. Their prior
source remains the behavior candidate. The old records place their differences
in VC5 scheduling, register allocation, x87 order, or address calculation.
They do not prove a new exact result.

`0044AFE0 DrawMask` remains `scratch`. It preserves the proven mask selection,
clipping, signed sample, saturation, and loop behavior. Its current source is
not byte exact. The remaining issue is the original parameter-home and loop
register shape.

## Accepted-drift and scratch review

| VA | State | Reviewed remaining difference |
| --- | --- | --- |
| `0044AB90` | accepted drift | VC5 schedules the ESI clear after the `BranchDistance` store. |
| `0044AFE0` | scratch | The mask rows need the original parameter-home and loop register shape. |
| `0044B2B0` | matching | The final grouped build resolves the earlier Width and Height load scheduling drift. |
| `0044B470` | accepted drift | VC5 swaps the two input register roles before the initial stores. |
| `0044B760` | accepted drift | VC5 uses another direction-register coloring and clamp schedule. |
| `0044BAA0` | scratch | The current check has broad control-flow and frame drift. |
| `0044BB60` | accepted drift | The post-ring probability tail has a local register-allocation drift. |
| `0044BCD0` | accepted drift | The saturation tail keeps the byte pointer and byte value in other registers. |
| `0044BD80` | scratch | The current check has broad control-flow drift and one extra jump. |
| `0044BF90` | accepted drift | Five x87 bytes differ. A volatile width local matches, but PDB evidence rejects it. |
| `0044C510` | accepted drift | The inner placement-cell address calculation uses another register schedule. |

The accepted rows retain their proven calls, predicates, writable addresses,
values, cleanup, and observable faults. The two scratch rows retain their
natural bodies but do not have a localized code-generation difference.

Fresh checks show `0044BAA0` differs by 163 bytes with only 22.86% exact-block
coverage, a 15-byte size deficit, and a frame mismatch. `0044BD80` differs by
273 bytes with an 11-byte size deficit, a high-severity control-flow
difference, and one extra jump. Neither row is accepted-drift safe.

## Shipped behavior

`MakeNewLink` and `MakeSatelliteLink` both use `dy = -dx` on the lower y bound.
The executable writes that value before it reverses `DirY`. Do not correct it
to `dy = -dy`.

`MakeArrays` retries each allocation ten times. It publishes each returned
pointer before its retry test. It does not clear the arrays.

`AddingCircle` uses signed remainders for both random branches. The second
cell offset uses the independent signed remainder values.

## Validation scope

The original group was `fractal_arrays`. It now maps its 31 exact owners to
`src/fractal.cpp`. The direct owner sweep passed after the metadata move. Each
row had the expected owner symbol and `MATCH` at `0.0000%`.

The candidate validator still requires source-bank includes. It cannot validate
the final direct source shape. Use focused compilation and
`check_function.py` for this module.
