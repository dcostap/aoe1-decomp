// Authentic PDB-order wrapper for taiinfmd.cpp.
// All 123 normal owners are included. Exact and observed status is recorded in the proposal.

#define TAIINFMD_PREFIX_CONTEXT 1
#include "../include/taiinfmd_prefix_context.h"

// 004D6AD0: taiinfmd.cpp:103-103
#include "matching/004D6AD0_E9.cpp"

// 004D6B70: taiinfmd.cpp:105-105
#include "matching/004D6B70_E19.cpp"

// 004D6BB0: taiinfmd.cpp:124-231
#include "accepted_drift/004D6BB0_TribeInformationAIModule.cpp"

// 004D7070: taiinfmd.cpp:241-407
#include "matching/004D7070_TribeInformationAIModule.cpp"

// 004D7CB0: taiinfmd.cpp:412-564
#include "accepted_drift/004D7CB0_TribeInformationAIModule.cpp"

// 004D8270: taiinfmd.cpp:569-581
#include "matching/004D8270_initialize.cpp"

// 004D8300: taiinfmd.cpp:586-732
#include "matching/004D8300_update.cpp"

// 004D84D0: taiinfmd.cpp:737-739
#include "matching/004D84D0_setMainDecisionAI.cpp"

// 004D84E0: taiinfmd.cpp:744-864
#include "matching/004D84E0_save.cpp"

// 004D8C80: taiinfmd.cpp:870-890
#include "matching/004D8C80_blotExploredMap.cpp"

// 004D8D20: taiinfmd.cpp:896-1116
#include "scratch/004D8D20_closestUnexploredTile.cpp"

// 004D9110: taiinfmd.cpp:1121-1133
#include "matching/004D9110_fullyExploredZone.cpp"

// 004D9160: taiinfmd.cpp:1138-1144
#include "matching/004D9160_setFullyExploredZone.cpp"

// 004D91A0: taiinfmd.cpp:1149-1166
#include "matching/004D91A0_tileUncovered.cpp"

// 004D91F0: taiinfmd.cpp:1171-1175
#include "matching/004D91F0_setTileExplored.cpp"

// 004D9230: taiinfmd.cpp:1180-1182
#include "matching/004D9230_ownerOfGameID.cpp"

// 004D9240: taiinfmd.cpp:1188-1484
#include "scratch/004D9240_gameIDOfResourceObject.cpp"

// 004D96B0: taiinfmd.cpp:1490-1553
#include "scratch/004D96B0_gameIDsOfObjectType.cpp"

// 004D9970: taiinfmd.cpp:1559-1635
#include "matching/004D9970_gameIDsOwnedBy.cpp"

// 004D9A90: taiinfmd.cpp:1641-1672
#include "matching/004D9A90_numberGameIDsOwnedBy.cpp"

// 004D9B20: taiinfmd.cpp:1678-1811
#include "matching/004D9B20_placeDock.cpp"

// 004D9EC0: taiinfmd.cpp:1816-1828
#include "matching/004D9EC0_numberDocksInZone.cpp"

// 004D9FC0: taiinfmd.cpp:1833-1848
#include "matching/004D9FC0_closestDockDistance.cpp"

// 004DA0E0: taiinfmd.cpp:1853-1894
#include "matching/004DA0E0_hasAdjacentTileType.cpp"

// 004DA190: taiinfmd.cpp:1899-1903
#include "scratch/004DA190_mapXSize.cpp"

// 004DA1C0: taiinfmd.cpp:1908-1912
#include "scratch/004DA1C0_mapYSize.cpp"

// 004DA1F0: taiinfmd.cpp:1917-1968
#include "accepted_drift/004DA1F0_addEnemyInfluences.cpp"

// 004DA420: taiinfmd.cpp:1973-2005
#include "scratch/004DA420_addPriorAttackInfluences.cpp"

// 004DA5A0: taiinfmd.cpp:2010-2020
#include "matching/004DA5A0_objectMemory.cpp"

// 004DA5F0: taiinfmd.cpp:2025-2035
#include "matching/004DA5F0_addObjectMemory.cpp"

// 004DA680: taiinfmd.cpp:2043-2159
#include "scratch/004DA680_addObjectMemory.cpp"

// 004DABB0: taiinfmd.cpp:2165-2256
#include "matching/004DABB0_addImportantObject.cpp"

// 004DAF80: taiinfmd.cpp:2261-2264
#include "matching/004DAF80_addImportantObject.cpp"

// 004DAFB0: taiinfmd.cpp:2269-2274
#include "matching/004DAFB0_importantObject.cpp"

// 004DAFF0: taiinfmd.cpp:2279-2303
#include "matching/004DAFF0_importantUnit.cpp"

// 004DB070: taiinfmd.cpp:2308-2321
#include "matching/004DB070_importantResource.cpp"

// 004DB0B0: taiinfmd.cpp:2326-2331
#include "matching/004DB0B0_importantMisc.cpp"

// 004DB0D0: taiinfmd.cpp:2336-2341
#include "matching/004DB0D0_isBuilding.cpp"

// 004DB100: taiinfmd.cpp:2346-2359
#include "matching/004DB100_isUnitBuilding.cpp"

// 004DB160: taiinfmd.cpp:2364-2371
#include "matching/004DB160_isBoat.cpp"

// 004DB190: taiinfmd.cpp:2431-2435
#include "matching/004DB190_isWall.cpp"

// 004DB1B0: taiinfmd.cpp:2440-2448
#include "matching/004DB1B0_isTower.cpp"

// 004DB1F0: taiinfmd.cpp:2463-2475
#include "matching/004DB1F0_isBoatAccessible.cpp"

// 004DB240: taiinfmd.cpp:2481-2492
#include "matching/004DB240_isLandAccessible.cpp"

// 004DB280: taiinfmd.cpp:2520-2523
#include "matching/004DB280_influenceCanPlaceStructure.cpp"

// 004DB290: taiinfmd.cpp:2532-3206
#include "scratch/004DB290_influencePlaceStructure.cpp"

// 004DC1B0: taiinfmd.cpp:3211-3249
#include "scratch/004DC1B0_addObject.cpp"

// 004DC3A0: taiinfmd.cpp:3254-3270
#include "matching/004DC3A0_removeObject.cpp"

// 004DC490: taiinfmd.cpp:3277-3451
#include "scratch/004DC490_objectToAttackWithPlay.cpp"

// 004DC750: taiinfmd.cpp:3458-3765
#include "scratch/004DC750_objectToAttack.cpp"

// 004DCF10: taiinfmd.cpp:3771-4247
#include "scratch/004DCF10_objectToAttackByGroup.cpp"

// 004DDD40: taiinfmd.cpp:4253-4435
#include "scratch/004DDD40_objectToAttackByGroup2.cpp"

// 004DE1F0: taiinfmd.cpp:4440-4521
#include "matching/004DE1F0_objectToDefend.cpp"

// 004DE330: taiinfmd.cpp:4527-4574
#include "accepted_drift/004DE330_higherPriorityObjectToDefend.cpp"

// 004DE4A0: taiinfmd.cpp:4579-4607
#include "matching/004DE4A0_defendPriority.cpp"

// 004DE600: taiinfmd.cpp:4612-4721
#include "accepted_drift/004DE600_checkDefend.cpp"

// 004DEA70: taiinfmd.cpp:4726-4731
#include "matching/004DEA70_numberItemsToDefend.cpp"

// 004DEA80: taiinfmd.cpp:4736-4787
#include "accepted_drift/004DEA80_objectToTradeWith.cpp"

// 004DEBA0: taiinfmd.cpp:4795-4959
#include "scratch/004DEBA0_findGatherPosition.cpp"

// 004DEE90: taiinfmd.cpp:4965-5522
#include "scratch/004DEE90_setupInfluenceMap.cpp"

// 004DFCE0: taiinfmd.cpp:5527-5552
#include "matching/004DFCE0_mapBound.cpp"

// 004DFD40: taiinfmd.cpp:5557-5563
#include "matching/004DFD40_groupInfluenceDimension.cpp"

// 004DFD60: taiinfmd.cpp:5569-5686
#include "matching/004DFD60_findObjectMemoryLimits.cpp"

// 004E0040: taiinfmd.cpp:5692-5702
#include "matching/004E0040_isNextTo.cpp"

// 004E0090: taiinfmd.cpp:5707-5735
#include "matching/004E0090_facetTo.cpp"

// 004E0100: taiinfmd.cpp:5740-5768
#include "matching/004E0100_placementCode.cpp"

// 004E02A0: taiinfmd.cpp:5774-5841
#include "accepted_drift/004E02A0_storeLot.cpp"

// 004E0470: taiinfmd.cpp:5847-5868
#include "accepted_drift/004E0470_removeLot.cpp"

// 004E0510: taiinfmd.cpp:5873-5879
#include "matching/004E0510_availableLot.cpp"

// 004E0560: taiinfmd.cpp:5884-5892
#include "matching/004E0560_invalidLot.cpp"

// 004E05C0: taiinfmd.cpp:5898-5911
#include "accepted_drift/004E05C0_undesirableLot.cpp"

// 004E0670: taiinfmd.cpp:5918-6326
#include "scratch/004E0670_setupWalls.cpp"

// 004E0F40: taiinfmd.cpp:6331-6353
#include "matching/004E0F40_insideGate.cpp"

// 004E0F90: taiinfmd.cpp:6360-6363
#include "matching/004E0F90_storeAttackMemory.cpp"

// 004E0FD0: taiinfmd.cpp:6370-6418
#include "matching/004E0FD0_storeAttackMemory.cpp"

// 004E1190: taiinfmd.cpp:6423-6437
#include "matching/004E1190_removeAttackMemory.cpp"

// 004E1230: taiinfmd.cpp:6442-6446
#include "matching/004E1230_attackMemory.cpp"

// 004E1260: taiinfmd.cpp:6451-6549
#include "scratch/004E1260_loadLearnInfo.cpp"

// 004E1720: taiinfmd.cpp:6554-6556
#include "matching/004E1720_setSaveLearnInformation.cpp"

// 004E1730: taiinfmd.cpp:6562-6649
#include "matching/004E1730_unexploredPlayerLocation.cpp"

// 004E1930: taiinfmd.cpp:6656-6676
#include "matching/004E1930_numberUnitsWithinXTiles.cpp"

// 004E1A00: taiinfmd.cpp:6682-6716
#include "matching/004E1A00_withinXTilesOfAttackOnPlayer.cpp"

// 004E1AF0: taiinfmd.cpp:6721-6744
#include "matching/004E1AF0_withinXTilesOfEnemyTowncenter.cpp"

// 004E1BD0: taiinfmd.cpp:6750-6791
#include "matching/004E1BD0_withinXTilesOfObject.cpp"

// 004E1D10: taiinfmd.cpp:6798-7027
#include "matching/004E1D10_findStagingPoint.cpp"

// 004E21E0: taiinfmd.cpp:7032-7076
#include "matching/004E21E0_setupLOSMap.cpp"

// 004E22F0: taiinfmd.cpp:7081-7114
#include "matching/004E22F0_setupAttackMap.cpp"

// 004E23A0: taiinfmd.cpp:7119-7132
#include "matching/004E23A0_addResourceType.cpp"

// 004E2440: taiinfmd.cpp:7137-7139
#include "matching/004E2440_resourceType.cpp"

// 004E2490: taiinfmd.cpp:7156-7336
#include "matching/004E2490_addResourceObject.cpp"

// 004E2A00: taiinfmd.cpp:7342-7376
#include "matching/004E2A00_findClosestDropsite.cpp"

// 004E2BA0: taiinfmd.cpp:7382-7417
#include "matching/004E2BA0_findClosestReturnDropsite.cpp"

// 004E2D10: taiinfmd.cpp:7422-7466
#include "matching/004E2D10_updateAllResourceDropsites.cpp"

// 004E2E90: taiinfmd.cpp:7471-7527
#include "matching/004E2E90_updateResourceDropsites.cpp"

// 004E3020: taiinfmd.cpp:7548-7556
#include "matching/004E3020_setResourceObjectValid.cpp"

// 004E3070: taiinfmd.cpp:7561-7571
#include "matching/004E3070_numberStoragePits.cpp"

// 004E3140: taiinfmd.cpp:7576-7586
#include "matching/004E3140_numberGranaries.cpp"

// 004E3210: taiinfmd.cpp:7592-7609
#include "matching/004E3210_amountForageBushesInXTiles.cpp"

// 004E32C0: taiinfmd.cpp:7615-7635
#include "matching/004E32C0_amountResourceTypesInXTiles.cpp"

// 004E3390: taiinfmd.cpp:7640-7716
#include "matching/004E3390_damagePerSecond.cpp"

// 004E34C0: taiinfmd.cpp:7722-7727
#include "matching/004E34C0_costToLoseUnit.cpp"

// 004E3500: taiinfmd.cpp:7732-7739
#include "scratch/004E3500_benefitToKillUnit.cpp"

// 004E3530: taiinfmd.cpp:7745-7769
#include "matching/004E3530_inRangeOfUnits.cpp"

// 004E3640: taiinfmd.cpp:7774-7854
#include "scratch/004E3640_wonderToAttack.cpp"

// 004E3840: taiinfmd.cpp:7859-7920
#include "matching/004E3840_ruinToCapture.cpp"

// 004E39D0: taiinfmd.cpp:7925-7976
#include "matching/004E39D0_artifactToCapture.cpp"

// 004E3B80: taiinfmd.cpp:7981-8013
#include "matching/004E3B80_resourceTypeToPlaceDropsiteBy.cpp"

// 004E3C90: taiinfmd.cpp:8019-8074
#include "matching/004E3C90_dropsitesWithinRequiredDistance.cpp"

// 004E3E90: taiinfmd.cpp:8079-8129
#include "matching/004E3E90_numberAvailableStoragePits.cpp"

// 004E3F80: taiinfmd.cpp:8134-8175
#include "matching/004E3F80_numberAvailableGranaries.cpp"

// 004E4040: taiinfmd.cpp:8180-8222
#include "matching/004E4040_lookAtMap.cpp"

// 004E41C0: taiinfmd.cpp:8228-8257
#include "matching/004E41C0_damageInflictedPerSecond.cpp"

// 004E4240: taiinfmd.cpp:8263-8292
#include "matching/004E4240_damageInflictedPerSecond.cpp"

// 004E42B0: taiinfmd.cpp:8298-8335
#include "matching/004E42B0_timeToBeKilled.cpp"

// 004E4350: taiinfmd.cpp:8341-8378
#include "matching/004E4350_timeToBeKilled.cpp"

// 004E43E0: taiinfmd.cpp:8383-8387
#include "matching/004E43E0_closestDropsiteResID.cpp"

// 004E4400: taiinfmd.cpp:8392-8399
#include "matching/004E4400_calculatePlayVariation.cpp"

// 004E4450: taiinfmd.cpp:8404-8449
#include "matching/004E4450_convertUnitToIntType.cpp"

// 004E4500: taiinfmd.cpp:8454-8470
#include "matching/004E4500_loadUnitHistory.cpp"

// 004E45A0: taiinfmd.cpp:8475-8498
#include "matching/004E45A0_unitsThatAreMostBuilt.cpp"

// 004E4610: taiinfmd.cpp:8503-8526
#include "matching/004E4610_unitsThatAreLeastBuilt.cpp"

// 004E4680: taiinfmd.cpp:8531-8560
#include "matching/004E4680_acceptablePotentialDropsiteArea.cpp"

// 004E4790: taiinfmd.cpp:8565-8574
#include "matching/004E4790_percentTilesExploredInPositionQuadrant.cpp"

// generated 004D7050 is emitted by the virtual destructor definition above.
#undef TAIINFMD_PREFIX_CONTEXT
