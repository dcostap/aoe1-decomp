# taibldmd.cpp source reunification

## Context

The PDB identifies `C:\\msdev\\work\\age1_x1\\taibldmd.cpp` as the owner of all
28 normal functions from lines 62 through 1773. Their address order is the
source order in `src/taibldmd.cpp`. The compiler-generated vector deleting
destructor at `004D3AB0` is not a handwritten owner.

The module header is `include/taibldmd.h`. It records the proven BuildItem,
BuildAIModule, TribeMainDecisionAIModule, ResourceItem, and player layouts used
by this source. No synthetic function or inline assembly is used.

`insert`, `insertResearch`, and `insertGathererPercentage` use the inherited
`TribeMainDecisionAIModule::player` field at `+0xF0`. The separate `aiPlayer`
field at `+0x1256C` is used by the later resource and research paths. The
BuildItem declaration order keeps `numberBuilds` before `buildCap`; this is
required for the original `mostNeededResource` call sequence.

PDB owner order and spans are:

| VA | PDB lines | bytes | owner |
| --- | ---: | ---: | --- |
| `004D3A80` | 62-63 | 42 | constructor |
| `004D3AD0` | 70-71 | 42 | constructor |
| `004D3B00` | 76 | 11 | destructor |
| `004D3B10` | 82-84 | 13 | setMainDecisionAI |
| `004D3B20` | 89-95 | 565 | loadBuildList |
| `004D3D60` | 100-434 | 1780 | initialize |
| `004D4460` | 439-459 | 218 | skipNextBuildListItem |
| `004D4540` | 464-891 | 2136 | nextBuildableItem |
| `004D4DB0` | 896-910 | 94 | nextBuildListItemCategory |
| `004D4E10` | 915-956 | 368 | blockingResource |
| `004D4F80` | 962-1026 | 264 | mostNeededResource |
| `004D5090` | 1032-1088 | 216 | addItem |
| `004D5170` | 1093-1147 | 252 | addBuiltItem |
| `004D5270` | 1152-1189 | 159 | removeBuiltItem |
| `004D5310` | 1195-1368 | 599 | cancelBuildItem |
| `004D5590` | 1374-1399 | 100 | addTrainedUnit |
| `004D5600` | 1405-1432 | 144 | cancelTrainUnit |
| `004D5690` | 1437-1456 | 88 | addResearch |
| `004D56F0` | 1462-1489 | 144 | cancelResearch |
| `004D5780` | 1494-1500 | 32 | isAgeResearch |
| `004D57A0` | 1505-1600 | 446 | insert |
| `004D5AD0` | 1605-1642 | 163 | insertResearch |
| `004D5B80` | 1647-1653 | 42 | insertGathererPercentage |
| `004D5BB0` | 1658-1675 | 109 | numberBuiltOrInProgressItemsOfType |
| `004D5C20` | 1680-1695 | 116 | allBuilt |
| `004D5CA0` | 1700-1716 | 145 | readyToResearch |
| `004D5D40` | 1721-1753 | 155 | unskipBuildList |
| `004D5DE0` | 1759-1773 | 123 | buildItem |

## Statuses

The module preserves the prior reviewed state:

- `matching`: `004D3A80`, `004D3AD0`, `004D3B00`, `004D3B10`, `004D3B20`,
  `004D4460`, `004D4DB0`, `004D4F80`, `004D5090`, `004D5170`, `004D5270`,
  `004D5310`, `004D5590`, `004D5690`, `004D56F0`, `004D5780`, `004D57A0`,
  `004D5AD0`, `004D5B80`, `004D5BB0`, `004D5C20`, `004D5DE0`.
- `accepted_drift`: `004D4E10`, `004D5600`, `004D5CA0`, `004D5D40`.
- `scratch`: `004D3D60`, `004D4540`.

The four accepted-drift owners retain their previous bounded equivalence
reviews. `004D5600` differs only in a virtual-call register. `004D5CA0` differs
only in equivalent register allocation. `004D4E10` and `004D5D40` retain their
localized loop/register drift reviews. None changes calls, predicates, cleanup,
memory effects, or return behavior.

## Scratch regressions

`004D3D60 initialize` remains a natural semantic reconstruction. Its prior best
standalone result used `/GX`, a 0xB0 BuildItem layout, 61 ordered calls, and a
953-byte positional difference. The remaining difference was broad register
and frame-slot allocation plus loop topology. The source keeps the proved
resource lifetime, field offsets, call order, and fault order. It does not use
codegen-only steering.

`004D4540 nextBuildableItem` remains a natural semantic reconstruction. Its
prior best standalone result used `/GX`, a 0xF4 EH frame, 115 ordered calls,
98.37% exact blocks, the original 2136-byte boundary, and a nine-byte
positional difference. The remaining difference was a branch-polarity hunk and
one switch-table relocation. The source keeps the proven shared-tail control
flow, typed object/resource calls, and 0x73 limit behavior.

## Migration effects

The old `src/taibldmd_tu.cpp` wrapper and its 28 source-bank fragments are no
longer compiler-facing owners. The direct translation-unit entry now points to
`src/taibldmd.cpp` and registers only the 22 matching owners. The module
metadata carries all 28 statuses, so accepted-drift and scratch owners remain
observed without stale exact claims.
