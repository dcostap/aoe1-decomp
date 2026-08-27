// VA: 004330A0 Add (209B)
// com_sync.cpp lines 44-62
//
// The checksum records occupy the class tail at +30.  The source-visible
// record order is PlayerNo, WTime, WTurn, cs1..cs5, Random; the original
// source writes the time/checksum fields first and PlayerNo last.

#ifndef COM_SYNC_TU_CONTEXT
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
    TCommunications_Handler* Comm;
    unsigned long CheckTime;
    unsigned long CheckTurn;
    int StopOnSyncFail;
    int DialogOnSyncFail;
    int SendChatMsgs;
    int NewData;             // +18
    int LastResult;          // +1C
    unsigned int Offset;     // +20
    int DoChecksums;         // +24
    unsigned long LastWorldRandom; // +28
    unsigned long GameWorldChecksum; // +2C
    RGE_Communications_Check Check[0x37]; // +30, stride 0x24

    int Add(unsigned turn, unsigned long wRandom, unsigned long checksum1,
            unsigned long checksum2, long chatCrc, long dataCrc,
            long a7, long a8, long a9);

protected:
    int ValidateChecksums(unsigned turn, unsigned long wRandom,
                          unsigned long checksum1, unsigned long checksum2,
                          long chatCrc, long dataCrc, long a7, long a8,
                          long a9);
};
#endif

int RGE_Communications_Synchronize::Add(
    unsigned turn, unsigned long wRandom, unsigned long checksum1,
    unsigned long checksum2, long chatCrc, long dataCrc,
    long a7, long a8, long a9) {
    if (!this->DoChecksums) {
        return 0;
    }

    this->Offset++;
    if ((unsigned)this->Offset >= 0x36u) {
        this->Offset = 0;
    }

    this->Check[this->Offset].WTime = wRandom;
    this->Check[this->Offset].WTurn = checksum1;
    this->Check[this->Offset].cs1 = chatCrc;
    this->Check[this->Offset].cs2 = dataCrc;
    this->Check[this->Offset].cs3 = a7;
    this->Check[this->Offset].cs4 = a8;
    this->Check[this->Offset].cs5 = a9;
    this->Check[this->Offset].Random = checksum2;
    this->Check[this->Offset].PlayerNo = turn;

    this->NewData = 1;
    return this->ValidateChecksums(turn, wRandom, checksum1, checksum2,
                                   chatCrc, dataCrc, a7, a8, a9);
}
