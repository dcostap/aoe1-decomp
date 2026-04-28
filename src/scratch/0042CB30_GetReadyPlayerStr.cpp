// 0042CB30 GetReadyPlayerStr (TCommunications_Handler::GetReadyPlayerStr)
// Inventory: infmap.cpp (actually Com_hand.cpp)
//
// Left in scratch: VC5 codegen drift — register allocation and loop optimization
// differences from original.
//
// Functional understanding:
// - Copies template string "Ready=                        " to global buffer 0x62C5B0
// - Loops i=1..MaxGamePlayers checking LastTurnAck[i] >= current_turn
// - If ready: writes 'A' at buffer[6+i]
// - If not ready: switches on PLAYERHUMANITY type (0='-', 2='W', 4='C', 5='X', 6='V', default='?')
//
// Remaining drift:
// - Prologue: original pushes ebp/esi/edi with ebp=this; rebuilt pushes esi/edi with edx=this
//   (missing 1 byte push ebp shifts all offsets)
// - String copy: original sets eax=1 after strcpy (loop counter init); rebuilt omits this
// - Loop counter: original keeps i in eax with [eax+62C5B6h] buffer writes;
//   rebuilt uses running buffer pointer in eax (converted from i+62C5B6h)
// - current_turn: original reloads [this+10C8h] each iteration; rebuilt hoists it
// - Default char: original uses bl=3Fh (push ebx); rebuilt uses immediate '?'
// - Zero-extend: original xor ecx,0/mov cx,[mem]; rebuilt and edi,0FFFFh
// - Jump table: original at fixed address 42CBE4; rebuilt at [ecx*4] (unresolved)
// - Missing pop ebp at epilogue (matching missing push ebp)
//
// Attempted probes (all produced same VC5 output):
// 1. do-while loop instead of goto
// 2. for loop with p computed inside
// 3. Removed defc variable (use '?' literal)
// 4. different buffer write syntax (0x62C5B6+i vs buf[i+6])
// 5. goto labels with declaration-first ordering
// 6. unsigned int casts for comparisons
// 7. int declared at top of function
//
// All VC5 output converges to edx=this, running pointer, hoisted current_turn.
// This appears to be a stable VC5 codegen basin; the source produces the same
// optimized output regardless of minor variations.
//
// A custom flags file or different TU context might be needed.

#include <string.h>
#pragma intrinsic(strcpy)

class TCommunications_Handler {
public:
    char gap_10C8[0x10C8];
    unsigned long current_turn;
    char gap_10CC[0x20C];
    unsigned short MaxGamePlayers;

    char* GetReadyPlayerStr();
};

char* TCommunications_Handler::GetReadyPlayerStr() {
    int i;
    int* p;

    strcpy((char*)0x62C5B0, (const char*)0x58284C);

    i = 1;
    if (MaxGamePlayers < 1) goto end;

    p = (int*)((char*)this + 0x16D8);

loop:
    if ((unsigned int)p[0x13] >= current_turn) {
        ((unsigned char*)0x62C5B0)[i + 6] = 'A';
    } else {
        switch (p[0]) {
        case 0: ((unsigned char*)0x62C5B0)[i + 6] = '-'; break;
        case 2: ((unsigned char*)0x62C5B0)[i + 6] = 'W'; break;
        case 4: ((unsigned char*)0x62C5B0)[i + 6] = 'C'; break;
        case 5: ((unsigned char*)0x62C5B0)[i + 6] = 'X'; break;
        case 6: ((unsigned char*)0x62C5B0)[i + 6] = 'V'; break;
        default: ((unsigned char*)0x62C5B0)[i + 6] = '?'; break;
        }
    }
    i++;
    p++;
    if ((unsigned int)i <= (unsigned int)MaxGamePlayers) goto loop;

end:
    return (char*)0x62C5B0;
}
