// Class: IPAD
// Function: `vector_deleting_destructor'
// Address: 00424ac0
/* public: void * __thiscall IPAD::`vector deleting destructor'(unsigned int) */

void * __thiscall IPAD::_vector_deleting_destructor_(IPAD *this,uint param_1)
{
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(this,0xa0,*(int *)(this[-1].Alias + 0x7c),~IPAD);
    operator_delete(this[-1].Alias + 0x7c);
    return this;
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: IPAD
// Address: 00424dd0
// [HELPER] s_: ""
/* public: __thiscall IPAD::IPAD(void) */

IPAD * __thiscall IPAD::IPAD(IPAD *this)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  IPAD *pIVar5;
  char *pcVar6;
  
  uVar2 = 0xffffffff;
  pcVar4 = s_;
  do {
    pcVar6 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar6 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar6;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar6 + -uVar2;
  pIVar5 = this;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pIVar5->DottedIPAddress = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pIVar5 = (IPAD *)(pIVar5->DottedIPAddress + 4);
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    pIVar5->DottedIPAddress[0] = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pIVar5 = (IPAD *)(pIVar5->DottedIPAddress + 1);
  }
  uVar2 = 0xffffffff;
  pcVar4 = s_;
  do {
    pcVar6 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar6 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar6;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar6 + -uVar2;
  pcVar6 = this->Alias;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar6 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: ~IPAD
// Address: 00424e30
/* public: __thiscall IPAD::~IPAD(void) */

void __thiscall IPAD::~IPAD(IPAD *this)
{
  return;
}

// --------------------------------------------------

