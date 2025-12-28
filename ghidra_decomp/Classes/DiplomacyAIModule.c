// Class: DiplomacyAIModule
// Size:  0x150
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
// [15] save
// [16] `vector_deleting_destructor'
// [17] loggingHistory
// [18] setLogHistory
// [19] toggleLogHistory
// [20] setHistoryFilename
// [21] loggingCommonHistory
// [22] setLogCommonHistory
// [23] toggleLogCommonHistory
// [24] loadState
// [25] saveState
// [26] gleanState
// [27] processMessage
// [28] update
// [29] setCallbackMessage
// [30] filterOutMessage
// [31] save
// [32] `vector_deleting_destructor'
// [33] loggingHistory
// [34] setLogHistory
// [35] toggleLogHistory
// [36] setHistoryFilename
// [37] loggingCommonHistory
// [38] setLogCommonHistory
// [39] toggleLogCommonHistory
// [40] loadState
// [41] saveState
// [42] gleanState
// [43] processMessage
// [44] update
// [45] setCallbackMessage
// [46] filterOutMessage
//
// Member Layout:
// [0x0F0] MainDecisionAIModule * md
// [0x0F4] int[10] dislikeTable (sz: 0x28)
// [0x11C] int[10] likeTable (sz: 0x28)
// [0x144] uchar[10] changeableTable (sz: 0xA)
// ----------------------------------------------------------------

// Function: DiplomacyAIModule
// Address: 0040bec0
// [HELPER] s_Diplomacy_AI: "Diplomacy AI"
/* public: __thiscall DiplomacyAIModule::DiplomacyAIModule(void *,int) */

DiplomacyAIModule * __thiscall
DiplomacyAIModule::DiplomacyAIModule(DiplomacyAIModule *this,void *param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
                    /* language.dll match for 0x3eb: "Age of Empires Help" */
  AIModule::AIModule((AIModule *)this,s_Diplomacy_AI,0x3eb,param_2,param_1);
  iVar1 = 0;
  this->_padding_ = (int)&_vftable_;
  this->md = (MainDecisionAIModule *)0x0;
  piVar2 = this->likeTable;
  do {
    piVar2[-10] = 0x31;
    *piVar2 = 0x31;
    this->changeableTable[iVar1] = '\x01';
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 10);
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0040bf20
/* public: virtual void * __thiscall DiplomacyAIModule::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
DiplomacyAIModule::_scalar_deleting_destructor_(DiplomacyAIModule *this,uint param_1)
{
  ~DiplomacyAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: DiplomacyAIModule
// Address: 0040bf40
// [HELPER] s_Diplomacy_AI: "Diplomacy AI"
/* public: __thiscall DiplomacyAIModule::DiplomacyAIModule(int,int) */

DiplomacyAIModule * __thiscall
DiplomacyAIModule::DiplomacyAIModule(DiplomacyAIModule *this,int param_1,int param_2)
{
  uchar *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c5f8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
                    /* language.dll match for 0x3eb: "Age of Empires Help" */
  AIModule::AIModule((AIModule *)this,s_Diplomacy_AI,0x3eb,param_1,(void *)0x0);
  local_4 = 0;
  this->md = (MainDecisionAIModule *)0x0;
  this->_padding_ = (int)&_vftable_;
  puVar1 = this->changeableTable;
  piVar3 = this->likeTable;
  iVar2 = 10;
  do {
    rge_read(param_2,piVar3 + -10,4);
    rge_read(param_2,piVar3,4);
    rge_read(param_2,puVar1,1);
    piVar3 = piVar3 + 1;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~DiplomacyAIModule
// Address: 0040bff0
/* public: virtual __thiscall DiplomacyAIModule::~DiplomacyAIModule(void) */

void __thiscall DiplomacyAIModule::~DiplomacyAIModule(DiplomacyAIModule *this)
{
  this->_padding_ = (int)&_vftable_;
  AIModule::~AIModule((AIModule *)this);
  return;
}

// --------------------------------------------------

// Function: setMainDecisionAI
// Address: 0040c000
/* public: void __thiscall DiplomacyAIModule::setMainDecisionAI(class MainDecisionAIModule *) */

void __thiscall
DiplomacyAIModule::setMainDecisionAI(DiplomacyAIModule *this,MainDecisionAIModule *param_1)
{
  this->md = param_1;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 0040c010
/* public: virtual int __thiscall DiplomacyAIModule::update(int) */

int __thiscall DiplomacyAIModule::update(DiplomacyAIModule *this,int param_1)
{
  RGE_Player *pRVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  pRVar1 = this->md->player;
  if (1 < pRVar1->world->player_num) {
    do {
      if (iVar3 != pRVar1->id) {
        iVar2 = isAlly(this,iVar3);
        if (iVar2 != 0) {
          iVar2 = isAlliedWithMe(this,iVar3);
          if (iVar2 == 0) {
            changeStance(this,iVar3,0,1);
          }
        }
        iVar2 = isAlly(this,iVar3);
        if (iVar2 == 0) {
          iVar2 = isAlliedWithMe(this,iVar3);
          if (iVar2 != 0) {
            changeStance(this,iVar3,2,1);
          }
        }
      }
      iVar3 = iVar3 + 1;
      pRVar1 = this->md->player;
    } while (iVar3 < pRVar1->world->player_num);
  }
  return 1;
}

// --------------------------------------------------

// Function: save
// Address: 0040c0a0
/* public: virtual int __thiscall DiplomacyAIModule::save(int) */

int __thiscall DiplomacyAIModule::save(DiplomacyAIModule *this,int param_1)
{
  uchar *puVar1;
  int iVar2;
  int *piVar3;
  
  puVar1 = this->changeableTable;
  piVar3 = this->likeTable;
  iVar2 = 10;
  do {
    rge_write(param_1,piVar3 + -10,4);
    rge_write(param_1,piVar3,4);
    rge_write(param_1,puVar1,1);
    piVar3 = piVar3 + 1;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 1;
}

// --------------------------------------------------

// Function: stance
// Address: 0040c100
/* public: int __thiscall DiplomacyAIModule::stance(int,int)const  */

int __thiscall DiplomacyAIModule::stance(DiplomacyAIModule *this,int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  if ((0 < param_1) && (param_1 < this->md->player->world->player_num)) {
    if (param_2 == 0) {
      return this->dislikeTable[param_1];
    }
    if (param_2 == 1) {
      iVar2 = 0x31 - this->dislikeTable[param_1];
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      iVar1 = 0x31 - this->likeTable[param_1];
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
      iVar1 = (100 - iVar2) - iVar1;
      if (-1 < iVar1) {
        return iVar1;
      }
      return 0;
    }
    if (param_2 == 2) {
      return this->likeTable[param_1];
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: changeStance
// Address: 0040c190
/* public: void __thiscall DiplomacyAIModule::changeStance(int,int,int) */

void __thiscall
DiplomacyAIModule::changeStance(DiplomacyAIModule *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  
  if ((0 < param_1) && (param_1 < this->md->player->world->player_num)) {
    if (param_2 == 0) {
      iVar1 = this->dislikeTable[param_1] + param_3;
      this->dislikeTable[param_1] = iVar1;
      if (this->changeableTable[param_1] == '\0') {
        if (iVar1 < 0x32) {
          this->dislikeTable[param_1] = 0x32;
          return;
        }
        if (100 < iVar1) {
          this->dislikeTable[param_1] = 100;
        }
      }
      else {
        if (iVar1 < 0) {
          this->dislikeTable[param_1] = 0;
          return;
        }
        if (100 < iVar1) {
          this->dislikeTable[param_1] = 100;
          return;
        }
      }
    }
    else if (param_2 == 2) {
      iVar1 = this->likeTable[param_1] + param_3;
      this->likeTable[param_1] = iVar1;
      if (this->changeableTable[param_1] == '\0') {
        if (iVar1 < 0) {
          this->likeTable[param_1] = 0;
          return;
        }
        if (0x30 < iVar1) {
          this->likeTable[param_1] = 0x30;
          return;
        }
      }
      else {
        if (iVar1 < 0) {
          this->likeTable[param_1] = 0;
          return;
        }
        if (100 < iVar1) {
          this->likeTable[param_1] = 100;
          return;
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: setStance
// Address: 0040c2b0
/* public: void __thiscall DiplomacyAIModule::setStance(int,int,int) */

void __thiscall
DiplomacyAIModule::setStance(DiplomacyAIModule *this,int param_1,int param_2,int param_3)
{
  if ((0 < param_1) && (param_1 < this->md->player->world->player_num)) {
    if (param_2 == 0) {
      this->dislikeTable[param_1] = param_3;
      if (this->changeableTable[param_1] == '\0') {
        if (param_3 < 0x32) {
          this->dislikeTable[param_1] = 0x32;
          return;
        }
        if (100 < param_3) {
          this->dislikeTable[param_1] = 100;
        }
      }
      else {
        if (param_3 < 0) {
          this->dislikeTable[param_1] = 0;
          return;
        }
        if (100 < param_3) {
          this->dislikeTable[param_1] = 100;
          return;
        }
      }
    }
    else if (param_2 == 2) {
      this->likeTable[param_1] = param_3;
      if (this->changeableTable[param_1] == '\0') {
        if (param_3 < 0) {
          this->likeTable[param_1] = 0;
          return;
        }
        if (0x30 < param_3) {
          this->likeTable[param_1] = 0x30;
          return;
        }
      }
      else {
        if (param_3 < 0) {
          this->likeTable[param_1] = 0;
          return;
        }
        if (100 < param_3) {
          this->likeTable[param_1] = 100;
          return;
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: isDisliked
// Address: 0040c3b0
/* public: int __thiscall DiplomacyAIModule::isDisliked(int)const  */

int __thiscall DiplomacyAIModule::isDisliked(DiplomacyAIModule *this,int param_1)
{
  if (((0 < param_1) && (param_1 < this->md->player->world->player_num)) &&
     (0x31 < this->dislikeTable[param_1])) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: isAmbivalent
// Address: 0040c3f0
/* public: int __thiscall DiplomacyAIModule::isAmbivalent(int)const  */

int __thiscall DiplomacyAIModule::isAmbivalent(DiplomacyAIModule *this,int param_1)
{
  int iVar1;
  
  iVar1 = isDisliked(this,param_1);
  if (iVar1 == 0) {
    iVar1 = isLiked(this,param_1);
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: isLiked
// Address: 0040c420
/* public: int __thiscall DiplomacyAIModule::isLiked(int)const  */

int __thiscall DiplomacyAIModule::isLiked(DiplomacyAIModule *this,int param_1)
{
  if (((0 < param_1) && (param_1 < this->md->player->world->player_num)) &&
     (0x31 < this->likeTable[param_1])) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: isChangeable
// Address: 0040c460
/* public: int __thiscall DiplomacyAIModule::isChangeable(int)const  */

int __thiscall DiplomacyAIModule::isChangeable(DiplomacyAIModule *this,int param_1)
{
  if (((0 < param_1) && (param_1 < this->md->player->world->player_num)) &&
     (this->changeableTable[param_1] == '\x01')) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: setChangeable
// Address: 0040c4a0
/* public: void __thiscall DiplomacyAIModule::setChangeable(int,unsigned char) */

void __thiscall DiplomacyAIModule::setChangeable(DiplomacyAIModule *this,int param_1,uchar param_2)
{
  if ((0 < param_1) && (param_1 < this->md->player->world->player_num)) {
    this->changeableTable[param_1] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: mostHated
// Address: 0040c4d0
/* WARNING: Variable defined which should be unmapped: highestValue */
/* public: int __thiscall DiplomacyAIModule::mostHated(int,int,int,int)const  */

int __thiscall
DiplomacyAIModule::mostHated
          (DiplomacyAIModule *this,int param_1,int param_2,int param_3,int param_4)
{
  RGE_Game_World *pRVar1;
  int iVar2;
  long lVar3;
  RGE_Player *pRVar4;
  int *piVar5;
  int iVar6;
  int highestValue;
  int highest;
  int local_4;
  
  local_4 = -1;
  highest = -1;
  iVar6 = 1;
  pRVar4 = this->md->player;
  pRVar1 = pRVar4->world;
  if (1 < pRVar1->player_num) {
    piVar5 = this->dislikeTable;
    do {
      piVar5 = piVar5 + 1;
      if (((iVar6 != pRVar4->id) && (pRVar1->players[iVar6]->game_status != '\x02')) &&
         ((param_1 < 1 || ((param_2 != iVar6 || (iVar2 = isAlly(this,iVar6), iVar2 == 0)))))) {
        lVar3 = RGE_Victory_Conditions::get_victory_points
                          (this->md->player->world->players[iVar6]->victory_conditions);
        iVar2 = *piVar5;
        if (1 < param_4) {
          if (param_3 == 1) {
            iVar2 = iVar2 + lVar3 / param_4;
          }
          else {
            iVar2 = iVar2 - lVar3 / param_4;
          }
        }
        if (highest < iVar2) {
          highest = iVar2;
          local_4 = iVar6;
        }
      }
      iVar6 = iVar6 + 1;
      pRVar4 = this->md->player;
      pRVar1 = pRVar4->world;
    } while (iVar6 < pRVar1->player_num);
  }
  return local_4;
}

// --------------------------------------------------

// Function: mostLiked
// Address: 0040c5b0
/* WARNING: Variable defined which should be unmapped: highest */
/* public: int __thiscall DiplomacyAIModule::mostLiked(int,int)const  */

int __thiscall DiplomacyAIModule::mostLiked(DiplomacyAIModule *this,int param_1,int param_2)
{
  RGE_Game_World *pRVar1;
  int iVar2;
  RGE_Player *pRVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int highest;
  int local_8;
  
  iVar5 = 1;
  iVar4 = -1;
  local_8 = -1;
  pRVar3 = this->md->player;
  pRVar1 = pRVar3->world;
  if (1 < pRVar1->player_num) {
    piVar6 = this->likeTable;
    do {
      piVar6 = piVar6 + 1;
      if ((((iVar5 != pRVar3->id) &&
           (*(char *)(*(int *)((int)pRVar1->players + (-0x11c - (int)this) + (int)piVar6) + 0x80) !=
            '\x02')) &&
          ((param_1 < 1 || ((param_2 != iVar5 || (iVar2 = isEnemy(this,iVar5), iVar2 == 0)))))) &&
         (iVar4 < *piVar6)) {
        iVar4 = *piVar6;
        local_8 = iVar5;
      }
      iVar5 = iVar5 + 1;
      pRVar3 = this->md->player;
      pRVar1 = pRVar3->world;
    } while (iVar5 < pRVar1->player_num);
  }
  return local_8;
}

// --------------------------------------------------

// Function: isEnemy
// Address: 0040c660
/* public: int __thiscall DiplomacyAIModule::isEnemy(int)const  */

int __thiscall DiplomacyAIModule::isEnemy(DiplomacyAIModule *this,int param_1)
{
  RGE_Player *pRVar1;
  
  if ((((0 < param_1) && (pRVar1 = this->md->player, param_1 <= pRVar1->world->player_num)) &&
      (param_1 != pRVar1->id)) && (pRVar1->relations[param_1] == '\x03')) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: isNeutral
// Address: 0040c6a0
/* public: int __thiscall DiplomacyAIModule::isNeutral(int)const  */

int __thiscall DiplomacyAIModule::isNeutral(DiplomacyAIModule *this,int param_1)
{
  RGE_Player *pRVar1;
  
  if ((((0 < param_1) && (pRVar1 = this->md->player, param_1 <= pRVar1->world->player_num)) &&
      (param_1 != pRVar1->id)) && (pRVar1->relations[param_1] == '\x01')) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: isAlly
// Address: 0040c6e0
/* public: int __thiscall DiplomacyAIModule::isAlly(int)const  */

int __thiscall DiplomacyAIModule::isAlly(DiplomacyAIModule *this,int param_1)
{
  RGE_Player *pRVar1;
  
  pRVar1 = this->md->player;
  if (param_1 == pRVar1->id) {
    return 1;
  }
  if (((0 < param_1) && (param_1 <= pRVar1->world->player_num)) &&
     (pRVar1->relations[param_1] == '\0')) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: isAlliedWithMe
// Address: 0040c730
/* public: int __thiscall DiplomacyAIModule::isAlliedWithMe(int)const  */

int __thiscall DiplomacyAIModule::isAlliedWithMe(DiplomacyAIModule *this,int param_1)
{
  RGE_Player *pRVar1;
  RGE_Game_World *pRVar2;
  RGE_Player *pRVar3;
  int iVar4;
  
  if (0 < param_1) {
    pRVar1 = this->md->player;
    pRVar2 = pRVar1->world;
    if ((param_1 < pRVar2->player_num) &&
       (pRVar3 = pRVar2->players[param_1], pRVar3 != (RGE_Player *)0x0)) {
      iVar4 = (**(code **)(pRVar3->_padding_ + 0x1c))((int)pRVar1->id);
      if (iVar4 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: setRelation
// Address: 0040c780
/* public: void __thiscall DiplomacyAIModule::setRelation(int,int) */

void __thiscall DiplomacyAIModule::setRelation(DiplomacyAIModule *this,int param_1,int param_2)
{
  RGE_Player *pRVar1;
  
  if (((0 < param_1) && (pRVar1 = this->md->player, param_1 < pRVar1->world->player_num)) &&
     (this->changeableTable[param_1] != '\0')) {
    (**(code **)(pRVar1->_padding_ + 0x28))(param_1,param_2);
  }
  return;
}

// --------------------------------------------------

