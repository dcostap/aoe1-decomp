// VA: 0049F2D0 TRIBE_Screen_Main_Error::set_text(long) (22B)
// Scr_main.cpp lines 443-445
// BINARY NOTE: The message text call uses the observed +0xE4 virtual slot.

#include "../../include/scr_main_context.h"

void TRIBE_Screen_Main_Error::set_text(long param) {
    this->message->set_text_long(param);
}
