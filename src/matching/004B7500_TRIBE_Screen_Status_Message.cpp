// attempt 2: no intermediate TPanel base adjustment; helper on visible screen-panel base
#include "../../include/scr_stms_context.h"
TRIBE_Screen_Status_Message::~TRIBE_Screen_Status_Message() {
    this->delete_panel(&this->message);
}
