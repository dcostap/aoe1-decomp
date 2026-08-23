#include "../../include/mouseptr_context.h"

int TMousePointer::in_game_mode() {
    if (this->GameMode && this->GameEnabled) {
        return 1;
    }
    return 0;
}
