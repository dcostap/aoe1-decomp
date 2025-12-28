// Class: RGE_Effects
// Size:  0xC
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] save
// [02] do_effect
//
// Member Layout:
// [0x004] RGE_Effect * effects
// [0x008] long effect_num
// ----------------------------------------------------------------

// Function: RGE_Effects
// Address: 004490e0
/* public: __thiscall RGE_Effects::RGE_Effects(int) */

RGE_Effects * __thiscall RGE_Effects::RGE_Effects(RGE_Effects *this,int param_1)
{
  long *plVar1;
  char *pcVar2;
  int iVar3;
  RGE_Effect *pRVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int index;
  int local_10;
  
  iVar3 = param_1;
  plVar1 = &this->effect_num;
  this->_padding_ = (int)&_vftable_;
  rge_read(param_1,plVar1,4);
  if (*plVar1 < 1) {
    this->effects = (RGE_Effect *)0x0;
    *plVar1 = 0;
  }
  else {
    pRVar4 = (RGE_Effect *)calloc(*plVar1,0x2c);
    this->effects = pRVar4;
    local_10 = 0;
    if (0 < *plVar1) {
      index = 0;
      do {
        pRVar4 = this->effects;
        rge_read(iVar3,pRVar4->name,0x1f);
        pcVar2 = pRVar4->name + index + 0x22;
        rge_read(iVar3,pcVar2,2);
        if (*(short *)pcVar2 < 1) {
          pcVar2 = pRVar4->name + index + 0x26;
          pcVar2[0] = '\0';
          pcVar2[1] = '\0';
          pcVar2[2] = '\0';
          pcVar2[3] = '\0';
        }
        else {
          iVar5 = calloc((int)*(short *)pcVar2,0xc);
          iVar6 = 0;
          *(int *)(pRVar4->name + index + 0x26) = iVar5;
          if (0 < *(short *)pcVar2) {
            param_1 = 0;
            do {
              pvVar7 = (void *)(*(int *)(pRVar4->name + index + 0x26) + param_1);
              rge_read(iVar3,pvVar7,1);
              rge_read(iVar3,(void *)((int)pvVar7 + 2),2);
              rge_read(iVar3,(void *)((int)pvVar7 + 4),2);
              rge_read(iVar3,(void *)((int)pvVar7 + 6),2);
              rge_read(iVar3,(void *)((int)pvVar7 + 8),4);
              iVar6 = iVar6 + 1;
              param_1 = param_1 + 0xc;
            } while (iVar6 < *(short *)pcVar2);
          }
        }
        local_10 = local_10 + 1;
        index = index + 0x2c;
      } while (local_10 < *plVar1);
      return this;
    }
  }
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00449240
/* public: virtual void * __thiscall RGE_Effects::`vector deleting destructor'(unsigned int) */

void * __thiscall RGE_Effects::_vector_deleting_destructor_(RGE_Effects *this,uint param_1)
{
  ~RGE_Effects(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Effects
// Address: 00449260
// [HELPER] s__d: "%d"
// [HELPER] s__d__d: "%d+%d"
// [HELPER] s__hd__hd__hd__hd__f: "%hd %hd %hd %hd %f"
// [HELPER] s__s__hd: "%s %hd"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: this_effect_num */
/* public: __thiscall RGE_Effects::RGE_Effects(char *) */

RGE_Effects * __thiscall RGE_Effects::RGE_Effects(RGE_Effects *this,char *param_1)
{
  long *plVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  RGE_Effect *pRVar5;
  RGE_Effect_Command *pRVar6;
  short sVar7;
  long this_effect_num;
  long index;
  long count;
  int local_4;
  
  this->_padding_ = (int)&_vftable_;
  iVar3 = fopen(param_1,s_r);
  if (iVar3 == 0) {
    this->effect_num = 0;
    this->effects = (RGE_Effect *)0x0;
    return this;
  }
  plVar1 = &this->effect_num;
  iVar4 = fscanf(iVar3,s__d__d,plVar1,&local_4);
  if (iVar4 == -1) {
    *plVar1 = 0;
    this->effects = (RGE_Effect *)0x0;
  }
  else {
    pRVar5 = (RGE_Effect *)calloc(*plVar1,0x2c);
    this->effects = pRVar5;
    count = 0;
    if (0 < local_4) {
      while( true ) {
        sVar7 = 0;
        fscanf(iVar3,&s__d,&index);
        iVar4 = fscanf(iVar3,s__s__hd,this->effects[index].name,
                       &this->effects[index].effect_list_num);
        if (iVar4 == -1) break;
        this->effects[index].id = (short)index;
        sVar2 = this->effects[index].effect_list_num;
        if (sVar2 < 1) {
          this->effects[index].effect_list = (RGE_Effect_Command *)0x0;
        }
        else {
          pRVar6 = (RGE_Effect_Command *)calloc((int)sVar2,0xc);
          this->effects[index].effect_list = pRVar6;
          pRVar5 = this->effects + index;
          if (0 < this->effects[index].effect_list_num) {
            do {
              pRVar6 = pRVar5->effect_list + sVar7;
              iVar4 = fscanf(iVar3,s__hd__hd__hd__hd__f,&param_1,&pRVar6->change_num1,
                             &pRVar6->change_num2,&pRVar6->change_num3,&pRVar6->change_amount);
              if (iVar4 == -1) break;
              sVar7 = sVar7 + 1;
              pRVar6->command = (uchar)param_1;
              pRVar5 = this->effects + index;
            } while (sVar7 < this->effects[index].effect_list_num);
          }
        }
        convert_us(this->effects[index].name);
        count = count + 1;
        if (local_4 <= count) {
          fclose(iVar3);
          return this;
        }
      }
    }
  }
  fclose(iVar3);
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Effects
// Address: 00449440
/* public: virtual __thiscall RGE_Effects::~RGE_Effects(void) */

void __thiscall RGE_Effects::~RGE_Effects(RGE_Effects *this)
{
  RGE_Effect_Command *pRVar1;
  int iVar2;
  short sVar3;
  
  sVar3 = 0;
  this->_padding_ = (int)&_vftable_;
  if (0 < this->effect_num) {
    iVar2 = 0;
    do {
      pRVar1 = this->effects[iVar2].effect_list;
      if (pRVar1 != (RGE_Effect_Command *)0x0) {
        free(pRVar1);
      }
      sVar3 = sVar3 + 1;
      this->effects[iVar2].effect_list = (RGE_Effect_Command *)0x0;
      iVar2 = (int)sVar3;
    } while (iVar2 < this->effect_num);
  }
  if (this->effects != (RGE_Effect *)0x0) {
    free(this->effects);
    this->effects = (RGE_Effect *)0x0;
  }
  this->effect_num = 0;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004494b0
/* WARNING: Variable defined which should be unmapped: index */
/* public: virtual void __thiscall RGE_Effects::save(int) */

void __thiscall RGE_Effects::save(RGE_Effects *this,int param_1)
{
  long *plVar1;
  char *pcVar2;
  RGE_Effect *pRVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int index;
  int local_14;
  
  iVar4 = param_1;
  plVar1 = &this->effect_num;
  rge_write(param_1,plVar1,4);
  local_14 = 0;
  if (0 < *plVar1) {
    param_1 = 0;
    do {
      pRVar3 = this->effects;
      rge_write(iVar4,pRVar3->name,0x1f);
      pcVar2 = pRVar3->name + param_1 + 0x22;
      rge_write(iVar4,pcVar2,2);
      iVar5 = 0;
      if (0 < *(short *)pcVar2) {
        iVar6 = 0;
        do {
          pvVar7 = (void *)(*(int *)(pRVar3->name + param_1 + 0x26) + iVar6);
          rge_write(iVar4,pvVar7,1);
          rge_write(iVar4,(void *)((int)pvVar7 + 2),2);
          rge_write(iVar4,(void *)((int)pvVar7 + 4),2);
          rge_write(iVar4,(void *)((int)pvVar7 + 6),2);
          rge_write(iVar4,(void *)((int)pvVar7 + 8),4);
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0xc;
        } while (iVar5 < *(short *)pcVar2);
      }
      local_14 = local_14 + 1;
      param_1 = param_1 + 0x2c;
    } while (local_14 < *plVar1);
  }
  return;
}

// --------------------------------------------------

// Function: do_effect
// Address: 004495c0
/* public: virtual void __thiscall RGE_Effects::do_effect(short,class RGE_Player *) */

void __thiscall RGE_Effects::do_effect(RGE_Effects *this,short param_1,RGE_Player *param_2)
{
  RGE_Effect *pRVar1;
  short sVar2;
  RGE_Effect_Command *pRVar3;
  short sVar4;
  
  if ((((int)param_1 < this->effect_num) &&
      (pRVar1 = this->effects + param_1, pRVar1 != (RGE_Effect *)0x0)) &&
     (sVar4 = 0, 0 < pRVar1->effect_list_num)) {
    do {
      pRVar3 = pRVar1->effect_list;
      switch(pRVar3[sVar4].command) {
      case '\0':
        RGE_Player::modify_tobj
                  (param_2,pRVar3[sVar4].change_num1,pRVar3[sVar4].change_num2,
                   pRVar3[sVar4].change_amount,(uchar)pRVar3[sVar4].change_num3);
        break;
      case '\x01':
        sVar2 = pRVar3[sVar4].change_num1;
        if (-1 < sVar2) {
          if (pRVar3[sVar4].change_num2 == 0) {
            RGE_Player::new_attribute_num(param_2,sVar2,pRVar3[sVar4].change_amount);
          }
          else {
            (**(code **)(param_2->_padding_ + 0x78))(sVar2,pRVar3[sVar4].change_amount,0);
          }
        }
        break;
      case '\x02':
        if (-1 < pRVar3[sVar4].change_num1) {
          RGE_Player::make_available
                    (param_2,pRVar3[sVar4].change_num1,(uchar)pRVar3[sVar4].change_num2);
        }
        break;
      case '\x03':
        RGE_Player::copy_obj(param_2,pRVar3[sVar4].change_num1,pRVar3[sVar4].change_num2);
        break;
      case '\x04':
        RGE_Player::modify_tobj_delta
                  (param_2,pRVar3[sVar4].change_num1,pRVar3[sVar4].change_num2,
                   pRVar3[sVar4].change_amount,(uchar)pRVar3[sVar4].change_num3);
        break;
      case '\x05':
        RGE_Player::modify_tobj_percent
                  (param_2,pRVar3[sVar4].change_num1,pRVar3[sVar4].change_num2,
                   pRVar3[sVar4].change_amount,(uchar)pRVar3[sVar4].change_num3);
      }
      sVar4 = sVar4 + 1;
    } while (sVar4 < pRVar1->effect_list_num);
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Effects
// Address: 0050d49e
void __thiscall RGE_Effects::~RGE_Effects(RGE_Effects *this)
{
  RGE_Effect_Command *pRVar1;
  int iVar2;
  short sVar3;
  
  sVar3 = 0;
  this->_padding_ = (int)&_vftable_;
  if (0 < this->effect_num) {
    iVar2 = 0;
    do {
      pRVar1 = this->effects[iVar2].effect_list;
      if (pRVar1 != (RGE_Effect_Command *)0x0) {
        free(pRVar1);
      }
      sVar3 = sVar3 + 1;
      this->effects[iVar2].effect_list = (RGE_Effect_Command *)0x0;
      iVar2 = (int)sVar3;
    } while (iVar2 < this->effect_num);
  }
  if (this->effects != (RGE_Effect *)0x0) {
    free(this->effects);
    this->effects = (RGE_Effect *)0x0;
  }
  this->effect_num = 0;
  return;
}

// --------------------------------------------------

