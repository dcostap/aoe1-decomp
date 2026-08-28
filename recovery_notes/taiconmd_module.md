# taiconmd.cpp source module

## PDB context

The PDB names `C:\\msdev\\work\\age1_x1\\taiconmd.cpp` as the source
module. The normal owners use `TribeConstructionAIModule` and appear in this
source and address order:

| VA | PDB lines | bytes | owner | state |
| --- | --- | ---: | --- | --- |
| `004D5E60` | 37-38 | 42 | `TribeConstructionAIModule::TribeConstructionAIModule(void*, int)` | matching |
| `004D5EB0` | 45-46 | 42 | `TribeConstructionAIModule::TribeConstructionAIModule(int, int)` | matching |
| `004D5EE0` | 51 | 11 | `TribeConstructionAIModule::~TribeConstructionAIModule()` | matching |
| `004D5EF0` | 57-59 | 13 | `setMainDecisionAI` | matching |
| `004D5F00` | 64-105 | 468 | `canPlace` | matching |
| `004D60E0` | 111-333 | 1689 | `placeStructure` | scratch |
| `004D6780` | 338-358 | 117 | `placeDock` | matching |
| `004D6800` | 363-379 | 160 | `setBuilt` | matching |
| `004D68A0` | 385-389 | 41 | `compare` | scratch |

The seven matching owners are the exact anchors for this PDB source module.
The nearby `004D5E90` scalar deleting destructor is compiler-generated. It has
no handwritten PDB source owner.

`src/taiconmd.cpp` now owns all nine normal bodies in PDB order. It uses
`include/taiconmd.h` with the canonical item, AI, object, world, and map
providers. The old wrapper, context header, and source-bank bodies are removed.
`config/source_modules/taiconmd.json` records the complete module.

## Status evidence

The seven registered owners are `004D5E60`, `004D5EB0`, `004D5EE0`, `004D5EF0`,
`004D5F00`, `004D6780`, and `004D6800`. Their exact symbols remain in the
translation-unit configuration.

`004D60E0` remains scratch. The direct natural source has 72 differing bytes
(4.2629%). Its 1689-byte boundary, owner symbol, 62 ordered direct calls, and
direct targets are correct. The remaining drift starts at the temporary-list
setup. It is a register-role and EH-state-store schedule difference.

`004D68A0` remains scratch. The direct natural source uses the canonical
const `ConstructionItem::buildAttempts` target. It reads `left` before
`right`, as the original does. A null `left` faults first. The source differs
by 12 bytes through private register roles. Do not promote it from a byte
result without a separate semantic review.

## Scoped validation

The focused group check used `tools/validate_candidate_tu.py` with the seven
registered owners, both scratch rows, and generated `004D5E90`.

| VA | kind | result | bytes | owner | relocation target mismatches | boundary escapes |
| --- | --- | --- | ---: | --- | ---: | ---: |
| `004D5E60` | exact | MATCH | 0 | match | 0 | 0 |
| `004D5EB0` | exact | MATCH | 0 | match | 0 | 0 |
| `004D5EE0` | exact | MATCH | 0 | match | 0 | 0 |
| `004D5EF0` | exact | MATCH | 0 | match | 0 | 0 |
| `004D5F00` | exact | MATCH | 0 | match | 0 | 0 |
| `004D6780` | exact | MATCH | 0 | match | 0 | 0 |
| `004D6800` | exact | MATCH | 0 | match | 0 | 0 |
| `004D60E0` | observed scratch | MISMATCH | 72 | match | 0 | 0 |
| `004D68A0` | observed scratch | MISMATCH | 12 | match | 0 | 0 |
| `004D5E90` | generated | MATCH | 0 | unverified | 0 | 0 |

The seven registered owners and generated destructor match. `004D60E0` and
`004D68A0` remain scratch. Neither observed result supports promotion.
