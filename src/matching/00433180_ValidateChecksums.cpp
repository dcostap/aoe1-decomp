// VA: 00433180 ValidateChecksums (259B)
// com_sync.cpp lines 74-125
//
// Attempt log:
// - Reconstructed the checksum record ownership from Add/constructor: Check[0x37]
//   begins at +30, with WTime at +34 and WTurn at +38; validation scans records
//   1 through 0x36 using the WTime cursor at +58.

#ifndef COM_SYNC_TU_CONTEXT
typedef int COMMMESSAGES;

class TCommunications_Handler {
public:
    void NotifyWindowParam(COMMMESSAGES msg, long param);
};

class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

extern TDebuggingLog* L;

struct RGE_Communications_Check {
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

class RGE_Communications_Synchronize {
public:
    TCommunications_Handler* Comm; // +00
    unsigned long CheckTime; // +04
    unsigned long CheckTurn; // +08
    int StopOnSyncFail; // +0C
    int DialogOnSyncFail; // +10
    int SendChatMsgs; // +14
    int NewData;             // +18
    int LastResult;          // +1C
    unsigned int Offset;     // +20
    int DoChecksums;         // +24
    unsigned long LastWorldRandom; // +28
    unsigned long GameWorldChecksum; // +2C
    RGE_Communications_Check Check[0x37]; // +30

protected:
    int ValidateChecksums(unsigned turn, unsigned long wRandom,
                          unsigned long checksum1, unsigned long checksum2,
                          long chatCrc, long dataCrc, long a7, long a8,
                          long a9);
    void LogChecksums(unsigned turn, unsigned long wRandom,
                      unsigned long checksum1, long chatCrc, long dataCrc,
                      long a7, long a8, long a9,
                      unsigned long checksum2);
};
#endif

int RGE_Communications_Synchronize::ValidateChecksums(
    unsigned turn, unsigned long wRandom, unsigned long checksum1,
    unsigned long checksum2, long chatCrc, long dataCrc, long a7, long a8,
    long a9) {
    int bad = 0;

    if (!this->NewData) {
        return this->LastResult;
    }

    this->NewData = 0;
    this->LastResult = 0;

    unsigned int i = 1;
    RGE_Communications_Check* check = &this->Check[1];
    for (; i <= 0x36; ++i, ++check) {
        if (check->WTurn == checksum1) {
            if (check->WTime != wRandom) {
                bad = 1;
            }
        }

        if (check->WTime == wRandom) {
            if (check->cs1 != chatCrc || check->cs2 != dataCrc ||
                check->cs3 != a7 || check->cs4 != a8 ||
                check->cs5 != a9 || check->Random != checksum2) {
                bad = 1;
            }
        }

        if (bad) {
            this->LogChecksums(turn, wRandom, checksum1, chatCrc, dataCrc,
                               a7, a8, a9, checksum2);
            this->Comm->NotifyWindowParam((COMMMESSAGES)0x17B0, checksum1);
            this->LastResult = 0;
            return 0;
        }

    }

    L->Log("P#%d In Sync @ Wtime=%d WTurn=%d Wrand=%d Wchksum=%d",
                        turn, wRandom, checksum1, checksum2, chatCrc);
    this->LastResult = 1;
    return 1;
}
