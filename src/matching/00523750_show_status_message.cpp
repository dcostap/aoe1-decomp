// 00523750 TRIBE_Game::show_status_message
// tribegam.cpp, 69 bytes. MATCH.
//
// Fix: both calls use the start of str, not str+4. The original LEA
// expressions occur at different stack depths but resolve to the same buffer
// address. The earlier scratch incorrectly compensated with str+4.

#include "../../include/tribegam_context.h"

void TRIBE_Game::show_status_message(int string_id, char* param_2, long param_3) {
    char str[0x100];
    this->get_string((long)string_id, str, 0x100);
    this->show_status_message(str, param_2, param_3);
}
