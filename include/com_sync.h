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
    RGE_Communications_Synchronize(TCommunications_Handler* comm);
    ~RGE_Communications_Synchronize();
    int Add(unsigned int turn, unsigned long wRandom,
            unsigned long checksum1, unsigned long checksum2,
            long chatCrc, long dataCrc, long a7, long a8, long a9);

protected:
    int ValidateChecksums(unsigned int turn, unsigned long wRandom,
                          unsigned long checksum1, unsigned long checksum2,
                          long chatCrc, long dataCrc, long a7, long a8,
                          long a9);

public:
    unsigned long DoChecksum(unsigned long turn);
    void SetLastWorldRandom(unsigned long value);
    void LogChecksums(unsigned int playerNo, unsigned long worldTime,
                      unsigned long commTurn, long unifiedVisible,
                      long checksumNew, long position, long action,
                      long obstruction, unsigned long random);
    void EnableSyncChecking(int value);
    void SetStopOnFail(int value);
    void SetDialogOnFail(int value);
    void SendChatMsgsAtChecksum(int value);
    int IsPlayerOutOfSync(unsigned int playerNo, unsigned long commTurn);
};

typedef RGE_Communications_Synchronize::CHECKSUMARRAY
    RGE_Communications_Check;

typedef char comm_sync_check_size[
    (sizeof(RGE_Communications_Check) == 0x24) ? 1 : -1];
typedef char comm_sync_size_check[
    (sizeof(RGE_Communications_Synchronize) == 0x7EC) ? 1 : -1];

#endif
