class RGE_Communications_Queue_go {
public:
    void Flush(void);
};

class TCommunications_Handler_go {
public:
    void GameOver(void);
    char gap_00[0x10C8];
    int current_turn;
    char gap_10CC[0x3F8];
    RGE_Communications_Queue_go* inQ;
    RGE_Communications_Queue_go* outQ;
};

void TCommunications_Handler_go::GameOver(void) {
    this->current_turn = 0;
    if (this->inQ)
        this->inQ->Flush();
    if (this->outQ)
        this->outQ->Flush();
}
