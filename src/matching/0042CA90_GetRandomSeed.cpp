unsigned long debug_timeGetTime(const char* file, int line);
void debug_srand(const char* file, int line, unsigned long seed);
unsigned long debug_rand(const char* file, int line);

class TCommunications_Handler {
public:
    char gap_00[0x10E4];
    int Multiplayer;
    char gap_10E8[0x624];
    unsigned long RandomSeed;

    unsigned long GetRandomSeed();
};

unsigned long TCommunications_Handler::GetRandomSeed() {
    if (Multiplayer == 0) {
        unsigned long t = debug_timeGetTime("Com_hand.cpp", 0x1336);
        debug_srand("Com_hand.cpp", 0x1336, t);
        unsigned long r = debug_rand("Com_hand.cpp", 0x1337);
        RandomSeed = r;
    }
    return RandomSeed;
}
