// Class: TRIGONOMETRY
// Function: TRIGONOMETRY
// Address: 0052a730
/* WARNING: Variable defined which should be unmapped: i */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall TRIGONOMETRY::TRIGONOMETRY(void) */

void __thiscall TRIGONOMETRY::TRIGONOMETRY(TRIGONOMETRY *this)
{
  float *pfVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  int i;
  int local_4;
  
  local_4 = 0;
  pfVar1 = this->tane;
  do {
    fVar2 = (float10)local_4 * (float10)_DAT_005772f0;
    fVar3 = (float10)fsin(fVar2);
    fVar4 = (float10)fcos(fVar2);
    ((TRIGONOMETRY *)(pfVar1 + -0x2000))->sines[0] = (float)fVar3;
    pfVar1[-0x1000] = (float)fVar4;
    if ((local_4 == 0x400) || (local_4 == 0xc00)) {
      *pfVar1 = 0.0;
    }
    else {
      fVar3 = (float10)fptan(fVar2);
      *pfVar1 = (float)fVar3;
    }
    if ((local_4 == 0) || (local_4 == 0x800)) {
      pfVar1[0x1000] = 0.0;
    }
    else {
      fVar2 = (float10)fpatan(fVar2,(float10)1);
      pfVar1[0x1000] = (float)fVar2;
    }
    local_4 = local_4 + 1;
    pfVar1 = pfVar1 + 1;
  } while (local_4 < 0x1000);
  pfVar1 = this->tane360;
  local_4 = 0;
  do {
    fVar2 = (float10)local_4 * (float10)_DAT_005772f8;
    fVar3 = (float10)fsin(fVar2);
    fVar4 = (float10)fcos(fVar2);
    pfVar1[-0x2d0] = (float)fVar3;
    pfVar1[-0x168] = (float)fVar4;
    if ((local_4 == 0x5a) || (local_4 == 0x10e)) {
      *pfVar1 = 0.0;
    }
    else {
      fVar3 = (float10)fptan(fVar2);
      *pfVar1 = (float)fVar3;
    }
    if ((local_4 == 0) || (local_4 == 0xb4)) {
      pfVar1[0x168] = 0.0;
    }
    else {
      fVar2 = (float10)fpatan(fVar2,(float10)1);
      pfVar1[0x168] = (float)fVar2;
    }
    local_4 = local_4 + 1;
    pfVar1 = pfVar1 + 1;
  } while (local_4 < 0x168);
  return;
}

// --------------------------------------------------

// Function: RestrictAngle
// Address: 0052a830
/* private: int __thiscall TRIGONOMETRY::RestrictAngle(int) */

int __thiscall TRIGONOMETRY::RestrictAngle(TRIGONOMETRY *this,int param_1)
{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1 >> 0x1f;
  iVar1 = ((param_1 ^ uVar2) - uVar2 & 0xfff ^ uVar2) - uVar2;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: RestrictAngle360
// Address: 0052a850
/* private: int __thiscall TRIGONOMETRY::RestrictAngle360(int) */

int __thiscall TRIGONOMETRY::RestrictAngle360(TRIGONOMETRY *this,int param_1)
{
  int iVar1;
  
  iVar1 = param_1 % 0x168;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: sine
// Address: 0052a870
/* public: float __thiscall TRIGONOMETRY::sine(int) */

float __thiscall TRIGONOMETRY::sine(TRIGONOMETRY *this,int param_1)
{
  int iVar1;
  
  iVar1 = RestrictAngle(this,param_1);
  return this->sines[iVar1];
}

// --------------------------------------------------

// Function: cosine
// Address: 0052a890
/* public: float __thiscall TRIGONOMETRY::cosine(int) */

float __thiscall TRIGONOMETRY::cosine(TRIGONOMETRY *this,int param_1)
{
  int iVar1;
  
  iVar1 = RestrictAngle(this,param_1);
  return this->cose[iVar1];
}

// --------------------------------------------------

// Function: tangent
// Address: 0052a8b0
/* public: float __thiscall TRIGONOMETRY::tangent(int) */

float __thiscall TRIGONOMETRY::tangent(TRIGONOMETRY *this,int param_1)
{
  int iVar1;
  
  iVar1 = RestrictAngle(this,param_1);
  return this->tane[iVar1];
}

// --------------------------------------------------

// Function: atangent
// Address: 0052a8d0
/* public: float __thiscall TRIGONOMETRY::atangent(int) */

float __thiscall TRIGONOMETRY::atangent(TRIGONOMETRY *this,int param_1)
{
  int iVar1;
  
  iVar1 = RestrictAngle(this,param_1);
  return this->atane[iVar1];
}

// --------------------------------------------------

// Function: sin360
// Address: 0052a8f0
/* public: float __thiscall TRIGONOMETRY::sin360(int) */

float __thiscall TRIGONOMETRY::sin360(TRIGONOMETRY *this,int param_1)
{
  int iVar1;
  
  iVar1 = RestrictAngle360(this,param_1);
  return this->sine360[iVar1];
}

// --------------------------------------------------

// Function: cos360
// Address: 0052a910
/* public: float __thiscall TRIGONOMETRY::cos360(int) */

float __thiscall TRIGONOMETRY::cos360(TRIGONOMETRY *this,int param_1)
{
  int iVar1;
  
  iVar1 = RestrictAngle360(this,param_1);
  return this->cose360[iVar1];
}

// --------------------------------------------------

// Function: tan360
// Address: 0052a930
/* public: float __thiscall TRIGONOMETRY::tan360(int) */

float __thiscall TRIGONOMETRY::tan360(TRIGONOMETRY *this,int param_1)
{
  int iVar1;
  
  iVar1 = RestrictAngle360(this,param_1);
  return this->tane360[iVar1];
}

// --------------------------------------------------

// Function: atan360
// Address: 0052a950
/* public: float __thiscall TRIGONOMETRY::atan360(int) */

float __thiscall TRIGONOMETRY::atan360(TRIGONOMETRY *this,int param_1)
{
  int iVar1;
  
  iVar1 = RestrictAngle360(this,param_1);
  return this->atane360[iVar1];
}

// --------------------------------------------------

