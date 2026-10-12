# `BuildAIModule::loadBuildList` local names

## Result

The PDB names are original, but the source assigned six names to the wrong variables.
The earlier name review checked membership, not the instruction-to-offset mapping.
The cleanup report's PDB table is correct. It does not prove the current source mapping.
The source now uses the correct mapping and no longer contains the misleading name comments.

| Previous source name | Correct PDB name | PDB offset | Use |
| --- | --- | --- | --- |
| `quantity` | `typeID` | `-0x160` | Object/type ID |
| `buildFrom` | `quantity` | `-0x15c` | Entry count |
| `buildCap` | `buildFrom` | `-0x158` | Constructor argument `bf` |
| `typeID` | `buildCap` | `-0x164` | Optional sixth field; argument to `setBuildCap` |
| `ySize` | `xSize` | `-0x168` | Doubled `radius_x`; constructor argument `x` |
| `xSize` | `ySize` | `-0x170` | Doubled `radius_y`; constructor argument `y` |

## Original evidence

Files under `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/`:

- `age1_x1.pdb`: direct `S_BPREL32` records in `BuildAIModule::loadBuildList`.
- `empiresx.exe`: direct instruction decoding at `0x00409430` through `0x00409778`.

The PDB offsets agree with `inventory/pdb/scoped_symbols.json`, entry `00409430`.
Do not use the Ghidra instruction labels to map these variables.

Let `S` be ESP at function entry, before the first instruction.
The prologue subtracts `0x184` in total, including saved registers.
At the main scan, ESP is `S - 0x184` before argument pushes.

- `0x004095a5`: `[esp + 0x2c]` gives `S - 0x158`, the fifth field (`buildFrom`).
- `0x004095a9`: `[esp + 0x28]` gives `S - 0x15c`, the fourth field (`quantity`).
- `0x004095b3`: two pending pushes make `[esp + 0x2c]` equal `S - 0x160` (`typeID`).
- `0x004095f7`: `[esp + 0x20]` gives `S - 0x164`, the optional sixth field (`buildCap`).
- `0x004096ce` and `0x00409773`: `[esp + 0x28]` supplies the entry count (`quantity`).
- `0x00409717`: seven pending pushes make `[esp + 0x48]` equal `S - 0x158` (`buildFrom`).
- `0x00409726`: the caller pushes that value as constructor argument `bf`.
- `0x00409769`: `[esp + 0x20]` supplies `buildCap` to `setBuildCap`.
- `0x004096b3`: the caller loads `radius_x` from object offset `0x30`.
- `0x004096d9`: the caller stores its doubled value at `S - 0x168` (`xSize`).
- `0x004096b0` and `0x004096b6`: the caller stores `radius_y` at `S - 0x170` (`ySize`).
- `0x00409705` through `0x00409716`: the caller passes these sizes as `x` and `y`.

## Limits

This inspection proves the listed name mapping. It does not validate the complete function.
The source correction changes only these six identifiers and removes the misleading comments.
An automated source comparison confirmed that no other source changed.
The source diff check passed.
Executable build, linked checks, automated tests, and runtime tests have not run for this correction.

## Scoped compilation and function check

Command:

```text
python tools/audit_translation_unit_functions.py --affected-by src/aibldmod.cpp --jobs 1 --output-dir build/validation/aibldmod-local-names-20261004T052919
```

Exit code: `0`. The tool compiled one module and checked 28 normal functions.
All 27 `matching` targets passed. `loadBuildList` had zero byte, relocation, and boundary differences.
Its owning symbol matched.
The unchanged `insertItem` retained `new_verified_logic` status and showed 476 byte differences.
That status does not claim byte equality. This check did not repeat its behavior review.

Report: `build/validation/aibldmod-local-names-20261004T052919/report.txt`.
