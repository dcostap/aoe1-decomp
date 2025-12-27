// Class: XYZ
// Function: XYZ
// Address: 0047e480
/* public: __thiscall XYZ::XYZ(void) */

void __thiscall XYZ::XYZ(XYZ *this)
{
  this->xValue = 0;
  this->yValue = 0;
  this->zValue = 0;
  return;
}

// --------------------------------------------------

// Function: XYZ
// Address: 0047e490
/* public: __thiscall XYZ::XYZ(int,int,int) */

void __thiscall XYZ::XYZ(XYZ *this,int param_1,int param_2,int param_3)
{
  this->xValue = param_1;
  this->yValue = param_2;
  this->zValue = param_3;
  return;
}

// --------------------------------------------------

// Function: operator=
// Address: 0047e510
/* public: class XYZ & __thiscall XYZ::operator=(class XYZ const &) */

XYZ * __thiscall XYZ::operator=(XYZ *this,XYZ *param_1)
{
  this->xValue = param_1->xValue;
  this->yValue = param_1->yValue;
  this->zValue = param_1->zValue;
  return this;
}

// --------------------------------------------------

// Function: operator+
// Address: 0047e530
/* WARNING: Variable defined which should be unmapped: newP */
/* public: class XYZ __thiscall XYZ::operator+(class XYZ const &)const  */

XYZ * __thiscall XYZ::operator+(XYZ *this,XYZ *__return_storage_ptr__,XYZ *param_1)
{
  XYZ newP;
  int local_4;
  
  XYZ((XYZ *)&newP.yValue,this->xValue + param_1->xValue,this->yValue + param_1->yValue,
      param_1->zValue + this->zValue);
  __return_storage_ptr__->xValue = newP.yValue;
  __return_storage_ptr__->yValue = newP.zValue;
  __return_storage_ptr__->zValue = local_4;
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: operator-
// Address: 0047e580
/* WARNING: Variable defined which should be unmapped: newP */
/* public: class XYZ __thiscall XYZ::operator-(class XYZ const &)const  */

XYZ * __thiscall XYZ::operator-(XYZ *this,XYZ *__return_storage_ptr__,XYZ *param_1)
{
  XYZ newP;
  int local_4;
  
  XYZ((XYZ *)&newP.yValue,this->xValue - param_1->xValue,this->yValue - param_1->yValue,
      this->zValue - param_1->zValue);
  __return_storage_ptr__->xValue = newP.yValue;
  __return_storage_ptr__->yValue = newP.zValue;
  __return_storage_ptr__->zValue = local_4;
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: rotateXYByFacet
// Address: 0047e5d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall XYZ::rotateXYByFacet(class XYZ const &,class XYZ &,unsigned char) */

void __thiscall XYZ::rotateXYByFacet(XYZ *this,XYZ *param_1,XYZ *param_2,uchar param_3)
{
  int iVar1;
  
  param_2->xValue = this->xValue;
  param_2->yValue = this->yValue;
  param_2->zValue = this->zValue;
  if (param_3 != '\0') {
    fsin((float10)param_3 * (float10)_DAT_00571ce8);
    fcos((float10)(float)((float10)param_3 * (float10)_DAT_00571ce8));
    iVar1 = __ftol();
    param_2->xValue = iVar1;
    iVar1 = __ftol();
    param_2->yValue = iVar1;
  }
  return;
}

// --------------------------------------------------

