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

    Waypoint* currentWaypoint() const;
};

Waypoint* Path::currentWaypoint() const {
    int index;

    if (pathValue != 0) {
        index = currentWaypointValue;
        if (index > -1 && index < currentSizeValue) {
            return pathValue + index;
        }
    }
    return 0;
}
