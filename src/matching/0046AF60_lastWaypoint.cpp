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

    const Waypoint* lastWaypoint() const;
};
#endif

const Waypoint* Path::lastWaypoint() const {
    if (pathValue != 0 && currentSizeValue > 0) {
        return pathValue + currentSizeValue - 1;
    }
    return 0;
}
