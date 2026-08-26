#define SCR_SET_CONTEXT_GROUP 1
#include "../../include/scr_set_context.h"
#ifndef SCR_SET_CONTEXT_GROUP
class TPanel {
public:
    long handle_user_command(unsigned int command, long param);
};

class TribeMPSetupScreen : public TPanel {};

class TribeGameSettingsScreen : public TPanel {
public:
    char gap_04[0x550];
    TribeMPSetupScreen* chat_scr;

    long handle_user_command(unsigned int command, long param);
};
#endif

long TribeGameSettingsScreen::handle_user_command(unsigned int command, long param) {
    if (this->chat_scr != 0) {
        long result = this->chat_scr->handle_user_command(command, param);
        if (result != 0) {
            return result;
        }
    }
#ifdef SCR_SET_CONTEXT_GROUP
    return this->TPanel::handle_user_command(command, param);
#else
    return ((TPanel*)this)->handle_user_command(command, param);
#endif
}
