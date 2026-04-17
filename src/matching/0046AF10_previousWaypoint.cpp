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

    const Waypoint* previousWaypoint() const;
};

const Waypoint* Path::previousWaypoint() const {
    int next_index;

    if (pathValue != 0) {
        next_index = currentWaypointValue + 1;
        if (next_index > 0 && currentWaypointValue < currentSizeValue) {
            return pathValue + currentWaypointValue - 1;
        }
    }
    return 0;
}
