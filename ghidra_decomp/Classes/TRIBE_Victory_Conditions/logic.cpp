// Class: TRIBE_Victory_Conditions
// Function: TRIBE_Victory_Conditions
// Address: 0052c8f0
/* public: __thiscall TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(class RGE_Player *,int,long
   *,unsigned char) */

TRIBE_Victory_Conditions * __thiscall
TRIBE_Victory_Conditions::TRIBE_Victory_Conditions
          (TRIBE_Victory_Conditions *this,RGE_Player *param_1,int param_2,long *param_3,
          uchar param_4)
{
  RGE_Victory_Conditions::RGE_Victory_Conditions
            ((RGE_Victory_Conditions *)this,param_1,param_2,param_3,param_4);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Victory_Conditions
// Address: 0052c920
/* public: __thiscall TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(class RGE_Player *) */

TRIBE_Victory_Conditions * __thiscall
TRIBE_Victory_Conditions::TRIBE_Victory_Conditions
          (TRIBE_Victory_Conditions *this,RGE_Player *param_1)
{
  RGE_Victory_Conditions::RGE_Victory_Conditions((RGE_Victory_Conditions *)this,param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Victory_Conditions
// Address: 0052c940
/* public: __thiscall TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions(void) */

void __thiscall TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions(TRIBE_Victory_Conditions *this)
{
  *(undefined ***)this = &_vftable_;
  RGE_Victory_Conditions::~RGE_Victory_Conditions((RGE_Victory_Conditions *)this);
  return;
}

// --------------------------------------------------

// Function: handle_condition
// Address: 0052c950
/* public: virtual void __thiscall TRIBE_Victory_Conditions::handle_condition(struct
   RGE_Victory_Entry *) */

void __thiscall
TRIBE_Victory_Conditions::handle_condition
          (TRIBE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  if (param_1->command != 'd') {
    RGE_Victory_Conditions::handle_condition((RGE_Victory_Conditions *)this,param_1);
    return;
  }
  handle_tech(this,param_1);
  return;
}

// --------------------------------------------------

// Function: handle_tech
// Address: 0052c970
/* protected: void __thiscall TRIBE_Victory_Conditions::handle_tech(struct RGE_Victory_Entry *) */

void __thiscall
TRIBE_Victory_Conditions::handle_tech(TRIBE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  short sVar1;
  
  if ((*(int *)&this->field_0xc != 0) && (param_1->state == '\0')) {
    sVar1 = TRIBE_Player_Tech::get_tech_state
                      (*(TRIBE_Player_Tech **)(*(int *)&this->field_0xc + 0x220),
                       (short)param_1->count);
    if (sVar1 == 3) {
      param_1->state = '\x02';
    }
  }
  return;
}

// --------------------------------------------------

// Function: add_tech
// Address: 0052c9b0
/* public: unsigned char __thiscall TRIBE_Victory_Conditions::add_tech(unsigned char,long) */

uchar __thiscall
TRIBE_Victory_Conditions::add_tech(TRIBE_Victory_Conditions *this,uchar param_1,long param_2)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add((RGE_Victory_Conditions *)this,param_1,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = 'd';
    pRVar1->count = param_2;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

