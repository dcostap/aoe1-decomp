#include "../../include/tribegam_context.h"

#if 0
class TRIBE_Game {
public:
    void close_status_message();
};
#endif

void TRIBE_Game::close_status_message() {
    panel_system.restorePreviousPanel(1);
}
