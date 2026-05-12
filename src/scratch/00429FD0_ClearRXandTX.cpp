// VA: 00429FD0 TCommunications_Handler::ClearRXandTX
// Source: Com_hand.cpp lines 3161-3170
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// 16: match original offset-increment-before-stores order

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

    offset = 0;
    do {
        entry = this->tx_array + offset;
        *((void**)entry) = 0;
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
