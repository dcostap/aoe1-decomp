// 0052B630 T_Scenario::SetSPDestObjectID
// Source: tscenaro.cpp lines 571-575. 53 bytes. __thiscall, ret 8.
//
// Attempt log:
// Probe 1: original scratch with int offset calc → lea ecx,[eax+1] (15% diff)
// Probe 2: moved which_player read before result=id+result++ → still lea
// Probe 3: raw pointer read (*(int*)(this+0x4BF0)) → still lea
// Probe 4: proper struct-type array sp_victory[12][12] → still lea
// Remaining: 2 bytes diff = mov ecx,eax+inc ecx vs lea ecx,[eax+1].
// VC5 folds copy+inc into lea when nothing requires eax before increment.
// Original source has which_player subscript read FUNCTIONALLY between
// call result and +1, forcing mov+inc+read+inc ordering. Pure C++ cannot
// force this scheduling with /O2 folding.
// Left in scratch.

#include "../../include/tscenaro_context.h"

#if 0
class T_Scenario {
public:
    char gap_00[0x1AD8];
    int sp_victory_dest_obj_id[1024];
    char gap_2AD8[0x2118];
    int which_player;

    int get_object_ID(RGE_Static_Object* object);
    void SetSPDestObjectID(int index, RGE_Static_Object* object);
};
#endif

void T_Scenario::SetSPDestObjectID(int index, RGE_Static_Object* object) {
    if (object != 0) {
        int object_id = this->get_object_ID(object);
        int which_player = this->which_player;

        int offset;
        offset = index + (which_player + which_player * 2) * 4;
        offset = offset + offset * 2;
        offset = offset + offset * 4;
        this->raw_dest_objects.sp_victory_dest_obj_id[offset] = object_id + 1;
    }
}
