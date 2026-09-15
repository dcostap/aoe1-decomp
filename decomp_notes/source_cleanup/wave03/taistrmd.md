# `src/taistrmd.cpp` cleanup report

## Commits and scope

- Module: `src/taistrmd.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `618afdf75a43932587f703a2f8b78e985bce30a8`
- Changed source file: `src/taistrmd.cpp`
- Changed report file: `decomp_notes/source_cleanup/wave03/taistrmd.md`
- Read-only header: `include/taistrmd.h`; it was not edited.
- No other tracked file changed.

The source change recovers original local and parameter names from the scoped
PDB. It keeps the existing function bodies, types, storage, order, literals,
calls, casts, and control flow. It does not change public symbols or headers.

## Evidence

The main evidence is:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  SHA256 `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
  SHA256 `aead4dde6d2839dbd667e0c2d1a2f266ca19c8e559ae23757c969c4c443de8b8`.
- Registry:
  `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/taistrmd.cpp.json`.
  SHA256 `8bf485484338fc40f320d4f9af00b087e559285f37b66140167cf40a0208796a`.
- PDB source path: `C:\msdev\work\age1_x1\taistrmd.cpp`.
- Pinned toolchain configuration:
  `C:/Projects/my_decomps/aoe1_attempt3/config/toolchain.json`.
  The source owner uses the registry `gx` flag profile.

Available registry-selected packets were inspected:

- `inventory/functions/004E/004E6E10_VictoryConditionRuleSystem.txt`,
  SHA256 `1b6cfac3e7078587f9ea92904e16be9b34160130bfa8e9029cae851150140f9a`.
  It covers `004E6E10-004E740A`, 1,531 bytes, and PDB lines 34-265.
- `inventory/functions/004E/004E7440_loadRules.txt`,
  SHA256 `cc81f3e6290f957638282d9d2d82ad39d64c2f94bdc94c13aa1015f9cebc0d63`.
  It covers `004E7440-004E75C9`, 394 bytes, and PDB lines 276-317.
- `inventory/functions/004E/004EA810_isRuleIdle.txt`,
  SHA256 `7c0c0174a4366dd368aeaff5cb49a1d4ee5ecc9656f772927276077940d38ac8`.
  It covers `004EA810-004EA857`, 72 bytes, and PDB lines 1622-1626.

The PDB register record is `this` in `ecx` for every listed procedure. The
following table records every registry function. Stack names include their
PDB stack offsets. A blank entry means that PDB scope had no stack name.

## Complete original-name recovery coverage

| VA | Source function | PDB parameters and locals | Recovery result |
| --- | --- | --- | --- |
| `004E6E10` | `VictoryConditionRuleSystem::VictoryConditionRuleSystem` | none | No source name needed. |
| `004E7430` | `VictoryConditionRuleSystem::~VictoryConditionRuleSystem` | none | No source name needed. |
| `004E7440` | `VictoryConditionRuleSystem::loadRules` | `rName` `char*` `+0x4`; `temp` `char[256]` `-0x100`; `commentTemp2` `char` `-0x109`; `commentTemp1` `char` `-0x10A`; `ruleValue` `int` `-0x104`; `ruleIndex` `int` `-0x108` | Recovered `rName`. Existing local names already match. |
| `004E75D0` | `VictoryConditionRuleSystem::setRule` | `ruleIndex` `int` `+0x4`; `ruleValue` `int` `+0x8` | Recovered both names. |
| `004E75F0` | `VictoryConditionRuleSystem::rule` | `ruleIndex` `int` `+0x4` | Recovered `ruleIndex`. |
| `004E7610` | `VictoryConditionRuleSystem::evaluateAsInProgress` | `p` `TRIBE_Player*` `+0x4`; `ruleNumber` `int` `+0x8` | Recovered both names. |
| `004E7620` | `VictoryConditionRuleSystem::evaluateAsNonInProgress` | `p` `TRIBE_Player*` `+0x4`; `ruleNumber` `int` `+0x8` | Recovered both names. |
| `004E7690` | `VictoryConditionRuleSystem::execute` | `p` `TRIBE_Player*` `+0x4`; `vcNumber` `int` `+0x8`; `ruleNumber` `int` `+0xC` | Recovered all three names. |
| `004E8D10` | `VictoryConditionRuleSystem::stopExecution` | `p` `TRIBE_Player*` `+0x4`; `ruleNumber` `int` `+0x8` | Recovered both names. |
| `004E8D20` | `VictoryConditionRuleSystem::modifyForDifficultyLevel` | `dL` `int` `+0x4`; `scale3` `float` `-0x8`; `scale1` `float` `-0xC` | Recovered `dL`. Renamed the existing second scale field to `scale3`. |
| `004E9100` | `TribeStrategyAIModule::TribeStrategyAIModule(void*, int)` | `pW` `void*` `+0x4`; `playerID` `int` `+0x8` | Recovered `pW`; `playerID` was already present. |
| `004E9260` | `TribeStrategyAIModule::TribeStrategyAIModule(int, int)` | `playerID` `int` `+0x4`; `infile` `int` `+0x8`; `tempIntNum` `int` `-0x18`; `i` `int` `-0x1C`; `tempInt` `int` `+0x8` | Existing names match all PDB records. The `tempInt` record reuses the `infile` stack offset. |
| `004E9730` | `TribeStrategyAIModule::~TribeStrategyAIModule` | none | No source name needed. |
| `004E9820` | `TribeStrategyAIModule::update` | `timeLimit` `int` `+0x4`; `bestRule` `int` `-0x8`; `worstRule` `int` `-0x4`; `worstRuleResult` `int` `-0x8`; `result` `int` `-0x4` | Recovered `timeLimit`, `bestRule`, `worstRule`, and `worstRuleResult`. Existing `result` matches. PDB offsets are reused across separate phases. |
| `004E9D90` | `TribeStrategyAIModule::setMainDecisionAI` | `m` `TribeMainDecisionAIModule*` `+0x4` | Recovered `m`. |
| `004E9DA0` | `TribeStrategyAIModule::save` | `outfile` `int` `+0x4`; `tempString` `char[257]` `-0x104`; `tempInt` `int` `-0x108` | Recovered `outfile` and `tempInt`. Existing `tempString` matches the PDB name. |
| `004EA130` | `TribeStrategyAIModule::ruleSetName` | none | No source name needed. |
| `004EA140` | `TribeStrategyAIModule::loadRules` | `rName` `char*` `+0x4` | Recovered `rName`. |
| `004EA180` | `TribeStrategyAIModule::setRule` | `ruleIndex` `int` `+0x4`; `value` `int` `+0x8` | Recovered `ruleIndex`; existing `value` matches. |
| `004EA1B0` | `TribeStrategyAIModule::rule` | `ruleIndex` `int` `+0x4` | Recovered `ruleIndex`. |
| `004EA1D0` | `TribeStrategyAIModule::setDifficultyLevel` | `difficultyLevel` `int` `+0x4` | Recovered `difficultyLevel`. |
| `004EA1F0` | `TribeStrategyAIModule::currentVictoryCondition` | none | No source name needed. |
| `004EA200` | `TribeStrategyAIModule::targetID` | none | No source name needed. |
| `004EA210` | `TribeStrategyAIModule::targetType` | none | No source name needed. |
| `004EA220` | `TribeStrategyAIModule::secondTargetID` | none | No source name needed. |
| `004EA230` | `TribeStrategyAIModule::secondTargetType` | none | No source name needed. |
| `004EA240` | `TribeStrategyAIModule::targetPoint1` | none | No source name needed. |
| `004EA250` | `TribeStrategyAIModule::targetPoint2` | none | No source name needed. |
| `004EA260` | `TribeStrategyAIModule::targetAttribute` | none | No source name needed. |
| `004EA270` | `TribeStrategyAIModule::targetNumber` | none | No source name needed. |
| `004EA280` | `TribeStrategyAIModule::setVictoryCondition` | `vcNumber` `int` `+0x4` | Recovered `vcNumber`. |
| `004EA7C0` | `TribeStrategyAIModule::isRuleExecuting` | `ruleNumber` `int` `+0x4` | Recovered `ruleNumber`. |
| `004EA810` | `TribeStrategyAIModule::isRuleIdle` | `ruleNumber` `int` `+0x4` | Recovered `ruleNumber`. |

The registry contains 33 handwritten functions. All 33 received procedure-
scoped PDB inspection. The PDB also records compiler-generated scalar
deleting destructors at `004E7410` and `004E9240`. They have `this` in `ecx`
and `__flags` at `+0x4`. They have no handwritten source owner and remain
unchanged.

### Unresolved declaration mappings

The PDB does not record every optimized source declaration. I left these
existing names unchanged:

- `loadRules`: `file` has no procedure-scoped PDB name.
- `modifyForDifficultyLevel`: `ScaleLocals`, `locals`, `add1`, `add2`,
  `add3`, and `tmp` have no PDB name. The PDB identifies only `scale1` and
  `scale3` among these fields.
- `update`: `i`, `bestResult`, `victoryCondition`, and `entry` have no PDB
  name. The PDB identifies the phase-specific `bestRule`, `worstRule`,
  `worstRuleResult`, and `result` names.
- `save`: `i`, `newMax`, `newArr`, and `j` have no PDB name.
- `setVictoryCondition`: `rules`, `v`, `i`, the loop `rule`, and `result`
  have no PDB name.
- `isRuleExecuting` and `isRuleIdle`: the loop `i` has no PDB name.

The current source declares `tempString` as `char[260]`. The PDB type record
reports `char[257]` at the same stack region. This wave does not change that
type or declaration arrangement. The discrepancy remains open for a separate
source-recovery review.

## Constants, comments, and resources

No new constant or enum was added. Existing strategic-number literals and
bounds remain unchanged. Existing casts and literal types remain unchanged.
No resource ID or resource lookup occurs in this module. Resource extraction
was not needed. No shared resource mapping request is open.

No source comment was added. The existing parser comment remains because the
source ignores both `sscanf` return values and preserves the malformed-input
behavior. Existing layout and call-target notes also remain unchanged. These
comments do not claim new behavior.

Recovered original spellings are the names stated in the PDB coverage table,
including mixed forms such as `rName`, `pW`, `dL`, and `vcNumber`. No new
cleanup names were invented. Existing names without PDB records were retained
rather than relabeled as original names.

## Generation and ownership risks

- The changes rename parameters and local declarations only.
- No type, storage duration, scope, declaration order, or evaluation order changed.
- No public function, member, class, global, ABI symbol, or virtual slot changed.
- The `p` rename updates every use in `VictoryConditionRuleSystem::execute`.
- The `scale2` to `scale3` change restores the PDB name for the second float
  at the PDB `-0x8` stack slot. It changes no field type or layout.
- The existing `ScaleLocals` helper and the `char[260]` save buffer remain
  unresolved source forms. They can affect compiler output and need later
  validation.
- No header change or shared declaration request is needed.
- The source diff was reviewed with `git diff --check` and a complete diff
  review. This does not prove generated-code equality.

Compilation, matching, audits, and tests were not run. Builds, compiler
checks, games, and runtime validation were not run.
