extern "C" void __cdecl operator_delete(void*);

struct HOLDER {
    void* HoldMsg;
    int Serial;
    int Length;
    unsigned int dcoFromID;
    unsigned int dcoReceiveID;
    char pad_14[4];
};

class TCommunications_Handler {
public:
    char gap_00[0x1524];
    HOLDER* OnHold;
    char gap_1528[0x3C];
    unsigned int dcoID[16];

    void ClearRXForPlayer(unsigned int player);
};

void TCommunications_Handler::ClearRXForPlayer(unsigned int player) {
    unsigned int off;
    int zero;
    void** pu;

    zero = 0;
    off = 0;
    do {
        pu = (void**)((int)&this->OnHold->HoldMsg + off);
        if (*(unsigned int*)((int)&this->OnHold->dcoFromID + off) == this->dcoID[player]) {
            if ((void*)*pu != 0) {
                operator_delete((void*)*pu);
            }
            *pu = (void*)zero;
            pu[1] = (void*)zero;
            pu[2] = (void*)zero;
            pu[3] = (void*)zero;
            pu[4] = (void*)zero;
        }
        off = off + 0x18;
    } while (off <= 0x2EF8);
}
