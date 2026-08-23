char* strncpy(char* dest, const char* src, unsigned int count);

#ifndef TPNL_BTN_SHARED_CONTEXT
class TRIBE_Panel_Button {
public:
    char gap_00[0x2D0];
    char text_msg[0x100];

    void set_text_msg(char* text);
};
#else
#include "../../include/tpnl_btn_context.h"
#endif

void TRIBE_Panel_Button::set_text_msg(char* text) {
    if (text == 0) {
        this->text_msg[0] = 0;
        return;
    }
    strncpy(this->text_msg, text, 0x100);
    this->text_msg[0xFF] = 0;
}
