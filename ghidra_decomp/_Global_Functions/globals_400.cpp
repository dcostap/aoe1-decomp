// GLOBAL FUNCTIONS PART 400
// Function: FUN_0040bb77
// Address: 0040bb77
float10 __fastcall FUN_0040bb77(int param_1)
{
  return (float10)*(float *)(param_1 + 0x300);
}

// --------------------------------------------------

// Function: FUN_0040bb87
// Address: 0040bb87
undefined4 FUN_0040bb87(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040bb95
// Address: 0040bb95
undefined4 __fastcall FUN_0040bb95(int param_1)
{
  return *(undefined4 *)(param_1 + 0x310);
}

// --------------------------------------------------

// Function: FUN_0040bba7
// Address: 0040bba7
void __thiscall FUN_0040bba7(int param_1,ConstructionItem *param_2,int param_3)
{
  int iVar1;
  ConstructionItem *this;
  
  this = *(ConstructionItem **)(param_1 + 0x160);
  if (this != (ConstructionItem *)(param_1 + 0xf4)) {
    while (this != (ConstructionItem *)0x0) {
      iVar1 = operator==(this,param_2);
      if (iVar1 != 0) {
        ConstructionItem::setBuilt(this,param_3);
        return;
      }
      this = this->next;
      if (this == (ConstructionItem *)(param_1 + 0xf4)) {
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040bbf8
// Address: 0040bbf8
int __thiscall FUN_0040bbf8(int param_1,ConstructionItem *param_2,int param_3)
{
  int iVar1;
  ConstructionItem *this;
  
  this = *(ConstructionItem **)(param_1 + 0x160);
  if (this != (ConstructionItem *)(param_1 + 0xf4)) {
    while (this != (ConstructionItem *)0x0) {
      iVar1 = operator==(this,param_2);
      if (iVar1 != 0) {
        ConstructionItem::setInProgress(this,0);
        ConstructionItem::setBuilt(this,0);
        iVar1 = BaseItem::uniqueID((BaseItem *)this);
        BaseItem::setUniqueID((BaseItem *)this,-1);
        if (param_3 == 1) {
          ConstructionItem::decrementBuildAttempts(this);
        }
        return iVar1;
      }
      this = this->next;
      if (this == (ConstructionItem *)(param_1 + 0xf4)) {
        return -1;
      }
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_0040bc7c
// Address: 0040bc7c
int __thiscall FUN_0040bc7c(int param_1,float param_2,float param_3,int param_4)
{
  int iVar1;
  ConstructionItem *this;
  float fVar2;
  
  this = *(ConstructionItem **)(param_1 + 0x160);
  if (this != (ConstructionItem *)(param_1 + 0xf4)) {
    while (this != (ConstructionItem *)0x0) {
      fVar2 = BaseItem::x((BaseItem *)this);
      if (fVar2 == param_2) {
        fVar2 = BaseItem::y((BaseItem *)this);
        if (fVar2 == param_3) {
          ConstructionItem::setInProgress(this,0);
          ConstructionItem::setBuilt(this,0);
          iVar1 = BaseItem::uniqueID((BaseItem *)this);
          BaseItem::setUniqueID((BaseItem *)this,-1);
          if (param_4 == 1) {
            ConstructionItem::decrementBuildAttempts(this);
          }
          return iVar1;
        }
      }
      this = this->next;
      if (this == (ConstructionItem *)(param_1 + 0xf4)) {
        return -1;
      }
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_0040bd0a
// Address: 0040bd0a
void __thiscall FUN_0040bd0a(ConstructionAIModule *param_1,float param_2,float param_3,int param_4)
{
  ConstructionItem *this;
  
  this = ConstructionAIModule::lot(param_1,param_2,param_3);
  if ((this != (ConstructionItem *)0x0) && (0 < param_4)) {
    do {
      ConstructionItem::decrementBuildAttempts(this);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040bd3e
// Address: 0040bd3e
void __thiscall FUN_0040bd3e(ConstructionAIModule *param_1,float param_2,float param_3,int param_4)
{
  ConstructionItem *this;
  
  this = ConstructionAIModule::lot(param_1,param_2,param_3);
  if ((this != (ConstructionItem *)0x0) && (0 < param_4)) {
    do {
      ConstructionItem::incrementBuildAttempts(this);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040bd6e
// Address: 0040bd6e
BaseItem * __thiscall FUN_0040bd6e(int param_1,float param_2,float param_3)
{
  BaseItem *pBVar1;
  float fVar2;
  
  pBVar1 = *(BaseItem **)(param_1 + 0x160);
  while( true ) {
    if ((pBVar1 == (BaseItem *)(param_1 + 0xf4)) || (pBVar1 == (BaseItem *)0x0)) {
      pBVar1 = *(BaseItem **)(param_1 + 0x1e4);
      if (pBVar1 != (BaseItem *)(param_1 + 0x178)) {
        while (pBVar1 != (BaseItem *)0x0) {
          fVar2 = BaseItem::x(pBVar1);
          if ((fVar2 == param_2) && (fVar2 = BaseItem::y(pBVar1), fVar2 == param_3)) {
            return pBVar1;
          }
          pBVar1 = (BaseItem *)pBVar1[1]._padding_;
          if (pBVar1 == (BaseItem *)(param_1 + 0x178)) {
            return (BaseItem *)0x0;
          }
        }
      }
      return (BaseItem *)0x0;
    }
    fVar2 = BaseItem::x(pBVar1);
    if ((fVar2 == param_2) && (fVar2 = BaseItem::y(pBVar1), fVar2 == param_3)) break;
    pBVar1 = (BaseItem *)pBVar1[1]._padding_;
  }
  return pBVar1;
}

// --------------------------------------------------

// Function: FUN_0040be0b
// Address: 0040be0b
BaseItem * __thiscall FUN_0040be0b(int param_1,float param_2,float param_3)
{
  BaseItem *this;
  float fVar1;
  
  this = *(BaseItem **)(param_1 + 0x1e4);
  if (this != (BaseItem *)(param_1 + 0x178)) {
    while (this != (BaseItem *)0x0) {
      fVar1 = BaseItem::x(this);
      if (fVar1 == param_2) {
        fVar1 = BaseItem::y(this);
        if (fVar1 == param_3) {
          return this;
        }
      }
      this = (BaseItem *)this[1]._padding_;
      if (this == (BaseItem *)(param_1 + 0x178)) {
        return (BaseItem *)0x0;
      }
    }
  }
  return (BaseItem *)0x0;
}

// --------------------------------------------------

// Function: FUN_0040be66
// Address: 0040be66
void __fastcall FUN_0040be66(int param_1)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 0x160);
  puVar1 = (undefined4 *)(param_1 + 0xf4);
  while ((puVar2 != puVar1 && (puVar2 != (undefined4 *)0x0))) {
    puVar3 = (undefined4 *)*puVar2;
    puVar2 = (undefined4 *)puVar2[0x1b];
    (*(code *)*puVar3)(1);
  }
  *(undefined4 **)(param_1 + 0x160) = puVar1;
  *(undefined4 **)(param_1 + 0x164) = puVar1;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0040beb2
// Address: 0040beb2
// [HELPER] s_Diplomacy_AI: "Diplomacy AI"
AIModule * __thiscall FUN_0040beb2(AIModule *param_1,void *param_2,int param_3)
{
  int iVar1;
  char *pcVar2;
  
  AIModule::AIModule(param_1,s_Diplomacy_AI,0x3eb,param_3,param_2);
  iVar1 = 0;
  param_1->_padding_ = (int)&DiplomacyAIModule::_vftable_;
  param_1[1]._padding_ = 0;
  pcVar2 = param_1[1].idValue.name + 0x20;
  do {
    ((AIModuleID *)(pcVar2 + -0x28))->_padding_ = 0x31;
    pcVar2[0] = '1';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    param_1[1].playerNameValue[iVar1 + 4] = '\x01';
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 4;
  } while (iVar1 < 10);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040bf16
// Address: 0040bf16
DiplomacyAIModule * __thiscall FUN_0040bf16(DiplomacyAIModule *param_1,byte param_2)
{
  DiplomacyAIModule::~DiplomacyAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040bf3e
// Address: 0040bf3e
// [HELPER] s_Diplomacy_AI: "Diplomacy AI"
AIModule * __thiscall FUN_0040bf3e(AIModule *param_1,int param_2,int param_3)
{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c5f8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  AIModule::AIModule(param_1,s_Diplomacy_AI,0x3eb,param_2,(void *)0x0);
  uStack_4 = 0;
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&DiplomacyAIModule::_vftable_;
  pcVar1 = param_1[1].playerNameValue + 4;
  pcVar3 = param_1[1].idValue.name + 0x20;
  iVar2 = 10;
  do {
    rge_read(param_3,(AIModuleID *)(pcVar3 + -0x28),4);
    rge_read(param_3,pcVar3,4);
    rge_read(param_3,pcVar1,1);
    pcVar3 = pcVar3 + 4;
    pcVar1 = pcVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040bfe3
// Address: 0040bfe3
void __fastcall FUN_0040bfe3(AIModule *param_1)
{
  param_1->_padding_ = (int)&DiplomacyAIModule::_vftable_;
  AIModule::~AIModule(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0040bffb
// Address: 0040bffb
void __thiscall FUN_0040bffb(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xf0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040c00d
// Address: 0040c00d
undefined4 __fastcall FUN_0040c00d(DiplomacyAIModule *param_1)
{
  RGE_Player *pRVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  pRVar1 = param_1->md->player;
  if (1 < pRVar1->world->player_num) {
    do {
      if (iVar3 != pRVar1->id) {
        iVar2 = DiplomacyAIModule::isAlly(param_1,iVar3);
        if (iVar2 != 0) {
          iVar2 = DiplomacyAIModule::isAlliedWithMe(param_1,iVar3);
          if (iVar2 == 0) {
            DiplomacyAIModule::changeStance(param_1,iVar3,0,1);
          }
        }
        iVar2 = DiplomacyAIModule::isAlly(param_1,iVar3);
        if (iVar2 == 0) {
          iVar2 = DiplomacyAIModule::isAlliedWithMe(param_1,iVar3);
          if (iVar2 != 0) {
            DiplomacyAIModule::changeStance(param_1,iVar3,2,1);
          }
        }
      }
      iVar3 = iVar3 + 1;
      pRVar1 = param_1->md->player;
    } while (iVar3 < pRVar1->world->player_num);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040c09f
// Address: 0040c09f
undefined4 __thiscall FUN_0040c09f(int param_1,int param_2)
{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  
  pvVar1 = (void *)(param_1 + 0x144);
  pvVar3 = (void *)(param_1 + 0x11c);
  iVar2 = 10;
  do {
    rge_write(param_2,(void *)((int)pvVar3 + -0x28),4);
    rge_write(param_2,pvVar3,4);
    rge_write(param_2,pvVar1,1);
    pvVar3 = (void *)((int)pvVar3 + 4);
    pvVar1 = (void *)((int)pvVar1 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040c0f3
// Address: 0040c0f3
int __thiscall FUN_0040c0f3(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  if ((0 < param_2) &&
     (param_2 < *(short *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c) + 0x3c))) {
    if (param_3 == 0) {
      return *(int *)(param_1 + 0xf4 + param_2 * 4);
    }
    if (param_3 == 1) {
      iVar2 = 0x31 - *(int *)(param_1 + 0xf4 + param_2 * 4);
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      iVar1 = 0x31 - *(int *)(param_1 + 0x11c + param_2 * 4);
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
      iVar1 = (100 - iVar2) - iVar1;
      if (-1 < iVar1) {
        return iVar1;
      }
      return 0;
    }
    if (param_3 == 2) {
      return *(int *)(param_1 + 0x11c + param_2 * 4);
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_0040c186
// Address: 0040c186
void __thiscall FUN_0040c186(int param_1,int param_2,int param_3,int param_4)
{
  if ((0 < param_2) &&
     (param_2 < *(short *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c) + 0x3c))) {
    if (param_3 == 0) {
      param_4 = *(int *)(param_1 + 0xf4 + param_2 * 4) + param_4;
      *(int *)(param_1 + 0xf4 + param_2 * 4) = param_4;
      if (*(char *)(param_1 + 0x144 + param_2) == '\0') {
        if (param_4 < 0x32) {
          *(undefined4 *)(param_1 + 0xf4 + param_2 * 4) = 0x32;
          return;
        }
        if (100 < param_4) {
          *(undefined4 *)(param_1 + 0xf4 + param_2 * 4) = 100;
        }
      }
      else {
        if (param_4 < 0) {
          *(undefined4 *)(param_1 + 0xf4 + param_2 * 4) = 0;
          return;
        }
        if (100 < param_4) {
          *(undefined4 *)(param_1 + 0xf4 + param_2 * 4) = 100;
          return;
        }
      }
    }
    else if (param_3 == 2) {
      param_4 = *(int *)(param_1 + 0x11c + param_2 * 4) + param_4;
      *(int *)(param_1 + 0x11c + param_2 * 4) = param_4;
      if (*(char *)(param_1 + 0x144 + param_2) == '\0') {
        if (param_4 < 0) {
          *(undefined4 *)(param_1 + 0x11c + param_2 * 4) = 0;
          return;
        }
        if (0x30 < param_4) {
          *(undefined4 *)(param_1 + 0x11c + param_2 * 4) = 0x30;
          return;
        }
      }
      else {
        if (param_4 < 0) {
          *(undefined4 *)(param_1 + 0x11c + param_2 * 4) = 0;
          return;
        }
        if (100 < param_4) {
          *(undefined4 *)(param_1 + 0x11c + param_2 * 4) = 100;
          return;
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040c2ab
// Address: 0040c2ab
void __thiscall FUN_0040c2ab(int param_1,int param_2,int param_3,int param_4)
{
  if ((0 < param_2) &&
     (param_2 < *(short *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c) + 0x3c))) {
    if (param_3 == 0) {
      *(int *)(param_1 + 0xf4 + param_2 * 4) = param_4;
      if (*(char *)(param_1 + 0x144 + param_2) == '\0') {
        if (param_4 < 0x32) {
          *(undefined4 *)(param_1 + 0xf4 + param_2 * 4) = 0x32;
          return;
        }
        if (100 < param_4) {
          *(undefined4 *)(param_1 + 0xf4 + param_2 * 4) = 100;
        }
      }
      else {
        if (param_4 < 0) {
          *(undefined4 *)(param_1 + 0xf4 + param_2 * 4) = 0;
          return;
        }
        if (100 < param_4) {
          *(undefined4 *)(param_1 + 0xf4 + param_2 * 4) = 100;
          return;
        }
      }
    }
    else if (param_3 == 2) {
      *(int *)(param_1 + 0x11c + param_2 * 4) = param_4;
      if (*(char *)(param_1 + 0x144 + param_2) == '\0') {
        if (param_4 < 0) {
          *(undefined4 *)(param_1 + 0x11c + param_2 * 4) = 0;
          return;
        }
        if (0x30 < param_4) {
          *(undefined4 *)(param_1 + 0x11c + param_2 * 4) = 0x30;
          return;
        }
      }
      else {
        if (param_4 < 0) {
          *(undefined4 *)(param_1 + 0x11c + param_2 * 4) = 0;
          return;
        }
        if (100 < param_4) {
          *(undefined4 *)(param_1 + 0x11c + param_2 * 4) = 100;
          return;
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040c3ac
// Address: 0040c3ac
undefined4 __thiscall FUN_0040c3ac(int param_1,int param_2)
{
  if (((0 < param_2) &&
      (param_2 < *(short *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c) + 0x3c))) &&
     (0x31 < *(int *)(param_1 + 0xf4 + param_2 * 4))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040c3e6
// Address: 0040c3e6
undefined4 __thiscall FUN_0040c3e6(DiplomacyAIModule *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = DiplomacyAIModule::isDisliked(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = DiplomacyAIModule::isLiked(param_1,param_2);
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040c41f
// Address: 0040c41f
undefined4 __thiscall FUN_0040c41f(int param_1,int param_2)
{
  if (((0 < param_2) &&
      (param_2 < *(short *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c) + 0x3c))) &&
     (0x31 < *(int *)(param_1 + 0x11c + param_2 * 4))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040c456
// Address: 0040c456
undefined4 __thiscall FUN_0040c456(int param_1,int param_2)
{
  if (((0 < param_2) &&
      (param_2 < *(short *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c) + 0x3c))) &&
     (*(char *)(param_1 + 0x144 + param_2) == '\x01')) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040c496
// Address: 0040c496
void __thiscall FUN_0040c496(int param_1,int param_2,undefined1 param_3)
{
  if ((0 < param_2) &&
     (param_2 < *(short *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c) + 0x3c))) {
    *(undefined1 *)(param_1 + 0x144 + param_2) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040c4cd
// Address: 0040c4cd
int __thiscall
FUN_0040c4cd(DiplomacyAIModule *param_1,int param_2,int param_3,int param_4,int param_5)
{
  RGE_Game_World *pRVar1;
  int iVar2;
  long lVar3;
  RGE_Player *pRVar4;
  int *piVar5;
  int iVar6;
  int iStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  iStack_8 = -1;
  iVar6 = 1;
  pRVar4 = param_1->md->player;
  pRVar1 = pRVar4->world;
  if (1 < pRVar1->player_num) {
    piVar5 = param_1->dislikeTable;
    do {
      piVar5 = piVar5 + 1;
      if (((iVar6 != pRVar4->id) && (pRVar1->players[iVar6]->game_status != '\x02')) &&
         ((param_2 < 1 ||
          ((param_3 != iVar6 || (iVar2 = DiplomacyAIModule::isAlly(param_1,iVar6), iVar2 == 0))))))
{
        lVar3 = RGE_Victory_Conditions::get_victory_points
                          (param_1->md->player->world->players[iVar6]->victory_conditions);
        iVar2 = *piVar5;
        if (1 < param_5) {
          if (param_4 == 1) {
            iVar2 = iVar2 + lVar3 / param_5;
          }
          else {
            iVar2 = iVar2 - lVar3 / param_5;
          }
        }
        if (iStack_8 < iVar2) {
          iStack_8 = iVar2;
          iStack_4 = iVar6;
        }
      }
      iVar6 = iVar6 + 1;
      pRVar4 = param_1->md->player;
      pRVar1 = pRVar4->world;
    } while (iVar6 < pRVar1->player_num);
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_0040c5ae
// Address: 0040c5ae
int __thiscall FUN_0040c5ae(DiplomacyAIModule *param_1,int param_2,int param_3)
{
  RGE_Game_World *pRVar1;
  int iVar2;
  RGE_Player *pRVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iStack_8;
  
  iVar5 = 1;
  iVar4 = -1;
  iStack_8 = -1;
  pRVar3 = param_1->md->player;
  pRVar1 = pRVar3->world;
  if (1 < pRVar1->player_num) {
    piVar6 = param_1->likeTable;
    do {
      piVar6 = piVar6 + 1;
      if ((((iVar5 != pRVar3->id) &&
           (*(char *)(*(int *)((int)pRVar1->players + (-0x11c - (int)param_1) + (int)piVar6) + 0x80)
            != '\x02')) &&
          ((param_2 < 1 ||
           ((param_3 != iVar5 || (iVar2 = DiplomacyAIModule::isEnemy(param_1,iVar5), iVar2 == 0)))))
          ) && (iVar4 < *piVar6)) {
        iVar4 = *piVar6;
        iStack_8 = iVar5;
      }
      iVar5 = iVar5 + 1;
      pRVar3 = param_1->md->player;
      pRVar1 = pRVar3->world;
    } while (iVar5 < pRVar1->player_num);
  }
  return iStack_8;
}

// --------------------------------------------------

// Function: FUN_0040c659
// Address: 0040c659
undefined4 __thiscall FUN_0040c659(int param_1,int param_2)
{
  int iVar1;
  
  if ((((0 < param_2) &&
       (iVar1 = *(int *)(*(int *)(param_1 + 0xf0) + 0xf0),
       param_2 <= *(short *)(*(int *)(iVar1 + 0x3c) + 0x3c))) &&
      (param_2 != *(short *)(iVar1 + 0x4a))) &&
     (*(char *)(*(int *)(iVar1 + 0x84) + param_2) == '\x03')) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040c728
// Address: 0040c728
undefined4 __thiscall FUN_0040c728(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (0 < param_2) {
    iVar3 = *(int *)(*(int *)(param_1 + 0xf0) + 0xf0);
    iVar1 = *(int *)(iVar3 + 0x3c);
    if ((param_2 < *(short *)(iVar1 + 0x3c)) &&
       (piVar2 = *(int **)(*(int *)(iVar1 + 0x40) + param_2 * 4), piVar2 != (int *)0x0)) {
      iVar3 = (**(code **)(*piVar2 + 0x1c))((int)*(short *)(iVar3 + 0x4a));
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040c777
// Address: 0040c777
void __thiscall FUN_0040c777(int param_1,int param_2,undefined4 param_3)
{
  int *piVar1;
  
  if (((0 < param_2) &&
      (piVar1 = *(int **)(*(int *)(param_1 + 0xf0) + 0xf0), param_2 < *(short *)(piVar1[0xf] + 0x3c)
      )) && (*(char *)(param_1 + 0x144 + param_2) != '\0')) {
    (**(code **)(*piVar1 + 0x28))(param_2,param_3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040c7be
// Address: 0040c7be
// [HELPER] s_Aggressive: "Aggressive"
// [HELPER] s_Compassionate: "Compassionate"
// [HELPER] s_Defensive: "Defensive"
// [HELPER] s_Emotional_AI: "Emotional AI"
// [HELPER] s_Friendly: "Friendly"
// [HELPER] s_Passive: "Passive"
// [HELPER] s_Vengeful: "Vengeful"
AIModule * __thiscall FUN_0040c7be(AIModule *param_1,void *param_2,int param_3)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  AIModule *pAVar7;
  int *piVar8;
  char *pcVar9;
  
  AIModule::AIModule(param_1,s_Emotional_AI,0x3ec,param_3,param_2);
  pAVar7 = param_1 + 1;
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&EmotionalAIModule::_vftable_;
  for (iVar2 = 6; pAVar7 = (AIModule *)&pAVar7->idValue, iVar2 != 0; iVar2 = iVar2 + -1) {
    ((AIModuleID *)pAVar7)->_padding_ = 0x31;
  }
  uVar3 = 0xffffffff;
  pcVar6 = &s_Aggressive;
  do {
    pcVar9 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar9 + -uVar3;
  pcVar9 = param_1[1].idValue.name + 0x10;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar6 = &s_Compassionate;
  do {
    pcVar9 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar9 + -uVar3;
  pcVar9 = param_1[1].idValue.name + 0x2e;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar6 = &s_Defensive;
  do {
    pcVar9 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar9 + -uVar3;
  pcVar9 = param_1[1].playerNameValue + 8;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar6 = &s_Friendly;
  do {
    pcVar9 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar9 + -uVar3;
  pcVar9 = param_1[1].playerNameValue + 0x26;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar6 = &s_Passive;
  do {
    pcVar9 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  piVar5 = (int *)(pcVar9 + -uVar3);
  piVar8 = &param_1[1].pausedValue;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *piVar8 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar8 = piVar8 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)piVar8 = (char)*piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
    piVar8 = (int *)((int)piVar8 + 1);
  }
  uVar3 = 0xffffffff;
  pcVar6 = &s_Vengeful;
  do {
    pcVar9 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar9 + -uVar3;
  pcVar9 = param_1[1].historyLogFilename + 0xe;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040c8fa
// Address: 0040c8fa
EmotionalAIModule * __thiscall FUN_0040c8fa(EmotionalAIModule *param_1,byte param_2)
{
  EmotionalAIModule::~EmotionalAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040c91e
// Address: 0040c91e
// [HELPER] s_Aggressive: "Aggressive"
// [HELPER] s_Compassionate: "Compassionate"
// [HELPER] s_Defensive: "Defensive"
// [HELPER] s_Emotional_AI: "Emotional AI"
// [HELPER] s_Friendly: "Friendly"
// [HELPER] s_Passive: "Passive"
// [HELPER] s_Vengeful: "Vengeful"
AIModule * __thiscall FUN_0040c91e(AIModule *param_1,int param_2,int param_3)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  AIModule *pAVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c618;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  AIModule::AIModule(param_1,s_Emotional_AI,0x3ec,param_2,(void *)0x0);
  uStack_4 = 0;
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&EmotionalAIModule::_vftable_;
  pAVar4 = param_1 + 1;
  iVar7 = 6;
  do {
    pAVar4 = (AIModule *)&pAVar4->idValue;
    rge_read(param_3,pAVar4,4);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar2 = 0xffffffff;
  pcVar6 = &s_Aggressive;
  do {
    pcVar9 = pcVar6;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar6 = pcVar9 + -uVar2;
  pcVar9 = param_1[1].idValue.name + 0x10;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar2 = 0xffffffff;
  pcVar6 = &s_Compassionate;
  do {
    pcVar9 = pcVar6;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar6 = pcVar9 + -uVar2;
  pcVar9 = param_1[1].idValue.name + 0x2e;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar2 = 0xffffffff;
  pcVar6 = &s_Defensive;
  do {
    pcVar9 = pcVar6;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar6 = pcVar9 + -uVar2;
  pcVar9 = param_1[1].playerNameValue + 8;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar2 = 0xffffffff;
  pcVar6 = &s_Friendly;
  do {
    pcVar9 = pcVar6;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar6 = pcVar9 + -uVar2;
  pcVar9 = param_1[1].playerNameValue + 0x26;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar2 = 0xffffffff;
  pcVar6 = &s_Passive;
  do {
    pcVar9 = pcVar6;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  piVar5 = (int *)(pcVar9 + -uVar2);
  piVar8 = &param_1[1].pausedValue;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *piVar8 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar8 = piVar8 + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(char *)piVar8 = (char)*piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
    piVar8 = (int *)((int)piVar8 + 1);
  }
  uVar2 = 0xffffffff;
  pcVar6 = &s_Vengeful;
  do {
    pcVar9 = pcVar6;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar6 = pcVar9 + -uVar2;
  pcVar9 = param_1[1].historyLogFilename + 0xe;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040ca8f
// Address: 0040ca8f
void __fastcall FUN_0040ca8f(AIModule *param_1)
{
  param_1->_padding_ = (int)&EmotionalAIModule::_vftable_;
  AIModule::~AIModule(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0040ca9b
// Address: 0040ca9b
void __thiscall FUN_0040ca9b(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xf0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040caad
// Address: 0040caad
undefined4 __thiscall FUN_0040caad(int param_1,int param_2)
{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = (void *)(param_1 + 0xf4);
  iVar2 = 6;
  do {
    rge_write(param_2,pvVar1,4);
    pvVar1 = (void *)((int)pvVar1 + 4);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040cadf
// Address: 0040cadf
int __thiscall FUN_0040cadf(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 6)) {
    return param_1 + 0x10c + param_2 * 0x1e;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040cb02
// Address: 0040cb02
undefined4 __thiscall FUN_0040cb02(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 6)) {
    return *(undefined4 *)(param_1 + 0xf4 + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0040cb2d
// Address: 0040cb2d
void __thiscall FUN_0040cb2d(int param_1,int param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 < 6)) {
    *(undefined4 *)(param_1 + 0xf4 + param_2 * 4) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040cb4b
// Address: 0040cb4b
void __thiscall FUN_0040cb4b(int param_1,int param_2,int param_3)
{
  if ((-1 < param_2) && (param_2 < 6)) {
    *(int *)(param_1 + 0xf4 + param_2 * 4) = *(int *)(param_1 + 0xf4 + param_2 * 4) + param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040cb76
// Address: 0040cb76
void __thiscall FUN_0040cb76(int param_1,int param_2,int param_3)
{
  if ((-1 < param_2) && (param_2 < 6)) {
    *(int *)(param_1 + 0xf4 + param_2 * 4) = *(int *)(param_1 + 0xf4 + param_2 * 4) - param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040cba6
// Address: 0040cba6
int __fastcall FUN_0040cba6(int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0xf4);
  iVar1 = 0;
  iVar2 = 1;
  piVar3 = (int *)(param_1 + 0xf8);
  do {
    if (iVar4 < *piVar3) {
      iVar1 = iVar2;
      iVar4 = *piVar3;
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 < 6);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0040cbdb
// Address: 0040cbdb
void __thiscall FUN_0040cbdb(int param_1,undefined4 param_2)
{
  switch(param_2) {
  case 0:
    *(undefined4 *)(param_1 + 0xf4) = 100;
    *(undefined4 *)(param_1 + 0x104) = 10;
    *(undefined4 *)(param_1 + 0xf8) = 10;
    *(undefined4 *)(param_1 + 0x100) = 10;
    *(undefined4 *)(param_1 + 0xfc) = 0;
    *(undefined4 *)(param_1 + 0x108) = 0x46;
    return;
  case 1:
    *(undefined4 *)(param_1 + 0xf4) = 10;
    *(undefined4 *)(param_1 + 0x104) = 0x32;
    *(undefined4 *)(param_1 + 0xf8) = 100;
    *(undefined4 *)(param_1 + 0x100) = 0x50;
    *(undefined4 *)(param_1 + 0xfc) = 0x32;
    *(undefined4 *)(param_1 + 0x108) = 0;
    return;
  case 2:
    *(undefined4 *)(param_1 + 0xf4) = 0x14;
    *(undefined4 *)(param_1 + 0x104) = 0x3c;
    *(undefined4 *)(param_1 + 0xf8) = 0x32;
    *(undefined4 *)(param_1 + 0x100) = 0x32;
    *(undefined4 *)(param_1 + 0xfc) = 100;
    *(undefined4 *)(param_1 + 0x108) = 10;
    return;
  case 3:
    *(undefined4 *)(param_1 + 0xf4) = 10;
    *(undefined4 *)(param_1 + 0x104) = 0x32;
    *(undefined4 *)(param_1 + 0xf8) = 0x46;
    *(undefined4 *)(param_1 + 0x100) = 100;
    *(undefined4 *)(param_1 + 0xfc) = 0x32;
    *(undefined4 *)(param_1 + 0x108) = 0x14;
    return;
  case 4:
    *(undefined4 *)(param_1 + 0xf4) = 0x14;
    *(undefined4 *)(param_1 + 0x104) = 100;
    *(undefined4 *)(param_1 + 0xf8) = 0x46;
    *(undefined4 *)(param_1 + 0x100) = 0x32;
    *(undefined4 *)(param_1 + 0xfc) = 0x3c;
    *(undefined4 *)(param_1 + 0x108) = 0;
    return;
  case 5:
    *(undefined4 *)(param_1 + 0xf4) = 0x5a;
    *(undefined4 *)(param_1 + 0x104) = 10;
    *(undefined4 *)(param_1 + 0xf8) = 0;
    *(undefined4 *)(param_1 + 0x100) = 0x1e;
    *(undefined4 *)(param_1 + 0xfc) = 0x32;
    *(undefined4 *)(param_1 + 0x108) = 100;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040cd5e
// Address: 0040cd5e
void FUN_0040cd5e(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0040cd86
// Address: 0040cd86
// [HELPER] s_InfAI: "InfAI"
AIModule * __thiscall FUN_0040cd86(AIModule *param_1,void *param_2,int param_3)
{
  AIModule::AIModule(param_1,s_InfAI,0x3ed,param_3,param_2);
  param_1->_padding_ = (int)&InformationAIModule::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040cdba
// Address: 0040cdba
InformationAIModule * __thiscall FUN_0040cdba(InformationAIModule *param_1,byte param_2)
{
  InformationAIModule::~InformationAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040cdde
// Address: 0040cdde
void __fastcall FUN_0040cdde(AIModule *param_1)
{
  param_1->_padding_ = (int)&InformationAIModule::_vftable_;
  AIModule::~AIModule(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0040cdeb
// Address: 0040cdeb
// [HELPER] s_Main_Decision_AI: "Main Decision AI"
AIModule * __thiscall FUN_0040cdeb(AIModule *param_1,void *param_2,int param_3,int param_4)
{
  AIModule *pAVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c638;
  *unaff_FS_OFFSET = &uStack_c;
  AIModule::AIModule(param_1,s_Main_Decision_AI,1000,param_3,param_2);
  param_1[1]._padding_ = param_4;
  param_1[1].idValue._padding_ = 0;
  param_1[1].idValue.id = 0;
  param_1[1].idValue.name[0] = '\0';
  param_1[1].idValue.name[1] = '\0';
  param_1[1].idValue.name[2] = '\0';
  param_1[1].idValue.name[3] = '\0';
  pAVar1 = param_1 + 1;
  (pAVar1->idValue).name[4] = '\0';
  (pAVar1->idValue).name[5] = '\0';
  (pAVar1->idValue).name[6] = '\0';
  (pAVar1->idValue).name[7] = '\0';
  param_1->_padding_ = (int)&MainDecisionAIModule::_vftable_;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040ce61
// Address: 0040ce61
MainDecisionAIModule * __thiscall FUN_0040ce61(MainDecisionAIModule *param_1,byte param_2)
{
  MainDecisionAIModule::~MainDecisionAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040ce8e
// Address: 0040ce8e
// [HELPER] s_Main_Decision_AI: "Main Decision AI"
AIModule * __thiscall FUN_0040ce8e(AIModule *param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  AIModule *pAVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 *unaff_FS_OFFSET;
  int iStack_14;
  AIModule *pAStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c666;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pAStack_10 = param_1;
  AIModule::AIModule(param_1,s_Main_Decision_AI,1000,param_2,(void *)0x0);
  param_1[1]._padding_ = param_3;
  param_1[1].idValue._padding_ = 0;
  param_1[1].idValue.id = 0;
  param_1[1].idValue.name[0] = '\0';
  param_1[1].idValue.name[1] = '\0';
  param_1[1].idValue.name[2] = '\0';
  param_1[1].idValue.name[3] = '\0';
  pAVar2 = param_1 + 1;
  (pAVar2->idValue).name[4] = '\0';
  (pAVar2->idValue).name[5] = '\0';
  (pAVar2->idValue).name[6] = '\0';
  (pAVar2->idValue).name[7] = '\0';
  uStack_4 = 1;
  param_1->_padding_ = (int)&MainDecisionAIModule::_vftable_;
  rge_read(param_4,&iStack_14,4);
  param_2 = 0;
  if (0 < iStack_14) {
    do {
      rge_read(param_4,&param_3,4);
      iVar3 = param_3;
      iVar1 = param_1[1].idValue.id;
      iVar4 = 0;
      if (0 < iVar1) {
        do {
          if (*(int *)(param_1[1].idValue.name + 4) <= iVar4) break;
          if (*(int *)(param_1[1].idValue._padding_ + iVar4 * 4) == param_3) goto LAB_0040cfea;
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar1);
      }
      if (*(int *)(param_1[1].idValue.name + 4) + -1 < iVar1) {
        iVar1 = iVar1 + 1;
        pvVar5 = operator_new(iVar1 * 4);
        if (pvVar5 != (void *)0x0) {
          iVar4 = 0;
          if (0 < *(int *)(param_1[1].idValue.name + 4)) {
            do {
              if (iVar1 <= iVar4) break;
              iVar4 = iVar4 + 1;
              *(undefined4 *)((int)pvVar5 + iVar4 * 4 + -4) =
                   *(undefined4 *)(param_1[1].idValue._padding_ + -4 + iVar4 * 4);
            } while (iVar4 < *(int *)(param_1[1].idValue.name + 4));
          }
          operator_delete((void *)param_1[1].idValue._padding_);
          param_1[1].idValue._padding_ = (int)pvVar5;
          *(int *)(param_1[1].idValue.name + 4) = iVar1;
        }
      }
      *(int *)(param_1[1].idValue._padding_ + param_1[1].idValue.id * 4) = iVar3;
      param_1[1].idValue.id = param_1[1].idValue.id + 1;
LAB_0040cfea:
      param_2 = param_2 + 1;
    } while (param_2 < iStack_14);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040d016
// Address: 0040d016
void __fastcall FUN_0040d016(AIModule *param_1)
{
  void *pvVar1;
  AIModule *pAVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055c678;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&MainDecisionAIModule::_vftable_;
  pvVar1 = (void *)param_1[1].idValue._padding_;
  uStack_4 = 0;
  if (pvVar1 != (void *)0x0) {
    operator_delete(pvVar1);
    param_1[1].idValue._padding_ = 0;
  }
  param_1[1].idValue.id = 0;
  param_1[1].idValue.name[0] = '\0';
  param_1[1].idValue.name[1] = '\0';
  param_1[1].idValue.name[2] = '\0';
  param_1[1].idValue.name[3] = '\0';
  pAVar2 = param_1 + 1;
  (pAVar2->idValue).name[4] = '\0';
  (pAVar2->idValue).name[5] = '\0';
  (pAVar2->idValue).name[6] = '\0';
  (pAVar2->idValue).name[7] = '\0';
  uStack_4 = 0xffffffff;
  AIModule::~AIModule(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0040d093
// Address: 0040d093
undefined4 __thiscall FUN_0040d093(int param_1,int param_2)
{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_4;
  
  uStack_4 = *(undefined4 *)(param_1 + 0xf8);
  rge_write(param_2,&uStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0xf8)) {
    do {
      if (*(int *)(param_1 + 0x100) + -1 < iVar3) {
        pvVar1 = operator_new(iVar3 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x100)) {
            do {
              if (iVar3 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0xf4) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0x100));
          }
          operator_delete(*(void **)(param_1 + 0xf4));
          *(void **)(param_1 + 0xf4) = pvVar1;
          *(int *)(param_1 + 0x100) = iVar3 + 1;
        }
      }
      uStack_4 = *(undefined4 *)(*(int *)(param_1 + 0xf4) + iVar3 * 4);
      rge_write(param_2,&uStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0xf8));
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040d17a
// Address: 0040d17a
int __thiscall FUN_0040d17a(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  if (param_2 == 0) {
    return param_2;
  }
  iVar1 = *(int *)(param_1 + 0xf8);
  iVar2 = *(int *)(param_2 + 4);
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      if (*(int *)(param_1 + 0x100) <= iVar3) break;
      if (*(int *)(*(int *)(param_1 + 0xf4) + iVar3 * 4) == iVar2) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  if (*(int *)(param_1 + 0x100) + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    pvVar4 = operator_new(iVar1 * 4);
    if (pvVar4 != (void *)0x0) {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x100)) {
        do {
          if (iVar1 <= iVar3) break;
          iVar3 = iVar3 + 1;
          *(undefined4 *)((int)pvVar4 + iVar3 * 4 + -4) =
               *(undefined4 *)(*(int *)(param_1 + 0xf4) + -4 + iVar3 * 4);
        } while (iVar3 < *(int *)(param_1 + 0x100));
      }
      operator_delete(*(void **)(param_1 + 0xf4));
      *(void **)(param_1 + 0xf4) = pvVar4;
      *(int *)(param_1 + 0x100) = iVar1;
    }
  }
  *(int *)(*(int *)(param_1 + 0xf4) + *(int *)(param_1 + 0xf8) * 4) = iVar2;
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040d24f
// Address: 0040d24f
undefined4 __thiscall FUN_0040d24f(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 0x100);
  iVar1 = 0;
  if (0 < iVar2) {
    piVar3 = *(int **)(param_1 + 0xf4);
    do {
      if (*piVar3 == param_2) break;
      iVar1 = iVar1 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar1 < iVar2);
  }
  if (iVar2 <= iVar1) {
    return 0;
  }
  if (iVar1 < iVar2 + -1) {
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0xf4) + -4 + iVar1 * 4) =
           *(undefined4 *)(*(int *)(param_1 + 0xf4) + iVar1 * 4);
    } while (iVar1 < *(int *)(param_1 + 0x100) + -1);
  }
  iVar2 = *(int *)(param_1 + 0xf8) + -1;
  *(int *)(param_1 + 0xf8) = iVar2;
  if (iVar2 < 0) {
    *(undefined4 *)(param_1 + 0xf8) = 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040d2c7
// Address: 0040d2c7
int __thiscall FUN_0040d2c7(int param_1,int param_2)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iVar4;
  int iStack_4;
  
  iVar4 = 0;
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0xf8)) {
    do {
      if (*(int *)(param_1 + 0x100) + -1 < iVar4) {
        pvVar1 = operator_new(iVar4 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x100)) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0xf4) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0x100));
          }
          operator_delete(*(void **)(param_1 + 0xf4));
          *(void **)(param_1 + 0xf4) = pvVar1;
          *(int *)(param_1 + 0x100) = iVar4 + 1;
        }
      }
      this = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(param_1 + 0xf0) + 0x3c),
                        *(int *)(*(int *)(param_1 + 0xf4) + iVar4 * 4));
      if ((this != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this), pUVar3 != (UnitAIModule *)0x0)) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentAction(pUVar3);
        if (iVar2 == param_2) {
          iStack_4 = iStack_4 + 1;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0xf8));
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_0040d3ad
// Address: 0040d3ad
int __thiscall FUN_0040d3ad(int param_1,int param_2)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iStack_4;
  
  iVar4 = 0;
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0xf8)) {
    do {
      if (*(int *)(param_1 + 0x100) + -1 < iVar4) {
        pvVar1 = operator_new(iVar4 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x100)) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0xf4) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0x100));
          }
          operator_delete(*(void **)(param_1 + 0xf4));
          *(void **)(param_1 + 0xf4) = pvVar1;
          *(int *)(param_1 + 0x100) = iVar4 + 1;
        }
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(param_1 + 0xf0) + 0x3c),
                          *(int *)(*(int *)(param_1 + 0xf4) + iVar4 * 4));
      if ((pRVar3 != (RGE_Static_Object *)0x0) && (pRVar3->master_obj->object_group == param_2)) {
        iStack_4 = iStack_4 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0xf8));
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_0040d479
// Address: 0040d479
int __thiscall FUN_0040d479(int param_1,int param_2,int param_3)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iVar4;
  int iStack_4;
  
  iVar4 = 0;
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0xf8)) {
    do {
      if (*(int *)(param_1 + 0x100) + -1 < iVar4) {
        pvVar1 = operator_new(iVar4 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x100)) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0xf4) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0x100));
          }
          operator_delete(*(void **)(param_1 + 0xf4));
          *(void **)(param_1 + 0xf4) = pvVar1;
          *(int *)(param_1 + 0x100) = iVar4 + 1;
        }
      }
      this = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(param_1 + 0xf0) + 0x3c),
                        *(int *)(*(int *)(param_1 + 0xf4) + iVar4 * 4));
      if ((this != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this), pUVar3 != (UnitAIModule *)0x0)) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentAction(pUVar3);
        if (iVar2 == param_2) {
          pUVar3 = RGE_Static_Object::unitAI(this);
          iVar2 = UnitAIModule::currentTarget(pUVar3);
          if (iVar2 == param_3) {
            iStack_4 = iStack_4 + 1;
          }
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0xf8));
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_0040d571
// Address: 0040d571
int __thiscall FUN_0040d571(int param_1,int param_2)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iVar4;
  int iStack_4;
  
  iVar4 = 0;
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0xf8)) {
    do {
      if (*(int *)(param_1 + 0x100) + -1 < iVar4) {
        pvVar1 = operator_new(iVar4 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x100)) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0xf4) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0x100));
          }
          operator_delete(*(void **)(param_1 + 0xf4));
          *(void **)(param_1 + 0xf4) = pvVar1;
          *(int *)(param_1 + 0x100) = iVar4 + 1;
        }
      }
      this = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(param_1 + 0xf0) + 0x3c),
                        *(int *)(*(int *)(param_1 + 0xf4) + iVar4 * 4));
      if ((this != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this), pUVar3 != (UnitAIModule *)0x0)) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentTargetType(pUVar3);
        if (iVar2 == param_2) {
          iStack_4 = iStack_4 + 1;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0xf8));
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_0040d65d
// Address: 0040d65d
int __thiscall FUN_0040d65d(int param_1,int param_2,int param_3)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iVar4;
  int iStack_4;
  
  iVar4 = 0;
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0xf8)) {
    do {
      if (*(int *)(param_1 + 0x100) + -1 < iVar4) {
        pvVar1 = operator_new(iVar4 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x100)) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0xf4) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0x100));
          }
          operator_delete(*(void **)(param_1 + 0xf4));
          *(void **)(param_1 + 0xf4) = pvVar1;
          *(int *)(param_1 + 0x100) = iVar4 + 1;
        }
      }
      this = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(param_1 + 0xf0) + 0x3c),
                        *(int *)(*(int *)(param_1 + 0xf4) + iVar4 * 4));
      if ((this != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this), pUVar3 != (UnitAIModule *)0x0)) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentAction(pUVar3);
        if (iVar2 == param_2) {
          pUVar3 = RGE_Static_Object::unitAI(this);
          iVar2 = UnitAIModule::currentTargetType(pUVar3);
          if (iVar2 == param_3) {
            iStack_4 = iStack_4 + 1;
          }
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0xf8));
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_0040d751
// Address: 0040d751
void __thiscall FUN_0040d751(int param_1,int param_2)
{
  RGE_Game_World::object(*(RGE_Game_World **)(*(int *)(param_1 + 0xf0) + 0x3c),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0040d776
// Address: 0040d776
RGE_Static_Object * __thiscall
FUN_0040d776(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,undefined4 param_9,uint param_10,int param_11)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iStack_4;
  
  iStack_4 = 0;
  if (param_1[0x3e] < 1) {
    return (RGE_Static_Object *)0x0;
  }
  do {
    if (param_1[0x40] + -1 < iStack_4) {
      pvVar1 = operator_new(iStack_4 * 4 + 4);
      if (pvVar1 != (void *)0x0) {
        iVar2 = 0;
        if (0 < param_1[0x40]) {
          do {
            if (iStack_4 + 1 <= iVar2) break;
            iVar2 = iVar2 + 1;
            *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                 *(undefined4 *)(param_1[0x3d] + -4 + iVar2 * 4);
          } while (iVar2 < param_1[0x40]);
        }
        operator_delete((void *)param_1[0x3d]);
        param_1[0x3d] = (int)pvVar1;
        param_1[0x40] = iStack_4 + 1;
      }
    }
    this = RGE_Game_World::object
                     (*(RGE_Game_World **)(param_1[0x3c] + 0x3c),
                      *(int *)(param_1[0x3d] + iStack_4 * 4));
    if ((((this != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this), pUVar3 != (UnitAIModule *)0x0)) &&
        ((param_2 == -1 || (this->id == param_2)))) &&
       (((param_3 == -1 || (this->master_obj->id == param_3)) &&
        ((param_4 == -1 || (this->master_obj->object_group == param_4)))))) {
      if (param_5 != -1) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentAction(pUVar3);
        if (iVar2 != param_5) goto LAB_0040d98d;
      }
      if (param_6 != -1) {
        if (param_1[0x40] + -1 < iStack_4) {
          pvVar1 = operator_new(iStack_4 * 4 + 4);
          if (pvVar1 != (void *)0x0) {
            iVar2 = 0;
            if (0 < param_1[0x40]) {
              do {
                if (iStack_4 + 1 <= iVar2) break;
                iVar2 = iVar2 + 1;
                *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                     *(undefined4 *)(param_1[0x3d] + -4 + iVar2 * 4);
              } while (iVar2 < param_1[0x40]);
            }
            operator_delete((void *)param_1[0x3d]);
            param_1[0x3d] = (int)pvVar1;
            param_1[0x40] = iStack_4 + 1;
          }
        }
        iVar2 = (**(code **)(*param_1 + 0x4c))
                          (*(undefined4 *)(param_1[0x3d] + iStack_4 * 4),param_6);
        if (iVar2 == 0) goto LAB_0040d98d;
      }
      if (param_7 != -1) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentTarget(pUVar3);
        if (iVar2 != param_7) goto LAB_0040d98d;
      }
      if (param_8 != -1) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentTargetType(pUVar3);
        if (iVar2 != param_8) goto LAB_0040d98d;
      }
      if (((param_10 == 0xffffffff) || (this->object_state == param_10)) &&
         ((param_11 == -1 || (this->attribute_amount_held <= (float)param_11)))) {
        return this;
      }
    }
LAB_0040d98d:
    iStack_4 = iStack_4 + 1;
    if (param_1[0x3e] <= iStack_4) {
      return (RGE_Static_Object *)0x0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0040d9c2
// Address: 0040d9c2
RGE_Static_Object * __thiscall
FUN_0040d9c2(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,uint param_7)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)(param_1 + 0xf8) < 1) {
    return (RGE_Static_Object *)0x0;
  }
  do {
    if (*(int *)(param_1 + 0x100) + -1 < iVar4) {
      pvVar1 = operator_new(iVar4 * 4 + 4);
      if (pvVar1 != (void *)0x0) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0x100)) {
          do {
            if (iVar4 + 1 <= iVar2) break;
            iVar2 = iVar2 + 1;
            *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0xf4) + -4 + iVar2 * 4);
          } while (iVar2 < *(int *)(param_1 + 0x100));
        }
        operator_delete(*(void **)(param_1 + 0xf4));
        *(void **)(param_1 + 0xf4) = pvVar1;
        *(int *)(param_1 + 0x100) = iVar4 + 1;
      }
    }
    this = RGE_Game_World::object
                     (*(RGE_Game_World **)(*(int *)(param_1 + 0xf0) + 0x3c),
                      *(int *)(*(int *)(param_1 + 0xf4) + iVar4 * 4));
    if (this != (RGE_Static_Object *)0x0) {
      pUVar3 = RGE_Static_Object::unitAI(this);
      if ((((pUVar3 != (UnitAIModule *)0x0) && ((param_2 == -1 || (this->id == param_2)))) &&
          ((param_3 == -1 || (this->master_obj->id == param_3)))) &&
         ((param_4 == -1 || (this->master_obj->object_group == param_4)))) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentAction(pUVar3);
        if (iVar2 != param_5) {
          pUVar3 = RGE_Static_Object::unitAI(this);
          iVar2 = UnitAIModule::currentAction(pUVar3);
          if ((iVar2 != param_6) && ((param_7 == 0xffffffff || (this->object_state == param_7)))) {
            return this;
          }
        }
      }
    }
    iVar4 = iVar4 + 1;
    if (*(int *)(param_1 + 0xf8) <= iVar4) {
      return (RGE_Static_Object *)0x0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0040db11
// Address: 0040db11
// [HELPER] s_ERROR____d_is_an_unrecognized_ac: "ERROR!  %d is an unrecognized action id."
undefined4 __thiscall FUN_0040db11(AIModule *param_1,undefined4 param_2)
{
  AIModule::logCommonHistory(param_1,(char *)param_1,s_ERROR____d_is_an_unrecognized_ac,param_2);
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0040db39
// Address: 0040db39
undefined4 FUN_0040db39(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040db45
// Address: 0040db45
int __fastcall FUN_0040db45(int param_1)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iVar4;
  int iStack_4;
  
  iVar4 = 0;
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0xf8)) {
    do {
      if (*(int *)(param_1 + 0x100) + -1 < iVar4) {
        pvVar1 = operator_new(iVar4 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x100)) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0xf4) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0x100));
          }
          operator_delete(*(void **)(param_1 + 0xf4));
          *(void **)(param_1 + 0xf4) = pvVar1;
          *(int *)(param_1 + 0x100) = iVar4 + 1;
        }
      }
      this = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(param_1 + 0xf0) + 0x3c),
                        *(int *)(*(int *)(param_1 + 0xf4) + iVar4 * 4));
      if ((this != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this), pUVar3 != (UnitAIModule *)0x0)) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentAction(pUVar3);
        if (iVar2 == -1) {
          iStack_4 = iStack_4 + 1;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0xf8));
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_0040dc2a
// Address: 0040dc2a
RGE_Static_Object * __thiscall FUN_0040dc2a(int param_1,int param_2,int param_3)
{
  short sVar1;
  void *pvVar2;
  int iVar3;
  RGE_Static_Object *this;
  UnitAIModule *pUVar4;
  int iVar5;
  int iStack_c;
  RGE_Static_Object *pRStack_8;
  
  iVar5 = 0;
  pRStack_8 = (RGE_Static_Object *)0x0;
  iStack_c = 0;
  if (0 < *(int *)(param_1 + 0xf8)) {
    do {
      if (*(int *)(param_1 + 0x100) + -1 < iVar5) {
        pvVar2 = operator_new(iVar5 * 4 + 4);
        if (pvVar2 != (void *)0x0) {
          iVar3 = 0;
          if (0 < *(int *)(param_1 + 0x100)) {
            do {
              if (iVar5 + 1 <= iVar3) break;
              iVar3 = iVar3 + 1;
              *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0xf4) + -4 + iVar3 * 4);
            } while (iVar3 < *(int *)(param_1 + 0x100));
          }
          operator_delete(*(void **)(param_1 + 0xf4));
          *(void **)(param_1 + 0xf4) = pvVar2;
          *(int *)(param_1 + 0x100) = iVar5 + 1;
        }
      }
      this = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(param_1 + 0xf0) + 0x3c),
                        *(int *)(*(int *)(param_1 + 0xf4) + iVar5 * 4));
      if (((((this != (RGE_Static_Object *)0x0) &&
            (pUVar4 = RGE_Static_Object::unitAI(this), pUVar4 != (UnitAIModule *)0x0)) &&
           (this->object_state != '\0')) &&
          ((this->master_obj->object_group == param_2 &&
           (this->hp < (float)(int)this->master_obj->hp)))) &&
         ((iVar3 = (**(code **)(this->_padding_ + 0x90))(), iVar3 == 1 &&
          ((param_3 == -1 || (param_3 == this->master_obj->id)))))) {
        sVar1 = this->master_obj->hp;
        iVar3 = __ftol();
        iVar3 = (iVar3 * 100) / (int)sVar1;
        if (iStack_c < iVar3) {
          iStack_c = iVar3;
          pRStack_8 = this;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_1 + 0xf8));
  }
  return pRStack_8;
}

// --------------------------------------------------

// Function: FUN_0040dd87
// Address: 0040dd87
// [HELPER] s_: ""
undefined4 * __thiscall FUN_0040dd87(undefined4 *param_1,int param_2,undefined4 param_3)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  param_1[1] = param_3;
  *param_1 = &AIModuleID::_vftable_;
  if (param_2 != 0) {
    strncpy(param_1 + 2,param_2,0x3f);
    return param_1;
  }
  uVar2 = 0xffffffff;
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
  pcVar5 = (char *)(param_1 + 2);
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
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040ddec
// Address: 0040ddec
AIModuleID * __thiscall FUN_0040ddec(AIModuleID *param_1,byte param_2)
{
  AIModuleID::~AIModuleID(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040de0e
// Address: 0040de0e
void __fastcall FUN_0040de0e(undefined4 *param_1)
{
  *param_1 = &AIModuleID::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_0040de17
// Address: 0040de17
// [HELPER] s_: ""
void __thiscall FUN_0040de17(int param_1,undefined4 param_2,int param_3)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  *(undefined4 *)(param_1 + 4) = param_2;
  if (param_3 != 0) {
    strncpy(param_1 + 8,param_3,0x3f);
    return;
  }
  uVar2 = 0xffffffff;
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
  pcVar5 = (char *)(param_1 + 8);
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
  return;
}

// --------------------------------------------------

// Function: FUN_0040de6d
// Address: 0040de6d
// [HELPER] s_: ""
// [HELPER] s_Recipient: "Recipient"
// [HELPER] s_Sender: "Sender"
undefined4 * __fastcall FUN_0040de6d(undefined4 *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c69e;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[1] = 0;
  param_1[0x22] = 0;
  AIModuleID::AIModuleID((AIModuleID *)(param_1 + 0x23),s_Sender,0);
  uStack_4 = 0;
  AIModuleID::AIModuleID((AIModuleID *)(param_1 + 0x35),s_Recipient,0);
  uVar2 = 0xffffffff;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  *param_1 = &AIModuleMessage::_vftable_;
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
  pcVar5 = (char *)(param_1 + 2);
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
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040df29
// Address: 0040df29
AIModuleMessage * __thiscall FUN_0040df29(AIModuleMessage *param_1,byte param_2)
{
  AIModuleMessage::~AIModuleMessage(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040df4e
// Address: 0040df4e
// [HELPER] s_: ""
undefined4 * __thiscall
FUN_0040df4e(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c6be;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[0x22] = param_5;
  param_1[1] = param_4;
  AIModuleID::AIModuleID((AIModuleID *)(param_1 + 0x23),s_,param_2);
  uStack_4 = 0;
  AIModuleID::AIModuleID((AIModuleID *)(param_1 + 0x35),s_,param_3);
  param_1[0x47] = param_6;
  param_1[0x48] = param_7;
  param_1[0x49] = param_8;
  param_1[0x4a] = param_9;
  uVar2 = 0xffffffff;
  param_1[0x4b] = param_10;
  *param_1 = &AIModuleMessage::_vftable_;
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
  pcVar5 = (char *)(param_1 + 2);
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
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040e025
// Address: 0040e025
AIModuleMessage * __thiscall FUN_0040e025(AIModuleMessage *param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c6ec;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->id = *(int *)(param_2 + 4);
  param_1->priority = *(int *)(param_2 + 0x88);
  AIModuleID::AIModuleID(&param_1->sender,(char *)(param_2 + 0x94),*(int *)(param_2 + 0x90));
  uStack_4 = 0;
  AIModuleID::AIModuleID(&param_1->recipient,(char *)(param_2 + 0xdc),*(int *)(param_2 + 0xd8));
  param_1->data1 = *(long *)(param_2 + 0x11c);
  param_1->data2 = *(long *)(param_2 + 0x120);
  param_1->data3 = *(long *)(param_2 + 0x124);
  param_1->callbackMessage = *(AIModuleMessage **)(param_2 + 0x128);
  param_1->timeStamp = *(int *)(param_2 + 300);
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  param_1->next = (AIModuleMessage *)0x0;
  param_1->prev = (AIModuleMessage *)0x0;
  param_1->_padding_ = (int)&AIModuleMessage::_vftable_;
  AIModuleMessage::setText(param_1,(char *)(param_2 + 8));
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040e119
// Address: 0040e119
void __fastcall FUN_0040e119(undefined4 *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  pcStack_8 = FUN_0055c71c;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &AIModuleMessage::_vftable_;
  uStack_4 = 1;
  if ((undefined4 *)param_1[0x4a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x4a])(1);
  }
  uStack_4 = uStack_4 & 0xffffff00;
  AIModuleID::~AIModuleID((AIModuleID *)(param_1 + 0x35));
  uStack_4 = 0xffffffff;
  AIModuleID::~AIModuleID((AIModuleID *)(param_1 + 0x23));
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0040e18e
// Address: 0040e18e
// [HELPER] s_: ""
void __thiscall FUN_0040e18e(int param_1,int param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_2 != 0) {
    strncpy(param_1 + 8,param_2,0x7f);
    return;
  }
  uVar2 = 0xffffffff;
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
  pcVar5 = (char *)(param_1 + 8);
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
  return;
}

// --------------------------------------------------

// Function: FUN_0040e1d6
// Address: 0040e1d6
void __thiscall FUN_0040e1d6(int param_1,int param_2,char *param_3)
{
  AIModuleID::setID((AIModuleID *)(param_1 + 0x8c),param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_0040e1f8
// Address: 0040e1f8
void __thiscall FUN_0040e1f8(int param_1,int param_2,char *param_3)
{
  AIModuleID::setID((AIModuleID *)(param_1 + 0xd4),param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_0040e218
// Address: 0040e218
// [HELPER] s_: ""
// [HELPER] s_Unknown: "Unknown"
undefined4 * __fastcall FUN_0040e218(undefined4 *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  AIModuleID::AIModuleID((AIModuleID *)(param_1 + 1),s_,-1);
  uVar2 = 0xffffffff;
  param_1[0x13] = 0xffffffff;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x39] = 5;
  param_1[0x3a] = 0x32;
  param_1[0x3b] = 0;
  *param_1 = &AIModule::_vftable_;
  pcVar4 = &s_Unknown;
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
  pcVar5 = (char *)(param_1 + 0x14);
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
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040e2a4
// Address: 0040e2a4
AIModule * __thiscall FUN_0040e2a4(AIModule *param_1,byte param_2)
{
  AIModule::~AIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040e2ce
// Address: 0040e2ce
// [HELPER] s_Unknown: "Unknown"
undefined4 * __thiscall
FUN_0040e2ce(undefined4 *param_1,char *param_2,int param_3,undefined4 param_4)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  AIModuleID::AIModuleID((AIModuleID *)(param_1 + 1),param_2,param_3);
  uVar2 = 0xffffffff;
  param_1[0x13] = param_4;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x39] = 5;
  param_1[0x3a] = 0x32;
  param_1[0x3b] = 0;
  *param_1 = &AIModule::_vftable_;
  pcVar4 = &s_Unknown;
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
  pcVar5 = (char *)(param_1 + 0x14);
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
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040e359
// Address: 0040e359
void __fastcall FUN_0040e359(undefined4 *param_1)
{
  *param_1 = &AIModule::_vftable_;
  if ((param_1[0x27] != 0) && (commonHistoryLogFile != (_iobuf *)0x0)) {
    fclose(commonHistoryLogFile);
    commonHistoryLogFile = (_iobuf *)0x0;
  }
  AIModuleID::~AIModuleID((AIModuleID *)(param_1 + 1));
  return;
}

// --------------------------------------------------

// Function: FUN_0040e399
// Address: 0040e399
void __thiscall FUN_0040e399(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  param_2[1] = *(undefined4 *)(param_1 + 8);
  puVar2 = (undefined4 *)(param_1 + 0xc);
  puVar3 = param_2 + 2;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *param_2 = &AIModuleID::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_0040e3ce
// Address: 0040e3ce
undefined4 __fastcall FUN_0040e3ce(int param_1)
{
  return *(undefined4 *)(param_1 + 8);
}

// --------------------------------------------------

// Function: FUN_0040e3d4
// Address: 0040e3d4
undefined4 __fastcall FUN_0040e3d4(int param_1)
{
  return *(undefined4 *)(param_1 + 0x4c);
}

// --------------------------------------------------

// Function: FUN_0040e3e4
// Address: 0040e3e4
int __fastcall FUN_0040e3e4(int param_1)
{
  return param_1 + 0x50;
}

// --------------------------------------------------

// Function: FUN_0040e3f4
// Address: 0040e3f4
// [HELPER] s_Unknown: "Unknown"
void __thiscall FUN_0040e3f4(int param_1,undefined4 param_2,int param_3)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  *(undefined4 *)(param_1 + 0x4c) = param_2;
  if (param_3 != 0) {
    strncpy(param_1 + 0x50,param_3,0x3f);
    return;
  }
  uVar2 = 0xffffffff;
  pcVar4 = &s_Unknown;
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
  pcVar5 = (char *)(param_1 + 0x50);
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
  return;
}

// --------------------------------------------------

// Function: FUN_0040e44d
// Address: 0040e44d
void __fastcall FUN_0040e44d(int param_1)
{
  *(undefined4 *)(param_1 + 0x90) = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0040e45b
// Address: 0040e45b
void __fastcall FUN_0040e45b(int param_1)
{
  *(undefined4 *)(param_1 + 0x90) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0040e46b
// Address: 0040e46b
void __fastcall FUN_0040e46b(int param_1)
{
  *(uint *)(param_1 + 0x90) = (uint)(*(int *)(param_1 + 0x90) == 0);
  return;
}

// --------------------------------------------------

// Function: FUN_0040e484
// Address: 0040e484
void __fastcall FUN_0040e484(int param_1)
{
  *(uint *)(param_1 + 0x94) = (uint)(*(int *)(param_1 + 0x94) == 0);
  return;
}

// --------------------------------------------------

// Function: FUN_0040e4a4
// Address: 0040e4a4
void FUN_0040e4a4(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e4b1
// Address: 0040e4b1
undefined4 __fastcall FUN_0040e4b1(int param_1)
{
  return *(undefined4 *)(param_1 + 0x90);
}

// --------------------------------------------------

// Function: FUN_0040e4c7
// Address: 0040e4c7
undefined4 __fastcall FUN_0040e4c7(int param_1)
{
  return *(undefined4 *)(param_1 + 0x94);
}

// --------------------------------------------------

// Function: FUN_0040e4d7
// Address: 0040e4d7
undefined4 __fastcall FUN_0040e4d7(int param_1)
{
  return *(undefined4 *)(param_1 + 0x98);
}

// --------------------------------------------------

// Function: FUN_0040e4e7
// Address: 0040e4e7
void FUN_0040e4e7(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e4f3
// Address: 0040e4f3
void FUN_0040e4f3(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e501
// Address: 0040e501
undefined4 __fastcall FUN_0040e501(int param_1)
{
  return *(undefined4 *)(param_1 + 0x9c);
}

// --------------------------------------------------

// Function: FUN_0040e517
// Address: 0040e517
// [HELPER] s_: ""
// [HELPER] s_Common_AI_History_File_Started__: "Common AI History File Started %s"
// [HELPER] s_c__aoeai_txt: "c:\aoeai.txt"
// [HELPER] s_wa: "wa"
void __thiscall FUN_0040e517(char *param_1,int param_2)
{
  undefined4 uVar1;
  AIModule *this;
  AIModule *this_00;
  
  *(int *)(param_1 + 0x9c) = param_2;
  if ((param_2 != 0) && (commonHistoryLogFile == (_iobuf *)0x0)) {
    commonHistoryLogFile = (_iobuf *)fopen(s_c__aoeai_txt,s_wa);
    time(&param_2);
    uVar1 = localtime(&param_2);
    uVar1 = asctime(uVar1);
    AIModule::logCommonHistory(this,param_1,s_Common_AI_History_File_Started__,uVar1);
    AIModule::logCommonHistory(this_00,param_1,s_);
    return;
  }
  if ((param_2 == 0) && (commonHistoryLogFile != (_iobuf *)0x0)) {
    fclose(commonHistoryLogFile);
    commonHistoryLogFile = (_iobuf *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040e5b5
// Address: 0040e5b5
void FUN_0040e5b5(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e5c1
// Address: 0040e5c1
void FUN_0040e5c1(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e5d3
// Address: 0040e5d3
undefined4 __fastcall FUN_0040e5d3(int param_1)
{
  return *(undefined4 *)(param_1 + 0xe4);
}

// --------------------------------------------------

// Function: FUN_0040e5e7
// Address: 0040e5e7
undefined4 __thiscall FUN_0040e5e7(int param_1,int param_2)
{
  *(int *)(param_1 + 0xe4) = param_2;
  if (param_2 < 1) {
    *(undefined4 *)(param_1 + 0xe4) = 1;
    return 0;
  }
  if (10 < param_2) {
    *(undefined4 *)(param_1 + 0xe4) = 10;
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040e62a
// Address: 0040e62a
undefined4 __fastcall FUN_0040e62a(int param_1)
{
  return *(undefined4 *)(param_1 + 0xe8);
}

// --------------------------------------------------

// Function: FUN_0040e637
// Address: 0040e637
undefined4 __thiscall FUN_0040e637(int param_1,int param_2)
{
  *(int *)(param_1 + 0xe8) = param_2;
  if (param_2 < 1) {
    *(undefined4 *)(param_1 + 0xe8) = 1;
    return 0;
  }
  if (100 < param_2) {
    *(undefined4 *)(param_1 + 0xe8) = 100;
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040e67a
// Address: 0040e67a
void __thiscall FUN_0040e67a(AIModule *param_1,int param_2)
{
  AIModule::setPriority(param_1,param_1->priorityValue + param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0040e695
// Address: 0040e695
void __thiscall FUN_0040e695(AIModule *param_1,int param_2)
{
  AIModule::setPriority(param_1,param_1->priorityValue - param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0040e6b5
// Address: 0040e6b5
undefined4 FUN_0040e6b5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e6c5
// Address: 0040e6c5
void FUN_0040e6c5(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e6d3
// Address: 0040e6d3
undefined4 FUN_0040e6d3(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e6e5
// Address: 0040e6e5
undefined4 FUN_0040e6e5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e6f5
// Address: 0040e6f5
void FUN_0040e6f5(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e703
// Address: 0040e703
undefined4 FUN_0040e703(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e713
// Address: 0040e713
void FUN_0040e713(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e723
// Address: 0040e723
undefined4 FUN_0040e723(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e733
// Address: 0040e733
void FUN_0040e733(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e743
// Address: 0040e743
undefined4 FUN_0040e743(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e753
// Address: 0040e753
void FUN_0040e753(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e763
// Address: 0040e763
undefined4 FUN_0040e763(void)
{
  AIModuleID::~AIModuleID((AIModuleID *)&stack0x00000004);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e77e
// Address: 0040e77e
undefined4 FUN_0040e77e(void)
{
  AIModuleID::~AIModuleID((AIModuleID *)&stack0x00000004);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e78e
// Address: 0040e78e
undefined4 FUN_0040e78e(void)
{
  AIModuleID::~AIModuleID((AIModuleID *)&stack0x00000004);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e79e
// Address: 0040e79e
undefined4 FUN_0040e79e(void)
{
  AIModuleID::~AIModuleID((AIModuleID *)&stack0x00000004);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e7ae
// Address: 0040e7ae
undefined4 FUN_0040e7ae(void)
{
  AIModuleID::~AIModuleID((AIModuleID *)&stack0x00000004);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e7be
// Address: 0040e7be
undefined4 FUN_0040e7be(void)
{
  AIModuleID::~AIModuleID((AIModuleID *)&stack0x00000004);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e7ce
// Address: 0040e7ce
undefined4 FUN_0040e7ce(void)
{
  AIModuleID::~AIModuleID((AIModuleID *)&stack0x00000004);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e7de
// Address: 0040e7de
undefined4 FUN_0040e7de(void)
{
  AIModuleID::~AIModuleID((AIModuleID *)&stack0x00000004);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e7ee
// Address: 0040e7ee
void FUN_0040e7ee(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e7f1
// Address: 0040e7f1
void FUN_0040e7f1(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e801
// Address: 0040e801
undefined4 FUN_0040e801(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e815
// Address: 0040e815
void FUN_0040e815(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e821
// Address: 0040e821
// [HELPER] s_P__d_: "P#%d\n"
// [HELPER] s_P__d__s___s_: "P#%d %s: %s\n"
void FUN_0040e821(int param_1,undefined4 param_2)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char acStack_400 [1024];
  
  if (((specificAIPlayerToLog == -1) || (specificAIPlayerToLog == *(int *)(param_1 + 0x4c))) &&
     (commonHistoryLogFile != (_iobuf *)0x0)) {
    vsprintf(acStack_400,param_2,&stack0x0000000c);
    iVar2 = -1;
    pcVar3 = acStack_400;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (iVar2 == -2) {
      fprintf(commonHistoryLogFile,s_P__d_,*(undefined4 *)(param_1 + 0x4c));
    }
    else {
      fprintf(commonHistoryLogFile,s_P__d__s___s_,*(undefined4 *)(param_1 + 0x4c),param_1 + 0xc,
              acStack_400);
    }
    fflush(commonHistoryLogFile);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040e8d5
// Address: 0040e8d5
void FUN_0040e8d5(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0040e8e1
// Address: 0040e8e1
undefined4 __fastcall FUN_0040e8e1(int param_1)
{
  return *(undefined4 *)(param_1 + 0xec);
}

// --------------------------------------------------

// Function: FUN_0040e8f7
// Address: 0040e8f7
void __fastcall FUN_0040e8f7(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xec) + 1;
  *(int *)(param_1 + 0xec) = iVar1;
  if (iVar1 == 0x7fffffff) {
    *(undefined4 *)(param_1 + 0xec) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040e91f
// Address: 0040e91f
undefined4 FUN_0040e91f(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040e925
// Address: 0040e925
void __fastcall FUN_0040e925(undefined1 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0040e943
// Address: 0040e943
void __thiscall
FUN_0040e943(undefined1 *param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)
{
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined4 *)(param_1 + 4) = param_4;
  *(undefined4 *)(param_1 + 8) = param_5;
  *(undefined4 *)(param_1 + 0xc) = param_6;
  return;
}

// --------------------------------------------------

// Function: FUN_0040e977
// Address: 0040e977
AIPlayPhaseCommand * __thiscall
FUN_0040e977(AIPlayPhaseCommand *param_1,uchar param_2,char *param_3,int param_4,int param_5,
            int param_6)
{
  uchar uVar1;
  
  param_1->groupValue = param_2;
  uVar1 = AIPlayPhaseCommand::convertToIntType(param_1,param_3);
  param_1->typeValue = uVar1;
  param_1->value2Value = param_5;
  param_1->value1Value = param_4;
  param_1->value3Value = param_6;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040e9b3
// Address: 0040e9b3
void __fastcall FUN_0040e9b3(AIPlayPhaseCommand *param_1)
{
  AIPlayPhaseCommand::convertToNameType(param_1,param_1->typeValue);
  return;
}

// --------------------------------------------------

// Function: FUN_0040e9ca
// Address: 0040e9ca
// [HELPER] s_Attack: "Attack"
// [HELPER] s_AttackSavedTarget: "AttackSavedTarget"
// [HELPER] s_Heal: "Heal"
// [HELPER] s_Move: "Move"
// [HELPER] s_ResetAliveCount: "ResetAliveCount"
// [HELPER] s_ResetHitPoints: "ResetHitPoints"
// [HELPER] s_Retreat: "Retreat"
// [HELPER] s_Wait: "Wait"
byte FUN_0040e9ca(byte *param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = &s_Move;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ea06:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ea0b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ea06;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ea0b:
  if (iVar3 == 0) {
    return 1;
  }
  pbVar4 = &s_Attack;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ea46:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ea4b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ea46;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ea4b:
  if (iVar3 == 0) {
    return 2;
  }
  pbVar4 = &s_AttackSavedTarget;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ea86:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ea8b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ea86;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ea8b:
  if (iVar3 == 0) {
    return 3;
  }
  pbVar4 = &s_Retreat;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040eac6:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040eacb;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040eac6;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040eacb:
  if (iVar3 == 0) {
    return 4;
  }
  pbVar4 = &s_Heal;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040eb06:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040eb0b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040eb06;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040eb0b:
  if (iVar3 == 0) {
    return 5;
  }
  pbVar4 = &s_ResetHitPoints;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040eb46:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040eb4b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040eb46;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040eb4b:
  if (iVar3 == 0) {
    return 6;
  }
  pbVar4 = &s_ResetAliveCount;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040eb86:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040eb8b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040eb86;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040eb8b:
  if (iVar3 == 0) {
    return 7;
  }
  pbVar2 = &s_Wait;
  while( true ) {
    bVar1 = *param_1;
    bVar5 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return 8;
    }
    bVar1 = param_1[1];
    bVar5 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = param_1 + 2;
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 8;
    }
  }
  return (1 - bVar5 != (uint)(bVar5 != 0)) - 1U & 8;
}

// --------------------------------------------------

// Function: FUN_0040ebe7
// Address: 0040ebe7
// [HELPER] s_Attack: "Attack"
// [HELPER] s_AttackSavedTarget: "AttackSavedTarget"
// [HELPER] s_Heal: "Heal"
// [HELPER] s_Invalid: "Invalid"
// [HELPER] s_Move: "Move"
// [HELPER] s_ResetAliveCount: "ResetAliveCount"
// [HELPER] s_ResetHitPoints: "ResetHitPoints"
// [HELPER] s_Retreat: "Retreat"
// [HELPER] s_Wait: "Wait"
char * FUN_0040ebe7(undefined1 param_1)
{
  switch(param_1) {
  case 1:
    return &s_Move;
  case 2:
    return &s_Attack;
  case 3:
    return &s_AttackSavedTarget;
  case 4:
    return &s_Retreat;
  case 5:
    return &s_Heal;
  case 6:
    return &s_ResetHitPoints;
  case 7:
    return &s_ResetAliveCount;
  case 8:
    return &s_Wait;
  default:
    return s_Invalid;
  }
}

// --------------------------------------------------

// Function: FUN_0040ec4e
// Address: 0040ec4e
void __fastcall FUN_0040ec4e(undefined4 param_1,undefined2 param_2)
{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined4 in_EAX;
  int iVar5;
  char cVar6;
  int unaff_EBX;
  char *unaff_ESI;
  
  uVar1 = in(param_2);
  *unaff_ESI = *unaff_ESI + (char)param_1;
  uVar2 = in(param_2);
  cVar6 = (char)param_2;
  *unaff_ESI = *unaff_ESI + cVar6;
  uVar3 = in(param_2);
  *unaff_ESI = *unaff_ESI + (char)unaff_EBX;
  uVar4 = in(param_2);
  iVar5 = CONCAT31((int3)((uint)(CONCAT31((int3)((uint)(CONCAT31((int3)((uint)(CONCAT31((int3)((uint
                                                  )in_EAX >> 8),uVar1) + 1) >> 8),uVar2) + 1) >> 8),
                                          uVar3) + 1) >> 8),uVar4) + 1;
  *unaff_ESI = *unaff_ESI + (char)((uint)iVar5 >> 8);
  uVar1 = in(param_2);
  *unaff_ESI = *unaff_ESI + (char)((uint)param_1 >> 8);
  uVar2 = in(param_2);
  *unaff_ESI = *unaff_ESI + (char)((ushort)param_2 >> 8);
  uVar3 = in(param_2);
  *unaff_ESI = *unaff_ESI + (char)((uint)unaff_EBX >> 8);
  uVar4 = in(param_2);
  iVar5 = CONCAT31((int3)((uint)(CONCAT31((int3)((uint)(CONCAT31((int3)((uint)(CONCAT31((int3)((uint
                                                  )iVar5 >> 8),uVar1) + 1) >> 8),uVar2) + 1) >> 8),
                                          uVar3) + 1) >> 8),uVar4);
  *(char *)(unaff_EBX + -0x7c2dcd3f) = *(char *)(unaff_EBX + -0x7c2dcd3f) + (char)param_1;
  *(int *)(iVar5 + 0x4488911) = *(int *)(iVar5 + 0x4488911) + -1;
  *(undefined4 *)(iVar5 + 9) = param_1;
  *(char *)(iVar5 + 0xd) = cVar6;
  *(char *)(iVar5 + 0xe) = cVar6;
  return;
}

// --------------------------------------------------

// Function: FUN_0040ec86
// Address: 0040ec86
void __thiscall
FUN_0040ec86(undefined1 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5,undefined1 param_6,undefined4 param_7)
{
  *param_1 = param_2;
  *(undefined4 *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 8) = param_4;
  param_1[0xc] = param_5;
  param_1[0xd] = param_6;
  *(undefined4 *)(param_1 + 0x10) = param_7;
  return;
}

// --------------------------------------------------

// Function: FUN_0040ecbe
// Address: 0040ecbe
AIPlayPhaseTrigger * __thiscall
FUN_0040ecbe(AIPlayPhaseTrigger *param_1,char *param_2,int param_3,int param_4,uchar param_5,
            uchar param_6,int param_7)
{
  uchar uVar1;
  
  uVar1 = AIPlayPhaseTrigger::convertToIntType(param_1,param_2);
  param_1->typeValue = uVar1;
  param_1->value1Value = param_3;
  param_1->value2Value = param_4;
  param_1->phaseValue = param_5;
  param_1->nextPhaseValue = param_6;
  param_1->randomnessValue = param_7;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040ecf8
// Address: 0040ecf8
void __fastcall FUN_0040ecf8(AIPlayPhaseTrigger *param_1)
{
  AIPlayPhaseTrigger::convertToNameType(param_1,param_1->typeValue);
  return;
}

// --------------------------------------------------

// Function: FUN_0040ed09
// Address: 0040ed09
// [HELPER] s_DamageToAnyGroup: "DamageToAnyGroup"
// [HELPER] s_DamageToGroup: "DamageToGroup"
// [HELPER] s_Death: "Death"
// [HELPER] s_DeathOfGroup: "DeathOfGroup"
// [HELPER] s_Gather: "Gather"
// [HELPER] s_HealOfGroup: "HealOfGroup"
// [HELPER] s_HealthLost: "HealthLost"
// [HELPER] s_Immediate: "Immediate"
// [HELPER] s_Level1EnemySighted: "Level1EnemySighted"
// [HELPER] s_Level2EnemySighted: "Level2EnemySighted"
// [HELPER] s_Time: "Time"
byte FUN_0040ed09(byte *param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = &s_Gather;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ed46:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ed4b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ed46;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ed4b:
  if (iVar3 == 0) {
    return 1;
  }
  pbVar4 = &s_Death;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ed86:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ed8b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ed86;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ed8b:
  if (iVar3 == 0) {
    return 2;
  }
  pbVar4 = &s_HealthLost;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040edc6:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040edcb;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040edc6;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040edcb:
  if (iVar3 == 0) {
    return 3;
  }
  pbVar4 = &s_DamageToGroup;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ee06:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ee0b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ee06;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ee0b:
  if (iVar3 == 0) {
    return 4;
  }
  pbVar4 = &s_DamageToAnyGroup;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ee46:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ee4b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ee46;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ee4b:
  if (iVar3 == 0) {
    return 5;
  }
  pbVar4 = &s_Level1EnemySighted;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ee86:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ee8b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ee86;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ee8b:
  if (iVar3 == 0) {
    return 6;
  }
  pbVar4 = &s_Level2EnemySighted;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040eec6:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040eecb;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040eec6;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040eecb:
  if (iVar3 == 0) {
    return 7;
  }
  pbVar4 = &s_DeathOfGroup;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ef06:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ef0b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ef06;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ef0b:
  if (iVar3 == 0) {
    return 8;
  }
  pbVar4 = &s_HealOfGroup;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ef46:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ef4b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ef46;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ef4b:
  if (iVar3 == 0) {
    return 9;
  }
  pbVar4 = &s_Immediate;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ef86:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ef8b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ef86;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ef8b:
  if (iVar3 == 0) {
    return 10;
  }
  pbVar2 = &s_Time;
  while( true ) {
    bVar1 = *param_1;
    bVar5 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return 0xb;
    }
    bVar1 = param_1[1];
    bVar5 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = param_1 + 2;
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 0xb;
    }
  }
  return (1 - bVar5 != (uint)(bVar5 != 0)) - 1U & 0xb;
}

// --------------------------------------------------

// Function: FUN_0040efe7
// Address: 0040efe7
// [HELPER] s_DamageToAnyGroup: "DamageToAnyGroup"
// [HELPER] s_DamageToGroup: "DamageToGroup"
// [HELPER] s_Death: "Death"
// [HELPER] s_DeathOfGroup: "DeathOfGroup"
// [HELPER] s_Gather: "Gather"
// [HELPER] s_HealOfGroup: "HealOfGroup"
// [HELPER] s_HealthLost: "HealthLost"
// [HELPER] s_Immediate: "Immediate"
// [HELPER] s_Invalid: "Invalid"
// [HELPER] s_Level1EnemySighted: "Level1EnemySighted"
// [HELPER] s_Level2EnemySighted: "Level2EnemySighted"
// [HELPER] s_Time: "Time"
char * FUN_0040efe7(undefined1 param_1)
{
  switch(param_1) {
  case 1:
    return &s_Gather;
  case 2:
    return &s_Death;
  case 3:
    return &s_HealthLost;
  case 4:
    return &s_DamageToGroup;
  case 5:
    return &s_DamageToAnyGroup;
  case 6:
    return &s_Level1EnemySighted;
  case 7:
    return &s_Level2EnemySighted;
  case 8:
    return &s_DeathOfGroup;
  case 9:
    return &s_HealOfGroup;
  case 10:
    return &s_Immediate;
  case 0xb:
    return &s_Time;
  default:
    return s_Invalid;
  }
}

// --------------------------------------------------

// Function: FUN_0040f066
// Address: 0040f066
/* WARNING: Control flow encountered bad instruction data */

void FUN_0040f066(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_0040f0db
// Address: 0040f0db
void FUN_0040f0db(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)
{
  if (-1 < param_3 + -1) {
    do {
      (*param_4)();
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: `vector_constructor_iterator'
// Address: 0040f0e0
/* void __stdcall `vector constructor iterator'(void *,unsigned int,int,void (__thiscall*)(void *))
    */

void _vector_constructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)
{
  void *unaff_EBX;
  
  if (-1 < param_3 + -1) {
    do {
      (*param_4)(unaff_EBX);
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040f10a
// Address: 0040f10a
int __thiscall FUN_0040f10a(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 5)) {
    return param_2 * 0x10 + param_1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040f12a
// Address: 0040f12a
int __thiscall FUN_0040f12a(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 3)) {
    return param_1 + (param_2 + 4) * 0x14;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040f14e
// Address: 0040f14e
undefined4 __thiscall FUN_0040f14e(int param_1,undefined1 *param_2)
{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  
  iVar1 = 0;
  pcVar3 = (char *)(param_1 + 1);
  do {
    if (*pcVar3 == '\0') {
      puVar2 = (undefined1 *)(iVar1 * 0x10 + param_1);
      *puVar2 = *param_2;
      puVar2[1] = param_2[1];
      *(undefined4 *)(puVar2 + 4) = *(undefined4 *)(param_2 + 4);
      *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(param_2 + 8);
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_2 + 0xc);
      return 1;
    }
    iVar1 = iVar1 + 1;
    pcVar3 = pcVar3 + 0x10;
  } while (iVar1 < 5);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040f195
// Address: 0040f195
undefined4 __thiscall FUN_0040f195(int param_1,undefined1 *param_2)
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = 0;
  pcVar3 = (char *)(param_1 + 0x50);
  do {
    if (*pcVar3 == '\0') {
      iVar1 = param_1 + iVar2 * 0x14;
      *(undefined1 *)(param_1 + (iVar2 + 4) * 0x14) = *param_2;
      *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(param_2 + 4);
      *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(param_2 + 8);
      *(undefined1 *)(iVar1 + 0x5c) = param_2[0xc];
      *(undefined1 *)(iVar1 + 0x5d) = param_2[0xd];
      *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)(param_2 + 0x10);
      return 1;
    }
    iVar2 = iVar2 + 1;
    pcVar3 = pcVar3 + 0x14;
  } while (iVar2 < 3);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040f1fb
// Address: 0040f1fb
void __fastcall FUN_0040f1fb(int param_1)
{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)(param_1 + 1);
  iVar2 = 5;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined1 *)(param_1 + 0x50);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x14;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_0040f223
// Address: 0040f223
AIPlayGroup * __fastcall FUN_0040f223(AIPlayGroup *param_1)
{
  AIPlayGroup::initialize(param_1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040f23c
// Address: 0040f23c
undefined1 __thiscall FUN_0040f23c(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 6)) {
    return *(undefined1 *)(param_1 + param_2);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040f258
// Address: 0040f258
void __thiscall FUN_0040f258(int param_1,int param_2,undefined1 param_3)
{
  if ((-1 < param_2) && (param_2 < 6)) {
    *(undefined1 *)(param_1 + param_2) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040f277
// Address: 0040f277
undefined1 __thiscall FUN_0040f277(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 6)) {
    return *(undefined1 *)(param_1 + 6 + param_2);
  }
  return 0xff;
}

// --------------------------------------------------

// Function: FUN_0040f299
// Address: 0040f299
void __thiscall FUN_0040f299(int param_1,int param_2,undefined1 param_3)
{
  if ((-1 < param_2) && (param_2 < 6)) {
    *(undefined1 *)(param_1 + 6 + param_2) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040f2b8
// Address: 0040f2b8
void __fastcall FUN_0040f2b8(int param_1)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(param_1 + 6);
  do {
    puVar1[-6] = 0;
    *puVar1 = 0xfe;
    puVar1 = puVar1 + 1;
  } while ((int)(puVar1 + (-6 - param_1)) < 6);
  return;
}

// --------------------------------------------------

// Function: FUN_0040f2de
// Address: 0040f2de
int __fastcall FUN_0040f2de(int param_1)
{
  undefined1 *puVar1;
  int iVar2;
  AIPlayGroup *this;
  AIPlayPhase *this_00;
  
  *(undefined1 *)(param_1 + 0x41) = 1;
  *(undefined1 *)(param_1 + 0x43) = 1;
  *(undefined1 *)(param_1 + 0x4f) = 1;
  *(undefined1 *)(param_1 + 0x42) = 0xff;
  *(undefined1 *)(param_1 + 0x4e) = 0;
  *(undefined1 *)(param_1 + 0x50) = 0x32;
  *(undefined1 *)(param_1 + 0x51) = 0x32;
  this = (AIPlayGroup *)(param_1 + 0x53);
  iVar2 = 5;
  do {
    AIPlayGroup::AIPlayGroup(this);
    this = this + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this_00 = (AIPlayPhase *)(param_1 + 0x90);
  iVar2 = 10;
  do {
    AIPlayPhase::AIPlayPhase(this_00);
    this_00 = this_00 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined1 *)(param_1 + 0x49);
  do {
    puVar1[-5] = 5;
    *puVar1 = 5;
    puVar1 = puVar1 + 1;
  } while ((int)(puVar1 + (-0x49 - param_1)) < 5);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040f351
// Address: 0040f351
void __thiscall FUN_0040f351(undefined4 param_1,int param_2)
{
  if (param_2 != 0) {
    strncpy(param_1,param_2,0x40);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040f377
// Address: 0040f377
undefined4 __fastcall FUN_0040f377(char *param_1)
{
  if ((*param_1 == 'H') && (param_1[1] == 'P')) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040f394
// Address: 0040f394
void __fastcall FUN_0040f394(AIPlay *param_1)
{
  AIPlay::convertToNameType(param_1,param_1->typeValue);
  return;
}

// --------------------------------------------------

// Function: FUN_0040f3aa
// Address: 0040f3aa
undefined1 __thiscall FUN_0040f3aa(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 5)) {
    return *(undefined1 *)(param_1 + 0x44 + param_2);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040f3c9
// Address: 0040f3c9
undefined4 __thiscall FUN_0040f3c9(int param_1,char param_2)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(char *)(iVar1 + 0x44 + param_1) == param_2) {
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040f3ef
// Address: 0040f3ef
undefined4 __thiscall FUN_0040f3ef(int param_1,undefined1 param_2)
{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    cVar1 = *(char *)(iVar2 + 0x44 + param_1);
    if ((cVar1 == '\0') || (cVar1 == '\x05')) break;
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
      return 0;
    }
  }
  *(undefined1 *)(iVar2 + 0x44 + param_1) = param_2;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040f419
// Address: 0040f419
undefined1 __thiscall FUN_0040f419(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 5)) {
    return *(undefined1 *)(param_1 + 0x49 + param_2);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040f439
// Address: 0040f439
undefined4 __thiscall FUN_0040f439(int param_1,char param_2)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(char *)(iVar1 + 0x49 + param_1) == param_2) {
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040f45f
// Address: 0040f45f
undefined4 __thiscall FUN_0040f45f(int param_1,undefined1 param_2)
{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    cVar1 = *(char *)(iVar2 + 0x49 + param_1);
    if ((cVar1 == '\0') || (cVar1 == '\x05')) break;
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
      return 0;
    }
  }
  *(undefined1 *)(iVar2 + 0x49 + param_1) = param_2;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040f489
// Address: 0040f489
int __thiscall FUN_0040f489(AIPlay *param_1,undefined4 param_2,int param_3)
{
  AIPlayPhase *this;
  AIPlayPhaseTrigger *pAVar1;
  int iVar2;
  
  this = AIPlay::phase(param_1,param_3);
  if (this == (AIPlayPhase *)0x0) {
    return 2;
  }
  iVar2 = 0;
  while( true ) {
    pAVar1 = AIPlayPhase::trigger(this,iVar2);
    if ((pAVar1 != (AIPlayPhaseTrigger *)0x0) && (pAVar1->typeValue == '\x01')) break;
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return 2;
    }
  }
  return pAVar1->value1Value;
}

// --------------------------------------------------

// Function: FUN_0040f4d7
// Address: 0040f4d7
int __thiscall FUN_0040f4d7(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 5)) {
    return param_1 + 0x53 + param_2 * 0xc;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040f4fc
// Address: 0040f4fc
int __thiscall FUN_0040f4fc(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 10)) {
    return param_1 + 0x90 + param_2 * 0x8c;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040f526
// Address: 0040f526
undefined4 __thiscall
FUN_0040f526(int param_1,AIPlayStatus *param_2,int *param_3,int param_4,RGE_Game_World *param_5)
{
  byte bVar1;
  uchar uVar2;
  byte bVar3;
  byte bVar4;
  uchar uVar5;
  AIPlay *this;
  RGE_Static_Object *pRVar6;
  AIPlayGroup *pAVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int *piStack_4f0;
  int *piStack_4ec;
  int iStack_4e8;
  int *piStack_4e4;
  undefined4 uStack_4e0;
  int iStack_4d4;
  int aiStack_4c8 [6];
  int aiStack_4b0 [300];
  
  this = AIPlayBook::play(param_5->playbook,param_2->playNumberValue);
  if (this == (AIPlay *)0x0) {
    return 0;
  }
  uStack_4e0 = 1;
  piVar11 = aiStack_4c8;
  for (iVar9 = 6; iVar9 != 0; iVar9 = iVar9 + -1) {
    *piVar11 = 0;
    piVar11 = piVar11 + 1;
  }
  if (0 < param_4) {
    piStack_4f0 = (int *)param_4;
    do {
      pRVar6 = RGE_Game_World::object(param_5,*param_3);
      if (((pRVar6 == (RGE_Static_Object *)0x0) ||
          (iVar9 = (**(code **)(param_5->playbook->_padding_ + 0x10))(pRVar6), iVar9 < 0)) ||
         (5 < iVar9)) {
        uStack_4e0 = 0;
      }
      else {
        iVar10 = aiStack_4c8[iVar9];
        iVar12 = *param_3;
        aiStack_4c8[iVar9] = iVar10 + 1;
        aiStack_4b0[iVar10 + iVar9 * 0x32] = iVar12;
      }
      param_3 = param_3 + 1;
      piStack_4f0 = (int *)((int)piStack_4f0 + -1);
    } while (piStack_4f0 != (int *)0x0);
  }
  iStack_4e8 = 0;
  if (this->numberGroupsValue != '\0') {
    do {
      pAVar7 = AIPlay::group(this,iStack_4e8);
      if (pAVar7 == (AIPlayGroup *)0x0) {
        return 0;
      }
      piStack_4f0 = aiStack_4c8;
      piStack_4ec = (int *)0x0;
      piStack_4e4 = (int *)0x0;
      do {
        bVar1 = AIPlayGroup::minimum(pAVar7,(int)piStack_4ec);
        if (bVar1 != 0) {
          iVar10 = 0;
          iVar12 = 0;
          iVar9 = *piStack_4f0;
          if (0 < iVar9) {
            do {
              if ((int)(uint)bVar1 <= iVar10) break;
              if (aiStack_4b0[iVar12 + (int)piStack_4e4] != -1) {
                iVar8 = AIPlayStatus::addGrouping
                                  (param_2,aiStack_4b0[iVar12 + (int)piStack_4e4],(uchar)iStack_4e8,
                                   (uchar)piStack_4ec);
                if (iVar8 == 1) {
                  iVar10 = iVar10 + 1;
                  uVar5 = this->maximumNumberUnitsValue;
                  aiStack_4b0[iVar12 + (int)piStack_4e4] = -1;
                  uVar2 = AIPlayStatus::numberInPlay(param_2);
                  if (uVar2 == uVar5) goto LAB_0040f918;
                }
                else {
                  uStack_4e0 = 0;
                }
              }
              iVar12 = iVar12 + 1;
            } while (iVar12 < iVar9);
          }
        }
        piStack_4e4 = (int *)((int)piStack_4e4 + 0x32);
        piStack_4ec = (int *)((int)piStack_4ec + 1);
        piStack_4f0 = piStack_4f0 + 1;
      } while ((int)piStack_4e4 < 300);
      iStack_4e8 = iStack_4e8 + 1;
    } while (iStack_4e8 < (int)(uint)this->numberGroupsValue);
  }
  piStack_4e4 = aiStack_4c8;
  piStack_4f0 = aiStack_4b0;
  iStack_4e8 = 0;
  do {
    iStack_4d4 = 0;
    iVar9 = *piStack_4e4;
    if (0 < iVar9) {
      piStack_4ec = piStack_4f0;
      do {
        iVar10 = *piStack_4ec;
        if (iVar10 != -1) {
          if (*(char *)(param_1 + 0x4f) == '\x01') {
            iVar12 = -1;
            iVar8 = 0;
            bVar1 = 0;
            if (this->numberGroupsValue != '\0') {
              do {
                pAVar7 = AIPlay::group(this,iVar8);
                if (pAVar7 != (AIPlayGroup *)0x0) {
                  bVar3 = AIPlayStatus::numberOfTypeInGroup(param_2,iVar8,iStack_4e8);
                  bVar4 = AIPlayGroup::maximum(pAVar7,iStack_4e8);
                  if ((bVar3 < bVar4) &&
                     ((iVar12 == -1 ||
                      (bVar3 = AIPlayStatus::numberInGroup(param_2,iVar8), bVar3 < bVar1)))) {
                    bVar1 = AIPlayStatus::numberInGroup(param_2,iVar8);
                    iVar12 = iVar8;
                  }
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 < (int)(uint)this->numberGroupsValue);
            }
            if (iVar12 != -1) {
              iVar10 = AIPlayStatus::addGrouping(param_2,iVar10,(uchar)iVar12,(uchar)iStack_4e8);
              if (iVar10 == 1) {
                uVar5 = this->maximumNumberUnitsValue;
                *piStack_4ec = -1;
                uVar2 = AIPlayStatus::numberInPlay(param_2);
                if (uVar2 == uVar5) goto LAB_0040f918;
              }
              else {
                uStack_4e0 = 0;
              }
            }
          }
          else if ((*(char *)(param_1 + 0x4f) == '\x02') &&
                  (iVar12 = 0, this->numberGroupsValue != '\0')) {
            do {
              pAVar7 = AIPlay::group(this,iVar12);
              if (pAVar7 != (AIPlayGroup *)0x0) {
                bVar1 = AIPlayStatus::numberOfTypeInGroup(param_2,iVar12,iStack_4e8);
                bVar3 = AIPlayGroup::maximum(pAVar7,iStack_4e8);
                if (bVar1 < bVar3) {
                  iVar8 = AIPlayStatus::addGrouping(param_2,iVar10,(uchar)iVar12,(uchar)iStack_4e8);
                  if (iVar8 == 1) {
                    uVar5 = this->maximumNumberUnitsValue;
                    *piStack_4ec = -1;
                    uVar2 = AIPlayStatus::numberInPlay(param_2);
                    if (uVar2 == uVar5) goto LAB_0040f918;
                    break;
                  }
                  uStack_4e0 = 0;
                }
              }
              iVar12 = iVar12 + 1;
            } while (iVar12 < (int)(uint)this->numberGroupsValue);
          }
        }
        iStack_4d4 = iStack_4d4 + 1;
        piStack_4ec = piStack_4ec + 1;
      } while (iStack_4d4 < iVar9);
    }
    iStack_4e8 = iStack_4e8 + 1;
    piStack_4f0 = piStack_4f0 + 0x32;
    piStack_4e4 = piStack_4e4 + 1;
  } while (iStack_4e8 < 6);
LAB_0040f918:
  iVar9 = 0;
  uVar5 = '\0';
  if (this->numberGroupsValue != '\0') {
    do {
      pAVar7 = AIPlay::group(this,iVar9);
      if (pAVar7 != (AIPlayGroup *)0x0) {
        iVar10 = 0;
        do {
          bVar1 = AIPlayGroup::minimum(pAVar7,iVar10);
          bVar3 = AIPlayStatus::numberOfTypeInGroup(param_2,iVar9,iVar10);
          if (bVar3 < bVar1) {
            uVar5 = uVar5 + (bVar1 - bVar3);
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < 6);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)(uint)this->numberGroupsValue);
  }
  param_2->deviationValue = uVar5;
  return uStack_4e0;
}

// --------------------------------------------------

// Function: FUN_0040f9ae
// Address: 0040f9ae
int __thiscall FUN_0040f9ae(int param_1,uint param_2,uint param_3,int param_4)
{
  AIPlayPhase *this;
  AIPlayPhaseCommand *pAVar1;
  int iVar2;
  
  if ((((-1 < (int)param_2) && ((int)param_2 < 5)) && (-1 < param_4)) && (param_4 < 10)) {
    iVar2 = 0;
    this = (AIPlayPhase *)(param_1 + 0x90 + param_4 * 0x8c);
    do {
      pAVar1 = AIPlayPhase::command(this,iVar2);
      if (pAVar1->groupValue == param_2) {
        pAVar1 = AIPlayPhase::command(this,iVar2);
        if (pAVar1->typeValue == param_3) {
          return iVar2;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 5);
    return -1;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_0040fa34
// Address: 0040fa34
// [HELPER] s_Annoy: "Annoy"
// [HELPER] s_Attack: "Attack"
// [HELPER] s_Flank: "Flank"
// [HELPER] s_Recon: "Recon"
byte FUN_0040fa34(byte *param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = &s_Attack;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040fa76:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040fa7b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040fa76;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040fa7b:
  if (iVar3 == 0) {
    return 1;
  }
  pbVar4 = &s_Annoy;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040fab6:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040fabb;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040fab6;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040fabb:
  if (iVar3 == 0) {
    return 2;
  }
  pbVar4 = &s_Flank;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040faf6:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040fafb;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040faf6;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040fafb:
  if (iVar3 == 0) {
    return 3;
  }
  pbVar2 = &s_Recon;
  while( true ) {
    bVar1 = *param_1;
    bVar5 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return 4;
    }
    bVar1 = param_1[1];
    bVar5 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = param_1 + 2;
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 4;
    }
  }
  return (1 - bVar5 != (uint)(bVar5 != 0)) - 1U & 4;
}

// --------------------------------------------------

// Function: FUN_0040fb57
// Address: 0040fb57
// [HELPER] s_Annoy: "Annoy"
// [HELPER] s_Attack: "Attack"
// [HELPER] s_Flank: "Flank"
// [HELPER] s_Invalid: "Invalid"
// [HELPER] s_Recon: "Recon"
char * FUN_0040fb57(undefined1 param_1)
{
  switch(param_1) {
  case 1:
    return &s_Attack;
  case 2:
    return &s_Annoy;
  case 3:
    return &s_Flank;
  case 4:
    return &s_Recon;
  default:
    return s_Invalid;
  }
}

// --------------------------------------------------

// Function: FUN_0040fb9e
// Address: 0040fb9e
undefined4 __fastcall
FUN_0040fb9e(int param_1,char param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6,
            int param_7,int param_8)
{
  char in_AL;
  AIPlayPhaseCommand *pAVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_ESI;
  int iVar4;
  AIPlayPhase *this;
  bool in_CF;
  bool in_ZF;
  
  if (in_CF || in_ZF) {
    *(char *)(unaff_EBX + 0x40fb76ff) = *(char *)(unaff_EBX + 0x40fb76ff) + (char)param_1;
  }
  else {
    in_AL = in_AL + '\x01';
  }
  *(char *)(unaff_ESI + -5) = *(char *)(unaff_ESI + -5) + (char)((uint)unaff_EBX >> 8);
  *(char *)(unaff_ESI + -0x71ffbf05) = *(char *)(unaff_ESI + -0x71ffbf05) + in_AL + '\x01';
  *(char *)(param_1 + 0x53) = *(char *)(param_1 + 0x53) + param_2;
  param_3 = 0;
  this = (AIPlayPhase *)(param_1 + 0x90);
  do {
    iVar4 = 0;
    do {
      pAVar1 = AIPlayPhase::command(this,iVar4);
      if (pAVar1->typeValue == '\x01') {
        iVar3 = pAVar1->value1Value + param_5;
        iVar2 = pAVar1->value2Value + param_6;
        if ((((iVar3 < 0) || (iVar2 < 0)) || (param_7 <= iVar3)) || (param_8 <= iVar2)) {
          return 0;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 5);
    this = this + 1;
    param_3 = param_3 + 1;
    if (9 < param_3) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0040fc2a
// Address: 0040fc2a
int __fastcall FUN_0040fc2a(int param_1)
{
  undefined1 *puVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 400) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x194) = 0xffffffff;
  XYZ::XYZ((XYZ *)(param_1 + 0x198),0,0,0);
  *(undefined1 *)(param_1 + 0x1b8) = 0xfd;
  *(undefined4 *)(param_1 + 0x1bc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  *(undefined1 *)(param_1 + 0x1c4) = 0;
  puVar1 = (undefined1 *)(param_1 + 5);
  iVar2 = 0x32;
  do {
    *(undefined4 *)(puVar1 + -5) = 0xffffffff;
    puVar1[-1] = 0xff;
    *puVar1 = 0xff;
    puVar1 = puVar1 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x1a4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1a8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1ac) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1b0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1b4) = 0xffffffff;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040fcad
// Address: 0040fcad
undefined4 __thiscall FUN_0040fcad(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 5)) {
    return *(undefined4 *)(param_1 + 0x1a4 + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0040fccd
// Address: 0040fccd
void __thiscall FUN_0040fccd(int param_1,int param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 < 5)) {
    *(undefined4 *)(param_1 + 0x1a4 + param_2 * 4) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040fceb
// Address: 0040fceb
char __fastcall FUN_0040fceb(int *param_1)
{
  char cVar1;
  int iVar2;
  
  cVar1 = '\0';
  iVar2 = 0x32;
  do {
    if (*param_1 != -1) {
      cVar1 = cVar1 + '\x01';
    }
    param_1 = param_1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return cVar1;
}

// --------------------------------------------------

// Function: FUN_0040fd05
// Address: 0040fd05
char __thiscall FUN_0040fd05(int *param_1,uint param_2)
{
  char cVar1;
  int iVar2;
  
  cVar1 = '\0';
  iVar2 = 0x32;
  do {
    if ((*param_1 != -1) && (*(byte *)(param_1 + 1) == param_2)) {
      cVar1 = cVar1 + '\x01';
    }
    param_1 = param_1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return cVar1;
}

// --------------------------------------------------

// Function: FUN_0040fd38
// Address: 0040fd38
char __thiscall FUN_0040fd38(int param_1,uint param_2,uint param_3)
{
  char cVar1;
  byte *pbVar2;
  int iVar3;
  
  cVar1 = '\0';
  pbVar2 = (byte *)(param_1 + 5);
  iVar3 = 0x32;
  do {
    if (((*(int *)(pbVar2 + -5) != -1) && (pbVar2[-1] == param_2)) && (*pbVar2 == param_3)) {
      cVar1 = cVar1 + '\x01';
    }
    pbVar2 = pbVar2 + 8;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return cVar1;
}

// --------------------------------------------------

// Function: FUN_0040fd7e
// Address: 0040fd7e
undefined1 __thiscall FUN_0040fd7e(int *param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
  if (param_2 < 0) {
    return 0xff;
  }
  iVar1 = 0;
  piVar2 = param_1;
  do {
    if (*piVar2 == param_2) {
      return (char)param_1[iVar1 * 2 + 1];
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 2;
  } while (iVar1 < 0x32);
  return 0xff;
}

// --------------------------------------------------

// Function: FUN_0040fdae
// Address: 0040fdae
undefined4 __thiscall FUN_0040fdae(int *param_1,int param_2,undefined1 param_3,undefined1 param_4)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = param_1;
  do {
    if (*piVar2 == -1) {
      param_1[iVar1 * 2] = param_2;
      *(undefined1 *)(param_1 + iVar1 * 2 + 1) = param_3;
      *(undefined1 *)((int)param_1 + iVar1 * 8 + 5) = param_4;
      return 1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 2;
  } while (iVar1 < 0x32);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040fde6
// Address: 0040fde6
undefined4 __thiscall FUN_0040fde6(int *param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = param_1;
  do {
    if (*piVar2 == param_2) {
      param_1[iVar1 * 2] = -1;
      *(undefined1 *)(param_1 + iVar1 * 2 + 1) = 0xff;
      *(undefined1 *)((int)param_1 + iVar1 * 8 + 5) = 0xff;
      return 1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 2;
  } while (iVar1 < 0x32);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040fe26
// Address: 0040fe26
void __fastcall FUN_0040fe26(int param_1)
{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)(param_1 + 5);
  iVar2 = 0x32;
  do {
    *(undefined4 *)(puVar1 + -5) = 0xffffffff;
    puVar1[-1] = 0xff;
    *puVar1 = 0xff;
    puVar1 = puVar1 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_0040fe4e
// Address: 0040fe4e
void __thiscall FUN_0040fe4e(int *param_1,int param_2,int *param_3)
{
  int iVar1;
  
  *param_3 = 0;
  iVar1 = 0x32;
  do {
    if (*param_1 != -1) {
      *(int *)(param_2 + *param_3 * 4) = *param_1;
      *param_3 = *param_3 + 1;
    }
    param_1 = param_1 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_0040fe83
// Address: 0040fe83
void __thiscall FUN_0040fe83(void *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = param_2;
  rge_read(param_2,(void *)((int)param_1 + 400),4);
  rge_read(iVar1,(void *)((int)param_1 + 0x194),4);
  rge_read(iVar1,&param_2,4);
  *(int *)((int)param_1 + 0x198) = param_2;
  rge_read(iVar1,&param_2,4);
  *(int *)((int)param_1 + 0x19c) = param_2;
  rge_read(iVar1,&param_2,4);
  *(int *)((int)param_1 + 0x1a0) = param_2;
  rge_read(iVar1,(void *)((int)param_1 + 0x1a4),0x14);
  rge_read(iVar1,(void *)((int)param_1 + 0x1b8),1);
  rge_read(iVar1,param_1,400);
  rge_read(iVar1,(void *)((int)param_1 + 0x1bc),4);
  rge_read(iVar1,(void *)((int)param_1 + 0x1c0),4);
  return;
}

// --------------------------------------------------

// Function: FUN_0040ff66
// Address: 0040ff66
void __thiscall FUN_0040ff66(void *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = param_2;
  rge_write(param_2,(void *)((int)param_1 + 400),4);
  rge_write(iVar1,(void *)((int)param_1 + 0x194),4);
  param_2 = *(undefined4 *)((int)param_1 + 0x198);
  rge_write(iVar1,&param_2,4);
  param_2 = *(undefined4 *)((int)param_1 + 0x19c);
  rge_write(iVar1,&param_2,4);
  param_2 = *(undefined4 *)((int)param_1 + 0x1a0);
  rge_write(iVar1,&param_2,4);
  rge_write(iVar1,(void *)((int)param_1 + 0x1a4),0x14);
  rge_write(iVar1,(void *)((int)param_1 + 0x1b8),1);
  rge_write(iVar1,param_1,400);
  rge_write(iVar1,(void *)((int)param_1 + 0x1bc),4);
  rge_write(iVar1,(void *)((int)param_1 + 0x1c0),4);
  return;
}

// --------------------------------------------------

// Function: FUN_00410046
// Address: 00410046
void __thiscall FUN_00410046(int param_1,undefined4 *param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar5 = 0x32;
  *(undefined4 *)(param_1 + 400) = param_2[100];
  *(undefined4 *)(param_1 + 0x194) = param_2[0x65];
  uVar1 = param_2[0x68];
  uVar2 = param_2[0x67];
  *(undefined4 *)(param_1 + 0x198) = param_2[0x66];
  *(undefined4 *)(param_1 + 0x19c) = uVar2;
  *(undefined4 *)(param_1 + 0x1a0) = uVar1;
  *(undefined1 *)(param_1 + 0x1b8) = *(undefined1 *)(param_2 + 0x6e);
  *(undefined4 *)(param_1 + 0x1bc) = param_2[0x6f];
  *(undefined4 *)(param_1 + 0x1c0) = param_2[0x70];
  puVar3 = (undefined1 *)(param_1 + 4);
  puVar4 = param_2;
  do {
    *(undefined4 *)(puVar3 + -4) = *puVar4;
    *puVar3 = puVar3[(int)param_2 - param_1];
    puVar3[1] = *(undefined1 *)((int)puVar4 + 5);
    puVar3 = puVar3 + 8;
    iVar5 = iVar5 + -1;
    puVar4 = puVar4 + 2;
  } while (iVar5 != 0);
  puVar4 = (undefined4 *)(param_1 + 0x1a4);
  iVar5 = 5;
  do {
    *puVar4 = *(undefined4 *)((int)puVar4 + ((int)param_2 - param_1));
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_004100fa
// Address: 004100fa
void __thiscall FUN_004100fa(int *param_1,undefined4 param_2,RGE_Game_World *param_3)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  
  iVar2 = 0x32;
  do {
    if (*param_1 != -1) {
      pRVar1 = RGE_Game_World::object(param_3,*param_1);
      if ((pRVar1 == (RGE_Static_Object *)0x0) || (2 < pRVar1->object_state)) {
        *param_1 = -1;
        *(undefined1 *)(param_1 + 1) = 0xff;
        *(undefined1 *)((int)param_1 + 5) = 0xff;
      }
    }
    param_1 = param_1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_00410143
// Address: 00410143
void __thiscall FUN_00410143(AIPlayStatus *param_1,uint param_2,RGE_Game_World *param_3)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  AIPlayStatus *pAVar5;
  
  iVar4 = 0;
  iVar3 = 0x32;
  pAVar5 = param_1;
  do {
    iVar2 = pAVar5->groupings[0].id;
    if ((iVar2 != -1) && (pAVar5->groupings[0].groupID == param_2)) {
      pRVar1 = RGE_Game_World::object(param_3,iVar2);
      if (pRVar1 != (RGE_Static_Object *)0x0) {
        iVar2 = __ftol();
        iVar4 = iVar4 + iVar2;
      }
    }
    pAVar5 = (AIPlayStatus *)(pAVar5->groupings + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  AIPlayStatus::setOriginalHitPoints(param_1,param_2,iVar4);
  return;
}

// --------------------------------------------------

// Function: FUN_004101ad
// Address: 004101ad
void __fastcall FUN_004101ad(undefined4 *param_1)
{
  param_1[1] = 0;
  param_1[0x13] = 0;
  *param_1 = &AIPlayBook::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_004101c1
// Address: 004101c1
AIPlayBook * __thiscall FUN_004101c1(AIPlayBook *param_1,byte param_2)
{
  AIPlayBook::~AIPlayBook(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004101ee
// Address: 004101ee
void __fastcall FUN_004101ee(undefined4 *param_1)
{
  *param_1 = &AIPlayBook::_vftable_;
  if ((void *)param_1[0x13] != (void *)0x0) {
    param_1[1] = 0;
    operator_delete((void *)param_1[0x13]);
    param_1[0x13] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00410219
// Address: 00410219
// [HELPER] s_: ""
// [HELPER] s_Balance: "Balance"
// [HELPER] s_DeathPercentage: "DeathPercentage"
// [HELPER] s_EndPlay: "EndPlay"
// [HELPER] s_FirstGroup: "FirstGroup"
// [HELPER] s_Group: "Group"
// [HELPER] s_Intelligence: "Intelligence"
// [HELPER] s_MaxUnits: "MaxUnits"
// [HELPER] s_MinUnits: "MinUnits"
// [HELPER] s_NONE: "NONE"
// [HELPER] s_NULL: "NULL"
// [HELPER] s_NumberGroups: "NumberGroups"
// [HELPER] s_Overflow: "Overflow"
// [HELPER] s_Phase: "Phase"
// [HELPER] s_Play: "Play"
// [HELPER] s_PlayType: "PlayType"
// [HELPER] s_Power: "Power"
// [HELPER] s_RTrigger: "RTrigger"
// [HELPER] s_TargetChar: "TargetChar"
// [HELPER] s_TargetType: "TargetType"
// [HELPER] s_Trigger: "Trigger"
// [HELPER] s___c_c: " %c%c"
// [HELPER] s___s__d_: "%*s %d "
// [HELPER] s___s__d__s__d____d_: "%*s %d %s %d - %d "
// [HELPER] s___s__d__s__d__d_: "%*s %d %s %d %d "
// [HELPER] s___s__d__s__d__d__d_: "%*s %d %s %d %d %d "
// [HELPER] s___s__s_: "%*s %s "
// [HELPER] s__s: "%s"
// [HELPER] s__sF_d: "%sF%d"
// [HELPER] s__s_: "%s\n"
// [HELPER] s_r: "r"
undefined4 __thiscall FUN_00410219(int *param_1,byte *param_2)
{
  char cVar1;
  uchar uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  AIPlay *pAVar6;
  AIPlay *pAVar7;
  AIPlayGroup *pAVar8;
  AIPlayPhase *pAVar9;
  AIPlayPhaseCommand *pAVar10;
  AIPlayPhaseTrigger *pAVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  char *pcVar16;
  byte *pbVar17;
  int iVar18;
  int *piVar19;
  byte *pbVar20;
  char *pcVar21;
  int *piVar22;
  int *unaff_FS_OFFSET;
  bool bVar23;
  int iStack_3b4;
  int iStack_3b0;
  char cStack_3a9;
  int iStack_3a8;
  char cStack_3a1;
  int iStack_3a0;
  AIPlayPhase *pAStack_39c;
  AIPlayGroup *pAStack_398;
  int iStack_394;
  AIPlay *pAStack_390;
  int iStack_38c;
  int iStack_388;
  int iStack_384;
  int iStack_380;
  int iStack_37c;
  XYZ XStack_378;
  XYZ XStack_36c;
  XYZ XStack_360;
  byte abStack_354 [256];
  AIPlayPhaseCommand AStack_254;
  AIPlayPhaseCommand AStack_244;
  char acStack_234 [256];
  AIPlayPhaseTrigger AStack_134;
  AIPlayPhaseTrigger AStack_120;
  char acStack_10c [256];
  int iStack_c;
  code *pcStack_8;
  int iStack_4;
  
  iStack_c = *unaff_FS_OFFSET;
  iStack_4 = -1;
  pcStack_8 = FUN_0055c73e;
  *unaff_FS_OFFSET = (int)&iStack_c;
  if (param_2 == (byte *)0x0) {
LAB_004112e9:
    pcVar16 = &s_NULL;
LAB_004112fb:
    uVar13 = 0xffffffff;
    do {
      pcVar21 = pcVar16;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar21 = pcVar16 + 1;
      cVar1 = *pcVar16;
      pcVar16 = pcVar21;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    piVar19 = (int *)(pcVar21 + -uVar13);
    piVar22 = param_1 + 2;
    for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
      *piVar22 = *piVar19;
      piVar19 = piVar19 + 1;
      piVar22 = piVar22 + 1;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(char *)piVar22 = (char)*piVar19;
      piVar19 = (int *)((int)piVar19 + 1);
      piVar22 = (int *)((int)piVar22 + 1);
    }
  }
  else {
    pbVar20 = &s_NONE;
    pbVar17 = param_2;
    do {
      bVar3 = *pbVar17;
      bVar23 = bVar3 < *pbVar20;
      if (bVar3 != *pbVar20) {
LAB_0041027f:
        iVar4 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
        goto LAB_00410284;
      }
      if (bVar3 == 0) break;
      bVar3 = pbVar17[1];
      bVar23 = bVar3 < pbVar20[1];
      if (bVar3 != pbVar20[1]) goto LAB_0041027f;
      pbVar17 = pbVar17 + 2;
      pbVar20 = pbVar20 + 2;
    } while (bVar3 != 0);
    iVar4 = 0;
LAB_00410284:
    if (iVar4 == 0) {
      if (param_2 == (byte *)0x0) goto LAB_004112e9;
      pcVar16 = &s_NONE;
      goto LAB_004112fb;
    }
    strncpy(param_1 + 2,param_2,0x40);
    sprintf(acStack_234,s__s,param_1 + 2);
    iVar4 = fopen(acStack_234,s_r);
    if (iVar4 != 0) {
      iStack_37c = iVar4;
      if ((void *)param_1[0x13] != (void *)0x0) {
        operator_delete((void *)param_1[0x13]);
        param_1[0x13] = 0;
      }
      param_1[1] = 0;
      iVar5 = fgets(acStack_234,0x100,iVar4);
      while (iVar5 != 0) {
        iVar5 = -1;
        pcVar16 = acStack_234;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          cVar1 = *pcVar16;
          pcVar16 = pcVar16 + 1;
        } while (cVar1 != '\0');
        if (iVar5 != -2) {
          sscanf(acStack_234,s__s_,abStack_354);
          pbVar17 = abStack_354;
          pbVar20 = &s_Play;
          do {
            bVar3 = *pbVar20;
            bVar23 = bVar3 < *pbVar17;
            if (bVar3 != *pbVar17) {
LAB_00410368:
              iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
              goto LAB_0041036d;
            }
            if (bVar3 == 0) break;
            bVar3 = pbVar20[1];
            bVar23 = bVar3 < pbVar17[1];
            if (bVar3 != pbVar17[1]) goto LAB_00410368;
            pbVar20 = pbVar20 + 2;
            pbVar17 = pbVar17 + 2;
          } while (bVar3 != 0);
          iVar5 = 0;
LAB_0041036d:
          if (iVar5 == 0) {
            param_1[1] = param_1[1] + 8;
          }
        }
        iVar5 = fgets(acStack_234,0x100,iVar4);
      }
      if (16000 < param_1[1]) {
        param_1[1] = 16000;
      }
      iVar4 = param_1[1];
      pAVar6 = (AIPlay *)operator_new(iVar4 * 0x608);
      iStack_4 = 0;
      pAVar7 = (AIPlay *)0x0;
      pAStack_390 = pAVar6;
      if ((pAVar6 != (AIPlay *)0x0) && (pAVar7 = pAVar6, -1 < iVar4 + -1)) {
        do {
          AIPlay::AIPlay(pAVar6);
          iVar4 = iVar4 + -1;
          pAVar6 = pAVar6 + 1;
        } while (iVar4 != 0);
      }
      iStack_4 = -1;
      param_1[0x13] = (int)pAVar7;
      if (pAVar7 != (AIPlay *)0x0) {
        rewind(iStack_37c);
        iVar4 = -1;
        iStack_394 = -1;
        iStack_3a8 = -1;
        do {
          iVar5 = fgets(acStack_234,0x100,iStack_37c);
          if (iVar5 == 0) break;
          iVar5 = -1;
          pcVar16 = acStack_234;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            cVar1 = *pcVar16;
            pcVar16 = pcVar16 + 1;
          } while (cVar1 != '\0');
          if (iVar5 != -2) {
            uVar13 = 0xffffffff;
            pcVar16 = s_;
            do {
              pcVar21 = pcVar16;
              if (uVar13 == 0) break;
              uVar13 = uVar13 - 1;
              pcVar21 = pcVar16 + 1;
              cVar1 = *pcVar16;
              pcVar16 = pcVar21;
            } while (cVar1 != '\0');
            uVar13 = ~uVar13;
            pbVar17 = (byte *)(pcVar21 + -uVar13);
            pbVar20 = abStack_354;
            for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
              *(undefined4 *)pbVar20 = *(undefined4 *)pbVar17;
              pbVar17 = pbVar17 + 4;
              pbVar20 = pbVar20 + 4;
            }
            for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
              *pbVar20 = *pbVar17;
              pbVar17 = pbVar17 + 1;
              pbVar20 = pbVar20 + 1;
            }
            uVar13 = 0xffffffff;
            pcVar16 = s_;
            do {
              pcVar21 = pcVar16;
              if (uVar13 == 0) break;
              uVar13 = uVar13 - 1;
              pcVar21 = pcVar16 + 1;
              cVar1 = *pcVar16;
              pcVar16 = pcVar21;
            } while (cVar1 != '\0');
            uVar13 = ~uVar13;
            pcVar16 = pcVar21 + -uVar13;
            pcVar21 = acStack_10c;
            for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
              *(undefined4 *)pcVar21 = *(undefined4 *)pcVar16;
              pcVar16 = pcVar16 + 4;
              pcVar21 = pcVar21 + 4;
            }
            iStack_3b4 = 0;
            for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
              *pcVar21 = *pcVar16;
              pcVar16 = pcVar16 + 1;
              pcVar21 = pcVar21 + 1;
            }
            iStack_3b0 = 0;
            iStack_38c = 0;
            iStack_380 = 0;
            iStack_384 = 0;
            iVar5 = sscanf(acStack_234,s___c_c,&cStack_3a1,&cStack_3a9);
            if ((iVar5 != -1) && ((cStack_3a1 != '/' || (cStack_3a9 != '/')))) {
              sscanf(acStack_234,s__s_,abStack_354);
              pbVar20 = &s_Play;
              pbVar17 = abStack_354;
              do {
                bVar3 = *pbVar17;
                bVar23 = bVar3 < *pbVar20;
                if (bVar3 != *pbVar20) {
LAB_00410539:
                  iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                  goto LAB_0041053e;
                }
                if (bVar3 == 0) break;
                bVar3 = pbVar17[1];
                bVar23 = bVar3 < pbVar20[1];
                if (bVar3 != pbVar20[1]) goto LAB_00410539;
                pbVar17 = pbVar17 + 2;
                pbVar20 = pbVar20 + 2;
              } while (bVar3 != 0);
              iVar5 = 0;
LAB_0041053e:
              if (iVar5 == 0) {
                iVar5 = 0;
                iVar15 = 0;
                cVar1 = acStack_234[0];
                while (cVar1 != '\"') {
                  iVar18 = iVar15 + 1;
                  iVar15 = iVar15 + 1;
                  iVar5 = iVar5 + 1;
                  cVar1 = acStack_234[iVar18];
                }
                iStack_3b4 = iVar5 + 1;
                pcVar16 = acStack_234 + iVar15 + 1;
                cVar1 = acStack_234[iVar15 + 1];
                iStack_3b0 = iStack_3b4;
                while (cVar1 != '\"') {
                  pcVar16 = pcVar16 + 1;
                  iStack_3b0 = iStack_3b0 + 1;
                  cVar1 = *pcVar16;
                }
                uVar13 = 0;
                if (iStack_3b4 < iStack_3b0) {
                  uVar13 = iStack_3b0 - iStack_3b4;
                  pbVar17 = (byte *)(acStack_234 + iVar5 + 1);
                  pbVar20 = abStack_354;
                  for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
                    *(undefined4 *)pbVar20 = *(undefined4 *)pbVar17;
                    pbVar17 = pbVar17 + 4;
                    pbVar20 = pbVar20 + 4;
                  }
                  for (uVar14 = uVar13 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
                    *pbVar20 = *pbVar17;
                    pbVar17 = pbVar17 + 1;
                    pbVar20 = pbVar20 + 1;
                  }
                }
                iVar4 = iVar4 + 1;
                abStack_354[uVar13] = 0;
                iStack_394 = iVar4;
                if (15999 < iVar4) break;
                AIPlay::setName((AIPlay *)(param_1[0x13] + iVar4 * 0x608),(char *)abStack_354);
              }
              else {
                pbVar20 = &s_PlayType;
                pbVar17 = abStack_354;
                do {
                  bVar3 = *pbVar17;
                  bVar23 = bVar3 < *pbVar20;
                  if (bVar3 != *pbVar20) {
LAB_00410612:
                    iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                    goto LAB_00410617;
                  }
                  if (bVar3 == 0) break;
                  bVar3 = pbVar17[1];
                  bVar23 = bVar3 < pbVar20[1];
                  if (bVar3 != pbVar20[1]) goto LAB_00410612;
                  pbVar17 = pbVar17 + 2;
                  pbVar20 = pbVar20 + 2;
                } while (bVar3 != 0);
                iVar5 = 0;
LAB_00410617:
                if ((iVar5 == 0) && (iVar4 != -1)) {
                  sscanf(acStack_234,s___s__s_,abStack_354);
                  pAVar7 = (AIPlay *)(param_1[0x13] + iVar4 * 0x608);
                  uVar2 = AIPlay::convertToIntType(pAVar7,(char *)abStack_354);
                  pAVar7->typeValue = uVar2;
                }
                else {
                  pbVar20 = &s_MinUnits;
                  pbVar17 = abStack_354;
                  do {
                    bVar3 = *pbVar17;
                    bVar23 = bVar3 < *pbVar20;
                    if (bVar3 != *pbVar20) {
LAB_0041068e:
                      iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                      goto LAB_00410693;
                    }
                    if (bVar3 == 0) break;
                    bVar3 = pbVar17[1];
                    bVar23 = bVar3 < pbVar20[1];
                    if (bVar3 != pbVar20[1]) goto LAB_0041068e;
                    pbVar17 = pbVar17 + 2;
                    pbVar20 = pbVar20 + 2;
                  } while (bVar3 != 0);
                  iVar5 = 0;
LAB_00410693:
                  if ((iVar5 == 0) && (iVar4 != -1)) {
                    sscanf(acStack_234,s___s__d_,&iStack_3b4);
                    *(undefined1 *)(param_1[0x13] + iVar4 * 0x608 + 0x41) = (undefined1)iStack_3b4;
                  }
                  else {
                    pbVar20 = &s_MaxUnits;
                    pbVar17 = abStack_354;
                    do {
                      bVar3 = *pbVar17;
                      bVar23 = bVar3 < *pbVar20;
                      if (bVar3 != *pbVar20) {
LAB_00410702:
                        iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                        goto LAB_00410707;
                      }
                      if (bVar3 == 0) break;
                      bVar3 = pbVar17[1];
                      bVar23 = bVar3 < pbVar20[1];
                      if (bVar3 != pbVar20[1]) goto LAB_00410702;
                      pbVar17 = pbVar17 + 2;
                      pbVar20 = pbVar20 + 2;
                    } while (bVar3 != 0);
                    iVar5 = 0;
LAB_00410707:
                    if ((iVar5 == 0) && (iVar4 != -1)) {
                      sscanf(acStack_234,s___s__d_,&iStack_3b4);
                      *(undefined1 *)(param_1[0x13] + iVar4 * 0x608 + 0x42) = (undefined1)iStack_3b4
                      ;
                    }
                    else {
                      pbVar20 = &s_Power;
                      pbVar17 = abStack_354;
                      do {
                        bVar3 = *pbVar17;
                        bVar23 = bVar3 < *pbVar20;
                        if (bVar3 != *pbVar20) {
LAB_00410776:
                          iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                          goto LAB_0041077b;
                        }
                        if (bVar3 == 0) break;
                        bVar3 = pbVar17[1];
                        bVar23 = bVar3 < pbVar20[1];
                        if (bVar3 != pbVar20[1]) goto LAB_00410776;
                        pbVar17 = pbVar17 + 2;
                        pbVar20 = pbVar20 + 2;
                      } while (bVar3 != 0);
                      iVar5 = 0;
LAB_0041077b:
                      if ((iVar5 == 0) && (iVar4 != -1)) {
                        sscanf(acStack_234,s___s__d_,&iStack_3b4);
                        *(undefined1 *)(param_1[0x13] + iVar4 * 0x608 + 0x4e) =
                             (undefined1)iStack_3b4;
                      }
                      else {
                        pbVar20 = &s_Overflow;
                        pbVar17 = abStack_354;
                        do {
                          bVar3 = *pbVar17;
                          bVar23 = bVar3 < *pbVar20;
                          if (bVar3 != *pbVar20) {
LAB_004107ea:
                            iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                            goto LAB_004107ef;
                          }
                          if (bVar3 == 0) break;
                          bVar3 = pbVar17[1];
                          bVar23 = bVar3 < pbVar20[1];
                          if (bVar3 != pbVar20[1]) goto LAB_004107ea;
                          pbVar17 = pbVar17 + 2;
                          pbVar20 = pbVar20 + 2;
                        } while (bVar3 != 0);
                        iVar5 = 0;
LAB_004107ef:
                        if ((iVar5 == 0) && (iVar4 != -1)) {
                          sscanf(acStack_234,s___s__s_,abStack_354);
                          pbVar20 = &s_Balance;
                          pbVar17 = abStack_354;
                          do {
                            bVar3 = *pbVar17;
                            bVar23 = bVar3 < *pbVar20;
                            if (bVar3 != *pbVar20) {
LAB_0041084b:
                              iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                              goto LAB_00410850;
                            }
                            if (bVar3 == 0) break;
                            bVar3 = pbVar17[1];
                            bVar23 = bVar3 < pbVar20[1];
                            if (bVar3 != pbVar20[1]) goto LAB_0041084b;
                            pbVar17 = pbVar17 + 2;
                            pbVar20 = pbVar20 + 2;
                          } while (bVar3 != 0);
                          iVar5 = 0;
LAB_00410850:
                          if (iVar5 == 0) {
                            *(undefined1 *)(param_1[0x13] + iVar4 * 0x608 + 0x4f) = 1;
                          }
                          else {
                            pbVar20 = &s_FirstGroup;
                            pbVar17 = abStack_354;
                            do {
                              bVar3 = *pbVar17;
                              bVar23 = bVar3 < *pbVar20;
                              if (bVar3 != *pbVar20) {
LAB_0041089d:
                                iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                                goto LAB_004108a2;
                              }
                              if (bVar3 == 0) break;
                              bVar3 = pbVar17[1];
                              bVar23 = bVar3 < pbVar20[1];
                              if (bVar3 != pbVar20[1]) goto LAB_0041089d;
                              pbVar17 = pbVar17 + 2;
                              pbVar20 = pbVar20 + 2;
                            } while (bVar3 != 0);
                            iVar5 = 0;
LAB_004108a2:
                            if (iVar5 == 0) {
                              *(undefined1 *)(param_1[0x13] + iVar4 * 0x608 + 0x4f) = 2;
                            }
                          }
                        }
                        else {
                          pbVar20 = &s_DeathPercentage;
                          pbVar17 = abStack_354;
                          do {
                            bVar3 = *pbVar17;
                            bVar23 = bVar3 < *pbVar20;
                            if (bVar3 != *pbVar20) {
LAB_004108f3:
                              iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                              goto LAB_004108f8;
                            }
                            if (bVar3 == 0) break;
                            bVar3 = pbVar17[1];
                            bVar23 = bVar3 < pbVar20[1];
                            if (bVar3 != pbVar20[1]) goto LAB_004108f3;
                            pbVar17 = pbVar17 + 2;
                            pbVar20 = pbVar20 + 2;
                          } while (bVar3 != 0);
                          iVar5 = 0;
LAB_004108f8:
                          if ((iVar5 == 0) && (iVar4 != -1)) {
                            sscanf(acStack_234,s___s__d_,&iStack_3b4);
                            if (iStack_3b4 < 0) {
                              *(undefined1 *)(param_1[0x13] + iVar4 * 0x608 + 0x51) = 0;
                            }
                            else if (iStack_3b4 < 0x65) {
                              *(char *)(param_1[0x13] + iVar4 * 0x608 + 0x51) = (char)iStack_3b4;
                            }
                            else {
                              *(undefined1 *)(param_1[0x13] + iVar4 * 0x608 + 0x51) = 100;
                            }
                          }
                          else {
                            pbVar20 = &s_Intelligence;
                            pbVar17 = abStack_354;
                            do {
                              bVar3 = *pbVar17;
                              bVar23 = bVar3 < *pbVar20;
                              if (bVar3 != *pbVar20) {
LAB_0041099c:
                                iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                                goto LAB_004109a1;
                              }
                              if (bVar3 == 0) break;
                              bVar3 = pbVar17[1];
                              bVar23 = bVar3 < pbVar20[1];
                              if (bVar3 != pbVar20[1]) goto LAB_0041099c;
                              pbVar17 = pbVar17 + 2;
                              pbVar20 = pbVar20 + 2;
                            } while (bVar3 != 0);
                            iVar5 = 0;
LAB_004109a1:
                            if ((iVar5 == 0) && (iVar4 != -1)) {
                              sscanf(acStack_234,s___s__d_,&iStack_3b4);
                              if (iStack_3b4 < 0) {
                                *(undefined1 *)(param_1[0x13] + iVar4 * 0x608 + 0x50) = 0;
                              }
                              else if (iStack_3b4 < 0x65) {
                                *(char *)(param_1[0x13] + iVar4 * 0x608 + 0x50) = (char)iStack_3b4;
                              }
                              else {
                                *(undefined1 *)(param_1[0x13] + iVar4 * 0x608 + 0x50) = 100;
                              }
                            }
                            else {
                              pbVar20 = &s_TargetChar;
                              pbVar17 = abStack_354;
                              do {
                                bVar3 = *pbVar17;
                                bVar23 = bVar3 < *pbVar20;
                                if (bVar3 != *pbVar20) {
LAB_00410a45:
                                  iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                                  goto LAB_00410a4a;
                                }
                                if (bVar3 == 0) break;
                                bVar3 = pbVar17[1];
                                bVar23 = bVar3 < pbVar20[1];
                                if (bVar3 != pbVar20[1]) goto LAB_00410a45;
                                pbVar17 = pbVar17 + 2;
                                pbVar20 = pbVar20 + 2;
                              } while (bVar3 != 0);
                              iVar5 = 0;
LAB_00410a4a:
                              if ((iVar5 == 0) && (iVar4 != -1)) {
                                sscanf(acStack_234,s___s__s_,acStack_10c);
                                iVar5 = (**(code **)(*param_1 + 8))(acStack_10c);
                                if (iVar5 != 0) {
                                  AIPlay::addTargetCharacteristic
                                            ((AIPlay *)(param_1[0x13] + iVar4 * 0x608),(uchar)iVar5)
                                  ;
                                }
                              }
                              else {
                                pbVar20 = &s_TargetType;
                                pbVar17 = abStack_354;
                                do {
                                  bVar3 = *pbVar17;
                                  bVar23 = bVar3 < *pbVar20;
                                  if (bVar3 != *pbVar20) {
LAB_00410ad2:
                                    iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                                    goto LAB_00410ad7;
                                  }
                                  if (bVar3 == 0) break;
                                  bVar3 = pbVar17[1];
                                  bVar23 = bVar3 < pbVar20[1];
                                  if (bVar3 != pbVar20[1]) goto LAB_00410ad2;
                                  pbVar17 = pbVar17 + 2;
                                  pbVar20 = pbVar20 + 2;
                                } while (bVar3 != 0);
                                iVar5 = 0;
LAB_00410ad7:
                                if ((iVar5 == 0) && (iVar4 != -1)) {
                                  sscanf(acStack_234,s___s__s_,acStack_10c);
                                  iVar5 = (**(code **)(*param_1 + 4))(acStack_10c);
                                  if (iVar5 != 0) {
                                    AIPlay::addTargetType
                                              ((AIPlay *)(param_1[0x13] + iVar4 * 0x608),
                                               (uchar)iVar5);
                                  }
                                }
                                else {
                                  pbVar20 = &s_NumberGroups;
                                  pbVar17 = abStack_354;
                                  do {
                                    bVar3 = *pbVar17;
                                    bVar23 = bVar3 < *pbVar20;
                                    if (bVar3 != *pbVar20) {
LAB_00410b5f:
                                      iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                                      goto LAB_00410b64;
                                    }
                                    if (bVar3 == 0) break;
                                    bVar3 = pbVar17[1];
                                    bVar23 = bVar3 < pbVar20[1];
                                    if (bVar3 != pbVar20[1]) goto LAB_00410b5f;
                                    pbVar17 = pbVar17 + 2;
                                    pbVar20 = pbVar20 + 2;
                                  } while (bVar3 != 0);
                                  iVar5 = 0;
LAB_00410b64:
                                  if ((iVar5 == 0) && (iVar4 != -1)) {
                                    sscanf(acStack_234,s___s__d_,&iStack_3b4);
                                    *(undefined1 *)(param_1[0x13] + iVar4 * 0x608 + 0x52) =
                                         (undefined1)iStack_3b4;
                                  }
                                  else {
                                    pbVar20 = &s_Group;
                                    pbVar17 = abStack_354;
                                    do {
                                      bVar3 = *pbVar17;
                                      bVar23 = bVar3 < *pbVar20;
                                      if (bVar3 != *pbVar20) {
LAB_00410bd3:
                                        iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                                        goto LAB_00410bd8;
                                      }
                                      if (bVar3 == 0) break;
                                      bVar3 = pbVar17[1];
                                      bVar23 = bVar3 < pbVar20[1];
                                      if (bVar3 != pbVar20[1]) goto LAB_00410bd3;
                                      pbVar17 = pbVar17 + 2;
                                      pbVar20 = pbVar20 + 2;
                                    } while (bVar3 != 0);
                                    iVar5 = 0;
LAB_00410bd8:
                                    if (((iVar5 == 0) && (iVar4 != -1)) && (iStack_3a8 == -1)) {
                                      sscanf(acStack_234,s___s__d__s__d____d_,&iStack_3b4,
                                             acStack_10c,&iStack_3b0,&iStack_38c);
                                      if (((-1 < iStack_3b4) && (iStack_3b4 < 5)) &&
                                         (iVar5 = (**(code **)(*param_1 + 0xc))(acStack_10c),
                                         iVar5 != -1)) {
                                        iVar15 = iStack_3b0;
                                        if (iStack_38c < 0) {
                                          iVar15 = 0;
                                        }
                                        iVar18 = iVar5;
                                        pAVar8 = AIPlay::group((AIPlay *)
                                                               (iVar4 * 0x608 + param_1[0x13]),
                                                               iStack_3b4);
                                        AIPlayGroup::setMinimum(pAVar8,iVar18,iVar15);
                                        iVar15 = iStack_38c;
                                        if (0x32 < iStack_38c) {
                                          iVar15 = 0x32;
                                        }
                                        pAVar8 = AIPlay::group((AIPlay *)
                                                               (iVar4 * 0x608 + param_1[0x13]),
                                                               iStack_3b4);
                                        AIPlayGroup::setMaximum(pAVar8,iVar5,iVar15);
                                      }
                                    }
                                    else {
                                      pbVar20 = &s_Phase;
                                      pbVar17 = abStack_354;
                                      do {
                                        bVar3 = *pbVar17;
                                        bVar23 = bVar3 < *pbVar20;
                                        if (bVar3 != *pbVar20) {
LAB_00410cf8:
                                          iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                                          goto LAB_00410cfd;
                                        }
                                        if (bVar3 == 0) break;
                                        bVar3 = pbVar17[1];
                                        bVar23 = bVar3 < pbVar20[1];
                                        if (bVar3 != pbVar20[1]) goto LAB_00410cf8;
                                        pbVar17 = pbVar17 + 2;
                                        pbVar20 = pbVar20 + 2;
                                      } while (bVar3 != 0);
                                      iVar5 = 0;
LAB_00410cfd:
                                      if ((iVar5 == 0) && (iVar4 != -1)) {
                                        sscanf(acStack_234,s___s__d_,&iStack_3b4);
                                        iStack_3a8 = iStack_3b4;
                                      }
                                      else {
                                        pbVar20 = &s_Group;
                                        pbVar17 = abStack_354;
                                        do {
                                          bVar3 = *pbVar17;
                                          bVar23 = bVar3 < *pbVar20;
                                          if (bVar3 != *pbVar20) {
LAB_00410d5a:
                                            iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                                            goto LAB_00410d5f;
                                          }
                                          if (bVar3 == 0) break;
                                          bVar3 = pbVar17[1];
                                          bVar23 = bVar3 < pbVar20[1];
                                          if (bVar3 != pbVar20[1]) goto LAB_00410d5a;
                                          pbVar17 = pbVar17 + 2;
                                          pbVar20 = pbVar20 + 2;
                                        } while (bVar3 != 0);
                                        iVar5 = 0;
LAB_00410d5f:
                                        if (((iVar5 == 0) && (iVar4 != -1)) && (iStack_3a8 != -1)) {
                                          sscanf(acStack_234,s___s__d__s__d__d__d_,&iStack_3b4,
                                                 acStack_10c,&iStack_3b0,&iStack_38c,&iStack_380);
                                          if ((-1 < iStack_3b4) && (iStack_3b4 < 5)) {
                                            pAVar9 = AIPlay::phase((AIPlay *)
                                                                   (param_1[0x13] + iVar4 * 0x608),
                                                                   iStack_3a8);
                                            AIPlayPhaseCommand::AIPlayPhaseCommand
                                                      (&AStack_254,(uchar)iStack_3b4,acStack_10c,
                                                       iStack_3b0,iStack_38c,iStack_380);
                                            AIPlayPhase::addCommand(pAVar9,&AStack_254);
                                          }
                                        }
                                        else {
                                          pbVar20 = &s_Trigger;
                                          pbVar17 = abStack_354;
                                          do {
                                            bVar3 = *pbVar17;
                                            bVar23 = bVar3 < *pbVar20;
                                            if (bVar3 != *pbVar20) {
LAB_00410e43:
                                              iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                                              goto LAB_00410e48;
                                            }
                                            if (bVar3 == 0) break;
                                            bVar3 = pbVar17[1];
                                            bVar23 = bVar3 < pbVar20[1];
                                            if (bVar3 != pbVar20[1]) goto LAB_00410e43;
                                            pbVar17 = pbVar17 + 2;
                                            pbVar20 = pbVar20 + 2;
                                          } while (bVar3 != 0);
                                          iVar5 = 0;
LAB_00410e48:
                                          if (((iVar5 == 0) && (iVar4 != -1)) && (iStack_3a8 != -1))
{
                                            sscanf(acStack_234,s___s__d__s__d__d_,&iStack_3b4,
                                                   acStack_10c,&iStack_3b0,&iStack_384);
                                            iVar5 = iStack_3a8;
                                            pAVar9 = AIPlay::phase((AIPlay *)
                                                                   (param_1[0x13] + iVar4 * 0x608),
                                                                   iStack_3a8);
                                            AIPlayPhaseTrigger::AIPlayPhaseTrigger
                                                      (&AStack_134,acStack_10c,iStack_3b0,iStack_384
                                                       ,(uchar)iVar5,(uchar)iStack_3b4,0);
                                            AIPlayPhase::addTrigger(pAVar9,&AStack_134);
                                          }
                                          else {
                                            pbVar20 = &s_RTrigger;
                                            pbVar17 = abStack_354;
                                            do {
                                              bVar3 = *pbVar17;
                                              bVar23 = bVar3 < *pbVar20;
                                              if (bVar3 != *pbVar20) {
LAB_00410f10:
                                                iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                                                goto LAB_00410f15;
                                              }
                                              if (bVar3 == 0) break;
                                              bVar3 = pbVar17[1];
                                              bVar23 = bVar3 < pbVar20[1];
                                              if (bVar3 != pbVar20[1]) goto LAB_00410f10;
                                              pbVar17 = pbVar17 + 2;
                                              pbVar20 = pbVar20 + 2;
                                            } while (bVar3 != 0);
                                            iVar5 = 0;
LAB_00410f15:
                                            if (((iVar5 == 0) && (iVar4 != -1)) &&
                                               (iStack_3a8 != -1)) {
                                              sscanf(acStack_234,s___s__d__s__d__d__d_,&iStack_3b4,
                                                     acStack_10c,&iStack_3b0,&iStack_384,&iStack_380
                                                    );
                                              iVar5 = iStack_3a8;
                                              pAVar9 = AIPlay::phase((AIPlay *)
                                                                     (param_1[0x13] + iVar4 * 0x608)
                                                                     ,iStack_3a8);
                                              AIPlayPhaseTrigger::AIPlayPhaseTrigger
                                                        (&AStack_120,acStack_10c,iStack_3b0,
                                                         iStack_384,(uchar)iVar5,(uchar)iStack_3b4,
                                                         iStack_380);
                                              AIPlayPhase::addTrigger(pAVar9,&AStack_120);
                                            }
                                            else {
                                              pbVar20 = &s_EndPlay;
                                              pbVar17 = abStack_354;
                                              do {
                                                bVar3 = *pbVar17;
                                                bVar23 = bVar3 < *pbVar20;
                                                if (bVar3 != *pbVar20) {
LAB_00410fe9:
                                                  iVar5 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
                                                  goto LAB_00410fee;
                                                }
                                                if (bVar3 == 0) break;
                                                bVar3 = pbVar17[1];
                                                bVar23 = bVar3 < pbVar20[1];
                                                if (bVar3 != pbVar20[1]) goto LAB_00410fe9;
                                                pbVar17 = pbVar17 + 2;
                                                pbVar20 = pbVar20 + 2;
                                              } while (bVar3 != 0);
                                              iVar5 = 0;
LAB_00410fee:
                                              if ((iVar5 == 0) && (iVar4 != -1)) {
                                                uVar13 = 0xffffffff;
                                                iStack_3a8 = -1;
                                                iVar5 = iStack_394 * 0x608;
                                                pAStack_390 = (AIPlay *)abStack_354;
                                                pcVar16 = (char *)(iVar5 + param_1[0x13]);
                                                do {
                                                  pcVar21 = pcVar16;
                                                  if (uVar13 == 0) break;
                                                  uVar13 = uVar13 - 1;
                                                  pcVar21 = pcVar16 + 1;
                                                  cVar1 = *pcVar16;
                                                  pcVar16 = pcVar21;
                                                } while (cVar1 != '\0');
                                                uVar13 = ~uVar13;
                                                pbVar17 = (byte *)(pcVar21 + -uVar13);
                                                pAVar7 = pAStack_390;
                                                for (uVar14 = uVar13 >> 2; uVar14 != 0;
                                                    uVar14 = uVar14 - 1) {
                                                  *(undefined4 *)pAVar7->nameValue =
                                                       *(undefined4 *)pbVar17;
                                                  pbVar17 = pbVar17 + 4;
                                                  pAVar7 = (AIPlay *)(pAVar7->nameValue + 4);
                                                }
                                                for (uVar13 = uVar13 & 3; uVar13 != 0;
                                                    uVar13 = uVar13 - 1) {
                                                  pAVar7->nameValue[0] = *pbVar17;
                                                  pbVar17 = pbVar17 + 1;
                                                  pAVar7 = (AIPlay *)(pAVar7->nameValue + 1);
                                                }
                                                if ((abStack_354[0] == 0x48) &&
                                                   (abStack_354[1] == 'P')) {
                                                  param_1[1] = param_1[1] + -7;
                                                  iVar4 = iStack_394;
                                                }
                                                else {
                                                  iStack_394 = iStack_394 + 7;
                                                  iStack_388 = 1;
                                                  iVar15 = iVar5;
                                                  do {
                                                    sprintf(abStack_354,s__sF_d,
                                                            iVar5 + param_1[0x13],iStack_388);
                                                    iVar18 = iVar15 + 0x608;
                                                    AIPlay::setName((AIPlay *)
                                                                    (iVar18 + param_1[0x13]),
                                                                    (char *)abStack_354);
                                                    iVar4 = 0;
                                                    *(undefined1 *)(iVar15 + 0x64b + param_1[0x13])
                                                         = *(undefined1 *)
                                                            (iVar5 + 0x43 + param_1[0x13]);
                                                    *(undefined1 *)(iVar15 + 0x649 + param_1[0x13])
                                                         = *(undefined1 *)
                                                            (iVar5 + 0x41 + param_1[0x13]);
                                                    *(undefined1 *)(iVar15 + 0x64a + param_1[0x13])
                                                         = *(undefined1 *)
                                                            (iVar5 + 0x42 + param_1[0x13]);
                                                    *(undefined1 *)(iVar15 + 0x656 + param_1[0x13])
                                                         = *(undefined1 *)
                                                            (iVar5 + 0x4e + param_1[0x13]);
                                                    *(undefined1 *)(iVar15 + 0x657 + param_1[0x13])
                                                         = *(undefined1 *)
                                                            (iVar5 + 0x4f + param_1[0x13]);
                                                    *(undefined1 *)(iVar15 + 0x659 + param_1[0x13])
                                                         = *(undefined1 *)
                                                            (iVar5 + 0x51 + param_1[0x13]);
                                                    *(undefined1 *)(iVar15 + 0x658 + param_1[0x13])
                                                         = *(undefined1 *)
                                                            (iVar5 + 0x50 + param_1[0x13]);
                                                    do {
                                                      uVar2 = AIPlay::targetType((AIPlay *)
                                                                                 (iVar5 + param_1[
                                                  0x13]),iVar4);
                                                  AIPlay::addTargetType
                                                            ((AIPlay *)(iVar18 + param_1[0x13]),
                                                             uVar2);
                                                  uVar2 = AIPlay::targetCharacteristic
                                                                    ((AIPlay *)
                                                                     (iVar5 + param_1[0x13]),iVar4);
                                                  AIPlay::addTargetCharacteristic
                                                            ((AIPlay *)(iVar18 + param_1[0x13]),
                                                             uVar2);
                                                  iVar4 = iVar4 + 1;
                                                  } while (iVar4 < 5);
                                                  iStack_3a0 = 0;
                                                  *(undefined1 *)(iVar15 + 0x65a + param_1[0x13]) =
                                                       *(undefined1 *)(iVar5 + 0x52 + param_1[0x13])
                                                  ;
                                                  do {
                                                    iVar4 = iStack_3a0;
                                                    pAStack_39c = (AIPlayPhase *)
                                                                  AIPlay::group((AIPlay *)
                                                                                (iVar5 + param_1[
                                                  0x13]),iStack_3a0);
                                                  pAStack_398 = AIPlay::group((AIPlay *)
                                                                              (iVar18 + param_1[0x13
                                                  ]),iVar4);
                                                  iVar4 = 0;
                                                  do {
                                                    bVar3 = AIPlayGroup::minimum
                                                                      ((AIPlayGroup *)pAStack_39c,
                                                                       iVar4);
                                                    AIPlayGroup::setMinimum
                                                              (pAStack_398,iVar4,(uint)bVar3);
                                                    bVar3 = AIPlayGroup::maximum
                                                                      ((AIPlayGroup *)pAStack_39c,
                                                                       iVar4);
                                                    AIPlayGroup::setMaximum
                                                              (pAStack_398,iVar4,(uint)bVar3);
                                                    iVar4 = iVar4 + 1;
                                                  } while (iVar4 < 6);
                                                  iStack_3a0 = iStack_3a0 + 1;
                                                  } while (iStack_3a0 < 5);
                                                  iStack_3a0 = 0;
                                                  do {
                                                    iVar4 = iStack_3a0;
                                                    pAStack_390 = (AIPlay *)
                                                                  AIPlay::phase((AIPlay *)
                                                                                (iVar5 + param_1[
                                                  0x13]),iStack_3a0);
                                                  pAStack_39c = AIPlay::phase((AIPlay *)
                                                                              (iVar18 + param_1[0x13
                                                  ]),iVar4);
                                                  pAStack_398 = (AIPlayGroup *)0x0;
                                                  do {
                                                    pAVar10 = AIPlayPhase::command
                                                                        ((AIPlayPhase *)pAStack_390,
                                                                         (int)pAStack_398);
                                                    if (pAVar10->typeValue == '\x01') {
                                                      XYZ::XYZ(&XStack_360,0,0,0);
                                                      XYZ::XYZ(&XStack_378);
                                                      XYZ::XYZ(&XStack_36c,pAVar10->value1Value,
                                                               pAVar10->value2Value,
                                                               pAVar10->value3Value);
                                                      XYZ::rotateXYByFacet
                                                                (&XStack_36c,&XStack_360,&XStack_378
                                                                 ,(uchar)iStack_388);
                                                      AIPlayPhaseCommand::AIPlayPhaseCommand
                                                                (&AStack_244,pAVar10->groupValue,
                                                                 pAVar10->typeValue,
                                                                 XStack_378.xValue,XStack_378.yValue
                                                                 ,XStack_378.zValue);
                                                      pAVar10 = &AStack_244;
                                                    }
                                                    AIPlayPhase::addCommand(pAStack_39c,pAVar10);
                                                    pAStack_398 = (AIPlayGroup *)
                                                                  (pAStack_398->minValue + 1);
                                                  } while ((int)pAStack_398 < 5);
                                                  iVar4 = 0;
                                                  do {
                                                    pAVar11 = AIPlayPhase::trigger
                                                                        ((AIPlayPhase *)pAStack_390,
                                                                         iVar4);
                                                    AIPlayPhase::addTrigger(pAStack_39c,pAVar11);
                                                    iVar4 = iVar4 + 1;
                                                  } while (iVar4 < 3);
                                                  iStack_3a0 = iStack_3a0 + 1;
                                                  } while (iStack_3a0 < 10);
                                                  iStack_388 = iStack_388 + 1;
                                                  iVar4 = iStack_394;
                                                  iVar15 = iVar18;
                                                  } while (iStack_388 < 8);
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
        } while (iVar4 < 16000);
        fclose(iStack_37c);
        uVar12 = 1;
        goto LAB_0041131a;
      }
    }
  }
  uVar12 = 0;
LAB_0041131a:
  *unaff_FS_OFFSET = iStack_c;
  return uVar12;
}

// --------------------------------------------------

