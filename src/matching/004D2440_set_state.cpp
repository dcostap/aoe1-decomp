#include "../../include/tact_tek_context.h"

#ifndef AOE1_TACT_TEK_CONTEXT_H
class TRIBE_Action_Make_Tech {
public:
    virtual ~TRIBE_Action_Make_Tech();
    char gap_0[0x8];
    unsigned char field_C;
    void set_state(unsigned char v);
};
#endif

void TRIBE_Action_Make_Tech::set_state(unsigned char v) { this->status = v; }
