// attempt log:
// first pass: direct guard + debug-time seeding path with the observed file/line helper calls
// target shape: if MeHost is zero return; if seed == -1 call the debug time/srand/rand chain; store seed to +0x170C, set NeedsToBeSent, SendSharedData(0)

extern unsigned long debug_timeGetTime(const char* file, int line);
extern void debug_srand(const char* file, int line, unsigned long value);
extern int debug_rand(const char* file, int line);

class TCommunications_Handler {
public:
    char gap_00[0x1C];
    int MeHost;
    char gap_20[0x1530];
    unsigned char NeedsToBeSent;
    char gap_1551[0x1BB];
    unsigned long RandomSeed;

    void SendSharedData(int zero);
    void SetRandomSeed(int seed);
};

void TCommunications_Handler::SetRandomSeed(int seed) {
    if (this->MeHost == 0) {
        return;
    }

    if (seed == -1) {
        unsigned long time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x1320);
        debug_srand("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x1320, time);
        seed = debug_rand("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x1321);
    }

    this->RandomSeed = (unsigned long)seed;
    this->NeedsToBeSent = 1;
    this->SendSharedData(0);
}
