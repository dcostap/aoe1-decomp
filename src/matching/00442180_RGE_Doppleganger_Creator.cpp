// attempt 1: straight destructor with ordered frees for the four allocation members and DDlogf fclose/reset
// blocker watch: this is a tiny teardown helper; if VC5 drifts, the first probes are whether the object pointer should live in esi the whole time and whether the global file handle wants a direct test/load
#include <stdio.h>

#ifndef DPL_OBJ_SHARED_CONTEXT
#include "../../include/dpl_obj_context.h"
#endif

extern "C" void __cdecl free(void* ptr);
RGE_Doppleganger_Creator::~RGE_Doppleganger_Creator() {
    if (this->Objects != 0) {
        free(this->Objects);
    }
    if (this->Map_Addresses != 0) {
        free(this->Map_Addresses);
    }
    if (this->Last_Map_Value != 0) {
        free(this->Last_Map_Value);
    }
    if (this->Object_ids != 0) {
        free(this->Object_ids);
    }
    if (DDlogf != 0) {
        fclose(DDlogf);
        DDlogf = 0;
    }
}
