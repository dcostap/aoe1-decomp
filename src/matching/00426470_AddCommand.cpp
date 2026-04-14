class RGE_Communications_Queue_ac {
public:
    void AddItem(int a, int b, int c, int d, int e, int f);
};

class TCommunications_Handler_ac {
public:
    void AddCommand(int a, int b, int c, int d, int e, int f);
    char gap_00[0x14C4];
    RGE_Communications_Queue_ac* inQ;
};

void TCommunications_Handler_ac::AddCommand(int a, int b, int c, int d, int e, int f) {
    this->inQ->AddItem(a, b, c, d, e, f);
}
