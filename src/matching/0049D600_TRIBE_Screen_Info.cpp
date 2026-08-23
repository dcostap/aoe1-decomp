// BINARY NOTE: the destructor owns the TScreenPanel base surface.  The shared
// context preserves the original base-dtor tail and vtable owner.
#include "../../include/scr_info_context.h"

TRIBE_Screen_Info::~TRIBE_Screen_Info() {
}
