// VA: 00460B70 removeUserDefinedWaypoint
// move_obj.cpp lines 2914-2935, 125 bytes
// RGE_Moving_Object::removeUserDefinedWaypoint(int)
// Attempt log:
// - The canonical member aliases emitted a short 112-byte body and missed the
//   original reloads of the waypoint pointer.
// - Removing both aliases and keeping the proven three-byte byte stride gives
//   the original 125-byte body and grouped MATCH.
// - A local count alias worsened the result to 121 differing bytes. Qualification
//   and decrement spelling did not change the exact bytes.
// BINARY NOTE: the executable reloads userDefinedWaypoints before each byte
// copy, so the direct member expression is required here.

#include "../../include/move_obj_context.h"

void RGE_Moving_Object::removeUserDefinedWaypoint(int index) {
    int i;

    if (index < 0 || index >= numberUserDefinedWaypointsValue) return;
    for (i = 0; i < numberUserDefinedWaypointsValue && i < index; i++) {
    }
    for (; i < numberUserDefinedWaypointsValue; i++) {
        if (i) {
            userDefinedWaypoints[i - 1].x = userDefinedWaypoints[i].x;
            userDefinedWaypoints[i - 1].y = userDefinedWaypoints[i].y;
            userDefinedWaypoints[i - 1].z = userDefinedWaypoints[i].z;
        }
    }
    numberUserDefinedWaypointsValue--;
}
