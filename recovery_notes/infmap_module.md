# Influence Map module recovery

## Scope

`src/infmap.cpp` owns all 21 normal `infmap.cpp` bodies in PDB order.
It replaces the fragment wrapper and every per-function owner.

The PDB source path is `C:\msdev\work\age1_x1\infmap.cpp`.
`0044E030` is a compiler-generated scalar deleting destructor.

## Canonical ownership

`include/infmap.h` owns `InfluenceMap` and `XYPoint`.
`include/rge_fio.h` owns `rge_read` and `rge_write`.

The source has no context include, local owner class, field overlay, or
absolute memory reference. `printToFile` uses source-local format strings.
Their contents come from the original read-only data records.

`XYPoint` is a structure. Its reference signatures use `ABUXYPoint@@`.
This identity is required for the four reference-argument symbols.

## Original behavior

`0044E680` and `0044E800` compare Y bounds with `xSizeValue`.
The executable proves this behavior. Keep this original bug.

`0044E9E0` keeps the case-zero fall-through into the case-seven suffix.
The switch layout comes from the original executable.

## Focused candidate gate

Command:

`python tools/validate_candidate_tu.py --proposal build/infmap_natural_proposal.json --output-dir build/candidate_tus/infmap_natural`

The candidate has 16 exact rows. Each has `MATCH`, `0.0000%`, matching
ownership, zero relocation mismatches, and zero boundary escapes:

- `0044DF80`, `0044E050`, `0044E080`, `0044E0B0`, `0044E0F0`, and `0044E1A0`;
- `0044E4C0`, `0044E4E0`, `0044E510`, `0044E560`, `0044E680`, and `0044E790`;
- `0044E800`, `0044E900`, `0044F030`, and `0044F040`.

Generated `0044E030` also matches exactly.

`0044E250` and `0044ED20` remain accepted drift.
The migration does not reopen their reviewed status.

`0044E600` remains scratch. Its candidate row has two boundary escapes.
`0044E9E0` remains scratch. `0044EC00` remains verified logic.
The candidate records their current results.
