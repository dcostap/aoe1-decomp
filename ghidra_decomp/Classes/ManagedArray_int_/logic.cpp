// Class: ManagedArray<int>
// Function: ~ManagedArray<int>
// Address: 00408d20
/* public: __thiscall ManagedArray<int>::~ManagedArray<int>(void) */

void __thiscall ManagedArray<int>::~ManagedArray<int>(ManagedArray<int> *this)
{
  if (this->value != (int *)0x0) {
    operator_delete(this->value);
    this->value = (int *)0x0;
  }
  this->numberValue = 0;
  this->desiredNumberValue = 0;
  this->maximumSizeValue = 0;
  return;
}

// --------------------------------------------------

// Function: resize
// Address: 004147a0
/* protected: int __thiscall ManagedArray<int>::resize(int) */

int __thiscall ManagedArray<int>::resize(ManagedArray<int> *this,int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)operator_new(param_1 * 4);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = 0;
  if (0 < this->maximumSizeValue) {
    do {
      if (param_1 <= iVar2) break;
      iVar3 = iVar2 + 1;
      piVar1[iVar2] = this->value[iVar2];
      iVar2 = iVar3;
    } while (iVar3 < this->maximumSizeValue);
  }
  operator_delete(this->value);
  this->value = piVar1;
  this->maximumSizeValue = param_1;
  return 1;
}

// --------------------------------------------------

// Function: contains
// Address: 004de980
/* public: int __thiscall ManagedArray<int>::contains(int const &) */

int __thiscall ManagedArray<int>::contains(ManagedArray<int> *this,int *param_1)
{
  int iVar1;
  
  iVar1 = 0;
  if (0 < this->numberValue) {
    while (iVar1 < this->maximumSizeValue) {
      if (this->value[iVar1] == *param_1) {
        return 1;
      }
      iVar1 = iVar1 + 1;
      if (this->numberValue <= iVar1) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: add
// Address: 004de9d0
/* public: int __thiscall ManagedArray<int>::add(int) */

int __thiscall ManagedArray<int>::add(ManagedArray<int> *this,int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar1 = this->numberValue;
  if (0 < iVar1) {
    do {
      if (this->maximumSizeValue <= iVar2) break;
      if (this->value[iVar2] == param_1) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if (this->maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar3 = (int *)operator_new(iVar1 * 4);
    if (piVar3 != (int *)0x0) {
      iVar2 = 0;
      if (0 < this->maximumSizeValue) {
        do {
          if (iVar1 <= iVar2) break;
          iVar4 = iVar2 + 1;
          piVar3[iVar2] = this->value[iVar2];
          iVar2 = iVar4;
        } while (iVar4 < this->maximumSizeValue);
      }
      operator_delete(this->value);
      this->value = piVar3;
      this->maximumSizeValue = iVar1;
    }
  }
  this->value[this->numberValue] = param_1;
  this->numberValue = this->numberValue + 1;
  return 1;
}

// --------------------------------------------------

// Function: operator[]
// Address: 004ea750
/* public: int & __thiscall ManagedArray<int>::operator[](int) */

int * __thiscall ManagedArray<int>::operator[](ManagedArray<int> *this,int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (this->maximumSizeValue + -1 < param_1) {
    iVar1 = param_1 + 1;
    piVar2 = (int *)operator_new(iVar1 * 4);
    if (piVar2 != (int *)0x0) {
      iVar3 = 0;
      if (0 < this->maximumSizeValue) {
        do {
          if (iVar1 <= iVar3) break;
          iVar4 = iVar3 + 1;
          piVar2[iVar3] = this->value[iVar3];
          iVar3 = iVar4;
        } while (iVar4 < this->maximumSizeValue);
      }
      operator_delete(this->value);
      this->value = piVar2;
      this->maximumSizeValue = iVar1;
    }
  }
  return this->value + param_1;
}

// --------------------------------------------------

// Function: remove
// Address: 004f1390
/* public: int __thiscall ManagedArray<int>::remove(int) */

int __thiscall ManagedArray<int>::remove(ManagedArray<int> *this,int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = this->maximumSizeValue;
  iVar1 = 0;
  if (0 < iVar2) {
    piVar3 = this->value;
    do {
      if (*piVar3 == param_1) break;
      iVar1 = iVar1 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar1 < iVar2);
  }
  if (iVar2 <= iVar1) {
    return 0;
  }
  if (iVar1 < iVar2 + -1) {
    do {
      iVar2 = iVar1 + 1;
      this->value[iVar1] = this->value[iVar2];
      iVar1 = iVar2;
    } while (iVar2 < this->maximumSizeValue + -1);
  }
  iVar2 = this->numberValue + -1;
  this->numberValue = iVar2;
  if (iVar2 < 0) {
    this->numberValue = 0;
  }
  return 1;
}

// --------------------------------------------------

