// VA: 0049F2B0 TRIBE_Screen_Main_Error::set_text(char*) (22B)
// Scr_main.cpp lines 435-437
// BINARY NOTE: The message text call uses the observed +0xE8 virtual slot.

#include "../../include/scr_main_context.h"

void TRIBE_Screen_Main_Error::set_text(char* param) {
    this->message->set_text(param);
}
