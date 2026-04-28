// 00429FD0 ClearRXandTX (136 bytes)
// PDB: Com_hand.cpp (TCommunications_Handler::ClearRXandTX)
// STATUS: parked — VC5 base+offset computation pattern differs
// 
// The function clears RX (0x1524) and TX (0x1520) arrays in TCommunications_Handler.
// RX: 501 entries * 0x18 = 0x2EF8 bytes. Each: delete ptr[0], zero 5 dwords (20 bytes)
// TX: 501 entries * 0x38 = 0x6D98 bytes. Each: zero dword[0], delete ptr[+8], zero 3 dwords,
//     memset 40 bytes at +0x10 via rep stosd (0Ah = 10 dwords).
//
// Remaining mismatch (~32 bytes, 23.5%): VC5 computes entry = base + offset as
//   mov edx, [base]; mov esi, ebp; add esi, edx  (3 insns)
// instead of original:
//   mov esi, [base]; add esi, ebp                 (2 insns)
// This propagates through both loops causing shifted alignment and branch
// offset differences. Pure TU-context register allocation issue.

#include <stdlib.h>
#include <string.h>

void __cdecl operator_delete(void* p);

class TCommunications_Handler {
public:
    char gap_1520[0x1520];
    char* tx_array;     // +0x1520
    char* rx_array;     // +0x1524

    void ClearRXandTX();
};

void TCommunications_Handler::ClearRXandTX()
{
    unsigned int offset;
    char* entry;

    // Clear RX array: this->rx_array (at +0x1524)
    offset = 0;
    do {
        entry = this->rx_array + offset;
        if (*(void**)entry) {
            operator_delete(*(void**)entry);
        }
        offset += 0x18;
        *(void**)entry = 0;
        *((void**)entry + 1) = 0;
        *((void**)entry + 2) = 0;
        *((void**)entry + 3) = 0;
        *((void**)entry + 4) = 0;
    } while (offset < 0x2EF8);

    // Clear TX array: this->tx_array (at +0x1520)
    offset = 0;
    do {
        entry = this->tx_array + offset;
        *(void**)entry = 0;
        if (*(void**)(entry + 8)) {
            operator_delete(*(void**)(entry + 8));
        }
        offset += 0x38;
        *(void**)(entry + 8) = 0;
        *(void**)(entry + 4) = 0;
        *(void**)(entry + 0xC) = 0;
        memset(entry + 0x10, 0, 0x28);
    } while (offset < 0x6D98);
}
