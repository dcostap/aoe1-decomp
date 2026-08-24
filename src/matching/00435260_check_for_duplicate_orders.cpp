#ifndef COMMAND_TU_CONTEXT
class RGE_Command {
public:
    char gap_00[0x8];
    unsigned char* last_order;
    long last_order_size;
    unsigned long last_order_time;

    unsigned char check_for_duplicate_orders(unsigned char* order, long size);
    unsigned char close_check_for_duplicate_orders(unsigned char* order);
};
#endif

unsigned long debug_timeGetTime(const char* file, int line);

unsigned char RGE_Command::check_for_duplicate_orders(unsigned char* order, long size) {
    if (last_order != 0) {
        if (last_order_size == size) {
            if (*last_order == *order) {
                unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Command.cpp", 0x497);
                if ((int)(now - last_order_time) < 0x1F4) {
                    return close_check_for_duplicate_orders(order);
                }
            }
        }
    }
    return 0;
}
