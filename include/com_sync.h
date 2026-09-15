#ifndef AOE1_COM_SYNC_H
#define AOE1_COM_SYNC_H

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

private:
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

public:
    RGE_Communications_Synchronize(TCommunications_Handler* c);
    ~RGE_Communications_Synchronize();
    int Add(unsigned int player, unsigned long worldtime,
            unsigned long worldturn, unsigned long worldrandom,
            long cs1, long cs2, long cs3, long cs4, long cs5);

protected:
    int ValidateChecksums(unsigned int player, unsigned long worldtime,
                          unsigned long worldturn, unsigned long worldrandom,
                          long cs1, long cs2, long cs3, long cs4, long cs5);

public:
    unsigned long DoChecksum(unsigned long turn);
    void SetLastWorldRandom(unsigned long lwr);
    void LogChecksums(unsigned int player, unsigned long worldtime,
                      unsigned long worldturn, long cs1, long cs2, long cs3,
                      long cs4, long cs5, unsigned long random);
    void EnableSyncChecking(int Status);
    void SetStopOnFail(int Status);
    void SetDialogOnFail(int Status);
    void SendChatMsgsAtChecksum(int Status);
    int IsPlayerOutOfSync(unsigned int pnum, unsigned long worldturn);
};

typedef RGE_Communications_Synchronize::CHECKSUMARRAY
    RGE_Communications_Check;

typedef char comm_sync_check_size[
    (sizeof(RGE_Communications_Check) == 0x24) ? 1 : -1];
typedef char comm_sync_size_check[
    (sizeof(RGE_Communications_Synchronize) == 0x7EC) ? 1 : -1];

#endif
