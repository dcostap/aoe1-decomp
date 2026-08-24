// ACCEPTED_DRIFT: loop setup scheduling drift only: xor edi is moved across an unrelated store; later inc/cmp overwrite flags and the same timestamps are stored.
// tried a direct time refresh with the ping arrays laid out at 0x1348/0x1398
// tried the asm-shaped loop pointer; remaining mismatch is the first loop body scheduling, specifically the xor edi / second-store order

#if !defined(COM_HAND_TU_CONTEXT)
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern char s_Com_hand_cpp[];
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x12D8];
    unsigned short MaxGamePlayers;
    char gap_12DA[0x6E];
    char LastRXPing[0x50];
    char LastTXPing[0x50];

    void ResetLastCommunicationTimes(void);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::ResetLastCommunicationTimes(void) {
    unsigned long now = debug_timeGetTime(s_Com_hand_cpp, 0x1282);
    if (1 <= this->MaxGamePlayers) {
        char* ecx = (char*)&this->LastTXPing[0];
        int edx = 1;
        do {
            *(unsigned long*)(ecx - 0x50) = now;
            ++edx;
            *(unsigned long*)ecx = now;
            ecx += 4;
        } while (edx <= (int)this->MaxGamePlayers);
    }
}
