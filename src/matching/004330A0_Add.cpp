// VA: 004330A0 Add (209B)
// com_sync.cpp lines 44-62
//
// The checksum records occupy the class tail at +30.  The source-visible
// record order is PlayerNo, WTime, WTurn, cs1..cs5, Random; the original
// source writes the time/checksum fields first and PlayerNo last.

struct RGE_Communications_Check {
    int PlayerNo;
    unsigned WTime;
    unsigned WTurn;
    unsigned cs1;
    unsigned cs2;
    long cs3;
    long cs4;
    long cs5;
    unsigned Random;
};

class RGE_Communications_Synchronize {
public:
    char gap_00[0x18];
    int NewData;             // +18
    int LastResult;          // +1C
    int Offset;              // +20
    int DoChecksums;         // +24
    int LastWorldRandom;     // +28
    int GameWorldChecksum;   // +2C
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
