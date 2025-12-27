// Class: TribeConstructionAIModule
// Function: TribeConstructionAIModule
// Address: 004d5e60
/* public: __thiscall TribeConstructionAIModule::TribeConstructionAIModule(void *,int) */

TribeConstructionAIModule * __thiscall
TribeConstructionAIModule::TribeConstructionAIModule
          (TribeConstructionAIModule *this,void *param_1,int param_2)
{
  ConstructionAIModule::ConstructionAIModule((ConstructionAIModule *)this,param_1,param_2);
  this->md = (TribeMainDecisionAIModule *)0x0;
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004d5e90
/* public: virtual void * __thiscall TribeConstructionAIModule::`scalar deleting
   destructor'(unsigned int) */

void * __thiscall
TribeConstructionAIModule::_scalar_deleting_destructor_
          (TribeConstructionAIModule *this,uint param_1)
{
  ~TribeConstructionAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TribeConstructionAIModule
// Address: 004d5eb0
/* public: __thiscall TribeConstructionAIModule::TribeConstructionAIModule(int,int) */

TribeConstructionAIModule * __thiscall
TribeConstructionAIModule::TribeConstructionAIModule
          (TribeConstructionAIModule *this,int param_1,int param_2)
{
  ConstructionAIModule::ConstructionAIModule((ConstructionAIModule *)this,param_1,param_2);
  this->md = (TribeMainDecisionAIModule *)0x0;
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: ~TribeConstructionAIModule
// Address: 004d5ee0
/* public: virtual __thiscall TribeConstructionAIModule::~TribeConstructionAIModule(void) */

void __thiscall
TribeConstructionAIModule::~TribeConstructionAIModule(TribeConstructionAIModule *this)
{
  this->_padding_ = (int)&_vftable_;
  ConstructionAIModule::~ConstructionAIModule((ConstructionAIModule *)this);
  return;
}

// --------------------------------------------------

// Function: setMainDecisionAI
// Address: 004d5ef0
/* public: void __thiscall TribeConstructionAIModule::setMainDecisionAI(class
   TribeMainDecisionAIModule *) */

void __thiscall
TribeConstructionAIModule::setMainDecisionAI
          (TribeConstructionAIModule *this,TribeMainDecisionAIModule *param_1)
{
  this->md = param_1;
  return;
}

// --------------------------------------------------

// Function: canPlace
// Address: 004d5f00
/* public: int __thiscall TribeConstructionAIModule::canPlace(class BuildItem *) */

int __thiscall
TribeConstructionAIModule::canPlace(TribeConstructionAIModule *this,BuildItem *param_1)
{
  ConstructionItem *this_00;
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  float fVar3;
  ConstructionItem tempLots;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005602db;
  *unaff_FS_OFFSET = &local_c;
  if (((((float)UNK_005754fc._4_8_ < (float)this->_padding_) &&
       ((float)UNK_005754fc._4_8_ < (float)this->_padding_)) &&
      ((float)this->_padding_ < (float)this->_padding_)) &&
     ((float)this->_padding_ < (float)this->_padding_)) {
    iVar1 = BaseItem::typeID((BaseItem *)param_1);
    if (iVar1 == 0x2d) {
      iVar1 = 1;
      goto LAB_004d60b9;
    }
    if ((useInfluencePlacement != 1) && (this->_padding_ != 0)) {
      ConstructionItem::ConstructionItem((ConstructionItem *)&tempLots._padding_);
      this_00 = (ConstructionItem *)this->_padding_;
      tempLots.prev = (ConstructionItem *)&tempLots._padding_;
      tempLots.inProgressValue = (int)&tempLots._padding_;
      local_4 = 0;
      for (; (this_00 != (ConstructionItem *)&this->_padding_ &&
             (this_00 != (ConstructionItem *)0x0)); this_00 = this_00->next) {
        iVar1 = BaseItem::typeID((BaseItem *)this_00);
        iVar2 = BaseItem::typeID((BaseItem *)param_1);
        if (iVar1 == iVar2) {
LAB_004d604d:
          iVar1 = ConstructionItem::built(this_00);
          if ((iVar1 == 0) && (iVar1 = ConstructionItem::inProgress(this_00), iVar1 == 0)) {
            local_4 = 0xffffffff;
            ConstructionItem::~ConstructionItem((ConstructionItem *)&tempLots._padding_);
            iVar1 = 1;
            goto LAB_004d60b9;
          }
        }
        else {
          tempLots._padding_ = (int)BaseItem::xSize((BaseItem *)this_00);
          fVar3 = BaseItem::xSize((BaseItem *)param_1);
          if (fVar3 == (float)tempLots._padding_) {
            tempLots._padding_ = (int)BaseItem::ySize((BaseItem *)this_00);
            fVar3 = BaseItem::ySize((BaseItem *)param_1);
            if ((fVar3 == (float)tempLots._padding_) &&
               (iVar1 = BaseItem::typeID((BaseItem *)this_00), iVar1 == -1)) goto LAB_004d604d;
          }
        }
      }
      local_4 = 0xffffffff;
      ConstructionItem::~ConstructionItem((ConstructionItem *)&tempLots._padding_);
      iVar1 = 0;
      goto LAB_004d60b9;
    }
  }
  iVar1 = TribeInformationAIModule::influenceCanPlaceStructure(&this->md->informationAI,param_1);
LAB_004d60b9:
  *unaff_FS_OFFSET = local_c;
  return iVar1;
}

// --------------------------------------------------

// Function: placeStructure
// Address: 004d60e0
/* WARNING: Variable defined which should be unmapped: builderZone */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class ConstructionItem * __thiscall TribeConstructionAIModule::placeStructure(class
   BuildItem *,int,struct PlacementState &,unsigned long) */

ConstructionItem * __thiscall
TribeConstructionAIModule::placeStructure
          (TribeConstructionAIModule *this,BuildItem *param_1,int param_2,PlacementState *param_3,
          ulong param_4)
{
  int iVar1;
  int *piVar2;
  uchar uVar3;
  int iVar4;
  ConstructionItem *pCVar5;
  ConstructionItem *pCVar6;
  RGE_Static_Object *this_00;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *unaff_FS_OFFSET;
  float fVar11;
  float fVar12;
  uchar builderZone;
  int maxX;
  int minBuildAttempts;
  int local_ac;
  int numberTempLots;
  int j;
  int i;
  int minY;
  RGE_Static_Object *protoBuilder;
  RGE_Static_Object *builderObj;
  ConstructionItem tempLots;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560325;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (((((float)this->_padding_ <= (float)UNK_005754fc._4_8_) ||
       ((float)this->_padding_ <= (float)UNK_005754fc._4_8_)) ||
      ((float)this->_padding_ <= (float)this->_padding_)) ||
     ((float)this->_padding_ <= (float)this->_padding_)) {
LAB_004d674d:
    this_00 = (RGE_Static_Object *)
              TribeInformationAIModule::influencePlaceStructure
                        (&this->md->informationAI,param_1,param_2,-1,0.0,(char *)0x0,-1,-1,-1,-1,
                         param_3,param_4);
  }
  else {
    iVar4 = BaseItem::typeID((BaseItem *)param_1);
    if (iVar4 == 0x2d) {
      pCVar5 = placeDock(this,param_1);
      if (pCVar5 != (ConstructionItem *)0x0) {
                    /* language.dll match for 0x80: "Arial" */
        pCVar6 = (ConstructionItem *)operator_new(0x80);
        local_4 = 0;
        if (pCVar6 != (ConstructionItem *)0x0) {
          this_00 = (RGE_Static_Object *)ConstructionItem::ConstructionItem(pCVar6,pCVar5);
          goto LAB_004d675e;
        }
      }
    }
    else {
      iVar4 = BaseItem::typeID((BaseItem *)param_1);
      if ((((((iVar4 == 0x67) || (iVar4 = BaseItem::typeID((BaseItem *)param_1), iVar4 == 0x44)) ||
            ((iVar4 = BaseItem::typeID((BaseItem *)param_1), iVar4 == 0x4f ||
             ((iVar4 = BaseItem::typeID((BaseItem *)param_1), iVar4 == 199 ||
              (iVar4 = BaseItem::typeID((BaseItem *)param_1), iVar4 == 0x45)))))) ||
           (iVar4 = BaseItem::typeID((BaseItem *)param_1), iVar4 == 0x48)) ||
          (((iVar4 = BaseItem::typeID((BaseItem *)param_1), iVar4 == 0x75 ||
            (iVar4 = BaseItem::typeID((BaseItem *)param_1), iVar4 == 0x9b)) ||
           (useInfluencePlacement == 1)))) || (this->_padding_ == 0)) goto LAB_004d674d;
      this_00 = MainDecisionAIModule::object
                          ((MainDecisionAIModule *)this->md,-1,-1,4,-1,-1,-1,-1,-1,-1,-1);
      if (this_00 == (RGE_Static_Object *)0x0) goto LAB_004d675e;
      tempLots._padding_ =
           (int)MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_2);
      maxX._3_1_ = '\0';
      if ((RGE_Static_Object *)tempLots._padding_ != (RGE_Static_Object *)0x0) {
        maxX._3_1_ = RGE_Static_Object::currentZone((RGE_Static_Object *)tempLots._padding_);
      }
      ConstructionItem::ConstructionItem((ConstructionItem *)&tempLots._padding_);
      pCVar5 = (ConstructionItem *)this->_padding_;
      tempLots.prev = (ConstructionItem *)&tempLots._padding_;
      tempLots.inProgressValue = (int)&tempLots._padding_;
      local_4 = 1;
      j = 0;
      local_ac = -1;
      for (; (pCVar5 != (ConstructionItem *)&this->_padding_ && (pCVar5 != (ConstructionItem *)0x0))
          ; pCVar5 = pCVar5->next) {
        iVar4 = BaseItem::typeID((BaseItem *)param_1);
        iVar7 = BaseItem::typeID((BaseItem *)pCVar5);
        if ((iVar7 == iVar4) || (iVar4 = BaseItem::typeID((BaseItem *)pCVar5), iVar4 == -1)) {
          fVar11 = BaseItem::xSize((BaseItem *)pCVar5);
          fVar12 = BaseItem::xSize((BaseItem *)param_1);
          if (fVar12 == fVar11) {
            fVar11 = BaseItem::ySize((BaseItem *)pCVar5);
            fVar12 = BaseItem::ySize((BaseItem *)param_1);
            if (((fVar12 == fVar11) && (iVar4 = ConstructionItem::built(pCVar5), iVar4 != 1)) &&
               (iVar4 = ConstructionItem::inProgress(pCVar5), iVar4 != 1)) {
              BaseItem::x((BaseItem *)pCVar5);
              BaseItem::xSize((BaseItem *)pCVar5);
              iVar4 = __ftol();
              BaseItem::y((BaseItem *)pCVar5);
              BaseItem::ySize((BaseItem *)pCVar5);
              iVar7 = __ftol();
              BaseItem::xSize((BaseItem *)pCVar5);
              iVar8 = __ftol();
              iVar8 = iVar8 + iVar4;
              BaseItem::ySize((BaseItem *)pCVar5);
              iVar9 = __ftol();
              if ((((-1 < iVar4) && (-1 < iVar7)) && (iVar8 < this->_padding_)) &&
                 (iVar9 + iVar7 < this->_padding_)) {
                for (; iVar1 = iVar7, iVar4 < iVar8; iVar4 = iVar4 + 1) {
                  for (; iVar1 < iVar9 + iVar7; iVar1 = iVar1 + 1) {
                    if ((((RGE_Static_Object *)tempLots._padding_ != (RGE_Static_Object *)0x0) &&
                        (uVar3 = RGE_Static_Object::lookupZone
                                           ((RGE_Static_Object *)tempLots._padding_,iVar4,iVar1),
                        uVar3 != maxX._3_1_)) ||
                       (iVar10 = (**(code **)(this_00->_padding_ + 0x114))
                                           ((float)iVar4 - ram0x00575508,
                                            (float)iVar1 - ram0x00575508,1), iVar10 == 0))
                    goto LAB_004d6520;
                  }
                }
                    /* language.dll match for 0x80: "Arial" */
                pCVar6 = (ConstructionItem *)operator_new(0x80);
                local_4._0_1_ = 2;
                if (pCVar6 == (ConstructionItem *)0x0) {
                  iVar4 = 0;
                }
                else {
                  iVar4 = ConstructionItem::ConstructionItem(pCVar6,pCVar5);
                }
                *(int **)(iVar4 + 0x6c) = &tempLots._padding_;
                *(int *)(iVar4 + 0x70) = tempLots.inProgressValue;
                local_4 = CONCAT31(local_4._1_3_,1);
                *(int *)(tempLots.inProgressValue + 0x6c) = iVar4;
                j = j + 1;
                tempLots.inProgressValue = iVar4;
                if ((local_ac == -1) ||
                   (iVar4 = ConstructionItem::buildAttempts(pCVar5), iVar4 < local_ac)) {
                  local_ac = ConstructionItem::buildAttempts(pCVar5);
                }
              }
            }
          }
        }
LAB_004d6520:
                    /* Symbol Ref: {@symbol LoopDone} */
      }
      if (((1 < local_ac) || (local_ac == -1)) &&
         (this_00 = (RGE_Static_Object *)
                    TribeInformationAIModule::influencePlaceStructure
                              (&this->md->informationAI,param_1,param_2,-1,0.0,(char *)0x0,-1,-1,-1,
                               -1,param_3,param_4), this_00 != (RGE_Static_Object *)0x0)) {
        local_4 = 0xffffffff;
        ConstructionItem::~ConstructionItem((ConstructionItem *)&tempLots._padding_);
        goto LAB_004d675e;
      }
      pCVar5 = tempLots.prev;
      if (j != 0) {
        pCVar6 = (tempLots.prev)->next;
        iVar4 = BaseItem::typeID((BaseItem *)param_1);
        if (iVar4 == 0x48) {
          if (pCVar6 != (ConstructionItem *)&tempLots._padding_) {
            do {
              if (pCVar6 == (ConstructionItem *)0x0) break;
              iVar4 = ConstructionItem::buildAttempts(pCVar5);
              iVar7 = ConstructionItem::buildAttempts(pCVar6);
              if (iVar7 + 5 < iVar4) {
                pCVar5 = pCVar6;
              }
              pCVar6 = pCVar6->next;
            } while (pCVar6 != (ConstructionItem *)&tempLots._padding_);
          }
        }
        else if (pCVar6 != (ConstructionItem *)&tempLots._padding_) {
          do {
            if (pCVar6 == (ConstructionItem *)0x0) break;
            pCVar5 = compare(this,pCVar5,pCVar6);
            pCVar6 = pCVar6->next;
          } while (pCVar6 != (ConstructionItem *)&tempLots._padding_);
        }
        fVar11 = BaseItem::y((BaseItem *)pCVar5);
        fVar12 = BaseItem::x((BaseItem *)pCVar5);
        pCVar5 = ConstructionAIModule::lot((ConstructionAIModule *)this,fVar12,fVar11);
        ConstructionItem::setInProgress(pCVar5,1);
        ConstructionItem::incrementBuildAttempts(pCVar5);
        iVar4 = BaseItem::uniqueID((BaseItem *)param_1);
        BaseItem::setUniqueID((BaseItem *)pCVar5,iVar4);
        this_00 = (RGE_Static_Object *)0x0;
                    /* language.dll match for 0x80: "Arial" */
        this->_padding_ = 0;
        pCVar6 = (ConstructionItem *)operator_new(0x80);
        local_4._0_1_ = 3;
        if (pCVar6 != (ConstructionItem *)0x0) {
          this_00 = (RGE_Static_Object *)ConstructionItem::ConstructionItem(pCVar6,pCVar5);
        }
        local_4 = CONCAT31(local_4._1_3_,1);
        iVar4 = BaseItem::typeID((BaseItem *)param_1);
        BaseItem::setTypeID((BaseItem *)this_00,iVar4);
        pCVar5 = tempLots.prev;
        if (tempLots.prev != (ConstructionItem *)&tempLots._padding_) {
          do {
            if (pCVar5 == (ConstructionItem *)0x0) break;
            piVar2 = &pCVar5->_padding_;
            pCVar5 = pCVar5->next;
            (**(code **)*piVar2)(1);
          } while (pCVar5 != (ConstructionItem *)&tempLots._padding_);
        }
        local_4 = 0xffffffff;
        ConstructionItem::~ConstructionItem((ConstructionItem *)&tempLots._padding_);
        goto LAB_004d675e;
      }
      this->_padding_ = 5;
      local_4 = 0xffffffff;
      ConstructionItem::~ConstructionItem((ConstructionItem *)&tempLots._padding_);
    }
    this_00 = (RGE_Static_Object *)0x0;
  }
LAB_004d675e:
  *unaff_FS_OFFSET = local_c;
  return (ConstructionItem *)this_00;
}

// --------------------------------------------------

// Function: placeDock
// Address: 004d6780
/* public: class ConstructionItem * __thiscall TribeConstructionAIModule::placeDock(class BuildItem
   *) */

ConstructionItem * __thiscall
TribeConstructionAIModule::placeDock(TribeConstructionAIModule *this,BuildItem *param_1)
{
  ConstructionItem *pCVar1;
  ConstructionItem *pCVar2;
  
  pCVar2 = TribeInformationAIModule::placeDock
                     (&this->md->informationAI,param_1,(float)this->_padding_,(float)this->_padding_
                      ,1,2);
  if (pCVar2 != (ConstructionItem *)0x0) {
    pCVar2->next = (ConstructionItem *)&this->_padding_;
    pCVar1 = (ConstructionItem *)this->_padding_;
    pCVar2->prev = pCVar1;
    pCVar1->next = pCVar2;
    this->_padding_ = (int)pCVar2;
    this->_padding_ = this->_padding_ + 1;
    this->_padding_ = 0;
    return pCVar2;
  }
  this->_padding_ = 5;
  return (ConstructionItem *)0x0;
}

// --------------------------------------------------

// Function: setBuilt
// Address: 004d6800
/* public: void __thiscall TribeConstructionAIModule::setBuilt(class RGE_Static_Object *,int) */

void __thiscall
TribeConstructionAIModule::setBuilt
          (TribeConstructionAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  ConstructionItem *this_00;
  uchar uVar1;
  uchar uVar2;
  int iVar3;
  float fVar4;
  uchar uVar5;
  
  this_00 = (ConstructionItem *)this->_padding_;
  while( true ) {
    if ((this_00 == (ConstructionItem *)&this->_padding_) || (this_00 == (ConstructionItem *)0x0)) {
      uVar5 = '\x01';
      uVar1 = __ftol();
      uVar2 = __ftol();
      TribeInformationAIModule::storeLot
                (&this->md->informationAI,(int)param_1->master_obj->id,uVar2,uVar1,uVar5);
      return;
    }
    iVar3 = BaseItem::typeID((BaseItem *)this_00);
    if ((iVar3 == param_1->master_obj->id) &&
       ((fVar4 = BaseItem::x((BaseItem *)this_00), fVar4 == param_1->world_x &&
        (fVar4 = BaseItem::y((BaseItem *)this_00), fVar4 == param_1->world_y)))) break;
    this_00 = this_00->next;
  }
  ConstructionItem::setBuilt(this_00,param_2);
  return;
}

// --------------------------------------------------

// Function: compare
// Address: 004d68a0
/* protected: class ConstructionItem * __thiscall TribeConstructionAIModule::compare(class
   ConstructionItem *,class ConstructionItem *) */

ConstructionItem * __thiscall
TribeConstructionAIModule::compare
          (TribeConstructionAIModule *this,ConstructionItem *param_1,ConstructionItem *param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = ConstructionItem::buildAttempts(param_1);
  iVar2 = ConstructionItem::buildAttempts(param_2);
  if (iVar1 <= iVar2) {
    param_2 = param_1;
  }
  return param_2;
}

// --------------------------------------------------

