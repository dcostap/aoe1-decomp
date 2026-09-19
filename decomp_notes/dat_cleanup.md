# `DAT_` cleanup ledger

This ledger records reviews of generated `DAT_` names in compiler-facing source.

Use one of these results:

- `named`: Evidence supports a descriptive source name.
- `removed`: The declaration or definition is generated scaffolding.
- `retained`: The storage is real, but available evidence does not support a name.

Do not replace uncertainty with an invented name.

The audit also removes duplicate non-`DAT_` scaffolding when it owns the same
original storage as a reviewed symbol.

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
| `DAT_00575758` | removed | The original read-only `-1.0f` has five comparison references in `taitacmd.cpp`. The PDB has no global symbol at this address. Source now uses the literal sentinel, which lets VC5 own the translation unit's constant-pool entry. |
| `DAT_00575700` through `DAT_00575754` | removed | These 20 read-only values form an earlier part of the `taitacmd.cpp` constant pool. The PDB has no global symbol for any entry. Recovered source already uses literals, and no source references the separate definitions. |
| `DAT_00577318` through `DAT_0057732c` | named | These six read-only values gate fields in `T_Scenario` file loading. Their comparison sites and values establish scenario file versions `1.13`, `1.02`, `1.03`, `1.04`, `1.12`, and `1.05`. The new `g_scenario_file_version_*` names are descriptive cleanup names, not recovered PDB names. |
| `DAT_00575618`, `DAT_0057561c` | named | These values gate conditional `TribeMainDecisionAIModule` save-file reads. Their new names state the owning module and version threshold. |
| `DAT_00575634` | removed | The original read-only `1.0f` has one code reference, but recovered source has no reference to the separate scaffold definition. The PDB has no global symbol at this address. |
| `DAT_00575690` | named | This `1.5f` value gates the strategy AI difficulty field during save-file loading. |
| `DAT_005756e0` through `DAT_005756ec` | named | These four values gate fields in `TacticalAIGroup::load`. Their names state the owning type and version threshold. |
| `DAT_005756f0` through `DAT_005756fc` | named | These four values control tactical distance clamping, offsets, and line-of-sight factors. Their names describe each use without claiming PDB provenance. |
| `DAT_00575550` through `DAT_00575560` | named | These five values gate conditional fields in `TribeInformationAIModule` save-file loading. Their names state the owning module and version threshold. |
| `DAT_00575564` through `DAT_0057557c` | removed | These seven read-only information-AI constants have no PDB symbols. Source now uses their direct float literals for distance, placement, size, and sentinel operations. |

## Related duplicate storage

| Symbol | Result | Evidence |
| --- | --- | --- |
| `g_time` | removed | `g_time` and `save_game_version` both modeled original address `0x0058EBCC` with initial value `7.23f`. `TribeMainDecisionAIModule` uses the value for conditional save-file reads. Source now uses the canonical `save_game_version` owner. |

## Validation

No build or test ran for this milestone. The active cleanup workflow defers them to final validation.
