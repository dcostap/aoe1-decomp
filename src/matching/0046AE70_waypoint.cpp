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

    const Waypoint* waypoint(int index) const;
};

const Waypoint* Path::waypoint(int index) const {
    if (pathValue != 0 && index > -1 && index < currentSizeValue) {
        return pathValue + index;
    }
    return 0;
}
