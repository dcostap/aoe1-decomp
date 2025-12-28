// Class: HOLDER
// Size:  0x18
//
// Member Layout:
// [0x000] char * HoldMsg
// [0x004] uint Serial
// [0x008] uint Length
// [0x00C] ulong dcoFromID
// [0x010] ulong dcoReceiveID
// [0x014] uint fromPlayer
// ----------------------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00426170
void * __thiscall HOLDER::_vector_deleting_destructor_(HOLDER *this,uint param_1)
{
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(this,0x18,this[-1].fromPlayer,~HOLDER);
    operator_delete(&this[-1].fromPlayer);
    return this;
  }
  if (this->HoldMsg != (char *)0x0) {
    operator_delete(this->HoldMsg);
  }
  this->HoldMsg = (char *)0x0;
  this->Serial = 0;
  this->Length = 0;
  this->dcoFromID = 0;
  this->dcoReceiveID = 0;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: HOLDER
// Address: 004265e0
void __thiscall HOLDER::HOLDER(HOLDER *this)
{
  this->HoldMsg = (char *)0x0;
  this->Serial = 0;
  this->Length = 0;
  this->dcoFromID = 0;
  this->dcoReceiveID = 0;
  return;
}

// --------------------------------------------------

// Function: ~HOLDER
// Address: 00426600
void __thiscall HOLDER::~HOLDER(HOLDER *this)
{
  if (this->HoldMsg != (char *)0x0) {
    operator_delete(this->HoldMsg);
  }
  this->HoldMsg = (char *)0x0;
  this->Serial = 0;
  this->Length = 0;
  this->dcoFromID = 0;
  this->dcoReceiveID = 0;
  return;
}

// --------------------------------------------------

