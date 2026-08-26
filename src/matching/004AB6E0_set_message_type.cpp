

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::set_message_type(MessageType type, int value) {
    message_input->set_active(value);
    bottom_panel->set_redraw(1);
}
