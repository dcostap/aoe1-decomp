// Class: RESENDER
// Size:  0x38
//
// Member Layout:
// [0x000] ulong TimeSent
// [0x004] uint Serial
// [0x008] char * ResendMsg
// [0x00C] uint Length
// [0x010] uint[10] DestMap (sz: 0x28)
// ----------------------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004260f0
/* public: void * __thiscall RESENDER::`vector deleting destructor'(unsigned int) */

void * __thiscall RESENDER::_vector_deleting_destructor_(RESENDER *this,uint param_1)
{
  int iVar1;
  uint *puVar2;
  
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(this,0x38,this[-1].DestMap[9],~RESENDER);
    operator_delete(this[-1].DestMap + 9);
    return this;
  }
  this->TimeSent = 0;
  if (this->ResendMsg != (char *)0x0) {
    operator_delete(this->ResendMsg);
  }
  this->ResendMsg = (char *)0x0;
  this->Serial = 0;
  this->Length = 0;
  puVar2 = this->DestMap;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RESENDER
// Address: 00426450
/* public: __thiscall RESENDER::RESENDER(void) */

RESENDER * __thiscall RESENDER::RESENDER(RESENDER *this)
{
  int iVar1;
  uint *puVar2;
  
  this->TimeSent = 0;
  this->ResendMsg = (char *)0x0;
  this->Serial = 0;
  this->Length = 0;
  puVar2 = this->DestMap;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: ~RESENDER
// Address: 004264a0
/* public: __thiscall RESENDER::~RESENDER(void) */

void __thiscall RESENDER::~RESENDER(RESENDER *this)
{
  int iVar1;
  uint *puVar2;
  
  this->TimeSent = 0;
  if (this->ResendMsg != (char *)0x0) {
    operator_delete(this->ResendMsg);
  }
  this->ResendMsg = (char *)0x0;
  this->Serial = 0;
  this->Length = 0;
  puVar2 = this->DestMap;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}

// --------------------------------------------------

