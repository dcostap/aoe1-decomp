#include "../../include/tact_tek_context.h"

#ifndef AOE1_TACT_TEK_CONTEXT_H
void rge_write(int file, void* data, int size);

class RGE_Action {
public:
    virtual void vf00(void);
    void save(int file);
};

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    char gap_04[0x3C];
    short tech_id;
    char gap_42[0x02];
    int unique_id;

    void save(int file);
};
#endif

void TRIBE_Action_Make_Tech::save(int file) {
    RGE_Action::save(file);
    rge_write(file, &this->tech_id, 2);
    rge_write(file, &this->unique_id, 4);
}
