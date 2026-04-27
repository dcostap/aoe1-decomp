// TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech ctor
// VA: 004D21B0
// PDB: tact_tek.cpp:29-34
// EH-framed, needs /GX

#include "../../include/game_globals.h"

// rge_read function
void rge_read(int handle, void* buf, int size);

// Forward declare vtable-needed classes with dummy virtuals for slots 0-23+1
class RGE_Action {
public:
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual void d3(); virtual void d4(); virtual void d5();
    virtual void d6(); virtual void d7(); virtual void d8();
    virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16(); virtual void d17();
    virtual void d18(); virtual void d19(); virtual void d20();
    virtual void d21(); virtual void d22(); virtual void d23();

    RGE_Action(int param_1, void* param_2, int flag);
    char gap_04[4];
    void* action_obj;       // +0x08
    unsigned char status;   // +0x0C
    char pad_0D[0x40 - 0x0D];
    short tech_id;          // +0x40
    char pad_42[2];
    int unique_id;          // +0x44
};

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    TRIBE_Action_Make_Tech(int param_1, void* param_2);
    virtual ~TRIBE_Action_Make_Tech();
};

TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(int param_1, void* param_2)
    : RGE_Action(param_1, param_2, 1)
{
    rge_read(param_1, &this->tech_id, 2);
    rge_read(param_1, &this->unique_id, 4);
}
