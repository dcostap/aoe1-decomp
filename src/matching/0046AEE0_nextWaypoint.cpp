#ifndef PATH_TU_CONTEXT
struct Waypoint {
    char bytes[0x10];
};

class Path {
public:
    char gap_00[0x24];
    Waypoint* pathValue;
    char gap_28[0x04];
    int currentSizeValue;
    int currentWaypointValue;

    const Waypoint* nextWaypoint() const;
};
#endif

const Waypoint* Path::nextWaypoint() const {
    int index;

    if (pathValue != 0 && currentWaypointValue > -1) {
        index = currentWaypointValue + 1;
        if (index < currentSizeValue) {
            return pathValue + index;
        }
    }
    return 0;
}
