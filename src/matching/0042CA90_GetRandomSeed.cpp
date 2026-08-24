unsigned long debug_timeGetTime(const char* file, int line);
void debug_srand(const char* file, int line, unsigned long seed);
#if !defined(COM_HAND_TU_CONTEXT)
unsigned long debug_rand(const char* file, int line);
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x10E4];
    int Multiplayer;
    char gap_10E8[0x624];
    unsigned long RandomSeed;

    unsigned long GetRandomSeed();
};
#endif // COM_HAND_TU_CONTEXT


unsigned long TCommunications_Handler::GetRandomSeed() {
    if (this->Multiplayer == 0) {
        unsigned long t = debug_timeGetTime("Com_hand.cpp", 0x1336);
        debug_srand("Com_hand.cpp", 0x1336, t);
        unsigned long r = debug_rand("Com_hand.cpp", 0x1337);
        this->PlayerOptions.RandomSeed = r;
    }
    return this->PlayerOptions.RandomSeed;
}
