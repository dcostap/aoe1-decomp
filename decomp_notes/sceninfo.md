# sceninfo.cpp source reunification

`src/sceninfo.cpp` owns the PDB source order.

- `0048CEA0`, lines 26-61.
- `0048CFD0`, lines 67-80.
- `0048D040`, lines 86-105.
- `0048D0E0`, lines 111-230.
- `0048D4D0`, lines 236-240.
- `0048D500`, lines 246-250.

The source includes `sceninfo.h`, `scenario.h`, `basegame.h`, and `main.h`.
It uses the pinned VC5 `<io.h>` CRT interface.
The destructor uses `delete` for scenario headers.
Both entry allocations use `sizeof(RGE_Scenario_File_Entry)`.

## Overload evidence

The PDB declares `new_scenario_header(int)` first.
It declares the pointer overload second.

The executable stores the pointer overload at `+0x34`.
It stores the integer overload at `+0x38`.

VC5 reverses this adjacent overload pair.
The canonical header keeps PDB declaration order.

This order emits the integer call through `+0x38`.
The previous order emitted `+0x34`.

## Validation status

`0048D040` is exact.
The typed scenario-entry source has no boundary escape.
It reports `MATCH` and `0.0000%`.

`0048D0E0` now uses PDB-supported locals and path-buffer bounds.
Its fresh VC5 check matches all 995 bytes, the boundary, and the owner.
The registry still lists it as accepted drift.
See `decomp_notes/functions/0048/0048D0E0.md` for behavior evidence.

The registry lists five matching owners and one accepted-drift owner.
