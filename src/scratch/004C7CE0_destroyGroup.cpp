// destroyGroup (004C7CE0, 20 bytes, stat_obj.cpp)
// sets groupMembers.count to 0, groupCommanderValue to -1, returns 1
#include "../../include/game_globals.h"
#include "../../include/game_types.h"
#include "../../include/stat_obj_context.h"

int RGE_Static_Object::destroyGroup() {
    groupMembers.numberValue = 0;
    groupCommanderValue = -1;
    return 1;
}
