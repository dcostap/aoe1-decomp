// VA: 0046A9E0 Path::operator=(const Path& other)
// Path.cpp lines 82-94
// 241 bytes

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

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

    Path& operator=(const Path& other);
};

Path& Path::operator=(const Path& other) {
    if (maxSizeValue < other.maxSizeValue) {
        int new_size;
        if (other.maxSizeValue == 0) {
            new_size = maxSizeValue * 2;
        } else if (other.maxSizeValue < maxSizeValue) {
            new_size = maxSizeValue;
        } else {
            new_size = maxSizeValue + other.maxSizeValue;
        }
        maxSizeValue = new_size;
        Waypoint* new_path = (Waypoint*)operator_new(new_size * 16);
        for (int i = 0; i < currentSizeValue; i++) {
            new_path[i] = pathValue[i];
        }
        if (pathValue != 0) {
            operator_delete(pathValue);
        }
        pathValue = new_path;
    }
    for (int i = 0; i < other.currentSizeValue; i++) {
        pathValue[i] = other.pathValue[i];
    }
    currentWaypointValue = other.currentWaypointValue;
    currentSizeValue = other.currentSizeValue;
    return *this;
}
