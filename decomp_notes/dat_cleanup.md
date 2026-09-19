# `DAT_` cleanup ledger

This ledger records reviews of generated `DAT_` names in compiler-facing source.

Use one of these results:

- `named`: Evidence supports a descriptive source name.
- `removed`: The declaration or definition is generated scaffolding.
- `retained`: The storage is real, but available evidence does not support a name.

Do not replace uncertainty with an invented name.

## Reviewed symbols

| Symbol | Result | Evidence |
| --- | --- | --- |
| `DAT_00575780` | removed | The original read-only `5.0f` has one reference from `stuffAvoidancePath`. The PDB has no global symbol at this address. The rebuilt function reads VC5's literal pool at `0x005562F0`. The separate `game_globals.obj` definition links at `0x00564324` and has no source reference. |
| `DAT_00575778` | removed | The original read-only `0.2f` has one reference from `stuffAvoidancePath`. The PDB has no global symbol at this address. The rebuilt function reads VC5's literal pool at `0x005562E8`. The separate definition has no source reference. |
| `DAT_0057577c` | removed | The original read-only `10.0f` has one reference from `stuffAvoidancePath`. The PDB has no global symbol at this address. The rebuilt function reads VC5's literal pool at `0x005562EC`. The separate definition has no source reference. |
| `DAT_00575784` | removed | The original read-only `25.0f` has one reference from `saveTheTown`. The PDB has no global symbol at this address. The rebuilt function reads VC5's literal pool at `0x005562F4`. The separate definition has no source reference. |
| `DAT_0057575c` | removed | The original read-only `-2.0f` is part of the `taitacmd.cpp` constant pool. The PDB has no global symbol at this address. Recovered source uses the literal, and no source references the separate definition. |
| `DAT_00575760` | removed | The original read-only `100.0f` is part of the `taitacmd.cpp` constant pool. The PDB has no global symbol at this address. Recovered source uses the literal, and no source references the separate definition. |
| `DAT_00575764` | removed | The original read-only value is the single-precision `0.01f` bit pattern. It is part of the `taitacmd.cpp` constant pool. The PDB has no global symbol, and no source references the separate definition. |
| `DAT_00575768` | removed | The original read-only `-0.5f` is part of the `taitacmd.cpp` constant pool. The PDB has no global symbol at this address. Recovered source uses equivalent literals, and no source references the separate definition. |
| `DAT_00575770` | removed | The original read-only `0.0` double is part of the `taitacmd.cpp` constant pool. The PDB has no global symbol at this address, and no source references the separate definition. |

## Validation

No build or test ran for this milestone. The active cleanup workflow defers them to final validation.
