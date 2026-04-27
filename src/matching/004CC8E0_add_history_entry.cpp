// VA: 004CC8E0 | TRIBE_History_Info::add_history_entry(uchar,uchar) | t_histry.cpp:110-137 | 106 bytes
//
// Attempt log:
// [1] First attempt.

#include "../../include/game_types.h"
#include <stdlib.h>
#include <string.h>

#pragma intrinsic(memcpy)

class TRIBE_History_Info {
public:
    unsigned char* buffer;  // +0x00
    char _gap_04[0x08];
    int count;              // +0x0C
    int capacity;           // +0x10

    void add_history_entry(unsigned char flag, unsigned char value);
};

void TRIBE_History_Info::add_history_entry(unsigned char flag, unsigned char value) {
    if (count >= capacity) {
        int oldCapacity = capacity;
        capacity += 0x3C;
        unsigned char* newBuf = (unsigned char*)calloc(capacity, 1);
        if (oldCapacity > 0) {
            memcpy(newBuf, buffer, oldCapacity);
            free(buffer);
        }
        buffer = newBuf;
    }

    if (flag == 0) {
        buffer[count] = value;
    }

    count++;
}
