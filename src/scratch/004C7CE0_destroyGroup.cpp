// destroyGroup (004C7CE0, 20 bytes, stat_obj.cpp)
// sets groupMembers.count to 0, groupCommanderValue to -1, returns 1
#include "game_globals.h"
#include "game_types.h"

class RGE_Static_Object {
public:
    unsigned char _pad[0x68];
    int groupMembersCount;  // +0x68
    unsigned char _pad2[0x10];
    int groupCommanderValue; // +0x78
};

int RGE_Static_Object::destroyGroup() {
    groupMembersCount = 0;
    groupCommanderValue = -1;
    return 1;
}
