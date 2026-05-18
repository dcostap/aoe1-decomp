// 00431790 `vector deleting destructor' for MsgQueue (113 bytes, 47 asm lines)
// Compiler-emitted helper (no PDB source)
//
// Status: MATCH.
//
// Key shape: keep vector-delete and scalar-delete paths under one if/else with
// a shared final `return this;`. This makes VC5 choose the original shared
// ebx/esi/edi prologue/epilogue instead of lazy per-branch saves. The flags
// parameter must stay unsigned char for the original byte-load shape.

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
        char* vectorBase = (char*)this - 4;
        eh_vector_destructor_iterator(this, 0x1C, elemCount, (void*)0x431F80);
        operator_delete(vectorBase);
    } else {
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
    }
    return this;
}
