// Class: TRIBE_Effects
// Size:  0xC
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] save
// [02] do_effect
// [03] `vector_deleting_destructor'
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TRIBE_Effects
// Address: 0050d460
/* public: __thiscall TRIBE_Effects::TRIBE_Effects(int) */

TRIBE_Effects * __thiscall TRIBE_Effects::TRIBE_Effects(TRIBE_Effects *this,int param_1)
{
  RGE_Effects::RGE_Effects((RGE_Effects *)this,param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0050d480
/* public: virtual void * __thiscall TRIBE_Effects::`vector deleting destructor'(unsigned int) */

void * __thiscall TRIBE_Effects::_vector_deleting_destructor_(TRIBE_Effects *this,uint param_1)
{
  ~TRIBE_Effects(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Effects
// Address: 0050d4a0
/* public: virtual __thiscall TRIBE_Effects::~TRIBE_Effects(void) */

void __thiscall TRIBE_Effects::~TRIBE_Effects(TRIBE_Effects *this)
{
  int iVar1;
  int iVar2;
  short sVar3;
  
  sVar3 = 0;
  *(undefined ***)this = &RGE_Effects::_vftable_;
  if (0 < *(int *)&this->field_0x8) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(*(int *)&this->field_0x4 + 0x28 + iVar2 * 0x2c);
      if (iVar1 != 0) {
        free(iVar1);
      }
      sVar3 = sVar3 + 1;
      *(undefined4 *)(*(int *)&this->field_0x4 + 0x28 + iVar2 * 0x2c) = 0;
      iVar2 = (int)sVar3;
    } while (iVar2 < *(int *)&this->field_0x8);
  }
  if (*(int *)&this->field_0x4 != 0) {
    free(*(int *)&this->field_0x4);
    *(undefined4 *)&this->field_0x4 = 0;
  }
  *(undefined4 *)&this->field_0x8 = 0;
  return;
}

// --------------------------------------------------

// Function: TRIBE_Effects
// Address: 0050d4b0
/* public: __thiscall TRIBE_Effects::TRIBE_Effects(char *) */

TRIBE_Effects * __thiscall TRIBE_Effects::TRIBE_Effects(TRIBE_Effects *this,char *param_1)
{
  RGE_Effects::RGE_Effects((RGE_Effects *)this,param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: do_effect
// Address: 0050d4d0
/* public: virtual void __thiscall TRIBE_Effects::do_effect(short,class RGE_Player *) */

void __thiscall TRIBE_Effects::do_effect(TRIBE_Effects *this,short param_1,RGE_Player *param_2)
{
  int iVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  uchar uVar6;
  
  if (((int)param_1 < *(int *)&this->field_0x8) &&
     (iVar1 = *(int *)&this->field_0x4 + param_1 * 0x2c, iVar1 != 0)) {
    iVar4 = 0;
    if (0 < *(short *)(iVar1 + 0x24)) {
      iVar5 = 0;
      do {
        cVar2 = *(char *)(*(int *)(iVar1 + 0x28) + iVar5);
        if ((cVar2 != 'e') && (cVar2 == 'f')) {
          uVar6 = '\0';
          lVar3 = __ftol();
          TRIBE_Player::tech_abling((TRIBE_Player *)param_2,lVar3,uVar6);
        }
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0xc;
      } while (iVar4 < *(short *)(iVar1 + 0x24));
    }
    RGE_Effects::do_effect((RGE_Effects *)this,param_1,param_2);
  }
  return;
}

// --------------------------------------------------

// Function: do_tech_effect
// Address: 0050d550
/* public: void __thiscall TRIBE_Effects::do_tech_effect(short,class RGE_Player *) */

void __thiscall TRIBE_Effects::do_tech_effect(TRIBE_Effects *this,short param_1,RGE_Player *param_2)
{
  int iVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  uchar uVar6;
  
  iVar4 = 0;
  iVar1 = *(int *)&this->field_0x4 + param_1 * 0x2c;
  if (0 < *(short *)(*(int *)&this->field_0x4 + 0x24 + param_1 * 0x2c)) {
    iVar5 = 0;
    do {
      cVar2 = *(char *)(*(int *)(iVar1 + 0x28) + iVar5);
      if ((cVar2 != 'e') && (cVar2 == 'f')) {
        uVar6 = '\0';
        lVar3 = __ftol();
        TRIBE_Player::tech_abling((TRIBE_Player *)param_2,lVar3,uVar6);
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0xc;
    } while (iVar4 < *(short *)(iVar1 + 0x24));
  }
  return;
}

// --------------------------------------------------

