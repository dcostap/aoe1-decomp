// 0042B860 TCommunications_Handler::DestroyMultiplayerGame
// Attempt log:
// initial direct source from original asm: explicit field stores and natural empty-string assignments.

class TDebuggingLog;
extern "C" unsigned long debug_timeGetTime(char*, int);
extern "C" int target_0042B860();
extern "C" void* memset(void*, int, unsigned int);
extern "C" char* strcpy(char*, const char*);
extern "C" void target_00436610(TDebuggingLog*, char*);

class TDebuggingLog {
public:
    void Time();
};
extern TDebuggingLog* debugging_log;

static char* const empty_string = (char*)0x580460;
static char* const log_string = (char*)0x580C4C;
static char* const com_hand_h = (char*)0x580C64;

class TCommunications_Handler {
public:
    char gap_0000[0x0008];
    int field_0008;
    int field_000c;
    int field_0010;
    char gap_0014[0x001c-0x0014];
    int field_001c;
    int field_0020;
    char gap_0024[0x10c8-0x0024];
    int field_10c8;
    char gap_10cc[0x10d8-0x10cc];
    unsigned short field_10d8;
    int field_10dc;
    int field_10e0;
    int field_10e4;
    int field_10e8;
    int field_10ec;
    int field_10f0;
    int field_10f4;
    char str_10f8[0x81];
    char str_1179[0x81];
    char str_11fa[0x8e];
    int field_1288;
    int field_128c;
    char gap_1290[0x1294-0x1290];
    int field_1294;
    int field_1298;
    char gap_129c[0x12a0-0x129c];
    int field_12a0;
    char gap_12a4[0x12a8-0x12a4];
    int field_12a8;
    char gap_12ac[0x12b8-0x12ac];
    int field_12b8;
    int field_12bc;
    int field_12c0;
    int field_12c4;
    char gap_12c8[0x12d0-0x12c8];
    int field_12d0;
    char gap_12d4[0x12d8-0x12d4];
    unsigned short field_12d8;
    char gap_12da[0x1310-0x12da];
    int field_1310;
    char gap_1314[0x1328-0x1314];
    int field_1328;
    int field_132c;
    int field_1330;
    int field_1334;
    int field_1338;
    char gap_133c[0x1340-0x133c];
    int field_1340;
    char gap_1344[0x13c0-0x1344];
    int clear_13c0[9];
    char gap_13e4[0x146c-0x13e4];
    int loop_a[10];
    char gap_1494[0x149c-0x1494];
    int loop_b[10];
    void* field_14c4;
    void* field_14c8;
    char gap_14cc[0x14e4-0x14cc];
    int field_14e4;
    char gap_14e8[0x1514-0x14e8];
    unsigned char field_1514;
    int field_1518;
    int field_151c;
    char gap_1520[0x1550-0x1520];
    unsigned char field_1550;
    int field_1554;
    int field_1558;
    int field_155c;
    char gap_1560[0x1590-0x1560];
    unsigned char field_1590;
    char gap_1591[0x1710-0x1591];
    unsigned short field_1710;
    unsigned short field_1712;
    char gap_1714[0x1718-0x1714];
    int field_1718;
    char gap_171c[0x1748-0x171c];
    int field_1748;

    void DestroyMultiplayerGame();
    long DestroyMyPlayer();
    void AddPlayer(long, long, char*, char*);
    void sub_00429F80();
    void sub_00429FD0();
    void sub_0042C7A0();
};

class Releasable { public: void Release(); };

void TCommunications_Handler::DestroyMultiplayerGame()
{
    this->DestroyMyPlayer();
    long t = debug_timeGetTime(com_hand_h, 0x267);
    int zero = 0;
    this->field_12b8 = zero;
    this->field_12bc = zero;
    this->field_12c0 = zero;
    this->field_12c4 = zero;
    this->field_10f0 = zero;
    this->field_10f4 = zero;
    this->field_1748 = zero;
    this->field_1340 = zero;
    this->field_1338 = zero;
    this->field_1334 = zero;
    this->field_1514 = (unsigned char)zero;
    this->field_1328 = zero;
    this->field_132c = zero;
    this->field_1330 = zero;
    this->field_1310 = zero;
    this->field_14e4 = zero;
    this->field_10ec = zero;
    this->field_10e8 = zero;
    debugging_log->Time();
    this->field_1298 = zero;
    this->field_12a0 = zero;
    this->field_1288 = zero;
    this->field_1518 = zero;
    this->field_1554 = t;
    strcpy(this->str_11fa, empty_string);
    strcpy(this->str_10f8, empty_string);
    strcpy(this->str_1179, empty_string);
    unsigned short cx = this->field_12d8;
    this->field_000c = zero;
    this->field_0010 = zero;
    this->field_12d0 = zero;
    this->field_1712 = 1;
    this->field_1710 = cx;
    this->field_1718 = zero;
    this->field_1558 = 3;
    this->field_001c = zero;
    this->field_0020 = zero;
    this->field_1590 = 2;
    this->field_10c8 = 4;
    this->field_155c = 4;
    this->field_1550 = (unsigned char)zero;
    this->field_10dc = 0x32;
    this->field_10e0 = zero;
    this->field_10e4 = zero;
    this->field_128c = zero;
    this->field_1294 = zero;
    target_00436610(debugging_log, log_string);
    int i = 1;
    if (this->field_12d8 >= i) {
        do {
            this->AddPlayer(i, zero, empty_string, empty_string);
            i++;
        } while (i <= this->field_12d8);
    }
    this->field_1550 = (unsigned char)zero;
    this->field_1554 = zero;
    this->sub_00429F80();
    this->sub_00429FD0();
    int* q = this->clear_13c0;
    for (int k = 9; k != 0; k--) *q++ = zero;
    this->field_0008 = 1;
    this->sub_0042C7A0();
    this->field_151c = zero;
    if (this->field_14c4 != 0) ((Releasable*)this->field_14c4)->Release();
    if (this->field_14c8 != 0) ((Releasable*)this->field_14c8)->Release();
    this->field_12a8 = zero;
    volatile char* p = (char*)this + 0x149c;
    int j = 10;
    do {
        *(volatile int*)(p - 0x130) = zero;
        *(volatile int*)p = zero;
        *(volatile int*)(p + 0x2b0) = zero;
        p += 4;
        j--;
    } while (j != 0);
}
