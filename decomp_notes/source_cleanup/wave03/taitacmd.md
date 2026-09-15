# `taitacmd.cpp` source-cleanup correction report

## Delivery identity

- Module: `src/taitacmd.cpp`.
- Common base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Previous source-cleanup commit: `a593951d6517d85078efd5a9d70c6300f22a9db5`.
- Correction source commit: `2b9bd67624c4c302b583f4cb57c00846266bac74`.
- Final source commit: `2b9bd67624c4c302b583f4cb57c00846266bac74`.
- The final report commit follows this source commit and changes this report only.

## Changed files

- `src/taitacmd.cpp`.
- `decomp_notes/source_cleanup/wave03/taitacmd.md`.

No header, registry, inventory, resource file, or shared source file changed.

## Evidence paths

- PDB procedure records: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
- Assigned function registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/taitacmd.cpp.json`.
- Source owner: `C:/Projects/my_decomps/aoe1_attempt3/src/taitacmd.cpp`.
- Representative original packet: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004EA9C0_load.txt`.
- Task original packet: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004EB6F0_task.txt`.
- Constructor original packet: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004ED4F0_TribeTacticalAIModule.txt`.
- Toolchain record: `C:/Projects/my_decomps/aoe1_attempt3/config/toolchain.json`.
- Baseline flags: `C:/Projects/my_decomps/aoe1_attempt3/config/flags/default.rsp`.
- Cleanup policy: `C:/Projects/my_decomps/aoe1_attempt3/docs/source_cleanup.md`.
- Comment policy: `C:/Projects/my_decomps/aoe1_attempt3/docs/source_comments.md`.
- Resource policy: `C:/Projects/my_decomps/aoe1_attempt3/docs/resource_ids.md`.
- Ownership policy: `C:/Projects/my_decomps/aoe1_attempt3/docs/source_cleanup_owners.md`.

## Procedure-scoped PDB coverage

The registry contains 216 assigned procedures. The PDB inventory contains a procedure record for every assigned VA. The table below lists all 216 registered procedures.

The stack column lists every procedure-scoped stack record. Positive offsets normally hold parameters. The PDB can reuse positive offsets for locals. Negative offsets normally hold locals. The table keeps all records so reused slots remain visible. The register column lists every procedure-scoped register record.

| VA | Registered symbol | PDB procedure | PDB stack records: parameters and locals | PDB registers |
| --- | --- | --- | --- | --- |
| `004EA860` | `??0TacticalAIGroup@@QAE@XZ` | `TacticalAIGroup::TacticalAIGroup` | — | this @ ecx: TacticalAIGroup* |
| `004EA9B0` | `??1TacticalAIGroup@@UAE@XZ` | `TacticalAIGroup::~TacticalAIGroup` | — | this @ ecx: TacticalAIGroup* |
| `004EA9C0` | `?load@TacticalAIGroup@@QAEHH@Z` | `TacticalAIGroup::load` | infile @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EACA0` | `?save@TacticalAIGroup@@QAEHH@Z` | `TacticalAIGroup::save` | outfile @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EAF20` | `?id@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::id` | — | this @ ecx: const TacticalAIGroup* |
| `004EAF30` | `?setID@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setID` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EAF40` | `?inUse@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::inUse` | — | this @ ecx: const TacticalAIGroup* |
| `004EAF50` | `?setInUse@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setInUse` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EAF60` | `?type@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::type` | — | this @ ecx: const TacticalAIGroup* |
| `004EAF70` | `?setType@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setType` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EAF80` | `?subType@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::subType` | — | this @ ecx: const TacticalAIGroup* |
| `004EAF90` | `?setSubType@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setSubType` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EAFA0` | `?addUnit@TacticalAIGroup@@QAEHHPAVTribeMainDecisionAIModule@@@Z` | `TacticalAIGroup::addUnit` | id @ +0x4: int; md @ +0x8: TribeMainDecisionAIModule* | this @ ecx: TacticalAIGroup* |
| `004EB030` | `?removeUnit@TacticalAIGroup@@QAEHHPAVTribeMainDecisionAIModule@@@Z` | `TacticalAIGroup::removeUnit` | id @ +0x4: int; md @ +0x8: TribeMainDecisionAIModule* | this @ ecx: TacticalAIGroup* |
| `004EB0C0` | `?removeUnitByIndex@TacticalAIGroup@@QAEHHPAVTribeMainDecisionAIModule@@@Z` | `TacticalAIGroup::removeUnitByIndex` | index @ +0x4: int; md @ +0x8: TribeMainDecisionAIModule* | this @ ecx: TacticalAIGroup* |
| `004EB140` | `?removeUnits@TacticalAIGroup@@QAEXPAVTribeMainDecisionAIModule@@@Z` | `TacticalAIGroup::removeUnits` | md @ +0x4: TribeMainDecisionAIModule* | this @ ecx: TacticalAIGroup* |
| `004EB180` | `?removeExtraUnits@TacticalAIGroup@@QAEHPAVTribeMainDecisionAIModule@@@Z` | `TacticalAIGroup::removeExtraUnits` | md @ +0x4: TribeMainDecisionAIModule* | this @ ecx: TacticalAIGroup* |
| `004EB1F0` | `?removeUnboardedUnits@TacticalAIGroup@@QAEHPAVTribeTacticalAIModule@@PAVTribeMainDecisionAIModule@@@Z` | `TacticalAIGroup::removeUnboardedUnits` | t @ +0x4: TribeTacticalAIModule*; md @ +0x8: TribeMainDecisionAIModule* | this @ ecx: TacticalAIGroup* |
| `004EB290` | `?containsUnit@TacticalAIGroup@@QAEHH@Z` | `TacticalAIGroup::containsUnit` | id @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EB2C0` | `?numberUnits@TacticalAIGroup@@QAEHXZ` | `TacticalAIGroup::numberUnits` | — | this @ ecx: TacticalAIGroup* |
| `004EB2D0` | `?unit@TacticalAIGroup@@QAEHH@Z` | `TacticalAIGroup::unit` | i @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EB320` | `?unitOriginalHitPoints@TacticalAIGroup@@QAEHH@Z` | `TacticalAIGroup::unitOriginalHitPoints` | i @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EB370` | `?desiredNumberUnits@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::desiredNumberUnits` | — | this @ ecx: const TacticalAIGroup* |
| `004EB380` | `?setDesiredNumberUnits@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setDesiredNumberUnits` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EB390` | `?commander@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::commander` | — | this @ ecx: const TacticalAIGroup* |
| `004EB3A0` | `?setSpecificCommander@TacticalAIGroup@@QAEXHPAVTribeMainDecisionAIModule@@@Z` | `TacticalAIGroup::setSpecificCommander` | id @ +0x4: int; md @ +0x8: TribeMainDecisionAIModule*; temp @ -0xa0: int[40] | this @ ecx: TacticalAIGroup* |
| `004EB430` | `?currentHitPoints@TacticalAIGroup@@QBEHPAVTribeMainDecisionAIModule@@@Z` | `TacticalAIGroup::currentHitPoints` | md @ +0x4: TribeMainDecisionAIModule* | this @ ecx: const TacticalAIGroup* |
| `004EB470` | `?originalHitPoints@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::originalHitPoints` | — | this @ ecx: const TacticalAIGroup* |
| `004EB480` | `?setOriginalHitPoints@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setOriginalHitPoints` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EB490` | `?originalUnitNumber@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::originalUnitNumber` | — | this @ ecx: const TacticalAIGroup* |
| `004EB4A0` | `?setOriginalUnitNumber@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setOriginalUnitNumber` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EB4B0` | `?location@TacticalAIGroup@@QBEABUWaypoint@@XZ` | `TacticalAIGroup::location` | — | this @ ecx: const TacticalAIGroup* |
| `004EB4C0` | `?setLocation@TacticalAIGroup@@QAEXMMM@Z` | `TacticalAIGroup::setLocation` | x @ +0x4: float; y @ +0x8: float; z @ +0xc: float | this @ ecx: TacticalAIGroup* |
| `004EB4F0` | `?action@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::action` | — | this @ ecx: const TacticalAIGroup* |
| `004EB500` | `?setAction@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setAction` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EB510` | `?target@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::target` | — | this @ ecx: const TacticalAIGroup* |
| `004EB520` | `?setTarget@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setTarget` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EB530` | `?targetType@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::targetType` | — | this @ ecx: const TacticalAIGroup* |
| `004EB540` | `?setTargetType@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setTargetType` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EB550` | `?targetLocation@TacticalAIGroup@@QBEABUWaypoint@@XZ` | `TacticalAIGroup::targetLocation` | — | this @ ecx: const TacticalAIGroup* |
| `004EB560` | `?setAllLocations@TacticalAIGroup@@QAEXMMM@Z` | `TacticalAIGroup::setAllLocations` | x @ +0x4: float; y @ +0x8: float; z @ +0xc: float | this @ ecx: TacticalAIGroup* |
| `004EB5C0` | `?setTargetLocation@TacticalAIGroup@@QAEXMMM@Z` | `TacticalAIGroup::setTargetLocation` | x @ +0x4: float; y @ +0x8: float; z @ +0xc: float | this @ ecx: TacticalAIGroup* |
| `004EB5F0` | `?gatherLocation@TacticalAIGroup@@QBEABUWaypoint@@XZ` | `TacticalAIGroup::gatherLocation` | — | this @ ecx: const TacticalAIGroup* |
| `004EB600` | `?setGatherLocation@TacticalAIGroup@@QAEXMMM@Z` | `TacticalAIGroup::setGatherLocation` | x @ +0x4: float; y @ +0x8: float; z @ +0xc: float | this @ ecx: TacticalAIGroup* |
| `004EB630` | `?retreatLocation@TacticalAIGroup@@QBEABUWaypoint@@XZ` | `TacticalAIGroup::retreatLocation` | — | this @ ecx: const TacticalAIGroup* |
| `004EB640` | `?setRetreatLocation@TacticalAIGroup@@QAEXMMM@Z` | `TacticalAIGroup::setRetreatLocation` | x @ +0x4: float; y @ +0x8: float; z @ +0xc: float | this @ ecx: TacticalAIGroup* |
| `004EB670` | `?priority@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::priority` | — | this @ ecx: const TacticalAIGroup* |
| `004EB680` | `?setPriority@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setPriority` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EB690` | `?waitCode@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::waitCode` | — | this @ ecx: const TacticalAIGroup* |
| `004EB6A0` | `?setWaitCode@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setWaitCode` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EB6B0` | `?assistGroupID@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::assistGroupID` | — | this @ ecx: const TacticalAIGroup* |
| `004EB6C0` | `?setAssistGroupID@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setAssistGroupID` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EB6D0` | `?assistGroupType@TacticalAIGroup@@QBEHXZ` | `TacticalAIGroup::assistGroupType` | — | this @ ecx: const TacticalAIGroup* |
| `004EB6E0` | `?setAssistGroupType@TacticalAIGroup@@QAEXH@Z` | `TacticalAIGroup::setAssistGroupType` | v @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004EB6F0` | `?task@TacticalAIGroup@@QAEHPAVTribeTacticalAIModule@@PAVTribeMainDecisionAIModule@@HHH@Z` | `TacticalAIGroup::task` | t @ +0x4: TribeTacticalAIModule*; md @ +0x8: TribeMainDecisionAIModule*; taskID @ +0xc: int; resetOriginal @ +0x10: int; overrideCurrentAction @ +0x14: int; i @ +0x18: int; oHP @ +0x10: int; i @ +0x8: int; commanderObj @ -0x14: RGE_Static_Object*; commanderZone @ -0x18: int; gatherRange @ -0x1c: float; distance @ +0x14: float; i @ +0x14: int; randomRoll @ -0x14: int; i @ +0x10: int; oHP @ +0x8: int; i @ +0x10: int; oHP @ +0x8: int; i @ +0x10: int; oHP @ +0x8: int; firstTime @ -0x18: int; i @ +0x8: int; oHP @ -0x1c: int; targetObj @ -0x14: RGE_Static_Object*; min @ -0x10: XYPoint; max @ -0x8: XYPoint; i @ +0x10: int; oHP @ +0x8: int; distance @ -0x14: float; i @ +0x10: int; oHP @ +0x8: int; i @ +0x10: int; oHP @ +0x8: int; i @ +0x18: int; oHP @ +0x10: int | this @ ecx: TacticalAIGroup* |
| `004ECD80` | `?isGathered@TacticalAIGroup@@QAEHPAVTribeTacticalAIModule@@PAVTribeMainDecisionAIModule@@@Z` | `TacticalAIGroup::isGathered` | t @ +0x4: TribeTacticalAIModule*; md @ +0x8: TribeMainDecisionAIModule*; distance @ -0x8: float | this @ ecx: TacticalAIGroup* |
| `004ECE70` | `?isTightGathered@TacticalAIGroup@@QAEHPAVTribeTacticalAIModule@@PAVTribeMainDecisionAIModule@@@Z` | `TacticalAIGroup::isTightGathered` | t @ +0x4: TribeTacticalAIModule*; md @ +0x8: TribeMainDecisionAIModule* | this @ ecx: TacticalAIGroup* |
| `004ECF10` | `?allUnitsIdle@TacticalAIGroup@@QAEHPAVTribeMainDecisionAIModule@@H@Z` | `TacticalAIGroup::allUnitsIdle` | md @ +0x4: TribeMainDecisionAIModule*; countAttackAsIdle @ +0x8: int | this @ ecx: TacticalAIGroup* |
| `004ECFE0` | `?consecutiveIdleUnitCount@TacticalAIGroup@@QBEKXZ` | `TacticalAIGroup::consecutiveIdleUnitCount` | — | this @ ecx: const TacticalAIGroup* |
| `004ECFF0` | `?setConsecutiveIdleUnitCount@TacticalAIGroup@@QAEXK@Z` | `TacticalAIGroup::setConsecutiveIdleUnitCount` | v @ +0x4: unsigned long | this @ ecx: TacticalAIGroup* |
| `004ED000` | `?incrementConsecutiveIdleUnitCount@TacticalAIGroup@@QAEXK@Z` | `TacticalAIGroup::incrementConsecutiveIdleUnitCount` | v @ +0x4: unsigned long | this @ ecx: TacticalAIGroup* |
| `004ED020` | `?numberAttackWaypoints@TacticalAIGroup@@QBEEXZ` | `TacticalAIGroup::numberAttackWaypoints` | — | this @ ecx: const TacticalAIGroup* |
| `004ED030` | `?currentAttackWaypoint@TacticalAIGroup@@QBEEXZ` | `TacticalAIGroup::currentAttackWaypoint` | — | this @ ecx: const TacticalAIGroup* |
| `004ED040` | `?setCurrentAttackWaypoint@TacticalAIGroup@@QAEXE@Z` | `TacticalAIGroup::setCurrentAttackWaypoint` | v @ +0x4: unsigned char | this @ ecx: TacticalAIGroup* |
| `004ED060` | `?addAttackWaypoint@TacticalAIGroup@@QAEXMM@Z` | `TacticalAIGroup::addAttackWaypoint` | x @ +0x4: float; y @ +0x8: float | this @ ecx: TacticalAIGroup* |
| `004ED0C0` | `?attackWaypoint@TacticalAIGroup@@QAEPAUWaypoint@@E@Z` | `TacticalAIGroup::attackWaypoint` | v @ +0x4: unsigned char | this @ ecx: TacticalAIGroup* |
| `004ED0F0` | `?firstIdleUnit@TacticalAIGroup@@QAEHPAVTribeMainDecisionAIModule@@@Z` | `TacticalAIGroup::firstIdleUnit` | md @ +0x4: TribeMainDecisionAIModule* | this @ ecx: TacticalAIGroup* |
| `004ED170` | `?objectToDestroy@TacticalAIGroup@@QAEHH@Z` | `TacticalAIGroup::objectToDestroy` | n @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004ED190` | `?addObjectToDestroy@TacticalAIGroup@@QAEHH@Z` | `TacticalAIGroup::addObjectToDestroy` | id @ +0x4: int | this @ ecx: TacticalAIGroup* |
| `004ED1C0` | `??0TribeTacticalAIModule@@QAE@PAXH@Z` | `TribeTacticalAIModule::TribeTacticalAIModule` | pW @ +0x4: void*; pID @ +0x8: int | this @ ecx: TribeTacticalAIModule* |
| `004ED4F0` | `??0TribeTacticalAIModule@@QAE@HH@Z` | `TribeTacticalAIModule::TribeTacticalAIModule` | pID @ +0x4: int; infile @ +0x8: int; tempIntNum @ +0x8: int; i @ -0x30: int; tempInt @ -0x2c: int; tempUD @ -0x20: OldUnitData2; tempUD @ -0x20: OldUnitData | this @ ecx: TribeTacticalAIModule* |
| `004EEB40` | `??1TribeTacticalAIModule@@UAE@XZ` | `TribeTacticalAIModule::~TribeTacticalAIModule` | — | this @ ecx: TribeTacticalAIModule* |
| `004EEE40` | `?updateAreaName@TribeTacticalAIModule@@QAEPADXZ` | `TribeTacticalAIModule::updateAreaName` | — | this @ ecx: TribeTacticalAIModule* |
| `004EEF40` | `?update@TribeTacticalAIModule@@UAEHH@Z` | `TribeTacticalAIModule::update` | timeLimit @ +0x4: int; mostHatedPlayer @ -0x8: int; mostLikedPlayer @ -0x4: int | this @ ecx: TribeTacticalAIModule* |
| `004EF4D0` | `?setMainDecisionAI@TribeTacticalAIModule@@QAEXPAVTribeMainDecisionAIModule@@@Z` | `TribeTacticalAIModule::setMainDecisionAI` | m @ +0x4: TribeMainDecisionAIModule* | this @ ecx: TribeTacticalAIModule* |
| `004EF4E0` | `?save@TribeTacticalAIModule@@UAEHH@Z` | `TribeTacticalAIModule::save` | outfile @ +0x4: int; tempInt @ -0x4: int | this @ ecx: TribeTacticalAIModule* |
| `004F0180` | `?logGroupDebug@TribeTacticalAIModule@@QAAXHPADZZ` | `TribeTacticalAIModule::logGroupDebug` | this @ +0x4: TribeTacticalAIModule*; gID @ +0x8: int; textIn @ +0xc: char* | — |
| `004F0190` | `?doSomething@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::doSomething` | startTime @ -0x11c: unsigned long; availableTime @ -0x120: unsigned long; incUpdateArea @ -0x128: int; updateAreaStartTime @ -0x124: unsigned long; tempName @ -0x100: char[256]; position @ -0x108: XYPoint; position @ -0x118: XYPoint; position @ -0x110: XYPoint | this @ ecx: TribeTacticalAIModule* |
| `004F0BC0` | `?clearArea@TribeTacticalAIModule@@QAEHHMMMM@Z` | `TribeTacticalAIModule::clearArea` | id @ +0x4: int; minX @ +0x8: float; minY @ +0xc: float; maxX @ +0x10: float; maxY @ +0x14: float; newY @ -0x8: float; newX @ -0x4: float; tempY @ -0x10: float; tempX @ -0x14: float; bestDistance @ -0xc: float | this @ ecx: TribeTacticalAIModule* |
| `004F0D70` | `?addObject@TribeTacticalAIModule@@QAEXPAVRGE_Static_Object@@@Z` | `TribeTacticalAIModule::addObject` | bo @ +0x4: RGE_Static_Object* | this @ ecx: TribeTacticalAIModule* |
| `004F1090` | `?removeObject@TribeTacticalAIModule@@QAEXH@Z` | `TribeTacticalAIModule::removeObject` | id @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `004F13F0` | `?evaluateCivilianDistribution@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::evaluateCivilianDistribution` | — | this @ ecx: TribeTacticalAIModule* |
| `004F1600` | `?taskCivilians@TribeTacticalAIModule@@QAEHKK@Z` | `TribeTacticalAIModule::taskCivilians` | startTime @ +0x4: unsigned long; availableTime @ +0x8: unsigned long; taskedCount @ -0xc: int; newExplorer @ -0x10: int; tcPosition @ -0x8: XYPoint; j @ -0x14: int; tcPosition @ -0x8: XYPoint | this @ ecx: TribeTacticalAIModule* |
| `004F1E10` | `?taskIdleSoldiers@TribeTacticalAIModule@@QAEXKK@Z` | `TribeTacticalAIModule::taskIdleSoldiers` | startTime @ +0x4: unsigned long; availableTime @ +0x8: unsigned long; isGathered @ -0xc: int; readyToTask @ -0x10: int | this @ ecx: TribeTacticalAIModule* |
| `004F21F0` | `?taskActiveSoldiers@TribeTacticalAIModule@@QAEXKK@Z` | `TribeTacticalAIModule::taskActiveSoldiers` | startTime @ +0x4: unsigned long; availableTime @ +0x8: unsigned long; attackAsAttack @ -0xcc: int; point @ -0xa8: XYZPoint; pathDistance @ -0x78: float; gatherX @ -0x8: float; gatherY @ -0x2c: float; point @ -0xb8: XYZPoint; defendDistance @ -0xd0: float; pathDistance @ -0x74: float; gatherX @ -0x10: float; gatherY @ -0x4: float; point @ -0x90: XYZPoint; pathDistance @ -0x7c: float; townCenter @ -0xd0: RGE_Static_Object*; gatherX @ -0xc: float; gatherY @ -0x18: float; targetPoint @ -0x38: XYZPoint; commanderPoint @ -0x70: XYPoint; taskedToEnter @ -0xc8: int; a @ -0xcc: int; unitObj @ -0xd0: RGE_Static_Object*; targetZone @ -0xac: unsigned char; j @ -0xd0: int; startPoint @ -0x24: XYPoint; stagingPoint @ -0xc0: XYPoint; allInsideTransport @ -0xc8: int; unit @ -0xcc: RGE_Static_Object*; j @ -0xcc: int; allOutsideTransport @ -0xc8: int; j @ -0xd0: int; transportObject @ -0x80: RGE_Action_Object*; allInsideTransport @ -0xcc: int; tGroup @ -0xc4: TacticalAIGroup*; targetObj @ -0x5c: RGE_Static_Object*; commanderObj @ -0xd0: RGE_Static_Object*; point @ -0x9c: XYZPoint; pathDistance @ -0x84: float; gatherX @ -0x1c: float; gatherY @ -0x28: float; unitObj @ -0xc4: RGE_Static_Object*; commanderObj @ -0xd0: RGE_Static_Object*; point @ -0x68: XYZPoint; pathDistance @ -0x14: float; tAreaMax @ -0x48: Waypoint; tAreaMin @ -0x58: Waypoint | this @ ecx: TribeTacticalAIModule* |
| `004F4760` | `?playTaskSoldiers@TribeTacticalAIModule@@QAEXKK@Z` | `TribeTacticalAIModule::playTaskSoldiers` | startTime @ +0x4: unsigned long; availableTime @ +0x8: unsigned long; unplayedSoldiers @ -0x190: int[50]; target @ -0x1a0: ObjectMemory*; playToRun @ -0x194: int; playUnits @ -0xc8: int[50]; playCommander @ -0x198: int; countUnplayedSoldiers @ -0x1a4: int; numberPlayUnits @ -0x19c: int | this @ ecx: TribeTacticalAIModule* |
| `004F4AA0` | `?taskUngroupedSoldiers@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::taskUngroupedSoldiers` | i @ -0x1c: int; centerPoint @ -0x10: XYPoint; soldierObj @ -0x14: RGE_Static_Object*; gatherPoint @ -0x8: XYPoint | this @ ecx: TribeTacticalAIModule* |
| `004F4D90` | `?taskBoats@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::taskBoats` | isGathered @ -0x60: int; exclusions @ -0x14: int[5]; numExclusions @ -0x60: int; dropsiteID @ -0x54: int; a @ -0x4c: int; point @ -0x38: XYZPoint; rYPos @ -0x58: float; rXPos @ -0x5c: float; point @ -0x2c: XYZPoint; pathDistance @ -0x40: float; rYPos @ -0x48: float; dropsiteID @ -0x4c: int; rXPos @ -0x44: float; point @ -0x20: XYZPoint; pathDistance @ -0x3c: float | this @ ecx: TribeTacticalAIModule* |
| `004F57C0` | `?evaluateOpenTasks@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::evaluateOpenTasks` | i @ -0x10: int | this @ ecx: TribeTacticalAIModule* |
| `004F5FB0` | `?evaluateBuildListInsertions@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::evaluateBuildListInsertions` | — | this @ ecx: TribeTacticalAIModule* |
| `004F6100` | `?numberCivilians@TribeTacticalAIModule@@QBEHXZ` | `TribeTacticalAIModule::numberCivilians` | — | this @ ecx: const TribeTacticalAIModule* |
| `004F6110` | `?numberCivilianExplorers@TribeTacticalAIModule@@QBEHXZ` | `TribeTacticalAIModule::numberCivilianExplorers` | — | this @ ecx: const TribeTacticalAIModule* |
| `004F6120` | `?numberGatherers@TribeTacticalAIModule@@QBEHXZ` | `TribeTacticalAIModule::numberGatherers` | — | this @ ecx: const TribeTacticalAIModule* |
| `004F6130` | `?desiredNumberCivilianExplorers@TribeTacticalAIModule@@QBEHXZ` | `TribeTacticalAIModule::desiredNumberCivilianExplorers` | — | this @ ecx: const TribeTacticalAIModule* |
| `004F6140` | `?desiredNumberGatherers@TribeTacticalAIModule@@QBEHXZ` | `TribeTacticalAIModule::desiredNumberGatherers` | — | this @ ecx: const TribeTacticalAIModule* |
| `004F6150` | `?numberSoldiers@TribeTacticalAIModule@@QBEHXZ` | `TribeTacticalAIModule::numberSoldiers` | — | this @ ecx: const TribeTacticalAIModule* |
| `004F6160` | `?numberSoldierExplorers@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberSoldierExplorers` | — | this @ ecx: TribeTacticalAIModule* |
| `004F6170` | `?numberBoats@TribeTacticalAIModule@@QBEHXZ` | `TribeTacticalAIModule::numberBoats` | — | this @ ecx: const TribeTacticalAIModule* |
| `004F6180` | `?neededResource@TribeTacticalAIModule@@QBEHH@Z` | `TribeTacticalAIModule::neededResource` | n @ +0x4: int | this @ ecx: const TribeTacticalAIModule* |
| `004F61A0` | `?neededResourceAmount@TribeTacticalAIModule@@QBEHH@Z` | `TribeTacticalAIModule::neededResourceAmount` | n @ +0x4: int | this @ ecx: const TribeTacticalAIModule* |
| `004F61D0` | `?detask@TribeTacticalAIModule@@QAEXH@Z` | `TribeTacticalAIModule::detask` | uid @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `004F6210` | `?strategicNumber@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::strategicNumber` | sNum @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `004F6230` | `?setStrategicNumber@TribeTacticalAIModule@@QAEXHH@Z` | `TribeTacticalAIModule::setStrategicNumber` | sNum @ +0x4: int; v @ +0x8: int | this @ ecx: TribeTacticalAIModule* |
| `004F62C0` | `?notify@TribeTacticalAIModule@@UAEXHHHJJJ@Z` | `TribeTacticalAIModule::notify` | callerID @ +0x4: int; recipientID @ +0x8: int; mType @ +0xc: int; p1 @ +0x10: long; p2 @ +0x14: long; p3 @ +0x18: long; entryTime @ -0x28: unsigned long; callerObject @ -0x24: RGE_Static_Object*; i @ +0x14: int; townCenter @ -0x2c: RGE_Static_Object*; attackPoint @ -0x20: XYPoint; numberToRespond @ -0x30: int; repCount @ +0x10: int; attackedUnit @ +0x10: RGE_Static_Object*; itemToCapture @ +0x14: ObjectMemory*; numberToRespond @ +0x10: int; repCount @ +0x8: int; point @ -0x18: XYZPoint; w @ +0x14: int; distance @ -0x2c: float; targetObj @ -0x2c: RGE_Static_Object*; point @ -0x18: XYZPoint; point @ -0xc: XYZPoint | this @ ecx: TribeTacticalAIModule* |
| `004F7350` | `?numberIdleSoldiers@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberIdleSoldiers` | i @ -0x4: int; count @ -0xc: int | this @ ecx: TribeTacticalAIModule* |
| `004F7590` | `?numberSoldiersWithPriority@TribeTacticalAIModule@@QAEHHHH@Z` | `TribeTacticalAIModule::numberSoldiersWithPriority` | priority @ +0x4: int; flag @ +0x8: int; zeroWorkingArea @ +0xc: int; i @ +0x10: int; count @ -0x8: int | this @ ecx: TribeTacticalAIModule* |
| `004F7870` | `?numberWarshipsWithPriority@TribeTacticalAIModule@@QAEHHH@Z` | `TribeTacticalAIModule::numberWarshipsWithPriority` | priority @ +0x4: int; flag @ +0x8: int; i @ -0xc: int; count @ -0x10: int | this @ ecx: TribeTacticalAIModule* |
| `004F7D90` | `?idleSoldier@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::idleSoldier` | — | this @ ecx: TribeTacticalAIModule* |
| `004F7E80` | `?idleCivilian@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::idleCivilian` | checkGroup @ +0x4: int; i @ -0x8: int; unitObj @ -0x8: RGE_Static_Object*; unitObj @ -0x4: RGE_Static_Object* | this @ ecx: TribeTacticalAIModule* |
| `004F81A0` | `?idleCivilian@TribeTacticalAIModule@@QAEHHAAUXYPoint@@H@Z` | `TribeTacticalAIModule::idleCivilian` | checkGroup @ +0x4: int; point @ +0x8: XYPoint&; closestToPoint @ +0xc: int; i @ -0xc: int; bestUnitID @ -0x8: int; bestUnitDistance @ -0x10: float; unitObj @ -0xc: RGE_Static_Object*; unitObj @ -0x4: RGE_Static_Object* | this @ ecx: TribeTacticalAIModule* |
| `004F8570` | `?civilian@TribeTacticalAIModule@@QAEHAAUXYPoint@@HHHHH@Z` | `TribeTacticalAIModule::civilian` | point @ +0x4: XYPoint&; closestToPoint @ +0x8: int; a1 @ +0xc: int; a2 @ +0x10: int; a3 @ +0x14: int; useFarmers @ +0x18: int; bestUnitID @ -0x4: int; bestUnitDistance @ -0x8: float | this @ ecx: TribeTacticalAIModule* |
| `004F87B0` | `?unit@TribeTacticalAIModule@@QAEHHHH@Z` | `TribeTacticalAIModule::unit` | action @ +0x4: int; target @ +0x8: int; targetType @ +0xc: int | this @ ecx: TribeTacticalAIModule* |
| `004F8BE0` | `?busyWithAction@TribeTacticalAIModule@@QAEHHH@Z` | `TribeTacticalAIModule::busyWithAction` | id @ +0x4: int; a @ +0x8: int | this @ ecx: TribeTacticalAIModule* |
| `004F8C30` | `?displayCivilianDistribution@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::displayCivilianDistribution` | — | this @ ecx: TribeTacticalAIModule* |
| `004F8C40` | `?updateNeededResources@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::updateNeededResources` | assignedResource @ -0x30: int[4]; tempResourceDifference @ -0x10: int[4]; tempNeededResource @ -0x20: int[4] | this @ ecx: TribeTacticalAIModule* |
| `004F8E20` | `?updateGathererDistribution@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::updateGathererDistribution` | i @ -0x4: int; gAction @ -0x8: int; gSTT @ -0xc: int | this @ ecx: TribeTacticalAIModule* |
| `004F9380` | `?stopUnit@TribeTacticalAIModule@@QAEHHH@Z` | `TribeTacticalAIModule::stopUnit` | uID @ +0x4: int; priority @ +0x8: int | this @ ecx: TribeTacticalAIModule* |
| `004F93D0` | `?moveUnit@TribeTacticalAIModule@@QAEHHMMH@Z` | `TribeTacticalAIModule::moveUnit` | uID @ +0x4: int; x @ +0x8: float; y @ +0xc: float; priority @ +0x10: int | this @ ecx: TribeTacticalAIModule* |
| `004F9420` | `?groupGatherUnit@TribeTacticalAIModule@@QAEHHHMMMMH@Z` | `TribeTacticalAIModule::groupGatherUnit` | uID @ +0x4: int; tID @ +0x8: int; x @ +0xc: float; y @ +0x10: float; z @ +0x14: float; range @ +0x18: float; priority @ +0x1c: int | this @ ecx: TribeTacticalAIModule* |
| `004F9470` | `?highLevelTaskExplorer@TribeTacticalAIModule@@QAEHHH@Z` | `TribeTacticalAIModule::highLevelTaskExplorer` | unitID @ +0x4: int; civilian @ +0x8: int | this @ ecx: TribeTacticalAIModule* |
| `004F95B0` | `?highLevelTaskGatherer@TribeTacticalAIModule@@QAEHHK@Z` | `TribeTacticalAIModule::highLevelTaskGatherer` | unitID @ +0x4: int; startTime @ +0x8: unsigned long; triedTasking @ -0x10: int[4]; gathererObj @ -0x14: RGE_Static_Object*; numNonFarmers @ +0x8: int | this @ ecx: TribeTacticalAIModule* |
| `004F99B0` | `?taskPlay@TribeTacticalAIModule@@QAEHHPAHHHHPAUWaypoint@@H@Z` | `TribeTacticalAIModule::taskPlay` | commander @ +0x4: int; groupUnits @ +0x8: int*; groupCount @ +0xc: int; target @ +0x10: int; play @ +0x14: int; path @ +0x18: Waypoint*; pathLength @ +0x1c: int | this @ ecx: TribeTacticalAIModule* |
| `004F9AD0` | `?taskBuilder@TribeTacticalAIModule@@QAEHHPAVBuildItem@@PAVConstructionItem@@K@Z` | `TribeTacticalAIModule::taskBuilder` | builder @ +0x4: int; newBuilding @ +0x8: BuildItem*; ci @ +0xc: ConstructionItem*; startTime @ +0x10: unsigned long; position @ -0x8: XYPoint | this @ ecx: TribeTacticalAIModule* |
| `004F9E00` | `?taskBuilder@TribeTacticalAIModule@@QAEHHPAVRGE_Static_Object@@@Z` | `TribeTacticalAIModule::taskBuilder` | builder @ +0x4: int; building @ +0x8: RGE_Static_Object*; builderObj @ -0x4: RGE_Static_Object*; distance @ +0xc: float | this @ ecx: TribeTacticalAIModule* |
| `004FA000` | `?taskRepairer@TribeTacticalAIModule@@QAEHHPAVRGE_Static_Object@@@Z` | `TribeTacticalAIModule::taskRepairer` | builder @ +0x4: int; building @ +0x8: RGE_Static_Object*; builderObj @ -0x4: RGE_Static_Object*; distance @ +0x8: float | this @ ecx: TribeTacticalAIModule* |
| `004FA170` | `?taskGatherer@TribeTacticalAIModule@@QAEHHHHKPAH@Z` | `TribeTacticalAIModule::taskGatherer` | id @ +0x4: int; resourceType @ +0x8: int; limitedTaskLimit @ +0xc: int; startTime @ +0x10: unsigned long; triedTasking @ +0x14: int*; rObjObj @ +0x18: RGE_Static_Object*; gathererUnitData @ -0x1c: UnitData*; rYPos @ -0x28: float; exclusions @ -0x14: int[5]; numExclusions @ -0x30: int; rXPos @ -0x24: float; gathererObj @ -0x2c: RGE_Static_Object*; i @ -0x30: int; dropsiteID @ -0x20: int; i @ -0x1c: int; dropsiteID @ -0x20: int; numGranaries @ -0x30: int; numUnbuiltGranaries @ -0x1c: int; maximumResourceDistance @ -0x18: int; numStoragePits @ -0x30: int; numUnbuiltStoragePits @ -0x1c: int; numStoragePits @ -0x30: int; numUnbuiltStoragePits @ -0x1c: int; maximumResourceDistance @ -0x18: int | this @ ecx: TribeTacticalAIModule* |
| `004FA820` | `?taskExplorer@TribeTacticalAIModule@@QAEHHH@Z` | `TribeTacticalAIModule::taskExplorer` | eID @ +0x4: int; civilian @ +0x8: int; targetPoint @ -0x8: XYPoint | this @ ecx: TribeTacticalAIModule* |
| `004FA940` | `?taskExplorer@TribeTacticalAIModule@@QAEHHMM@Z` | `TribeTacticalAIModule::taskExplorer` | eID @ +0x4: int; x @ +0x8: float; y @ +0xc: float; targetPoint @ -0x8: XYPoint | this @ ecx: TribeTacticalAIModule* |
| `004FAAA0` | `?taskExplorer@TribeTacticalAIModule@@QAEHHMMH@Z` | `TribeTacticalAIModule::taskExplorer` | eID @ +0x4: int; x @ +0x8: float; y @ +0xc: float; civilian @ +0x10: int | this @ ecx: TribeTacticalAIModule* |
| `004FAC90` | `?taskFollower@TribeTacticalAIModule@@QAEHHHMH@Z` | `TribeTacticalAIModule::taskFollower` | uID @ +0x4: int; tID @ +0x8: int; range @ +0xc: float; priority @ +0x10: int | this @ ecx: TribeTacticalAIModule* |
| `004FADA0` | `?taskDefender@TribeTacticalAIModule@@QAEHHHMH@Z` | `TribeTacticalAIModule::taskDefender` | uID @ +0x4: int; tID @ +0x8: int; range @ +0xc: float; priority @ +0x10: int | this @ ecx: TribeTacticalAIModule* |
| `004FAEB0` | `?taskWaterExplorer@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::taskWaterExplorer` | explorer @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `004FAFC0` | `?taskWaterTrader@TribeTacticalAIModule@@QAEHHH@Z` | `TribeTacticalAIModule::taskWaterTrader` | unitID @ +0x4: int; targetID @ +0x8: int; targetObj @ -0x4: RGE_Static_Object* | this @ ecx: TribeTacticalAIModule* |
| `004FB160` | `?taskWaterFisher@TribeTacticalAIModule@@QAEHHHMM@Z` | `TribeTacticalAIModule::taskWaterFisher` | unitID @ +0x4: int; targetID @ +0x8: int; x @ +0xc: float; y @ +0x10: float | this @ ecx: TribeTacticalAIModule* |
| `004FB2D0` | `?taskAttacker@TribeTacticalAIModule@@QAEHHMMHHPAUWaypoint@@HHH@Z` | `TribeTacticalAIModule::taskAttacker` | soldierID @ +0x4: int; xLocation @ +0x8: float; yLocation @ +0xc: float; targetID @ +0x10: int; targetOwner @ +0x14: int; path @ +0x18: Waypoint*; pathLength @ +0x1c: int; commanderID @ +0x20: int; idleAttackRoundup @ +0x24: int; distance @ +0x1c: float; distance @ +0x14: float | this @ ecx: TribeTacticalAIModule* |
| `004FB500` | `?taskDefender@TribeTacticalAIModule@@QAEHHH@Z` | `TribeTacticalAIModule::taskDefender` | defender @ +0x4: int; targetID @ +0x8: int | this @ ecx: TribeTacticalAIModule* |
| `004FB520` | `?taskDefender@TribeTacticalAIModule@@QAEHHMM@Z` | `TribeTacticalAIModule::taskDefender` | defender @ +0x4: int; x @ +0x8: float; y @ +0xc: float | this @ ecx: TribeTacticalAIModule* |
| `004FB550` | `?taskTrain@TribeTacticalAIModule@@QAEHPAVBuildItem@@@Z` | `TribeTacticalAIModule::taskTrain` | trainItem @ +0x4: BuildItem*; trainBuilding @ +0x8: RGE_Static_Object* | this @ ecx: TribeTacticalAIModule* |
| `004FB710` | `?taskResearch@TribeTacticalAIModule@@QAEHPAVBuildItem@@@Z` | `TribeTacticalAIModule::taskResearch` | researchItem @ +0x4: BuildItem*; researchBuilding @ +0x8: RGE_Static_Object* | this @ ecx: TribeTacticalAIModule* |
| `004FB8D0` | `?taskToEnter@TribeTacticalAIModule@@QAEHHH@Z` | `TribeTacticalAIModule::taskToEnter` | unitID @ +0x4: int; targetID @ +0x8: int | this @ ecx: TribeTacticalAIModule* |
| `004FB9E0` | `?taskTransporter@TribeTacticalAIModule@@QAEHHMM@Z` | `TribeTacticalAIModule::taskTransporter` | unitID @ +0x4: int; x @ +0x8: float; y @ +0xc: float; priority @ +0x8: int; distance @ +0x8: float | this @ ecx: TribeTacticalAIModule* |
| `004FBB30` | `?removeFromTaskLists@TribeTacticalAIModule@@QAEXH@Z` | `TribeTacticalAIModule::removeFromTaskLists` | gID @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `004FBC10` | `?calculatePriority@TribeTacticalAIModule@@QAEHM@Z` | `TribeTacticalAIModule::calculatePriority` | distance @ +0x4: float | this @ ecx: TribeTacticalAIModule* |
| `004FBC30` | `?setupSoldierGroups@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::setupSoldierGroups` | numPotentialDGroups @ -0x34: int; numPotentialEGroups @ -0x30: int; numEGroups @ -0x24: int; i @ -0x30: int; groupsToRemove @ -0x1c: ManagedArray<int>; numPotentialAGroups @ -0x38: int; numAGroups @ -0x2c: int; numDGroups @ -0x28: int; newArtifact @ -0x34: int | this @ ecx: TribeTacticalAIModule* |
| `004FC500` | `?fillSoldierGroups@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::fillSoldierGroups` | i @ -0x1c: int; temp @ -0x1c: TacticalAIGroup*; a @ -0xc: int; commanderZone @ -0x18: int; bestUnit @ -0x4: int; bestDistance @ -0x14: float; unitDistance @ -0x8: float; bestUnit @ -0x8: int; bestDistance @ -0x10: float; unitDistance @ -0x4: float; bestGroupDifference @ -0x4: int; unitZone @ -0x1d: unsigned char; bestGroup @ -0x18: TacticalAIGroup* | this @ ecx: TribeTacticalAIModule* |
| `004FD2F0` | `?numberUngroupedSoldiers@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberUngroupedSoldiers` | i @ -0x4: int; rNum @ -0xc: int | this @ ecx: TribeTacticalAIModule* |
| `004FD4F0` | `?numberExtraGroupedSoldiers@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberExtraGroupedSoldiers` | rNum @ -0x8: int; tempCount @ -0xc: int; j @ -0x10: int | this @ ecx: TribeTacticalAIModule* |
| `004FD6D0` | `?numberUngroupedArtifacts@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberUngroupedArtifacts` | i @ -0x4: int; rNum @ -0xc: int | this @ ecx: TribeTacticalAIModule* |
| `004FD8D0` | `?displaySoldierGroups@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::displaySoldierGroups` | — | this @ ecx: TribeTacticalAIModule* |
| `004FDE00` | `?setupBoatGroups@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::setupBoatGroups` | numPotentialDGroups @ -0x38: int; numPotentialEGroups @ -0x2c: int; numEGroups @ -0x34: int; i @ -0x38: int; groupsToRemove @ -0x1c: ManagedArray<int>; numPotentialAGroups @ -0x30: int; numAGroups @ -0x20: int; numDGroups @ -0x28: int | this @ ecx: TribeTacticalAIModule* |
| `004FE950` | `?fillBoatGroups@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::fillBoatGroups` | i @ -0x14: int; temp @ -0x18: TacticalAIGroup*; a @ -0xc: int; bestUnit @ -0x4: int; bestDistance @ -0x14: float; unitDistance @ -0x8: float; bestUnit @ -0x8: int; bestDistance @ -0x10: float; unitDistance @ -0x4: float; bestGroupDifference @ -0x4: int; bestGroup @ -0x18: TacticalAIGroup* | this @ ecx: TribeTacticalAIModule* |
| `004FF4E0` | `?numberUngroupedWarBoats@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberUngroupedWarBoats` | i @ -0x4: int; rNum @ -0xc: int | this @ ecx: TribeTacticalAIModule* |
| `004FF6E0` | `?numberExtraGroupedWarBoats@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberExtraGroupedWarBoats` | rNum @ -0x8: int; tempCount @ -0xc: int; j @ -0x10: int | this @ ecx: TribeTacticalAIModule* |
| `004FF8E0` | `?numberUngroupedFishingBoats@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberUngroupedFishingBoats` | i @ -0x4: int; rNum @ -0xc: int | this @ ecx: TribeTacticalAIModule* |
| `004FFAE0` | `?numberUngroupedTradeBoats@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberUngroupedTradeBoats` | i @ -0x4: int; rNum @ -0xc: int | this @ ecx: TribeTacticalAIModule* |
| `004FFCE0` | `?numberUngroupedTransportBoats@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberUngroupedTransportBoats` | i @ -0x4: int; rNum @ -0xc: int | this @ ecx: TribeTacticalAIModule* |
| `004FFEE0` | `?displayBoatGroups@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::displayBoatGroups` | — | this @ ecx: TribeTacticalAIModule* |
| `00500260` | `?createGroup@TribeTacticalAIModule@@QAEPAVTacticalAIGroup@@H@Z` | `TribeTacticalAIModule::createGroup` | initID @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00500320` | `?removeGroup@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::removeGroup` | gID @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `005003A0` | `?removeAllGroups@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::removeAllGroups` | tID @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00500420` | `?group@TribeTacticalAIModule@@QAEPAVTacticalAIGroup@@HHHH@Z` | `TribeTacticalAIModule::group` | gID @ +0x4: int; type @ +0x8: int; action @ +0xc: int; targetID @ +0x10: int | this @ ecx: TribeTacticalAIModule* |
| `005004C0` | `?bestGroup@TribeTacticalAIModule@@QAEPAVTacticalAIGroup@@HHHAAUXYPoint@@H@Z` | `TribeTacticalAIModule::bestGroup` | type @ +0x4: int; action @ +0x8: int; distance @ +0xc: int; point @ +0x10: XYPoint&; zone @ +0x14: int; bGValue @ -0x10: int; bG @ -0x8: TacticalAIGroup* | this @ ecx: TribeTacticalAIModule* |
| `00500670` | `?readyAndIdleGroup@TribeTacticalAIModule@@QAEPAVTacticalAIGroup@@HHAAUXYPoint@@@Z` | `TribeTacticalAIModule::readyAndIdleGroup` | type @ +0x4: int; distance @ +0x8: int; point @ +0xc: XYPoint&; bGValue @ -0xc: int; bG @ -0x4: TacticalAIGroup* | this @ ecx: TribeTacticalAIModule* |
| `005007B0` | `?addToGroup@TribeTacticalAIModule@@QAEHHH@Z` | `TribeTacticalAIModule::addToGroup` | uID @ +0x4: int; gID @ +0x8: int | this @ ecx: TribeTacticalAIModule* |
| `005007F0` | `?removeFromGroup@TribeTacticalAIModule@@QAEHHH@Z` | `TribeTacticalAIModule::removeFromGroup` | uID @ +0x4: int; gID @ +0x8: int | this @ ecx: TribeTacticalAIModule* |
| `00500850` | `?removeFromGroup@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::removeFromGroup` | uID @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `005008A0` | `?groupUnitIsIn@TribeTacticalAIModule@@QAEPAVTacticalAIGroup@@H@Z` | `TribeTacticalAIModule::groupUnitIsIn` | uID @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `005008F0` | `?numberGroups@TribeTacticalAIModule@@QAEHHH@Z` | `TribeTacticalAIModule::numberGroups` | type @ +0x4: int; action @ +0x8: int; rVal @ -0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00500950` | `?numberUnitsInGroups@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::numberUnitsInGroups` | type @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `005009A0` | `?numberItemsToAttack@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberItemsToAttack` | — | this @ ecx: TribeTacticalAIModule* |
| `00500A30` | `?itemToCapture@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::itemToCapture` | — | this @ ecx: TribeTacticalAIModule* |
| `00500A80` | `?itemToBringToArea@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::itemToBringToArea` | — | this @ ecx: TribeTacticalAIModule* |
| `00500AD0` | `?numberItemsToDefend@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberItemsToDefend` | — | this @ ecx: TribeTacticalAIModule* |
| `00500AF0` | `?attackLimiterTime@TribeTacticalAIModule@@QAEKH@Z` | `TribeTacticalAIModule::attackLimiterTime` | snType @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00500B30` | `?resetAttackSeparationTime@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::resetAttackSeparationTime` | — | this @ ecx: TribeTacticalAIModule* |
| `00500BA0` | `?setGatherLocation@TribeTacticalAIModule@@QAEHPAVTacticalAIGroup@@@Z` | `TribeTacticalAIModule::setGatherLocation` | g @ +0x4: TacticalAIGroup*; landSoldiers @ +0x8: int; gatherPoint @ -0x8: XYPoint; centerPoint @ -0x10: XYPoint | this @ ecx: TribeTacticalAIModule* |
| `00500CC0` | `?setAllGroupLocations@TribeTacticalAIModule@@QAEHPAVTacticalAIGroup@@@Z` | `TribeTacticalAIModule::setAllGroupLocations` | g @ +0x4: TacticalAIGroup*; landSoldiers @ +0x8: int; gatherPoint @ -0x8: XYPoint; centerPoint @ -0x10: XYPoint | this @ ecx: TribeTacticalAIModule* |
| `00500DE0` | `?setGroupInfluences@TribeTacticalAIModule@@QAEXAAVInfluenceMap@@@Z` | `TribeTacticalAIModule::setGroupInfluences` | iMap @ +0x4: InfluenceMap&; clearDistance @ -0x14: int; min @ -0x8: XYPoint; max @ -0x10: XYPoint; clearDistance @ +0x8: float; min @ -0x10: XYPoint; max @ -0x8: XYPoint | this @ ecx: TribeTacticalAIModule* |
| `00501190` | `?selectBestCommander@TribeTacticalAIModule@@QAEHPAVTacticalAIGroup@@@Z` | `TribeTacticalAIModule::selectBestCommander` | temp @ +0x4: TacticalAIGroup*; bestUnit @ -0x8: int | this @ ecx: TribeTacticalAIModule* |
| `00501260` | `?selectBestCommander@TribeTacticalAIModule@@QAEHAAV?$ManagedArray@H@@@Z` | `TribeTacticalAIModule::selectBestCommander` | temp @ +0x4: ManagedArray<int>&; i @ -0xc: int; bestUnit @ -0x8: int; unitValue @ +0x8: int | this @ ecx: TribeTacticalAIModule* |
| `00501430` | `?dealWithGAIAAttacker@TribeTacticalAIModule@@QAEHPAVRGE_Static_Object@@0@Z` | `TribeTacticalAIModule::dealWithGAIAAttacker` | attacker @ +0x4: RGE_Static_Object*; victim @ +0x8: RGE_Static_Object*; count @ +0x8: int; vPosition @ -0x14: XYPoint; point @ -0xc: XYZPoint | this @ ecx: TribeTacticalAIModule* |
| `005015E0` | `?addWaypoint@TribeTacticalAIModule@@QAEXHEE@Z` | `TribeTacticalAIModule::addWaypoint` | recipient @ +0x4: int; x @ +0x8: unsigned char; y @ +0xc: unsigned char; point @ +0xc: XYZBYTEPoint | this @ ecx: TribeTacticalAIModule* |
| `00501620` | `?importantGroupLeader@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::importantGroupLeader` | cID @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00501660` | `?enableAttack@TribeTacticalAIModule@@QAEXH@Z` | `TribeTacticalAIModule::enableAttack` | type @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00501690` | `?unexploredArea@TribeTacticalAIModule@@QAEHHAAUXYPoint@@@Z` | `TribeTacticalAIModule::unexploredArea` | uID @ +0x4: int; rPoint @ +0x8: XYPoint&; bestPoint @ -0x8: XYPoint; unitZone @ -0x11: unsigned char; bestDistance @ -0x10: float; unit @ -0xc: RGE_Static_Object*; i @ +0xc: int | this @ ecx: TribeTacticalAIModule* |
| `005018F0` | `?gatherer@TribeTacticalAIModule@@QAEPAUUnitData@@H@Z` | `TribeTacticalAIModule::gatherer` | id @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00501920` | `?addGatherer@TribeTacticalAIModule@@QAEPAUUnitData@@H@Z` | `TribeTacticalAIModule::addGatherer` | id @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `005019C0` | `?removeGatherer@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::removeGatherer` | id @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00501A80` | `?isGatherer@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::isGatherer` | id @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00501AB0` | `?requiredGatherAmount@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::requiredGatherAmount` | rType @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00501AF0` | `?trackUnitGather@TribeTacticalAIModule@@QAEXHHH@Z` | `TribeTacticalAIModule::trackUnitGather` | unitID @ +0x4: int; attributeID @ +0x8: int; amount @ +0xc: int | this @ ecx: TribeTacticalAIModule* |
| `00501B50` | `?deleteUnit@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::deleteUnit` | unitID @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00501B90` | `?numberAvailableStoragePits@TribeTacticalAIModule@@QAEHAAH0H@Z` | `TribeTacticalAIModule::numberAvailableStoragePits` | numStoragePits @ +0x4: int&; numUnbuiltStoragePits @ +0x8: int&; rType @ +0xc: int | this @ ecx: TribeTacticalAIModule* |
| `00501C70` | `?numberAvailableGranaries@TribeTacticalAIModule@@QAEHAAH0@Z` | `TribeTacticalAIModule::numberAvailableGranaries` | numGranaries @ +0x4: int&; numUnbuiltGranaries @ +0x8: int& | this @ ecx: TribeTacticalAIModule* |
| `00501D20` | `?initialExplorationSatisfied@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::initialExplorationSatisfied` | — | this @ ecx: TribeTacticalAIModule* |
| `00501D70` | `?checkForBuildInsertion@TribeTacticalAIModule@@QAEXHHH@Z` | `TribeTacticalAIModule::checkForBuildInsertion` | type @ +0x4: int; number @ +0x8: int; position @ +0xc: int; itemCost @ -0x7c: ResourceItem; itemCost @ -0x7c: ResourceItem; numGranaries @ -0x80: int; numUnbuiltGranaries @ -0x84: int | this @ ecx: TribeTacticalAIModule* |
| `005020A0` | `?isFarmer@TribeTacticalAIModule@@QAEHPAVRGE_Static_Object@@@Z` | `TribeTacticalAIModule::isFarmer` | temp @ +0x4: RGE_Static_Object* | this @ ecx: TribeTacticalAIModule* |
| `00502100` | `?numberFarmers@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberFarmers` | rVal @ -0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00502200` | `?inAge@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::inAge` | age @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00502230` | `?stuffAvoidancePath@TribeTacticalAIModule@@QAEXPAVTacticalAIGroup@@PAVPath@@@Z` | `TribeTacticalAIModule::stuffAvoidancePath` | group @ +0x4: TacticalAIGroup*; path @ +0x8: Path*; divisionLength @ -0x4: float; temp @ +0xc: float | this @ ecx: TribeTacticalAIModule* |
| `00502310` | `?checkForAttackResponseBuildInsertions@TribeTacticalAIModule@@QAEXH@Z` | `TribeTacticalAIModule::checkForAttackResponseBuildInsertions` | playerID @ +0x4: int; insertedUnit @ -0x80: int; i @ -0x84: int; itemCost @ -0x7c: ResourceItem | this @ ecx: TribeTacticalAIModule* |
| `00502600` | `?checkForCoopTributeDemand@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::checkForCoopTributeDemand` | amountDemandable @ -0x18: int; j @ -0x8: int; world @ -0x10: TRIBE_World*; tempRand @ -0x14: int; i @ -0xc: int | this @ ecx: TribeTacticalAIModule* |
| `00502920` | `?checkForCoopTributeGift@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::checkForCoopTributeGift` | j @ -0x18: int; world @ -0x10: TRIBE_World*; tempRand @ -0xc: int; bestCPValue @ -0x8: float; i @ -0xc: int; bestCP @ -0x1c: int; tributeAmount @ -0x4: float | this @ ecx: TribeTacticalAIModule* |
| `00502BF0` | `?checkForASAPAgeResearch@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::checkForASAPAgeResearch` | — | this @ ecx: TribeTacticalAIModule* |
| `00502D50` | `?checkForCoopAttack@TribeTacticalAIModule@@QAEXHHH@Z` | `TribeTacticalAIModule::checkForCoopAttack` | playerToAttack @ +0x4: int; x @ +0x8: int; y @ +0xc: int; i @ -0x4: int; tempRand @ -0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00502F30` | `?processCoopAttack@TribeTacticalAIModule@@QAEHHHHH@Z` | `TribeTacticalAIModule::processCoopAttack` | caller @ +0x4: int; playerToAttack @ +0x8: int; x @ +0xc: int; y @ +0x10: int | this @ ecx: TribeTacticalAIModule* |
| `00502FC0` | `?resourceDifference@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::resourceDifference` | n @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00502FF0` | `?actualGathererCount@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::actualGathererCount` | n @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00503020` | `?actualGathererCountByRealResourceID@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::actualGathererCountByRealResourceID` | n @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00503040` | `?desiredGathererCount@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::desiredGathererCount` | n @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00503070` | `?taskElephantGatherers@TribeTacticalAIModule@@QAEXHHH@Z` | `TribeTacticalAIModule::taskElephantGatherers` | mainHunterID @ +0x4: int; numberToTask @ +0x8: int; targetID @ +0xc: int; targetObject @ -0x24: RGE_Static_Object*; count @ -0x20: int; alreadyTasked @ -0x1c: ManagedArray<int>; bestValueID @ -0x28: int; bestDistance @ +0x8: float | this @ ecx: TribeTacticalAIModule* |
| `005032E0` | `?checkTradeBoats@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::checkTradeBoats` | i @ -0x4: int | this @ ecx: TribeTacticalAIModule* |
| `00503480` | `?numberGatherersWithTarget@TribeTacticalAIModule@@QAEHH@Z` | `TribeTacticalAIModule::numberGatherersWithTarget` | targetID @ +0x4: int | this @ ecx: TribeTacticalAIModule* |
| `005034B0` | `?checkStaleAttackGroups@TribeTacticalAIModule@@QAEXXZ` | `TribeTacticalAIModule::checkStaleAttackGroups` | — | this @ ecx: TribeTacticalAIModule* |
| `00503580` | `?numberWaterExplorers@TribeTacticalAIModule@@QAEHXZ` | `TribeTacticalAIModule::numberWaterExplorers` | — | this @ ecx: TribeTacticalAIModule* |
| `00503600` | `?saveTheTown@TribeTacticalAIModule@@QAEXH@Z` | `TribeTacticalAIModule::saveTheTown` | idToKill @ +0x4: int; entryTime @ -0x1c: unsigned long; i @ -0x24: int; count @ -0x20: int; objPosition @ -0x14: XYPoint; point @ -0xc: XYZPoint; targetObj @ -0x18: RGE_Static_Object*; point @ -0xc: XYZPoint; point @ -0xc: XYZPoint | this @ ecx: TribeTacticalAIModule* |

PDB coverage result: 216/216 records found. Missing records: none.

## Recovered names and evidence

All names in this list come from the procedure-scoped PDB records above. The VA is the direct evidence key in both the registry and PDB inventory.

| Procedure VA | Recovered declarations and locals | Evidence |
| --- | --- | --- |
| `004EA9C0`, `004EACA0` | `infile`, `outfile` | Direct PDB stack names for `TacticalAIGroup::load` and `save`; original serialization calls use the same handle. |
| `004EAF30`, `004EAF50`, `004EAF70`, `004EAF90`, `004EB380`, `004EB480`, `004EB490`, `004EB680`, `004EB6A0`, `004EB6C0`, `004EB6E0` | Setter value `v` | Direct PDB parameter name `v`. |
| `004EAFA0`, `004EB030`, `004EB290`, `004ED190` | Unit or object `id` | Direct PDB parameter name `id`. |
| `004EB1F0`, `004EB6F0` | Tactical and module parameters `t`, `md`; task identifiers `taskID`, `resetOriginal`, `overrideCurrentAction` | Direct PDB parameter records. The task packet is `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004EB6F0_task.txt`. |
| `004EB2D0`, `004EB320` | Indexed group access parameter `i` | Direct PDB parameter name `i`; loop storage remains separate from the parameter. |
| `004EB3A0`, `004EB430` | Commander and module parameters `id`, `md` | Direct PDB parameter names `id` and `md`. |
| `004ED1C0`, `004ED4F0` | Constructor parameters `pW`, `pID`, `infile`; legacy record `tempUD` | Direct PDB parameter and local names. The constructor packet is `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004ED4F0_TribeTacticalAIModule.txt`. |
| `004EEF40`, `004EF4D0`, `004F0180`, `004F0BC0`, `004F0D70`, `004F1090` | `timeLimit`, `m`, `gID`, `textIn`, `id`, `minX`, `minY`, `maxX`, `maxY`, `bo` | Direct PDB parameter names for update, module setup, debug, area, and object procedures. |
| `004F1600`, `004F1E10` | `startTime`, `availableTime`, `taskedCount`, `newExplorer`, `tcPosition`, `j`, `isGathered`, `readyToTask` | Direct PDB parameter and local names. |
| `004F6180`, `004F61A0`, `004F6210`, `004F62C0` | `n`, `sNum`, `v`, `callerID`, `recipientID`, `mType`, `p1`, `p2`, `p3` | Direct PDB records for resource, strategic-number, and notification procedures. |
| `004F8BE0`, `004F9380`, `004F93D0`, `004F9420` | `id`, `a`, `uID`, `priority`, `tID`, `x`, `y`, `z`, `range` | Direct PDB parameter names for action and order wrappers. |
| `004F99B0` | `commander`, `groupUnits`, `groupCount`, `target`, `play`, `path`, `pathLength` | Direct PDB task-play parameter records. |
| `004FA820`, `004FA940`, `004FAAA0` | Explorer parameters `eID`, `civilian`, `x`, `y` | Direct PDB records for all three overloads. |
| `004FAC90`, `004FADA0`, `004FB500`, `004FB520` | `uID`, `tID`, `range`, `priority`; defender overloads `defender`, `targetID`, `x`, `y` | Direct PDB records for follower and defender procedures. |
| `004FAEB0`, `004FAFC0`, `004FB160`, `004FB8D0` | `explorer`, `unitID`, `targetID`, `x`, `y` | Direct PDB records for water and transport procedures. |
| `004FB2D0` | `soldierID`, `xLocation`, `yLocation`, `targetID`, `targetOwner`, `path`, `pathLength`, `commanderID`, `idleAttackRoundup` | Direct PDB task-attacker records and the original packet. |
| `005007F0`, `00500850`, `005008F0`, `00500AF0`, `00501B50` | `uID`, `gID`, `type`, `action`, `snType`, `id` | Direct PDB group, limiter, and delete-unit parameter records. |

### Task-local recovery

- `TacticalAIGroup::task` recovered `oHP`, `distance`, `gatherRange`, `randomRoll`, `commanderObj`, and `targetObj` from scoped local records and the original task packet.
- `TacticalAIGroup::isGathered` recovered `distance` and `t` from scoped local and parameter records.
- `taskCivilians` recovered `tcPosition` and `j` from scoped local records.
- This correction recovers the supported parameter spellings `t` in `TacticalAIGroup::task` and `outfile` in `TribeTacticalAIModule::save`.
- The PDB stack records in the coverage table are the complete local and parameter evidence for every assigned procedure.

## Unresolved declaration mappings

- The load constructor still has generated local spellings `iVar1`, `piVar2`, `pTVar5`, `iVar6`, `tempInt`, and `local_2c` where PDB records overlap or reuse stack slots. `tempUD` is recovered. No alias or extra local was added.
- Positive-offset PDB records that overlay locals are not treated as proof of a distinct C++ declaration. The full stack record list above preserves that uncertainty.
- Coverage review found no other reliable parameter or local name left unchanged for convenience. The remaining constructor mappings are uncertain because the records reuse or overlay storage.

## Recovered versus invented names

- Recovered names are listed in the evidence table and match a PDB parameter or local record, or a direct original-packet label.
- The first constructor's local names `value` and `i` are descriptive names, not PDB recoveries. The PDB exposes no local record for `004ED1C0`.
- No new gameplay name, resource name, constant, field, class, function, or storage object was invented.
- Existing descriptive spellings remain where no direct declaration mapping was safe.

## Constants, resources, and comments

- No numeric constant changed.
- No resource ID changed or was requested. Resource policy evidence is `C:/Projects/my_decomps/aoe1_attempt3/docs/resource_ids.md`.
- No string or message ID changed.
- Existing comments were retained. The correction adds no behavior comment and makes no comment claim about an unresolved mapping.

## Formatting-only correction

- Applied 1TBS brace placement and consistent four-space indentation throughout `src/taitacmd.cpp`.
- The earlier formatting correction changed whitespace and brace placement only. It preserved declarations, statements, scopes, macro continuations, names, constants, casts, calls, and evaluation order.
- This second correction changes only the supported parameter identifiers and their uses. It does not change formatting, statements, constants, casts, calls, or evaluation order.
- The load constructor no longer uses its former two-space indentation.

## Code-generation and ownership risks

- The owner is `src/taitacmd.cpp`; the registry is `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/taitacmd.cpp.json`.
- The registry selects module flags `gx`. Toolchain evidence is `C:/Projects/my_decomps/aoe1_attempt3/config/toolchain.json` and `C:/Projects/my_decomps/aoe1_attempt3/config/flags/default.rsp`.
- Name edits do not change generated instructions. Formatting edits do not change tokens, but the result was not compiled because the assignment forbids compilation.
- No header or duplicate source owner changed. No vtable, layout, calling convention, inline assembly, or binary dependency changed.
- The main risk is unverified compiler output because compilation and matching were not run.

## Shared requests

- No shared declaration request was made.
- No resource request was made.
- No ownership transfer was requested.

## Correction history

1. The first cleanup commit was `a593951d6517d85078efd5a9d70c6300f22a9db5`.
2. Review found that the report lacked full delivery, evidence, coverage, and risk records.
3. This correction expands the report, records all 216 registered procedures, and formats the source with 1TBS and four-space indentation.
4. The first correction source commit is `ce810adbb5d020a2788c5800018a20470701d4f9`. Report-only follow-up commits recorded that delivery report.
5. This second correction recovers the reliable PDB parameter names `t` and `outfile`, updates all uses in their owning functions, and does not change formatting.
6. The second-correction source commit is `2b9bd67624c4c302b583f4cb57c00846266bac74`; a report-only follow-up commit records this updated report.

## Required validation statement

Compilation was not run. Matching checks were not run. Audits were not run. Tests were not run.
