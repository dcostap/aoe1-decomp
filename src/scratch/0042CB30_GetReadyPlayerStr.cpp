// 0042CB30 GetReadyPlayerStr (TCommunications_Handler::GetReadyPlayerStr)
// Attempt log:
// inherited scratch variants: do/for/goto, p computed inside, literal/default local, unsigned casts all converged to compact edx=this/running-buffer-pointer family.
// tried direct one-based index expressions: 176B (too short), still running-buffer pointer.
// tried local this alias and register i: no change.
// tried volatile MaxGamePlayers: 179B but wrong ebx=this family, still running buffer pointer and hoisted current_turn.
// tried volatile current_turn only (current source): 179B and reloads current_turn each iteration, but still wrong ebx=this, esi=max_count, eax=buffer pointer family.
// tried register/split default char; VC5 still immediate '?' rather than original bl=3Fh.
// left in scratch: behavior is understood; remaining gap is broad VC5 register-allocation/induction-variable basin (original ebp=this, eax=i, edx=record pointer, bl='?', reload max into cx at bottom).

#include <string.h>
#pragma intrinsic(strcpy)

class TCommunications_Handler {
public:
    char gap_10C8[0x10C8];
    volatile unsigned long current_turn;
    char gap_10CC[0x20C];
    unsigned short MaxGamePlayers;

    char* GetReadyPlayerStr();
};

char* TCommunications_Handler::GetReadyPlayerStr() {
    strcpy((char*)0x62C5B0, (const char*)0x58284C);

    register unsigned int i = 1;
    if (i <= this->MaxGamePlayers) {
        int* p = (int*)((char*)this + 0x16D8);
        char defc;
        defc = '?';
        do {
            if ((unsigned int)p[0x13] >= this->current_turn) {
                ((volatile char*)0x62C5B0)[i + 6] = 'A';
            } else {
                switch (p[0]) {
                case 0: ((volatile char*)0x62C5B0)[i + 6] = '-'; break;
                case 2: ((volatile char*)0x62C5B0)[i + 6] = 'W'; break;
                case 4: ((volatile char*)0x62C5B0)[i + 6] = 'C'; break;
                case 5: ((volatile char*)0x62C5B0)[i + 6] = 'X'; break;
                case 6: ((volatile char*)0x62C5B0)[i + 6] = 'V'; break;
                default: ((volatile char*)0x62C5B0)[i + 6] = defc; break;
                }
            }
            ++i;
            ++p;
        } while (i <= this->MaxGamePlayers);
    }
    return (char*)0x62C5B0;
}
