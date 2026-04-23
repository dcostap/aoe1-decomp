class RGE_Communications_Queue {
public:
    char gap_00[0x10C];
    unsigned long LastCurrentTurn;
    unsigned char Sequence;

    unsigned char GetNextSequence(unsigned long value);
};

unsigned char RGE_Communications_Queue::GetNextSequence(unsigned long value) {
    if (value != this->LastCurrentTurn) {
        this->LastCurrentTurn = value;
        this->Sequence = 1;
        return 1;
    }
    unsigned char next = this->Sequence + 1;
    this->Sequence = next;
    if (next == 0xFF) {
        return 0;
    }
    return next;
}
