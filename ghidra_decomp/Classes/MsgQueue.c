// Class: MsgQueue
// Size:  0x1C
//
// Member Layout:
// [0x000] ulong Code
// [0x004] ulong ExecTurn
// [0x008] uchar SeqNo
// [0x00C] char * msgptr
// [0x010] uint From
// [0x014] uint Size
// [0x018] int ControlCommand
// ----------------------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00431790
/* public: void * __thiscall MsgQueue::`vector deleting destructor'(unsigned int) */

void * __thiscall MsgQueue::_vector_deleting_destructor_(MsgQueue *this,uint param_1)
{
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(this,0x1c,this[-1].ControlCommand,~MsgQueue);
    operator_delete(&this[-1].ControlCommand);
    return this;
  }
  this->Code = 0;
  this->ExecTurn = 0;
  this->SeqNo = '\0';
  this->From = 0;
  this->Size = 0;
  this->ControlCommand = 0;
  if (this->msgptr != (char *)0x0) {
    operator_delete(this->msgptr);
  }
  this->msgptr = (char *)0x0;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: MsgQueue
// Address: 00431f60
/* public: __thiscall MsgQueue::MsgQueue(void) */

void __thiscall MsgQueue::MsgQueue(MsgQueue *this)
{
  this->Code = 0;
  this->ExecTurn = 0;
  this->SeqNo = '\0';
  this->From = 0;
  this->Size = 0;
  this->ControlCommand = 0;
  this->msgptr = (char *)0x0;
  return;
}

// --------------------------------------------------

// Function: ~MsgQueue
// Address: 00431f80
/* public: __thiscall MsgQueue::~MsgQueue(void) */

void __thiscall MsgQueue::~MsgQueue(MsgQueue *this)
{
  this->Code = 0;
  this->ExecTurn = 0;
  this->SeqNo = '\0';
  this->From = 0;
  this->Size = 0;
  this->ControlCommand = 0;
  if (this->msgptr != (char *)0x0) {
    operator_delete(this->msgptr);
  }
  this->msgptr = (char *)0x0;
  return;
}

// --------------------------------------------------

