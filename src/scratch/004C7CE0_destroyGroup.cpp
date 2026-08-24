// destroyGroup (004C7CE0, 20 bytes, stat_obj.cpp)
// sets groupMembers.count to 0, groupCommanderValue to -1, returns 1
#include "../../include/game_globals.h"
#include "../../include/game_types.h"

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    unsigned char _pad[0x68];
    int groupMembersCount;  // +0x68
    unsigned char _pad2[0x10];
    int groupCommanderValue; // +0x78
};
#endif

int RGE_Static_Object::destroyGroup() {
    groupMembersCount = 0;
    groupCommanderValue = -1;
    return 1;
}
