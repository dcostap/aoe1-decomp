#include <stdlib.h>

class TCommunications_Handler {
public:
    void new_command(void* data, long size);
};

unsigned long debug_timeGetTime(const char* file, int line);

class RGE_Command {
public:
    char gap_00[0x8];
    unsigned char* last_order;
    long last_order_size;
    unsigned long last_order_time;
    TCommunications_Handler* com_hand;

    unsigned char check_for_duplicate_orders(unsigned char* order, long size);
    void submit(unsigned char* order, long size);
};

void RGE_Command::submit(unsigned char* order, long size) {
    unsigned char dup = check_for_duplicate_orders(order, size);
    if (dup == 0) {
        com_hand->new_command(order, size);
    }
    if (last_order != 0) {
        free(last_order);
    }
    last_order = order;
    last_order_size = size;
    unsigned long t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Command.cpp", 0x4AC);
    last_order_time = t;
}
