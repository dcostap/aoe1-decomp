# tairesmd.cpp source reunification

## Context

The PDB identifies `C:\\msdev\\work\\age1_x1\\tairesmd.cpp` as the owner of
all ten normal functions from lines 30 through 143. Their address sequence is
the source order in `src/tairesmd.cpp`. The nearby `004E6B80` scalar deleting
destructor is compiler-generated and is not a handwritten owner.

The module header is `include/tairesmd.h`. It imports the canonical AIModule
and ResourceItem declarations. It retains only the PDB-proven local
TribeMainDecisionAIModule, ResourceTable, and TribeResourceAIModule views.
No synthetic function, inline assembly, or ABI shim is used.

PDB owner order and spans are:

| VA | PDB lines | bytes | owner |
| --- | ---: | ---: | --- |
| `004E6B40` | 30-31 | 62 | `TribeResourceAIModule` constructor |
| `004E6BA0` | 38-40 | 117 | `TribeResourceAIModule` constructor |
| `004E6C20` | 45 | 11 | `TribeResourceAIModule` destructor |
| `004E6C30` | 51-53 | 13 | `setMainDecisionAI` |
| `004E6C40` | 58-61 | 30 | `save` |
| `004E6C60` | 66-68 | 7 | `numberResources` |
| `004E6C70` | 73-77 | 48 | `resource` |
| `004E6CA0` | 82-110 | 147 | `resourcesAvailable` |
| `004E6D40` | 115-128 | 134 | `unavailableResource` |
| `004E6DD0` | 133-143 | 60 | `resourceName` |

The exact anchors are the nine prior matching owners in this sequence. The
accepted-drift anchor is `004E6CA0`; its source retains the prior reviewed
implementation and status.

## Statuses

The module preserves the prior reviewed state:

- `matching`: `004E6B40`, `004E6BA0`, `004E6C20`, `004E6C30`, `004E6C40`,
  `004E6C60`, `004E6C70`, `004E6D40`, and `004E6DD0`.
- `accepted_drift`: `004E6CA0`.

`004E6CA0` has the original 147-byte boundary. Its rebuilt body is 146 bytes.
Its reviewed difference is limited to equivalent register allocation: the
rebuilt source selects EBX for the available-resource pointer and EBP for
`this`, while the executable makes the opposite allocation. The calls,
predicate, memory effects, branch paths, and return values remain equivalent.
The compare uses an equivalent encoding, with the resulting one-byte padding
difference.

## Migration effects

The old `src/tairesmd_tu.cpp` wrapper and ten source-bank fragments are no
longer compiler-facing owners. The direct translation-unit entry points to
`src/tairesmd.cpp` and registers the nine matching owners. The module metadata
records all ten normal statuses, including the accepted-drift owner.

The compiler-generated `004E6B80` entry remains outside the handwritten owner
list. It is emitted by the virtual destructor surface.
