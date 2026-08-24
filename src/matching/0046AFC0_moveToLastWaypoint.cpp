#ifndef PATH_TU_CONTEXT
class Path {
public:
    char gap_00[0x30];
    int currentWaypointValue;

    int moveToLastWaypoint();
};
#endif

int Path::moveToLastWaypoint() {
    if (currentWaypointValue > 0) {
        currentWaypointValue = currentWaypointValue - 1;
        return 1;
    }
    return 0;
}
