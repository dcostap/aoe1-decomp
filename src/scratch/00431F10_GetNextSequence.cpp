// VA: 00431F10 GetNextSequence (58B)
// com_q.cpp - branchless return using bit trick

class RGE_Communications_Queue {
public:
    char gap_00[0x10C];
    int LastCurrentTurn;      // +0x10C
    unsigned char Sequence;    // +0x110

    unsigned char GetNextSequence(unsigned long param_1);
};

unsigned char RGE_Communications_Queue::GetNextSequence(unsigned long param_1) {
    if (param_1 != this->LastCurrentTurn) {
        this->LastCurrentTurn = param_1;
        this->Sequence = 1;
        return 1;
    }
    this->Sequence = this->Sequence + 1;
    return ((unsigned char)(this->Sequence == 0xFF) - 1) & this->Sequence;
}
