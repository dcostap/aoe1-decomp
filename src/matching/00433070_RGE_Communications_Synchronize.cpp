#ifndef COM_SYNC_TU_CONTEXT
class TCommunications_Handler;
class RGE_Communications_Synchronize {
public:
    struct CHECKSUMARRAY {
        int PlayerNo;
        unsigned long WTime;
        unsigned long WTurn;
        long cs1;
        long cs2;
        long cs3;
        long cs4;
        long cs5;
        unsigned long Random;
    };

    TCommunications_Handler* Comm;
    unsigned long CheckTime;
    unsigned long CheckTurn;
    int StopOnSyncFail;
    int DialogOnSyncFail;
    int SendChatMsgs;
    int NewData;
    int LastResult;
    unsigned int Offset;
    int DoChecksums;
    unsigned long LastWorldRandom;
    unsigned long GameWorldChecksum;
    CHECKSUMARRAY Check[0x37];

    ~RGE_Communications_Synchronize();
};
#endif

RGE_Communications_Synchronize::~RGE_Communications_Synchronize() {
    unsigned long* p = &this->Check[0].WTurn;
    int i = 0x37;

    do {
        p[-1] = 0;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[-2] = 0;
        p += 9;
        i = i - 1;
    } while (i != 0);
}
