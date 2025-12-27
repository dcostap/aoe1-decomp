// Class: TribeBuildAIModule
// Function: TribeBuildAIModule
// Address: 004d3a80
/* public: __thiscall TribeBuildAIModule::TribeBuildAIModule(void *,int) */

TribeBuildAIModule * __thiscall
TribeBuildAIModule::TribeBuildAIModule(TribeBuildAIModule *this,void *param_1,int param_2)
{
  BuildAIModule::BuildAIModule((BuildAIModule *)this,param_1,param_2);
  this->md = (TribeMainDecisionAIModule *)0x0;
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004d3ab0
/* public: virtual void * __thiscall TribeBuildAIModule::`vector deleting destructor'(unsigned int)
    */

void * __thiscall
TribeBuildAIModule::_vector_deleting_destructor_(TribeBuildAIModule *this,uint param_1)
{
  ~TribeBuildAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TribeBuildAIModule
// Address: 004d3ad0
/* public: __thiscall TribeBuildAIModule::TribeBuildAIModule(int,int) */

TribeBuildAIModule * __thiscall
TribeBuildAIModule::TribeBuildAIModule(TribeBuildAIModule *this,int param_1,int param_2)
{
  BuildAIModule::BuildAIModule((BuildAIModule *)this,param_1,param_2);
  this->md = (TribeMainDecisionAIModule *)0x0;
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: ~TribeBuildAIModule
// Address: 004d3b00
/* public: virtual __thiscall TribeBuildAIModule::~TribeBuildAIModule(void) */

void __thiscall TribeBuildAIModule::~TribeBuildAIModule(TribeBuildAIModule *this)
{
  this->_padding_ = (int)&_vftable_;
  BuildAIModule::~BuildAIModule((BuildAIModule *)this);
  return;
}

// --------------------------------------------------

// Function: setMainDecisionAI
// Address: 004d3b10
/* public: void __thiscall TribeBuildAIModule::setMainDecisionAI(class TribeMainDecisionAIModule *)
    */

void __thiscall
TribeBuildAIModule::setMainDecisionAI(TribeBuildAIModule *this,TribeMainDecisionAIModule *param_1)
{
  this->md = param_1;
  return;
}

// --------------------------------------------------

// Function: loadBuildList
// Address: 004d3b20
/* public: virtual int __thiscall TribeBuildAIModule::loadBuildList(char *,class RGE_Player *) */

int __thiscall
TribeBuildAIModule::loadBuildList(TribeBuildAIModule *this,char *param_1,RGE_Player *param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = this->_padding_;
  if (0 < iVar3) {
    do {
      if (this->_padding_ <= iVar1) break;
      if (*(int *)(this->_padding_ + iVar1 * 4) == 0x46) goto LAB_004d3bd8;
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar3);
  }
  if (this->_padding_ + -1 < iVar3) {
    iVar3 = iVar3 + 1;
    pvVar2 = operator_new(iVar3 * 4);
    if (pvVar2 != (void *)0x0) {
      iVar1 = 0;
      if (0 < this->_padding_) {
        do {
          if (iVar3 <= iVar1) break;
          iVar1 = iVar1 + 1;
          *(undefined4 *)((int)pvVar2 + iVar1 * 4 + -4) =
               *(undefined4 *)(this->_padding_ + -4 + iVar1 * 4);
        } while (iVar1 < this->_padding_);
      }
      operator_delete((void *)this->_padding_);
      this->_padding_ = (int)pvVar2;
      this->_padding_ = iVar3;
    }
  }
  *(undefined4 *)(this->_padding_ + this->_padding_ * 4) = 0x46;
  this->_padding_ = this->_padding_ + 1;
LAB_004d3bd8:
  iVar3 = this->_padding_;
  iVar1 = 0;
  if (0 < iVar3) {
    do {
      if (this->_padding_ <= iVar1) break;
      if (*(int *)(this->_padding_ + iVar1 * 4) == 0x67) goto LAB_004d3c8b;
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar3);
  }
  if (this->_padding_ + -1 < iVar3) {
    iVar3 = iVar3 + 1;
    pvVar2 = operator_new(iVar3 * 4);
    if (pvVar2 != (void *)0x0) {
      iVar1 = 0;
      if (0 < this->_padding_) {
        do {
          if (iVar3 <= iVar1) break;
          iVar1 = iVar1 + 1;
          *(undefined4 *)((int)pvVar2 + iVar1 * 4 + -4) =
               *(undefined4 *)(this->_padding_ + -4 + iVar1 * 4);
        } while (iVar1 < this->_padding_);
      }
      operator_delete((void *)this->_padding_);
      this->_padding_ = (int)pvVar2;
      this->_padding_ = iVar3;
    }
  }
  *(undefined4 *)(this->_padding_ + this->_padding_ * 4) = 0x67;
  this->_padding_ = this->_padding_ + 1;
LAB_004d3c8b:
  iVar3 = this->_padding_;
  iVar1 = 0;
  if (0 < iVar3) {
    do {
      if (this->_padding_ <= iVar1) break;
      if (*(int *)(this->_padding_ + iVar1 * 4) == 0x44) goto LAB_004d3d3e;
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar3);
  }
  if (this->_padding_ + -1 < iVar3) {
    iVar3 = iVar3 + 1;
    pvVar2 = operator_new(iVar3 * 4);
    if (pvVar2 != (void *)0x0) {
      iVar1 = 0;
      if (0 < this->_padding_) {
        do {
          if (iVar3 <= iVar1) break;
          iVar1 = iVar1 + 1;
          *(undefined4 *)((int)pvVar2 + iVar1 * 4 + -4) =
               *(undefined4 *)(this->_padding_ + -4 + iVar1 * 4);
        } while (iVar1 < this->_padding_);
      }
      operator_delete((void *)this->_padding_);
      this->_padding_ = (int)pvVar2;
      this->_padding_ = iVar3;
    }
  }
  *(undefined4 *)(this->_padding_ + this->_padding_ * 4) = 0x44;
  this->_padding_ = this->_padding_ + 1;
LAB_004d3d3e:
  iVar3 = BuildAIModule::loadBuildList((BuildAIModule *)this,param_1,param_2);
  return iVar3;
}

// --------------------------------------------------

// Function: initialize
// Address: 004d3d60
/* WARNING: Variable defined which should be unmapped: requiredPop */
/* public: void __thiscall TribeBuildAIModule::initialize(void) */

void __thiscall TribeBuildAIModule::initialize(TribeBuildAIModule *this)
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  BuildItem *pBVar9;
  undefined4 *unaff_FS_OFFSET;
  ResourceItem *pRVar10;
  int iVar11;
  int requiredPop;
  int bronzeAgeIndex;
  int count;
  int divisionSize;
  int ironAgeIndex;
  int totalPercentage;
  int dockCount;
  int transportCount;
  int fishingBoatCount;
  int toolAgeIndex;
  int warshipCount;
  ResourceItem resourceCount;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560278;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar8 = -1;
  bronzeAgeIndex = 0;
  pBVar9 = (BuildItem *)this->_padding_;
  transportCount = 0;
  toolAgeIndex = 0;
  fishingBoatCount = 0;
  resourceCount._padding_ = 0;
  warshipCount = -1;
  totalPercentage = -1;
  bVar2 = false;
  bVar3 = false;
  bVar1 = false;
  for (; (pBVar9 != (BuildItem *)&this->_padding_ && (pBVar9 != (BuildItem *)0x0));
      pBVar9 = pBVar9->next) {
    iVar4 = BuildItem::buildCategory(pBVar9);
    if (iVar4 == 0) {
      iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
      if (iVar4 == 0x46) {
        bronzeAgeIndex = bronzeAgeIndex + 1;
      }
      else {
        iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
        if (iVar4 == 0x2d) {
          transportCount = transportCount + 1;
        }
      }
    }
    else {
      iVar4 = BuildItem::buildCategory(pBVar9);
      if (iVar4 == 2) {
        iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
        if (iVar4 == 0xd) {
          toolAgeIndex = toolAgeIndex + 1;
        }
        else {
          iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
          if ((iVar4 == 0x11) || (iVar4 = BaseItem::typeID((BaseItem *)pBVar9), iVar4 == 0x12)) {
            fishingBoatCount = fishingBoatCount + 1;
          }
          else {
            iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
            if ((iVar4 == 0x13) || (iVar4 = BaseItem::typeID((BaseItem *)pBVar9), iVar4 == 0xfa)) {
              resourceCount._padding_ = resourceCount._padding_ + 1;
            }
          }
        }
      }
      else {
        iVar4 = BuildItem::buildCategory(pBVar9);
        if ((iVar4 == 1) || (iVar4 = BuildItem::buildCategory(pBVar9), iVar4 == 4)) {
          iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
          if (iVar4 == 0x65) {
            warshipCount = BaseItem::uniqueID((BaseItem *)pBVar9);
          }
          else {
            iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
            if (iVar4 == 0x66) {
              iVar8 = BaseItem::uniqueID((BaseItem *)pBVar9);
            }
            else {
              iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
              if (iVar4 == 0x67) {
                totalPercentage = BaseItem::uniqueID((BaseItem *)pBVar9);
              }
              else {
                iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
                if (iVar4 == 5) {
                  bVar2 = true;
                }
                else {
                  iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
                  if (iVar4 == 7) {
                    bVar3 = true;
                  }
                  else {
                    iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
                    if (iVar4 == 8) {
                      bVar1 = true;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  iVar4 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xd4);
  if ((transportCount < iVar4) &&
     (iVar4 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xd0), iVar4 == 1)) {
    iVar4 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xd4);
    iVar4 = iVar4 - transportCount;
    if (iVar8 == -1) {
      if (warshipCount == -1) {
        iVar5 = 10;
      }
      else {
        iVar5 = warshipCount / iVar4;
      }
    }
    else {
      iVar5 = iVar8 / iVar4;
    }
    iVar6 = iVar5;
    if (0 < iVar4) {
      do {
        insert(this,0x2d,-1,iVar6);
        iVar4 = iVar4 + -1;
        iVar6 = iVar6 + iVar5;
      } while (iVar4 != 0);
    }
  }
  iVar4 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xd5);
  if ((toolAgeIndex < iVar4) &&
     (iVar4 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xd1), iVar4 == 1)) {
    iVar4 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xd5);
    iVar4 = iVar4 - toolAgeIndex;
    if (0 < iVar4) {
      if (iVar8 == -1) {
        if (warshipCount == -1) {
          iVar5 = 10;
        }
        else {
          iVar5 = warshipCount / iVar4;
        }
      }
      else {
        iVar5 = iVar8 / iVar4;
      }
      iVar6 = iVar5;
      if (0 < iVar4) {
        do {
          insert(this,0xd,-1,iVar6);
          iVar4 = iVar4 + -1;
          iVar6 = iVar6 + iVar5;
        } while (iVar4 != 0);
      }
    }
  }
  iVar4 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xd6);
  if ((fishingBoatCount < iVar4) &&
     (iVar4 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xd2), iVar4 == 1)) {
    iVar4 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xd6);
    iVar4 = iVar4 - fishingBoatCount;
    if (warshipCount == -1) {
      if (iVar8 == -1) {
        iVar6 = 10;
        iVar5 = 0;
      }
      else {
        iVar6 = (this->_padding_ - iVar8) / (iVar4 * 2);
        iVar5 = -1;
      }
    }
    else {
      iVar6 = (this->_padding_ - warshipCount) / (iVar4 * 2);
      iVar5 = iVar8;
    }
    if (0 < iVar4) {
      do {
        iVar5 = iVar5 + iVar6;
        insert(this,0x11,-1,iVar5);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    if ((!bVar1) && (totalPercentage != -1)) {
      insertResearch(this,8,totalPercentage + 2);
    }
  }
  iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xe0);
  iVar4 = resourceCount._padding_;
  if (((resourceCount._padding_ < iVar5) &&
      (iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xdf), iVar5 == 1)) &&
     ((totalPercentage != -1 || (iVar8 != -1)))) {
    iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xe0);
    iVar5 = iVar5 - iVar4;
    iVar4 = totalPercentage;
    if (totalPercentage == -1) {
      iVar4 = iVar8;
    }
    iVar4 = iVar4 / iVar5;
    iVar6 = iVar4;
    if (0 < iVar5) {
      do {
        insertResearch(this,0x13,iVar6);
        iVar5 = iVar5 + -1;
        iVar6 = iVar6 + iVar4;
      } while (iVar5 != 0);
    }
    if ((!bVar2) && (iVar8 != -1)) {
      insertResearch(this,5,iVar8 + 5);
    }
    if ((!bVar3) && (totalPercentage != -1)) {
      insertResearch(this,7,totalPercentage + 5);
    }
  }
  if ((bronzeAgeIndex == 0) &&
     (iVar8 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xb4), iVar8 == 1)) {
    pBVar9 = (BuildItem *)this->_padding_;
    iVar4 = 0;
    iVar8 = 0;
    bronzeAgeIndex = 0;
    if (pBVar9 != (BuildItem *)&this->_padding_) {
      do {
        if (pBVar9 == (BuildItem *)0x0) break;
        iVar5 = BuildItem::buildCategory(pBVar9);
        if ((iVar5 == 0) && (iVar5 = BaseItem::typeID((BaseItem *)pBVar9), iVar5 == 0x6d)) {
          iVar8 = iVar8 + 4;
        }
        iVar5 = BuildItem::buildCategory(pBVar9);
        if (iVar5 == 2) {
          bronzeAgeIndex = bronzeAgeIndex + 1;
        }
        if (iVar8 < bronzeAgeIndex) {
          if (iVar4 < 2) {
            iVar5 = 1;
          }
          else {
            iVar5 = iVar4 + -1;
          }
          iVar5 = insert(this,0x46,-1,iVar5);
          if (iVar5 == 1) {
            iVar8 = iVar8 + 4;
          }
        }
        iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x98);
        if (iVar5 + 0x32 < iVar8) break;
        pBVar9 = pBVar9->next;
        iVar4 = iVar4 + 1;
      } while (pBVar9 != (BuildItem *)&this->_padding_);
    }
  }
  iVar8 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xa0);
  iVar4 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x9b);
  if (iVar8 != 0) {
    pBVar9 = (BuildItem *)this->_padding_;
    ResourceItem::ResourceItem((ResourceItem *)&resourceCount.next,4);
    divisionSize = 0;
    local_4 = 0;
    ResourceItem::setAllValues((ResourceItem *)&resourceCount.next,0);
    if (pBVar9 != (BuildItem *)&this->_padding_) {
      bronzeAgeIndex = 0;
      do {
        if (pBVar9 == (BuildItem *)0x0) break;
        iVar5 = BuildItem::buildCategory(pBVar9);
        if (iVar5 == 6) {
          pBVar9 = pBVar9->next;
          divisionSize = divisionSize + 1;
        }
        else {
          iVar5 = BuildItem::buildCategory(pBVar9);
          if ((iVar5 == 1) || (iVar5 = BuildItem::buildCategory(pBVar9), iVar5 == 4)) {
            pRVar10 = (ResourceItem *)&resourceCount.next;
            iVar11 = 1;
            iVar6 = -1;
            iVar5 = BaseItem::typeID((BaseItem *)pBVar9);
            TRIBE_Player::researchCost(this->md->aiPlayer,iVar5,iVar6,pRVar10,iVar11);
          }
          else {
            pRVar10 = (ResourceItem *)&resourceCount.next;
            iVar11 = 1;
            iVar6 = -1;
            iVar5 = BaseItem::typeID((BaseItem *)pBVar9);
            TRIBE_Player::objectCost(this->md->aiPlayer,iVar5,iVar6,pRVar10,iVar11);
          }
          divisionSize = divisionSize + 1;
          if (iVar4 + 4 <= divisionSize) {
            iVar5 = 0;
            iVar6 = 0;
            do {
              iVar11 = ResourceItem::value((ResourceItem *)&resourceCount.next,iVar6);
              iVar5 = iVar5 + iVar11;
              iVar6 = iVar6 + 1;
            } while (iVar6 < 4);
            if (0 < iVar5) {
              iVar6 = 0;
              do {
                iVar11 = bronzeAgeIndex;
                iVar7 = ResourceItem::value((ResourceItem *)&resourceCount.next,iVar6);
                insertGathererPercentage(this,iVar6,(iVar7 * iVar8) / iVar5,iVar11);
                iVar6 = iVar6 + 1;
              } while (iVar6 < 4);
              ResourceItem::setAllValues((ResourceItem *)&resourceCount.next,0);
              bronzeAgeIndex = bronzeAgeIndex + iVar4 + 4;
              divisionSize = 0;
            }
          }
          pBVar9 = pBVar9->next;
        }
      } while (pBVar9 != (BuildItem *)&this->_padding_);
    }
    local_4 = 0xffffffff;
    ResourceItem::~ResourceItem((ResourceItem *)&resourceCount.next);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: skipNextBuildListItem
// Address: 004d4460
/* public: void __thiscall TribeBuildAIModule::skipNextBuildListItem(void) */

void __thiscall TribeBuildAIModule::skipNextBuildListItem(TribeBuildAIModule *this)
{
  int iVar1;
  int iVar2;
  BuildItem *this_00;
  
  this_00 = (BuildItem *)this->_padding_;
  if (this_00 != (BuildItem *)&this->_padding_) {
    while (this_00 != (BuildItem *)0x0) {
      iVar1 = BuildItem::built(this_00);
      if (((iVar1 == 0) && (iVar1 = BuildItem::inProgress(this_00), iVar1 == 0)) &&
         (iVar1 = BaseItem::skip((BaseItem *)this_00), iVar1 != 1)) {
        iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xb1);
        iVar2 = BaseItem::typeID((BaseItem *)this_00);
        if ((iVar2 != iVar1) || (iVar1 = BuildItem::buildCategory(this_00), iVar1 != 0)) {
                    /* language.dll match for 0x72: "21" */
          iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x72);
          BuildItem::setBuildAttempts(this_00,iVar1);
          BaseItem::setSkip((BaseItem *)this_00,1);
          BuildItem::incrementSkipCycles(this_00);
          iVar1 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x92);
          iVar2 = BuildItem::skipCycles(this_00);
          if (iVar2 != iVar1) {
            return;
          }
          BuildItem::setPermanentSkip(this_00,'\x01');
          return;
        }
      }
      this_00 = this_00->next;
      if (this_00 == (BuildItem *)&this->_padding_) {
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: nextBuildableItem
// Address: 004d4540
/* WARNING: Variable defined which should be unmapped: count */
/* WARNING: Removing unreachable block (ram,0x004d46de) */
/* WARNING: Removing unreachable block (ram,0x004d4758) */
/* public: class BuildItem * __thiscall TribeBuildAIModule::nextBuildableItem(int) */

BuildItem * __thiscall TribeBuildAIModule::nextBuildableItem(TribeBuildAIModule *this,int param_1)
{
  code *pcVar1;
  bool bVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  BuildItem *this_00;
  RGE_Static_Object *pRVar8;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  ResourceItem *pRVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int count;
  int numGranaries;
  int numStoragePits;
  int realCount;
  int numHouses;
  ResourceItem itemCost;
  ResourceItem itemCost_ffffff80;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005602a3;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
                    /* language.dll match for 0x67: "Comic Sans MS" */
  pcVar1 = *(code **)(this->_padding_ + 0x48);
  numGranaries = (*pcVar1)(0x67);
  (*pcVar1)(0x44,0);
  iVar4 = (*pcVar1)(0x46,0);
  this_00 = (BuildItem *)this->_padding_;
                    /* language.dll match for 0x73: "B" */
  iVar18 = 0;
  iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x73);
  if (-1 < iVar5) {
    do {
      if ((this_00 == (BuildItem *)&this->_padding_) || (this_00 == (BuildItem *)0x0)) break;
      iVar5 = BuildItem::buildCategory(this_00);
      if ((iVar5 == 1) || (iVar5 = BuildItem::buildCategory(this_00), iVar5 == 4)) {
        iVar5 = BaseItem::typeID((BaseItem *)this_00);
        iVar5 = isAgeResearch(this,iVar5);
        if (iVar5 != 1) goto switchD_004d4615_default;
        iVar5 = BaseItem::typeID((BaseItem *)this_00);
        uVar3 = TRIBE_Player::researchState(this->md->aiPlayer,iVar5);
        switch(uVar3) {
        case '\0':
        case '\x01':
          iVar5 = 0;
          break;
        case '\x02':
          BuildItem::setBuilt(this_00,0);
          iVar5 = 1;
          goto LAB_004d4638;
        case '\x03':
          iVar5 = 1;
          break;
        default:
          goto switchD_004d4615_default;
        }
        BuildItem::setBuilt(this_00,iVar5);
        iVar5 = 0;
LAB_004d4638:
        BuildItem::setInProgress(this_00,iVar5);
      }
switchD_004d4615_default:
      iVar5 = BuildItem::built(this_00);
      if ((iVar5 == 0) && (iVar5 = BuildItem::inProgress(this_00), iVar5 == 0)) {
        bVar2 = true;
        iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xa1);
        if ((iVar5 == 1) && (unaff_EDI == 0)) {
          bVar2 = false;
        }
        if (((iVar5 == 2) &&
            (iVar6 = TribeResourceAIModule::resource(&this->md->resourceAI,1), iVar6 < 0xfa)) &&
           (unaff_EDI == 0)) {
          bVar2 = false;
        }
        if (iVar5 == 3) {
          bVar2 = false;
        }
        if (iVar5 == 4) {
          bVar2 = false;
        }
        if ((itemCost_ffffff80.numberValue == 0) &&
           (((((!bVar2 && (iVar5 = BuildItem::buildCategory(this_00), iVar5 == 0)) &&
              ((iVar5 = BaseItem::typeID((BaseItem *)this_00), iVar5 != 0x46 &&
               ((iVar5 = BaseItem::typeID((BaseItem *)this_00), iVar5 != 0x6d &&
                (iVar5 = BaseItem::typeID((BaseItem *)this_00), iVar5 != 0x67)))))) &&
             (iVar5 = BaseItem::typeID((BaseItem *)this_00), iVar5 != 0x44)) ||
            ((((iVar5 = BuildItem::buildCategory(this_00), iVar5 == 0 &&
               (iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xae),
               iVar5 <= iVar4)) && (iVar5 = BaseItem::typeID((BaseItem *)this_00), iVar5 != 0x6d))
             && ((iVar5 = BaseItem::typeID((BaseItem *)this_00), iVar5 != 0x67 &&
                 (iVar5 = BaseItem::typeID((BaseItem *)this_00), iVar5 != 0x44))))))))
        goto LAB_004d489e;
        iVar5 = BuildItem::buildCategory(this_00);
        if ((iVar5 == 5) && (iVar18 == 0)) {
          TribeTacticalAIModule::enableAttack(&this->md->tacticalAI,1);
LAB_004d488c:
          BuildItem::setInProgress(this_00,0);
          BuildItem::setBuilt(this_00,1);
          goto LAB_004d489e;
        }
        iVar5 = BuildItem::buildCategory(this_00);
        if (iVar5 == 6) {
          if (iVar18 < 1) {
            iVar5 = BuildItem::buildFrom(this_00);
            iVar6 = BaseItem::typeID((BaseItem *)this_00);
            TribeTacticalAIModule::setStrategicNumber(&this->md->tacticalAI,iVar6 + 0x9c,iVar5);
            goto LAB_004d488c;
          }
          goto LAB_004d489e;
        }
        if ((itemCost_ffffff80.numberValue == 3) && (0 < iVar18)) break;
        iVar5 = BuildItem::buildCap(this_00);
        if (iVar5 != -1) {
          iVar5 = BuildItem::buildCap(this_00);
          iVar6 = BuildItem::numberBuilds(this_00);
          if (iVar5 < iVar6) goto LAB_004d489e;
        }
        if ((itemCost_ffffff80.numberValue == 1) &&
           ((iVar5 = BuildItem::buildCategory(this_00), iVar5 == 1 ||
            (iVar5 = BuildItem::buildCategory(this_00), iVar5 == 4)))) {
          iVar5 = BaseItem::typeID((BaseItem *)this_00);
          iVar5 = TRIBE_Player::researchEverAvailable(this->md->aiPlayer,iVar5);
          if (iVar5 == 0) goto LAB_004d488c;
        }
        iVar5 = BuildItem::buildCategory(this_00);
        if (iVar5 == 4) {
          ResourceItem::ResourceItem((ResourceItem *)(itemCost.sortedIndexValue + 4),4);
          pRVar13 = (ResourceItem *)(itemCost.sortedIndexValue + 4);
          iVar16 = 1;
          iVar6 = -1;
          iVar5 = BaseItem::typeID((BaseItem *)this_00);
          TRIBE_Player::researchCost(this->md->aiPlayer,iVar5,iVar6,pRVar13,iVar16);
          iVar5 = BaseItem::typeID((BaseItem *)this_00);
          iVar5 = TRIBE_Player::researchAvailable(this->md->aiPlayer,iVar5);
          if (((iVar5 == 0) ||
              (iVar5 = TribeResourceAIModule::resourcesAvailable
                                 (&this->md->resourceAI,
                                  (ResourceItem *)(itemCost.sortedIndexValue + 4)), iVar5 == 0)) ||
             (itemCost_ffffff80.numberValue != 1)) {
            ResourceItem::~ResourceItem((ResourceItem *)(itemCost.sortedIndexValue + 4));
            break;
          }
          ResourceItem::~ResourceItem((ResourceItem *)(itemCost.sortedIndexValue + 4));
        }
        iVar5 = BaseItem::skip((BaseItem *)this_00);
        if (((iVar5 == 1) && (iVar5 = BuildItem::buildAttempts(this_00), 0 < iVar5)) ||
           (uVar3 = BuildItem::permanentSkip(this_00), uVar3 != '\0')) {
          BuildItem::decrementBuildAttempts(this_00);
          goto LAB_004d489e;
        }
        iVar5 = BaseItem::skip((BaseItem *)this_00);
        if ((iVar5 == 1) && (iVar5 = BuildItem::buildAttempts(this_00), iVar5 < 1)) {
          BaseItem::setSkip((BaseItem *)this_00,0);
          iVar5 = BuildItem::buildCategory(this_00);
          if ((iVar5 == 0) &&
             ((iVar5 = BaseItem::typeID((BaseItem *)this_00), iVar5 == 0x67 ||
              (iVar5 = BaseItem::typeID((BaseItem *)this_00), iVar5 == 0x44)))) {
                    /* language.dll match for 0x72: "21" */
            iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x72);
            BuildItem::setBuildAttempts(this_00,iVar5 + -1);
          }
        }
        iVar5 = *(int *)(this->md->_padding_ + 0x50);
        if ((*(float *)(iVar5 + 0x2c) < *(float *)(iVar5 + 0x80)) ||
           (iVar5 = BuildItem::buildCategory(this_00), iVar5 != 2)) {
          iVar18 = iVar18 + 1;
        }
        if (itemCost_ffffff80.numberValue != 1) {
          iVar5 = BuildItem::buildCategory(this_00);
          if (itemCost_ffffff80.numberValue == iVar5) goto LAB_004d4b55;
          goto LAB_004d489e;
        }
        iVar5 = BuildItem::buildCategory(this_00);
        if ((iVar5 != 1) && (iVar5 = BuildItem::buildCategory(this_00), iVar5 != 4))
        goto LAB_004d489e;
LAB_004d4b55:
        if ((itemCost_ffffff80.numberValue == 3) &&
           (iVar5 = BuildItem::buildCategory(this_00), iVar5 != 3)) {
LAB_004d48db:
          BuildItem::setBuildAttempts(this_00,0);
          break;
        }
        BuildItem::incrementBuildAttempts(this_00);
        iVar5 = BuildItem::buildAttempts(this_00);
                    /* language.dll match for 0x72: "21" */
        iVar6 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x72);
        if (((iVar6 < iVar5) && (iVar5 = BaseItem::skip((BaseItem *)this_00), iVar5 == 0)) &&
           (uVar3 = BuildItem::permanentSkip(this_00), uVar3 == '\0')) {
          if ((itemCost_ffffff80.numberValue == 1) &&
             (iVar5 = BuildItem::buildCategory(this_00), iVar5 == 4)) goto LAB_004d48db;
          iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0xb1);
          iVar6 = BaseItem::typeID((BaseItem *)this_00);
          if ((iVar6 != iVar5) || (iVar5 = BuildItem::buildCategory(this_00), iVar5 != 0)) {
            BaseItem::setSkip((BaseItem *)this_00,1);
            iVar5 = BuildItem::buildCategory(this_00);
            if ((iVar5 == 0) &&
               ((iVar5 = BaseItem::typeID((BaseItem *)this_00), iVar5 == 0x67 ||
                (iVar5 = BaseItem::typeID((BaseItem *)this_00), iVar5 == 0x44)))) {
                    /* language.dll match for 0x72: "21" */
              iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x72);
              BuildItem::setBuildAttempts(this_00,iVar5 * 6);
            }
            else {
                    /* language.dll match for 0x72: "21" */
              iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x72);
              BuildItem::setBuildAttempts(this_00,iVar5);
            }
            goto LAB_004d489e;
          }
        }
        if ((itemCost_ffffff80.numberValue == 3) &&
           (iVar5 = BuildItem::buildCategory(this_00), iVar5 == 3)) {
          uVar15 = 0x3f;
          pcVar7 = BaseItem::name((BaseItem *)this_00);
          strncpy((undefined1 *)((int)&this->_padding_ + 2),pcVar7,uVar15);
          iVar18 = BaseItem::uniqueID((BaseItem *)this_00);
          this->_padding_ = iVar18;
          uVar15 = 0x3f;
          pcVar7 = BaseItem::name((BaseItem *)this_00->next);
          strncpy((undefined1 *)((int)&this->_padding_ + 3),pcVar7,uVar15);
          iVar18 = BaseItem::uniqueID((BaseItem *)this_00);
          this->_padding_ = iVar18;
          goto LAB_004d499d;
        }
        if (itemCost_ffffff80.numberValue == 1) {
          iVar5 = BaseItem::typeID((BaseItem *)this_00);
          iVar5 = TRIBE_Player::researchAvailable(this->md->aiPlayer,iVar5);
        }
        else {
          iVar5 = BaseItem::typeID((BaseItem *)this_00);
          iVar5 = TRIBE_Player::objectAvailable(this->md->aiPlayer,iVar5);
        }
        if (iVar5 == 0) goto LAB_004d489e;
        ResourceItem::ResourceItem((ResourceItem *)&count,4);
        iVar5 = 1;
        if (itemCost_ffffff80.numberValue == 1) {
          pRVar13 = (ResourceItem *)&count;
          iVar16 = -1;
          iVar6 = BaseItem::typeID((BaseItem *)this_00);
          TRIBE_Player::researchCost(this->md->aiPlayer,iVar6,iVar16,pRVar13,iVar5);
        }
        else {
          pRVar13 = (ResourceItem *)&count;
          iVar16 = -1;
          iVar6 = BaseItem::typeID((BaseItem *)this_00);
          TRIBE_Player::objectCost(this->md->aiPlayer,iVar6,iVar16,pRVar13,iVar5);
        }
        iVar5 = TribeResourceAIModule::resourcesAvailable
                          (&this->md->resourceAI,(ResourceItem *)&count);
        if (iVar5 != 0) {
          if ((itemCost_ffffff80.numberValue == 2) || (itemCost_ffffff80.numberValue == 1)) {
            iVar17 = -1;
            iVar14 = 2;
            iVar12 = -1;
            iVar11 = -1;
            iVar10 = -1;
            iVar9 = -1;
            iVar16 = -1;
            iVar6 = -1;
            iVar5 = BuildItem::buildFrom(this_00);
            pRVar8 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)this->md,-1,iVar5,iVar6,iVar16,iVar9,iVar10,
                                iVar11,iVar12,iVar14,iVar17);
          }
          else {
            pRVar8 = (RGE_Static_Object *)
                     TribeConstructionAIModule::canPlace(&this->md->constructionAI,this_00);
          }
          if (pRVar8 != (RGE_Static_Object *)0x0) {
            uVar15 = 0x3f;
            pcVar7 = BaseItem::name((BaseItem *)this_00);
            strncpy((undefined1 *)((int)&this->_padding_ + 2),pcVar7,uVar15);
            iVar18 = BaseItem::uniqueID((BaseItem *)this_00);
            this->_padding_ = iVar18;
            uVar15 = 0x3f;
            pcVar7 = BaseItem::name((BaseItem *)this_00->next);
            strncpy((undefined1 *)((int)&this->_padding_ + 3),pcVar7,uVar15);
            iVar18 = BaseItem::uniqueID((BaseItem *)this_00);
            this->_padding_ = iVar18;
            ResourceItem::~ResourceItem((ResourceItem *)&count);
            goto LAB_004d499d;
          }
        }
        this_00 = this_00->next;
        ResourceItem::~ResourceItem((ResourceItem *)&count);
      }
      else {
LAB_004d489e:
        this_00 = this_00->next;
      }
                    /* language.dll match for 0x73: "B" */
      iVar5 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI,0x73);
    } while (iVar18 <= iVar5);
  }
  this_00 = (BuildItem *)0x0;
LAB_004d499d:
  *unaff_FS_OFFSET = itemCost_ffffff80.sortedIndexValue[4];
  return this_00;
}

// --------------------------------------------------

// Function: nextBuildListItemCategory
// Address: 004d4db0
/* public: int __thiscall TribeBuildAIModule::nextBuildListItemCategory(void) */

int __thiscall TribeBuildAIModule::nextBuildListItemCategory(TribeBuildAIModule *this)
{
  uchar uVar1;
  int iVar2;
  BuildItem *this_00;
  
  this_00 = (BuildItem *)this->_padding_;
  if (this_00 != (BuildItem *)&this->_padding_) {
    while (this_00 != (BuildItem *)0x0) {
      iVar2 = BuildItem::built(this_00);
      if (iVar2 == 0) {
        iVar2 = BuildItem::inProgress(this_00);
        if (iVar2 == 0) {
          iVar2 = BaseItem::skip((BaseItem *)this_00);
          if (iVar2 != 1) {
            uVar1 = BuildItem::permanentSkip(this_00);
            if (uVar1 == '\0') {
              iVar2 = BuildItem::buildCategory(this_00);
              return iVar2;
            }
          }
        }
      }
      this_00 = this_00->next;
      if (this_00 == (BuildItem *)&this->_padding_) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: blockingResource
// Address: 004d4e10
/* WARNING: Variable defined which should be unmapped: itemCost */
/* public: int __thiscall TribeBuildAIModule::blockingResource(void) */

int __thiscall TribeBuildAIModule::blockingResource(TribeBuildAIModule *this)
{
  int *piVar1;
  uchar uVar2;
  int iVar3;
  BuildItem *this_00;
  undefined4 *unaff_FS_OFFSET;
  int iVar4;
  ResourceItem *pRVar5;
  int iVar6;
  ResourceItem itemCost;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005602b8;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (BuildItem *)this->_padding_;
  piVar1 = &this->_padding_;
  if (this_00 == (BuildItem *)piVar1) goto LAB_004d4f6b;
  do {
    if (this_00 == (BuildItem *)0x0) break;
    iVar3 = BuildItem::built(this_00);
    if (iVar3 == 0) {
      iVar3 = BuildItem::inProgress(this_00);
      if (iVar3 == 0) {
        iVar3 = BaseItem::skip((BaseItem *)this_00);
        if (iVar3 != 1) {
          uVar2 = BuildItem::permanentSkip(this_00);
          if (uVar2 == '\0') break;
        }
      }
    }
    this_00 = this_00->next;
  } while (this_00 != (BuildItem *)piVar1);
  if ((this_00 == (BuildItem *)piVar1) || (this_00 == (BuildItem *)0x0)) goto LAB_004d4f6b;
  ResourceItem::ResourceItem((ResourceItem *)&itemCost.next,4);
  local_4 = 0;
  iVar3 = BuildItem::buildCategory(this_00);
  if (iVar3 == 1) {
LAB_004d4edb:
    pRVar5 = (ResourceItem *)&itemCost.next;
    iVar6 = 1;
    iVar4 = -1;
    iVar3 = BaseItem::typeID((BaseItem *)this_00);
    TRIBE_Player::researchCost(this->md->aiPlayer,iVar3,iVar4,pRVar5,iVar6);
  }
  else {
    iVar3 = BuildItem::buildCategory(this_00);
    if (iVar3 == 4) goto LAB_004d4edb;
    pRVar5 = (ResourceItem *)&itemCost.next;
    iVar6 = 1;
    iVar4 = -1;
    iVar3 = BaseItem::typeID((BaseItem *)this_00);
    TRIBE_Player::objectCost(this->md->aiPlayer,iVar3,iVar4,pRVar5,iVar6);
  }
  iVar3 = TribeResourceAIModule::resourcesAvailable
                    (&this->md->resourceAI,(ResourceItem *)&itemCost.next);
  if (iVar3 == 0) {
    iVar3 = TribeResourceAIModule::unavailableResource
                      (&this->md->resourceAI,(ResourceItem *)&itemCost.next);
    local_4 = 0xffffffff;
    ResourceItem::~ResourceItem((ResourceItem *)&itemCost.next);
    *unaff_FS_OFFSET = local_c;
    return iVar3;
  }
  local_4 = 0xffffffff;
  ResourceItem::~ResourceItem((ResourceItem *)&itemCost.next);
LAB_004d4f6b:
  *unaff_FS_OFFSET = local_c;
  return -1;
}

// --------------------------------------------------

// Function: mostNeededResource
// Address: 004d4f80
/* public: int __thiscall TribeBuildAIModule::mostNeededResource(class ResourceItem &,int) */

int __thiscall
TribeBuildAIModule::mostNeededResource(TribeBuildAIModule *this,ResourceItem *param_1,int param_2)
{
  ResourceItem *pRVar1;
  int iVar2;
  int iVar3;
  BuildItem *this_00;
  ResourceItem *pRVar4;
  int iVar5;
  
  pRVar1 = param_1;
  ResourceItem::setAllValues(param_1,0);
  this_00 = (BuildItem *)this->_padding_;
  param_1 = (ResourceItem *)0x0;
  if (this_00 != (BuildItem *)&this->_padding_) {
    do {
      if (this_00 == (BuildItem *)0x0) {
        return (int)param_1;
      }
      iVar2 = BuildItem::built(this_00);
      if (((iVar2 == 0) && (iVar2 = BuildItem::inProgress(this_00), iVar2 == 0)) &&
         (iVar2 = BuildItem::buildCategory(this_00), iVar2 != 6)) {
        iVar2 = BuildItem::buildCap(this_00);
        if (iVar2 != -1) {
          iVar2 = BuildItem::numberBuilds(this_00);
          iVar3 = BuildItem::buildCap(this_00);
          if (iVar3 < iVar2) goto LAB_004d506c;
        }
        iVar2 = BuildItem::buildCategory(this_00);
        if ((iVar2 == 1) || (iVar2 = BuildItem::buildCategory(this_00), iVar2 == 4)) {
          iVar5 = 1;
          iVar3 = -1;
          pRVar4 = pRVar1;
          iVar2 = BaseItem::typeID((BaseItem *)this_00);
          TRIBE_Player::researchCost(this->md->aiPlayer,iVar2,iVar3,pRVar4,iVar5);
        }
        else {
          iVar5 = 1;
          iVar3 = -1;
          pRVar4 = pRVar1;
          iVar2 = BaseItem::typeID((BaseItem *)this_00);
          TRIBE_Player::objectCost(this->md->aiPlayer,iVar2,iVar3,pRVar4,iVar5);
        }
        param_1 = (ResourceItem *)((int)&param_1->_padding_ + 1);
        if (param_1 == (ResourceItem *)param_2) {
          return (int)param_1;
        }
      }
LAB_004d506c:
      this_00 = this_00->next;
    } while (this_00 != (BuildItem *)&this->_padding_);
  }
  return (int)param_1;
}

// --------------------------------------------------

// Function: addItem
// Address: 004d5090
/* public: int __thiscall TribeBuildAIModule::addItem(class RGE_Static_Object *,int) */

int __thiscall
TribeBuildAIModule::addItem(TribeBuildAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  int iVar1;
  BuildItem *this_00;
  
  iVar1 = TribeInformationAIModule::isBuilding(&this->md->informationAI,param_1);
  if (iVar1 != 0) {
    TribeConstructionAIModule::setBuilt(&this->md->constructionAI,param_1,1);
  }
  if (param_2 == 0) {
    this_00 = (BuildItem *)this->_padding_;
    if (this_00 != (BuildItem *)&this->_padding_) {
      while (this_00 != (BuildItem *)0x0) {
        iVar1 = BaseItem::typeID((BaseItem *)this_00);
        if (iVar1 == param_1->master_obj->id) {
          iVar1 = BuildItem::built(this_00);
          if (iVar1 == 0) {
            BaseItem::setGameID((BaseItem *)this_00,param_1->id);
            BuildItem::setInProgress(this_00,0);
            BuildItem::setBuilt(this_00,1);
            BuildItem::incrementNumberBuilds(this_00);
            iVar1 = BaseItem::typeID((BaseItem *)this_00);
            if (iVar1 == 0x114) {
              (this->md->tacticalAI).wonderBuiltValue = 1;
            }
            return 1;
          }
        }
        this_00 = this_00->next;
        if (this_00 == (BuildItem *)&this->_padding_) {
          return 0;
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: addBuiltItem
// Address: 004d5170
/* public: int __thiscall TribeBuildAIModule::addBuiltItem(class RGE_Static_Object *,int) */

int __thiscall
TribeBuildAIModule::addBuiltItem(TribeBuildAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  int iVar1;
  char *pcVar2;
  bool bVar3;
  BuildItem *this_00;
  undefined4 uVar4;
  
  bVar3 = false;
  this_00 = (BuildItem *)this->_padding_;
  if (this_00 != (BuildItem *)&this->_padding_) {
    do {
      if ((this_00 == (BuildItem *)0x0) || (bVar3)) break;
      iVar1 = BaseItem::typeID((BaseItem *)this_00);
      if ((iVar1 == param_1->master_obj->id) &&
         (((iVar1 = BuildItem::built(this_00), iVar1 == 0 && (param_2 != -1)) &&
          (iVar1 = BaseItem::uniqueID((BaseItem *)this_00), iVar1 == param_2)))) {
        BuildItem::setInProgress(this_00,0);
        bVar3 = true;
        BuildItem::setBuilt(this_00,1);
        BaseItem::setGameID((BaseItem *)this_00,param_1->id);
        BuildItem::incrementNumberBuilds(this_00);
        iVar1 = BaseItem::typeID((BaseItem *)this_00);
        if (iVar1 == 0x114) {
          (this->md->tacticalAI).wonderBuiltValue = 1;
        }
        uVar4 = 0x3f;
        pcVar2 = BaseItem::name((BaseItem *)this_00);
        strncpy((undefined1 *)((int)&this->_padding_ + 1),pcVar2,uVar4);
        iVar1 = BaseItem::uniqueID((BaseItem *)this_00);
        this->_padding_ = iVar1;
      }
      else {
        this_00 = this_00->next;
      }
    } while (this_00 != (BuildItem *)&this->_padding_);
  }
  TribeTacticalAIModule::updateNeededResources(&this->md->tacticalAI);
  return 1;
}

// --------------------------------------------------

// Function: removeBuiltItem
// Address: 004d5270
/* public: int __thiscall TribeBuildAIModule::removeBuiltItem(int) */

int __thiscall TribeBuildAIModule::removeBuiltItem(TribeBuildAIModule *this,int param_1)
{
  BuildItem *this_00;
  int iVar1;
  bool bVar2;
  
  this_00 = (BuildItem *)this->_padding_;
  bVar2 = false;
  while (((this_00 != (BuildItem *)&this->_padding_ && (this_00 != (BuildItem *)0x0)) && (!bVar2)))
{
    iVar1 = BaseItem::gameID((BaseItem *)this_00);
    if ((iVar1 == param_1) && (iVar1 = BuildItem::built(this_00), iVar1 == 1)) {
      BuildItem::setInProgress(this_00,0);
      BuildItem::setBuilt(this_00,0);
      BaseItem::setGameID((BaseItem *)this_00,-1);
      BuildItem::setBuildAttempts(this_00,0);
      iVar1 = BaseItem::typeID((BaseItem *)this_00);
      if (iVar1 == 0x114) {
        (this->md->tacticalAI).wonderBuiltValue = 0;
      }
      bVar2 = true;
    }
    else {
      this_00 = this_00->next;
      bVar2 = false;
    }
  }
  TribeTacticalAIModule::updateNeededResources(&this->md->tacticalAI);
  return 1;
}

// --------------------------------------------------

// Function: cancelBuildItem
// Address: 004d5310
/* WARNING: Variable defined which should be unmapped: newLotStatus */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TribeBuildAIModule::cancelBuildItem(int,int,int,float,float,int,int) */

int __thiscall
TribeBuildAIModule::cancelBuildItem
          (TribeBuildAIModule *this,int param_1,int param_2,int param_3,float param_4,float param_5,
          int param_6,int param_7)
{
  bool bVar1;
  uchar uVar2;
  uchar uVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  ConstructionItem *this_00;
  BuildItem *this_01;
  uchar unaff_SI;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  uchar newLotStatus;
  
  if (param_7 != -1) {
    TribeMainDecisionAIModule::detask(this->md,param_7);
  }
  bVar1 = false;
  param_7 = 0;
  switch(param_1) {
  default:
    param_7 = 1;
    bVar1 = false;
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
    break;
  case 8:
    bVar1 = true;
    param_7 = 1;
    break;
  case -1:
    param_7 = 1;
    bVar1 = false;
  }
  pRVar4 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_2);
  if ((pRVar4 != (RGE_Static_Object *)0x0) && (bVar1)) {
    iVar5 = TribeMainDecisionAIModule::isMoveable(this->md,param_2);
    if (iVar5 == 1) {
      this_00 = ConstructionAIModule::lot
                          ((ConstructionAIModule *)&this->md->constructionAI,param_4,param_5);
      if (this_00 == (ConstructionItem *)0x0) {
        TribeTacticalAIModule::clearArea
                  (&this->md->tacticalAI,param_2,param_4 - _DAT_00575498,param_5 - _DAT_00575498,
                   param_4 - _DAT_00575494,param_5 - _DAT_00575494);
      }
      else {
        fVar6 = BaseItem::y((BaseItem *)this_00);
        fVar7 = BaseItem::ySize((BaseItem *)this_00);
        fVar6 = fVar6 - fVar7 * _DAT_0057548c;
        fVar7 = BaseItem::x((BaseItem *)this_00);
        fVar8 = BaseItem::xSize((BaseItem *)this_00);
        fVar7 = fVar7 - fVar8 * _DAT_0057548c;
        fVar8 = BaseItem::y((BaseItem *)this_00);
        fVar9 = BaseItem::ySize((BaseItem *)this_00);
        fVar8 = fVar8 - fVar9 * _DAT_00575490;
        fVar9 = BaseItem::x((BaseItem *)this_00);
        fVar10 = BaseItem::xSize((BaseItem *)this_00);
        TribeTacticalAIModule::clearArea
                  (&this->md->tacticalAI,param_2,fVar9 - fVar10 * _DAT_00575490,fVar8,fVar7,fVar6);
      }
    }
    else {
      (**(code **)((this->md->constructionAI)._padding_ + 0x58))(param_4,param_5,10);
    }
  }
  (**(code **)((this->md->constructionAI)._padding_ + 0x4c))(param_4,param_5,param_7);
  this_01 = BuildAIModule::specificBuildListItem((BuildAIModule *)this,param_3);
  if (this_01 != (BuildItem *)0x0) {
    BuildItem::setInProgress(this_01,0);
    uVar2 = __ftol();
    uVar3 = __ftol();
    iVar5 = BaseItem::typeID((BaseItem *)this_01);
    TribeInformationAIModule::removeLot(&this->md->informationAI,iVar5,uVar3,uVar2,unaff_SI);
    iVar5 = BaseItem::typeID((BaseItem *)this_01);
    if (iVar5 == 0x114) {
      (this->md->tacticalAI).wonderInProgressValue = 0;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: addTrainedUnit
// Address: 004d5590
/* public: int __thiscall TribeBuildAIModule::addTrainedUnit(int,int,int,int) */

int __thiscall
TribeBuildAIModule::addTrainedUnit
          (TribeBuildAIModule *this,int param_1,int param_2,int param_3,int param_4)
{
  BuildItem *this_00;
  
  this_00 = BuildAIModule::specificBuildListItem((BuildAIModule *)this,param_3);
  if (this_00 != (BuildItem *)0x0) {
    BuildItem::setInProgress(this_00,0);
    BuildItem::setBuilt(this_00,1);
    BaseItem::setGameID((BaseItem *)this_00,param_4);
    BuildItem::incrementNumberBuilds(this_00);
  }
  TribeMainDecisionAIModule::detask(this->md,param_2);
  TribeTacticalAIModule::updateNeededResources(&this->md->tacticalAI);
  return 1;
}

// --------------------------------------------------

// Function: cancelTrainUnit
// Address: 004d5600
// [HELPER] s_Canceling_training__WT__ld__for_: "Canceling training (WT=%ld) for item of type %d at building w/ gameID=%d."
// [HELPER] s___ERROR___Invalid_build_item_: "  ERROR!  Invalid build item."
// [HELPER] s___Setting_build_item___d_in_prog: "  Setting build item #%d in progress to FALSE."
/* public: int __thiscall TribeBuildAIModule::cancelTrainUnit(int,int,int,int) */

int __thiscall
TribeBuildAIModule::cancelTrainUnit
          (TribeBuildAIModule *this,int param_1,int param_2,int param_3,int param_4)
{
  AIModule *this_00;
  BuildItem *this_01;
  int iVar1;
  AIModule *this_02;
  AIModule *this_03;
  
  this_00 = *(AIModule **)(this->md->_padding_ + 0x3c);
  AIModule::logCommonHistory
            (this_00,(char *)this,s_Canceling_training__WT__ld__for_,(this_00->idValue)._padding_,
             param_2,param_3);
  this_01 = BuildAIModule::specificBuildListItem((BuildAIModule *)this,param_4);
  if (this_01 != (BuildItem *)0x0) {
    iVar1 = BaseItem::uniqueID((BaseItem *)this_01);
    AIModule::logCommonHistory(this_03,(char *)this,s___Setting_build_item___d_in_prog,iVar1);
    BuildItem::setInProgress(this_01,0);
    (**(code **)(this->_padding_ + 0x40))();
    return 1;
  }
  AIModule::logCommonHistory(this_02,(char *)this,s___ERROR___Invalid_build_item_);
  (**(code **)(this->_padding_ + 0x40))();
  return 1;
}

// --------------------------------------------------

// Function: addResearch
// Address: 004d5690
/* public: int __thiscall TribeBuildAIModule::addResearch(int,int,int) */

int __thiscall
TribeBuildAIModule::addResearch(TribeBuildAIModule *this,int param_1,int param_2,int param_3)
{
  BuildItem *this_00;
  
  this_00 = BuildAIModule::specificBuildListItem((BuildAIModule *)this,param_3);
  if (this_00 != (BuildItem *)0x0) {
    BuildItem::setInProgress(this_00,0);
    BuildItem::setBuilt(this_00,1);
    BuildItem::incrementNumberBuilds(this_00);
  }
  TribeMainDecisionAIModule::detask(this->md,param_2);
  TribeTacticalAIModule::updateNeededResources(&this->md->tacticalAI);
  return 1;
}

// --------------------------------------------------

// Function: cancelResearch
// Address: 004d56f0
// [HELPER] s_Canceling_research__WT__ld__for_: "Canceling research (WT=%ld) for item of type %d at building w/ gameID=%d."
// [HELPER] s___ERROR___Invalid_build_item_: "  ERROR!  Invalid build item."
// [HELPER] s___Setting_build_item___d_in_prog: "  Setting build item #%d in progress to FALSE."
/* public: int __thiscall TribeBuildAIModule::cancelResearch(int,int,int,int) */

int __thiscall
TribeBuildAIModule::cancelResearch
          (TribeBuildAIModule *this,int param_1,int param_2,int param_3,int param_4)
{
  AIModule *this_00;
  BuildItem *this_01;
  int iVar1;
  AIModule *this_02;
  AIModule *this_03;
  
  this_00 = *(AIModule **)(this->md->_padding_ + 0x3c);
  AIModule::logCommonHistory
            (this_00,(char *)this,s_Canceling_research__WT__ld__for_,(this_00->idValue)._padding_,
             param_2,param_3);
  this_01 = BuildAIModule::specificBuildListItem((BuildAIModule *)this,param_4);
  if (this_01 != (BuildItem *)0x0) {
    iVar1 = BaseItem::uniqueID((BaseItem *)this_01);
    AIModule::logCommonHistory(this_03,(char *)this,s___Setting_build_item___d_in_prog,iVar1);
    BuildItem::setInProgress(this_01,0);
    (**(code **)(this->_padding_ + 0x40))();
    return 1;
  }
  AIModule::logCommonHistory(this_02,(char *)this,s___ERROR___Invalid_build_item_);
  (**(code **)(this->_padding_ + 0x40))();
  return 1;
}

// --------------------------------------------------

// Function: isAgeResearch
// Address: 004d5780
/* public: int __thiscall TribeBuildAIModule::isAgeResearch(int) */

int __thiscall TribeBuildAIModule::isAgeResearch(TribeBuildAIModule *this,int param_1)
{
  if (((param_1 != 0x65) && (param_1 != 0x66)) && (param_1 != 0x67)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: insert
// Address: 004d57a0
/* WARNING: Variable defined which should be unmapped: buildCategory */
/* public: int __thiscall TribeBuildAIModule::insert(int,int,int) */

int __thiscall
TribeBuildAIModule::insert(TribeBuildAIModule *this,int param_1,int param_2,int param_3)
{
  BuildItem *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int buildCategory;
  int local_8;
  
  if (param_1 < 0xc) {
    if (param_1 == 0xb) {
switchD_004d580e_caseD_23:
      iVar2 = 0x31;
      local_8 = 2;
      goto LAB_004d58b9;
    }
    if (param_1 < 4) {
      return 0;
    }
    if (5 < param_1) {
      return 0;
    }
  }
  else {
    if (0x19 < param_1) {
      if (param_1 < 0x47) {
        if (param_1 < 0x44) {
          switch(param_1) {
          case 0x23:
          case 0x24:
            goto switchD_004d580e_caseD_23;
          case 0x25:
          case 0x28:
          case 0x2e:
            goto switchD_004d580e_caseD_25;
          default:
            goto switchD_004d57e5_caseD_e;
          case 0x27:
          case 0x29:
            goto switchD_004d580e_caseD_27;
          case 0x2d:
          case 0x31:
          case 0x32:
            break;
          }
        }
switchD_004d580e_caseD_2d:
        iVar2 = -1;
        local_8 = 0;
      }
      else {
        switch(param_1) {
        case 0x49:
        case 0x4b:
          iVar2 = 0xc;
          local_8 = 2;
          break;
        default:
switchD_004d57e5_caseD_e:
          return 0;
        case 0x4f:
        case 0x67:
        case 199:
        case 0x114:
        case 0x116:
          goto switchD_004d580e_caseD_2d;
        case 0x53:
          iVar2 = 0x6d;
          local_8 = 2;
          break;
        case 0x5d:
          iVar2 = 0;
          local_8 = 2;
          break;
        case 0x7d:
          iVar2 = 0x68;
          local_8 = 2;
          break;
        case 0xfa:
          goto switchD_004d57e5_caseD_d;
        case 299:
switchD_004d580e_caseD_25:
          iVar2 = 0x65;
          local_8 = 2;
        }
      }
      goto LAB_004d58b9;
    }
    if (param_1 != 0x19) {
      switch(param_1) {
      case 0xd:
      case 0xf:
      case 0x11:
      case 0x12:
      case 0x13:
        goto switchD_004d57e5_caseD_d;
      default:
        goto switchD_004d57e5_caseD_e;
      }
    }
  }
switchD_004d580e_caseD_27:
  iVar2 = 0x57;
  local_8 = 2;
LAB_004d58b9:
  if (param_3 != -1) {
    iVar2 = BuildAIModule::insertItem
                      ((BuildAIModule *)this,(RGE_Player *)this->md->_padding_,param_1,1,local_8,
                       iVar2,param_2,param_3);
    return iVar2;
  }
  this_00 = (BuildItem *)this->_padding_;
  iVar3 = 0;
  while (((this_00 != (BuildItem *)&this->_padding_ && (this_00 != (BuildItem *)0x0)) &&
         (iVar1 = BuildItem::built(this_00), iVar1 == 1))) {
    this_00 = this_00->next;
    iVar3 = iVar3 + 1;
  }
  iVar2 = BuildAIModule::insertItem
                    ((BuildAIModule *)this,(RGE_Player *)this->md->_padding_,param_1,1,local_8,iVar2
                     ,param_2,iVar3);
  return iVar2;
switchD_004d57e5_caseD_d:
  iVar2 = 0x2d;
  local_8 = 2;
  goto LAB_004d58b9;
}

// --------------------------------------------------

// Function: insertResearch
// Address: 004d5ad0
/* public: int __thiscall TribeBuildAIModule::insertResearch(int,int) */

int __thiscall TribeBuildAIModule::insertResearch(TribeBuildAIModule *this,int param_1,int param_2)
{
  BuildItem *this_00;
  int iVar1;
  int iVar2;
  
  if ((param_1 != 5) && ((param_1 < 7 || (8 < param_1)))) {
    return 0;
  }
  if (param_2 == -1) {
    this_00 = (BuildItem *)this->_padding_;
    iVar2 = 0;
    while (((this_00 != (BuildItem *)&this->_padding_ && (this_00 != (BuildItem *)0x0)) &&
           (iVar1 = BuildItem::built(this_00), iVar1 == 1))) {
      this_00 = this_00->next;
      iVar2 = iVar2 + 1;
    }
    iVar2 = BuildAIModule::insertItem
                      ((BuildAIModule *)this,(RGE_Player *)this->md->_padding_,param_1,1,1,0x2d,1,
                       iVar2);
    return iVar2;
  }
  iVar2 = BuildAIModule::insertItem
                    ((BuildAIModule *)this,(RGE_Player *)this->md->_padding_,param_1,1,1,0x2d,1,
                     param_2);
  return iVar2;
}

// --------------------------------------------------

// Function: insertGathererPercentage
// Address: 004d5b80
/* public: int __thiscall TribeBuildAIModule::insertGathererPercentage(int,int,int) */

int __thiscall
TribeBuildAIModule::insertGathererPercentage
          (TribeBuildAIModule *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = BuildAIModule::insertItem
                    ((BuildAIModule *)this,(RGE_Player *)this->md->_padding_,param_1,1,6,param_2,1,
                     param_3);
  return iVar1;
}

// --------------------------------------------------

// Function: numberBuiltOrInProgressItemsOfType
// Address: 004d5bb0
/* public: virtual int __thiscall TribeBuildAIModule::numberBuiltOrInProgressItemsOfType(int,int) */

int __thiscall
TribeBuildAIModule::numberBuiltOrInProgressItemsOfType
          (TribeBuildAIModule *this,int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  if ((param_2 == 0) && ((param_1 == 0x67 || (param_1 == 0x44)))) {
    iVar1 = BuildAIModule::numberInProgressItemsOfType((BuildAIModule *)this,param_1,0);
    if (param_1 == 0x67) {
      iVar2 = TribeInformationAIModule::numberStoragePits(&this->md->informationAI);
      return iVar1 + iVar2;
    }
    iVar2 = TribeInformationAIModule::numberGranaries(&this->md->informationAI);
    return iVar1 + iVar2;
  }
  iVar1 = BuildAIModule::numberBuiltOrInProgressItemsOfType((BuildAIModule *)this,param_1,param_2);
  return iVar1;
}

// --------------------------------------------------

// Function: allBuilt
// Address: 004d5c20
/* public: int __thiscall TribeBuildAIModule::allBuilt(int,int) */

int __thiscall TribeBuildAIModule::allBuilt(TribeBuildAIModule *this,int param_1,int param_2)
{
  int iVar1;
  BuildItem *this_00;
  
  this_00 = (BuildItem *)this->_padding_;
  if (this_00 != (BuildItem *)&this->_padding_) {
    while (this_00 != (BuildItem *)0x0) {
      iVar1 = BuildItem::buildCategory(this_00);
      if ((((iVar1 == param_1) || (iVar1 = BuildItem::buildCategory(this_00), iVar1 == param_2)) &&
          (iVar1 = BuildItem::built(this_00), iVar1 == 0)) &&
         (iVar1 = BuildItem::inProgress(this_00), iVar1 == 0)) {
        return 0;
      }
      this_00 = this_00->next;
      if (this_00 == (BuildItem *)&this->_padding_) {
        return 1;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: readyToResearch
// Address: 004d5ca0
/* public: int __thiscall TribeBuildAIModule::readyToResearch(int,int) */

int __thiscall TribeBuildAIModule::readyToResearch(TribeBuildAIModule *this,int param_1,int param_2)
{
  uchar uVar1;
  
  if (param_2 == 1) {
    if (param_1 == 2) {
                    /* language.dll match for 0x65: "1" */
      uVar1 = TRIBE_Player::researchState(this->md->aiPlayer,0x65);
    }
    else {
      uVar1 = (uchar)param_1;
    }
    if (param_1 == 3) {
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
      uVar1 = TRIBE_Player::researchState(this->md->aiPlayer,0x66);
    }
    if (param_1 == 4) {
                    /* language.dll match for 0x67: "Comic Sans MS" */
      uVar1 = TRIBE_Player::researchState(this->md->aiPlayer,0x67);
      return (uint)(uVar1 == '\x01');
    }
  }
  else {
    uVar1 = TRIBE_Player::researchState(this->md->aiPlayer,param_1);
  }
  return (uint)(uVar1 == '\x01');
}

// --------------------------------------------------

// Function: unskipBuildList
// Address: 004d5d40
/* public: void __thiscall TribeBuildAIModule::unskipBuildList(int,int) */

void __thiscall
TribeBuildAIModule::unskipBuildList(TribeBuildAIModule *this,int param_1,int param_2)
{
  code *pcVar1;
  BuildItem *this_00;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* language.dll match for 0x67: "Comic Sans MS" */
  pcVar1 = *(code **)(this->_padding_ + 0x48);
  iVar2 = (*pcVar1)(0x67,0);
  iVar3 = (*pcVar1)(0x44,0);
  for (this_00 = (BuildItem *)this->_padding_;
      (this_00 != (BuildItem *)&this->_padding_ && (this_00 != (BuildItem *)0x0));
      this_00 = this_00->next) {
    iVar4 = BuildItem::built(this_00);
    if ((((iVar4 != 1) && (iVar4 = BuildItem::inProgress(this_00), iVar4 != 1)) &&
        ((iVar2 < 1 || (iVar4 = BaseItem::typeID((BaseItem *)this_00), iVar4 != 0x67)))) &&
       ((iVar3 < 1 || (iVar4 = BaseItem::typeID((BaseItem *)this_00), iVar4 != 0x44)))) {
      BaseItem::setSkip((BaseItem *)this_00,0);
      BuildItem::setBuildAttempts(this_00,0);
      BuildItem::setSkipCycles(this_00,0);
      BuildItem::setPermanentSkip(this_00,'\0');
    }
  }
  return;
}

// --------------------------------------------------

// Function: buildItem
// Address: 004d5de0
/* public: class BuildItem * __thiscall TribeBuildAIModule::buildItem(int,int,int) */

BuildItem * __thiscall
TribeBuildAIModule::buildItem(TribeBuildAIModule *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  BuildItem *this_00;
  
  this_00 = (BuildItem *)this->_padding_;
  if (this_00 != (BuildItem *)&this->_padding_) {
    while (this_00 != (BuildItem *)0x0) {
      iVar1 = BuildItem::built(this_00);
      if ((((iVar1 == 0) && (iVar1 = BuildItem::inProgress(this_00), iVar1 == 0)) &&
          (iVar1 = BaseItem::typeID((BaseItem *)this_00), iVar1 == param_1)) &&
         ((iVar1 = BuildItem::buildCategory(this_00), iVar1 == param_2 ||
          (iVar1 = BuildItem::buildCategory(this_00), iVar1 == param_3)))) {
        return this_00;
      }
      this_00 = this_00->next;
      if (this_00 == (BuildItem *)&this->_padding_) {
        return (BuildItem *)0x0;
      }
    }
  }
  return (BuildItem *)0x0;
}

// --------------------------------------------------

