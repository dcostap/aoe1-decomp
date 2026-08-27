# taiconmd.cpp registration cleanup

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

The seven matching owners are the exact anchors for this PDB source module. The
nearby `004D5E90` scalar deleting destructor is compiler-generated. It has no
handwritten PDB source owner.

The compiler-facing source remains `src/taiconmd_tu.cpp` with
`include/taiconmd_context.h`. The two scratch owners remain included only to
preserve the existing recovery source. They are not registered exact owners.
The `004D60E0` and `004D68A0` source files are in `src/scratch` to match their
reviewed status. This cleanup does not add `config/source_modules/taiconmd.json`
or a `module` key. Keep this wrapper and context header until direct natural
`src/taiconmd.cpp` exists.

## Status evidence

The seven registered owners are `004D5E60`, `004D5EB0`, `004D5EE0`, `004D5EF0`,
`004D5F00`, `004D6780`, and `004D6800`. Their exact symbols remain in the
translation-unit configuration.

`004D60E0` is scratch. Its prior accepted-drift result is not retained by this
metadata state. Two separate baselines remain recorded:

1. The canonical candidate differs by 1546 bytes. It has five wrong direct
   targets and four boundary escapes.
2. The current clean-main source differs by 73 bytes. Its direct targets and
   boundaries are clean.

Neither baseline supports promotion. The 1546-byte result contains a bad
cascade. Do not infer owner conclusions from that cascade. Future recovery
must establish the canonical source and ABI before any equivalence claim.

`004D68A0` is scratch and has no exact translation-unit registration. Its
current recovery lead is disqualified by reversed left/right fault order and a
wrong non-const direct target. Future source work must include canonical
`aiconitm.h` and call `const ConstructionItem::buildAttempts`. Do not add a
local declaration. Do not accept drift for this owner.

## Scoped validation

The focused group check used `tools/validate_candidate_tu.py` with the seven
registered owners, both scratch rows, and generated `004D5E90`. The legacy
wrapper was checked directly because this cleanup has no source manifest.

| VA | kind | result | bytes | owner | relocation target mismatches | boundary escapes |
| --- | --- | --- | ---: | --- | ---: | ---: |
| `004D5E60` | exact | MATCH | 0 | match | 0 | 0 |
| `004D5EB0` | exact | MATCH | 0 | match | 0 | 0 |
| `004D5EE0` | exact | MATCH | 0 | match | 0 | 0 |
| `004D5EF0` | exact | MATCH | 0 | match | 0 | 0 |
| `004D5F00` | exact | MATCH | 0 | match | 0 | 0 |
| `004D6780` | exact | MATCH | 0 | match | 0 | 0 |
| `004D6800` | exact | MATCH | 0 | match | 0 | 0 |
| `004D60E0` | observed scratch | MISMATCH | 85 | match | 0 | 0 |
| `004D68A0` | observed scratch | MATCH | 0 | match | 0 | 0 |
| `004D5E90` | generated | MATCH | 0 | unverified | 0 | 0 |

The seven registered owners and generated destructor match. `004D60E0`
remains scratch. Its observed grouped row is a separate clean-source check
with an original 1689-byte boundary; the two baselines above remain the
status evidence. `004D68A0` remains scratch despite the byte result because
its source lead has the disqualifying reversed left/right fault order and
wrong non-const direct target.
