// tried explicit store-then-return-1 and multiple literal/cast/comma variants; VC5 still emits
// mov al,1 / mov [ecx+110h],al instead of mov byte [ecx+110h],1 / mov al,1.
// tried branch inversion and local-temp forms; lower sbb/and path can match, but upper reset path stays 1 byte short.
class RGE_Communications_Queue {
public:
    char gap_00[0x10C];
    int LastCurrentTurn;
    unsigned char Sequence;
    unsigned char GetNextSequence(unsigned long param_1);
};
unsigned char RGE_Communications_Queue::GetNextSequence(unsigned long param_1) {
    if (param_1 != this->LastCurrentTurn) {
        this->LastCurrentTurn = param_1;
        return this->Sequence = 1;
    }
    this->Sequence = this->Sequence + 1;
    if (this->Sequence >= 0xFF) {
        return 0;
    }
    return this->Sequence;
}
