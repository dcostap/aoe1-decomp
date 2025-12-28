// Class: TribeInformationAIModule
// Size:  0x10090
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] loggingHistory
// [02] setLogHistory
// [03] toggleLogHistory
// [04] setHistoryFilename
// [05] loggingCommonHistory
// [06] setLogCommonHistory
// [07] toggleLogCommonHistory
// [08] loadState
// [09] saveState
// [10] gleanState
// [11] processMessage
// [12] update
// [13] setCallbackMessage
// [14] filterOutMessage
//
// Member Layout:
// [0x0F0] ManagedArray<int> farmsTaskedThisUpdate (sz: 0x10)
// [0x100] TribeMainDecisionAIModule * md
// [0x104] int mapXSizeValue
// [0x108] int mapYSizeValue
// [0x10C] int lastUpdateRowValue
// [0x110] int maxImportantObjectMemory
// [0x114] ObjectMemory * importantObjectMemory
// [0x118] ManagedArray<int> importantObjects (sz: 0x10)
// [0x128] ManagedArray<int> importantUnits (sz: 0x10)
// [0x138] ManagedArray<int> importantMiscs (sz: 0x10)
// [0x148] ManagedArray<int> itemsToDefend (sz: 0x10)
// [0x158] InfluenceMap pathMap (sz: 0x28)
// [0x180] ManagedArray<int> playerObjects (sz: 0x10)
// [0x190] ManagedArray<int> playerBuildings (sz: 0x10)
// [0x1A0] XYPoint lastWallPosition (sz: 0x8)
// [0x1A8] XYPoint lastWallPosition2 (sz: 0x8)
// [0x1B0] int numberGatesValue
// [0x1B4] XYPoint[4] minGatePosition (sz: 0x20)
// [0x1D4] XYPoint[4] maxGatePosition (sz: 0x20)
// [0x1F4] int maxBuildingLots
// [0x1F8] BuildingLot * buildingLots
// [0x1FC] int maxAttackMemories
// [0x200] AttackMemory * attackMemories
// [0x204] int saveLearnInformationValue
// [0x208] char[256] learnFileName (sz: 0x100)
// [0x308] uchar[255] fullyExploredZoneValue (sz: 0xFF)
// [0x408] QuadrantLog[4][4] quadrantLog (sz: 0xC0)
// [0x4C8] int * * resourceTypesValue
// [0x4CC] int * numberResourceTypesValue
// [0x4D0] ResourceMemory *[4] resources (sz: 0x10)
// [0x4E0] int[4] numResources (sz: 0x10)
// [0x4F0] int[4] maxResources (sz: 0x10)
// [0x500] int[4][4] dropsitesByAge (sz: 0x40)
// [0x540] int[4] closestDropsiteValue (sz: 0x10)
// [0x550] int[4] closestDropsiteResourceID (sz: 0x10)
// [0x560] int numberFoundForestTilesValue
// [0x564] int[16000] playHistory (sz: 0xFA00)
// [0xFF64] int[11] unitHistory (sz: 0x2C)
// [0xFF90] char[256] unitHistoryFilename (sz: 0x100)
// ----------------------------------------------------------------

// Function: TribeInformationAIModule
// Address: 004d6bb0
// [HELPER] s_learn_Default_uh: "learn\Default.uh"
/* public: __thiscall TribeInformationAIModule::TribeInformationAIModule(void *,int) */

TribeInformationAIModule * __thiscall
TribeInformationAIModule::TribeInformationAIModule
          (TribeInformationAIModule *this,void *param_1,int param_2)
{
  char cVar1;
  int **ppiVar2;
  int *piVar3;
  int iVar4;
  int (*paiVar5) [4];
  ObjectMemory *pOVar6;
  BuildingLot *pBVar7;
  AttackMemory *pAVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  uchar *puVar14;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005603a8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  InformationAIModule::InformationAIModule((InformationAIModule *)this,param_1,param_2);
  (this->farmsTaskedThisUpdate).value = (int *)0x0;
  (this->farmsTaskedThisUpdate).numberValue = 0;
  (this->farmsTaskedThisUpdate).desiredNumberValue = 0;
  (this->farmsTaskedThisUpdate).maximumSizeValue = 0;
  this->md = (TribeMainDecisionAIModule *)0x0;
  this->mapXSizeValue = -1;
  this->mapYSizeValue = -1;
  this->lastUpdateRowValue = 0;
  this->maxImportantObjectMemory = 500;
  (this->importantObjects).value = (int *)0x0;
  (this->importantObjects).numberValue = 0;
  (this->importantObjects).desiredNumberValue = 0;
  (this->importantObjects).maximumSizeValue = 0;
  (this->importantUnits).value = (int *)0x0;
  (this->importantUnits).numberValue = 0;
  (this->importantUnits).desiredNumberValue = 0;
  (this->importantUnits).maximumSizeValue = 0;
  (this->importantMiscs).value = (int *)0x0;
  (this->importantMiscs).numberValue = 0;
  (this->importantMiscs).desiredNumberValue = 0;
  (this->importantMiscs).maximumSizeValue = 0;
  (this->itemsToDefend).value = (int *)0x0;
  (this->itemsToDefend).numberValue = 0;
  (this->itemsToDefend).desiredNumberValue = 0;
  (this->itemsToDefend).maximumSizeValue = 0;
  local_4._0_1_ = 5;
  local_4._1_3_ = 0;
  InfluenceMap::InfluenceMap(&this->pathMap,0xfe,0xfe,0xff);
  (this->playerObjects).value = (int *)0x0;
  (this->playerObjects).numberValue = 0;
  (this->playerObjects).desiredNumberValue = 0;
  (this->playerObjects).maximumSizeValue = 0;
  (this->playerBuildings).value = (int *)0x0;
  (this->playerBuildings).numberValue = 0;
  (this->playerBuildings).desiredNumberValue = 0;
  (this->playerBuildings).maximumSizeValue = 0;
  uVar9 = 0xffffffff;
  this->maxBuildingLots = 200;
  this->maxAttackMemories = 0x19;
  this->saveLearnInformationValue = 0;
  this->numberFoundForestTilesValue = 0;
  this->_padding_ = (int)&_vftable_;
  pcVar12 = &s_learn_Default_uh;
  do {
    pcVar13 = pcVar12;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    pcVar13 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar13;
  } while (cVar1 != '\0');
  uVar9 = ~uVar9;
  local_4 = CONCAT31(local_4._1_3_,8);
  pcVar12 = pcVar13 + -uVar9;
  pcVar13 = this->unitHistoryFilename;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *pcVar13 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar13 = pcVar13 + 1;
  }
  ppiVar2 = (int **)operator_new(0x10);
  this->resourceTypesValue = ppiVar2;
  piVar3 = (int *)operator_new(0x10);
  this->numberResourceTypesValue = piVar3;
  iVar11 = 0;
  do {
    iVar4 = iVar11 + 4;
    *(undefined4 *)(iVar11 + (int)this->numberResourceTypesValue) = 0;
    *(undefined4 *)(iVar11 + (int)this->resourceTypesValue) = 0;
    iVar11 = iVar4;
  } while (iVar4 < 0x10);
  piVar3 = this->unitHistory;
  for (iVar11 = 0xb; iVar11 != 0; iVar11 = iVar11 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  piVar3 = this->playHistory;
  for (iVar11 = 16000; iVar11 != 0; iVar11 = iVar11 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  paiVar5 = this->dropsitesByAge + 1;
  iVar11 = 4;
  do {
    paiVar5[-1][0] = 0;
    (*paiVar5)[0] = 1;
    paiVar5[1][0] = 1;
    paiVar5[2][0] = 1;
    paiVar5 = (int (*) [4])(*paiVar5 + 1);
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  piVar3 = this->closestDropsiteResourceID;
  iVar11 = 4;
  do {
    piVar3[-4] = -1;
    *piVar3 = -1;
    piVar3 = piVar3 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  pOVar6 = (ObjectMemory *)operator_new(this->maxImportantObjectMemory * 0x24);
  this->importantObjectMemory = pOVar6;
  if ((pOVar6 != (ObjectMemory *)0x0) && (iVar11 = 0, 0 < this->maxImportantObjectMemory)) {
    iVar4 = 0;
    do {
      iVar11 = iVar11 + 1;
      *(undefined4 *)((int)&this->importantObjectMemory->id + iVar4) = 0xffffffff;
      *(undefined2 *)((int)&this->importantObjectMemory->type + iVar4) = 0xffff;
      *(undefined2 *)((int)&this->importantObjectMemory->group + iVar4) = 0xffff;
      (&this->importantObjectMemory->x)[iVar4] = '\0';
      (&this->importantObjectMemory->y)[iVar4] = '\0';
      (&this->importantObjectMemory->z)[iVar4] = '\0';
      (&this->importantObjectMemory->owner)[iVar4] = '\0';
      *(undefined2 *)((int)&this->importantObjectMemory->hitPoints + iVar4) = 0;
      *(undefined4 *)((int)&this->importantObjectMemory->attackAttempts + iVar4) = 0;
      (&this->importantObjectMemory->kills)[iVar4] = '\0';
      *(undefined4 *)((int)&this->importantObjectMemory->damageCapability + iVar4) = 0;
      *(undefined4 *)((int)&this->importantObjectMemory->rateOfFire + iVar4) = 0;
      *(undefined4 *)((int)&this->importantObjectMemory->range + iVar4) = 0;
      iVar4 = iVar4 + 0x24;
    } while (iVar11 < this->maxImportantObjectMemory);
  }
  pBVar7 = (BuildingLot *)operator_new(this->maxBuildingLots << 3);
  this->buildingLots = pBVar7;
  if ((pBVar7 != (BuildingLot *)0x0) && (iVar11 = 0, 0 < this->maxBuildingLots)) {
    do {
      iVar4 = iVar11 + 1;
      this->buildingLots[iVar11].typeID = -1;
      this->buildingLots[iVar11].x = '\0';
      this->buildingLots[iVar11].y = '\0';
      this->buildingLots[iVar11].status = '\0';
      iVar11 = iVar4;
    } while (iVar4 < this->maxBuildingLots);
  }
  pAVar8 = (AttackMemory *)operator_new(this->maxAttackMemories * 0x18);
  this->attackMemories = pAVar8;
  if ((pAVar8 != (AttackMemory *)0x0) && (iVar11 = 0, 0 < this->maxAttackMemories)) {
    iVar4 = 0;
    do {
      iVar11 = iVar11 + 1;
      *(undefined4 *)((int)&this->attackMemories->id + iVar4) = 0xffffffff;
      *(undefined4 *)((int)&this->attackMemories->id + iVar4) = 0xffffffff;
      (&this->attackMemories->minX)[iVar4] = '\0';
      (&this->attackMemories->minY)[iVar4] = '\0';
      (&this->attackMemories->maxX)[iVar4] = '\0';
      (&this->attackMemories->maxY)[iVar4] = '\0';
      (&this->attackMemories->attackingOwner)[iVar4] = 0xff;
      (&this->attackMemories->targetOwner)[iVar4] = 0xff;
      *(undefined2 *)((int)&this->attackMemories->kills + iVar4) = 0;
      (&this->attackMemories->success)[iVar4] = '\0';
      *(undefined4 *)((int)&this->attackMemories->play + iVar4) = 0xffffffff;
      iVar4 = iVar4 + 0x18;
    } while (iVar11 < this->maxAttackMemories);
  }
  piVar3 = &this->minGatePosition[0].y;
  (this->lastWallPosition).x = -1;
  (this->lastWallPosition).y = -1;
  (this->lastWallPosition2).x = -1;
  (this->lastWallPosition2).y = -1;
  this->numberGatesValue = -1;
  iVar11 = 4;
  do {
    ((XYPoint *)(piVar3 + -1))->x = -1;
    *piVar3 = -1;
    piVar3[7] = 0xffffffff;
    piVar3[8] = 0xffffffff;
    piVar3 = piVar3 + 2;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar4 = 4;
  puVar14 = this->fullyExploredZoneValue;
  for (iVar11 = 0x3f; iVar11 != 0; iVar11 = iVar11 + -1) {
    puVar14[0] = '\0';
    puVar14[1] = '\0';
    puVar14[2] = '\0';
    puVar14[3] = '\0';
    puVar14 = puVar14 + 4;
  }
  puVar14[0] = '\0';
  puVar14[1] = '\0';
  puVar14[2] = '\0';
  piVar3 = &this->quadrantLog[0][0].numberAttacksByUs;
  do {
    iVar11 = 4;
    do {
      ((QuadrantLog *)(piVar3 + -2))->numberExploredTiles = 0;
      piVar3[-1] = 0;
      *piVar3 = 0;
      piVar3 = piVar3 + 3;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  piVar3 = this->maxResources;
  iVar11 = 4;
  do {
    piVar3[-8] = 0;
    *piVar3 = 0;
    piVar3[-4] = 0;
    piVar3 = piVar3 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004d7050
/* public: virtual void * __thiscall TribeInformationAIModule::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TribeInformationAIModule::_scalar_deleting_destructor_(TribeInformationAIModule *this,uint param_1)
{
  ~TribeInformationAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TribeInformationAIModule
// Address: 004d7070
// [HELPER] s_: ""
// [HELPER] s_learn_Default_uh: "learn\Default.uh"
/* WARNING: Variable defined which should be unmapped: tempIntNum */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall TribeInformationAIModule::TribeInformationAIModule(int,int) */

TribeInformationAIModule * __thiscall
TribeInformationAIModule::TribeInformationAIModule
          (TribeInformationAIModule *this,int param_1,int param_2)
{
  char cVar1;
  int **ppiVar2;
  int *piVar3;
  int iVar4;
  int (*paiVar5) [4];
  ObjectMemory *pOVar6;
  BuildingLot *pBVar7;
  AttackMemory *pAVar8;
  int iVar9;
  int iVar10;
  ResourceMemory *pRVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  XYPoint *pXVar15;
  char *pcVar16;
  char *pcVar17;
  undefined4 *unaff_FS_OFFSET;
  int tempIntNum;
  int tempInt;
  int tempInt_ffffffe8;
  int local_14;
  TribeInformationAIModule *local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560438;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_10 = this;
  InformationAIModule::InformationAIModule((InformationAIModule *)this,(void *)0x0,param_1);
  (this->farmsTaskedThisUpdate).value = (int *)0x0;
  (this->farmsTaskedThisUpdate).numberValue = 0;
  (this->farmsTaskedThisUpdate).desiredNumberValue = 0;
  (this->farmsTaskedThisUpdate).maximumSizeValue = 0;
  this->md = (TribeMainDecisionAIModule *)0x0;
  (this->importantObjects).value = (int *)0x0;
  (this->importantObjects).numberValue = 0;
  (this->importantObjects).desiredNumberValue = 0;
  (this->importantObjects).maximumSizeValue = 0;
  (this->importantUnits).value = (int *)0x0;
  (this->importantUnits).numberValue = 0;
  (this->importantUnits).desiredNumberValue = 0;
  (this->importantUnits).maximumSizeValue = 0;
  (this->importantMiscs).value = (int *)0x0;
  (this->importantMiscs).numberValue = 0;
  (this->importantMiscs).desiredNumberValue = 0;
  (this->importantMiscs).maximumSizeValue = 0;
  (this->itemsToDefend).value = (int *)0x0;
  (this->itemsToDefend).numberValue = 0;
  (this->itemsToDefend).desiredNumberValue = 0;
  (this->itemsToDefend).maximumSizeValue = 0;
  local_4._0_1_ = 5;
  local_4._1_3_ = 0;
  InfluenceMap::InfluenceMap(&this->pathMap,0xfe,0xfe,0xff);
  (this->playerObjects).value = (int *)0x0;
  (this->playerObjects).numberValue = 0;
  (this->playerObjects).desiredNumberValue = 0;
  (this->playerObjects).maximumSizeValue = 0;
  (this->playerBuildings).value = (int *)0x0;
  (this->playerBuildings).numberValue = 0;
  (this->playerBuildings).desiredNumberValue = 0;
  (this->playerBuildings).maximumSizeValue = 0;
  uVar12 = 0xffffffff;
  this->saveLearnInformationValue = 0;
  this->numberFoundForestTilesValue = 0;
  this->_padding_ = (int)&_vftable_;
  pcVar16 = &s_learn_Default_uh;
  do {
    pcVar17 = pcVar16;
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    pcVar17 = pcVar16 + 1;
    cVar1 = *pcVar16;
    pcVar16 = pcVar17;
  } while (cVar1 != '\0');
  uVar12 = ~uVar12;
  pcVar16 = pcVar17 + -uVar12;
  pcVar17 = this->unitHistoryFilename;
  for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar16;
    pcVar16 = pcVar16 + 4;
    pcVar17 = pcVar17 + 4;
  }
  local_4 = CONCAT31(local_4._1_3_,8);
  for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *pcVar17 = *pcVar16;
    pcVar16 = pcVar16 + 1;
    pcVar17 = pcVar17 + 1;
  }
  ppiVar2 = (int **)operator_new(0x10);
  this->resourceTypesValue = ppiVar2;
  piVar3 = (int *)operator_new(0x10);
  this->numberResourceTypesValue = piVar3;
  iVar14 = 0;
  do {
    iVar4 = iVar14 + 4;
    *(undefined4 *)(iVar14 + (int)this->numberResourceTypesValue) = 0;
    *(undefined4 *)(iVar14 + (int)this->resourceTypesValue) = 0;
    iVar14 = iVar4;
  } while (iVar4 < 0x10);
  piVar3 = this->unitHistory;
  for (iVar14 = 0xb; iVar14 != 0; iVar14 = iVar14 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  piVar3 = this->playHistory;
  for (iVar14 = 16000; iVar14 != 0; iVar14 = iVar14 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  paiVar5 = this->dropsitesByAge + 1;
  iVar14 = 4;
  do {
    paiVar5[-1][0] = 0;
    (*paiVar5)[0] = 1;
    paiVar5[1][0] = 1;
    paiVar5[2][0] = 1;
    paiVar5 = (int (*) [4])(*paiVar5 + 1);
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  piVar3 = this->closestDropsiteResourceID;
  iVar14 = 4;
  do {
    piVar3[-4] = -1;
    *piVar3 = -1;
    piVar3 = piVar3 + 1;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  iVar14 = 0;
  do {
    rge_read(param_2,&param_1,4);
    iVar4 = 0;
    if (0 < param_1) {
      do {
        rge_read(param_2,&local_14,4);
        addResourceType(this,iVar14,local_14);
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_1);
    }
    iVar4 = param_2;
    iVar14 = iVar14 + 1;
  } while (iVar14 < 4);
  rge_read(param_2,&this->mapXSizeValue,4);
  rge_read(iVar4,&this->mapYSizeValue,4);
  rge_read(iVar4,&this->lastUpdateRowValue,4);
  rge_read(iVar4,&this->maxImportantObjectMemory,4);
  pOVar6 = (ObjectMemory *)operator_new(this->maxImportantObjectMemory * 0x24);
  this->importantObjectMemory = pOVar6;
  if (pOVar6 != (ObjectMemory *)0x0) {
    iVar14 = 0;
    if (0 < this->maxImportantObjectMemory) {
      iVar4 = 0;
      do {
        rge_read(param_2,(void *)((int)&this->importantObjectMemory->id + iVar4),0x24);
        iVar14 = iVar14 + 1;
        iVar4 = iVar4 + 0x24;
      } while (iVar14 < this->maxImportantObjectMemory);
    }
    piVar3 = &this->maxBuildingLots;
    rge_read(param_2,piVar3,4);
    pBVar7 = (BuildingLot *)operator_new(*piVar3 << 3);
    this->buildingLots = pBVar7;
    if (pBVar7 != (BuildingLot *)0x0) {
      iVar14 = 0;
      if (0 < *piVar3) {
        do {
          rge_read(param_2,this->buildingLots + iVar14,8);
          iVar14 = iVar14 + 1;
        } while (iVar14 < *piVar3);
      }
      piVar3 = &this->maxAttackMemories;
      rge_read(param_2,piVar3,4);
      pAVar8 = (AttackMemory *)operator_new(*piVar3 * 0x18);
      this->attackMemories = pAVar8;
      if (pAVar8 != (AttackMemory *)0x0) {
        iVar14 = 0;
        if (0 < *piVar3) {
          iVar4 = 0;
          do {
            rge_read(param_2,(void *)((int)&this->attackMemories->id + iVar4),0x18);
            iVar14 = iVar14 + 1;
            iVar4 = iVar4 + 0x18;
          } while (iVar14 < *piVar3);
        }
        rge_read(param_2,&tempInt,4);
        param_1 = 0;
        if (0 < tempInt) {
          do {
            rge_read(param_2,&tempInt_ffffffe8,4);
            iVar4 = tempInt_ffffffe8;
            iVar14 = (this->importantObjects).numberValue;
            iVar9 = 0;
            if (0 < iVar14) {
              do {
                if ((this->importantObjects).maximumSizeValue <= iVar9) break;
                if ((this->importantObjects).value[iVar9] == tempInt_ffffffe8) goto LAB_004d74e2;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar14);
            }
            if ((this->importantObjects).maximumSizeValue + -1 < iVar14) {
              iVar14 = iVar14 + 1;
              piVar3 = (int *)operator_new(iVar14 * 4);
              if (piVar3 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (this->importantObjects).maximumSizeValue) {
                  do {
                    if (iVar14 <= iVar9) break;
                    iVar10 = iVar9 + 1;
                    piVar3[iVar9] = (this->importantObjects).value[iVar9];
                    iVar9 = iVar10;
                  } while (iVar10 < (this->importantObjects).maximumSizeValue);
                }
                operator_delete((this->importantObjects).value);
                (this->importantObjects).value = piVar3;
                (this->importantObjects).maximumSizeValue = iVar14;
              }
            }
            (this->importantObjects).value[(this->importantObjects).numberValue] = iVar4;
            (this->importantObjects).numberValue = (this->importantObjects).numberValue + 1;
LAB_004d74e2:
            param_1 = param_1 + 1;
          } while (param_1 < tempInt);
        }
        rge_read(param_2,&tempInt,4);
        param_1 = 0;
        if (0 < tempInt) {
          do {
            rge_read(param_2,&tempInt_ffffffe8,4);
            iVar4 = tempInt_ffffffe8;
            iVar14 = (this->importantUnits).numberValue;
            iVar9 = 0;
            if (0 < iVar14) {
              do {
                if ((this->importantUnits).maximumSizeValue <= iVar9) break;
                if ((this->importantUnits).value[iVar9] == tempInt_ffffffe8) goto LAB_004d75e7;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar14);
            }
            if ((this->importantUnits).maximumSizeValue + -1 < iVar14) {
              iVar14 = iVar14 + 1;
              piVar3 = (int *)operator_new(iVar14 * 4);
              if (piVar3 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (this->importantUnits).maximumSizeValue) {
                  do {
                    if (iVar14 <= iVar9) break;
                    iVar10 = iVar9 + 1;
                    piVar3[iVar9] = (this->importantUnits).value[iVar9];
                    iVar9 = iVar10;
                  } while (iVar10 < (this->importantUnits).maximumSizeValue);
                }
                operator_delete((this->importantUnits).value);
                (this->importantUnits).value = piVar3;
                (this->importantUnits).maximumSizeValue = iVar14;
              }
            }
            (this->importantUnits).value[(this->importantUnits).numberValue] = iVar4;
            (this->importantUnits).numberValue = (this->importantUnits).numberValue + 1;
LAB_004d75e7:
            param_1 = param_1 + 1;
          } while (param_1 < tempInt);
        }
        rge_read(param_2,&tempInt,4);
        param_1 = 0;
        if (0 < tempInt) {
          do {
            rge_read(param_2,&tempInt_ffffffe8,4);
            iVar4 = tempInt_ffffffe8;
            iVar14 = (this->importantMiscs).numberValue;
            iVar9 = 0;
            if (0 < iVar14) {
              do {
                if ((this->importantMiscs).maximumSizeValue <= iVar9) break;
                if ((this->importantMiscs).value[iVar9] == tempInt_ffffffe8) goto LAB_004d76ec;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar14);
            }
            if ((this->importantMiscs).maximumSizeValue + -1 < iVar14) {
              iVar14 = iVar14 + 1;
              piVar3 = (int *)operator_new(iVar14 * 4);
              if (piVar3 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (this->importantMiscs).maximumSizeValue) {
                  do {
                    if (iVar14 <= iVar9) break;
                    iVar10 = iVar9 + 1;
                    piVar3[iVar9] = (this->importantMiscs).value[iVar9];
                    iVar9 = iVar10;
                  } while (iVar10 < (this->importantMiscs).maximumSizeValue);
                }
                operator_delete((this->importantMiscs).value);
                (this->importantMiscs).value = piVar3;
                (this->importantMiscs).maximumSizeValue = iVar14;
              }
            }
            (this->importantMiscs).value[(this->importantMiscs).numberValue] = iVar4;
            (this->importantMiscs).numberValue = (this->importantMiscs).numberValue + 1;
LAB_004d76ec:
            param_1 = param_1 + 1;
          } while (param_1 < tempInt);
        }
        rge_read(param_2,&tempInt,4);
        param_1 = 0;
        if (0 < tempInt) {
          do {
            rge_read(param_2,&tempInt_ffffffe8,4);
            iVar4 = tempInt_ffffffe8;
            iVar14 = (this->itemsToDefend).numberValue;
            iVar9 = 0;
            if (0 < iVar14) {
              do {
                if ((this->itemsToDefend).maximumSizeValue <= iVar9) break;
                if ((this->itemsToDefend).value[iVar9] == tempInt_ffffffe8) goto LAB_004d77f1;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar14);
            }
            if ((this->itemsToDefend).maximumSizeValue + -1 < iVar14) {
              iVar14 = iVar14 + 1;
              piVar3 = (int *)operator_new(iVar14 * 4);
              if (piVar3 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (this->itemsToDefend).maximumSizeValue) {
                  do {
                    if (iVar14 <= iVar9) break;
                    iVar10 = iVar9 + 1;
                    piVar3[iVar9] = (this->itemsToDefend).value[iVar9];
                    iVar9 = iVar10;
                  } while (iVar10 < (this->itemsToDefend).maximumSizeValue);
                }
                operator_delete((this->itemsToDefend).value);
                (this->itemsToDefend).value = piVar3;
                (this->itemsToDefend).maximumSizeValue = iVar14;
              }
            }
            (this->itemsToDefend).value[(this->itemsToDefend).numberValue] = iVar4;
            (this->itemsToDefend).numberValue = (this->itemsToDefend).numberValue + 1;
LAB_004d77f1:
            param_1 = param_1 + 1;
          } while (param_1 < tempInt);
        }
        rge_read(param_2,&tempInt,4);
        param_1 = 0;
        if (0 < tempInt) {
          do {
            rge_read(param_2,&tempInt_ffffffe8,4);
            iVar4 = tempInt_ffffffe8;
            iVar14 = (this->playerBuildings).numberValue;
            iVar9 = 0;
            if (0 < iVar14) {
              do {
                if ((this->playerBuildings).maximumSizeValue <= iVar9) break;
                if ((this->playerBuildings).value[iVar9] == tempInt_ffffffe8) goto LAB_004d78f6;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar14);
            }
            if ((this->playerBuildings).maximumSizeValue + -1 < iVar14) {
              iVar14 = iVar14 + 1;
              piVar3 = (int *)operator_new(iVar14 * 4);
              if (piVar3 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (this->playerBuildings).maximumSizeValue) {
                  do {
                    if (iVar14 <= iVar9) break;
                    iVar10 = iVar9 + 1;
                    piVar3[iVar9] = (this->playerBuildings).value[iVar9];
                    iVar9 = iVar10;
                  } while (iVar10 < (this->playerBuildings).maximumSizeValue);
                }
                operator_delete((this->playerBuildings).value);
                (this->playerBuildings).value = piVar3;
                (this->playerBuildings).maximumSizeValue = iVar14;
              }
            }
            (this->playerBuildings).value[(this->playerBuildings).numberValue] = iVar4;
            (this->playerBuildings).numberValue = (this->playerBuildings).numberValue + 1;
LAB_004d78f6:
            param_1 = param_1 + 1;
          } while (param_1 < tempInt);
        }
        rge_read(param_2,&tempInt,4);
        param_1 = 0;
        if (0 < tempInt) {
          do {
            rge_read(param_2,&tempInt_ffffffe8,4);
            iVar4 = tempInt_ffffffe8;
            iVar14 = (this->playerObjects).numberValue;
            iVar9 = 0;
            if (0 < iVar14) {
              do {
                if ((this->playerObjects).maximumSizeValue <= iVar9) break;
                if ((this->playerObjects).value[iVar9] == tempInt_ffffffe8) goto LAB_004d79fb;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar14);
            }
            if ((this->playerObjects).maximumSizeValue + -1 < iVar14) {
              iVar14 = iVar14 + 1;
              piVar3 = (int *)operator_new(iVar14 * 4);
              if (piVar3 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (this->playerObjects).maximumSizeValue) {
                  do {
                    if (iVar14 <= iVar9) break;
                    iVar10 = iVar9 + 1;
                    piVar3[iVar9] = (this->playerObjects).value[iVar9];
                    iVar9 = iVar10;
                  } while (iVar10 < (this->playerObjects).maximumSizeValue);
                }
                operator_delete((this->playerObjects).value);
                (this->playerObjects).value = piVar3;
                (this->playerObjects).maximumSizeValue = iVar14;
              }
            }
            (this->playerObjects).value[(this->playerObjects).numberValue] = iVar4;
            (this->playerObjects).numberValue = (this->playerObjects).numberValue + 1;
LAB_004d79fb:
            param_1 = param_1 + 1;
          } while (param_1 < tempInt);
        }
        iVar14 = param_2;
        InfluenceMap::load(&this->pathMap,param_2);
        rge_read(iVar14,&this->lastWallPosition,8);
        rge_read(iVar14,&this->lastWallPosition2,8);
        if (save_game_version < _DAT_00575550) {
          iVar4 = 8;
        }
        else {
          iVar4 = 4;
        }
        rge_read(iVar14,&this->numberGatesValue,iVar4);
        pXVar15 = this->maxGatePosition;
        iVar4 = 4;
        do {
          rge_read(iVar14,pXVar15 + -4,8);
          rge_read(iVar14,pXVar15,8);
          pXVar15 = pXVar15 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        rge_read(iVar14,&this->saveLearnInformationValue,4);
        if (save_game_version < _DAT_00575550) {
          uVar12 = 0xffffffff;
          pcVar16 = s_;
          do {
            pcVar17 = pcVar16;
            if (uVar12 == 0) break;
            uVar12 = uVar12 - 1;
            pcVar17 = pcVar16 + 1;
            cVar1 = *pcVar16;
            pcVar16 = pcVar17;
          } while (cVar1 != '\0');
          uVar12 = ~uVar12;
          pcVar16 = pcVar17 + -uVar12;
          pcVar17 = this->learnFileName;
          for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *(undefined4 *)pcVar17 = *(undefined4 *)pcVar16;
            pcVar16 = pcVar16 + 4;
            pcVar17 = pcVar17 + 4;
          }
          for (uVar12 = uVar12 & 3; iVar14 = param_2, uVar12 != 0; uVar12 = uVar12 - 1) {
            *pcVar17 = *pcVar16;
            pcVar16 = pcVar16 + 1;
            pcVar17 = pcVar17 + 1;
          }
        }
        else {
          rge_read(iVar14,&tempInt_ffffffe8,4);
          rge_read(iVar14,this->learnFileName,tempInt_ffffffe8);
          this->learnFileName[tempInt_ffffffe8] = '\0';
        }
        rge_read(iVar14,this->fullyExploredZoneValue,0xff);
        if (save_game_version < _DAT_00575554) {
          piVar3 = &this->quadrantLog[0][0].numberAttacksByUs;
          iVar4 = 4;
          do {
            iVar9 = 4;
            do {
              ((QuadrantLog *)(piVar3 + -2))->numberExploredTiles = 0;
              piVar3[-1] = 0;
              *piVar3 = 0;
              piVar3 = piVar3 + 3;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        else {
          rge_read(iVar14,this->quadrantLog,0xc0);
        }
        piVar3 = this->maxResources;
        rge_read(iVar14,piVar3,0x10);
        rge_read(iVar14,this->numResources,0x10);
        iVar4 = 4;
        do {
          if (*piVar3 == 0) {
            piVar3[-8] = 0;
          }
          else {
            pRVar11 = (ResourceMemory *)operator_new(*piVar3 * 0x14);
            piVar3[-8] = (int)pRVar11;
            rge_read(iVar14,pRVar11,*piVar3 * 0x14);
          }
          piVar3 = piVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (_DAT_00575558 <= save_game_version) {
          rge_read(iVar14,this->dropsitesByAge,0x40);
        }
        if (_DAT_00575558 <= save_game_version) {
          rge_read(iVar14,this->closestDropsiteValue,0x10);
          rge_read(iVar14,this->closestDropsiteResourceID,0x10);
        }
        if (_DAT_0057555c <= save_game_version) {
          rge_read(iVar14,&this->numberFoundForestTilesValue,4);
        }
        if (_DAT_00575560 <= save_game_version) {
          rge_read(iVar14,this->playHistory,64000);
        }
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~TribeInformationAIModule
// Address: 004d7cb0
/* WARNING: Variable defined which should be unmapped: count */
/* public: virtual __thiscall TribeInformationAIModule::~TribeInformationAIModule(void) */

void __thiscall TribeInformationAIModule::~TribeInformationAIModule(TribeInformationAIModule *this)
{
  void *pvVar1;
  byte bVar2;
  AttackMemory *pAVar3;
  ObjectMemory *pOVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ResourceMemory **ppRVar10;
  undefined4 *unaff_FS_OFFSET;
  int count;
  int tempInt;
  int outFile;
  int local_14;
  TribeInformationAIModule *local_10;
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_005604c8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  iVar8 = 0;
  local_4 = 8;
  iVar9 = 0;
  local_10 = this;
  do {
    operator_delete(*(void **)(iVar9 + (int)this->resourceTypesValue));
    iVar9 = iVar9 + 4;
  } while (iVar9 < 0x10);
  operator_delete(this->resourceTypesValue);
  operator_delete(this->numberResourceTypesValue);
  if ((this->saveLearnInformationValue == 1) &&
     (iVar9 = rge_open(this->learnFileName,0x8301,0x180), local_14 = iVar9, iVar9 != -1)) {
    rge_write(iVar9,&this->mapXSizeValue,4);
    rge_write(iVar9,&this->mapYSizeValue,4);
    iVar7 = this->maxAttackMemories;
    tempInt = 0;
    if (0 < iVar7) {
      pAVar3 = this->attackMemories;
      do {
        if (pAVar3->id != -1) {
          tempInt = tempInt + 1;
        }
        pAVar3 = pAVar3 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    rge_write(iVar9,&tempInt,4);
    if (0 < this->maxAttackMemories) {
      iVar7 = 0;
      do {
        if (*(int *)((int)&this->attackMemories->id + iVar7) != -1) {
          rge_write(iVar9,(void *)((int)&this->attackMemories->id + iVar7),0x18);
        }
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + 0x18;
      } while (iVar8 < this->maxAttackMemories);
    }
    iVar8 = this->maxImportantObjectMemory;
    tempInt = 0;
    if (0 < iVar8) {
      pOVar4 = this->importantObjectMemory;
      do {
        if ((pOVar4->id != -1) && (pOVar4->type == 0x6d)) {
          tempInt = tempInt + 1;
        }
        pOVar4 = pOVar4 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    rge_write(iVar9,&tempInt,4);
    iVar8 = 0;
    if (0 < this->maxImportantObjectMemory) {
      iVar7 = 0;
      do {
        pvVar1 = (void *)((int)&this->importantObjectMemory->id + iVar7);
        if ((*(int *)((int)&this->importantObjectMemory->id + iVar7) != -1) &&
           (*(short *)((int)pvVar1 + 4) == 0x6d)) {
          rge_write(iVar9,pvVar1,0x24);
        }
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + 0x24;
      } while (iVar8 < this->maxImportantObjectMemory);
    }
    piVar5 = this->maxResources;
    iVar8 = 4;
    do {
      rge_write(iVar9,piVar5,4);
      rge_write(iVar9,piVar5 + -4,4);
      if (*piVar5 != 0) {
        rge_write(iVar9,(ResourceMemory *)piVar5[-8],*piVar5 * 0x14);
      }
      piVar5 = piVar5 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    outFile = (this->importantMiscs).numberValue;
    rge_write(iVar9,&outFile,4);
    iVar8 = 0;
    if (0 < (this->importantMiscs).numberValue) {
      do {
        if (((this->importantMiscs).maximumSizeValue + -1 < iVar8) &&
           (piVar5 = (int *)operator_new(iVar8 * 4 + 4), piVar5 != (int *)0x0)) {
          iVar7 = 0;
          if (0 < (this->importantMiscs).maximumSizeValue) {
            do {
              if (iVar8 + 1 <= iVar7) break;
              iVar6 = iVar7 + 1;
              piVar5[iVar7] = (this->importantMiscs).value[iVar7];
              iVar7 = iVar6;
            } while (iVar6 < (this->importantMiscs).maximumSizeValue);
          }
          operator_delete((this->importantMiscs).value);
          (this->importantMiscs).value = piVar5;
          (this->importantMiscs).maximumSizeValue = iVar8 + 1;
        }
        outFile = (this->importantMiscs).value[iVar8];
        rge_write(iVar9,&outFile,4);
        iVar8 = iVar8 + 1;
      } while (iVar8 < (this->importantMiscs).numberValue);
    }
    outFile = (this->itemsToDefend).numberValue;
    rge_write(iVar9,&outFile,4);
    iVar8 = 0;
    if (0 < (this->itemsToDefend).numberValue) {
      do {
        if ((this->itemsToDefend).maximumSizeValue + -1 < iVar8) {
          piVar5 = (int *)operator_new(iVar8 * 4 + 4);
          iVar9 = local_14;
          if (piVar5 != (int *)0x0) {
            iVar9 = 0;
            if (0 < (this->itemsToDefend).maximumSizeValue) {
              do {
                if (iVar8 + 1 <= iVar9) break;
                iVar7 = iVar9 + 1;
                piVar5[iVar9] = (this->itemsToDefend).value[iVar9];
                iVar9 = iVar7;
              } while (iVar7 < (this->itemsToDefend).maximumSizeValue);
            }
            operator_delete((this->itemsToDefend).value);
            (this->itemsToDefend).value = piVar5;
            (this->itemsToDefend).maximumSizeValue = iVar8 + 1;
            iVar9 = local_14;
          }
        }
        outFile = (this->itemsToDefend).value[iVar8];
        rge_write(iVar9,&outFile,4);
        iVar8 = iVar8 + 1;
      } while (iVar8 < (this->itemsToDefend).numberValue);
    }
    rge_close(iVar9);
  }
  iVar8 = this->md->_padding_;
  bVar2 = *(byte *)(*(int *)(iVar8 + 0x3c) + 0x11d);
  if ((((ushort)bVar2 == *(ushort *)(iVar8 + 0x4a)) || (bVar2 == 0xff)) &&
     (iVar8 = rge_open(this->unitHistoryFilename,0x8301,0x180), iVar8 != -1)) {
    rge_write(iVar8,this->unitHistory,0x2c);
    rge_close(iVar8);
  }
  if (this->importantObjectMemory != (ObjectMemory *)0x0) {
    operator_delete(this->importantObjectMemory);
  }
  if (this->buildingLots != (BuildingLot *)0x0) {
    operator_delete(this->buildingLots);
  }
  if (this->attackMemories != (AttackMemory *)0x0) {
    operator_delete(this->attackMemories);
  }
  ppRVar10 = this->resources;
  iVar8 = 4;
  do {
    if (*ppRVar10 != (ResourceMemory *)0x0) {
      operator_delete(*ppRVar10);
      *ppRVar10 = (ResourceMemory *)0x0;
    }
    ppRVar10 = ppRVar10 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  piVar5 = (this->playerBuildings).value;
  local_4._0_1_ = 7;
  if (piVar5 != (int *)0x0) {
    operator_delete(piVar5);
    (this->playerBuildings).value = (int *)0x0;
  }
  (this->playerBuildings).numberValue = 0;
  (this->playerBuildings).desiredNumberValue = 0;
  (this->playerBuildings).maximumSizeValue = 0;
  piVar5 = (this->playerObjects).value;
  local_4._0_1_ = 6;
  if (piVar5 != (int *)0x0) {
    operator_delete(piVar5);
    (this->playerObjects).value = (int *)0x0;
  }
  (this->playerObjects).numberValue = 0;
  (this->playerObjects).desiredNumberValue = 0;
  (this->playerObjects).maximumSizeValue = 0;
  local_4._0_1_ = 5;
  InfluenceMap::~InfluenceMap(&this->pathMap);
  piVar5 = (this->itemsToDefend).value;
  local_4._0_1_ = 4;
  if (piVar5 != (int *)0x0) {
    operator_delete(piVar5);
    (this->itemsToDefend).value = (int *)0x0;
  }
  (this->itemsToDefend).numberValue = 0;
  (this->itemsToDefend).desiredNumberValue = 0;
  (this->itemsToDefend).maximumSizeValue = 0;
  piVar5 = (this->importantMiscs).value;
  local_4._0_1_ = 3;
  if (piVar5 != (int *)0x0) {
    operator_delete(piVar5);
    (this->importantMiscs).value = (int *)0x0;
  }
  (this->importantMiscs).numberValue = 0;
  (this->importantMiscs).desiredNumberValue = 0;
  (this->importantMiscs).maximumSizeValue = 0;
  piVar5 = (this->importantUnits).value;
  local_4._0_1_ = 2;
  if (piVar5 != (int *)0x0) {
    operator_delete(piVar5);
    (this->importantUnits).value = (int *)0x0;
  }
  (this->importantUnits).numberValue = 0;
  (this->importantUnits).desiredNumberValue = 0;
  (this->importantUnits).maximumSizeValue = 0;
  piVar5 = (this->importantObjects).value;
  local_4._0_1_ = 1;
  if (piVar5 != (int *)0x0) {
    operator_delete(piVar5);
    (this->importantObjects).value = (int *)0x0;
  }
  (this->importantObjects).numberValue = 0;
  (this->importantObjects).desiredNumberValue = 0;
  (this->importantObjects).maximumSizeValue = 0;
  piVar5 = (this->farmsTaskedThisUpdate).value;
  local_4 = (uint)local_4._1_3_ << 8;
  if (piVar5 != (int *)0x0) {
    operator_delete(piVar5);
    (this->farmsTaskedThisUpdate).value = (int *)0x0;
  }
  (this->farmsTaskedThisUpdate).numberValue = 0;
  (this->farmsTaskedThisUpdate).desiredNumberValue = 0;
  (this->farmsTaskedThisUpdate).maximumSizeValue = 0;
  local_4 = 0xffffffff;
  InformationAIModule::~InformationAIModule((InformationAIModule *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: initialize
// Address: 004d8270
// [HELPER] s_learn_Default_uh: "learn\Default.uh"
// [HELPER] s_learn__s_uh: "learn\%s.uh"
/* public: int __thiscall TribeInformationAIModule::initialize(void) */

int __thiscall TribeInformationAIModule::initialize(TribeInformationAIModule *this)
{
  char cVar1;
  int iVar2;
  RGE_Game_Info *this_00;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
  iVar2 = *(int *)(*(int *)(this->md->_padding_ + 0x3c) + 0x28);
  this->mapXSizeValue = *(int *)(iVar2 + 8);
  this->mapYSizeValue = *(int *)(iVar2 + 0xc);
  this_00 = rge_base_game->player_game_info;
  pcVar3 = RGE_Game_Info::get_current_player_name(this_00);
  if (pcVar3 != (char *)0x0) {
    pcVar3 = RGE_Game_Info::get_current_player_name(this_00);
    sprintf(this->unitHistoryFilename,s_learn__s_uh,pcVar3);
    return 1;
  }
  uVar4 = 0xffffffff;
  pcVar3 = &s_learn_Default_uh;
  do {
    pcVar6 = pcVar3;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar3 = pcVar6 + -uVar4;
  pcVar6 = this->unitHistoryFilename;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar6 = pcVar6 + 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: update
// Address: 004d8300
/* WARNING: Variable defined which should be unmapped: visibleStatus */
/* public: virtual int __thiscall TribeInformationAIModule::update(int) */

int __thiscall TribeInformationAIModule::update(TribeInformationAIModule *this,int param_1)
{
  QuadrantLog *pQVar1;
  RGE_Tile *pRVar2;
  undefined4 *puVar3;
  RGE_Static_Object *pRVar4;
  uchar uVar5;
  int iVar6;
  int iVar7;
  uchar visibleStatus;
  int qX;
  RGE_Tile_List_Node *list;
  RGE_Map *gMap;
  int i;
  int listSize;
  RGE_Visible_Map *vMap;
  RGE_Visible_Map *local_c;
  int tileType;
  uint local_4;
  
  RGE_Tile_List::get_list_info
            ((RGE_Tile_List *)(this->md->_padding_ + 0x58),(RGE_Tile_List_Node **)&gMap,(int *)&vMap
            );
  iVar6 = RGE_Tile_List::get_new_count((RGE_Tile_List *)(this->md->_padding_ + 0x58));
  iVar7 = this->md->_padding_;
  local_c = *(RGE_Visible_Map **)(iVar7 + 0x38);
  i = *(int *)(*(int *)(iVar7 + 0x3c) + 0x28);
  if ((0 < iVar6) && (listSize = (int)vMap - iVar6, listSize < (int)vMap)) {
    tileType = (int)&this->pathMap;
    do {
      pRVar2 = gMap->map;
      iVar6 = gMap->_padding_;
      uVar5 = RGE_Visible_Map::get_visible(local_c,iVar6,(int)pRVar2);
      iVar7 = (int)pRVar2 * 4;
      local_4 = *(byte *)(*(int *)(*(int *)(i + 0x8d8c) + iVar7) + 5 + iVar6 * 0x18) & 0x1f;
      if (this->mapXSizeValue != -1) {
        pQVar1 = this->quadrantLog[(iVar6 * 4) / this->mapXSizeValue] + iVar7 / this->mapYSizeValue;
        pQVar1->numberExploredTiles = pQVar1->numberExploredTiles + 1;
      }
      InfluenceMap::setValue((InfluenceMap *)tileType,iVar6,(int)pRVar2,'\0');
      list = (RGE_Tile_List_Node *)0x0;
      for (puVar3 = *(undefined4 **)(*(int *)(*(int *)(i + 0x8d8c) + iVar7) + 0x10 + iVar6 * 0x18);
          puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)puVar3[1]) {
        pRVar4 = (RGE_Static_Object *)*puVar3;
        if ((uVar5 != 0x80) || (pRVar4->master_obj->fog_flag != '\0')) {
          iVar6 = (int)pRVar4->master_obj->object_group;
          iVar7 = importantObject(this,iVar6);
          if (iVar7 == 1) {
            addImportantObject(this,pRVar4,0);
          }
          if (iVar6 == 0xf) {
            list = (RGE_Tile_List_Node *)((int)&list->col + 1);
          }
        }
      }
      if ((0 < (int)list) &&
         ((((local_4 == 10 || (local_4 == 0x13)) || (local_4 == 0xd)) || (local_4 == 0x14)))) {
        this->numberFoundForestTilesValue = this->numberFoundForestTilesValue + 1;
      }
      listSize = listSize + 1;
      gMap = (RGE_Map *)&gMap->map_width;
    } while (listSize < (int)vMap);
  }
  return 1;
}

// --------------------------------------------------

// Function: setMainDecisionAI
// Address: 004d84d0
/* public: void __thiscall TribeInformationAIModule::setMainDecisionAI(class
   TribeMainDecisionAIModule *) */

void __thiscall
TribeInformationAIModule::setMainDecisionAI
          (TribeInformationAIModule *this,TribeMainDecisionAIModule *param_1)
{
  this->md = param_1;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004d84e0
/* WARNING: Variable defined which should be unmapped: tempInt */
/* public: int __thiscall TribeInformationAIModule::save(int) */

int __thiscall TribeInformationAIModule::save(TribeInformationAIModule *this,int param_1)
{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  XYPoint *pXVar10;
  char *pcVar11;
  int tempInt;
  undefined4 local_4;
  
  iVar3 = param_1;
  iVar9 = 0;
  do {
    local_4 = *(undefined4 *)(iVar9 + (int)this->numberResourceTypesValue);
    rge_write(iVar3,&local_4,4);
    iVar8 = 0;
    if (0 < *(int *)(iVar9 + (int)this->numberResourceTypesValue)) {
      do {
        local_4 = *(undefined4 *)(*(int *)(iVar9 + (int)this->resourceTypesValue) + iVar8 * 4);
        rge_write(iVar3,&local_4,4);
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(iVar9 + (int)this->numberResourceTypesValue));
    }
    iVar9 = iVar9 + 4;
  } while (iVar9 < 0x10);
  rge_write(iVar3,&this->mapXSizeValue,4);
  rge_write(iVar3,&this->mapYSizeValue,4);
  rge_write(iVar3,&this->lastUpdateRowValue,4);
  rge_write(iVar3,&this->maxImportantObjectMemory,4);
  iVar9 = 0;
  if (0 < this->maxImportantObjectMemory) {
    iVar8 = 0;
    do {
      rge_write(iVar3,(void *)((int)&this->importantObjectMemory->id + iVar8),0x24);
      iVar9 = iVar9 + 1;
      iVar8 = iVar8 + 0x24;
    } while (iVar9 < this->maxImportantObjectMemory);
  }
  piVar4 = &this->maxBuildingLots;
  rge_write(iVar3,piVar4,4);
  iVar9 = 0;
  if (0 < *piVar4) {
    do {
      rge_write(iVar3,this->buildingLots + iVar9,8);
      iVar9 = iVar9 + 1;
    } while (iVar9 < *piVar4);
  }
  rge_write(iVar3,&this->maxAttackMemories,4);
  iVar9 = 0;
  if (0 < this->maxAttackMemories) {
    iVar8 = 0;
    do {
      rge_write(iVar3,(void *)((int)&this->attackMemories->id + iVar8),0x18);
      iVar9 = iVar9 + 1;
      iVar8 = iVar8 + 0x18;
    } while (iVar9 < this->maxAttackMemories);
  }
  param_1 = (this->importantObjects).numberValue;
  rge_write(iVar3,&param_1,4);
  iVar9 = 0;
  if (0 < (this->importantObjects).numberValue) {
    do {
      if ((this->importantObjects).maximumSizeValue + -1 < iVar9) {
        piVar4 = (int *)operator_new(iVar9 * 4 + 4);
        if (piVar4 != (int *)0x0) {
          iVar8 = 0;
          if (0 < (this->importantObjects).maximumSizeValue) {
            do {
              if (iVar9 + 1 <= iVar8) break;
              iVar5 = iVar8 + 1;
              piVar4[iVar8] = (this->importantObjects).value[iVar8];
              iVar8 = iVar5;
            } while (iVar5 < (this->importantObjects).maximumSizeValue);
          }
          operator_delete((this->importantObjects).value);
          (this->importantObjects).value = piVar4;
          (this->importantObjects).maximumSizeValue = iVar9 + 1;
        }
      }
      param_1 = (this->importantObjects).value[iVar9];
      rge_write(iVar3,&param_1,4);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (this->importantObjects).numberValue);
  }
  param_1 = (this->importantUnits).numberValue;
  rge_write(iVar3,&param_1,4);
  iVar9 = 0;
  if (0 < (this->importantUnits).numberValue) {
    do {
      if ((this->importantUnits).maximumSizeValue + -1 < iVar9) {
        piVar4 = (int *)operator_new(iVar9 * 4 + 4);
        if (piVar4 != (int *)0x0) {
          iVar8 = 0;
          if (0 < (this->importantUnits).maximumSizeValue) {
            do {
              if (iVar9 + 1 <= iVar8) break;
              iVar5 = iVar8 + 1;
              piVar4[iVar8] = (this->importantUnits).value[iVar8];
              iVar8 = iVar5;
            } while (iVar5 < (this->importantUnits).maximumSizeValue);
          }
          operator_delete((this->importantUnits).value);
          (this->importantUnits).value = piVar4;
          (this->importantUnits).maximumSizeValue = iVar9 + 1;
        }
      }
      param_1 = (this->importantUnits).value[iVar9];
      rge_write(iVar3,&param_1,4);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (this->importantUnits).numberValue);
  }
  param_1 = (this->importantMiscs).numberValue;
  rge_write(iVar3,&param_1,4);
  iVar9 = 0;
  if (0 < (this->importantMiscs).numberValue) {
    do {
      if ((this->importantMiscs).maximumSizeValue + -1 < iVar9) {
        piVar4 = (int *)operator_new(iVar9 * 4 + 4);
        if (piVar4 != (int *)0x0) {
          iVar8 = 0;
          if (0 < (this->importantMiscs).maximumSizeValue) {
            do {
              if (iVar9 + 1 <= iVar8) break;
              iVar5 = iVar8 + 1;
              piVar4[iVar8] = (this->importantMiscs).value[iVar8];
              iVar8 = iVar5;
            } while (iVar5 < (this->importantMiscs).maximumSizeValue);
          }
          operator_delete((this->importantMiscs).value);
          (this->importantMiscs).value = piVar4;
          (this->importantMiscs).maximumSizeValue = iVar9 + 1;
        }
      }
      param_1 = (this->importantMiscs).value[iVar9];
      rge_write(iVar3,&param_1,4);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (this->importantMiscs).numberValue);
  }
  param_1 = (this->itemsToDefend).numberValue;
  rge_write(iVar3,&param_1,4);
  iVar9 = 0;
  if (0 < (this->itemsToDefend).numberValue) {
    do {
      if ((this->itemsToDefend).maximumSizeValue + -1 < iVar9) {
        piVar4 = (int *)operator_new(iVar9 * 4 + 4);
        if (piVar4 != (int *)0x0) {
          iVar8 = 0;
          if (0 < (this->itemsToDefend).maximumSizeValue) {
            do {
              if (iVar9 + 1 <= iVar8) break;
              iVar5 = iVar8 + 1;
              piVar4[iVar8] = (this->itemsToDefend).value[iVar8];
              iVar8 = iVar5;
            } while (iVar5 < (this->itemsToDefend).maximumSizeValue);
          }
          operator_delete((this->itemsToDefend).value);
          (this->itemsToDefend).value = piVar4;
          (this->itemsToDefend).maximumSizeValue = iVar9 + 1;
        }
      }
      param_1 = (this->itemsToDefend).value[iVar9];
      rge_write(iVar3,&param_1,4);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (this->itemsToDefend).numberValue);
  }
  param_1 = (this->playerBuildings).numberValue;
  rge_write(iVar3,&param_1,4);
  iVar9 = 0;
  if (0 < (this->playerBuildings).numberValue) {
    do {
      if ((this->playerBuildings).maximumSizeValue + -1 < iVar9) {
        piVar4 = (int *)operator_new(iVar9 * 4 + 4);
        if (piVar4 != (int *)0x0) {
          iVar8 = 0;
          if (0 < (this->playerBuildings).maximumSizeValue) {
            do {
              if (iVar9 + 1 <= iVar8) break;
              iVar5 = iVar8 + 1;
              piVar4[iVar8] = (this->playerBuildings).value[iVar8];
              iVar8 = iVar5;
            } while (iVar5 < (this->playerBuildings).maximumSizeValue);
          }
          operator_delete((this->playerBuildings).value);
          (this->playerBuildings).value = piVar4;
          (this->playerBuildings).maximumSizeValue = iVar9 + 1;
        }
      }
      param_1 = (this->playerBuildings).value[iVar9];
      rge_write(iVar3,&param_1,4);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (this->playerBuildings).numberValue);
  }
  param_1 = (this->playerObjects).numberValue;
  rge_write(iVar3,&param_1,4);
  iVar9 = 0;
  if (0 < (this->playerObjects).numberValue) {
    do {
      if ((this->playerObjects).maximumSizeValue + -1 < iVar9) {
        piVar4 = (int *)operator_new(iVar9 * 4 + 4);
        if (piVar4 != (int *)0x0) {
          iVar8 = 0;
          if (0 < (this->playerObjects).maximumSizeValue) {
            do {
              if (iVar9 + 1 <= iVar8) break;
              iVar5 = iVar8 + 1;
              piVar4[iVar8] = (this->playerObjects).value[iVar8];
              iVar8 = iVar5;
            } while (iVar5 < (this->playerObjects).maximumSizeValue);
          }
          operator_delete((this->playerObjects).value);
          (this->playerObjects).value = piVar4;
          (this->playerObjects).maximumSizeValue = iVar9 + 1;
        }
      }
      param_1 = (this->playerObjects).value[iVar9];
      rge_write(iVar3,&param_1,4);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (this->playerObjects).numberValue);
  }
  InfluenceMap::save(&this->pathMap,iVar3);
  rge_write(iVar3,&this->lastWallPosition,8);
  rge_write(iVar3,&this->lastWallPosition2,8);
  rge_write(iVar3,&this->numberGatesValue,4);
  pXVar10 = this->maxGatePosition;
  iVar9 = 4;
  do {
    rge_write(iVar3,pXVar10 + -4,8);
    rge_write(iVar3,pXVar10,8);
    pXVar10 = pXVar10 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  rge_write(iVar3,&this->saveLearnInformationValue,4);
  pcVar1 = this->learnFileName;
  uVar7 = 0xffffffff;
  pcVar11 = pcVar1;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar2 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar2 != '\0');
  param_1 = ~uVar7 - 1;
  rge_write(iVar3,&param_1,4);
  uVar7 = 0xffffffff;
  pcVar11 = pcVar1;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar2 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar2 != '\0');
  rge_write(iVar3,pcVar1,~uVar7 - 1);
  rge_write(iVar3,this->fullyExploredZoneValue,0xff);
  rge_write(iVar3,this->quadrantLog,0xc0);
  piVar4 = this->maxResources;
  iVar9 = 4;
  piVar6 = piVar4;
  do {
    if ((*piVar6 != 0) && ((ResourceMemory *)piVar6[-8] == (ResourceMemory *)0x0)) {
      *piVar6 = 0;
    }
    piVar6 = piVar6 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  rge_write(iVar3,piVar4,0x10);
  rge_write(iVar3,this->numResources,0x10);
  iVar9 = 4;
  do {
    if (*piVar4 != 0) {
      rge_write(iVar3,(ResourceMemory *)piVar4[-8],*piVar4 * 0x14);
    }
    piVar4 = piVar4 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  rge_write(iVar3,this->dropsitesByAge,0x40);
  rge_write(iVar3,this->closestDropsiteValue,0x10);
  rge_write(iVar3,this->closestDropsiteResourceID,0x10);
  rge_write(iVar3,&this->numberFoundForestTilesValue,4);
  rge_write(iVar3,this->playHistory,64000);
  return 1;
}

// --------------------------------------------------

// Function: blotExploredMap
// Address: 004d8c80
/* WARNING: Variable defined which should be unmapped: max */
/* public: void __thiscall TribeInformationAIModule::blotExploredMap(int,int,int,int) */

void __thiscall
TribeInformationAIModule::blotExploredMap
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  XYPoint max;
  XYPoint min;
  
  min.y = param_1;
  mapBound(this,(XYPoint *)&min.y);
  min.x = param_4;
  max.y = param_3;
  mapBound(this,(XYPoint *)&max.y);
  iVar1 = min.x;
  iVar2 = min.y;
  if (min.y <= max.y) {
    do {
      if (param_2 <= iVar1) {
        iVar3 = param_2;
        do {
          iVar1 = InfluenceMap::lookupValue(&this->pathMap,iVar2,iVar3);
          if (iVar1 != 1) {
            InfluenceMap::setValue(&this->pathMap,iVar2,iVar3,'\x02');
          }
          iVar3 = iVar3 + 1;
          iVar1 = min.x;
        } while (iVar3 <= min.x);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= max.y);
  }
  return;
}

// --------------------------------------------------

// Function: closestUnexploredTile
// Address: 004d8d20
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
/* WARNING: Variable defined which should be unmapped: initialZone */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TribeInformationAIModule::closestUnexploredTile(int,float,float,float
   *,float *) */

int __thiscall
TribeInformationAIModule::closestUnexploredTile
          (TribeInformationAIModule *this,int param_1,float param_2,float param_3,float *param_4,
          float *param_5)
{
  RGE_Visible_Map *this_00;
  char cVar1;
  bool bVar2;
  bool bVar3;
  uchar uVar4;
  uchar uVar5;
  RGE_Static_Object *this_01;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined4 uVar11;
  QuadrantLog *pQVar12;
  uint uVar13;
  int unaff_EBX;
  float *pfVar14;
  bool bVar15;
  uchar initialZone;
  int direction;
  RGE_Static_Object *obj;
  int offTop;
  int offBottom;
  int civilianObj;
  int j;
  int i;
  int local_1c;
  RGE_Visible_Map *vMap;
  int stepSize;
  float pathDistance;
  XYPoint cPoint;
  int local_4;
  
  iVar7 = this->md->_padding_;
  this_00 = *(RGE_Visible_Map **)(iVar7 + 0x38);
  this_01 = RGE_Game_World::object(*(RGE_Game_World **)(iVar7 + 0x3c),param_1);
  if (this_01 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  bVar15 = this_01->master_obj->object_group == 4;
  uVar4 = RGE_Static_Object::currentZone(this_01);
  uVar6 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x397);
  uVar13 = (int)uVar6 >> 0x1f;
  pfVar14 = (float *)0x0;
  obj = (RGE_Static_Object *)(((uVar6 ^ uVar13) - uVar13 & 3 ^ uVar13) - uVar13);
  iVar7 = __ftol();
  cPoint.y = iVar7;
  iVar8 = __ftol();
  bVar2 = false;
  bVar3 = false;
  offBottom = 0;
  civilianObj = 0;
  local_4 = iVar8;
  do {
    if ((((bVar2) && (bVar3)) && (offBottom != 0)) && (civilianObj != 0)) {
      setFullyExploredZone(this,param_1,1);
      return 0;
    }
    pfVar14 = (float *)((int)pfVar14 + 1);
    local_1c = 0;
    do {
      i = 0;
      puVar9 = (undefined1 *)((int)&obj->_padding_ + 1);
      uVar6 = (int)puVar9 >> 0x1f;
      obj = (RGE_Static_Object *)((((uint)puVar9 ^ uVar6) - uVar6 & 3 ^ uVar6) - uVar6);
      if (0 < (int)pfVar14) {
        do {
          switch(obj) {
          case (RGE_Static_Object *)0x0:
            iVar8 = iVar8 + 1;
            local_4 = iVar8;
            break;
          case (RGE_Static_Object *)0x1:
            iVar7 = iVar7 + 1;
            cPoint.y = iVar7;
            break;
          case (RGE_Static_Object *)0x2:
            iVar8 = iVar8 + -1;
            local_4 = iVar8;
            break;
          case (RGE_Static_Object *)0x3:
            iVar7 = iVar7 + -1;
            cPoint.y = iVar7;
          }
          if (iVar7 < 0) {
            bVar2 = true;
          }
          else if (iVar7 < this->mapXSizeValue) {
            if (iVar8 < 0) {
              offBottom = 1;
            }
            else if (iVar8 < this->mapYSizeValue) {
              iVar10 = InfluenceMap::lookupValue(&this->pathMap,iVar7,iVar8);
              cVar1 = (char)iVar10;
              uVar5 = RGE_Visible_Map::get_visible(this_00,iVar7,iVar8);
              if ((((uVar5 != '\x0f') && ((!bVar15 || (cVar1 == -1)))) &&
                  ((bVar15 || ((cVar1 == -1 || (cVar1 == '\x02')))))) &&
                 ((iVar10 = (**(code **)(this_01->_padding_ + 0x114))
                                      ((float)cPoint.y,(float)local_4,1), iVar10 != 0 &&
                  (uVar5 = RGE_Static_Object::lookupZone(this_01,iVar7,iVar8), uVar5 == uVar4)))) {
                uVar11 = __ftol();
                iVar10 = (**(code **)(this_01->_padding_ + 0x198))
                                   (iVar7,iVar8,uVar11,this_01->master_obj->los - _DAT_00575564,
                                    0xffffffff,&cPoint,1,0xffffffff,0xffffffff);
                if (iVar10 == 0) {
                  InfluenceMap::setValue(&this->pathMap,iVar7,iVar8,'\x01');
                  iVar7 = -1;
                  offBottom = 0;
                  vMap = (RGE_Visible_Map *)0x0;
                  local_1c = 0;
                  pQVar12 = this->quadrantLog[0];
                  do {
                    i = 0;
                    do {
                      iVar8 = ((QuadrantLog *)&pQVar12->numberExploredTiles)->numberExploredTiles;
                      iVar10 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x420);
                      iVar8 = pQVar12->numberAttacksOnUs * 0x19 + iVar8 + iVar10 % 100;
                      if ((iVar7 == -1) || (iVar8 < iVar7)) {
                        iVar7 = *(int *)(unaff_EBX + 0x104) * local_1c;
                        iVar10 = *(int *)(unaff_EBX + 0x108) * i;
                        offBottom = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
                        vMap = (RGE_Visible_Map *)((int)(iVar10 + (iVar10 >> 0x1f & 3U)) >> 2);
                        iVar7 = iVar8;
                      }
                      pQVar12 = pQVar12 + 1;
                      i = i + 1;
                    } while (i < 4);
                    local_1c = local_1c + 1;
                  } while (local_1c < 4);
                  iVar7 = ((int)(*(int *)(unaff_EBX + 0x104) +
                                (*(int *)(unaff_EBX + 0x104) >> 0x1f & 3U)) >> 2) + -1 + offBottom;
                  civilianObj = ((int)(*(int *)(unaff_EBX + 0x108) +
                                      (*(int *)(unaff_EBX + 0x108) >> 0x1f & 3U)) >> 2) + -1 +
                                (int)vMap;
                  uVar6 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x430);
                  uVar13 = (int)uVar6 >> 0x1f;
                  uVar6 = (uVar6 ^ uVar13) - uVar13 & 3 ^ uVar13;
                  iVar8 = uVar6 - uVar13;
                  if (uVar6 == uVar13) {
                    civilianObj = (int)vMap;
                  }
                  else if ((iVar8 != 1) && (offBottom = iVar7, iVar8 != 2)) {
                    civilianObj = (int)vMap;
                  }
                }
                else {
                  InfluenceMap::setValue(&this->pathMap,iVar7,iVar8,'\0');
                }
                this_00->map_offsets = (uchar **)(float)offBottom;
                *pfVar14 = (float)civilianObj;
                return 1;
              }
            }
            else {
              civilianObj = 1;
            }
          }
          else {
            bVar3 = true;
          }
          i = i + 1;
        } while (i < (int)pfVar14);
      }
      local_1c = local_1c + 1;
    } while (local_1c < 2);
  } while( true );
}

// --------------------------------------------------

// Function: fullyExploredZone
// Address: 004d9110
/* public: int __thiscall TribeInformationAIModule::fullyExploredZone(int) */

int __thiscall
TribeInformationAIModule::fullyExploredZone(TribeInformationAIModule *this,int param_1)
{
  byte bVar1;
  RGE_Static_Object *this_00;
  
  this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if (this_00 != (RGE_Static_Object *)0x0) {
    bVar1 = RGE_Static_Object::currentZone(this_00);
    param_1 = (int)bVar1;
    if (this->fullyExploredZoneValue[param_1] == '\0') {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: setFullyExploredZone
// Address: 004d9160
/* public: void __thiscall TribeInformationAIModule::setFullyExploredZone(int,int) */

void __thiscall
TribeInformationAIModule::setFullyExploredZone
          (TribeInformationAIModule *this,int param_1,int param_2)
{
  byte bVar1;
  RGE_Static_Object *this_00;
  
  this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if (this_00 != (RGE_Static_Object *)0x0) {
    bVar1 = RGE_Static_Object::currentZone(this_00);
    param_1 = (int)bVar1;
    this->fullyExploredZoneValue[param_1] = (uchar)param_2;
  }
  return;
}

// --------------------------------------------------

// Function: tileUncovered
// Address: 004d91a0
/* public: int __thiscall TribeInformationAIModule::tileUncovered(int,int) */

int __thiscall
TribeInformationAIModule::tileUncovered(TribeInformationAIModule *this,int param_1,int param_2)
{
  int iVar1;
  
  if ((((-1 < param_1) && (-1 < param_2)) && (param_1 < this->mapXSizeValue)) &&
     (param_2 < this->mapYSizeValue)) {
    iVar1 = InfluenceMap::lookupValue(&this->pathMap,param_1,param_2);
    if (iVar1 != 0xff) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: setTileExplored
// Address: 004d91f0
/* public: void __thiscall TribeInformationAIModule::setTileExplored(int,int) */

void __thiscall
TribeInformationAIModule::setTileExplored(TribeInformationAIModule *this,int param_1,int param_2)
{
  if ((((-1 < param_1) && (-1 < param_2)) && (param_1 < this->mapXSizeValue)) &&
     (param_2 < this->mapYSizeValue)) {
    InfluenceMap::setValue(&this->pathMap,param_1,param_2,'\0');
  }
  return;
}

// --------------------------------------------------

// Function: ownerOfGameID
// Address: 004d9230
/* public: int __thiscall TribeInformationAIModule::ownerOfGameID(int) */

int __thiscall TribeInformationAIModule::ownerOfGameID(TribeInformationAIModule *this,int param_1)
{
  return -1;
}

// --------------------------------------------------

// Function: gameIDOfResourceObject
// Address: 004d9240
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TribeInformationAIModule::gameIDOfResourceObject(int,int,float &,float
   &,int &,int *,int) */

int __thiscall
TribeInformationAIModule::gameIDOfResourceObject
          (TribeInformationAIModule *this,int param_1,int param_2,float *param_3,float *param_4,
          int *param_5,int *param_6,int param_7)
{
  short sVar1;
  ResourceMemory *pRVar2;
  bool bVar3;
  bool bVar4;
  uchar uVar5;
  uchar uVar6;
  RGE_Static_Object *this_00;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  RGE_Static_Object *pRVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  int *piVar15;
  ResourceMemory *bestObject;
  int bestValue;
  int fishingBoat;
  int i;
  int updateResourceDist;
  int gathererX;
  int gathererY;
  RGE_Static_Object *gathererObj;
  
  *param_5 = -1;
  this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_2);
  if (this_00 != (RGE_Static_Object *)0x0) {
    uVar5 = RGE_Static_Object::currentZone(this_00);
    iVar7 = __ftol();
    iVar8 = __ftol();
    iVar9 = isBoat(this,this_00);
    fishingBoat = -1;
    bestValue = 0;
    bVar4 = false;
    updateResourceDist = 0;
    piVar15 = (int *)0x0;
    if (0 < this->numResources[param_1]) {
      bestObject = (ResourceMemory *)0x0;
      do {
        piVar15 = (int *)((int)&this->resources[param_1]->id + (int)&bestObject->id);
        if (*(char *)((int)piVar15 + 0xd) != '\x01') {
          if ((char)piVar15[3] == '\0') {
            bVar3 = false;
            iVar10 = 0;
            if (0 < param_7) {
              piVar13 = param_6;
              do {
                if (*piVar13 == *piVar15) {
                  bVar3 = true;
                  break;
                }
                iVar10 = iVar10 + 1;
                piVar13 = piVar13 + 1;
              } while (iVar10 < param_7);
            }
            if (!bVar3) {
              pRVar11 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,*piVar15);
              if (pRVar11 == (RGE_Static_Object *)0x0) {
                (&bestObject->gone)[(int)this->resources[param_1]] = '\x01';
                if (this->closestDropsiteResourceID[param_1] ==
                    *(int *)((int)&this->resources[param_1]->id + (int)&bestObject->id)) {
                  bVar4 = true;
                }
              }
              else if (((((iVar9 != 1) || (sVar1 = pRVar11->master_obj->object_group, sVar1 == 5))
                        || (sVar1 == 0x1f)) || (sVar1 == 0x21)) &&
                      ((iVar9 != 0 ||
                       (((sVar1 = pRVar11->master_obj->object_group, sVar1 != 5 && (sVar1 != 0x1f))
                        && (sVar1 != 0x21)))))) {
                pRVar2 = this->resources[param_1];
                piVar15 = &bestObject->id;
                iVar10 = iVar7 - (uint)(&pRVar2->x)[(int)piVar15];
                iVar14 = iVar8 - (uint)(&pRVar2->y)[(int)piVar15];
                iVar10 = iVar10 * iVar10 + iVar14 * iVar14 +
                         *(int *)((int)&pRVar2->gatherValue + (int)piVar15) * 10;
                if (pRVar11->master_obj->id == 0x3b) {
                  if (0x14 < (&pRVar2->dropDistance)[(int)piVar15]) goto LAB_004d9646;
                  iVar10 = iVar10 + (&pRVar2->gatherAttempts)[(int)piVar15] / 0x96;
                  iVar14 = TribeTacticalAIModule::numberGatherersWithTarget
                                     (&this->md->tacticalAI,pRVar11->id);
                  if (2 < iVar14) {
                    iVar10 = iVar10 + 200;
                  }
                }
                else {
                  iVar10 = iVar10 + (&pRVar2->gatherAttempts)[(int)piVar15] / 0x32;
                }
                if ((bestValue == 0) || (iVar10 < fishingBoat)) {
                  sVar1 = pRVar11->master_obj->object_group;
                  if (((sVar1 == 9) || (sVar1 == 10)) &&
                     ((2 < pRVar11->object_state && (_DAT_00575568 < pRVar11->attribute_amount_held)
                      ))) {
                    iVar10 = iVar10 + 0x19;
                  }
                  iVar14 = withinXTilesOfEnemyTowncenter(this,pRVar11,0x19);
                  if (iVar14 != 1) {
                    iVar14 = withinXTilesOfAttackOnPlayer
                                       (this,pRVar11,0xf,(int)*(short *)(this->md->_padding_ + 0x4a)
                                       );
                    if (iVar14 == 1) {
                      iVar10 = iVar10 + 500;
                    }
                    if (pRVar11->master_obj->id == 0x32) {
                      if (((pRVar11->owner->id != *(short *)(this->md->_padding_ + 0x4a)) ||
                          (pRVar11->object_state != '\x02')) ||
                         (iVar14 = TribeTacticalAIModule::numberGatherersWithTarget
                                             (&this->md->tacticalAI,pRVar11->id), 0 < iVar14))
                      goto LAB_004d9646;
                      iVar14 = (this->farmsTaskedThisUpdate).numberValue;
                      iVar12 = 0;
                      if (0 < iVar14) {
                        do {
                          if ((this->farmsTaskedThisUpdate).maximumSizeValue <= iVar12) break;
                          if ((this->farmsTaskedThisUpdate).value[iVar12] == pRVar11->id)
                          goto LAB_004d9646;
                          iVar12 = iVar12 + 1;
                        } while (iVar12 < iVar14);
                      }
                    }
                    if (((param_1 != 1) ||
                        (iVar14 = TribeTacticalAIModule::numberGatherersWithTarget
                                            (&this->md->tacticalAI,pRVar11->id), iVar14 < 1)) &&
                       (((param_1 != 3 && (param_1 != 2)) ||
                        (iVar14 = TribeTacticalAIModule::numberGatherersWithTarget
                                            (&this->md->tacticalAI,pRVar11->id), iVar14 < 4)))) {
                      if ((pRVar11->master_obj->id == 0x30) && (pRVar11->object_state == '\x02')) {
                        iVar14 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xcc);
                        iVar12 = TribeTacticalAIModule::actualGathererCountByRealResourceID
                                           (&this->md->tacticalAI,0);
                        if (iVar12 < iVar14) goto LAB_004d9646;
                      }
                      uVar6 = RGE_Static_Object::lookupZone
                                        (this_00,(uint)(&bestObject->x)
                                                       [(int)this->resources[param_1]],
                                         (uint)(&bestObject->y)[(int)this->resources[param_1]]);
                      if ((uVar5 == uVar6) && ((bestValue == 0 || (iVar10 < fishingBoat)))) {
                        bestValue = (int)&this->resources[param_1]->id + (int)&bestObject->id;
                        *param_3 = pRVar11->world_x;
                        *param_4 = pRVar11->world_y;
                        fishingBoat = iVar10;
                      }
                    }
                  }
                }
              }
            }
          }
          else if (*(char *)((int)piVar15 + 0xd) == '\0') {
            *(char *)(piVar15 + 3) = (char)piVar15[3] + -1;
          }
        }
LAB_004d9646:
        updateResourceDist = updateResourceDist + 1;
        bestObject = bestObject + 1;
        piVar15 = (int *)bestValue;
      } while (updateResourceDist < this->numResources[param_1]);
    }
    if (bVar4) {
      updateResourceDropsites(this,param_1);
    }
    if (piVar15 != (int *)0x0) {
      *(char *)((int)piVar15 + 6) = *(char *)((int)piVar15 + 6) + '\x01';
      *param_5 = piVar15[4];
      return *piVar15;
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: gameIDsOfObjectType
// Address: 004d96b0
/* WARNING: Variable defined which should be unmapped: maxCount */
/* public: int __thiscall TribeInformationAIModule::gameIDsOfObjectType(int,int * *,int * *,int) */

int __thiscall
TribeInformationAIModule::gameIDsOfObjectType
          (TribeInformationAIModule *this,int param_1,int **param_2,int **param_3,int param_4)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int *piVar5;
  int maxCount;
  int count;
  RGE_Static_Object *tempObj;
  int i;
  int local_4;
  
  *param_2 = (int *)0x0;
  tempObj = (RGE_Static_Object *)0x0;
  *param_3 = (int *)0x0;
  count = 10;
  local_4 = 0;
  if (0 < (this->importantObjects).numberValue) {
    do {
      if ((this->importantObjects).maximumSizeValue + -1 < local_4) {
        piVar1 = (int *)operator_new(local_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->importantObjects).maximumSizeValue) {
            do {
              if (local_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->importantObjects).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->importantObjects).maximumSizeValue);
          }
          operator_delete((this->importantObjects).value);
          (this->importantObjects).value = piVar1;
          (this->importantObjects).maximumSizeValue = local_4 + 1;
        }
      }
      pRVar3 = RGE_Game_World::object
                         ((RGE_Game_World *)this->md->aiPlayer->_padding_,
                          (this->importantObjects).value[local_4]);
      if ((((pRVar3 != (RGE_Static_Object *)0x0) &&
           ((param_4 != -5 ||
            (*(short *)((int)&this->md->aiPlayer->_padding_ + 2) != pRVar3->owner->id)))) &&
          ((param_4 != -6 ||
           (iVar4 = (**(code **)(this->md->aiPlayer->_padding_ + 0x18))((int)pRVar3->owner->id),
           iVar4 == 0)))) &&
         (((param_4 == -1 || (pRVar3->owner->id == param_4)) &&
          ((param_1 == -1 || (param_1 == pRVar3->master_obj->id)))))) {
        if ((tempObj == (RGE_Static_Object *)count) || (*param_2 == (int *)0x0)) {
          piVar1 = (int *)operator_new(count * 8);
          piVar5 = (int *)operator_new(count * 8);
          if ((*param_2 != (int *)0x0) && (0 < count)) {
            iVar4 = 0;
            do {
              iVar2 = iVar4 + 1;
              *(int *)(((int)piVar1 - (int)piVar5) + (int)(piVar5 + iVar4)) = (*param_2)[iVar4];
              piVar5[iVar4] = (*param_3)[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < count);
          }
          count = count * 2;
          if (*param_2 != (int *)0x0) {
            operator_delete(*param_2);
          }
          if (*param_3 != (int *)0x0) {
            operator_delete(*param_3);
          }
          *param_2 = piVar1;
          *param_3 = piVar5;
        }
        if ((this->importantObjects).maximumSizeValue + -1 < local_4) {
          piVar1 = (int *)operator_new(local_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (this->importantObjects).maximumSizeValue) {
              do {
                if (local_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (this->importantObjects).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (this->importantObjects).maximumSizeValue);
            }
            operator_delete((this->importantObjects).value);
            (this->importantObjects).value = piVar1;
            (this->importantObjects).maximumSizeValue = local_4 + 1;
          }
        }
        (*param_2)[(int)tempObj] = (this->importantObjects).value[local_4];
        tempObj = (RGE_Static_Object *)((int)&tempObj->_padding_ + 1);
        (*param_3)[(int)&tempObj[-1].field_0x87] = (int)pRVar3->owner->id;
      }
      local_4 = local_4 + 1;
    } while (local_4 < (this->importantObjects).numberValue);
  }
  return (int)tempObj;
}

// --------------------------------------------------

// Function: gameIDsOwnedBy
// Address: 004d9970
/* WARNING: Variable defined which should be unmapped: count */
/* public: int __thiscall TribeInformationAIModule::gameIDsOwnedBy(int,int * *,int) */

int __thiscall
TribeInformationAIModule::gameIDsOwnedBy
          (TribeInformationAIModule *this,int param_1,int **param_2,int param_3)
{
  int **ppiVar1;
  RGE_Static_Object *pRVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int count;
  int local_8;
  int local_4;
  
  ppiVar1 = param_2;
  *param_2 = (int *)0x0;
  local_8 = 0;
  iVar6 = 10;
  param_2 = (int **)0x0;
  if (0 < this->maxImportantObjectMemory) {
    local_4 = 0;
    do {
      iVar4 = *(int *)((int)&this->importantObjectMemory->id + local_4);
      if (iVar4 != -1) {
        pRVar2 = RGE_Game_World::object((RGE_Game_World *)this->md->aiPlayer->_padding_,iVar4);
        if (((pRVar2 != (RGE_Static_Object *)0x0) && (pRVar2->owner->id == param_3)) &&
           ((param_1 == -1 || (param_1 == (uint)(&this->importantObjectMemory->owner)[local_4])))) {
          if ((local_8 == iVar6) || (*ppiVar1 == (int *)0x0)) {
            piVar3 = (int *)operator_new(iVar6 * 8);
            if ((*ppiVar1 != (int *)0x0) && (iVar4 = 0, 0 < iVar6)) {
              do {
                iVar5 = iVar4 + 1;
                piVar3[iVar4] = (*ppiVar1)[iVar4];
                iVar4 = iVar5;
              } while (iVar5 < iVar6);
            }
            iVar6 = iVar6 * 2;
            if (*ppiVar1 != (int *)0x0) {
              operator_delete(*ppiVar1);
            }
            *ppiVar1 = piVar3;
          }
          (*ppiVar1)[local_8] = *(int *)((int)&this->importantObjectMemory->id + local_4);
          local_8 = local_8 + 1;
        }
      }
      param_2 = (int **)((int)param_2 + 1);
      local_4 = local_4 + 0x24;
    } while ((int)param_2 < this->maxImportantObjectMemory);
  }
  return local_8;
}

// --------------------------------------------------

// Function: numberGameIDsOwnedBy
// Address: 004d9a90
/* WARNING: Variable defined which should be unmapped: count */
/* public: int __thiscall TribeInformationAIModule::numberGameIDsOwnedBy(int,int) */

int __thiscall
TribeInformationAIModule::numberGameIDsOwnedBy
          (TribeInformationAIModule *this,int param_1,int param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  int count;
  int local_4;
  
  iVar4 = 0;
  iVar3 = 0;
  local_4 = 0;
  if (0 < this->maxImportantObjectMemory) {
    do {
      iVar1 = *(int *)((int)&this->importantObjectMemory->id + iVar4);
      if ((((iVar1 != -1) &&
           (pRVar2 = RGE_Game_World::object((RGE_Game_World *)this->md->aiPlayer->_padding_,iVar1),
           pRVar2 != (RGE_Static_Object *)0x0)) && (pRVar2->owner->id == param_2)) &&
         ((param_1 == -1 || (param_1 == (uint)(&this->importantObjectMemory->owner)[iVar4])))) {
        local_4 = local_4 + 1;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x24;
    } while (iVar3 < this->maxImportantObjectMemory);
  }
  return local_4;
}

// --------------------------------------------------

// Function: placeDock
// Address: 004d9b20
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
/* WARNING: Variable defined which should be unmapped: y */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class ConstructionItem * __thiscall TribeInformationAIModule::placeDock(class BuildItem
   *,float,float,int,int) */

ConstructionItem * __thiscall
TribeInformationAIModule::placeDock
          (TribeInformationAIModule *this,BuildItem *param_1,float param_2,float param_3,int param_4
          ,int param_5)
{
  TRIBE_Player *pTVar1;
  RGE_Visible_Map *this_00;
  int iVar2;
  uint uVar3;
  RGE_Visible_Map *pRVar4;
  uchar uVar5;
  byte bVar6;
  RGE_Zone_Map *this_01;
  int iVar7;
  int iVar8;
  ConstructionItem *pCVar9;
  char *pcVar10;
  int iVar11;
  uchar *puVar12;
  undefined4 *unaff_FS_OFFSET;
  float fVar13;
  float fVar14;
  float fVar15;
  int y;
  float cD;
  float local_13c;
  int bXTile;
  RGE_Visible_Map *vMap;
  RGE_Zone_Map *zoneMap;
  float bD;
  int bYTile;
  int randSelect;
  int x;
  uchar currentZone;
  RGE_Map *gMap;
  int tempInt;
  uchar zoneCounter [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005604ee;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = this->md->aiPlayer;
  iVar7 = this->md->_padding_;
  this_00 = (RGE_Visible_Map *)pTVar1->_padding_;
  iVar2 = *(int *)(pTVar1->_padding_ + 0x28);
  puVar12 = zoneCounter;
  for (iVar11 = 0x40; puVar12 = puVar12 + 4, iVar11 != 0; iVar11 = iVar11 + -1) {
    puVar12[0] = 0xff;
    puVar12[1] = 0xff;
    puVar12[2] = 0xff;
    puVar12[3] = 0xff;
  }
  iVar11 = *(int *)(iVar7 + 0x3c);
  vMap = (RGE_Visible_Map *)0xffffffff;
  randSelect = -1;
  bYTile = -0x40800000;
  this_01 = RGE_Zone_Map_List::get_zone_map
                      (*(RGE_Zone_Map_List **)(iVar2 + 0x8dc4),
                       *(float **)
                        (*(int *)(iVar11 + 0x54) +
                        *(short *)(*(int *)(*(int *)(iVar7 + 0x24) + 0x4c) + 0x66) * 4),
                       (int)*(short *)(iVar11 + 0x52),(int *)zoneCounter);
  iVar7 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x6a9);
  _currentZone = (RGE_Visible_Map *)0x1;
  if (1 < this_00->widthValue + -2) {
    do {
      cD = 1.4013e-45;
      if (1 < this_00->heightValue + -2) {
        do {
          uVar5 = RGE_Visible_Map::get_visible(this_00,(int)_currentZone,(int)cD);
          pRVar4 = vMap;
          fVar13 = (float)bYTile;
          fVar14 = (float)randSelect;
          if (((((uVar5 != '\0') && (-1 < (int)((int)&_currentZone[-1].input_csum + 3))) &&
               (-1 < (int)cD + -1)) &&
              (((int)((int)&_currentZone->map_offsets + 1) <= this_00->widthValue + -1 &&
               ((int)cD + 1 <= this_00->heightValue + -1)))) &&
             ((param_4 == -1 ||
              ((*(byte *)(*(int *)(*(int *)(iVar2 + 0x8d8c) + (int)cD * 4) + 5 +
                         (int)_currentZone * 0x18) & 0x1f) == param_4)))) {
            bVar6 = RGE_Zone_Map::get_zone_info(this_01,(long)_currentZone,(long)cD);
            iVar11 = RGE_Zone_Map::numberTilesInZone(this_01,bVar6);
                    /* language.dll match for 0x70: "B" */
            iVar8 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x70);
            if ((iVar8 <= iVar11) &&
               (iVar11 = hasAdjacentTileType(this,(int)_currentZone,(int)cD,param_5), iVar11 != 0))
{
              pCVar9 = ConstructionAIModule::randomLot
                                 ((ConstructionAIModule *)&this->md->constructionAI,
                                  (float)(int)_currentZone - _DAT_00575570,
                                  (float)(int)cD - _DAT_00575570);
              if (pCVar9 == (ConstructionItem *)0x0) {
                uVar3 = (uint)bVar6;
                local_13c = ((float)(int)cD - param_3) * ((float)(int)cD - param_3) +
                            ((float)(int)_currentZone - param_2) *
                            ((float)(int)_currentZone - param_2);
                if (zoneCounter[uVar3 + 4] == 0xff) {
                  iVar11 = numberDocksInZone(this,uVar3,this_01);
                  zoneCounter[uVar3 + 4] = (byte)iVar11;
                }
                bVar6 = zoneCounter[uVar3 + 4];
                if (bVar6 != 0) {
                  local_13c = (float)((uint)bVar6 * 1000) + local_13c;
                }
                iVar11 = closestDockDistance(this,(int)_currentZone,(int)cD);
                if (iVar11 != -1) {
                  local_13c = (float)(int)(100000 / (longlong)iVar11) + local_13c;
                }
                pRVar4 = _currentZone;
                fVar13 = local_13c;
                fVar14 = cD;
                if ((vMap != (RGE_Visible_Map *)0xffffffff) &&
                   (pRVar4 = _currentZone, fVar13 = local_13c, fVar14 = cD,
                   (float)(iVar7 % 0x32) + (float)bYTile <= local_13c)) {
                  pRVar4 = vMap;
                  fVar13 = (float)bYTile;
                  fVar14 = (float)randSelect;
                }
              }
            }
          }
          randSelect = (int)fVar14;
          bYTile = (int)fVar13;
          vMap = pRVar4;
          cD = (float)((int)cD + 1);
        } while ((int)cD < this_00->heightValue + -2);
      }
      _currentZone = (RGE_Visible_Map *)((int)&_currentZone->map_offsets + 1);
    } while ((int)_currentZone < this_00->widthValue + -2);
  }
  if (vMap != (RGE_Visible_Map *)0xffffffff) {
                    /* language.dll match for 0x80: "Arial" */
    pCVar9 = (ConstructionItem *)operator_new(0x80);
    local_4 = 0;
    if (pCVar9 != (ConstructionItem *)0x0) {
      pcVar10 = BaseItem::name((BaseItem *)param_1);
      iVar7 = BaseItem::typeID((BaseItem *)param_1);
      fVar13 = BaseItem::zSize((BaseItem *)param_1);
      fVar14 = BaseItem::ySize((BaseItem *)param_1);
      fVar15 = BaseItem::xSize((BaseItem *)param_1);
      pCVar9 = (ConstructionItem *)
               ConstructionItem::ConstructionItem
                         (pCVar9,(float)(int)vMap - _DAT_00575570,(float)randSelect - _DAT_00575570,
                          0.0,fVar15,fVar14,fVar13,iVar7,pcVar10);
      goto LAB_004d9e9f;
    }
  }
  pCVar9 = (ConstructionItem *)0x0;
LAB_004d9e9f:
  *unaff_FS_OFFSET = local_c;
  return pCVar9;
}

// --------------------------------------------------

// Function: numberDocksInZone
// Address: 004d9ec0
/* WARNING: Variable defined which should be unmapped: count */
/* public: int __thiscall TribeInformationAIModule::numberDocksInZone(int,class RGE_Zone_Map *) */

int __thiscall
TribeInformationAIModule::numberDocksInZone
          (TribeInformationAIModule *this,int param_1,RGE_Zone_Map *param_2)
{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  int count;
  uchar dockZone;
  
  iVar8 = 0;
  _dockZone = 0;
  if (0 < (this->playerBuildings).numberValue) {
    do {
      if ((this->playerBuildings).maximumSizeValue + -1 < iVar8) {
        piVar2 = (int *)operator_new(iVar8 * 4 + 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->playerBuildings).maximumSizeValue) {
            do {
              if (iVar8 + 1 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->playerBuildings).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->playerBuildings).maximumSizeValue);
          }
          operator_delete((this->playerBuildings).value);
          (this->playerBuildings).value = piVar2;
          (this->playerBuildings).maximumSizeValue = iVar8 + 1;
        }
      }
      pRVar5 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)this->md,(this->playerBuildings).value[iVar8]);
      if ((pRVar5 != (RGE_Static_Object *)0x0) && (pRVar5->master_obj->id == 0x2d)) {
        lVar6 = __ftol();
        lVar7 = __ftol();
        bVar1 = RGE_Zone_Map::get_zone_info(param_2,lVar7,lVar6);
        if ((uint)bVar1 == param_1) {
          _dockZone = _dockZone + 1;
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < (this->playerBuildings).numberValue);
  }
  return _dockZone;
}

// --------------------------------------------------

// Function: closestDockDistance
// Address: 004d9fc0
/* WARNING: Variable defined which should be unmapped: distance */
/* public: int __thiscall TribeInformationAIModule::closestDockDistance(int,int) */

int __thiscall
TribeInformationAIModule::closestDockDistance
          (TribeInformationAIModule *this,int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  int distance;
  int local_8;
  
  iVar5 = 0;
  local_8 = -1;
  if (0 < (this->playerBuildings).numberValue) {
    do {
      if ((this->playerBuildings).maximumSizeValue + -1 < iVar5) {
        piVar1 = (int *)operator_new(iVar5 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->playerBuildings).maximumSizeValue) {
            do {
              if (iVar5 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->playerBuildings).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->playerBuildings).maximumSizeValue);
          }
          operator_delete((this->playerBuildings).value);
          (this->playerBuildings).value = piVar1;
          (this->playerBuildings).maximumSizeValue = iVar5 + 1;
        }
      }
      pRVar3 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)this->md,(this->playerBuildings).value[iVar5]);
      if ((pRVar3 != (RGE_Static_Object *)0x0) && (pRVar3->master_obj->id == 0x2d)) {
        __ftol();
        __ftol();
        iVar4 = __ftol();
        if ((iVar4 != 0) && ((local_8 == -1 || (iVar4 < local_8)))) {
          local_8 = iVar4;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (this->playerBuildings).numberValue);
  }
  return local_8;
}

// --------------------------------------------------

// Function: hasAdjacentTileType
// Address: 004da0e0
/* public: int __thiscall TribeInformationAIModule::hasAdjacentTileType(int,int,int) */

int __thiscall
TribeInformationAIModule::hasAdjacentTileType
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = *(int *)(this->md->aiPlayer->_padding_ + 0x28);
  iVar2 = param_1;
  iVar3 = param_2;
  do {
    switch(iVar4) {
    case 0:
      iVar2 = param_1 + -1;
      iVar3 = param_2;
    case 7:
      iVar3 = iVar3 + -1;
      break;
    case 1:
    case 2:
      iVar2 = iVar2 + 1;
      break;
    case 3:
    case 4:
      iVar3 = iVar3 + 1;
      break;
    case 5:
    case 6:
      iVar2 = iVar2 + -1;
    }
    if ((((-1 < iVar2) && (-1 < iVar3)) && (iVar2 <= *(int *)(iVar1 + 8) + -1)) &&
       ((iVar3 <= *(int *)(iVar1 + 0xc) + -1 &&
        ((*(byte *)(*(int *)(*(int *)(iVar1 + 0x8d8c) + iVar3 * 4) + 5 + iVar2 * 0x18) & 0x1f) ==
         param_3)))) {
      return 1;
    }
    iVar4 = iVar4 + 1;
    if (7 < iVar4) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: mapXSize
// Address: 004da190
/* public: int __thiscall TribeInformationAIModule::mapXSize(void) */

int __thiscall TribeInformationAIModule::mapXSize(TribeInformationAIModule *this)
{
  if (this->mapXSizeValue == -1) {
    this->mapXSizeValue = *(int *)(*(int *)(this->md->aiPlayer->_padding_ + 0x28) + 8);
  }
  return this->mapXSizeValue;
}

// --------------------------------------------------

// Function: mapYSize
// Address: 004da1c0
/* public: int __thiscall TribeInformationAIModule::mapYSize(void) */

int __thiscall TribeInformationAIModule::mapYSize(TribeInformationAIModule *this)
{
  if (this->mapYSizeValue == -1) {
    this->mapYSizeValue = *(int *)(*(int *)(this->md->aiPlayer->_padding_ + 0x28) + 0xc);
  }
  return this->mapYSizeValue;
}

// --------------------------------------------------

// Function: addEnemyInfluences
// Address: 004da1f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TribeInformationAIModule::addEnemyInfluences(int,int) */

void __thiscall
TribeInformationAIModule::addEnemyInfluences(TribeInformationAIModule *this,int param_1,int param_2)
{
  byte bVar1;
  int *piVar2;
  RGE_Static_Object *pRVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int i;
  XYPoint maxLOS;
  XYPoint maxRange;
  XYPoint minLOS;
  XYPoint minRange;
  
  maxLOS.x = 0;
  if (0 < this->maxImportantObjectMemory) {
    i = 0;
    do {
      piVar2 = (int *)((int)&this->importantObjectMemory->id + i);
      if ((((uint)*(byte *)((int)piVar2 + 0xb) == param_1) && (iVar5 = *piVar2, iVar5 != param_2))
         && (pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar5),
            pRVar3 != (RGE_Static_Object *)0x0)) {
        minLOS.y = __ftol();
        minRange.x = __ftol();
        mapBound(this,(XYPoint *)&minLOS.y);
        maxLOS.y = __ftol();
        maxRange.x = __ftol();
        mapBound(this,(XYPoint *)&maxLOS.y);
        iVar5 = maxRange.x;
        iVar6 = minRange.x;
        iVar8 = minLOS.y;
        if (minLOS.y <= maxLOS.y) {
          do {
            iVar7 = iVar6;
            if (iVar6 <= iVar5) {
              do {
                bVar1 = PathingSystem::lookupMisc(&aiPathSystem,iVar8,iVar6);
                uVar4 = bVar1 + 10;
                if (0xff < uVar4) {
                  uVar4 = 0xff;
                }
                PathingSystem::setMisc(&aiPathSystem,iVar8,iVar6,(uchar)uVar4);
                iVar6 = iVar6 + 1;
                iVar5 = maxRange.x;
                iVar7 = minRange.x;
              } while (iVar6 <= maxRange.x);
            }
            iVar8 = iVar8 + 1;
            iVar6 = iVar7;
          } while (iVar8 <= maxLOS.y);
        }
        if (_DAT_00575564 < *(float *)((int)&this->importantObjectMemory->range + i)) {
          minRange.y = __ftol();
          iVar8 = __ftol();
          mapBound(this,(XYPoint *)&minRange.y);
          maxRange.y = __ftol();
          minLOS.x = __ftol();
          mapBound(this,(XYPoint *)&maxRange.y);
          iVar5 = minLOS.x;
          iVar6 = minRange.y;
          if (minRange.y <= maxRange.y) {
            do {
              iVar7 = iVar8;
              if (iVar8 <= iVar5) {
                do {
                  bVar1 = PathingSystem::lookupMisc(&aiPathSystem,iVar6,iVar7);
                  uVar4 = bVar1 + 10;
                  if (0xff < uVar4) {
                    uVar4 = 0xff;
                  }
                  PathingSystem::setMisc(&aiPathSystem,iVar6,iVar7,(uchar)uVar4);
                  iVar7 = iVar7 + 1;
                  iVar5 = minLOS.x;
                } while (iVar7 <= minLOS.x);
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 <= maxRange.y);
          }
        }
      }
      maxLOS.x = maxLOS.x + 1;
      i = i + 0x24;
    } while (maxLOS.x < this->maxImportantObjectMemory);
  }
  return;
}

// --------------------------------------------------

// Function: addPriorAttackInfluences
// Address: 004da420
/* WARNING: Variable defined which should be unmapped: i */
/* public: void __thiscall TribeInformationAIModule::addPriorAttackInfluences(int,int) */

void __thiscall
TribeInformationAIModule::addPriorAttackInfluences
          (TribeInformationAIModule *this,int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int i;
  XYPoint max;
  XYPoint min;
  
  iVar4 = 0;
  max.x = 0;
  if (0 < this->maxAttackMemories) {
    do {
      piVar1 = (int *)((int)&this->attackMemories->id + iVar4);
      if (((*piVar1 != -1) && ((uint)*(byte *)((int)piVar1 + 10) == param_1)) &&
         ((ushort)*(byte *)((int)piVar1 + 9) == *(ushort *)(this->md->_padding_ + 0x4a))) {
        min.y = (int)*(byte *)((int)piVar1 + 5);
        uVar3 = (uint)*(byte *)((int)piVar1 + 6);
        mapBound(this,(XYPoint *)&min.y);
        max.y = (int)(&this->attackMemories->maxX)[iVar4];
        min.x = (int)(&this->attackMemories->maxY)[iVar4];
        mapBound(this,(XYPoint *)&max.y);
        iVar2 = min.x;
        iVar7 = min.y;
        if (min.y <= max.y) {
          do {
            uVar5 = uVar3;
            if ((int)uVar3 <= iVar2) {
              do {
                PathingSystem::setMisc(&aiPathSystem,iVar7,uVar5,'K');
                uVar5 = uVar5 + 1;
                iVar2 = min.x;
              } while ((int)uVar5 <= min.x);
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 <= max.y);
        }
        min.y = min.y + -5;
        mapBound(this,(XYPoint *)&min.y);
        max.y = max.y + 5;
        min.x = min.x + 5;
        mapBound(this,(XYPoint *)&max.y);
        iVar2 = min.x;
        iVar7 = min.y;
        if (min.y <= max.y) {
          do {
            iVar6 = uVar3 - 5;
            if ((int)(uVar3 - 5) <= iVar2) {
              do {
                PathingSystem::setMisc(&aiPathSystem,iVar7,iVar6,'\x0f');
                iVar6 = iVar6 + 1;
                iVar2 = min.x;
              } while (iVar6 <= min.x);
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 <= max.y);
        }
      }
      max.x = max.x + 1;
      iVar4 = iVar4 + 0x18;
    } while (max.x < this->maxAttackMemories);
  }
  return;
}

// --------------------------------------------------

// Function: objectMemory
// Address: 004da5a0
/* public: struct ObjectMemory * __thiscall TribeInformationAIModule::objectMemory(int) */

ObjectMemory * __thiscall
TribeInformationAIModule::objectMemory(TribeInformationAIModule *this,int param_1)
{
  int iVar1;
  ObjectMemory *pOVar2;
  
  if (param_1 != -1) {
    iVar1 = 0;
    if (0 < this->maxImportantObjectMemory) {
      pOVar2 = this->importantObjectMemory;
      do {
        if (pOVar2->id == param_1) {
          return this->importantObjectMemory + iVar1;
        }
        iVar1 = iVar1 + 1;
        pOVar2 = pOVar2 + 1;
      } while (iVar1 < this->maxImportantObjectMemory);
      return (ObjectMemory *)0x0;
    }
  }
  return (ObjectMemory *)0x0;
}

// --------------------------------------------------

// Function: addObjectMemory
// Address: 004da5f0
/* public: struct ObjectMemory * __thiscall TribeInformationAIModule::addObjectMemory(class
   RGE_Static_Object *) */

ObjectMemory * __thiscall
TribeInformationAIModule::addObjectMemory(TribeInformationAIModule *this,RGE_Static_Object *param_1)
{
  RGE_Master_Static_Object *pRVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  short sVar5;
  ObjectMemory *pOVar6;
  float10 fVar7;
  uchar uVar8;
  int iVar9;
  uchar uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  RGE_Static_Object *pRVar14;
  
  if (param_1 == (RGE_Static_Object *)0x0) {
    return (ObjectMemory *)0x0;
  }
  iVar9 = param_1->_padding_;
  pRVar1 = param_1->master_obj;
  pRVar14 = param_1;
  fVar7 = (float10)(**(code **)(iVar9 + 0x10c))();
  fVar13 = (float)fVar7;
  fVar7 = (float10)(**(code **)(iVar9 + 0x100))();
  fVar12 = (float)fVar7;
  fVar7 = (float10)(**(code **)(iVar9 + 0x108))();
  fVar11 = (float)fVar7;
  uVar10 = '\0';
  iVar9 = 0;
  sVar5 = __ftol();
  uVar8 = (uchar)param_1->owner->id;
  uVar2 = __ftol();
  uVar3 = __ftol();
  uVar4 = __ftol();
  pOVar6 = addObjectMemory(this,param_1->id,pRVar1->id,pRVar1->object_group,uVar4,uVar3,uVar2,uVar8,
                           sVar5,iVar9,uVar10,fVar11,fVar12,fVar13,pRVar14);
  return pOVar6;
}

// --------------------------------------------------

// Function: addObjectMemory
// Address: 004da680
/* public: struct ObjectMemory * __thiscall
   TribeInformationAIModule::addObjectMemory(int,short,short,unsigned char,unsigned char,unsigned
   char,unsigned char,short,int,unsigned char,float,float,float,class RGE_Static_Object *) */

ObjectMemory * __thiscall
TribeInformationAIModule::addObjectMemory
          (TribeInformationAIModule *this,int param_1,short param_2,short param_3,uchar param_4,
          uchar param_5,uchar param_6,uchar param_7,short param_8,int param_9,uchar param_10,
          float param_11,float param_12,float param_13,RGE_Static_Object *param_14)
{
  int iVar1;
  ObjectMemory *pOVar2;
  short *psVar3;
  ushort uVar4;
  int iVar5;
  
  iVar5 = -1;
  iVar1 = 0;
  if (0 < this->maxImportantObjectMemory) {
    pOVar2 = this->importantObjectMemory;
    do {
      if (pOVar2->id == param_1) {
        this->importantObjectMemory[iVar1].id = param_1;
        this->importantObjectMemory[iVar1].type = param_2;
        this->importantObjectMemory[iVar1].group = param_3;
        this->importantObjectMemory[iVar1].x = param_4;
        this->importantObjectMemory[iVar1].y = param_5;
        this->importantObjectMemory[iVar1].z = param_6;
        this->importantObjectMemory[iVar1].owner = param_7;
        this->importantObjectMemory[iVar1].hitPoints = param_8;
        this->importantObjectMemory[iVar1].attackAttempts = param_9;
        this->importantObjectMemory[iVar1].kills = param_10;
        this->importantObjectMemory[iVar1].damageCapability = param_11;
        this->importantObjectMemory[iVar1].rateOfFire = param_12;
        this->importantObjectMemory[iVar1].range = param_13;
        return this->importantObjectMemory + iVar1;
      }
      if ((pOVar2->id == -1) && (iVar5 == -1)) {
        iVar5 = iVar1;
      }
      iVar1 = iVar1 + 1;
      pOVar2 = pOVar2 + 1;
    } while (iVar1 < this->maxImportantObjectMemory);
  }
  if (param_14 != (RGE_Static_Object *)0x0) {
    uVar4 = (ushort)*(byte *)(*(int *)(this->md->_padding_ + 0x3c) + 0x11d);
    iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xc9);
    if ((iVar1 == 1) && ((uVar4 == *(ushort *)(this->md->_padding_ + 0x4a) || (uVar4 == 0xff)))) {
      if (0 < param_14->owner->id) {
        iVar1 = RGE_Player::computerPlayer(param_14->owner);
        if (iVar1 == 0) {
          iVar1 = RGE_Base_Game::singlePlayerGame(rge_base_game);
          if (iVar1 == 1) {
            iVar1 = convertUnitToIntType(this,param_14);
            if (iVar1 != -1) {
              this->unitHistory[iVar1] = this->unitHistory[iVar1] + 1;
            }
          }
        }
      }
    }
  }
  if (iVar5 == -1) {
    pOVar2 = (ObjectMemory *)operator_new(this->maxImportantObjectMemory * 0x48);
    if (pOVar2 == (ObjectMemory *)0x0) {
      return (ObjectMemory *)0x0;
    }
    iVar5 = 0;
    if (0 < this->maxImportantObjectMemory) {
      iVar1 = 0;
      psVar3 = &pOVar2->group;
      do {
        iVar5 = iVar5 + 1;
        ((ObjectMemory *)(psVar3 + -3))->id =
             *(int *)((int)&this->importantObjectMemory->id + iVar1);
        psVar3[-1] = *(short *)((int)&this->importantObjectMemory->type + iVar1);
        *psVar3 = *(short *)((int)&this->importantObjectMemory->group + iVar1);
        *(uchar *)(psVar3 + 1) = (&this->importantObjectMemory->x)[iVar1];
        *(uchar *)((int)psVar3 + 3) = (&this->importantObjectMemory->y)[iVar1];
        *(uchar *)(psVar3 + 2) = (&this->importantObjectMemory->z)[iVar1];
        *(uchar *)((int)psVar3 + 5) = (&this->importantObjectMemory->owner)[iVar1];
        psVar3[3] = *(short *)((int)&this->importantObjectMemory->hitPoints + iVar1);
        *(int *)(psVar3 + 5) = *(int *)((int)&this->importantObjectMemory->attackAttempts + iVar1);
        *(uchar *)(psVar3 + 7) = (&this->importantObjectMemory->kills)[iVar1];
        *(float *)(psVar3 + 9) =
             *(float *)((int)&this->importantObjectMemory->damageCapability + iVar1);
        *(float *)(psVar3 + 0xb) = *(float *)((int)&this->importantObjectMemory->rateOfFire + iVar1)
        ;
        *(float *)(psVar3 + 0xd) = *(float *)((int)&this->importantObjectMemory->range + iVar1);
        iVar1 = iVar1 + 0x24;
        psVar3 = psVar3 + 0x12;
      } while (iVar5 < this->maxImportantObjectMemory);
    }
    if (iVar5 < this->maxImportantObjectMemory * 2) {
      psVar3 = &pOVar2[iVar5].group;
      do {
        iVar5 = iVar5 + 1;
        ((ObjectMemory *)(psVar3 + -3))->id = -1;
        psVar3[-1] = -1;
        *psVar3 = -1;
        *(uchar *)(psVar3 + 1) = '\0';
        *(uchar *)((int)psVar3 + 3) = '\0';
        *(uchar *)(psVar3 + 2) = '\0';
        *(uchar *)((int)psVar3 + 5) = '\0';
        psVar3[3] = 0;
        *(int *)(psVar3 + 5) = 0;
        *(uchar *)(psVar3 + 7) = '\0';
        *(float *)(psVar3 + 9) = 0.0;
        *(float *)(psVar3 + 0xb) = 0.0;
        *(float *)(psVar3 + 0xd) = 0.0;
        psVar3 = psVar3 + 0x12;
      } while (iVar5 < this->maxImportantObjectMemory * 2);
    }
    operator_delete(this->importantObjectMemory);
    this->importantObjectMemory = pOVar2;
    pOVar2[this->maxImportantObjectMemory].id = param_1;
    this->importantObjectMemory[this->maxImportantObjectMemory].type = param_2;
    this->importantObjectMemory[this->maxImportantObjectMemory].group = param_3;
    this->importantObjectMemory[this->maxImportantObjectMemory].x = param_4;
    this->importantObjectMemory[this->maxImportantObjectMemory].y = param_5;
    this->importantObjectMemory[this->maxImportantObjectMemory].z = param_6;
    this->importantObjectMemory[this->maxImportantObjectMemory].owner = param_7;
    this->importantObjectMemory[this->maxImportantObjectMemory].hitPoints = param_8;
    this->importantObjectMemory[this->maxImportantObjectMemory].attackAttempts = param_9;
    this->importantObjectMemory[this->maxImportantObjectMemory].kills = param_10;
    this->importantObjectMemory[this->maxImportantObjectMemory].damageCapability = param_11;
    this->importantObjectMemory[this->maxImportantObjectMemory].rateOfFire = param_12;
    this->importantObjectMemory[this->maxImportantObjectMemory].range = param_13;
    iVar5 = this->maxImportantObjectMemory;
    this->maxImportantObjectMemory = iVar5 * 2;
    return this->importantObjectMemory + iVar5;
  }
  this->importantObjectMemory[iVar5].id = param_1;
  this->importantObjectMemory[iVar5].type = param_2;
  this->importantObjectMemory[iVar5].group = param_3;
  this->importantObjectMemory[iVar5].x = param_4;
  this->importantObjectMemory[iVar5].y = param_5;
  this->importantObjectMemory[iVar5].z = param_6;
  this->importantObjectMemory[iVar5].owner = param_7;
  this->importantObjectMemory[iVar5].hitPoints = param_8;
  this->importantObjectMemory[iVar5].attackAttempts = param_9;
  this->importantObjectMemory[iVar5].kills = param_10;
  this->importantObjectMemory[iVar5].damageCapability = param_11;
  this->importantObjectMemory[iVar5].rateOfFire = param_12;
  this->importantObjectMemory[iVar5].range = param_13;
  return this->importantObjectMemory + iVar5;
}

// --------------------------------------------------

// Function: addImportantObject
// Address: 004dabb0
/* WARNING: Variable defined which should be unmapped: oType */
/* public: int __thiscall TribeInformationAIModule::addImportantObject(class RGE_Static_Object
   *,int) */

int __thiscall
TribeInformationAIModule::addImportantObject
          (TribeInformationAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  RGE_Player *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int oType;
  
  if ((param_1 != (RGE_Static_Object *)0x0) && (-1 < param_1->id)) {
    iVar1 = (int)param_1->master_obj->object_group;
    iVar2 = importantObject(this,iVar1);
    if (iVar2 != 0) {
      iVar3 = (int)param_1->owner->id;
      piVar5 = (int *)this->md->_padding_;
      iVar2 = piVar5[0xf];
      if ((((param_2 == 0) && (0 < iVar3)) &&
          (iVar3 = (**(code **)(*piVar5 + 0x18))(iVar3), iVar3 != 0)) &&
         (3 < *(short *)(iVar2 + 0x3c))) {
        iVar3 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xc2);
        iVar7 = 1;
        if ((iVar3 == 1) && (1 < *(short *)(iVar2 + 0x3c))) {
          do {
            if (iVar7 != *(short *)(this->md->_padding_ + 0x4a)) {
              this_00 = *(RGE_Player **)(*(int *)(iVar2 + 0x40) + iVar7 * 4);
              iVar3 = RGE_Player::computerPlayer(this_00);
              if (((iVar3 != 0) &&
                  (iVar3 = (**(code **)(*(int *)this->md->_padding_ + 0x1c))(iVar7), iVar3 != 0)) &&
                 (iVar3 = (**(code **)(this_00->_padding_ + 0x1c))
                                    ((int)*(short *)(this->md->_padding_ + 0x4a)), iVar3 != 0)) {
                addImportantObject((TribeInformationAIModule *)
                                   (this_00[1].position_checksum + 0xcec),param_1,1);
              }
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(short *)(iVar2 + 0x3c));
        }
      }
      iVar7 = checkDefend(this,param_1);
      iVar2 = (this->importantObjects).numberValue;
      iVar3 = param_1->id;
      iVar4 = 0;
      if (0 < iVar2) {
        do {
          if ((this->importantObjects).maximumSizeValue <= iVar4) break;
          if ((this->importantObjects).value[iVar4] == iVar3) goto LAB_004dad90;
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar2);
      }
      if ((this->importantObjects).maximumSizeValue + -1 < iVar2) {
        iVar2 = iVar2 + 1;
        piVar5 = (int *)operator_new(iVar2 * 4);
        if (piVar5 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->importantObjects).maximumSizeValue) {
            do {
              if (iVar2 <= iVar4) break;
              iVar6 = iVar4 + 1;
              piVar5[iVar4] = (this->importantObjects).value[iVar4];
              iVar4 = iVar6;
            } while (iVar6 < (this->importantObjects).maximumSizeValue);
          }
          operator_delete((this->importantObjects).value);
          (this->importantObjects).value = piVar5;
          (this->importantObjects).maximumSizeValue = iVar2;
        }
      }
      (this->importantObjects).value[(this->importantObjects).numberValue] = iVar3;
      (this->importantObjects).numberValue = (this->importantObjects).numberValue + 1;
LAB_004dad90:
      iVar2 = importantUnit(this,iVar1);
      if (iVar2 == 1) {
        iVar2 = (this->importantUnits).numberValue;
        iVar3 = param_1->id;
        iVar4 = 0;
        if (0 < iVar2) {
          do {
            if ((this->importantUnits).maximumSizeValue <= iVar4) break;
            if ((this->importantUnits).value[iVar4] == iVar3) goto LAB_004daf3b;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar2);
        }
        if ((this->importantUnits).maximumSizeValue + -1 < iVar2) {
          iVar2 = iVar2 + 1;
          piVar5 = (int *)operator_new(iVar2 * 4);
          if (piVar5 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (this->importantUnits).maximumSizeValue) {
              do {
                if (iVar2 <= iVar4) break;
                iVar6 = iVar4 + 1;
                piVar5[iVar4] = (this->importantUnits).value[iVar4];
                iVar4 = iVar6;
              } while (iVar6 < (this->importantUnits).maximumSizeValue);
            }
            operator_delete((this->importantUnits).value);
            (this->importantUnits).value = piVar5;
            (this->importantUnits).maximumSizeValue = iVar2;
          }
        }
        (this->importantUnits).value[(this->importantUnits).numberValue] = iVar3;
        (this->importantUnits).numberValue = (this->importantUnits).numberValue + 1;
      }
      else {
        iVar2 = importantResource(this,iVar1);
        if (iVar2 == 1) {
          addResourceObject(this,param_1);
        }
        else {
          iVar2 = importantMisc(this,iVar1);
          if (iVar2 == 1) {
            iVar2 = (this->importantMiscs).numberValue;
            iVar3 = param_1->id;
            iVar4 = 0;
            if (0 < iVar2) {
              do {
                if ((this->importantMiscs).maximumSizeValue <= iVar4) break;
                if ((this->importantMiscs).value[iVar4] == iVar3) goto LAB_004daf3b;
                iVar4 = iVar4 + 1;
              } while (iVar4 < iVar2);
            }
            if ((this->importantMiscs).maximumSizeValue + -1 < iVar2) {
              iVar2 = iVar2 + 1;
              piVar5 = (int *)operator_new(iVar2 * 4);
              if (piVar5 != (int *)0x0) {
                iVar4 = 0;
                if (0 < (this->importantMiscs).maximumSizeValue) {
                  do {
                    if (iVar2 <= iVar4) break;
                    iVar6 = iVar4 + 1;
                    piVar5[iVar4] = (this->importantMiscs).value[iVar4];
                    iVar4 = iVar6;
                  } while (iVar6 < (this->importantMiscs).maximumSizeValue);
                }
                operator_delete((this->importantMiscs).value);
                (this->importantMiscs).value = piVar5;
                (this->importantMiscs).maximumSizeValue = iVar2;
              }
            }
            (this->importantMiscs).value[(this->importantMiscs).numberValue] = iVar3;
            (this->importantMiscs).numberValue = (this->importantMiscs).numberValue + 1;
          }
        }
      }
LAB_004daf3b:
      iVar1 = importantUnit(this,iVar1);
      if ((iVar1 == 1) || (iVar7 == 1)) {
        addObjectMemory(this,param_1);
      }
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: addImportantObject
// Address: 004daf80
/* public: int __thiscall TribeInformationAIModule::addImportantObject(int) */

int __thiscall
TribeInformationAIModule::addImportantObject(TribeInformationAIModule *this,int param_1)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  
  pRVar1 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  iVar2 = addImportantObject(this,pRVar1,0);
  return iVar2;
}

// --------------------------------------------------

// Function: importantObject
// Address: 004dafb0
/* public: int __thiscall TribeInformationAIModule::importantObject(int) */

int __thiscall TribeInformationAIModule::importantObject(TribeInformationAIModule *this,int param_1)
{
  int iVar1;
  
  iVar1 = importantUnit(this,param_1);
  if (iVar1 == 0) {
    iVar1 = importantResource(this,param_1);
    if (iVar1 == 0) {
      iVar1 = importantMisc(this,param_1);
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: importantUnit
// Address: 004daff0
/* public: int __thiscall TribeInformationAIModule::importantUnit(int) */

int __thiscall TribeInformationAIModule::importantUnit(TribeInformationAIModule *this,int param_1)
{
  if (((((((param_1 != 0) && (param_1 != 3)) && (param_1 != 4)) &&
        (((param_1 != 0x18 && (param_1 != 0x15)) &&
         ((param_1 != 6 && ((param_1 != 0x19 && (param_1 != 0x11)))))))) &&
       ((param_1 != 0x1a && (((param_1 != 0xc && (param_1 != 0x23)) && (param_1 != 0x17)))))) &&
      (((param_1 != 0x24 && (param_1 != 0x1c)) &&
       (((param_1 != 0x12 && ((param_1 != 0xd && (param_1 != 2)))) && (param_1 != 0x14)))))) &&
     (((param_1 != 0x1b && (param_1 != 0x16)) && (param_1 != 0x27)))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: importantResource
// Address: 004db070
/* public: int __thiscall TribeInformationAIModule::importantResource(int) */

int __thiscall
TribeInformationAIModule::importantResource(TribeInformationAIModule *this,int param_1)
{
  if (((((param_1 != 0x1f) && (param_1 != 5)) && (param_1 != 0x21)) &&
      ((param_1 != 7 && (param_1 != 9)))) &&
     ((param_1 != 8 && ((param_1 != 0x20 && (param_1 != 0xf)))))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: importantMisc
// Address: 004db0b0
/* public: int __thiscall TribeInformationAIModule::importantMisc(int) */

int __thiscall TribeInformationAIModule::importantMisc(TribeInformationAIModule *this,int param_1)
{
  if ((param_1 != 1) && (param_1 != 0x1e)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: isBuilding
// Address: 004db0d0
/* public: int __thiscall TribeInformationAIModule::isBuilding(class RGE_Static_Object *) */

int __thiscall
TribeInformationAIModule::isBuilding(TribeInformationAIModule *this,RGE_Static_Object *param_1)
{
  short sVar1;
  
  sVar1 = param_1->master_obj->object_group;
  if ((sVar1 != 3) && (sVar1 != 0x1b)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: isUnitBuilding
// Address: 004db100
/* public: int __thiscall TribeInformationAIModule::isUnitBuilding(class RGE_Static_Object *) */

int __thiscall
TribeInformationAIModule::isUnitBuilding(TribeInformationAIModule *this,RGE_Static_Object *param_1)
{
  short sVar1;
  
  if (param_1->master_obj->object_group != 3) {
    return 0;
  }
  sVar1 = param_1->master_obj->id;
  if (((((sVar1 != 0x6d) && (sVar1 != 0xc)) && (sVar1 != 0x57)) &&
      ((sVar1 != 0x31 && (sVar1 != 0x2d)))) &&
     ((sVar1 != 0 && ((sVar1 != 0x65 && (sVar1 != 0x68)))))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: isBoat
// Address: 004db160
/* public: int __thiscall TribeInformationAIModule::isBoat(class RGE_Static_Object *) */

int __thiscall
TribeInformationAIModule::isBoat(TribeInformationAIModule *this,RGE_Static_Object *param_1)
{
  short sVar1;
  
  sVar1 = param_1->master_obj->object_group;
  if ((((sVar1 != 0x15) && (sVar1 != 2)) && (sVar1 != 0x14)) && (sVar1 != 0x16)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: isWall
// Address: 004db190
/* public: int __thiscall TribeInformationAIModule::isWall(class RGE_Static_Object *) */

int __thiscall
TribeInformationAIModule::isWall(TribeInformationAIModule *this,RGE_Static_Object *param_1)
{
  return (uint)(param_1->master_obj->object_group == 0x1b);
}

// --------------------------------------------------

// Function: isTower
// Address: 004db1b0
/* public: int __thiscall TribeInformationAIModule::isTower(class RGE_Static_Object *) */

int __thiscall
TribeInformationAIModule::isTower(TribeInformationAIModule *this,RGE_Static_Object *param_1)
{
  short sVar1;
  
  sVar1 = param_1->master_obj->id;
  if ((((sVar1 != 0x4f) && (sVar1 != 199)) && (sVar1 != 0x45)) &&
     ((sVar1 != 0x17f && (sVar1 != 0x17c)))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: isBoatAccessible
// Address: 004db1f0
/* public: int __thiscall TribeInformationAIModule::isBoatAccessible(class RGE_Static_Object *,int)
    */

int __thiscall
TribeInformationAIModule::isBoatAccessible
          (TribeInformationAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  short sVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_2);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  sVar1 = pRVar2->master_obj->object_group;
  if ((((sVar1 != 0x15) && (sVar1 != 2)) && (sVar1 != 0x14)) &&
     ((sVar1 != 0x16 && (pRVar2->master_obj->id != 0x2d)))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: isLandAccessible
// Address: 004db240
/* public: int __thiscall TribeInformationAIModule::isLandAccessible(class RGE_Static_Object *,int)
    */

int __thiscall
TribeInformationAIModule::isLandAccessible
          (TribeInformationAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  short sVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_2);
  if ((((pRVar2 != (RGE_Static_Object *)0x0) &&
       (sVar1 = pRVar2->master_obj->object_group, sVar1 != 0x15)) && (sVar1 != 2)) &&
     ((sVar1 != 0x14 && (sVar1 != 0x16)))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: influenceCanPlaceStructure
// Address: 004db280
/* public: int __thiscall TribeInformationAIModule::influenceCanPlaceStructure(class BuildItem *) */

int __thiscall
TribeInformationAIModule::influenceCanPlaceStructure
          (TribeInformationAIModule *this,BuildItem *param_1)
{
  return 1;
}

// --------------------------------------------------

// Function: influencePlaceStructure
// Address: 004db290
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
// [HELPER] s_Invalid_influence_placement_type: "Invalid influence placement type id (%d), bombing."
// [HELPER] s_____Unsupported_building_size___: "    Unsupported building size (%d x %d)."
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class ConstructionItem * __thiscall
   TribeInformationAIModule::influencePlaceStructure(class BuildItem *,int,int,float,char
   *,int,int,int,int,struct PlacementState &,unsigned long) */

ConstructionItem * __thiscall
TribeInformationAIModule::influencePlaceStructure
          (TribeInformationAIModule *this,BuildItem *param_1,int param_2,int param_3,float param_4,
          char *param_5,int param_6,int param_7,int param_8,int param_9,PlacementState *param_10,
          ulong param_11)
{
  XYPoint *pXVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  RGE_Static_Object *this_00;
  int iVar6;
  RGE_Static_Object *this_01;
  int iVar7;
  int iVar8;
  BuildingLot *pBVar9;
  int iVar10;
  int iVar11;
  ulong uVar12;
  int iVar13;
  uint uVar14;
  ConstructionItem *pCVar15;
  AIModule *this_02;
  TribeMainDecisionAIModule *pTVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar23;
  float buildingSize;
  int buildingType;
  int x;
  int randSelect;
  int placementType;
  XYPoint bestPoint;
  int basePlacementTotal;
  int y;
  int maximumDistance;
  XYPoint centerPoint;
  XYPoint maxClear;
  XYPoint minClear;
  int bestPointValue;
  int minimumDistance;
  int local_154;
  XYPoint max;
  ulong availableTime;
  int firstTimeThrough;
  int useExcludeRegion;
  XYPoint min;
  XYPoint maxExclude;
  XYPoint minExclude;
  int blockingObject;
  undefined4 local_120;
  XYPoint newPosition;
  TRIBE_Master_Building_Object *masterObj;
  char buildingName [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560538;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = MainDecisionAIModule::object
                      ((MainDecisionAIModule *)this->md,-1,-1,4,-1,-1,-1,-1,-1,-1,-1);
  if (this_00 == (RGE_Static_Object *)0x0) {
    param_10->active = 0;
  }
  else {
    if (param_10->active == 1) {
      x = param_10->buildingTypeID;
      buildingType = (int)param_10->buildingSize;
      param_5 = param_10->buildingName;
      uVar23 = 0xff;
    }
    else if (param_1 == (BuildItem *)0x0) {
      uVar23 = 0xff;
      x = param_3;
      buildingType = (int)param_4;
    }
    else {
      x = BaseItem::typeID((BaseItem *)param_1);
      buildingType = (int)BaseItem::xSize((BaseItem *)param_1);
      uVar23 = 0xff;
      param_5 = BaseItem::name((BaseItem *)param_1);
    }
    strncpy(buildingName + 4,param_5,uVar23);
    newPosition.x = __ftol();
    iVar6 = newPosition.x * newPosition.x * 0x14;
    buildingName._0_4_ = ((RGE_Player *)this->md->_padding_)->master_objects[x];
    if ((RGE_Master_Static_Object *)buildingName._0_4_ != (RGE_Master_Static_Object *)0x0) {
      this_01 = MainDecisionAIModule::object
                          ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
      iVar7 = param_2;
      if (param_10->active == 1) {
        iVar7 = param_10->builderID;
      }
      MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar7);
      if ((param_1 == (BuildItem *)0x0) && (param_10->active != 1)) {
        centerPoint.y = param_8;
        maxClear.x = param_9;
      }
      else {
        centerPoint.y = __ftol();
        maxClear.x = __ftol();
      }
      iVar7 = placementCode(this,x);
      if (iVar7 == -1) {
        AIModule::logCommonHistory(this_02,(char *)this,s_Invalid_influence_placement_type,x);
      }
      else {
        if ((param_1 == (BuildItem *)0x0) && (param_10->active != 1)) {
          centerPoint.x = param_7;
          local_154 = param_6;
          RGE_Static_Object::lookupZone(this_00,param_8,param_9);
          iVar21 = centerPoint.x;
        }
        else {
          if (iVar7 == 1) {
            local_154 = 7;
            iVar21 = TribeTacticalAIModule::inAge(&this->md->tacticalAI,2);
            if (iVar21 == 0) {
              iVar21 = TribeTacticalAIModule::inAge(&this->md->tacticalAI,3);
              if (iVar21 == 0) {
                iVar8 = TribeTacticalAIModule::inAge(&this->md->tacticalAI,4);
                iVar21 = 1;
                if (iVar8 != 0) {
                  iVar21 = 4;
                }
              }
              else {
                iVar21 = 3;
              }
            }
            else {
              iVar21 = 2;
            }
            iVar8 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x56);
            centerPoint.x = iVar8 * iVar21;
          }
          else if (iVar7 == 2) {
            local_154 = 4;
            centerPoint.x = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x57);
          }
          else {
            if ((iVar7 == 3) || (iVar7 == 4)) {
              local_154 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x49);
              pTVar16 = this->md;
            }
            else {
              local_154 = 4;
              pTVar16 = this->md;
            }
            centerPoint.x = TribeTacticalAIModule::strategicNumber(&pTVar16->tacticalAI,0x4a);
          }
          iVar21 = centerPoint.x;
          if (this_01 == (RGE_Static_Object *)0x0) {
            this_01 = this_00;
          }
          RGE_Static_Object::currentZone(this_01);
        }
        if (local_154 < iVar21) {
          min.y = centerPoint.y - iVar21;
          maxExclude.x = maxClear.x - iVar21;
          mapBound(this,(XYPoint *)&min.y);
          max.y = iVar21 + centerPoint.y;
          iVar21 = iVar21 + maxClear.x;
          mapBound(this,(XYPoint *)&max.y);
          minExclude.y = centerPoint.y - local_154;
          iVar8 = maxClear.x - local_154;
          mapBound(this,(XYPoint *)&minExclude.y);
          maxExclude.y = local_154 + centerPoint.y;
          minExclude.x = local_154 + maxClear.x;
          mapBound(this,(XYPoint *)&maxExclude.y);
          if (param_1 == (BuildItem *)0x0) {
LAB_004db819:
            if (param_10->active == 0) {
              setupInfluenceMap(this,iVar7,x,(XYPoint *)&centerPoint.y,(XYPoint *)&min.y,
                                (XYPoint *)&max.y);
            }
          }
          else if (param_10->active == 0) {
            pBVar9 = availableLot(this,x);
            if (pBVar9 != (BuildingLot *)0x0) {
              if (iVar7 == 4) {
                iVar6 = (this->lastWallPosition).y;
                (this->lastWallPosition2).x = (this->lastWallPosition).x;
                (this->lastWallPosition2).y = iVar6;
                (this->lastWallPosition).x = (uint)pBVar9->x;
                (this->lastWallPosition).y = (uint)pBVar9->y;
              }
                    /* language.dll match for 0x80: "Arial" */
              if ((float)buildingType == _DAT_00575574) {
                max.x = (int)operator_new(0x80);
                local_4 = 0;
                if ((ConstructionItem *)max.x != (ConstructionItem *)0x0) {
                  pCVar15 = (ConstructionItem *)
                            ConstructionItem::ConstructionItem
                                      ((ConstructionItem *)max.x,(float)pBVar9->x,(float)pBVar9->y,
                                       1.0,(float)buildingType,(float)buildingType,1.0,x,
                                       buildingName + 4);
                  pBVar9->status = '\x01';
                  param_10->active = 0;
                  goto LAB_004dc0d9;
                }
              }
              else {
                max.x = (int)operator_new(0x80);
                local_4 = 1;
                if ((ConstructionItem *)max.x != (ConstructionItem *)0x0) {
                  pCVar15 = (ConstructionItem *)
                            ConstructionItem::ConstructionItem
                                      ((ConstructionItem *)max.x,(float)pBVar9->x - _DAT_00575570,
                                       (float)pBVar9->y - _DAT_00575570,1.0,(float)buildingType,
                                       (float)buildingType,1.0,x,buildingName + 4);
                  pBVar9->status = '\x01';
                  param_10->active = 0;
                  goto LAB_004dc0d9;
                }
              }
              pCVar15 = (ConstructionItem *)0x0;
              pBVar9->status = '\x01';
              param_10->active = 0;
              goto LAB_004dc0d9;
            }
            goto LAB_004db819;
          }
          if (param_10->active == 0) {
            iVar10 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xa8);
            if (iVar10 < 1) {
              placementType = 0;
            }
            else {
              iVar11 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0xac8);
              placementType = iVar11 % iVar10;
            }
            bestPoint.y = -1;
            basePlacementTotal = -1;
            minimumDistance = -1;
            randSelect = min.y;
          }
          else {
            placementType = param_10->randomInfluence;
            bestPoint.y = (param_10->bestPoint).x;
            basePlacementTotal = (param_10->bestPoint).y;
            minimumDistance = param_10->bestPointValue;
            randSelect = param_10->iterationX;
          }
          uVar2 = *(uint *)(*(int *)(this->md->_padding_ + 0x3c) + 0xf8);
          uVar12 = debug_timeGetTime(s_C__msdev_work_age1_x1_taiinfmd_c,0xade);
          if ((param_10->active == 0) && (uVar2 <= uVar12 - param_11)) {
            param_10->buildingTypeID = x;
            strncpy(param_10->buildingName,buildingName + 4,0xff);
            param_10->buildingSize = (float)buildingType;
            param_10->builderID = param_2;
            param_10->minimumDistance = local_154;
            param_10->maximumDistance = centerPoint.x;
            (param_10->bestPoint).x = bestPoint.y;
            param_10->active = 1;
            (param_10->bestPoint).y = basePlacementTotal;
            param_10->bestPointValue = minimumDistance;
            param_10->iterationX = randSelect;
            param_10->randomInfluence = placementType;
            param_10->buildItem = param_1;
            goto LAB_004dc0d7;
          }
          min.x = 0;
          if ((iVar7 == 4) || (iVar7 == 3)) {
            min.x = 1;
          }
          bVar4 = true;
          iVar10 = minimumDistance;
          if (randSelect <= max.y) {
            do {
              if (bVar4) {
                bVar4 = false;
                iVar11 = maxExclude.x;
              }
              else {
                uVar12 = debug_timeGetTime(s_C__msdev_work_age1_x1_taiinfmd_c,0xb16);
                iVar11 = maxExclude.x;
                if (uVar2 <= uVar12 - param_11) {
                  param_10->buildingTypeID = x;
                  strncpy(param_10->buildingName,buildingName + 4,0xff);
                  param_10->buildingSize = (float)buildingType;
                  param_10->builderID = param_2;
                  param_10->minimumDistance = local_154;
                  param_10->maximumDistance = centerPoint.x;
                  (param_10->bestPoint).x = bestPoint.y;
                  param_10->active = 1;
                  (param_10->bestPoint).y = basePlacementTotal;
                  param_10->bestPointValue = iVar10;
                  param_10->iterationX = randSelect;
                  param_10->randomInfluence = placementType;
                  param_10->buildItem = param_1;
                  goto LAB_004dc0d7;
                }
              }
              for (; iVar11 <= iVar21; iVar11 = iVar11 + 1) {
                if ((((min.x != 1) || (randSelect < minExclude.y)) || (maxExclude.y < randSelect))
                   || ((iVar11 < iVar8 || (minExclude.x < iVar11)))) {
                  if ((float)buildingType == _DAT_00575578) {
LAB_004dbad8:
                    minClear.y = randSelect + -2;
                    maxClear.y = randSelect + 2;
                    minClear.x = iVar11 + 2;
                    bestPointValue = iVar11 + -2;
                  }
                  else if ((float)buildingType == _DAT_0057557c) {
                    if (((iVar7 != 6) && (iVar7 != 3)) &&
                       (((iVar7 != 4 && ((iVar7 != 1 && (iVar7 != 2)))) && (iVar7 != 8))))
                    goto LAB_004dbad8;
LAB_004dbb67:
                    minClear.y = randSelect + -1;
                    maxClear.y = randSelect + 1;
                    minClear.x = iVar11 + 1;
                    bestPointValue = iVar11 + -1;
                  }
                  else if ((float)buildingType == _DAT_00575574) {
                    if (((iVar7 == 6) || (iVar7 == 3)) || (iVar7 == 4)) {
                      minClear.y = randSelect + -1;
                      minClear.x = iVar11;
                      maxClear.y = randSelect;
                      bestPointValue = iVar11 + -1;
                    }
                    else {
                      minClear.y = randSelect + -2;
                      maxClear.y = randSelect + 1;
                      minClear.x = iVar11 + 1;
                      bestPointValue = iVar11 + -2;
                    }
                  }
                  else {
                    if ((float)buildingType != _DAT_00575564) {
                      basePlacementTotal = (int)((ulonglong)(double)(float)buildingType >> 0x20);
                      bestPoint.y = SUB84((double)(float)buildingType,0);
                      AIModule::logCommonHistory
                                ((AIModule *)bestPoint.y,(char *)this,
                                 s_____Unsupported_building_size___,bestPoint.y,basePlacementTotal,
                                 bestPoint.y,basePlacementTotal);
                      goto LAB_004dc0cd;
                    }
                    minClear.x = iVar11;
                    maxClear.y = randSelect;
                    minClear.y = randSelect;
                    bestPointValue = iVar11;
                    if (((iVar7 != 6) && (iVar7 != 3)) && (iVar7 != 4)) goto LAB_004dbb67;
                  }
                  iVar10 = mapBound(this,(XYPoint *)&minClear.y);
                  if ((iVar10 != 1) && (iVar10 = mapBound(this,(XYPoint *)&maxClear.y), iVar10 != 1)
                     ) {
                    local_120 = 0xffffffff;
                    cVar5 = (**(code **)(*(int *)buildingName._0_4_ + 0x20))
                                      (this->md->_padding_,(float)randSelect - _DAT_00575570,
                                       (float)iVar11 - _DAT_00575570,&local_120,1,1,1,1,1,1);
                    if (cVar5 == '\0') {
                      iVar10 = 0;
                      bVar3 = false;
                      iVar13 = minClear.x;
                      iVar22 = minClear.y;
                      if (minClear.y <= maxClear.y) {
                        do {
                          if (bVar3) break;
                          iVar19 = bestPointValue;
                          if (bestPointValue <= iVar13) {
                            do {
                              if (bVar3) break;
                              iVar13 = InfluenceMap::lookupValue(&iMap,iVar22,iVar19);
                              if (iVar13 == 0xff) {
                                bVar3 = true;
                              }
                              else {
                                iVar10 = iVar10 + iVar13;
                              }
                              iVar19 = iVar19 + 1;
                              iVar13 = minClear.x;
                            } while (iVar19 <= minClear.x);
                          }
                          iVar22 = iVar22 + 1;
                        } while (iVar22 <= maxClear.y);
                      }
                      iVar13 = iMap.connectionCountValue;
                      if (!bVar3) {
                        if ((iVar7 == 4) || (iVar7 == 6)) {
                          iVar22 = InfluenceMap::connectionsIncluding
                                             (&iMap,(XYPoint *)&minClear.y,(XYPoint *)&maxClear.y,
                                              0xff,0xff,1,0,1);
                          if ((iVar7 == 4) && (6 < iVar22 - iVar13)) goto LAB_004dbece;
                          iVar10 = (iVar22 - iVar13) * iVar10;
                        }
                        if (iVar7 == 4) {
                          pXVar1 = &this->lastWallPosition;
                          newPosition.y = randSelect;
                          if (((this->lastWallPosition).x != -1) &&
                             (iVar13 = isNextTo(this,pXVar1,(XYPoint *)&newPosition.y,0),
                             iVar13 == 0)) {
                            iVar10 = iVar10 / 2;
                          }
                          uVar14 = facetTo(this,pXVar1,(XYPoint *)&newPosition.y);
                          uVar17 = (int)uVar14 >> 0x1f;
                          if (((uVar14 ^ uVar17) - uVar17 & 1 ^ uVar17) - uVar17 == 1) {
                            iVar10 = iVar10 * 3;
                          }
                          uVar17 = facetTo(this,&this->lastWallPosition2,pXVar1);
                          if (uVar17 == uVar14) {
                            iVar10 = iVar10 * 3;
                          }
                          uVar17 = pXVar1->x - centerPoint.y;
                          uVar20 = (this->lastWallPosition).y - maxClear.x;
                          uVar18 = (int)uVar17 >> 0x1f;
                          iVar22 = (uVar17 ^ uVar18) - uVar18;
                          uVar17 = (int)uVar20 >> 0x1f;
                          iVar13 = (uVar20 ^ uVar17) - uVar17;
                          if (iVar13 < iVar22) {
                            if (uVar14 == 1) {
LAB_004dbdb1:
                              iVar10 = iVar10 * 3;
                            }
                            else if (uVar14 == 5) {
                              iVar10 = iVar10 * 3;
                            }
                          }
                          else if ((iVar22 < iVar13) && ((uVar14 == 3 || (uVar14 == 7))))
                          goto LAB_004dbdb1;
                        }
                        else {
                          if ((iVar7 == 1) || (iVar7 == 2)) {
                            iVar13 = undesirableLot(this,x,(uchar)randSelect,(uchar)iVar11,10);
                          }
                          else {
                            if (iVar7 == 6) goto LAB_004dbe30;
                            iVar13 = undesirableLot(this,x,(uchar)randSelect,(uchar)iVar11,
                                                    newPosition.x);
                          }
                          if (iVar13 == 1) {
                            iVar10 = iVar10 / 10;
                          }
                        }
LAB_004dbe30:
                        if ((iVar7 == 1) || (iVar7 == 2)) {
                          max.x = (randSelect - centerPoint.y) * (randSelect - centerPoint.y) +
                                  (iVar11 - maxClear.x) * (iVar11 - maxClear.x);
                          iVar13 = __ftol();
                          if ((0 < iVar13 + -10) &&
                             (iVar13 = iVar10 - (iVar13 + -10) / 5, iVar6 < iVar13)) {
                            iVar10 = iVar13;
                          }
                        }
                        if ((minimumDistance == -1) || (minimumDistance < iVar10 + placementType)) {
                          if (iVar10 <= minimumDistance) {
                            placementType = placementType / 2;
                          }
                          bestPoint.y = randSelect;
                          minimumDistance = iVar10;
                          basePlacementTotal = iVar11;
                        }
                      }
                    }
                  }
                }
LAB_004dbece:
                iVar10 = minimumDistance;
              }
              randSelect = randSelect + 1;
            } while (randSelect <= max.y);
          }
          if ((iVar10 != -1) &&
             ((iVar6 < iVar10 || ((iVar7 != 2 && ((iVar6 < iVar10 || (iVar7 != 1)))))))) {
            if (iVar7 == 4) {
              iVar6 = (this->lastWallPosition).y;
              (this->lastWallPosition2).x = (this->lastWallPosition).x;
              (this->lastWallPosition2).y = iVar6;
              (this->lastWallPosition).x = bestPoint.y;
              (this->lastWallPosition).y = basePlacementTotal;
            }
            if ((param_1 == (BuildItem *)0x0) && (param_10->active != 1)) {
              storeLot(this,x,(uchar)bestPoint.y,(uchar)basePlacementTotal,'\0');
              param_10->active = 0;
              pCVar15 = (ConstructionItem *)0x1;
              goto LAB_004dc0d9;
            }
                    /* language.dll match for 0x80: "Arial" */
            if ((float)buildingType == _DAT_00575574) {
              max.x = (int)operator_new(0x80);
              local_4 = 2;
              if ((ConstructionItem *)max.x == (ConstructionItem *)0x0) {
LAB_004dc06f:
                pCVar15 = (ConstructionItem *)0x0;
              }
              else {
                pCVar15 = (ConstructionItem *)
                          ConstructionItem::ConstructionItem
                                    ((ConstructionItem *)max.x,(float)bestPoint.y,
                                     (float)basePlacementTotal,1.0,(float)buildingType,
                                     (float)buildingType,1.0,x,buildingName + 4);
              }
            }
            else {
              max.x = (int)operator_new(0x80);
              local_4 = 3;
              if ((ConstructionItem *)max.x == (ConstructionItem *)0x0) goto LAB_004dc06f;
              pCVar15 = (ConstructionItem *)
                        ConstructionItem::ConstructionItem
                                  ((ConstructionItem *)max.x,(float)bestPoint.y - _DAT_00575570,
                                   (float)basePlacementTotal - _DAT_00575570,1.0,(float)buildingType
                                   ,(float)buildingType,1.0,x,buildingName + 4);
            }
            local_4 = 0xffffffff;
            storeLot(this,x,(uchar)bestPoint.y,(uchar)basePlacementTotal,'\x01');
            param_10->active = 0;
            goto LAB_004dc0d9;
          }
          if (iVar7 == 4) {
            iVar6 = (this->lastWallPosition).y;
            (this->lastWallPosition2).x = (this->lastWallPosition).x;
            (this->lastWallPosition2).y = iVar6;
            (this->lastWallPosition).x = -1;
            (this->lastWallPosition).y = -1;
          }
        }
      }
    }
LAB_004dc0cd:
    param_10->active = 0;
  }
LAB_004dc0d7:
  pCVar15 = (ConstructionItem *)0x0;
LAB_004dc0d9:
  *unaff_FS_OFFSET = local_c;
  return pCVar15;
}

// --------------------------------------------------

// Function: addObject
// Address: 004dc1b0
/* public: void __thiscall TribeInformationAIModule::addObject(class RGE_Static_Object *) */

void __thiscall
TribeInformationAIModule::addObject(TribeInformationAIModule *this,RGE_Static_Object *param_1)
{
  short sVar1;
  int iVar2;
  ObjectMemory *pOVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  if ((param_1 != (RGE_Static_Object *)0x0) && (-1 < param_1->id)) {
    pOVar3 = objectMemory(this,param_1->id);
    if (pOVar3 != (ObjectMemory *)0x0) {
      pOVar3->owner = (uchar)param_1->owner->id;
    }
    iVar7 = (this->playerObjects).numberValue;
    iVar2 = param_1->id;
    iVar4 = 0;
    if (0 < iVar7) {
      do {
        if ((this->playerObjects).maximumSizeValue <= iVar4) break;
        if ((this->playerObjects).value[iVar4] == iVar2) goto LAB_004dc295;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar7);
    }
    if ((this->playerObjects).maximumSizeValue + -1 < iVar7) {
      iVar7 = iVar7 + 1;
      piVar5 = (int *)operator_new(iVar7 * 4);
      if (piVar5 != (int *)0x0) {
        iVar4 = 0;
        if (0 < (this->playerObjects).maximumSizeValue) {
          do {
            if (iVar7 <= iVar4) break;
            iVar6 = iVar4 + 1;
            piVar5[iVar4] = (this->playerObjects).value[iVar4];
            iVar4 = iVar6;
          } while (iVar6 < (this->playerObjects).maximumSizeValue);
        }
        operator_delete((this->playerObjects).value);
        (this->playerObjects).value = piVar5;
        (this->playerObjects).maximumSizeValue = iVar7;
      }
    }
    (this->playerObjects).value[(this->playerObjects).numberValue] = iVar2;
    (this->playerObjects).numberValue = (this->playerObjects).numberValue + 1;
LAB_004dc295:
    iVar7 = isBuilding(this,param_1);
    if (iVar7 == 1) {
      iVar7 = (this->playerBuildings).numberValue;
      iVar2 = param_1->id;
      iVar4 = 0;
      if (0 < iVar7) {
        do {
          if ((this->playerBuildings).maximumSizeValue <= iVar4) break;
          if ((this->playerBuildings).value[iVar4] == iVar2) goto LAB_004dc357;
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar7);
      }
      if ((this->playerBuildings).maximumSizeValue + -1 < iVar7) {
        iVar7 = iVar7 + 1;
        piVar5 = (int *)operator_new(iVar7 * 4);
        if (piVar5 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->playerBuildings).maximumSizeValue) {
            do {
              if (iVar7 <= iVar4) break;
              iVar6 = iVar4 + 1;
              piVar5[iVar4] = (this->playerBuildings).value[iVar4];
              iVar4 = iVar6;
            } while (iVar6 < (this->playerBuildings).maximumSizeValue);
          }
          operator_delete((this->playerBuildings).value);
          (this->playerBuildings).value = piVar5;
          (this->playerBuildings).maximumSizeValue = iVar7;
        }
      }
      (this->playerBuildings).value[(this->playerBuildings).numberValue] = iVar2;
      (this->playerBuildings).numberValue = (this->playerBuildings).numberValue + 1;
LAB_004dc357:
      sVar1 = param_1->master_obj->id;
      if (((sVar1 == 0x6d) || (sVar1 == 0x67)) || (sVar1 == 0x44)) {
        updateAllResourceDropsites(this);
      }
      if (param_1->master_obj->id == 0x32) {
        addResourceObject(this,param_1);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: removeObject
// Address: 004dc3a0
/* public: void __thiscall TribeInformationAIModule::removeObject(int) */

void __thiscall TribeInformationAIModule::removeObject(TribeInformationAIModule *this,int param_1)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  ObjectMemory *pOVar4;
  int *piVar5;
  
  iVar1 = 0;
  iVar2 = (this->playerBuildings).maximumSizeValue;
  if (0 < iVar2) {
    piVar5 = (this->playerBuildings).value;
    do {
      if (*piVar5 == param_1) break;
      iVar1 = iVar1 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar1 < iVar2);
  }
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar5 = (this->playerBuildings).value;
        iVar2 = iVar1 + 1;
        piVar5[iVar1] = piVar5[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (this->playerBuildings).maximumSizeValue + -1);
    }
    iVar2 = (this->playerBuildings).numberValue + -1;
    (this->playerBuildings).numberValue = iVar2;
    if (iVar2 < 0) {
      (this->playerBuildings).numberValue = 0;
    }
  }
  iVar2 = (this->playerObjects).maximumSizeValue;
  iVar1 = 0;
  if (0 < iVar2) {
    piVar5 = (this->playerObjects).value;
    do {
      if (*piVar5 == param_1) break;
      iVar1 = iVar1 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar1 < iVar2);
  }
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar5 = (this->playerObjects).value;
        iVar2 = iVar1 + 1;
        piVar5[iVar1] = piVar5[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (this->playerObjects).maximumSizeValue + -1);
    }
    iVar2 = (this->playerObjects).numberValue + -1;
    (this->playerObjects).numberValue = iVar2;
    if (iVar2 < 0) {
      (this->playerObjects).numberValue = 0;
    }
  }
  pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if (pRVar3 != (RGE_Static_Object *)0x0) {
    pOVar4 = objectMemory(this,param_1);
    if (pOVar4 != (ObjectMemory *)0x0) {
      pOVar4->owner = (uchar)pRVar3->owner->id;
    }
  }
  return;
}

// --------------------------------------------------

// Function: objectToAttackWithPlay
// Address: 004dc490
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
/* WARNING: Variable defined which should be unmapped: i */
/* public: struct ObjectMemory * __thiscall TribeInformationAIModule::objectToAttackWithPlay(int,int
   *,int,int &,int *,int &,int &) */

ObjectMemory * __thiscall
TribeInformationAIModule::objectToAttackWithPlay
          (TribeInformationAIModule *this,int param_1,int *param_2,int param_3,int *param_4,
          int *param_5,int *param_6,int *param_7)
{
  byte bVar1;
  uchar uVar2;
  RGE_Game_World *pRVar3;
  bool bVar4;
  ObjectMemory *pOVar5;
  AIPlay *this_00;
  int iVar6;
  AIPlayPhase *this_01;
  AIPlayPhaseCommand *pAVar7;
  int iVar8;
  int iVar9;
  int i;
  ObjectMemory *target;
  AIPlay *play;
  int p;
  RGE_Game_World *world;
  AIPlayBook *playbook;
  AIPlayStatus playStatus;
  char local_4;
  
  if (param_3 == 0) {
    return (ObjectMemory *)param_3;
  }
  pOVar5 = objectToAttackByGroup2(this,param_1,param_2,param_3);
  if (pOVar5 == (ObjectMemory *)0x0) {
    return (ObjectMemory *)0x0;
  }
  target = (ObjectMemory *)0x0;
  pRVar3 = *(RGE_Game_World **)(this->md->_padding_ + 0x3c);
  playStatus.groupings[0].id = (int)pRVar3->playbook;
  *param_4 = -1;
  if (0 < ((AIPlayBook *)playStatus.groupings[0].id)->numberPlaysValue) {
    do {
      this_00 = AIPlayBook::play((AIPlayBook *)playStatus.groupings[0].id,(int)target);
      if ((this_00 != (AIPlay *)0x0) && (iVar6 = AIPlay::humanPlay(this_00), iVar6 != 1)) {
        AIPlayStatus::AIPlayStatus((AIPlayStatus *)&playStatus.groupings[0].groupID);
        playStatus.targetValue = (int)target;
        AIPlay::fillGroups(this_00,(AIPlayStatus *)&playStatus.groupings[0].groupID,param_2,param_3,
                           pRVar3);
        if (local_4 == '\0') {
          bVar4 = false;
          world = (RGE_Game_World *)0x0;
          do {
            if (bVar4) goto LAB_004dc6f8;
            iVar6 = 0;
            do {
              if (bVar4) break;
              iVar8 = iVar6;
              this_01 = AIPlay::phase(this_00,(int)world);
              pAVar7 = AIPlayPhase::command(this_01,iVar8);
              if (pAVar7->typeValue == '\x01') {
                iVar9 = pAVar7->value1Value + (uint)pOVar5->x;
                iVar8 = pAVar7->value2Value + (uint)pOVar5->y;
                if ((((iVar9 < 0) || (iVar8 < 0)) || (this->mapXSizeValue <= iVar9)) ||
                   (this->mapYSizeValue <= iVar8)) {
                  bVar4 = true;
                }
                iVar8 = inRangeOfUnits(this,param_1,iVar9,iVar8,0);
                if (iVar8 == 1) {
                  bVar4 = true;
                }
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < 5);
            world = (RGE_Game_World *)((int)&world->_padding_ + 1);
          } while ((int)world < 10);
          if (!bVar4) {
            iVar6 = calculatePlayVariation(this,(int)target);
            bVar1 = this_00->deathPercentageValue;
            iVar8 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0xd49);
            iVar9 = 0;
            uVar2 = this_00->typeValue;
            if (uVar2 == '\x01') {
              iVar9 = 0xbd;
LAB_004dc687:
              iVar9 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,iVar9);
            }
            else {
              if (uVar2 == '\x02') {
                iVar9 = 0xc6;
                goto LAB_004dc687;
              }
              if (uVar2 == '\x03') {
                iVar9 = 199;
                goto LAB_004dc687;
              }
            }
            if ((*param_4 == -1) ||
               (0 < (int)(iVar9 + ((100 - (uint)bVar1) + iVar6) * 2 + iVar8 % 0x32))) {
              *param_4 = (int)target;
              AIPlayStatus::copyUnits
                        ((AIPlayStatus *)&playStatus.groupings[0].groupID,param_5,param_6);
              iVar6 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0xd6a);
              *param_7 = param_5[iVar6 % *param_6];
            }
          }
        }
      }
LAB_004dc6f8:
      target = (ObjectMemory *)((int)&target->id + 1);
    } while ((int)target < *(int *)(playStatus.groupings[0].id + 4));
  }
  iVar6 = *param_4;
  if (iVar6 != -1) {
    this->playHistory[iVar6] = this->playHistory[iVar6] + 1;
    return pOVar5;
  }
  return (ObjectMemory *)0x0;
}

// --------------------------------------------------

// Function: objectToAttack
// Address: 004dc750
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
/* WARNING: Variable defined which should be unmapped: specialRating1 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: struct ObjectMemory * __thiscall
   TribeInformationAIModule::objectToAttack(int,int,int,int,int &) */

ObjectMemory * __thiscall
TribeInformationAIModule::objectToAttack
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3,int param_4,
          int *param_5)
{
  short sVar1;
  short sVar2;
  float10 fVar3;
  bool bVar4;
  uchar uVar5;
  uchar uVar6;
  ObjectMemory *pOVar7;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar8;
  int iVar9;
  RGE_Static_Object *pRVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  float10 fVar28;
  float fVar29;
  int specialRating1;
  float fStack_88;
  int iStack_84;
  uchar unitZone;
  RGE_Static_Object *unit;
  int rOFRating;
  int siegeWeapon;
  int rangeRating;
  float timeToKill;
  ObjectMemory *bestObject;
  float timeToBeKilled;
  int boatWeapon;
  int zoneRating;
  int specialRating2;
  RGE_Static_Object *tempObj;
  int killRating;
  int bestAttackValue;
  int specialRating3;
  int i;
  int dCRating;
  int hpRating;
  int distanceRating;
  int unitIsPriest;
  int numberNonSiegeTargets;
  int randomRating;
  int numberNonBoatTargets;
  ObjectMemory oLimits;
  float fStack_4;
  
  pOVar7 = wonderToAttack(this,-1);
  if (pOVar7 != (ObjectMemory *)0x0) {
    *param_5 = 1;
    return pOVar7;
  }
  this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_4);
  if ((this_00 == (RGE_Static_Object *)0x0) ||
     (pUVar8 = RGE_Static_Object::unitAI(this_00), pUVar8 == (UnitAIModule *)0x0)) {
    return (ObjectMemory *)0x0;
  }
  uVar5 = RGE_Static_Object::currentZone(this_00);
  sVar1 = this_00->master_obj->id;
  if (((sVar1 == 0x23) || (sVar1 == 0x24)) || (bVar4 = false, sVar1 == 0xb)) {
    bVar4 = true;
  }
  iVar9 = isBoat(this,this_00);
  sVar1 = this_00->master_obj->object_group;
  findObjectMemoryLimits
            (this,(ObjectMemory *)&oLimits.type,param_1,param_4,&randomRating,&oLimits.id);
  timeToBeKilled = 0.0;
  specialRating3 = -1;
  dCRating = 0;
  if (0 < this->maxImportantObjectMemory) {
    iStack_84 = 0;
    do {
      if ((((uint)(&this->importantObjectMemory->owner)[iStack_84] == param_1) &&
          (pRVar10 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)this->md,
                                *(int *)((int)&this->importantObjectMemory->id + iStack_84)),
          pRVar10 != (RGE_Static_Object *)0x0)) && (pRVar10->object_state < 3)) {
        iVar11 = __ftol();
        iVar12 = __ftol();
        fVar29 = damagePerSecond(this,param_4,iVar12,iVar11);
        (**(code **)(pRVar10->_padding_ + 0x104))(this_00);
        fVar28 = (float10)(**(code **)(this_00->_padding_ + 0x100))();
        fVar3 = (float10)fStack_88;
        if (fVar29 <= _DAT_00575580) {
          boatWeapon = -0x40800000;
        }
        else {
          boatWeapon = (int)(this_00->hp / fVar29);
        }
        if (fVar3 / fVar28 <= (float10)_DAT_00575580) {
          bestObject = (ObjectMemory *)0xbf800000;
        }
        else {
          fStack_88 = (float)(int)*(short *)((int)&this->importantObjectMemory->hitPoints +
                                            iStack_84);
          bestObject = (ObjectMemory *)(float)((float10)(int)fStack_88 / (fVar3 / fVar28));
        }
        if (((((bVar4) || (param_2 == 0)) ||
             ((sVar2 = pRVar10->master_obj->object_group, sVar2 != 3 && (sVar2 != 0x1b)))) ||
            (randomRating < 1)) &&
           (((iVar9 != 0 || (param_3 == 0)) ||
            (((pRVar10->master_obj->id != 0x2d &&
              ((((sVar2 = pRVar10->master_obj->object_group, sVar2 != 2 && (sVar2 != 0x15)) &&
                (sVar2 != 0x16)) && (sVar2 != 0x14)))) || (oLimits.id < 1)))))) {
          if (sVar1 == 0x12) {
            pUVar8 = RGE_Static_Object::unitAI(this_00);
            iVar11 = (**(code **)(pUVar8->_padding_ + 0xc4))
                               (*(undefined4 *)((int)&this->importantObjectMemory->id + iStack_84));
            if (iVar11 == 0) goto LAB_004dcecb;
          }
          pOVar7 = this->importantObjectMemory;
          iVar11 = __ftol();
          iVar12 = (uint)(&pOVar7->x)[iStack_84] - iVar11;
          if (iVar12 < 0) {
            iVar12 = -iVar12;
          }
          iVar13 = __ftol();
          iVar27 = (uint)(&pOVar7->y)[iStack_84] - iVar13;
          if (iVar27 < 0) {
            iVar27 = -iVar27;
          }
          if (((iVar12 < 6) && (iVar27 < 6)) ||
             (uVar6 = RGE_Visible_Map::get_visible
                                (*(RGE_Visible_Map **)(this->md->_padding_ + 0x38),iVar11,iVar13),
             uVar6 == '\x0f')) {
            pOVar7 = this->importantObjectMemory;
            __ftol();
            __ftol();
            iVar11 = __ftol();
            if (oLimits._4_4_ == 0) {
              unitIsPriest = 100;
            }
            else {
              unitIsPriest = 100 - (iVar11 * 100) / (int)oLimits._4_4_;
            }
            if ((short)oLimits.attackAttempts == 0) {
              distanceRating = 100;
            }
            else {
              distanceRating =
                   (*(short *)((int)&pOVar7->hitPoints + iStack_84) * 100) /
                   (int)(short)oLimits.attackAttempts;
            }
            if (SUB41(oLimits.damageCapability,0) == '\0') {
              bestAttackValue = 100;
            }
            else {
              bestAttackValue =
                   ((uint)(&pOVar7->kills)[iStack_84] * 100) /
                   ((uint)oLimits.damageCapability & 0xff);
            }
            if (oLimits.rateOfFire == _DAT_00575580) {
              hpRating = 100;
            }
            else {
              hpRating = __ftol();
            }
            if (*(float *)((int)&pOVar7->damageCapability + iStack_84) <= _DAT_00575580) {
              timeToKill = 0.0;
              siegeWeapon = 0;
            }
            else {
              if (fStack_4 == _DAT_00575580) {
                timeToKill = 1.4013e-43;
              }
              else {
                timeToKill = (float)__ftol();
              }
              if (oLimits.range == _DAT_00575580) {
                siegeWeapon = 100;
              }
              else {
                iVar11 = __ftol();
                siegeWeapon = 100 - iVar11;
              }
            }
            iVar11 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0xe36);
            numberNonBoatTargets = iVar11 % 100;
            iVar11 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x6a);
            fStack_88 = (float)(uint)(*(short *)((int)&this->importantObjectMemory->type + iStack_84
                                                ) == iVar11);
            iVar11 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x6b);
            tempObj = (RGE_Static_Object *)
                      (uint)(*(short *)((int)&this->importantObjectMemory->type + iStack_84) ==
                            iVar11);
            iVar11 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x6c);
            i = (int)(*(short *)((int)&this->importantObjectMemory->type + iStack_84) == iVar11);
            iVar11 = __ftol();
            iVar12 = __ftol();
            uVar6 = RGE_Static_Object::lookupZone(this_00,iVar12,iVar11);
            specialRating2 = (int)(uVar5 == uVar6);
            sVar2 = pRVar10->master_obj->object_group;
            if ((sVar2 == 3) || (sVar2 == 0x1b)) {
              iVar11 = (-(uint)bVar4 & 2) - 1;
            }
            else {
              iVar11 = (-(uint)bVar4 & 0xfffffffe) + 1;
            }
            if ((((pRVar10->master_obj->id == 0x2d) || (sVar2 == 2)) || (sVar2 == 0x15)) ||
               ((sVar2 == 0x16 || (sVar2 == 0x14)))) {
              iVar12 = (-(uint)(iVar9 != 0) & 2) - 1;
            }
            else {
              iVar12 = (-(uint)(iVar9 != 0) & 0xfffffffe) + 1;
            }
            iVar27 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x59);
            iVar13 = *(int *)((int)&this->importantObjectMemory->attackAttempts + iStack_84);
            iVar14 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x90);
                    /* language.dll match for 0x7b: "9" */
            iVar15 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x7b);
                    /* language.dll match for 0x7a: "Arial" */
            iVar16 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x7a);
            iVar17 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x50);
            iVar18 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x53);
            iVar18 = iVar18 * numberNonBoatTargets;
            iVar19 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x4d);
                    /* language.dll match for 0x6f: "12" */
            iVar20 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x6f);
            iVar21 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x5a);
            iVar22 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x4e);
            iVar23 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x4f);
            iVar24 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x52);
                    /* language.dll match for 0x6e: "Copperplate Gothic Light" */
            iVar25 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x6e);
            iVar26 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x6d);
            iVar11 = iVar27 * iVar13 + iVar14 * iVar12 + iVar15 * iVar11 + iVar16 * specialRating2 +
                     iVar17 * bestAttackValue + iVar18 + iVar19 * unitIsPriest + iVar20 * i +
                     iVar21 * (int)timeToKill + iVar22 * distanceRating + iVar23 * hpRating +
                     iVar24 * siegeWeapon + iVar25 * (int)tempObj + iVar26 * (int)fStack_88;
            if ((((float)boatWeapon < (float)bestObject) && ((float)boatWeapon != _DAT_0057556c)) ||
               ((float)bestObject == _DAT_0057556c)) {
              iVar11 = 1;
            }
            if ((timeToBeKilled == 0.0) || (specialRating3 < iVar11)) {
              timeToBeKilled = (float)((int)&this->importantObjectMemory->id + iStack_84);
              *param_5 = 1;
              specialRating3 = iVar11;
            }
          }
        }
      }
LAB_004dcecb:
      dCRating = dCRating + 1;
      iStack_84 = iStack_84 + 0x24;
    } while (dCRating < this->maxImportantObjectMemory);
  }
  return (ObjectMemory *)timeToBeKilled;
}

// --------------------------------------------------

// Function: objectToAttackByGroup
// Address: 004dcf10
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
/* WARNING: Variable defined which should be unmapped: tempZone */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: struct ObjectMemory * __thiscall
   TribeInformationAIModule::objectToAttackByGroup(int,class TacticalAIGroup *,struct AttackState
   &,unsigned long) */

ObjectMemory * __thiscall
TribeInformationAIModule::objectToAttackByGroup
          (TribeInformationAIModule *this,int param_1,TacticalAIGroup *param_2,AttackState *param_3,
          ulong param_4)
{
  byte bVar1;
  short sVar2;
  short sVar3;
  code *pcVar4;
  uint uVar5;
  float fVar6;
  byte bVar7;
  byte bVar8;
  uchar uVar9;
  int iVar10;
  RGE_Static_Object *pRVar11;
  UnitAIModule *pUVar12;
  RGE_Static_Object *pRVar13;
  ObjectMemory *pOVar14;
  int iVar15;
  int iVar16;
  void *pvVar17;
  ulong uVar18;
  int *piVar19;
  int iVar20;
  int iVar21;
  RGE_Static_Object *this_00;
  int iVar22;
  undefined4 *unaff_FS_OFFSET;
  bool bVar23;
  float10 fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  uchar tempZone;
  uchar commanderZone;
  float miscFactor;
  ObjectMemory *wonder;
  RGE_Static_Object *commanderObj;
  int inProgressCount;
  int commanderIsBoat;
  float targetDistance;
  int commanderIsPriest;
  float inProgressFactor;
  float zoneFactor;
  float targetRandomization;
  RGE_Static_Object *tempObj;
  float killsByTarget;
  float timeKillRatio;
  int unobstructibleGroupID;
  ManagedArray<int> wallObjects;
  int iStack_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560560;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar10 = TacticalAIGroup::commander(param_2);
  pRVar11 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar10);
  if ((pRVar11 == (RGE_Static_Object *)0x0) ||
     (pUVar12 = RGE_Static_Object::unitAI(pRVar11), pUVar12 == (UnitAIModule *)0x0)) {
    param_3->active = 0;
  }
  else {
    bVar7 = RGE_Static_Object::currentZone(pRVar11);
    sVar2 = pRVar11->master_obj->object_group;
    iVar10 = isBoat(this,pRVar11);
    bVar23 = iVar10 == 1;
    if ((((param_3->active == 0) && (param_2->objectsToDestroyOwnerValue == param_1)) &&
        (0 < param_2->numberObjectsToDestroyValue)) &&
       (param_2->objectsToDestroyCommanderZoneValue == (uint)bVar7)) {
      iVar10 = TacticalAIGroup::objectToDestroy(param_2,param_2->numberObjectsToDestroyValue + -1);
      pRVar13 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar10);
      if (((pRVar13 != (RGE_Static_Object *)0x0) &&
          (iVar10 = (**(code **)(*(int *)this->md->_padding_ + 0x18))((int)pRVar13->owner->id),
          iVar10 == 1)) && (pRVar13->object_state < 3)) {
        iVar10 = param_2->numberObjectsToDestroyValue;
        iVar15 = pRVar11->_padding_;
        fVar24 = (float10)(**(code **)(iVar15 + 0x10c))(0,1,0xffffffff,0xffffffff);
        fVar27 = (float)fVar24;
        iVar10 = TacticalAIGroup::objectToDestroy(param_2,iVar10 + -1);
        iVar10 = (**(code **)(iVar15 + 0x194))(iVar10,fVar27);
        if (iVar10 == 1) {
          iVar10 = TacticalAIGroup::objectToDestroy
                             (param_2,param_2->numberObjectsToDestroyValue + -1);
          param_2->numberObjectsToDestroyValue = 0;
          TacticalAIGroup::addObjectToDestroy(param_2,iVar10);
          pOVar14 = objectMemory(this,iVar10);
          goto LAB_004ddd27;
        }
      }
      iVar10 = 0;
      if (param_2->numberObjectsToDestroyValue != 1 &&
          -1 < param_2->numberObjectsToDestroyValue + -1) {
        do {
          iVar15 = TacticalAIGroup::objectToDestroy(param_2,iVar10);
          pRVar13 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar15);
          if (((pRVar13 != (RGE_Static_Object *)0x0) &&
              (iVar15 = (**(code **)(*(int *)this->md->_padding_ + 0x18))((int)pRVar13->owner->id),
              iVar15 == 1)) && (pRVar13->object_state < 3)) {
            iVar15 = pRVar11->_padding_;
            fVar24 = (float10)(**(code **)(iVar15 + 0x10c))(0,1,0xffffffff,0xffffffff);
            fVar27 = (float)fVar24;
            iVar16 = TacticalAIGroup::objectToDestroy(param_2,iVar10);
            iVar15 = (**(code **)(iVar15 + 0x194))(iVar16,fVar27);
            if (iVar15 == 1) goto LAB_004ddcee;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < param_2->numberObjectsToDestroyValue + -1);
      }
    }
    if (param_3->active == 0) {
      pOVar14 = wonderToAttack(this,-1);
      if (pOVar14 != (ObjectMemory *)0x0) {
        bVar8 = RGE_Static_Object::lookupZone(pRVar11,(uint)pOVar14->x,(uint)pOVar14->y);
        if ((bVar8 != bVar7) && (!bVar23)) goto LAB_004ddd27;
        iVar10 = pRVar11->_padding_;
        pcVar4 = *(code **)(iVar10 + 0x10c);
        fVar24 = (float10)(*pcVar4)(0,1,0xffffffff,0xffffffff);
        iVar15 = (**(code **)(iVar10 + 0x194))(pOVar14->id,(float)fVar24);
        if (iVar15 == 1) {
          param_2->numberObjectsToDestroyValue = 0;
          TacticalAIGroup::addObjectToDestroy(param_2,pOVar14->id);
          param_2->objectsToDestroyOwnerValue = (uint)pOVar14->owner;
          param_2->objectsToDestroyCommanderZoneValue = (uint)bVar7;
          goto LAB_004ddd27;
        }
        wallObjects.numberValue = 0;
        wallObjects.desiredNumberValue = 0;
        wallObjects.maximumSizeValue = 0;
        iStack_10 = 0;
        uStack_4 = 0;
        fVar24 = (float10)(*pcVar4)(0,1,param_1,0x1b,&wallObjects.numberValue);
        iVar10 = (**(code **)(iVar10 + 0x1a0))(pOVar14->id,(float)fVar24);
        if (iVar10 == 1) {
          iVar10 = 0;
          param_2->numberObjectsToDestroyValue = 0;
          if (0 < wallObjects.desiredNumberValue) {
            do {
              if (iStack_10 + -1 < iVar10) {
                pvVar17 = operator_new(iVar10 * 4 + 4);
                if (pvVar17 != (void *)0x0) {
                  iVar15 = 0;
                  if (0 < iStack_10) {
                    do {
                      if (iVar10 + 1 <= iVar15) break;
                      iVar15 = iVar15 + 1;
                      *(undefined4 *)((int)pvVar17 + iVar15 * 4 + -4) =
                           *(undefined4 *)(wallObjects.numberValue + -4 + iVar15 * 4);
                    } while (iVar15 < iStack_10);
                  }
                  operator_delete((void *)wallObjects.numberValue);
                  wallObjects.numberValue = (int)pvVar17;
                  iStack_10 = iVar10 + 1;
                }
              }
              pRVar11 = MainDecisionAIModule::object
                                  ((MainDecisionAIModule *)this->md,
                                   *(int *)(wallObjects.numberValue + iVar10 * 4));
              if (pRVar11 != (RGE_Static_Object *)0x0) {
                if (iStack_10 + -1 < iVar10) {
                  pvVar17 = operator_new(iVar10 * 4 + 4);
                  if (pvVar17 != (void *)0x0) {
                    iVar15 = 0;
                    if (0 < iStack_10) {
                      do {
                        if (iVar10 + 1 <= iVar15) break;
                        iVar15 = iVar15 + 1;
                        *(undefined4 *)((int)pvVar17 + iVar15 * 4 + -4) =
                             *(undefined4 *)(wallObjects.numberValue + -4 + iVar15 * 4);
                      } while (iVar15 < iStack_10);
                    }
                    operator_delete((void *)wallObjects.numberValue);
                    wallObjects.numberValue = (int)pvVar17;
                    iStack_10 = iVar10 + 1;
                  }
                }
                addImportantObject(this,*(int *)(wallObjects.numberValue + iVar10 * 4));
                if (iStack_10 + -1 < iVar10) {
                  pvVar17 = operator_new(iVar10 * 4 + 4);
                  if (pvVar17 != (void *)0x0) {
                    iVar15 = 0;
                    if (0 < iStack_10) {
                      do {
                        if (iVar10 + 1 <= iVar15) break;
                        iVar15 = iVar15 + 1;
                        *(undefined4 *)((int)pvVar17 + iVar15 * 4 + -4) =
                             *(undefined4 *)(wallObjects.numberValue + -4 + iVar15 * 4);
                      } while (iVar15 < iStack_10);
                    }
                    operator_delete((void *)wallObjects.numberValue);
                    wallObjects.numberValue = (int)pvVar17;
                    iStack_10 = iVar10 + 1;
                  }
                }
                TacticalAIGroup::addObjectToDestroy
                          (param_2,*(int *)(wallObjects.numberValue + iVar10 * 4));
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 < wallObjects.desiredNumberValue);
          }
          TacticalAIGroup::addObjectToDestroy(param_2,pOVar14->id);
          bVar8 = pOVar14->owner;
          param_2->objectsToDestroyCommanderZoneValue = (uint)bVar7;
          param_2->objectsToDestroyOwnerValue = (uint)bVar8;
          uStack_4 = 0xffffffff;
          if (wallObjects.numberValue != 0) {
            operator_delete((void *)wallObjects.numberValue);
          }
          goto LAB_004ddd27;
        }
        uStack_4 = 0xffffffff;
        if (wallObjects.numberValue != 0) {
          operator_delete((void *)wallObjects.numberValue);
        }
      }
      param_3->bestTargetID = -1;
      param_3->bestTargetValue = -1.0;
      param_3->bestTargetMemoryIndex = -1;
      param_3->iterationIndex = 0;
      param_3->attackGroupID = -1;
      param_3->playID = -1;
      param_3->phase = '\0';
      param_3->bestNonWallTargetID = -1;
      param_3->bestNonWallTargetValue = -1.0;
      param_3->bestNonWallTargetMemoryIndex = -1;
      param_3->active = 1;
    }
    iVar10 = param_3->iterationIndex;
    if (iVar10 < this->maxImportantObjectMemory) {
      iVar15 = iVar10 * 0x24;
      do {
        if ((param_3->iterationIndex < iVar10) &&
           (uVar5 = *(uint *)(*(int *)(this->md->_padding_ + 0x3c) + 0xf8),
           uVar18 = debug_timeGetTime(s_C__msdev_work_age1_x1_taiinfmd_c,0xf5a),
           uVar5 <= uVar18 - param_4)) {
          param_3->iterationIndex = iVar10;
          goto LAB_004ddd25;
        }
        piVar19 = (int *)((int)&this->importantObjectMemory->id + iVar15);
        if (((((uint)*(byte *)((int)piVar19 + 0xb) == param_1) &&
             (pRVar13 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,*piVar19),
             pRVar13 != (RGE_Static_Object *)0x0)) && (pRVar13->object_state < 3)) &&
           ((pRVar13->hp != _DAT_00575580 &&
            ((bVar23 || (iVar16 = isBoat(this,pRVar13), iVar16 != 1)))))) {
          iVar16 = __ftol();
          iVar20 = __ftol();
          bVar8 = RGE_Static_Object::lookupZone(pRVar11,iVar20,iVar16);
          if (((bVar23) ||
              ((*(short *)((int)&this->importantObjectMemory->type + iVar15) != 0x2d ||
               (bVar7 == bVar8)))) &&
             (((param_3->phase != '\0' ||
               (*(short *)((int)&this->importantObjectMemory->group + iVar15) != 0x1b)) &&
              ((param_3->phase != '\x01' ||
               (*(short *)((int)&this->importantObjectMemory->group + iVar15) == 0x1b)))))) {
            pOVar14 = this->importantObjectMemory;
            iVar16 = __ftol();
            iVar20 = (uint)(&pOVar14->x)[iVar15] - iVar16;
            if (iVar20 < 0) {
              iVar20 = -iVar20;
            }
            iVar21 = __ftol();
            iVar22 = (uint)(&pOVar14->y)[iVar15] - iVar21;
            if (iVar22 < 0) {
              iVar22 = -iVar22;
            }
            if (((iVar20 < 6) && (iVar22 < 6)) ||
               (uVar9 = RGE_Visible_Map::get_visible
                                  (*(RGE_Visible_Map **)(this->md->_padding_ + 0x38),iVar16,iVar21),
               uVar9 == '\x0f')) {
              if (sVar2 == 0x12) {
                pUVar12 = RGE_Static_Object::unitAI(pRVar11);
                iVar16 = (**(code **)(pUVar12->_padding_ + 0xc4))
                                   (*(undefined4 *)((int)&this->importantObjectMemory->id + iVar15))
                ;
                if (iVar16 == 0) goto LAB_004ddc98;
              }
              fVar25 = damageInflictedPerSecond(this,param_2,pRVar13);
              fVar27 = pRVar13->hp;
              fVar26 = timeToBeKilled(this,param_2,pRVar13);
              if ((fVar25 != _DAT_00575580) && (fVar26 != _DAT_00575580)) {
                pOVar14 = this->importantObjectMemory;
                iVar16 = __ftol();
                iVar16 = (uint)(&pOVar14->x)[iVar15] - iVar16;
                iVar20 = __ftol();
                iVar20 = (uint)(&pOVar14->y)[iVar15] - iVar20;
                commanderIsPriest = (int)SQRT((float)(iVar16 * iVar16 + iVar20 * iVar20));
                if ((float)commanderIsPriest < _DAT_00575564) {
                  commanderIsPriest = 0x3f800000;
                }
                bVar1 = (&pOVar14->kills)[iVar15];
                iVar16 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x53);
                if (iVar16 < 1) {
                  tempObj = (RGE_Static_Object *)0x0;
                }
                else {
                  iVar16 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x53);
                  iVar20 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0xfd5);
                  tempObj = (RGE_Static_Object *)(float)(iVar20 % iVar16);
                }
                iVar16 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x59);
                wallObjects.value =
                     (int *)((float)iVar16 *
                            (float)*(int *)((int)&this->importantObjectMemory->attackAttempts +
                                           iVar15));
                if (bVar7 == bVar8) {
                    /* language.dll match for 0x7a: "Arial" */
                  iVar16 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x7a);
                  targetRandomization = (float)iVar16;
                }
                else {
                  targetRandomization = 0.0;
                }
                zoneFactor = 0.0;
                iVar16 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xb9);
                if (0 < iVar16) {
                  iVar20 = 0;
                  commanderIsBoat = 0;
                  iVar16 = TacticalAIGroup::numberUnits(param_2);
                  if (0 < iVar16) {
                    do {
                      iVar16 = TacticalAIGroup::unit(param_2,iVar20);
                      this_00 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)this->md,iVar16);
                      if ((this_00 != (RGE_Static_Object *)0x0) &&
                         (pUVar12 = RGE_Static_Object::unitAI(this_00),
                         pUVar12 != (UnitAIModule *)0x0)) {
                        pUVar12 = RGE_Static_Object::unitAI(this_00);
                        iVar16 = UnitAIModule::currentTarget(pUVar12);
                        if (iVar16 == *(int *)((int)&this->importantObjectMemory->id + iVar15)) {
                          commanderIsBoat = commanderIsBoat + 1;
                        }
                      }
                      iVar20 = iVar20 + 1;
                      iVar16 = TacticalAIGroup::numberUnits(param_2);
                    } while (iVar20 < iVar16);
                  }
                  iVar16 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xb9);
                  zoneFactor = (float)iVar16 * (float)commanderIsBoat;
                }
                wonder = (ObjectMemory *)0x0;
                if ((param_3->phase == '\x01') && (param_3->bestNonWallTargetID != -1)) {
                  pOVar14 = this->importantObjectMemory;
                  iVar16 = (uint)(&pOVar14->x)[iVar15] -
                           (uint)pOVar14[param_3->bestNonWallTargetMemoryIndex].x;
                  iVar20 = (uint)(&pOVar14->y)[iVar15] -
                           (uint)pOVar14[param_3->bestNonWallTargetMemoryIndex].y;
                  fVar6 = SQRT((float)(iVar16 * iVar16 + iVar20 * iVar20));
                  if (_DAT_00575564 <= fVar6) {
                    wonder = (ObjectMemory *)(_DAT_0057558c / fVar6);
                  }
                  else {
                    wonder = (ObjectMemory *)0x447a0000;
                  }
                }
                iVar16 = isUnitBuilding(this,pRVar13);
                if (iVar16 == 1) {
                  sVar3 = pRVar13->master_obj->id;
                  fVar6 = _DAT_00575594;
                  if ((sVar3 != 0x6d) && (sVar3 != 0x2d)) {
                    fVar6 = _DAT_00575590;
                  }
                  wonder = (ObjectMemory *)((float)wonder - fVar6);
                }
                iVar16 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x50);
                iVar20 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x4d);
                iVar21 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xb8);
                fVar27 = (float)iVar21 * (fVar26 / (fVar27 / fVar25)) +
                         (float)iVar20 / (float)commanderIsPriest + (float)iVar16 * (float)bVar1 +
                         (float)wonder + zoneFactor + targetRandomization + (float)wallObjects.value
                         + (float)tempObj;
                if ((param_3->bestTargetID == -1) || (param_3->bestTargetValue < fVar27)) {
                  if ((param_3->phase == '\0') &&
                     (fVar24 = (float10)(**(code **)(pRVar13->_padding_ + 0xfc))(),
                     fVar24 == (float10)_DAT_00575580)) {
                    param_3->bestNonWallTargetID =
                         *(int *)((int)&this->importantObjectMemory->id + iVar15);
                    param_3->bestNonWallTargetMemoryIndex = iVar10;
                    param_3->bestNonWallTargetValue = fVar27;
                  }
                  wallObjects.numberValue = 0;
                  wallObjects.value = (int *)((-(uint)(param_3->phase != '\0') & 0xffffffe4) + 0x1b)
                  ;
                  wallObjects.desiredNumberValue = 0;
                  wallObjects.maximumSizeValue = 0;
                  iStack_10 = 0;
                  uStack_4 = 1;
                  if (bVar7 == bVar8) {
                    iVar16 = pRVar11->_padding_;
                    pcVar4 = *(code **)(iVar16 + 0x10c);
                    fVar24 = (float10)(*pcVar4)(0,1,0xffffffff,0xffffffff);
                    iVar20 = (**(code **)(iVar16 + 0x194))
                                       (*(undefined4 *)
                                         ((int)&this->importantObjectMemory->id + iVar15),
                                        (float)fVar24);
                    if (iVar20 == 1) goto LAB_004ddaa8;
                    fVar24 = (float10)(*pcVar4)(0,1,param_1,wallObjects.value,
                                                &wallObjects.numberValue);
                    iVar16 = (**(code **)(iVar16 + 0x1a0))
                                       (*(undefined4 *)
                                         ((int)&this->importantObjectMemory->id + iVar15),
                                        (float)fVar24);
                    if (iVar16 == 1) goto LAB_004ddaa8;
                  }
                  else {
LAB_004ddaa8:
                    iVar16 = 0;
                    param_2->numberObjectsToDestroyValue = 0;
                    if (0 < wallObjects.desiredNumberValue) {
                      do {
                        if (iStack_10 + -1 < iVar16) {
                          pvVar17 = operator_new(iVar16 * 4 + 4);
                          if (pvVar17 != (void *)0x0) {
                            iVar20 = 0;
                            if (0 < iStack_10) {
                              do {
                                if (iVar16 + 1 <= iVar20) break;
                                iVar20 = iVar20 + 1;
                                *(undefined4 *)((int)pvVar17 + iVar20 * 4 + -4) =
                                     *(undefined4 *)(wallObjects.numberValue + -4 + iVar20 * 4);
                              } while (iVar20 < iStack_10);
                            }
                            operator_delete((void *)wallObjects.numberValue);
                            wallObjects.numberValue = (int)pvVar17;
                            iStack_10 = iVar16 + 1;
                          }
                        }
                        pRVar13 = MainDecisionAIModule::object
                                            ((MainDecisionAIModule *)this->md,
                                             *(int *)(wallObjects.numberValue + iVar16 * 4));
                        if (pRVar13 != (RGE_Static_Object *)0x0) {
                          if (iStack_10 + -1 < iVar16) {
                            pvVar17 = operator_new(iVar16 * 4 + 4);
                            if (pvVar17 != (void *)0x0) {
                              iVar20 = 0;
                              if (0 < iStack_10) {
                                do {
                                  if (iVar16 + 1 <= iVar20) break;
                                  iVar20 = iVar20 + 1;
                                  *(undefined4 *)((int)pvVar17 + iVar20 * 4 + -4) =
                                       *(undefined4 *)(wallObjects.numberValue + -4 + iVar20 * 4);
                                } while (iVar20 < iStack_10);
                              }
                              operator_delete((void *)wallObjects.numberValue);
                              wallObjects.numberValue = (int)pvVar17;
                              iStack_10 = iVar16 + 1;
                            }
                          }
                          addImportantObject(this,*(int *)(wallObjects.numberValue + iVar16 * 4));
                          if (iStack_10 + -1 < iVar16) {
                            pvVar17 = operator_new(iVar16 * 4 + 4);
                            if (pvVar17 != (void *)0x0) {
                              iVar20 = 0;
                              if (0 < iStack_10) {
                                do {
                                  if (iVar16 + 1 <= iVar20) break;
                                  iVar20 = iVar20 + 1;
                                  *(undefined4 *)((int)pvVar17 + iVar20 * 4 + -4) =
                                       *(undefined4 *)(wallObjects.numberValue + -4 + iVar20 * 4);
                                } while (iVar20 < iStack_10);
                              }
                              operator_delete((void *)wallObjects.numberValue);
                              wallObjects.numberValue = (int)pvVar17;
                              iStack_10 = iVar16 + 1;
                            }
                          }
                          TacticalAIGroup::addObjectToDestroy
                                    (param_2,*(int *)(wallObjects.numberValue + iVar16 * 4));
                        }
                        iVar16 = iVar16 + 1;
                      } while (iVar16 < wallObjects.desiredNumberValue);
                    }
                    TacticalAIGroup::addObjectToDestroy
                              (param_2,*(int *)((int)&this->importantObjectMemory->id + iVar15));
                    bVar8 = (&this->importantObjectMemory->owner)[iVar15];
                    param_2->objectsToDestroyCommanderZoneValue = (uint)bVar7;
                    param_2->objectsToDestroyOwnerValue = (uint)bVar8;
                    param_3->bestTargetID = *(int *)((int)&this->importantObjectMemory->id + iVar15)
                    ;
                    param_3->bestTargetMemoryIndex = iVar10;
                    param_3->bestTargetValue = fVar27;
                  }
                  uStack_4 = 0xffffffff;
                  if (wallObjects.numberValue != 0) {
                    operator_delete((void *)wallObjects.numberValue);
                    wallObjects.numberValue = 0;
                  }
                  wallObjects.desiredNumberValue = 0;
                  wallObjects.maximumSizeValue = 0;
                }
              }
            }
          }
        }
LAB_004ddc98:
        iVar10 = iVar10 + 1;
        iVar15 = iVar15 + 0x24;
      } while (iVar10 < this->maxImportantObjectMemory);
    }
    if (param_3->bestTargetID != -1) {
      iVar10 = 0;
      this->importantObjectMemory[param_3->bestTargetMemoryIndex].attackAttempts =
           this->importantObjectMemory[param_3->bestTargetMemoryIndex].attackAttempts + 1;
      param_3->active = 0;
LAB_004ddcee:
      iVar10 = TacticalAIGroup::objectToDestroy(param_2,iVar10);
      pOVar14 = objectMemory(this,iVar10);
      goto LAB_004ddd27;
    }
    if (param_3->phase == '\0') {
      param_3->phase = '\x01';
      param_3->iterationIndex = 0;
    }
    else {
      param_3->active = 0;
    }
  }
LAB_004ddd25:
  pOVar14 = (ObjectMemory *)0x0;
LAB_004ddd27:
  *unaff_FS_OFFSET = local_c;
  return pOVar14;
}

// --------------------------------------------------

// Function: objectToAttackByGroup2
// Address: 004ddd40
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
/* WARNING: Variable defined which should be unmapped: commanderZone */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: struct ObjectMemory * __thiscall TribeInformationAIModule::objectToAttackByGroup2(int,int
   *,int) */

ObjectMemory * __thiscall
TribeInformationAIModule::objectToAttackByGroup2
          (TribeInformationAIModule *this,int param_1,int *param_2,int param_3)
{
  float fVar1;
  byte bVar2;
  short sVar3;
  uchar uVar4;
  uchar uVar5;
  ObjectMemory *pOVar6;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar7;
  RGE_Static_Object *pRVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  float fVar15;
  float fVar16;
  uchar commanderZone;
  RGE_Static_Object *commanderObj;
  int inProgressCount;
  float targetDistance;
  ObjectMemory *bestObject;
  int commanderIsPriest;
  float inProgressFactor;
  float zoneFactor;
  float targetRandomization;
  float bestAttackValue;
  int i;
  float timeTK;
  float timeKillRatio;
  float killsByTarget;
  float attackAttemptFactor;
  
  pOVar6 = wonderToAttack(this,-1);
  if (pOVar6 == (ObjectMemory *)0x0) {
    if (((param_3 != 0) &&
        (this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,*param_2),
        this_00 != (RGE_Static_Object *)0x0)) &&
       (pUVar7 = RGE_Static_Object::unitAI(this_00), pUVar7 != (UnitAIModule *)0x0)) {
      uVar4 = RGE_Static_Object::currentZone(this_00);
      sVar3 = this_00->master_obj->object_group;
      commanderIsPriest = 0;
      i = -0x40800000;
      timeTK = 0.0;
      if (0 < this->maxImportantObjectMemory) {
        commanderObj = (RGE_Static_Object *)0x0;
        do {
          piVar14 = (int *)((int)&commanderObj->_padding_ + (int)&this->importantObjectMemory->id);
          if ((((uint)*(byte *)((int)piVar14 + 0xb) == param_1) &&
              (pRVar8 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,*piVar14),
              pRVar8 != (RGE_Static_Object *)0x0)) &&
             ((pRVar8->object_state < 3 && (pRVar8->hp != _DAT_00575580)))) {
            pOVar6 = this->importantObjectMemory;
            iVar9 = __ftol();
            iVar13 = (uint)(&pOVar6->x)[(int)&commanderObj->_padding_] - iVar9;
            if (iVar13 < 0) {
              iVar13 = -iVar13;
            }
            iVar10 = __ftol();
            iVar12 = (uint)(&pOVar6->y)[(int)&commanderObj->_padding_] - iVar10;
            if (iVar12 < 0) {
              iVar12 = -iVar12;
            }
            if (((iVar13 < 6) && (iVar12 < 6)) ||
               (uVar5 = RGE_Visible_Map::get_visible
                                  (*(RGE_Visible_Map **)(this->md->_padding_ + 0x38),iVar9,iVar10),
               uVar5 == '\x0f')) {
              if (sVar3 == 0x12) {
                pUVar7 = RGE_Static_Object::unitAI(this_00);
                iVar9 = (**(code **)(pUVar7->_padding_ + 0xc4))
                                  (*(undefined4 *)
                                    ((int)&this->importantObjectMemory->id +
                                    (int)&commanderObj->_padding_));
                if (iVar9 == 0) goto LAB_004de1b4;
              }
              fVar15 = damageInflictedPerSecond(this,param_2,param_3,pRVar8);
              fVar1 = pRVar8->hp;
              fVar16 = timeToBeKilled(this,param_2,param_3,pRVar8);
              if ((fVar15 != _DAT_00575580) && (fVar16 != _DAT_00575580)) {
                pOVar6 = this->importantObjectMemory;
                piVar14 = &commanderObj->_padding_;
                iVar9 = __ftol();
                iVar9 = (uint)(&pOVar6->x)[(int)piVar14] - iVar9;
                iVar13 = __ftol();
                iVar13 = (uint)(&pOVar6->y)[(int)piVar14] - iVar13;
                bestObject = (ObjectMemory *)SQRT((float)(iVar9 * iVar9 + iVar13 * iVar13));
                if ((float)bestObject < _DAT_00575564) {
                  bestObject = (ObjectMemory *)0x3f800000;
                }
                bVar2 = (&pOVar6->kills)[(int)piVar14];
                iVar9 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x53);
                if (iVar9 < 1) {
                  bestAttackValue = 0.0;
                }
                else {
                  iVar9 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x53);
                  iVar13 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x110b);
                  bestAttackValue = (float)(iVar13 % iVar9);
                }
                iVar13 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x59);
                iVar9 = *(int *)((int)&commanderObj->sprite + (int)this->importantObjectMemory);
                iVar10 = __ftol();
                iVar12 = __ftol();
                uVar5 = RGE_Static_Object::lookupZone(this_00,iVar12,iVar10);
                if (uVar4 == uVar5) {
                    /* language.dll match for 0x7a: "Arial" */
                  iVar10 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x7a);
                  targetRandomization = (float)iVar10;
                }
                else {
                  targetRandomization = 0.0;
                }
                zoneFactor = 0.0;
                iVar10 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xb9);
                if (0 < iVar10) {
                  targetDistance = 0.0;
                  if (0 < param_3) {
                    zoneFactor = (float)param_3;
                    piVar14 = param_2;
                    do {
                      pRVar8 = MainDecisionAIModule::object
                                         ((MainDecisionAIModule *)this->md,*piVar14);
                      if ((pRVar8 != (RGE_Static_Object *)0x0) &&
                         (pUVar7 = RGE_Static_Object::unitAI(pRVar8), pUVar7 != (UnitAIModule *)0x0)
                         ) {
                        pUVar7 = RGE_Static_Object::unitAI(pRVar8);
                        iVar10 = UnitAIModule::currentTarget(pUVar7);
                        if (iVar10 == *(int *)((int)&this->importantObjectMemory->id +
                                              (int)&commanderObj->_padding_)) {
                          targetDistance = (float)((int)targetDistance + 1);
                        }
                      }
                      piVar14 = piVar14 + 1;
                      zoneFactor = (float)((int)zoneFactor + -1);
                    } while (zoneFactor != 0.0);
                  }
                  iVar10 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xb9);
                  zoneFactor = (float)iVar10 * (float)(int)targetDistance;
                }
                iVar10 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xb8);
                iVar12 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x4d);
                iVar11 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x50);
                fVar1 = (float)iVar11 * (float)bVar2 +
                        (float)iVar12 / (float)bestObject +
                        (float)iVar10 * (fVar16 / (fVar1 / fVar15)) + zoneFactor +
                        targetRandomization + (float)iVar13 * (float)iVar9 + bestAttackValue;
                if ((commanderIsPriest == 0) || ((float)i < fVar1)) {
                  commanderIsPriest =
                       (int)&this->importantObjectMemory->id + (int)&commanderObj->_padding_;
                  i = (int)fVar1;
                }
              }
            }
          }
LAB_004de1b4:
          timeTK = (float)((int)timeTK + 1);
          commanderObj = (RGE_Static_Object *)&commanderObj->objects;
        } while ((int)timeTK < this->maxImportantObjectMemory);
      }
      return (ObjectMemory *)commanderIsPriest;
    }
    pOVar6 = (ObjectMemory *)0x0;
  }
  return pOVar6;
}

// --------------------------------------------------

// Function: objectToDefend
// Address: 004de1f0
/* WARNING: Variable defined which should be unmapped: bestDefendValue */
/* public: struct ObjectMemory * __thiscall TribeInformationAIModule::objectToDefend(int) */

ObjectMemory * __thiscall
TribeInformationAIModule::objectToDefend(TribeInformationAIModule *this,int param_1)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  TacticalAIGroup *pTVar4;
  int *piVar5;
  int iVar6;
  XYPoint *pXVar7;
  int bestDefendValue;
  int i;
  XYPoint objPoint;
  
  pRVar1 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  iVar6 = 0;
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return (ObjectMemory *)0x0;
  }
  param_1 = 0;
  i = -1;
  objPoint.x = 0;
  if (0 < this->maxImportantObjectMemory) {
    do {
      piVar5 = (int *)((int)&this->importantObjectMemory->id + iVar6);
      if (*piVar5 != -1) {
        iVar3 = (this->itemsToDefend).numberValue;
        iVar2 = 0;
        if (0 < iVar3) {
          while (iVar2 < (this->itemsToDefend).maximumSizeValue) {
            if ((this->itemsToDefend).value[iVar2] == *piVar5) {
              if (piVar5[4] < 1) {
                objPoint.y = (int)*(byte *)(piVar5 + 2);
                iVar2 = -1;
                pXVar7 = (XYPoint *)&objPoint.y;
                iVar3 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x5c);
                pTVar4 = TribeTacticalAIModule::bestGroup
                                   (&this->md->tacticalAI,-1,4,iVar3,pXVar7,iVar2);
                if ((pTVar4 == (TacticalAIGroup *)0x0) &&
                   ((iVar3 = defendPriority(this,(int)*(short *)((int)&this->importantObjectMemory->
                                                                       type + iVar6),
                                            (int)*(short *)((int)&this->importantObjectMemory->group
                                                           + iVar6)), param_1 == 0 || (iVar3 < i))))
{
                  param_1 = (int)&this->importantObjectMemory->id + iVar6;
                  i = iVar3;
                }
              }
              break;
            }
            iVar2 = iVar2 + 1;
            if (iVar3 <= iVar2) break;
          }
        }
      }
      objPoint.x = objPoint.x + 1;
      iVar6 = iVar6 + 0x24;
    } while (objPoint.x < this->maxImportantObjectMemory);
  }
  return (ObjectMemory *)param_1;
}

// --------------------------------------------------

// Function: higherPriorityObjectToDefend
// Address: 004de330
/* WARNING: Variable defined which should be unmapped: bestObject */
/* public: struct ObjectMemory * __thiscall
   TribeInformationAIModule::higherPriorityObjectToDefend(int,int,int) */

ObjectMemory * __thiscall
TribeInformationAIModule::higherPriorityObjectToDefend
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  uchar uVar2;
  uchar uVar3;
  RGE_Static_Object *this_00;
  int iVar4;
  RGE_Static_Object *this_01;
  int iVar5;
  int iVar6;
  float10 fVar7;
  XYPoint *pXVar8;
  ObjectMemory *bestObject;
  RGE_Static_Object *unit;
  XYPoint local_8;
  
  this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  iVar6 = 0;
  if (this_00 == (RGE_Static_Object *)0x0) {
    return (ObjectMemory *)0x0;
  }
  uVar2 = RGE_Static_Object::currentZone(this_00);
  unit = (RGE_Static_Object *)0x0;
  param_3 = defendPriority(this,param_2,param_3);
  param_2 = 0;
  if (0 < this->maxImportantObjectMemory) {
    do {
      iVar5 = *(int *)((int)&this->importantObjectMemory->id + iVar6);
      if (iVar5 != -1) {
        iVar1 = (this->itemsToDefend).numberValue;
        iVar4 = 0;
        if (0 < iVar1) {
          while (iVar4 < (this->itemsToDefend).maximumSizeValue) {
            if ((this->itemsToDefend).value[iVar4] == iVar5) {
              if ((0 < *(int *)((int)&this->importantObjectMemory->attackAttempts + iVar6)) ||
                 (this_01 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar5),
                 this_01 == (RGE_Static_Object *)0x0)) break;
              uVar3 = RGE_Static_Object::currentZone(this_01);
              if (uVar2 != uVar3) {
                local_8.x = __ftol();
                local_8.y = __ftol();
                pXVar8 = &local_8;
                fVar7 = (float10)(**(code **)(this_00->_padding_ + 0x10c))();
                iVar5 = RGE_Static_Object::withinRangeOfZoneAtPoint
                                  (this_00,uVar2,(float)fVar7,pXVar8);
                if (iVar5 != 1) break;
              }
              iVar5 = defendPriority(this,(int)*(short *)((int)&this->importantObjectMemory->type +
                                                         iVar6),
                                     (int)*(short *)((int)&this->importantObjectMemory->group +
                                                    iVar6));
              if (iVar5 < param_3) {
                unit = (RGE_Static_Object *)((int)&this->importantObjectMemory->id + iVar6);
                param_3 = iVar5;
              }
              break;
            }
            iVar4 = iVar4 + 1;
            if (iVar1 <= iVar4) break;
          }
        }
      }
      param_2 = param_2 + 1;
      iVar6 = iVar6 + 0x24;
    } while (param_2 < this->maxImportantObjectMemory);
  }
  return (ObjectMemory *)unit;
}

// --------------------------------------------------

// Function: defendPriority
// Address: 004de4a0
/* public: int __thiscall TribeInformationAIModule::defendPriority(int,int) */

int __thiscall
TribeInformationAIModule::defendPriority(TribeInformationAIModule *this,int param_1,int param_2)
{
  int iVar1;
  
  switch(param_1) {
  case 0x2d:
    iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x46);
    return iVar1;
  case 0x6d:
    iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x38);
    return iVar1;
  case 0x9e:
  case 0xa3:
    iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x36);
    return iVar1;
  case 0x9f:
    iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x37);
    return iVar1;
  }
  if (param_2 == 7) {
    iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x34);
    return iVar1;
  }
  if (param_2 == 8) {
    iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x33);
    return iVar1;
  }
  if (param_2 != 0x20) {
    return -1;
  }
  iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x32);
  return iVar1;
}

// --------------------------------------------------

// Function: checkDefend
// Address: 004de600
/* public: int __thiscall TribeInformationAIModule::checkDefend(class RGE_Static_Object *) */

int __thiscall
TribeInformationAIModule::checkDefend(TribeInformationAIModule *this,RGE_Static_Object *param_1)
{
  short sVar1;
  short sVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  ManagedArray<int> *pMVar6;
  int iVar7;
  
  pRVar3 = param_1;
  sVar1 = param_1->master_obj->object_group;
  sVar2 = param_1->owner->id;
  switch(param_1->master_obj->id) {
  case 0x2d:
    if ((sVar2 == *(short *)(this->md->_padding_ + 0x4a)) &&
       (iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x46), 0 < iVar5)) {
      iVar5 = (this->itemsToDefend).numberValue;
      iVar7 = pRVar3->id;
      iVar4 = 0;
      if (0 < iVar5) {
        do {
          if ((this->itemsToDefend).maximumSizeValue <= iVar4) break;
          if ((this->itemsToDefend).value[iVar4] == iVar7) {
            return 1;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar5);
      }
LAB_004de793:
      if ((this->itemsToDefend).maximumSizeValue + -1 < iVar5) {
        ManagedArray<int>::resize(&this->itemsToDefend,iVar5 + 1);
      }
      (this->itemsToDefend).value[(this->itemsToDefend).numberValue] = iVar7;
      (this->itemsToDefend).numberValue = (this->itemsToDefend).numberValue + 1;
      return 1;
    }
    break;
  default:
    if (sVar1 == 7) {
      iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x34);
      if (0 < iVar5) {
        ManagedArray<int>::add(&this->itemsToDefend,pRVar3->id);
        return 1;
      }
    }
    else if (sVar1 == 8) {
      iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x33);
      if (0 < iVar5) {
        param_1 = (RGE_Static_Object *)pRVar3->id;
        pMVar6 = &this->itemsToDefend;
        iVar5 = ManagedArray<int>::contains(pMVar6,(int *)&param_1);
        if (iVar5 == 1) {
          return 1;
        }
        iVar5 = (this->itemsToDefend).numberValue;
        if ((this->itemsToDefend).maximumSizeValue + -1 < iVar5) {
          ManagedArray<int>::resize(pMVar6,iVar5 + 1);
        }
        pMVar6->value[(this->itemsToDefend).numberValue] = (int)param_1;
        (this->itemsToDefend).numberValue = (this->itemsToDefend).numberValue + 1;
        return 1;
      }
    }
    else if ((sVar1 == 0x20) &&
            (iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x32), 0 < iVar5))
{
      param_1 = (RGE_Static_Object *)pRVar3->id;
      pMVar6 = &this->itemsToDefend;
      iVar5 = ManagedArray<int>::contains(pMVar6,(int *)&param_1);
      if (iVar5 == 1) {
        return 1;
      }
      iVar5 = (this->itemsToDefend).numberValue;
      if ((this->itemsToDefend).maximumSizeValue + -1 < iVar5) {
        ManagedArray<int>::resize(pMVar6,iVar5 + 1);
      }
      pMVar6->value[(this->itemsToDefend).numberValue] = (int)param_1;
      (this->itemsToDefend).numberValue = (this->itemsToDefend).numberValue + 1;
      return 1;
    }
    break;
  case 0x6d:
    if ((sVar2 == *(short *)(this->md->_padding_ + 0x4a)) &&
       (iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x38), 0 < iVar5)) {
      iVar5 = (this->itemsToDefend).numberValue;
      iVar7 = pRVar3->id;
      iVar4 = 0;
      if (0 < iVar5) {
        do {
          if ((this->itemsToDefend).maximumSizeValue <= iVar4) break;
          if ((this->itemsToDefend).value[iVar4] == iVar7) {
            return 1;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar5);
      }
      goto LAB_004de793;
    }
    break;
  case 0x9e:
  case 0xa3:
    iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x36);
    if (0 < iVar5) {
      iVar5 = (this->itemsToDefend).numberValue;
      iVar7 = pRVar3->id;
      iVar4 = 0;
      if (0 < iVar5) {
        do {
          if ((this->itemsToDefend).maximumSizeValue <= iVar4) break;
          if ((this->itemsToDefend).value[iVar4] == iVar7) {
            return 1;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar5);
      }
      goto LAB_004de793;
    }
    break;
  case 0x9f:
    iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x37);
    if (0 < iVar5) {
      iVar5 = (this->itemsToDefend).numberValue;
      iVar7 = pRVar3->id;
      iVar4 = 0;
      if (0 < iVar5) {
        do {
          if ((this->itemsToDefend).maximumSizeValue <= iVar4) break;
          if ((this->itemsToDefend).value[iVar4] == iVar7) {
            return 1;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar5);
      }
      goto LAB_004de793;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: numberItemsToDefend
// Address: 004dea70
/* public: int __thiscall TribeInformationAIModule::numberItemsToDefend(void) */

int __thiscall TribeInformationAIModule::numberItemsToDefend(TribeInformationAIModule *this)
{
  return (this->itemsToDefend).numberValue;
}

// --------------------------------------------------

// Function: objectToTradeWith
// Address: 004dea80
/* WARNING: Variable defined which should be unmapped: unit */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: struct ObjectMemory * __thiscall TribeInformationAIModule::objectToTradeWith(int) */

ObjectMemory * __thiscall
TribeInformationAIModule::objectToTradeWith(TribeInformationAIModule *this,int param_1)
{
  ObjectMemory *pOVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  RGE_Static_Object *unit;
  int bestDockDistance;
  int i;
  int local_4;
  
  pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  iVar6 = 0;
  if (pRVar3 != (RGE_Static_Object *)0x0) {
    param_1 = 0;
    i = 0;
    local_4 = 0;
    if (0 < this->maxImportantObjectMemory) {
      do {
        pOVar1 = this->importantObjectMemory;
        iVar2 = *(int *)((int)&pOVar1->id + iVar6);
        if ((((iVar2 != -1) &&
             ((ushort)(&pOVar1->owner)[iVar6] != ((RGE_Player *)this->md->_padding_)->id)) &&
            (*(short *)((int)&pOVar1->type + iVar6) == 0x2d)) &&
           ((pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar2),
            pRVar3 != (RGE_Static_Object *)0x0 && (_DAT_00575580 < pRVar3->owner->attributes[9]))))
{
          iVar2 = (int)&this->importantObjectMemory->id + iVar6;
          iVar4 = __ftol();
          iVar4 = (uint)*(byte *)(iVar2 + 8) - iVar4;
          iVar5 = __ftol();
          iVar5 = (uint)*(byte *)(iVar2 + 9) - iVar5;
          iVar4 = iVar4 * iVar4 + iVar5 * iVar5;
          if ((param_1 == 0) || (iVar4 < i)) {
            param_1 = iVar2;
            i = iVar4;
          }
        }
        local_4 = local_4 + 1;
        iVar6 = iVar6 + 0x24;
      } while (local_4 < this->maxImportantObjectMemory);
    }
    return (ObjectMemory *)param_1;
  }
  return (ObjectMemory *)0x0;
}

// --------------------------------------------------

// Function: findGatherPosition
// Address: 004deba0
/* WARNING: Variable defined which should be unmapped: bestPointValue */
/* public: int __thiscall TribeInformationAIModule::findGatherPosition(struct XYPoint
   &,int,int,int,int,class RGE_Static_Object *,struct XYPoint &) */

int __thiscall
TribeInformationAIModule::findGatherPosition
          (TribeInformationAIModule *this,XYPoint *param_1,int param_2,int param_3,int param_4,
          int param_5,RGE_Static_Object *param_6,XYPoint *param_7)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int bestPointValue;
  int j;
  int i;
  int clearDistance;
  XYPoint maxClear;
  XYPoint max;
  XYPoint minClear;
  XYPoint min;
  XYPoint minExclude;
  XYPoint maxExclude;
  XYPoint cPosition;
  XYPoint lineCollisionPoint;
  
  if (param_4 <= param_5) {
    return 0;
  }
  minExclude.x = (param_1->y - param_4) - param_5;
  min.y = (param_1->x - param_4) - param_5;
  mapBound(this,(XYPoint *)&min.y);
  minClear.x = param_5 + param_4 + param_1->y;
  max.y = param_1->x + param_5 + param_4;
  mapBound(this,(XYPoint *)&max.y);
  minExclude.y = (param_1->x - param_4) + param_5;
  maxExclude.x = (param_5 - param_4) + param_1->y;
  mapBound(this,(XYPoint *)&minExclude.y);
  maxExclude.y = (param_1->x - param_5) + param_4;
  cPosition.x = (param_4 - param_5) + param_1->y;
  mapBound(this,(XYPoint *)&maxExclude.y);
  setupInfluenceMap(this,0,-1,param_1,(XYPoint *)&min.y,(XYPoint *)&max.y);
  j = -1;
  maxClear.x = groupInfluenceDimension(this,param_2);
  iVar3 = min.y;
  if (min.y <= max.y) {
    do {
      iVar7 = minExclude.x;
      if (minExclude.x <= minClear.x) {
        do {
          if ((((iVar3 < minExclude.y) || (maxExclude.y < iVar3)) || (iVar7 < maxExclude.x)) ||
             (cPosition.x < iVar7)) {
            iVar4 = maxClear.x / 2;
            minClear.y = iVar3 - iVar4;
            min.x = iVar7 - iVar4;
            iVar2 = mapBound(this,(XYPoint *)&minClear.y);
            if (iVar2 != 1) {
              maxClear.y = iVar3 + iVar4;
              max.x = iVar7 + iVar4;
              iVar2 = mapBound(this,(XYPoint *)&maxClear.y);
              if (iVar2 != 1) {
                bVar1 = false;
                iVar2 = max.x;
                iVar4 = minClear.y;
                if (minClear.y < maxClear.y) {
                  do {
                    if (bVar1) break;
                    iVar5 = min.x;
                    if (min.x < iVar2) {
                      do {
                        if (bVar1) break;
                        iVar2 = (**(code **)(param_6->_padding_ + 0x114))
                                          ((float)iVar4,(float)iVar5,1);
                        if (iVar2 == 0) {
                          bVar1 = true;
                        }
                        iVar5 = iVar5 + 1;
                        iVar2 = max.x;
                      } while (iVar5 < max.x);
                    }
                    iVar4 = iVar4 + 1;
                  } while (iVar4 < maxClear.y);
                }
                if (!bVar1) {
                    /* language.dll match for 0x80: "Arial" */
                  iVar4 = 0x80;
                  cPosition.y = iVar3;
                  lineCollisionPoint.x = iVar7;
                  iVar2 = (**(code **)(param_6->_padding_ + 0x1b0))
                                    (&cPosition.y,param_1,(float)param_4,&lineCollisionPoint.y,1);
                  if (iVar2 == 0) {
                    iVar4 = 0x40;
                  }
                  iVar2 = max.x;
                  iVar5 = minClear.y;
                  if (minClear.y <= maxClear.y) {
                    do {
                      if (bVar1) break;
                      iVar6 = min.x;
                      if (min.x <= iVar2) {
                        do {
                          if (bVar1) break;
                          iVar2 = InfluenceMap::lookupValue(&iMap,iVar5,iVar6);
                          if (iVar2 == 0xff) {
                            bVar1 = true;
                          }
                          else {
                            iVar4 = iVar4 + iVar2;
                          }
                          iVar6 = iVar6 + 1;
                          iVar2 = max.x;
                        } while (iVar6 <= max.x);
                      }
                      iVar5 = iVar5 + 1;
                    } while (iVar5 <= maxClear.y);
                  }
                  if ((!bVar1) && ((j == -1 || (j < iVar4)))) {
                    param_7->x = iVar3;
                    param_7->y = iVar7;
                    j = iVar4;
                  }
                }
              }
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 <= minClear.x);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= max.y);
  }
  return (uint)(j != -1);
}

// --------------------------------------------------

// Function: setupInfluenceMap
// Address: 004dee90
// [HELPER] s_____Unsupported_building_size___: "    Unsupported building size (%d x %d)."
/* WARNING: Variable defined which should be unmapped: bXRadius */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TribeInformationAIModule::setupInfluenceMap(int,int,struct XYPoint
   &,struct XYPoint &,struct XYPoint &) */

void __thiscall
TribeInformationAIModule::setupInfluenceMap
          (TribeInformationAIModule *this,int param_1,int param_2,XYPoint *param_3,XYPoint *param_4,
          XYPoint *param_5)
{
  short sVar1;
  float fVar2;
  RGE_Map *this_00;
  AttackMemory *pAVar3;
  BuildingLot *pBVar4;
  uchar uVar5;
  RGE_Static_Object *pRVar6;
  int *piVar7;
  int iVar8;
  AIModule *this_01;
  int iVar9;
  int iVar10;
  int iVar11;
  ResourceMemory **ppRVar12;
  int iVar13;
  undefined8 uVar14;
  float bXRadius;
  int buildingCode;
  int a;
  XYPoint bMaxLOS_ffffff98;
  uchar terrainType;
  XYPoint bMin;
  XYPoint bMax;
  XYPoint bMinLOS_ffffffb4;
  XYPoint bMaxLOS;
  XYPoint bMinLOS;
  XYPoint bMaxLOS_ffffffcc;
  XYPoint bMinLOS_ffffffd4;
  XYPoint aMin;
  XYPoint aMax;
  XYPoint max;
  XYPoint min;
  
  InfluenceMap::initialize(&iMap,'\x14');
  InfluenceMap::setUnchangeableLimit(&iMap,0xff);
  iVar11 = 0;
  BuildAIModule::numberBuiltItemsOfType((BuildAIModule *)&this->md->buildAI,0x44,0);
                    /* language.dll match for 0x67: "Comic Sans MS" */
  BuildAIModule::numberBuiltItemsOfType((BuildAIModule *)&this->md->buildAI,0x67,0);
  iVar9 = this->mapXSizeValue;
  iVar10 = this->mapYSizeValue;
  min.y = 0;
  max.y = iVar9;
  min.x = iVar10;
  if (((param_1 == 3) || (param_1 == 4)) || (param_1 == 0)) {
    max.x = iVar10 + -5;
    iVar8 = iVar9 + -5;
    if (0 < iVar9) {
      do {
        iVar13 = 0;
        if (0 < iVar10) {
          do {
            if (((iVar11 < 5) || (iVar8 < iVar11)) || ((iVar13 < 5 || (max.x < iVar13)))) {
              InfluenceMap::decrementValue(&iMap,iVar11,iVar13,'\n');
              iVar10 = min.x;
            }
            iVar13 = iVar13 + 1;
            iVar9 = max.y;
          } while (iVar13 < iVar10);
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < iVar9);
    }
  }
  if (((param_1 == 1) || (param_1 == 2)) || (param_1 == 9)) {
    bMin.x = resourceTypeToPlaceDropsiteBy(this,param_1);
    ppRVar12 = this->resources;
    bMaxLOS_ffffff98.y = 4;
    do {
      bMaxLOS_ffffff98.x = 0;
      if (0 < (int)ppRVar12[4]) {
        buildingCode = 0;
        do {
          piVar7 = (int *)((int)&(*ppRVar12)->id + buildingCode);
          if ((*(char *)((int)piVar7 + 0xd) == '\x01') ||
             (pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,*piVar7),
             pRVar6 == (RGE_Static_Object *)0x0)) goto LAB_004df33a;
          bMax.y = __ftol();
          bMinLOS_ffffffb4.x = __ftol();
          mapBound(this,(XYPoint *)&bMax.y);
          bMin.y = __ftol();
          bMax.x = __ftol();
          mapBound(this,(XYPoint *)&bMin.y);
          bMinLOS.y = __ftol();
          bMaxLOS_ffffffcc.x = __ftol();
          mapBound(this,(XYPoint *)&bMinLOS.y);
          if ((param_1 == 1) || (param_1 == 2)) {
            InfluenceMap::setValue(&iMap,bMinLOS.y,bMaxLOS_ffffffcc.x,0xff);
          }
          else {
            InfluenceMap::setValue(&iMap,bMax.y,bMinLOS_ffffffb4.x,bMin.y,bMax.x,0xff);
          }
          if (param_1 == 1) {
            sVar1 = pRVar6->master_obj->object_group;
            if (sVar1 == 7) {
              if (pRVar6->master_obj->object_group != 7) goto LAB_004df2c3;
              bMax.y = bMax.y + -5;
              bMinLOS_ffffffb4.x = bMinLOS_ffffffb4.x + -5;
              mapBound(this,(XYPoint *)&bMax.y);
              bMin.y = bMin.y + 5;
              bMax.x = bMax.x + 5;
              mapBound(this,(XYPoint *)&bMin.y);
                    /* language.dll match for 0x80: "Arial" */
              InfluenceMap::decrementValue(&iMap,bMax.y,bMinLOS_ffffffb4.x,bMin.y,bMax.x,0x80);
            }
            else if ((((bMin.x == -1) || ((bMin.x == 3 && (sVar1 == 0x20)))) ||
                     ((bMin.x == 2 && (sVar1 == 8)))) ||
                    (((bMin.x == 1 && (sVar1 == 0xf)) ||
                     ((bMin.x == 0 && (((sVar1 != 0x20 && (sVar1 != 8)) && (sVar1 != 0xf)))))))) {
              bMax.y = bMax.y + -1;
              bMinLOS_ffffffb4.x = bMinLOS_ffffffb4.x + -1;
              mapBound(this,(XYPoint *)&bMax.y);
              bMin.y = bMin.y + 1;
              bMax.x = bMax.x + 1;
              mapBound(this,(XYPoint *)&bMin.y);
              InfluenceMap::incrementValue(&iMap,bMax.y,bMinLOS_ffffffb4.x,bMin.y,bMax.x,'\b');
              bMax.y = bMax.y + -3;
              bMinLOS_ffffffb4.x = bMinLOS_ffffffb4.x + -3;
              mapBound(this,(XYPoint *)&bMax.y);
              bMin.y = bMin.y + 3;
              bMax.x = bMax.x + 3;
              mapBound(this,(XYPoint *)&bMin.y);
              InfluenceMap::incrementValue(&iMap,bMax.y,bMinLOS_ffffffb4.x,bMin.y,bMax.x,'\x04');
              bMax.y = bMax.y + -5;
              bMinLOS_ffffffb4.x = bMinLOS_ffffffb4.x + -5;
              mapBound(this,(XYPoint *)&bMax.y);
              bMin.y = bMin.y + 5;
              bMax.x = bMax.x + 5;
              mapBound(this,(XYPoint *)&bMin.y);
              uVar14 = CONCAT44(2,bMax.x);
              goto LAB_004df330;
            }
          }
          else {
LAB_004df2c3:
            if ((param_1 == 2) && (pRVar6->master_obj->object_group == 7)) {
              bMax.y = bMax.y + -3;
              bMinLOS_ffffffb4.x = bMinLOS_ffffffb4.x + -3;
              mapBound(this,(XYPoint *)&bMax.y);
              bMin.y = bMin.y + 3;
              bMax.x = bMax.x + 3;
              mapBound(this,(XYPoint *)&bMin.y);
                    /* language.dll match for 0x80: "Arial" */
              uVar14 = CONCAT44(0x80,bMax.x);
LAB_004df330:
              InfluenceMap::incrementValue
                        (&iMap,bMax.y,bMinLOS_ffffffb4.x,bMin.y,(int)uVar14,
                         (uchar)((ulonglong)uVar14 >> 0x20));
            }
          }
LAB_004df33a:
          bMaxLOS_ffffff98.x = bMaxLOS_ffffff98.x + 1;
          buildingCode = buildingCode + 0x14;
        } while (bMaxLOS_ffffff98.x < (int)ppRVar12[4]);
      }
      ppRVar12 = ppRVar12 + 1;
      bMaxLOS_ffffff98.y = bMaxLOS_ffffff98.y + -1;
    } while (bMaxLOS_ffffff98.y != 0);
    bMaxLOS_ffffff98.y = 0;
  }
  if (((((param_1 == 1) || (param_1 == 2)) ||
       (((param_1 == 3 || ((param_1 == 4 || (param_1 == 0)))) || (param_1 == 5)))) ||
      ((param_1 == 6 || (param_1 == 8)))) &&
     (bMaxLOS_ffffff98.x = 0, 0 < (this->playerBuildings).numberValue)) {
    do {
      iVar9 = bMaxLOS_ffffff98.x;
      if ((this->playerBuildings).maximumSizeValue + -1 < bMaxLOS_ffffff98.x) {
        iVar10 = bMaxLOS_ffffff98.x + 1;
        piVar7 = (int *)operator_new(bMaxLOS_ffffff98.x * 4 + 4);
        if (piVar7 != (int *)0x0) {
          iVar11 = 0;
          if (0 < (this->playerBuildings).maximumSizeValue) {
            do {
              if (iVar10 <= iVar11) break;
              iVar8 = iVar11 + 1;
              piVar7[iVar11] = (this->playerBuildings).value[iVar11];
              iVar11 = iVar8;
            } while (iVar8 < (this->playerBuildings).maximumSizeValue);
          }
          operator_delete((this->playerBuildings).value);
          (this->playerBuildings).value = piVar7;
          (this->playerBuildings).maximumSizeValue = iVar10;
        }
      }
      pRVar6 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)this->md,(this->playerBuildings).value[iVar9]);
      if (pRVar6 != (RGE_Static_Object *)0x0) {
        this_01 = (AIModule *)placementCode(this,(int)pRVar6->master_obj->id);
        fVar2 = pRVar6->master_obj->radius_x;
        bMin.x = (int)pRVar6->master_obj->radius_y;
        if (fVar2 == (float)_DAT_00575598) {
LAB_004df4ad:
          iVar9 = __ftol();
          iVar9 = iVar9 + -3;
          bMin.y = iVar9;
          iVar10 = __ftol();
          iVar10 = iVar10 + -3;
          bMax.x = iVar10;
          iVar11 = __ftol();
          bMax.y = iVar11 + 3;
          iVar11 = __ftol();
          bMinLOS_ffffffb4.x = iVar11 + 3;
        }
        else if (fVar2 == (float)_DAT_005755a0) {
          if (this_01 == (AIModule *)0x6) {
LAB_004df5bc:
            iVar9 = __ftol();
            iVar9 = iVar9 + -1;
            bMin.y = iVar9;
            iVar10 = __ftol();
            iVar10 = iVar10 + -1;
            bMax.x = iVar10;
            iVar11 = __ftol();
            bMax.y = iVar11 + 1;
            iVar11 = __ftol();
            bMinLOS_ffffffb4.x = iVar11 + 1;
          }
          else {
            if (param_2 == 0x46) goto LAB_004df4ad;
            iVar9 = __ftol();
            iVar9 = iVar9 + -2;
            bMin.y = iVar9;
            iVar10 = __ftol();
            iVar10 = iVar10 + -2;
            bMax.x = iVar10;
            iVar11 = __ftol();
            bMax.y = iVar11 + 2;
            iVar11 = __ftol();
            bMinLOS_ffffffb4.x = iVar11 + 2;
          }
        }
        else {
          if (fVar2 == _DAT_00575564) {
            if ((this_01 != (AIModule *)0x6) && (this_01 != (AIModule *)&DAT_00000003)) {
              iVar9 = __ftol();
              iVar9 = iVar9 + -2;
              bMin.y = iVar9;
              iVar10 = __ftol();
              iVar10 = iVar10 + -2;
              bMax.x = iVar10;
              iVar11 = __ftol();
              bMax.y = iVar11 + 1;
              iVar11 = __ftol();
              bMinLOS_ffffffb4.x = iVar11 + 1;
              goto LAB_004df622;
            }
            iVar9 = __ftol();
            iVar9 = iVar9 + -1;
            bMin.y = iVar9;
            iVar10 = __ftol();
            iVar10 = iVar10 + -1;
          }
          else {
            if (fVar2 != (float)_DAT_005755a8) {
              AIModule::logCommonHistory
                        (this_01,(char *)this,s_____Unsupported_building_size___,
                         (double)(fVar2 + fVar2),(double)((float)bMin.x + (float)bMin.x));
              goto LAB_004df9fb;
            }
            if ((this_01 != (AIModule *)0x6) && (this_01 != (AIModule *)0x4)) goto LAB_004df5bc;
            iVar9 = __ftol();
            bMin.y = iVar9;
            iVar10 = __ftol();
          }
          bMax.x = iVar10;
          bMax.y = __ftol();
          bMinLOS_ffffffb4.x = __ftol();
        }
LAB_004df622:
        if (this_01 == (AIModule *)0x6d) {
          bMin.y = iVar9 + -1;
          bMax.x = iVar10 + -1;
          bMax.y = bMax.y + 1;
          bMinLOS_ffffffb4.x = bMinLOS_ffffffb4.x + 1;
        }
        mapBound(this,(XYPoint *)&bMin.y);
        mapBound(this,(XYPoint *)&bMax.y);
        InfluenceMap::setValue(&iMap,bMin.y,bMax.x,bMax.y,bMinLOS_ffffffb4.x,0xff);
        if ((param_1 == 3) || (param_1 == 0)) {
          iVar9 = __ftol();
          bMinLOS.y = bMin.y - iVar9;
          bMaxLOS_ffffffcc.x = bMax.x - iVar9;
          mapBound(this,(XYPoint *)&bMinLOS.y);
          bMaxLOS.y = bMax.y + iVar9;
          bMinLOS.x = bMinLOS_ffffffb4.x + iVar9;
          mapBound(this,(XYPoint *)&bMaxLOS.y);
          if ((param_1 == 0) && (this_01 == (AIModule *)&DAT_00000003)) {
            InfluenceMap::incrementValue
                      (&iMap,bMinLOS.y,bMaxLOS_ffffffcc.x,bMaxLOS.y,bMinLOS.x,'\n');
          }
          else {
            InfluenceMap::decrementValue
                      (&iMap,bMinLOS.y,bMaxLOS_ffffffcc.x,bMaxLOS.y,bMinLOS.x,'\n');
          }
        }
        else if ((param_1 == 1) || (param_1 == 2)) {
          iVar9 = __ftol();
          max.x = bMax.x - iVar9;
          aMax.y = bMin.y - iVar9;
          mapBound(this,(XYPoint *)&aMax.y);
          aMax.x = bMinLOS_ffffffb4.x + iVar9;
          aMin.y = bMax.y + iVar9;
          mapBound(this,(XYPoint *)&aMin.y);
          InfluenceMap::decrementValue(&iMap,aMax.y,max.x,aMin.y,aMax.x,'\n');
        }
        else if (param_1 == 5) {
          iVar9 = __ftol();
          bMinLOS_ffffffd4.y = bMin.y + iVar9 * -2;
          aMin.x = bMax.x + iVar9 * -2;
          mapBound(this,(XYPoint *)&bMinLOS_ffffffd4.y);
          bMaxLOS_ffffffcc.y = bMax.y + iVar9 * 2;
          bMinLOS_ffffffd4.x = bMinLOS_ffffffb4.x + iVar9 * 2;
          mapBound(this,(XYPoint *)&bMaxLOS_ffffffcc.y);
          InfluenceMap::decrementValue
                    (&iMap,bMinLOS_ffffffd4.y,aMin.x,bMaxLOS_ffffffcc.y,bMinLOS_ffffffd4.x,'\x14');
        }
        else if (param_1 == 8) {
          iVar9 = __ftol();
          bMinLOS_ffffffb4.y = bMin.y - iVar9;
          bMaxLOS.x = bMax.x - iVar9;
          mapBound(this,(XYPoint *)&bMinLOS_ffffffb4.y);
          bMaxLOS_ffffff98.y = bMax.y + iVar9;
          iVar10 = bMinLOS_ffffffb4.x + iVar9;
          mapBound(this,(XYPoint *)&bMaxLOS_ffffff98.y);
          InfluenceMap::incrementValue
                    (&iMap,bMinLOS_ffffffb4.y,bMaxLOS.x,bMaxLOS_ffffff98.y,iVar10,'\x14');
          iVar10 = iVar9 / 2;
          bMinLOS_ffffffb4.y = bMin.y - iVar10;
          bMaxLOS.x = bMax.x - iVar10;
          mapBound(this,(XYPoint *)&bMinLOS_ffffffb4.y);
          bMaxLOS_ffffff98.y = bMax.y + iVar10;
          iVar10 = bMinLOS_ffffffb4.x + iVar10;
          mapBound(this,(XYPoint *)&bMaxLOS_ffffff98.y);
          InfluenceMap::incrementValue
                    (&iMap,bMinLOS_ffffffb4.y,bMaxLOS.x,bMaxLOS_ffffff98.y,iVar10,'\x14');
          iVar9 = iVar9 / 3;
          bMinLOS_ffffffb4.y = bMin.y - iVar9;
          bMaxLOS.x = bMax.x - iVar9;
          mapBound(this,(XYPoint *)&bMinLOS_ffffffb4.y);
          bMaxLOS_ffffff98.y = bMax.y + iVar9;
          iVar9 = bMinLOS_ffffffb4.x + iVar9;
          mapBound(this,(XYPoint *)&bMaxLOS_ffffff98.y);
          InfluenceMap::incrementValue
                    (&iMap,bMinLOS_ffffffb4.y,bMaxLOS.x,bMaxLOS_ffffff98.y,iVar9,'\x14');
        }
      }
LAB_004df9fb:
      bMaxLOS_ffffff98.x = bMaxLOS_ffffff98.x + 1;
    } while (bMaxLOS_ffffff98.x < (this->playerBuildings).numberValue);
  }
  if (((param_1 == 3) || (param_1 == 4)) || (param_1 == 0)) {
    iVar9 = param_4->x;
    this_00 = *(RGE_Map **)(*(int *)(this->md->_padding_ + 0x3c) + 0x28);
    if (iVar9 <= param_5->x) {
      bMaxLOS_ffffff98.x = iVar9 * 0x18;
      do {
        iVar10 = param_4->y;
        if (iVar10 <= param_5->y) {
          do {
            uVar5 = RGE_Map::get_terrain(this_00,(short)iVar9,(short)iVar10);
            bMin.x = CONCAT31(bMin.x._1_3_,uVar5);
            if (uVar5 == '\x01') {
              aMax.x = iVar10 + -2;
              aMin.y = iVar9 + -2;
              aMax.y = aMin.y;
              max.x = aMax.x;
              mapBound(this,(XYPoint *)&aMin.y);
              mapBound(this,(XYPoint *)&aMax.y);
              InfluenceMap::setValue(&iMap,iVar9,iVar10,0xff);
              InfluenceMap::decrementValue(&iMap,aMin.y,aMax.x,aMax.y,max.x,'\n');
            }
            InfluenceMap::incrementValue
                      (&iMap,iVar9,iVar10,
                       ((byte)(&this_00->map_row_offset[iVar10]->field_0x5)[bMaxLOS_ffffff98.x] >> 5
                       ) * '\x05');
            iVar10 = iVar10 + 1;
          } while (iVar10 <= param_5->y);
        }
        iVar9 = iVar9 + 1;
        bMaxLOS_ffffff98.x = bMaxLOS_ffffff98.x + 0x18;
      } while (iVar9 <= param_5->x);
    }
  }
  if ((((param_1 == 3) || (param_1 == 4)) || ((param_1 == 0 || ((param_1 == 6 || (param_1 == 5))))))
     && (iVar9 = 0, 0 < this->maxAttackMemories)) {
    iVar10 = 0;
    do {
      pAVar3 = this->attackMemories;
      if ((*(int *)((int)&pAVar3->id + iVar10) != -1) &&
         ((ushort)(&pAVar3->targetOwner)[iVar10] == *(ushort *)(this->md->_padding_ + 0x4a))) {
        aMin.y = (&pAVar3->minX)[iVar10] - 4;
        aMax.x = (&pAVar3->minY)[iVar10] - 4;
        mapBound(this,(XYPoint *)&aMin.y);
        aMax.y = (&this->attackMemories->maxX)[iVar10] + 4;
        max.x = (&this->attackMemories->maxY)[iVar10] + 4;
        mapBound(this,(XYPoint *)&aMax.y);
        InfluenceMap::incrementValue(&iMap,aMin.y,aMax.x,aMax.y,max.x,'\x10');
      }
      iVar9 = iVar9 + 1;
      iVar10 = iVar10 + 0x18;
    } while (iVar9 < this->maxAttackMemories);
  }
  if (param_1 == 0) {
    TribeTacticalAIModule::setGroupInfluences(&this->md->tacticalAI,&iMap);
  }
  InfluenceMap::setConnectionCount
            (&iMap,(XYPoint *)&min.y,(XYPoint *)&max.y,0xff,1,(uint)(param_1 != 4),1);
  if ((param_1 != 0) && (iVar9 = 0, 0 < this->maxBuildingLots)) {
    do {
      pBVar4 = this->buildingLots;
      if ((pBVar4[iVar9].typeID == param_2) && (pBVar4[iVar9].status == '\x02')) {
        InfluenceMap::setValue(&iMap,(uint)pBVar4[iVar9].x,(uint)pBVar4[iVar9].y,0xff);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < this->maxBuildingLots);
  }
  return;
}

// --------------------------------------------------

// Function: mapBound
// Address: 004dfce0
/* public: int __thiscall TribeInformationAIModule::mapBound(struct XYPoint &) */

int __thiscall TribeInformationAIModule::mapBound(TribeInformationAIModule *this,XYPoint *param_1)
{
  int iVar1;
  
  iVar1 = 0;
  if (param_1->x < 0) {
    param_1->x = 0;
  }
  else {
    if (param_1->x < this->mapXSizeValue) goto LAB_004dfd04;
    param_1->x = this->mapXSizeValue + -1;
  }
  iVar1 = 1;
LAB_004dfd04:
  if (param_1->y < 0) {
    param_1->y = 0;
    return 1;
  }
  if (this->mapYSizeValue <= param_1->y) {
    iVar1 = 1;
    param_1->y = this->mapYSizeValue + -1;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: groupInfluenceDimension
// Address: 004dfd40
/* public: int __thiscall TribeInformationAIModule::groupInfluenceDimension(int) */

int __thiscall
TribeInformationAIModule::groupInfluenceDimension(TribeInformationAIModule *this,int param_1)
{
  if (param_1 < 2) {
    return 2;
  }
  return param_1 * param_1;
}

// --------------------------------------------------

// Function: findObjectMemoryLimits
// Address: 004dfd60
/* public: struct ObjectMemory __thiscall
   TribeInformationAIModule::findObjectMemoryLimits(int,int,int &,int &) */

ObjectMemory * __thiscall
TribeInformationAIModule::findObjectMemoryLimits
          (TribeInformationAIModule *this,ObjectMemory *__return_storage_ptr__,int param_1,
          int param_2,int *param_3,int *param_4)
{
  short sVar1;
  ushort uVar2;
  uchar uVar3;
  uchar uVar4;
  RGE_Static_Object *this_00;
  int *piVar5;
  RGE_Static_Object *pRVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  short *psVar11;
  int iVar12;
  ObjectMemory *pOVar13;
  float10 fVar14;
  float fVar15;
  XYPoint *pXVar16;
  uchar currentZone;
  int i;
  int local_34;
  undefined1 local_2c [4];
  ObjectMemory rVal;
  float local_4;
  
  *param_3 = 0;
  *param_4 = 0;
  rVal.type = 0;
  rVal.group = 0;
  rVal.attackAttempts._0_2_ = 0;
  rVal.kills = '\0';
  rVal._21_3_ = 0;
  rVal.damageCapability._0_1_ = 0;
  rVal.rateOfFire = 0.0;
  rVal.range = 0.0;
  local_4 = 0.0;
  this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_2);
  if (this_00 != (RGE_Static_Object *)0x0) {
    uVar3 = RGE_Static_Object::currentZone(this_00);
    local_34 = 0;
    if (0 < this->maxImportantObjectMemory) {
      _currentZone = 0;
      do {
        piVar5 = (int *)((int)&this->importantObjectMemory->id + _currentZone);
        if (((uint)*(byte *)((int)piVar5 + 0xb) == param_1) &&
           (pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,*piVar5),
           pRVar6 != (RGE_Static_Object *)0x0)) {
          uVar4 = RGE_Static_Object::currentZone(pRVar6);
          if (uVar3 != uVar4) {
            local_2c = (undefined1  [4])__ftol();
            rVal.id = __ftol();
            pXVar16 = (XYPoint *)local_2c;
            fVar14 = (float10)(**(code **)(this_00->_padding_ + 0x10c))();
            iVar7 = RGE_Static_Object::withinRangeOfZoneAtPoint(this_00,uVar3,(float)fVar14,pXVar16)
            ;
            if (iVar7 != 1) goto LAB_004e0002;
          }
          pRVar6 = MainDecisionAIModule::object
                             ((MainDecisionAIModule *)this->md,
                              *(int *)((int)&this->importantObjectMemory->id + _currentZone));
          if (pRVar6 != (RGE_Static_Object *)0x0) {
            pOVar13 = this->importantObjectMemory;
            iVar7 = __ftol();
            iVar12 = (uint)(&pOVar13->x)[_currentZone] - iVar7;
            if (iVar12 < 0) {
              iVar12 = -iVar12;
            }
            iVar8 = __ftol();
            iVar10 = (uint)(&pOVar13->y)[_currentZone] - iVar8;
            if (iVar10 < 0) {
              iVar10 = -iVar10;
            }
            if (((iVar12 < 6) && (iVar10 < 6)) ||
               (uVar4 = RGE_Visible_Map::get_visible
                                  (*(RGE_Visible_Map **)(this->md->_padding_ + 0x38),iVar7,iVar8),
               uVar4 == '\x0f')) {
              sVar1 = *(short *)((int)&this->importantObjectMemory->group + _currentZone);
              if ((sVar1 != 3) && (sVar1 != 0x1b)) {
                *param_3 = *param_3 + 1;
              }
              sVar1 = *(short *)((int)&this->importantObjectMemory->group + _currentZone);
              if (((sVar1 != 2) && (sVar1 != 0x15)) &&
                 ((sVar1 != 0x16 &&
                  ((sVar1 != 0x14 &&
                   (*(short *)((int)&this->importantObjectMemory->type + _currentZone) != 0x2d))))))
{
                *param_4 = *param_4 + 1;
              }
              pOVar13 = this->importantObjectMemory;
              fVar15 = RGE_Static_Object::distance_to_position
                                 (this_00,(float)(&pOVar13->x)[_currentZone],
                                  (float)(&pOVar13->y)[_currentZone],
                                  (float)(&pOVar13->z)[_currentZone]);
              if ((float)(int)rVal._4_4_ < fVar15) {
                uVar9 = __ftol();
                rVal.type = (short)uVar9;
                rVal.group = SUB42(uVar9,2);
              }
              pOVar13 = this->importantObjectMemory;
              uVar2 = *(ushort *)((int)&pOVar13->hitPoints + _currentZone);
              if ((short)(ushort)rVal.attackAttempts < (short)uVar2) {
                rVal.attackAttempts._0_2_ = uVar2;
              }
              if (0 < *(int *)((int)&pOVar13->attackAttempts + _currentZone)) {
                rVal.attackAttempts._0_2_ =
                     *(ushort *)((int)&pOVar13->attackAttempts + _currentZone);
              }
              if ((&pOVar13->kills)[_currentZone] != 0) {
                rVal.attackAttempts._0_2_ = (ushort)(&pOVar13->kills)[_currentZone];
              }
              if (rVal.rateOfFire < *(float *)((int)&pOVar13->damageCapability + _currentZone)) {
                rVal.rateOfFire = *(float *)((int)&pOVar13->damageCapability + _currentZone);
              }
              if (rVal.range < *(float *)((int)&pOVar13->rateOfFire + _currentZone)) {
                rVal.range = *(float *)((int)&pOVar13->rateOfFire + _currentZone);
              }
              if (local_4 < *(float *)((int)&pOVar13->range + _currentZone)) {
                local_4 = *(float *)((int)&pOVar13->range + _currentZone);
              }
            }
          }
        }
LAB_004e0002:
        local_34 = local_34 + 1;
        _currentZone = _currentZone + 0x24;
      } while (local_34 < this->maxImportantObjectMemory);
    }
  }
  psVar11 = &rVal.type;
  pOVar13 = __return_storage_ptr__;
  for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
    pOVar13->id = *(int *)psVar11;
    psVar11 = psVar11 + 2;
    pOVar13 = (ObjectMemory *)&pOVar13->type;
  }
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: isNextTo
// Address: 004e0040
/* public: int __thiscall TribeInformationAIModule::isNextTo(struct XYPoint &,struct XYPoint &,int)
    */

int __thiscall
TribeInformationAIModule::isNextTo
          (TribeInformationAIModule *this,XYPoint *param_1,XYPoint *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2->x - param_1->x;
  iVar2 = param_2->y - param_1->y;
  iVar1 = iVar1 * iVar1 + iVar2 * iVar2;
  if ((param_3 == 0) && (1 < iVar1)) {
    return 0;
  }
  if ((param_3 == 1) && (2 < iVar1)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: facetTo
// Address: 004e0090
/* public: int __thiscall TribeInformationAIModule::facetTo(struct XYPoint &,struct XYPoint &) */

int __thiscall
TribeInformationAIModule::facetTo(TribeInformationAIModule *this,XYPoint *param_1,XYPoint *param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2->x - param_1->x;
  iVar2 = param_2->y - param_1->y;
  if (param_2->x == param_1->x) {
    return ((-1 < iVar2) - 1 & 0xfffffffc) + 5;
  }
  if (param_2->y == param_1->y) {
    return ((-1 < iVar1) - 1 & 4) + 3;
  }
  if (iVar1 < 0) {
    return ((-1 < iVar2) - 1 & 0xfffffffa) + 6;
  }
  return ((-1 < iVar2) - 1 & 0xfffffffe) + 4;
}

// --------------------------------------------------

// Function: placementCode
// Address: 004e0100
/* public: int __thiscall TribeInformationAIModule::placementCode(int) */

int __thiscall TribeInformationAIModule::placementCode(TribeInformationAIModule *this,int param_1)
{
  switch(param_1) {
  case 0x2d:
    return 7;
  default:
    return 5;
  case 0x32:
    return 8;
  case 0x44:
    return 2;
  case 0x45:
  case 0x4f:
  case 199:
    return 3;
  case 0x46:
  case 0x52:
  case 0x54:
  case 0x6e:
  case 0x114:
    return 6;
  case 0x48:
  case 0x75:
  case 0x9b:
    return 4;
  case 0x67:
    return 1;
  case 0x6d:
    return 9;
  }
}

// --------------------------------------------------

// Function: storeLot
// Address: 004e02a0
/* public: void __thiscall TribeInformationAIModule::storeLot(int,unsigned char,unsigned
   char,unsigned char) */

void __thiscall
TribeInformationAIModule::storeLot
          (TribeInformationAIModule *this,int param_1,uchar param_2,uchar param_3,uchar param_4)
{
  BuildingLot *pBVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = -1;
  iVar3 = 0;
  iVar4 = this->maxBuildingLots;
  if (0 < iVar4) {
    pBVar1 = this->buildingLots;
    do {
      if (((pBVar1->typeID == param_1) && (pBVar1->x == param_2)) && (pBVar1->y == param_3)) {
        this->buildingLots[iVar3].status = param_4;
        return;
      }
      if ((iVar5 == -1) && (pBVar1->typeID == -1)) {
        iVar5 = iVar3;
      }
      iVar3 = iVar3 + 1;
      pBVar1 = pBVar1 + 1;
    } while (iVar3 < iVar4);
  }
  if (iVar5 == -1) {
    pBVar1 = (BuildingLot *)operator_new(iVar4 << 4);
    if (pBVar1 != (BuildingLot *)0x0) {
      iVar4 = 0;
      if (0 < this->maxBuildingLots) {
        puVar2 = &pBVar1->y;
        iVar5 = iVar4;
        do {
          iVar4 = iVar5 + 1;
          ((BuildingLot *)(puVar2 + -6))->typeID = this->buildingLots[iVar5].typeID;
          puVar2[-1] = this->buildingLots[iVar5].x;
          *puVar2 = this->buildingLots[iVar5].y;
          puVar2[-2] = this->buildingLots[iVar5].status;
          puVar2 = puVar2 + 8;
          iVar5 = iVar4;
        } while (iVar4 < this->maxBuildingLots);
      }
      if (iVar4 < this->maxBuildingLots * 2) {
        puVar2 = &pBVar1[iVar4].y;
        do {
          ((BuildingLot *)(puVar2 + -6))->typeID = -1;
          puVar2[-1] = '\0';
          *puVar2 = '\0';
          puVar2[-2] = param_4;
          iVar4 = iVar4 + 1;
          puVar2 = puVar2 + 8;
        } while (iVar4 < this->maxBuildingLots * 2);
      }
      operator_delete(this->buildingLots);
      this->buildingLots = pBVar1;
      pBVar1[this->maxBuildingLots].typeID = param_1;
      this->buildingLots[this->maxBuildingLots].x = param_2;
      this->buildingLots[this->maxBuildingLots].y = param_3;
      this->buildingLots[this->maxBuildingLots].status = param_4;
      this->maxBuildingLots = this->maxBuildingLots << 1;
      return;
    }
  }
  else {
    this->buildingLots[iVar5].typeID = param_1;
    this->buildingLots[iVar5].x = param_2;
    this->buildingLots[iVar5].y = param_3;
    this->buildingLots[iVar5].status = param_4;
  }
  return;
}

// --------------------------------------------------

// Function: removeLot
// Address: 004e0470
/* public: void __thiscall TribeInformationAIModule::removeLot(int,unsigned char,unsigned
   char,unsigned char) */

void __thiscall
TribeInformationAIModule::removeLot
          (TribeInformationAIModule *this,int param_1,uchar param_2,uchar param_3,uchar param_4)
{
  BuildingLot *pBVar1;
  BuildingLot *pBVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < this->maxBuildingLots) {
    pBVar1 = this->buildingLots;
    pBVar2 = pBVar1;
    while (((pBVar2->typeID != param_1 || (pBVar2->x != param_2)) || (pBVar2->y != param_3))) {
      iVar3 = iVar3 + 1;
      pBVar2 = pBVar2 + 1;
      if (this->maxBuildingLots <= iVar3) {
        return;
      }
    }
    if (param_4 != '\x03') {
      pBVar1[iVar3].status = param_4;
      return;
    }
    pBVar1[iVar3].typeID = -1;
    this->buildingLots[iVar3].x = '\0';
    this->buildingLots[iVar3].y = '\0';
    this->buildingLots[iVar3].status = '\x03';
  }
  return;
}

// --------------------------------------------------

// Function: availableLot
// Address: 004e0510
/* public: struct BuildingLot * __thiscall TribeInformationAIModule::availableLot(int) */

BuildingLot * __thiscall
TribeInformationAIModule::availableLot(TribeInformationAIModule *this,int param_1)
{
  BuildingLot *pBVar1;
  int iVar2;
  
  iVar2 = 0;
  if (this->maxBuildingLots < 1) {
    return (BuildingLot *)0x0;
  }
  pBVar1 = this->buildingLots;
  while ((pBVar1->typeID != param_1 || (pBVar1->status != '\0'))) {
    iVar2 = iVar2 + 1;
    pBVar1 = pBVar1 + 1;
    if (this->maxBuildingLots <= iVar2) {
      return (BuildingLot *)0x0;
    }
  }
  return this->buildingLots + iVar2;
}

// --------------------------------------------------

// Function: invalidLot
// Address: 004e0560
/* public: int __thiscall TribeInformationAIModule::invalidLot(int,unsigned char,unsigned char) */

int __thiscall
TribeInformationAIModule::invalidLot
          (TribeInformationAIModule *this,int param_1,uchar param_2,uchar param_3)
{
  BuildingLot *pBVar1;
  int iVar2;
  
  iVar2 = 0;
  if (this->maxBuildingLots < 1) {
    return 0;
  }
  pBVar1 = this->buildingLots;
  while ((((pBVar1->typeID != param_1 || (pBVar1->status != '\x02')) || (pBVar1->x != param_2)) ||
         (pBVar1->y != param_3))) {
    iVar2 = iVar2 + 1;
    pBVar1 = pBVar1 + 1;
    if (this->maxBuildingLots <= iVar2) {
      return 0;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: undesirableLot
// Address: 004e05c0
/* WARNING: Variable defined which should be unmapped: i */
/* public: int __thiscall TribeInformationAIModule::undesirableLot(int,unsigned char,unsigned
   char,int) */

int __thiscall
TribeInformationAIModule::undesirableLot
          (TribeInformationAIModule *this,int param_1,uchar param_2,uchar param_3,int param_4)
{
  BuildingLot *pBVar1;
  int i;
  int local_8;
  
  local_8 = 0;
  if (this->maxBuildingLots < 1) {
    return 0;
  }
  pBVar1 = this->buildingLots;
  do {
    if ((pBVar1->typeID == param_1) && (pBVar1->status == '\x01')) {
      if (((int)((uint)pBVar1->x - param_4) <= (int)(uint)param_2) &&
         ((((int)(uint)param_2 <= (int)(param_4 + (uint)pBVar1->x) &&
           ((int)((uint)pBVar1->y - param_4) <= (int)(uint)param_3)) &&
          ((int)(uint)param_3 <= (int)(param_4 + (uint)pBVar1->y))))) {
        return 1;
      }
    }
    pBVar1 = pBVar1 + 1;
    local_8 = local_8 + 1;
    if (this->maxBuildingLots <= local_8) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: setupWalls
// Address: 004e0670
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
/* public: void __thiscall TribeInformationAIModule::setupWalls(int,int,int,int,int,int,int,int) */

void __thiscall
TribeInformationAIModule::setupWalls
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3,int param_4,
          int param_5,int param_6,int param_7,int param_8)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  XYPoint *pXVar9;
  int iVar10;
  XYPoint max;
  XYPoint min;
  XYPoint realMin_ffffffdc;
  XYPoint realMin;
  XYPoint realMax;
  XYPoint realMax_fffffff4;
  
  if ((param_8 == 1) && (0 < param_6)) {
    this->numberGatesValue = param_6;
    uVar1 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x1731);
    uVar5 = (int)uVar1 >> 0x1f;
    iVar4 = ((uVar1 ^ uVar5) - uVar5 & 3 ^ uVar5) - uVar5;
    iVar8 = param_7 / 2;
    *(int *)((int)this + iVar4 * 8 + 0x1b4) = param_1 - iVar8;
    *(int *)((int)this + iVar4 * 8 + 0x1b8) = param_2 + param_4 * -2;
    *(int *)((int)this + iVar4 * 8 + 0x1d4) = param_1 + iVar8;
    *(int *)((int)this + iVar4 * 8 + 0x1d8) = param_2;
    uVar1 = (int)(iVar4 + 1U) >> 0x1f;
    iVar4 = ((iVar4 + 1U ^ uVar1) - uVar1 & 3 ^ uVar1) - uVar1;
    *(int *)((int)this + iVar4 * 8 + 0x1b4) = param_1 - iVar8;
    *(int *)((int)this + iVar4 * 8 + 0x1b8) = param_2;
    *(int *)((int)this + iVar4 * 8 + 0x1d4) = param_1 + iVar8;
    *(int *)((int)this + iVar4 * 8 + 0x1d8) = param_2 + param_4 * 2;
    uVar1 = (int)(iVar4 + 1U) >> 0x1f;
    iVar4 = ((iVar4 + 1U ^ uVar1) - uVar1 & 3 ^ uVar1) - uVar1;
    *(int *)((int)this + iVar4 * 8 + 0x1b4) = param_1;
    *(int *)((int)this + iVar4 * 8 + 0x1b8) = param_2 - iVar8;
    *(int *)((int)this + iVar4 * 8 + 0x1d4) = param_1 + param_4 * 2;
    *(int *)((int)this + iVar4 * 8 + 0x1d8) = iVar8 + param_2;
    uVar1 = (int)(iVar4 + 1U) >> 0x1f;
    iVar4 = ((iVar4 + 1U ^ uVar1) - uVar1 & 3 ^ uVar1) - uVar1;
    *(int *)((int)this + iVar4 * 8 + 0x1b4) = param_1 + param_4 * -2;
    *(int *)((int)this + iVar4 * 8 + 0x1b8) = param_2 - iVar8;
    *(int *)((int)this + iVar4 * 8 + 0x1d4) = param_1;
    *(int *)((int)this + iVar4 * 8 + 0x1d8) = iVar8 + param_2;
    if (0 < param_6) {
      pXVar9 = this->maxGatePosition;
      param_8 = param_6;
      do {
        mapBound(this,pXVar9 + -4);
        mapBound(this,pXVar9);
        pXVar9 = pXVar9 + 1;
        param_8 = param_8 + -1;
      } while (param_8 != 0);
    }
  }
  if (param_5 == 0) {
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x176a);
    param_5 = iVar4 % 3;
  }
  if (param_5 == 1) {
    if (param_3 <= param_4) {
      iVar4 = param_3 + param_2;
      iVar8 = param_1 - param_2;
      param_2 = param_2 - param_3;
      param_8 = ((param_4 - param_3) + 3U) / 3;
      param_3 = iVar4;
      do {
        realMin_ffffffdc.x = param_2;
        min.y = iVar8 + param_2;
        mapBound(this,(XYPoint *)&min.y);
        max.y = iVar8 + param_3;
        min.x = param_3;
        mapBound(this,(XYPoint *)&max.y);
        iVar4 = realMin_ffffffdc.x;
        iVar6 = min.y;
        if (min.y < max.y) {
          do {
            iVar2 = insideGate(this,param_6,iVar6,iVar4);
            if (iVar2 == 0) {
              storeLot(this,0x48,(uchar)iVar6,(uchar)iVar4,'\0');
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < max.y);
        }
        if (iVar4 < min.x) {
          do {
            iVar2 = insideGate(this,param_6,iVar6,iVar4);
            if (iVar2 == 0) {
              storeLot(this,0x48,(uchar)iVar6,(uchar)iVar4,'\0');
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < min.x);
        }
        if (min.y < iVar6) {
          do {
            iVar2 = insideGate(this,param_6,iVar6,iVar4);
            if (iVar2 == 0) {
              storeLot(this,0x48,(uchar)iVar6,(uchar)iVar4,'\0');
            }
            iVar6 = iVar6 + -1;
          } while (min.y < iVar6);
        }
        if (realMin_ffffffdc.x < iVar4) {
          do {
            iVar2 = insideGate(this,param_6,iVar6,iVar4);
            if (iVar2 == 0) {
              storeLot(this,0x48,(uchar)iVar6,(uchar)iVar4,'\0');
            }
            iVar4 = iVar4 + -1;
          } while (realMin_ffffffdc.x < iVar4);
        }
        param_2 = param_2 + -3;
        param_3 = param_3 + 3;
        param_8 = param_8 + -1;
      } while (param_8 != 0);
      return;
    }
  }
  else if (param_5 == 2) {
    param_8 = param_3;
    if (param_3 <= param_4) {
      param_7 = param_3 + param_2;
      iVar6 = param_1 - param_2;
      iVar8 = param_2 - param_3;
      min.y = (param_4 - param_3) + 1;
      iVar4 = iVar8;
      param_3 = param_3 * 2;
      do {
        realMin.y = iVar8 + iVar6;
        realMax.x = iVar8;
        mapBound(this,(XYPoint *)&realMin.y);
        max.y = param_8 + 1;
        realMax_fffffff4.x = param_2 + -1 + max.y;
        realMax.y = realMax_fffffff4.x + iVar6;
        mapBound(this,(XYPoint *)&realMax.y);
        realMin_ffffffdc.y = iVar4 + iVar6;
        realMin.x = iVar4;
        mapBound(this,(XYPoint *)&realMin_ffffffdc.y);
        realMax_fffffff4.y = param_7 + iVar6;
        mapBound(this,(XYPoint *)&realMax_fffffff4.y);
        iVar2 = realMin_ffffffdc.y;
        iVar7 = realMin.x;
        iVar10 = param_8;
        if (0 < param_3) {
          do {
            iVar3 = insideGate(this,param_6,iVar2,iVar7);
            if (iVar3 == 0) {
              storeLot(this,0x48,(uchar)iVar2,(uchar)iVar7,'\0');
            }
            iVar7 = iVar7 + -1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
        }
        if (0 < param_3) {
          max.x = param_3;
          do {
            iVar10 = insideGate(this,param_6,iVar2,iVar7);
            if (iVar10 == 0) {
              storeLot(this,0x48,(uchar)iVar2,(uchar)iVar7,'\0');
            }
            iVar2 = iVar2 + 1;
            max.x = max.x + -1;
          } while (max.x != 0);
          max.x = 0;
        }
        if (0 < param_3) {
          max.x = param_8;
          do {
            iVar10 = insideGate(this,param_6,iVar2,iVar7);
            if (iVar10 == 0) {
              storeLot(this,0x48,(uchar)iVar2,(uchar)iVar7,'\0');
            }
            iVar7 = iVar7 + 1;
            max.x = max.x + -1;
          } while (max.x != 0);
          max.x = 0;
          if (0 < param_3) {
            max.x = param_8;
            do {
              iVar10 = insideGate(this,param_6,iVar2,iVar7);
              if (iVar10 == 0) {
                storeLot(this,0x48,(uchar)iVar2,(uchar)iVar7,'\0');
              }
              iVar2 = iVar2 + 1;
              max.x = max.x + -1;
            } while (max.x != 0);
            max.x = 0;
            if (0 < param_3) {
              max.x = param_3;
              do {
                iVar10 = insideGate(this,param_6,iVar2,iVar7);
                if (iVar10 == 0) {
                  storeLot(this,0x48,(uchar)iVar2,(uchar)iVar7,'\0');
                }
                iVar7 = iVar7 + 1;
                max.x = max.x + -1;
              } while (max.x != 0);
              max.x = 0;
              iVar10 = param_8;
              if (0 < param_3) {
                do {
                  iVar3 = insideGate(this,param_6,iVar2,iVar7);
                  if (iVar3 == 0) {
                    storeLot(this,0x48,(uchar)iVar2,(uchar)iVar7,'\0');
                  }
                  iVar2 = iVar2 + -1;
                  iVar10 = iVar10 + -1;
                } while (iVar10 != 0);
              }
            }
          }
        }
        iVar10 = max.y;
        if (-1 < param_3) {
          do {
            iVar3 = insideGate(this,param_6,iVar2,iVar7);
            if (iVar3 == 0) {
              storeLot(this,0x48,(uchar)iVar2,(uchar)iVar7,'\0');
            }
            iVar7 = iVar7 + 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          iVar10 = param_3;
          if (0 < param_3) {
            do {
              iVar3 = insideGate(this,param_6,iVar2,iVar7);
              if (iVar3 == 0) {
                storeLot(this,0x48,(uchar)iVar2,(uchar)iVar7,'\0');
              }
              iVar2 = iVar2 + -1;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
          }
          iVar10 = max.y;
          if (-1 < param_3) {
            do {
              iVar3 = insideGate(this,param_6,iVar2,iVar7);
              if (iVar3 == 0) {
                storeLot(this,0x48,(uchar)iVar2,(uchar)iVar7,'\0');
              }
              iVar7 = iVar7 + -1;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
            iVar10 = param_8;
            if (0 < param_3) {
              do {
                iVar3 = insideGate(this,param_6,iVar2,iVar7);
                if (iVar3 == 0) {
                  storeLot(this,0x48,(uchar)iVar2,(uchar)iVar7,'\0');
                }
                iVar2 = iVar2 + -1;
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
              iVar10 = param_3;
              if (0 < param_3) {
                do {
                  iVar3 = insideGate(this,param_6,iVar2,iVar7);
                  if (iVar3 == 0) {
                    storeLot(this,0x48,(uchar)iVar2,(uchar)iVar7,'\0');
                  }
                  iVar7 = iVar7 + -1;
                  iVar10 = iVar10 + -1;
                } while (iVar10 != 0);
                iVar10 = param_8;
                if (0 < param_3) {
                  do {
                    iVar3 = insideGate(this,param_6,iVar2,iVar7);
                    if (iVar3 == 0) {
                      storeLot(this,0x48,(uchar)iVar2,(uchar)iVar7,'\0');
                    }
                    iVar2 = iVar2 + 1;
                    iVar10 = iVar10 + -1;
                  } while (iVar10 != 0);
                }
              }
            }
          }
        }
        param_8 = param_8 + 2;
        iVar8 = iVar8 + -2;
        iVar4 = iVar4 + -1;
        param_7 = param_7 + 1;
        param_3 = param_3 + 4;
        min.y = min.y + -1;
      } while (min.y != 0);
      return;
    }
  }
  else if ((param_5 == 3) && (iVar4 = param_3 / 2, iVar4 <= param_4)) {
    iVar6 = param_3 + param_2;
    iVar8 = param_1 - param_2;
    param_8 = iVar4 + param_2;
    param_3 = param_2 - param_3;
    param_7 = (param_4 - iVar4) + 1;
    param_1 = iVar6;
    param_2 = param_2 - iVar4;
    do {
      realMin.x = param_3;
      realMin_ffffffdc.y = param_3 + iVar8;
      mapBound(this,(XYPoint *)&realMin_ffffffdc.y);
      realMax_fffffff4.y = param_1 + iVar8;
      mapBound(this,(XYPoint *)&realMax_fffffff4.y);
      realMin_ffffffdc.x = param_2;
      min.y = param_2 + iVar8;
      mapBound(this,(XYPoint *)&min.y);
      min.x = param_8;
      max.y = param_8 + iVar8;
      mapBound(this,(XYPoint *)&max.y);
      iVar4 = realMin_ffffffdc.y;
      iVar6 = realMin_ffffffdc.x;
      if (realMin_ffffffdc.y < min.y) {
        do {
          iVar2 = insideGate(this,param_6,iVar4,iVar6);
          if (iVar2 == 0) {
            storeLot(this,0x48,(uchar)iVar4,(uchar)iVar6,'\0');
          }
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar4 < min.y);
      }
      if (iVar4 < max.y) {
        do {
          iVar2 = insideGate(this,param_6,iVar4,iVar6);
          if (iVar2 == 0) {
            storeLot(this,0x48,(uchar)iVar4,(uchar)iVar6,'\0');
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < max.y);
      }
      if (iVar6 < realMin_ffffffdc.x) {
        do {
          iVar2 = insideGate(this,param_6,iVar4,iVar6);
          if (iVar2 == 0) {
            storeLot(this,0x48,(uchar)iVar4,(uchar)iVar6,'\0');
          }
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 1;
        } while (iVar6 < realMin_ffffffdc.x);
      }
      if (iVar6 < min.x) {
        do {
          iVar2 = insideGate(this,param_6,iVar4,iVar6);
          if (iVar2 == 0) {
            storeLot(this,0x48,(uchar)iVar4,(uchar)iVar6,'\0');
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < min.x);
      }
      if (max.y < iVar4) {
        do {
          iVar2 = insideGate(this,param_6,iVar4,iVar6);
          if (iVar2 == 0) {
            storeLot(this,0x48,(uchar)iVar4,(uchar)iVar6,'\0');
          }
          iVar4 = iVar4 + -1;
          iVar6 = iVar6 + 1;
        } while (max.y < iVar4);
      }
      if (min.y < iVar4) {
        do {
          iVar2 = insideGate(this,param_6,iVar4,iVar6);
          if (iVar2 == 0) {
            storeLot(this,0x48,(uchar)iVar4,(uchar)iVar6,'\0');
          }
          iVar4 = iVar4 + -1;
        } while (min.y < iVar4);
      }
      if (min.x < iVar6) {
        do {
          iVar2 = insideGate(this,param_6,iVar4,iVar6);
          if (iVar2 == 0) {
            storeLot(this,0x48,(uchar)iVar4,(uchar)iVar6,'\0');
          }
          iVar4 = iVar4 + -1;
          iVar6 = iVar6 + -1;
        } while (min.x < iVar6);
      }
      if (realMin_ffffffdc.x < iVar6) {
        do {
          iVar2 = insideGate(this,param_6,iVar4,iVar6);
          if (iVar2 == 0) {
            storeLot(this,0x48,(uchar)iVar4,(uchar)iVar6,'\0');
          }
          iVar6 = iVar6 + -1;
        } while (realMin_ffffffdc.x < iVar6);
      }
      param_2 = param_2 + -1;
      param_3 = param_3 + -2;
      param_1 = param_1 + 2;
      param_8 = param_8 + 1;
      param_7 = param_7 + -1;
    } while (param_7 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: insideGate
// Address: 004e0f40
/* public: int __thiscall TribeInformationAIModule::insideGate(int,int,int) */

int __thiscall
TribeInformationAIModule::insideGate
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 < 1) {
    return 0;
  }
  piVar1 = &this->minGatePosition[0].y;
  while ((((param_2 < ((XYPoint *)(piVar1 + -1))->x || (param_3 < *piVar1)) || (piVar1[7] < param_2)
          ) || (piVar1[8] < param_3))) {
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 2;
    if (param_1 <= iVar2) {
      return 0;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: storeAttackMemory
// Address: 004e0f90
/* public: int __thiscall TribeInformationAIModule::storeAttackMemory(unsigned char,unsigned
   char,unsigned char,unsigned char,unsigned char,short,unsigned char,unsigned long,int) */

int __thiscall
TribeInformationAIModule::storeAttackMemory
          (TribeInformationAIModule *this,uchar param_1,uchar param_2,uchar param_3,uchar param_4,
          uchar param_5,short param_6,uchar param_7,ulong param_8,int param_9)
{
  int iVar1;
  
  iVar1 = storeAttackMemory(this,param_1,param_2,param_3,param_2,param_3,param_4,param_5,param_6,
                            param_7,param_8,param_9);
  return iVar1;
}

// --------------------------------------------------

// Function: storeAttackMemory
// Address: 004e0fd0
/* public: int __thiscall TribeInformationAIModule::storeAttackMemory(unsigned char,unsigned
   char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,short,unsigned
   char,unsigned long,int) */

int __thiscall
TribeInformationAIModule::storeAttackMemory
          (TribeInformationAIModule *this,uchar param_1,uchar param_2,uchar param_3,uchar param_4,
          uchar param_5,uchar param_6,uchar param_7,short param_8,uchar param_9,ulong param_10,
          int param_11)
{
  ushort uVar1;
  AttackMemory *pAVar2;
  int *piVar3;
  ulong *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_4;
  
  if ((0 < this->mapXSizeValue) && (0 < this->mapYSizeValue)) {
    iVar6 = ((uint)param_4 + (uint)param_2) * 4;
    iVar8 = (iVar6 / this->mapXSizeValue) / 2;
    iVar6 = (iVar6 / this->mapYSizeValue) / 2;
    if (4 < iVar8) {
      iVar8 = 3;
    }
    if (4 < iVar6) {
      iVar6 = 3;
    }
    uVar1 = *(ushort *)(this->md->_padding_ + 0x4a);
    if (param_7 == uVar1) {
      piVar3 = &this->quadrantLog[iVar8][iVar6].numberAttacksOnUs;
    }
    else {
      if (param_6 != uVar1) goto LAB_004e1077;
      piVar3 = &this->quadrantLog[iVar8][iVar6].numberAttacksByUs;
    }
    *piVar3 = *piVar3 + 1;
  }
LAB_004e1077:
  iVar6 = -1;
  iVar7 = 0;
  iVar8 = iVar6;
  if (0 < this->maxAttackMemories) {
    pAVar2 = this->attackMemories;
    local_4 = -0x18;
    iVar5 = 0;
    puVar4 = &pAVar2->timeStamp;
    do {
      iVar8 = iVar7;
      if (*(int *)((int)&pAVar2->id + iVar5) == -1) break;
      if ((iVar6 == -1) || (*(uint *)((int)&pAVar2->timeStamp + local_4) < *puVar4)) {
        iVar6 = iVar7;
        local_4 = iVar5;
      }
      iVar7 = iVar7 + 1;
      iVar5 = iVar5 + 0x18;
      puVar4 = puVar4 + 6;
      iVar8 = iVar6;
    } while (iVar7 < this->maxAttackMemories);
  }
  if (iVar8 != -1) {
    this->attackMemories[iVar8].id = iVar7;
    this->attackMemories[iVar8].type = param_1;
    this->attackMemories[iVar8].minX = param_2;
    this->attackMemories[iVar8].minY = param_3;
    this->attackMemories[iVar8].maxX = param_4;
    this->attackMemories[iVar8].maxY = param_5;
    this->attackMemories[iVar8].attackingOwner = param_6;
    this->attackMemories[iVar8].targetOwner = param_7;
    this->attackMemories[iVar8].kills = param_8;
    this->attackMemories[iVar8].success = param_9;
    this->attackMemories[iVar8].timeStamp = param_10;
    this->attackMemories[iVar8].play = param_11;
  }
  return iVar8;
}

// --------------------------------------------------

// Function: removeAttackMemory
// Address: 004e1190
/* public: void __thiscall TribeInformationAIModule::removeAttackMemory(int) */

void __thiscall
TribeInformationAIModule::removeAttackMemory(TribeInformationAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < this->maxAttackMemories)) {
    this->attackMemories[param_1].id = -1;
    this->attackMemories[param_1].type = '\0';
    this->attackMemories[param_1].minX = '\0';
    this->attackMemories[param_1].minY = '\0';
    this->attackMemories[param_1].maxX = '\0';
    this->attackMemories[param_1].maxY = '\0';
    this->attackMemories[param_1].attackingOwner = 0xff;
    this->attackMemories[param_1].targetOwner = 0xff;
    this->attackMemories[param_1].kills = 0;
    this->attackMemories[param_1].success = '\0';
    this->attackMemories[param_1].play = -1;
  }
  return;
}

// --------------------------------------------------

// Function: attackMemory
// Address: 004e1230
/* public: struct AttackMemory * __thiscall TribeInformationAIModule::attackMemory(int) */

AttackMemory * __thiscall
TribeInformationAIModule::attackMemory(TribeInformationAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < this->maxAttackMemories)) {
    return this->attackMemories + param_1;
  }
  return (AttackMemory *)0x0;
}

// --------------------------------------------------

// Function: loadLearnInfo
// Address: 004e1260
// [HELPER] s_learn__s_s__d: "learn\%s%s.%d"
// [HELPER] s_learn_default__d: "learn\default.%d"
/* WARNING: Variable defined which should be unmapped: numMemoriesToLoad */
/* public: void __thiscall TribeInformationAIModule::loadLearnInfo(char *) */

void __thiscall
TribeInformationAIModule::loadLearnInfo(TribeInformationAIModule *this,char *param_1)
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  ResourceMemory *pRVar7;
  int iVar8;
  int numMemoriesToLoad;
  int numToLoad;
  int tempInt;
  int local_2c;
  ObjectMemory temp;
  float local_4;
  
  pcVar1 = this->learnFileName;
  if (param_1 == (char *)0x0) {
    sprintf(pcVar1,s_learn_default__d,(int)*(short *)(this->md->_padding_ + 0x4a));
  }
  else {
    pcVar2 = RGE_Game_Info::get_current_player_name(rge_base_game->player_game_info);
    sprintf(pcVar1,s_learn__s_s__d,param_1,pcVar2);
  }
  iVar3 = rge_open(pcVar1,0x8000);
  if (iVar3 != -1) {
    rge_read(iVar3,&this->mapXSizeValue,4);
    rge_read(iVar3,&this->mapYSizeValue,4);
    rge_read(iVar3,&numToLoad,4);
    iVar8 = 0;
    if (0 < numToLoad) {
      do {
        rge_read(iVar3,&temp.type,0x18);
        storeAttackMemory(this,temp.x,temp.y,temp.z,temp.owner,(uchar)temp.hitPoints,
                          temp.hitPoints._1_1_,temp._14_1_,
                          CONCAT11(temp.attackAttempts._1_1_,(undefined1)temp.attackAttempts),
                          temp.attackAttempts._2_1_,CONCAT22(temp._22_2_,temp._20_2_),
                          (int)temp.damageCapability);
        iVar8 = iVar8 + 1;
      } while (iVar8 < numToLoad);
    }
    rge_read(iVar3,&numToLoad,4);
    param_1 = (char *)0x0;
    if (0 < numToLoad) {
      do {
        rge_read(iVar3,&temp.type,0x24);
        addObjectMemory(this,temp._4_4_,CONCAT11(temp.y,temp.x),CONCAT11(temp.owner,temp.z),
                        (uchar)temp.hitPoints,temp.hitPoints._1_1_,temp._14_1_,temp._15_1_,
                        CONCAT11(temp.attackAttempts._1_1_,(undefined1)temp.attackAttempts),
                        CONCAT22(temp._22_2_,temp._20_2_),SUB41(temp.damageCapability,0),
                        temp.rateOfFire,temp.range,local_4,(RGE_Static_Object *)0x0);
        iVar8 = (this->importantUnits).numberValue;
        iVar4 = 0;
        temp.id._0_2_ = temp.type;
        temp.id._2_2_ = temp.group;
        if (0 < iVar8) {
          do {
            if ((this->importantUnits).maximumSizeValue <= iVar4) break;
            if ((this->importantUnits).value[iVar4] == temp._4_4_) goto LAB_004e149b;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar8);
        }
        if ((this->importantUnits).maximumSizeValue + -1 < iVar8) {
          iVar8 = iVar8 + 1;
          piVar5 = (int *)operator_new(iVar8 * 4);
          if (piVar5 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (this->importantUnits).maximumSizeValue) {
              do {
                if (iVar8 <= iVar4) break;
                iVar6 = iVar4 + 1;
                piVar5[iVar4] = (this->importantUnits).value[iVar4];
                iVar4 = iVar6;
              } while (iVar6 < (this->importantUnits).maximumSizeValue);
            }
            operator_delete((this->importantUnits).value);
            (this->importantUnits).value = piVar5;
            (this->importantUnits).maximumSizeValue = iVar8;
          }
        }
        (this->importantUnits).value[(this->importantUnits).numberValue] = temp.id;
        (this->importantUnits).numberValue = (this->importantUnits).numberValue + 1;
LAB_004e149b:
        param_1 = param_1 + 1;
      } while ((int)param_1 < numToLoad);
    }
    piVar5 = this->maxResources;
    iVar8 = 4;
    do {
      rge_read(iVar3,piVar5,4);
      rge_read(iVar3,piVar5 + -4,4);
      pRVar7 = (ResourceMemory *)operator_new(*piVar5 * 0x14);
      piVar5[-8] = (int)pRVar7;
      rge_read(iVar3,pRVar7,*piVar5 * 0x14);
      piVar5 = piVar5 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    rge_read(iVar3,&tempInt,4);
    param_1 = (char *)0x0;
    if (0 < tempInt) {
      do {
        rge_read(iVar3,&local_2c,4);
        iVar8 = (this->importantMiscs).numberValue;
        iVar4 = 0;
        temp.id = local_2c;
        if (0 < iVar8) {
          do {
            if ((this->importantMiscs).maximumSizeValue <= iVar4) break;
            if ((this->importantMiscs).value[iVar4] == local_2c) goto LAB_004e15f1;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar8);
        }
        if ((this->importantMiscs).maximumSizeValue + -1 < iVar8) {
          iVar8 = iVar8 + 1;
          piVar5 = (int *)operator_new(iVar8 * 4);
          if (piVar5 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (this->importantMiscs).maximumSizeValue) {
              do {
                if (iVar8 <= iVar4) break;
                iVar6 = iVar4 + 1;
                piVar5[iVar4] = (this->importantMiscs).value[iVar4];
                iVar4 = iVar6;
              } while (iVar6 < (this->importantMiscs).maximumSizeValue);
            }
            operator_delete((this->importantMiscs).value);
            (this->importantMiscs).value = piVar5;
            (this->importantMiscs).maximumSizeValue = iVar8;
          }
        }
        (this->importantMiscs).value[(this->importantMiscs).numberValue] = temp.id;
        (this->importantMiscs).numberValue = (this->importantMiscs).numberValue + 1;
LAB_004e15f1:
        param_1 = param_1 + 1;
      } while ((int)param_1 < tempInt);
    }
    rge_read(iVar3,&tempInt,4);
    param_1 = (char *)0x0;
    if (0 < tempInt) {
      do {
        rge_read(iVar3,&local_2c,4);
        iVar8 = (this->itemsToDefend).numberValue;
        iVar4 = 0;
        temp.id = local_2c;
        if (0 < iVar8) {
          do {
            if ((this->itemsToDefend).maximumSizeValue <= iVar4) break;
            if ((this->itemsToDefend).value[iVar4] == local_2c) goto LAB_004e16f4;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar8);
        }
        if ((this->itemsToDefend).maximumSizeValue + -1 < iVar8) {
          iVar8 = iVar8 + 1;
          piVar5 = (int *)operator_new(iVar8 * 4);
          if (piVar5 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (this->itemsToDefend).maximumSizeValue) {
              do {
                if (iVar8 <= iVar4) break;
                iVar6 = iVar4 + 1;
                piVar5[iVar4] = (this->itemsToDefend).value[iVar4];
                iVar4 = iVar6;
              } while (iVar6 < (this->itemsToDefend).maximumSizeValue);
            }
            operator_delete((this->itemsToDefend).value);
            (this->itemsToDefend).value = piVar5;
            (this->itemsToDefend).maximumSizeValue = iVar8;
          }
        }
        (this->itemsToDefend).value[(this->itemsToDefend).numberValue] = temp.id;
        (this->itemsToDefend).numberValue = (this->itemsToDefend).numberValue + 1;
LAB_004e16f4:
        param_1 = param_1 + 1;
      } while ((int)param_1 < tempInt);
    }
    rge_close(iVar3);
  }
  return;
}

// --------------------------------------------------

// Function: setSaveLearnInformation
// Address: 004e1720
/* public: void __thiscall TribeInformationAIModule::setSaveLearnInformation(int) */

void __thiscall
TribeInformationAIModule::setSaveLearnInformation(TribeInformationAIModule *this,int param_1)
{
  this->saveLearnInformationValue = param_1;
  return;
}

// --------------------------------------------------

// Function: unexploredPlayerLocation
// Address: 004e1730
/* WARNING: Variable defined which should be unmapped: bestDistance */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TribeInformationAIModule::unexploredPlayerLocation(int,struct XYPoint &)
    */

int __thiscall
TribeInformationAIModule::unexploredPlayerLocation
          (TribeInformationAIModule *this,int param_1,XYPoint *param_2)
{
  byte bVar1;
  ObjectMemory *pOVar2;
  XYPoint *pXVar3;
  uchar uVar4;
  RGE_Static_Object *this_00;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int bestDistance;
  int i;
  int local_14;
  XYZPoint point;
  
  iVar8 = param_1;
  this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if (iVar8 != 0) {
    uVar4 = RGE_Static_Object::currentZone(this_00);
    param_1 = CONCAT31(param_1._1_3_,uVar4);
    iVar9 = 0;
    iVar8 = 0;
    i = -1;
    local_14 = 0;
    if (0 < this->maxImportantObjectMemory) {
      do {
        piVar5 = (int *)((int)&this->importantObjectMemory->id + iVar9);
        if (((*piVar5 != -1) &&
            ((ushort)*(byte *)((int)piVar5 + 0xb) != *(ushort *)(this->md->_padding_ + 0x4a))) &&
           (*(char *)((int)piVar5 + 0xb) != '\0')) {
          iVar6 = tileUncovered(this,(uint)*(byte *)(piVar5 + 2),(uint)*(byte *)((int)piVar5 + 9));
          if (iVar6 != 1) {
            uVar4 = RGE_Static_Object::lookupZone
                              (this_00,(uint)(&this->importantObjectMemory->x)[iVar9],
                               (uint)(&this->importantObjectMemory->y)[iVar9]);
            if (uVar4 == (uchar)param_1) {
              pOVar2 = this->importantObjectMemory;
              RGE_Static_Object::distance_to_position
                        (this_00,(float)(&pOVar2->x)[iVar9],(float)(&pOVar2->y)[iVar9],
                         (float)(&pOVar2->z)[iVar9]);
              iVar6 = __ftol();
              if ((iVar8 == 0) || (iVar6 < i)) {
                iVar8 = (int)&this->importantObjectMemory->id + iVar9;
                i = iVar6;
              }
            }
          }
        }
        local_14 = local_14 + 1;
        iVar9 = iVar9 + 0x24;
      } while (local_14 < this->maxImportantObjectMemory);
    }
    pXVar3 = param_2;
    if (iVar8 != 0) {
      param_2->x = (uint)*(byte *)(iVar8 + 8);
      bVar1 = *(byte *)(iVar8 + 9);
      param_2->y = (uint)bVar1;
      uVar7 = __ftol();
      iVar8 = (**(code **)(this_00->_padding_ + 0x198))
                        (pXVar3->x,(uint)bVar1,uVar7,this_00->master_obj->los - _DAT_00575564,
                         0xffffffff,&param_1,1,0xffffffff,0xffffffff);
      if (iVar8 == 0) {
        InfluenceMap::setValue(&this->pathMap,pXVar3->x,pXVar3->y,'\x01');
        return 0;
      }
      InfluenceMap::setValue(&this->pathMap,pXVar3->x,pXVar3->y,'\0');
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: numberUnitsWithinXTiles
// Address: 004e1930
/* WARNING: Variable defined which should be unmapped: i */
/* public: int __thiscall TribeInformationAIModule::numberUnitsWithinXTiles(int,int,int,int) */

int __thiscall
TribeInformationAIModule::numberUnitsWithinXTiles
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int i;
  int local_4;
  
  iVar4 = 0;
  iVar3 = param_4 * param_4;
  param_4 = 0;
  local_4 = 0;
  if (0 < this->maxImportantObjectMemory) {
    do {
      if (param_1 == -1) {
LAB_004e1974:
        iVar1 = (**(code **)(*(int *)this->md->_padding_ + 0x18))
                          ((&this->importantObjectMemory->owner)[iVar4]);
        if (iVar1 != 0) {
LAB_004e199a:
          iVar1 = (uint)(&this->importantObjectMemory->x)[iVar4] - param_2;
          iVar2 = (uint)(&this->importantObjectMemory->y)[iVar4] - param_3;
          if (iVar1 * iVar1 + iVar2 * iVar2 <= iVar3) {
            param_4 = param_4 + 1;
          }
        }
      }
      else if ((uint)(&this->importantObjectMemory->owner)[iVar4] == param_1) {
        if (param_1 == -1) goto LAB_004e1974;
        goto LAB_004e199a;
      }
      local_4 = local_4 + 1;
      iVar4 = iVar4 + 0x24;
    } while (local_4 < this->maxImportantObjectMemory);
  }
  return param_4;
}

// --------------------------------------------------

// Function: withinXTilesOfAttackOnPlayer
// Address: 004e1a00
/* public: int __thiscall TribeInformationAIModule::withinXTilesOfAttackOnPlayer(class
   RGE_Static_Object *,int,int) */

int __thiscall
TribeInformationAIModule::withinXTilesOfAttackOnPlayer
          (TribeInformationAIModule *this,RGE_Static_Object *param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  AttackMemory *pAVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = param_2 * param_2;
  iVar1 = __ftol();
  iVar2 = __ftol();
  param_1 = (RGE_Static_Object *)0x0;
  if (this->maxAttackMemories < 1) {
    return 0;
  }
  pAVar4 = this->attackMemories;
  do {
    if (((pAVar4->id != -1) && (pAVar4->attackingOwner != '\0')) &&
       ((uint)pAVar4->targetOwner == param_3)) {
      iVar7 = (uint)pAVar4->minY - iVar2;
      iVar3 = (uint)pAVar4->minX - iVar1;
      iVar3 = iVar3 * iVar3;
      if (((iVar7 * iVar7 + iVar3 <= iVar5) ||
          (iVar6 = (uint)pAVar4->maxY - iVar2, iVar6 = iVar6 * iVar6, iVar3 + iVar6 <= iVar5)) ||
         ((iVar3 = (uint)pAVar4->maxX - iVar1, iVar3 = iVar3 * iVar3, iVar6 + iVar3 <= iVar5 ||
          (iVar7 * iVar7 + iVar3 <= iVar5)))) {
        return 1;
      }
    }
    pAVar4 = pAVar4 + 1;
    param_1 = (RGE_Static_Object *)((int)&param_1->_padding_ + 1);
    if (this->maxAttackMemories <= (int)param_1) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: withinXTilesOfEnemyTowncenter
// Address: 004e1af0
/* WARNING: Variable defined which should be unmapped: y */
/* public: int __thiscall TribeInformationAIModule::withinXTilesOfEnemyTowncenter(class
   RGE_Static_Object *,int) */

int __thiscall
TribeInformationAIModule::withinXTilesOfEnemyTowncenter
          (TribeInformationAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int y;
  
  iVar5 = param_2 * param_2;
  iVar1 = __ftol();
  iVar2 = __ftol();
  iVar6 = 0;
  param_2 = 0;
  if (this->maxImportantObjectMemory < 1) {
    return 0;
  }
  do {
    if (*(short *)((int)&this->importantObjectMemory->type + iVar6) == 0x6d) {
      iVar3 = (**(code **)(*(int *)this->md->_padding_ + 0x18))
                        ((&this->importantObjectMemory->owner)[iVar6]);
      if ((iVar3 != 0) &&
         (iVar3 = (uint)(&this->importantObjectMemory->x)[iVar6] - iVar1,
         iVar4 = (uint)(&this->importantObjectMemory->y)[iVar6] - iVar2,
         iVar3 * iVar3 + iVar4 * iVar4 <= iVar5)) {
        return 1;
      }
    }
    param_2 = param_2 + 1;
    iVar6 = iVar6 + 0x24;
    if (this->maxImportantObjectMemory <= param_2) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: withinXTilesOfObject
// Address: 004e1bd0
/* WARNING: Variable defined which should be unmapped: i */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TribeInformationAIModule::withinXTilesOfObject(class RGE_Static_Object
   *,int,int,int,int,int) */

int __thiscall
TribeInformationAIModule::withinXTilesOfObject
          (TribeInformationAIModule *this,RGE_Static_Object *param_1,int param_2,int param_3,
          int param_4,int param_5,int param_6)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int i;
  int x;
  int y;
  
  iVar7 = param_2 * param_2;
  iVar2 = __ftol();
  iVar3 = __ftol();
  param_2 = -1;
  param_1 = (RGE_Static_Object *)0xffffffff;
  iVar8 = 0;
  x = 0;
  if (0 < this->maxImportantObjectMemory) {
    do {
      pRVar4 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)this->md,
                          *(int *)((int)&this->importantObjectMemory->id + iVar8));
      if (((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar4->object_state < 3)) &&
         (pRVar4->hp != _DAT_00575580)) {
        iVar5 = (int)*(short *)((int)&this->importantObjectMemory->type + iVar8);
        if ((((iVar5 == param_3) || (iVar5 == param_4)) ||
            ((iVar5 == param_5 || (iVar5 == param_6)))) &&
           (iVar5 = (**(code **)(*(int *)this->md->_padding_ + 0x18))
                              ((&this->importantObjectMemory->owner)[iVar8]), iVar5 != 0)) {
          piVar1 = (int *)((int)&this->importantObjectMemory->id + iVar8);
          iVar5 = (uint)(&this->importantObjectMemory->x)[iVar8] - iVar2;
          iVar6 = (uint)*(byte *)((int)piVar1 + 9) - iVar3;
          pRVar4 = (RGE_Static_Object *)(iVar5 * iVar5 + iVar6 * iVar6);
          if (((int)pRVar4 <= iVar7) && (((int)pRVar4 < (int)param_1 || (param_2 == -1)))) {
            param_2 = *piVar1;
            param_1 = pRVar4;
          }
        }
      }
      x = x + 1;
      iVar8 = iVar8 + 0x24;
    } while (x < this->maxImportantObjectMemory);
  }
  return param_2;
}

// --------------------------------------------------

// Function: findStagingPoint
// Address: 004e1d10
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
/* public: int __thiscall TribeInformationAIModule::findStagingPoint(struct XYPoint,struct XYPoint
   &,int,int,int,int,int) */

int __thiscall
TribeInformationAIModule::findStagingPoint
          (TribeInformationAIModule *this,XYPoint param_1,XYPoint *param_2,int param_3,int param_4,
          int param_5,int param_6,int param_7)
{
  RGE_Visible_Map *this_00;
  bool bVar1;
  uchar uVar2;
  uchar uVar3;
  ObjectMemory *pOVar4;
  RGE_Static_Object *this_01;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  RGE_Map *pRVar12;
  byte bVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  RGE_Static_Object *unit;
  int bestValue;
  RGE_Map *gMap;
  int b;
  int maxLOSValue;
  int maxAttackValue;
  RGE_Visible_Map *vMap;
  ObjectMemory *target;
  XYPoint passableMax;
  XYPoint max;
  XYPoint min;
  XYPoint zoneRefPoint;
  XYPoint passableMin;
  XYPoint targetPoint;
  XYPoint temp;
  XYPoint temp2;
  
  pOVar4 = objectMemory(this,param_5);
  if (pOVar4 == (ObjectMemory *)0x0) {
    return 0;
  }
  passableMax.x = (int)pOVar4;
  this_01 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_7);
  if (this_01 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  iVar5 = isBoat(this,this_01);
  if ((iVar5 == 1) && (param_3 == 0)) {
    iVar5 = 1;
    iVar15 = 0x16;
  }
  else {
    iVar5 = 2;
    iVar15 = 0;
  }
  passableMin.x = param_1.y;
  zoneRefPoint.y = param_1.x;
  RGE_Static_Object::findClosestPointInTerrainType
            (this_01,param_1,(XYPoint *)&zoneRefPoint.y,iVar5,iVar15,4);
  uVar2 = RGE_Static_Object::lookupZone(this_01,zoneRefPoint.y,passableMin.x);
  iVar15 = setupLOSMap(this,(uint)pOVar4->owner,(uint)pOVar4->x,(uint)pOVar4->y);
  iVar6 = setupAttackMap(this,(uint)pOVar4->owner,(uint)pOVar4->x,(uint)pOVar4->y);
  min.y = (uint)pOVar4->x - param_6;
  zoneRefPoint.x = (uint)pOVar4->y - param_6;
  mapBound(this,(XYPoint *)&min.y);
  max.y = param_6 + (uint)pOVar4->x;
  min.x = param_6 + (uint)pOVar4->y;
  mapBound(this,(XYPoint *)&max.y);
  targetPoint.y = (int)pOVar4->x;
  temp.x = (int)pOVar4->y;
  mapBound(this,(XYPoint *)&targetPoint.y);
  gMap = (RGE_Map *)0xffffffff;
  this_00 = *(RGE_Visible_Map **)(this->md->_padding_ + 0x38);
  iVar5 = *(int *)(this->md->aiPlayer->_padding_ + 0x28);
  if (min.y <= max.y) {
    iVar7 = min.y * 0x18;
    iVar16 = min.x;
    iVar14 = zoneRefPoint.x;
    iVar17 = min.y;
    do {
      iVar8 = iVar14;
      if (iVar14 <= iVar16) {
        do {
          bVar13 = *(byte *)(*(int *)(*(int *)(iVar5 + 0x8d8c) + iVar14 * 4) + 5 + iVar7) & 0x1f;
          RGE_Visible_Map::get_visible(this_00,iVar17,iVar14);
          if (param_3 == 1) {
            if (bVar13 == 2) goto LAB_004e1f44;
          }
          else if (param_4 == 1) {
            if ((bVar13 != 1) && (bVar13 != 0x16)) {
LAB_004e1f44:
              uVar3 = RGE_Static_Object::lookupZone(this_01,iVar17,iVar14);
              if (uVar3 == uVar2) {
                if (param_3 == 1) {
                  passableMin.y = iVar17 + -2;
                  targetPoint.x = iVar14 + -2;
                  mapBound(this,(XYPoint *)&passableMin.y);
                  passableMax.y = iVar17 + 2;
                  max.x = iVar14 + 2;
                  mapBound(this,(XYPoint *)&passableMax.y);
                  bVar1 = true;
                  param_1.x = passableMin.y;
                  if (passableMin.y <= passableMax.y) {
                    unit = (RGE_Static_Object *)(passableMin.y * 0x18);
                    do {
                      if (!bVar1) goto LAB_004e218d;
                      iVar16 = targetPoint.x;
                      if (targetPoint.x <= max.x) {
                        do {
                          if (!bVar1) break;
                          bVar13 = *(byte *)((int)&unit->id +
                                            *(int *)(*(int *)(iVar5 + 0x8d8c) + iVar16 * 4) + 1) &
                                   0x1f;
                          if (((bVar13 != 1) && (bVar13 != 0x16)) &&
                             (iVar8 = (**(code **)(this_01->_padding_ + 0x114))
                                                ((float)param_1.x,(float)iVar16,1), iVar8 == 0)) {
                            bVar1 = false;
                          }
                          iVar16 = iVar16 + 1;
                        } while (iVar16 <= max.x);
                      }
                      param_1.x = param_1.x + 1;
                      unit = (RGE_Static_Object *)&unit->sprite_list;
                    } while (param_1.x <= passableMax.y);
                  }
                  if (!bVar1) goto LAB_004e218d;
                }
                iVar16 = __ftol();
                iVar8 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x1b3f);
                temp.y = iVar17;
                temp2.x = iVar14;
                iVar9 = (**(code **)(this_01->_padding_ + 0x1b0))
                                  (&temp.y,&targetPoint.y,0x3f800000,&temp2.y,1);
                if (iVar15 < 1) {
                  iVar10 = 0;
                }
                else {
                  iVar10 = InfluenceMap::lookupValue(&losMap,iVar17,iVar14);
                  iVar10 = -((iVar10 * param_6) / iVar15);
                }
                if (iVar6 < 1) {
                  iVar11 = 0;
                }
                else {
                  iVar11 = InfluenceMap::lookupValue(&attackMap,iVar17,iVar14);
                  iVar11 = -((iVar11 * param_6) / iVar6);
                }
                pRVar12 = (RGE_Map *)
                          (iVar11 + iVar10 + (~-(uint)(iVar9 != 1) & param_6) +
                           iVar8 % (param_6 * 3) + iVar16);
                if ((gMap == (RGE_Map *)0xffffffff) || ((int)gMap < (int)pRVar12)) {
                  param_2->x = iVar17;
                  param_2->y = iVar14;
                  gMap = pRVar12;
                }
              }
            }
          }
          else if (((param_4 != 0) || (bVar13 == 1)) || (bVar13 == 0x16)) goto LAB_004e1f44;
LAB_004e218d:
          iVar14 = iVar14 + 1;
          iVar16 = min.x;
          iVar8 = zoneRefPoint.x;
        } while (iVar14 <= min.x);
      }
      iVar17 = iVar17 + 1;
      iVar7 = iVar7 + 0x18;
      iVar14 = iVar8;
    } while (iVar17 <= max.y);
  }
  return (uint)(gMap != (RGE_Map *)0xffffffff);
}

// --------------------------------------------------

// Function: setupLOSMap
// Address: 004e21e0
/* WARNING: Variable defined which should be unmapped: maxX */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TribeInformationAIModule::setupLOSMap(int,int,int) */

int __thiscall
TribeInformationAIModule::setupLOSMap
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3)
{
  uchar uVar1;
  int *piVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  int maxX;
  
  InfluenceMap::initialize(&losMap,'\0');
  InfluenceMap::setReferencePoint(&losMap,param_2,param_3);
  param_2 = 0;
  if (0 < this->maxImportantObjectMemory) {
    param_3 = 0;
    do {
      piVar2 = (int *)((int)&this->importantObjectMemory->id + param_3);
      if (((uint)*(byte *)((int)piVar2 + 0xb) == param_1) &&
         (pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,*piVar2),
         pRVar3 != (RGE_Static_Object *)0x0)) {
        iVar4 = __ftol();
        iVar5 = __ftol();
        iVar6 = __ftol();
        fVar7 = (float10)(**(code **)(pRVar3->_padding_ + 0x108))();
        uVar1 = '\x05';
        if (fVar7 <= (float10)_DAT_00575580) {
          uVar1 = '\x01';
        }
        InfluenceMap::incrementValue
                  (&losMap,iVar5 - iVar4,iVar6 - iVar4,iVar4 + iVar5,iVar4 + iVar6,uVar1);
      }
      param_2 = param_2 + 1;
      param_3 = param_3 + 0x24;
    } while (param_2 < this->maxImportantObjectMemory);
  }
  iVar4 = InfluenceMap::maxValue(&losMap);
  return iVar4;
}

// --------------------------------------------------

// Function: setupAttackMap
// Address: 004e22f0
/* public: int __thiscall TribeInformationAIModule::setupAttackMap(int,int,int) */

int __thiscall
TribeInformationAIModule::setupAttackMap
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3)
{
  AttackMemory *pAVar1;
  int iVar2;
  int iVar3;
  
  InfluenceMap::initialize(&attackMap,'\0');
  InfluenceMap::setReferencePoint(&attackMap,param_2,param_3);
  iVar2 = 0;
  if (0 < this->maxAttackMemories) {
    iVar3 = 0;
    do {
      pAVar1 = this->attackMemories;
      if (((uint)(&pAVar1->targetOwner)[iVar3] == param_1) &&
         ((ushort)(&pAVar1->attackingOwner)[iVar3] == *(ushort *)(this->md->_padding_ + 0x4a))) {
        InfluenceMap::incrementValue
                  (&attackMap,(uint)(&pAVar1->minX)[iVar3],(uint)(&pAVar1->minY)[iVar3],
                   (uint)(&pAVar1->maxX)[iVar3],(uint)(&pAVar1->maxY)[iVar3],'\x01');
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x18;
    } while (iVar2 < this->maxAttackMemories);
  }
  iVar2 = InfluenceMap::maxValue(&attackMap);
  return iVar2;
}

// --------------------------------------------------

// Function: addResourceType
// Address: 004e23a0
/* public: void __thiscall TribeInformationAIModule::addResourceType(int,int) */

void __thiscall
TribeInformationAIModule::addResourceType(TribeInformationAIModule *this,int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)operator_new(this->numberResourceTypesValue[param_1] * 4 + 4);
  iVar2 = 0;
  iVar3 = iVar2;
  if (0 < this->numberResourceTypesValue[param_1]) {
    do {
      iVar2 = iVar3 + 1;
      piVar1[iVar3] = this->resourceTypesValue[param_1][iVar3];
      iVar3 = iVar2;
    } while (iVar2 < this->numberResourceTypesValue[param_1]);
  }
  piVar1[iVar2] = param_2;
  if (this->resourceTypesValue[param_1] != (int *)0x0) {
    operator_delete(this->resourceTypesValue[param_1]);
  }
  this->resourceTypesValue[param_1] = piVar1;
  this->numberResourceTypesValue[param_1] = this->numberResourceTypesValue[param_1] + 1;
  return;
}

// --------------------------------------------------

// Function: resourceType
// Address: 004e2440
/* public: int __thiscall TribeInformationAIModule::resourceType(int,int) */

int __thiscall
TribeInformationAIModule::resourceType(TribeInformationAIModule *this,int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (this->numberResourceTypesValue[param_1] < 1) {
    return 0;
  }
  piVar2 = this->resourceTypesValue[param_1];
  do {
    if (*piVar2 == param_2) {
      return 1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < this->numberResourceTypesValue[param_1]);
  return 0;
}

// --------------------------------------------------

// Function: addResourceObject
// Address: 004e2490
/* WARNING: Variable defined which should be unmapped: newSize */
/* public: int __thiscall TribeInformationAIModule::addResourceObject(class RGE_Static_Object *) */

int __thiscall
TribeInformationAIModule::addResourceObject
          (TribeInformationAIModule *this,RGE_Static_Object *param_1)
{
  short sVar1;
  uchar uVar2;
  ResourceMemory *pRVar3;
  uchar *puVar4;
  ResourceMemory *pRVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  RGE_Static_Object *pRVar9;
  int newSize;
  ResourceMemory *temp;
  int dropsiteID;
  int local_4;
  
  pRVar9 = param_1;
  sVar1 = param_1->master_obj->object_group;
  if (sVar1 == 0xf) {
    uVar7 = 1;
  }
  else if (sVar1 == 8) {
    uVar7 = 2;
  }
  else {
    uVar7 = (sVar1 != 0x20) - 1 & 3;
  }
  iVar8 = this->maxResources[uVar7];
  if ((this->numResources[uVar7] == iVar8) || (this->resources[uVar7] == (ResourceMemory *)0x0)) {
    if (iVar8 == 0) {
      temp = (ResourceMemory *)0x64;
    }
    else {
      temp = (ResourceMemory *)(iVar8 * 2);
    }
    pRVar3 = (ResourceMemory *)operator_new((int)temp * 0x14);
    if (pRVar3 == (ResourceMemory *)0x0) {
      return 0;
    }
    pRVar5 = this->resources[uVar7];
    iVar8 = 0;
    if (pRVar5 != (ResourceMemory *)0x0) {
      iVar6 = 0;
      puVar4 = &pRVar3->y;
      do {
        pRVar9 = param_1;
        if (this->maxResources[uVar7] <= iVar8) break;
        iVar8 = iVar8 + 1;
        ((ResourceMemory *)(puVar4 + -5))->id = *(int *)((int)&pRVar5->id + iVar6);
        puVar4[-1] = (&this->resources[uVar7]->x)[iVar6];
        *puVar4 = (&this->resources[uVar7]->y)[iVar6];
        puVar4[1] = (&this->resources[uVar7]->gatherAttempts)[iVar6];
        *(int *)(puVar4 + 3) = *(int *)((int)&this->resources[uVar7]->gatherValue + iVar6);
        puVar4[7] = (&this->resources[uVar7]->valid)[iVar6];
        puVar4[8] = (&this->resources[uVar7]->gone)[iVar6];
        puVar4[9] = (&this->resources[uVar7]->dropDistance)[iVar6];
        puVar4[10] = (&this->resources[uVar7]->resourceType)[iVar6];
        *(int *)(puVar4 + 0xb) = *(int *)((int)&this->resources[uVar7]->dropsiteID + iVar6);
        pRVar5 = this->resources[uVar7];
        iVar6 = iVar6 + 0x14;
        puVar4 = puVar4 + 0x14;
      } while (pRVar5 != (ResourceMemory *)0x0);
    }
    if (iVar8 < (int)temp) {
      iVar6 = (int)temp - iVar8;
      puVar4 = &pRVar3[iVar8].y;
      do {
        ((ResourceMemory *)(puVar4 + -5))->id = -1;
        puVar4[-1] = '\0';
        *puVar4 = '\0';
        puVar4[1] = '\0';
        *(int *)(puVar4 + 3) = 0xff;
        puVar4[7] = '\0';
        puVar4[8] = '\0';
        puVar4[9] = 0xff;
        puVar4[10] = 0xff;
        *(int *)(puVar4 + 0xb) = -1;
        puVar4 = puVar4 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    if (this->resources[uVar7] != (ResourceMemory *)0x0) {
      operator_delete(this->resources[uVar7]);
    }
    this->resources[uVar7] = pRVar3;
    this->maxResources[uVar7] = (int)temp;
  }
  iVar8 = 0;
  if (0 < this->maxResources[uVar7]) {
    pRVar3 = this->resources[uVar7];
    do {
      if (pRVar3->id == pRVar9->id) {
        param_1 = (RGE_Static_Object *)0xffffffff;
        findClosestDropsite(this,pRVar9,1,(int *)&param_1);
        iVar6 = __ftol();
        this->resources[uVar7][iVar8].gatherValue = iVar6;
        this->resources[uVar7][iVar8].dropsiteID = (int)param_1;
        sVar1 = pRVar9->master_obj->object_group;
        if (sVar1 == 0xf) {
          iVar6 = __ftol();
          if ((this->closestDropsiteValue[1] <= iVar6) && (this->closestDropsiteValue[1] != -1)) {
            return 1;
          }
          this->closestDropsiteValue[1] = iVar6;
          this->closestDropsiteResourceID[1] = this->resources[uVar7][iVar8].id;
          return 1;
        }
        if (sVar1 == 0x20) {
          iVar6 = __ftol();
          if ((this->closestDropsiteValue[3] <= iVar6) && (this->closestDropsiteValue[3] != -1)) {
            return 1;
          }
          this->closestDropsiteValue[3] = iVar6;
          this->closestDropsiteResourceID[3] = this->resources[uVar7][iVar8].id;
          return 1;
        }
        if (sVar1 == 8) {
          iVar6 = __ftol();
          if ((this->closestDropsiteValue[2] <= iVar6) && (this->closestDropsiteValue[2] != -1)) {
            return 1;
          }
          this->closestDropsiteValue[2] = iVar6;
          this->closestDropsiteResourceID[2] = this->resources[uVar7][iVar8].id;
          return 1;
        }
        if (sVar1 != 7) {
          return 1;
        }
        iVar6 = __ftol();
        if ((this->closestDropsiteValue[0] <= iVar6) && (this->closestDropsiteValue[0] != -1)) {
          return 1;
        }
        this->closestDropsiteValue[0] = iVar6;
        this->closestDropsiteResourceID[0] = this->resources[uVar7][iVar8].id;
        return 1;
      }
      iVar8 = iVar8 + 1;
      pRVar3 = pRVar3 + 1;
    } while (iVar8 < this->maxResources[uVar7]);
  }
  this->resources[uVar7][this->numResources[uVar7]].id = pRVar9->id;
  uVar2 = __ftol();
  this->resources[uVar7][this->numResources[uVar7]].x = uVar2;
  uVar2 = __ftol();
  this->resources[uVar7][this->numResources[uVar7]].y = uVar2;
  this->resources[uVar7][this->numResources[uVar7]].gatherAttempts = '\0';
  this->resources[uVar7][this->numResources[uVar7]].valid = '\0';
  this->resources[uVar7][this->numResources[uVar7]].gone = '\0';
  this->resources[uVar7][this->numResources[uVar7]].resourceType = (uchar)uVar7;
  local_4 = -1;
  findClosestDropsite(this,pRVar9,1,&local_4);
  uVar2 = __ftol();
  this->resources[uVar7][this->numResources[uVar7]].dropDistance = uVar2;
  this->resources[uVar7][this->numResources[uVar7]].dropsiteID = local_4;
  iVar8 = __ftol();
  this->resources[uVar7][this->numResources[uVar7]].gatherValue = iVar8;
  this->numResources[uVar7] = this->numResources[uVar7] + 1;
  sVar1 = pRVar9->master_obj->object_group;
  if (sVar1 == 0xf) {
    iVar8 = __ftol();
    if ((iVar8 < this->closestDropsiteValue[1]) || (this->closestDropsiteValue[1] == -1)) {
      this->closestDropsiteValue[1] = iVar8;
      this->closestDropsiteResourceID[1] = pRVar9->id;
      return 1;
    }
  }
  else if (sVar1 == 0x20) {
    iVar8 = __ftol();
    if ((iVar8 < this->closestDropsiteValue[3]) || (this->closestDropsiteValue[3] == -1)) {
      this->closestDropsiteValue[3] = iVar8;
      this->closestDropsiteResourceID[3] = pRVar9->id;
      return 1;
    }
  }
  else if (sVar1 == 8) {
    iVar8 = __ftol();
    if ((iVar8 < this->closestDropsiteValue[2]) || (this->closestDropsiteValue[2] == -1)) {
      this->closestDropsiteValue[2] = iVar8;
      this->closestDropsiteResourceID[2] = pRVar9->id;
      return 1;
    }
  }
  else if (sVar1 == 7) {
    iVar8 = __ftol();
    if ((iVar8 < this->closestDropsiteValue[0]) || (this->closestDropsiteValue[0] == -1)) {
      this->closestDropsiteValue[0] = iVar8;
      this->closestDropsiteResourceID[0] = pRVar9->id;
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: findClosestDropsite
// Address: 004e2a00
/* WARNING: Variable defined which should be unmapped: resourceZone */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: float __thiscall TribeInformationAIModule::findClosestDropsite(class RGE_Static_Object
   *,int,int &) */

float __thiscall
TribeInformationAIModule::findClosestDropsite
          (TribeInformationAIModule *this,RGE_Static_Object *param_1,int param_2,int *param_3)
{
  short sVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  uchar uVar5;
  uchar uVar6;
  int *piVar7;
  int iVar8;
  RGE_Static_Object *pRVar9;
  int iVar10;
  int iVar11;
  uchar resourceZone;
  float dropDistance;
  float xDiff;
  
  xDiff = 1000.0;
  uVar5 = RGE_Static_Object::currentZone(param_1);
  iVar11 = 0;
  *param_3 = -1;
  if (0 < (this->playerBuildings).numberValue) {
    do {
      if ((this->playerBuildings).maximumSizeValue + -1 < iVar11) {
        piVar7 = (int *)operator_new(iVar11 * 4 + 4);
        if (piVar7 != (int *)0x0) {
          iVar10 = 0;
          if (0 < (this->playerBuildings).maximumSizeValue) {
            do {
              if (iVar11 + 1 <= iVar10) break;
              iVar8 = iVar10 + 1;
              piVar7[iVar10] = (this->playerBuildings).value[iVar10];
              iVar10 = iVar8;
            } while (iVar8 < (this->playerBuildings).maximumSizeValue);
          }
          operator_delete((this->playerBuildings).value);
          (this->playerBuildings).value = piVar7;
          (this->playerBuildings).maximumSizeValue = iVar11 + 1;
        }
      }
      pRVar9 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)this->md,(this->playerBuildings).value[iVar11]);
      if (pRVar9 != (RGE_Static_Object *)0x0) {
        iVar10 = __ftol();
        iVar8 = __ftol();
        uVar6 = RGE_Static_Object::lookupZone(param_1,iVar8,iVar10);
        if (((uVar6 == uVar5) &&
            ((((sVar1 = pRVar9->master_obj->id, sVar1 == 0x6d && (param_2 != 0)) ||
              ((sVar1 == 0x67 &&
               ((sVar2 = param_1->master_obj->id, sVar2 != 0x3b && (sVar2 != 0x32)))))) ||
             ((sVar1 == 0x44 &&
              ((sVar1 = param_1->master_obj->id, sVar1 == 0x3b || (sVar1 == 0x32)))))))) &&
           ((fVar4 = pRVar9->world_x - param_1->world_x, fVar3 = pRVar9->world_y - param_1->world_y,
            fVar3 = SQRT(fVar3 * fVar3 + fVar4 * fVar4), xDiff == _DAT_00575588 || (fVar3 < xDiff)))
           ) {
          *param_3 = pRVar9->id;
          xDiff = fVar3;
        }
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < (this->playerBuildings).numberValue);
  }
  return xDiff;
}

// --------------------------------------------------

// Function: findClosestReturnDropsite
// Address: 004e2ba0
/* WARNING: Variable defined which should be unmapped: unitZone */
/* public: class RGE_Static_Object * __thiscall
   TribeInformationAIModule::findClosestReturnDropsite(class RGE_Static_Object *) */

RGE_Static_Object * __thiscall
TribeInformationAIModule::findClosestReturnDropsite
          (TribeInformationAIModule *this,RGE_Static_Object *param_1)
{
  short sVar1;
  float fVar2;
  float fVar3;
  RGE_Static_Object *pRVar4;
  uchar uVar5;
  uchar uVar6;
  int *piVar7;
  int iVar8;
  RGE_Static_Object *pRVar9;
  int iVar10;
  int iVar11;
  uchar unitZone;
  RGE_Static_Object *rVal;
  float xDiff;
  float dropDistance;
  float local_4;
  
  iVar11 = 0;
  xDiff = 0.0;
  local_4 = 1000.0;
  uVar5 = RGE_Static_Object::currentZone(param_1);
  if (0 < (this->playerBuildings).numberValue) {
    do {
      if ((this->playerBuildings).maximumSizeValue + -1 < iVar11) {
        piVar7 = (int *)operator_new(iVar11 * 4 + 4);
        if (piVar7 != (int *)0x0) {
          iVar10 = 0;
          if (0 < (this->playerBuildings).maximumSizeValue) {
            do {
              if (iVar11 + 1 <= iVar10) break;
              iVar8 = iVar10 + 1;
              piVar7[iVar10] = (this->playerBuildings).value[iVar10];
              iVar10 = iVar8;
            } while (iVar8 < (this->playerBuildings).maximumSizeValue);
          }
          operator_delete((this->playerBuildings).value);
          (this->playerBuildings).value = piVar7;
          (this->playerBuildings).maximumSizeValue = iVar11 + 1;
        }
      }
      pRVar9 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)this->md,(this->playerBuildings).value[iVar11]);
      pRVar4 = (RGE_Static_Object *)xDiff;
      fVar2 = local_4;
      if (pRVar9 != (RGE_Static_Object *)0x0) {
        iVar10 = __ftol();
        iVar8 = __ftol();
        uVar6 = RGE_Static_Object::lookupZone(param_1,iVar8,iVar10);
        if (((uVar6 == uVar5) &&
            (((sVar1 = pRVar9->master_obj->id, sVar1 == 0x6d ||
              ((sVar1 == 0x67 && (param_1->attribute_type_held != 0x10)))) ||
             ((sVar1 == 0x44 && (param_1->attribute_type_held == 0x10)))))) &&
           ((fVar3 = pRVar9->world_x - param_1->world_x, fVar2 = pRVar9->world_y - param_1->world_y,
            fVar2 = SQRT(fVar2 * fVar2 + fVar3 * fVar3), pRVar4 = pRVar9, xDiff != 0.0 &&
            (local_4 <= fVar2)))) {
          pRVar4 = (RGE_Static_Object *)xDiff;
          fVar2 = local_4;
        }
      }
      local_4 = fVar2;
      xDiff = (float)pRVar4;
      iVar11 = iVar11 + 1;
    } while (iVar11 < (this->playerBuildings).numberValue);
  }
  return (RGE_Static_Object *)xDiff;
}

// --------------------------------------------------

// Function: updateAllResourceDropsites
// Address: 004e2d10
/* WARNING: Variable defined which should be unmapped: dropsiteID */
/* public: void __thiscall TribeInformationAIModule::updateAllResourceDropsites(void) */

void __thiscall TribeInformationAIModule::updateAllResourceDropsites(TribeInformationAIModule *this)
{
  short sVar1;
  uchar uVar2;
  RGE_Static_Object *pRVar3;
  undefined4 uVar4;
  int iVar5;
  ResourceMemory **ppRVar6;
  int iVar7;
  int dropsiteID;
  int a;
  int local_8;
  int local_4;
  
  local_4 = 4;
  ppRVar6 = this->resources;
  do {
    iVar7 = 0;
    ppRVar6[0x1c] = (ResourceMemory *)0xffffffff;
    ppRVar6[0x20] = (ResourceMemory *)0xffffffff;
    local_8 = 0;
    if (0 < (int)ppRVar6[4]) {
      do {
        pRVar3 = MainDecisionAIModule::object
                           ((MainDecisionAIModule *)this->md,*(int *)((int)&(*ppRVar6)->id + iVar7))
        ;
        if (pRVar3 != (RGE_Static_Object *)0x0) {
          a = -1;
          findClosestDropsite(this,pRVar3,1,&a);
          uVar4 = __ftol();
          *(undefined4 *)((int)&(*ppRVar6)->gatherValue + iVar7) = uVar4;
          uVar2 = __ftol();
          (&(*ppRVar6)->dropDistance)[iVar7] = uVar2;
          *(int *)((int)&(*ppRVar6)->dropsiteID + iVar7) = a;
          sVar1 = pRVar3->master_obj->object_group;
          if (sVar1 == 0xf) {
            iVar5 = __ftol();
            if ((iVar5 < this->closestDropsiteValue[1]) || (this->closestDropsiteValue[1] == -1)) {
              this->closestDropsiteValue[1] = iVar5;
              this->closestDropsiteResourceID[1] = pRVar3->id;
            }
          }
          else if (sVar1 == 0x20) {
            iVar5 = __ftol();
            if ((iVar5 < this->closestDropsiteValue[3]) || (this->closestDropsiteValue[3] == -1)) {
              this->closestDropsiteValue[3] = iVar5;
              this->closestDropsiteResourceID[3] = pRVar3->id;
            }
          }
          else if (sVar1 == 8) {
            iVar5 = __ftol();
            if ((iVar5 < this->closestDropsiteValue[2]) || (this->closestDropsiteValue[2] == -1)) {
              this->closestDropsiteValue[2] = iVar5;
              this->closestDropsiteResourceID[2] = pRVar3->id;
            }
          }
          else if (sVar1 == 7) {
            iVar5 = __ftol();
            if ((iVar5 < this->closestDropsiteValue[0]) || (this->closestDropsiteValue[0] == -1)) {
              this->closestDropsiteValue[0] = iVar5;
              this->closestDropsiteResourceID[0] = pRVar3->id;
            }
          }
        }
        local_8 = local_8 + 1;
        iVar7 = iVar7 + 0x14;
      } while (local_8 < (int)ppRVar6[4]);
    }
    ppRVar6 = ppRVar6 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  return;
}

// --------------------------------------------------

// Function: updateResourceDropsites
// Address: 004e2e90
/* WARNING: Variable defined which should be unmapped: a */
/* public: void __thiscall TribeInformationAIModule::updateResourceDropsites(int) */

void __thiscall
TribeInformationAIModule::updateResourceDropsites(TribeInformationAIModule *this,int param_1)
{
  short sVar1;
  int iVar2;
  uchar uVar3;
  int *piVar4;
  RGE_Static_Object *pRVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int a;
  int local_4;
  
  iVar2 = param_1;
  iVar8 = 0;
  this->closestDropsiteValue[param_1] = -1;
  this->closestDropsiteResourceID[param_1] = -1;
  local_4 = 0;
  if (0 < this->numResources[param_1]) {
    do {
      piVar4 = (int *)((int)&this->resources[iVar2]->id + iVar8);
      if ((*(char *)((int)piVar4 + 0xd) != '\x01') &&
         (pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,*piVar4),
         pRVar5 != (RGE_Static_Object *)0x0)) {
        param_1 = -1;
        findClosestDropsite(this,pRVar5,1,&param_1);
        uVar6 = __ftol();
        *(undefined4 *)((int)&this->resources[iVar2]->gatherValue + iVar8) = uVar6;
        uVar3 = __ftol();
        (&this->resources[iVar2]->dropDistance)[iVar8] = uVar3;
        *(int *)((int)&this->resources[iVar2]->dropsiteID + iVar8) = param_1;
        sVar1 = pRVar5->master_obj->object_group;
        if (sVar1 == 0xf) {
          iVar7 = __ftol();
          if ((iVar7 < this->closestDropsiteValue[1]) || (this->closestDropsiteValue[1] == -1)) {
            this->closestDropsiteValue[1] = iVar7;
            this->closestDropsiteResourceID[1] = pRVar5->id;
          }
        }
        else if (sVar1 == 0x20) {
          iVar7 = __ftol();
          if ((iVar7 < this->closestDropsiteValue[3]) || (this->closestDropsiteValue[3] == -1)) {
            this->closestDropsiteValue[3] = iVar7;
            this->closestDropsiteResourceID[3] = pRVar5->id;
          }
        }
        else if (sVar1 == 8) {
          iVar7 = __ftol();
          if ((iVar7 < this->closestDropsiteValue[2]) || (this->closestDropsiteValue[2] == -1)) {
            this->closestDropsiteValue[2] = iVar7;
            this->closestDropsiteResourceID[2] = pRVar5->id;
          }
        }
        else if (sVar1 == 7) {
          iVar7 = __ftol();
          if ((iVar7 < this->closestDropsiteValue[0]) || (this->closestDropsiteValue[0] == -1)) {
            this->closestDropsiteValue[0] = iVar7;
            this->closestDropsiteResourceID[0] = pRVar5->id;
          }
        }
      }
      local_4 = local_4 + 1;
      iVar8 = iVar8 + 0x14;
    } while (local_4 < this->numResources[iVar2]);
  }
  return;
}

// --------------------------------------------------

// Function: setResourceObjectValid
// Address: 004e3020
/* public: int __thiscall TribeInformationAIModule::setResourceObjectValid(int,int,int) */

int __thiscall
TribeInformationAIModule::setResourceObjectValid
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  ResourceMemory *pRVar2;
  
  iVar1 = 0;
  if (this->numResources[param_1] < 1) {
    return 0;
  }
  pRVar2 = this->resources[param_1];
  do {
    if (pRVar2->id == param_2) {
      this->resources[param_1][iVar1].valid = (uchar)param_3;
      return 1;
    }
    iVar1 = iVar1 + 1;
    pRVar2 = pRVar2 + 1;
  } while (iVar1 < this->numResources[param_1]);
  return 0;
}

// --------------------------------------------------

// Function: numberStoragePits
// Address: 004e3070
/* WARNING: Variable defined which should be unmapped: count */
/* public: int __thiscall TribeInformationAIModule::numberStoragePits(void) */

int __thiscall TribeInformationAIModule::numberStoragePits(TribeInformationAIModule *this)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int count;
  int local_4;
  
  iVar5 = 0;
  local_4 = 0;
  if (0 < (this->playerBuildings).numberValue) {
    do {
      if ((this->playerBuildings).maximumSizeValue + -1 < iVar5) {
        piVar1 = (int *)operator_new(iVar5 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (this->playerBuildings).maximumSizeValue) {
            do {
              if (iVar5 + 1 <= iVar2) break;
              iVar3 = iVar2 + 1;
              piVar1[iVar2] = (this->playerBuildings).value[iVar2];
              iVar2 = iVar3;
            } while (iVar3 < (this->playerBuildings).maximumSizeValue);
          }
          operator_delete((this->playerBuildings).value);
          (this->playerBuildings).value = piVar1;
          (this->playerBuildings).maximumSizeValue = iVar5 + 1;
        }
      }
      pRVar4 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)this->md,(this->playerBuildings).value[iVar5]);
      if ((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar4->master_obj->id == 0x67)) {
        local_4 = local_4 + 1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (this->playerBuildings).numberValue);
  }
  return local_4;
}

// --------------------------------------------------

// Function: numberGranaries
// Address: 004e3140
/* WARNING: Variable defined which should be unmapped: count */
/* public: int __thiscall TribeInformationAIModule::numberGranaries(void) */

int __thiscall TribeInformationAIModule::numberGranaries(TribeInformationAIModule *this)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int count;
  int local_4;
  
  iVar5 = 0;
  local_4 = 0;
  if (0 < (this->playerBuildings).numberValue) {
    do {
      if ((this->playerBuildings).maximumSizeValue + -1 < iVar5) {
        piVar1 = (int *)operator_new(iVar5 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (this->playerBuildings).maximumSizeValue) {
            do {
              if (iVar5 + 1 <= iVar2) break;
              iVar3 = iVar2 + 1;
              piVar1[iVar2] = (this->playerBuildings).value[iVar2];
              iVar2 = iVar3;
            } while (iVar3 < (this->playerBuildings).maximumSizeValue);
          }
          operator_delete((this->playerBuildings).value);
          (this->playerBuildings).value = piVar1;
          (this->playerBuildings).maximumSizeValue = iVar5 + 1;
        }
      }
      pRVar4 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)this->md,(this->playerBuildings).value[iVar5]);
      if ((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar4->master_obj->id == 0x44)) {
        local_4 = local_4 + 1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (this->playerBuildings).numberValue);
  }
  return local_4;
}

// --------------------------------------------------

// Function: amountForageBushesInXTiles
// Address: 004e3210
/* WARNING: Variable defined which should be unmapped: count */
/* public: int __thiscall TribeInformationAIModule::amountForageBushesInXTiles(int,int,int) */

int __thiscall
TribeInformationAIModule::amountForageBushesInXTiles
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3)
{
  int *piVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  float count;
  float dX;
  
  iVar3 = 0;
  if (0 < this->numResources[0]) {
    iVar4 = 0;
    do {
      piVar1 = (int *)((int)&this->resources[0]->id + iVar4);
      if (((*(char *)((int)piVar1 + 0xd) != '\x01') &&
          (pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,*piVar1),
          pRVar2 != (RGE_Static_Object *)0x0)) && (pRVar2->master_obj->id == 0x3b)) {
        __ftol();
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x14;
    } while (iVar3 < this->numResources[0]);
  }
  iVar3 = __ftol();
  return iVar3;
}

// --------------------------------------------------

// Function: amountResourceTypesInXTiles
// Address: 004e32c0
/* WARNING: Variable defined which should be unmapped: count */
/* public: int __thiscall TribeInformationAIModule::amountResourceTypesInXTiles(int,int,int,int) */

int __thiscall
TribeInformationAIModule::amountResourceTypesInXTiles
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3,int param_4)
{
  int *piVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  float count;
  int i;
  int local_4;
  
  iVar3 = 0;
  local_4 = 0;
  if (0 < this->numResources[param_1]) {
    do {
      piVar1 = (int *)((int)&this->resources[param_1]->id + iVar3);
      if (((*(char *)((int)piVar1 + 0xd) != '\x01') &&
          (pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,*piVar1),
          pRVar2 != (RGE_Static_Object *)0x0)) &&
         ((param_1 != 0 || (pRVar2->master_obj->id != 0x3b)))) {
        __ftol();
      }
      local_4 = local_4 + 1;
      iVar3 = iVar3 + 0x14;
    } while (local_4 < this->numResources[param_1]);
  }
  iVar3 = __ftol();
  return iVar3;
}

// --------------------------------------------------

// Function: damagePerSecond
// Address: 004e3390
/* WARNING: Variable defined which should be unmapped: rVal */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: float __thiscall TribeInformationAIModule::damagePerSecond(int,int,int) */

float __thiscall
TribeInformationAIModule::damagePerSecond
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float fVar6;
  float rVal;
  float rateOfFire;
  RGE_Static_Object *unit;
  
  rateOfFire = 0.0;
  pRVar1 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if (pRVar1 != (RGE_Static_Object *)0x0) {
    iVar3 = 0;
    if (0 < this->maxImportantObjectMemory) {
      iVar4 = 0;
      do {
        iVar2 = (**(code **)(*(int *)this->md->_padding_ + 0x18))
                          ((&this->importantObjectMemory->owner)[iVar4]);
        if ((((iVar2 != 0) &&
             (this_00 = MainDecisionAIModule::object
                                  ((MainDecisionAIModule *)this->md,
                                   *(int *)((int)&this->importantObjectMemory->id + iVar4)),
             this_00 != (RGE_Static_Object *)0x0)) && (this_00->object_state < 3)) &&
           (fVar6 = RGE_Static_Object::distance_to_position
                              (this_00,(float)param_2,(float)param_3,this_00->world_z),
           fVar6 <= this_00->master_obj->los)) {
          (**(code **)(pRVar1->_padding_ + 0x104))(this_00);
          fVar5 = (float10)(**(code **)(this_00->_padding_ + 0x100))();
          if ((fVar5 != (float10)_DAT_00575580) && ((float)param_1 != _DAT_00575580)) {
            rateOfFire = (float)param_1 / (float)fVar5 + rateOfFire;
          }
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x24;
      } while (iVar3 < this->maxImportantObjectMemory);
    }
    return rateOfFire;
  }
  return _DAT_00575580;
}

// --------------------------------------------------

// Function: costToLoseUnit
// Address: 004e34c0
/* public: int __thiscall TribeInformationAIModule::costToLoseUnit(int) */

int __thiscall TribeInformationAIModule::costToLoseUnit(TribeInformationAIModule *this,int param_1)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  
  pRVar1 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return -1;
  }
  iVar2 = (**(code **)(*(int *)this->md->_padding_ + 0x58))((int)pRVar1->master_obj->id);
  return iVar2;
}

// --------------------------------------------------

// Function: benefitToKillUnit
// Address: 004e3500
/* public: int __thiscall TribeInformationAIModule::benefitToKillUnit(int) */

int __thiscall
TribeInformationAIModule::benefitToKillUnit(TribeInformationAIModule *this,int param_1)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  
  pRVar1 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return -1;
  }
  iVar2 = (**(code **)(pRVar1->owner->_padding_ + 0x58))((int)pRVar1->master_obj->id);
  return iVar2;
}

// --------------------------------------------------

// Function: inRangeOfUnits
// Address: 004e3530
/* WARNING: Variable defined which should be unmapped: i */
/* public: int __thiscall TribeInformationAIModule::inRangeOfUnits(int,int,int,int) */

int __thiscall
TribeInformationAIModule::inRangeOfUnits
          (TribeInformationAIModule *this,int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  RGE_Static_Object *this_00;
  int iVar2;
  float10 fVar3;
  float fVar4;
  int i;
  int local_4;
  
  iVar2 = 0;
  local_4 = 0;
  if (this->maxImportantObjectMemory < 1) {
    return 0;
  }
  do {
    if (param_1 == -1) {
LAB_004e356b:
      iVar1 = (**(code **)(*(int *)this->md->_padding_ + 0x18))
                        ((&this->importantObjectMemory->owner)[iVar2]);
      if (iVar1 != 0) {
LAB_004e358d:
        this_00 = MainDecisionAIModule::object
                            ((MainDecisionAIModule *)this->md,
                             *(int *)((int)&this->importantObjectMemory->id + iVar2));
        if ((this_00 != (RGE_Static_Object *)0x0) && (this_00->object_state < 3)) {
          fVar4 = RGE_Static_Object::distance_to_position
                            (this_00,(float)param_2,(float)param_3,this_00->world_z);
          fVar3 = (float10)(**(code **)(this_00->_padding_ + 0x10c))();
          if ((param_4 == 0) && (fVar4 < this_00->master_obj->los)) {
            fVar3 = (float10)this_00->master_obj->los;
          }
          if ((float10)fVar4 <= fVar3) {
            return 1;
          }
        }
      }
    }
    else if ((uint)(&this->importantObjectMemory->owner)[iVar2] == param_1) {
      if (param_1 == -1) goto LAB_004e356b;
      goto LAB_004e358d;
    }
    local_4 = local_4 + 1;
    iVar2 = iVar2 + 0x24;
    if (this->maxImportantObjectMemory <= local_4) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: wonderToAttack
// Address: 004e3640
/* public: struct ObjectMemory * __thiscall TribeInformationAIModule::wonderToAttack(int) */

ObjectMemory * __thiscall
TribeInformationAIModule::wonderToAttack(TribeInformationAIModule *this,int param_1)
{
  float fVar1;
  ObjectMemory *pOVar2;
  float fVar3;
  uchar uVar4;
  short sVar5;
  int iVar6;
  RGE_Static_Object *pRVar7;
  RGE_Action *pRVar8;
  float fVar9;
  ObjectMemory *pOVar10;
  int bestState;
  float bestTimer;
  float hitpoints;
  float bestHitpoints;
  int i;
  int local_4;
  
  pOVar10 = (ObjectMemory *)0x0;
  bestTimer = -NAN;
  hitpoints = 0.0;
  i = 0;
  local_4 = 0;
  if (0 < this->maxImportantObjectMemory) {
    bestState = 0;
    do {
      pOVar2 = this->importantObjectMemory;
      if (*(short *)((int)&pOVar2->type + bestState) == 0x114) {
        if (param_1 == -1) {
LAB_004e36a2:
          iVar6 = (**(code **)(*(int *)this->md->_padding_ + 0x18))((&pOVar2->owner)[bestState]);
          if (iVar6 != 0) {
LAB_004e36c3:
            pRVar7 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)this->md,
                                *(int *)((int)&this->importantObjectMemory->id + bestState));
            if (((pRVar7 != (RGE_Static_Object *)0x0) && (pRVar7->object_state < 3)) &&
               (uVar4 = RGE_Action_List::have_action((RGE_Action_List *)pRVar7[2].unitAIValue),
               uVar4 != '\0')) {
              pRVar8 = RGE_Action_List::get_action((RGE_Action_List *)pRVar7[2].unitAIValue);
              sVar5 = (**(code **)(pRVar8->_padding_ + 0x18))();
              if (sVar5 == 0x78) {
                pRVar8 = RGE_Action_List::get_action((RGE_Action_List *)pRVar7[2].unitAIValue);
                fVar9 = (float)(uint)pRVar8->state;
                pRVar8 = RGE_Action_List::get_action((RGE_Action_List *)pRVar7[2].unitAIValue);
                fVar3 = pRVar7->hp;
                fVar1 = pRVar8->timer;
                if (pOVar10 == (ObjectMemory *)0x0) {
                  pOVar10 = (ObjectMemory *)((int)&this->importantObjectMemory->id + bestState);
                  bestTimer = fVar9;
                  hitpoints = fVar1;
                  i = (int)fVar3;
                }
                else if ((bestTimer != 8.40779e-45) || (fVar9 != 2.8026e-45)) {
                  if ((bestTimer == 2.8026e-45) && (fVar9 == 8.40779e-45)) {
                    pOVar10 = (ObjectMemory *)((int)&this->importantObjectMemory->id + bestState);
                    bestTimer = fVar9;
                    hitpoints = fVar1;
                    i = (int)fVar3;
                  }
                  else if (bestTimer == fVar9) {
                    if ((bestTimer != 2.8026e-45) || (fVar3 <= (float)i)) {
                      if ((bestTimer == fVar9) &&
                         ((bestTimer == 8.40779e-45 && (fVar1 < hitpoints)))) {
                        pOVar10 = (ObjectMemory *)
                                  ((int)&this->importantObjectMemory->id + bestState);
                        bestTimer = fVar9;
                        hitpoints = fVar1;
                        i = (int)fVar3;
                      }
                    }
                    else {
                      pOVar10 = (ObjectMemory *)((int)&this->importantObjectMemory->id + bestState);
                      bestTimer = fVar9;
                      hitpoints = fVar1;
                      i = (int)fVar3;
                    }
                  }
                }
              }
            }
          }
        }
        else if ((uint)(&pOVar2->owner)[bestState] == param_1) {
          if (param_1 == -1) goto LAB_004e36a2;
          goto LAB_004e36c3;
        }
      }
      local_4 = local_4 + 1;
      bestState = bestState + 0x24;
    } while (local_4 < this->maxImportantObjectMemory);
  }
  return pOVar10;
}

// --------------------------------------------------

// Function: ruinToCapture
// Address: 004e3840
/* WARNING: Variable defined which should be unmapped: bestMem */
/* public: struct ObjectMemory * __thiscall TribeInformationAIModule::ruinToCapture(int) */

ObjectMemory * __thiscall
TribeInformationAIModule::ruinToCapture(TribeInformationAIModule *this,int param_1)
{
  short sVar1;
  ObjectMemory *pOVar2;
  RGE_Static_Object *this_00;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iVar6;
  ObjectMemory *bestMem;
  int bestValue;
  int i;
  int local_8;
  
  this_00 = MainDecisionAIModule::object
                      ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  iVar6 = 0;
  i = -1;
  bestValue = 0;
  local_8 = 0;
  if (0 < this->maxImportantObjectMemory) {
    do {
      pOVar2 = this->importantObjectMemory;
      sVar1 = *(short *)((int)&pOVar2->type + iVar6);
      if ((sVar1 == 0x9e) || (sVar1 == 0xa3)) {
        if (param_1 == -1) {
LAB_004e38c3:
          iVar3 = (**(code **)(*(int *)this->md->_padding_ + 0x18))((&pOVar2->owner)[iVar6]);
          if (iVar3 != 0) {
LAB_004e38e6:
            pRVar4 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)this->md,
                                *(int *)((int)&this->importantObjectMemory->id + iVar6));
            if ((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar4->object_state < 3)) {
              iVar3 = numberUnitsWithinXTiles
                                (this,param_1,(uint)(&this->importantObjectMemory->x)[iVar6],
                                 (uint)(&this->importantObjectMemory->y)[iVar6],5);
              if (this_00 != (RGE_Static_Object *)0x0) {
                pOVar2 = this->importantObjectMemory;
                RGE_Static_Object::distance_to_position
                          (this_00,(float)(&pOVar2->x)[iVar6],(float)(&pOVar2->y)[iVar6],
                           (float)(&pOVar2->z)[iVar6]);
                iVar5 = __ftol();
                iVar3 = iVar5 * iVar3;
              }
              if ((bestValue == 0) || (iVar3 < i)) {
                bestValue = (int)&this->importantObjectMemory->id + iVar6;
                i = iVar3;
              }
            }
          }
        }
        else if ((uint)(&pOVar2->owner)[iVar6] == param_1) {
          if (param_1 == -1) goto LAB_004e38c3;
          goto LAB_004e38e6;
        }
      }
      local_8 = local_8 + 1;
      iVar6 = iVar6 + 0x24;
    } while (local_8 < this->maxImportantObjectMemory);
  }
  return (ObjectMemory *)bestValue;
}

// --------------------------------------------------

// Function: artifactToCapture
// Address: 004e39d0
/* WARNING: Variable defined which should be unmapped: bestMem */
/* public: struct ObjectMemory * __thiscall TribeInformationAIModule::artifactToCapture(int) */

ObjectMemory * __thiscall
TribeInformationAIModule::artifactToCapture(TribeInformationAIModule *this,int param_1)
{
  RGE_Visible_Map *this_00;
  ObjectMemory *pOVar1;
  uchar uVar2;
  RGE_Static_Object *this_01;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iVar6;
  ObjectMemory *bestMem;
  int bestValue;
  int i;
  RGE_Visible_Map *vMap;
  int artifactY;
  RGE_Static_Object *townCenter;
  
  this_01 = MainDecisionAIModule::object
                      ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  iVar6 = 0;
  i = -1;
  bestValue = 0;
  this_00 = *(RGE_Visible_Map **)(this->md->_padding_ + 0x38);
  vMap = (RGE_Visible_Map *)0x0;
  if (0 < this->maxImportantObjectMemory) {
    do {
      pOVar1 = this->importantObjectMemory;
      if (*(short *)((int)&pOVar1->type + iVar6) == 0x9f) {
        if (param_1 == -1) {
LAB_004e3a5e:
          iVar3 = (**(code **)(*(int *)this->md->_padding_ + 0x18))((&pOVar1->owner)[iVar6]);
          if (iVar3 != 0) {
LAB_004e3a7d:
            pRVar4 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)this->md,
                                *(int *)((int)&this->importantObjectMemory->id + iVar6));
            if ((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar4->object_state < 3)) {
              iVar3 = __ftol();
              iVar5 = __ftol();
              uVar2 = RGE_Visible_Map::get_visible(this_00,iVar3,iVar5);
              if (uVar2 != '\0') {
                uVar2 = __ftol();
                (&this->importantObjectMemory->x)[iVar6] = uVar2;
                uVar2 = __ftol();
                (&this->importantObjectMemory->y)[iVar6] = uVar2;
                uVar2 = __ftol();
                (&this->importantObjectMemory->z)[iVar6] = uVar2;
                iVar3 = numberUnitsWithinXTiles(this,param_1,iVar3,iVar5,5);
                if (this_01 != (RGE_Static_Object *)0x0) {
                  RGE_Static_Object::distance_to_object(this_01,pRVar4);
                  iVar5 = __ftol();
                  iVar3 = iVar5 * iVar3;
                }
                if ((bestValue == 0) || (iVar3 < i)) {
                  bestValue = (int)&this->importantObjectMemory->id + iVar6;
                  i = iVar3;
                }
              }
            }
          }
        }
        else if ((uint)(&pOVar1->owner)[iVar6] == param_1) {
          if (param_1 == -1) goto LAB_004e3a5e;
          goto LAB_004e3a7d;
        }
      }
      vMap = (RGE_Visible_Map *)((int)&vMap->map_offsets + 1);
      iVar6 = iVar6 + 0x24;
    } while ((int)vMap < this->maxImportantObjectMemory);
  }
  return (ObjectMemory *)bestValue;
}

// --------------------------------------------------

// Function: resourceTypeToPlaceDropsiteBy
// Address: 004e3b80
/* public: int __thiscall TribeInformationAIModule::resourceTypeToPlaceDropsiteBy(int) */

int __thiscall
TribeInformationAIModule::resourceTypeToPlaceDropsiteBy(TribeInformationAIModule *this,int param_1)
{
  int iVar1;
  
  if (param_1 == 2) {
    return 0;
  }
                    /* language.dll match for 0x67: "Comic Sans MS" */
  iVar1 = (**(code **)((this->md->buildAI)._padding_ + 0x48))(0x67,0);
  if ((iVar1 == 0) && (this->closestDropsiteValue[1] != -1)) {
    return 1;
  }
  if (param_1 == 1) {
    if (this->closestDropsiteValue[1] != -1) {
      iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xa4);
      if (iVar1 < this->closestDropsiteValue[1]) {
        return 1;
      }
    }
    if (this->closestDropsiteValue[3] != -1) {
      iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xa6);
      if (iVar1 < this->closestDropsiteValue[3]) {
        return 3;
      }
    }
    if ((this->closestDropsiteValue[0] != -1) && (0xf < this->closestDropsiteValue[0])) {
      return 2;
    }
    if (this->closestDropsiteValue[2] != -1) {
      iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xa5);
      if (iVar1 < this->closestDropsiteValue[2]) {
        return 2;
      }
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: dropsitesWithinRequiredDistance
// Address: 004e3c90
/* public: int __thiscall TribeInformationAIModule::dropsitesWithinRequiredDistance(int &,int,int)
    */

int __thiscall
TribeInformationAIModule::dropsitesWithinRequiredDistance
          (TribeInformationAIModule *this,int *param_1,int param_2,int param_3)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *pvVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined4 *unaff_FS_OFFSET;
  int numApplicableResources;
  int local_2c;
  int a;
  ManagedArray<int> dropsites;
  int local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00560578;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar9 = 0;
  *param_1 = 0;
  local_2c = 0;
  dropsites.numberValue = 0;
  local_10 = 0;
  local_4 = 0;
  dropsites.value = (int *)0x0;
  pvVar6 = (void *)0x0;
  if (0 < this->numResources[param_2]) {
    numApplicableResources = 0;
    do {
      if (((&this->resources[param_2]->gone)[numApplicableResources] != '\x01') &&
         (pRVar1 = MainDecisionAIModule::object
                             ((MainDecisionAIModule *)this->md,
                              *(int *)((int)&this->resources[param_2]->id + numApplicableResources))
         , pRVar1 != (RGE_Static_Object *)0x0)) {
        local_2c = local_2c + 1;
        if ((int)(uint)(&this->resources[param_2]->dropDistance)[numApplicableResources] <= param_3)
{
          iVar2 = 0;
          piVar7 = (int *)dropsites.numberValue;
          if (0 < iVar9) {
            do {
              if (local_10 <= iVar2) break;
              if (*piVar7 ==
                  *(int *)((int)&this->resources[param_2]->dropsiteID + numApplicableResources))
              goto LAB_004e3e1c;
              iVar2 = iVar2 + 1;
              piVar7 = piVar7 + 1;
            } while (iVar2 < iVar9);
          }
          *param_1 = *param_1 + 1;
          iVar2 = *(int *)((int)&this->resources[param_2]->dropsiteID + numApplicableResources);
          iVar3 = 0;
          piVar7 = (int *)dropsites.numberValue;
          if (0 < iVar9) {
            do {
              if (local_10 <= iVar3) break;
              if (*piVar7 == iVar2) goto LAB_004e3e1c;
              iVar3 = iVar3 + 1;
              piVar7 = piVar7 + 1;
            } while (iVar3 < iVar9);
          }
          if (local_10 + -1 < iVar9) {
            iVar3 = iVar9 + 1;
            puVar4 = (undefined4 *)operator_new(iVar3 * 4);
            if (puVar4 != (undefined4 *)0x0) {
              iVar8 = 0;
              if (0 < local_10) {
                puVar5 = puVar4;
                do {
                  if (iVar3 <= iVar8) break;
                  iVar8 = iVar8 + 1;
                  *puVar5 = *(undefined4 *)((dropsites.numberValue - (int)puVar4) + (int)puVar5);
                  puVar5 = puVar5 + 1;
                } while (iVar8 < local_10);
              }
              operator_delete((void *)dropsites.numberValue);
              dropsites.numberValue = (int)puVar4;
              local_10 = iVar3;
            }
          }
          iVar9 = iVar9 + 1;
          *(int *)(dropsites.numberValue + -4 + iVar9 * 4) = iVar2;
        }
      }
LAB_004e3e1c:
      dropsites.value = (int *)((int)dropsites.value + 1);
      numApplicableResources = numApplicableResources + 0x14;
      pvVar6 = (void *)dropsites.numberValue;
    } while ((int)dropsites.value < this->numResources[param_2]);
  }
  local_4 = 0xffffffff;
  if (local_2c < 1) {
    if (pvVar6 != (void *)0x0) {
      operator_delete(pvVar6);
    }
    iVar9 = 0;
  }
  else {
    if (pvVar6 != (void *)0x0) {
      operator_delete(pvVar6);
    }
    iVar9 = 1;
  }
  *unaff_FS_OFFSET = local_c;
  return iVar9;
}

// --------------------------------------------------

// Function: numberAvailableStoragePits
// Address: 004e3e90
/* public: int __thiscall TribeInformationAIModule::numberAvailableStoragePits(int) */

int __thiscall
TribeInformationAIModule::numberAvailableStoragePits(TribeInformationAIModule *this,int param_1)
{
  TribeMainDecisionAIModule *this_00;
  uchar uVar1;
  uchar uVar2;
  int iVar3;
  RGE_Static_Object *this_01;
  RGE_Static_Object *pRVar4;
  int iVar5;
  
  this_00 = this->md;
  iVar3 = __ftol();
  iVar3 = iVar3 + -1;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (3 < iVar3) {
    iVar3 = 3;
  }
  if (this->dropsitesByAge[param_1][iVar3] != 0) {
    this_01 = MainDecisionAIModule::object
                        ((MainDecisionAIModule *)this_00,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
    if ((this_01 != (RGE_Static_Object *)0x0) &&
       (pRVar4 = MainDecisionAIModule::object
                           ((MainDecisionAIModule *)this->md,
                            this->closestDropsiteResourceID[param_1]),
       pRVar4 != (RGE_Static_Object *)0x0)) {
      uVar1 = RGE_Static_Object::currentZone(this_01);
      iVar3 = __ftol();
      iVar5 = __ftol();
      uVar2 = RGE_Static_Object::lookupZone(this_01,iVar5,iVar3);
      if (uVar1 != uVar2) {
        return 0;
      }
    }
    iVar3 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,param_1 + 0xa3);
    return (uint)(iVar3 < this->closestDropsiteValue[param_1]);
  }
  return 0;
}

// --------------------------------------------------

// Function: numberAvailableGranaries
// Address: 004e3f80
/* public: int __thiscall TribeInformationAIModule::numberAvailableGranaries(void) */

int __thiscall TribeInformationAIModule::numberAvailableGranaries(TribeInformationAIModule *this)
{
  uchar uVar1;
  uchar uVar2;
  RGE_Static_Object *this_00;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  
  if (this->closestDropsiteValue[0] == -1) {
    return 0;
  }
  this_00 = MainDecisionAIModule::object
                      ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  if (this_00 != (RGE_Static_Object *)0x0) {
    pRVar3 = MainDecisionAIModule::object
                       ((MainDecisionAIModule *)this->md,this->closestDropsiteResourceID[0]);
    if (pRVar3 != (RGE_Static_Object *)0x0) {
      uVar1 = RGE_Static_Object::currentZone(this_00);
      iVar4 = __ftol();
      iVar5 = __ftol();
      uVar2 = RGE_Static_Object::lookupZone(this_00,iVar5,iVar4);
      if (uVar1 != uVar2) {
        return 0;
      }
    }
  }
  iVar4 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xa3);
  return (uint)(iVar4 < this->closestDropsiteValue[0]);
}

// --------------------------------------------------

// Function: lookAtMap
// Address: 004e4040
/* public: void __thiscall TribeInformationAIModule::lookAtMap(void) */

void __thiscall TribeInformationAIModule::lookAtMap(TribeInformationAIModule *this)
{
  int iVar1;
  undefined4 *puVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  int numberTreesOnTile;
  int x;
  int local_18;
  RGE_Map *gMap;
  int y;
  int local_c;
  int tileType;
  
  iVar1 = *(int *)(*(int *)(this->md->_padding_ + 0x3c) + 0x28);
  local_18 = 0;
  if (0 < this->mapXSizeValue) {
    gMap = (RGE_Map *)0x0;
    numberTreesOnTile = 0;
    do {
      iVar5 = this->mapYSizeValue;
      local_c = 0;
      if (0 < iVar5) {
        tileType = 0;
        do {
          bVar6 = *(byte *)(*(int *)(*(int *)(iVar1 + 0x8d8c) + tileType) + 5 + numberTreesOnTile) &
                  0x1f;
          if (this->mapXSizeValue != -1) {
            iVar4 = (int)gMap / this->mapXSizeValue;
            this->quadrantLog[iVar4][tileType / iVar5].numberExploredTiles =
                 this->quadrantLog[iVar4][tileType / iVar5].numberExploredTiles + 1;
          }
          InfluenceMap::setValue(&this->pathMap,local_18,local_c,'\0');
          x = 0;
          for (puVar2 = *(undefined4 **)
                         (*(int *)(*(int *)(iVar1 + 0x8d8c) + tileType) + 0x10 + numberTreesOnTile);
              puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[1]) {
            pRVar3 = (RGE_Static_Object *)*puVar2;
            iVar4 = (int)pRVar3->master_obj->object_group;
            iVar5 = importantObject(this,iVar4);
            if (iVar5 == 1) {
              addImportantObject(this,pRVar3,0);
            }
            if (iVar4 == 0xf) {
              x = x + 1;
            }
          }
          if ((0 < x) && ((((bVar6 == 10 || (bVar6 == 0x13)) || (bVar6 == 0xd)) || (bVar6 == 0x14)))
             ) {
            this->numberFoundForestTilesValue = this->numberFoundForestTilesValue + 1;
          }
          iVar5 = this->mapYSizeValue;
          local_c = local_c + 1;
          tileType = tileType + 4;
        } while (local_c < iVar5);
      }
      local_18 = local_18 + 1;
      numberTreesOnTile = numberTreesOnTile + 0x18;
      gMap = (RGE_Map *)&gMap->map;
    } while (local_18 < this->mapXSizeValue);
  }
  return;
}

// --------------------------------------------------

// Function: damageInflictedPerSecond
// Address: 004e41c0
/* WARNING: Variable defined which should be unmapped: rVal */
/* public: float __thiscall TribeInformationAIModule::damageInflictedPerSecond(class TacticalAIGroup
   *,class RGE_Static_Object *) */

float __thiscall
TribeInformationAIModule::damageInflictedPerSecond
          (TribeInformationAIModule *this,TacticalAIGroup *param_1,RGE_Static_Object *param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  float10 fVar4;
  float rVal;
  float local_4;
  
  local_4 = 0.0;
  iVar3 = 0;
  iVar1 = TacticalAIGroup::numberUnits(param_1);
  if (0 < iVar1) {
    do {
      iVar1 = TacticalAIGroup::unit(param_1,iVar3);
      pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar1);
      if (pRVar2 != (RGE_Static_Object *)0x0) {
        (**(code **)(param_2->_padding_ + 0x104))(pRVar2);
        fVar4 = (float10)(**(code **)(pRVar2->_padding_ + 0x100))();
        local_4 = (float)((float10)(float)param_1 / fVar4 + (float10)local_4);
      }
      iVar3 = iVar3 + 1;
      iVar1 = TacticalAIGroup::numberUnits(param_1);
    } while (iVar3 < iVar1);
  }
  return local_4;
}

// --------------------------------------------------

// Function: damageInflictedPerSecond
// Address: 004e4240
/* WARNING: Variable defined which should be unmapped: rVal */
/* public: float __thiscall TribeInformationAIModule::damageInflictedPerSecond(int *,int,class
   RGE_Static_Object *) */

float __thiscall
TribeInformationAIModule::damageInflictedPerSecond
          (TribeInformationAIModule *this,int *param_1,int param_2,RGE_Static_Object *param_3)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  float10 fVar3;
  float rVal;
  float local_4;
  
  local_4 = 0.0;
  iVar2 = param_2;
  if (0 < param_2) {
    do {
      pRVar1 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,*param_1);
      if (pRVar1 != (RGE_Static_Object *)0x0) {
        (**(code **)(param_3->_padding_ + 0x104))(pRVar1);
        fVar3 = (float10)(**(code **)(pRVar1->_padding_ + 0x100))();
        local_4 = (float)((float10)(float)param_2 / fVar3 + (float10)local_4);
      }
      param_1 = param_1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return local_4;
}

// --------------------------------------------------

// Function: timeToBeKilled
// Address: 004e42b0
/* WARNING: Variable defined which should be unmapped: rVal */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: float __thiscall TribeInformationAIModule::timeToBeKilled(class TacticalAIGroup *,class
   RGE_Static_Object *) */

float __thiscall
TribeInformationAIModule::timeToBeKilled
          (TribeInformationAIModule *this,TacticalAIGroup *param_1,RGE_Static_Object *param_2)
{
  float fVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float rVal;
  float local_4;
  
  local_4 = 0.0;
  iVar6 = 0;
  iVar2 = TacticalAIGroup::numberUnits(param_1);
  if (0 < iVar2) {
    do {
      iVar2 = TacticalAIGroup::unit(param_1,iVar6);
      pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar2);
      if (pRVar3 != (RGE_Static_Object *)0x0) {
        iVar2 = __ftol();
        iVar4 = __ftol();
        iVar5 = TacticalAIGroup::unit(param_1,iVar6);
        fVar7 = damagePerSecond(this,iVar5,iVar4,iVar2);
        fVar1 = _DAT_005755c0;
        if (fVar7 != _DAT_00575580) {
          fVar1 = pRVar3->hp / fVar7;
        }
        local_4 = fVar1 + local_4;
      }
      iVar6 = iVar6 + 1;
      iVar2 = TacticalAIGroup::numberUnits(param_1);
    } while (iVar6 < iVar2);
  }
  return local_4;
}

// --------------------------------------------------

// Function: timeToBeKilled
// Address: 004e4350
/* WARNING: Variable defined which should be unmapped: rVal */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: float __thiscall TribeInformationAIModule::timeToBeKilled(int *,int,class
   RGE_Static_Object *) */

float __thiscall
TribeInformationAIModule::timeToBeKilled
          (TribeInformationAIModule *this,int *param_1,int param_2,RGE_Static_Object *param_3)
{
  float fVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float rVal;
  float local_4;
  
  local_4 = 0.0;
  if (0 < param_2) {
    do {
      pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,*param_1);
      if (pRVar2 != (RGE_Static_Object *)0x0) {
        iVar3 = __ftol();
        iVar4 = __ftol();
        fVar5 = damagePerSecond(this,*param_1,iVar4,iVar3);
        fVar1 = _DAT_005755c0;
        if (fVar5 != _DAT_00575580) {
          fVar1 = pRVar2->hp / fVar5;
        }
        local_4 = fVar1 + local_4;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return local_4;
}

// --------------------------------------------------

// Function: closestDropsiteResID
// Address: 004e43e0
/* public: int __thiscall TribeInformationAIModule::closestDropsiteResID(int)const  */

int __thiscall
TribeInformationAIModule::closestDropsiteResID(TribeInformationAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 4)) {
    return this->closestDropsiteResourceID[param_1];
  }
  return -1;
}

// --------------------------------------------------

// Function: calculatePlayVariation
// Address: 004e4400
/* WARNING: Variable defined which should be unmapped: totalPlays */
/* public: int __thiscall TribeInformationAIModule::calculatePlayVariation(int) */

int __thiscall
TribeInformationAIModule::calculatePlayVariation(TribeInformationAIModule *this,int param_1)
{
  int iVar1;
  int totalPlays;
  
  iVar1 = 16000;
  do {
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = __ftol();
  return 100 - iVar1;
}

// --------------------------------------------------

// Function: convertUnitToIntType
// Address: 004e4450
/* public: int __thiscall TribeInformationAIModule::convertUnitToIntType(class RGE_Static_Object
   *)const  */

int __thiscall
TribeInformationAIModule::convertUnitToIntType
          (TribeInformationAIModule *this,RGE_Static_Object *param_1)
{
  short sVar1;
  short sVar2;
  
  sVar1 = param_1->master_obj->object_group;
  sVar2 = param_1->master_obj->id;
  if (sVar1 == 0x12) {
    return 5;
  }
  if (sVar1 == 0x1c) {
    return 3;
  }
  if (sVar1 == 0xd) {
    return 4;
  }
  if (sVar1 == 0xc) {
    return 2;
  }
  if (sVar1 == 0x23) {
    return 7;
  }
  if (sVar2 == 0x49) {
    return 0;
  }
  if (sVar2 == 0x4b) {
    return 1;
  }
  if (((sVar2 != 4) && (sVar2 != 5)) && (sVar2 != 0x27)) {
    if (sVar2 == 0x29) {
      return 10;
    }
    if ((sVar2 != 0x2e) && (sVar2 != 0x19)) {
      return (-(uint)(sVar1 != 0x16) & 0xfffffff7) + 8;
    }
    return 9;
  }
  return 6;
}

// --------------------------------------------------

// Function: loadUnitHistory
// Address: 004e4500
// [HELPER] s_learn_Default_uh: "learn\Default.uh"
// [HELPER] s_learn__s_uh: "learn\%s.uh"
/* WARNING: Variable defined which should be unmapped: historyFileName */
/* public: void __thiscall TribeInformationAIModule::loadUnitHistory(void) */

void __thiscall TribeInformationAIModule::loadUnitHistory(TribeInformationAIModule *this)
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char historyFileName [256];
  
  if (rge_base_game->player_game_info == (RGE_Game_Info *)0x0) {
    uVar4 = 0xffffffff;
    pcVar2 = historyFileName;
    pcVar6 = &s_learn_Default_uh;
    do {
      pcVar7 = pcVar6;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar7 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar7;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar6 = pcVar7 + -uVar4;
    for (uVar5 = uVar4 >> 2; pcVar2 = pcVar2 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar2 = pcVar2 + 1;
    }
  }
  else {
    pcVar2 = RGE_Game_Info::get_current_player_name(rge_base_game->player_game_info);
    sprintf(historyFileName + 4,s_learn__s_uh,pcVar2);
  }
  iVar3 = rge_open(historyFileName + 4,0x8000);
  if (iVar3 != -1) {
    rge_read(iVar3,this->unitHistory,0x2c);
    rge_close(iVar3);
  }
  return;
}

// --------------------------------------------------

// Function: unitsThatAreMostBuilt
// Address: 004e45a0
/* public: void __thiscall TribeInformationAIModule::unitsThatAreMostBuilt(int &,int &) */

void __thiscall
TribeInformationAIModule::unitsThatAreMostBuilt
          (TribeInformationAIModule *this,int *param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = this->unitHistory;
  iVar4 = -1;
  *param_1 = -1;
  iVar1 = 0;
  piVar2 = piVar3;
  do {
    if ((iVar4 == -1) || (iVar4 < *piVar2)) {
      *param_1 = iVar1;
      iVar4 = *piVar2;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0xb);
  iVar4 = -1;
  iVar1 = 0;
  *param_2 = -1;
  do {
    if ((iVar1 != *param_1) && ((iVar4 == -1 || (iVar4 < *piVar3)))) {
      *param_2 = iVar1;
      iVar4 = *piVar3;
    }
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar1 < 0xb);
  return;
}

// --------------------------------------------------

// Function: unitsThatAreLeastBuilt
// Address: 004e4610
/* public: void __thiscall TribeInformationAIModule::unitsThatAreLeastBuilt(int &,int &) */

void __thiscall
TribeInformationAIModule::unitsThatAreLeastBuilt
          (TribeInformationAIModule *this,int *param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = this->unitHistory;
  iVar4 = -1;
  *param_1 = 0x7fffffff;
  iVar1 = 0;
  piVar2 = piVar3;
  do {
    if ((iVar4 == -1) || (*piVar2 < iVar4)) {
      *param_1 = iVar1;
      iVar4 = *piVar2;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0xb);
  iVar4 = -1;
  iVar1 = 0;
  *param_2 = 0x7fffffff;
  do {
    if ((iVar1 != *param_1) && ((iVar4 == -1 || (*piVar3 < iVar4)))) {
      *param_2 = iVar1;
      iVar4 = *piVar3;
    }
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar1 < 0xb);
  return;
}

// --------------------------------------------------

// Function: acceptablePotentialDropsiteArea
// Address: 004e4680
/* WARNING: Variable defined which should be unmapped: i */
/* public: int __thiscall TribeInformationAIModule::acceptablePotentialDropsiteArea(int,int) */

int __thiscall
TribeInformationAIModule::acceptablePotentialDropsiteArea
          (TribeInformationAIModule *this,int param_1,int param_2)
{
  short sVar1;
  ObjectMemory *pOVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int i;
  int local_4;
  
  iVar3 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xca);
  iVar4 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xca);
  iVar7 = 0;
  local_4 = 0;
  if (this->maxImportantObjectMemory < 1) {
    return 1;
  }
  do {
    iVar5 = (**(code **)(*(int *)this->md->_padding_ + 0x18))
                      ((&this->importantObjectMemory->owner)[iVar7]);
    if (iVar5 != 0) {
      pOVar2 = this->importantObjectMemory;
      sVar1 = *(short *)((int)&pOVar2->type + iVar7);
      if (((((sVar1 == 0x6d) || (sVar1 == 0x67)) || (sVar1 == 0x44)) ||
          (((sVar1 == 0x4f || (sVar1 == 199)) || (sVar1 == 0x45)))) &&
         (iVar5 = (uint)(&pOVar2->x)[iVar7] - param_1, iVar6 = (uint)(&pOVar2->y)[iVar7] - param_2,
         iVar5 * iVar5 + iVar6 * iVar6 <= iVar3 * iVar4)) {
        return 0;
      }
    }
    local_4 = local_4 + 1;
    iVar7 = iVar7 + 0x24;
    if (this->maxImportantObjectMemory <= local_4) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: percentTilesExploredInPositionQuadrant
// Address: 004e4790
/* public: int __thiscall TribeInformationAIModule::percentTilesExploredInPositionQuadrant(int,int)
    */

int __thiscall
TribeInformationAIModule::percentTilesExploredInPositionQuadrant
          (TribeInformationAIModule *this,int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = this->mapXSizeValue;
  if (iVar1 == -1) {
    return 0;
  }
  iVar2 = ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) * this->mapYSizeValue;
  return (this->quadrantLog[(param_1 << 2) / iVar1][(param_2 * 4) / this->mapYSizeValue].
          numberExploredTiles * 100) / ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2);
}

// --------------------------------------------------

