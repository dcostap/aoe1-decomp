#include "../../include/scr_info_context.h"

long TRIBE_Screen_Info::key_down_action(long key, short repeat, int ctrl, int alt, int shift) {
    if (((key != 0x12) && (key != 0x11)) && (key != 0x10)) {
        close_screen();
    }
    return 0;
}
