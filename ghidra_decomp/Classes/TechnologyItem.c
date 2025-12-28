// Class: TechnologyItem
// Size:  0x54
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] `scalar_deleting_destructor'
// [02] loggingHistory
// [03] setLogHistory
// [04] toggleLogHistory
// [05] setHistoryFilename
// [06] loggingCommonHistory
// [07] setLogCommonHistory
// [08] toggleLogCommonHistory
// [09] loadState
// [10] saveState
// [11] gleanState
// [12] processMessage
// [13] update
// [14] setCallbackMessage
// [15] filterOutMessage
// [16] save
// [17] `scalar_deleting_destructor'
// [18] save
// [19] load
// [20] owner
// [21] order
// [22] notify
// [23] notifyCommander
// [24] notifyCommander
// [25] search
// [26] importantWhenDead
// [27] retryableOrder
// [28] actionRequiresLiveTarget
// [29] bestUnitToAttack
// [30] mostDangerousEnemy
// [31] weakestEnemy
// [32] closestAttacker
// [33] closestObject
// [34] closestResourceObject
// [35] closestUndiscoveredTile
// [36] logDebug
// [37] canAttackUnit
// [38] canAttackUnitAtNeutrality
// [39] stopObject
// [40] attackObject
// [41] attackRoundupObject
// [42] huntObject
// [43] gatherObject
// [44] convertObject
// [45] healObject
// [46] repairObject
// [47] buildObject
// [48] tradeWithObject
// [49] explore
// [50] enterObject
// [51] unload
// [52] transportObject
// [53] moveTo
// [54] moveTo
// [55] moveTo
// [56] evasiveMoveTo
// [57] intelligentEvasiveMoveTo
// [58] runAwayFromAttackers
// [59] followObject
// [60] defendObject
// [61] defendPosition
// [62] seekAndDestroy
// [63] exploreAndDestroy
// [64] importantObject
// [65] convertToLOSResourceType
// [66] canConvert
// [67] processOrder
// [68] processNotify
// [69] processGroupNotify
// [70] processIdle
// [71] processMisc
// [72] processRetryableOrder
//
// Member Layout:
// [0x004] TechnologyItem * next
// [0x008] TechnologyItem * prev
// [0x00C] int idValue
// [0x010] char[64] nameValue (sz: 0x40)
// [0x050] ResourceItem * resourceCostValue
// ----------------------------------------------------------------

// Function: TechnologyItem
// Address: 00412bb0
// [HELPER] s_: ""
TechnologyItem * __thiscall TechnologyItem::TechnologyItem(TechnologyItem *this)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  this->next = (TechnologyItem *)0x0;
  this->prev = (TechnologyItem *)0x0;
  this->idValue = 0;
  this->resourceCostValue = (ResourceItem *)0x0;
  this->_padding_ = (int)&_vftable_;
  pcVar4 = s_;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = this->nameValue;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00412c00
void * __thiscall TechnologyItem::_scalar_deleting_destructor_(TechnologyItem *this,uint param_1)
{
  ~TechnologyItem(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TechnologyItem
// Address: 00412c20
TechnologyItem * __thiscall
TechnologyItem::TechnologyItem(TechnologyItem *this,int param_1,char *param_2,ResourceItem param_3)
{
  char cVar1;
  ResourceItem *pRVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055c853;
  *unaff_FS_OFFSET = &local_c;
  local_4 = 0;
  this->next = (TechnologyItem *)0x0;
  this->prev = (TechnologyItem *)0x0;
  this->idValue = param_1;
  this->_padding_ = (int)&_vftable_;
  pRVar2 = (ResourceItem *)operator_new(0x70);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pRVar2 == (ResourceItem *)0x0) {
    pRVar2 = (ResourceItem *)0x0;
  }
  else {
    pRVar2 = (ResourceItem *)ResourceItem::ResourceItem(pRVar2,&param_3);
  }
  this->resourceCostValue = pRVar2;
  uVar3 = 0xffffffff;
  do {
    pcVar5 = param_2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  local_4 = 0xffffffff;
  pcVar5 = pcVar5 + -uVar3;
  pcVar6 = this->nameValue;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  ResourceItem::~ResourceItem(&param_3);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: TechnologyItem
// Address: 00412cd0
TechnologyItem * __thiscall
TechnologyItem::TechnologyItem(TechnologyItem *this,TechnologyItem *param_1)
{
  char cVar1;
  int iVar2;
  ResourceItem *pRVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c86b;
  *unaff_FS_OFFSET = &local_c;
  this->next = (TechnologyItem *)0x0;
  this->prev = (TechnologyItem *)0x0;
  iVar2 = param_1->idValue;
  this->_padding_ = (int)&_vftable_;
  this->idValue = iVar2;
  pRVar3 = (ResourceItem *)operator_new(0x70);
  local_4 = 0;
  if (pRVar3 == (ResourceItem *)0x0) {
    pRVar3 = (ResourceItem *)0x0;
  }
  else {
    pRVar3 = (ResourceItem *)ResourceItem::ResourceItem(pRVar3,param_1->resourceCostValue);
  }
  this->resourceCostValue = pRVar3;
  uVar4 = 0xffffffff;
  pcVar6 = param_1->nameValue;
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
  pcVar7 = this->nameValue;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~TechnologyItem
// Address: 00412d70
void __thiscall TechnologyItem::~TechnologyItem(TechnologyItem *this)
{
  this->_padding_ = (int)&_vftable_;
  if (this->resourceCostValue != (ResourceItem *)0x0) {
    (**(code **)this->resourceCostValue->_padding_)(1);
  }
  return;
}

// --------------------------------------------------

// Function: id
// Address: 00412e10
int __thiscall TechnologyItem::id(TechnologyItem *this)
{
  return this->idValue;
}

// --------------------------------------------------

// Function: name
// Address: 00412e20
char * __thiscall TechnologyItem::name(TechnologyItem *this)
{
  return this->nameValue;
}

// --------------------------------------------------

// Function: resourceCost
// Address: 00412e30
ResourceItem * __thiscall TechnologyItem::resourceCost(TechnologyItem *this)
{
  return this->resourceCostValue;
}

// --------------------------------------------------

