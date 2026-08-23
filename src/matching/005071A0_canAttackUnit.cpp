#include "../../include/taiuaimd_context.h"

// PDB ownership gives a public virtual method with a class-pointer parameter.

int TribeSoldierUnitAIModule::canAttackUnit(RGE_Static_Object* obj) {
    if (!obj) return 0;
    return obj->master_obj->object_group != 1;
}
