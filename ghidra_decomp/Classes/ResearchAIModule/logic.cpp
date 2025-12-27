// Class: ResearchAIModule
// Function: ResearchAIModule
// Address: 00411670
// [HELPER] s_: ""
// [HELPER] s_Research_AI: "Research AI"
/* public: __thiscall ResearchAIModule::ResearchAIModule(void *,int) */

ResearchAIModule * __thiscall
ResearchAIModule::ResearchAIModule(ResearchAIModule *this,void *param_1,int param_2)
{
  TechnologyItem *this_00;
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c758;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  AIModule::AIModule((AIModule *)this,s_Research_AI,0x3ee,param_2,param_1);
  this_00 = &this->techTree;
  local_4 = 0;
  this->md = (MainDecisionAIModule *)0x0;
  TechnologyItem::TechnologyItem(this_00);
  this->techTreeLengthValue = 0;
  uVar2 = 0xffffffff;
  this->_padding_ = (int)&_vftable_;
  (this->techTree).next = this_00;
  (this->techTree).prev = this_00;
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
  pcVar5 = this->techTreeNameValue;
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
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00411720
/* public: virtual void * __thiscall ResearchAIModule::`scalar deleting destructor'(unsigned int) */

void * __thiscall
ResearchAIModule::_scalar_deleting_destructor_(ResearchAIModule *this,uint param_1)
{
  ~ResearchAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ResearchAIModule
// Address: 00411740
// [HELPER] s_Research_AI: "Research AI"
/* WARNING: Variable defined which should be unmapped: tempInt */
/* public: __thiscall ResearchAIModule::ResearchAIModule(int,int) */

ResearchAIModule * __thiscall
ResearchAIModule::ResearchAIModule(ResearchAIModule *this,int param_1,int param_2)
{
  TechnologyItem *pTVar1;
  ResourceItem RVar2;
  TechnologyItem *pTVar3;
  int iVar4;
  int *piVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined1 in_stack_fffffdd8 [92];
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int tempInt;
  int i;
  int typeID;
  int local_1a0;
  TechnologyItem *local_19c;
  ResearchAIModule *local_198;
  int rc [4];
  ResourceItem newRCost;
  char name [257];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c7a5;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar6 = 0x41177f;
  local_198 = this;
  AIModule::AIModule((AIModule *)this,s_Research_AI,0x3ee,param_1,(void *)0x0);
  pTVar3 = &this->techTree;
  local_4 = 0;
  this->md = (MainDecisionAIModule *)0x0;
  TechnologyItem::TechnologyItem(pTVar3);
  piVar5 = &this->techTreeLengthValue;
  local_4 = CONCAT31(local_4._1_3_,1);
  *piVar5 = 0;
  this->_padding_ = (int)&_vftable_;
  (this->techTree).next = pTVar3;
  (this->techTree).prev = pTVar3;
  rge_read(param_2,piVar5,4);
  rge_read(param_2,&i,4);
  rge_read(param_2,this->techTreeNameValue,i);
  typeID = 0;
  this->techTreeNameValue[i] = '\0';
  if (0 < *piVar5) {
    do {
      rge_read(param_2,&i,4);
      rge_read(param_2,name + 4,i);
      name[i + 4] = '\0';
      rge_read(param_2,&local_1a0,4);
      piVar5 = rc;
      iVar4 = 4;
      do {
        piVar5 = piVar5 + 1;
        iVar7 = 0x411869;
        rge_read(param_2,&i,4);
        *piVar5 = i;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      iVar4 = 0x411888;
      ResourceItem::ResourceItem((ResourceItem *)&newRCost.next,4,rc + 1);
      iVar9 = 0x54;
      local_4._0_1_ = 2;
      iVar8 = 0x411897;
      pTVar3 = (TechnologyItem *)operator_new(0x54);
      local_4._0_1_ = 3;
      local_19c = pTVar3;
      if (pTVar3 == (TechnologyItem *)0x0) {
        pTVar3 = (TechnologyItem *)0x0;
      }
      else {
        rc[0] = (int)&stack0xfffffdd8;
        ResourceItem::ResourceItem((ResourceItem *)&stack0xfffffdd8,(ResourceItem *)&newRCost.next);
        RVar2.sortedIndexValue[4] = iVar6;
        RVar2._padding_ = in_stack_fffffdd8._0_4_;
        RVar2.next = (ResourceItem *)in_stack_fffffdd8._4_4_;
        RVar2.prev = (ResourceItem *)in_stack_fffffdd8._8_4_;
        RVar2.valueValue[0] = in_stack_fffffdd8._12_4_;
        RVar2.valueValue[1] = in_stack_fffffdd8._16_4_;
        RVar2.valueValue[2] = in_stack_fffffdd8._20_4_;
        RVar2.valueValue[3] = in_stack_fffffdd8._24_4_;
        RVar2.valueValue[4] = in_stack_fffffdd8._28_4_;
        RVar2.valueValue[5] = in_stack_fffffdd8._32_4_;
        RVar2.valueValue[6] = in_stack_fffffdd8._36_4_;
        RVar2.valueValue[7] = in_stack_fffffdd8._40_4_;
        RVar2.sortedValue[0] = in_stack_fffffdd8._44_4_;
        RVar2.sortedValue[1] = in_stack_fffffdd8._48_4_;
        RVar2.sortedValue[2] = in_stack_fffffdd8._52_4_;
        RVar2.sortedValue[3] = in_stack_fffffdd8._56_4_;
        RVar2.sortedValue[4] = in_stack_fffffdd8._60_4_;
        RVar2.sortedValue[5] = in_stack_fffffdd8._64_4_;
        RVar2.sortedValue[6] = in_stack_fffffdd8._68_4_;
        RVar2.sortedValue[7] = in_stack_fffffdd8._72_4_;
        RVar2.sortedIndexValue[0] = in_stack_fffffdd8._76_4_;
        RVar2.sortedIndexValue[1] = in_stack_fffffdd8._80_4_;
        RVar2.sortedIndexValue[2] = in_stack_fffffdd8._84_4_;
        RVar2.sortedIndexValue[3] = in_stack_fffffdd8._88_4_;
        RVar2.sortedIndexValue[5] = iVar7;
        RVar2.sortedIndexValue[6] = iVar4;
        RVar2.sortedIndexValue[7] = iVar8;
        RVar2.numberValue = iVar9;
        pTVar3 = (TechnologyItem *)TechnologyItem::TechnologyItem(pTVar3,local_1a0,name + 4,RVar2);
      }
      local_4 = CONCAT31(local_4._1_3_,1);
      pTVar3->next = &this->techTree;
      pTVar1 = (this->techTree).prev;
      pTVar3->prev = pTVar1;
      pTVar1->next = pTVar3;
      (this->techTree).prev = pTVar3;
      ResourceItem::~ResourceItem((ResourceItem *)&newRCost.next);
      typeID = typeID + 1;
    } while (typeID < this->techTreeLengthValue);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~ResearchAIModule
// Address: 00411940
/* public: virtual __thiscall ResearchAIModule::~ResearchAIModule(void) */

void __thiscall ResearchAIModule::~ResearchAIModule(ResearchAIModule *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_0055c7c6;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 1;
  if (0 < this->techTreeLengthValue) {
    removeOldTechTree(this);
  }
  local_4 = local_4 & 0xffffff00;
  TechnologyItem::~TechnologyItem(&this->techTree);
  local_4 = 0xffffffff;
  AIModule::~AIModule((AIModule *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: setMainDecisionAI
// Address: 004119b0
/* public: void __thiscall ResearchAIModule::setMainDecisionAI(class MainDecisionAIModule *) */

void __thiscall
ResearchAIModule::setMainDecisionAI(ResearchAIModule *this,MainDecisionAIModule *param_1)
{
  this->md = param_1;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004119c0
/* WARNING: Variable defined which should be unmapped: tempInt */
/* public: virtual int __thiscall ResearchAIModule::save(int) */

int __thiscall ResearchAIModule::save(ResearchAIModule *this,int param_1)
{
  char cVar1;
  char *pcVar2;
  ResourceItem *this_00;
  uint uVar3;
  uint uVar4;
  TechnologyItem *this_01;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int tempInt;
  int local_10c;
  char tempString [257];
  
  tempString._0_4_ = this;
  rge_write(param_1,&this->techTreeLengthValue,4);
  uVar3 = 0xffffffff;
  pcVar7 = this->techTreeNameValue;
  do {
    pcVar2 = pcVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar2 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar2;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar7 = tempString;
  pcVar2 = pcVar2 + -uVar3;
  for (uVar4 = uVar3 >> 2; pcVar7 = pcVar7 + 4, uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar7 = tempString + 4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  local_10c = ~uVar3 - 1;
  rge_write(param_1,&local_10c,4);
  uVar3 = 0xffffffff;
  pcVar7 = tempString + 4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  rge_write(param_1,tempString + 4,~uVar3 - 1);
  this_01 = (this->techTree).next;
  tempString._0_4_ = tempString._0_4_ + 0xf4;
  if (this_01 != (TechnologyItem *)tempString._0_4_) {
    do {
      if (this_01 == (TechnologyItem *)0x0) {
        return 1;
      }
      pcVar2 = TechnologyItem::name(this_01);
      uVar3 = 0xffffffff;
      pcVar7 = tempString;
      do {
        pcVar6 = pcVar2;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar6 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar6;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar2 = pcVar6 + -uVar3;
      for (uVar4 = uVar3 >> 2; pcVar7 = pcVar7 + 4, uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar7 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        pcVar7 = pcVar7 + 1;
      }
      uVar3 = 0xffffffff;
      pcVar7 = tempString + 4;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      local_10c = ~uVar3 - 1;
      rge_write(param_1,&local_10c,4);
      rge_write(param_1,tempString + 4,local_10c);
      local_10c = TechnologyItem::id(this_01);
      rge_write(param_1,&local_10c,4);
      this_00 = TechnologyItem::resourceCost(this_01);
      iVar5 = 0;
      do {
        local_10c = ResourceItem::value(this_00,iVar5);
        rge_write(param_1,&local_10c,4);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 4);
      this_01 = this_01->next;
    } while (this_01 != (TechnologyItem *)tempString._0_4_);
  }
  return 1;
}

// --------------------------------------------------

// Function: resourceCost
// Address: 00411b40
/* public: class ResourceItem * __thiscall ResearchAIModule::resourceCost(int) */

ResourceItem * __thiscall ResearchAIModule::resourceCost(ResearchAIModule *this,int param_1)
{
  TechnologyItem *this_00;
  ResourceItem *pRVar1;
  
  this_00 = item(this,param_1);
  if (this_00 == (TechnologyItem *)0x0) {
    return (ResourceItem *)0x0;
  }
  pRVar1 = TechnologyItem::resourceCost(this_00);
  return pRVar1;
}

// --------------------------------------------------

// Function: buildable
// Address: 00411b60
/* public: virtual int __thiscall ResearchAIModule::buildable(class BuildItem *) */

int __thiscall ResearchAIModule::buildable(ResearchAIModule *this,BuildItem *param_1)
{
  return 1;
}

// --------------------------------------------------

// Function: research
// Address: 00411b70
/* public: virtual void __thiscall ResearchAIModule::research(class BuildItem *) */

void __thiscall ResearchAIModule::research(ResearchAIModule *this,BuildItem *param_1)
{
  return;
}

// --------------------------------------------------

// Function: loadTechnologyTree
// Address: 00411b80
// [HELPER] s_NONE: "NONE"
// [HELPER] s_NULL: "NULL"
// [HELPER] s___c_d__s___d___d__d__d__d__d___d: "%*c%d %s %*d %*d %d %d %d %d %*d %*d %*d %*d %*d %*d"
/* public: int __thiscall ResearchAIModule::loadTechnologyTree(char *) */

int __thiscall ResearchAIModule::loadTechnologyTree(ResearchAIModule *this,char *param_1)
{
  char cVar1;
  byte bVar2;
  TechnologyItem *pTVar3;
  ResourceItem RVar4;
  char *pcVar5;
  int iVar6;
  TechnologyItem *pTVar7;
  uint uVar8;
  uint uVar9;
  AIModule *this_00;
  byte *pbVar10;
  char *pcVar11;
  undefined4 *unaff_FS_OFFSET;
  bool bVar12;
  undefined1 in_stack_fffffda4 [76];
  char *pcVar13;
  int *piVar14;
  int *piVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int id;
  int rc [4];
  char name [64];
  ResourceItem newRCost;
  char temp [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c7e9;
  *unaff_FS_OFFSET = &local_c;
  if (0 < this->techTreeLengthValue) {
    removeOldTechTree(this);
  }
  uVar8 = 0xffffffff;
  pcVar11 = this->techTreeNameValue;
  do {
    pcVar5 = param_1;
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    pcVar5 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar5;
  } while (cVar1 != '\0');
  uVar8 = ~uVar8;
  pcVar5 = pcVar5 + -uVar8;
  pcVar13 = pcVar11;
  for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined4 *)pcVar13 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *pcVar13 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar13 = pcVar13 + 1;
  }
  pbVar10 = &s_NONE;
  pcVar5 = pcVar11;
  do {
    bVar2 = *pcVar5;
    this_00 = (AIModule *)(uint)bVar2;
    bVar12 = bVar2 < *pbVar10;
    if (bVar2 != *pbVar10) {
LAB_00411c09:
      iVar6 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      goto LAB_00411c0e;
    }
    if (bVar2 == 0) break;
    bVar2 = pcVar5[1];
    this_00 = (AIModule *)(uint)bVar2;
    bVar12 = bVar2 < pbVar10[1];
    if (bVar2 != pbVar10[1]) goto LAB_00411c09;
    pcVar5 = pcVar5 + 2;
    pbVar10 = pbVar10 + 2;
  } while (bVar2 != 0);
  iVar6 = 0;
LAB_00411c0e:
  if (iVar6 == 0) {
    if (pcVar11 == (char *)0x0) goto LAB_00411dad;
LAB_00411dcf:
    AIModule::logCommonHistory(this_00,(char *)this);
  }
  else {
    if (pcVar11 == (char *)0x0) {
LAB_00411dad:
      uVar8 = 0xffffffff;
      pcVar11 = &s_NULL;
      do {
        pcVar5 = pcVar11;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar5 = pcVar11 + 1;
        cVar1 = *pcVar11;
        pcVar11 = pcVar5;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      pcVar11 = pcVar5 + -uVar8;
      pcVar5 = (char *)0x0;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar11;
        pcVar11 = pcVar11 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (this_00 = (AIModule *)(uVar8 & 3); this_00 != (AIModule *)0x0;
          this_00 = (AIModule *)((int)&this_00[-1].processFrameValue + 3)) {
        *pcVar5 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        pcVar5 = pcVar5 + 1;
      }
      goto LAB_00411dcf;
    }
    AIModule::logCommonHistory(this_00,(char *)this);
    sprintf();
    iVar6 = fopen();
    if (iVar6 == 0) goto LAB_00411de2;
    iVar6 = fgets();
    if (iVar6 != 0) {
      do {
        piVar15 = rc + 1;
        pcVar11 = name + 4;
        piVar14 = rc;
        pcVar5 = temp + 4;
        pcVar13 = s___c_d__s___d___d__d__d__d__d___d;
        iVar6 = 0x411cbd;
        sscanf();
        iVar16 = 0x411cd0;
        ResourceItem::ResourceItem((ResourceItem *)&newRCost.next,4,rc + 1);
        iVar18 = 0x54;
        local_4 = 0;
        iVar17 = 0x411ce2;
        pTVar7 = (TechnologyItem *)operator_new(0x54);
        local_4 = CONCAT31(local_4._1_3_,1);
        name._0_4_ = pTVar7;
        if (pTVar7 == (TechnologyItem *)0x0) {
          pTVar7 = (TechnologyItem *)0x0;
        }
        else {
          ResourceItem::ResourceItem
                    ((ResourceItem *)&stack0xfffffda4,(ResourceItem *)&newRCost.next);
          RVar4.sortedIndexValue[0] = iVar6;
          RVar4._padding_ = in_stack_fffffda4._0_4_;
          RVar4.next = (ResourceItem *)in_stack_fffffda4._4_4_;
          RVar4.prev = (ResourceItem *)in_stack_fffffda4._8_4_;
          RVar4.valueValue[0] = in_stack_fffffda4._12_4_;
          RVar4.valueValue[1] = in_stack_fffffda4._16_4_;
          RVar4.valueValue[2] = in_stack_fffffda4._20_4_;
          RVar4.valueValue[3] = in_stack_fffffda4._24_4_;
          RVar4.valueValue[4] = in_stack_fffffda4._28_4_;
          RVar4.valueValue[5] = in_stack_fffffda4._32_4_;
          RVar4.valueValue[6] = in_stack_fffffda4._36_4_;
          RVar4.valueValue[7] = in_stack_fffffda4._40_4_;
          RVar4.sortedValue[0] = in_stack_fffffda4._44_4_;
          RVar4.sortedValue[1] = in_stack_fffffda4._48_4_;
          RVar4.sortedValue[2] = in_stack_fffffda4._52_4_;
          RVar4.sortedValue[3] = in_stack_fffffda4._56_4_;
          RVar4.sortedValue[4] = in_stack_fffffda4._60_4_;
          RVar4.sortedValue[5] = in_stack_fffffda4._64_4_;
          RVar4.sortedValue[6] = in_stack_fffffda4._68_4_;
          RVar4.sortedValue[7] = in_stack_fffffda4._72_4_;
          RVar4.sortedIndexValue[1] = (int)pcVar5;
          RVar4.sortedIndexValue[2] = (int)pcVar13;
          RVar4.sortedIndexValue[3] = (int)piVar14;
          RVar4.sortedIndexValue[4] = (int)pcVar11;
          RVar4.sortedIndexValue[5] = (int)piVar15;
          RVar4.sortedIndexValue[6] = iVar16;
          RVar4.sortedIndexValue[7] = iVar17;
          RVar4.numberValue = iVar18;
          pTVar7 = (TechnologyItem *)TechnologyItem::TechnologyItem(pTVar7,rc[0],name + 4,RVar4);
        }
        pTVar7->next = &this->techTree;
        pTVar3 = (this->techTree).prev;
        pTVar7->prev = pTVar3;
        local_4 = 0xffffffff;
        pTVar3->next = pTVar7;
        iVar6 = this->techTreeLengthValue;
        (this->techTree).prev = pTVar7;
        this->techTreeLengthValue = iVar6 + 1;
        ResourceItem::~ResourceItem((ResourceItem *)&newRCost.next);
        iVar6 = fgets();
      } while (iVar6 != 0);
    }
    fclose();
    iVar6 = strstr();
    if (iVar6 != 0) {
      __unlink();
    }
  }
  iVar6 = 1;
LAB_00411de2:
  *unaff_FS_OFFSET = local_c;
  return iVar6;
}

// --------------------------------------------------

// Function: numberTechnologyItems
// Address: 00411e00
/* public: int __thiscall ResearchAIModule::numberTechnologyItems(void)const  */

int __thiscall ResearchAIModule::numberTechnologyItems(ResearchAIModule *this)
{
  return this->techTreeLengthValue;
}

// --------------------------------------------------

// Function: technologyTreeName
// Address: 00411e10
/* public: char * __thiscall ResearchAIModule::technologyTreeName(void) */

char * __thiscall ResearchAIModule::technologyTreeName(ResearchAIModule *this)
{
  return this->techTreeNameValue;
}

// --------------------------------------------------

// Function: removeOldTechTree
// Address: 00411e20
/* protected: void __thiscall ResearchAIModule::removeOldTechTree(void) */

void __thiscall ResearchAIModule::removeOldTechTree(ResearchAIModule *this)
{
  TechnologyItem *pTVar1;
  TechnologyItem *pTVar2;
  int *piVar3;
  
  pTVar2 = (this->techTree).next;
  pTVar1 = &this->techTree;
  while ((pTVar2 != pTVar1 && (pTVar2 != (TechnologyItem *)0x0))) {
    piVar3 = &pTVar2->_padding_;
    pTVar2 = pTVar2->next;
    (**(code **)*piVar3)(1);
  }
  (this->techTree).next = pTVar1;
  (this->techTree).prev = pTVar1;
  this->techTreeLengthValue = 0;
  return;
}

// --------------------------------------------------

// Function: item
// Address: 00411e70
/* protected: class TechnologyItem * __thiscall ResearchAIModule::item(int) */

TechnologyItem * __thiscall ResearchAIModule::item(ResearchAIModule *this,int param_1)
{
  int iVar1;
  TechnologyItem *this_00;
  
  this_00 = (this->techTree).next;
  if (this_00 != &this->techTree) {
    while (this_00 != (TechnologyItem *)0x0) {
      iVar1 = TechnologyItem::id(this_00);
      if (iVar1 == param_1) {
        return this_00;
      }
      this_00 = this_00->next;
      if (this_00 == &this->techTree) {
        return (TechnologyItem *)0x0;
      }
    }
  }
  return (TechnologyItem *)0x0;
}

// --------------------------------------------------

