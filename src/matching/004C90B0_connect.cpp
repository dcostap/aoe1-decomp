// VA: 004C90B0 TRIBE_Building_Object::connect
// PDB source: t_b_obj.cpp
// Baseline: natural building-neighbor reconnection flow, using the same
// binary-proven field and check surface as the exact connect2 sibling.
// Attempt log:
// - Full base surface with function-scope branch aliases kept live added 9
//   bytes and saved EBX; flattening the surface did not change that basin.
// - Scoping the branch-only aliases before the common connect2 tail restored
//   the stack reloads and matched all 200 bytes.
// - A combined if/else spelling was 4 bytes off from alias load order; the
//   nested branches and explicit shared continuation below are retained.

#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::connect()
{
    if (this->object_info != 0) {
        if (*(short*)((char*)this->object_info + 0x60) == 3) {
            this->set_angle();

            TRIBE_Building_Object* checks[4];
            this->check(checks);

            {
                TRIBE_Building_Object* a = checks[0];
                TRIBE_Building_Object* c = checks[2];
                TRIBE_Building_Object* b = checks[1];
                TRIBE_Building_Object* d = checks[3];

                if (a && d) {
                    if (!b && !c) {
                        this->rotate(1 - this->facet);
                        goto connect_neighbors;
                    }
                }
                if (b && c) {
                    if (!a && !d) {
                        this->rotate(-this->facet);
                        goto connect_neighbors;
                    }
                }
                this->rotate(2 - this->facet);
            }

connect_neighbors:
            if (checks[0] != 0) {
                checks[0]->connect2();
            }
            if (checks[1] != 0) {
                checks[1]->connect2();
            }
            if (checks[2] != 0) {
                checks[2]->connect2();
            }
            if (checks[3] != 0) {
                checks[3]->connect2();
            }
            return;
        }
        this->facet = 0;
    }
}
