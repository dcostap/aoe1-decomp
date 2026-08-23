// 004828A0 RGE_RMM_Controller::count_map_tiles
// Exact anchor: mov eax,[ecx+14h]; imul eax,[ecx+18h]; ret 4.
// The byte parameter is intentionally unused, as in the shipped helper.
#include "../../include/rmm_cntr_context.h"

long RGE_RMM_Controller::count_map_tiles(uchar ignored)
{
    return this->map_width * this->map_height;
}
