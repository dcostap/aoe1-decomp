// 004835A0 RGE_RMM_Database_Controller::de_init
// Context audit: the loop owns the inherited random-map module list at +0x08.
// It is not a world pointer. This source uses the canonical rmm_dbct base
// surface and preserves the original module-destruction and resource order.

#include "..\..\include\rmm_dbct_context.h"

void operator delete(void* p);

uchar RGE_RMM_Database_Controller::de_init() {
    this->world = 0;
    this->map_type = -1;
    this->number_of_players = 0;
    while (this->list != 0) {
        RGE_Random_Map_Module* p = this->list->module;
        if (p != 0) {
            p->~RGE_Random_Map_Module();
            operator delete(p);
        }
    }
    this->destroy_shared_resources();
    this->update_map_info(0);
    return 0;
}
