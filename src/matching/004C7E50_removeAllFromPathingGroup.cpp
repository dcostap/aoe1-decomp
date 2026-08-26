#include "../../include/stat_obj_context.h"
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
#define RGE_STAT_OBJ_SHARED_CONTEXT 1
#endif

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Player {
public:
    int computerPlayer(void);
};

class RGE_Static_Object {
public:
    char gap_00[0x0C];
    RGE_Player* owner;
    char gap_10[0x48];
    int pathingGroupMembers_numberValue;

    void removeAllFromPathingGroup(void);
};
#endif

void RGE_Static_Object::removeAllFromPathingGroup(void) {
    if (owner->computerPlayer() == 1) {
        pathingGroupMembers.numberValue = 0;
    }
}
