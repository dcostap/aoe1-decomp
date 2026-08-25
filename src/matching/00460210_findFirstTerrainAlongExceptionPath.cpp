// VA: 00460210 RGE_Moving_Object::findFirstTerrainAlongExceptionPath
// PDB owner: move_obj.cpp. The canonical moving-object, Path, and point
// declarations live in include/move_obj_context.h.
// Standalone owner checkpoint: 406-byte owner with the exact XYPoint virtual ABI.

extern float DAT_00570B80;

int RGE_Moving_Object::findFirstTerrainAlongExceptionPath(
    int terrain, float* result_x, float* result_y) {
    int i;
    XYPoint p1, p2, rVal;
    Path* path = &this->exceptionPathValue;

    if (path->numberOfWaypoints() < 2) {
        return 0;
    }

    path->initToStart();
    if (path->currentWaypoint() == 0) {
        return 0;
    }

    p1.x = (int)path->currentWaypoint()->x;
    p1.y = (int)path->currentWaypoint()->y;
    path->moveToNextWaypoint();
    if (path->currentWaypoint() == 0) {
        return 0;
    }

    p2.x = (int)path->currentWaypoint()->x;
    p2.y = (int)path->currentWaypoint()->y;
    i = 1;
    while (i < path->numberOfWaypoints()) {
        if (this->firstTileAlongLine(&p1, &p2, &rVal,
                                     terrain, terrain, 1) == 1) {
            float result = (float)rVal.x - DAT_00570B80;
            *result_x = result;
            *result_y = result;
            return 1;
        }

        p1.x = (int)path->currentWaypoint()->x;
        p1.y = (int)path->currentWaypoint()->y;
        path->moveToNextWaypoint();
        if (path->currentWaypoint() == 0) {
            return 0;
        }

        p2.x = (int)path->currentWaypoint()->x;
        p2.y = (int)path->currentWaypoint()->y;
        ++i;
    }

    *result_x = -1.0f;
    *result_y = -1.0f;
    return 0;
}
