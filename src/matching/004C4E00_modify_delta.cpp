// VA: 004C4E00 RGE_Static_Object::modify_delta
// PDB source: stat_obj.cpp lines 2471-2486
// Attempt log:
// rewrite 2026-05-19: replaced wrong integer stub with packet-observed float/virtual-call behavior.
// retry: the binary uses the virtual (float, unsigned char) surface. The
// switch and parameter-home reuse preserve its observed dispatch and FPU
// sequence. The complete wrapper owns the shared class declaration.

#include "../../include/stat_obj_context.h"

void RGE_Static_Object::modify_delta(float delta, unsigned char type)
{
    unsigned int op = type & 0xff;
    switch (op) {
    case 1:
        if (this->tile != 0 && this->object_state == 2) {
            RGE_Player* owner = this->owner;
            this->unexplore_terrain(owner, 0, -1);
            RGE_Master_Static_Object* master = this->master_obj;
            this->explore_terrain(this->owner, 0, (int)(master->los + delta));
        }
        return;
    case 0: {
        RGE_Master_Static_Object* master = this->master_obj;
        float original_delta = delta;
        *(int*)&delta = (int)master->hp;
        this->hp = (float)(int)(short)((original_delta + (float)*(int*)&delta) * this->hp / (float)*(int*)&delta);
        break;
    }
    default:
        return;
    }
}
