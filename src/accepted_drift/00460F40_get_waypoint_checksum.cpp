// VA: 00460F40 RGE_Moving_Object::get_waypoint_checksum()
// PDB owner: move_obj.cpp:3173-3183.
// The canonical RGE_Moving_Object and Path layouts live in
// include/move_obj_context.h. Accepted drift remains limited to the reviewed
// EBX/EBP allocation swap and commutative FPU add order.

extern "C" long __cdecl _ftol(void);

long RGE_Moving_Object::get_waypoint_checksum() {
    float sum = 0.0f;
    register int savedIndex;
    Path* path = &this->pathValue;
    savedIndex = path->currentWaypointNumber();
    path->initToStart();
    int i = 0;
    if (path->numberOfWaypoints() > 0) {
        do {
            Waypoint* wp1 = path->currentWaypoint();
            Waypoint* wp2 = path->currentWaypoint();
            sum += wp1->y + wp2->x;
            i++;
            path->moveToNextWaypoint();
        } while (i < path->numberOfWaypoints());
    }
    path->setCurrentWaypointNumber(savedIndex);
    return (long)(int)sum;
}
