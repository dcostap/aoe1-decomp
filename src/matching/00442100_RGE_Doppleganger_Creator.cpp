// 00442100 RGE_Doppleganger_Creator::RGE_Doppleganger_Creator
// first pass: ctor allocates four arrays and lazily opens DD log file.

#ifndef DPL_OBJ_SHARED_CONTEXT
#include "../../include/dpl_obj_context.h"
#endif

RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(RGE_Player* player, int count)
{
    this->objects = (int*)calloc(count, 4);
    this->mapAddresses = (int*)calloc(count, 4);
    this->lastMapValue = (int*)calloc(count, 4);
    this->objectIds = (int*)calloc(count, 4);
    this->maxCount = count;
    this->activeCount = 0;
    this->player = player;
    if (DDlogf == 0) {
        DDlogf = fopen("c:\\aoedoppl.txt", "w");
    }
}
