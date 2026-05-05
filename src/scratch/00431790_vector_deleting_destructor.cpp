// 00431790 `vector deleting destructor' for MsgQueue (113 bytes, 47 asm lines)
// Compiler-emitted helper (no PDB source)
//
// Attempts: 14. Best: 112 bytes (1 byte short of original 113).
//
// BLOCKER: Register-save scheduling basin. The original pushes ebx/esl/edi
// at function entry (conservative — all three saved regardless of path).
// VC5 /O2 lazily pushes inside each branch (esi at entry, edi in vector
// path, ebx in scalar path), saving 1 byte by omitting `pop edi` in the
// scalar path (edi is never modified there). C++ source cannot override
// VC5's register liveness analysis.
//
// All logic, field offsets (+0/+4/+8/+0C/+10/+14/+18), function-pointer
// call at vtable[0], and both paths are correct.
//
// Left in scratch — register-save-scheduling basin.

#include "..\..\include\game_globals.h"

void __cdecl operator_delete(void*);
void __stdcall eh_vector_destructor_iterator(void* obj, int elemSize, int elemCount, void* dtor);

class MsgQueue {
public:
    int Code;
    int ExecTurn;
    char SeqNo;
    char _pad_09[3];
    char* msgptr;
    int From;
    int Size;
    int ControlCommand;
    
    void* vector_deleting_destructor(unsigned int flags);
};

void* MsgQueue::vector_deleting_destructor(unsigned int flags)
{
    int zero = 0;
    void* base;

    if (flags & 2) {
        base = (char*)this - 4;
        int elemCount = *(int*)base;
        eh_vector_destructor_iterator(this, 0x1C, elemCount, (void*)0x431F80);
        operator_delete(base);
        return this;
    }

    base = this->msgptr;
    this->Code = zero;
    this->ExecTurn = zero;
    this->SeqNo = (char)zero;
    this->From = zero;
    this->Size = zero;
    this->ControlCommand = zero;

    if (base != 0) {
        operator_delete(base);
    }
    this->msgptr = 0;

    if (flags & 1) {
        operator_delete(this);
    }
    return this;
}
