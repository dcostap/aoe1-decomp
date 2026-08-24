#ifndef PATH_TU_CONTEXT
class Path {
public:
    char gap_00[0x2C];
    int currentSizeValue;
    int currentWaypointValue;

    int moveToNextWaypoint();
};
#endif

int Path::moveToNextWaypoint() {
    int index;

    index = currentSizeValue - 1;
    if (currentWaypointValue < index) {
        currentWaypointValue = currentWaypointValue + 1;
        return 1;
    }
    currentWaypointValue = index;
    return 0;
}
