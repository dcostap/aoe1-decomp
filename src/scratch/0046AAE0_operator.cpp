// VA: 0046AAE0 Path::operator==(const Path& other) const
// Path.cpp lines 99-108
// 122 bytes
// attempted direct compare with named i; close but not exact: remaining mismatch is setup load order.

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
};

struct Path {
    int timeStampValue;
    float startValue[3];
    int gap_10;
    float goalValue[3];
    int gap_20;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;

    int operator==(const Path& other) const;
};

int Path::operator==(const Path& other) const {
    int i = 0;
    if (currentSizeValue <= 0) return 1;
    for (; i < currentSizeValue; i++) {
        if (other.pathValue[i].x != pathValue[i].x ||
            other.pathValue[i].y != pathValue[i].y ||
            other.pathValue[i].z != pathValue[i].z ||
            other.pathValue[i].facetToNextWaypoint != pathValue[i].facetToNextWaypoint) {
            return 0;
        }
    }
    return 1;
}
