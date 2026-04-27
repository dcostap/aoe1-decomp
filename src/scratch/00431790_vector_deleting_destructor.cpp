// 00431790 MsgQueue::`vector deleting destructor' (113 bytes)
// VC5 compiler-emitted helper
//
// Attempt log:
// Probe 3: function-scope locals to force register saves before branch

#include "..\..\include\game_globals.h"

class MsgQueue {
public:
    int Code;           // +0x00
    int ExecTurn;       // +0x04
    char SeqNo;         // +0x08 (byte!)
    char _pad_09[3];    // padding to +0x0C
    char* msgptr;       // +0x0C
    int From;           // +0x10
    int Size;           // +0x14
    int ControlCommand; // +0x18
    
    void* vector_deleting_destructor(unsigned int flags);
};

extern "C" void __cdecl operator_delete(void*);
void __stdcall eh_vector_destructor_iterator(void* obj, int elemSize, int elemCount, void* dtor);

void* MsgQueue::vector_deleting_destructor(unsigned int flags)
{
    int z = 0;     // forces ebx save upfront
    void* base;    // forces edi save upfront
    
    if (flags & 2) {
        int elemCount = *(int*)((char*)this - 4);
        base = (char*)this - 4;
        eh_vector_destructor_iterator(this, 0x1C, elemCount, (void*)0x431F80);
        operator_delete(base);
        return this;
    }

    // Scalar cleanup
    char* p = this->msgptr;
    this->Code = z;
    this->ExecTurn = z;
    this->SeqNo = (char)z;
    this->From = z;
    this->Size = z;
    this->ControlCommand = z;
    
    if (p != 0) {
        operator_delete(p);
    }
    this->msgptr = 0;

    if (flags & 1) {
        operator_delete(this);
    }
    return this;
}
