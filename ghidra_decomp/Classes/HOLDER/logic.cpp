// Class: HOLDER
// Function: `vector_deleting_destructor'
// Address: 00426170
/* public: void * __thiscall HOLDER::`vector deleting destructor'(unsigned int) */

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
/* public: __thiscall HOLDER::HOLDER(void) */

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
/* public: __thiscall HOLDER::~HOLDER(void) */

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

