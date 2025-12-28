// Class: AIPlayGroup
// Size:  0xC
//
// Member Layout:
// [0x000] uchar[6] minValue (sz: 0x6)
// [0x006] uchar[6] maxValue (sz: 0x6)
// ----------------------------------------------------------------

// Function: AIPlayGroup
// Address: 0040f230
/* public: __thiscall AIPlayGroup::AIPlayGroup(void) */

AIPlayGroup * __thiscall AIPlayGroup::AIPlayGroup(AIPlayGroup *this)
{
  initialize(this);
  return this;
}

// --------------------------------------------------

// Function: minimum
// Address: 0040f240
/* public: unsigned char __thiscall AIPlayGroup::minimum(int)const  */

uchar __thiscall AIPlayGroup::minimum(AIPlayGroup *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 6)) {
    return this->minValue[param_1];
  }
  return '\0';
}

// --------------------------------------------------

// Function: setMinimum
// Address: 0040f260
/* public: void __thiscall AIPlayGroup::setMinimum(int,int) */

void __thiscall AIPlayGroup::setMinimum(AIPlayGroup *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 6)) {
    this->minValue[param_1] = (uchar)param_2;
  }
  return;
}

// --------------------------------------------------

// Function: maximum
// Address: 0040f280
/* public: unsigned char __thiscall AIPlayGroup::maximum(int)const  */

uchar __thiscall AIPlayGroup::maximum(AIPlayGroup *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 6)) {
    return this->maxValue[param_1];
  }
  return 0xff;
}

// --------------------------------------------------

// Function: setMaximum
// Address: 0040f2a0
/* public: void __thiscall AIPlayGroup::setMaximum(int,int) */

void __thiscall AIPlayGroup::setMaximum(AIPlayGroup *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 6)) {
    this->maxValue[param_1] = (uchar)param_2;
  }
  return;
}

// --------------------------------------------------

// Function: initialize
// Address: 0040f2c0
/* protected: void __thiscall AIPlayGroup::initialize(void) */

void __thiscall AIPlayGroup::initialize(AIPlayGroup *this)
{
  uchar *puVar1;
  
  puVar1 = this->maxValue;
  do {
    ((AIPlayGroup *)(puVar1 + -6))->minValue[0] = '\0';
    *puVar1 = 0xfe;
    puVar1 = puVar1 + 1;
  } while ((int)(puVar1 + (-6 - (int)this)) < 6);
  return;
}

// --------------------------------------------------

