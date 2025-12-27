// Class: TRIBE_Dialog_List
// Function: TRIBE_Dialog_List
// Address: 0050b450
/* public: __thiscall TRIBE_Dialog_List::TRIBE_Dialog_List(char *) */

TRIBE_Dialog_List * __thiscall
TRIBE_Dialog_List::TRIBE_Dialog_List(TRIBE_Dialog_List *this,char *param_1)
{
  RGE_Dialog_List::RGE_Dialog_List((RGE_Dialog_List *)this,param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0050b470
/* public: virtual void * __thiscall TRIBE_Dialog_List::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Dialog_List::_scalar_deleting_destructor_(TRIBE_Dialog_List *this,uint param_1)
{
  ~TRIBE_Dialog_List(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Dialog_List
// Address: 0050b490
/* public: virtual __thiscall TRIBE_Dialog_List::~TRIBE_Dialog_List(void) */

void __thiscall TRIBE_Dialog_List::~TRIBE_Dialog_List(TRIBE_Dialog_List *this)
{
  int iVar1;
  int iVar2;
  
  *(undefined ***)this = &RGE_Dialog_List::_vftable_;
  if (*(int *)&this->field_0x4b8 != 0) {
    iVar2 = 0;
    if (0 < *(short *)&this->field_0x4b0) {
      do {
        iVar1 = *(int *)(*(int *)&this->field_0x4b8 + iVar2 * 4);
        if (iVar1 != 0) {
          free(iVar1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(short *)&this->field_0x4b0);
    }
    free(*(undefined4 *)&this->field_0x4b8);
    *(undefined4 *)&this->field_0x4b8 = 0;
  }
  if (*(int *)&this->field_0x4b4 != 0) {
    free(*(int *)&this->field_0x4b4);
    *(undefined4 *)&this->field_0x4b4 = 0;
  }
  TListDialog::~TListDialog((TListDialog *)this);
  return;
}

// --------------------------------------------------

// Function: create_list
// Address: 0050b4a0
/* protected: virtual int __thiscall TRIBE_Dialog_List::create_list(void) */

int __thiscall TRIBE_Dialog_List::create_list(TRIBE_Dialog_List *this)
{
  int iVar1;
  
  iVar1 = *(int *)&this->field_0x4ac;
  if (iVar1 == 100) {
    iVar1 = create_build_list(this);
    return iVar1;
  }
  if (iVar1 != 0x65) {
    if (iVar1 != 0x66) {
      iVar1 = RGE_Dialog_List::create_list((RGE_Dialog_List *)this);
      return iVar1;
    }
    iVar1 = create_research_list(this);
    return iVar1;
  }
  iVar1 = create_train_list(this);
  return iVar1;
}

// --------------------------------------------------

// Function: create_build_list
// Address: 0050b4d0
/* WARNING: Variable defined which should be unmapped: item_list */
/* protected: int __thiscall TRIBE_Dialog_List::create_build_list(void) */

int __thiscall TRIBE_Dialog_List::create_build_list(TRIBE_Dialog_List *this)
{
  char cVar1;
  short sVar2;
  TRIBE_Player *this_00;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  char *pcVar7;
  char *pcVar8;
  Item_Avail *item_list;
  short item_num;
  short local_8 [4];
  
  this_00 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
  sVar6 = 0;
  if (this_00 == (TRIBE_Player *)0x0) {
    return 0;
  }
  iVar3 = RGE_Player::is_group_selected((RGE_Player *)this_00,4);
  if (iVar3 == 0) {
    return 0;
  }
                    /* language.dll match for 0x76: "B" */
  _item_num = (Item_Avail *)0x0;
  local_8[0] = 0;
  local_8[1] = 0;
  TRIBE_Player::interface_item_avail(this_00,(Item_Avail **)&item_num,local_8,0x76);
  sVar2 = (short)local_8._0_4_;
  if (sVar2 == 0) {
    return 0;
  }
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
  *(short *)&this->field_0x4b0 = sVar2;
  iVar3 = calloc((int)sVar2,0x66);
  *(int *)&this->field_0x4b4 = iVar3;
  if (iVar3 == 0) {
    return 0;
  }
  if (0 < *(short *)&this->field_0x4b0) {
    do {
      iVar3 = (int)sVar6;
      *(short *)(*(int *)&this->field_0x4b4 + 100 + iVar3 * 0x66) = _item_num[iVar3].id;
      uVar4 = 0xffffffff;
      pcVar7 = _item_num[iVar3].name;
      do {
        pcVar8 = pcVar7;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar8 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar8;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar7 = pcVar8 + -uVar4;
      pcVar8 = (char *)(*(int *)&this->field_0x4b4 + iVar3 * 0x66);
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar8 = pcVar8 + 4;
      }
      sVar6 = sVar6 + 1;
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      }
    } while (sVar6 < *(short *)&this->field_0x4b0);
  }
  return 1;
}

// --------------------------------------------------

// Function: create_train_list
// Address: 0050b5e0
/* WARNING: Variable defined which should be unmapped: item_list */
/* protected: int __thiscall TRIBE_Dialog_List::create_train_list(void) */

int __thiscall TRIBE_Dialog_List::create_train_list(TRIBE_Dialog_List *this)
{
  char cVar1;
  short sVar2;
  TRIBE_Player *this_00;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  char *pcVar7;
  char *pcVar8;
  Item_Avail *item_list;
  short item_num;
  short local_8 [4];
  
  this_00 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
  sVar6 = 0;
  if ((this_00 != (TRIBE_Player *)0x0) && (this_00->_padding_ != 0)) {
    iVar3 = RGE_Player::own_selected((RGE_Player *)this_00);
    if (iVar3 != 0) {
      _item_num = (Item_Avail *)0x0;
      local_8[0] = 0;
      local_8[1] = 0;
      TRIBE_Player::interface_item_avail
                (this_00,(Item_Avail **)&item_num,local_8,
                 *(short *)(*(int *)(this_00->_padding_ + 8) + 0x10));
      sVar2 = (short)local_8._0_4_;
      if (sVar2 != 0) {
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
        *(short *)&this->field_0x4b0 = sVar2;
        iVar3 = calloc((int)sVar2,0x66);
        *(int *)&this->field_0x4b4 = iVar3;
        if (iVar3 != 0) {
          if (0 < *(short *)&this->field_0x4b0) {
            do {
              iVar3 = (int)sVar6;
              *(short *)(*(int *)&this->field_0x4b4 + 100 + iVar3 * 0x66) = _item_num[iVar3].id;
              uVar4 = 0xffffffff;
              pcVar7 = _item_num[iVar3].name;
              do {
                pcVar8 = pcVar7;
                if (uVar4 == 0) break;
                uVar4 = uVar4 - 1;
                pcVar8 = pcVar7 + 1;
                cVar1 = *pcVar7;
                pcVar7 = pcVar8;
              } while (cVar1 != '\0');
              uVar4 = ~uVar4;
              pcVar7 = pcVar8 + -uVar4;
              pcVar8 = (char *)(*(int *)&this->field_0x4b4 + iVar3 * 0x66);
              for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
                pcVar7 = pcVar7 + 4;
                pcVar8 = pcVar8 + 4;
              }
              sVar6 = sVar6 + 1;
              for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                *pcVar8 = *pcVar7;
                pcVar7 = pcVar7 + 1;
                pcVar8 = pcVar8 + 1;
              }
            } while (sVar6 < *(short *)&this->field_0x4b0);
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: create_research_list
// Address: 0050b700
/* WARNING: Variable defined which should be unmapped: item_list */
/* protected: int __thiscall TRIBE_Dialog_List::create_research_list(void) */

int __thiscall TRIBE_Dialog_List::create_research_list(TRIBE_Dialog_List *this)
{
  char cVar1;
  short sVar2;
  TRIBE_Player *this_00;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  char *pcVar7;
  char *pcVar8;
  Item_Avail *item_list;
  short item_num;
  short local_8 [4];
  
  this_00 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
  sVar6 = 0;
  if ((this_00 != (TRIBE_Player *)0x0) && (this_00->_padding_ != 0)) {
    iVar3 = RGE_Player::own_selected((RGE_Player *)this_00);
    if (iVar3 != 0) {
      _item_num = (Item_Avail *)0x0;
      local_8[0] = 0;
      local_8[1] = 0;
      TRIBE_Player::interface_tech_avail
                (this_00,(Item_Avail **)&item_num,local_8,
                 *(short *)(*(int *)(this_00->_padding_ + 8) + 0x10));
      sVar2 = (short)local_8._0_4_;
      if (sVar2 != 0) {
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
        *(short *)&this->field_0x4b0 = sVar2;
        iVar3 = calloc((int)sVar2,0x66);
        *(int *)&this->field_0x4b4 = iVar3;
        if (iVar3 != 0) {
          if (0 < *(short *)&this->field_0x4b0) {
            do {
              iVar3 = (int)sVar6;
              *(short *)(*(int *)&this->field_0x4b4 + 100 + iVar3 * 0x66) = _item_num[iVar3].id;
              uVar4 = 0xffffffff;
              pcVar7 = _item_num[iVar3].name;
              do {
                pcVar8 = pcVar7;
                if (uVar4 == 0) break;
                uVar4 = uVar4 - 1;
                pcVar8 = pcVar7 + 1;
                cVar1 = *pcVar7;
                pcVar7 = pcVar8;
              } while (cVar1 != '\0');
              uVar4 = ~uVar4;
              pcVar7 = pcVar8 + -uVar4;
              pcVar8 = (char *)(*(int *)&this->field_0x4b4 + iVar3 * 0x66);
              for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
                pcVar7 = pcVar7 + 4;
                pcVar8 = pcVar8 + 4;
              }
              sVar6 = sVar6 + 1;
              for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                *pcVar8 = *pcVar7;
                pcVar7 = pcVar7 + 1;
                pcVar8 = pcVar8 + 1;
              }
            } while (sVar6 < *(short *)&this->field_0x4b0);
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: get_cur_id
// Address: 0050b820
/* protected: virtual short __thiscall TRIBE_Dialog_List::get_cur_id(void) */

short __thiscall TRIBE_Dialog_List::get_cur_id(TRIBE_Dialog_List *this)
{
  int iVar1;
  short sVar2;
  
  iVar1 = *(int *)&this->field_0x4ac;
  if (((iVar1 != 100) && (iVar1 != 0x65)) && (iVar1 != 0x66)) {
    sVar2 = RGE_Dialog_List::get_cur_id((RGE_Dialog_List *)this);
    return sVar2;
  }
  return -1;
}

// --------------------------------------------------

