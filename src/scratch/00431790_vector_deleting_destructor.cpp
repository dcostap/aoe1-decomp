// 00431790 `vector deleting destructor' for MsgQueue (113 bytes, 47 asm lines)
// Compiler-emitted helper (no PDB source)
//
// Status: STUCK — register-save scheduling basin.
//
// Blocker: Original pushes ebx/esi/edi at entry. VC5 /O2 lazily pushes inside
// each branch (esi at entry, edi in vector path, ebx in scalar path), saving
// 2 prologue bytes but missing 1 byte in each epilogue (no pop for unpushed
// register). Function is 112 bytes vs original 113.
//
// Best improvement: changed flags parameter from unsigned int to unsigned char.
// Now byte-load matches original `mov al,[esp+4]` encoding (8a vs 8b). But
// register-save scheduling basin is unchanged.
//
// All logic, field offsets (+0/+4/+8/+0C/+10/+14/+18), function-pointer call
// at vtable[0], and both paths are correct.

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
    
    void* vector_deleting_destructor(unsigned char flags);
};

void* MsgQueue::vector_deleting_destructor(unsigned char flags)
{
    if (flags & 2) {
        int elemCount = *(int*)((char*)this - 4);
        eh_vector_destructor_iterator(this, 0x1C, elemCount, (void*)0x431F80);
        operator_delete((char*)this - 4);
        return this;
    }

    char* base = this->msgptr;
    this->Code = 0;
    this->ExecTurn = 0;
    this->SeqNo = 0;
    this->From = 0;
    this->Size = 0;
    this->ControlCommand = 0;

    if (base != 0) {
        operator_delete(base);
    }
    this->msgptr = 0;

    if (flags & 1) {
        operator_delete(this);
    }
    return this;
}
