#include "../../include/m_dg_obj_context.h"

RGE_Master_Static_Object* RGE_Master_Doppleganger_Object::make_new_master() {
    return new RGE_Master_Doppleganger_Object(this, 1);
}
