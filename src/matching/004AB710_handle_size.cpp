// VA: 004AB710 TRIBE_Screen_Sed::handle_size | scr_sed.cpp:2201-2213
// Using proper inheritance chain

#include "../../include/scr_sed_context.h"

long TRIBE_Screen_Sed::handle_size(long width, long height) {
    TPanel::handle_size(width, height);
    this->position_panels();
    TPanel::handle_size(width, height);
    return 0;
}
